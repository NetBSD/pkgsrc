package pkglint

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_LoadMk(c *check.C) {
	t := s.Init(c)

	t.Chdir(".")
	t.CreateFileLines("filename.mk",
		"# line 1 \\",
		"# continues in line 2")

	mklines := LoadMk("filename.mk", nil, 0)

	t.CheckEquals(len(mklines.mklines), 1)
	// The '#' from line 2 is discarded in nextLogicalLine, to properly
	// parse multi-line variable assignments that are commented out.
	// See Test_MkLineParser_MatchVarassign, 'multi-line variable'.
	t.CheckEquals(mklines.mklines[0].Text, "# line 1  continues in line 2")
}

func (s *Suite) Test_Load(c *check.C) {
	t := s.Init(c)

	nonexistent := t.File("nonexistent")
	empty := t.CreateFileLines("empty",
		nil...)
	oneLiner := t.CreateFileLines("one-liner",
		"hello, world")

	t.CheckNil(Load(nonexistent, 0))
	t.CheckLen(Load(empty, 0).Lines, 0)
	t.CheckEquals(Load(oneLiner, 0).Lines[0].Text, "hello, world")

	t.CheckOutputEmpty()

	t.CheckNil(Load(nonexistent, LogErrors))
	t.CheckLen(Load(empty, LogErrors).Lines, 0)
	t.CheckEquals(Load(oneLiner, LogErrors).Lines[0].Text, "hello, world")

	t.CheckOutputLines(
		"ERROR: ~/nonexistent: Cannot be read.")

	t.CheckNil(Load(nonexistent, NotEmpty))
	t.CheckNil(Load(empty, NotEmpty))
	t.CheckEquals(Load(oneLiner, NotEmpty).Lines[0].Text, "hello, world")

	// Specifying NotEmpty only makes sense when combined with LogErrors
	// or with MustSucceed.  On its own, NotEmpty returns nil in error
	// cases, which is indistinguishable from an empty slice.
	t.CheckOutputEmpty()

	t.CheckNil(Load(nonexistent, NotEmpty|LogErrors))
	t.CheckNil(Load(empty, NotEmpty|LogErrors))
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

// Up to 2019-12-04, pkglint suppressed fatal errors when it was started
// with the --autofix option. This was another case where the clear
// separation between diagnostics and technical errors had been confused.
func (s *Suite) Test_Load__not_found_in_autofix_mode(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--autofix")
	t.Chdir(".")

	t.ExpectFatal(
		func() { Load("nonexistent", MustSucceed) },
		"FATAL: nonexistent: Cannot be read.")
}

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

// This test demonstrates that pkglint deviates from bmake.
// Bmake keeps all the trailing whitespace from the line and replaces the
// backslash plus any indentation with a single space. This results in:
//  "\tprintf '%s\\n' 'none none  space  space  tab\t tab'"
// This is another of the edge cases probably no-one relies on.
func (s *Suite) Test_convertToLogicalLines__continuation_spacing(c *check.C) {
	t := s.Init(c)

	rawText := "" +
		"\tprintf '%s\\n' 'none\\\n" +
		"none\\\n" +
		"space \\\n" +
		" space \\\n" +
		"tab\t\\\n" +
		"\ttab'\n"

	lines := convertToLogicalLines("filename", rawText, true)

	t.CheckEquals(lines.Lines[0].Text,
		"\tprintf '%s\\n' 'none none space space tab tab'")
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
		"# This is NOT an escaped comment due to the double backslashes \\\\",
		"VAR=\tThis is not a comment",
		"",
		"# This is a comment",
		"#\\\\",
		"\tThis is no comment",
		"#\\\\ This is a comment",
		"#\\\\\\\\",
		"\tThis is no comment",
		"#\\\\\\\\ This is a comment",
		"#\\\\\\\\\\\\",
		"\tThis is no comment"})

	t.CheckOutputEmpty()
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

func (s *Suite) Test_nextLogicalLine__commented_multi(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		"#COMMENTED= \\",
		"#\tcontinuation 1 \\",
		"#\tcontinuation 2")
	mkline := mklines.mklines[0]

	// The leading comments are stripped from the continuation lines as well.
	t.CheckEquals(mkline.Value(), "continuation 1 \tcontinuation 2")
	t.CheckEquals(mkline.HasComment(), false)
}

func (s *Suite) Test_matchContinuationLine(c *check.C) {
	t := s.Init(c)

	leadingWhitespace, text, trailingWhitespace, continuation := matchContinuationLine("")

	t.CheckEquals(leadingWhitespace, "")
	t.CheckEquals(text, "")
	t.CheckEquals(trailingWhitespace, "")
	t.CheckEquals(continuation, "")

	leadingWhitespace, text, trailingWhitespace, continuation = matchContinuationLine("\tword   \\")

	t.CheckEquals(leadingWhitespace, "\t")
	t.CheckEquals(text, "word")
	t.CheckEquals(trailingWhitespace, "   ")
	t.CheckEquals(continuation, "\\")
}
