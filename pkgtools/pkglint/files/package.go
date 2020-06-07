package pkglint

import (
	"netbsd.org/pkglint/pkgver"
	"os"
	"strconv"
	"strings"
)

// TODO: What about package names that refer to other variables?
// TODO: Allow a hyphen in the middle of a version number.
const rePkgname = `^([\w\-.+]+)-([0-9][.0-9A-Z_a-z]*)$`

// Package is the pkgsrc package that is currently checked.
//
// Most of the information is loaded first, and after loading the actual checks take place.
// This is necessary because variables in Makefiles may be used before they are defined,
// and such dependencies often span multiple files that are included indirectly.
type Package struct {
	dir     CurrPath   // The directory of the package, for resolving files
	Pkgpath PkgsrcPath // e.g. "category/pkgdir"

	EffectivePkgname     string  // PKGNAME or DISTNAME from the package Makefile, including nb13, can be empty
	EffectivePkgbase     string  // EffectivePkgname without the version
	EffectivePkgversion  string  // The version part of the effective PKGNAME, excluding nb13
	EffectivePkgnameLine *MkLine // The origin of the three Effective* values
	buildlinkID          string
	optionsID            string

	Pkgdir       PackagePath  // PKGDIR from the package Makefile
	Filesdir     PackagePath  // FILESDIR from the package Makefile
	Patchdir     PackagePath  // PATCHDIR from the package Makefile
	DistinfoFile PackagePath  // DISTINFO_FILE from the package Makefile
	Plist        PlistContent // Files and directories mentioned in the PLIST files
	PlistLines   *PlistLines

	vars      Scope
	redundant *RedundantScope

	// bl3 contains the buildlink3.mk files that are included by the
	// package, including any transitively included files.
	//
	// This is later compared to those buildlink3.mk files that are
	// included by the package's own buildlink3.mk file.
	// These included files should match.
	bl3 map[PackagePath]*MkLine

	// The default dependencies from the buildlink3.mk files.
	bl3Data map[Buildlink3ID]*Buildlink3Data

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

	// Does the package have any .includes?
	//
	// TODO: Be more precise about the purpose of this field.
	seenInclude bool

	// The identifiers for which PKG_BUILD_OPTIONS is defined.
	seenPkgbase Once

	// During both load() and check(), tells whether bsd.prefs.mk has
	// already been loaded directly or indirectly.
	//
	// At the end of load(), it is reset to false.
	seenPrefs bool

	// The first line of the package Makefile at which bsd.prefs.mk is
	// guaranteed to be loaded.
	prefsLine *MkLine

	// Files from .include lines that are nested inside .if.
	// They often depend on OPSYS or on the existence of files in the build environment.
	conditionalIncludes map[PackagePath]*MkLine
	// Files from .include lines that are not nested.
	// These are cross-checked with buildlink3.mk whether they are unconditional there, too.
	unconditionalIncludes map[PackagePath]*MkLine

	IgnoreMissingPatches bool // In distinfo, don't warn about patches that cannot be found.

	Once Once

	// Contains the basenames of the distfiles that are mentioned in distinfo,
	// for example "package-1.0.tar.gz", even if that file is in a DIST_SUBDIR.
	distinfoDistfiles map[RelPath]bool
}

func NewPackage(dir CurrPath) *Package {
	pkgpath := G.Pkgsrc.Rel(dir)

	// Package directory must be two subdirectories below the pkgsrc root.
	// As of November 2019, it is technically possible to create packages
	// on different levels, but that is not used at all. Therefore all
	// relative directories are in the form "../../category/package".
	assert(pkgpath.Count() == 2)

	pkg := Package{
		dir:                   dir,
		Pkgpath:               pkgpath,
		Pkgdir:                ".",
		Filesdir:              "files",              // TODO: Redundant, see the vars.Fallback below.
		Patchdir:              "patches",            // TODO: Redundant, see the vars.Fallback below.
		DistinfoFile:          "${PKGDIR}/distinfo", // TODO: Redundant, see the vars.Fallback below.
		Plist:                 NewPlistContent(),
		PlistLines:            NewPlistLines(),
		vars:                  NewScope(),
		bl3:                   make(map[PackagePath]*MkLine),
		bl3Data:               make(map[Buildlink3ID]*Buildlink3Data),
		included:              Once{},
		conditionalIncludes:   make(map[PackagePath]*MkLine),
		unconditionalIncludes: make(map[PackagePath]*MkLine),
	}
	pkg.vars.DefineAll(G.Pkgsrc.UserDefinedVars)

	pkg.vars.Fallback("PKGDIR", ".")
	pkg.vars.Fallback("DISTINFO_FILE", "${PKGDIR}/distinfo")
	pkg.vars.Fallback("FILESDIR", "files")
	pkg.vars.Fallback("PATCHDIR", "patches")
	pkg.vars.Fallback("KRB5_TYPE", "heimdal")
	pkg.vars.Fallback("PGSQL_VERSION", "95")
	pkg.vars.Fallback("EXTRACT_SUFX", ".tar.gz")

	// In reality, this is an absolute pathname. Since this variable is
	// typically used in the form ${.CURDIR}/../../somewhere, this doesn't
	// matter much.
	pkg.vars.Fallback(".CURDIR", ".")

	return &pkg
}

func (pkg *Package) Check() {
	files, mklines, allLines := pkg.load()
	if files == nil {
		return
	}
	pkg.check(files, mklines, allLines)
}

func (pkg *Package) load() ([]CurrPath, *MkLines, *MkLines) {
	// Load the package Makefile and all included files,
	// to collect all used and defined variables and similar data.
	mklines, allLines := pkg.loadPackageMakefile()
	if mklines == nil {
		return nil, nil, nil
	}

	files := pkg.File(".").ReadPaths()
	if pkg.Pkgdir != "." && pkg.Rel(pkg.File(pkg.Pkgdir)) != "." {
		files = append(files, pkg.File(pkg.Pkgdir).ReadPaths()...)
	}
	files = append(files, pkg.File(pkg.Patchdir).ReadPaths()...)
	if pkg.DistinfoFile != NewPackagePathString(pkg.vars.v("DISTINFO_FILE").fallback) {
		files = append(files, pkg.File(pkg.DistinfoFile))
	}

	isRelevantMk := func(filename CurrPath, basename RelPath) bool {
		if !hasPrefix(basename.String(), "Makefile.") && !filename.HasSuffixText(".mk") {
			return false
		}
		if filename.Dir().HasBase("patches") {
			return false
		}
		if pkg.Pkgdir == "." {
			return true
		}
		return !filename.ContainsPath(pkg.Pkgdir.AsPath())
	}

	// Determine the used variables and PLIST directories before checking any of the Makefile fragments.
	// TODO: Why is this code necessary? What effect does it have?
	pkg.collectConditionalIncludes(mklines)
	for _, filename := range files {
		basename := filename.Base()
		if isRelevantMk(filename, basename) {
			fragmentMklines := LoadMk(filename, pkg, MustSucceed)
			pkg.collectConditionalIncludes(fragmentMklines)
			pkg.loadBuildlink3Pkgbase(filename, fragmentMklines)
		}
		if basename.HasPrefixText("PLIST") {
			pkg.loadPlistDirs(filename)
		}
	}

	pkg.seenPrefs = false
	return files, mklines, allLines
}

