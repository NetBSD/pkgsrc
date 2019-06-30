package pkglint

import "netbsd.org/pkglint/regex"

// LinesLexer records the state when checking a list of lines from top to bottom.
type LinesLexer struct {
	lines *Lines
	index int
}

func NewLinesLexer(lines *Lines) *LinesLexer {
	return &LinesLexer{lines, 0}
}

// CurrentLine returns the line that the lexer is currently looking at.
// If it is at the end of file, the line number of the line is EOF.
func (llex *LinesLexer) CurrentLine() *Line {
	if llex.index < llex.lines.Len() {
		return llex.lines.Lines[llex.index]
	}
	return NewLineEOF(llex.lines.Filename)
}

func (llex *LinesLexer) PreviousLine() *Line {
	return llex.lines.Lines[llex.index-1]
}

func (llex *LinesLexer) EOF() bool {
	return !(llex.index < llex.lines.Len())
}

// Skip skips the current line and returns true.
func (llex *LinesLexer) Skip() bool {
	if llex.EOF() {
		return false
	}
	llex.index++
	return true
}

func (llex *LinesLexer) Undo() {
	llex.index--
}

func (llex *LinesLexer) NextRegexp(re regex.Pattern) []string {
	if trace.Tracing {
		defer trace.Call(llex.CurrentLine().Text, re)()
	}

	if !llex.EOF() {
		if m := G.res.Match(llex.lines.Lines[llex.index].Text, re); m != nil {
			llex.index++
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

	if !llex.EOF() && hasPrefix(llex.lines.Lines[llex.index].Text, prefix) {
		llex.Skip()
		return true
	}
	return false
}

func (llex *LinesLexer) SkipString(text string) bool {
	if trace.Tracing {
		defer trace.Call2(llex.CurrentLine().Text, text)()
	}

	if !llex.EOF() && llex.lines.Lines[llex.index].Text == text {
		llex.Skip()
		return true
	}
	return false
}

func (llex *LinesLexer) SkipEmptyOrNote() bool {
	if llex.SkipString("") {
		return true
	}

	if G.Opts.WarnSpace {
		if llex.index == 0 {
			fix := llex.CurrentLine().Autofix()
			fix.Notef("Empty line expected before this line.")
			fix.InsertBefore("")
			fix.Apply()
		} else {
			fix := llex.PreviousLine().Autofix()
			fix.Notef("Empty line expected after this line.")
			fix.InsertAfter("")
			fix.Apply()
		}
	}
	return false
}

func (llex *LinesLexer) SkipContainsOrWarn(text string) bool {
	result := llex.SkipString(text)
	if !result {
		llex.CurrentLine().Warnf("This line should contain the following text: %s", text)
	}
	return result
}

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

func (mlex *MkLinesLexer) SkipWhile(pred func(mkline *MkLine) bool) {
	if trace.Tracing {
		defer trace.Call(mlex.CurrentMkLine().Text)()
	}

	for !mlex.EOF() && pred(mlex.CurrentMkLine()) {
		mlex.Skip()
	}
}

func (mlex *MkLinesLexer) SkipIf(pred func(mkline *MkLine) bool) bool {
	if !mlex.EOF() && pred(mlex.CurrentMkLine()) {
		mlex.Skip()
		return true
	}
	return false
}
