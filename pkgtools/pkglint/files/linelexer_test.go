package pkglint

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_LinesLexer_SkipEmptyOrNote__beginning_of_file(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("file.txt",
		"line 1",
		"line 2")
	llex := NewLinesLexer(lines)

	llex.SkipEmptyOrNote()

	t.CheckOutputLines(
		"NOTE: file.txt:1: Empty line expected before this line.")
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
		"NOTE: file.txt:2: Empty line expected after this line.")
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
