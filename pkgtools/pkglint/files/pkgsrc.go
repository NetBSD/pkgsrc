package pkglint

import (
	"netbsd.org/pkglint/pkgver"
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/textproc"
	"os"
	"path/filepath"
	"sort"
	"strings"
)

// Pkgsrc describes a pkgsrc installation.
// In each pkglint run, only a single pkgsrc installation is ever loaded.
// It just doesn't make sense to check multiple pkgsrc installations at once.
//
// This type only contains data that is loaded once and then stays constant.
// Everything else (distfile hashes, package names) is recorded in the
// InterPackage type instead.
type Pkgsrc struct {
	// The top directory (PKGSRCDIR).
	topdir CurrPath

	// The set of user-defined variables that are added to BUILD_DEFS
	// within the bsd.pkg.mk file.
	buildDefs map[string]bool

	Tools *Tools

	MasterSiteURLToVar map[string]string // "github.com/" => "MASTER_SITE_GITHUB"
	MasterSiteVarToURL map[string]string // "MASTER_SITE_GITHUB" => "https://github.com/"

	PkgOptions map[string]string // "x11" => "Provides X11 support"

	suggestedUpdates    []SuggestedUpdate
	suggestedWipUpdates []SuggestedUpdate

	LastChange      map[PkgsrcPath]*Change
	LastFreezeStart string // e.g. "2018-01-01", or ""
	LastFreezeEnd   string // e.g. "2018-01-01", or ""

	listVersions map[string][]string // See Pkgsrc.ListVersions

	// Variables that may be overridden by the pkgsrc user.
	// They are typically defined in mk/defaults/mk.conf.
	//
	// Whenever a package uses such a variable, it must add the variable name
	// to BUILD_DEFS.
	UserDefinedVars Scope

	Deprecated map[string]string
	vartypes   VarTypeRegistry
}

func NewPkgsrc(dir CurrPath) Pkgsrc {
	return Pkgsrc{
		dir,
		make(map[string]bool),
		NewTools(),
		make(map[string]string),
		make(map[string]string),
		make(map[string]string),
		nil,
		nil,
		make(map[PkgsrcPath]*Change),
		"",
		"",
		make(map[string][]string),
		NewScope(),
		make(map[string]string),
		NewVarTypeRegistry()}
}

// LoadInfrastructure reads the pkgsrc infrastructure files to
// extract information like the tools, packages to update,
// user-defined variables.
//
// This work is not done in the constructor to keep the tests
// simple, since setting up a realistic pkgsrc environment requires
// a lot of files.
func (src *Pkgsrc) LoadInfrastructure() {
	src.vartypes.Init(src)
	src.loadMasterSites()
	src.loadPkgOptions()
	src.loadDocChanges()
	src.loadSuggestedUpdates()
	src.loadUserDefinedVars()
	src.loadTools()
	src.initDeprecatedVars()
	src.loadUntypedVars()
	src.loadDefaultBuildDefs()
}

func (src *Pkgsrc) loadMasterSites() {
	mklines := src.LoadMk("mk/fetch/sites.mk", MustSucceed|NotEmpty)

	for _, mkline := range mklines.mklines {
		if !mkline.IsVarassign() {
			continue
		}
		varname := mkline.Varname()

		// MASTER_SITE_BACKUP is only used internally and should
		// not appear in package definitions since it is not the
		// primary, official source for getting the files.
		if varname == "MASTER_SITE_BACKUP" {
			continue
		}
		if !hasPrefix(varname, "MASTER_SITE_") {
			continue
		}

		for _, url := range mkline.ValueFields(mkline.Value()) {
			if matches(url, `^(?:http://|https://|ftp://)`) {
				src.registerMasterSite(varname, url)
			}
		}
	}

	// Explicitly allowed, although not defined in mk/fetch/sites.mk.
	// It is defined in mk/fetch/fetch.mk instead.
	src.registerMasterSite("MASTER_SITE_LOCAL", "ftp://ftp.NetBSD.org/pub/pkgsrc/distfiles/LOCAL_PORTS/")

	if trace.Tracing {
		trace.Stepf("Loaded %d MASTER_SITE_* URLs.", len(src.MasterSiteURLToVar))
	}
}

func (src *Pkgsrc) registerMasterSite(varname, url string) {
	nameToURL := src.MasterSiteVarToURL
	urlToName := src.MasterSiteURLToVar

	if nameToURL[varname] == "" {
		nameToURL[varname] = url
	}
	urlToName[replaceAll(url, `^\w+://`, "")] = varname
}

func (src *Pkgsrc) loadPkgOptions() {
	lines := src.Load("mk/defaults/options.description", MustSucceed)

	for _, line := range lines.Lines {
		if m, name, description := match2(line.Text, `^([-0-9a-z_+]+)(?:[\t ]+(.*))?$`); m {
			src.PkgOptions[name] = description
		} else {
			line.Errorf("Invalid line format: %s", line.Text)
		}
	}
}

