package main

import (
	"io/ioutil"
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/trace"
	"sort"
	"strings"
)

// Pkgsrc describes a pkgsrc installation.
// In each pkglint run, only a single pkgsrc installation is ever loaded.
// It just doesn't make sense to check multiple pkgsrc installations at once.
type Pkgsrc struct {
	// The top directory (PKGSRCDIR), either absolute or relative to
	// the current working directory.
	topdir string

	// The set of user-defined variables that are added to BUILD_DEFS
	// within the bsd.pkg.mk file.
	buildDefs map[string]bool

	Tools ToolRegistry

	MasterSiteURLToVar map[string]string // "https://github.com/" => "MASTER_SITE_GITHUB"
	MasterSiteVarToURL map[string]string // "MASTER_SITE_GITHUB" => "https://github.com/"

	PkgOptions map[string]string // "x11" => "Provides X11 support"

	suggestedUpdates    []SuggestedUpdate  //
	suggestedWipUpdates []SuggestedUpdate  //
	LastChange          map[string]*Change //
	latest              map[string]string  // "lang/php[0-9]*" => "lang/php70"

	UserDefinedVars map[string]MkLine   // varname => line; used for checking BUILD_DEFS
	Deprecated      map[string]string   //
	vartypes        map[string]*Vartype // varcanon => type

	Hashes       map[string]*Hash // Maps "alg:fname" => hash (inter-package check).
	UsedLicenses map[string]bool  // Maps "license name" => true (inter-package check).
}

func NewPkgsrc(dir string) *Pkgsrc {
	src := &Pkgsrc{
		dir,
		make(map[string]bool),
		NewToolRegistry(),
		make(map[string]string),
		make(map[string]string),
		make(map[string]string),
		nil,
		nil,
		make(map[string]*Change),
		make(map[string]string),
		make(map[string]MkLine),
		make(map[string]string),
		make(map[string]*Vartype),
		nil, // Only initialized when pkglint is run for a whole pkgsrc installation
		nil}

	// Some user-defined variables do not influence the binary
	// package at all and therefore do not have to be added to
	// BUILD_DEFS; therefore they are marked as "already added".
	src.AddBuildDef("DISTDIR")
	src.AddBuildDef("FETCH_CMD")
	src.AddBuildDef("FETCH_OUTPUT_ARGS")

	// The following variables are not expected to be modified
	// by the pkgsrc user. They are added here to prevent unnecessary
	// warnings by pkglint.
	src.AddBuildDef("GAMES_USER")
	src.AddBuildDef("GAMES_GROUP")
	src.AddBuildDef("GAMEDATAMODE")
	src.AddBuildDef("GAMEDIRMODE")
	src.AddBuildDef("GAMEMODE")
	src.AddBuildDef("GAMEOWN")
	src.AddBuildDef("GAMEGRP")

	return src
}

// LoadInfrastructure reads the pkgsrc infrastructure files to
// extract information like the tools, packages to update,
// user-defined variables.
//
// This work is not done in the constructor to keep the tests
// simple, since setting up a realistic pkgsrc environment requires
// a lot of files.
func (src *Pkgsrc) LoadInfrastructure() {
	src.InitVartypes()
	src.loadMasterSites()
	src.loadPkgOptions()
	src.loadDocChanges()
	src.loadSuggestedUpdates()
	src.loadUserDefinedVars()
	src.loadTools()
	src.initDeprecatedVars()
}

// Latest returns the latest package matching the given pattern.
// It searches the `category` for subdirectories matching the given
// regular expression, and returns the `repl` string, in which the
// placeholder is filled with the best result.
//
// Example:
//  Latest("lang", `^php[0-9]+$`, "../../lang/$0") => "../../lang/php72"
func (src *Pkgsrc) Latest(category string, re regex.Pattern, repl string) string {
	key := category + "/" + string(re) + " => " + repl
	if latest, found := src.latest[key]; found {
		return latest
	}

	if src.latest == nil {
		src.latest = make(map[string]string)
	}

	categoryDir := src.File(category)
	error := func() string {
		dummyLine.Errorf("Cannot find latest version of %q in %q.", re, categoryDir)
		src.latest[key] = ""
		return ""
	}

	all, err := ioutil.ReadDir(categoryDir)
	sort.SliceStable(all, func(i, j int) bool {
		return naturalLess(all[i].Name(), all[j].Name())
	})
	if err != nil {
		return error()
	}

	latest := ""
	for _, fileInfo := range all {
		if matches(fileInfo.Name(), re) {
			latest = regex.Compile(re).ReplaceAllString(fileInfo.Name(), repl)
		}
	}
	if latest == "" {
		return error()
	}

	src.latest[key] = latest
	return latest
}

