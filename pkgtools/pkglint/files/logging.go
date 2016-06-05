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

func shallBeLogged(fname, lineno, msg string) bool {
	uniq := path.Clean(fname) + ":" + lineno + ":" + msg
	if G.logged[uniq] {
		return false
	}

	if G.logged == nil {
		G.logged = make(map[string]bool)
	}
	G.logged[uniq] = true
	return true
}

func logs(level *LogLevel, fname, lineno, format, msg string) bool {
	if fname != "" {
		fname = cleanpath(fname)
	}

	if !G.opts.LogVerbose && !shallBeLogged(fname, lineno, msg) {
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
	if G.opts.Profiling {
		G.loghisto.Add(format, 1)
	}
	text += sep + msg + "\n"

	out := G.logOut
	if level == llFatal {
		out = G.logErr
	}

	io.WriteString(out, text)

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
	} else if G.Testing {
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