func (src *Pkgsrc) loadDocChanges() {
	docDir := src.File("doc")
	files := src.ReadDir("doc")
	if len(files) == 0 {
		G.Logger.TechFatalf(docDir, "Cannot be read for loading the package changes.")
	}

	var filenames []RelPath
	for _, file := range files {
		filename := file.Name()
		// Files before 2011 are too far in the past to be still relevant today.
		if matches(filename, `^CHANGES-20\d\d$`) && filename >= "CHANGES-2011" {
			filenames = append(filenames, NewRelPathString(filename))
		}
	}

	src.LastChange = make(map[PkgsrcPath]*Change)
	for _, filename := range filenames {
		changes := src.loadDocChangesFromFile(docDir.JoinNoClean(filename))
		for _, change := range changes {
			src.LastChange[change.Pkgpath] = change
			if change.Action == Renamed || change.Action == Moved {
				src.LastChange[change.Target()] = change
			}
		}
	}

	src.checkRemovedAfterLastFreeze()
}

func (src *Pkgsrc) loadDocChangesFromFile(filename CurrPath) []*Change {

	warn := G.CheckGlobal && !G.Wip

	// Each date in the file should be from the same year as the filename says.
	// This check has been added in 2018.
	// For years earlier than 2018 pkglint doesn't care because it's not a big issue anyway.
	year := ""
	if _, yyyy := match1(filename.Base().String(), `-(\d\d\d\d)$`); yyyy >= "2018" {
		year = yyyy
	}

	latest := make(map[PkgsrcPath]*Change)

	infra := false
	lines := Load(filename, MustSucceed|NotEmpty)
	var changes []*Change
	for _, line := range lines.Lines {

		if hasPrefix(line.Text, "\tmk/") {
			infra = true
			if hasPrefix(line.Text, "\tmk/bsd.pkg.mk: started freeze for") {
				if m, date := match1(line.Text, `(\d\d\d\d-\d\d-\d\d)\]$`); m {
					src.LastFreezeStart = date
					src.LastFreezeEnd = ""
				}
			} else if hasPrefix(line.Text, "\tmk/bsd.pkg.mk: freeze ended for") {
				if m, date := match1(line.Text, `(\d\d\d\d-\d\d-\d\d)\]$`); m {
					src.LastFreezeEnd = date
				}
			}
		}
		if infra {
			if hasSuffix(line.Text, "]") {
				infra = false
			}
			continue
		}

		change := src.parseDocChange(line, warn)
		if change == nil {
			continue
		}

		changes = append(changes, change)

		if !warn {
			continue
		}

		src.checkChangeVersion(change, latest, line)
		src.checkChangeDate(filename, year, change, line, changes)
	}

	return changes
}

func (src *Pkgsrc) checkChangeVersion(change *Change, latest map[PkgsrcPath]*Change, line *Line) {
	switch change.Action {

	case Added:
		src.checkChangeVersionNumber(change, line)
		existing := latest[change.Pkgpath]
		if existing != nil && existing.Version() == change.Version() {
			line.Warnf("Package %q was already added in %s.",
				change.Pkgpath.String(), line.RelLocation(existing.Location))
		}
		latest[change.Pkgpath] = change

	case Updated:
		src.checkChangeVersionNumber(change, line)
		existing := latest[change.Pkgpath]
		if existing != nil && pkgver.Compare(change.Version(), existing.Version()) <= 0 {
			line.Warnf("Updating %q from %s in %s to %s should increase the version number.",
				change.Pkgpath.String(), existing.Version(), line.RelLocation(existing.Location), change.Version())
		}
		latest[change.Pkgpath] = change

	case Downgraded:
		src.checkChangeVersionNumber(change, line)
		existing := latest[change.Pkgpath]
		if existing != nil && pkgver.Compare(change.Version(), existing.Version()) >= 0 {
			line.Warnf("Downgrading %q from %s in %s to %s should decrease the version number.",
				change.Pkgpath.String(), existing.Version(), line.RelLocation(existing.Location), change.Version())
		}
		latest[change.Pkgpath] = change

	case Renamed, Moved, Removed:
		latest[change.Pkgpath] = nil
	}
}

func (src *Pkgsrc) checkChangeVersionNumber(change *Change, line *Line) {
	version := change.Version()

	switch {
	case !textproc.NewLexer(version).TestByteSet(textproc.Digit):
		line.Warnf("Version number %q should start with a digit.", version)

	// See rePkgname for the regular expression.
	case !matches(version, `^([0-9][.\-0-9A-Z_a-z]*)$`):
		line.Warnf("Malformed version number %q.", version)
	}
}

func (src *Pkgsrc) checkChangeDate(filename CurrPath, year string, change *Change, line *Line, changes []*Change) {
	if year != "" && change.Date[0:4] != year {
		line.Warnf("Year %q for %s does not match the filename %s.",
			change.Date[0:4], change.Pkgpath.String(), line.Rel(filename))
	}

	if len(changes) >= 2 && year != "" {
		if prev := changes[len(changes)-2]; change.Date < prev.Date {
			line.Warnf("Date %q for %s is earlier than %q in %s.",
				change.Date, change.Pkgpath.String(), prev.Date, line.RelLocation(prev.Location))
			line.Explain(
				"The entries in doc/CHANGES should be in chronological order, and",
				"all dates are assumed to be in the UTC timezone, to prevent time",
				"warps.",
				"",
				"To fix this, determine which of the involved dates are correct",
				"and which aren't.",
				"",
				"To prevent this kind of mistakes in the future,",
				"make sure that your system time is correct and run",
				sprintf("%q", bmake("cce")),
				"to commit the changes entry.")
		}
	}
}

