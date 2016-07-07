package main

import (
	"fmt"
	"os/user"
	"path"
	"regexp"
	"strconv"
	"strings"
)

// Package contains data for the pkgsrc package that is currently checked.
type Package struct {
	Pkgpath              string  // e.g. "category/pkgdir"
	Pkgdir               string  // PKGDIR from the package Makefile
	Filesdir             string  // FILESDIR from the package Makefile
	Patchdir             string  // PATCHDIR from the package Makefile
	DistinfoFile         string  // DISTINFO_FILE from the package Makefile
	EffectivePkgname     string  // PKGNAME or DISTNAME from the package Makefile, including nb13
	EffectivePkgbase     string  // The effective PKGNAME without the version
	EffectivePkgversion  string  // The version part of the effective PKGNAME, excluding nb13
	EffectivePkgnameLine *MkLine // The origin of the three effective_* values
	SeenBsdPrefsMk       bool    // Has bsd.prefs.mk already been included?

	vardef             map[string]*MkLine // (varname, varcanon) => line
	varuse             map[string]*MkLine // (varname, varcanon) => line
	bl3                map[string]*Line   // buildlink3.mk name => line; contains only buildlink3.mk files that are directly included.
	plistSubstCond     map[string]bool    // varname => true; list of all variables that are used as conditionals (@comment or nothing) in PLISTs.
	included           map[string]*Line   // fname => line
	seenMakefileCommon bool               // Does the package have any .includes?
	loadTimeTools      map[string]bool    // true=ok, false=not ok, absent=not mentioned in USE_TOOLS.
}

func NewPackage(pkgpath string) *Package {
	pkg := &Package{
		Pkgpath:        pkgpath,
		vardef:         make(map[string]*MkLine),
		varuse:         make(map[string]*MkLine),
		bl3:            make(map[string]*Line),
		plistSubstCond: make(map[string]bool),
		included:       make(map[string]*Line),
		loadTimeTools:  make(map[string]bool),
	}
	for varname, line := range G.globalData.UserDefinedVars {
		pkg.vardef[varname] = line
	}
	return pkg
}

func (pkg *Package) defineVar(mkline *MkLine, varname string) {
	if pkg.vardef[varname] == nil {
		pkg.vardef[varname] = mkline
	}
	varcanon := varnameCanon(varname)
	if pkg.vardef[varcanon] == nil {
		pkg.vardef[varcanon] = mkline
	}
}

func (pkg *Package) varValue(varname string) (string, bool) {
	switch varname {
	case "KRB5_TYPE":
		return "heimdal", true
	case "PGSQL_VERSION":
		return "95", true
	}
	if mkline := pkg.vardef[varname]; mkline != nil {
		return mkline.Value(), true
	}
	return "", false
}

func (pkg *Package) setSeenBsdPrefsMk() {
	if !pkg.SeenBsdPrefsMk {
		pkg.SeenBsdPrefsMk = true
		if G.opts.Debug {
			traceStep("Pkg.setSeenBsdPrefsMk")
		}
	}
}

func (pkg *Package) checkPossibleDowngrade() {
	if G.opts.Debug {
		defer tracecall0()()
	}

	m, _, pkgversion := match2(pkg.EffectivePkgname, rePkgname)
	if !m {
		return
	}

	mkline := pkg.EffectivePkgnameLine

	change := G.globalData.LastChange[pkg.Pkgpath]
	if change == nil {
		if G.opts.Debug {
			traceStep1("No change log for package %q", pkg.Pkgpath)
		}
		return
	}

	if change.Action == "Updated" {
		changeVersion := regcomp(`nb\d+$`).ReplaceAllString(change.Version, "")
		if pkgverCmp(pkgversion, changeVersion) < 0 {
			mkline.Line.Warnf("The package is being downgraded from %s (see %s) to %s", change.Version, change.Line.ReferenceFrom(mkline.Line), pkgversion)
			Explain4(
				"The files in doc/CHANGES-*, in which all version changes are",
				"recorded, have a higher version number than what the package says.",
				"This is unusual, since packages are typically upgraded instead of",
				"downgraded.")
		}
	}
}

