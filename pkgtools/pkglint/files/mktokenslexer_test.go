package pkglint

import (
	"gopkg.in/check.v1"
	"netbsd.org/pkglint/textproc"
)

// A slice of a single token behaves like textproc.Lexer.
func (s *Suite) Test_MkTokensLexer__single_plain_text_token(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	lexer := NewMkTokensLexer(b.Tokens(b.TextToken("\\# $$ [#] $V")))

	t.CheckEquals(lexer.SkipByte('\\'), true)
	t.CheckEquals(lexer.Rest(), "# $$ [#] $V")
	t.CheckEquals(lexer.SkipByte('#'), true)
	t.CheckEquals(lexer.NextHspace(), " ")
	t.CheckEquals(lexer.NextBytesSet(textproc.Space.Inverse()), "$$")
	t.CheckEquals(lexer.Skip(len(lexer.Rest())), true)
	t.CheckEquals(lexer.EOF(), true)
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
func (s *Suite) Test_NewMkTokensLexer__shared_array(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	tokens := b.Tokens(b.VaruseToken("VAR"))
	lexer := NewMkTokensLexer(tokens)

	t.CheckEquals(lexer.Rest(), "${VAR}")

	tokens[0].Text = "modified text"
	tokens[0].Varuse = b.VarUse("MODIFIED", "Mpattern")

	t.CheckEquals(lexer.Rest(), "modified text")
}

func (s *Suite) Test_MkTokensLexer_next(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	tokens := b.Tokens(b.VaruseToken("VAR"))
	lexer := NewMkTokensLexer(tokens)

	t.CheckEquals(lexer.Lexer.Rest(), "")
}

func (s *Suite) Test_MkTokensLexer_EOF__plain_text(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	lexer := NewMkTokensLexer(b.Tokens(b.TextToken("rest")))

	t.CheckEquals(lexer.EOF(), false)

	lexer.SkipString("rest")

	t.CheckEquals(lexer.EOF(), true)
}

func (s *Suite) Test_MkTokensLexer_EOF__varuse(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	lexer := NewMkTokensLexer(b.Tokens(b.VaruseToken("VAR")))

	t.CheckEquals(lexer.EOF(), false)

	lexer.NextVarUse()

	t.CheckEquals(lexer.EOF(), true)
}

func (s *Suite) Test_MkTokensLexer_Rest(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	lexer := NewMkTokensLexer(b.Tokens(b.VaruseToken("VAR"), b.TextToken("text"), b.VaruseToken("VAR2")))

	t.CheckEquals(lexer.Rest(), "${VAR}text${VAR2}")
	t.CheckEquals(lexer.NextVarUse().Text, "${VAR}")
	t.CheckEquals(lexer.Rest(), "text${VAR2}")
	t.CheckEquals(lexer.SkipString("text"), true)
	t.CheckEquals(lexer.Rest(), "${VAR2}")
	t.CheckEquals(lexer.NextVarUse().Text, "${VAR2}")
	t.CheckEquals(lexer.Rest(), "")
}

func (s *Suite) Test_MkTokensLexer_Skip(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	lexer := NewMkTokensLexer(b.Tokens(b.VaruseToken("VAR"), b.TextToken("text"), b.VaruseToken("VAR2")))

	t.CheckEquals(lexer.Rest(), "${VAR}text${VAR2}")
	t.CheckEquals(lexer.NextVarUse().Text, "${VAR}")
	t.CheckEquals(lexer.Rest(), "text${VAR2}")
	t.CheckEquals(lexer.Skip(4), true)
	t.CheckEquals(lexer.Rest(), "${VAR2}")
	t.CheckEquals(lexer.NextVarUse().Text, "${VAR2}")
	t.CheckEquals(lexer.Rest(), "")
}

func (s *Suite) Test_MkTokensLexer_SkipMixed__exact(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	lexer := NewMkTokensLexer(b.Tokens(b.VaruseToken("VAR"), b.TextToken("text"), b.VaruseToken("VAR2")))

	t.CheckEquals(lexer.SkipMixed(17), true)
	t.CheckEquals(lexer.EOF(), true)
}

func (s *Suite) Test_MkTokensLexer_SkipMixed__short(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	lexer := NewMkTokensLexer(b.Tokens(b.VaruseToken("VAR"), b.TextToken("text"), b.VaruseToken("VAR2")))

	// After 15 characters, the lexer would be in the middle of a MkVarUse.
	t.ExpectAssert(func() { lexer.SkipMixed(15) })
}

func (s *Suite) Test_MkTokensLexer_SkipMixed__long(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	lexer := NewMkTokensLexer(b.Tokens(b.VaruseToken("VAR"), b.TextToken("text"), b.VaruseToken("VAR2")))

	t.ExpectAssert(func() { lexer.SkipMixed(20) })
}

// If the first element of the slice is a variable use, none of the plain
// text patterns matches.
//
// The code that uses the MkTokensLexer needs to distinguish these cases
// anyway, therefore it doesn't make sense to treat variable uses as plain
// text.
func (s *Suite) Test_MkTokensLexer_NextVarUse__single_varuse_token(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	tokens := b.Tokens(b.VaruseToken("VAR", "Mpattern"))
	lexer := NewMkTokensLexer(tokens)

	t.CheckEquals(lexer.EOF(), false)
	t.CheckEquals(lexer.PeekByte(), -1)
	t.CheckDeepEquals(lexer.NextVarUse(), tokens[0])
}

func (s *Suite) Test_MkTokensLexer_NextVarUse__plain_then_varuse(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	tokens := b.Tokens(
		b.TextToken("plain text"),
		b.VaruseToken("VAR", "Mpattern"))
	lexer := NewMkTokensLexer(tokens)

	t.CheckEquals(lexer.NextBytesSet(textproc.Digit.Inverse()), "plain text")
	t.CheckDeepEquals(lexer.NextVarUse(), tokens[1])
	t.CheckEquals(lexer.EOF(), true)
}

func (s *Suite) Test_MkTokensLexer_NextVarUse__varuse_varuse_varuse(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	tokens := b.Tokens(
		b.VaruseToken("dirs", "O", "u"),
		b.VaruseToken("VAR", "Mpattern"),
		b.VaruseToken(".TARGET"))
	lexer := NewMkTokensLexer(tokens)

	t.CheckDeepEquals(lexer.NextVarUse(), tokens[0])
	t.CheckDeepEquals(lexer.NextVarUse(), tokens[1])
	t.CheckDeepEquals(lexer.NextVarUse(), tokens[2])
	t.CheckNil(lexer.NextVarUse())
}

func (s *Suite) Test_MkTokensLexer_NextVarUse__varuse_when_plain_text(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	lexer := NewMkTokensLexer(b.Tokens(b.TextToken("text")))

	t.CheckNil(lexer.NextVarUse())
	t.CheckEquals(lexer.NextString("te"), "te")
	t.CheckNil(lexer.NextVarUse())
	t.CheckEquals(lexer.NextString("xt"), "xt")
	t.CheckNil(lexer.NextVarUse())
}

func (s *Suite) Test_MkTokensLexer_NextVarUse__peek_after_varuse(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	tokens := b.Tokens(
		b.VaruseToken("VAR"),
		b.VaruseToken("VAR"),
		b.TextToken("text"))
	lexer := NewMkTokensLexer(tokens)

	t.CheckDeepEquals(lexer.NextVarUse(), tokens[0])
	t.CheckEquals(lexer.PeekByte(), -1)

	t.CheckDeepEquals(lexer.NextVarUse(), tokens[1])
	t.CheckEquals(lexer.PeekByte(), int('t'))
}

// The code that creates the tokens for the lexer never puts two
// plain text MkTokens besides each other. There's no point in doing
// that since they could have been combined into a single token from
// the beginning.
func (s *Suite) Test_MkTokensLexer_NextVarUse__adjacent_plain_text(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	lexer := NewMkTokensLexer(b.Tokens(
		b.TextToken("text1"),
		b.TextToken("text2")))

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
	t.CheckNil(lexer.NextVarUse())

	// The string is still not found since the next token is only consumed
	// by the NextVarUse above if it is indeed a VarUse.
	t.CheckEquals(lexer.SkipString("text2"), false)
}

func (s *Suite) Test_MkTokensLexer_Mark__multiple_marks_in_varuse(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	tokens := b.Tokens(
		b.VaruseToken("VAR1"),
		b.VaruseToken("VAR2"),
		b.VaruseToken("VAR3"))
	lexer := NewMkTokensLexer(tokens)

	start := lexer.Mark()
	t.CheckDeepEquals(lexer.NextVarUse(), tokens[0])
	middle := lexer.Mark()
	t.CheckDeepEquals(lexer.NextVarUse(), tokens[1])
	further := lexer.Mark()
	t.CheckDeepEquals(lexer.NextVarUse(), tokens[2])
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

func (s *Suite) Test_MkTokensLexer_Mark__multiple_marks_in_same_plain_text(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	lexer := NewMkTokensLexer(b.Tokens(
		b.TextToken("plain text"),
		b.VaruseToken("VAR", "Mpattern"),
		b.TextToken("rest")))

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

func (s *Suite) Test_MkTokensLexer_Since(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	tokens := b.Tokens(
		b.VaruseToken("dirs", "O", "u"),
		b.VaruseToken("VAR", "Mpattern"),
		b.VaruseToken(".TARGET"))
	lexer := NewMkTokensLexer(tokens)

	start := lexer.Mark()
	t.CheckDeepEquals(lexer.NextVarUse(), tokens[0])
	middle := lexer.Mark()
	t.CheckEquals(lexer.Since(start), "${dirs:O:u}")
	t.CheckEquals(lexer.Since(middle), "")
}

func (s *Suite) Test_MkTokensLexer_Reset__initial_state(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	tokens := b.Tokens(
		b.VaruseToken("dirs", "O", "u"),
		b.VaruseToken("VAR", "Mpattern"),
		b.VaruseToken(".TARGET"))
	lexer := NewMkTokensLexer(tokens)

	start := lexer.Mark()
	t.CheckDeepEquals(lexer.NextVarUse(), tokens[0])
	middle := lexer.Mark()
	t.CheckEquals(lexer.Rest(), "${VAR:Mpattern}${.TARGET}")
	lexer.Reset(start)
	t.CheckEquals(lexer.Rest(), "${dirs:O:u}${VAR:Mpattern}${.TARGET}")
	lexer.Reset(middle)
	t.CheckEquals(lexer.Rest(), "${VAR:Mpattern}${.TARGET}")
}

func (s *Suite) Test_MkTokensLexer_Reset__inside_plain_text(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	lexer := NewMkTokensLexer(b.Tokens(
		b.TextToken("plain text"),
		b.VaruseToken("VAR", "Mpattern"),
		b.TextToken("rest")))

	start := lexer.Mark()
	t.CheckEquals(lexer.NextBytesSet(textproc.Alpha), "plain")
	middle := lexer.Mark()
	t.CheckEquals(lexer.Rest(), " text${VAR:Mpattern}rest")
	lexer.Reset(start)
	t.CheckEquals(lexer.Rest(), "plain text${VAR:Mpattern}rest")
	lexer.Reset(middle)
	t.CheckEquals(lexer.Rest(), " text${VAR:Mpattern}rest")
}

func (s *Suite) Test_MkTokensLexer_Reset__after_plain_text(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	lexer := NewMkTokensLexer(b.Tokens(
		b.TextToken("plain text"),
		b.VaruseToken("VAR", "Mpattern"),
		b.TextToken("rest")))

	start := lexer.Mark()
	t.CheckEquals(lexer.SkipString("plain text"), true)
	end := lexer.Mark()
	t.CheckEquals(lexer.Rest(), "${VAR:Mpattern}rest")
	lexer.Reset(start)
	t.CheckEquals(lexer.Rest(), "plain text${VAR:Mpattern}rest")
	lexer.Reset(end)
	t.CheckEquals(lexer.Rest(), "${VAR:Mpattern}rest")
}

func (s *Suite) Test_MkTokensLexer_Reset__after_varuse(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	tokens := b.Tokens(
		b.VaruseToken("VAR", "Mpattern"),
		b.TextToken("rest"))
	lexer := NewMkTokensLexer(tokens)

	start := lexer.Mark()
	t.CheckEquals(lexer.NextVarUse(), tokens[0])
	end := lexer.Mark()
	t.CheckEquals(lexer.Rest(), "rest")
	lexer.Reset(start)
	t.CheckEquals(lexer.Rest(), "${VAR:Mpattern}rest")
	lexer.Reset(end)
	t.CheckEquals(lexer.Rest(), "rest")
}