func (*Pkgsrc) parseDocChange(line *Line, warn bool) *Change {
	lex := textproc.NewLexer(line.Text)

	space := lex.NextHspace()
	if space == "" {
		return nil
	}

	if space != "\t" {
		if warn {
			line.Warnf("Package changes should be indented using a single tab, not %q.", space)
			line.Explain(
				"To avoid this formatting mistake in the future, just run",
				sprintf("%q", bmake("cce")),
				"after committing the update to the package.")
		}

		return nil
	}

	invalid := func() *Change {
		if warn {
			line.Warnf("Invalid doc/CHANGES line: %s", line.Text)
			line.Explain(
				"See mk/misc/developer.mk for the rules.",
				"",
				"To generate these entries automatically, run",
				sprintf("%q.", bmakeHelp("cce")))
		}
		return nil
	}

	f := strings.Fields(lex.Rest())
	n := len(f)
	if n > 1 && hasSuffix(f[0], ":") {
		return nil
	}
	if n == 0 {
		return invalid()
	}

	action := ParseChangeAction(f[0])
	var pkgpath, author, date string
	if n > 1 {
		pkgpath = f[1]
		date = f[n-1]
	}
	if n > 2 {
		author = f[n-2]
	}

	if !matches(author, `^\[\w+$`) || !matches(date, `\d\d\d\d-\d\d-\d\d]$`) {
		return invalid()
	}
	author, date = author[1:], date[:len(date)-1]

	switch {
	case
		action == Added && f[2] == "version",
		action == Updated && f[2] == "to",
		action == Downgraded && f[2] == "to",
		action == Removed && (f[2] == "successor" || n == 4),
		(action == Renamed || action == Moved) && f[2] == "to":
		return &Change{
			Location: line.Location,
			Action:   action,
			Pkgpath:  NewPkgsrcPath(NewPath(intern(pkgpath))),
			target:   intern(condStr(n == 6, f[3], "")),
			Author:   intern(author),
			Date:     intern(date),
		}
	}

	return invalid()
}

func (src *Pkgsrc) checkRemovedAfterLastFreeze() {
	if src.LastFreezeStart == "" || G.Wip || !G.CheckGlobal {
		return
	}

	var wrong []*Change
	for pkgpath, change := range src.LastChange {
		switch change.Action {
		case Added, Updated, Downgraded:
			if !src.File(pkgpath).IsDir() {
				wrong = append(wrong, change)
			}
		}
	}

	sort.Slice(wrong, func(i, j int) bool { return wrong[i].IsAbove(wrong[j]) })

	for _, change := range wrong {
		// The original line of the change is not available anymore.
		// Therefore it is necessary to load the whole file again.
		lines := Load(change.Location.Filename, MustSucceed)
		line := lines.Lines[change.Location.lineno-1]
		line.Errorf("Package %s must either exist or be marked as removed.", change.Pkgpath.String())
	}
}

func (src *Pkgsrc) loadSuggestedUpdates() {
	src.suggestedUpdates = src.parseSuggestedUpdates(Load(src.File("doc/TODO"), MustSucceed))
	src.suggestedWipUpdates = src.parseSuggestedUpdates(Load(src.File("wip/TODO"), NotEmpty))
}

func (src *Pkgsrc) parseSuggestedUpdates(lines *Lines) []SuggestedUpdate {
	if lines == nil {
		return nil
	}

	var updates []SuggestedUpdate

	llex := NewLinesLexer(lines)
	for !llex.EOF() && !llex.SkipText("Suggested package updates") {
		llex.Skip()
	}
	for !llex.EOF() && !llex.SkipText("") {
		llex.Skip()
	}
	for llex.SkipText("") {
	}

	for !llex.EOF() && !llex.SkipText("") {
		line := llex.CurrentLine()
		text := line.Text
		llex.Skip()

		if m, pkgname, comment := match2(text, `^\to[\t ]([^\t ]+)(?:[\t ]*(.+))?$`); m {
			if m, pkgbase, pkgversion := match2(pkgname, rePkgname); m {
				if hasPrefix(comment, "[") && hasSuffix(comment, "]") {
					comment = comment[1 : len(comment)-1]
				}
				updates = append(updates, SuggestedUpdate{line.Location, intern(pkgbase), intern(pkgversion), intern(comment)})
			} else {
				line.Warnf("Invalid package name %q.", pkgname)
			}
		} else {
			line.Warnf("Invalid line format %q.", text)
		}
	}
	return updates
}

func (src *Pkgsrc) loadUserDefinedVars() {
	mklines := src.LoadMk("mk/defaults/mk.conf", MustSucceed|NotEmpty)

	for _, mkline := range mklines.mklines {
		if mkline.IsVarassignMaybeCommented() {
			src.UserDefinedVars.Define(mkline.Varname(), mkline)
		}
	}
}

