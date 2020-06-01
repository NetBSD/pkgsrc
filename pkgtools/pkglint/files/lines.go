package pkglint

import (
	"netbsd.org/pkglint/regex"
)

type Lines struct {
	Filename CurrPath
	BaseName RelPath
	Lines    []*Line
}

func NewLines(filename CurrPath, lines []*Line) *Lines {
	return &Lines{filename, filename.Base(), lines}
}

func (ls *Lines) Len() int { return len(ls.Lines) }

func (ls *Lines) LastLine() *Line { return ls.Lines[ls.Len()-1] }

func (ls *Lines) EOFLine() *Line { return NewLineMulti(ls.Filename, -1, "", nil) }

// Whole returns a virtual line that can be used for issuing diagnostics
// and explanations, but not for text replacements.
func (ls *Lines) Whole() *Line { return NewLineWhole(ls.Filename) }

func (ls *Lines) SaveAutofixChanges() bool {
	return SaveAutofixChanges(ls)
}

// CheckCvsID returns true if the expected CVS Id was found.
func (ls *Lines) CheckCvsID(index int, prefixRe regex.Pattern, suggestedPrefix string) bool {
	if trace.Tracing {
		defer trace.Call(prefixRe, suggestedPrefix)()
	}

	line := ls.Lines[index]
	if m, expanded := line.IsCvsID(prefixRe); m {

		// This check is considered experimental because it produces a few
		// thousand notes and doesn't really affect the functionality of
		// the packages. The worst thing that might happen is that a file
		// looks older than it really is.
		if G.Experimental && G.Wip && expanded {
			fix := line.Autofix()
			fix.Notef("Expected exactly %q.", suggestedPrefix+"$"+"NetBSD$")
			fix.Explain(
				"Most files in pkgsrc contain the CVS Id, so that their",
				"current version can be traced back later from a binary package.",
				"This is to ensure reproducible builds and for reliably locating bugs.",
				"",
				"These CVS Ids are specific to the CVS version control system,",
				"and pkgsrc-wip uses Git instead.",
				"Therefore, having the expanded CVS Ids in those files represents",
				"the file from which they were originally copied but not their current state.",
				"Because of that, these markers should be replaced with the plain,",
				"unexpanded string $"+"NetBSD$.",
				"",
				"To preserve the history of the CVS Id, should that ever be needed,",
				"remove the leading $.")
			fix.Replace(line.Text, suggestedPrefix+"$"+"NetBSD$")
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
	fix.InsertAbove(suggestedPrefix + "$" + "NetBSD$")
	fix.Apply()

	return false
}
