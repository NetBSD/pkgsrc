package main

import (
	"netbsd.org/pkglint/regex"
	"strings"
)

// Expecter records the state when checking a list of lines from top to bottom.
type Expecter struct {
	lines Lines
	index int
	m     []string // The groups from the last successful regex match
}

func NewExpecter(lines Lines) *Expecter {
	return &Expecter{lines, 0, nil}
}

func (exp *Expecter) CurrentLine() Line {
	if exp.index < exp.lines.Len() {
		return exp.lines.Lines[exp.index]
	}
	return NewLineEOF(exp.lines.FileName)
}

func (exp *Expecter) PreviousLine() Line {
	return exp.lines.Lines[exp.index-1]
}

func (exp *Expecter) EOF() bool {
	return !(exp.index < exp.lines.Len())
}

func (exp *Expecter) Group(index int) string {
	return exp.m[index]
}

// Advance skips the current line and returns true.
func (exp *Expecter) Advance() bool {
	if exp.EOF() {
		return false
	}
	exp.index++
	exp.m = nil
	return true
}

func (exp *Expecter) StepBack() {
	exp.index--
}

func (exp *Expecter) AdvanceIfMatches(re regex.Pattern) bool {
	if trace.Tracing {
		defer trace.Call(exp.CurrentLine().Text, re)()
	}

	if !exp.EOF() {
		if m := G.res.Match(exp.lines.Lines[exp.index].Text, re); m != nil {
			exp.index++
			exp.m = m
			return true
		}
	}
	return false
}

func (exp *Expecter) AdvanceIfPrefix(prefix string) bool {
	if trace.Tracing {
		defer trace.Call2(exp.CurrentLine().Text, prefix)()
	}

	return !exp.EOF() && strings.HasPrefix(exp.lines.Lines[exp.index].Text, prefix) && exp.Advance()
}

func (exp *Expecter) AdvanceIfEquals(text string) bool {
	if trace.Tracing {
		defer trace.Call2(exp.CurrentLine().Text, text)()
	}

	return !exp.EOF() && exp.lines.Lines[exp.index].Text == text && exp.Advance()
}

func (exp *Expecter) ExpectEmptyLine() bool {
	if exp.AdvanceIfEquals("") {
		return true
	}

	if G.Opts.WarnSpace {
		if exp.index == 0 {
			fix := exp.CurrentLine().Autofix()
			fix.Notef("Empty line expected before this line.")
			fix.InsertBefore("")
			fix.Apply()
		} else {
			fix := exp.PreviousLine().Autofix()
			fix.Notef("Empty line expected after this line.")
			fix.InsertAfter("")
			fix.Apply()
		}
	}
	return false
}

func (exp *Expecter) ExpectText(text string) bool {
	result := exp.AdvanceIfEquals(text)
	if !result {
		exp.CurrentLine().Warnf("This line should contain the following text: %s", text)
	}
	return result
}

// MkExpecter records the state when checking a list of Makefile lines from top to bottom.
type MkExpecter struct {
	mklines MkLines
	Expecter
}

func NewMkExpecter(mklines MkLines) *MkExpecter {
	return &MkExpecter{mklines, *NewExpecter(mklines.lines)}
}

func (exp *MkExpecter) PreviousMkLine() MkLine {
	return exp.mklines.mklines[exp.index-1]
}

func (exp *MkExpecter) CurrentMkLine() MkLine {
	return exp.mklines.mklines[exp.index]
}

func (exp *MkExpecter) AdvanceWhile(pred func(mkline MkLine) bool) {
	if trace.Tracing {
		defer trace.Call(exp.CurrentMkLine().Text)()
	}

	for !exp.EOF() && pred(exp.CurrentMkLine()) {
		exp.Advance()
	}
}

func (exp *MkExpecter) AdvanceIf(pred func(mkline MkLine) bool) bool {
	return !exp.EOF() && pred(exp.CurrentMkLine()) && exp.Advance()
}
