package main

import (
	"bytes"
	"fmt"
	"io"
	"io/ioutil"
	"netbsd.org/pkglint/regex"
	"os"
	"path"
	"path/filepath"
	"strings"
	"testing"

	"gopkg.in/check.v1"
	"netbsd.org/pkglint/textproc"
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
// CreateFileLines, SetupPkgsrc, SetupPackage
//
// * load these files into Line and MkLine objects (for tests spanning multiple files):
// SetupFileLines, SetupFileMkLines
//
// * create new in-memory Line and MkLine objects (for simple tests):
// NewLine, NewLines, NewMkLine, NewMkLines
//
// * check the files that have been changed by the --autofix feature:
// CheckFileLines
//
// * check the pkglint diagnostics: CheckLinesEmpty, CheckLinesOutput
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
	t := &Tester{c: c}
	s.Tester = t

	G = NewPkglint()
	G.Testing = true
	textproc.Testing = true
	G.logOut = NewSeparatorWriter(&t.stdout)
	G.logErr = NewSeparatorWriter(&t.stderr)
	trace.Out = &t.stdout

	// XXX: Maybe the tests can run a bit faster when they don't
	// create a temporary directory each.
	G.Pkgsrc = NewPkgsrc(t.File("."))

	t.c = c
	t.SetupCommandLine("-Wall") // To catch duplicate warnings
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
		_, _ = fmt.Fprintf(os.Stderr, "Cannot chdir back to previous dir: %s", err)
	}

	G = Pkglint{} // unusable because of missing logOut and logErr
	textproc.Testing = false
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
}

var _ = check.Suite(new(Suite))

func Test(t *testing.T) { check.TestingT(t) }

// Tester provides utility methods for testing pkglint.
// It is separated from the Suite since the latter contains
// all the test methods, which makes it difficult to find
// a method by auto-completion.
type Tester struct {
	stdout  bytes.Buffer
	stderr  bytes.Buffer
	tmpdir  string
	c       *check.C // Only usable during the test method itself
	prevdir string   // The current working directory before the test started
	relCwd  string   // See Tester.Chdir
}

// SetupCommandLine simulates a command line for the remainder of the test.
// See Pkglint.ParseCommandLine.
//
// If SetupCommandLine is not called explicitly in a test, the command line
// "-Wall" is used, to provide a high code coverage in the tests.
func (t *Tester) SetupCommandLine(args ...string) {

	// Prevent tracing from being disabled; see EnableSilentTracing.
	prevTracing := trace.Tracing
	defer func() { trace.Tracing = prevTracing }()

	exitcode := G.ParseCommandLine(append([]string{"pkglint"}, args...))
	if exitcode != nil && *exitcode != 0 {
		t.CheckOutputEmpty()
		t.c.Fatalf("Cannot parse command line: %#v", args)
	}

	// Duplicate diagnostics often mean that the checking code is run
	// twice, which is unnecessary.
	//
	// It also reveals diagnostics that are logged multiple times per
	// line and thus can easily get annoying to the pkgsrc developers.
	G.Opts.LogVerbose = true
}

// SetupVartypes registers a few hundred variables like MASTER_SITES,
// WRKSRC, SUBST_SED.*, so that their data types are known to pkglint.
//
// Without calling this, there will be many warnings about undefined
// or unused variables, or unknown shell commands.
//
// See SetupTool for registering tools like echo, awk, perl.
func (t *Tester) SetupVartypes() {
	G.Pkgsrc.InitVartypes()
}

func (t *Tester) SetupMasterSite(varname string, urls ...string) {
	for _, url := range urls {
		G.Pkgsrc.registerMasterSite(varname, url)
	}
}

// SetupOption pretends that the package option is defined in mk/defaults/options.description.
func (t *Tester) SetupOption(name, description string) {
	G.Pkgsrc.PkgOptions[name] = description
}

func (t *Tester) SetupTool(name, varname string, validity Validity) *Tool {
	return G.Pkgsrc.Tools.def(name, varname, false, validity)
}

// SetupFileLines creates a temporary file and writes the given lines to it.
// The file is then read in, without interpreting line continuations.
//
// See SetupFileMkLines for loading a Makefile fragment.
func (t *Tester) SetupFileLines(relativeFileName string, lines ...string) Lines {
	fileName := t.CreateFileLines(relativeFileName, lines...)
	return Load(fileName, MustSucceed)
}

// SetupFileLines creates a temporary file and writes the given lines to it.
// The file is then read in, handling line continuations for Makefiles.
//
// See SetupFileLines for loading an ordinary file.
func (t *Tester) SetupFileMkLines(relativeFileName string, lines ...string) MkLines {
	fileName := t.CreateFileLines(relativeFileName, lines...)
	return LoadMk(fileName, MustSucceed)
}