// loadTools loads the tool definitions from `mk/tools/*`.
func (src *Pkgsrc) loadTools() {
	tools := src.Tools

	toolFiles := []RelPath{"defaults.mk"}
	{
		toc := src.File("mk/tools/bsd.tools.mk")
		mklines := LoadMk(toc, nil, MustSucceed|NotEmpty)
		for _, mkline := range mklines.mklines {
			if mkline.IsInclude() {
				includedFile := mkline.IncludedFile()
				if !includedFile.ContainsText("/") {
					toolFiles = append(toolFiles, includedFile)
				}
			}
		}
		if len(toolFiles) <= 1 {
			G.Logger.TechFatalf(toc, "Too few tool files.")
		}
	}

	// TODO: parse bsd.prefs.mk and bsd.pkg.mk instead of hardcoding this.
	tools.def("echo", "ECHO", true, AfterPrefsMk, nil)
	tools.def("echo -n", "ECHO_N", true, AfterPrefsMk, nil)
	tools.def("false", "FALSE", true, AtRunTime, nil) // from bsd.pkg.mk
	tools.def("test", "TEST", true, AfterPrefsMk, nil)
	tools.def("true", "TRUE", true, AfterPrefsMk, nil)

	for _, basename := range toolFiles {
		mklines := src.LoadMk(NewPkgsrcPath("mk/tools").JoinNoClean(basename), MustSucceed|NotEmpty)
		mklines.ForEach(func(mkline *MkLine) {
			conditional := mklines.indentation.IsConditional()
			tools.ParseToolLine(mklines, mkline, true, !conditional)
		})
	}

	for _, relativeName := range [...]PkgsrcPath{"mk/bsd.prefs.mk", "mk/bsd.pkg.mk"} {

		mklines := src.LoadMk(relativeName, MustSucceed|NotEmpty)
		mklines.ForEach(func(mkline *MkLine) {
			if mkline.IsVarassign() {
				varname := mkline.Varname()
				switch varname {
				case "USE_TOOLS":
					conditional := mklines.indentation.IsConditional()
					tools.ParseToolLine(mklines, mkline, true, !conditional)

				case "_BUILD_DEFS":
					// TODO: Compare with src.loadDefaultBuildDefs; is it redundant?
					for _, buildDefsVar := range mkline.Fields() {
						src.addBuildDefs(buildDefsVar)
					}
				}
			}
		})
	}

	src.loadToolsPlatform()

	if trace.Tracing {
		tools.Trace()
	}
}

func (src *Pkgsrc) loadToolsPlatform() {
	var systems []string
	scopes := make(map[string]*RedundantScope)
	for _, mkFile := range src.File("mk/tools").ReadPaths() {
		m, opsys := match1(mkFile.Base().String(), `^tools\.(.+)\.mk$`)
		if !m {
			continue
		}
		systems = append(systems, opsys)

		mklines := LoadMk(mkFile, nil, MustSucceed)
		scope := NewRedundantScope()
		// Suppress any warnings, just compute the variable state.
		scope.IsRelevant = func(*MkLine) bool { return false }
		scope.Check(mklines)
		scopes[opsys] = scope

		mklines.ForEach(func(mkline *MkLine) {
			if mkline.IsVarassign() && hasPrefix(mkline.Varname(), "TOOLS_PLATFORM.") {
				src.Tools.Define(mkline.Varparam(), "", mkline)
			}
		})
	}

	// 0 = undefined, 1 = conditional, 2 = definitely assigned
	type status int
	statusByNameAndOpsys := make(map[string]map[string]status)

	for opsys, scope := range scopes {
		for varname, varinfo := range scope.vars {
			if varnameCanon(varname) == "TOOLS_PLATFORM.*" {
				var s status
				if varinfo.vari.IsConditional() {
					if len(varinfo.vari.WriteLocations()) == 1 {
						s = 1
					} else {
						// TODO: Don't just count the number of assignments,
						//  check whether they definitely assign the variable.
						//  See substScope.
						s = 2
					}
				} else if varinfo.vari.IsConstant() {
					s = 2
				} else {
					continue
				}

				name := varnameParam(varname)
				if statusByNameAndOpsys[name] == nil {
					statusByNameAndOpsys[name] = make(map[string]status)
				}
				statusByNameAndOpsys[name][opsys] = s
			}
		}
	}

	for name, tool := range src.Tools.byName {
		undefined := make(map[string]bool)
		conditional := make(map[string]bool)
		for _, opsys := range systems {
			undefined[opsys] = true
			conditional[opsys] = true
		}
		for opsys, status := range statusByNameAndOpsys[name] {
			delete(undefined, opsys)
			if status == 2 {
				delete(conditional, opsys)
			}
		}
		tool.undefinedOn = keysSorted(undefined)
		tool.conditionalOn = keysSorted(conditional)
	}
}

func (src *Pkgsrc) addBuildDefs(varnames ...string) {
	for _, varname := range varnames {
		src.buildDefs[varname] = true
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
		// Only applies to BUILDLINK_TRANSFORM.${pkgbase}.
		// There is still BUILDLINK_TRANSFORM.${OPSYS}.
		// "BUILDLINK_TRANSFORM.*": "Use BUILDLINK_FNAME_TRANSFORM.* instead.",

		// March 2007
		"SCRIPTDIR":       "You can just remove it.",
		"NO_PKG_REGISTER": "You can just remove it.",
		"NO_DEPENDS":      "You can just remove it.",

		// October 2007
		"_PKG_SILENT": "Use RUN (with more error checking) instead.",
		"_PKG_DEBUG":  "Use RUN (with more error checking) instead.",
		"LICENCE":     "Use LICENSE instead.",

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

		// November 2015, commit abccb56
		"EVAL_PREFIX": "All packages are installed in PREFIX now.",

		// January 2016
		"SUBST_POSTCMD.*": "Has been removed, as it seemed unused.",

		// June 2016
		"USE_CROSSBASE": "Has been removed.",
	}
}

