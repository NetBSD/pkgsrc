package pkglint

import (
	"netbsd.org/pkglint/regex"
	"os"
	"strconv"
	"strings"
)

type Autofixer interface {
	Diagnoser
	Autofix() *Autofix
}

// Autofix handles all modifications to a single line,
// possibly spanning multiple physical lines in case of Makefile lines,
// describes them in a human-readable form and formats the output.
// The modifications are kept in memory only,
// until they are written to disk by SaveAutofixChanges.
type Autofix struct {
	line        *Line
	linesBefore []string // Newly inserted lines, including \n
	linesAfter  []string // Newly inserted lines, including \n
	// Whether an actual fix has been applied to the text of the raw lines
	modified bool

	autofixShortTerm
}

// autofixShortTerm is the part of the Autofix that is reset after each call to Apply.
type autofixShortTerm struct {
	// Human-readable description of the actual autofix actions.
	// There can be more than one action in cases where a follow-up
	// fix is necessary.
	actions []autofixAction

	// The diagnostic to be logged.
	// It is subject to the --only command line option.
	// In --autofix mode it is suppressed if there were no actual actions.
	level       *LogLevel
	diagFormat  string
	diagArgs    []interface{}
	explanation []string
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

// autofixFormat is a special value that is used for logging
// diagnostics like "Replacing \"old\" with \"new\".".
//
// Since these are not really diagnostics, duplicates are not suppressed.
const autofixFormat = "AutofixFormat"

func NewAutofix(line *Line) *Autofix {
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
	// not provide any clue as to what diagnostic it belongs.
	// That would be confusing, therefore this case is not allowed.
	assert(fix.diagFormat != SilentAutofixFormat)

	fix.explanation = explanation
}

// Replace replaces "from" with "to", a single time.
// If the text is not found exactly once, nothing is replaced at all.
func (fix *Autofix) Replace(from string, to string) {
	fix.ReplaceAfter("", from, to)
}

// ReplaceAfter replaces the text "prefix+from" with "prefix+to", a single time.
// In the diagnostic, only the replacement of "from" with "to" is mentioned.
// If the text is not found exactly once, nothing is replaced at all.
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
				//
				// FIXME: Only actually update fix.line.Text if the replacement
				//  has been done exactly once; see ReplaceAt.
				fix.line.Text = strings.Replace(fix.line.Text, prefixFrom, prefixTo, 1)
			}
			fix.Describef(rawLine.Lineno, "Replacing %q with %q.", from, to)
			return
		}
	}
}

