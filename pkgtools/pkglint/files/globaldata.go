package main

import (
	"io/ioutil"
	"path"
	"sort"
)

// GlobalData contains data describing pkgsrc as a whole.
type GlobalData struct {
	pkgsrcdir           string              // Relative to the current working directory.
	masterSiteUrls      map[string]string   // "https://github.com/" => "MASTER_SITE_GITHUB"
	masterSiteVars      map[string]bool     // "MASTER_SITE_GITHUB" => true
	pkgOptions          map[string]string   // "x11" => "Provides X11 support"
	tools               map[string]bool     // Known tool names, e.g. "sed" and "gm4".
	vartools            map[string]string   // Maps tool names to their respective variable, e.g. "sed" => "SED", "gzip" => "GZIP_CMD".
	predefinedTools     map[string]bool     // Tools that a package does not need to add to USE_TOOLS explicitly because they are used by the pkgsrc infrastructure, too.
	varnameToToolname   map[string]string   // Maps the tool variable names to the tool name they use, e.g. "GZIP_CMD" => "gzip" and "SED" => "sed".
	systemBuildDefs     map[string]bool     // The set of user-defined variables that are added to BUILD_DEFS within the bsd.pkg.mk file.
	toolvarsVarRequired map[string]bool     // Tool variable names that may not be converted to their "direct" form, that is: ${CP} may not be written as cp.
	toolsVarRequired    map[string]bool     // Tools that need to be written in variable form, e.g. echo => ${ECHO}.
	suggestedUpdates    []SuggestedUpdate   //
	suggestedWipUpdates []SuggestedUpdate   //
	lastChange          map[string]*Change  //
	userDefinedVars     map[string]*Line    // varname => line (after calling parselineMk on it)
	deprecated          map[string]string   //
	vartypes            map[string]*Vartype // varcanon => type
}

// Change is a change entry from the `doc/CHANGES-*` files.
type Change struct {
	line    *Line
	action  string
	pkgpath string
	version string
	author  string
	date    string
}

// SuggestedUpdate is from the `doc/TODO` file.
type SuggestedUpdate struct {
	line    *Line
	pkgname string
	version string
	comment string
}

func (gd *GlobalData) Initialize() {
	firstArg := G.todo[0]
	if fileExists(firstArg) {
		firstArg = path.Dir(firstArg)
	}
	if relTopdir := findPkgsrcTopdir(firstArg); relTopdir != "" {
		gd.pkgsrcdir = firstArg + "/" + relTopdir
	} else {
		dummyLine.fatalf("%q is not inside a pkgsrc tree.", firstArg)
	}

	gd.vartypes = make(map[string]*Vartype)
	gd.InitVartypes()
	gd.loadDistSites()
	gd.loadPkgOptions()
	gd.loadDocChanges()
	gd.loadSuggestedUpdates()
	gd.loadUserDefinedVars()
	gd.loadTools()
	gd.deprecated = getDeprecatedVars()
}

