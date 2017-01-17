package main

import "gopkg.in/check.v1"

func (s *Suite) Test_LineChecker_CheckAbsolutePathname(c *check.C) {
	ck := LineChecker{NewLine("Makefile", 1, "# dummy", nil)}

	ck.CheckAbsolutePathname("bindir=/bin")
	ck.CheckAbsolutePathname("bindir=/../lib")

	c.Check(s.Output(), equals, "WARN: Makefile:1: Found absolute pathname: /bin\n")
}

func (s *Suite) Test_LineChecker_CheckTrailingWhitespace(c *check.C) {
	ck := LineChecker{NewLine("Makefile", 32, "The line must go on   ", nil)}

	ck.CheckTrailingWhitespace()

	c.Check(s.Output(), equals, "NOTE: Makefile:32: Trailing white-space.\n")
}

func (s *Suite) Test_LineChecker_CheckRcsid(c *check.C) {
	lines := s.NewLines("fname",
		"$"+"NetBSD: dummy $",
		"$"+"NetBSD$",
		"$"+"Id: dummy $",
		"$"+"Id$",
		"$"+"FreeBSD$")

	for _, line := range lines {
		LineChecker{line}.CheckRcsid(``, "")
	}

	c.Check(s.Output(), equals, ""+
		"ERROR: fname:3: Expected \"$"+"NetBSD$\".\n"+
		"ERROR: fname:4: Expected \"$"+"NetBSD$\".\n"+
		"ERROR: fname:5: Expected \"$"+"NetBSD$\".\n")
}
