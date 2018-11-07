package main

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_convertToLogicalLines__no_continuation(c *check.C) {
	rawText := "" +
		"first line\n" +
		"second line\n"

	lines := convertToLogicalLines("fileName", rawText, false)

	c.Check(lines.Len(), equals, 2)
	c.Check(lines.Lines[0].String(), equals, "fileName:1: first line")
	c.Check(lines.Lines[1].String(), equals, "fileName:2: second line")
}

func (s *Suite) Test_convertToLogicalLines__continuation(c *check.C) {
	rawText := "" +
		"first line, \\\n" +
		"still first line\n" +
		"second line\n"

	lines := convertToLogicalLines("fileName", rawText, true)

	c.Check(lines.Len(), equals, 2)
	c.Check(lines.Lines[0].String(), equals, "fileName:1--2: first line, still first line")
	c.Check(lines.Lines[1].String(), equals, "fileName:3: second line")
}

func (s *Suite) Test_convertToLogicalLines__continuation_in_last_line(c *check.C) {
	t := s.Init(c)

	rawText := "" +
		"last line\\\n"

	lines := convertToLogicalLines("fileName", rawText, true)

	c.Check(lines.Len(), equals, 1)
	c.Check(lines.Lines[0].String(), equals, "fileName:1: last line\\")
	t.CheckOutputEmpty()
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
		"on and on",
		"# This is NOT an escaped comment due to the double backslashes \\\\",
		"VAR=\tThis is not a comment",
		"",
		"#\\",
		"\tThis is a comment",
		"#\\\\",
		"\tThis is no comment",
		"#\\\\\\",
		"\tThis is a comment",
		"#\\\\\\\\",
		"\tThis is no comment",
		"#\\\\\\\\\\",
		"\tThis is a comment",
		"#\\\\\\\\\\\\",
		"\tThis is no comment")

	var texts []string
	for _, line := range mklines.lines.Lines {
		texts = append(texts, line.Text)
	}

	c.Check(texts, deepEquals, []string{
		"# This is a comment",
		"",
		"# Multiline comment",
		"# Another escaped comment that goes on and on",
		"# This is NOT an escaped comment due to the double backslashes \\",
		"VAR=\tThis is not a comment",
		"",
		"# This is a comment",
		"#\\",
		"\tThis is no comment",
		"#\\ This is a comment",
		"#\\\\",
		"\tThis is no comment",
		"#\\\\ This is a comment",
		"#\\\\\\",
		"\tThis is no comment"})

	t.CheckOutputEmpty()
}

func (s *Suite) Test_convertToLogicalLines__missing_newline_at_eof(c *check.C) {
	t := s.Init(c)

	rawText := "" +
		"The package description\n" +
		"takes 2 lines"

	lines := convertToLogicalLines("DESCR", rawText, true)

	c.Check(lines.Len(), equals, 2)
	c.Check(lines.Lines[1].String(), equals, "DESCR:2: takes 2 lines")
	t.CheckOutputLines(
		"ERROR: DESCR:2: File must end with a newline.")
}

func (s *Suite) Test_convertToLogicalLines__missing_newline_at_eof_in_continuation_line(c *check.C) {
	t := s.Init(c)

	rawText := "" +
		"last line\\"

	lines := convertToLogicalLines("fileName", rawText, true)

	c.Check(lines.Len(), equals, 1)
	c.Check(lines.Lines[0].String(), equals, "fileName:1: last line\\")
	t.CheckOutputLines(
		"ERROR: fileName:1: File must end with a newline.")
}

func (s *Suite) Test_matchContinuationLine(c *check.C) {
	leadingWhitespace, text, trailingWhitespace, continuation := matchContinuationLine("\n")

	c.Check(leadingWhitespace, equals, "")
	c.Check(text, equals, "")
	c.Check(trailingWhitespace, equals, "")
	c.Check(continuation, equals, "")

	leadingWhitespace, text, trailingWhitespace, continuation = matchContinuationLine("\tword   \\\n")

	c.Check(leadingWhitespace, equals, "\t")
	c.Check(text, equals, "word")
	c.Check(trailingWhitespace, equals, "   ")
	c.Check(continuation, equals, "\\")
}

func (s *Suite) Test_Load__errors(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("empty")

	t.ExpectFatal(
		func() { Load(t.File("does-not-exist"), MustSucceed) },
		"FATAL: ~/does-not-exist: Cannot be read.")

	t.ExpectFatal(
		func() { Load(t.File("empty"), MustSucceed|NotEmpty) },
		"FATAL: ~/empty: Must not be empty.")
}
