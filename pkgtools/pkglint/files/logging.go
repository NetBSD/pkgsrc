package main

import (
	"fmt"
	"io"
	"path"
	"strings"
)

type LogLevel struct {
	TraditionalName string
	GccName         string
}

var (
	llFatal   = &LogLevel{"FATAL", "fatal"}
	llError   = &LogLevel{"ERROR", "error"}
	llWarn    = &LogLevel{"WARN", "warning"}
	llNote    = &LogLevel{"NOTE", "note"}
	llAutofix = &LogLevel{"AUTOFIX", "autofix"}
)

var dummyLine = NewLine("", 0, "", nil)
var dummyMkLine = NewMkLine(dummyLine)

func shallBeLogged(msg string) bool {
	if len(G.opts.LogOnly) > 0 {
		found := false
		for _, substr := range G.opts.LogOnly {
			if contains(msg, substr) {
				found = true
				break
			}
		}
		if !found {
			return false
		}
	}

	return true
}

func loggedAlready(fname, lineno, msg string) bool {
	uniq := path.Clean(fname) + ":" + lineno + ":" + msg
	if G.logged[uniq] {
		return true
	}

	if G.logged == nil {
		G.logged = make(map[string]bool)
	}
	G.logged[uniq] = true
	return false
}

func logs(level *LogLevel, fname, lineno, format, msg string) bool {
	if fname != "" {
		fname = cleanpath(fname)
	}
	if G.Testing && format != "Magic-Autofix-Format" && !hasSuffix(format, ".") && !hasSuffix(format, ": %s") && !hasSuffix(format, ". %s") {
		panic(fmt.Sprintf("Diagnostic format %q must end in a period.", format))
	}

	if !G.opts.LogVerbose && loggedAlready(fname, lineno, msg) {
		return false
	}

	var text, sep string
	if !G.opts.GccOutput {
		text += sep + level.TraditionalName + ":"
		sep = " "
	}
	if fname != "" {
		text += sep + fname
		sep = ": "
		if lineno != "" {
			text += ":" + lineno
		}
	}
	if G.opts.GccOutput {
		text += sep + level.GccName + ":"
		sep = " "
	}
	if G.opts.Profiling && format != "Magic-Autofix-Format" {
		G.loghisto.Add(format, 1)
	}
	text += sep + msg + "\n"

	out := G.logOut
	if level == llFatal {
		out = G.logErr
	}

	out.Write(text)

	switch level {
	case llFatal:
		panic(pkglintFatal{})
	case llError:
		G.errors++
	case llWarn:
		G.warnings++
	}
	return true
}

// Explain outputs an explanation for the preceding diagnostic
// if the --explain option is given. Otherwise it just records
// that an explanation is available.
func Explain(explanation ...string) {
	if G.Testing {
		for _, s := range explanation {
			if l := tabWidth(s); l > 68 && contains(s, " ") {
				lastSpace := strings.LastIndexByte(s[:68], ' ')
				print(fmt.Sprintf("Long explanation line: %s\nBreak after: %s\n", s, s[:lastSpace]))
			}
			if m, before := match1(s, `(.+)\. [^ ]`); m {
				if !matches(before, `\d$|e\.g`) {
					print(fmt.Sprintf("Short space after period: %s\n", s))
				}
			}
		}
	}

	if !G.explainNext {
		return
	}
	G.explanationsAvailable = true
	if !G.opts.Explain {
		return
	}

	complete := strings.Join(explanation, "\n")
	if G.explanationsGiven[complete] {
		return
	}
	if G.explanationsGiven == nil {
		G.explanationsGiven = make(map[string]bool)
	}
	G.explanationsGiven[complete] = true

	G.logOut.WriteLine("")
	for _, explanationLine := range explanation {
		G.logOut.WriteLine("\t" + explanationLine)
	}
	G.logOut.WriteLine("")

}

type pkglintFatal struct{}

// SeparatorWriter writes output, occasionally separated by an
// empty line. This is used for layouting the diagnostics in
// --source mode combined with --show-autofix, where each
// log message consists of multiple lines.
type SeparatorWriter struct {
	out            io.Writer
	needSeparator  bool
	wroteSomething bool
}

func NewSeparatorWriter(out io.Writer) *SeparatorWriter {
	return &SeparatorWriter{out, false, false}
}

func (wr *SeparatorWriter) WriteLine(text string) {
	wr.Write(text)
	io.WriteString(wr.out, "\n")
}

func (wr *SeparatorWriter) Write(text string) {
	if wr.needSeparator && wr.wroteSomething {
		io.WriteString(wr.out, "\n")
		wr.needSeparator = false
	}
	io.WriteString(wr.out, text)
	wr.wroteSomething = true
}

func (wr *SeparatorWriter) Printf(format string, args ...interface{}) {
	wr.Write(fmt.Sprintf(format, args...))
}

func (wr *SeparatorWriter) Separate() {
	wr.needSeparator = true
}
