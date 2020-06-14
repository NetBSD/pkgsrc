package pkglint

import (
	"bytes"
	"fmt"
	"io"
	"io/ioutil"
	"netbsd.org/pkglint/intqa"
	"netbsd.org/pkglint/regex"
	"os"
	"regexp"
	"strconv"
	"strings"
	"testing"

	"gopkg.in/check.v1"
)

const CvsID = "$" + "NetBSD$"
const MkCvsID = "# $" + "NetBSD$"
const PlistCvsID = "@comment $" + "NetBSD$"

type Suite struct {
	Tester *Tester
}

// Init creates and returns a test helper that allows to:
//
// * create files for the test:
// CreateFileLines, SetUpPkgsrc, SetUpPackage
//
// * load these files into Line and MkLine objects (for tests spanning multiple files):
// SetUpFileLines, SetUpFileMkLines
//
// * create new in-memory Line and MkLine objects (for simple tests):
// NewLine, NewLines, NewMkLine, NewMkLines
//
// * check the files that have been changed by the --autofix feature:
// CheckFileLines
//
// * check the pkglint diagnostics: CheckOutputEmpty, CheckOutputLines
func (s *Suite) Init(c *check.C) *Tester {

	// Note: the check.C object from SetUpTest cannot be used here,
	// and the parameter given here cannot be used in TearDownTest;
	// see https://github.com/go-check/check/issues/22.

	t := s.Tester // Has been initialized by SetUpTest
	if t.c != nil {
		panic("Suite.Init must only be called once.")
	}
	t.c = c
	return t
}

func (s *Suite) SetUpTest(c *check.C) {
	t := Tester{c: c, testName: c.TestName()}
	s.Tester = &t

	G = NewPkglint(&t.stdout, &t.stderr)
	G.Testing = true
	trace.Out = &t.stdout

	G.Pkgsrc = NewPkgsrc(t.File("."))

	t.c = c
	t.SetUpCommandLine("-Wall")    // To catch duplicate warnings
	G.Todo.Pop()                   // The "." was inserted by default.
	t.seenSetUpCommandLine = false // This default call doesn't count.

	// To improve code coverage and ensure that trace.Result works
	// in all cases. The latter cannot be ensured at compile time.
	t.EnableSilentTracing()

	prevdir, err := os.Getwd()
	assertNil(err, "Cannot get current working directory: %s", err)
	t.prevdir = NewCurrPathString(prevdir)

	// No longer usable; see https://github.com/go-check/check/issues/22
	t.c = nil
}

func (s *Suite) TearDownTest(c *check.C) {
	t := s.Tester
	t.c = nil // No longer usable; see https://github.com/go-check/check/issues/22

	err := os.Chdir(t.prevdir.String())
	assertNil(err, "Cannot chdir back to previous dir: %s", err)

	if t.seenSetupPkgsrc > 0 && !t.seenFinish && !t.seenMain {
		t.InternalErrorf("After t.SetupPkgsrc(), either t.FinishSetUp() or t.Main() must be called.")
	}

	t.ReportUncheckedOutput()
	t.tmpdir = ""
	t.DisableTracing()

	G = unusablePkglint()
}

// Ensures that all test names follow a common naming scheme:
//
//  Test_${Type}_${Method}__${description_using_underscores}
func Test__qa(t *testing.T) {
	ck := intqa.NewQAChecker(t.Errorf)

	ck.Configure("distinfo.go", "*", "*", -intqa.EMissingTest)       // TODO
	ck.Configure("files.go", "*", "*", -intqa.EMissingTest)          // TODO
	ck.Configure("licenses.go", "*", "*", -intqa.EMissingTest)       // TODO
	ck.Configure("line.go", "*", "*", -intqa.EMissingTest)           // TODO
	ck.Configure("linechecker.go", "*", "*", -intqa.EMissingTest)    // TODO
	ck.Configure("lines.go", "*", "*", -intqa.EMissingTest)          // TODO
	ck.Configure("logging.go", "*", "*", -intqa.EMissingTest)        // TODO
	ck.Configure("mkline.go", "*", "*", -intqa.EMissingTest)         // TODO
	ck.Configure("mklineparser.go", "*", "*", -intqa.EMissingTest)   // TODO
	ck.Configure("mklinechecker.go", "*", "*", -intqa.EMissingTest)  // TODO
	ck.Configure("mklines.go", "*", "*", -intqa.EMissingTest)        // TODO
	ck.Configure("mkparser.go", "*", "*", -intqa.EMissingTest)       // TODO
	ck.Configure("mkshparser.go", "*", "*", -intqa.EMissingTest)     // TODO
	ck.Configure("mkshtypes.go", "*", "*", -intqa.EMissingTest)      // TODO
	ck.Configure("mkshwalker.go", "*", "*", -intqa.EMissingTest)     // TODO
	ck.Configure("mktokenslexer.go", "*", "*", -intqa.EMissingTest)  // TODO
	ck.Configure("mktypes.go", "*", "*", -intqa.EMissingTest)        // TODO
	ck.Configure("options.go", "*", "*", -intqa.EMissingTest)        // TODO
	ck.Configure("package.go", "*", "*", -intqa.EMissingTest)        // TODO
	ck.Configure("paragraph.go", "*", "*", -intqa.EMissingTest)      // TODO
	ck.Configure("patches.go", "*", "*", -intqa.EMissingTest)        // TODO
	ck.Configure("pkglint.go", "*", "*", -intqa.EMissingTest)        // TODO
	ck.Configure("pkgsrc.go", "*", "*", -intqa.EMissingTest)         // TODO
	ck.Configure("redundantscope.go", "*", "*", -intqa.EMissingTest) // TODO
	ck.Configure("scope.go", "*", "*", -intqa.EMissingTest)          // TODO
	ck.Configure("shell.go", "*", "*", -intqa.EMissingTest)          // TODO
	ck.Configure("shtokenizer.go", "*", "*", -intqa.EMissingTest)    // TODO
	ck.Configure("shtypes.go", "*", "*", -intqa.EMissingTest)        // TODO
	ck.Configure("substcontext.go", "*", "*", -intqa.EMissingTest)   // TODO
	ck.Configure("tools.go", "*", "*", -intqa.EMissingTest)          // TODO
	ck.Configure("util.go", "*", "*", -intqa.EMissingTest)           // TODO
	ck.Configure("var.go", "*", "*", -intqa.EMissingTest)            // TODO

	ck.Configure("varalignblock.go", "*", "*", -intqa.EMissingTest)            // TODO
	ck.Configure("varalignblock.go", "varalignLine", "*", +intqa.EMissingTest) // TODO: remove as redundant

	ck.Configure("vardefs.go", "*", "*", -intqa.EMissingTest)   // TODO
	ck.Configure("vargroups.go", "*", "*", -intqa.EMissingTest) // TODO
	ck.Configure("vartype.go", "*", "*", -intqa.EMissingTest)   // TODO

	// Don't require tests for helper methods.
	ck.Configure("*.go", "VartypeCheck", "[a-z]*", -intqa.EMissingTest)

	// For now, don't require tests for all the test code.
	// Having good coverage for the main code is more important.
	ck.Configure("*_test.go", "*", "*", -intqa.EMissingTest)

	// These helper methods are usually so simple that they don't need
	// separate tests.
	// They are tested indirectly by the tests of their corresponding checks.
	ck.Configure("*", "*", "warn[A-Z]*", -intqa.EMissingTest)

	// Generated code doesn't need a unit test.
	// If any, every grammar production in the corresponding yacc file
	// should have a unit test.
	ck.Configure("*yacc.go", "*", "*", intqa.ENone)

	// Type definitions don't need a unit test.
	// Only functions and methods do.
	ck.Configure("*", "*", "", -intqa.EMissingTest)

	// The Suite type is used for testing all parts of pkglint.
	// Therefore its test methods may be everywhere.
	ck.Configure("*.go", "Suite", "*", -intqa.EMethodsSameFile)
	ck.Configure("*.go", "Tester", "*", -intqa.EMethodsSameFile)

	ck.Check()
}