func (pkg *Package) checklinesBuildlink3Inclusion(mklines *MkLines) {
	if G.opts.Debug {
		defer tracecall0()()
	}

	// Collect all the included buildlink3.mk files from the file.
	includedFiles := make(map[string]*MkLine)
	for _, mkline := range mklines.mklines {
		if mkline.IsInclude() {
			file := mkline.Includefile()
			if m, bl3 := match1(file, `^\.\./\.\./(.*)/buildlink3\.mk`); m {
				includedFiles[bl3] = mkline
				if pkg.bl3[bl3] == nil {
					mkline.Warn1("%s/buildlink3.mk is included by this file but not by the package.", bl3)
				}
			}
		}
	}

	if G.opts.Debug {
		for packageBl3 := range pkg.bl3 {
			if includedFiles[packageBl3] == nil {
				traceStep1("%s/buildlink3.mk is included by the package but not by the buildlink3.mk file.", packageBl3)
			}
		}
	}
}

func checkdirPackage(pkgpath string) {
	if G.opts.Debug {
		defer tracecall1(pkgpath)()
	}

	G.Pkg = NewPackage(pkgpath)
	defer func() { G.Pkg = nil }()
	pkg := G.Pkg

	// we need to handle the Makefile first to get some variables
	lines := pkg.loadPackageMakefile(G.CurrentDir + "/Makefile")
	if lines == nil {
		return
	}

	files := dirglob(G.CurrentDir)
	if pkg.Pkgdir != "." {
		files = append(files, dirglob(G.CurrentDir+"/"+pkg.Pkgdir)...)
	}
	if G.opts.CheckExtra {
		files = append(files, dirglob(G.CurrentDir+"/"+pkg.Filesdir)...)
	}
	files = append(files, dirglob(G.CurrentDir+"/"+pkg.Patchdir)...)
	if pkg.DistinfoFile != "distinfo" && pkg.DistinfoFile != "./distinfo" {
		files = append(files, G.CurrentDir+"/"+pkg.DistinfoFile)
	}
	haveDistinfo := false
	havePatches := false

	// Determine the used variables before checking any of the Makefile fragments.
	for _, fname := range files {
		if (hasPrefix(path.Base(fname), "Makefile.") || hasSuffix(fname, ".mk")) &&
			!matches(fname, `patch-`) &&
			!contains(fname, pkg.Pkgdir+"/") &&
			!contains(fname, pkg.Filesdir+"/") {
			if lines, err := readLines(fname, true); err == nil && lines != nil {
				NewMkLines(lines).DetermineUsedVariables()
			}
		}
	}

	for _, fname := range files {
		if containsVarRef(fname) {
			continue
		}
		if fname == G.CurrentDir+"/Makefile" {
			if G.opts.CheckMakefile {
				pkg.checkfilePackageMakefile(fname, lines)
			}
		} else {
			Checkfile(fname)
		}
		if contains(fname, "/patches/patch-") {
			havePatches = true
		} else if hasSuffix(fname, "/distinfo") {
			haveDistinfo = true
		}
		pkg.checkLocallyModified(fname)
	}

	if G.opts.CheckDistinfo && G.opts.CheckPatches {
		if havePatches && !haveDistinfo {
			NewLineWhole(G.CurrentDir+"/"+pkg.DistinfoFile).Warn1("File not found. Please run \"%s makepatchsum\".", confMake)
		}
	}

	if !isEmptyDir(G.CurrentDir + "/scripts") {
		NewLineWhole(G.CurrentDir + "/scripts").Warn0("This directory and its contents are deprecated! Please call the script(s) explicitly from the corresponding target(s) in the pkg's Makefile.")
	}
}