func (pkg *Package) loadBuildlink3Pkgbase(filename CurrPath, fragmentMklines *MkLines) {
	if !filename.HasBase("buildlink3.mk") {
		return
	}
	fragmentMklines.ForEach(func(mkline *MkLine) {
		if mkline.IsVarassign() && mkline.Varname() == "pkgbase" {
			pkg.seenPkgbase.FirstTime(mkline.Value())
		}
	})
}

func (pkg *Package) loadPackageMakefile() (*MkLines, *MkLines) {
	filename := pkg.File("Makefile")
	if trace.Tracing {
		defer trace.Call(filename)()
	}

	mainLines := LoadMk(filename, pkg, NotEmpty|LogErrors)
	if mainLines == nil {
		return nil, nil
	}

	G.checkRegCvsSubst(filename)
	allLines := NewMkLines(NewLines("", nil), pkg, &pkg.vars)
	if !pkg.parse(mainLines, allLines, "", true) {
		return nil, nil
	}

	// See mk/bsd.hacks.mk, which is included by mk/bsd.pkg.mk.
	hacks := LoadMk(pkg.File("${PKGDIR}/hacks.mk"), pkg, NotEmpty)
	if hacks != nil {
		_ = pkg.parse(hacks, allLines, "", false)
	}

	// TODO: Is this still necessary? This code is 20 years old and was introduced
	//  when pkglint loaded the package Makefile including all included files into
	//  a single string. Maybe it makes sense to print the file inclusion hierarchy
	//  to quickly see files that cannot be included because of unresolved variables.
	if G.DumpMakefile {
		G.Logger.out.WriteLine("Whole Makefile (with all included files) follows:")
		for _, line := range allLines.lines.Lines {
			G.Logger.out.WriteLine(line.String())
		}
	}

	// See mk/tools/cmake.mk
	if pkg.vars.IsDefined("USE_CMAKE") {
		allLines.Tools.def("cmake", "", false, AtRunTime, nil)
		allLines.Tools.def("cpack", "", false, AtRunTime, nil)
	}

	allLines.collectUsedVariables()

	pkg.Pkgdir = NewPackagePathString(pkg.vars.LastValue("PKGDIR"))
	pkg.DistinfoFile = NewPackagePathString(pkg.vars.LastValue("DISTINFO_FILE"))
	pkg.Filesdir = NewPackagePathString(pkg.vars.LastValue("FILESDIR"))
	pkg.Patchdir = NewPackagePathString(pkg.vars.LastValue("PATCHDIR"))

	// See lang/php/ext.mk
	if pkg.vars.IsDefinedSimilar("PHPEXT_MK") {
		if !pkg.vars.IsDefinedSimilar("USE_PHP_EXT_PATCHES") {
			pkg.Patchdir = "patches"
		}
		if pkg.vars.IsDefinedSimilar("PECL_VERSION") {
			pkg.DistinfoFile = "distinfo"
		} else {
			pkg.IgnoreMissingPatches = true
		}

		// For PHP modules that are not PECL, this combination means that
		// the patches in the distinfo cannot be found in PATCHDIR.
	}

	if trace.Tracing {
		trace.Stepf("DISTINFO_FILE=%s", pkg.DistinfoFile)
		trace.Stepf("FILESDIR=%s", pkg.Filesdir)
		trace.Stepf("PATCHDIR=%s", pkg.Patchdir)
		trace.Stepf("PKGDIR=%s", pkg.Pkgdir)
	}

	return mainLines, allLines
}

func (pkg *Package) parse(mklines *MkLines, allLines *MkLines, includingFileForUsedCheck CurrPath, main bool) bool {
	if trace.Tracing {
		defer trace.Call(mklines.lines.Filename)()
	}

	result := mklines.ForEachEnd(
		func(mkline *MkLine) bool { return pkg.parseLine(mklines, mkline, allLines, main) },
		func(mkline *MkLine) {})

	if includingFileForUsedCheck != "" {
		mklines.CheckUsedBy(G.Pkgsrc.Rel(includingFileForUsedCheck))
	}

	// For every included buildlink3.mk, include the corresponding builtin.mk
	// automatically since the pkgsrc infrastructure does the same.
	filename := mklines.lines.Filename
	if mklines.lines.BaseName == "buildlink3.mk" {
		builtin := filename.Dir().JoinNoClean("builtin.mk").CleanPath()
		builtinRel := G.Pkgsrc.Relpath(pkg.dir, builtin)
		if pkg.included.FirstTime(builtinRel.String()) && builtin.IsFile() {
			builtinMkLines := LoadMk(builtin, pkg, MustSucceed|LogErrors)
			pkg.parse(builtinMkLines, allLines, "", false)
		}

		data := LoadBuildlink3Data(mklines)
		if data != nil {
			pkg.bl3Data[data.id] = data
		}
	}

	return result
}

