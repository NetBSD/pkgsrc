package main

import (
	check "gopkg.in/check.v1"
	"path/filepath"
)

func (s *Suite) TestChecklinesPatch_WithComment(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	lines := s.NewLines("patch-WithComment",
		"$"+"NetBSD$",
		"",
		"Text",
		"Text",
		"",
		"--- file.orig",
		"+++ file",
		"@@ -5,3 +5,3 @@",
		" context before",
		"-old line",
		"+old line",
		" context after")

	checklinesPatch(lines)

	c.Check(s.Output(), equals, "")
}

func (s *Suite) TestChecklinesPatch_WithoutEmptyLine(c *check.C) {
	tmpdir := c.MkDir()
	fname := filepath.ToSlash(tmpdir + "/patch-WithoutEmptyLines")
	s.UseCommandLine(c, "-Wall", "--autofix")
	lines := s.NewLines(fname,
		"$"+"NetBSD$",
		"Text",
		"--- file.orig",
		"+++ file",
		"@@ -5,3 +5,3 @@",
		" context before",
		"-old line",
		"+old line",
		" context after")

	checklinesPatch(lines)

	c.Check(s.Output(), equals, ""+
		"NOTE: "+fname+":2: Empty line expected.\n"+
		"NOTE: "+fname+":2: Autofix: inserting a line \"\\n\" before this line.\n"+
		"NOTE: "+fname+":3: Empty line expected.\n"+
		"NOTE: "+fname+":3: Autofix: inserting a line \"\\n\" before this line.\n"+
		"NOTE: "+fname+": Has been auto-fixed. Please re-run pkglint.\n")
}

func (s *Suite) TestChecklinesPatch_WithoutComment(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	lines := s.NewLines("patch-WithoutComment",
		"$"+"NetBSD$",
		"",
		"--- file.orig",
		"+++ file",
		"@@ -5,3 +5,3 @@",
		" context before",
		"-old line",
		"+old line",
		" context after")

	checklinesPatch(lines)

	c.Check(s.Output(), equals, "ERROR: patch-WithoutComment:3: Each patch must be documented.\n")
}

func (s *Suite) TestChecklineOtherAbsolutePathname(c *check.C) {
	line := NewLine("patch-ag", "1", "+$install -s -c ./bin/rosegarden ${DESTDIR}$BINDIR", nil)

	checklineOtherAbsolutePathname(line, line.text)

	c.Check(s.Output(), equals, "")
}

func (s *Suite) TestChecklinesPatch_ErrorCode(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	lines := s.NewLines("patch-ErrorCode",
		"$"+"NetBSD$",
		"",
		"*** Error code 1", // Looks like a context diff, but isn’t.
		"",
		"--- file.orig",
		"+++ file",
		"@@ -5,3 +5,3 @@",
		" context before",
		"-old line",
		"+old line",
		" context after")

	checklinesPatch(lines)

	c.Check(s.Output(), equals, "")
}

func (s *Suite) TestChecklinesPatch_WrongOrder(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	lines := s.NewLines("patch-WrongOrder",
		"$"+"NetBSD$",
		"",
		"Text",
		"Text",
		"",
		"+++ file",      // Wrong
		"--- file.orig", // Wrong
		"@@ -5,3 +5,3 @@",
		" context before",
		"-old line",
		"+old line",
		" context after")

	checklinesPatch(lines)

	c.Check(s.Output(), equals, "WARN: patch-WrongOrder:7: Unified diff headers should be first ---, then +++.\n")
}
