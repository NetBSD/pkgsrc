package main

import (
	"path"
	"regexp"
	"strconv"
	"strings"
)

func checkpackagePossibleDowngrade() {
	defer tracecall("checkpackagePossibleDowngrade")()

	m, _, pkgversion := match2(G.pkgContext.effectivePkgname, rePkgname)
	if !m {
		return
	}

	line := G.pkgContext.effectivePkgnameLine

	change := G.globalData.lastChange[G.pkgContext.pkgpath]
	if change == nil {
		_ = G.opts.DebugMisc && line.debugf("No change log for package %q", G.pkgContext.pkgpath)
		return
	}

	if change.action == "Updated" {
		if pkgverCmp(pkgversion, change.version) < 0 {
			line.warnf("The package is being downgraded from %s to %s", change.version, pkgversion)
		}
	}
}

func checklinesBuildlink3Inclusion(lines []*Line) {
	defer tracecall("checklinesbuildlink3Inclusion")()

	if G.pkgContext == nil {
		return
	}

	// Collect all the included buildlink3.mk files from the file.
	includedFiles := make(map[string]*Line)
	for _, line := range lines {
		if m, _, file := match2(line.text, reMkInclude); m {
			if m, bl3 := match1(file, `^\.\./\.\./(.*)/buildlink3\.mk`); m {
				includedFiles[bl3] = line
				if G.pkgContext.bl3[bl3] == nil {
					line.warnf("%s/buildlink3.mk is included by this file but not by the package.", bl3)
				}
			}
		}
	}

	if G.opts.DebugMisc {
		for packageBl3, line := range G.pkgContext.bl3 {
			if includedFiles[packageBl3] == nil {
				line.debugf("%s/buildlink3.mk is included by the package but not by the buildlink3.mk file.", packageBl3)
			}
		}
	}
}

func checkdirPackage(pkgpath string) {
	defer tracecall("checkdirPackage", pkgpath)()
	ctx := newPkgContext(pkgpath)
	G.pkgContext = ctx
	defer func() { G.pkgContext = nil }()

	// we need to handle the Makefile first to get some variables
	lines := loadPackageMakefile(G.currentDir + "/Makefile")
	if lines == nil {
		errorf(G.currentDir+"/Makefile", NO_LINES, "Cannot be read.")
		return
	}

	files := dirglob(G.currentDir)
	if ctx.pkgdir != "." {
		files = append(files, dirglob(G.currentDir+"/"+ctx.pkgdir)...)
	}
	if G.opts.CheckExtra {
		files = append(files, dirglob(G.currentDir+"/"+ctx.filesdir)...)
	}
	files = append(files, dirglob(G.currentDir+"/"+ctx.patchdir)...)
	if ctx.distinfoFile != "distinfo" && ctx.distinfoFile != "./distinfo" {
		files = append(files, G.currentDir+"/"+ctx.distinfoFile)
	}
	haveDistinfo := false
	havePatches := false

	// Determine the used variables before checking any of the Makefile fragments.
	for _, fname := range files {
		if (hasPrefix(path.Base(fname), "Makefile.") || hasSuffix(fname, ".mk")) &&
			!matches(fname, `patch-`) &&
			!contains(fname, G.pkgContext.pkgdir+"/") &&
			!contains(fname, G.pkgContext.filesdir+"/") {
			if lines, err := readLines(fname, true); err == nil && lines != nil {
				ParselinesMk(lines)
				determineUsedVariables(lines)
			}
		}
	}

	for _, fname := range files {
		if fname == G.currentDir+"/Makefile" {
			if G.opts.CheckMakefile {
				checkfilePackageMakefile(fname, lines)
			}
		} else {
			checkfile(fname)
		}
		if matches(fname, `/patches/patch-*$`) {
			havePatches = true
		} else if hasSuffix(fname, "/distinfo") {
			haveDistinfo = true
		}
	}

	if G.opts.CheckDistinfo && G.opts.CheckPatches {
		if havePatches && !haveDistinfo {
			warnf(G.currentDir+"/"+ctx.distinfoFile, NO_LINES, "File not found. Please run \"%s makepatchsum\".", confMake)
		}
	}

	if !isEmptyDir(G.currentDir + "/scripts") {
		warnf(G.currentDir+"/scripts", NO_LINES, "This directory and its contents are deprecated! Please call the script(s) explicitly from the corresponding target(s) in the pkg's Makefile.")
	}
}

