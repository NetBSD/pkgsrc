package pkglint

import (
	"io/ioutil"
	"netbsd.org/pkglint/regex"
	"os"
	"strconv"
	"strings"
)

// Autofix handles all modifications to a single line,
// describes them in a human-readable form and formats the output.
// The modifications are kept in memory only,
// until they are written to disk by SaveAutofixChanges.
type Autofix struct {
	line        *Line
	linesBefore []string // Newly inserted lines, including \n
	linesAfter  []string // Newly inserted lines, including \n
	// Whether an actual fix has been applied (or, without --show-autofix,
	// whether a fix is applicable)
	modified bool

	autofixShortTerm
}

// autofixShortTerm is the part of the Autofix that is reset after each call to Apply.
type autofixShortTerm struct {
	actions     []autofixAction // Human-readable description of the actual autofix actions
	level       *LogLevel       //
	diagFormat  string          // Is logged only if it couldn't be fixed automatically
	diagArgs    []interface{}   //
	explanation []string        // Is printed together with the diagnostic
	anyway      bool            // Print the diagnostic even if it cannot be autofixed
}

type autofixAction struct {
	description string
	lineno      int
}

// SilentAutofixFormat is used in exceptional situations when an
// autofix action is not directly related to a diagnostic.
//
// To prevent confusion, the code using this magic value must ensure
// to log a diagnostic by other means.
const SilentAutofixFormat = "SilentAutofixFormat"

// AutofixFormat is a special value that is used for logging
// diagnostics like "Replacing \"old\" with \"new\".".
//
// Since these are not really diagnostics, duplicates are not suppressed.
const AutofixFormat = "AutofixFormat"

func NewAutofix(line *Line) *Autofix {
	// FIXME: replacing the returned value with
	//  &Autofix{line: line, autofixShortTerm: autofixShortTerm{anyway: true}}
	//  makes some tests output source code without diagnostic.
	return &Autofix{line: line}
}

// Errorf remembers the error for logging it later when Apply is called.
func (fix *Autofix) Errorf(format string, args ...interface{}) {
	fix.setDiag(Error, format, args)
}

// Warnf remembers the warning for logging it later when Apply is called.
func (fix *Autofix) Warnf(format string, args ...interface{}) {
	fix.setDiag(Warn, format, args)
}

// Notef remembers the note for logging it later when Apply is called.
func (fix *Autofix) Notef(format string, args ...interface{}) {
	fix.setDiag(Note, format, args)
}

// Explain remembers the explanation for logging it later when Apply is called.
func (fix *Autofix) Explain(explanation ...string) {
	// Since a silent fix doesn't have a diagnostic, its explanation would
	// not provide any clue as to what diagnostic it belongs. That would
	// be confusing, therefore this case is not allowed.
	assert(fix.diagFormat != SilentAutofixFormat)

	fix.explanation = explanation
}

// Replace replaces "from" with "to", a single time.
func (fix *Autofix) Replace(from string, to string) {
	fix.ReplaceAfter("", from, to)
}

// ReplaceAfter replaces the text "prefix+from" with "prefix+to", a single time.
// In the diagnostic, only the replacement of "from" with "to" is mentioned.
func (fix *Autofix) ReplaceAfter(prefix, from string, to string) {
	fix.assertRealLine()
	if fix.skip() {
		return
	}

	prefixFrom := prefix + from
	prefixTo := prefix + to

	n := 0
	for _, rawLine := range fix.line.raw {
		n += strings.Count(rawLine.textnl, prefixFrom)
	}
	if n != 1 {
		return
	}

	for _, rawLine := range fix.line.raw {
		replaced := strings.Replace(rawLine.textnl, prefixFrom, prefixTo, 1)
		if replaced != rawLine.textnl {
			if G.Logger.IsAutofix() {
				rawLine.textnl = replaced

				// Fix the parsed text as well.
				// This is only approximate and won't work in some edge cases
				// that involve escaped comments or replacements across line breaks.
				//
				// TODO: Do this properly by parsing the whole line again,
				//  and ideally everything that depends on the parsed line.
				//  This probably requires a generic notification mechanism.
				fix.line.Text = strings.Replace(fix.line.Text, prefixFrom, prefixTo, 1)
			}
			fix.Describef(rawLine.Lineno, "Replacing %q with %q.", from, to)
			return
		}
	}
}