func (pkg *Package) parseLine(mklines *MkLines, mkline *MkLine, allLines *MkLines, main bool) bool {
	allLines.mklines = append(allLines.mklines, mkline)
	allLines.lines.Lines = append(allLines.lines.Lines, mkline.Line)

	if mkline.IsInclude() {
		includingFile := mkline.Filename()
		includedFile := mkline.IncludedFile()
		includedMkLines, skip := pkg.loadIncluded(mkline, includingFile)

		if includedMkLines == nil {
			pkgsrcPath := G.Pkgsrc.Rel(mkline.File(includedFile))
			if skip || mklines.indentation.HasExists(pkgsrcPath) {
				return true // See https://github.com/rillig/pkglint/issues/1
			}
			mkline.Errorf("Cannot read %q.", includedFile)
			return false
		}

		filenameForUsedCheck := NewCurrPath("")
		dir, base := includedFile.Split()
		if dir != "" && base == "Makefile.common" && dir.String() != "../../"+pkg.Pkgpath.String()+"/" {
			filenameForUsedCheck = includingFile
		}
		if !pkg.parse(includedMkLines, allLines, filenameForUsedCheck, false) {
			return false
		}
		if main && pkg.seenPrefs && pkg.prefsLine == nil {
			pkg.prefsLine = mkline
		}
	}

	if mkline.IsVarassign() {
		varname, op, value := mkline.Varname(), mkline.Op(), mkline.Value()

		if op != opAssignDefault || !pkg.vars.IsDefined(varname) {
			if trace.Tracing {
				trace.Stepf("varassign(%q, %q, %q)", varname, op, value)
			}
			pkg.vars.Define(varname, mkline)
		}

		if varname == "pkgbase" {
			pkg.seenPkgbase.FirstTime(mkline.Value())
		}
	}
	return true
}

// loadIncluded loads the lines from the file given by the .include directive
// in mkline.
//
// The returned lines may be nil in two different cases: if skip is true,
// the included file is not processed further for whatever reason. But if
// skip is false, the file could not be read and an appropriate error message
// has already been logged.
func (pkg *Package) loadIncluded(mkline *MkLine, includingFile CurrPath) (includedMklines *MkLines, skip bool) {
	includedFile := pkg.resolveIncludedFile(mkline, includingFile)

	if includedFile.IsEmpty() {
		return nil, true
	}

	// TODO: .Dir? Add test before changing this.
	// pkglint -Wall x11/kde-runtime4
	dirname, _ := includingFile.Split()
	dirname = dirname.CleanPath()
	fullIncluded := dirname.JoinNoClean(includedFile)
	relIncludedFile := G.Pkgsrc.Relpath(pkg.dir, fullIncluded)

	if !pkg.shouldDiveInto(includingFile, includedFile) {
		return nil, true
	}

	if !pkg.included.FirstTime(relIncludedFile.String()) {
		return nil, true
	}

	pkg.collectSeenInclude(mkline, includedFile)

	if trace.Tracing {
		trace.Stepf("Including %q.", fullIncluded)
	}
	includedMklines = LoadMk(fullIncluded, pkg, 0)
	if includedMklines != nil {
		return includedMklines, false
	}

	// Only look in the directory relative to the current file
	// and in the package directory; see
	// devel/bmake/files/parse.c, function Parse_include_file.
	//
	// Bmake has a list of include directories that can be specified
	// on the command line using the -I option, but pkgsrc doesn't
	// make use of that, so pkglint also doesn't need this extra
	// complexity.
	pkgBasedir := pkg.File(".")

	// Prevent unnecessary syscalls
	if dirname == pkgBasedir {
		return nil, false
	}

	dirname = pkgBasedir

	fullIncludedFallback := dirname.JoinNoClean(includedFile)
	includedMklines = LoadMk(fullIncludedFallback, pkg, 0)
	if includedMklines == nil {
		return nil, false
	}

	mkline.Warnf("The path to the included file should be %q.",
		mkline.Rel(fullIncludedFallback))
	mkline.Explain(
		"The .include directive first searches the file relative to the including file.",
		"And if that doesn't exist, falls back to the current directory, which in the",
		"case of a pkgsrc package is the package directory.",
		"",
		"This fallback mechanism is not necessary for pkgsrc, therefore it should not",
		"be used. One less thing to learn for package developers.")

	return includedMklines, false
}

// resolveIncludedFile resolves Makefile variables such as ${PKGPATH} to
// their actual values.
func (pkg *Package) resolveIncludedFile(mkline *MkLine, includingFilename CurrPath) RelPath {

	// TODO: Try to combine resolveVariableRefs and ResolveVarsInRelativePath.
	// TODO: Not every relative path is relative to the package directory.
	resolved := mkline.ResolveVarsInRelativePath(NewPackagePath(mkline.IncludedFile()), pkg)
	includedText := resolveVariableRefs(resolved.String(), nil, pkg)
	includedFile := NewRelPathString(includedText)
	if containsVarUse(includedText) {
		if trace.Tracing && !includingFilename.ContainsPath("mk") {
			trace.Stepf("%s:%s: Skipping unresolvable include file %q.",
				mkline.Filename(), mkline.Linenos(), includedFile)
		}
		return ""
	}

	if mkline.Basename != "buildlink3.mk" {
		if includedFile.HasSuffixPath("buildlink3.mk") {
			curr := mkline.File(includedFile)
			if !curr.IsFile() {
				curr = pkg.File(PackagePath(includedFile))
			}
			packagePath := pkg.Rel(curr)
			pkg.bl3[packagePath] = mkline
			if trace.Tracing {
				trace.Stepf("Buildlink3 file in package: %q", packagePath)
			}
		}
	}

	return includedFile
}

// shouldDiveInto decides whether to load the includedFile.
//
// The includingFile is relative to the current working directory,
// the includedFile is taken directly from the .include directive.
func (pkg *Package) shouldDiveInto(includingFile CurrPath, includedFile RelPath) bool {

	if includedFile.HasSuffixPath("bsd.pkg.mk") || IsPrefs(includedFile) {
		pkg.seenPrefs = true
		return false
	}

	if G.Pkgsrc.IsInfraMain(includingFile) {
		return includingFile.HasSuffixText(".buildlink3.mk") &&
			includedFile.HasSuffixText(".builtin.mk")
	}

	return true
}

func (pkg *Package) collectSeenInclude(mkline *MkLine, includedFile RelPath) {
	if mkline.Basename != "Makefile" {
		return
	}

	incDir, incBase := includedFile.Split()
	switch {
	case
		incDir.HasPrefixPath("../../mk"),
		incBase == "buildlink3.mk",
		incBase == "builtin.mk",
		incBase == "options.mk":
		return
	}

	if trace.Tracing {
		trace.Stepf("Including %q sets seenInclude.", includedFile)
	}
	pkg.seenInclude = true
}

func (pkg *Package) collectConditionalIncludes(mklines *MkLines) {
	mklines.ForEach(func(mkline *MkLine) {
		if mkline.IsInclude() {
			mkline.SetConditionalVars(mklines.indentation.Varnames())

			includedFile := pkg.Rel(mkline.IncludedFileFull())
			if mklines.indentation.IsConditional() {
				pkg.conditionalIncludes[includedFile] = mkline
			} else {
				pkg.unconditionalIncludes[includedFile] = mkline
			}
		}
	})
}

