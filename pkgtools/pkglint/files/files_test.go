package main

import (
	"gopkg.in/check.v1"
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

// In Makefiles, comment lines can also have continuations.
// See devel/bmake/files/unit-tests/comment.mk
func (s *Suite) Test_convertToLogicalLines__comments(c *check.C) {
	t := s.Init(c)

	mklines := t.SetupFileMkLines("comment.mk",
		"# This is a comment",
		"",
		"#\\",
		"\tMultiline comment",
		"# Another escaped comment \\",
		"that \\",
		"goes \\",
		"on",
		"# This is NOT an escaped comment due to the double backslashes \\\\",
		"VAR=\tThis is not a comment",
		"",
		"#\\",
		"This is a comment",
		"#\\\\",
		"This is no comment",
		"#\\\\\\",
		"This is a comment",
		"#\\\\\\\\",
		"This is no comment",
		"#\\\\\\\\\\",
		"This is a comment",
		"#\\\\\\\\\\\\",
		"This is no comment")

	var texts []string
	for _, line := range mklines.lines {
		texts = append(texts, line.Text)
	}

	c.Check(texts, deepEquals, []string{
		"# This is a comment",
		"",
		"# Multiline comment",
		"# Another escaped comment that goes on",
		"# This is NOT an escaped comment due to the double backslashes \\",
		"VAR=\tThis is not a comment",
		"",
		"# This is a comment",
		"#\\",
		"This is no comment",
		"#\\ This is a comment",
		"#\\\\",
		"This is no comment",
		"#\\\\ This is a comment",
		"#\\\\\\",
		"This is no comment"})

	var rawTexts []string
	for _, line := range mklines.lines {
		for _, rawLine := range line.raw {
			rawTexts = append(rawTexts, rawLine.textnl)
		}
	}

	c.Check(rawTexts, deepEquals, []string{
		"# This is a comment\n",
		"\n",
		"#\\\n",
		"\tMultiline comment\n",
		"# Another escaped comment \\\n",
		"that \\\n",
		"goes \\\n",
		"on\n",
		"# This is NOT an escaped comment due to the double backslashes \\\\\n",
		"VAR=\tThis is not a comment\n",
		"\n",
		"#\\\n",
		"This is a comment\n",
		"#\\\\\n",
		"This is no comment\n",
		"#\\\\\\\n",
		"This is a comment\n",
		"#\\\\\\\\\n",
		"This is no comment\n",
		"#\\\\\\\\\\\n",
		"This is a comment\n",
		"#\\\\\\\\\\\\\n",
		"This is no comment\n"})

	// This is just a side-effect and not relevant for this particular test.
	t.CheckOutputLines(
		"ERROR: ~/comment.mk:15: Unknown Makefile line format.",
		"ERROR: ~/comment.mk:19: Unknown Makefile line format.",
		"ERROR: ~/comment.mk:23: Unknown Makefile line format.")
}

func (s *Suite) Test_convertToLogicalLines_continuationInLastLine(c *check.C) {
	t := s.Init(c)

	rawText := "" +
		"last line\\"

	lines := convertToLogicalLines("fname_contlast", rawText, true)

	c.Check(lines, check.HasLen, 1)
	c.Check(lines[0].String(), equals, "fname_contlast:1: last line\\")
	t.CheckOutputLines(
		"ERROR: fname_contlast:EOF: File must end with a newline.")
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

func (s *Suite) Test_Load(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("empty")

	func() {
		defer t.ExpectFatalError()
		Load(t.File("does-not-exist"), MustSucceed)
	}()

	func() {
		defer t.ExpectFatalError()
		Load(t.File("empty"), MustSucceed|NotEmpty)
	}()

	t.CheckOutputLines(
		"FATAL: ~/does-not-exist: Cannot be read.",
		"FATAL: ~/empty: Must not be empty.")
}
