package main

import (
	"io/ioutil"
	"path"
	"sort"
	"strings"
)

// GlobalData contains data describing pkgsrc as a whole.
type GlobalData struct {
	Pkgsrcdir           string              // Relative to the current working directory.
	MasterSiteUrls      map[string]string   // "https://github.com/" => "MASTER_SITE_GITHUB"
	MasterSiteVars      map[string]bool     // "MASTER_SITE_GITHUB" => true
	PkgOptions          map[string]string   // "x11" => "Provides X11 support"
	Tools               map[string]bool     // Known tool names, e.g. "sed" and "gm4".
	Vartools            map[string]string   // Maps tool names to their respective variable, e.g. "sed" => "SED", "gzip" => "GZIP_CMD".
	PredefinedTools     map[string]bool     // Tools that a package does not need to add to USE_TOOLS explicitly because they are used by the pkgsrc infrastructure, too.
	VarnameToToolname   map[string]string   // Maps the tool variable names to the tool name they use, e.g. "GZIP_CMD" => "gzip" and "SED" => "sed".
	SystemBuildDefs     map[string]bool     // The set of user-defined variables that are added to BUILD_DEFS within the bsd.pkg.mk file.
	toolvarsVarRequired map[string]bool     // Tool variable names that may not be converted to their "direct" form, that is: ${CP} may not be written as cp.
	toolsVarRequired    map[string]bool     // Tools that need to be written in variable form, e.g. "echo"; see Vartools.
	suggestedUpdates    []SuggestedUpdate   //
	suggestedWipUpdates []SuggestedUpdate   //
	LastChange          map[string]*Change  //
	UserDefinedVars     map[string]*MkLine  // varname => line
	Deprecated          map[string]string   //
	vartypes            map[string]*Vartype // varcanon => type
}

// Change is a change entry from the `doc/CHANGES-*` files.
type Change struct {
	Line    *Line
	Action  string
	Pkgpath string
	Version string
	Author  string
	Date    string
}

// SuggestedUpdate is from the `doc/TODO` file.
type SuggestedUpdate struct {
	Line    *Line
	Pkgname string
	Version string
	Comment string
}

func (gd *GlobalData) Initialize() {
	firstArg := G.Todo[0]
	if fileExists(firstArg) {
		firstArg = path.Dir(firstArg)
	}
	if relTopdir := findPkgsrcTopdir(firstArg); relTopdir != "" {
		gd.Pkgsrcdir = firstArg + "/" + relTopdir
	} else {
		dummyLine.Fatalf("%q is not inside a pkgsrc tree.", firstArg)
	}

	gd.vartypes = make(map[string]*Vartype)
	gd.InitVartypes()
	gd.loadDistSites()
	gd.loadPkgOptions()
	gd.loadDocChanges()
	gd.loadSuggestedUpdates()
	gd.loadUserDefinedVars()
	gd.loadTools()
	gd.loadDeprecatedVars()
}

func (gd *GlobalData) loadDistSites() {
	fname := gd.Pkgsrcdir + "/mk/fetch/sites.mk"
	lines := LoadExistingLines(fname, true)

	names := make(map[string]bool)
	url2name := make(map[string]string)
	for _, line := range lines {
		if m, varname, _, _, urls, _ := MatchVarassign(line.Text); m {
			if hasPrefix(varname, "MASTER_SITE_") && varname != "MASTER_SITE_BACKUP" {
				names[varname] = true
				for _, url := range splitOnSpace(urls) {
					if matches(url, `^(?:http://|https://|ftp://)`) {
						url2name[url] = varname
					}
				}
			}
		}
	}

	// Explicitly allowed, although not defined in mk/fetch/sites.mk.
	names["MASTER_SITE_SUSE_UPD"] = true
	names["MASTER_SITE_LOCAL"] = true

	if G.opts.DebugMisc {
		Debugf(fname, noLines, "Loaded %d MASTER_SITE_* URLs.", len(url2name))
	}
	gd.MasterSiteUrls = url2name
	gd.MasterSiteVars = names
}

