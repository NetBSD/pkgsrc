package pkglint

import (
	"netbsd.org/pkglint/pkgver"
	"path"
	"strconv"
	"strings"
)

// TODO: What about package names that refer to other variables?
const rePkgname = `^([\w\-.+]+)-(\d[.0-9A-Z_a-z]*)$`

// Package is the pkgsrc package that is currently checked.
//
// Most of the information is loaded first, and after loading the actual checks take place.
// This is necessary because variables in Makefiles may be used before they are defined,
// and such dependencies often span multiple files that are included indirectly.
type Package struct {
	dir                  string       // The directory of the package, for resolving files
	Pkgpath              string       // e.g. "category/pkgdir"
	Pkgdir               string       // PKGDIR from the package Makefile
	Filesdir             string       // FILESDIR from the package Makefile
	Patchdir             string       // PATCHDIR from the package Makefile
	DistinfoFile         string       // DISTINFO_FILE from the package Makefile
	EffectivePkgname     string       // PKGNAME or DISTNAME from the package Makefile, including nb13
	EffectivePkgbase     string       // EffectivePkgname without the version
	EffectivePkgversion  string       // The version part of the effective PKGNAME, excluding nb13
	EffectivePkgnameLine MkLine       // The origin of the three Effective* values
	Plist                PlistContent // Files and directories mentioned in the PLIST files

	vars               Scope
	bl3                map[string]MkLine // buildlink3.mk name => line; contains only buildlink3.mk files that are directly included.
	included           map[string]MkLine // filename => line
	seenMakefileCommon bool              // Does the package have any .includes?

	// Files from .include lines that are nested inside .if.
	// They often depend on OPSYS or on the existence of files in the build environment.
	conditionalIncludes map[string]MkLine
	// Files from .include lines that are not nested.
	// These are cross-checked with buildlink3.mk whether they are unconditional there, too.
	unconditionalIncludes map[string]MkLine

	once                 Once
	IgnoreMissingPatches bool // In distinfo, don't warn about patches that cannot be found.
}

func NewPackage(dir string) *Package {
	pkgpath := G.Pkgsrc.ToRel(dir)
	if strings.Count(pkgpath, "/") != 1 {
		G.Assertf(false, "Package directory %q must be two subdirectories below the pkgsrc root %q.",
			dir, G.Pkgsrc.File("."))
	}

	pkg := Package{
		dir:                   dir,
		Pkgpath:               pkgpath,
		Pkgdir:                ".",
		Filesdir:              "files",              // TODO: Redundant, see the vars.Fallback below.
		Patchdir:              "patches",            // TODO: Redundant, see the vars.Fallback below.
		DistinfoFile:          "${PKGDIR}/distinfo", // TODO: Redundant, see the vars.Fallback below.
		Plist:                 NewPlistContent(),
		vars:                  NewScope(),
		bl3:                   make(map[string]MkLine),
		included:              make(map[string]MkLine),
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
			mkline.Warnf("The package is being downgraded from %s (see %s) to %s.",
				change.Version, mkline.Line.RefToLocation(change.Location), pkgversion)
			G.Explain(
				"The files in doc/CHANGES-*, in which all version changes are",
				"recorded, have a higher version number than what the package says.",
				"This is unusual, since packages are typically upgraded instead of",
				"downgraded.")

			// TODO: Check whether the current version is mentioned in doc/CHANGES.
		}
	}
}