func (pkg *Package) loadPackageMakefile(fname string) *MkLines {
	if G.opts.Debug {
		defer tracecall1(fname)()
	}

	mainLines, allLines := NewMkLines(nil), NewMkLines(nil)
	if !pkg.readMakefile(fname, mainLines, allLines, "") {
		return nil
	}

	if G.opts.DumpMakefile {
		fmt.Printf("Whole Makefile (with all included files) follows:\n")
		for _, line := range allLines.lines {
			fmt.Printf("%s\n", line.String())
		}
	}

	allLines.DetermineUsedVariables()

	pkg.Pkgdir = expandVariableWithDefault("PKGDIR", ".")
	pkg.DistinfoFile = expandVariableWithDefault("DISTINFO_FILE", "distinfo")
	pkg.Filesdir = expandVariableWithDefault("FILESDIR", "files")
	pkg.Patchdir = expandVariableWithDefault("PATCHDIR", "patches")

	if varIsDefined("PHPEXT_MK") {
		if !varIsDefined("USE_PHP_EXT_PATCHES") {
			pkg.Patchdir = "patches"
		}
		if varIsDefined("PECL_VERSION") {
			pkg.DistinfoFile = "distinfo"
		}
	}

	if G.opts.Debug {
		traceStep1("DISTINFO_FILE=%s", pkg.DistinfoFile)
		traceStep1("FILESDIR=%s", pkg.Filesdir)
		traceStep1("PATCHDIR=%s", pkg.Patchdir)
		traceStep1("PKGDIR=%s", pkg.Pkgdir)
	}

	return mainLines
}

func (pkg *Package) readMakefile(fname string, mainLines *MkLines, allLines *MkLines, includingFnameForUsedCheck string) bool {
	if G.opts.Debug {
		defer tracecall1(fname)()
	}

	fileLines := LoadNonemptyLines(fname, true)
	if fileLines == nil {
		return false
	}
	fileMklines := NewMkLines(fileLines)

	isMainMakefile := len(mainLines.mklines) == 0

	for _, mkline := range fileMklines.mklines {
		line := mkline.Line

		if isMainMakefile {
			mainLines.mklines = append(mainLines.mklines, mkline)
			mainLines.lines = append(mainLines.lines, line)
		}
		allLines.mklines = append(allLines.mklines, mkline)
		allLines.lines = append(allLines.lines, line)

		var includeFile, incDir, incBase string
		if mkline.IsInclude() {
			inc := mkline.Includefile()
			includeFile = resolveVariableRefs(resolveVarsInRelativePath(inc, true))
			if containsVarRef(includeFile) {
				if !contains(fname, "/mk/") {
					line.Note1("Skipping include file %q. This may result in false warnings.", includeFile)
				}
				includeFile = ""
			}
			incDir, incBase = path.Split(includeFile)
		}

		if includeFile != "" {
			if path.Base(fname) != "buildlink3.mk" {
				if m, bl3File := match1(includeFile, `^\.\./\.\./(.*)/buildlink3\.mk$`); m {
					G.Pkg.bl3[bl3File] = line
					if G.opts.Debug {
						traceStep1("Buildlink3 file in package: %q", bl3File)
					}
				}
			}
		}

		if includeFile != "" && G.Pkg.included[includeFile] == nil {
			G.Pkg.included[includeFile] = line

			if matches(includeFile, `^\.\./[^./][^/]*/[^/]+`) {
				mkline.Warn0("References to other packages should look like \"../../category/package\", not \"../package\".")
				mkline.explainRelativeDirs()
			}

			if path.Base(fname) == "Makefile" && !hasPrefix(incDir, "../../mk/") && incBase != "buildlink3.mk" && incBase != "builtin.mk" && incBase != "options.mk" {
				if G.opts.Debug {
					traceStep1("Including %q sets seenMakefileCommon.", includeFile)
				}
				G.Pkg.seenMakefileCommon = true
			}

			skip := contains(fname, "/mk/") || hasSuffix(includeFile, "/bsd.pkg.mk") || hasSuffix(includeFile, "/bsd.prefs.mk")
			if !skip {
				dirname, _ := path.Split(fname)
				dirname = cleanpath(dirname)

				// Only look in the directory relative to the
				// current file and in the current working directory.
				// Pkglint doesn’t have an include dir list, like make(1) does.
				if !fileExists(dirname + "/" + includeFile) {
					dirname = G.CurrentDir
				}
				if !fileExists(dirname + "/" + includeFile) {
					line.Error1("Cannot read %q.", dirname+"/"+includeFile)
					return false
				}

				if G.opts.Debug {
					traceStep1("Including %q.", dirname+"/"+includeFile)
				}
				includingFname := ifelseStr(incBase == "Makefile.common" && incDir != "", fname, "")
				if !pkg.readMakefile(dirname+"/"+includeFile, mainLines, allLines, includingFname) {
					return false
				}
			}
		}

		if mkline.IsVarassign() {
			varname, op, value := mkline.Varname(), mkline.Op(), mkline.Value()

			if op != opAssignDefault || G.Pkg.vardef[varname] == nil {
				if G.opts.Debug {
					traceStep("varassign(%q, %q, %q)", varname, op, value)
				}
				G.Pkg.vardef[varname] = mkline
			}
		}
	}

	if includingFnameForUsedCheck != "" {
		fileMklines.checkForUsedComment(relpath(G.globalData.Pkgsrcdir, includingFnameForUsedCheck))
	}

	return true
}

