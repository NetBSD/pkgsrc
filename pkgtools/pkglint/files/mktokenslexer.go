package pkglint

import (
	"netbsd.org/pkglint/textproc"
	"strings"
)

// MkTokensLexer parses a sequence of variable uses (like ${VAR:Mpattern})
// interleaved with other text that is uninterpreted by bmake.
type MkTokensLexer struct {
	// The lexer for the current text-only token.
	// If the current token is a variable use, the lexer will always return
	// EOF internally. That is not visible from the outside though, as EOF is
	// overridden in this type.
	*textproc.Lexer

	// The remaining tokens.
	tokens []*MkToken
}

func NewMkTokensLexer(tokens []*MkToken) *MkTokensLexer {
	lexer := &MkTokensLexer{nil, tokens}
	lexer.next()
	return lexer
}

func (m *MkTokensLexer) next() {
	if len(m.tokens) > 0 && m.tokens[0].Varuse == nil {
		m.Lexer = textproc.NewLexer(m.tokens[0].Text)
		m.tokens = m.tokens[1:]
	} else {
		m.Lexer = textproc.NewLexer("")
	}
}

// EOF returns whether the whole input has been consumed.
func (m *MkTokensLexer) EOF() bool { return m.Lexer.EOF() && len(m.tokens) == 0 }

// Rest returns the string concatenation of the tokens that have not yet been consumed.
func (m *MkTokensLexer) Rest() string {
	sb := NewLazyStringBuilder(m.Lexer.Rest())
	sb.WriteString(m.Lexer.Rest())
	for _, token := range m.tokens {
		sb.WriteString(token.Text)
	}
	return sb.String()
}

// Skip skips the next n bytes from the plain text.
// If there is a variable use in the next n bytes, it panics; see SkipMixed.
func (m *MkTokensLexer) Skip(n int) bool {
	return m.Lexer.Skip(n)
}

// SkipMixed skips the next n bytes, be they in plain text or in variable uses.
// It is only used in very special situations.
func (m *MkTokensLexer) SkipMixed(n int) bool {
	result := n > 0
	for n > 0 {
		use := m.NextVarUse()
		if use != nil {
			n -= len(use.Text)
		} else {
			skip := imin(len(m.Lexer.Rest()), n)
			assert(m.Lexer.Skip(skip))
			n -= skip
		}
	}
	return result
}

// NextVarUse returns the next varuse token, unless there is some plain text
// before it. In that case or at EOF, it returns nil.
func (m *MkTokensLexer) NextVarUse() *MkToken {
	if m.Lexer.EOF() && len(m.tokens) > 0 && m.tokens[0].Varuse != nil {
		token := m.tokens[0]
		m.tokens = m.tokens[1:]
		m.next()
		return token
	}
	return nil
}

// Mark remembers the current position of the lexer.
// The lexer can later be reset to that position by calling Reset.
func (m *MkTokensLexer) Mark() MkTokensLexerMark {
	return MkTokensLexerMark{m.Lexer.Rest(), m.tokens}
}

// Since returns the text between the given mark and the current position
// of the lexer.
func (m *MkTokensLexer) Since(mark MkTokensLexerMark) string {
	early := (&MkTokensLexer{textproc.NewLexer(mark.rest), mark.tokens}).Rest()
	late := m.Rest()

	return strings.TrimSuffix(early, late)
}

// Reset sets the lexer back to the given position.
// The lexer may be reset to the same mark multiple times,
// that is, the mark is not destroyed.
func (m *MkTokensLexer) Reset(mark MkTokensLexerMark) {
	m.Lexer = textproc.NewLexer(mark.rest)
	m.tokens = mark.tokens
}

// MkTokensLexerMark remembers a position of a token lexer,
// to be restored later.
type MkTokensLexerMark struct {
	rest   string
	tokens []*MkToken
}