// SetupPkgsrc sets up a minimal but complete pkgsrc installation in the
// temporary folder, so that pkglint runs without any errors.
// Individual files may be overwritten by calling other Setup* methods.
// This setup is especially interesting for testing Pkglint.Main.
func (t *Tester) SetupPkgsrc() {

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
		"The licenses for most software ...")

	// The various MASTER_SITE_* variables for use in the
	// MASTER_SITES are defined in this file.
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

	// Category Makefiles require this file for the common definitions.
	t.CreateFileLines("mk/misc/category.mk")
}

// SetupCategory makes the given category valid by creating a dummy Makefile.
// After that, it can be mentioned in the CATEGORIES variable of a package.
func (t *Tester) SetupCategory(name string) {
	G.Assertf(!contains(name, "/"), "Category must not contain a slash.")

	if _, err := os.Stat(t.File(name + "/Makefile")); os.IsNotExist(err) {
		t.CreateFileLines(name+"/Makefile",
			MkRcsID)
	}
}

// SetupPackage sets up all files for a package (including the pkgsrc
// infrastructure) so that it does not produce any warnings.
//
// The given makefileLines start in line 20. Except if they are variable
// definitions for already existing variables, then they replace that line.
//
// Returns the path to the package, ready to be used with Pkglint.CheckDirent.
//
// After calling this method, individual files can be overwritten as necessary.
// Then, G.Pkgsrc.LoadInfrastructure should be called to load all the files.
func (t *Tester) SetupPackage(pkgpath string, makefileLines ...string) string {
	category := path.Dir(pkgpath)

	t.SetupPkgsrc()
	t.SetupVartypes()
	t.SetupCategory(category)

	t.CreateFileLines(pkgpath+"/DESCR",
		"Package description")
	t.CreateFileLines(pkgpath+"/PLIST",
		PlistRcsID,
		"bin/program")
	t.CreateFileLines(pkgpath+"/distinfo",
		RcsID,
		"",
		"SHA1 (distfile-1.0.tar.gz) = 12341234...",
		"RMD160 (distfile-1.0.tar.gz) = 12341234...",
		"SHA512 (distfile-1.0.tar.gz) = 12341234...",
		"Size (distfile-1.0.tar.gz) = 12341234")

	mlines := []string{
		MkRcsID,
		"",
		"DISTNAME=\tdistname-1.0",
		"CATEGORIES=\t" + category,
		"MASTER_SITES=\t# none",
		"",
		"MAINTAINER=\tpkgsrc-users@NetBSD.org",
		"HOMEPAGE=\t# none",
		"COMMENT=\tDummy package",
		"LICENSE=\t2-clause-bsd",
		""}
	for len(mlines) < 19 {
		mlines = append(mlines, "# empty")
	}

line:
	for _, line := range makefileLines {
		if m, prefix := match1(line, `^(\w+=)`); m {
			for i, existingLine := range mlines {
				if hasPrefix(existingLine, prefix) {
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
func (t *Tester) CreateFileLines(relativeFileName string, lines ...string) (fileName string) {
	var content bytes.Buffer
	for _, line := range lines {
		content.WriteString(line)
		content.WriteString("\n")
	}

	fileName = t.File(relativeFileName)
	err := os.MkdirAll(path.Dir(fileName), 0777)
	t.c.Assert(err, check.IsNil)

	err = ioutil.WriteFile(fileName, []byte(content.Bytes()), 0666)
	t.c.Assert(err, check.IsNil)

	G.fileCache.Evict(fileName)

	return fileName
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

// File returns the absolute path to the given file in the
// temporary directory. It doesn't check whether that file exists.
// Calls to Tester.Chdir change the base directory for the relative file name.
func (t *Tester) File(relativeFileName string) string {
	if t.tmpdir == "" {
		t.tmpdir = filepath.ToSlash(t.c.MkDir())
	}
	if t.relCwd != "" {
		return path.Clean(relativeFileName)
	}
	return path.Clean(t.tmpdir + "/" + relativeFileName)
}

// Chdir changes the current working directory to the given subdirectory
// of the temporary directory, creating it if necessary.
//
// After this call, all files loaded from the temporary directory via
// SetupFileLines or CreateFileLines or similar methods will use path names
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
		// the resulting Lines and MkLines variables will use relative file names,
		// and these will point to different areas in the file system. This is
		// usually not indented and therefore prevented.
		t.c.Fatalf("Chdir must only be called once per test; already in %q.", t.relCwd)
	}

	_ = os.MkdirAll(t.File(relativeDirName), 0700)
	if err := os.Chdir(t.File(relativeDirName)); err != nil {
		t.c.Fatalf("Cannot chdir: %s", err)
	}
	t.relCwd = relativeDirName
}

// Remove removes the file from the temporary directory. The file must exist.
func (t *Tester) Remove(relativeFileName string) {
	fileName := t.File(relativeFileName)
	err := os.Remove(fileName)
	t.c.Assert(err, check.IsNil)
	G.fileCache.Evict(fileName)
}

// Check delegates a check to the check.Check function.
// Thereby, there is no need to distinguish between c.Check and t.Check
// in the test code.
func (t *Tester) Check(obj interface{}, checker check.Checker, args ...interface{}) bool {
	return t.c.Check(obj, checker, args...)
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
			t.Check(t.Output(), check.Matches, string(expected))
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
func (t *Tester) NewLine(fileName string, lineno int, text string) Line {
	textnl := text + "\n"
	rawLine := RawLine{lineno, textnl, textnl}
	return NewLine(fileName, lineno, text, []*RawLine{&rawLine})
}

// NewMkLine creates an in-memory line in the Makefile format with the given text.
func (t *Tester) NewMkLine(fileName string, lineno int, text string) MkLine {
	return NewMkLine(t.NewLine(fileName, lineno, text))
}

func (t *Tester) NewShellLine(fileName string, lineno int, text string) *ShellLine {
	return NewShellLine(t.NewMkLine(fileName, lineno, text))
}

// NewLines returns a list of simple lines that belong together.
//
// To work with line continuations like in Makefiles, use SetupFileMkLines.
func (t *Tester) NewLines(fileName string, lines ...string) Lines {
	return t.NewLinesAt(fileName, 1, lines...)
}

// NewLinesAt returns a list of simple lines that belong together.
//
// To work with line continuations like in Makefiles, use SetupFileMkLines.
func (t *Tester) NewLinesAt(fileName string, firstLine int, texts ...string) Lines {
	lines := make([]Line, len(texts))
	for i, text := range texts {
		lines[i] = t.NewLine(fileName, i+firstLine, text)
	}
	return NewLines(fileName, lines)
}

// NewMkLines returns a list of lines in Makefile format,
// as if they were parsed from a Makefile fragment,
// taking continuation lines into account.
//
// No actual file is created for the lines;
// see SetupFileMkLines for loading Makefile fragments with line continuations.
func (t *Tester) NewMkLines(fileName string, lines ...string) MkLines {
	var rawText strings.Builder
	for _, line := range lines {
		rawText.WriteString(line)
		rawText.WriteString("\n")
	}
	return NewMkLines(convertToLogicalLines(fileName, rawText.String(), true))
}

// Returns and consumes the output from both stdout and stderr.
// In the output, the temporary directory is replaced with a tilde (~).
func (t *Tester) Output() string {
	stdout := t.stdout.String()
	stderr := t.stderr.String()

	t.stdout.Reset()
	t.stderr.Reset()

	output := stdout + stderr
	if t.tmpdir != "" {
		output = strings.Replace(output, t.tmpdir, "~", -1)
	} else {
		panic("asdfgsfas")
	}
	return output
}

// CheckOutputEmpty ensures that the output up to now is empty.
//
// See CheckOutputLines.
func (t *Tester) CheckOutputEmpty() {
	output := t.Output()
	actualLines := strings.Split(output, "\n")
	actualLines = actualLines[:len(actualLines)-1]
	t.Check(emptyToNil(actualLines), deepEquals, emptyToNil(nil))
}

// CheckOutputLines checks that the output up to now equals the given lines.
// After the comparison, the output buffers are cleared so that later
// calls only check against the newly added output.
//
// See CheckOutputEmpty.
func (t *Tester) CheckOutputLines(expectedLines ...string) {
	G.Assertf(len(expectedLines) > 0, "To check empty lines, use CheckLinesEmpty instead.")

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
// in combination with SetupCommandLine("--debug").
//
// In JetBrains GoLand, the tracing output is suppressed after the first
// failed check, see https://youtrack.jetbrains.com/issue/GO-6154.
func (t *Tester) EnableTracing() {
	G.logOut = NewSeparatorWriter(io.MultiWriter(os.Stdout, &t.stdout))
	trace.Out = os.Stdout
	trace.Tracing = true
}

// EnableTracingToLog enables the tracing and writes the tracing output
// to the test log that can be examined with Tester.Output.
func (t *Tester) EnableTracingToLog() {
	t.EnableTracing()
	trace.Out = &t.stdout
}

// EnableSilentTracing enables tracing mode but discards any tracing output.
// This is the default mode when running the tests.
// The diagnostics go to the in-memory buffer.
//
// It is used to check all calls to trace.Result, since the compiler
// cannot check them.
func (t *Tester) EnableSilentTracing() {
	G.logOut = NewSeparatorWriter(&t.stdout)
	trace.Out = ioutil.Discard
	trace.Tracing = true
}

// DisableTracing skips all tracing code.
// The diagnostics go to the in-memory buffer again,
// ready to be checked with CheckOutputLines.
func (t *Tester) DisableTracing() {
	G.logOut = NewSeparatorWriter(&t.stdout)
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