func (pkg *Package) checkfilePackageMakefile(fname string, mklines *MkLines) {
	if G.opts.Debug {
		defer tracecall1(fname)()
	}

	vardef := pkg.vardef
	if vardef["PLIST_SRC"] == nil &&
		vardef["GENERATE_PLIST"] == nil &&
		vardef["META_PACKAGE"] == nil &&
		!fileExists(G.CurrentDir+"/"+pkg.Pkgdir+"/PLIST") &&
		!fileExists(G.CurrentDir+"/"+pkg.Pkgdir+"/PLIST.common") {
		NewLineWhole(fname).Warn0("Neither PLIST nor PLIST.common exist, and PLIST_SRC is unset. Are you sure PLIST handling is ok?")
	}

	if (vardef["NO_CHECKSUM"] != nil || vardef["META_PACKAGE"] != nil) && isEmptyDir(G.CurrentDir+"/"+pkg.Patchdir) {
		if distinfoFile := G.CurrentDir + "/" + pkg.DistinfoFile; fileExists(distinfoFile) {
			NewLineWhole(distinfoFile).Warn0("This file should not exist if NO_CHECKSUM or META_PACKAGE is set.")
		}
	} else {
		if distinfoFile := G.CurrentDir + "/" + pkg.DistinfoFile; !containsVarRef(distinfoFile) && !fileExists(distinfoFile) {
			NewLineWhole(distinfoFile).Warn1("File not found. Please run \"%s makesum\".", confMake)
		}
	}

	if perlLine, noconfLine := vardef["REPLACE_PERL"], vardef["NO_CONFIGURE"]; perlLine != nil && noconfLine != nil {
		perlLine.Warn1("REPLACE_PERL is ignored when NO_CONFIGURE is set (in %s)", noconfLine.Line.ReferenceFrom(perlLine.Line))
	}

	if vardef["LICENSE"] == nil && vardef["META_PACKAGE"] == nil {
		NewLineWhole(fname).Error0("Each package must define its LICENSE.")
	}

	if gnuLine, useLine := vardef["GNU_CONFIGURE"], vardef["USE_LANGUAGES"]; gnuLine != nil && useLine != nil {
		if matches(useLine.Comment(), `(?-i)\b(?:c|empty|none)\b`) {
			// Don't emit a warning, since the comment
			// probably contains a statement that C is
			// really not needed.

		} else if !matches(useLine.Value(), `(?:^|\s+)(?:c|c99|objc)(?:\s+|$)`) {
			gnuLine.Warn1("GNU_CONFIGURE almost always needs a C compiler, but \"c\" is not added to USE_LANGUAGES in %s.",
				useLine.Line.ReferenceFrom(gnuLine.Line))
		}
	}

	pkg.determineEffectivePkgVars()
	pkg.checkPossibleDowngrade()

	if vardef["COMMENT"] == nil {
		NewLineWhole(fname).Warn0("No COMMENT given.")
	}

	if imake, x11 := vardef["USE_IMAKE"], vardef["USE_X11"]; imake != nil && x11 != nil {
		if !hasSuffix(x11.Line.Fname, "/mk/x11.buildlink3.mk") {
			imake.Line.Note1("USE_IMAKE makes USE_X11 in %s superfluous.", x11.Line.ReferenceFrom(imake.Line))
		}
	}

	pkg.checkUpdate()
	mklines.Check()
	pkg.ChecklinesPackageMakefileVarorder(mklines)
	SaveAutofixChanges(mklines.lines)
}

func (pkg *Package) getNbpart() string {
	line := pkg.vardef["PKGREVISION"]
	if line == nil {
		return ""
	}
	pkgrevision := line.Value()
	if rev, err := strconv.Atoi(pkgrevision); err == nil {
		return "nb" + strconv.Itoa(rev)
	}
	return ""
}

