package pkglint

import (
	"bytes"
	"fmt"
	"io"
	"io/ioutil"
	"netbsd.org/pkglint/regex"
	"os"
	"path"
	"path/filepath"
	"regexp"
	"strings"
	"testing"

	"gopkg.in/check.v1"
)

var equals = check.Equals
var deepEquals = check.DeepEquals

const RcsID = "$" + "NetBSD$"
const MkRcsID = "# $" + "NetBSD$"
const PlistRcsID = "@comment $" + "NetBSD$"

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

	G = NewPkglint()
	G.Testing = true
	G.Logger.out = NewSeparatorWriter(&t.stdout)
	G.Logger.err = NewSeparatorWriter(&t.stderr)
	trace.Out = &t.stdout

	// XXX: Maybe the tests can run a bit faster when they don't
	// create a temporary directory each.
	G.Pkgsrc = NewPkgsrc(t.File("."))

	t.c = c
	t.SetUpCommandLine("-Wall") // To catch duplicate warnings
	t.c = nil

	// To improve code coverage and ensure that trace.Result works
	// in all cases. The latter cannot be ensured at compile time.
	t.EnableSilentTracing()

	prevdir, err := os.Getwd()
	if err != nil {
		c.Fatalf("Cannot get current working directory: %s", err)
	}
	t.prevdir = prevdir
}