var _ = check.Suite(new(Suite))

func Test(t *testing.T) { check.TestingT(t) }

// Tester provides utility methods for testing pkglint.
// It is separated from the Suite since the latter contains
// all the test methods, which makes it difficult to find
// a method by auto-completion.
type Tester struct {
	c        *check.C // Only usable during the test method itself
	testName string
	argv     []string // from the last invocation of Tester.SetUpCommandLine

	stdout  bytes.Buffer
	stderr  bytes.Buffer
	tmpdir  CurrPath
	prevdir CurrPath // The current working directory before the test started
	cwd     RelPath  // relative to tmpdir; see Tester.Chdir

	seenSetUpCommandLine bool
	seenSetupPkgsrc      int
	seenFinish           bool
	seenMain             bool
}

// SetUpCommandLine simulates a command line for the remainder of the test.
// See Pkglint.ParseCommandLine.
//
// If SetUpCommandLine is not called explicitly in a test, the command line
// "-Wall" is used, to provide a high code coverage in the tests.
func (t *Tester) SetUpCommandLine(args ...string) {

	// Prevent tracing from being disabled; see EnableSilentTracing.
	prevTracing := trace.Tracing
	defer func() { trace.Tracing = prevTracing }()

	argv := append([]string{"pkglint"}, args...)
	t.argv = argv
	exitcode := G.ParseCommandLine(argv)
	if exitcode != -1 && exitcode != 0 {
		t.CheckOutputEmpty()
		t.c.Fatalf("Cannot parse command line: %#v", args)
	}

	// Duplicate diagnostics often mean that the checking code is run
	// twice, which is unnecessary.
	//
	// It also reveals diagnostics that are logged multiple times per
	// line and thus can easily get annoying to the pkgsrc developers.
	//
	// To avoid running a check multiple times, see Line.once or MkLines.once.
	G.Logger.verbose = true

	t.seenSetUpCommandLine = true
}

// SetUpVartypes registers a few hundred variables like MASTER_SITES,
// WRKSRC, SUBST_SED.*, so that their data types are known to pkglint.
//
// Without calling this, there will be many warnings about undefined
// or unused variables, or unknown shell commands.
//
// See SetUpTool for registering tools like echo, awk, perl.
func (t *Tester) SetUpVartypes() {
	G.Pkgsrc.vartypes.Init(&G.Pkgsrc)
}

func (t *Tester) SetUpMasterSite(varname string, urls ...string) {
	if !G.Pkgsrc.vartypes.IsDefinedExact(varname) {
		t.SetUpType(varname, BtFetchURL,
			List|SystemProvided,
			"buildlink3.mk: none",
			"*: use")
	}

	for _, url := range urls {
		G.Pkgsrc.registerMasterSite(varname, url)
	}
}

// SetUpOption pretends that the given package option is defined in mk/defaults/options.description.
//
// In tests, the description may be left empty.
func (t *Tester) SetUpOption(name, description string) {
	G.Pkgsrc.PkgOptions[name] = description
}

func (t *Tester) SetUpTool(name, varname string, validity Validity) *Tool {
	return G.Pkgsrc.Tools.def(name, varname, false, validity, nil)
}

// SetUpType defines a variable to have a certain type and access permissions,
// like in the type definitions in vardefs.go.
//
// Example:
//  SetUpType("PKGPATH", BtPkgpath, DefinedIfInScope|NonemptyIfDefined,
//      "Makefile, *.mk: default, set, append, use, use-loadtime")
func (t *Tester) SetUpType(varname string, basicType *BasicType,
	options vartypeOptions, aclEntries ...string) {

	if len(aclEntries) == 0 {
		aclEntries = []string{"Makefile, *.mk: default, set, append, use, use-loadtime"}
	}

	G.Pkgsrc.vartypes.acl(varname, basicType, options, aclEntries...)

	// Make sure that registering the type succeeds.
	// This is necessary for BtUnknown and guessed types.
	vartype := G.Pkgsrc.VariableType(nil, varname)
	t.c.Assert(vartype.basicType, check.Equals, basicType)
}

// SetUpFileLines creates a temporary file and writes the given lines to it.
// The file is then read in, without interpreting line continuations.
//
// See SetUpFileMkLines for loading a Makefile fragment.
func (t *Tester) SetUpFileLines(filename RelPath, lines ...string) *Lines {
	abs := t.CreateFileLines(filename, lines...)
	return Load(abs, MustSucceed)
}

// SetUpFileLines creates a temporary file and writes the given lines to it.
// The file is then read in, handling line continuations for Makefiles.
//
// See SetUpFileLines for loading an ordinary file.
//
// If the filename is irrelevant for the particular test, take filename.mk.
func (t *Tester) SetUpFileMkLines(filename RelPath, lines ...string) *MkLines {
	return t.SetUpFileMkLinesPkg(filename, nil, lines...)
}

func (t *Tester) SetUpFileMkLinesPkg(filename RelPath, pkg *Package, lines ...string) *MkLines {
	abs := t.CreateFileLines(filename, lines...)
	return LoadMk(abs, pkg, MustSucceed)
}

