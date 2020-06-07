package pkglint

import "netbsd.org/pkglint/regex"

// LinesLexer records the state when checking a list of lines from top to bottom.
type LinesLexer struct {
	line  *Line
	index int
	lines *Lines
}

func NewLinesLexer(lines *Lines) *LinesLexer {
	llex := LinesLexer{nil, 0, lines}
	llex.setIndex(0)
	return &llex
}

// CurrentLine returns the line that the lexer is currently looking at.
// For the EOF, a virtual line with line number "EOF" is returned.
func (llex *LinesLexer) CurrentLine() *Line {
	if llex.line != nil {
		return llex.line
	}
	return NewLineEOF(llex.lines.Filename)
}

func (llex *LinesLexer) PreviousLine() *Line {
	return llex.lines.Lines[llex.index-1]
}

func (llex *LinesLexer) EOF() bool {
	return llex.line == nil
}

// Skip skips the current line.
func (llex *LinesLexer) Skip() bool {
	if llex.EOF() {
		return false
	}
	llex.next()
	return true
}

func (llex *LinesLexer) Undo() {
	llex.setIndex(llex.index - 1)
}

func (llex *LinesLexer) NextRegexp(re regex.Pattern) []string {
	if trace.Tracing {
		defer trace.Call(llex.CurrentLine().Text, re)()
	}

	if !llex.EOF() {
		if m := match(llex.line.Text, re); m != nil {
			llex.next()
			return m
		}
	}
	return nil
}

func (llex *LinesLexer) SkipRegexp(re regex.Pattern) bool {
	return llex.NextRegexp(re) != nil
}

func (llex *LinesLexer) SkipPrefix(prefix string) bool {
	if trace.Tracing {
		defer trace.Call2(llex.CurrentLine().Text, prefix)()
	}

	if !llex.EOF() && hasPrefix(llex.line.Text, prefix) {
		llex.next()
		return true
	}
	return false
}

func (llex *LinesLexer) SkipText(text string) bool {
	if trace.Tracing {
		defer trace.Call2(llex.CurrentLine().Text, text)()
	}

	if !llex.EOF() && llex.line.Text == text {
		llex.Skip()
		return true
	}
	return false
}

func (llex *LinesLexer) SkipEmptyOrNote() bool {
	if llex.SkipText("") {
		return true
	}

	if llex.index < llex.lines.Len() || llex.lines.Len() == 0 {
		fix := llex.CurrentLine().Autofix()
		fix.Notef("Empty line expected above this line.")
		if !llex.EOF() {
			fix.InsertAbove("")
		}
		fix.Apply()
	} else {
		fix := llex.PreviousLine().Autofix()
		fix.Notef("Empty line expected below this line.")
		fix.InsertBelow("")
		fix.Apply()
	}

	return false
}

func (llex *LinesLexer) SkipTextOrWarn(text string) bool {
	result := llex.SkipText(text)
	if !result {
		llex.CurrentLine().Warnf("This line should consist of the following text: %s", text)
	}
	return result
}

func (llex *LinesLexer) setIndex(index int) {
	llex.index = index
	if index < llex.lines.Len() {
		llex.line = llex.lines.Lines[index]
	} else {
		llex.line = nil
	}
}

func (llex *LinesLexer) next() { llex.setIndex(llex.index + 1) }

// MkLinesLexer records the state when checking a list of Makefile lines from top to bottom.
type MkLinesLexer struct {
	mklines *MkLines
	LinesLexer
}

func NewMkLinesLexer(mklines *MkLines) *MkLinesLexer {
	return &MkLinesLexer{mklines, *NewLinesLexer(mklines.lines)}
}

func (mlex *MkLinesLexer) PreviousMkLine() *MkLine {
	return mlex.mklines.mklines[mlex.index-1]
}

func (mlex *MkLinesLexer) CurrentMkLine() *MkLine {
	return mlex.mklines.mklines[mlex.index]
}

func (mlex *MkLinesLexer) SkipIf(pred func(mkline *MkLine) bool) bool {
	if !mlex.EOF() && pred(mlex.CurrentMkLine()) {
		mlex.next()
		return true
	}
	return false
}
