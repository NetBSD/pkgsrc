package main

import (
	"fmt"
	"io/ioutil"
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/trace"
	"os"
	"strconv"
	"strings"
)

// Autofix handles all modifications to a single line,
// describes them in a human-readable form and formats the output.
// The modifications are kept in memory only,
// until they are written to disk by SaveAutofixChanges.
type Autofix struct {
	line        Line
	linesBefore []string        // Newly inserted lines, including \n
	lines       []*RawLine      // Original lines, available for diff
	linesAfter  []string        // Newly inserted lines, including \n
	modified    bool            // Modified in memory, but not necessarily written back to disk
	actions     []autofixAction // Human-readable description of the actual autofix actions
	level       *LogLevel       //
	diagFormat  string          // Is printed only if it couldn't be fixed automatically
	diagArgs    []interface{}   //
	explanation []string        // Is printed together with the diagnostic
}

type autofixAction struct {
	description string
	lineno      int
}

func NewAutofix(line Line) *Autofix {
	return &Autofix{
		line:  line,
		lines: append([]*RawLine{}, line.raw...)}
}

func (fix *Autofix) Replace(from string, to string) {
	fix.ReplaceAfter("", from, to)
}

// ReplaceAfter replaces the text "prefix+from" with "prefix+to",
// but in the diagnostic, only the replacement of "from" with "to"
// is mentioned.
func (fix *Autofix) ReplaceAfter(prefix, from string, to string) {
	if fix.skip() {
		return
	}

	for _, rawLine := range fix.lines {
		if rawLine.Lineno != 0 {
			if replaced := strings.Replace(rawLine.textnl, prefix+from, prefix+to, 1); replaced != rawLine.textnl {
				if G.opts.PrintAutofix || G.opts.Autofix {
					rawLine.textnl = replaced
				}
				fix.Describef(rawLine.Lineno, "Replacing %q with %q.", from, to)
			}
		}
	}
}

// ReplaceRegex replaces the first or all occurrences of the `from` pattern
// with the fixed string `toText`. Placeholders like `$1` are _not_ expanded.
// (If you know how to do the expansion correctly, feel free to implement it.)
func (fix *Autofix) ReplaceRegex(from regex.Pattern, toText string, howOften int) {
	if fix.skip() {
		return
	}

	done := 0
	for _, rawLine := range fix.lines {
		if rawLine.Lineno != 0 {
			var froms []string // The strings that have actually changed

			replace := func(fromText string) string {
				if howOften >= 0 && done >= howOften {
					return fromText
				}
				froms = append(froms, fromText)
				done++
				return toText
			}

			if replaced := regex.Compile(from).ReplaceAllStringFunc(rawLine.textnl, replace); replaced != rawLine.textnl {
				if G.opts.PrintAutofix || G.opts.Autofix {
					rawLine.textnl = replaced
				}
				for _, fromText := range froms {
					fix.Describef(rawLine.Lineno, "Replacing %q with %q.", fromText, toText)
				}
			}
		}
	}
}

func (fix *Autofix) Realign(mkline MkLine, newWidth int) {
	if fix.skip() || !mkline.IsMultiline() || !(mkline.IsVarassign() || mkline.IsCommentedVarassign()) {
		return
	}

	normalized := true // Whether all indentation is tabs, followed by spaces.
	oldWidth := 0      // The minimum required indentation in the original lines.

	{
		// Interpreting the continuation marker as variable value
		// is cheating, but works well.
		m, _, _, _, _, valueAlign, value, _, _ := MatchVarassign(mkline.raw[0].orignl)
		if m && value != "\\" {
			oldWidth = tabWidth(valueAlign)
		}
	}

	for _, rawLine := range fix.lines[1:] {
		_, comment, space := regex.Match2(rawLine.textnl, `^(#?)([ \t]*)`)
		width := tabWidth(comment + space)
		if (oldWidth == 0 || width < oldWidth) && width >= 8 && rawLine.textnl != "\n" {
			oldWidth = width
		}
		if !regex.Matches(space, `^\t* {0,7}`) {
			normalized = false
		}
	}

	if normalized && newWidth == oldWidth {
		return
	}

	// Continuation lines with the minimal unambiguous indentation
	// attempt to keep the indentation as small as possible, so don't
	// realign them.
	if oldWidth == 8 {
		return
	}

	for _, rawLine := range fix.lines[1:] {
		_, comment, oldSpace := regex.Match2(rawLine.textnl, `^(#?)([ \t]*)`)
		newWidth := tabWidth(oldSpace) - oldWidth + newWidth
		newSpace := strings.Repeat("\t", newWidth/8) + strings.Repeat(" ", newWidth%8)
		replaced := strings.Replace(rawLine.textnl, comment+oldSpace, comment+newSpace, 1)
		if replaced != rawLine.textnl {
			if G.opts.PrintAutofix || G.opts.Autofix {
				rawLine.textnl = replaced
			}
			fix.Describef(rawLine.Lineno, "Replacing indentation %q with %q.", oldSpace, newSpace)
		}
	}
}

