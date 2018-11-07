package main

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_CheckLineAbsolutePathname(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("Makefile", 1, "# dummy")

	CheckLineAbsolutePathname(line, "bindir=/bin")
	CheckLineAbsolutePathname(line, "bindir=/../lib")
	CheckLineAbsolutePathname(line, "cat /dev/null")
	CheckLineAbsolutePathname(line, "cat /dev/tty")
	CheckLineAbsolutePathname(line, "cat /dev/zero")
	CheckLineAbsolutePathname(line, "cat /dev/stdin")
	CheckLineAbsolutePathname(line, "cat /dev/stdout")
	CheckLineAbsolutePathname(line, "cat /dev/stderr")
	CheckLineAbsolutePathname(line, "printf '#! /bin/sh\\nexit 0'")

	// This is not a file name at all, but certainly looks like one.
	// Nevertheless, pkglint doesn't fall into the trap.
	CheckLineAbsolutePathname(line, "sed -e /usr/s/usr/var/g")

	t.CheckOutputLines(
		"WARN: Makefile:1: Found absolute pathname: /bin",
		"WARN: Makefile:1: Found absolute pathname: /dev/stdin",
		"WARN: Makefile:1: Found absolute pathname: /dev/stdout",
		"WARN: Makefile:1: Found absolute pathname: /dev/stderr")
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

	lines := t.NewLines("fileName",
		"$"+"NetBSD: dummy $",
		"$"+"NetBSD$",
		"$"+"Id: dummy $",
		"$"+"Id$",
		"$"+"FreeBSD$")

	for _, line := range lines.Lines {
		CheckLineRcsid(line, ``, "")
	}

	t.CheckOutputLines(
		"ERROR: fileName:3: Expected \"$"+"NetBSD$\".",
		"ERROR: fileName:4: Expected \"$"+"NetBSD$\".",
		"ERROR: fileName:5: Expected \"$"+"NetBSD$\".")
}
