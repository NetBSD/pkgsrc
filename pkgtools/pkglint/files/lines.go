package main

import (
	"netbsd.org/pkglint/regex"
	"path"
)

type Lines = *LinesImpl

type LinesImpl struct {
	FileName string
	BaseName string
	Lines    []Line
}

func NewLines(filename string, lines []Line) Lines {
	return &LinesImpl{filename, path.Base(filename), lines}
}

func (ls *LinesImpl) Len() int { return len(ls.Lines) }

func (ls *LinesImpl) LastLine() Line { return ls.Lines[ls.Len()-1] }

func (ls *LinesImpl) EOFLine() Line { return NewLineMulti(ls.FileName, -1, -1, "", nil) }

func (ls *LinesImpl) Errorf(format string, args ...interface{}) {
	NewLineWhole(ls.FileName).Errorf(format, args...)
}

func (ls *LinesImpl) Warnf(format string, args ...interface{}) {
	NewLineWhole(ls.FileName).Warnf(format, args...)
}

func (ls *LinesImpl) SaveAutofixChanges() {
	SaveAutofixChanges(ls)
}

func (ls *LinesImpl) CheckRcsID(index int, prefixRe regex.Pattern, suggestedPrefix string) bool {
	if trace.Tracing {
		defer trace.Call(prefixRe, suggestedPrefix)()
	}

	line := ls.Lines[index]
	if m, expanded := match1(line.Text, `^`+prefixRe+`\$`+`NetBSD(:[^\$]+)?\$$`); m {

		if G.Wip && expanded != "" {
			fix := line.Autofix()
			fix.Notef("Expected exactly %q.", suggestedPrefix+"$"+"NetBSD$")
			fix.Explain(
				"Several files in pkgsrc must contain the CVS Id, so that their",
				"current version can be traced back later from a binary package.",
				"This is to ensure reproducible builds, for example for finding bugs.",
				"",
				"These CVS Ids are specific to the CVS version control system, and",
				"pkgsrc-wip uses Git instead.  Therefore, having the expanded CVS Ids",
				"in those files represents the file from which they were originally",
				"copied but not their current state.  Because of that, these markers",
				"should be replaced with the plain, unexpanded string $"+"NetBSD$.",
				"",
				"To preserve the history of the CVS Id, should that ever be needed,",
				"remove the leading $.")
			fix.ReplaceRegex(`.*`, suggestedPrefix+"$"+"NetBSD$", 1)
			fix.Apply()
		}

		return true
	}

	fix := line.Autofix()
	fix.Errorf("Expected %q.", suggestedPrefix+"$"+"NetBSD$")
	fix.Explain(
		"Most files in pkgsrc contain the CVS Id, so that their current",
		"version can be traced back later from a binary package.",
		"This is to ensure reproducible builds, for example for finding bugs.")
	fix.InsertBefore(suggestedPrefix + "$" + "NetBSD$")
	fix.Apply()

	return false
}
