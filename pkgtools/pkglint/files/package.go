package main

import (
	"fmt"
	"netbsd.org/pkglint/pkgver"
	"path"
	"strconv"
	"strings"
)

const rePkgname = `^([\w\-.+]+)-(\d[.0-9A-Z_a-z]*)$`

// Package contains data for the pkgsrc package that is currently checked.
type Package struct {
	dir                  string       // The directory of the package, for resolving files
	Pkgpath              string       // e.g. "category/pkgdir"
	Pkgdir               string       // PKGDIR from the package Makefile
	Filesdir             string       // FILESDIR from the package Makefile
	Patchdir             string       // PATCHDIR from the package Makefile
	DistinfoFile         string       // DISTINFO_FILE from the package Makefile
	EffectivePkgname     string       // PKGNAME or DISTNAME from the package Makefile, including nb13
	EffectivePkgbase     string       // The effective PKGNAME without the version
	EffectivePkgversion  string       // The version part of the effective PKGNAME, excluding nb13
	EffectivePkgnameLine MkLine       // The origin of the three effective_* values
	Plist                PlistContent // Files and directories mentioned in the PLIST files

	vars                  Scope
	bl3                   map[string]Line // buildlink3.mk name => line; contains only buildlink3.mk files that are directly included.
	included              map[string]Line // filename => line
	seenMakefileCommon    bool            // Does the package have any .includes?
	conditionalIncludes   map[string]MkLine
	unconditionalIncludes map[string]MkLine
	once                  Once
	IgnoreMissingPatches  bool // In distinfo, don't warn about patches that cannot be found.
}

func NewPackage(dir string) *Package {
	pkgpath := G.Pkgsrc.ToRel(dir)
	if strings.Count(pkgpath, "/") != 1 {
		panic(fmt.Sprintf("Package directory %q must be two subdirectories below the pkgsrc root %q.", dir, G.Pkgsrc.File(".")))
	}

	pkg := Package{
		dir:                   dir,
		Pkgpath:               pkgpath,
		Pkgdir:                ".",
		Filesdir:              "files",
		Patchdir:              "patches",
		DistinfoFile:          "${PKGDIR}/distinfo",
		Plist:                 NewPlistContent(),
		vars:                  NewScope(),
		bl3:                   make(map[string]Line),
		included:              make(map[string]Line),
		conditionalIncludes:   make(map[string]MkLine),
		unconditionalIncludes: make(map[string]MkLine),
	}
	pkg.vars.DefineAll(G.Pkgsrc.UserDefinedVars)

	pkg.vars.Fallback("PKGDIR", ".")
	pkg.vars.Fallback("DISTINFO_FILE", "${PKGDIR}/distinfo")
	pkg.vars.Fallback("FILESDIR", "files")
	pkg.vars.Fallback("PATCHDIR", "patches")
	pkg.vars.Fallback("KRB5_TYPE", "heimdal")
	pkg.vars.Fallback("PGSQL_VERSION", "95")
	pkg.vars.Fallback(".CURDIR", ".") // FIXME: In reality, this is an absolute pathname.

	return &pkg
}

// File returns the (possibly absolute) path to relativeFileName,
// as resolved from the package's directory.
// Variables that are known in the package are resolved, e.g. ${PKGDIR}.
func (pkg *Package) File(relativeFileName string) string {
	return cleanpath(resolveVariableRefs(pkg.dir + "/" + relativeFileName))
}

func (pkg *Package) checkPossibleDowngrade() {
	if trace.Tracing {
		defer trace.Call0()()
	}

	m, _, pkgversion := match2(pkg.EffectivePkgname, rePkgname)
	if !m {
		return
	}

	mkline := pkg.EffectivePkgnameLine

	change := G.Pkgsrc.LastChange[pkg.Pkgpath]
	if change == nil {
		if trace.Tracing {
			trace.Step1("No change log for package %q", pkg.Pkgpath)
		}
		return
	}

	if change.Action == "Updated" {
		changeVersion := replaceAll(change.Version, `nb\d+$`, "")
		if pkgver.Compare(pkgversion, changeVersion) < 0 {
			mkline.Warnf("The package is being downgraded from %s (see %s) to %s.", change.Version, mkline.Line.RefTo(change.Line), pkgversion)
			G.Explain(
				"The files in doc/CHANGES-*, in which all version changes are",
				"recorded, have a higher version number than what the package says.",
				"This is unusual, since packages are typically upgraded instead of",
				"downgraded.")
		}
	}
}