// ReplaceAt replaces the text "from" with "to", a single time.
// If the text at the given position does not match, ReplaceAt panics.
func (fix *Autofix) ReplaceAt(rawIndex int, textIndex int, from string, to string) {
	assert(from != to)
	fix.assertRealLine()

	// XXX: This should only affect the diagnostics, but not the modifications
	//  to the text of the affected line, since that text will be used in
	//  further checks.
	if fix.skip() {
		return
	}

	rawLine := fix.line.raw[rawIndex]
	assert(textIndex < len(rawLine.textnl))
	assert(hasPrefix(rawLine.textnl[textIndex:], from))

	replaced := rawLine.textnl[:textIndex] + to + rawLine.textnl[textIndex+len(from):]

	rawLine.textnl = replaced

	// Fix the parsed text as well.
	// This is only approximate and won't work in some edge cases
	// that involve escaped comments or replacements across line breaks.
	//
	// TODO: Do this properly by parsing the whole line again,
	//  and ideally everything that depends on the parsed line.
	//  This probably requires a generic notification mechanism.
	if strings.Count(fix.line.Text, from) == 1 {
		fix.line.Text = strings.Replace(fix.line.Text, from, to, 1)
	}

	fix.Describef(rawLine.Lineno, "Replacing %q with %q.", from, to)
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
	//
	// FIXME: Only actually update fix.line.Text if the replacement
	//  has been done exactly once.
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

// Custom runs a custom fix action, unless the fix is skipped anyway
// because of the --only option.
//
// The fixer function must check whether it can actually fix something,
// and if so, call Describef to describe the actual fix.
//
// If autofix is false, the the fix should be applied, as far as only
// in-memory data structures are effected, and these are not written
// back to disk. No externally observable modification must be done.
// For example, changing the text of Line.raw is appropriate,
// but changing files in the file system is not.
//
// Only if autofix is true, fixes other than modifying the current Line
// should be done persistently, such as changes to the file system.
//
// If pkglint is run in --autofix mode, all changes to the lines of a
// file will be collected in memory and are written back to disk by
// SaveAutofixChanges, once at the end.
func (fix *Autofix) Custom(fixer func(showAutofix, autofix bool)) {
	// Contrary to the fixes that modify the line text, this one
	// can be run even on dummy lines (like those standing for a
	// file at whole), for example to fix the permissions of the file.

	if fix.skip() {
		return
	}

	fixer(G.Logger.Opts.ShowAutofix, G.Logger.Opts.Autofix)
}

// Describef can be called from within an Autofix.Custom call to remember a
// description of the actual fix for logging it later when Apply is called.
// Describef may be called multiple times before calling Apply.
func (fix *Autofix) Describef(lineno int, format string, args ...interface{}) {
	fix.actions = append(fix.actions, autofixAction{sprintf(format, args...), lineno})
}

// Apply does the actual work that has been prepared by previous calls to
// Errorf, Warnf, Notef, Describef, Replace, Delete and so on.
//
// In default mode, the diagnostic is logged even when nothing has actually
// been fixed. This frees the calling code from distinguishing the cases where
// a fix can or cannot be applied automatically.
//
// In --show-autofix mode, only those diagnostics are logged that actually fix
// something. This is done to hide possibly distracting, unrelated diagnostics.
//
// In --autofix mode, only the actual changes are logged, but not the
// corresponding diagnostics. To get both, specify --show-autofix as well.
//
// Apply does the modifications only in memory. To actually save them to disk,
// SaveAutofixChanges needs to be called. For example, this is done by
// MkLines.Check.
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

		fix.autofixShortTerm = autofixShortTerm{}
	}

	if !(G.Logger.Relevant(fix.diagFormat) && (len(fix.actions) > 0 || !G.Logger.IsAutofix())) {
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
		linenos := fix.affectedLinenos()
		msg := sprintf(fix.diagFormat, fix.diagArgs...)
		if !logFix && G.Logger.FirstTime(line.Filename, linenos, msg) {
			G.Logger.showSource(line)
		}
		G.Logger.Logf(fix.level, line.Filename, linenos, fix.diagFormat, msg)
	}

	if logFix {
		for _, action := range fix.actions {
			lineno := ""
			if action.lineno != 0 {
				lineno = strconv.Itoa(action.lineno)
			}
			G.Logger.Logf(AutofixLogLevel, line.Filename, lineno, autofixFormat, action.description)
		}
		G.Logger.showSource(line)
	}

	if logDiagnostic && len(fix.explanation) > 0 {
		line.Explain(fix.explanation...)
	}

	reset()
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

func (fix *Autofix) affectedLinenos() string {
	if len(fix.actions) == 0 {
		return fix.line.Linenos()
	}

	var first, last int
	for _, action := range fix.actions {
		if action.lineno == 0 {
			continue
		}

		if last == 0 || action.lineno < first {
			first = action.lineno
		}
		if last == 0 || action.lineno > last {
			last = action.lineno
		}
	}

	if last == 0 {
		return fix.line.Linenos()
	} else if first < last {
		return sprintf("%d--%d", first, last)
	} else {
		return strconv.Itoa(first)
	}
}

// skip returns whether this autofix should be skipped because
// its message is matched by one of the --only command line options.
func (fix *Autofix) skip() bool {
	assert(fix.diagFormat != "") // The diagnostic must be given before the action.

	return !G.Logger.shallBeLogged(fix.diagFormat)
}

func (fix *Autofix) assertRealLine() {
	// Some Line objects do not correspond to real lines of a file.
	// These cannot be fixed since they are neither part of Lines nor of MkLines.
	assert(fix.line.firstLine >= 1)
}

// SaveAutofixChanges writes the given lines back into their files,
// applying the autofix changes.
// The lines may come from different files.
// Only files that actually have changed lines are saved.
//
// This only happens in --autofix mode.
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

	if G.Testing {
		abs := G.Abs(lines.Filename)
		absTmp := G.Abs(NewCurrPathSlash(os.TempDir()))

		// This assertion prevents the pkglint tests from overwriting files
		// on disk. This can easily happen if a test creates Lines or MkLines
		// using a relative path.
		//
		// By default, these paths are relative to the current working
		// directory. To let them refer to the temporary directory used by
		// the tests, call t.Chdir(".").
		assertf(abs.HasPrefixPath(absTmp), "%q must be inside %q", abs, absTmp)
	}

	changes := make(map[CurrPath][]string)
	changed := make(map[CurrPath]bool)
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
		err := tmpName.WriteString(text.String())
		if err != nil {
			G.Logger.TechErrorf(tmpName, "Cannot write: %s", err)
			continue
		}
		err = tmpName.Rename(filename)
		if err != nil {
			G.Logger.TechErrorf(tmpName, "Cannot overwrite with autofixed content: %s", err)
			continue
		}
		autofixed = true
	}
	return
}