// loadUntypedVars scans all pkgsrc infrastructure files in mk/
// to find variable definitions that are not yet covered in
// Pkgsrc.InitVartypes.
//
// Even if pkglint cannot guess the type of each variable,
// at least prevent the "used but not defined" warnings.
func (src *Pkgsrc) loadUntypedVars() {

	// Setting guessed to false prevents the vartype.guessed case in MkLineChecker.CheckVaruse.
	unknownType := NewVartype(BtUnknown, NoVartypeOptions, NewACLEntry("*", aclpAll))

	define := func(varcanon string, mkline *MkLine) {
		switch {
		case src.vartypes.IsDefinedCanon(varcanon):
			// Already defined, can also be a tool.

		case !matches(varcanon, `^[A-Z]`):
			// This filters out several unwanted variables: empty strings,
			// punctuation, lowercase letters (that are used in .for loops),
			// dotted names (that are used in ${VAR:@f@${f}@}).

		case contains(varcanon, "$"):
			// Indirect, but not the usual parameterized form. Variables of
			// this form should not be unintentionally visible from outside
			// the infrastructure since they don't follow the pkgsrc naming
			// conventions.

		case hasSuffix(varcanon, "_MK"):
			// Multiple-inclusion guards are internal to the infrastructure.

		default:
			if trace.Tracing {
				trace.Stepf("Untyped variable %q in %s", varcanon, mkline)
			}
			src.vartypes.DefineType(varcanon, unknownType)
		}
	}

	handleMkFile := func(path CurrPath) {
		mklines := LoadMk(path, nil, MustSucceed)
		mklines.collectVariables()
		mklines.collectUsedVariables()
		mklines.allVars.forEach(func(varname string, data *scopeVar) {
			if data.firstDef != nil {
				define(varnameCanon(varname), data.firstDef)
			}
		})
		mklines.allVars.forEach(func(varname string, data *scopeVar) {
			if data.used != nil {
				define(varnameCanon(varname), data.used)
			}
		})
	}

	handleFile := func(pathName string, info os.FileInfo, err error) error {
		assertNil(err, "handleFile %q", pathName)
		baseName := info.Name()
		if info.Mode().IsRegular() && (hasSuffix(baseName, ".mk") || baseName == "mk.conf") {
			handleMkFile(NewCurrPathSlash(pathName))
		}
		return nil
	}

	err := filepath.Walk(src.File("mk").String(), handleFile)
	assertNil(err, "Walk error in pkgsrc infrastructure")
}

func (src *Pkgsrc) loadDefaultBuildDefs() {

	// Some user-defined variables do not influence the binary
	// package at all and therefore do not have to be added to
	// BUILD_DEFS; therefore they are marked as "already added".
	src.addBuildDefs(
		"DISTDIR",
		"FETCH_CMD",
		"FETCH_OUTPUT_ARGS",
		"FETCH_USING",
		"PKGSRC_RUN_TEST")

	// The following variables are used so often that not every
	// package should need to add it to BUILD_DEFS manually.
	src.addBuildDefs(
		"PKGSRC_COMPILER",
		"PKGSRC_USE_SSP",
		"UNPRIVILEGED",
		"USE_CROSS_COMPILE")

	// The following variables are so obscure that they are
	// probably not used in practice.
	src.addBuildDefs(
		"MANINSTALL")

	// The following variables are added to _BUILD_DEFS by the pkgsrc
	// infrastructure and thus don't need to be added by the package again.
	// To regenerate the below list:
	//  grep -hr '^_BUILD_DEFS+=' mk/ | tr ' \t' '\n\n' | sed -e 's,.*=,,' -e '/^_/d' -e '/^$/d' -e 's,.*,"&"\,,' | sort -u
	// TODO: Run the equivalent of the above command at startup.
	src.addBuildDefs(
		"ABI",
		"BUILTIN_PKGS",
		"CFLAGS",
		"CMAKE_ARGS",
		"CONFIGURE_ARGS",
		"CONFIGURE_ENV",
		"CPPFLAGS",
		"FFLAGS",
		"GAMEDATAMODE",
		"GAMEDIRMODE",
		"GAMEMODE",
		"GAMES_GROUP",
		"GAMES_USER",
		"GLIBC_VERSION",
		"INIT_SYSTEM",
		"LDFLAGS",
		"LICENSE",
		"LOCALBASE",
		"MACHINE_ARCH",
		"MACHINE_GNU_ARCH",
		"MULTI",
		"NO_BIN_ON_CDROM",
		"NO_BIN_ON_FTP",
		"NO_SRC_ON_CDROM",
		"NO_SRC_ON_FTP",
		"OBJECT_FMT",
		"OPSYS",
		"OS_VERSION",
		"OSVERSION_SPECIFIC",
		"PKG_HACKS",
		"PKG_OPTIONS",
		"PKG_SYSCONFBASEDIR",
		"PKG_SYSCONFDIR",
		"PKGGNUDIR",
		"PKGINFODIR",
		"PKGMANDIR",
		"PKGPATH",
		"RESTRICTED",
		"USE_ABI_DEPENDS")
}

// Latest returns the latest package matching the given pattern.
// It searches the category for subdirectories matching the given
// regular expression, takes the latest of them and replaces its
// name with repl.
//
// Example:
//  Latest("lang", `^php[0-9]+$`, "../../lang/$0")
//      => "../../lang/php72"
func (src *Pkgsrc) Latest(category PkgsrcPath, re regex.Pattern, repl string) string {
	versions := src.ListVersions(category, re, repl, true)

	if len(versions) > 0 {
		return versions[len(versions)-1]
	}
	return ""
}

