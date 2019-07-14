package pkglint

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_convertToLogicalLines__no_continuation(c *check.C) {
	t := s.Init(c)

	rawText := "" +
		"first line\n" +
		"second line\n"

	lines := convertToLogicalLines("filename", rawText, false)

	t.CheckEquals(lines.Len(), 2)
	t.CheckEquals(lines.Lines[0].String(), "filename:1: first line")
	t.CheckEquals(lines.Lines[1].String(), "filename:2: second line")
}

func (s *Suite) Test_convertToLogicalLines__continuation(c *check.C) {
	t := s.Init(c)

	rawText := "" +
		"first line, \\\n" +
		"still first line\n" +
		"second line\n"

	lines := convertToLogicalLines("filename", rawText, true)

	t.CheckEquals(lines.Len(), 2)
	t.CheckEquals(lines.Lines[0].String(), "filename:1--2: first line, still first line")
	t.CheckEquals(lines.Lines[1].String(), "filename:3: second line")
}

func (s *Suite) Test_convertToLogicalLines__continuation_in_last_line(c *check.C) {
	t := s.Init(c)

	rawText := "" +
		"last line\\\n"

	lines := convertToLogicalLines("filename", rawText, true)

	t.CheckEquals(lines.Len(), 1)
	t.CheckEquals(lines.Lines[0].String(), "filename:1: last line\\")
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

	t.CheckDeepEquals(texts, []string{
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
	t.CheckEquals(mkline.Value(), "continuation 1 \tcontinuation 2")
	t.CheckEquals(mkline.VarassignComment(), "")
}

func (s *Suite) Test_convertToLogicalLines__missing_newline_at_eof(c *check.C) {
	t := s.Init(c)

	rawText := "" +
		"The package description\n" +
		"takes 2 lines"

	lines := convertToLogicalLines("DESCR", rawText, true)

	t.CheckEquals(lines.Len(), 2)
	t.CheckEquals(lines.Lines[1].String(), "DESCR:2: takes 2 lines")
	t.CheckOutputLines(
		"ERROR: DESCR:2: File must end with a newline.")
}

func (s *Suite) Test_convertToLogicalLines__missing_newline_at_eof_in_continuation_line(c *check.C) {
	t := s.Init(c)

	rawText := "" +
		"last line\\"

	lines := convertToLogicalLines("filename", rawText, true)

	t.CheckEquals(lines.Len(), 1)
	t.CheckEquals(lines.Lines[0].String(), "filename:1: last line\\")
	t.CheckOutputLines(
		"ERROR: filename:1: File must end with a newline.")
}

func (s *Suite) Test_convertToLogicalLines__missing_newline_at_eof_with_source(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--source")
	rawText := "" +
		"last line\\"

	lines := convertToLogicalLines("filename", rawText, true)

	t.CheckEquals(lines.Len(), 1)
	t.CheckEquals(lines.Lines[0].String(), "filename:1: last line\\")
	t.CheckOutputLines(
		">\tlast line\\",
		"ERROR: filename:1: File must end with a newline.")
}

func (s *Suite) Test_matchContinuationLine(c *check.C) {
	t := s.Init(c)

	leadingWhitespace, text, trailingWhitespace, continuation := matchContinuationLine("\n")

	t.CheckEquals(leadingWhitespace, "")
	t.CheckEquals(text, "")
	t.CheckEquals(trailingWhitespace, "")
	t.CheckEquals(continuation, "")

	leadingWhitespace, text, trailingWhitespace, continuation = matchContinuationLine("\tword   \\\n")

	t.CheckEquals(leadingWhitespace, "\t")
	t.CheckEquals(text, "word")
	t.CheckEquals(trailingWhitespace, "   ")
	t.CheckEquals(continuation, "\\")
}

func (s *Suite) Test_Load(c *check.C) {
	t := s.Init(c)

	nonexistent := t.File("nonexistent")
	empty := t.CreateFileLines("empty")
	oneLiner := t.CreateFileLines("one-liner",
		"hello, world")

	t.Check(Load(nonexistent, 0), check.IsNil)
	t.Check(Load(empty, 0).Lines, check.HasLen, 0)
	t.CheckEquals(Load(oneLiner, 0).Lines[0].Text, "hello, world")

	t.CheckOutputEmpty()

	t.Check(Load(nonexistent, LogErrors), check.IsNil)
	t.Check(Load(empty, LogErrors).Lines, check.HasLen, 0)
	t.CheckEquals(Load(oneLiner, LogErrors).Lines[0].Text, "hello, world")

	t.CheckOutputLines(
		"ERROR: ~/nonexistent: Cannot be read.")

	t.Check(Load(nonexistent, NotEmpty), check.IsNil)
	t.Check(Load(empty, NotEmpty), check.IsNil)
	t.CheckEquals(Load(oneLiner, NotEmpty).Lines[0].Text, "hello, world")

	t.CheckOutputEmpty()

	t.Check(Load(nonexistent, NotEmpty|LogErrors), check.IsNil)
	t.Check(Load(empty, NotEmpty|LogErrors), check.IsNil)
	t.CheckEquals(Load(oneLiner, NotEmpty|LogErrors).Lines[0].Text, "hello, world")

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
