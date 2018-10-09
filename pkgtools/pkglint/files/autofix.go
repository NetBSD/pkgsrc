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

// Custom runs a custom fix action, unless the fix is skipped anyway
// because of the --only option.
//
// The fixer function must always call Describef.
//
// If printAutofix or autofix is true, the fix should be done in
// memory as far as possible (e.g. changes to the text of the line).
//
// If autofix is true, the fix should be done persistently
// (e.g. direct changes to the file system). Except if the fix only
// affects the current line, then SaveAutofixChanges will do that.
func (fix *Autofix) Custom(fixer func(printAutofix, autofix bool)) {
	if fix.skip() {
		return
	}

	fixer(G.opts.PrintAutofix, G.opts.Autofix)
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

// ReplaceRegex replaces the first howOften or all occurrences (if negative)
// of the `from` pattern with the fixed string `toText`.
//
// Placeholders like `$1` are _not_ expanded in the `toText`.
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

			if replaced := replaceAllFunc(rawLine.textnl, from, replace); replaced != rawLine.textnl {
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
		text := strings.TrimSuffix(mkline.raw[0].orignl, "\n")
		m, _, _, _, _, valueAlign, value, _, _ := MatchVarassign(text)
		if m && value != "\\" {
			oldWidth = tabWidth(valueAlign)
		}
	}

	for _, rawLine := range fix.lines[1:] {
		_, comment, space := match2(rawLine.textnl, `^(#?)([ \t]*)`)
		width := tabWidth(comment + space)
		if (oldWidth == 0 || width < oldWidth) && width >= 8 && rawLine.textnl != "\n" {
			oldWidth = width
		}
		if !matches(space, `^\t* {0,7}$`) {
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
		_, comment, oldSpace := match2(rawLine.textnl, `^(#?)([ \t]*)`)
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

// InsertAfter appends a line after the current line.
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
	fix.setDiag(llNote, format, args)
}

// Warnf remembers the warning for logging it later when Apply is called.
func (fix *Autofix) Warnf(format string, args ...interface{}) {
	fix.setDiag(llWarn, format, args)
}

// Errorf remembers the error for logging it later when Apply is called.
func (fix *Autofix) Errorf(format string, args ...interface{}) {
	fix.setDiag(llError, format, args)
}

// Explain remembers the explanation for logging it later when Apply is called.
func (fix *Autofix) Explain(explanation ...string) {
	fix.explanation = explanation
}

// Apply does the actual work.
// Depending on the pkglint mode, it either:
//
// * logs the associated message (default)
// * logs what would be fixed (--show-autofix)
// * records the fixes in the line (--autofix)
func (fix *Autofix) Apply() {
	line := fix.line

	if fix.diagFormat == "" {
		panic("Each autofix must have a diagnostic.")
	}
	G.explainNext = shallBeLogged(fix.diagFormat)
	if G.explainNext {
		logDiagnostic := fix.level != nil && fix.diagFormat != "Silent-Magic-Diagnostic" &&
			!(G.opts.Autofix && !G.opts.PrintAutofix) && len(fix.actions) > 0
		if logDiagnostic {
			msg := fmt.Sprintf(fix.diagFormat, fix.diagArgs...)
			logs(fix.level, line.Filename, line.Linenos(), fix.diagFormat, msg)
		}

		logRepair := len(fix.actions) > 0 && (G.opts.Autofix || G.opts.PrintAutofix)
		if logRepair {
			for _, action := range fix.actions {
				lineno := ""
				if action.lineno != 0 {
					lineno = strconv.Itoa(action.lineno)
				}
				logs(llAutofix, line.Filename, lineno, "Magic-Autofix-Format", action.description)
			}
		}

		if logDiagnostic || logRepair {
			line.printSource(G.logOut)
			if logDiagnostic && len(fix.explanation) != 0 {
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

func (fix *Autofix) setDiag(level *LogLevel, format string, args []interface{}) {
	if G.Testing && format != "Silent-Magic-Diagnostic" && !hasSuffix(format, ".") {
		panic(fmt.Sprintf("Autofix: format %q must end with a period.", format))
	}

	fix.level = level
	fix.diagFormat = format
	fix.diagArgs = args
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
				G.fileCache.Evict(line.Filename)
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
		G.fileCache.Evict(fname)
		changedLines := changes[fname]
		tmpname := fname + ".pkglint.tmp"
		text := ""
		for _, changedLine := range changedLines {
			text += changedLine
		}
		err := ioutil.WriteFile(tmpname, []byte(text), 0666)
		if err != nil {
			logs(llError, tmpname, "", "Cannot write: %s", "Cannot write: "+err.Error())
			continue
		}
		err = os.Rename(tmpname, fname)
		if err != nil {
			logs(llError, tmpname, "",
				"Cannot overwrite with auto-fixed content: %s",
				"Cannot overwrite with auto-fixed content: "+err.Error())
			continue
		}
		autofixed = true
	}
	return
}