func (s *Suite) TearDownTest(c *check.C) {
	t := s.Tester
	t.c = nil // No longer usable; see https://github.com/go-check/check/issues/22

	if err := os.Chdir(t.prevdir); err != nil {
		t.Errorf("Cannot chdir back to previous dir: %s", err)
	}

	if t.seenSetupPkgsrc > 0 && !t.seenFinish && !t.seenMain {
		t.Errorf("After t.SetupPkgsrc(), t.FinishSetUp() or t.Main() must be called.")
	}

	if out := t.Output(); out != "" {
		var msg strings.Builder
		msg.WriteString("\n")
		_, _ = fmt.Fprintf(&msg, "Unchecked output in %s; check with:\n", c.TestName())
		msg.WriteString("\n")
		msg.WriteString("t.CheckOutputLines(\n")
		lines := strings.Split(strings.TrimSpace(out), "\n")
		for i, line := range lines {
			_, _ = fmt.Fprintf(&msg, "\t%q%s\n", line, ifelseStr(i == len(lines)-1, ")", ","))
		}
		_, _ = fmt.Fprintf(&msg, "\n")
		_, _ = os.Stderr.WriteString(msg.String())
	}

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

	stdout  bytes.Buffer
	stderr  bytes.Buffer
	tmpdir  string
	prevdir string // The current working directory before the test started
	relCwd  string // See Tester.Chdir

	seenSetupPkgsrc int
	seenFinish      bool
	seenMain        bool
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

	exitcode := G.ParseCommandLine(append([]string{"pkglint"}, args...))
	if exitcode != -1 && exitcode != 0 {
		t.CheckOutputEmpty()
		t.c.Fatalf("Cannot parse command line: %#v", args)
	}

	// Duplicate diagnostics often mean that the checking code is run
	// twice, which is unnecessary.
	//
	// It also reveals diagnostics that are logged multiple times per
	// line and thus can easily get annoying to the pkgsrc developers.
	G.Logger.Opts.LogVerbose = true
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
	if !G.Pkgsrc.vartypes.DefinedExact(varname) {
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
func (t *Tester) SetUpFileLines(relativeFileName string, lines ...string) Lines {
	filename := t.CreateFileLines(relativeFileName, lines...)
	return Load(filename, MustSucceed)
}

// SetUpFileLines creates a temporary file and writes the given lines to it.
// The file is then read in, handling line continuations for Makefiles.
//
// See SetUpFileLines for loading an ordinary file.
func (t *Tester) SetUpFileMkLines(relativeFileName string, lines ...string) MkLines {
	filename := t.CreateFileLines(relativeFileName, lines...)
	return LoadMk(filename, MustSucceed)
}

// LoadMkInclude loads the given Makefile fragment and all the files it includes,
// merging all the lines into a single MkLines object.
//
// This is useful for testing code related to Package.readMakefile.
func (t *Tester) LoadMkInclude(relativeFileName string) MkLines {
	var lines []Line

	// TODO: Include files with multiple-inclusion guard only once.
	// TODO: Include files without multiple-inclusion guard as often as needed.
	// TODO: Set an upper limit, to prevent denial of service.

	var load func(filename string)
	load = func(filename string) {
		for _, mkline := range NewMkLines(Load(filename, MustSucceed)).mklines {
			lines = append(lines, mkline.Line)

			if mkline.IsInclude() {
				included := cleanpath(path.Dir(filename) + "/" + mkline.IncludedFile())
				load(included)
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
//
// If the test works on a lower level than Pkglint.Main,
// LoadInfrastructure must be called to actually load the infrastructure files.
func (t *Tester) SetUpPkgsrc() {

	// This file is needed to locate the pkgsrc root directory.
	// See findPkgsrcTopdir.
	t.CreateFileLines("mk/bsd.pkg.mk",
		MkRcsID)

	// See Pkgsrc.loadDocChanges.
	t.CreateFileLines("doc/CHANGES-2018",
		RcsID)

	// See Pkgsrc.loadSuggestedUpdates.
	t.CreateFileLines("doc/TODO",
		RcsID)

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
		MkRcsID)

	// The options for the PKG_OPTIONS framework are defined here.
	//
	// See Pkgsrc.loadPkgOptions.
	t.CreateFileLines("mk/defaults/options.description",
		"example-option   Description for the example option",
		"example-option-without-description")

	// The user-defined variables are read in to check for missing
	// BUILD_DEFS declarations in the package Makefile.
	t.CreateFileLines("mk/defaults/mk.conf",
		MkRcsID)

	// The tool definitions are defined in various files in mk/tools/.
	// The relevant files are listed in bsd.tools.mk.
	// The tools that are defined here can be used in USE_TOOLS.
	t.CreateFileLines("mk/tools/bsd.tools.mk",
		".include \"defaults.mk\"")
	t.CreateFileLines("mk/tools/defaults.mk",
		MkRcsID)

	// Those tools that are added to USE_TOOLS in bsd.prefs.mk may be
	// used at load time by packages.
	t.CreateFileLines("mk/bsd.prefs.mk",
		MkRcsID)
	t.CreateFileLines("mk/bsd.fast.prefs.mk",
		MkRcsID)

	// Category Makefiles require this file for the common definitions.
	t.CreateFileLines("mk/misc/category.mk")

	t.seenSetupPkgsrc++
}

// SetUpCategory makes the given category valid by creating a dummy Makefile.
// After that, it can be mentioned in the CATEGORIES variable of a package.
func (t *Tester) SetUpCategory(name string) {
	assertf(!contains(name, "/"), "Category must not contain a slash.")

	if _, err := os.Stat(t.File(name + "/Makefile")); os.IsNotExist(err) {
		t.CreateFileLines(name+"/Makefile",
			MkRcsID)
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
func (t *Tester) SetUpPackage(pkgpath string, makefileLines ...string) string {

	category := path.Dir(pkgpath)
	if category == "wip" {
		// To avoid boilerplate CATEGORIES definitions for wip packages.
		category = "local"
	}

	t.SetUpPkgsrc()
	t.SetUpCategory(category)

	t.CreateFileLines(pkgpath+"/DESCR",
		"Package description")
	t.CreateFileLines(pkgpath+"/PLIST",
		PlistRcsID,
		"bin/program")

	// Because the package Makefile includes this file, the check for the
	// correct ordering of variables is skipped. As of February 2019, the
	// SetupPackage function does not insert the custom variables in the
	// correct position. To prevent the tests from having to mention the
	// unrelated warnings about the variable order, that check is suppressed
	// here.
	t.CreateFileLines(pkgpath+"/suppress-varorder.mk",
		MkRcsID)

	// This distinfo file contains dummy hashes since pkglint cannot check the
	// distfiles hashes anyway. It can only check the hashes for the patches.
	t.CreateFileLines(pkgpath+"/distinfo",
		RcsID,
		"",
		"SHA1 (distfile-1.0.tar.gz) = 12341234",
		"RMD160 (distfile-1.0.tar.gz) = 12341234",
		"SHA512 (distfile-1.0.tar.gz) = 12341234",
		"Size (distfile-1.0.tar.gz) = 12341234")

	mlines := []string{
		MkRcsID,
		"",
		"DISTNAME=\tdistname-1.0",
		"#PKGNAME=\tpackage-1.0",
		"CATEGORIES=\t" + category,
		"MASTER_SITES=\t# none",
		"",
		"MAINTAINER=\tpkgsrc-users@NetBSD.org",
		"HOMEPAGE=\t# none",
		"COMMENT=\tDummy package",
		"LICENSE=\t2-clause-bsd",
		"",
		".include \"suppress-varorder.mk\""}
	for len(mlines) < 19 {
		mlines = append(mlines, "# empty")
	}

line:
	for _, line := range makefileLines {
		if m, prefix := match1(line, `^#?(\w+=)`); m {
			for i, existingLine := range mlines[:19] {
				if hasPrefix(strings.TrimPrefix(existingLine, "#"), prefix) {
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

	t.CreateFileLines(pkgpath+"/Makefile",
		mlines...)

	return t.File(pkgpath)
}

// CreateFileLines creates a file in the temporary directory and writes the
// given lines to it.
//
// It returns the full path to the created file.
func (t *Tester) CreateFileLines(relativeFileName string, lines ...string) (filename string) {
	var content bytes.Buffer
	for _, line := range lines {
		content.WriteString(line)
		content.WriteString("\n")
	}

	filename = t.File(relativeFileName)
	err := os.MkdirAll(path.Dir(filename), 0777)
	t.c.Assert(err, check.IsNil)

	err = ioutil.WriteFile(filename, []byte(content.Bytes()), 0666)
	t.c.Assert(err, check.IsNil)

	G.fileCache.Evict(filename)

	return filename
}

// CreateFileDummyPatch creates a patch file with the given name in the
// temporary directory.
func (t *Tester) CreateFileDummyPatch(relativeFileName string) {
	t.CreateFileLines(relativeFileName,
		RcsID,
		"",
		"Documentation",
		"",
		"--- oldfile",
		"+++ newfile",
		"@@ -1 +1 @@",
		"-old",
		"+new")
}

func (t *Tester) CreateFileDummyBuildlink3(relativeFileName string, customLines ...string) {
	dir := path.Dir(relativeFileName)
	lower := path.Base(dir)
	upper := strings.ToUpper(lower)

	width := tabWidth(sprintf("BUILDLINK_API_DEPENDS.%s+=\t", lower))

	aligned := func(format string, args ...interface{}) string {
		msg := sprintf(format, args...)
		for tabWidth(msg) < width {
			msg += "\t"
		}
		return msg
	}

	var lines []string
	lines = append(lines,
		MkRcsID,
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
func (t *Tester) File(relativeFileName string) string {
	if t.tmpdir == "" {
		t.tmpdir = filepath.ToSlash(t.c.MkDir())
	}
	if t.relCwd != "" {
		return path.Clean(relativeFileName)
	}
	return path.Clean(t.tmpdir + "/" + relativeFileName)
}

// Copy copies a file inside the temporary directory.
func (t *Tester) Copy(relativeSrc, relativeDst string) {
	data, err := ioutil.ReadFile(t.File(relativeSrc))
	assertNil(err, "Copy.Read")
	err = ioutil.WriteFile(t.File(relativeDst), data, 0777)
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
func (t *Tester) Chdir(relativeDirName string) {
	if t.relCwd != "" {
		// When multiple calls of Chdir are mixed with calls to CreateFileLines,
		// the resulting Lines and MkLines variables will use relative filenames,
		// and these will point to different areas in the file system. This is
		// usually not indented and therefore prevented.
		t.c.Fatalf("Chdir must only be called once per test; already in %q.", t.relCwd)
	}

	absDirName := t.File(relativeDirName)
	_ = os.MkdirAll(absDirName, 0700)
	if err := os.Chdir(absDirName); err != nil {
		t.c.Fatalf("Cannot chdir: %s", err)
	}
	t.relCwd = relativeDirName
	G.cwd = absDirName
}

// Remove removes the file from the temporary directory. The file must exist.
func (t *Tester) Remove(relativeFileName string) {
	filename := t.File(relativeFileName)
	err := os.Remove(filename)
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
	include func(filename string, args ...interface{}) MkLines,
	get func(string) MkLines) {

	files := map[string]MkLines{}

	include = func(filename string, args ...interface{}) MkLines {
		var lines []Line
		lineno := 1

		addLine := func(text string) {
			lines = append(lines, t.NewLine(filename, lineno, text))
			lineno++
		}

		for _, arg := range args {
			switch arg := arg.(type) {
			case string:
				addLine(arg)
			case MkLines:
				text := sprintf(".include %q", relpath(path.Dir(filename), arg.lines.FileName))
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

	get = func(filename string) MkLines {
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

	mklines.ForEach(func(mkline MkLine) { mkline.Notef("Text is: %s", mkline.Text) })

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
		t.Errorf("Unnecessary t.FinishSetUp() since t.SetUpPkgsrc() has not been called.")
	}

	if !t.seenFinish {
		t.seenFinish = true
		G.Pkgsrc.LoadInfrastructure()
	} else {
		t.Errorf("Redundant t.FinishSetup() since it was called multiple times.")
	}
}

// Main runs the pkglint main program with the given command line arguments.
//
// Arguments that name existing files or directories in the temporary test
// directory are transformed to their actual paths.
func (t *Tester) Main(args ...string) int {
	if t.seenFinish && !t.seenMain {
		t.Errorf("Calling t.FinishSetup() before t.Main() is redundant " +
			"since t.Main() loads the pkgsrc infrastructure.")
	}

	t.seenMain = true

	// Reset the logger, for tests where t.Main is called multiple times.
	G.Logger.errors = 0
	G.Logger.warnings = 0
	G.Logger.logged = Once{}

	argv := []string{"pkglint"}
	for _, arg := range args {
		fileArg := t.File(arg)
		_, err := os.Lstat(fileArg)
		if err == nil {
			argv = append(argv, fileArg)
		} else {
			argv = append(argv, arg)
		}
	}

	return G.Main(argv...)
}

// Check delegates a check to the check.Check function.
// Thereby, there is no need to distinguish between c.Check and t.Check
// in the test code.
func (t *Tester) Check(obj interface{}, checker check.Checker, args ...interface{}) bool {
	return t.c.Check(obj, checker, args...)
}

func (t *Tester) Errorf(format string, args ...interface{}) {
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
// Pkglint.Assertf or uses some other way to panic.
//
// Usage:
//  t.ExpectPanic(
//      func() { /* do something that panics */ },
//      "FATAL: ~/Makefile:1: Must not be empty")
func (t *Tester) ExpectPanic(action func(), expectedMessage string) {
	t.Check(action, check.Panics, expectedMessage)
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
func (t *Tester) NewLine(filename string, lineno int, text string) Line {
	textnl := text + "\n"
	rawLine := RawLine{lineno, textnl, textnl}
	return NewLine(filename, lineno, text, &rawLine)
}

// NewMkLine creates an in-memory line in the Makefile format with the given text.
func (t *Tester) NewMkLine(filename string, lineno int, text string) MkLine {
	basename := path.Base(filename)
	assertf(
		hasSuffix(basename, ".mk") ||
			basename == "Makefile" ||
			hasPrefix(basename, "Makefile.") ||
			basename == "mk.conf",
		"filename %q must be realistic, otherwise the variable permissions are wrong", filename)

	return MkLineParser{}.Parse(t.NewLine(filename, lineno, text))
}

func (t *Tester) NewShellLineChecker(text string) *ShellLineChecker {
	mklines := t.NewMkLines("filename.mk", text)
	return NewShellLineChecker(mklines, mklines.mklines[0])
}

// NewLines returns a list of simple lines that belong together.
//
// To work with line continuations like in Makefiles, use SetUpFileMkLines.
func (t *Tester) NewLines(filename string, lines ...string) Lines {
	return t.NewLinesAt(filename, 1, lines...)
}

// NewLinesAt returns a list of simple lines that belong together.
//
// To work with line continuations like in Makefiles, use SetUpFileMkLines.
func (t *Tester) NewLinesAt(filename string, firstLine int, texts ...string) Lines {
	lines := make([]Line, len(texts))
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
func (t *Tester) NewMkLines(filename string, lines ...string) MkLines {
	basename := path.Base(filename)
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
	if G.usable() {
		G.Logger.logged = Once{}
		if G.Logger.out != nil { // Necessary because Main resets the G variable.
			G.Logger.out.state = 0 // Prevent an empty line at the beginning of the next output.
			G.Logger.err.state = 0
		}
	}

	assertf(t.tmpdir != "", "Tester must be initialized before checking the output.")
	return strings.Replace(stdout+stderr, t.tmpdir, "~", -1)
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
	t.Check(actual, deepEquals, expected)
}

func (t *Tester) compareOutputIgnoreSpace(rawOutput string, expectedLines []string, tmpdir string) ([]string, []string) {
	whitespace := regexp.MustCompile(`\s+`)

	// Replace all occurrences of tmpdir in the raw output with a tilde,
	// also covering cases where tmpdir is wrapped into multiple lines.
	output := func() string {
		var tmpdirPattern strings.Builder
		for i, part := range whitespace.Split(tmpdir, -1) {
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
	test := func(rawOutput string, expectedLines []string, tmpdir string, eq bool) {
		actual, expected := t.compareOutputIgnoreSpace(rawOutput, expectedLines, tmpdir)
		t.Check(actual == nil && expected == nil, equals, eq)
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
		if err != nil {
			return false
		}

		return re.MatchString(actualLine)
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

	t.Check(emptyToNil(actualLines), deepEquals, emptyToNil(patterns))
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
	t.Check(emptyToNil(actualLines), deepEquals, emptyToNil(expectedLines))
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
	if G.usable() {
		G.Logger.out = NewSeparatorWriter(&t.stdout)
	}
	trace.Tracing = false
	trace.Out = nil
}

// CheckFileLines loads the lines from the temporary file and checks that
// they equal the given lines.
func (t *Tester) CheckFileLines(relativeFileName string, lines ...string) {
	content, err := ioutil.ReadFile(t.File(relativeFileName))
	t.c.Assert(err, check.IsNil)
	actualLines := strings.Split(string(content), "\n")
	actualLines = actualLines[:len(actualLines)-1]
	t.Check(emptyToNil(actualLines), deepEquals, emptyToNil(lines))
}

// CheckFileLinesDetab loads the lines from the temporary file and checks
// that they equal the given lines. The loaded file may use tabs or spaces
// for indentation, while the lines in the code use spaces exclusively,
// in order to make the depth of the indentation clearly visible in the test code.
func (t *Tester) CheckFileLinesDetab(relativeFileName string, lines ...string) {
	actualLines := Load(t.File(relativeFileName), MustSucceed)

	var detabbedLines []string
	for _, line := range actualLines.Lines {
		detabbedLines = append(detabbedLines, detab(line.Text))
	}

	t.Check(detabbedLines, deepEquals, lines)
}

// Use marks all passed functions as used for the Go compiler.
//
// This means that the test cases that follow do not have to use each of them,
// and this in turn allows uninteresting test cases to be deleted during
// development.
func (t *Tester) Use(functions ...interface{}) {
}
