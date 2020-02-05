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
	Lineno int // Counting starts at 1

	// The line as read in from the file, including newline;
	// can never be empty. Only in the very last line of each file,
	// the trailing newline might be missing.
	orignl string

	// The line as modified by Autofix, including newline;
	// empty string for deleted lines.
	textnl string

	// XXX: Since only Autofix needs to distinguish between orignl and textnl,
	// one of these fields should probably be moved there.
}

func (rline *RawLine) String() string { return sprintf("%d:%s", rline.Lineno, rline.textnl) }

func (rline *RawLine) Text() string {
	return strings.TrimSuffix(rline.textnl, "\n")
}

func (rline *RawLine) Orig() string {
	return strings.TrimSuffix(rline.orignl, "\n")
}

type Location struct {
	Filename  CurrPath
	firstLine int32 // zero means the whole file, -1 means EOF
	lastLine  int32 // usually the same as firstLine, may differ in Makefiles
}

func NewLocation(filename CurrPath, firstLine, lastLine int) Location {
	return Location{filename, int32(firstLine), int32(lastLine)}
}

func (loc *Location) String() string {
	return loc.Filename.String() + ":" + loc.Linenos()
}

func (loc *Location) Linenos() string {
	switch {
	case loc.firstLine == -1:
		return "EOF"
	case loc.firstLine == 0:
		return ""
	case loc.firstLine == loc.lastLine:
		return strconv.Itoa(int(loc.firstLine))
	default:
		return sprintf("%d--%d", loc.firstLine, loc.lastLine)
	}
}

func (loc *Location) File(rel RelPath) CurrPath {
	return loc.Filename.DirNoClean().JoinNoClean(rel)
}

// Line represents a line of text from a file.
type Line struct {
	// TODO: Consider storing pointers to the Filename and Basename instead of strings to save memory.
	//  But first find out where and why pkglint needs so much memory (200 MB for a full recursive run over pkgsrc + wip).
	Location
	Basename string // the last component of the Filename

	// the text of the line, without the trailing newline character;
	// in Makefiles, also contains the text from the continuation lines,
	// joined by single spaces
	Text string

	raw     []*RawLine // contains the original text including trailing newline
	autofix *Autofix   // any changes that pkglint would like to apply to the line
	once    Once

	// XXX: Filename and Basename could be replaced with a pointer to a Lines object.
}

func NewLine(filename CurrPath, lineno int, text string, rawLine *RawLine) *Line {
	assert(rawLine != nil) // Use NewLineMulti for creating a Line with no RawLine attached to it.
	return NewLineMulti(filename, lineno, lineno, text, []*RawLine{rawLine})
}

// NewLineMulti is for logical Makefile lines that end with backslash.
func NewLineMulti(filename CurrPath, firstLine, lastLine int, text string, rawLines []*RawLine) *Line {
	return &Line{NewLocation(filename, firstLine, lastLine), filename.Base(), text, rawLines, nil, Once{}}
}

// NewLineEOF creates a dummy line for logging, with the "line number" EOF.
func NewLineEOF(filename CurrPath) *Line {
	return NewLineMulti(filename, -1, 0, "", nil)
}

// NewLineWhole creates a dummy line for logging messages that affect a file as a whole.
func NewLineWhole(filename CurrPath) *Line {
	return NewLineMulti(filename, 0, 0, "", nil)
}

// RelLine returns a reference to another line,
// which can be in the same file or in a different file.
func (line *Line) RelLine(other *Line) string {
	return line.RelLocation(other.Location)
}

func (line *Line) RelLocation(other Location) string {
	if line.Filename != other.Filename {
		return line.Rel(other.Filename).String() + ":" + other.Linenos()
	}
	return "line " + other.Linenos()
}

// Rel returns the relative path from this line to the given file path.
// This is typically used for arguments in diagnostics, which should always be
// relative to the line with which the diagnostic is associated.
func (line *Line) Rel(other CurrPath) RelPath {
	return G.Pkgsrc.Relpath(line.Filename.DirNoClean(), other)
}

func (line *Line) IsMultiline() bool {
	return line.firstLine > 0 && line.firstLine != line.lastLine
}

func (line *Line) IsCvsID(prefixRe regex.Pattern) (found bool, expanded bool) {
	m, exp := match1(line.Text, `^`+prefixRe+`\$`+`NetBSD(:[^\$]+)?\$$`)
	return m, exp != ""
}

// FIXME: By definition there cannot be fatal diagnostics.
//  Having these was a misconception from the beginning,
//  and they must be re-classified as fatal technical errors.
func (line *Line) Fatalf(format string, args ...interface{}) {
	if trace.Tracing {
		trace.Stepf("Fatalf: %q, %v", format, args)
	}
	G.Logger.Diag(line, Fatal, format, args...)
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
	return sprintf("%s:%s: %s", line.Filename, line.Linenos(), line.Text)
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
//  fix.InsertBefore("new line")
//  fix.InsertAfter("new line")
//  fix.Delete()
//  fix.Custom(func(showAutofix, autofix bool) {})
//
//  fix.Apply()
func (line *Line) Autofix() *Autofix {
	if line.autofix == nil {
		line.autofix = NewAutofix(line)
	} else {
		// This assertion fails if an Autofix is reused before
		// its Apply method is called.
		assert(line.autofix.autofixShortTerm.diagFormat == "")
	}
	return line.autofix
}
