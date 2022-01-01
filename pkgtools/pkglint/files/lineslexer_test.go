package pkglint

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_NewLinesLexer(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("file.txt",
		"line 1")

	llex := NewLinesLexer(lines)

	t.CheckEquals(llex.line, lines.Lines[0])
}

func (s *Suite) Test_LinesLexer_CurrentLine(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("file.txt",
		"line 1")

	llex := NewLinesLexer(lines)

	t.CheckEquals(llex.CurrentLine(), lines.Lines[0])

	llex.Skip()

	t.CheckEquals(llex.CurrentLine().Linenos(), "EOF")
}

func (s *Suite) Test_LinesLexer_PreviousLine(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("file.txt",
		"line 1")

	llex := NewLinesLexer(lines)

	t.ExpectPanicMatches(func() { llex.PreviousLine() }, `.*index out of range.*`)

	llex.Skip()

	t.CheckEquals(llex.PreviousLine(), lines.Lines[0])
}

func (s *Suite) Test_LinesLexer_EOF(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("file.txt",
		"line 1")

	llex := NewLinesLexer(lines)

	t.CheckEquals(llex.EOF(), false)

	llex.Skip()

	t.CheckEquals(llex.EOF(), true)
}

func (s *Suite) Test_LinesLexer_Skip(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("file.txt",
		"line 1")

	llex := NewLinesLexer(lines)

	t.CheckEquals(llex.Skip(), true)
	t.CheckEquals(llex.Skip(), false)
}

func (s *Suite) Test_LinesLexer_Undo(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("file.txt",
		"line 1")

	llex := NewLinesLexer(lines)

	t.CheckEquals(llex.Skip(), true)

	llex.Undo()

	t.CheckEquals(llex.CurrentLine(), lines.Lines[0])
}

func (s *Suite) Test_LinesLexer_NextRegexp(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("file.txt",
		"line 1")

	llex := NewLinesLexer(lines)

	t.CheckNil(llex.NextRegexp(`not found`))
	t.CheckDeepEquals(llex.NextRegexp(`ne..`), []string{"ne 1"})

	t.CheckEquals(llex.EOF(), true)

	t.CheckNil(llex.NextRegexp(`^`))
}

func (s *Suite) Test_LinesLexer_SkipRegexp(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("file.txt",
		"line 1")

	llex := NewLinesLexer(lines)

	t.CheckEquals(llex.SkipRegexp(`not found`), false)
	t.CheckEquals(llex.SkipRegexp(`ne..`), true)

	t.CheckEquals(llex.EOF(), true)

	t.CheckEquals(llex.SkipRegexp(`^`), false)
}

func (s *Suite) Test_LinesLexer_SkipPrefix(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("file.txt",
		"line 1",
		"line 2")
	llex := NewLinesLexer(lines)

	t.CheckEquals(llex.SkipPrefix("line 1"), true)
	t.CheckEquals(llex.SkipPrefix("line 1"), false)
	t.CheckEquals(llex.SkipPrefix("line 2"), true)
	t.CheckEquals(llex.SkipPrefix("line 2"), false)
	t.CheckEquals(llex.SkipPrefix(""), false)
}

func (s *Suite) Test_LinesLexer_SkipText(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("file.txt",
		"line 1")
	llex := NewLinesLexer(lines)

	t.CheckEquals(llex.SkipText("line"), false)
	t.CheckEquals(llex.SkipText("line 12"), false)
	t.CheckEquals(llex.SkipText("line 1"), true)

	t.CheckEquals(llex.EOF(), true)
}

func (s *Suite) Test_LinesLexer_SkipEmptyOrNote__beginning_of_file(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("file.txt",
		"line 1",
		"line 2")
	llex := NewLinesLexer(lines)

	llex.SkipEmptyOrNote()

	t.CheckOutputLines(
		"NOTE: file.txt:1: Empty line expected above this line.")
}

func (s *Suite) Test_LinesLexer_SkipEmptyOrNote__end_of_file(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("file.txt",
		"line 1",
		"line 2")
	llex := NewLinesLexer(lines)

	for llex.Skip() {
	}

	llex.SkipEmptyOrNote()

	t.CheckOutputLines(
		"NOTE: file.txt:2: Empty line expected below this line.")
}

func (s *Suite) Test_LinesLexer_SkipTextOrWarn(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("file.txt",
		"line 1",
		"line 2")
	llex := NewLinesLexer(lines)

	llex.SkipTextOrWarn("ne")
	llex.SkipTextOrWarn("line 1")
	llex.SkipTextOrWarn("line 2")

	t.CheckEquals(llex.EOF(), true)
	t.CheckOutputLines(
		"WARN: file.txt:1: This line should consist of the following text: ne")
}

func (s *Suite) Test_LinesLexer_setIndex(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("file.txt",
		"line 1",
		"line 2")
	llex := NewLinesLexer(lines)

	llex.setIndex(1)

	t.CheckEquals(llex.CurrentLine(), lines.Lines[1])

	llex.setIndex(0)

	t.CheckEquals(llex.CurrentLine(), lines.Lines[0])

	llex.setIndex(2)

	t.CheckEquals(llex.EOF(), true)
}

func (s *Suite) Test_LinesLexer_next(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("file.txt",
		"line 1",
		"line 2")
	llex := NewLinesLexer(lines)

	llex.next()

	t.CheckEquals(llex.CurrentLine(), lines.Lines[1])

	llex.next()

	t.CheckEquals(llex.CurrentLine().Linenos(), "EOF")

	llex.next()

	t.CheckNil(llex.line)
}

func (s *Suite) Test_NewMkLinesLexer(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		"# line 1",
		"# line 2")
	mlex := NewMkLinesLexer(mklines)

	t.CheckEquals(mlex.CurrentMkLine(), mklines.mklines[0])
}

func (s *Suite) Test_MkLinesLexer_PreviousMkLine(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		"# line 1",
		"# line 2")
	mlex := NewMkLinesLexer(mklines)

	t.ExpectPanicMatches(func() { mlex.PreviousMkLine() }, `.*index out of range.*`)

	mlex.Skip()

	t.CheckEquals(mlex.PreviousMkLine().Linenos(), "1")
}

func (s *Suite) Test_MkLinesLexer_CurrentMkLine(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		"# line 1",
		"# line 2")
	mlex := NewMkLinesLexer(mklines)

	t.CheckEquals(mlex.CurrentMkLine(), mklines.mklines[0])

	mlex.Skip()

	t.CheckEquals(mlex.CurrentMkLine(), mklines.mklines[1])

	mlex.Skip()

	t.ExpectPanicMatches(func() { mlex.CurrentMkLine() }, `.*index out of range.*`)
}

func (s *Suite) Test_MkLinesLexer_SkipIf(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		"# comment",
		"VAR=\tnot a comment")
	mlex := NewMkLinesLexer(mklines)

	t.CheckEquals(mlex.SkipIf((*MkLine).IsComment), true)
	t.CheckEquals(mlex.SkipIf((*MkLine).IsComment), false)
	t.CheckEquals(mlex.SkipIf((*MkLine).IsVarassign), true)
	t.CheckEquals(mlex.SkipIf((*MkLine).IsVarassign), false)
	t.CheckEquals(mlex.EOF(), true)
}