func (pkg *Package) loadPlistDirs(plistFilename CurrPath) {
	lines := Load(plistFilename, MustSucceed)
	ck := PlistChecker{
		pkg,
		make(map[RelPath]*PlistLine),
		make(map[RelPath]*PlistLine),
		"",
		Once{},
		false}
	plistLines := ck.Load(lines)

	for filename, pline := range ck.allFiles {
		pkg.Plist.Files[filename] = pline
	}
	for dirname, pline := range ck.allDirs {
		pkg.Plist.Dirs[dirname] = pline
	}
	for _, plistLine := range plistLines {
		if plistLine.HasPath() {
			rank := NewPlistRank(plistLine.Basename)
			pkg.PlistLines.Add(plistLine, rank)
		}
		for _, cond := range plistLine.conditions {
			pkg.Plist.Conditions[strings.TrimPrefix(cond, "PLIST.")] = true
		}
	}
}

func (pkg *Package) check(filenames []CurrPath, mklines, allLines *MkLines) {
	haveDistinfo := false
	havePatches := false

	for _, filename := range filenames {
		if containsVarUse(filename.String()) {
			if trace.Tracing {
				trace.Stepf("Skipping file %q because the name contains an unresolved variable.", filename)
			}
			continue
		}

		st, err := filename.Lstat()
		switch {
		case err != nil:
			// For a missing custom distinfo file, an error message is already generated
			// for the line where DISTINFO_FILE is defined.
			//
			// For all other cases it is next to impossible to reach this branch
			// since all those files come from calls to dirglob.
			break

		case filename.HasBase("Makefile") && pkg.Rel(filename) == "Makefile":
			G.checkExecutable(filename, st.Mode())
			pkg.checkfilePackageMakefile(filename, mklines, allLines)

		default:
			pkg.checkDirent(filename, st.Mode())
		}

		if filename.ContainsText("/patches/patch-") {
			havePatches = true
		} else if filename.HasSuffixPath("distinfo") {
			haveDistinfo = true
		}
		pkg.checkOwnerMaintainer(filename)
		pkg.checkFreeze(filename)
	}

	if pkg.Pkgdir == "." {
		if havePatches && !haveDistinfo {
			line := NewLineWhole(pkg.File(pkg.DistinfoFile))
			line.Warnf("A package with patches should have a distinfo file.")
			line.Explain(
				"To generate a distinfo file for the existing patches, run",
				sprintf("%q.", bmake("makepatchsum")))
		}

		pkg.checkDescr(filenames, mklines)
	}

	pkg.checkDistfilesInDistinfo(allLines)
}

func (pkg *Package) checkDescr(filenames []CurrPath, mklines *MkLines) {
	for _, filename := range filenames {
		if filename.HasBase("DESCR") {
			return
		}
	}
	if pkg.vars.IsDefined("DESCR_SRC") {
		return
	}
	mklines.Whole().Errorf("Each package must have a DESCR file.")
}

func (pkg *Package) checkDistfilesInDistinfo(mklines *MkLines) {
	// Needs more work; see MkLines.IsUnreachable.
	if !G.Experimental {
		return
	}

	if len(pkg.distinfoDistfiles) == 0 {
		return
	}

	redundant := pkg.redundant
	distfiles := redundant.get("DISTFILES")
	if len(distfiles.vari.WriteLocations()) == 0 {
		return
	}

	for _, mkline := range distfiles.vari.WriteLocations() {
		unreachable := newLazyBool(
			func() bool { return mklines.IsUnreachable(mkline) })
		resolved := resolveVariableRefs(mkline.Value(), nil, pkg)

		for _, distfile := range mkline.ValueFields(resolved) {
			if containsVarUse(distfile) {
				continue
			}
			if pkg.distinfoDistfiles[NewPath(distfile).Base()] {
				continue
			}
			if unreachable.get() {
				continue
			}
			mkline.Warnf("Distfile %q is not mentioned in %s.",
				distfile, mkline.Rel(pkg.File(pkg.DistinfoFile)))
		}
	}
}

func (pkg *Package) checkfilePackageMakefile(filename CurrPath, mklines *MkLines, allLines *MkLines) {
	if trace.Tracing {
		defer trace.Call(filename)()
	}

	pkg.checkPlist()

	pkg.checkDistinfoExists()

	// TODO: There are other REPLACE_* variables which are probably also affected by NO_CONFIGURE.
	vars := pkg.vars
	if noConfigureLine := vars.FirstDefinition("NO_CONFIGURE"); noConfigureLine != nil {
		if replacePerlLine := vars.FirstDefinition("REPLACE_PERL"); replacePerlLine != nil {
			replacePerlLine.Warnf("REPLACE_PERL is ignored when NO_CONFIGURE is set (in %s).",
				replacePerlLine.RelMkLine(noConfigureLine))
		}
	}

	if !vars.IsDefined("LICENSE") && !vars.IsDefined("META_PACKAGE") {
		line := NewLineWhole(filename)
		line.Errorf("Each package must define its LICENSE.")
		// TODO: Explain why the LICENSE is necessary.
		line.Explain(
			"To take a good guess on the license of a package,",
			sprintf("run %q.", bmake("guess-license")))
	}

	pkg.redundant = NewRedundantScope()
	pkg.redundant.IsRelevant = func(mkline *MkLine) bool {
		// As of December 2019, the RedundantScope is only used for
		// checking a whole package. Therefore, G.Infrastructure can
		// never be true and there is no point testing it.
		//
		// If the RedundantScope is applied also to individual files,
		// it would have to be added here.
		return G.CheckGlobal || !G.Pkgsrc.IsInfra(mkline.Filename())
	}
	pkg.redundant.Check(allLines) // Updates the variables in the scope
	pkg.checkGnuConfigureUseLanguages()
	pkg.checkUseLanguagesCompilerMk(allLines)

	pkg.determineEffectivePkgVars()
	pkg.checkPossibleDowngrade()

	if !vars.IsDefined("COMMENT") {
		NewLineWhole(filename).Warnf("Each package should define a COMMENT.")
	}

	if imake := vars.FirstDefinition("USE_IMAKE"); imake != nil {
		if x11 := vars.FirstDefinition("USE_X11"); x11 != nil {
			if !x11.Filename().HasSuffixPath("mk/x11.buildlink3.mk") {
				imake.Notef("USE_IMAKE makes USE_X11 in %s redundant.", imake.RelMkLine(x11))
			}
		}
	}

	pkg.checkUpdate()

	// TODO: Maybe later collect the conditional includes from allLines
	//  instead of mklines. This will lead to about 6000 new warnings
	//  though.
	// pkg.collectConditionalIncludes(allLines)

	allLines.collectVariables()    // To get the tool definitions
	mklines.Tools = allLines.Tools // TODO: also copy the other collected data

	// TODO: Checking only mklines instead of allLines ignores the
	//  .include lines. For example, including "options.mk" does not
	//  set Tools.SeenPrefs, but it should.
	//
	// See Test_Package_checkfilePackageMakefile__options_mk.
	mklines.checkAllData.postLine = func(mkline *MkLine) {
		if mkline == pkg.prefsLine {
			pkg.seenPrefs = true
		}
	}
	mklines.Check()

	// This check is experimental because it's not yet clear how to
	// classify the various Python packages and whether all Python
	// packages really need the prefix.
	if G.Experimental && pkg.EffectivePkgname != "" && pkg.Includes("../../lang/python/extension.mk") != nil {
		pkg.EffectivePkgnameLine.Warnf("The PKGNAME of Python extensions should start with ${PYPKGPREFIX}.")
	}

	pkg.CheckVarorder(mklines)

	SaveAutofixChanges(mklines.lines)
}