// loadTools loads the tool definitions from `mk/tools/*`.
func (src *Pkgsrc) loadTools() {
	toolFiles := []string{"defaults.mk"}
	{
		toc := G.Pkgsrc.File("mk/tools/bsd.tools.mk")
		mklines := LoadMk(toc, MustSucceed|NotEmpty)
		for _, mkline := range mklines.mklines {
			if mkline.IsInclude() {
				includefile := mkline.IncludeFile()
				if !contains(includefile, "/") {
					toolFiles = append(toolFiles, includefile)
				}
			}
		}
		if len(toolFiles) <= 1 {
			NewLine(toc, 0, "", nil).Fatalf("Too few tool files.")
		}
	}

	reg := src.Tools
	reg.RegisterTool(&Tool{"echo", "ECHO", true, true, true}, dummyMkLine)
	reg.RegisterTool(&Tool{"echo -n", "ECHO_N", true, true, true}, dummyMkLine)
	reg.RegisterTool(&Tool{"false", "FALSE", true /*why?*/, true, false}, dummyMkLine)
	reg.RegisterTool(&Tool{"test", "TEST", true, true, true}, dummyMkLine)
	reg.RegisterTool(&Tool{"true", "TRUE", true /*why?*/, true, true}, dummyMkLine)

	for _, basename := range toolFiles {
		mklines := G.Pkgsrc.LoadMk("mk/tools/"+basename, MustSucceed|NotEmpty)
		for _, mkline := range mklines.mklines {
			reg.ParseToolLine(mkline)
		}
	}

	for _, relativeName := range [...]string{"mk/bsd.prefs.mk", "mk/bsd.pkg.mk"} {
		dirDepth := 0

		mklines := G.Pkgsrc.LoadMk(relativeName, MustSucceed|NotEmpty)
		for _, mkline := range mklines.mklines {
			if mkline.IsVarassign() {
				varname := mkline.Varname()
				value := mkline.Value()
				if varname == "USE_TOOLS" {
					if trace.Tracing {
						trace.Stepf("[dirDepth=%d] %s", dirDepth, value)
					}
					if dirDepth == 0 || dirDepth == 1 && relativeName == "mk/bsd.prefs.mk" {
						for _, toolname := range splitOnSpace(value) {
							if !containsVarRef(toolname) {
								tool := reg.Register(toolname, mkline)
								tool.Predefined = true
								if relativeName == "mk/bsd.prefs.mk" {
									tool.UsableAtLoadTime = true
								}
							}
						}
					}

				} else if varname == "_BUILD_DEFS" {
					for _, bdvar := range splitOnSpace(value) {
						src.AddBuildDef(bdvar)
					}
				}

			} else if mkline.IsDirective() {
				switch mkline.Directive() {
				case "if", "ifdef", "ifndef", "for":
					dirDepth++
				case "endif", "endfor":
					dirDepth--
				}
			}
		}
	}

	if trace.Tracing {
		reg.Trace()
	}
}

func (src *Pkgsrc) parseSuggestedUpdates(lines []Line) []SuggestedUpdate {
	var updates []SuggestedUpdate
	state := 0
	for _, line := range lines {
		text := line.Text

		if state == 0 && text == "Suggested package updates" {
			state = 1
		} else if state == 1 && text == "" {
			state = 2
		} else if state == 2 {
			state = 3
		} else if state == 3 && text == "" {
			state = 4
		}

		if state == 3 {
			if m, pkgname, comment := match2(text, `^\to\s(\S+)(?:\s*(.+))?$`); m {
				if m, pkgbase, pkgversion := match2(pkgname, rePkgname); m {
					updates = append(updates, SuggestedUpdate{line, pkgbase, pkgversion, comment})
				} else {
					line.Warnf("Invalid package name %q", pkgname)
				}
			} else {
				line.Warnf("Invalid line format %q", text)
			}
		}
	}
	return updates
}

