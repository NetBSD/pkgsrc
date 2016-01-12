package main

import (
	"fmt"
	"io"
	"strings"
)

const noFile = ""
const noLines = ""

type LogLevel struct {
	TraditionalName string
	GccName         string
}

var (
	llFatal   = &LogLevel{"FATAL", "fatal"}
	llError   = &LogLevel{"ERROR", "error"}
	llWarn    = &LogLevel{"WARN", "warning"}
	llNote    = &LogLevel{"NOTE", "note"}
	llDebug   = &LogLevel{"DEBUG", "debug"}
	llAutofix = &LogLevel{"AUTOFIX", "autofix"}
)

var dummyLine = NewLine(noFile, 0, "", nil)

func logf(out io.Writer, level *LogLevel, fname, lineno, format string, args ...interface{}) bool {
	if fname != noFile {
		fname = cleanpath(fname)
	}

	var text, sep string
	if !G.opts.GccOutput {
		text += sep + level.TraditionalName + ":"
		sep = " "
	}
	if fname != noFile {
		text += sep + fname
		sep = ": "
		if lineno != noLines {
			text += ":" + lineno
		}
	}
	if G.opts.GccOutput {
		text += sep + level.GccName + ":"
		sep = " "
	}
	if G.opts.Profiling {
		G.loghisto.Add(format, 1)
	}
	text += sep + fmt.Sprintf(format, args...) + "\n"
	io.WriteString(out, text)
	return true
}

func Fatalf(fname, lineno, format string, args ...interface{}) {
	logf(G.logErr, llFatal, fname, lineno, format, args...)
	panic(pkglintFatal{})
}
func Errorf(fname, lineno, format string, args ...interface{}) bool {
	G.errors++
	return logf(G.logOut, llError, fname, lineno, format, args...)
}
func Warnf(fname, lineno, format string, args ...interface{}) bool {
	G.warnings++
	return logf(G.logOut, llWarn, fname, lineno, format, args...)
}
func Notef(fname, lineno, format string, args ...interface{}) bool {
	return logf(G.logOut, llNote, fname, lineno, format, args...)
}
func autofixf(fname, lineno, format string, args ...interface{}) bool {
	return logf(G.logOut, llAutofix, fname, lineno, format, args...)
}
func Debugf(fname, lineno, format string, args ...interface{}) bool {
	return logf(G.debugOut, llDebug, fname, lineno, format, args...)
}

func Explain(explanation ...string) {
	if G.opts.Explain {
		complete := strings.Join(explanation, "\n")
		if G.explanationsGiven[complete] {
			return
		}
		if G.explanationsGiven == nil {
			G.explanationsGiven = make(map[string]bool)
		}
		G.explanationsGiven[complete] = true

		io.WriteString(G.logOut, "\n")
		for _, explanationLine := range explanation {
			io.WriteString(G.logOut, "\t"+explanationLine+"\n")
		}
		io.WriteString(G.logOut, "\n")
	} else if G.TestingData != nil {
		for _, s := range explanation {
			if l := tabLength(s); l > 68 && contains(s, " ") {
				print(fmt.Sprintf("Long explanation line (%d): %s\n", l, s))
			}
			if m, before := match1(s, `(.+)\. [^ ]`); m {
				if !matches(before, `\d$`) {
					print(fmt.Sprintf("Short space after period: %s\n", s))
				}
			}
		}
	}
	G.explanationsAvailable = true
}
func Explain1(e1 string)             { Explain(e1) }
func Explain2(e1, e2 string)         { Explain(e1, e2) }
func Explain3(e1, e2, e3 string)     { Explain(e1, e2, e3) }
func Explain4(e1, e2, e3, e4 string) { Explain(e1, e2, e3, e4) }

type pkglintFatal struct{}