// LoadMkInclude loads the given Makefile fragment and all the files it includes,
// merging all the lines into a single MkLines object.
//
// This is useful for testing code related to Package.readMakefile.
func (t *Tester) LoadMkInclude(filename RelPath) *MkLines {
	var lines []*Line

	// TODO: Include files with multiple-inclusion guard only once.
	// TODO: Include files without multiple-inclusion guard as often as needed.

	var load func(filename CurrPath)
	load = func(filename CurrPath) {
		mklines := NewMkLines(Load(filename, MustSucceed), nil, nil)
		for _, mkline := range mklines.mklines {
			lines = append(lines, mkline.Line)

			if mkline.IsInclude() {
				load(mkline.IncludedFileFull())
			}
		}
	}

	load(t.File(filename))

	// This assumes that the test files do not contain parse errors.
	// Otherwise the diagnostics would appear twice.
	return NewMkLines(NewLines(t.File(filename), lines), nil, nil)
}

// SetUpPkgsrc sets up a minimal but complete pkgsrc installation in the
// temporary folder, so that pkglint runs without any errors.
// Individual files may be overwritten by calling other SetUp* methods.
//
// This setup is especially interesting for testing Pkglint.Main.
func (t *Tester) SetUpPkgsrc() {

	// This file is needed to locate the pkgsrc root directory.
	// See findPkgsrcTopdir.
	t.CreateFileLines("mk/bsd.pkg.mk",
		MkCvsID)

	// See Pkgsrc.loadDocChanges.
	t.CreateFileLines("doc/CHANGES-2018",
		CvsID)

	// See Pkgsrc.loadSuggestedUpdates.
	t.CreateFileLines("doc/TODO",
		CvsID)

	// Some example licenses so that the tests for whole packages
	// don't need to define them on their own.
	t.CreateFileLines("licenses/2-clause-bsd",
		"Redistribution and use in source and binary forms ...")
	t.CreateFileLines("licenses/gnu-gpl-v2",
		"The licenses for most software are designed to take away ...")

	// The various MASTER_SITE_* variables for use in the
	// MASTER_SITES are defined in this file.
	//
	// To define a MASTER_SITE for a pkglint test, call t.SetUpMasterSite.
	//
	// See Pkgsrc.loadMasterSites.
	t.CreateFileLines("mk/fetch/sites.mk",
		MkCvsID)

	// The options for the PKG_OPTIONS framework are defined here.
	//
	// See Pkgsrc.loadPkgOptions.
	t.CreateFileLines("mk/defaults/options.description",
		"example-option   Description for the example option",
		"example-option-without-description")

	// The user-defined variables are read in to check for missing
	// BUILD_DEFS declarations in the package Makefile.
	t.CreateFileLines("mk/defaults/mk.conf",
		MkCvsID)

	// The tool definitions are defined in various files in mk/tools/.
	// The relevant files are listed in bsd.tools.mk.
	// The tools that are defined here can be used in USE_TOOLS.
	t.CreateFileLines("mk/tools/bsd.tools.mk",
		".include \"defaults.mk\"")
	t.CreateFileLines("mk/tools/defaults.mk",
		MkCvsID)

	// Those tools that are added to USE_TOOLS in bsd.prefs.mk may be
	// used at load time by packages.
	t.CreateFileLines("mk/bsd.prefs.mk",
		MkCvsID)
	t.CreateFileLines("mk/bsd.fast.prefs.mk",
		MkCvsID)

	// This file is used for initializing the allowed values for
	// USE_LANGUAGES; see VarTypeRegistry.compilerLanguages.
	t.CreateFileLines("mk/compiler.mk",
		"_CXX_STD_VERSIONS=\tc++ c++14",
		".if ${USE_LANGUAGES:Mada} || \\",
		"    ${USE_LANGUAGES:Mc} || \\",
		"    ${USE_LANGUAGES:Mc99} || \\",
		"    ${USE_LANGUAGES:Mobjc} || \\",
		"    ${USE_LANGUAGES:Mfortran} || \\",
		"    ${USE_LANGUAGES:Mfortran77}",
		".endif")

	// Category Makefiles require this file for the common definitions.
	t.CreateFileLines("mk/misc/category.mk")

	// TODO
	// assert(!t.File("mk/bsd.options.mk").IsFile())
	// t.CreateFileLines("mk/bsd.options.mk")

	t.seenSetupPkgsrc++
}

// SetUpCategory makes the given category valid by creating a dummy Makefile.
// After that, it can be mentioned in the CATEGORIES variable of a package.
func (t *Tester) SetUpCategory(name RelPath) {
	assert(G.Pkgsrc.Rel(t.File(name)).Count() == 1)

	makefile := name.JoinNoClean("Makefile")
	if !t.File(makefile).IsFile() {
		t.CreateFileLines(makefile,
			MkCvsID)
	}
}

