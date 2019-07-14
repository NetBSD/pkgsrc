package pkglint

import (
	"gopkg.in/check.v1"
	"netbsd.org/pkglint/textproc"
)

func (s *Suite) Test_MkTokensLexer__empty_slice_returns_EOF(c *check.C) {
	t := s.Init(c)

	lexer := NewMkTokensLexer(nil)

	t.CheckEquals(lexer.EOF(), true)
}

// A slice of a single token behaves like textproc.Lexer.
func (s *Suite) Test_MkTokensLexer__single_plain_text_token(c *check.C) {
	t := s.Init(c)

	lexer := NewMkTokensLexer([]*MkToken{{"\\# $$ [#] $V", nil}})

	t.CheckEquals(lexer.SkipByte('\\'), true)
	t.CheckEquals(lexer.Rest(), "# $$ [#] $V")
	t.CheckEquals(lexer.SkipByte('#'), true)
	t.CheckEquals(lexer.NextHspace(), " ")
	t.CheckEquals(lexer.NextBytesSet(textproc.Space.Inverse()), "$$")
	t.CheckEquals(lexer.Skip(len(lexer.Rest())), true)
	t.CheckEquals(lexer.EOF(), true)
}

// If the first element of the slice is a variable use, none of the plain
// text patterns matches.
//
// The code that uses the MkTokensLexer needs to distinguish these cases
// anyway, therefore it doesn't make sense to treat variable uses as plain
// text.
func (s *Suite) Test_MkTokensLexer__single_varuse_token(c *check.C) {
	t := s.Init(c)

	lexer := NewMkTokensLexer([]*MkToken{{"${VAR:Mpattern}", NewMkVarUse("VAR", "Mpattern")}})

	t.CheckEquals(lexer.EOF(), false)
	t.CheckEquals(lexer.PeekByte(), -1)
	t.CheckDeepEquals(lexer.NextVarUse(), NewMkVarUse("VAR", "Mpattern"))
}

func (s *Suite) Test_MkTokensLexer__plain_then_varuse(c *check.C) {
	t := s.Init(c)

	lexer := NewMkTokensLexer([]*MkToken{
		{"plain text", nil},
		{"${VAR:Mpattern}", NewMkVarUse("VAR", "Mpattern")}})

	t.CheckEquals(lexer.NextBytesSet(textproc.Digit.Inverse()), "plain text")
	t.CheckDeepEquals(lexer.NextVarUse(), NewMkVarUse("VAR", "Mpattern"))
	t.CheckEquals(lexer.EOF(), true)
}

func (s *Suite) Test_MkTokensLexer__varuse_varuse_varuse(c *check.C) {
	t := s.Init(c)

	lexer := NewMkTokensLexer([]*MkToken{
		{"${dirs:O:u}", NewMkVarUse("dirs", "O", "u")},
		{"${VAR:Mpattern}", NewMkVarUse("VAR", "Mpattern")},
		{"${.TARGET}", NewMkVarUse(".TARGET")}})

	t.CheckDeepEquals(lexer.NextVarUse(), NewMkVarUse("dirs", "O", "u"))
	t.CheckDeepEquals(lexer.NextVarUse(), NewMkVarUse("VAR", "Mpattern"))
	t.CheckDeepEquals(lexer.NextVarUse(), NewMkVarUse(".TARGET"))
	t.Check(lexer.NextVarUse(), check.IsNil)
}

func (s *Suite) Test_MkTokensLexer__mark_reset_since_in_initial_state(c *check.C) {
	t := s.Init(c)

	lexer := NewMkTokensLexer([]*MkToken{
		{"${dirs:O:u}", NewMkVarUse("dirs", "O", "u")},
		{"${VAR:Mpattern}", NewMkVarUse("VAR", "Mpattern")},
		{"${.TARGET}", NewMkVarUse(".TARGET")}})

	start := lexer.Mark()
	t.CheckDeepEquals(lexer.NextVarUse(), NewMkVarUse("dirs", "O", "u"))
	middle := lexer.Mark()
	t.CheckEquals(lexer.Rest(), "${VAR:Mpattern}${.TARGET}")
	lexer.Reset(start)
	t.CheckEquals(lexer.Rest(), "${dirs:O:u}${VAR:Mpattern}${.TARGET}")
	lexer.Reset(middle)
	t.CheckEquals(lexer.Rest(), "${VAR:Mpattern}${.TARGET}")
}