// ReplaceRegex replaces the first howOften or all occurrences (if negative)
// of the `from` pattern with the fixed string `toText`.
//
// Placeholders like `$1` are _not_ expanded in the `toText`.
// (If you know how to do the expansion correctly, feel free to implement it.)
func (fix *Autofix) ReplaceRegex(from regex.Pattern, toText string, howOften int) {
	fix.assertRealLine()
	if fix.skip() {
		return
	}

	done := 0
	for _, rawLine := range fix.line.raw {
		var froms []string // The strings that have actually changed

		replace := func(fromText string) string {
			if howOften >= 0 && done >= howOften {
				return fromText
			}
			froms = append(froms, fromText)
			done++
			return toText
		}

		replaced := replaceAllFunc(rawLine.textnl, from, replace)
		if replaced != rawLine.textnl {
			if G.Logger.IsAutofix() {
				rawLine.textnl = replaced
			}
			for _, fromText := range froms {
				fix.Describef(rawLine.Lineno, "Replacing %q with %q.", fromText, toText)
			}
		}
	}

	// Fix the parsed text as well.
	// This is only approximate and won't work in some edge cases
	// that involve escaped comments or replacements across line breaks.
	//
	// TODO: Do this properly by parsing the whole line again,
	//  and ideally everything that depends on the parsed line.
	//  This probably requires a generic notification mechanism.
	done = 0
	fix.line.Text = replaceAllFunc(
		fix.line.Text,
		from,
		func(fromText string) string {
			if howOften >= 0 && done >= howOften {
				return fromText
			}
			done++
			return toText
		})
}

// Custom runs a custom fix action, unless the fix is skipped anyway
// because of the --only option.
//
// The fixer function must check whether it can actually fix something,
// and if so, call Describef to describe the actual fix.
//
// If showAutofix and autofix are both false, the fix must only be
// described by calling Describef. No observable modification must be done,
// not even in memory.
//
// If showAutofix is true but autofix is false, the fix should be done in
// memory as far as possible. For example, changing the text of Line.raw
// is appropriate, but changing files in the file system is not.
//
// Only if autofix is true, fixes other than modifying the current Line
// should be done persistently, such as changes to the file system.
//
// In any case, changes to the current Line will be written back to disk
// by SaveAutofixChanges, after fixing all the lines in the file at once.
func (fix *Autofix) Custom(fixer func(showAutofix, autofix bool)) {
	// Contrary to the fixes that modify the line text, this one
	// can be run even on dummy lines (like those standing for a
	// file at whole), for example to fix the permissions of the file.

	if fix.skip() {
		return
	}

	fixer(G.Logger.Opts.ShowAutofix, G.Logger.Opts.Autofix)
}

// Describef is used while Autofix.Custom is called to remember a description
// of the actual fix for logging it later when Apply is called.
// Describef may be called multiple times before calling Apply.
func (fix *Autofix) Describef(lineno int, format string, args ...interface{}) {
	fix.actions = append(fix.actions, autofixAction{sprintf(format, args...), lineno})
}

// InsertBefore prepends a line before the current line.
// The newline is added internally.
func (fix *Autofix) InsertBefore(text string) {
	fix.assertRealLine()
	if fix.skip() {
		return
	}

	if G.Logger.IsAutofix() {
		fix.linesBefore = append(fix.linesBefore, text+"\n")
	}
	fix.Describef(fix.line.raw[0].Lineno, "Inserting a line %q before this line.", text)
}