// SetUpPackage sets up all files for a package (including the pkgsrc
// infrastructure) so that it does not produce any warnings.
//
// The given makefileLines start in line 20. Except if they are variable
// definitions for already existing variables, then they replace that line.
//
// Returns the path to the package, ready to be used with Pkglint.Check.
//
// After calling this method, individual files can be overwritten as necessary.
// At the end of the setup phase, t.FinishSetUp() must be called to load all
// the files.
//
// If the package path does not really matter for this test,
// just use "category/package".
//
// To get short pathnames in the diagnostics, t.Chdir is often called
// afterwards, if the test only sets up a single package.
// In that case, the returned path is often not used since passing it
// to Pkglint.Check would generate the long pathnames in the diagnostics.
func (t *Tester) SetUpPackage(pkgpath RelPath, makefileLines ...string) CurrPath {
	assertf(
		matches(pkgpath.String(), `^[^/]+/[^/]+$`),
		"pkgpath %q must have the form \"category/package\"", pkgpath)

	distname := pkgpath.Base()
	category := pkgpath.Dir()
	if category == "wip" {
		// To avoid boilerplate CATEGORIES definitions for wip packages.
		category = "local"
	}

	t.SetUpPkgsrc()
	t.SetUpCategory(category)

	t.CreateFileLines(pkgpath.JoinNoClean("DESCR"),
		"Package description")
	t.CreateFileLines(pkgpath.JoinNoClean("PLIST"),
		PlistCvsID,
		"bin/program")

	// Because the package Makefile includes this file, the check for the
	// correct ordering of variables is skipped. As of February 2019, the
	// SetupPackage function does not insert the custom variables in the
	// correct position. To prevent the tests from having to mention the
	// unrelated warnings about the variable order, that check is suppressed
	// here.
	t.CreateFileLines(pkgpath.JoinNoClean("suppress-varorder.mk"),
		MkCvsID)

	// This distinfo file contains dummy hashes since pkglint cannot check the
	// distfiles hashes anyway. It can only check the hashes for the patches.
	t.CreateFileLines(pkgpath.JoinNoClean("distinfo"),
		CvsID,
		"",
		"SHA1 (distfile-1.0.tar.gz) = 12341234",
		"RMD160 (distfile-1.0.tar.gz) = 12341234",
		"SHA512 (distfile-1.0.tar.gz) = 12341234",
		"Size (distfile-1.0.tar.gz) = 12341234")

	mlines := []string{
		MkCvsID,
		"",
		"DISTNAME=\t" + distname.String() + "-1.0",
		"#PKGNAME=\tpackage-1.0",
		"CATEGORIES=\t" + category.String(),
		"MASTER_SITES=\t# none",
		"",
		"MAINTAINER=\tpkgsrc-users@NetBSD.org",
		"HOMEPAGE=\t# none",
		"COMMENT=\tDummy package",
		"LICENSE=\t2-clause-bsd",
		"",
		".include \"suppress-varorder.mk\""}
	if len(mlines) < 19 {
		mlines = append(mlines, "")
	}
	for len(mlines) < 18 {
		mlines = append(mlines, "# filler")
	}
	if len(mlines) < 19 {
		mlines = append(mlines, "")
	}

line:
	for _, line := range makefileLines {
		assert(!hasSuffix(line, "\\")) // Continuation lines are not yet supported.

		if m, varname := match1(line, `^#?(\w+)[!+:?]?=`); m {
			for i, existingLine := range mlines[:19] {
				if hasPrefix(strings.TrimPrefix(existingLine, "#"), varname+"=") {
					mlines[i] = line
					continue line
				}
			}
		}
		mlines = append(mlines, line)
	}

	mlines = append(mlines,
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	t.CreateFileLines(pkgpath.JoinNoClean("Makefile"),
		mlines...)

	return t.File(pkgpath)
}

// CreateFileLines creates a file in the temporary directory and writes the
// given lines to it.
//
// It returns the full path to the created file.
func (t *Tester) CreateFileLines(filename RelPath, lines ...string) CurrPath {
	var content strings.Builder
	for _, line := range lines {
		content.WriteString(line)
		content.WriteString("\n")
	}

	abs := t.File(filename)
	err := os.MkdirAll(abs.Dir().String(), 0777)
	t.c.Assert(err, check.IsNil)

	err = abs.WriteString(content.String())
	t.c.Assert(err, check.IsNil)

	G.fileCache.Evict(abs)

	return abs
}

// CreateFileDummyPatch creates a patch file with the given name in the
// temporary directory.
func (t *Tester) CreateFileDummyPatch(filename RelPath) {
	// Patch files only make sense in category/package/patches directories.
	assert(G.Pkgsrc.Rel(t.File(filename)).Count() == 4)

	patchedFile := replaceAll(filename.String(), `.*?\bpatches/patch-`, "")

	t.CreateFileLines(filename,
		CvsID,
		"",
		"Documentation",
		"",
		"--- oldfile",
		"+++ "+patchedFile,
		"@@ -1 +1 @@",
		"-old",
		"+new")
}

func (t *Tester) CreateFileBuildlink3(filename RelPath, customLines ...string) {
	lower := filename.Dir().Base()
	t.CreateFileBuildlink3Id(filename, lower.String(), customLines...)
}

func (t *Tester) CreateFileBuildlink3Id(filename RelPath, id string, customLines ...string) {
	// Buildlink3.mk files only make sense in category/package directories.
	assert(G.Pkgsrc.Rel(t.File(filename)).Count() == 3)

	dir := filename.Dir().Clean()
	// see pkgtools/createbuildlink/files/createbuildlink, "package specific variables"
	upperID := strings.Replace(strings.ToUpper(id), "-", "_", -1)

	width := tabWidthSlice("BUILDLINK_API_DEPENDS.", id, "+=\t")

	aligned := func(format string, args ...interface{}) string {
		msg := sprintf(format, args...)
		for tabWidth(msg) < width {
			msg += "\t"
		}
		return msg
	}

	var lines []string
	lines = append(lines,
		MkCvsID,
		"",
		sprintf("BUILDLINK_TREE+=\t%s", id),
		"",
		sprintf(".if !defined(%s_BUILDLINK3_MK)", upperID),
		sprintf("%s_BUILDLINK3_MK:=", upperID),
		"",
		aligned("BUILDLINK_API_DEPENDS.%s+=", id)+sprintf("%s>=0", id),
		// TODO: Add ABI_DEPENDS; see Test_LoadBuildlink3Data
		aligned("BUILDLINK_PKGSRCDIR.%s?=", id)+sprintf("../../%s", dir),
		aligned("BUILDLINK_DEPMETHOD.%s?=", id)+"build",
		"")
	lines = append(lines, customLines...)
	lines = append(lines,
		"",
		sprintf(".endif # %s_BUILDLINK3_MK", upperID),
		"",
		sprintf("BUILDLINK_TREE+=\t-%s", id))

	t.CreateFileLines(filename, lines...)
}

// File returns the absolute path to the given file in the
// temporary directory. It doesn't check whether that file exists.
// Calls to Tester.Chdir change the base directory for the relative filename.
func (t *Tester) File(filename RelPath) CurrPath {
	if t.tmpdir.IsEmpty() {
		t.tmpdir = NewCurrPathSlash(t.c.MkDir())
	}
	if t.cwd != "" {
		return NewCurrPath(filename.Clean().AsPath())
	}
	return t.tmpdir.JoinClean(filename)
}

// Copy copies a file inside the temporary directory.
func (t *Tester) Copy(source, target RelPath) {
	absSource := t.File(source)
	absTarget := t.File(target)

	data, err := absSource.ReadString()
	assertNil(err, "Copy.Read")
	err = os.MkdirAll(absTarget.Dir().Clean().String(), 0777)
	assertNil(err, "Copy.MkdirAll")
	err = absTarget.WriteString(data)
	assertNil(err, "Copy.Write")
}

// Chdir changes the current working directory to the given subdirectory
// of the temporary directory, creating it if necessary.
//
// After this call, all files loaded from the temporary directory via
// SetUpFileLines or CreateFileLines or similar methods will use path names
// relative to this directory.
//
// After the test, the previous working directory is restored, so that
// the other tests are unaffected.
//
// As long as this method is not called in a test, the current working
// directory is indeterminate.
func (t *Tester) Chdir(dirname RelPath) {
	if t.cwd != "" {
		// When multiple calls of Chdir are mixed with calls to CreateFileLines,
		// the resulting Lines and MkLines variables will use relative filenames,
		// and these will point to different areas in the file system. This is
		// usually not indented and therefore prevented.
		t.c.Fatalf("Chdir must only be called once per test; already in %q.", t.cwd)
	}

	absDirName := t.File(dirname)
	assertNil(os.MkdirAll(absDirName.String(), 0700), "MkDirAll")
	assertNil(os.Chdir(absDirName.String()), "Chdir")
	t.cwd = dirname
	G.cwd = absDirName
	G.Pkgsrc.topdir = NewCurrPath(absDirName.Rel(G.Pkgsrc.topdir).AsPath())
}

// Remove removes the file or directory from the temporary directory.
// The file or directory must exist.
func (t *Tester) Remove(filename RelPath) {
	abs := t.File(filename)
	err := os.Remove(abs.String())
	t.c.Assert(err, check.IsNil)
	G.fileCache.Evict(abs)
}

// SetUpHierarchy provides a function for creating hierarchies of MkLines
// that include each other.
// The hierarchy is created only in memory, nothing is written to disk.
//
//  include, get := t.SetUpHierarchy()
//
//  include("including.mk",
//      include("other.mk",
//          "VAR= other"),
//      include("subdir/module.mk",
//          "VAR= module",
//          include("subdir/version.mk",
//              "VAR= version"),
//          include("subdir/env.mk",
//              "VAR= env")))
//
//  mklines := get("including.mk")
//  module := get("subdir/module.mk")
//
// The filenames passed to the include function are all relative to the
// same location, which is typically the pkgsrc root or a package directory,
// but the code doesn't care.
//
// The generated .include lines take the relative paths into account.
// For example, when subdir/module.mk includes subdir/version.mk,
// the include line is just:
//  .include "version.mk"
func (t *Tester) SetUpHierarchy() (
	include func(filename RelPath, args ...interface{}) *MkLines,
	get func(path RelPath) *MkLines) {

	files := map[RelPath]*MkLines{}
	basedir := NewPath(".")

	// includePath returns the path to be used in an .include.
	//
	// This is the same mechanism that is used in Pkgsrc.Relpath.
	includePath := func(including, included RelPath) RelPath {
		fromDir := including.Dir().Clean()
		to := basedir.Rel(included.AsPath())
		if fromDir == to.Dir() {
			return to.Base()
		} else {
			return fromDir.Rel(basedir).JoinNoClean(to).CleanDot()
		}
	}

	include = func(filename RelPath, args ...interface{}) *MkLines {
		var lines []*Line
		lineno := 1
		relFilename := basedir.Rel(filename.AsPath())

		addLine := func(text string) {
			lines = append(lines, t.NewLine(NewCurrPath(relFilename.AsPath()), lineno, text))
			lineno++
		}

		for _, arg := range args {
			switch arg := arg.(type) {
			case string:
				addLine(arg)
			case *MkLines:
				rel := includePath(relFilename, NewRelPath(arg.lines.Filename.AsPath()))
				addLine(sprintf(".include %q", rel))
				lines = append(lines, arg.lines.Lines...)
			default:
				panic("invalid type")
			}
		}

		mklines := NewMkLines(NewLines(NewCurrPath(relFilename.AsPath()), lines), nil, nil)
		assertf(files[filename] == nil, "MkLines with name %q already exists.", filename)
		files[filename] = mklines
		return mklines
	}

	get = func(filename RelPath) *MkLines {
		assertf(files[filename] != nil, "MkLines with name %q doesn't exist.", filename)
		return files[filename]
	}

	return
}

// Demonstrates that Tester.SetUpHierarchy uses relative paths for the
// .include directives.
func (s *Suite) Test_Tester_SetUpHierarchy(c *check.C) {
	t := s.Init(c)

	include, get := t.SetUpHierarchy()
	include("including.mk",
		include("other.mk",
			"VAR= other"),
		include("subdir/module.mk",
			"VAR= module",
			include("subdir/version.mk",
				"VAR= version"),
			include("subdir/env.mk",
				"VAR= env")))

	mklines := get("including.mk")

	mklines.ForEach(func(mkline *MkLine) { mkline.Notef("Text is: %s", mkline.Text) })

	t.CheckOutputLines(
		"NOTE: including.mk:1: Text is: .include \"other.mk\"",
		"NOTE: other.mk:1: Text is: VAR= other",
		"NOTE: including.mk:2: Text is: .include \"subdir/module.mk\"",
		"NOTE: subdir/module.mk:1: Text is: VAR= module",
		"NOTE: subdir/module.mk:2: Text is: .include \"version.mk\"",
		"NOTE: subdir/version.mk:1: Text is: VAR= version",
		"NOTE: subdir/module.mk:3: Text is: .include \"env.mk\"",
		"NOTE: subdir/env.mk:1: Text is: VAR= env")
}

// FinishSetup loads the pkgsrc infrastructure.
// Later changes to the files in mk/ have no effect.
func (t *Tester) FinishSetUp() {
	if t.seenSetupPkgsrc == 0 {
		t.InternalErrorf("Unnecessary t.FinishSetUp() since t.SetUpPkgsrc() has not been called.")
	}

	if !t.seenFinish {
		t.seenFinish = true
		G.Pkgsrc.LoadInfrastructure()
	} else {
		t.InternalErrorf("Redundant t.FinishSetup() since it was called multiple times.")
	}
}

// Main runs the pkglint main program with the given command line arguments.
// Other than in the other tests, the -Wall option is not added implicitly.
//
// Arguments that name existing files or directories in the temporary test
// directory are transformed to their actual paths.
//
// Does not work in combination with SetUpOption.
func (t *Tester) Main(args ...string) int {
	if t.seenFinish && !t.seenMain {
		t.InternalErrorf("Calling t.FinishSetup() before t.Main() is redundant " +
			"since t.Main() loads the pkgsrc infrastructure.")
	}
	if t.seenSetUpCommandLine {
		t.InternalErrorf("Calling t.SetupCommandLine() before t.Main() is redundant " +
			"since t.Main() accepts the command line options directly.")
	}

	t.seenMain = true

	// Reset the logger, for tests where t.Main is called multiple times.
	G.Logger.errors = 0
	G.Logger.warnings = 0
	G.Logger.logged = Once{}

	argv := []string{"pkglint"}
	for _, arg := range args {
		fileArg := NewCurrPathSlash(arg)
		if fileArg.IsAbs() {
			argv = append(argv, arg)
			continue
		}

		file := t.File(NewRelPathString(arg))
		if file.Exists() {
			argv = append(argv, file.String())
		} else {
			argv = append(argv, arg)
		}
	}

	return G.Main(&t.stdout, &t.stderr, argv)
}

// Check delegates a check to the check.Check function.
// Thereby, there is no need to distinguish between c.Check and t.Check
// in the test code.
func (t *Tester) Check(obj interface{}, checker check.Checker, args ...interface{}) bool {
	return t.c.Check(obj, checker, args...)
}

func (t *Tester) CheckEquals(actual interface{}, expected interface{}) bool {
	return t.c.Check(actual, check.Equals, expected)
}

func (t *Tester) CheckEqualsf(actual interface{}, expected interface{}, format string, args ...interface{}) bool {
	return t.c.Check(actual, check.Equals, expected,
		check.Commentf(format, args...))
}

func (t *Tester) CheckDeepEquals(actual interface{}, expected interface{}) bool {
	return t.c.Check(actual, check.DeepEquals, expected)
}

func (t *Tester) CheckDeepEqualsf(actual interface{}, expected interface{}, format string, args ...interface{}) bool {
	return t.c.Check(actual, check.DeepEquals, expected,
		check.Commentf(format, args...))
}

// InternalErrorf reports a consistency error in the tests.
func (t *Tester) InternalErrorf(format string, args ...interface{}) {
	// It is not possible to panic here since check.v1 would then
	// ignore all subsequent tests.
	_, _ = fmt.Fprintf(os.Stderr, "In %s: %s\n", t.testName, sprintf(format, args...))
}

// ExpectFatal runs the given action and expects that this action calls
// Line.Fatalf or uses some other way to panic with a pkglintFatal.
//
// Usage:
//  t.ExpectFatal(
//      func() { /* do something that panics */ },
//      "FATAL: ~/Makefile:1: Must not be empty")
func (t *Tester) ExpectFatal(action func(), expectedLines ...string) {
	defer func() {
		r := recover()
		if r == nil {
			panic("Expected a pkglint fatal error but didn't get one.")
		} else if _, ok := r.(pkglintFatal); ok {
			t.CheckOutputLines(expectedLines...)
		} else {
			panic(r)
		}
	}()

	action()
}

// ExpectFatalMatches runs the given action and expects that this action
// calls Line.Fatalf or uses some other way to panic with a pkglintFatal.
// It then matches the output against the given regular expression.
//
// Usage:
//  t.ExpectFatalMatches(
//      func() { /* do something that panics */ },
//      `FATAL: ~/Makefile:1: .*\n`)
func (t *Tester) ExpectFatalMatches(action func(), expected regex.Pattern) {
	defer func() {
		r := recover()
		if r == nil {
			panic("Expected a pkglint fatal error but didn't get one.")
		} else if _, ok := r.(pkglintFatal); ok {
			pattern := `^(?:` + string(expected) + `)$`
			t.Check(t.Output(), check.Matches, pattern)
		} else {
			panic(r)
		}
	}()

	action()
}

// ExpectPanic runs the given action and expects that this action calls
// assert or assertf, or uses some other way to panic.
//
// Usage:
//  t.ExpectPanic(
//      func() { /* do something that panics */ },
//      "runtime error: path not found")
func (t *Tester) ExpectPanic(action func(), expectedMessage string) {
	t.Check(action, check.Panics, expectedMessage)
}

// ExpectPanicMatches runs the given action and expects that this action
// calls assert or assertf, or uses some other way to panic.
// The expectedMessage is anchored on both ends.
func (t *Tester) ExpectPanicMatches(action func(), expectedMessage regex.Pattern) {
	t.Check(action, check.PanicMatches, string(expectedMessage))
}

// ExpectAssert runs the given action and expects that this action calls assert.
//
// Usage:
//  t.ExpectAssert(
//      func() { /* do something that panics */ })
func (t *Tester) ExpectAssert(action func()) {
	t.Check(action, check.Panics, "Pkglint internal error")
}

// ExpectDiagnosticsAutofix first runs the given action with -Wall, and
// then another time with -Wall --autofix.
//
// Note that to be realistic, the action must work with completely freshly
// created objects, to prevent suppression of duplicate diagnostics and
// changes to the text due to autofixes.
func (t *Tester) ExpectDiagnosticsAutofix(action func(autofix bool), diagnostics ...string) {
	t.SetUpCommandLine("-Wall")
	action(false)

	t.SetUpCommandLine("-Wall", "--autofix")
	action(true)

	t.CheckOutput(diagnostics)
}

// NewLine creates an in-memory line with the given text.
// This line does not correspond to any line in a file.
func (t *Tester) NewLine(filename CurrPath, lineno int, text string) *Line {
	return NewLine(filename, lineno, text, &RawLine{text + "\n"})
}

// NewMkLine creates an in-memory line in the Makefile format with the given text.
func (t *Tester) NewMkLine(filename CurrPath, lineno int, text string) *MkLine {
	basename := filename.Base()
	assertf(
		basename.HasSuffixText(".mk") ||
			basename == "Makefile" ||
			basename.HasPrefixText("Makefile.") ||
			basename == "mk.conf",
		"filename %q must be realistic, otherwise the variable permissions are wrong", filename)

	return NewMkLineParser().Parse(t.NewLine(filename, lineno, text))
}

func (t *Tester) NewShellLineChecker(text string) *ShellLineChecker {
	mklines := t.NewMkLines("filename.mk", text)
	return NewShellLineChecker(mklines, mklines.mklines[0])
}

// NewLines returns a list of simple lines that belong together.
//
// To work with line continuations like in Makefiles, use SetUpFileMkLines.
func (t *Tester) NewLines(filename CurrPath, lines ...string) *Lines {
	return t.NewLinesAt(filename, 1, lines...)
}

// NewLinesAt returns a list of simple lines that belong together.
//
// To work with line continuations like in Makefiles, use SetUpFileMkLines.
func (t *Tester) NewLinesAt(filename CurrPath, firstLine int, texts ...string) *Lines {
	lines := make([]*Line, len(texts))
	for i, text := range texts {
		lines[i] = t.NewLine(filename, i+firstLine, text)
	}
	return NewLines(filename, lines)
}

// NewMkLines returns a list of lines in Makefile format,
// as if they were parsed from a Makefile fragment,
// taking continuation lines into account.
//
// No actual file is created for the lines;
// see SetUpFileMkLines for loading Makefile fragments with line continuations.
//
// After calling Tester.Chdir, NewMkLines creates the same object as
// SetUpFileMkLines, just without anything being written to disk.
// This can lead to strange error messages such as "Relative path %s does
// not exist." because an intermediate directory in the path does not exist.
//
// If the filename is irrelevant for the particular test, just use filename.mk.
func (t *Tester) NewMkLines(filename CurrPath, lines ...string) *MkLines {
	return t.NewMkLinesPkg(filename, nil, lines...)
}

func (t *Tester) NewMkLinesPkg(filename CurrPath, pkg *Package, lines ...string) *MkLines {
	basename := filename.Base()
	assertf(
		basename.HasSuffixText(".mk") || basename == "Makefile" || basename.HasPrefixText("Makefile."),
		"filename %q must be realistic, otherwise the variable permissions are wrong", filename)

	var rawText strings.Builder
	for _, line := range lines {
		rawText.WriteString(line)
		rawText.WriteString("\n")
	}
	return NewMkLines(convertToLogicalLines(filename, rawText.String(), true), pkg, nil)
}

// Returns and consumes the output from both stdout and stderr.
// In the output, the temporary directory is replaced with a tilde (~).
func (t *Tester) Output() string {
	stdout := t.stdout.String()
	stderr := t.stderr.String()

	t.stdout.Reset()
	t.stderr.Reset()
	if G.isUsable() {
		G.Logger.logged = Once{}
		if G.Logger.out != nil { // Necessary because Main resets the G variable.
			G.Logger.out.state = 0 // Prevent an empty line at the beginning of the next output.
			G.Logger.err.state = 0
		}
	}

	assertf(t.tmpdir != "", "Tester must be initialized before checking the output.")
	return strings.Replace(stdout+stderr, t.tmpdir.String(), "~", -1)
}

// CheckOutputEmpty ensures that the output up to now is empty.
//
// See CheckOutputLines.
func (t *Tester) CheckOutputEmpty() {
	t.CheckOutput(nil)
}

// CheckOutputLines checks that the output up to now equals the given lines.
//
// After the comparison, the output buffers are cleared so that later
// calls only check against the newly added output.
//
// See CheckOutputEmpty, CheckOutputLinesIgnoreSpace.
func (t *Tester) CheckOutputLines(expectedLines ...string) {
	assertf(len(expectedLines) > 0, "To check empty lines, use CheckOutputEmpty instead.")
	t.CheckOutput(expectedLines)
}

// CheckOutputLinesMatching checks that the lines from the output that match
// the given pattern equal the given lines.
//
// After the comparison, the output buffers are cleared so that later
// calls only check against the newly added output.
//
// See CheckOutputEmpty, CheckOutputLinesIgnoreSpace.
func (t *Tester) CheckOutputLinesMatching(pattern regex.Pattern, expectedLines ...string) {
	output := t.Output()
	var actualLines []string
	for _, line := range strings.Split(strings.TrimSuffix(output, "\n"), "\n") {
		if matches(line, pattern) {
			actualLines = append(actualLines, line)
		}
	}
	t.CheckDeepEquals(emptyToNil(actualLines), emptyToNil(expectedLines))
}

// CheckOutputLinesIgnoreSpace checks that the output up to now equals the given lines.
// During comparison, each run of whitespace (space, tab, newline) is normalized so that
// different line breaks are ignored. This is useful for testing line-wrapped explanations.
//
// After the comparison, the output buffers are cleared so that later
// calls only check against the newly added output.
//
// See CheckOutputEmpty, CheckOutputLines.
func (t *Tester) CheckOutputLinesIgnoreSpace(expectedLines ...string) {
	assertf(len(expectedLines) > 0, "To check empty lines, use CheckOutputEmpty instead.")
	assertf(!t.tmpdir.IsEmpty(), "Tester must be initialized before checking the output.")

	rawOutput := t.stdout.String() + t.stderr.String()
	_ = t.Output() // Just to consume the output

	actual, expected := t.compareOutputIgnoreSpace(rawOutput, expectedLines, t.tmpdir)
	t.CheckDeepEquals(actual, expected)
}

func (t *Tester) compareOutputIgnoreSpace(rawOutput string, expectedLines []string, tmpdir CurrPath) ([]string, []string) {
	whitespace := regexp.MustCompile(`\s+`)

	// Replace all occurrences of tmpdir in the raw output with a tilde,
	// also covering cases where tmpdir is wrapped into multiple lines.
	output := func() string {
		var tmpdirPattern strings.Builder
		for i, part := range whitespace.Split(tmpdir.String(), -1) {
			if i > 0 {
				tmpdirPattern.WriteString("\\s+")
			}
			tmpdirPattern.WriteString(regexp.QuoteMeta(part))
		}

		return regexp.MustCompile(tmpdirPattern.String()).ReplaceAllString(rawOutput, "~")
	}()

	normSpace := func(s string) string {
		return whitespace.ReplaceAllString(s, " ")
	}
	if normSpace(output) == normSpace(strings.Join(expectedLines, "\n")) {
		return nil, nil
	}

	actualLines := strings.Split(output, "\n")
	actualLines = actualLines[:len(actualLines)-1]

	return emptyToNil(actualLines), emptyToNil(expectedLines)
}

func (s *Suite) Test_Tester_compareOutputIgnoreSpace(c *check.C) {
	t := s.Init(c)

	lines := func(lines ...string) []string { return lines }
	test := func(rawOutput string, expectedLines []string, tmpdir CurrPath, eq bool) {
		actual, expected := t.compareOutputIgnoreSpace(rawOutput, expectedLines, tmpdir)
		t.CheckEquals(actual == nil && expected == nil, eq)
	}

	test("", lines(), "/tmp", true)

	// The expectedLines are missing a space at the end.
	test(" \t\noutput\n\t ", lines("\toutput"), "/tmp", false)

	test(" \t\noutput\n\t ", lines("\toutput\n"), "/tmp", true)

	test("/tmp/\n\t \nspace", lines("~"), "/tmp/\t\t\t   \n\n\nspace", true)

	// The rawOutput contains more spaces than the tmpdir.
	test("/tmp/\n\t \nspace", lines("~"), "/tmp/space", false)

	// The tmpdir contains more spaces than the rawOutput.
	test("/tmp/space", lines("~"), "/tmp/ \t\nspace", false)
}

// CheckOutputMatches checks that the output up to now matches the given lines.
// Each line may either be an exact string or a regular expression.
// By convention, regular expressions are written in backticks.
//
// After the comparison, the output buffers are cleared so that later
// calls only check against the newly added output.
//
// See CheckOutputEmpty.
func (t *Tester) CheckOutputMatches(expectedLines ...regex.Pattern) {
	output := t.Output()
	actualLines := strings.Split(output, "\n")
	actualLines = actualLines[:len(actualLines)-1]

	ok := func(actualLine string, expectedLine regex.Pattern) bool {
		if actualLine == string(expectedLine) {
			return true
		}

		pattern := `^(?:` + string(expectedLine) + `)$`
		re, err := regexp.Compile(pattern)
		return err == nil && re.MatchString(actualLine)
	}

	// If a line matches the corresponding pattern, make them equal in the
	// comparison output, in order to concentrate on the lines that don't match.
	var patterns []string
	for i, expectedLine := range expectedLines {
		if i < len(actualLines) && ok(actualLines[i], expectedLine) {
			patterns = append(patterns, actualLines[i])
		} else {
			patterns = append(patterns, string(expectedLine))
		}
	}

	t.CheckDeepEquals(emptyToNil(actualLines), emptyToNil(patterns))
}

// CheckOutput checks that the output up to now equals the given lines.
// After the comparison, the output buffers are cleared so that later
// calls only check against the newly added output.
//
// The expectedLines can be either empty or non-empty.
//
// When the output is always empty, use CheckOutputEmpty instead.
// When the output always contain some lines, use CheckOutputLines instead.
// This variant should only be used when the expectedLines are generated dynamically.
func (t *Tester) CheckOutput(expectedLines []string) {
	output := t.Output()
	actualLines := strings.Split(output, "\n")
	actualLines = actualLines[:len(actualLines)-1]
	t.CheckDeepEquals(emptyToNil(actualLines), emptyToNil(expectedLines))
}

// EnableTracing logs the tracing output to os.Stdout instead of silently discarding it.
// The normal diagnostics are written to the in-memory buffer as usual,
// and additionally they are written to os.Stdout,
// where they are shown together with the trace log.
//
// This is useful when stepping through the code, especially
// in combination with SetUpCommandLine("--debug").
func (t *Tester) EnableTracing() {
	G.Logger.out = NewSeparatorWriter(io.MultiWriter(os.Stdout, &t.stdout))
	trace.Out = os.Stdout
	trace.Tracing = true
}

// EnableTracingToLog enables the tracing and writes the tracing output
// to the test log that can be examined with Tester.Output.
func (t *Tester) EnableTracingToLog() {
	G.Logger.out = NewSeparatorWriter(&t.stdout)
	trace.Out = &t.stdout
	trace.Tracing = true
}

// EnableSilentTracing enables tracing mode but discards any tracing output.
// This is the default mode when running the tests.
// The diagnostics go to the in-memory buffer.
//
// It is used to check all calls to trace.Result, since the compiler
// cannot check them.
func (t *Tester) EnableSilentTracing() {
	G.Logger.out = NewSeparatorWriter(&t.stdout)
	trace.Out = ioutil.Discard
	trace.Tracing = true
}

// DisableTracing skips all tracing code.
// The diagnostics go to the in-memory buffer again,
// ready to be checked with CheckOutputLines.
func (t *Tester) DisableTracing() {
	if G.isUsable() {
		G.Logger.out = NewSeparatorWriter(&t.stdout)
	}
	trace.Tracing = false
	trace.Out = nil
}

// CheckFileLines loads the lines from the temporary file and checks that
// they equal the given lines.
func (t *Tester) CheckFileLines(filename RelPath, lines ...string) {
	content, err := t.File(filename).ReadString()
	t.c.Assert(err, check.IsNil)
	actualLines := strings.Split(content, "\n")
	actualLines = actualLines[:len(actualLines)-1]
	t.CheckDeepEquals(emptyToNil(actualLines), emptyToNil(lines))
}

// CheckFileLinesDetab loads the lines from the temporary file and checks
// that they equal the given lines. The loaded file may use tabs or spaces
// for indentation, while the lines in the code use spaces exclusively,
// in order to make the depth of the indentation clearly visible in the test code.
func (t *Tester) CheckFileLinesDetab(filename RelPath, lines ...string) {
	actualLines := Load(t.File(filename), MustSucceed)

	var detabbedLines []string
	for _, line := range actualLines.Lines {
		detabbedLines = append(detabbedLines, detab(line.Text))
	}

	t.CheckDeepEquals(detabbedLines, lines)
}

// CheckDotColumns verifies that each appearance of "..34" is indeed
// right-aligned at column 34, taking tabs into account.
// Columns are zero-based.
func (t *Tester) CheckDotColumns(lines ...string) {
	for index, line := range lines {
		ms := regcomp(`\.\.(\d+)`).FindAllStringSubmatchIndex(line, -1)
		for _, m := range ms {
			prefix := line[:m[1]]
			width := tabWidth(prefix)
			num, err := strconv.Atoi(line[m[2]:m[3]])
			assertNil(err, "")
			t.CheckEqualsf(num, width,
				"The dots in lines[%d] are wrong.", index)
		}
	}
}

// Use marks all passed functions as used for the Go compiler.
//
// This means that the test cases that follow do not have to use each of them,
// and this in turn allows uninteresting test cases to be deleted during
// development.
func (t *Tester) Use(...interface{}) {}

// Shquote renders the given paths into the message, adding shell quoting
// around the paths if necessary.
//
// It is typically used to check the advertisement lines at the very end
// of the pkglint output. ("Run \"pkglint -e %s\" to show explanations.")
func (t *Tester) Shquote(format string, rels ...RelPath) string {
	var subs []interface{}
	for _, rel := range rels {
		quoted := shquote(t.tmpdir.JoinClean(rel).String())
		subs = append(subs, strings.Replace(quoted, t.tmpdir.String(), "~", -1))
	}
	return sprintf(format, subs...)
}

func (t *Tester) ReportUncheckedOutput() {
	out := t.Output()
	if out == "" {
		return
	}

	var msg strings.Builder
	msg.WriteString("\n")
	_, _ = fmt.Fprintf(&msg, "Unchecked output in %s; check with:\n", t.testName)
	msg.WriteString("\n")
	msg.WriteString("t.CheckOutputLines(\n")
	lines := strings.Split(strings.TrimSpace(out), "\n")
	for i, line := range lines {
		_, _ = fmt.Fprintf(&msg, "\t%q%s\n", line, condStr(i == len(lines)-1, ")", ","))
	}
	_, _ = fmt.Fprintf(&msg, "\n")
	_, _ = os.Stderr.WriteString(msg.String())
}

// SplitStringsBool unpacks the given varargs into a string slice and a bool.
func (t *Tester) SplitStringsBool(data []interface{}) ([]string, bool) {
	var strs []string
	for _, text := range data[:len(data)-1] {
		strs = append(strs, text.(string))
	}
	return strs, data[len(data)-1].(bool)
}
