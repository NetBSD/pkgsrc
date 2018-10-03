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
// logical line, but leave the Text field untouched. These methods are
// used in the --autofix mode.

import (
	"fmt"
	"path"
	"strconv"
)

type Line = *LineImpl

type RawLine struct {
	Lineno int
	orignl string
	textnl string
}

func (rline *RawLine) String() string {
	return strconv.Itoa(rline.Lineno) + ":" + rline.textnl
}

type LineImpl struct {
	Filename  string
	Basename  string
	firstLine int32 // Zero means not applicable, -1 means EOF
	lastLine  int32 // Usually the same as firstLine, may differ in Makefiles
	Text      string
	raw       []*RawLine
	autofix   *Autofix
	Once
}

func NewLine(fname string, lineno int, text string, rawLines []*RawLine) Line {
	return NewLineMulti(fname, lineno, lineno, text, rawLines)
}

// NewLineMulti is for logical Makefile lines that end with backslash.
func NewLineMulti(fname string, firstLine, lastLine int, text string, rawLines []*RawLine) Line {
	return &LineImpl{fname, path.Base(fname), int32(firstLine), int32(lastLine), text, rawLines, nil, Once{}}
}

// NewLineEOF creates a dummy line for logging, with the "line number" EOF.
func NewLineEOF(fname string) Line {
	return NewLineMulti(fname, -1, 0, "", nil)
}

// NewLineWhole creates a dummy line for logging messages that affect a file as a whole.
func NewLineWhole(fname string) Line {
	return NewLine(fname, 0, "", nil)
}

func (line *LineImpl) Linenos() string {
	switch {
	case line.firstLine == -1:
		return "EOF"
	case line.firstLine == 0:
		return ""
	case line.firstLine == line.lastLine:
		return strconv.Itoa(int(line.firstLine))
	default:
		return strconv.Itoa(int(line.firstLine)) + "--" + strconv.Itoa(int(line.lastLine))
	}
}

func (line *LineImpl) ReferenceFrom(other Line) string {
	if line.Filename != other.Filename {
		return cleanpath(relpath(path.Dir(other.Filename), line.Filename)) + ":" + line.Linenos()
	}
	return "line " + line.Linenos()
}

func (line *LineImpl) IsMultiline() bool {
	return line.firstLine > 0 && line.firstLine != line.lastLine
}

func (line *LineImpl) printSource(out *SeparatorWriter) {
	if !G.opts.PrintSource {
		return
	}

	printDiff := func(rawLines []*RawLine) {
		for _, rawLine := range rawLines {
			if rawLine.textnl != rawLine.orignl {
				if rawLine.orignl != "" {
					out.Write("-\t" + rawLine.orignl)
				}
				if rawLine.textnl != "" {
					out.Write("+\t" + rawLine.textnl)
				}
			} else {
				out.Write(">\t" + rawLine.orignl)
			}
		}
	}

	if line.autofix != nil {
		for _, before := range line.autofix.linesBefore {
			out.Write("+\t" + before)
		}
		printDiff(line.autofix.lines)
		for _, after := range line.autofix.linesAfter {
			out.Write("+\t" + after)
		}
	} else {
		printDiff(line.raw)
	}
}

func (line *LineImpl) log(level *LogLevel, format string, args []interface{}) {
	if G.opts.PrintAutofix || G.opts.Autofix {
		// In these two cases, the only interesting diagnostics are
		// those that can be fixed automatically.
		// These are logged by Autofix.Apply.
		return
	}
	G.explainNext = shallBeLogged(format)
	if !G.explainNext {
		return
	}

	out := G.logOut
	if level == llError {
		out = G.logErr
	}

	logs(level, line.Filename, line.Linenos(), format, fmt.Sprintf(format, args...))
	if !G.opts.PrintAutofix && G.opts.PrintSource {
		line.printSource(out)
		out.Separate()
	}
}

func (line *LineImpl) Fatalf(format string, args ...interface{}) {
	line.log(llFatal, format, args)
}

func (line *LineImpl) Errorf(format string, args ...interface{}) {
	line.log(llError, format, args)
}

func (line *LineImpl) Warnf(format string, args ...interface{}) {
	line.log(llWarn, format, args)
}

func (line *LineImpl) Notef(format string, args ...interface{}) {
	line.log(llNote, format, args)
}

func (line *LineImpl) String() string {
	return line.Filename + ":" + line.Linenos() + ": " + line.Text
}

// Autofix returns the autofix instance belonging to the line.
//
// Usage:
//
//  fix := line.Autofix()
//
//  fix.Errorf("Must not be ...")
//  fix.Warnf("Should not be ...")
//  fix.Notef("It is also possible ...")
//
//  fix.Explain(
//      "Explanation ...",
//      "... end of explanation.")
//
//  fix.Replace("from", "to")
//  fix.ReplaceAfter("prefix", "from", "to")
//  fix.ReplaceRegex(`\s+`, "space", -1)
//  fix.InsertBefore("new line")
//  fix.InsertAfter("new line")
//  fix.Delete()
//  fix.Custom(func(...))
//
//  fix.Apply()
func (line *LineImpl) Autofix() *Autofix {
	if line.autofix == nil {
		line.autofix = NewAutofix(line)
	}
	return line.autofix
}