func (gd *GlobalData) loadPkgOptions() {
	fname := gd.Pkgsrcdir + "/mk/defaults/options.description"
	lines := LoadExistingLines(fname, false)

	gd.PkgOptions = make(map[string]string)
	for _, line := range lines {
		if m, optname, optdescr := match2(line.Text, `^([-0-9a-z_+]+)(?:\s+(.*))?$`); m {
			gd.PkgOptions[optname] = optdescr
		} else {
			line.Fatalf("Unknown line format.")
		}
	}
}

func (gd *GlobalData) loadTools() {
	toolFiles := []string{"defaults.mk"}
	{
		fname := G.globalData.Pkgsrcdir + "/mk/tools/bsd.tools.mk"
		lines := LoadExistingLines(fname, true)
		for _, line := range lines {
			if m, _, includefile := match2(line.Text, reMkInclude); m {
				if !contains(includefile, "/") {
					toolFiles = append(toolFiles, includefile)
				}
			}
		}
	}
	if len(toolFiles) <= 1 {
		Fatalf(toolFiles[0], noLines, "Too few tool files.")
	}

	tools := make(map[string]bool)
	vartools := make(map[string]string)
	predefinedTools := make(map[string]bool)
	varnameToToolname := make(map[string]string)
	systemBuildDefs := make(map[string]bool)

	for _, basename := range toolFiles {
		fname := G.globalData.Pkgsrcdir + "/mk/tools/" + basename
		lines := LoadExistingLines(fname, true)
		for _, line := range lines {
			if m, varname, _, _, value, _ := MatchVarassign(line.Text); m {
				if varname == "TOOLS_CREATE" && (value == "[" || matches(value, `^?[-\w.]+$`)) {
					tools[value] = true
				} else if m, toolname := match1(varname, `^(?:_TOOLS_VARNAME)\.([-\w.]+|\[)$`); m {
					tools[toolname] = true
					vartools[toolname] = value
					varnameToToolname[value] = toolname

				} else if m, toolname := match1(varname, `^(?:TOOLS_PATH|_TOOLS_DEPMETHOD)\.([-\w.]+|\[)$`); m {
					tools[toolname] = true

				} else if m, toolname := match1(varname, `_TOOLS\.(.*)`); m {
					tools[toolname] = true
					for _, tool := range splitOnSpace(value) {
						tools[tool] = true
					}
				}
			}
		}
	}

	{
		basename := "bsd.pkg.mk"
		fname := G.globalData.Pkgsrcdir + "/mk/" + basename
		condDepth := 0

		lines := LoadExistingLines(fname, true)
		for _, line := range lines {
			text := line.Text

			if m, varname, _, _, value, _ := MatchVarassign(text); m {
				if varname == "USE_TOOLS" {
					if G.opts.DebugTools {
						line.Debugf("[condDepth=%d] %s", condDepth, value)
					}
					if condDepth == 0 {
						for _, tool := range splitOnSpace(value) {
							if !containsVarRef(tool) && tools[tool] {
								predefinedTools[tool] = true
								predefinedTools["TOOLS_"+tool] = true
							}
						}
					}

				} else if varname == "_BUILD_DEFS" {
					for _, bdvar := range splitOnSpace(value) {
						systemBuildDefs[bdvar] = true
					}
				}

			} else if m, _, cond, _ := matchMkCond(text); m {
				switch cond {
				case "if", "ifdef", "ifndef", "for":
					condDepth++
				case "endif", "endfor":
					condDepth--
				}
			}
		}
	}

	if G.opts.DebugTools {
		dummyLine.Debugf("tools: %v", stringBoolMapKeys(tools))
		dummyLine.Debugf("vartools: %v", stringStringMapKeys(vartools))
		dummyLine.Debugf("predefinedTools: %v", stringBoolMapKeys(predefinedTools))
		dummyLine.Debugf("varnameToToolname: %v", stringStringMapKeys(varnameToToolname))
	}
	if G.opts.DebugMisc {
		dummyLine.Debugf("systemBuildDefs: %v", systemBuildDefs)
	}

	// Some user-defined variables do not influence the binary
	// package at all and therefore do not have to be added to
	// BUILD_DEFS; therefore they are marked as “already added”.
	systemBuildDefs["DISTDIR"] = true
	systemBuildDefs["FETCH_CMD"] = true
	systemBuildDefs["FETCH_OUTPUT_ARGS"] = true
	systemBuildDefs["GAMES_USER"] = true
	systemBuildDefs["GAMES_GROUP"] = true
	systemBuildDefs["GAMEDATAMODE"] = true
	systemBuildDefs["GAMEDIRMODE"] = true
	systemBuildDefs["GAMEMODE"] = true
	systemBuildDefs["GAMEOWN"] = true
	systemBuildDefs["GAMEGRP"] = true

	gd.Tools = tools
	gd.Vartools = vartools
	gd.PredefinedTools = predefinedTools
	gd.VarnameToToolname = varnameToToolname
	gd.SystemBuildDefs = systemBuildDefs
	gd.toolvarsVarRequired = map[string]bool{
		"ECHO":   true,
		"ECHO_N": true,
		"FALSE":  true,
		"TEST":   true,
		"TRUE":   true,
	}
	gd.toolsVarRequired = map[string]bool{
		"echo":  true,
		"false": true,
		"test":  true,
		"true":  true,
	}
}