func (s *Suite) Test_MkTokensLexer__mark_reset_since_inside_plain_text(c *check.C) {
	t := s.Init(c)

	lexer := NewMkTokensLexer([]*MkToken{
		{"plain text", nil},
		{"${VAR:Mpattern}", NewMkVarUse("VAR", "Mpattern")},
		{"rest", nil}})

	start := lexer.Mark()
	t.CheckEquals(lexer.NextBytesSet(textproc.Alpha), "plain")
	middle := lexer.Mark()
	t.CheckEquals(lexer.Rest(), " text${VAR:Mpattern}rest")
	lexer.Reset(start)
	t.CheckEquals(lexer.Rest(), "plain text${VAR:Mpattern}rest")
	lexer.Reset(middle)
	t.CheckEquals(lexer.Rest(), " text${VAR:Mpattern}rest")
}

func (s *Suite) Test_MkTokensLexer__mark_reset_since_after_plain_text(c *check.C) {
	t := s.Init(c)

	lexer := NewMkTokensLexer([]*MkToken{
		{"plain text", nil},
		{"${VAR:Mpattern}", NewMkVarUse("VAR", "Mpattern")},
		{"rest", nil}})

	start := lexer.Mark()
	t.CheckEquals(lexer.SkipString("plain text"), true)
	end := lexer.Mark()
	t.CheckEquals(lexer.Rest(), "${VAR:Mpattern}rest")
	lexer.Reset(start)
	t.CheckEquals(lexer.Rest(), "plain text${VAR:Mpattern}rest")
	lexer.Reset(end)
	t.CheckEquals(lexer.Rest(), "${VAR:Mpattern}rest")
}

func (s *Suite) Test_MkTokensLexer__mark_reset_since_after_varuse(c *check.C) {
	t := s.Init(c)

	lexer := NewMkTokensLexer([]*MkToken{
		{"${VAR:Mpattern}", NewMkVarUse("VAR", "Mpattern")},
		{"rest", nil}})

	start := lexer.Mark()
	t.CheckDeepEquals(lexer.NextVarUse(), NewMkVarUse("VAR", "Mpattern"))
	end := lexer.Mark()
	t.CheckEquals(lexer.Rest(), "rest")
	lexer.Reset(start)
	t.CheckEquals(lexer.Rest(), "${VAR:Mpattern}rest")
	lexer.Reset(end)
	t.CheckEquals(lexer.Rest(), "rest")
}

func (s *Suite) Test_MkTokensLexer__multiple_marks_in_same_plain_text(c *check.C) {
	t := s.Init(c)

	lexer := NewMkTokensLexer([]*MkToken{
		{"plain text", nil},
		{"${VAR:Mpattern}", NewMkVarUse("VAR", "Mpattern")},
		{"rest", nil}})

	start := lexer.Mark()
	t.CheckEquals(lexer.NextString("plain "), "plain ")
	middle := lexer.Mark()
	t.CheckEquals(lexer.NextString("text"), "text")
	end := lexer.Mark()
	t.CheckEquals(lexer.Rest(), "${VAR:Mpattern}rest")
	lexer.Reset(start)
	t.CheckEquals(lexer.Rest(), "plain text${VAR:Mpattern}rest")
	lexer.Reset(middle)
	t.CheckEquals(lexer.Rest(), "text${VAR:Mpattern}rest")
	lexer.Reset(end)
	t.CheckEquals(lexer.Rest(), "${VAR:Mpattern}rest")
}

func (s *Suite) Test_MkTokensLexer__multiple_marks_in_varuse(c *check.C) {
	t := s.Init(c)

	lexer := NewMkTokensLexer([]*MkToken{
		{"${VAR1}", NewMkVarUse("VAR1")},
		{"${VAR2}", NewMkVarUse("VAR2")},
		{"${VAR3}", NewMkVarUse("VAR3")}})

	start := lexer.Mark()
	t.CheckDeepEquals(lexer.NextVarUse(), NewMkVarUse("VAR1"))
	middle := lexer.Mark()
	t.CheckDeepEquals(lexer.NextVarUse(), NewMkVarUse("VAR2"))
	further := lexer.Mark()
	t.CheckDeepEquals(lexer.NextVarUse(), NewMkVarUse("VAR3"))
	end := lexer.Mark()
	t.CheckEquals(lexer.Rest(), "")
	lexer.Reset(middle)
	t.CheckEquals(lexer.Rest(), "${VAR2}${VAR3}")
	lexer.Reset(further)
	t.CheckEquals(lexer.Rest(), "${VAR3}")
	lexer.Reset(start)
	t.CheckEquals(lexer.Rest(), "${VAR1}${VAR2}${VAR3}")
	lexer.Reset(end)
	t.CheckEquals(lexer.Rest(), "")
}