func (pkg *Package) checkDistinfoExists() {
	vars := pkg.vars

	want := pkg.wantDistinfo(vars)

	if !want {
		distinfoFile := pkg.File(pkg.DistinfoFile)
		if distinfoFile.IsFile() {
			NewLineWhole(distinfoFile).Warnf("This file should not exist.")
		}
	} else {
		distinfoFile := pkg.File(pkg.DistinfoFile)
		if !containsVarUse(distinfoFile.String()) && !distinfoFile.IsFile() {
			line := NewLineWhole(distinfoFile)
			line.Warnf("A package that downloads files should have a distinfo file.")
			line.Explain(
				sprintf("To generate the distinfo file, run %q.", bmake("makesum")),
				"",
				"To mark the package as not needing a distinfo file, set",
				"NO_CHECKSUM=yes in the package Makefile.")
		}
	}
}

func (pkg *Package) wantDistinfo(vars Scope) bool {
	switch {
	case vars.IsDefined("DISTINFO_FILE"):
		return true
	case vars.IsDefined("DISTFILES") && vars.LastValue("DISTFILES") != "":
		return true
	case vars.IsDefined("DISTFILES"):
		break
	case vars.IsDefined("NO_CHECKSUM"):
		break
	case vars.IsDefined("META_PACKAGE"):
		break // see Test_Package_checkfilePackageMakefile__META_PACKAGE_with_patch
	case !vars.IsDefined("DISTNAME"):
		break
	default:
		return true
	}

	return !isEmptyDir(pkg.File(pkg.Patchdir))
}

// checkPlist checks whether the package needs a PLIST file,
// or whether that file should be omitted since it is autogenerated.
func (pkg *Package) checkPlist() {
	vars := pkg.vars
	if vars.IsDefined("PLIST_SRC") || vars.IsDefined("GENERATE_PLIST") {
		return
	}

	needsPlist, line := pkg.needsPlist()
	hasPlist := pkg.File(pkg.Pkgdir.JoinNoClean("PLIST")).IsFile() ||
		pkg.File(pkg.Pkgdir.JoinNoClean("PLIST.common")).IsFile()

	if needsPlist && !hasPlist {
		line.Warnf("This package should have a PLIST file.")
		line.Explain(
			"The PLIST file provides the list of files that will be",
			"installed by the package. Having this list ensures that",
			"a package update doesn't accidentally modify the list",
			"of installed files.",
			"",
			seeGuide("PLIST issues", "plist"))
	}

	if hasPlist && !needsPlist {
		line.Warnf("This package should not have a PLIST file.")
	}
}

func (pkg *Package) needsPlist() (bool, *Line) {
	vars := pkg.vars

	// TODO: In the below code, it shouldn't be necessary to mention
	//  each variable name twice.

	if vars.IsDefined("PERL5_PACKLIST") {
		return false, vars.LastDefinition("PERL5_PACKLIST").Line
	}

	if vars.IsDefined("PERL5_USE_PACKLIST") {
		needed := strings.ToLower(vars.LastValue("PERL5_USE_PACKLIST")) == "no"
		return needed, vars.LastDefinition("PERL5_USE_PACKLIST").Line
	}

	if vars.IsDefined("META_PACKAGE") {
		return false, vars.LastDefinition("META_PACKAGE").Line
	}

	return true, NewLineWhole(pkg.File("Makefile"))
}

