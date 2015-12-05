package main

// When files are read in by pkglint, they are interpreted in terms of
// lines. For Makefiles, line continuations are handled properly, allowing
// multiple raw lines to end in a single logical line. For other files
// there is a 1:1 translation.
//
// A difference between the raw and the logical lines is that the
// raw lines include the line end sequence, whereas the logical lines
// do not.
//
// Some methods allow modification of the raw lines contained in the
// logical line, but leave the “text” field untouched. These methods are
// used in the --autofix mode.

import (
	"fmt"
	"io"
	"strings"
)

type RawLine struct {
	lineno int
	textnl string
}

func (rline *RawLine) String() string {
	return sprintf("%d:%s", rline.lineno, rline.textnl)
}

type Line struct {
	fname   string
	lines   string
	text    string
	raw     []*RawLine
	changed bool
	before  []*RawLine
	after   []*RawLine
	extra   map[string]interface{}
}

func NewLine(fname, linenos, text string, rawLines []*RawLine) *Line {
	return &Line{fname, linenos, text, rawLines, false, nil, nil, make(map[string]interface{})}
}

func (ln *Line) rawLines() []*RawLine {
	return append(append(append([]*RawLine(nil), ln.before...), ln.raw...), ln.after...)
}

func (ln *Line) printSource(out io.Writer) {
	if G.opts.PrintSource {
		io.WriteString(out, "\n")
		for _, rawLine := range ln.rawLines() {
			fmt.Fprintf(out, "> %s", rawLine.textnl)
		}
	}
}

func (ln *Line) fatalf(format string, args ...interface{}) bool {
	ln.printSource(G.logErr)
	return fatalf(ln.fname, ln.lines, format, args...)
}
func (ln *Line) errorf(format string, args ...interface{}) bool {
	ln.printSource(G.logOut)
	return errorf(ln.fname, ln.lines, format, args...)
}
func (ln *Line) warnf(format string, args ...interface{}) bool {
	ln.printSource(G.logOut)
	return warnf(ln.fname, ln.lines, format, args...)
}
func (ln *Line) notef(format string, args ...interface{}) bool {
	ln.printSource(G.logOut)
	return notef(ln.fname, ln.lines, format, args...)
}
func (ln *Line) debugf(format string, args ...interface{}) bool {
	ln.printSource(G.logOut)
	return debugf(ln.fname, ln.lines, format, args...)
}

func (ln *Line) explain(explanation ...string) {
	if G.opts.Explain {
		complete := strings.Join(explanation, "\n")
		if G.explanationsGiven[complete] {
			return
		}
		if G.explanationsGiven == nil {
			G.explanationsGiven = make(map[string]bool)
			G.explanationsGiven[complete] = true
		}

		io.WriteString(G.logOut, "\n")
		for _, explanationLine := range explanation {
			io.WriteString(G.logOut, "\t"+explanationLine+"\n")
		}
		io.WriteString(G.logOut, "\n")
	}
	G.explanationsAvailable = true
}

func (ln *Line) String() string {
	return ln.fname + ":" + ln.lines + ": " + ln.text
}

func (ln *Line) insertBefore(line string) {
	ln.before = append(ln.before, &RawLine{0, line + "\n"})
	ln.noteAutofix("Autofix: inserting a line %q before this line.", line)
}

func (ln *Line) insertAfter(line string) {
	ln.after = append(ln.after, &RawLine{0, line + "\n"})
	ln.noteAutofix("Autofix: inserting a line %q after this line.", line)
}

func (ln *Line) delete() {
	ln.raw = nil
	ln.changed = true
}

func (ln *Line) replace(from, to string) {
	for _, rawLine := range ln.raw {
		if rawLine.lineno != 0 {
			if replaced := strings.Replace(rawLine.textnl, from, to, 1); replaced != rawLine.textnl {
				rawLine.textnl = replaced
				ln.noteAutofix("Autofix: replacing %q with %q.", from, to)
			}
		}
	}
}
func (ln *Line) replaceRegex(from, to string) {
	for _, rawLine := range ln.raw {
		if rawLine.lineno != 0 {
			if replaced := regcomp(from).ReplaceAllString(rawLine.textnl, to); replaced != rawLine.textnl {
				rawLine.textnl = replaced
				ln.noteAutofix("Autofix: replacing regular expression %q with %q.", from, to)
			}
		}
	}
}

func (ln *Line) noteAutofix(format string, args ...interface{}) {
	ln.changed = true
	if G.opts.Autofix || G.opts.PrintAutofix {
		ln.notef(format, args...)
	}
	G.autofixAvailable = true
}
