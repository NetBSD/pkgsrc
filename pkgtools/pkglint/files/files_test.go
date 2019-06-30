package pkglint

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_convertToLogicalLines__no_continuation(c *check.C) {
	rawText := "" +
		"first line\n" +
		"second line\n"

	lines := convertToLogicalLines("filename", rawText, false)

	c.Check(lines.Len(), equals, 2)
	c.Check(lines.Lines[0].String(), equals, "filename:1: first line")
	c.Check(lines.Lines[1].String(), equals, "filename:2: second line")
}

func (s *Suite) Test_convertToLogicalLines__continuation(c *check.C) {
	rawText := "" +
		"first line, \\\n" +
		"still first line\n" +
		"second line\n"

	lines := convertToLogicalLines("filename", rawText, true)

	c.Check(lines.Len(), equals, 2)
	c.Check(lines.Lines[0].String(), equals, "filename:1--2: first line, still first line")
	c.Check(lines.Lines[1].String(), equals, "filename:3: second line")
}

func (s *Suite) Test_convertToLogicalLines__continuation_in_last_line(c *check.C) {
	t := s.Init(c)

	rawText := "" +
		"last line\\\n"

	lines := convertToLogicalLines("filename", rawText, true)

	c.Check(lines.Len(), equals, 1)
	c.Check(lines.Lines[0].String(), equals, "filename:1: last line\\")
	t.CheckOutputEmpty()
}

// In Makefiles, comment lines can also have continuations.
// See devel/bmake/files/unit-tests/comment.mk
func (s *Suite) Test_convertToLogicalLines__comments(c *check.C) {
	t := s.Init(c)

	mklines := t.SetUpFileMkLines("comment.mk",
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

func (s *Suite) Test_nextLogicalLine__commented_multi(c *check.C) {
	t := s.Init(c)

	mklines := t.SetUpFileMkLines("filename.mk",
		"#COMMENTED= \\",
		"#\tcontinuation 1 \\",
		"#\tcontinuation 2")
	mkline := mklines.mklines[0]

	// The leading comments are stripped from the continuation lines as well.
	t.Check(mkline.Value(), equals, "continuation 1 \tcontinuation 2")
	t.Check(mkline.VarassignComment(), equals, "")
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

	lines := convertToLogicalLines("filename", rawText, true)

	c.Check(lines.Len(), equals, 1)
	c.Check(lines.Lines[0].String(), equals, "filename:1: last line\\")
	t.CheckOutputLines(
		"ERROR: filename:1: File must end with a newline.")
}

func (s *Suite) Test_convertToLogicalLines__missing_newline_at_eof_with_source(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--source")
	rawText := "" +
		"last line\\"

	lines := convertToLogicalLines("filename", rawText, true)

	c.Check(lines.Len(), equals, 1)
	c.Check(lines.Lines[0].String(), equals, "filename:1: last line\\")
	t.CheckOutputLines(
		">\tlast line\\",
		"ERROR: filename:1: File must end with a newline.")
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

func (s *Suite) Test_Load(c *check.C) {
	t := s.Init(c)

	nonexistent := t.File("nonexistent")
	empty := t.CreateFileLines("empty")
	oneLiner := t.CreateFileLines("one-liner",
		"hello, world")

	t.Check(Load(nonexistent, 0), check.IsNil)
	t.Check(Load(empty, 0).Lines, check.HasLen, 0)
	t.Check(Load(oneLiner, 0).Lines[0].Text, equals, "hello, world")

	t.CheckOutputEmpty()

	t.Check(Load(nonexistent, LogErrors), check.IsNil)
	t.Check(Load(empty, LogErrors).Lines, check.HasLen, 0)
	t.Check(Load(oneLiner, LogErrors).Lines[0].Text, equals, "hello, world")

	t.CheckOutputLines(
		"ERROR: ~/nonexistent: Cannot be read.")

	t.Check(Load(nonexistent, NotEmpty), check.IsNil)
	t.Check(Load(empty, NotEmpty), check.IsNil)
	t.Check(Load(oneLiner, NotEmpty).Lines[0].Text, equals, "hello, world")

	t.CheckOutputEmpty()

	t.Check(Load(nonexistent, NotEmpty|LogErrors), check.IsNil)
	t.Check(Load(empty, NotEmpty|LogErrors), check.IsNil)
	t.Check(Load(oneLiner, NotEmpty|LogErrors).Lines[0].Text, equals, "hello, world")

	t.CheckOutputLines(
		"ERROR: ~/nonexistent: Cannot be read.",
		"ERROR: ~/empty: Must not be empty.")

	t.ExpectFatal(
		func() { Load(t.File("does-not-exist"), MustSucceed) },
		"FATAL: ~/does-not-exist: Cannot be read.")

	t.ExpectFatal(
		func() { Load(t.File("empty"), MustSucceed|NotEmpty) },
		"FATAL: ~/empty: Must not be empty.")
}
