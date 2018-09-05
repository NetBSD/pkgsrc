package main

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_LineChecker_CheckAbsolutePathname(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("Makefile", 1, "# dummy")

	CheckLineAbsolutePathname(line, "bindir=/bin")
	CheckLineAbsolutePathname(line, "bindir=/../lib")
	CheckLineAbsolutePathname(line, "cat /dev/null")   // FIXME: Not classified as absolute path.
	CheckLineAbsolutePathname(line, "cat /dev//tty")   // FIXME: Not classified as absolute patFIXMEh.
	CheckLineAbsolutePathname(line, "cat /dev/zero")   // FIXME: Not classified as absolute path.
	CheckLineAbsolutePathname(line, "cat /dev/stdin")  // FIXME: Not classified as absolute path.
	CheckLineAbsolutePathname(line, "cat /dev/stdout") // FIXME: Not classified as absolute path.
	CheckLineAbsolutePathname(line, "cat /dev/stderr") // FIXME: Not classified as absolute path.

	t.CheckOutputLines(
		"WARN: Makefile:1: Found absolute pathname: /bin")
}

func (s *Suite) Test_CheckLineTrailingWhitespace(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("Makefile", 32, "The line must go on   ")

	CheckLineTrailingWhitespace(line)

	t.CheckOutputLines(
		"NOTE: Makefile:32: Trailing white-space.")
}

func (s *Suite) Test_CheckLineRcsid(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("fname",
		"$"+"NetBSD: dummy $",
		"$"+"NetBSD$",
		"$"+"Id: dummy $",
		"$"+"Id$",
		"$"+"FreeBSD$")

	for _, line := range lines {
		CheckLineRcsid(line, ``, "")
	}

	t.CheckOutputLines(
		"ERROR: fname:3: Expected \"$"+"NetBSD$\".",
		"ERROR: fname:4: Expected \"$"+"NetBSD$\".",
		"ERROR: fname:5: Expected \"$"+"NetBSD$\".")
}