func (gd *GlobalData) loadDistSites() {
	fname := gd.pkgsrcdir + "/mk/fetch/sites.mk"
	lines := LoadExistingLines(fname, true)

	names := make(map[string]bool)
	url2name := make(map[string]string)
	for _, line := range lines {
		if m, varname, _, urls, _ := matchVarassign(line.text); m {
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

	_ = G.opts.DebugMisc && debugf(fname, noLines, "Loaded %d MASTER_SITE_* URLs.", len(url2name))
	gd.masterSiteUrls = url2name
	gd.masterSiteVars = names
}

func (gd *GlobalData) loadPkgOptions() {
	fname := gd.pkgsrcdir + "/mk/defaults/options.description"
	lines := LoadExistingLines(fname, false)

	gd.pkgOptions = make(map[string]string)
	for _, line := range lines {
		if m, optname, optdescr := match2(line.text, `^([-0-9a-z_+]+)(?:\s+(.*))?$`); m {
			gd.pkgOptions[optname] = optdescr
		} else {
			line.fatalf("Unknown line format.")
		}
	}
}

func (gd *GlobalData) loadTools() {
	toolFiles := []string{"defaults.mk"}
	{
		fname := G.globalData.pkgsrcdir + "/mk/tools/bsd.tools.mk"
		lines := LoadExistingLines(fname, true)
		for _, line := range lines {
			if m, _, includefile := match2(line.text, reMkInclude); m {
				if m, toolfile := match1(includefile, `^(?:\$\{PKGSRCDIR\}/mk/tools/)?([^/]+)$`); m {
					toolFiles = append(toolFiles, toolfile)
				}
			}
		}
	}
	if len(toolFiles) <= 1 {
		fatalf(toolFiles[0], noLines, "Too few tool files.")
	}

	tools := make(map[string]bool)
	vartools := make(map[string]string)
	predefinedTools := make(map[string]bool)
	varnameToToolname := make(map[string]string)
	systemBuildDefs := make(map[string]bool)

	for _, basename := range toolFiles {
		fname := G.globalData.pkgsrcdir + "/mk/tools/" + basename
		lines := LoadExistingLines(fname, true)
		for _, line := range lines {
			if m, varname, _, value, _ := matchVarassign(line.text); m {
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
		fname := G.globalData.pkgsrcdir + "/mk/" + basename
		condDepth := 0

		lines := LoadExistingLines(fname, true)
		for _, line := range lines {
			text := line.text

			if m, varname, _, value, _ := matchVarassign(text); m {
				if varname == "USE_TOOLS" {
					_ = G.opts.DebugTools && line.debugf("[condDepth=%d] %s", condDepth, value)
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

			} else if m, _, cond, _ := match3(text, reMkCond); m {
				switch cond {
				case "if":
				case "ifdef":
				case "ifndef":
				case "for":
					condDepth++
				case "endif":
				case "endfor":
					condDepth--
				}
			}
		}
	}

	if G.opts.DebugTools {
		dummyLine.debugf("tools: %v", stringBoolMapKeys(tools))
		dummyLine.debugf("vartools: %v", stringStringMapKeys(vartools))
		dummyLine.debugf("predefinedTools: %v", stringBoolMapKeys(predefinedTools))
		dummyLine.debugf("varnameToToolname: %v", stringStringMapKeys(varnameToToolname))
	}
	_ = G.opts.DebugMisc && dummyLine.debugf("systemBuildDefs: %v", systemBuildDefs)

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

	gd.tools = tools
	gd.vartools = vartools
	gd.predefinedTools = predefinedTools
	gd.varnameToToolname = varnameToToolname
	gd.systemBuildDefs = systemBuildDefs
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
		text := line.text

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
					line.warnf("Invalid package name %q", pkgname)
				}
			} else {
				line.warnf("Invalid line format %q", text)
			}
		}
	}
	return updates
}

func (gd *GlobalData) loadSuggestedUpdates() {
	gd.suggestedUpdates = loadSuggestedUpdates(G.globalData.pkgsrcdir + "/doc/TODO")
	if wipFilename := G.globalData.pkgsrcdir + "/wip/TODO"; fileExists(wipFilename) {
		gd.suggestedWipUpdates = loadSuggestedUpdates(wipFilename)
	}
}

func (gd *GlobalData) loadDocChangesFromFile(fname string) []Change {
	lines := LoadExistingLines(fname, false)

	var changes []Change
	for _, line := range lines {
		text := line.text
		if !(hasPrefix(text, "\t") && matches(text, `^\t[A-Z]`)) {
			continue
		}

		if m, action, pkgpath, version, author, date := match5(text, `^\t(Updated) (\S+) to (\S+) \[(\S+) (\d\d\d\d-\d\d-\d\d)\]$`); m {
			changes = append(changes, Change{line, action, pkgpath, version, author, date})

		} else if m, action, pkgpath, version, author, date := match5(text, `^\t(Added) (\S+) version (\S+) \[(\S+) (\d\d\d\d-\d\d-\d\d)\]$`); m {
			changes = append(changes, Change{line, action, pkgpath, version, author, date})

		} else if m, action, pkgpath, author, date := match4(text, `^\t(Removed) (\S+) (?:successor \S+ )?\[(\S+) (\d\d\d\d-\d\d-\d\d)\]$`); m {
			changes = append(changes, Change{line, action, pkgpath, "", author, date})

		} else if m, action, pkgpath, version, author, date := match5(text, `^\t(Downgraded) (\S+) to (\S+) \[(\S+) (\d\d\d\d-\d\d-\d\d)\]$`); m {
			changes = append(changes, Change{line, action, pkgpath, version, author, date})

		} else if m, action, pkgpath, version, author, date := match5(text, `^\t(Renamed|Moved) (\S+) to (\S+) \[(\S+) (\d\d\d\d-\d\d-\d\d)\]$`); m {
			changes = append(changes, Change{line, action, pkgpath, version, author, date})

		} else {
			line.warnf("Unknown doc/CHANGES line: %q", text)
			line.explain("See mk/misc/developer.mk for the rules.")
		}
	}
	return changes
}

func (gd *GlobalData) getSuggestedPackageUpdates() []SuggestedUpdate {
	if G.isWip {
		return gd.suggestedWipUpdates
	} else {
		return gd.suggestedUpdates
	}
}

func (gd *GlobalData) loadDocChanges() {
	docdir := G.globalData.pkgsrcdir + "/doc"
	files, err := ioutil.ReadDir(docdir)
	if err != nil {
		fatalf(docdir, noLines, "Cannot be read.")
	}

	var fnames []string
	for _, file := range files {
		fname := file.Name()
		if matches(fname, `^CHANGES-20\d\d$`) && fname >= "CHANGES-2011" {
			fnames = append(fnames, fname)
		}
	}

	sort.Strings(fnames)
	gd.lastChange = make(map[string]*Change)
	for _, fname := range fnames {
		changes := gd.loadDocChangesFromFile(docdir + "/" + fname)
		for _, change := range changes {
			c := change
			gd.lastChange[change.pkgpath] = &c
		}
	}
}

func (gd *GlobalData) loadUserDefinedVars() {
	lines := LoadExistingLines(G.globalData.pkgsrcdir+"/mk/defaults/mk.conf", true)

	gd.userDefinedVars = make(map[string]*Line)
	for _, line := range lines {
		parselineMk(line)
		if varname, ok := line.extra["varname"].(string); ok {
			gd.userDefinedVars[varname] = line
		}
	}
}