// InsertAfter appends a line after the current line.
// The newline is added internally.
func (fix *Autofix) InsertAfter(text string) {
	fix.assertRealLine()
	if fix.skip() {
		return
	}

	if G.Logger.IsAutofix() {
		fix.linesAfter = append(fix.linesAfter, text+"\n")
	}
	fix.Describef(fix.line.raw[len(fix.line.raw)-1].Lineno, "Inserting a line %q after this line.", text)
}

// Delete removes the current line completely.
// It can be combined with InsertAfter or InsertBefore to
// replace the complete line with some different text.
func (fix *Autofix) Delete() {
	fix.assertRealLine()
	if fix.skip() {
		return
	}

	for _, line := range fix.line.raw {
		if G.Logger.IsAutofix() {
			line.textnl = ""
		}
		fix.Describef(line.Lineno, "Deleting this line.")
	}
}

// Anyway has the effect of showing the diagnostic even when nothing can
// be fixed automatically.
//
// As usual, the diagnostic is only shown if neither --show-autofix nor
// --autofix mode is given.
func (fix *Autofix) Anyway() {
	fix.anyway = !G.Logger.IsAutofix()
}

// Apply does the actual work.
// Depending on the pkglint mode, it either:
//
// * logs the associated message (default) but does not record the fixes in the line
//
// * logs what would be fixed (--show-autofix) and records the fixes in the line
//
// * records the fixes in the line (--autofix), ready for SaveAutofixChanges
func (fix *Autofix) Apply() {
	line := fix.line

	// Each autofix must have a log level and a diagnostic.
	// To fix this assertion, call one of Autofix.Errorf, Autofix.Warnf
	// or Autofix.Notef before calling Apply.
	assert(fix.level != nil)

	reset := func() {
		if len(fix.actions) > 0 {
			fix.modified = true
		}

		// Reduce number of calls to runtime.writeBarrier.
		fix.autofixShortTerm = autofixShortTerm{}
	}

	if !(G.Logger.Relevant(fix.diagFormat) && (len(fix.actions) > 0 || fix.anyway)) {
		reset()
		return
	}

	logDiagnostic := true
	switch {
	case fix.diagFormat == SilentAutofixFormat:
		logDiagnostic = false
	case G.Logger.Opts.Autofix && !G.Logger.Opts.ShowAutofix:
		logDiagnostic = false
	}

	logFix := G.Logger.IsAutofix()

	if logDiagnostic {
		msg := sprintf(fix.diagFormat, fix.diagArgs...)
		if !logFix && G.Logger.FirstTime(line.Filename, line.Linenos(), msg) {
			line.showSource(G.Logger.out)
		}
		G.Logger.Logf(fix.level, line.Filename, line.Linenos(), fix.diagFormat, msg)
	}

	if logFix {
		for _, action := range fix.actions {
			lineno := ""
			if action.lineno != 0 {
				lineno = strconv.Itoa(action.lineno)
			}
			G.Logger.Logf(AutofixLogLevel, line.Filename, lineno, AutofixFormat, action.description)
		}
	}

	if logDiagnostic || logFix {
		if logFix {
			line.showSource(G.Logger.out)
		}
		if logDiagnostic && len(fix.explanation) > 0 {
			line.Explain(fix.explanation...)
		}
		if G.Logger.Opts.ShowSource {
			if !(G.Logger.Opts.Explain && logDiagnostic && len(fix.explanation) > 0) {
				G.Logger.out.Separate()
			}
		}
	}

	reset()
}

