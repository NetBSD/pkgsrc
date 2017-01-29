package main

import "gopkg.in/check.v1"

func (s *Suite) Test_LineChecker_CheckAbsolutePathname(c *check.C) {
	s.Init(c)
	ck := LineChecker{NewLine("Makefile", 1, "# dummy", nil)}

	ck.CheckAbsolutePathname("bindir=/bin")
	ck.CheckAbsolutePathname("bindir=/../lib")

	s.CheckOutputLines(
		"WARN: Makefile:1: Found absolute pathname: /bin")
}

func (s *Suite) Test_LineChecker_CheckTrailingWhitespace(c *check.C) {
	s.Init(c)
	ck := LineChecker{NewLine("Makefile", 32, "The line must go on   ", nil)}

	ck.CheckTrailingWhitespace()

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
		LineChecker{line}.CheckRcsid(``, "")
	}

	s.CheckOutputLines(
		"ERROR: fname:3: Expected \"$"+"NetBSD$\".",
		"ERROR: fname:4: Expected \"$"+"NetBSD$\".",
		"ERROR: fname:5: Expected \"$"+"NetBSD$\".")
}
