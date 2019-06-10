package pkglint

import (
	"netbsd.org/pkglint/pkgver"
	"os"
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

	vars Scope
	bl3  map[string]MkLine // buildlink3.mk name => line; contains only buildlink3.mk files that are directly included.

	// Remembers the Makefile fragments that have already been included.
	// The key to the map is the filename relative to the package directory.
	// Typical keys are "../../category/package/buildlink3.mk".
	//
	// TODO: Include files with multiple-inclusion guard only once.
	//
	// TODO: Include files without multiple-inclusion guard as often as needed.
	//
	// TODO: Set an upper limit, to prevent denial of service.
	included Once

	seenMakefileCommon bool // Does the package have any .includes?

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
		assertf(false, "Package directory %q must be two subdirectories below the pkgsrc root %q.",
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
		included:              Once{},
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

	// In reality, this is an absolute pathname. Since this variable is
	// typically used in the form ${.CURDIR}/../../somewhere, this doesn't
	// matter much.
	pkg.vars.Fallback(".CURDIR", ".")

	return &pkg
}

// File returns the (possibly absolute) path to relativeFileName,
// as resolved from the package's directory.
// Variables that are known in the package are resolved, e.g. ${PKGDIR}.
func (pkg *Package) File(relativeFileName string) string {
	return cleanpath(resolveVariableRefs(nil, pkg.dir+"/"+relativeFileName))
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
		pkgversionNorev := replaceAll(pkgversion, `nb\d+$`, "")
		changeNorev := replaceAll(change.Version, `nb\d+$`, "")
		cmp := pkgver.Compare(pkgversionNorev, changeNorev)
		switch {
		case cmp < 0:
			mkline.Warnf("The package is being downgraded from %s (see %s) to %s.",
				change.Version, mkline.Line.RefToLocation(change.Location), pkgversion)
			mkline.Explain(
				"The files in doc/CHANGES-*, in which all version changes are",
				"recorded, have a higher version number than what the package says.",
				"This is unusual, since packages are typically upgraded instead of",
				"downgraded.")

		case cmp > 0 && !isLocallyModified(mkline.Filename):
			mkline.Notef("Package version %q is greater than the latest %q from %s.",
				pkgversion, change.Version, mkline.Line.RefToLocation(change.Location))
			mkline.Explain(
				"Each update to a package should be mentioned in the doc/CHANGES file.",
				"To do this after updating a package, run",
				sprintf("%q,", bmake("cce")),
				"which is the abbreviation for commit-changes-entry.")
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

func (pkg *Package) load() ([]string, MkLines, MkLines) {
	// Load the package Makefile and all included files,
	// to collect all used and defined variables and similar data.
	mklines, allLines := pkg.loadPackageMakefile()
	if mklines == nil {
		return nil, nil, nil
	}

	files := dirglob(pkg.File("."))
	if pkg.Pkgdir != "." {
		files = append(files, dirglob(pkg.File(pkg.Pkgdir))...)
	}
	if G.Opts.CheckExtra {
		files = append(files, dirglob(pkg.File(pkg.Filesdir))...)
	}
	files = append(files, dirglob(pkg.File(pkg.Patchdir))...)
	if pkg.DistinfoFile != pkg.vars.fallback["DISTINFO_FILE"] {
		files = append(files, pkg.File(pkg.DistinfoFile))
	}

	// Determine the used variables and PLIST directories before checking any of the Makefile fragments.
	// TODO: Why is this code necessary? What effect does it have?
	for _, filename := range files {
		basename := path.Base(filename)
		if (hasPrefix(basename, "Makefile.") || hasSuffix(filename, ".mk")) &&
			!matches(filename, `patch-`) &&
			!contains(filename, pkg.Pkgdir+"/") &&
			!contains(filename, pkg.Filesdir+"/") {
			if fragmentMklines := LoadMk(filename, MustSucceed); fragmentMklines != nil {
				fragmentMklines.collectUsedVariables()
			}
		}
		if hasPrefix(basename, "PLIST") {
			pkg.loadPlistDirs(filename)
		}
	}

	return files, mklines, allLines
}

func (pkg *Package) check(filenames []string, mklines, allLines MkLines) {
	haveDistinfo := false
	havePatches := false

	for _, filename := range filenames {
		if containsVarRef(filename) {
			if trace.Tracing {
				trace.Stepf("Skipping file %q because the name contains an unresolved variable.", filename)
			}
			continue
		}

		st, err := os.Lstat(filename)
		switch {
		case err != nil:
			// For missing custom distinfo file, an error message is already generated
			// for the line where DISTINFO_FILE is defined.
			//
			// For all other cases it is next to impossible to reach this branch
			// since all those files come from calls to dirglob.
			break

		case path.Base(filename) == "Makefile":
			G.checkExecutable(filename, st.Mode())
			pkg.checkfilePackageMakefile(filename, mklines, allLines)

		default:
			G.checkDirent(filename, st.Mode())
		}

		if contains(filename, "/patches/patch-") {
			havePatches = true
		} else if hasSuffix(filename, "/distinfo") {
			haveDistinfo = true
		}
		pkg.checkLocallyModified(filename)
	}

	if pkg.Pkgdir == "." {
		if havePatches && !haveDistinfo {
			line := NewLineWhole(pkg.File(pkg.DistinfoFile))
			line.Warnf("A package with patches should have a distinfo file.")
			line.Explain(
				"To generate a distinfo file for the existing patches, run",
				sprintf("%q.", bmake("makepatchsum")))
		}
	}
}

func (pkg *Package) loadPackageMakefile() (MkLines, MkLines) {
	filename := pkg.File("Makefile")
	if trace.Tracing {
		defer trace.Call1(filename)()
	}

	mainLines := NewMkLines(NewLines(filename, nil))
	allLines := NewMkLines(NewLines("", nil))
	if _, result := pkg.readMakefile(filename, mainLines, allLines, ""); !result {
		LoadMk(filename, NotEmpty|LogErrors) // Just for the LogErrors.
		return nil, nil
	}

	// TODO: Is this still necessary? This code is 20 years old and was introduced
	//  when pkglint loaded the package Makefile including all included files into
	//  a single string. Maybe it makes sense to print the file inclusion hierarchy
	//  to quickly see files that cannot be included because of unresolved variables.
	if G.Opts.DumpMakefile {
		G.Logger.out.WriteLine("Whole Makefile (with all included files) follows:")
		for _, line := range allLines.lines.Lines {
			G.Logger.out.WriteLine(line.String())
		}
	}

	// See mk/tools/cmake.mk
	if pkg.vars.Defined("USE_CMAKE") {
		allLines.Tools.def("cmake", "", false, AtRunTime, nil)
		allLines.Tools.def("cpack", "", false, AtRunTime, nil)
	}

	allLines.collectUsedVariables()

	pkg.Pkgdir = pkg.vars.LastValue("PKGDIR")
	pkg.DistinfoFile = pkg.vars.LastValue("DISTINFO_FILE")
	pkg.Filesdir = pkg.vars.LastValue("FILESDIR")
	pkg.Patchdir = pkg.vars.LastValue("PATCHDIR")

	// See lang/php/ext.mk
	if pkg.vars.DefinedSimilar("PHPEXT_MK") {
		if !pkg.vars.DefinedSimilar("USE_PHP_EXT_PATCHES") {
			pkg.Patchdir = "patches"
		}
		if pkg.vars.DefinedSimilar("PECL_VERSION") {
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

	return mainLines, allLines
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
	result = true

	isMainMakefile := len(mainLines.mklines) == 0

	handleIncludeLine := func(mkline MkLine) YesNoUnknown {
		includedFile, incDir, incBase := pkg.findIncludedFile(mkline, filename)

		if includedFile == "" {
			return unknown
		}

		dirname, _ := path.Split(filename)
		dirname = cleanpath(dirname)
		fullIncluded := dirname + "/" + includedFile
		relIncludedFile := relpath(pkg.dir, fullIncluded)

		if !pkg.diveInto(filename, includedFile) {
			return unknown
		}

		if !pkg.included.FirstTime(relIncludedFile) {
			return unknown
		}

		pkg.collectUsedBy(mkline, incDir, incBase, includedFile)

		if trace.Tracing {
			trace.Step1("Including %q.", fullIncluded)
		}
		fullIncluding := ifelseStr(incBase == "Makefile.common" && incDir != "", filename, "")
		innerExists, innerResult := pkg.readMakefile(fullIncluded, mainLines, allLines, fullIncluding)

		if !innerExists {
			if fileMklines.indentation.IsCheckedFile(includedFile) {
				return yes // See https://github.com/rillig/pkglint/issues/1
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
			return no
		}

		return unknown
	}

	lineAction := func(mkline MkLine) bool {
		if isMainMakefile {
			mainLines.mklines = append(mainLines.mklines, mkline)
			mainLines.lines.Lines = append(mainLines.lines.Lines, mkline.Line)
		}
		allLines.mklines = append(allLines.mklines, mkline)
		allLines.lines.Lines = append(allLines.lines.Lines, mkline.Line)

		if mkline.IsInclude() {
			includeResult := handleIncludeLine(mkline)
			if includeResult != unknown {
				return includeResult == yes
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
		builtin := cleanpath(path.Dir(filename) + "/builtin.mk")
		builtinRel := relpath(pkg.dir, builtin)
		if pkg.included.FirstTime(builtinRel) && fileExists(builtin) {
			pkg.readMakefile(builtin, mainLines, allLines, "")
		}
	}

	return
}

func (pkg *Package) diveInto(includingFile string, includedFile string) bool {

	// The variables that appear in these files are largely modeled by
	// pkglint in the file vardefs.go. Therefore parsing these files again
	// doesn't make much sense.
	if hasSuffix(includedFile, "/bsd.pkg.mk") || IsPrefs(includedFile) {
		return false
	}

	// All files that are included from outside of the pkgsrc infrastructure
	// are relevant. This is typically mk/compiler.mk or the various
	// mk/*.buildlink3.mk files.
	if !contains(includingFile, "/mk/") {
		return true
	}

	// The mk/*.buildlink3.mk files often come with a companion file called
	// mk/*.builtin.mk, which also defines variables that are visible from
	// the package.
	//
	// This case is needed for getting the redundancy check right. Without it
	// there will be warnings about redundant assignments to the
	// BUILTIN_CHECK.pthread variable.
	if contains(includingFile, "buildlink3.mk") && contains(includedFile, "builtin.mk") {
		return true
	}

	return false
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

	// TODO: resolveVariableRefs uses G.Pkg implicitly. It should be made explicit.
	// TODO: Try to combine resolveVariableRefs and ResolveVarsInRelativePath.
	includedFile = resolveVariableRefs(nil, mkline.ResolveVarsInRelativePath(mkline.IncludedFile()))
	if containsVarRef(includedFile) {
		if trace.Tracing && !contains(includingFilename, "/mk/") {
			trace.Stepf("%s:%s: Skipping include file %q. This may result in false warnings.",
				mkline.Filename, mkline.Linenos(), includedFile)
		}
		includedFile = ""
	}
	incDir, incBase = path.Split(includedFile)

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

func (pkg *Package) checkfilePackageMakefile(filename string, mklines MkLines, allLines MkLines) {
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

	if (vars.Defined("NO_CHECKSUM") || vars.Defined("META_PACKAGE")) &&
		isEmptyDir(pkg.File(pkg.Patchdir)) {

		distinfoFile := pkg.File(pkg.DistinfoFile)
		if fileExists(distinfoFile) {
			NewLineWhole(distinfoFile).Warnf("This file should not exist since NO_CHECKSUM or META_PACKAGE is set.")
		}
	} else {
		distinfoFile := pkg.File(pkg.DistinfoFile)
		if !containsVarRef(distinfoFile) && !fileExists(distinfoFile) {
			line := NewLineWhole(distinfoFile)
			line.Warnf("A package that downloads files should have a distinfo file.")
			line.Explain(
				sprintf("To generate the distinfo file, run %q.", bmake("makesum")),
				"",
				"To mark the package as not needing a distinfo file, set",
				"NO_CHECKSUM=yes in the package Makefile.")
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
		line := NewLineWhole(filename)
		line.Errorf("Each package must define its LICENSE.")
		// TODO: Explain why the LICENSE is necessary.
		line.Explain(
			"To take a good guess on the license of a package,",
			sprintf("run %q.", bmake("guess-license")))
	}

	scope := NewRedundantScope()
	scope.Check(allLines) // Updates the variables in the scope
	pkg.checkGnuConfigureUseLanguages(scope)
	pkg.checkUseLanguagesCompilerMk(allLines)

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
	allLines.collectDefinedVariables() // To get the tool definitions
	mklines.Tools = allLines.Tools     // TODO: also copy the other collected data
	mklines.Check()
	pkg.CheckVarorder(mklines)
	SaveAutofixChanges(mklines.lines)
}

func (pkg *Package) checkGnuConfigureUseLanguages(s *RedundantScope) {

	gnuConfigure := s.vars["GNU_CONFIGURE"]
	if gnuConfigure == nil || !gnuConfigure.vari.Constant() {
		return
	}

	useLanguages := s.vars["USE_LANGUAGES"]
	if useLanguages == nil || !useLanguages.vari.Constant() {
		return
	}

	var wrongLines []MkLine
	for _, mkline := range useLanguages.vari.WriteLocations() {

		if G.Pkgsrc.IsInfra(mkline.Line.Filename) {
			continue
		}

		if matches(mkline.VarassignComment(), `(?-i)\b(?:c|empty|none)\b`) {
			// Don't emit a warning since the comment probably contains a
			// statement that C is really not needed.
			return
		}

		languages := mkline.Value()
		if matches(languages, `(?:^|[\t ]+)(?:c|c99|objc)(?:[\t ]+|$)`) {
			return
		}

		wrongLines = append(wrongLines, mkline)
	}

	gnuLine := gnuConfigure.vari.WriteLocations()[0]
	for _, useLine := range wrongLines {
		gnuLine.Warnf(
			"GNU_CONFIGURE almost always needs a C compiler, "+
				"but \"c\" is not added to USE_LANGUAGES in %s.",
			gnuLine.RefTo(useLine))
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

	effname := pkgname
	if distname != "" && effname != "" {
		merged, ok := pkg.pkgnameFromDistname(effname, distname)
		if ok {
			effname = merged
		}
	}

	if pkgname != "" && (pkgname == distname || pkgname == "${DISTNAME}") {
		if pkgnameLine.VarassignComment() == "" {
			pkgnameLine.Notef("This assignment is probably redundant " +
				"since PKGNAME is ${DISTNAME} by default.")
			pkgnameLine.Explain(
				"To mark this assignment as necessary, add a comment to the end of this line.")
		}
	}

	if pkgname == "" && distname != "" && !containsVarRef(distname) && !matches(distname, rePkgname) {
		distnameLine.Warnf("As DISTNAME is not a valid package name, please define the PKGNAME explicitly.")
	}

	if pkgname != "" {
		distname = ""
	}

	if effname != "" && !containsVarRef(effname) {
		if m, m1, m2 := match2(effname, rePkgname); m {
			pkg.EffectivePkgname = effname + pkg.nbPart()
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

func (pkg *Package) pkgnameFromDistname(pkgname, distname string) (string, bool) {
	tokens := NewMkParser(nil, pkgname, false).MkTokens()

	// TODO: Make this resolving of variable references available to all other variables as well.

	var result strings.Builder
	for _, token := range tokens {
		if token.Varuse != nil {
			if token.Varuse.varname != "DISTNAME" {
				return "", false
			}

			newDistname := distname
			for _, mod := range token.Varuse.modifiers {
				if mod.IsToLower() {
					newDistname = strings.ToLower(newDistname)
				} else if subst, ok := mod.Subst(newDistname); ok {
					newDistname = subst
				} else {
					return "", false
				}
			}
			result.WriteString(newDistname)
		} else {
			result.WriteString(token.Text)
		}
	}
	return result.String(), true
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
			pkgnameLine.Explain(
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

	// TODO: Extract all this code into a separate VarOrderChecker
	//  since it is equally useful for PKG_OPTIONS in options.mk.

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
	mkline.Explain(
		"In simple package Makefiles, some common variables should be",
		"arranged in a specific order.",
		"",
		"See doc/Makefile-example for an example Makefile.",
		seeGuide("Package components, Makefile", "components.Makefile"))
}

func (pkg *Package) checkFileMakefileExt(filename string) {
	base := path.Base(filename)
	if !hasPrefix(base, "Makefile.") || base == "Makefile.common" {
		return
	}
	ext := strings.TrimPrefix(base, "Makefile.")

	line := NewLineWhole(filename)
	line.Notef("Consider renaming %q to %q.", base, ext+".mk")
	line.Explain(
		"The main definition of a pkgsrc package should be in the Makefile.",
		"Common definitions for a few very closely related packages can be",
		"placed in a Makefile.common, these may cover various topics.",
		"",
		"All other definitions should be grouped by topics and implemented",
		"in separate files named *.mk after their topics. Typical examples",
		"are extension.mk, module.mk, version.mk.",
		"",
		"These topic files should be documented properly so that their",
		sprintf("content can be queried using %q.", makeHelp("help")))
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

	if !isLocallyModified(filename) || !fileExists(filename) {
		return
	}

	if owner != "" {
		line := NewLineWhole(filename)
		line.Warnf("Don't commit changes to this file without asking the OWNER, %s.", owner)
		line.Explain(
			seeGuide("Package components, Makefile", "components.Makefile"))
	}

	if maintainer != "" {
		line := NewLineWhole(filename)
		line.Notef("Please only commit changes that %s would approve.", maintainer)
		line.Explain(
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
		//  Ideally they should match, but there may be some differences in internal
		//  variables, which need to be filtered out before comparing them, like it is
		//  already done with *_MK variables.
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

// checkUseLanguagesCompilerMk checks that after including mk/compiler.mk
// or mk/endian.mk for the first time, there are no more changes to
// USE_LANGUAGES, as these would be ignored by the pkgsrc infrastructure.
func (pkg *Package) checkUseLanguagesCompilerMk(mklines MkLines) {

	var seen Once

	handleVarassign := func(mkline MkLine) {
		if mkline.Varname() != "USE_LANGUAGES" {
			return
		}

		if !seen.Seen("../../mk/compiler.mk") && !seen.Seen("../../mk/endian.mk") {
			return
		}

		if mkline.Basename == "compiler.mk" {
			if relpath(pkg.dir, mkline.Filename) == "../../mk/compiler.mk" {
				return
			}
		}

		mkline.Warnf("Modifying USE_LANGUAGES after including ../../mk/compiler.mk has no effect.")
		mkline.Explain(
			"The file compiler.mk guards itself against multiple inclusion.")
	}

	handleInclude := func(mkline MkLine) {
		dirname, _ := path.Split(mkline.Filename)
		dirname = cleanpath(dirname)
		fullIncluded := dirname + "/" + mkline.IncludedFile()
		relIncludedFile := relpath(pkg.dir, fullIncluded)

		seen.FirstTime(relIncludedFile)
	}

	mklines.ForEach(func(mkline MkLine) {
		switch {
		case mkline.IsVarassign():
			handleVarassign(mkline)

		case mkline.IsInclude():
			handleInclude(mkline)
		}
	})
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
