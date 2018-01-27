package main

import (
	"bytes"
	"fmt"
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

const RcsId = "$" + "NetBSD$"
const MkRcsId = "# $" + "NetBSD$"
const PlistRcsId = "@comment $" + "NetBSD$"

type Suite struct {
	Tester *Tester
}

// Init initializes the suite with the check.C instance for the actual
// test run. See https://github.com/go-check/check/issues/22
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

	G = GlobalVars{Testing: true}
	textproc.Testing = true
	G.logOut = NewSeparatorWriter(&t.stdout)
	G.logErr = NewSeparatorWriter(&t.stderr)
	trace.Out = &t.stdout

	t.checkC = c
	t.SetupCommandLine( /* no arguments */ )
	t.checkC = nil

	G.opts.LogVerbose = true // To detect duplicate work being done
}

func (s *Suite) TearDownTest(c *check.C) {
	t := s.Tester
	t.checkC = nil // No longer usable; see https://github.com/go-check/check/issues/22

	G = GlobalVars{}
	textproc.Testing = false
	if out := t.Output(); out != "" {
		fmt.Fprintf(os.Stderr, "Unchecked output in %q; check with: t.CheckOutputLines(%v)",
			c.TestName(), strings.Split(out, "\n"))
	}
	t.tmpdir = ""
}

var _ = check.Suite(new(Suite))

func Test(t *testing.T) { check.TestingT(t) }

// Tester provides utility methods for testing pkglint.
// It is separated from the Suite since the latter contains
// all the test methods, which makes it difficult to find
// a method by auto-completion.
type Tester struct {
	stdout bytes.Buffer
	stderr bytes.Buffer
	tmpdir string
	checkC *check.C
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
	exitcode := new(Pkglint).ParseCommandLine(append([]string{"pkglint"}, args...))
	if exitcode != nil && *exitcode != 0 {
		t.CheckOutputEmpty()
		t.c().Fatalf("Cannot parse command line: %#v", args)
	}
	G.opts.LogVerbose = true // See SetUpTest
}

func (t *Tester) SetupMasterSite(varname string, urls ...string) {
	name2url := &G.globalData.MasterSiteVarToURL
	url2name := &G.globalData.MasterSiteURLToVar
	if *name2url == nil {
		*name2url = make(map[string]string)
		*url2name = make(map[string]string)
	}
	(*name2url)[varname] = urls[0]
	for _, url := range urls {
		(*url2name)[url] = varname
	}
}

func (t *Tester) SetupTool(tool *Tool) {
	reg := G.globalData.Tools

	if len(reg.byName) == 0 && len(reg.byVarname) == 0 {
		reg = NewToolRegistry()
		G.globalData.Tools = reg
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
	return LoadExistingLines(filename, false)
}

// SetupFileLines creates a temporary file and writes the given lines to it.
// The file is then read in, handling line continuations for Makefiles.
func (t *Tester) SetupFileLinesContinuation(relativeFilename string, lines ...string) []Line {
	filename := t.CreateFileLines(relativeFilename, lines...)
	return LoadExistingLines(filename, true)
}

func (t *Tester) CreateFileLines(relativeFilename string, lines ...string) (filename string) {
	content := ""
	for _, line := range lines {
		content += line + "\n"
	}

	filename = t.TempFilename(relativeFilename)
	err := os.MkdirAll(path.Dir(filename), 0777)
	t.c().Assert(err, check.IsNil)

	err = ioutil.WriteFile(filename, []byte(content), 0666)
	t.c().Check(err, check.IsNil)

	return filename
}

func (t *Tester) LoadTmpFile(relFname string) (absFname string) {
	bytes, err := ioutil.ReadFile(t.TmpDir() + "/" + relFname)
	t.c().Assert(err, check.IsNil)
	return string(bytes)
}

func (t *Tester) TmpDir() string {
	if t.tmpdir == "" {
		t.tmpdir = filepath.ToSlash(t.c().MkDir())
	}
	return t.tmpdir
}

// TempFilename returns the absolute path to the given file in the
// temporary directory. It doesn't check whether that file exists.
func (t *Tester) TempFilename(relativeFilename string) string {
	return t.TmpDir() + "/" + relativeFilename
}

func (t *Tester) ExpectFatalError(action func()) {
	if r := recover(); r != nil {
		if _, ok := r.(pkglintFatal); ok {
			action()
			return
		}
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
	return NewMkLines(t.NewLines(fileName, lines...))
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

// BeginDebugToStdout redirects all logging output to stdout instead of
// the buffer. This is useful when stepping through the code, especially
// in combination with SetupCommandLine("--debug").
func (t *Tester) BeginDebugToStdout() {
	G.logOut = NewSeparatorWriter(os.Stdout)
	trace.Out = os.Stdout
	trace.Tracing = true
}

// EndDebugToStdout logs the output to the buffers again, ready to be
// checked with CheckOutputLines.
func (t *Tester) EndDebugToStdout() {
	G.logOut = NewSeparatorWriter(&t.stdout)
	trace.Out = &t.stdout
	trace.Tracing = false
}

// CheckFileLines loads the lines from the temporary file and checks that
// they equal the given lines.
func (t *Tester) CheckFileLines(relativeFileName string, lines ...string) {
	text := t.LoadTmpFile(relativeFileName)
	actualLines := strings.Split(text, "\n")
	actualLines = actualLines[:len(actualLines)-1]
	t.c().Check(emptyToNil(actualLines), deepEquals, emptyToNil(lines))
}

// CheckFileLinesDetab loads the lines from the temporary file and checks
// that they equal the given lines. The loaded file may use tabs or spaces
// for indentation, while the lines in the code use spaces exclusively,
// in order to make the depth of the indentation clearly visible.
func (t *Tester) CheckFileLinesDetab(relativeFileName string, lines ...string) {
	actualLines, err := readLines(t.TempFilename(relativeFileName), false)
	if !t.c().Check(err, check.IsNil) {
		return
	}

	var detabbed []string
	for _, line := range actualLines {
		rawText := strings.TrimRight(detab(line.raw[0].orignl), "\n")
		detabbed = append(detabbed, rawText)
	}

	t.c().Check(detabbed, deepEquals, lines)
}
