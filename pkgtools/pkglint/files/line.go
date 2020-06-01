package pkglint

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
	"netbsd.org/pkglint/regex"
	"strconv"
	"strings"
)

type RawLine struct {
	// The line as read in from the file, including newline;
	// can never be empty. Only in the very last line of each file,
	// the trailing newline might be missing.
	orignl string
}

func (rline *RawLine) Orig() string {
	return strings.TrimSuffix(rline.orignl, "\n")
}

type Location struct {
	Filename CurrPath

	// zero means the whole file, -1 means EOF, normal lines start with 1
	lineno int
}

func NewLocation(filename CurrPath, lineno int) Location {
	return Location{filename, lineno}
}

func (loc *Location) Lineno(rawIndex int) int {
	return loc.lineno + rawIndex
}

// File resolves the given path relative to the directory of this
// location.
func (loc *Location) File(rel RelPath) CurrPath {
	return loc.Filename.Dir().JoinNoClean(rel)
}

// Line represents a line of text from a file.
type Line struct {
	// TODO: Consider storing pointers to the Filename and Basename instead of strings to save memory.
	//  But first find out where and why pkglint needs so much memory (200 MB for a full recursive run over pkgsrc + wip).
	Location Location
	Basename RelPath // the last component of the Filename

	// the text of the line, without the trailing newline character;
	// in Makefiles, also contains the text from the continuation lines,
	// joined by single spaces
	Text string

	raw  []*RawLine // contains the original text including trailing newline
	fix  *Autofix   // any changes that pkglint would like to apply to the line
	once Once

	// XXX: Filename and Basename could be replaced with a pointer to a Lines object.
}

func NewLine(filename CurrPath, lineno int, text string, rawLine *RawLine) *Line {
	assert(rawLine != nil) // Use NewLineMulti for creating a Line with no RawLine attached to it.
	return NewLineMulti(filename, lineno, text, []*RawLine{rawLine})
}

// NewLineMulti is for logical Makefile lines that end with backslash.
func NewLineMulti(filename CurrPath, firstLine int, text string, rawLines []*RawLine) *Line {
	return &Line{NewLocation(filename, firstLine), filename.Base(), text, rawLines, nil, Once{}}
}

// NewLineEOF creates a dummy line for logging, with the "line number" EOF.
func NewLineEOF(filename CurrPath) *Line {
	return NewLineMulti(filename, -1, "", nil)
}

// NewLineWhole creates a dummy line for logging messages that affect a file as a whole.
func NewLineWhole(filename CurrPath) *Line {
	return NewLineMulti(filename, 0, "", nil)
}

func (line *Line) Filename() CurrPath { return line.Location.Filename }

// File resolves the given path relative to the directory where this line
// appears in.
func (line *Line) File(rel RelPath) CurrPath { return line.Location.File(rel) }

func (line *Line) Linenos() string {
	first := line.Location.lineno
	if first == -1 {
		return "EOF"
	}
	if first == 0 {
		return ""
	}

	n := len(line.raw)
	if n == 1 {
		return strconv.Itoa(first)
	}
	return sprintf("%d--%d", first, first+n-1)
}

// RelLine returns a reference to another line,
// which can be in the same file or in a different file.
func (line *Line) RelLine(other *Line) string {
	assert(other.Location.Lineno(0) >= 1)

	if line.Filename() != other.Filename() {
		return line.Rel(other.Filename()).String() + ":" + other.Linenos()
	}
	return "line " + other.Linenos()
}

func (line *Line) RelLocation(other Location) string {
	lineno := other.Lineno(0)
	assert(lineno >= 1)

	if line.Filename() != other.Filename {
		return sprintf("%s:%d", line.Rel(other.Filename).String(), lineno)
	}
	return sprintf("line %d", lineno)
}

// Rel returns the relative path from this line to the given file path.
// This is typically used for arguments in diagnostics, which should always be
// relative to the line with which the diagnostic is associated.
func (line *Line) Rel(other CurrPath) RelPath {
	return G.Pkgsrc.Relpath(line.Filename().Dir(), other)
}

func (line *Line) IsMultiline() bool { return len(line.raw) > 1 }

// RawText returns the raw text from the given physical line,
// excluding \n, including any previous autofixes.
func (line *Line) RawText(rawIndex int) string {
	var textnl string
	if line.fix != nil {
		textnl = line.fix.texts[rawIndex]
	} else {
		textnl = line.raw[rawIndex].orignl
	}
	return strings.TrimSuffix(textnl, "\n")
}

func (line *Line) IsCvsID(prefixRe regex.Pattern) (found bool, expanded bool) {
	m, exp := match1(line.Text, `^`+prefixRe+`\$`+`NetBSD(:[^\$]+)?\$$`)
	return m, exp != ""
}

func (line *Line) Errorf(format string, args ...interface{}) {
	G.Logger.Diag(line, Error, format, args...)
}

func (line *Line) Warnf(format string, args ...interface{}) {
	G.Logger.Diag(line, Warn, format, args...)
}

func (line *Line) Notef(format string, args ...interface{}) {
	G.Logger.Diag(line, Note, format, args...)
}

func (line *Line) Explain(explanation ...string) { G.Logger.Explain(explanation...) }

func (line *Line) String() string {
	return sprintf("%s:%s: %s", line.Filename(), line.Linenos(), line.Text)
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
//  fix.InsertAbove("new line")
//  fix.InsertBelow("new line")
//  fix.Delete()
//  fix.Custom(func(showAutofix, autofix bool) {})
//
//  fix.Apply()
func (line *Line) Autofix() *Autofix {
	if line.fix == nil {
		line.fix = NewAutofix(line)
	} else {
		// This assertion fails if an Autofix is reused before
		// its Apply method is called.
		assert(line.fix.autofixShortTerm.diagFormat == "")
	}
	return line.fix
}