// ListVersions searches the category for subdirectories matching the given
// regular expression, replaces their names with repl and returns a slice
// of them, properly sorted from early to late.
//
// Example:
//  ListVersions("lang", `^php[0-9]+$`, "php-$0")
//      => {"php-53", "php-56", "php-73"}
func (src *Pkgsrc) ListVersions(category PkgsrcPath, re regex.Pattern, repl string, errorIfEmpty bool) []string {
	if G.Testing {
		// Regular expression must be anchored at both ends, to avoid typos.
		assert(hasPrefix(string(re), "^"))
		assert(hasSuffix(string(re), "$"))
	}

	// XXX: Maybe convert cache key to a struct, to save allocations.
	cacheKey := category.String() + "/" + string(re) + " => " + repl
	if latest, found := src.listVersions[cacheKey]; found {
		return latest
	}

	var names []string
	dir := src.File(category)
	for _, fileInfo := range src.ReadDir(category) {
		name := fileInfo.Name()
		if matches(name, re) && !isEmptyDir(dir.JoinNoClean(NewRelPathString(name))) {
			names = append(names, name)
		}
	}
	if len(names) == 0 {
		if errorIfEmpty {
			G.Logger.TechErrorf(src.File(category), "Cannot find package versions of %q.", string(re))
		}
		src.listVersions[cacheKey] = nil
		return nil
	}

	// In the pkgsrc directories, the major versions of packages are
	// written without dots, which leads to ambiguities:
	//
	// databases/postgresql: 94 < 95 < 96 < 10 < 11
	// lang/go: 19 < 110 < 111 < 2
	keys := make(map[string]int)
	for _, name := range names {
		if m, pkgbase, versionStr := match2(name, `^(\D+)(\d+)$`); m {
			version := toInt(versionStr, 0)
			if pkgbase == "postgresql" && version < 60 {
				version = 10 * version
			}
			if pkgbase == "go" {
				major := toInt(versionStr[:1], 0)
				minor := toInt(versionStr[1:], 0)
				version = 100*major + minor
			}
			keys[name] = version
		}
	}

	sort.SliceStable(names, func(i, j int) bool {
		if keyI, keyJ := keys[names[i]], keys[names[j]]; keyI != keyJ {
			return keyI < keyJ
		}
		return naturalLess(names[i], names[j])
	})

	var repls = make([]string, len(names))
	for i, name := range names {
		repls[i] = replaceAll(name, re, repl)
	}

	src.listVersions[cacheKey] = repls
	return repls
}

// VariableType returns the type of the variable
// (possibly guessed based on the variable name),
// or nil if the type cannot even be guessed.
func (src *Pkgsrc) VariableType(mklines *MkLines, varname string) (vartype *Vartype) {
	if trace.Tracing {
		defer trace.Call(varname, trace.Result(&vartype))()
	}

	// When scanning mk/** for otherwise unknown variables, their type
	// is set to BtUnknown. These variables must not override the guess
	// based on the variable name.
	vartype = src.vartypes.Canon(varname)
	if vartype != nil && vartype.basicType != BtUnknown {
		return vartype
	}

	if tool := G.ToolByVarname(mklines, varname); tool != nil {
		if trace.Tracing {
			trace.Stepf("Use of tool %+v", tool)
		}
		perms := aclpUse
		if tool.Validity == AfterPrefsMk && mklines.Tools.SeenPrefs {
			perms |= aclpUseLoadtime
		}
		return NewVartype(BtShellCommand, NoVartypeOptions, NewACLEntry("*", perms))
	}

	if m, toolVarname := match1(varname, `^TOOLS_(.*)`); m {
		if tool := G.ToolByVarname(mklines, toolVarname); tool != nil {
			return NewVartype(BtPathname, NoVartypeOptions, NewACLEntry("*", aclpUse))
		}
	}

	return src.guessVariableType(varname)
}