// CheckVarorder checks that in simple package Makefiles,
// the most common variables appear in a fixed order.
// The order itself is a little arbitrary but provides
// at least a bit of consistency.
func (pkg *Package) CheckVarorder(mklines *MkLines) {
	if trace.Tracing {
		defer trace.Call0()()
	}

	if pkg.seenInclude {
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
		Name       string
		Repetition Repetition
	}

	emptyLine := Variable{"", once}

	// See doc/Makefile-example.
	// See https://netbsd.org/docs/pkgsrc/pkgsrc.html#components.Makefile.
	var variables = []Variable{
		{"GITHUB_PROJECT", optional}, // either here or below MASTER_SITES
		{"GITHUB_TAG", optional},
		{"GITHUB_RELEASE", optional},
		{"DISTNAME", optional},
		{"PKGNAME", optional},
		{"R_PKGNAME", optional},
		{"R_PKGVER", optional},
		{"PKGREVISION", optional},
		{"CATEGORIES", once},
		{"MASTER_SITES", many},
		{"GITHUB_PROJECT", optional}, // either here or at the very top
		{"GITHUB_TAG", optional},
		{"GITHUB_RELEASE", optional},
		{"DIST_SUBDIR", optional},
		{"EXTRACT_SUFX", optional},
		{"DISTFILES", many},
		{"SITES.*", many},
		emptyLine,
		{"PATCH_SITES", optional}, // or once?
		{"PATCH_SITE_SUBDIR", optional},
		{"PATCHFILES", optional}, // or once?
		{"PATCH_DIST_ARGS", optional},
		{"PATCH_DIST_STRIP", optional},
		{"PATCH_DIST_CAT", optional},
		emptyLine,
		{"MAINTAINER", optional},
		{"OWNER", optional},
		{"HOMEPAGE", optional},
		{"COMMENT", once},
		{"LICENSE", once},
		emptyLine,
		{"LICENSE_FILE", optional},
		{"RESTRICTED", optional},
		{"NO_BIN_ON_CDROM", optional},
		{"NO_BIN_ON_FTP", optional},
		{"NO_SRC_ON_CDROM", optional},
		{"NO_SRC_ON_FTP", optional},
		emptyLine,
		{"BROKEN_EXCEPT_ON_PLATFORM", many},
		{"BROKEN_ON_PLATFORM", many},
		{"NOT_FOR_PLATFORM", many},
		{"ONLY_FOR_PLATFORM", many},
		{"NOT_FOR_COMPILER", many},
		{"ONLY_FOR_COMPILER", many},
		{"NOT_FOR_UNPRIVILEGED", optional},
		emptyLine,
		{"BUILD_DEPENDS", many},
		{"TOOL_DEPENDS", many},
		{"DEPENDS", many}}

	relevantLines := func() []*MkLine {
		firstRelevant := -1
		lastRelevant := -1

		relevantVars := make(map[string]bool)
		for _, variable := range variables {
			if variable != emptyLine {
				relevantVars[variable.Name] = true
			}
		}

		firstIrrelevant := -1
		for i, mkline := range mklines.mklines {
			switch {
			case mkline.IsVarassignMaybeCommented():
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
	}()

	// If there are foreign variables, skip the whole check.
	// The check is only intended for the most simple packages.
	skip := func() bool {
		interesting := relevantLines

		varcanon := func() string {
			for len(interesting) > 0 && interesting[0].IsComment() {
				interesting = interesting[1:]
			}

			if len(interesting) > 0 && interesting[0].IsVarassign() {
				return interesting[0].Varcanon()
			}
			return ""
		}

		for _, variable := range variables {
			if variable == emptyLine {
				for len(interesting) > 0 && (interesting[0].IsEmpty() || interesting[0].IsComment()) {
					interesting = interesting[1:]
				}
				continue
			}

			switch variable.Repetition {
			case optional:
				if varcanon() == variable.Name {
					interesting = interesting[1:]
				}
			case once:
				if varcanon() == variable.Name {
					interesting = interesting[1:]
				} else if variable.Name != "LICENSE" {
					if trace.Tracing {
						trace.Stepf("Wrong varorder because %s is missing.", variable.Name)
					}
					return false
				}
			default:
				for varcanon() == variable.Name {
					interesting = interesting[1:]
				}
			}
		}

		return len(interesting) == 0
	}

	// canonical returns the canonical ordering of the variables. It mentions all the
	// variables that occur in the relevant section, as well as the "once" variables.
	canonical := func() string {
		var canonical []string
		for _, variable := range variables {
			if variable == emptyLine {
				if canonical[len(canonical)-1] != "empty line" {
					canonical = append(canonical, "empty line")
				}
				continue
			}

			found := false
			for _, mkline := range relevantLines {
				if mkline.IsVarassignMaybeCommented() &&
					mkline.Varcanon() == variable.Name {

					canonical = append(canonical, mkline.Varname())
					found = true
					break
				}
			}

			if !found && variable.Repetition == once {
				canonical = append(canonical, variable.Name)
			}
		}

		if canonical[len(canonical)-1] == "empty line" {
			canonical = canonical[:len(canonical)-1]
		}
		return strings.Join(canonical, ", ")
	}

	if len(relevantLines) == 0 || skip() {
		return
	}

	// TODO: This leads to very long and complicated warnings.
	//  Those parts that are correct should not be mentioned,
	//  except if they are helpful for locating the mistakes.
	mkline := relevantLines[0]
	mkline.Warnf("The canonical order of the variables is %s.", canonical())
	mkline.Explain(
		"In simple package Makefiles, some common variables should be",
		"arranged in a specific order.",
		"",
		"See doc/Makefile-example for an example Makefile.",
		seeGuide("Package components, Makefile", "components.Makefile"))
}

func (pkg *Package) checkGnuConfigureUseLanguages() {
	s := pkg.redundant

	gnuConfigure := s.vars["GNU_CONFIGURE"]
	if gnuConfigure == nil || !gnuConfigure.vari.IsConstant() {
		return
	}

	useLanguages := s.vars["USE_LANGUAGES"]
	if useLanguages == nil || !useLanguages.vari.IsConstant() {
		return
	}

	var wrongLines []*MkLine
	for _, mkline := range useLanguages.vari.WriteLocations() {

		if G.Pkgsrc.IsInfra(mkline.Filename()) {
			continue
		}

		if matches(mkline.Comment(), `(?-i)\b(?:c|empty|none)\b`) {
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
			gnuLine.RelMkLine(useLine))
	}
}

// checkUseLanguagesCompilerMk checks that after including mk/compiler.mk
// or mk/endian.mk for the first time, there are no more changes to
// USE_LANGUAGES, as these would be ignored by the pkgsrc infrastructure.
func (pkg *Package) checkUseLanguagesCompilerMk(mklines *MkLines) {

	var seen Once

	handleVarassign := func(mkline *MkLine) {
		if mkline.Varname() != "USE_LANGUAGES" {
			return
		}

		if !seen.Seen("../../mk/compiler.mk") && !seen.Seen("../../mk/endian.mk") {
			return
		}

		if mkline.Basename == "compiler.mk" {
			if G.Pkgsrc.Relpath(pkg.dir, mkline.Filename()) == "../../mk/compiler.mk" {
				return
			}
		}

		mkline.Warnf("Modifying USE_LANGUAGES after including ../../mk/compiler.mk has no effect.")
		mkline.Explain(
			"The file compiler.mk guards itself against multiple inclusion.")
	}

	handleInclude := func(mkline *MkLine) {
		_ = seen.FirstTime(pkg.Rel(mkline.IncludedFileFull()).String())
	}

	mklines.ForEach(func(mkline *MkLine) {
		switch {
		case mkline.IsVarassign():
			handleVarassign(mkline)

		case mkline.IsInclude():
			handleInclude(mkline)
		}
	})
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
		merged, ok := pkg.pkgnameFromDistname(effname, distname, pkgnameLine)
		if ok {
			effname = merged
		}
	}

	if pkgnameLine != nil && (pkgname == distname || pkgname == "${DISTNAME}") {
		if !pkgnameLine.HasComment() {
			pkgnameLine.Notef("This assignment is probably redundant " +
				"since PKGNAME is ${DISTNAME} by default.")
			pkgnameLine.Explain(
				"To mark this assignment as necessary, add a comment to the end of this line.")
		}
	}

	if pkgname == "" && distnameLine != nil && !containsVarUse(distname) && !matches(distname, rePkgname) {
		distnameLine.Warnf("As DISTNAME is not a valid package name, please define the PKGNAME explicitly.")
	}

	if pkgname != "" {
		distname = ""
	}

	if effname != "" && !containsVarUse(effname) {
		if m, m1, m2 := match2(effname, rePkgname); m {
			pkg.EffectivePkgname = effname + pkg.nbPart()
			pkg.EffectivePkgnameLine = pkgnameLine
			pkg.EffectivePkgbase = m1
			pkg.EffectivePkgversion = m2
		}
	}

	if pkg.EffectivePkgnameLine == nil && distname != "" && !containsVarUse(distname) {
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

func (pkg *Package) pkgnameFromDistname(pkgname, distname string, diag Diagnoser) (string, bool) {
	tokens, rest := NewMkLexer(pkgname, nil).MkTokens()
	if rest != "" {
		return "", false
	}

	// TODO: Make this resolving of variable references available to all other variables as well.

	result := NewLazyStringBuilder(pkgname)
	for _, token := range tokens {
		if token.Varuse != nil {
			if token.Varuse.varname != "DISTNAME" {
				return "", false
			}

			newDistname := distname
			for _, mod := range token.Varuse.modifiers {
				if mod.IsToLower() {
					newDistname = strings.ToLower(newDistname)
				} else if ok, subst := mod.Subst(newDistname); ok {
					if subst == newDistname && !containsVarUse(subst) {
						diag.Notef("The modifier :%s does not have an effect.", mod.Text)
					}
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
			trace.Stepf("No change log for package %q", pkg.Pkgpath)
		}
		return
	}

	if change.Action == Updated {
		pkgversionNorev := replaceAll(pkgversion, `nb\d+$`, "")
		changeNorev := replaceAll(change.Version(), `nb\d+$`, "")
		cmp := pkgver.Compare(pkgversionNorev, changeNorev)
		switch {
		case cmp < 0:
			mkline.Warnf("The package is being downgraded from %s (see %s) to %s.",
				change.Version(), mkline.Line.RelLocation(change.Location), pkgversion)
			mkline.Explain(
				"The files in doc/CHANGES-*, in which all version changes are",
				"recorded, have a higher version number than what the package says.",
				"This is unusual, since packages are typically upgraded instead of",
				"downgraded.")

		case cmp > 0 && !isLocallyModified(mkline.Filename()):
			mkline.Notef("Package version %q is greater than the latest %q from %s.",
				pkgversion, change.Version(), mkline.Line.RelLocation(change.Location))
			mkline.Explain(
				"Each update to a package should be mentioned in the doc/CHANGES file.",
				"That file is used for the quarterly statistics of updated packages.",
				"",
				"To do this after updating a package, run",
				sprintf("%q,", bmake("cce")),
				"which is the abbreviation for commit-changes-entry.")
		}
	}
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

		commentSuffix := func() string {
			if comment != "" {
				return " (" + comment + ")"
			}
			return ""
		}

		mkline := pkg.EffectivePkgnameLine
		cmp := pkgver.Compare(pkg.EffectivePkgversion, suggver)
		ref := mkline.RelLocation(sugg.Line)
		switch {

		case cmp < 0:
			if comment != "" {
				mkline.Warnf("This package should be updated to %s (%s; see %s).",
					sugg.Version, comment, ref)
			} else {
				mkline.Warnf("This package should be updated to %s (see %s).",
					sugg.Version, ref)
			}

		case cmp > 0:
			mkline.Notef("This package is newer than the update request to %s%s from %s.",
				suggver, commentSuffix(), ref)

		default:
			mkline.Notef("The update request to %s%s from %s has been done.",
				suggver, commentSuffix(), ref)
		}
	}
}

// checkDirent checks a directory entry based on its filename and its mode
// (regular file, directory, symlink).
func (pkg *Package) checkDirent(dirent CurrPath, mode os.FileMode) {
	// TODO: merge duplicate code in Pkglint.checkMode

	basename := dirent.Base()

	switch {

	case mode.IsRegular():
		G.checkReg(dirent, basename, G.Pkgsrc.Rel(dirent).Count(), pkg)

	case basename.HasPrefixText("work"):
		if G.Import {
			NewLineWhole(dirent).Errorf("Must be cleaned up before committing the package.")
		}
		return

	case mode.IsDir():
		switch {
		case basename == "files",
			basename == "patches",
			dirent.Dir().HasBase("files"),
			isEmptyDir(dirent):
			break

		default:
			NewLineWhole(dirent).Warnf("Unknown directory name.")
		}

	case mode&os.ModeSymlink != 0:
		NewLineWhole(dirent).Warnf("Invalid symlink name.")

	default:
		NewLineWhole(dirent).Errorf("Only files and directories are allowed in pkgsrc.")
	}
}

// checkOwnerMaintainer checks files that are about to be committed.
// Depending on whether the package has a MAINTAINER or an OWNER,
// the wording differs.
//
// Pkglint assumes that the local username is the same as the NetBSD
// username, which fits most scenarios.
func (pkg *Package) checkOwnerMaintainer(filename CurrPath) {
	if trace.Tracing {
		defer trace.Call(filename)()
	}

	owner := pkg.vars.LastValue("OWNER")
	maintainer := pkg.vars.LastValue("MAINTAINER")
	if maintainer == "pkgsrc-users@NetBSD.org" || maintainer == "INSERT_YOUR_MAIL_ADDRESS_HERE" {
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
		line := NewLineWhole(filename)
		line.Warnf("Don't commit changes to this file without asking the OWNER, %s.", owner)
		line.Explain(
			seeGuide("Package components, Makefile", "components.Makefile"))
		return
	}

	line := NewLineWhole(filename)
	line.Notef("Please only commit changes that %s would approve.", maintainer)
	line.Explain(
		"See the pkgsrc guide, section \"Package components\",",
		"keyword \"maintainer\", for more information.")
}

func (pkg *Package) checkFreeze(filename CurrPath) {
	freezeStart := G.Pkgsrc.LastFreezeStart
	if freezeStart == "" || G.Pkgsrc.LastFreezeEnd != "" {
		return
	}

	if !isLocallyModified(filename) {
		return
	}

	line := NewLineWhole(filename)
	line.Notef("Pkgsrc is frozen since %s.", freezeStart)
	line.Explain(
		"During a pkgsrc freeze, changes to pkgsrc should only be made very carefully.",
		"See https://www.NetBSD.org/developers/pkgsrc/ for the exact rules.")
}

// TODO: Move to MkLinesChecker.
func (*Package) checkFileMakefileExt(filename CurrPath) {
	base := filename.Base()
	if !base.HasPrefixText("Makefile.") || base == "Makefile.common" {
		return
	}
	ext := strings.TrimPrefix(base.String(), "Makefile.")

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
		sprintf("content can be queried using %q.", bmakeHelp("help")))
}

// checkLinesBuildlink3Inclusion checks whether the package Makefile includes
// at least those buildlink3.mk files that are included by the buildlink3.mk
// file of the package.
//
// The other direction is not checked since it is perfectly fine for a package
// to have more dependencies than are needed for buildlink the package.
// (This might be worth re-checking though.)
func (pkg *Package) checkLinesBuildlink3Inclusion(mklines *MkLines) {
	if trace.Tracing {
		defer trace.Call0()()
	}

	// Collect all the included buildlink3.mk files from the file.
	includedFiles := make(map[PackagePath]*MkLine)
	for _, mkline := range mklines.mklines {
		if mkline.IsInclude() {
			included := pkg.Rel(mkline.IncludedFileFull())
			if included.AsPath().HasSuffixPath("buildlink3.mk") {
				includedFiles[included] = mkline
				if pkg.bl3[included] == nil {
					mkline.Warnf("%s is included by this file but not by the package.",
						mkline.IncludedFile())
				}
			}
		}
	}

	if trace.Tracing {
		for packageBl3 := range pkg.bl3 {
			if includedFiles[packageBl3] == nil {
				trace.Stepf("%s is included by the package but not by the buildlink3.mk file.", packageBl3)
			}
		}
	}
}

func (pkg *Package) checkIncludeConditionally(mkline *MkLine, indentation *Indentation) {
	if IsPrefs(mkline.IncludedFile()) {
		return
	}

	key := pkg.Rel(mkline.IncludedFileFull())

	explainPkgOptions := func(uncond *MkLine, cond *MkLine) {
		if uncond.Basename == "buildlink3.mk" && containsStr(cond.ConditionalVars(), "PKG_OPTIONS") {
			mkline.Explain(
				"When including a dependent file, the conditions in the",
				"buildlink3.mk file should be the same as in options.mk",
				"or the Makefile.",
				"",
				"To find out the PKG_OPTIONS of this package at build time,",
				"have a look at mk/pkg-build-options.mk.")
		}
	}

	dependingOn := func(varnames []string) string {
		if len(varnames) == 0 {
			return ""
		}
		return sprintf(" (depending on %s)", strings.Join(varnames, ", "))
	}

	if indentation.IsConditional() {
		if other := pkg.unconditionalIncludes[key]; other != nil {
			if !pkg.Once.FirstTimeSlice("checkIncludeConditionally", mkline.String(), other.String()) {
				return
			}

			mkline.Warnf(
				"%q is included conditionally here%s "+
					"and unconditionally in %s.",
				mkline.IncludedFile().CleanPath(),
				dependingOn(mkline.ConditionalVars()),
				mkline.RelMkLine(other))

			explainPkgOptions(other, mkline)
		}

	} else {
		if other := pkg.conditionalIncludes[key]; other != nil {
			if !pkg.Once.FirstTimeSlice("checkIncludeConditionally", other.String(), mkline.String()) {
				return
			}

			mkline.Warnf(
				"%q is included unconditionally here "+
					"and conditionally in %s%s.",
				mkline.IncludedFile().CleanPath(),
				mkline.RelMkLine(other),
				dependingOn(other.ConditionalVars()))

			explainPkgOptions(mkline, other)
		}
	}

	// TODO: Check whether the conditional variables are the same on both places.
	//  Ideally they should match, but there may be some differences in internal
	//  variables, which need to be filtered out before comparing them, like it is
	//  already done with *_MK variables.
}

func (pkg *Package) matchesLicenseFile(basename RelPath) bool {
	licenseFile := NewPath(pkg.vars.LastValue("LICENSE_FILE"))
	return basename == licenseFile.Base()
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

// File returns the (possibly absolute) path to relativeFileName,
// as resolved from the package's directory.
// Variables that are known in the package are resolved, e.g. ${PKGDIR}.
func (pkg *Package) File(relativeFileName PackagePath) CurrPath {
	joined := pkg.dir.JoinNoClean(NewRelPath(relativeFileName.AsPath()))
	resolved := resolveVariableRefs(joined.String(), nil, pkg)
	return NewCurrPathString(resolved).CleanPath()
}

// Rel returns the path by which the given filename (as seen from the
// current working directory) can be reached as a relative path from
// the package directory.
//
// Example:
//  NewPackage("category/package").Rel("other/package") == "../../other/package"
func (pkg *Package) Rel(filename CurrPath) PackagePath {
	return NewPackagePath(G.Pkgsrc.Relpath(pkg.dir, filename))
}

// Returns whether the given file (relative to the package directory)
// is included somewhere in the package, either directly or indirectly.
func (pkg *Package) Includes(filename PackagePath) *MkLine {
	mkline := pkg.unconditionalIncludes[filename]
	if mkline == nil {
		mkline = pkg.conditionalIncludes[filename]
	}
	return mkline
}

// PlistContent lists the directories and files that appear in the
// package's PLIST files. It serves two purposes:
//
// 1. Decide whether AUTO_MKDIRS can be used instead of listing
// the INSTALLATION_DIRS redundantly.
//
// 2. Ensure that the entries mentioned in the ALTERNATIVES file
// also appear in the PLIST files.
type PlistContent struct {
	Dirs       map[RelPath]*PlistLine
	Files      map[RelPath]*PlistLine
	Conditions map[string]bool // each ${PLIST.id} sets ["id"] = true.
}

func NewPlistContent() PlistContent {
	return PlistContent{
		make(map[RelPath]*PlistLine),
		make(map[RelPath]*PlistLine),
		make(map[string]bool)}
}
