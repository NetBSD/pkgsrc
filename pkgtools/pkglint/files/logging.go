package pkglint

import (
	"bytes"
	"io"
	"netbsd.org/pkglint/histogram"
	"netbsd.org/pkglint/textproc"
	"strings"
)

// Diagnoser provides the standard way of producing errors, warnings
// and notes, and explanations for them.
//
// For convenience, it is implemented by several types in pkglint.
type Diagnoser interface {
	Errorf(format string, args ...interface{})
	Warnf(format string, args ...interface{})
	Notef(format string, args ...interface{})
	Explain(explanation ...string)
}

type Logger struct {
	Opts LoggerOpts

	out *SeparatorWriter
	err *SeparatorWriter

	suppressDiag bool
	suppressExpl bool
	prevLine     *Line

	verbose   bool // allow duplicate diagnostics, even in the same line
	logged    Once
	explained Once
	histo     *histogram.Histogram

	errors                int
	warnings              int
	notes                 int
	explanationsAvailable bool
	autofixAvailable      bool
}

type LoggerOpts struct {
	ShowAutofix,
	Autofix,
	Explain,
	ShowSource,
	GccOutput,
	Quiet bool

	Only []string
}

type LogLevel struct {
	TraditionalName string
	GccName         string
}

var (
	Error           = &LogLevel{"ERROR", "error"}
	Warn            = &LogLevel{"WARN", "warning"}
	Note            = &LogLevel{"NOTE", "note"}
	AutofixLogLevel = &LogLevel{"AUTOFIX", "autofix"}
)

// Explain outputs an explanation for the preceding diagnostic
// if the --explain option is given. Otherwise it just records
// that an explanation is available.
func (l *Logger) Explain(explanation ...string) {
	if l.suppressExpl {
		return
	}

	l.explanationsAvailable = true
	if !l.Opts.Explain {
		return
	}

	if !l.explained.FirstTimeSlice(explanation...) {
		return
	}

	// The explanation should fit nicely on a screen that is 80
	// characters wide. The explanation is indented using a tab, and
	// there should be a little margin at the right. The resulting
	// number comes remarkably close to the line width recommended
	// by typographers, which is 66.
	const explanationWidth = 80 - 8 - 4

	l.prevLine = nil
	l.out.Separate()
	wrapped := wrap(explanationWidth, explanation...)
	for _, explanationLine := range wrapped {
		if explanationLine != "" {
			l.out.Write("\t")
		}
		l.out.WriteLine(escapePrintable(explanationLine))
	}
	l.out.WriteLine("")
}

// Diag logs a diagnostic. These are filtered by the --only command line option,
// and duplicates are suppressed unless the --log-verbose command line option is given.
//
// See Logf for logging arbitrary messages.
func (l *Logger) Diag(line *Line, level *LogLevel, format string, args ...interface{}) {
	if G.Testing {
		for _, arg := range args {
			switch arg.(type) {
			case int, string:
			case error:
				// TODO: errors do not belong in diagnostics,
				//  they belong in normal error messages.
			default:
				// All paths in diagnostics must be relative to the line.
				// To achieve that, call line.Rel(currPath).
				_ = arg.(RelPath)
			}
		}
	}

	if l.IsAutofix() {
		// In these two cases, the only interesting diagnostics are those that can
		// be fixed automatically. These are logged by Autofix.Apply.
		l.suppressExpl = true
		return
	}

	if !l.Relevant(format) {
		return
	}

	filename := line.Filename()
	linenos := line.Linenos()
	msg := sprintf(format, args...)
	if !l.FirstTime(filename, linenos, msg) {
		l.suppressDiag = false
		return
	}

	if l.Opts.ShowSource {
		if line != l.prevLine {
			l.out.Separate()
		}
		l.writeSource(line)
	}

	l.Logf(level, filename, linenos, format, msg)
}

func (l *Logger) FirstTime(filename CurrPath, linenos, msg string) bool {
	if l.verbose {
		return true
	}

	if !l.logged.FirstTimeSlice(filename.Clean().String(), linenos, msg) {
		l.suppressDiag = true
		l.suppressExpl = true
		return false
	}

	return true
}

