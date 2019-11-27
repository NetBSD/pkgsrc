package pkglint

import (
	"bytes"
	"fmt"
	"io"
	"io/ioutil"
	"netbsd.org/pkglint/regex"
	"os"
	"regexp"
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

	// XXX: Maybe the tests can run a bit faster when they don't
	// create a temporary directory each.
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
	t.prevdir = prevdir

	// No longer usable; see https://github.com/go-check/check/issues/22
	t.c = nil
}

func (s *Suite) TearDownTest(c *check.C) {
	t := s.Tester
	t.c = nil // No longer usable; see https://github.com/go-check/check/issues/22

	err := os.Chdir(t.prevdir)
	assertNil(err, "Cannot chdir back to previous dir: %s", err)

	if t.seenSetupPkgsrc > 0 && !t.seenFinish && !t.seenMain {
		t.InternalErrorf("After t.SetupPkgsrc(), either t.FinishSetUp() or t.Main() must be called.")
	}

	t.ReportUncheckedOutput()
	t.tmpdir = ""
	t.DisableTracing()

	G = unusablePkglint()
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
	tmpdir  Path
	prevdir string // The current working directory before the test started
	relCwd  Path   // See Tester.Chdir

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
		G.Pkgsrc.vartypes.DefineParse(varname, BtFetchURL,
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

// SetUpFileLines creates a temporary file and writes the given lines to it.
// The file is then read in, without interpreting line continuations.
//
// See SetUpFileMkLines for loading a Makefile fragment.
func (t *Tester) SetUpFileLines(relativeFileName Path, lines ...string) *Lines {
	filename := t.CreateFileLines(relativeFileName, lines...)
	return Load(filename, MustSucceed)
}

// SetUpFileLines creates a temporary file and writes the given lines to it.
// The file is then read in, handling line continuations for Makefiles.
//
// See SetUpFileLines for loading an ordinary file.
func (t *Tester) SetUpFileMkLines(relativeFileName Path, lines ...string) *MkLines {
	filename := t.CreateFileLines(relativeFileName, lines...)
	return LoadMk(filename, MustSucceed)
}

// LoadMkInclude loads the given Makefile fragment and all the files it includes,
// merging all the lines into a single MkLines object.
//
// This is useful for testing code related to Package.readMakefile.
func (t *Tester) LoadMkInclude(relativeFileName Path) *MkLines {
	var lines []*Line

	// TODO: Include files with multiple-inclusion guard only once.
	// TODO: Include files without multiple-inclusion guard as often as needed.
	// TODO: Set an upper limit, to prevent denial of service.

	var load func(filename Path)
	load = func(filename Path) {
		for _, mkline := range NewMkLines(Load(filename, MustSucceed)).mklines {
			lines = append(lines, mkline.Line)

			if mkline.IsInclude() {
				load(mkline.IncludedFileFull())
			}
		}
	}

	load(t.File(relativeFileName))

	// This assumes that the test files do not contain parse errors.
	// Otherwise the diagnostics would appear twice.
	return NewMkLines(NewLines(t.File(relativeFileName), lines))
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

	t.seenSetupPkgsrc++
}

// SetUpCategory makes the given category valid by creating a dummy Makefile.
// After that, it can be mentioned in the CATEGORIES variable of a package.
func (t *Tester) SetUpCategory(name Path) {
	assert(name.Count() == 1)

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
func (t *Tester) SetUpPackage(pkgpath Path, makefileLines ...string) Path {
	assertf(matches(pkgpath.String(), `^[^/]+/[^/]+$`), "pkgpath %q must have the form \"category/package\"", pkgpath)

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
		"DISTNAME=\t" + distname + "-1.0",
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
func (t *Tester) CreateFileLines(relativeFileName Path, lines ...string) (filename Path) {
	var content strings.Builder
	for _, line := range lines {
		content.WriteString(line)
		content.WriteString("\n")
	}

	filename = t.File(relativeFileName)
	err := os.MkdirAll(filename.Dir().String(), 0777)
	t.c.Assert(err, check.IsNil)

	err = filename.WriteString(content.String())
	t.c.Assert(err, check.IsNil)

	G.fileCache.Evict(filename)

	return filename
}

// CreateFileDummyPatch creates a patch file with the given name in the
// temporary directory.
func (t *Tester) CreateFileDummyPatch(relativeFileName Path) {
	t.CreateFileLines(relativeFileName,
		CvsID,
		"",
		"Documentation",
		"",
		"--- oldfile",
		"+++ newfile",
		"@@ -1 +1 @@",
		"-old",
		"+new")
}

func (t *Tester) CreateFileDummyBuildlink3(relativeFileName Path, customLines ...string) {
	assert(relativeFileName.Count() == 3)
	dir := relativeFileName.Dir()
	lower := dir.Base()
	// see pkgtools/createbuildlink/files/createbuildlink, "package specific variables"
	upper := strings.Replace(strings.ToUpper(lower), "-", "_", -1)

	width := tabWidthSlice("BUILDLINK_API_DEPENDS.", lower, "+=\t")

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
		sprintf("BUILDLINK_TREE+=\t%s", lower),
		"",
		sprintf(".if !defined(%s_BUILDLINK3_MK)", upper),
		sprintf("%s_BUILDLINK3_MK:=", upper),
		"",
		aligned("BUILDLINK_API_DEPENDS.%s+=", lower)+sprintf("%s>=0", lower),
		aligned("BUILDLINK_PKGSRCDIR.%s?=", lower)+sprintf("../../%s", dir),
		aligned("BUILDLINK_DEPMETHOD.%s?=", lower)+"build",
		"")
	lines = append(lines, customLines...)
	lines = append(lines,
		"",
		sprintf(".endif # %s_BUILDLINK3_MK", upper),
		"",
		sprintf("BUILDLINK_TREE+=\t-%s", lower))

	t.CreateFileLines(relativeFileName, lines...)
}

// File returns the absolute path to the given file in the
// temporary directory. It doesn't check whether that file exists.
// Calls to Tester.Chdir change the base directory for the relative filename.
func (t *Tester) File(relativeFileName Path) Path {
	if t.tmpdir == "" {
		t.tmpdir = NewPathSlash(t.c.MkDir())
	}
	if t.relCwd != "" {
		return relativeFileName.Clean()
	}
	return t.tmpdir.JoinClean(relativeFileName)
}

// Copy copies a file inside the temporary directory.
func (t *Tester) Copy(relativeSrc, relativeDst Path) {
	src := t.File(relativeSrc)
	dst := t.File(relativeDst)

	data, err := src.ReadString()
	assertNil(err, "Copy.Read")
	err = os.MkdirAll(dst.Dir().String(), 0777)
	assertNil(err, "Copy.MkdirAll")
	err = dst.WriteString(data)
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
func (t *Tester) Chdir(relativeDirName Path) {
	if t.relCwd != "" {
		// When multiple calls of Chdir are mixed with calls to CreateFileLines,
		// the resulting Lines and MkLines variables will use relative filenames,
		// and these will point to different areas in the file system. This is
		// usually not indented and therefore prevented.
		t.c.Fatalf("Chdir must only be called once per test; already in %q.", t.relCwd)
	}

	absDirName := t.File(relativeDirName)
	assertNil(os.MkdirAll(absDirName.String(), 0700), "MkDirAll")
	assertNil(os.Chdir(absDirName.String()), "Chdir")
	t.relCwd = relativeDirName
	G.cwd = absDirName
}

// Remove removes the file or directory from the temporary directory.
// The file or directory must exist.
func (t *Tester) Remove(relativeFileName Path) {
	filename := t.File(relativeFileName)
	err := os.Remove(filename.String())
	t.c.Assert(err, check.IsNil)
	G.fileCache.Evict(filename)
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
// same location, but that location is irrelevant in practice. The generated
// .include lines take the relative paths into account. For example, when
// subdir/module.mk includes subdir/version.mk, the include line is just:
//  .include "version.mk"
func (t *Tester) SetUpHierarchy() (
	include func(filename Path, args ...interface{}) *MkLines,
	get func(Path) *MkLines) {

	files := map[Path]*MkLines{}

	include = func(filename Path, args ...interface{}) *MkLines {
		var lines []*Line
		lineno := 1

		addLine := func(text string) {
			lines = append(lines, t.NewLine(filename, lineno, text))
			lineno++
		}

		for _, arg := range args {
			switch arg := arg.(type) {
			case string:
				addLine(arg)
			case *MkLines:
				fromDir := G.Pkgsrc.File(filename.Dir())
				to := G.Pkgsrc.File(arg.lines.Filename)
				rel := G.Pkgsrc.Relpath(fromDir, to)
				text := sprintf(".include %q", rel)
				addLine(text)
				lines = append(lines, arg.lines.Lines...)
			default:
				panic("invalid type")
			}
		}

		mklines := NewMkLines(NewLines(filename, lines))
		assertf(files[filename] == nil, "MkLines with name %q already exists.", filename)
		files[filename] = mklines
		return mklines
	}

	get = func(filename Path) *MkLines {
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
		fileArg := t.File(NewPath(arg))
		if fileArg.Exists() {
			argv = append(argv, fileArg.String())
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

func (t *Tester) CheckDeepEquals(actual interface{}, expected interface{}) bool {
	return t.c.Check(actual, check.DeepEquals, expected)
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
func (t *Tester) ExpectPanicMatches(action func(), expectedMessage string) {
	t.Check(action, check.PanicMatches, expectedMessage)
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
func (t *Tester) ExpectDiagnosticsAutofix(action func(), diagnostics ...string) {
	t.SetUpCommandLine("-Wall")
	action()

	t.SetUpCommandLine("-Wall", "--autofix")
	action()

	t.CheckOutput(diagnostics)
}

// NewRawLines creates lines from line numbers and raw text, including newlines.
//
// Arguments are sequences of either (lineno, orignl) or (lineno, orignl, textnl).
//
// Specifying textnl is only useful when simulating a line that has already been
// modified by Autofix.
func (t *Tester) NewRawLines(args ...interface{}) []*RawLine {
	rawlines := make([]*RawLine, len(args)/2)
	j := 0
	for i := 0; i < len(args); i += 2 {
		lineno := args[i].(int)
		orignl := args[i+1].(string)
		textnl := orignl
		if i+2 < len(args) {
			if s, ok := args[i+2].(string); ok {
				textnl = s
				i++
			}
		}
		rawlines[j] = &RawLine{lineno, orignl, textnl}
		j++
	}
	return rawlines[:j]
}

// NewLine creates an in-memory line with the given text.
// This line does not correspond to any line in a file.
func (t *Tester) NewLine(filename Path, lineno int, text string) *Line {
	textnl := text + "\n"
	rawLine := RawLine{lineno, textnl, textnl}
	return NewLine(filename, lineno, text, &rawLine)
}

// NewMkLine creates an in-memory line in the Makefile format with the given text.
func (t *Tester) NewMkLine(filename Path, lineno int, text string) *MkLine {
	basename := filename.Base()
	assertf(
		hasSuffix(basename, ".mk") ||
			basename == "Makefile" ||
			hasPrefix(basename, "Makefile.") ||
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
func (t *Tester) NewLines(filename Path, lines ...string) *Lines {
	return t.NewLinesAt(filename, 1, lines...)
}

// NewLinesAt returns a list of simple lines that belong together.
//
// To work with line continuations like in Makefiles, use SetUpFileMkLines.
func (t *Tester) NewLinesAt(filename Path, firstLine int, texts ...string) *Lines {
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
func (t *Tester) NewMkLines(filename Path, lines ...string) *MkLines {
	basename := filename.Base()
	assertf(
		hasSuffix(basename, ".mk") || basename == "Makefile" || hasPrefix(basename, "Makefile."),
		"filename %q must be realistic, otherwise the variable permissions are wrong", filename)

	var rawText strings.Builder
	for _, line := range lines {
		rawText.WriteString(line)
		rawText.WriteString("\n")
	}
	return NewMkLines(convertToLogicalLines(filename, rawText.String(), true))
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
	actualLines = append(actualLines)
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
	assertf(t.tmpdir != "", "Tester must be initialized before checking the output.")

	rawOutput := t.stdout.String() + t.stderr.String()
	_ = t.Output() // Just to consume the output

	actual, expected := t.compareOutputIgnoreSpace(rawOutput, expectedLines, t.tmpdir)
	t.CheckDeepEquals(actual, expected)
}

func (t *Tester) compareOutputIgnoreSpace(rawOutput string, expectedLines []string, tmpdir Path) ([]string, []string) {
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
	test := func(rawOutput string, expectedLines []string, tmpdir Path, eq bool) {
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
func (t *Tester) CheckFileLines(relativeFileName Path, lines ...string) {
	content, err := t.File(relativeFileName).ReadString()
	t.c.Assert(err, check.IsNil)
	actualLines := strings.Split(content, "\n")
	actualLines = actualLines[:len(actualLines)-1]
	t.CheckDeepEquals(emptyToNil(actualLines), emptyToNil(lines))
}

// CheckFileLinesDetab loads the lines from the temporary file and checks
// that they equal the given lines. The loaded file may use tabs or spaces
// for indentation, while the lines in the code use spaces exclusively,
// in order to make the depth of the indentation clearly visible in the test code.
func (t *Tester) CheckFileLinesDetab(relativeFileName Path, lines ...string) {
	actualLines := Load(t.File(relativeFileName), MustSucceed)

	var detabbedLines []string
	for _, line := range actualLines.Lines {
		detabbedLines = append(detabbedLines, detab(line.Text))
	}

	t.CheckDeepEquals(detabbedLines, lines)
}

// Use marks all passed functions as used for the Go compiler.
//
// This means that the test cases that follow do not have to use each of them,
// and this in turn allows uninteresting test cases to be deleted during
// development.
func (t *Tester) Use(...interface{}) {}

func (t *Tester) Shquote(format string, rels ...Path) string {
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