func (src *Pkgsrc) loadSuggestedUpdates() {
	src.suggestedUpdates = src.parseSuggestedUpdates(Load(G.Pkgsrc.File("doc/TODO"), MustSucceed))
	src.suggestedWipUpdates = src.parseSuggestedUpdates(Load(G.Pkgsrc.File("wip/TODO"), NotEmpty))
}

func (src *Pkgsrc) loadDocChangesFromFile(fname string) []*Change {

	parseChange := func(line Line) *Change {
		text := line.Text
		if !hasPrefix(text, "\t") {
			return nil
		}

		f := strings.Fields(text)
		n := len(f)
		if n != 4 && n != 6 {
			return nil
		}

		action, pkgpath, author, date := f[0], f[1], f[len(f)-2], f[len(f)-1]
		if !hasPrefix(author, "[") || !hasSuffix(date, "]") {
			return nil
		}
		author, date = author[1:], date[:len(date)-1]

		switch {
		case action == "Added" && f[2] == "version" && n == 6:
			return &Change{line, action, pkgpath, f[3], author, date}
		case (action == "Updated" || action == "Downgraded") && f[2] == "to" && n == 6:
			return &Change{line, action, pkgpath, f[3], author, date}
		case action == "Removed" && (n == 6 && f[2] == "successor" || n == 4):
			return &Change{line, action, pkgpath, "", author, date}
		case (action == "Renamed" || action == "Moved") && f[2] == "to" && n == 6:
			return &Change{line, action, pkgpath, "", author, date}
		}
		return nil
	}

	year := ""
	if m, yyyy := match1(fname, `-(\d+)$`); m && yyyy >= "2018" {
		year = yyyy
	}

	lines := Load(fname, MustSucceed|NotEmpty)
	var changes []*Change
	for _, line := range lines {
		if change := parseChange(line); change != nil {
			changes = append(changes, change)
			if year != "" && change.Date[0:4] != year {
				line.Warnf("Year %s for %s does not match the file name %s.", change.Date[0:4], change.Pkgpath, fname)
			}
			if len(changes) >= 2 && year != "" {
				if prev := changes[len(changes)-2]; change.Date < prev.Date {
					line.Warnf("Date %s for %s is earlier than %s for %s.", change.Date, change.Pkgpath, prev.Date, prev.Pkgpath)
					Explain(
						"The entries in doc/CHANGES should be in chronological order, and",
						"all dates are assumed to be in the UTC timezone, to prevent time",
						"warps.",
						"",
						"To fix this, determine which of the involved dates are correct",
						"and which aren't.",
						"",
						"To prevent this kind of mistakes in the future, make sure that",
						"your system time is correct and use \""+confMake+" cce\" to commit",
						"the changes entry.")
				}
			}
		} else if text := line.Text; len(text) >= 2 && text[0] == '\t' && 'A' <= text[1] && text[1] <= 'Z' {
			line.Warnf("Unknown doc/CHANGES line: %q", text)
			Explain("See mk/misc/developer.mk for the rules.")
		}
	}
	return changes
}

func (src *Pkgsrc) GetSuggestedPackageUpdates() []SuggestedUpdate {
	if G.Wip {
		return src.suggestedWipUpdates
	} else {
		return src.suggestedUpdates
	}
}

func (src *Pkgsrc) loadDocChanges() {
	docdir := G.Pkgsrc.File("doc")
	files, err := ioutil.ReadDir(docdir)
	if err != nil {
		NewLineWhole(docdir).Fatalf("Cannot be read.")
	}

	var fnames []string
	for _, file := range files {
		fname := file.Name()
		if matches(fname, `^CHANGES-20\d\d$`) && fname >= "CHANGES-2011" {
			fnames = append(fnames, fname)
		}
	}

	sort.Strings(fnames)
	src.LastChange = make(map[string]*Change)
	for _, fname := range fnames {
		changes := src.loadDocChangesFromFile(docdir + "/" + fname)
		for _, change := range changes {
			src.LastChange[change.Pkgpath] = change
		}
	}
}

func (src *Pkgsrc) loadUserDefinedVars() {
	mklines := G.Pkgsrc.LoadMk("mk/defaults/mk.conf", MustSucceed|NotEmpty)

	for _, mkline := range mklines.mklines {
		if mkline.IsVarassign() {
			src.UserDefinedVars[mkline.Varname()] = mkline
		}
	}
}