func (s *Suite) Test_MkTokensLexer__EOF_before_plain_text(c *check.C) {
	t := s.Init(c)

	lexer := NewMkTokensLexer([]*MkToken{{"rest", nil}})

	t.CheckEquals(lexer.EOF(), false)
}

func (s *Suite) Test_MkTokensLexer__EOF_before_varuse(c *check.C) {
	t := s.Init(c)

	lexer := NewMkTokensLexer([]*MkToken{{"${VAR}", NewMkVarUse("VAR")}})

	t.CheckEquals(lexer.EOF(), false)
}

// When the MkTokensLexer is constructed, it gets a copy of the tokens array.
// In theory it would be possible to change the tokens after starting lexing,
// but there is no practical case where that would be useful.
//
// Since each slice is a separate view on the underlying array, modifying the
// size of the outside slice does not affect parsing. This is also only a
// theoretical case.
//
// Because all these cases are only theoretical, the MkTokensLexer doesn't
// bother to make this unnecessary copy and works on the shared slice.
func (s *Suite) Test_MkTokensLexer__constructor_uses_shared_array(c *check.C) {
	t := s.Init(c)

	tokens := []*MkToken{{"${VAR}", NewMkVarUse("VAR")}}
	lexer := NewMkTokensLexer(tokens)

	t.CheckEquals(lexer.Rest(), "${VAR}")

	tokens[0].Text = "modified text"
	tokens[0].Varuse = NewMkVarUse("MODIFIED", "Mpattern")

	t.CheckEquals(lexer.Rest(), "modified text")
}

func (s *Suite) Test_MkTokensLexer__peek_after_varuse(c *check.C) {
	t := s.Init(c)

	lexer := NewMkTokensLexer([]*MkToken{
		{"${VAR}", NewMkVarUse("VAR")},
		{"${VAR}", NewMkVarUse("VAR")},
		{"text", nil}})

	t.CheckDeepEquals(lexer.NextVarUse(), NewMkVarUse("VAR"))
	t.CheckEquals(lexer.PeekByte(), -1)

	t.CheckDeepEquals(lexer.NextVarUse(), NewMkVarUse("VAR"))
	t.CheckEquals(lexer.PeekByte(), int('t'))
}

func (s *Suite) Test_MkTokensLexer__varuse_when_plain_text(c *check.C) {
	t := s.Init(c)

	lexer := NewMkTokensLexer([]*MkToken{{"text", nil}})

	t.Check(lexer.NextVarUse(), check.IsNil)
	t.CheckEquals(lexer.NextString("te"), "te")
	t.Check(lexer.NextVarUse(), check.IsNil)
	t.CheckEquals(lexer.NextString("xt"), "xt")
	t.Check(lexer.NextVarUse(), check.IsNil)
}

// The code that creates the tokens for the lexer never puts two
// plain text MkTokens besides each other. There's no point in doing
// that since they could have been combined into a single token from
// the beginning.
func (s *Suite) Test_MkTokensLexer__adjacent_plain_text(c *check.C) {
	t := s.Init(c)

	lexer := NewMkTokensLexer([]*MkToken{
		{"text1", nil},
		{"text2", nil}})

	// Returns false since the string is distributed over two separate tokens.
	t.CheckEquals(lexer.SkipString("text1text2"), false)

	t.CheckEquals(lexer.SkipString("text1"), true)

	// This returns false since the internal lexer is not advanced to the
	// next text token. To do that, all methods from the internal lexer
	// would have to be redefined by MkTokensLexer in order to advance the
	// internal lexer to the next token.
	//
	// Since this situation doesn't occur in practice, there's no point in
	// implementing it.
	t.CheckEquals(lexer.SkipString("text2"), false)

	// Just for covering the "Varuse != nil" branch in MkTokensLexer.NextVarUse.
	t.Check(lexer.NextVarUse(), check.IsNil)

	// The string is still not found since the next token is only consumed
	// by the NextVarUse above if it is indeed a VarUse.
	t.CheckEquals(lexer.SkipString("text2"), false)
}