func (pkg *Package) checklinesBuildlink3Inclusion(mklines MkLines) {
	if trace.Tracing {
		defer trace.Call0()()
	}

	// Collect all the included buildlink3.mk files from the file.
	includedFiles := make(map[string]MkLine)
	for _, mkline := range mklines.mklines {
		if mkline.IsInclude() {
			includedFile := mkline.IncludedFile()
			if m, bl3 := match1(includedFile, `^\.\./\.\./(.*)/buildlink3\.mk`); m {
				includedFiles[bl3] = mkline
				if pkg.bl3[bl3] == nil {
					mkline.Warnf("%s/buildlink3.mk is included by this file but not by the package.", bl3)
				}
			}
		}
	}

	if trace.Tracing {
		for packageBl3 := range pkg.bl3 {
			if includedFiles[packageBl3] == nil {
				trace.Step1("%s/buildlink3.mk is included by the package but not by the buildlink3.mk file.", packageBl3)
			}
		}
	}
}

func (pkg *Package) loadPackageMakefile() MkLines {
	filename := pkg.File("Makefile")
	if trace.Tracing {
		defer trace.Call1(filename)()
	}

	mainLines := NewMkLines(NewLines(filename, nil))
	allLines := NewMkLines(NewLines("", nil))
	if _, result := pkg.readMakefile(filename, mainLines, allLines, ""); !result {
		LoadMk(filename, NotEmpty|LogErrors) // Just for the LogErrors.
		return nil
	}

	if G.Opts.DumpMakefile {
		G.out.WriteLine("Whole Makefile (with all included files) follows:")
		for _, line := range allLines.lines.Lines {
			G.out.WriteLine(line.String())
		}
	}

	if pkg.vars.Defined("USE_CMAKE") {
		mainLines.Tools.def("cmake", "", false, AtRunTime)
		mainLines.Tools.def("cpack", "", false, AtRunTime)
	}

	allLines.DetermineUsedVariables()
	allLines.CheckRedundantVariables()

	pkg.Pkgdir, _ = pkg.vars.Value("PKGDIR")
	pkg.DistinfoFile, _ = pkg.vars.Value("DISTINFO_FILE")
	pkg.Filesdir, _ = pkg.vars.Value("FILESDIR")
	pkg.Patchdir, _ = pkg.vars.Value("PATCHDIR")

	// See lang/php/ext.mk
	if varIsDefinedSimilar("PHPEXT_MK") {
		if !varIsDefinedSimilar("USE_PHP_EXT_PATCHES") {
			pkg.Patchdir = "patches"
		}
		if varIsDefinedSimilar("PECL_VERSION") {
			pkg.DistinfoFile = "distinfo"
		} else {
			pkg.IgnoreMissingPatches = true
		}

		// For PHP modules that are not PECL, this combination means that
		// the patches in the distinfo cannot be found in PATCHDIR.
	}

	if trace.Tracing {
		trace.Step1("DISTINFO_FILE=%s", pkg.DistinfoFile)
		trace.Step1("FILESDIR=%s", pkg.Filesdir)
		trace.Step1("PATCHDIR=%s", pkg.Patchdir)
		trace.Step1("PKGDIR=%s", pkg.Pkgdir)
	}

	return mainLines
}