func (pkg *Package) determineEffectivePkgVars() {
	distnameLine := pkg.vardef["DISTNAME"]
	pkgnameLine := pkg.vardef["PKGNAME"]

	distname := ""
	if distnameLine != nil {
		distname = distnameLine.Value()
	}
	pkgname := ""
	if pkgnameLine != nil {
		pkgname = pkgnameLine.Value()
	}

	if distname != "" && pkgname != "" {
		pkgname = pkg.pkgnameFromDistname(pkgname, distname)
	}

	if pkgname != "" && pkgname == distname && pkgnameLine.Comment() == "" {
		pkgnameLine.Note0("PKGNAME is ${DISTNAME} by default. You probably don't need to define PKGNAME.")
	}

	if pkgname == "" && distname != "" && !containsVarRef(distname) && !matches(distname, rePkgname) {
		distnameLine.Warn0("As DISTNAME is not a valid package name, please define the PKGNAME explicitly.")
	}

	if pkgname != "" && !containsVarRef(pkgname) {
		if m, m1, m2 := match2(pkgname, rePkgname); m {
			pkg.EffectivePkgname = pkgname + pkg.getNbpart()
			pkg.EffectivePkgnameLine = pkgnameLine
			pkg.EffectivePkgbase = m1
			pkg.EffectivePkgversion = m2
		}
	}
	if pkg.EffectivePkgnameLine == nil && distname != "" && !containsVarRef(distname) {
		if m, m1, m2 := match2(distname, rePkgname); m {
			pkg.EffectivePkgname = distname + pkg.getNbpart()
			pkg.EffectivePkgnameLine = distnameLine
			pkg.EffectivePkgbase = m1
			pkg.EffectivePkgversion = m2
		}
	}
	if pkg.EffectivePkgnameLine != nil {
		if G.opts.Debug {
			traceStep("Effective name=%q base=%q version=%q",
				pkg.EffectivePkgname, pkg.EffectivePkgbase, pkg.EffectivePkgversion)
		}
	}
}

func (pkg *Package) pkgnameFromDistname(pkgname, distname string) string {
	tokens := NewMkParser(dummyLine, pkgname, false).MkTokens()

	subst := func(str, smod string) (result string) {
		if G.opts.Debug {
			defer tracecall(str, smod, ref(result))()
		}
		qsep := regexp.QuoteMeta(smod[1:2])
		if m, left, from, right, to, flags := match5(smod, `^S`+qsep+`(\^?)([^:]*?)(\$?)`+qsep+`([^:]*)`+qsep+`([1g]*)$`); m {
			result := mkopSubst(str, left != "", from, right != "", to, flags)
			if G.opts.Debug {
				traceStep("subst %q %q => %q", str, smod, result)
			}
			return result
		}
		return str
	}

	result := ""
	for _, token := range tokens {
		if token.Varuse != nil && token.Varuse.varname == "DISTNAME" {
			newDistname := distname
			for _, mod := range token.Varuse.modifiers {
				if mod == "tl" {
					newDistname = strings.ToLower(newDistname)
				} else if hasPrefix(mod, "S") {
					newDistname = subst(newDistname, mod)
				} else {
					newDistname = token.Text
					break
				}
			}
			result += newDistname
		} else {
			result += token.Text
		}
	}
	return result
}

func (pkg *Package) checkUpdate() {
	if pkg.EffectivePkgbase != "" {
		for _, sugg := range G.globalData.GetSuggestedPackageUpdates() {
			if pkg.EffectivePkgbase != sugg.Pkgname {
				continue
			}

			suggver, comment := sugg.Version, sugg.Comment
			if comment != "" {
				comment = " (" + comment + ")"
			}

			pkgnameLine := pkg.EffectivePkgnameLine
			cmp := pkgverCmp(pkg.EffectivePkgversion, suggver)
			switch {
			case cmp < 0:
				pkgnameLine.Warn2("This package should be updated to %s%s.", sugg.Version, comment)
				Explain2(
					"The wishlist for package updates in doc/TODO mentions that a newer",
					"version of this package is available.")
			case cmp > 0:
				pkgnameLine.Note2("This package is newer than the update request to %s%s.", suggver, comment)
			default:
				pkgnameLine.Note2("The update request to %s from doc/TODO%s has been done.", suggver, comment)
			}
		}
	}
}

