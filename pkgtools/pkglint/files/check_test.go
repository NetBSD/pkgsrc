package main

import (
	"bytes"
	"fmt"
	"io"
	"io/ioutil"
	"os"
	"path"
	"path/filepath"
	"strings"
	"testing"

	"gopkg.in/check.v1"
	"netbsd.org/pkglint/textproc"
	"netbsd.org/pkglint/trace"
)

var equals = check.Equals
var deepEquals = check.DeepEquals

const RcsID = "$" + "NetBSD$"
const MkRcsID = "# $" + "NetBSD$"
const PlistRcsID = "@comment $" + "NetBSD$"

type Suite struct {
	Tester *Tester
}

// Init initializes the suite with the check.C instance for the actual
// test run.
// The returned tester can be used to easily setup the test environment
// and check the results using a high-level API.
//
// See https://github.com/go-check/check/issues/22
func (s *Suite) Init(c *check.C) *Tester {
	t := s.Tester // Has been initialized by SetUpTest
	if t.checkC != nil {
		panic("Suite.Init must only be called once.")
	}
	t.checkC = c
	return t
}

func (s *Suite) SetUpTest(c *check.C) {
	t := &Tester{checkC: c}
	s.Tester = t

	G = Pkglint{Testing: true}
	textproc.Testing = true
	G.logOut = NewSeparatorWriter(&t.stdout)
	G.logErr = NewSeparatorWriter(&t.stderr)
	trace.Out = &t.stdout
	G.Pkgsrc = NewPkgsrc(t.File("."))

	t.checkC = c
	t.SetupCommandLine( /* no arguments */ )
	t.checkC = nil

	G.opts.LogVerbose = true // To detect duplicate work being done
	t.EnableSilentTracing()

	prevdir, err := os.Getwd()
	if err != nil {
		c.Fatalf("Cannot get current working directory: %s", err)
	}
	t.prevdir = prevdir
}

