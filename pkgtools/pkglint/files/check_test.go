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

	check "gopkg.in/check.v1"
)

var equals = check.Equals
var deepEquals = check.DeepEquals

type Suite struct {
	stdout bytes.Buffer
	stderr bytes.Buffer
	tmpdir string
}

func (s *Suite) Stdout() string {
	defer s.stdout.Reset()
	return s.stdout.String()
}

func (s *Suite) Stderr() string {
	defer s.stderr.Reset()
	return s.stderr.String()
}

// Returns and consumes the output from both stdout and stderr.
// The temporary directory is replaced with a tilde (~).
func (s *Suite) Output() string {
	output := s.Stdout() + s.Stderr()
	if s.tmpdir != "" {
		output = strings.Replace(output, s.tmpdir, "~", -1)
	}
	return output
}

// Arguments are either (lineno, orignl) or (lineno, orignl, textnl).
func (s *Suite) NewRawLines(args ...interface{}) []*RawLine {
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

func (s *Suite) NewLines(fname string, texts ...string) []*Line {
	result := make([]*Line, len(texts))
	for i, text := range texts {
		textnl := text + "\n"
		result[i] = NewLine(fname, i+1, text, s.NewRawLines(i+1, textnl))
	}
	return result
}

func (s *Suite) NewMkLines(fname string, lines ...string) *MkLines {
	return NewMkLines(s.NewLines(fname, lines...))
}

func (s *Suite) DebugToStdout() {
	G.debugOut = os.Stdout
	G.logOut = os.Stdout
	G.opts.Debug = true
}

func (s *Suite) UseCommandLine(c *check.C, args ...string) {
	exitcode := new(Pkglint).ParseCommandLine(append([]string{"pkglint"}, args...))
	if exitcode != nil && *exitcode != 0 {
		c.Fatalf("Cannot parse command line: %#v", args)
	}
	G.opts.LogVerbose = true // See SetUpTest
}

func (s *Suite) RegisterMasterSite(varname string, urls ...string) {
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

func (s *Suite) RegisterTool(tool *Tool) {
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

func (s *Suite) CreateTmpFile(c *check.C, relFname, content string) (absFname string) {
	if s.tmpdir == "" {
		s.tmpdir = filepath.ToSlash(c.MkDir())
	}
	absFname = s.tmpdir + "/" + relFname
	err := os.MkdirAll(path.Dir(absFname), 0777)
	c.Assert(err, check.IsNil)

	err = ioutil.WriteFile(absFname, []byte(content), 0666)
	c.Check(err, check.IsNil)
	return
}

func (s *Suite) CreateTmpFileLines(c *check.C, relFname string, rawTexts ...string) (absFname string) {
	text := ""
	for _, rawText := range rawTexts {
		text += rawText + "\n"
	}
	return s.CreateTmpFile(c, relFname, text)
}

func (s *Suite) LoadTmpFile(c *check.C, relFname string) string {
	bytes, err := ioutil.ReadFile(s.tmpdir + "/" + relFname)
	c.Assert(err, check.IsNil)
	return string(bytes)
}

func (s *Suite) ExpectFatalError(action func()) {
	if r := recover(); r != nil {
		if _, ok := r.(pkglintFatal); ok {
			action()
			return
		}
		panic(r)
	}
}

func (s *Suite) SetUpTest(c *check.C) {
	G = GlobalVars{Testing: true}
	G.logOut, G.logErr, G.debugOut = &s.stdout, &s.stderr, &s.stdout
	s.UseCommandLine(c /* no arguments */)
	G.opts.LogVerbose = true // To detect duplicate work being done
}

func (s *Suite) TearDownTest(c *check.C) {
	G = GlobalVars{}
	if out := s.Output(); out != "" {
		fmt.Fprintf(os.Stderr, "Unchecked output in %q; check with: c.Check(s.Output(), equals, %q)", c.TestName(), out)
	}
	s.tmpdir = ""
}

var _ = check.Suite(new(Suite))

func Test(t *testing.T) { check.TestingT(t) }
