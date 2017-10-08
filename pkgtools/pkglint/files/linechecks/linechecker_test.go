package linechecks

// Note: These tests are currently not run, since the dependencies
// between the Go packages are not yet resolved properly.

import (
	"gopkg.in/check.v1"
	"netbsd.org/pkglint/line"
)

type Suite struct {
	c *check.C
}

func (s *Suite) SetUpTest(c *check.C) {
	Explain = func(...string) {}
}

func (s *Suite) TearDownTest(c *check.C) {
	Explain = nil
}

func (s *Suite) Init(c *check.C) {
	s.c = c
}

func (s *Suite) CheckOutputLines(lines ...string) {
	panic("Not yet implemented")
}

func (s *Suite) NewLines(...string) []line.Line {
	panic("Not yet implemented")
}

func NewLine(string, int, string, []string) line.Line {
	panic("Not yet implemented")
}

func (s *Suite) Test_LineChecker_CheckAbsolutePathname(c *check.C) {
	line := NewLine("Makefile", 1, "# dummy", nil)

	CheckAbsolutePathname(line, "bindir=/bin")
	CheckAbsolutePathname(line, "bindir=/../lib")

	s.CheckOutputLines(
		"WARN: Makefile:1: Found absolute pathname: /bin")
}

func (s *Suite) Test_LineChecker_CheckTrailingWhitespace(c *check.C) {
	s.Init(c)
	line := NewLine("Makefile", 32, "The line must go on   ", nil)

	CheckTrailingWhitespace(line)

	s.CheckOutputLines(
		"NOTE: Makefile:32: Trailing white-space.")
}

func (s *Suite) Test_LineChecker_CheckRcsid(c *check.C) {
	s.Init(c)
	lines := s.NewLines("fname",
		"$"+"NetBSD: dummy $",
		"$"+"NetBSD$",
		"$"+"Id: dummy $",
		"$"+"Id$",
		"$"+"FreeBSD$")

	for _, line := range lines {
		CheckRcsid(line, ``, "")
	}

	s.CheckOutputLines(
		"ERROR: fname:3: Expected \"$"+"NetBSD$\".",
		"ERROR: fname:4: Expected \"$"+"NetBSD$\".",
		"ERROR: fname:5: Expected \"$"+"NetBSD$\".")
}