// Relevant decides and remembers whether the given diagnostic is relevant and should be logged.
//
// The result of the decision affects all log items until Relevant is called for the next time.
func (l *Logger) Relevant(format string) bool {
	relevant := l.shallBeLogged(format)
	l.suppressDiag = !relevant
	l.suppressExpl = !relevant
	return relevant
}

// shallBeLogged tests whether a diagnostic with the given format should
// be logged.
//
// It only inspects the --only arguments; duplicates are handled in Logger.Logf.
func (l *Logger) shallBeLogged(format string) bool {
	if len(l.Opts.Only) == 0 {
		return true
	}

	for _, substr := range l.Opts.Only {
		if contains(format, substr) {
			return true
		}
	}
	return false
}

func (l *Logger) writeSource(line *Line) {
	if !G.Logger.Opts.ShowSource {
		return
	}

	if !l.IsAutofix() {
		if line == l.prevLine {
			return
		}
		l.prevLine = line
	}

	if !l.IsAutofix() {
		l.out.Separate()
	}
	if l.IsAutofix() {
		for _, above := range line.fix.above {
			l.writeLine("+\t", above)
		}
		l.writeDiff(line)
		for _, below := range line.fix.below {
			l.writeLine("+\t", below)
		}
	} else {
		l.writeDiff(line)
	}
	if l.IsAutofix() {
		l.out.Separate()
	}
}

func (l *Logger) writeDiff(line *Line) {
	showAsChanged := func(rawIndex int, rawLine *RawLine) bool {
		return l.IsAutofix() &&
			line.fix.texts[rawIndex] != rawLine.orignl
	}

	rawLines := line.raw

	prefix := ">\t"
	for rawIndex, rawLine := range rawLines {
		if showAsChanged(rawIndex, rawLine) {
			prefix = "\t" // Make it look like an actual diff
		}
	}

	for rawIndex, rawLine := range rawLines {
		if showAsChanged(rawIndex, rawLine) {
			l.writeLine("-\t", rawLine.orignl)
			if line.fix.texts[rawIndex] != "" {
				l.writeLine("+\t", line.fix.texts[rawIndex])
			}
		} else {
			l.writeLine(prefix, rawLine.orignl)
		}
	}
}

func (l *Logger) writeLine(prefix, line string) {
	out := l.out
	out.Write(prefix)
	out.Write(escapePrintable(line))
	if !hasSuffix(line, "\n") {
		out.Write("\n")
	}
}

// IsAutofix returns whether one of the --show-autofix or --autofix options is active.
func (l *Logger) IsAutofix() bool { return l.Opts.Autofix || l.Opts.ShowAutofix }

func (l *Logger) Logf(level *LogLevel, filename CurrPath, lineno, format, msg string) {
	if l.suppressDiag {
		l.suppressDiag = false
		return
	}

	if G.Testing {
		if level != Error {
			assertf(
				!contains(format, "must"),
				"The word \"must\" must only appear in errors: %s", format)
		}
		if level != Warn && level != Note {
			assertf(
				!contains(format, "should"),
				"The word \"should\" must only appear in warnings: %s", format)
		}
	}

	if G.Testing && format != autofixFormat {
		if textproc.Alpha.Contains(format[0]) {
			assertf(
				textproc.Upper.Contains(format[0]),
				"Diagnostic %q must start with an uppercase letter.",
				format)
		}

		if !hasSuffix(format, ": %s") && !hasSuffix(format, ". %s") {
			assertf(hasSuffix(format, "."), "Diagnostic format %q must end in a period.", format)
		}
	}

	if !filename.IsEmpty() {
		filename = filename.CleanPath()
	}
	if G.Profiling && format != autofixFormat {
		l.histo.Add(format, 1)
	}

	filenameSep := condStr(!filename.IsEmpty(), ": ", "")
	effLineno := condStr(!filename.IsEmpty(), lineno, "")
	linenoSep := condStr(effLineno != "", ":", "")
	var diag string
	if l.Opts.GccOutput {
		diag = sprintf("%s%s%s%s%s: %s\n", filename, linenoSep, effLineno, filenameSep, level.GccName, msg)
	} else {
		diag = sprintf("%s%s%s%s%s: %s\n", level.TraditionalName, filenameSep, filename, linenoSep, effLineno, msg)
	}
	l.out.Write(escapePrintable(diag))

	switch level {
	case Error:
		l.errors++
	case Warn:
		l.warnings++
	case Note:
		l.notes++
	}
}