// guessVariableType guesses the data type of the variable based on naming conventions.
func (src *Pkgsrc) guessVariableType(varname string) (vartype *Vartype) {
	plainType := func(basicType *BasicType, permissions ACLPermissions) *Vartype {
		gtype := NewVartype(basicType, Guessed, NewACLEntry("*", permissions))
		trace.Step2("The guessed type of %q is %q.", varname, gtype.String())
		return gtype
	}
	listType := func(basicType *BasicType, permissions ACLPermissions) *Vartype {
		gtype := NewVartype(basicType, List|Guessed, NewACLEntry("*", permissions))
		trace.Step2("The guessed type of %q is %q.", varname, gtype.String())
		return gtype
	}

	varbase := varnameBase(varname)
	switch {
	case hasSuffix(varbase, "DIRS"):
		return listType(BtPathPattern, aclpAllRuntime)
	case hasSuffix(varbase, "DIR") && !hasSuffix(varbase, "DESTDIR"), hasSuffix(varname, "_HOME"):
		// TODO: hasSuffix(varbase, "BASE")
		return plainType(BtPathname, aclpAllRuntime)
	case hasSuffix(varbase, "FILES"):
		return listType(BtPathPattern, aclpAllRuntime)
	case hasSuffix(varbase, "FILE"):
		return plainType(BtPathname, aclpAllRuntime)
	case hasSuffix(varbase, "PATH"):
		return plainType(BtPathlist, aclpAllRuntime)
	case hasSuffix(varbase, "PATHS"):
		return listType(BtPathname, aclpAllRuntime)
	case hasSuffix(varbase, "_USER"):
		return plainType(BtUserGroupName, aclpAll)
	case hasSuffix(varbase, "_GROUP"):
		return plainType(BtUserGroupName, aclpAll)
	case hasSuffix(varbase, "_ENV"):
		return listType(BtShellWord, aclpAllRuntime)
	case hasSuffix(varbase, "_CMD"):
		return plainType(BtShellCommand, aclpAllRuntime)
	case hasSuffix(varbase, "_ARGS"):
		return listType(BtShellWord, aclpAllRuntime)
	case hasSuffix(varbase, "_CFLAGS"), hasSuffix(varname, "_CPPFLAGS"), hasSuffix(varname, "_CXXFLAGS"):
		return listType(BtCFlag, aclpAllRuntime)
	case hasSuffix(varname, "_LDFLAGS"):
		return listType(BtLdFlag, aclpAllRuntime)
	case hasSuffix(varname, "FLAGS"):
		return listType(BtShellWord, aclpAll)
	case hasSuffix(varbase, "_MK"):
		// TODO: Add BtGuard for inclusion guards, since these variables may only be checked using defined().
		return plainType(BtUnknown, aclpAll)
	case hasSuffix(varbase, "_AWK"):
		return plainType(BtAwkCommand, aclpAll)
	case hasSuffix(varbase, "_SKIP"):
		return listType(BtPathPattern, aclpAllRuntime)
	}

	// Variables whose name doesn't match the above patterns may be
	// looked up from the pkgsrc infrastructure.
	//
	// As of May 2019, pkglint only distinguishes plain variables and
	// list variables, but not "unknown". Therefore the above patterns
	// must take precedence over this rule, because otherwise, list
	// variables from the infrastructure would be guessed to be plain
	// variables.
	vartype = src.vartypes.Canon(varname)
	if vartype != nil {
		return vartype
	}

	if trace.Tracing {
		trace.Step1("No type definition found for %q.", varname)
	}
	return nil
}

func (src *Pkgsrc) checkToplevelUnusedLicenses() {
	if !G.InterPackage.Enabled() {
		return
	}

	licensesDir := src.File("licenses")
	for _, licenseFile := range src.ReadDir("licenses") {
		licenseName := licenseFile.Name()
		if !G.InterPackage.IsLicenseUsed(licenseName) {
			licensePath := licensesDir.JoinNoClean(NewRelPathString(licenseName))
			NewLineWhole(licensePath).Warnf("This license seems to be unused.")
		}
	}
}

func (src *Pkgsrc) SuggestedUpdates() []SuggestedUpdate {
	if G.Wip {
		return src.suggestedWipUpdates
	} else {
		return src.suggestedUpdates
	}
}

// IsBuildDef returns whether the given variable is automatically added
// to BUILD_DEFS by the pkgsrc infrastructure. In such a case, the
// package doesn't need to add the variable to BUILD_DEFS itself.
func (src *Pkgsrc) IsBuildDef(varname string) bool {
	return src.buildDefs[varname]
}

// ReadDir lists the files and subdirectories from the given directory
// (relative to the pkgsrc root).
//
// The result may contain empty directories that are left over from CVS.
// For performance reasons, the caller needs to filter these out; see isEmptyDir.
func (src *Pkgsrc) ReadDir(dirName PkgsrcPath) []os.FileInfo {
	dir := src.File(dirName)
	files, err := dir.ReadDir()
	if err != nil {
		return nil
	}

	var relevantFiles []os.FileInfo
	for _, dirent := range files {
		name := dirent.Name()
		if !dirent.IsDir() || !isIgnoredFilename(name) {
			relevantFiles = append(relevantFiles, dirent)
		}
	}

	return relevantFiles
}

// LoadMkExisting loads a file that must exist.
//
// During pkglint testing, these files often don't exist, as they are
// emulated by setting their data structures manually.
func (src *Pkgsrc) LoadMkExisting(filename PkgsrcPath) *MkLines {
	options := NotEmpty
	if !G.Testing {
		options |= MustSucceed
	}
	return src.LoadMk(filename, options)
}

// LoadMk loads the Makefile relative to the pkgsrc top directory.
func (src *Pkgsrc) LoadMk(filename PkgsrcPath, options LoadOptions) *MkLines {
	return LoadMk(src.File(filename), nil, options)
}

// Load loads the file relative to the pkgsrc top directory.
func (src *Pkgsrc) Load(filename PkgsrcPath, options LoadOptions) *Lines {
	return Load(src.File(filename), options)
}