func (pkg *Package) readMakefile(filename string, mainLines MkLines, allLines MkLines, includingFnameForUsedCheck string) (exists bool, result bool) {
	if trace.Tracing {
		defer trace.Call1(filename)()
	}

	fileMklines := LoadMk(filename, NotEmpty)
	if fileMklines == nil {
		return false, false
	}
	exists = true

	isMainMakefile := len(mainLines.mklines) == 0

	result = true
	lineAction := func(mkline MkLine) bool {
		if isMainMakefile {
			mainLines.mklines = append(mainLines.mklines, mkline)
			mainLines.lines.Lines = append(mainLines.lines.Lines, mkline.Line)
		}
		allLines.mklines = append(allLines.mklines, mkline)
		allLines.lines.Lines = append(allLines.lines.Lines, mkline.Line)

		var includedFile, incDir, incBase string
		if mkline.IsInclude() {
			includedFile = resolveVariableRefs(mkline.ResolveVarsInRelativePath(mkline.IncludedFile(), true))
			if containsVarRef(includedFile) {
				if !contains(filename, "/mk/") {
					mkline.Notef("Skipping include file %q. This may result in false warnings.", includedFile)
				}
				includedFile = ""
			}
			incDir, incBase = path.Split(includedFile)
		}

		if includedFile != "" {
			if mkline.Basename != "buildlink3.mk" {
				if m, bl3File := match1(includedFile, `^\.\./\.\./(.*)/buildlink3\.mk$`); m {
					pkg.bl3[bl3File] = mkline.Line
					if trace.Tracing {
						trace.Step1("Buildlink3 file in package: %q", bl3File)
					}
				}
			}
		}

		if includedFile != "" && pkg.included[includedFile] == nil {
			pkg.included[includedFile] = mkline.Line

			if matches(includedFile, `^\.\./[^./][^/]*/[^/]+`) {
				mkline.Warnf("References to other packages should look like \"../../category/package\", not \"../package\".")
				mkline.ExplainRelativeDirs()
			}

			if mkline.Basename == "Makefile" && !hasPrefix(incDir, "../../mk/") && incBase != "buildlink3.mk" && incBase != "builtin.mk" && incBase != "options.mk" {
				if trace.Tracing {
					trace.Step1("Including %q sets seenMakefileCommon.", includedFile)
				}
				pkg.seenMakefileCommon = true
			}

			skip := contains(filename, "/mk/") || hasSuffix(includedFile, "/bsd.pkg.mk") || IsPrefs(includedFile)
			if !skip {
				dirname, _ := path.Split(filename)
				dirname = cleanpath(dirname)

				fullIncluded := dirname + "/" + includedFile
				if trace.Tracing {
					trace.Step1("Including %q.", fullIncluded)
				}
				fullIncluding := ifelseStr(incBase == "Makefile.common" && incDir != "", filename, "")
				innerExists, innerResult := pkg.readMakefile(fullIncluded, mainLines, allLines, fullIncluding)

				if !innerExists {
					if fileMklines.indentation.IsCheckedFile(includedFile) {
						return true // See https://github.com/rillig/pkglint/issues/1
					}

					// Only look in the directory relative to the
					// current file and in the package directory.
					// Make(1) has a list of include directories, but pkgsrc
					// doesn't make use of that, so pkglint also doesn't
					// need this extra complexity.
					pkgBasedir := pkg.File(".")
					if dirname != pkgBasedir { // Prevent unnecessary syscalls
						dirname = pkgBasedir

						fullIncludedFallback := dirname + "/" + includedFile
						innerExists, innerResult = pkg.readMakefile(fullIncludedFallback, mainLines, allLines, fullIncluding)
					}

					if !innerExists {
						mkline.Errorf("Cannot read %q.", includedFile)
					}
				}

				if !innerResult {
					result = false
					return false
				}
			}
		}

		if mkline.IsVarassign() {
			varname, op, value := mkline.Varname(), mkline.Op(), mkline.Value()

			if op != opAssignDefault || !pkg.vars.Defined(varname) {
				if trace.Tracing {
					trace.Stepf("varassign(%q, %q, %q)", varname, op, value)
				}
				pkg.vars.Define(varname, mkline)
			}
		}
		return true
	}
	atEnd := func(mkline MkLine) {}
	fileMklines.ForEachEnd(lineAction, atEnd)

	if includingFnameForUsedCheck != "" {
		fileMklines.CheckForUsedComment(G.Pkgsrc.ToRel(includingFnameForUsedCheck))
	}

	// For every included buildlink3.mk, include the corresponding builtin.mk
	// automatically since the pkgsrc infrastructure does the same.
	if false && path.Base(filename) == "buildlink3.mk" {
		builtin := path.Join(path.Dir(filename), "builtin.mk")
		if fileExists(builtin) {
			pkg.readMakefile(builtin, mainLines, allLines, "")
		}
	}

	return
}