func (s *Suite) TearDownTest(c *check.C) {
	t := s.Tester
	t.checkC = nil // No longer usable; see https://github.com/go-check/check/issues/22

	if err := os.Chdir(t.prevdir); err != nil {
		fmt.Fprintf(os.Stderr, "Cannot chdir back to previous dir: %s", err)
	}

	G = Pkglint{} // unusable because of missing logOut and logErr
	textproc.Testing = false
	if out := t.Output(); out != "" {
		fmt.Fprintf(os.Stderr, "Unchecked output in %q; check with: t.CheckOutputLines(%v)",
			c.TestName(), strings.Split(out, "\n"))
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
	checkC  *check.C // Only usable during the test method itself
	prevdir string   // The current working directory before the test started
	relcwd  string
}

func (t *Tester) c() *check.C {
	if t.checkC == nil {
		panic("Suite.Init must be called before accessing check.C.")
	}
	return t.checkC
}

// SetupCommandLine simulates a command line for the remainder of the test.
// See Pkglint.ParseCommandLine.
func (t *Tester) SetupCommandLine(args ...string) {

	// Prevent tracing from being disabled; see EnableSilentTracing.
	prevTracing := trace.Tracing
	defer func() { trace.Tracing = prevTracing }()

	exitcode := G.ParseCommandLine(append([]string{"pkglint"}, args...))
	if exitcode != nil && *exitcode != 0 {
		t.CheckOutputEmpty()
		t.c().Fatalf("Cannot parse command line: %#v", args)
	}
	G.opts.LogVerbose = true // See SetUpTest
}

// SetupVartypes registers a few hundred variables like MASTER_SITES,
// WRKSRC, SUBST_SED.*, so that their data types are known to pkglint.
func (t *Tester) SetupVartypes() {
	G.Pkgsrc.InitVartypes()
}

func (t *Tester) SetupMasterSite(varname string, urls ...string) {
	name2url := &G.Pkgsrc.MasterSiteVarToURL
	url2name := &G.Pkgsrc.MasterSiteURLToVar
	if *name2url == nil {
		*name2url = make(map[string]string)
		*url2name = make(map[string]string)
	}
	(*name2url)[varname] = urls[0]
	for _, url := range urls {
		(*url2name)[url] = varname
	}
}

// SetupOption pretends that the package option is defined in mk/defaults/options.description.
func (t *Tester) SetupOption(name, description string) {
	G.Pkgsrc.PkgOptions[name] = description
}

func (t *Tester) SetupTool(tool *Tool) {
	reg := G.Pkgsrc.Tools

	if len(reg.byName) == 0 && len(reg.byVarname) == 0 {
		reg = NewToolRegistry()
		G.Pkgsrc.Tools = reg
	}
	if tool.Name != "" {
		reg.byName[tool.Name] = tool
	}
	if tool.Varname != "" {
		reg.byVarname[tool.Varname] = tool
	}
}

// SetupFileLines creates a temporary file and writes the given lines to it.
// The file is then read in, without considering line continuations.
func (t *Tester) SetupFileLines(relativeFilename string, lines ...string) []Line {
	filename := t.CreateFileLines(relativeFilename, lines...)
	return Load(filename, MustSucceed)
}

// SetupFileLines creates a temporary file and writes the given lines to it.
// The file is then read in, handling line continuations for Makefiles.
func (t *Tester) SetupFileMkLines(relativeFilename string, lines ...string) *MkLines {
	filename := t.CreateFileLines(relativeFilename, lines...)
	return LoadMk(filename, MustSucceed)
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

	// The MASTER_SITES in the package Makefile are searched here.
	// See Pkgsrc.loadMasterSites.
	t.CreateFileLines("mk/fetch/sites.mk",
		MkRcsID)

	// The options for the PKG_OPTIONS framework must be readable.
	// See Pkgsrc.loadPkgOptions.
	t.CreateFileLines("mk/defaults/options.description")

	// The user-defined variables are read in to check for missing
	// BUILD_DEFS declarations in the package Makefile.
	t.CreateFileLines("mk/defaults/mk.conf",
		MkRcsID)

	// The tool definitions are read in to check for missing
	// USE_TOOLS declarations in the package Makefile.
	// They spread over several files from the pkgsrc infrastructure.
	t.CreateFileLines("mk/tools/bsd.tools.mk",
		".include \"defaults.mk\"")
	t.CreateFileLines("mk/tools/defaults.mk",
		MkRcsID)
	t.CreateFileLines("mk/bsd.prefs.mk", // Some tools are defined here.
		MkRcsID)
}

func (t *Tester) CreateFileLines(relativeFilename string, lines ...string) (filename string) {
	content := ""
	for _, line := range lines {
		content += line + "\n"
	}

	filename = t.File(relativeFilename)
	err := os.MkdirAll(path.Dir(filename), 0777)
	t.c().Assert(err, check.IsNil)

	err = ioutil.WriteFile(filename, []byte(content), 0666)
	t.c().Check(err, check.IsNil)

	return filename
}

// File returns the absolute path to the given file in the
// temporary directory. It doesn't check whether that file exists.
// Calls to Tester.Chdir change the base directory for the relative file name.
func (t *Tester) File(relativeFilename string) string {
	if t.tmpdir == "" {
		t.tmpdir = filepath.ToSlash(t.c().MkDir())
	}
	if t.relcwd != "" {
		return cleanpath(relativeFilename)
	}
	return cleanpath(t.tmpdir + "/" + relativeFilename)
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
func (t *Tester) Chdir(relativeFilename string) {
	if t.relcwd != "" {
		// When multiple calls of Chdir are mixed with calls to CreateFileLines,
		// the resulting []Line and MkLines variables will use relative file names,
		// and these will point to different areas in the file system. This is
		// usually not indented and therefore prevented.
		t.checkC.Fatalf("Chdir must only be called once per test; already in %q.", t.relcwd)
	}

	_ = os.MkdirAll(t.File(relativeFilename), 0700)
	if err := os.Chdir(t.File(relativeFilename)); err != nil {
		t.checkC.Fatalf("Cannot chdir: %s", err)
	}
	t.relcwd = relativeFilename
}

// ExpectFatalError promises that in the remainder of the current function
// call, a panic with a pkglintFatal will occur (typically from Line.Fatalf).
//
// Usage:
// 	func() {
//      defer t.ExpectFatalError()
//
//      // The code that causes the fatal error.
//      Load(t.File("nonexistent"), MustSucceed)
//  }()
//  t.CheckOutputLines(
//      "FATAL: ~/nonexistent: Does not exist.")
func (t *Tester) ExpectFatalError() {
	r := recover()
	if r == nil {
		panic("Expected a pkglint fatal error, but didn't get one.")
	} else if _, ok := r.(pkglintFatal); !ok {
		panic(r)
	}
}

// Arguments are either (lineno, orignl) or (lineno, orignl, textnl).
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

func (t *Tester) NewLine(filename string, lineno int, text string) Line {
	textnl := text + "\n"
	rawLine := RawLine{lineno, textnl, textnl}
	return NewLine(filename, lineno, text, []*RawLine{&rawLine})
}

func (t *Tester) NewMkLine(fileName string, lineno int, text string) MkLine {
	return NewMkLine(t.NewLine(fileName, lineno, text))
}

func (t *Tester) NewShellLine(fileName string, lineno int, text string) *ShellLine {
	return NewShellLine(t.NewMkLine(fileName, lineno, text))
}

// NewLines generates a slice of simple lines,
// i.e. each logical line has exactly one physical line.
// To work with line continuations like in Makefiles,
// use CreateFileLines together with LoadExistingLines.
func (t *Tester) NewLines(fileName string, lines ...string) []Line {
	return t.NewLinesAt(fileName, 1, lines...)
}

// NewLinesAt generates a slice of simple lines,
// i.e. each logical line has exactly one physical line.
// To work with line continuations like in Makefiles,
// use Suite.CreateFileLines together with Suite.LoadExistingLines.
func (t *Tester) NewLinesAt(fileName string, firstLine int, texts ...string) []Line {
	result := make([]Line, len(texts))
	for i, text := range texts {
		textnl := text + "\n"
		result[i] = NewLine(fileName, i+firstLine, text, t.NewRawLines(i+firstLine, textnl))
	}
	return result
}

func (t *Tester) NewMkLines(fileName string, lines ...string) *MkLines {
	rawText := ""
	for _, line := range lines {
		rawText += line + "\n"
	}
	return NewMkLines(convertToLogicalLines(fileName, rawText, true))
}

// Returns and consumes the output from both stdout and stderr.
// The temporary directory is replaced with a tilde (~).
func (t *Tester) Output() string {
	stdout := t.stdout.String()
	stderr := t.stderr.String()

	t.stdout.Reset()
	t.stderr.Reset()

	output := stdout + stderr
	if t.tmpdir != "" {
		output = strings.Replace(output, t.tmpdir, "~", -1)
	}
	return output
}

func (t *Tester) CheckOutputEmpty() {
	t.CheckOutputLines( /* none */ )
}

// CheckOutputLines checks that the output up to now equals the given lines.
// After the comparison, the output buffers are cleared so that later
// calls only check against the newly added output.
func (t *Tester) CheckOutputLines(expectedLines ...string) {
	output := t.Output()
	actualLines := strings.Split(output, "\n")
	actualLines = actualLines[:len(actualLines)-1]
	t.c().Check(emptyToNil(actualLines), deepEquals, emptyToNil(expectedLines))
}

// EnableTracing redirects all logging output (which is normally captured
// in an in-memory buffer) additionally to stdout.
// This is useful when stepping through the code, especially
// in combination with SetupCommandLine("--debug").
func (t *Tester) EnableTracing() {
	G.logOut = NewSeparatorWriter(io.MultiWriter(os.Stdout, &t.stdout))
	trace.Out = os.Stdout
	trace.Tracing = true
}

// EnableTracingToLog enables the tracing and writes the tracing output
// to the test log that can be examined with Tester.Output.
func (t *Tester) EnableTracingToLog() {
	G.logOut = NewSeparatorWriter(io.MultiWriter(os.Stdout, &t.stdout))
	trace.Out = &t.stdout
	trace.Tracing = true
}

// EnableSilentTracing enables tracing mode, but discards any tracing output.
// This can be used to improve code coverage without any side-effects,
// since tracing output is quite large.
func (t *Tester) EnableSilentTracing() {
	trace.Out = ioutil.Discard
	trace.Tracing = true
}

// DisableTracing logs the output to the buffers again, ready to be
// checked with CheckOutputLines.
func (t *Tester) DisableTracing() {
	G.logOut = NewSeparatorWriter(&t.stdout)
	trace.Tracing = false
	trace.Out = nil
}

// CheckFileLines loads the lines from the temporary file and checks that
// they equal the given lines.
func (t *Tester) CheckFileLines(relativeFileName string, lines ...string) {
	content, err := ioutil.ReadFile(t.File(relativeFileName))
	t.c().Assert(err, check.IsNil)
	text := string(content)
	actualLines := strings.Split(text, "\n")
	actualLines = actualLines[:len(actualLines)-1]
	t.c().Check(emptyToNil(actualLines), deepEquals, emptyToNil(lines))
}

// CheckFileLinesDetab loads the lines from the temporary file and checks
// that they equal the given lines. The loaded file may use tabs or spaces
// for indentation, while the lines in the code use spaces exclusively,
// in order to make the depth of the indentation clearly visible.
func (t *Tester) CheckFileLinesDetab(relativeFileName string, lines ...string) {
	actualLines := Load(t.File(relativeFileName), MustSucceed)

	var detabbed []string
	for _, line := range actualLines {
		rawText := strings.TrimRight(detab(line.raw[0].orignl), "\n")
		detabbed = append(detabbed, rawText)
	}

	t.c().Check(detabbed, deepEquals, lines)
}