func (pkg *Package) ChecklinesPackageMakefileVarorder(mklines *MkLines) {
	if G.opts.Debug {
		defer tracecall0()()
	}

	if !G.opts.WarnOrder || pkg.seenMakefileCommon {
		return
	}

	type OccCount uint8
	const (
		once OccCount = iota
		optional
		many
	)
	type OccDef struct {
		varname string
		count   OccCount
	}
	type OccGroup struct {
		name  string
		count OccCount
		occ   []OccDef
	}

	var sections = []OccGroup{
		{"Initial comments", once,
			[]OccDef{},
		},
		{"Unsorted stuff, part 1", once,
			[]OccDef{
				{"DISTNAME", optional},
				{"PKGNAME", optional},
				{"PKGREVISION", optional},
				{"CATEGORIES", once},
				{"MASTER_SITES", optional},
				{"DIST_SUBDIR", optional},
				{"EXTRACT_SUFX", optional},
				{"DISTFILES", many},
				{"SITES.*", many},
			},
		},
		{"Distribution patches", optional,
			[]OccDef{
				{"PATCH_SITES", optional}, // or once?
				{"PATCH_SITE_SUBDIR", optional},
				{"PATCHFILES", optional}, // or once?
				{"PATCH_DIST_ARGS", optional},
				{"PATCH_DIST_STRIP", optional},
				{"PATCH_DIST_CAT", optional},
			},
		},
		{"Unsorted stuff, part 2", once,
			[]OccDef{
				{"MAINTAINER", optional},
				{"OWNER", optional},
				{"HOMEPAGE", optional},
				{"COMMENT", once},
				{"LICENSE", once},
			},
		},
		{"Legal issues", optional,
			[]OccDef{
				{"LICENSE_FILE", optional},
				{"RESTRICTED", optional},
				{"NO_BIN_ON_CDROM", optional},
				{"NO_BIN_ON_FTP", optional},
				{"NO_SRC_ON_CDROM", optional},
				{"NO_SRC_ON_FTP", optional},
			},
		},
		{"Technical restrictions", optional,
			[]OccDef{
				{"BROKEN_EXCEPT_ON_PLATFORM", many},
				{"BROKEN_ON_PLATFORM", many},
				{"NOT_FOR_PLATFORM", many},
				{"ONLY_FOR_PLATFORM", many},
				{"NOT_FOR_COMPILER", many},
				{"ONLY_FOR_COMPILER", many},
				{"NOT_FOR_UNPRIVILEGED", optional},
				{"ONLY_FOR_UNPRIVILEGED", optional},
			},
		},
		{"Dependencies", optional,
			[]OccDef{
				{"BUILD_DEPENDS", many},
				{"TOOL_DEPENDS", many},
				{"DEPENDS", many},
			},
		},
	}

	lineno := 0
	sectindex := -1
	varindex := 0
	nextSection := true
	var vars []OccDef
	below := make(map[string]string)
	var belowWhat string

	// If the current section is optional but contains non-optional
	// fields, the complete section may be skipped as long as there
	// has not been a non-optional variable.
	maySkipSection := false

	// In each iteration, one of the following becomes true:
	// - new lineno > old lineno
	// - new sectindex > old sectindex
	// - new sectindex == old sectindex && new varindex > old varindex
	// - new nextSection == true && old nextSection == false
	for lineno < len(mklines.lines) {
		mkline := mklines.mklines[lineno]
		line := mklines.lines[lineno]
		text := line.Text

		if G.opts.Debug {
			traceStep("[varorder] section %d variable %d vars %v", sectindex, varindex, vars)
		}

		if nextSection {
			nextSection = false
			sectindex++
			if !(sectindex < len(sections)) {
				break
			}
			vars = sections[sectindex].occ
			maySkipSection = sections[sectindex].count == optional
			varindex = 0
		}

		switch {
		case hasPrefix(text, "#"):
			lineno++

		case mkline.IsVarassign():
			varcanon := mkline.Varcanon()

			if belowText, exists := below[varcanon]; exists {
				if belowText != "" {
					line.Warn2("%s appears too late. Please put it below %s.", varcanon, belowText)
				} else {
					line.Warn1("%s appears too late. It should be the very first definition.", varcanon)
				}
				lineno++
				continue
			}

			for varindex < len(vars) && varcanon != vars[varindex].varname && (vars[varindex].count != once || maySkipSection) {
				if vars[varindex].count == once {
					maySkipSection = false
				}
				below[vars[varindex].varname] = belowWhat
				varindex++
			}
			switch {
			case !(varindex < len(vars)):
				if sections[sectindex].count != optional {
					line.Warn0("Empty line expected.")
				}
				nextSection = true

			case varcanon != vars[varindex].varname:
				line.Warn2("Expected %s, but found %s.", vars[varindex].varname, varcanon)
				lineno++

			default:
				if vars[varindex].count != many {
					below[vars[varindex].varname] = belowWhat
					varindex++
				}
				lineno++
			}
			belowWhat = varcanon

		default:
			for varindex < len(vars) {
				if vars[varindex].count == once && !maySkipSection {
					line.Warn1("The canonical position for the required variable %s is here.", vars[varindex].varname)
					Explain(
						"In simple package Makefiles, some common variables should be",
						"arranged in a specific order.",
						"",
						"See doc/Makefile-example or the pkgsrc guide, section",
						"\"Package components\", subsection \"Makefile\" for more information.")
				}
				below[vars[varindex].varname] = belowWhat
				varindex++
			}
			nextSection = true
			if text == "" {
				belowWhat = "the previous empty line"
				lineno++
			}
		}
	}
}