// InsertBefore prepends a line before the current line.
// The newline is added internally.
func (fix *Autofix) InsertBefore(text string) {
	if fix.skip() {
		return
	}

	fix.linesBefore = append(fix.linesBefore, text+"\n")
	fix.Describef(fix.lines[0].Lineno, "Inserting a line %q before this line.", text)
}

// InsertBefore appends a line after the current line.
// The newline is added internally.
func (fix *Autofix) InsertAfter(text string) {
	if fix.skip() {
		return
	}

	fix.linesAfter = append(fix.linesAfter, text+"\n")
	fix.Describef(fix.lines[len(fix.lines)-1].Lineno, "Inserting a line %q after this line.", text)
}

func (fix *Autofix) Delete() {
	if fix.skip() {
		return
	}

	for _, line := range fix.lines {
		fix.Describef(line.Lineno, "Deleting this line.")
		line.textnl = ""
	}
}

// Describef remembers a description of the actual fix
// for logging it later when Apply is called.
// There may be multiple fixes in one pass.
func (fix *Autofix) Describef(lineno int, format string, args ...interface{}) {
	fix.actions = append(fix.actions, autofixAction{fmt.Sprintf(format, args...), lineno})
}

// Notef remembers the note for logging it later when Apply is called.
func (fix *Autofix) Notef(format string, args ...interface{}) {
	fix.level = llNote
	fix.diagFormat = format
	fix.diagArgs = args
}

// Notef remembers the warning for logging it later when Apply is called.
func (fix *Autofix) Warnf(format string, args ...interface{}) {
	fix.level = llWarn
	fix.diagFormat = format
	fix.diagArgs = args
}

// Notef remembers the error for logging it later when Apply is called.
func (fix *Autofix) Errorf(format string, args ...interface{}) {
	fix.level = llError
	fix.diagFormat = format
	fix.diagArgs = args
}

// Explain remembers the explanation for logging it later when Apply is called.
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

	if shallBeLogged(fix.diagFormat) {
		logDiagnostic := fix.level != nil && fix.diagFormat != "Silent-Magic-Diagnostic" &&
			!(G.opts.Autofix && !G.opts.PrintAutofix) && len(fix.actions) > 0
		if logDiagnostic {
			msg := fmt.Sprintf(fix.diagFormat, fix.diagArgs...)
			logs(fix.level, line.Filename, line.Linenos(), fix.diagFormat, msg)
		}

		logRepair := len(fix.actions) > 0 && (G.opts.Autofix || G.opts.PrintAutofix)
		if logRepair {
			for _, action := range fix.actions {
				logs(llAutofix, line.Filename, strconv.Itoa(action.lineno), "", action.description)
			}
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

	fix.modified = fix.modified || len(fix.actions) > 0

	fix.actions = nil
	fix.level = nil
	fix.diagFormat = ""
	fix.diagArgs = nil
	fix.explanation = nil
}

func (fix *Autofix) skip() bool {
	// This check is necessary for the --only command line option.
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
		autofixed = true
	}
	return
}
