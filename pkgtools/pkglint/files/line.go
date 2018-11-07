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
// logical line but leave the Text field untouched. These methods are
// used in the --autofix mode.

import (
	"fmt"
	"path"
	"strconv"
)

type RawLine struct {
	Lineno int
	// XXX: This is only needed for Autofix; probably should be moved there.
	orignl string
	textnl string
}

func (rline *RawLine) String() string {
	return strconv.Itoa(rline.Lineno) + ":" + rline.textnl
}

type Line = *LineImpl

type LineImpl struct {
	FileName  string
	Basename  string
	firstLine int32 // Zero means not applicable, -1 means EOF
	lastLine  int32 // Usually the same as firstLine, may differ in Makefiles
	Text      string
	raw       []*RawLine
	autofix   *Autofix
	Once
}

func NewLine(fileName string, lineno int, text string, rawLines []*RawLine) Line {
	return NewLineMulti(fileName, lineno, lineno, text, rawLines)
}

// NewLineMulti is for logical Makefile lines that end with backslash.
func NewLineMulti(fileName string, firstLine, lastLine int, text string, rawLines []*RawLine) Line {
	return &LineImpl{fileName, path.Base(fileName), int32(firstLine), int32(lastLine), text, rawLines, nil, Once{}}
}

// NewLineEOF creates a dummy line for logging, with the "line number" EOF.
func NewLineEOF(fileName string) Line {
	return NewLineMulti(fileName, -1, 0, "", nil)
}

// NewLineWhole creates a dummy line for logging messages that affect a file as a whole.
func NewLineWhole(fileName string) Line {
	return NewLine(fileName, 0, "", nil)
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

// RefTo returns a reference to another line,
// which can be in the same file or in a different file.
func (line *LineImpl) RefTo(other Line) string {
	if line.FileName != other.FileName {
		return cleanpath(relpath(path.Dir(line.FileName), other.FileName)) + ":" + other.Linenos()
	}
	return "line " + other.Linenos()
}

// PathToFile returns the relative path from this line to the given file path.
// This is typically used for arguments in diagnostics, which should always be
// relative to the line with which the diagnostic is associated.
func (line *LineImpl) PathToFile(filePath string) string {
	return relpath(path.Dir(line.FileName), filePath)
}

func (line *LineImpl) IsMultiline() bool {
	return line.firstLine > 0 && line.firstLine != line.lastLine
}

func (line *LineImpl) showSource(out *SeparatorWriter) {
	if !G.Opts.ShowSource {
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
		printDiff(line.raw)
		for _, after := range line.autofix.linesAfter {
			out.Write("+\t" + after)
		}
	} else {
		printDiff(line.raw)
	}
}

func (line *LineImpl) log(level *LogLevel, format string, args []interface{}) {
	if G.Opts.ShowAutofix || G.Opts.Autofix {
		// In these two cases, the only interesting diagnostics are
		// those that can be fixed automatically.
		// These are logged by Autofix.Apply.
		return
	}
	G.explainNext = shallBeLogged(format)
	if !G.explainNext {
		return
	}

	if G.Opts.ShowSource {
		line.showSource(G.logOut)
	}
	logf(level, line.FileName, line.Linenos(), format, fmt.Sprintf(format, args...))
	if G.Opts.ShowSource {
		G.logOut.Separate()
	}
}

func (line *LineImpl) Fatalf(format string, args ...interface{}) {
	line.log(Fatal, format, args)
}

func (line *LineImpl) Errorf(format string, args ...interface{}) {
	line.log(Error, format, args)
}

func (line *LineImpl) Warnf(format string, args ...interface{}) {
	line.log(Warn, format, args)
}

func (line *LineImpl) Notef(format string, args ...interface{}) {
	line.log(Note, format, args)
}

func (line *LineImpl) String() string {
	return line.FileName + ":" + line.Linenos() + ": " + line.Text
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
//  fix.ReplaceRegex(`[\t ]+`, "space", -1)
//  fix.InsertBefore("new line")
//  fix.InsertAfter("new line")
//  fix.Delete()
//  fix.Custom(func(showAutofix, autofix bool) {})
//
//  fix.Apply()
func (line *LineImpl) Autofix() *Autofix {
	if line.autofix == nil {
		line.autofix = NewAutofix(line)
	}
	return line.autofix
}