func (mklines *MkLines) checkForUsedComment(relativeName string) {
	lines := mklines.lines
	if len(lines) < 3 {
		return
	}

	expected := "# used by " + relativeName
	for _, line := range lines {
		if line.Text == expected {
			return
		}
	}

	i := 0
	for i < 2 && hasPrefix(lines[i].Text, "#") {
		i++
	}

	insertLine := lines[i]
	if !insertLine.AutofixInsertBefore(expected) {
		insertLine.Warn1("Please add a line %q here.", expected)
		Explain(
			"Since Makefile.common files usually don't have any comments and",
			"therefore not a clearly defined interface, they should at least",
			"contain references to all files that include them, so that it is",
			"easier to see what effects future changes may have.",
			"",
			"If there are more than five packages that use a Makefile.common,",
			"you should think about giving it a proper name (maybe plugin.mk) and",
			"documenting its interface.")
	}
	SaveAutofixChanges(lines)
}

func (pkg *Package) checkLocallyModified(fname string) {
	if G.opts.Debug {
		defer tracecall(fname)()
	}

	ownerLine := pkg.vardef["OWNER"]
	maintainerLine := pkg.vardef["MAINTAINER"]
	owner := ""
	maintainer := ""
	if ownerLine != nil && !containsVarRef(ownerLine.Value()) {
		owner = ownerLine.Value()
	}
	if maintainerLine != nil && !containsVarRef(maintainerLine.Value()) && maintainerLine.Value() != "pkgsrc-users@NetBSD.org" {
		maintainer = maintainerLine.Value()
	}
	if owner == "" && maintainer == "" {
		return
	}

	user, err := user.Current()
	if err != nil || user.Username == "" {
		return
	}
	// On Windows, this is `Computername\Username`.
	username := regcomp(`^.*\\`).ReplaceAllString(user.Username, "")

	if G.opts.Debug {
		traceStep("user=%q owner=%q maintainer=%q", username, owner, maintainer)
	}

	if username == strings.Split(owner, "@")[0] || username == strings.Split(maintainer, "@")[0] {
		return
	}

	if isLocallyModified(fname) {
		if owner != "" {
			NewLineWhole(fname).Warn1("Don't commit changes to this file without asking the OWNER, %s.", owner)
			Explain2(
				"See the pkgsrc guide, section \"Package components\",",
				"keyword \"owner\", for more information.")
		}
		if maintainer != "" {
			NewLineWhole(fname).Note1("Please only commit changes that %s would approve.", maintainer)
			Explain2(
				"See the pkgsrc guide, section \"Package components\",",
				"keyword \"maintainer\", for more information.")
		}
	}
}