func (src *Pkgsrc) initDeprecatedVars() {
	src.Deprecated = map[string]string{
		// December 2003
		"FIX_RPATH": "It has been removed from pkgsrc in 2003.",

		// February 2005
		"LIB_DEPENDS":    "Use DEPENDS instead.",
		"ONLY_FOR_ARCHS": "Use ONLY_FOR_PLATFORM instead.",
		"NOT_FOR_ARCHS":  "Use NOT_FOR_PLATFORM instead.",
		"ONLY_FOR_OPSYS": "Use ONLY_FOR_PLATFORM instead.",
		"NOT_FOR_OPSYS":  "Use NOT_FOR_PLATFORM instead.",

		// May 2005
		"ALL_TARGET":         "Use BUILD_TARGET instead.",
		"DIGEST_FILE":        "Use DISTINFO_FILE instead.",
		"IGNORE":             "Use PKG_FAIL_REASON or PKG_SKIP_REASON instead.",
		"IS_INTERACTIVE":     "Use INTERACTIVE_STAGE instead.",
		"KERBEROS":           "Use the PKG_OPTIONS framework instead.",
		"MASTER_SITE_SUBDIR": "Use some form of MASTER_SITES instead.",
		"MD5_FILE":           "Use DISTINFO_FILE instead.",
		"MIRROR_DISTFILE":    "Use NO_BIN_ON_FTP and/or NO_SRC_ON_FTP instead.",
		"NO_CDROM":           "Use NO_BIN_ON_CDROM and/or NO_SRC_ON_CDROM instead.",
		"NO_PATCH":           "You can just remove it.",
		"NO_WRKSUBDIR":       "Use WRKSRC=${WRKDIR} instead.",
		"PATCH_SITE_SUBDIR":  "Use some form of PATCHES_SITES instead.",
		"PATCH_SUM_FILE":     "Use DISTINFO_FILE instead.",
		"PKG_JVM":            "Use PKG_DEFAULT_JVM instead.",
		"USE_BUILDLINK2":     "You can just remove it.",
		"USE_BUILDLINK3":     "You can just remove it.",
		"USE_CANNA":          "Use the PKG_OPTIONS framework instead.",
		"USE_DB4":            "Use the PKG_OPTIONS framework instead.",
		"USE_DIRS":           "You can just remove it.",
		"USE_ESOUND":         "Use the PKG_OPTIONS framework instead.",
		"USE_GIF":            "Use the PKG_OPTIONS framework instead.",
		"USE_GMAKE":          "Use USE_TOOLS+=gmake instead.",
		"USE_GNU_TOOLS":      "Use USE_TOOLS instead.",
		"USE_IDEA":           "Use the PKG_OPTIONS framework instead.",
		"USE_LIBCRACK":       "Use the PKG_OPTIONS framework instead.",
		"USE_MMX":            "Use the PKG_OPTIONS framework instead.",
		"USE_PKGLIBTOOL":     "Use USE_LIBTOOL instead.",
		"USE_SSL":            "Include \"../../security/openssl/buildlink3.mk\" instead.",

		// July 2005
		"USE_PERL5": "Use USE_TOOLS+=perl or USE_TOOLS+=perl:run instead.",

		// October 2005
		"NO_TOOLS":   "You can just remove it.",
		"NO_WRAPPER": "You can just remove it.",

		// November 2005
		"ALLFILES":       "Use CKSUMFILES instead.",
		"DEPENDS_TARGET": "Use DEPENDS instead.",
		"FETCH_DEPENDS":  "Use DEPENDS instead.",
		"RUN_DEPENDS":    "Use DEPENDS instead.",

		// December 2005
		"USE_CUPS":     "Use the PKG_OPTIONS framework (option cups) instead.",
		"USE_I586":     "Use the PKG_OPTIONS framework (option i586) instead.",
		"USE_INN":      "Use the PKG_OPTIONS framework instead.",
		"USE_OPENLDAP": "Use the PKG_OPTIONS framework (option openldap) instead.",
		"USE_OSS":      "Use the PKG_OPTIONS framework (option oss) instead.",
		"USE_RSAREF2":  "Use the PKG_OPTIONS framework (option rsaref) instead.",
		"USE_SASL":     "Use the PKG_OPTIONS framework (option sasl) instead.",
		"USE_SASL2":    "Use the PKG_OPTIONS framework (option sasl) instead.",
		"USE_SJ3":      "Use the PKG_OPTIONS framework (option sj3) instead.",
		"USE_SOCKS":    "Use the PKG_OPTIONS framework (socks4 and socks5 options) instead.",
		"USE_WNN4":     "Use the PKG_OPTIONS framework (option wnn4) instead.",
		"USE_XFACE":    "Use the PKG_OPTIONS framework instead.",

		// February 2006
		"TOOLS_DEPMETHOD":     "Use the :build or :run modifiers in USE_TOOLS instead.",
		"MANDIR":              "Please use ${PREFIX}/${PKGMANDIR} instead.",
		"DOWNLOADED_DISTFILE": "Use the shell variable $$extract_file instead.",
		"DECOMPRESS_CMD":      "Use EXTRACT_CMD instead.",

		// March 2006
		"INSTALL_EXTRA_TMPL":   "Use INSTALL_TEMPLATE instead.",
		"DEINSTALL_EXTRA_TMPL": "Use DEINSTALL_TEMPLATE instead.",

		// April 2006
		"RECOMMENDED":        "Use ABI_DEPENDS instead.",
		"BUILD_USES_MSGFMT":  "Use USE_TOOLS+=msgfmt instead.",
		"USE_MSGFMT_PLURALS": "Use USE_TOOLS+=msgfmt instead.",

		// May 2006
		"EXTRACT_USING_PAX":       "Use \"EXTRACT_OPTS=-t pax\" instead.",
		"NO_EXTRACT":              "It doesn't exist anymore.",
		"_FETCH_MESSAGE":          "Use FETCH_MESSAGE (different format) instead.",
		"BUILDLINK_DEPENDS.*":     "Use BUILDLINK_API_DEPENDS.* instead.",
		"BUILDLINK_RECOMMENDED.*": "Use BUILDLINK_ABI_DEPENDS.* instead.",
		"SHLIB_HANDLING":          "Use CHECK_SHLIBS_SUPPORTED instead.",
		"USE_RMAN":                "It has been removed.",

		// June 2006
		"DEINSTALL_SRC":      "Use the pkginstall framework instead.",
		"INSTALL_SRC":        "Use the pkginstall framework instead.",
		"DEINSTALL_TEMPLATE": "Use DEINSTALL_TEMPLATES instead.",
		"INSTALL_TEMPLATE":   "Use INSTALL_TEMPLATES instead.",
		"HEADER_TEMPLATE":    "Use HEADER_TEMPLATES instead.",
		"_REPLACE.*":         "Use REPLACE.* instead.",
		"_REPLACE_FILES.*":   "Use REPLACE_FILES.* instead.",
		"MESSAGE":            "Use MESSAGE_SRC instead.",
		"INSTALL_FILE":       "It may only be used internally by pkgsrc.",
		"DEINSTALL_FILE":     "It may only be used internally by pkgsrc.",

		// July 2006
		"USE_DIGEST":           "You can just remove it.",
		"LTCONFIG_OVERRIDE":    "You can just remove it.",
		"USE_GNU_GETTEXT":      "You can just remove it.",
		"BUILD_ENV":            "Use PKGSRC_MAKE_ENV instead.",
		"DYNAMIC_MASTER_SITES": "You can just remove it.",

		// September 2006
		"MAKEFILE": "Use MAKE_FILE instead.",

		// November 2006
		"SKIP_PORTABILITY_CHECK": "Use CHECK_PORTABILITY_SKIP (a list of patterns) instead.",

		// January 2007
		"BUILDLINK_TRANSFORM.*": "Use BUILDLINK_FNAME_TRANSFORM.* instead.",

		// March 2007
		"SCRIPTDIR":       "You can just remove it.",
		"NO_PKG_REGISTER": "You can just remove it.",
		"NO_DEPENDS":      "You can just remove it.",

		// October 2007
		"_PKG_SILENT": "Use RUN (with more error checking) instead.",
		"_PKG_DEBUG":  "Use RUN (with more error checking) instead.",
		"LICENCE":     "Use LICENSE instead.",

		// November 2007
		//USE_NCURSES		Include "../../devel/ncurses/buildlink3.mk" instead.

		// December 2007
		"INSTALLATION_DIRS_FROM_PLIST": "Use AUTO_MKDIRS instead.",

		// April 2009
		"NO_PACKAGE": "It doesn't exist anymore.",
		"NO_MTREE":   "You can just remove it.",

		// July 2012
		"SETGIDGAME": "Use USE_GAMESGROUP instead.",
		"GAMEGRP":    "Use GAMES_GROUP instead.",
		"GAMEOWN":    "Use GAMES_USER instead.",

		// July 2013
		"USE_GNU_READLINE": "Include \"../../devel/readline/buildlink3.mk\" instead.",

		// October 2014
		"SVR4_PKGNAME":           "Just remove it.",
		"PKG_INSTALLATION_TYPES": "Just remove it.",

		// January 2016
		"SUBST_POSTCMD.*": "Has been removed, as it seemed unused.",

		// June 2016
		"USE_CROSSBASE": "Has been removed.",
	}
}

