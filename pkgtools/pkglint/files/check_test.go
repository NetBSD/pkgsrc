package main

import (
	"bytes"
	"io/ioutil"
	"os"
	"path"
	"path/filepath"
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
func (s *Suite) Output() string {
	return s.Stdout() + s.Stderr()
}

func (s *Suite) NewLines(fname string, lines ...string) []*Line {
	result := make([]*Line, len(lines))
	for i, line := range lines {
		result[i] = NewLine(fname, sprintf("%d", i+1), line, []*RawLine{{i + 1, line + "\n"}})
	}
	return result
}

func (s *Suite) UseCommandLine(c *check.C, args ...string) {
	exitcode := new(Pkglint).ParseCommandLine(append([]string{"pkglint"}, args...))
	if exitcode != nil && *exitcode != 0 {
		c.Fatalf("Cannot parse command line: %#v", args)
	}
}

func (s *Suite) DummyLine() *Line {
	return NewLine("fname", "1", "dummy", nil)
}

func (s *Suite) CreateTmpFile(c *check.C, fname, content string) {
	if s.tmpdir == "" {
		s.tmpdir = filepath.ToSlash(c.MkDir())
	}
	err := os.MkdirAll(s.tmpdir+"/"+path.Dir(fname), 0777)
	c.Check(err, check.IsNil)

	err = ioutil.WriteFile(s.tmpdir+"/"+fname, []byte(content), 0666)
	c.Check(err, check.IsNil)
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
	G = new(GlobalVars)
	G.logOut, G.logErr, G.traceOut = &s.stdout, &s.stderr, &s.stdout
}

func (s *Suite) TearDownTest(c *check.C) {
	G = nil
	if out := s.Output(); out != "" {
		c.Logf("Unchecked output; check with: c.Check(s.Output(), equals, %q)", out)
	}
	s.tmpdir = ""
}

var _ = check.Suite(new(Suite))

func Test(t *testing.T) { check.TestingT(t) }
