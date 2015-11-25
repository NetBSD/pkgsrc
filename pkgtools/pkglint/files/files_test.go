package main

import (
	check "gopkg.in/check.v1"
	"io/ioutil"
)

func (s *Suite) TestConvertToLogicalLines_nocont(c *check.C) {
	rawText := "" +
		"first line\n" +
		"second line\n"

	lines := convertToLogicalLines("fname_nocont", rawText, false)

	c.Check(lines, check.HasLen, 2)
	c.Check(lines[0].String(), equals, "fname_nocont:1: first line")
	c.Check(lines[1].String(), equals, "fname_nocont:2: second line")
}

func (s *Suite) TestConvertToLogicalLines_cont(c *check.C) {
	rawText := "" +
		"first line \\\n" +
		"second line\n" +
		"third\n"

	lines := convertToLogicalLines("fname_cont", rawText, true)

	c.Check(lines, check.HasLen, 2)
	c.Check(lines[0].String(), equals, "fname_cont:1--2: first line second line")
	c.Check(lines[1].String(), equals, "fname_cont:3: third")
}

func (s *Suite) TestConvertToLogicalLines_contInLastLine(c *check.C) {
	rawText := "" +
		"last line\\"

	lines := convertToLogicalLines("fname_contlast", rawText, true)

	c.Check(lines, check.HasLen, 1)
	c.Check(lines[0].String(), equals, "fname_contlast:1: last line\\")
	c.Check(s.Stdout(), equals, "ERROR: fname_contlast:1: File must end with a newline.\n")
}

func (s *Suite) TestSplitRawLine(c *check.C) {
	leadingWhitespace, text, trailingWhitespace, continuation := splitRawLine("\n")

	c.Check(leadingWhitespace, equals, "")
	c.Check(text, equals, "")
	c.Check(trailingWhitespace, equals, "")
	c.Check(continuation, equals, "")

	leadingWhitespace, text, trailingWhitespace, continuation = splitRawLine("\tasdf   \\\n")

	c.Check(leadingWhitespace, equals, "\t")
	c.Check(text, equals, "asdf")
	c.Check(trailingWhitespace, equals, "   ")
	c.Check(continuation, equals, "\\")
}

func (s *Suite) TestAutofix(c *check.C) {
	tmpdir := c.MkDir()
	tmpname := tmpdir + "/Makefile"
	lines := s.NewLines(tmpname,
		"line1",
		"line2",
		"line3")
	lines[1].replaceRegex(`.`, "X")

	saveAutofixChanges(lines)

	c.Assert(fileExists(tmpname), equals, false)

	G.opts.Autofix = true
	saveAutofixChanges(lines)

	content, err := ioutil.ReadFile(tmpdir + "/Makefile")
	c.Assert(err, check.IsNil)
	c.Check(string(content), equals, "line1\nXXXXX\nline3\n")
}