func loadSuggestedUpdates(fname string) []SuggestedUpdate {
	lines := LoadExistingLines(fname, false)
	return parselinesSuggestedUpdates(lines)
}

func parselinesSuggestedUpdates(lines []*Line) []SuggestedUpdate {
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
					line.Warn1("Invalid package name %q", pkgname)
				}
			} else {
				line.Warn1("Invalid line format %q", text)
			}
		}
	}
	return updates
}

func (gd *GlobalData) loadSuggestedUpdates() {
	gd.suggestedUpdates = loadSuggestedUpdates(G.globalData.Pkgsrcdir + "/doc/TODO")
	if wipFilename := G.globalData.Pkgsrcdir + "/wip/TODO"; fileExists(wipFilename) {
		gd.suggestedWipUpdates = loadSuggestedUpdates(wipFilename)
	}
}

func (gd *GlobalData) loadDocChangesFromFile(fname string) []*Change {
	lines := LoadExistingLines(fname, false)

	parseChange := func(line *Line) *Change {
		text := line.Text
		if !hasPrefix(line.Text, "\t") {
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

	var changes []*Change
	for _, line := range lines {
		if change := parseChange(line); change != nil {
			changes = append(changes, change)
		} else if len(line.Text) >= 2 && line.Text[0] == '\t' && 'A' <= line.Text[1] && line.Text[1] <= 'Z' {
			line.Warn1("Unknown doc/CHANGES line: %q", line.Text)
			Explain1("See mk/misc/developer.mk for the rules.")
		}
	}
	return changes
}

func (gd *GlobalData) GetSuggestedPackageUpdates() []SuggestedUpdate {
	if G.Wip {
		return gd.suggestedWipUpdates
	} else {
		return gd.suggestedUpdates
	}
}

func (gd *GlobalData) loadDocChanges() {
	docdir := G.globalData.Pkgsrcdir + "/doc"
	files, err := ioutil.ReadDir(docdir)
	if err != nil {
		Fatalf(docdir, noLines, "Cannot be read.")
	}

	var fnames []string
	for _, file := range files {
		fname := file.Name()
		if matches(fname, `^CHANGES-20\d\d$`) && fname >= "CHANGES-2011" {
			fnames = append(fnames, fname)
		}
	}

	sort.Strings(fnames)
	gd.LastChange = make(map[string]*Change)
	for _, fname := range fnames {
		changes := gd.loadDocChangesFromFile(docdir + "/" + fname)
		for _, change := range changes {
			gd.LastChange[change.Pkgpath] = change
		}
	}
}

func (gd *GlobalData) loadUserDefinedVars() {
	lines := LoadExistingLines(G.globalData.Pkgsrcdir+"/mk/defaults/mk.conf", true)
	mklines := NewMkLines(lines)

	gd.UserDefinedVars = make(map[string]*MkLine)
	for _, mkline := range mklines.mklines {
		if mkline.IsVarassign() {
			gd.UserDefinedVars[mkline.Varname()] = mkline
		}
	}
}

func (gd *GlobalData) loadDeprecatedVars() {
	gd.Deprecated = map[string]string{

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
		"PKG_SKIP_REASON":        "Use PKG_FAIL_REASON instead.",

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
	}
}
