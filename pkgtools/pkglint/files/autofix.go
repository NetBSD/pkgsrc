package main

import (
	"fmt"
	"io/ioutil"
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/trace"
	"os"
	"strings"
)

// Autofix handles all modifications to a single line,
// describes them in a human-readable form and formats the output.
// The modifications are kept in memory only,
// until they are written to disk by SaveAutofixChanges.
type Autofix struct {
	line        Line
	linesBefore []string      // Newly inserted lines, including \n
	lines       []*RawLine    // Original lines, available for diff
	linesAfter  []string      // Newly inserted lines, including \n
	modified    bool          // Modified in memory, but not necessarily written back to disk
	descrFormat string        // Human-readable description of the latest modification
	descrArgs   []interface{} //
	level       *LogLevel     //
	diagFormat  string        // Is printed only if it couldn't be fixed automatically
	diagArgs    []interface{} //
	explanation []string      // Is printed together with the diagnostic
}

func NewAutofix(line Line) *Autofix {
	return &Autofix{
		line:  line,
		lines: append([]*RawLine{}, line.raw...)}
}

func (fix *Autofix) Replace(from string, to string) {
	if fix.skip() {
		return
	}

	for _, rawLine := range fix.lines {
		if rawLine.Lineno != 0 {
			if replaced := strings.Replace(rawLine.textnl, from, to, 1); replaced != rawLine.textnl {
				if G.opts.PrintAutofix || G.opts.Autofix {
					rawLine.textnl = replaced
				}
				fix.Describef("Replacing %q with %q.", from, to)
			}
		}
	}
}

func (fix *Autofix) ReplaceRegex(from regex.Pattern, to string) {
	if fix.skip() {
		return
	}

	for _, rawLine := range fix.lines {
		if rawLine.Lineno != 0 {
			if replaced := regex.Compile(from).ReplaceAllString(rawLine.textnl, to); replaced != rawLine.textnl {
				if G.opts.PrintAutofix || G.opts.Autofix {
					rawLine.textnl = replaced
				}
				fix.Describef("Replacing regular expression %q with %q.", from, to)
			}
		}
	}
}

func (fix *Autofix) InsertBefore(text string) {
	if fix.skip() {
		return
	}

	fix.linesBefore = append(fix.linesBefore, text+"\n")
	fix.Describef("Inserting a line %q before this line.", text)
}

func (fix *Autofix) InsertAfter(text string) {
	if fix.skip() {
		return
	}

	fix.linesAfter = append(fix.linesAfter, text+"\n")
	fix.Describef("Inserting a line %q after this line.", text)
}

func (fix *Autofix) Delete() {
	if fix.skip() {
		return
	}

	for _, line := range fix.lines {
		line.textnl = ""
	}
	fix.Describef("Deleting this line.")
}

func (fix *Autofix) Describef(format string, args ...interface{}) {
	fix.descrFormat = format
	fix.descrArgs = args
}

func (fix *Autofix) Notef(format string, args ...interface{}) {
	fix.level = llNote
	fix.diagFormat = format
	fix.diagArgs = args
}

func (fix *Autofix) Warnf(format string, args ...interface{}) {
	fix.level = llWarn
	fix.diagFormat = format
	fix.diagArgs = args
}

func (fix *Autofix) Errorf(format string, args ...interface{}) {
	fix.level = llError
	fix.diagFormat = format
	fix.diagArgs = args
}

func (fix *Autofix) Explain(explanation ...string) {
	fix.explanation = explanation
}

// Depending on the pkglint mode, either:
//
// * logs the associated message (default)
// * logs what would be fixed (--show-autofix)
// * records the fixes in the line (--autofix)
func (fix *Autofix) Apply() {
	line := fix.line
	if line.firstLine < 1 {
		return
	}

	if shallBeLogged(fix.diagFormat) && fix.descrFormat != "" {
		logDiagnostic := fix.level != nil && fix.diagFormat != "Silent-Magic-Diagnostic" && !G.opts.Autofix
		if logDiagnostic {
			msg := fmt.Sprintf(fix.diagFormat, fix.diagArgs...)
			logs(fix.level, line.Filename, line.Linenos(), fix.diagFormat, msg)
		}

		logRepair := G.opts.Autofix || G.opts.PrintAutofix
		if logRepair {
			msg := fmt.Sprintf(fix.descrFormat, fix.descrArgs...)
			logs(llAutofix, line.Filename, line.Linenos(), "", msg)
		}

		if logDiagnostic || logRepair {
			line.printSource(G.logOut)
			if G.opts.Explain && logDiagnostic && len(fix.explanation) != 0 {
				Explain(fix.explanation...)
			} else if G.opts.PrintSource {
				G.logOut.Separate()
			}
		}
	}

	fix.modified = fix.modified || fix.descrFormat != ""

	fix.descrFormat = ""
	fix.descrArgs = nil
	fix.level = nil
	fix.diagFormat = ""
	fix.diagArgs = nil
	fix.explanation = nil
}

func (fix *Autofix) skip() bool {
	if fix.diagFormat == "" {
		panic("Autofix: The diagnostic must be given before the action.")
	}
	return !shallBeLogged(fix.diagFormat)
}

// SaveAutofixChanges writes the given lines back into their files,
// applying the autofix changes.
// The lines may come from different files.
// Only files that actually have changed lines are saved.
func SaveAutofixChanges(lines []Line) (autofixed bool) {
	if trace.Tracing {
		defer trace.Call0()()
	}

	if !G.opts.Autofix {
		for _, line := range lines {
			if line.autofix != nil && line.autofix.modified {
				G.autofixAvailable = true
			}
		}
		return
	}

	changes := make(map[string][]string)
	changed := make(map[string]bool)
	for _, line := range lines {
		chlines := changes[line.Filename]
		if fix := line.autofix; fix != nil {
			if fix.modified {
				changed[line.Filename] = true
			}
			chlines = append(chlines, fix.linesBefore...)
			for _, raw := range line.raw {
				chlines = append(chlines, raw.textnl)
			}
			chlines = append(chlines, fix.linesAfter...)
		} else {
			for _, raw := range line.raw {
				chlines = append(chlines, raw.textnl)
			}
		}
		changes[line.Filename] = chlines
	}

	for fname := range changed {
		changedLines := changes[fname]
		tmpname := fname + ".pkglint.tmp"
		text := ""
		for _, changedLine := range changedLines {
			text += changedLine
		}
		err := ioutil.WriteFile(tmpname, []byte(text), 0666)
		if err != nil {
			NewLineWhole(tmpname).Errorf("Cannot write.")
			continue
		}
		err = os.Rename(tmpname, fname)
		if err != nil {
			NewLineWhole(fname).Errorf("Cannot overwrite with auto-fixed content.")
			continue
		}
		msg := "Has been auto-fixed. Please re-run pkglint."
		logs(llAutofix, fname, "", msg, msg)
		autofixed = true
	}
	return
}