func checkfilePackageMakefile(fname string, lines []*Line) {
	defer tracecall("checkfilePackageMakefile", fname, len(lines))()

	vardef := G.pkgContext.vardef
	if vardef["PLIST_SRC"] == nil &&
		vardef["GENERATE_PLIST"] == nil &&
		vardef["META_PACKAGE"] == nil &&
		!fileExists(G.currentDir+"/"+G.pkgContext.pkgdir+"/PLIST") &&
		!fileExists(G.currentDir+"/"+G.pkgContext.pkgdir+"/PLIST.common") {
		warnf(fname, NO_LINES, "Neither PLIST nor PLIST.common exist, and PLIST_SRC is unset. Are you sure PLIST handling is ok?")
	}

	if (vardef["NO_CHECKSUM"] != nil || vardef["META_PACKAGE"] != nil) && isEmptyDir(G.currentDir+"/"+G.pkgContext.patchdir) {
		if distinfoFile := G.currentDir + "/" + G.pkgContext.distinfoFile; fileExists(distinfoFile) {
			warnf(distinfoFile, NO_LINES, "This file should not exist if NO_CHECKSUM or META_PACKAGE is set.")
		}
	} else {
		if distinfoFile := G.currentDir + "/" + G.pkgContext.distinfoFile; !containsVarRef(distinfoFile) && !fileExists(distinfoFile) {
			warnf(distinfoFile, NO_LINES, "File not found. Please run \"%s makesum\".", confMake)
		}
	}

	if vardef["REPLACE_PERL"] != nil && vardef["NO_CONFIGURE"] != nil {
		vardef["REPLACE_PERL"].warnf("REPLACE_PERL is ignored when ...")
		vardef["NO_CONFIGURE"].warnf("... NO_CONFIGURE is set.")
	}

	if vardef["LICENSE"] == nil {
		errorf(fname, NO_LINES, "Each package must define its LICENSE.")
	}

	if vardef["GNU_CONFIGURE"] != nil && vardef["USE_LANGUAGES"] != nil {
		languagesLine := vardef["USE_LANGUAGES"]
		value := languagesLine.extra["value"].(string)

		if languagesLine.extra["comment"] != nil && matches(languagesLine.extra["comment"].(string), `(?-i)\b(?:c|empty|none)\b`) {
			// Don't emit a warning, since the comment
			// probably contains a statement that C is
			// really not needed.

		} else if !matches(value, `(?:^|\s+)(?:c|c99|objc)(?:\s+|$)`) {
			vardef["GNU_CONFIGURE"].warnf("GNU_CONFIGURE almost always needs a C compiler, ...")
			languagesLine.warnf("... but \"c\" is not added to USE_LANGUAGES.")
		}
	}

	distnameLine := vardef["DISTNAME"]
	pkgnameLine := vardef["PKGNAME"]

	distname := ""
	if distnameLine != nil {
		distname = distnameLine.extra["value"].(string)
	}
	pkgname := ""
	if pkgnameLine != nil {
		pkgname = pkgnameLine.extra["value"].(string)
	}

	if distname != "" && pkgname != "" {
		pkgname = pkgnameFromDistname(pkgname, distname)
	}

	if pkgname != "" && pkgname == distname && pkgnameLine.extra["comment"].(string) == "" {
		pkgnameLine.notef("PKGNAME is ${DISTNAME} by default. You probably don't need to define PKGNAME.")
	}

	if pkgname == "" && distname != "" && !containsVarRef(distname) && !matches(distname, rePkgname) {
		distnameLine.warnf("As DISTNAME is not a valid package name, please define the PKGNAME explicitly.")
	}

	G.pkgContext.effectivePkgname,
		G.pkgContext.effectivePkgnameLine,
		G.pkgContext.effectivePkgbase,
		G.pkgContext.effectivePkgversion = determineEffectivePkgVars(pkgname, pkgnameLine, distname, distnameLine)

	if G.pkgContext.effectivePkgnameLine != nil {
		_ = G.opts.DebugMisc && G.pkgContext.effectivePkgnameLine.debugf("Effective name=%q base=%q version=%q",
			G.pkgContext.effectivePkgname, G.pkgContext.effectivePkgbase, G.pkgContext.effectivePkgversion)
	}

	checkpackagePossibleDowngrade()

	if vardef["COMMENT"] == nil {
		warnf(fname, NO_LINES, "No COMMENT given.")
	}

	if vardef["USE_IMAKE"] != nil && vardef["USE_X11"] != nil {
		vardef["USE_IMAKE"].notef("USE_IMAKE makes ...")
		vardef["USE_X11"].notef("... USE_X11 superfluous.")
	}

	if G.pkgContext.effectivePkgbase != "" {
		for _, sugg := range G.globalData.getSuggestedPackageUpdates() {
			if G.pkgContext.effectivePkgbase != sugg.pkgname {
				continue
			}

			suggver, comment := sugg.version, sugg.comment
			if comment != "" {
				comment = " (" + comment + ")"
			}

			pkgnameLine := G.pkgContext.effectivePkgnameLine
			cmp := pkgverCmp(G.pkgContext.effectivePkgversion, suggver)
			switch {
			case cmp < 0:
				pkgnameLine.warnf("This package should be updated to %s%s.", sugg.version, comment)
				pkgnameLine.explain(
					"The wishlist for package updates in doc/TODO mentions that a newer",
					"version of this package is available.")
			case cmp > 0:
				pkgnameLine.notef("This package is newer than the update request to %s%s.", suggver, comment)
			default:
				pkgnameLine.notef("The update request to %s from doc/TODO%s has been done.", suggver, comment)
			}
		}
	}

	ChecklinesMk(lines)
	ChecklinesPackageMakefileVarorder(lines)
	saveAutofixChanges(lines)
}