func (fix *Autofix) Realign(mkline *MkLine, newWidth int) {

	// XXX: Check whether this method can be implemented as Custom fix.
	// This complicated code should not be in the Autofix type.

	fix.assertRealLine()
	assert(mkline.IsMultiline())
	assert(mkline.IsVarassign() || mkline.IsCommentedVarassign())

	if fix.skip() {
		return
	}

	normalized := true // Whether all indentation is tabs, followed by spaces.
	oldWidth := 0      // The minimum required indentation in the original lines.

	{
		// Parsing the continuation marker as variable value is cheating but works well.
		text := strings.TrimSuffix(mkline.raw[0].orignl, "\n")
		data := MkLineParser{}.split(nil, text)
		_, a := MkLineParser{}.MatchVarassign(mkline.Line, text, data)
		if a.value != "\\" {
			oldWidth = tabWidth(a.valueAlign)
		}
	}

	for _, rawLine := range fix.line.raw[1:] {
		_, comment, space := match2(rawLine.textnl, `^(#?)([ \t]*)`)
		width := tabWidth(comment + space)
		if (oldWidth == 0 || width < oldWidth) && width >= 8 {
			oldWidth = width
		}
		if !matches(space, `^\t* {0,7}$`) {
			normalized = false
		}
	}

	if normalized && newWidth == oldWidth {
		return
	}

	// 8 spaces is the minimum possible indentation that can be
	// distinguished from an initial line, by looking only at the
	// beginning of the line. Therefore, this indentation is always
	// regarded as intentional and is not realigned.
	if oldWidth == 8 {
		return
	}

	for _, rawLine := range fix.line.raw[1:] {
		_, comment, oldSpace := match2(rawLine.textnl, `^(#?)([ \t]*)`)
		newLineWidth := tabWidth(oldSpace) - oldWidth + newWidth
		newSpace := strings.Repeat("\t", newLineWidth/8) + strings.Repeat(" ", newLineWidth%8)
		replaced := strings.Replace(rawLine.textnl, comment+oldSpace, comment+newSpace, 1)
		if replaced != rawLine.textnl {
			if G.Logger.IsAutofix() {
				rawLine.textnl = replaced
			}
			fix.Describef(rawLine.Lineno, "Replacing indentation %q with %q.", oldSpace, newSpace)
		}
	}
}

func (fix *Autofix) setDiag(level *LogLevel, format string, args []interface{}) {
	if G.Testing && format != SilentAutofixFormat {
		assertf(
			hasSuffix(format, "."),
			"Autofix: format %q must end with a period.",
			format)
	}
	assert(fix.level == nil)     // Autofix can only have a single diagnostic.
	assert(fix.diagFormat == "") // Autofix can only have a single diagnostic.

	fix.level = level
	fix.diagFormat = format
	fix.diagArgs = args
}

func (fix *Autofix) skip() bool {
	assert(fix.diagFormat != "") // The diagnostic must be given before the action.

	// This check is necessary for the --only command line option.
	return !G.Logger.shallBeLogged(fix.diagFormat)
}

func (fix *Autofix) assertRealLine() {
	assert(fix.line.firstLine >= 1) // Cannot autofix this line since it is not a real line.
}

// SaveAutofixChanges writes the given lines back into their files,
// applying the autofix changes.
// The lines may come from different files.
// Only files that actually have changed lines are saved.
func SaveAutofixChanges(lines *Lines) (autofixed bool) {
	if trace.Tracing {
		defer trace.Call0()()
	}

	// Fast lane for the case that nothing is written back to disk.
	if !G.Logger.Opts.Autofix {
		for _, line := range lines.Lines {
			if line.autofix != nil && line.autofix.modified {
				G.Logger.autofixAvailable = true
				if G.Logger.Opts.ShowAutofix {
					// Only in this case can the loaded lines be modified.
					G.fileCache.Evict(line.Filename)
				}
			}
		}
		return
	}

	changes := make(map[string][]string)
	changed := make(map[string]bool)
	for _, line := range lines.Lines {
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

	for filename := range changed {
		G.fileCache.Evict(filename)
		changedLines := changes[filename]
		tmpName := filename + ".pkglint.tmp"
		var text strings.Builder
		for _, changedLine := range changedLines {
			text.WriteString(changedLine)
		}
		err := ioutil.WriteFile(tmpName, []byte(text.String()), 0666)
		if err != nil {
			G.Logger.Errorf(tmpName, "Cannot write: %s", err)
			continue
		}
		err = os.Rename(tmpName, filename)
		if err != nil {
			G.Logger.Errorf(tmpName, "Cannot overwrite with autofixed content: %s", err)
			continue
		}
		autofixed = true
	}
	return
}