// Load loads the file relative to the pkgsrc top directory.
func (src *Pkgsrc) Load(fileName string, options LoadOptions) []Line {
	return Load(src.File(fileName), options)
}

// LoadMk loads the Makefile relative to the pkgsrc top directory.
func (src *Pkgsrc) LoadMk(fileName string, options LoadOptions) *MkLines {
	return LoadMk(src.File(fileName), options)
}

// File resolves a file name relative to the pkgsrc top directory.
//
// Example:
//  NewPkgsrc("/usr/pkgsrc").File("distfiles") => "/usr/pkgsrc/distfiles"
func (src *Pkgsrc) File(relativeName string) string {
	return cleanpath(src.topdir + "/" + relativeName)
}

// ToRel returns the path of `fileName`, relative to the pkgsrc top directory.
//
// Example:
//  NewPkgsrc("/usr/pkgsrc").ToRel("/usr/pkgsrc/distfiles") => "distfiles"
func (src *Pkgsrc) ToRel(fileName string) string {
	return relpath(src.topdir, fileName)
}

func (src *Pkgsrc) AddBuildDef(varname string) {
	src.buildDefs[varname] = true
}

func (src *Pkgsrc) IsBuildDef(varname string) bool {
	return src.buildDefs[varname]
}

func (src *Pkgsrc) loadMasterSites() {
	mklines := src.LoadMk("mk/fetch/sites.mk", MustSucceed|NotEmpty)

	nameToUrl := src.MasterSiteVarToURL
	urlToName := src.MasterSiteURLToVar
	for _, mkline := range mklines.mklines {
		if mkline.IsVarassign() {
			varname := mkline.Varname()
			if hasPrefix(varname, "MASTER_SITE_") && varname != "MASTER_SITE_BACKUP" {
				for _, url := range splitOnSpace(mkline.Value()) {
					if matches(url, `^(?:http://|https://|ftp://)`) {
						if nameToUrl[varname] == "" {
							nameToUrl[varname] = url
						}
						urlToName[url] = varname
					}
				}
			}
		}
	}

	// Explicitly allowed, although not defined in mk/fetch/sites.mk.
	nameToUrl["MASTER_SITE_LOCAL"] = "ftp://ftp.NetBSD.org/pub/pkgsrc/distfiles/LOCAL_PORTS/"

	if trace.Tracing {
		trace.Stepf("Loaded %d MASTER_SITE_* URLs.", len(urlToName))
	}
}

func (src *Pkgsrc) loadPkgOptions() {
	lines := src.Load("mk/defaults/options.description", MustSucceed)

	for _, line := range lines {
		if m, optname, optdescr := match2(line.Text, `^([-0-9a-z_+]+)(?:\s+(.*))?$`); m {
			src.PkgOptions[optname] = optdescr
		} else {
			line.Fatalf("Unknown line format.")
		}
	}
}

// Change is a change entry from the `doc/CHANGES-*` files.
type Change struct {
	Line    Line
	Action  string
	Pkgpath string
	Version string
	Author  string
	Date    string
}

// SuggestedUpdate is from the `doc/TODO` file.
type SuggestedUpdate struct {
	Line    Line
	Pkgname string
	Version string
	Comment string
}