func (pkg *Package) checkfilePackageMakefile(filename string, mklines MkLines) {
	if trace.Tracing {
		defer trace.Call1(filename)()
	}

	vars := pkg.vars
	if !vars.Defined("PLIST_SRC") &&
		!vars.Defined("GENERATE_PLIST") &&
		!vars.Defined("META_PACKAGE") &&
		!fileExists(pkg.File(pkg.Pkgdir+"/PLIST")) &&
		!fileExists(pkg.File(pkg.Pkgdir+"/PLIST.common")) {
		NewLineWhole(filename).Warnf("Neither PLIST nor PLIST.common exist, and PLIST_SRC is unset.")
	}

	if (vars.Defined("NO_CHECKSUM") || vars.Defined("META_PACKAGE")) && isEmptyDir(pkg.File(pkg.Patchdir)) {
		if distinfoFile := pkg.File(pkg.DistinfoFile); fileExists(distinfoFile) {
			NewLineWhole(distinfoFile).Warnf("This file should not exist if NO_CHECKSUM or META_PACKAGE is set.")
		}
	} else {
		if distinfoFile := pkg.File(pkg.DistinfoFile); !containsVarRef(distinfoFile) && !fileExists(distinfoFile) {
			NewLineWhole(distinfoFile).Warnf(
				"File not found. Please run %q or define NO_CHECKSUM=yes in the package Makefile.", bmake("makesum"))
		}
	}

	if perlLine, noconfLine := vars.FirstDefinition("REPLACE_PERL"), vars.FirstDefinition("NO_CONFIGURE"); perlLine != nil && noconfLine != nil {
		perlLine.Warnf("REPLACE_PERL is ignored when NO_CONFIGURE is set (in %s).", perlLine.RefTo(noconfLine))
	}

	if !vars.Defined("LICENSE") && !vars.Defined("META_PACKAGE") && pkg.once.FirstTime("LICENSE") {
		NewLineWhole(filename).Errorf("Each package must define its LICENSE.")
	}

	pkg.checkGnuConfigureUseLanguages()
	pkg.determineEffectivePkgVars()
	pkg.checkPossibleDowngrade()

	if !vars.Defined("COMMENT") {
		NewLineWhole(filename).Warnf("No COMMENT given.")
	}

	if imake, x11 := vars.FirstDefinition("USE_IMAKE"), vars.FirstDefinition("USE_X11"); imake != nil && x11 != nil {
		if !hasSuffix(x11.Filename, "/mk/x11.buildlink3.mk") {
			imake.Notef("USE_IMAKE makes USE_X11 in %s superfluous.", imake.RefTo(x11))
		}
	}

	pkg.checkUpdate()
	mklines.Check()
	pkg.CheckVarorder(mklines)
	SaveAutofixChanges(mklines.lines)
}

func (pkg *Package) checkGnuConfigureUseLanguages() {
	vars := pkg.vars

	if gnuLine, useLine := vars.FirstDefinition("GNU_CONFIGURE"), vars.FirstDefinition("USE_LANGUAGES"); gnuLine != nil && useLine != nil {
		if matches(useLine.VarassignComment(), `(?-i)\b(?:c|empty|none)\b`) {
			// Don't emit a warning, since the comment
			// probably contains a statement that C is
			// really not needed.

		} else if !matches(useLine.Value(), `(?:^|[\t ]+)(?:c|c99|objc)(?:[\t ]+|$)`) {
			gnuLine.Warnf("GNU_CONFIGURE almost always needs a C compiler, but \"c\" is not added to USE_LANGUAGES in %s.",
				gnuLine.RefTo(useLine))
		}
	}
}

func (pkg *Package) getNbpart() string {
	pkgrevision, _ := pkg.vars.Value("PKGREVISION")
	if rev, err := strconv.Atoi(pkgrevision); err == nil {
		return "nb" + strconv.Itoa(rev)
	}
	return ""
}