// Relpath returns the canonical relative path from the directory "from"
// to the filesystem entry "to".
//
// The relative path is built by going from the "from" directory up to the
// pkgsrc root and from there to the "to" filename. This produces the form
// "../../category/package" that is found in DEPENDS and .include lines.
//
// This function should only be used if the relative path from one file to
// another cannot be computed in another way. The preferred way is to take
// the relative filenames directly from the .include or exists() where they
// appear.
func (src *Pkgsrc) Relpath(from, to CurrPath) RelPath {
	cfrom := from.Clean()
	cto := to.Clean()

	if cfrom == cto {
		return "."
	}

	// Take a shortcut for the common case from "dir" to "dir/subdir/...".
	if cto.HasPrefixPath(cfrom) {
		return cfrom.Rel(cto)
	}

	// Take a shortcut for the common case from "category/package" to ".".
	// This is the most common variant in a complete pkgsrc scan.
	if cto == "." {
		fromParts := cfrom.Parts()
		if len(fromParts) == 2 && fromParts[0] != ".." {
			return "../.."
		}
	}

	if cfrom == "." && !cto.IsAbs() {
		return NewRelPath(cto.Clean().AsPath())
	}

	absFrom := G.Abs(cfrom)
	absTopdir := G.Abs(src.topdir)
	absTo := G.Abs(cto)

	up := absFrom.Rel(absTopdir)
	down := absTopdir.Rel(absTo)

	if absFrom.HasPrefixPath(absTo) || absTo.HasPrefixPath(absFrom) {
		return absFrom.Rel(absTo)
	}

	fromParts := absTopdir.Rel(absFrom).Parts()
	toParts := down.Parts()

	if len(fromParts) >= 2 && len(toParts) >= 2 {
		if fromParts[0] == toParts[0] && fromParts[1] == toParts[1] {
			var relParts []string
			for range fromParts[2:] {
				relParts = append(relParts, "..")
			}
			relParts = append(relParts, toParts[2:]...)
			return NewRelPath(NewPath(strings.Join(relParts, "/")).CleanDot())
		}
	}

	return up.JoinNoClean(down).CleanDot()
}

// File resolves a filename relative to the pkgsrc top directory.
//
// Example:
//  NewPkgsrc("/usr/pkgsrc").File("distfiles") => "/usr/pkgsrc/distfiles"
func (src *Pkgsrc) File(relativeName PkgsrcPath) CurrPath {
	cleaned := NewRelPath(relativeName.AsPath()).Clean()
	if cleaned == "." {
		return src.topdir.CleanDot()
	}
	// TODO: Package.File resolves variables, Pkgsrc.File doesn't. They should behave the same.
	return src.topdir.JoinNoClean(cleaned).CleanDot()
}

// FilePkg resolves a package-relative path to the real file that it represents.
// If the given path does not start with "../../", the result is empty.
func (src *Pkgsrc) FilePkg(rel PackagePath) CurrPath {
	parts := rel.AsPath().Parts()
	if len(parts) >= 4 && parts[0] == ".." && parts[1] == ".." && parts[2] != ".." {
		return src.File(NewPkgsrcPath(NewPath(strings.Join(parts[2:], "/"))))
	}
	return ""
}

// Rel returns the path of `filename`, relative to the pkgsrc top directory.
//
// Example:
//  NewPkgsrc("/usr/pkgsrc").Rel("/usr/pkgsrc/distfiles") => "distfiles"
func (src *Pkgsrc) Rel(filename CurrPath) PkgsrcPath {
	return NewPkgsrcPath(src.Relpath(src.topdir, filename).AsPath())
}

// IsInfra returns whether the given filename is part of the pkgsrc
// infrastructure.
func (src *Pkgsrc) IsInfra(filename CurrPath) bool {
	rel := src.Rel(filename)
	return rel.HasPrefixPath("mk") || rel.HasPrefixPath("wip/mk")
}

func (src *Pkgsrc) IsInfraMain(filename CurrPath) bool {
	rel := src.Rel(filename)
	return rel.HasPrefixPath("mk")
}

func (src *Pkgsrc) IsWip(filename CurrPath) bool {
	rel := src.Rel(filename)
	return rel.HasPrefixPath("wip")
}

// Change describes a modification to a single package, from the doc/CHANGES-* files.
type Change struct {
	Location Location
	Action   ChangeAction // Added, Updated, Downgraded, Renamed, Moved, Removed
	Pkgpath  PkgsrcPath   // For renamed or moved packages, the previous PKGPATH
	target   string       // The path or version number, depending on the action
	Author   string
	Date     string
}

// Version returns the version number for an Added, Updated or Downgraded package.
func (ch *Change) Version() string {
	assert(ch.Action == Added || ch.Action == Updated || ch.Action == Downgraded)
	return ch.target
}

// Target returns the target PKGPATH for a Renamed or Moved package.
func (ch *Change) Target() PkgsrcPath {
	assert(ch.Action == Renamed || ch.Action == Moved)
	return NewPkgsrcPath(NewPath(ch.target))
}

// Successor returns the successor for a Removed package.
func (ch *Change) Successor() string {
	assert(ch.Action == Removed)
	return ch.target
}

func (ch *Change) IsAbove(other *Change) bool {
	if ch.Date != other.Date {
		return ch.Date < other.Date
	}
	return ch.Location.lineno < other.Location.lineno
}

type ChangeAction uint8

const (
	Added ChangeAction = 1 + iota
	Updated
	Downgraded
	Renamed
	Moved
	Removed
)

func ParseChangeAction(s string) ChangeAction {
	switch s {
	case "Added":
		return Added
	case "Updated":
		return Updated
	case "Downgraded":
		return Downgraded
	case "Renamed":
		return Renamed
	case "Moved":
		return Moved
	case "Removed":
		return Removed
	}
	return 0
}

func (ca ChangeAction) String() string {
	return [...]string{"", "Added", "Updated", "Downgraded", "Renamed", "Moved", "Removed"}[ca]
}

// SuggestedUpdate describes a desired package update, from the doc/TODO file.
type SuggestedUpdate struct {
	Line    Location
	Pkgname string
	Version string
	Comment string
}
