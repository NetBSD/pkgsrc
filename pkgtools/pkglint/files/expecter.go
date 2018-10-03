package main

import (
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/trace"
	"strings"
)

// Expecter records the state when checking a list of lines from top to bottom.
type Expecter struct {
	lines []Line
	index int
	m     []string
}

func NewExpecter(lines []Line) *Expecter {
	return &Expecter{lines, 0, nil}
}

func (exp *Expecter) CurrentLine() Line {
	if exp.index < len(exp.lines) {
		return exp.lines[exp.index]
	}

	return NewLineEOF(exp.lines[0].Filename)
}

func (exp *Expecter) PreviousLine() Line {
	return exp.lines[exp.index-1]
}

func (exp *Expecter) Index() int {
	return exp.index
}

func (exp *Expecter) EOF() bool {
	return !(exp.index < len(exp.lines))
}

func (exp *Expecter) Group(index int) string {
	return exp.m[index]
}

func (exp *Expecter) Advance() bool {
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
		if m := G.res.Match(exp.lines[exp.index].Text, re); m != nil {
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

	return !exp.EOF() && strings.HasPrefix(exp.lines[exp.index].Text, prefix) && exp.Advance()
}

func (exp *Expecter) AdvanceIfEquals(text string) bool {
	if trace.Tracing {
		defer trace.Call2(exp.CurrentLine().Text, text)()
	}

	return !exp.EOF() && exp.lines[exp.index].Text == text && exp.Advance()
}

func (exp *Expecter) ExpectEmptyLine(warnSpace bool) bool {
	if exp.AdvanceIfEquals("") {
		return true
	}

	if warnSpace {
		fix := exp.CurrentLine().Autofix()
		fix.Notef("Empty line expected.")
		fix.InsertBefore("")
		fix.Apply()
	}
	return false
}

func (exp *Expecter) ExpectText(text string) bool {
	if !exp.EOF() && exp.lines[exp.index].Text == text {
		exp.index++
		exp.m = nil
		return true
	}

	exp.CurrentLine().Warnf("This line should contain the following text: %s", text)
	return false
}

func (exp *Expecter) SkipToFooter() {
	exp.index = len(exp.lines) - 2
}

// MkExpecter records the state when checking a list of Makefile lines from top to bottom.
type MkExpecter struct {
	mklines *MkLines
	Expecter
}

func NewMkExpecter(mklines *MkLines) *MkExpecter {
	return &MkExpecter{mklines, *NewExpecter(mklines.lines)}
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