func (pkg *Package) determineEffectivePkgVars() {
	distnameLine := pkg.vars.FirstDefinition("DISTNAME")
	pkgnameLine := pkg.vars.FirstDefinition("PKGNAME")

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

	if pkgname != "" && pkgname == distname && pkgnameLine.VarassignComment() == "" {
		pkgnameLine.Notef("PKGNAME is ${DISTNAME} by default. You probably don't need to define PKGNAME.")
	}

	if pkgname == "" && distname != "" && !containsVarRef(distname) && !matches(distname, rePkgname) {
		distnameLine.Warnf("As DISTNAME is not a valid package name, please define the PKGNAME explicitly.")
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
		if trace.Tracing {
			trace.Stepf("Effective name=%q base=%q version=%q",
				pkg.EffectivePkgname, pkg.EffectivePkgbase, pkg.EffectivePkgversion)
		}
	}
}

func (pkg *Package) pkgnameFromDistname(pkgname, distname string) string {
	tokens := NewMkParser(nil, pkgname, false).MkTokens()

	result := ""
	for _, token := range tokens {
		if token.Varuse != nil && token.Varuse.varname == "DISTNAME" {
			newDistname := distname
			for _, mod := range token.Varuse.modifiers {
				if mod.IsToLower() {
					newDistname = strings.ToLower(newDistname)
				} else if m, regex, _, _, _ := mod.MatchSubst(); m && !regex {
					newDistname = mod.Subst(newDistname)
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
		for _, sugg := range G.Pkgsrc.GetSuggestedPackageUpdates() {
			if pkg.EffectivePkgbase != sugg.Pkgname {
				continue
			}

			suggver, comment := sugg.Version, sugg.Comment
			if comment != "" {
				comment = " (" + comment + ")"
			}

			pkgnameLine := pkg.EffectivePkgnameLine
			cmp := pkgver.Compare(pkg.EffectivePkgversion, suggver)
			switch {
			case cmp < 0:
				pkgnameLine.Warnf("This package should be updated to %s%s.", sugg.Version, comment)
				G.Explain(
					"The wishlist for package updates in doc/TODO mentions that a newer",
					"version of this package is available.")
			case cmp > 0:
				pkgnameLine.Notef("This package is newer than the update request to %s%s.", suggver, comment)
			default:
				pkgnameLine.Notef("The update request to %s from doc/TODO%s has been done.", suggver, comment)
			}
		}
	}
}

// CheckVarorder checks that in simple package Makefiles,
// the most common variables appear in a fixed order.
// The order itself is a little arbitrary but provides
// at least a bit of consistency.
func (pkg *Package) CheckVarorder(mklines MkLines) {
	if trace.Tracing {
		defer trace.Call0()()
	}

	if !G.Opts.WarnOrder || pkg.seenMakefileCommon {
		return
	}

	type Repetition uint8
	const (
		optional Repetition = iota
		once
		many
	)
	type Variable struct {
		varname    string
		repetition Repetition
	}
	type Section struct {
		repetition Repetition
		vars       []Variable
	}
	variable := func(name string, repetition Repetition) Variable { return Variable{name, repetition} }
	section := func(repetition Repetition, vars ...Variable) Section { return Section{repetition, vars} }

	var sections = []Section{
		section(once,
			variable("GITHUB_PROJECT", optional), // either here or below MASTER_SITES
			variable("GITHUB_TAG", optional),
			variable("DISTNAME", optional),
			variable("PKGNAME", optional),
			variable("PKGREVISION", optional),
			variable("CATEGORIES", once),
			variable("MASTER_SITES", many),
			variable("GITHUB_PROJECT", optional), // either here or at the very top
			variable("GITHUB_TAG", optional),
			variable("DIST_SUBDIR", optional),
			variable("EXTRACT_SUFX", optional),
			variable("DISTFILES", many),
			variable("SITES.*", many)),
		section(optional,
			variable("PATCH_SITES", optional), // or once?
			variable("PATCH_SITE_SUBDIR", optional),
			variable("PATCHFILES", optional), // or once?
			variable("PATCH_DIST_ARGS", optional),
			variable("PATCH_DIST_STRIP", optional),
			variable("PATCH_DIST_CAT", optional)),
		section(once,
			variable("MAINTAINER", optional),
			variable("OWNER", optional),
			variable("HOMEPAGE", optional),
			variable("COMMENT", once),
			variable("LICENSE", once)),
		section(optional,
			variable("LICENSE_FILE", optional),
			variable("RESTRICTED", optional),
			variable("NO_BIN_ON_CDROM", optional),
			variable("NO_BIN_ON_FTP", optional),
			variable("NO_SRC_ON_CDROM", optional),
			variable("NO_SRC_ON_FTP", optional)),
		section(optional,
			variable("BROKEN_EXCEPT_ON_PLATFORM", many),
			variable("BROKEN_ON_PLATFORM", many),
			variable("NOT_FOR_PLATFORM", many),
			variable("ONLY_FOR_PLATFORM", many),
			variable("NOT_FOR_COMPILER", many),
			variable("ONLY_FOR_COMPILER", many),
			variable("NOT_FOR_UNPRIVILEGED", optional),
			variable("ONLY_FOR_UNPRIVILEGED", optional)),
		section(optional,
			variable("BUILD_DEPENDS", many),
			variable("TOOL_DEPENDS", many),
			variable("DEPENDS", many)),
	}

	firstRelevant := -1
	lastRelevant := -1
	skip := func() bool {
		relevantVars := make(map[string]bool)
		for _, section := range sections {
			for _, variable := range section.vars {
				relevantVars[variable.varname] = true
			}
		}

		firstIrrelevant := -1
		for i, mkline := range mklines.mklines {
			switch {
			case mkline.IsVarassign(), mkline.IsCommentedVarassign():
				varcanon := mkline.Varcanon()
				if relevantVars[varcanon] {
					if firstRelevant == -1 {
						firstRelevant = i
					}
					if firstIrrelevant != -1 {
						if trace.Tracing {
							trace.Stepf("Skipping varorder because of line %s.",
								mklines.mklines[firstIrrelevant].Linenos())
						}
						return true
					}
					lastRelevant = i
				} else {
					if firstIrrelevant == -1 {
						firstIrrelevant = i
					}
				}

			case mkline.IsComment(), mkline.IsEmpty():
				break

			default:
				if firstIrrelevant == -1 {
					firstIrrelevant = i
				}
			}
		}

		if firstRelevant == -1 {
			return true
		}
		interesting := mklines.mklines[firstRelevant : lastRelevant+1]

		varcanon := func() string {
			for len(interesting) > 0 && interesting[0].IsComment() {
				interesting = interesting[1:]
			}
			if len(interesting) > 0 && (interesting[0].IsVarassign() || interesting[0].IsCommentedVarassign()) {
				return interesting[0].Varcanon()
			}
			return ""
		}

		for _, section := range sections {
			for _, variable := range section.vars {
				switch variable.repetition {
				case optional:
					if varcanon() == variable.varname {
						interesting = interesting[1:]
					}
				case once:
					if varcanon() == variable.varname {
						interesting = interesting[1:]
					} else if section.repetition == once {
						if variable.varname != "LICENSE" {
							if trace.Tracing {
								trace.Stepf("Wrong varorder because %s is missing.", variable.varname)
							}
							return false
						}
					}
				case many:
					for varcanon() == variable.varname {
						interesting = interesting[1:]
					}
				}
			}

			for len(interesting) > 0 && (interesting[0].IsEmpty() || interesting[0].IsComment()) {
				interesting = interesting[1:]
			}
		}

		return len(interesting) == 0
	}

	if skip() {
		return
	}

	var canonical []string
	for _, section := range sections {
		for _, variable := range section.vars {
			found := false
			for _, mkline := range mklines.mklines[firstRelevant : lastRelevant+1] {
				if mkline.IsVarassign() || mkline.IsCommentedVarassign() {
					if mkline.Varcanon() == variable.varname {
						canonical = append(canonical, mkline.Varname())
						found = true
					}
				}
			}
			if !found && section.repetition == once && variable.repetition == once {
				canonical = append(canonical, variable.varname)
			}
		}
		if len(canonical) > 0 && canonical[len(canonical)-1] != "empty line" {
			canonical = append(canonical, "empty line")
		}
	}
	if len(canonical) > 0 && canonical[len(canonical)-1] == "empty line" {
		canonical = canonical[:len(canonical)-1]
	}

	mkline := mklines.mklines[firstRelevant]
	mkline.Warnf("The canonical order of the variables is %s.", strings.Join(canonical, ", "))
	G.Explain(
		"In simple package Makefiles, some common variables should be",
		"arranged in a specific order.",
		"",
		"See doc/Makefile-example for an example Makefile.",
		seeGuide("Package components, Makefile", "components.Makefile"))
}

func (pkg *Package) checkLocallyModified(filename string) {
	if trace.Tracing {
		defer trace.Call(filename)()
	}

	owner, _ := pkg.vars.Value("OWNER")
	maintainer, _ := pkg.vars.Value("MAINTAINER")
	if maintainer == "pkgsrc-users@NetBSD.org" {
		maintainer = ""
	}
	if owner == "" && maintainer == "" {
		return
	}

	username := G.CurrentUsername
	if trace.Tracing {
		trace.Stepf("user=%q owner=%q maintainer=%q", username, owner, maintainer)
	}

	if username == strings.Split(owner, "@")[0] || username == strings.Split(maintainer, "@")[0] {
		return
	}

	if isLocallyModified(filename) {
		if owner != "" {
			NewLineWhole(filename).Warnf("Don't commit changes to this file without asking the OWNER, %s.", owner)
			G.Explain(
				seeGuide("Package components, Makefile", "components.Makefile"))
		}
		if maintainer != "" {
			NewLineWhole(filename).Notef("Please only commit changes that %s would approve.", maintainer)
			G.Explain(
				"See the pkgsrc guide, section \"Package components\",",
				"keyword \"maintainer\", for more information.")
		}
	}
}

func (pkg *Package) CheckInclude(mkline MkLine, indentation *Indentation) {
	conditionalVars := mkline.ConditionalVars()
	if len(conditionalVars) == 0 {
		conditionalVars = indentation.Varnames()
		mkline.SetConditionalVars(conditionalVars)
	}

	if path.Dir(abspath(mkline.Filename)) == abspath(pkg.File(".")) {
		includedFile := mkline.IncludedFile()

		if indentation.IsConditional() {
			pkg.conditionalIncludes[includedFile] = mkline
			if other := pkg.unconditionalIncludes[includedFile]; other != nil {
				mkline.Warnf("%q is included conditionally here (depending on %s) and unconditionally in %s.",
					cleanpath(includedFile), strings.Join(mkline.ConditionalVars(), ", "), mkline.RefTo(other))
			}
		} else {
			pkg.unconditionalIncludes[includedFile] = mkline
			if other := pkg.conditionalIncludes[includedFile]; other != nil {
				mkline.Warnf("%q is included unconditionally here and conditionally in %s (depending on %s).",
					cleanpath(includedFile), mkline.RefTo(other), strings.Join(other.ConditionalVars(), ", "))
			}
		}

		// TODO: Check whether the conditional variables are the same on both places.
		// Ideally they should match, but there may be some differences in internal
		// variables, which need to be filtered out before comparing them, like it is
		// already done with *_MK variables.
	}
}

func (pkg *Package) loadPlistDirs(plistFilename string) {
	lines := Load(plistFilename, MustSucceed)
	for _, line := range lines.Lines {
		text := line.Text
		pkg.Plist.Files[text] = true // XXX: ignores PLIST conditions for now
		// Keep in sync with PlistChecker.collectFilesAndDirs
		if !contains(text, "$") && !contains(text, "@") {
			for dir := path.Dir(text); dir != "."; dir = path.Dir(dir) {
				pkg.Plist.Dirs[dir] = true
			}
		}
	}
}

type PlistContent struct {
	Dirs  map[string]bool
	Files map[string]bool
}

func NewPlistContent() PlistContent {
	return PlistContent{
		make(map[string]bool),
		make(map[string]bool)}
}