// checkLinesBuildlink3Inclusion checks whether the package Makefile and
// the corresponding buildlink3.mk agree for all included buildlink3.mk
// files whether they are included conditionally or unconditionally.
func (pkg *Package) checkLinesBuildlink3Inclusion(mklines MkLines) {
	if trace.Tracing {
		defer trace.Call0()()
	}

	// Collect all the included buildlink3.mk files from the file.
	includedFiles := make(map[string]MkLine)
	for _, mkline := range mklines.mklines {
		if mkline.IsInclude() {
			includedFile := mkline.IncludedFile()
			if matches(includedFile, `^\.\./\.\./.*/buildlink3\.mk`) {
				includedFiles[includedFile] = mkline
				if pkg.bl3[includedFile] == nil {
					mkline.Warnf("%s is included by this file but not by the package.", includedFile)
				}
			}
		}
	}

	if trace.Tracing {
		for packageBl3 := range pkg.bl3 {
			if includedFiles[packageBl3] == nil {
				trace.Step1("%s is included by the package but not by the buildlink3.mk file.", packageBl3)
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

	// TODO: Is this still necessary? This code is 20 years old and was introduced
	// when pkglint loaded the package Makefile including all included files into
	// a single string. Maybe it makes sense to print the file inclusion hierarchy
	// to quickly see files that cannot be included because of unresolved variables.
	if G.Opts.DumpMakefile {
		G.out.WriteLine("Whole Makefile (with all included files) follows:")
		for _, line := range allLines.lines.Lines {
			G.out.WriteLine(line.String())
		}
	}

	// See mk/tools/cmake.mk
	if pkg.vars.Defined("USE_CMAKE") {
		mainLines.Tools.def("cmake", "", false, AtRunTime)
		mainLines.Tools.def("cpack", "", false, AtRunTime)
	}

	allLines.collectUsedVariables()
	allLines.CheckRedundantAssignments()

	pkg.Pkgdir = pkg.vars.LastValue("PKGDIR")
	pkg.DistinfoFile = pkg.vars.LastValue("DISTINFO_FILE")
	pkg.Filesdir = pkg.vars.LastValue("FILESDIR")
	pkg.Patchdir = pkg.vars.LastValue("PATCHDIR")

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

// TODO: What is allLines used for, is it still necessary? Would it be better as a field in Package?
func (pkg *Package) readMakefile(filename string, mainLines MkLines, allLines MkLines, includingFileForUsedCheck string) (exists bool, result bool) {
	if trace.Tracing {
		defer trace.Call1(filename)()
	}

	fileMklines := LoadMk(filename, NotEmpty) // TODO: Document why omitting LogErrors is correct here.
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

		includedFile, incDir, incBase := pkg.findIncludedFile(mkline, filename)

		if includedFile != "" && pkg.included[includedFile] == nil {
			pkg.included[includedFile] = mkline

			// TODO: "../../../.." also matches but shouldn't.
			if matches(includedFile, `^\.\./[^./][^/]*/[^/]+`) {
				mkline.Warnf("References to other packages should look like \"../../category/package\", not \"../package\".")
				mkline.ExplainRelativeDirs()
			}

			pkg.collectUsedBy(mkline, incDir, incBase, includedFile)

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

	if includingFileForUsedCheck != "" {
		fileMklines.CheckForUsedComment(G.Pkgsrc.ToRel(includingFileForUsedCheck))
	}

	// For every included buildlink3.mk, include the corresponding builtin.mk
	// automatically since the pkgsrc infrastructure does the same.
	if path.Base(filename) == "buildlink3.mk" {
		builtin := path.Join(path.Dir(filename), "builtin.mk")
		if fileExists(builtin) {
			pkg.readMakefile(builtin, mainLines, allLines, "")
		}
	}

	return
}

func (pkg *Package) collectUsedBy(mkline MkLine, incDir string, incBase string, includedFile string) {
	switch {
	case
		mkline.Basename != "Makefile",
		hasPrefix(incDir, "../../mk/"),
		incBase == "buildlink3.mk",
		incBase == "builtin.mk",
		incBase == "options.mk":
		return
	}

	if trace.Tracing {
		trace.Step1("Including %q sets seenMakefileCommon.", includedFile)
	}
	pkg.seenMakefileCommon = true
}

func (pkg *Package) findIncludedFile(mkline MkLine, includingFilename string) (includedFile, incDir, incBase string) {

	if mkline.IsInclude() {
		// TODO: resolveVariableRefs uses G.Pkg implicitly. It should be made explicit.
		// TODO: Try to combine resolveVariableRefs and ResolveVarsInRelativePath.
		includedFile = resolveVariableRefs(mkline.ResolveVarsInRelativePath(mkline.IncludedFile()))
		if containsVarRef(includedFile) {
			if trace.Tracing && !contains(includingFilename, "/mk/") {
				trace.Stepf("%s:%s: Skipping include file %q. This may result in false warnings.",
					mkline.Filename, mkline.Linenos(), includedFile)
			}
			includedFile = ""
		}
		incDir, incBase = path.Split(includedFile)
	}

	if includedFile != "" {
		if mkline.Basename != "buildlink3.mk" {
			if matches(includedFile, `^\.\./\.\./(.*)/buildlink3\.mk$`) {
				pkg.bl3[includedFile] = mkline
				if trace.Tracing {
					trace.Step1("Buildlink3 file in package: %q", includedFile)
				}
			}
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
		// TODO: Move these technical details into the explanation, making space for an understandable warning.
		NewLineWhole(filename).Warnf("Neither PLIST nor PLIST.common exist, and PLIST_SRC is unset.")
	}

	if (vars.Defined("NO_CHECKSUM") ||
		vars.Defined("META_PACKAGE")) && isEmptyDir(pkg.File(pkg.Patchdir)) {

		if distinfoFile := pkg.File(pkg.DistinfoFile); fileExists(distinfoFile) {
			NewLineWhole(distinfoFile).Warnf("This file should not exist if NO_CHECKSUM or META_PACKAGE is set.")
		}
	} else {
		if distinfoFile := pkg.File(pkg.DistinfoFile); !containsVarRef(distinfoFile) && !fileExists(distinfoFile) {
			NewLineWhole(distinfoFile).Warnf(
				"File not found. Please run %q or define NO_CHECKSUM=yes in the package Makefile.", bmake("makesum"))
		}
	}

	// TODO: There are other REPLACE_* variables which are probably also affected by NO_CONFIGURE.
	if noConfigureLine := vars.FirstDefinition("NO_CONFIGURE"); noConfigureLine != nil {
		if replacePerlLine := vars.FirstDefinition("REPLACE_PERL"); replacePerlLine != nil {
			replacePerlLine.Warnf("REPLACE_PERL is ignored when NO_CONFIGURE is set (in %s).",
				replacePerlLine.RefTo(noConfigureLine))
		}
	}

	if !vars.Defined("LICENSE") && !vars.Defined("META_PACKAGE") && pkg.once.FirstTime("LICENSE") {
		NewLineWhole(filename).Errorf("Each package must define its LICENSE.")
		// TODO: Explain why the LICENSE is necessary.
	}

	pkg.checkGnuConfigureUseLanguages()
	pkg.determineEffectivePkgVars()
	pkg.checkPossibleDowngrade()

	if !vars.Defined("COMMENT") {
		NewLineWhole(filename).Warnf("Each package should define a COMMENT.")
	}

	if imake := vars.FirstDefinition("USE_IMAKE"); imake != nil {
		if x11 := vars.FirstDefinition("USE_X11"); x11 != nil {
			if !hasSuffix(x11.Filename, "/mk/x11.buildlink3.mk") {
				imake.Notef("USE_IMAKE makes USE_X11 in %s redundant.", imake.RefTo(x11))
			}
		}
	}

	pkg.checkUpdate()
	mklines.Check()
	pkg.CheckVarorder(mklines)
	SaveAutofixChanges(mklines.lines)
}

func (pkg *Package) checkGnuConfigureUseLanguages() {
	vars := pkg.vars

	if gnuLine := vars.FirstDefinition("GNU_CONFIGURE"); gnuLine != nil {

		// FIXME: Instead of using the first definition here, a better approach
		//  is probably to use all the definitions except those from mk/compiler.mk.
		//  In real pkgsrc, the last definition is typically from mk/compiler.mk
		//  and only contains c++.
		if useLine := vars.FirstDefinition("USE_LANGUAGES"); useLine != nil {

			if matches(useLine.VarassignComment(), `(?-i)\b(?:c|empty|none)\b`) {
				// Don't emit a warning since the comment probably contains a
				// statement that C is really not needed.

			} else if !matches(useLine.Value(), `(?:^|[\t ]+)(?:c|c99|objc)(?:[\t ]+|$)`) {
				gnuLine.Warnf(
					"GNU_CONFIGURE almost always needs a C compiler, "+
						"but \"c\" is not added to USE_LANGUAGES in %s.",
					gnuLine.RefTo(useLine))
			}
		}
	}
}

// nbPart determines the smallest part of the package version number,
// typically "nb13" or an empty string.
//
// It is only used inside pkgsrc to mark changes that are
// independent from the upstream package.
func (pkg *Package) nbPart() string {
	pkgrevision := pkg.vars.LastValue("PKGREVISION")
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
		pkgnameLine.Notef("This assignment is probably redundant since PKGNAME is ${DISTNAME} by default.")
	}

	if pkgname == "" && distname != "" && !containsVarRef(distname) && !matches(distname, rePkgname) {
		distnameLine.Warnf("As DISTNAME is not a valid package name, please define the PKGNAME explicitly.")
	}

	if pkgname != "" && !containsVarRef(pkgname) {
		if m, m1, m2 := match2(pkgname, rePkgname); m {
			pkg.EffectivePkgname = pkgname + pkg.nbPart()
			pkg.EffectivePkgnameLine = pkgnameLine
			pkg.EffectivePkgbase = m1
			pkg.EffectivePkgversion = m2
		}
	}

	if pkg.EffectivePkgnameLine == nil && distname != "" && !containsVarRef(distname) {
		if m, m1, m2 := match2(distname, rePkgname); m {
			pkg.EffectivePkgname = distname + pkg.nbPart()
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

	// TODO: Make this resolving of variable references available to all other variables as well.

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
	if pkg.EffectivePkgbase == "" {
		return
	}

	for _, sugg := range G.Pkgsrc.SuggestedUpdates() {
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
			pkgnameLine.Warnf("This package should be updated to %s%s.",
				sugg.Version, comment)
			G.Explain(
				"The wishlist for package updates in doc/TODO mentions that a newer",
				"version of this package is available.")

		case cmp > 0:
			pkgnameLine.Notef("This package is newer than the update request to %s%s.",
				suggver, comment)

		default:
			pkgnameLine.Notef("The update request to %s from doc/TODO%s has been done.",
				suggver, comment)
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

	if pkg.seenMakefileCommon {
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

	// See doc/Makefile-example.
	// See https://netbsd.org/docs/pkgsrc/pkgsrc.html#components.Makefile.
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
			variable("DEPENDS", many))}

	relevantLines := (func() []MkLine {
		firstRelevant := -1
		lastRelevant := -1

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
						return nil
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
			return nil
		}
		return mklines.mklines[firstRelevant : lastRelevant+1]
	})()

	skip := func() bool {
		interesting := relevantLines

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

	if len(relevantLines) == 0 || skip() {
		return
	}

	var canonical []string
	for _, section := range sections {
		for _, variable := range section.vars {
			found := false
			for _, mkline := range relevantLines {
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

	// TODO: This leads to very long and complicated warnings.
	//  Those parts that are correct should not be mentioned,
	//  except if they are helpful for locating the mistakes.
	mkline := relevantLines[0]
	mkline.Warnf("The canonical order of the variables is %s.", strings.Join(canonical, ", "))
	G.Explain(
		"In simple package Makefiles, some common variables should be",
		"arranged in a specific order.",
		"",
		"See doc/Makefile-example for an example Makefile.",
		seeGuide("Package components, Makefile", "components.Makefile"))
}

// checkLocallyModified checks files that are about to be committed.
// Depending on whether the package has a MAINTAINER or an OWNER,
// the wording differs.
//
// Pkglint assumes that the local username is the same as the NetBSD
// username, which fits most scenarios.
func (pkg *Package) checkLocallyModified(filename string) {
	if trace.Tracing {
		defer trace.Call(filename)()
	}

	owner := pkg.vars.LastValue("OWNER")
	maintainer := pkg.vars.LastValue("MAINTAINER")
	if maintainer == "pkgsrc-users@NetBSD.org" {
		maintainer = ""
	}
	if owner == "" && maintainer == "" {
		return
	}

	username := G.Username
	if trace.Tracing {
		trace.Stepf("user=%q owner=%q maintainer=%q", username, owner, maintainer)
	}

	if username == strings.Split(owner, "@")[0] || username == strings.Split(maintainer, "@")[0] {
		return
	}

	if !isLocallyModified(filename) {
		return
	}

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

func (pkg *Package) checkIncludeConditionally(mkline MkLine, indentation *Indentation) {
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
				mkline.Warnf(
					"%q is included conditionally here (depending on %s) "+
						"and unconditionally in %s.",
					cleanpath(includedFile), strings.Join(mkline.ConditionalVars(), ", "), mkline.RefTo(other))
			}

		} else {
			pkg.unconditionalIncludes[includedFile] = mkline
			if other := pkg.conditionalIncludes[includedFile]; other != nil {
				mkline.Warnf(
					"%q is included unconditionally here "+
						"and conditionally in %s (depending on %s).",
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

func (pkg *Package) AutofixDistinfo(oldSha1, newSha1 string) {
	distinfoFilename := pkg.File(pkg.DistinfoFile)
	if lines := Load(distinfoFilename, NotEmpty|LogErrors); lines != nil {
		for _, line := range lines.Lines {
			fix := line.Autofix()
			fix.Warnf(SilentAutofixFormat)
			fix.Replace(oldSha1, newSha1)
			fix.Apply()
		}
		lines.SaveAutofixChanges()
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