func getNbpart() string {
	line := G.pkgContext.vardef["PKGREVISION"]
	if line == nil {
		return ""
	}
	pkgrevision := line.extra["value"].(string)
	if rev, err := strconv.Atoi(pkgrevision); err == nil {
		return sprintf("nb%d", rev)
	}
	return ""
}

func determineEffectivePkgVars(pkgname string, pkgnameLine *Line, distname string, distnameLine *Line) (string, *Line, string, string) {
	if pkgname != "" && !containsVarRef(pkgname) {
		if m, m1, m2 := match2(pkgname, rePkgname); m {
			return pkgname + getNbpart(), pkgnameLine, m1, m2
		}
	}
	if distname != "" && !containsVarRef(distname) {
		if m, m1, m2 := match2(distname, rePkgname); m {
			return distname + getNbpart(), distnameLine, m1, m2
		}
	}
	return "", nil, "", ""
}

func pkgnameFromDistname(pkgname, distname string) string {
	pkgname = strings.Replace(pkgname, "${DISTNAME}", distname, -1)

	if m, before, sep, subst, after := match4(pkgname, `^(.*)\$\{DISTNAME:S(.)([^\\}:]+)\}(.*)$`); m {
		qsep := regexp.QuoteMeta(sep)
		if m, left, from, right, to, mod := match5(subst, `^(\^?)([^:]*)(\$?)`+qsep+`([^:]*)`+qsep+`(g?)$`); m {
			newPkgname := before + mkopSubst(distname, left != "", from, right != "", to, mod != "") + after
			_ = G.opts.DebugMisc && G.pkgContext.vardef["PKGNAME"].debugf("pkgnameFromDistname %q => %q", pkgname, newPkgname)
			pkgname = newPkgname
		}
	}
	return pkgname
}

func ChecklinesPackageMakefileVarorder(lines []*Line) {
	defer tracecall("ChecklinesPackageMakefileVarorder", len(lines))

	if !G.opts.WarnOrder {
		return
	}

	type OccCount int
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

	if G.pkgContext == nil || G.pkgContext.seenMakefileCommon {
		return
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
	// - new next_section == true && old next_section == false
	for lineno <= len(lines) {
		line := lines[lineno]
		text := line.text

		_ = G.opts.DebugMisc && line.debugf("[varorder] section %d variable %d", sectindex, varindex)

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

		case line.extra["varcanon"] != nil:
			varcanon := line.extra["varcanon"].(string)

			if belowText, exists := below[varcanon]; exists {
				if belowText != "" {
					line.warnf("%s appears too late. Please put it below %s.", varcanon, belowText)
				} else {
					line.warnf("%s appears too late. It should be the very first definition.", varcanon)
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
					line.warnf("Empty line expected.")
				}
				nextSection = true

			case varcanon != vars[varindex].varname:
				line.warnf("Expected %s, but found %s.", vars[varindex].varname, varcanon)
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
					line.warnf("%s should be set here.", vars[varindex].varname)
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