// TechFatalf logs a technical error on the error output and quits pkglint.
//
// For diagnostics, use Logf instead.
func (l *Logger) TechFatalf(location CurrPath, format string, args ...interface{}) {
	loc := location.String() + condStr(location.IsEmpty(), "", ": ")
	msg := sprintf(format, args...)
	all := sprintf("FATAL: %s%s\n", loc, msg)
	esc := escapePrintable(all)
	l.err.Write(esc)

	if trace.Tracing {
		trace.Stepf("TechFatalf: %s%s", loc, msg)
	}
	panic(pkglintFatal{})
}

// TechErrorf logs a technical error on the error output.
//
// For diagnostics, use Logf instead.
func (l *Logger) TechErrorf(location CurrPath, format string, args ...interface{}) {
	loc := location.String() + condStr(location.IsEmpty(), "", ": ")
	msg := sprintf(format, args...)
	all := sprintf("ERROR: %s%s\n", loc, msg)
	esc := escapePrintable(all)
	l.err.Write(esc)
}

func (l *Logger) ShowSummary(args []string) {
	if l.Opts.Quiet || l.Opts.Autofix {
		return
	}

	if l.Opts.ShowSource {
		l.out.Separate()
	}

	if l.errors != 0 || l.warnings != 0 {
		num := func(n int, singular, plural string) string {
			if n == 0 {
				return ""
			} else if n == 1 {
				return sprintf("%d %s", n, singular)
			} else {
				return sprintf("%d %s", n, plural)
			}
		}

		l.out.Write(sprintf("%s found.\n",
			joinCambridge("and",
				num(l.errors, "error", "errors"),
				num(l.warnings, "warning", "warnings"),
				num(l.notes, "note", "notes"))))
	} else {
		l.out.WriteLine("Looks fine.")
	}

	commandLine := func(arg string) string {
		argv := append([]string{args[0], arg}, args[1:]...)
		for i := range argv {
			argv[i] = shquote(argv[i])
		}
		return strings.Join(argv, " ")
	}

	if l.explanationsAvailable && !l.Opts.Explain {
		l.out.WriteLine(sprintf("(Run \"%s\" to show explanations.)", commandLine("-e")))
	}
	if l.autofixAvailable {
		if !l.Opts.ShowAutofix {
			l.out.WriteLine(sprintf("(Run \"%s\" to show what can be fixed automatically.)", commandLine("-fs")))
		}
		l.out.WriteLine(sprintf("(Run \"%s\" to automatically fix some issues.)", commandLine("-F")))
	}
}

// SeparatorWriter writes output, occasionally separated by an
// empty line. This is used for separating the diagnostics when
// --source is combined with --show-autofix, where each
// log message consists of multiple lines.
type SeparatorWriter struct {
	out   io.Writer
	state uint8 // 0 = beginning of line, 1 = in line, 2 = separator wanted, 3 = paragraph
	line  bytes.Buffer
}

func NewSeparatorWriter(out io.Writer) *SeparatorWriter {
	assertNotNil(out)
	return &SeparatorWriter{out, 3, bytes.Buffer{}}
}

func (wr *SeparatorWriter) WriteLine(text string) {
	wr.Write(text)
	wr.write('\n')
}

func (wr *SeparatorWriter) Write(text string) {
	for _, b := range []byte(text) {
		wr.write(b)
	}
}

// Separate remembers to output an empty line before the next character.
//
// The writer must not be in the middle of a line.
func (wr *SeparatorWriter) Separate() {
	assert(wr.state != 1)
	if wr.state < 2 {
		wr.state = 2
	}
}

func (wr *SeparatorWriter) write(b byte) {
	if b == '\n' {
		if wr.state == 1 {
			wr.state = 0
		} else {
			wr.state = 3
		}
		wr.line.WriteByte('\n')
		wr.Flush()
		return
	}

	if wr.state == 2 {
		wr.line.WriteByte('\n')
		wr.Flush()
	}
	wr.state = 1
	wr.line.WriteByte(b)
}

func (wr *SeparatorWriter) Flush() {
	_, _ = io.Copy(wr.out, &wr.line)
	wr.line.Reset()
}
