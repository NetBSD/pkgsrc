package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) Test_convertToLogicalLines_no_continuation(c *check.C) {
	rawText := "" +
		"first line\n" +
		"second line\n"

	lines := convertToLogicalLines("fname_nocont", rawText, false)

	c.Check(lines, check.HasLen, 2)
	c.Check(lines[0].String(), equals, "fname_nocont:1: first line")
	c.Check(lines[1].String(), equals, "fname_nocont:2: second line")
}

func (s *Suite) Test_convertToLogicalLines_continuation(c *check.C) {
	rawText := "" +
		"first line \\\n" +
		"second line\n" +
		"third\n"

	lines := convertToLogicalLines("fname_cont", rawText, true)

	c.Check(lines, check.HasLen, 2)
	c.Check(lines[0].String(), equals, "fname_cont:1--2: first line second line")
	c.Check(lines[1].String(), equals, "fname_cont:3: third")
}

func (s *Suite) Test_convertToLogicalLines_continuationInLastLine(c *check.C) {
	rawText := "" +
		"last line\\"

	lines := convertToLogicalLines("fname_contlast", rawText, true)

	c.Check(lines, check.HasLen, 1)
	c.Check(lines[0].String(), equals, "fname_contlast:1: last line\\")
	c.Check(s.Stdout(), equals, "ERROR: fname_contlast:EOF: File must end with a newline.\n")
}

func (s *Suite) Test_splitRawLine(c *check.C) {
	leadingWhitespace, text, trailingWhitespace, continuation := splitRawLine("\n")

	c.Check(leadingWhitespace, equals, "")
	c.Check(text, equals, "")
	c.Check(trailingWhitespace, equals, "")
	c.Check(continuation, equals, "")

	leadingWhitespace, text, trailingWhitespace, continuation = splitRawLine("\tword   \\\n")

	c.Check(leadingWhitespace, equals, "\t")
	c.Check(text, equals, "word")
	c.Check(trailingWhitespace, equals, "   ")
	c.Check(continuation, equals, "\\")
}

func (s *Suite) Test_show_autofix(c *check.C) {
	s.Init(c)
	s.UseCommandLine("--show-autofix")
	fname := s.CreateTmpFile("Makefile", ""+
		"line1\n"+
		"line2\n"+
		"line3\n")
	lines := LoadExistingLines(fname, true)

	if !lines[1].AutofixReplaceRegexp(`.`, "X") {
		lines[1].Warnf("Something's wrong here.") // Prints the autofix NOTE afterwards
	}
	SaveAutofixChanges(lines)

	c.Check(lines[1].(*LineImpl).raw[0].textnl, equals, "XXXXX\n")
	c.Check(s.LoadTmpFile("Makefile"), equals, "line1\nline2\nline3\n")
	s.CheckOutputLines(
		"WARN: ~/Makefile:2: Something's wrong here.",
		"AUTOFIX: ~/Makefile:2: Replacing regular expression \".\" with \"X\".")
}

func (s *Suite) Test_autofix(c *check.C) {
	s.Init(c)
	s.UseCommandLine("--autofix")
	fname := s.CreateTmpFile("Makefile", ""+
		"line1\n"+
		"line2\n"+
		"line3\n")
	lines := LoadExistingLines(fname, true)

	if !lines[1].AutofixReplaceRegexp(`.`, "X") {
		lines[1].Warnf("Something's wrong here.") // Prints the autofix NOTE afterwards
	}
	SaveAutofixChanges(lines)

	c.Check(s.LoadTmpFile("Makefile"), equals, "line1\nXXXXX\nline3\n")
	s.CheckOutputLines(
		"AUTOFIX: ~/Makefile:2: Replacing regular expression \".\" with \"X\".",
		"AUTOFIX: ~/Makefile: Has been auto-fixed. Please re-run pkglint.")
}
