package main

import (
	"io"
)

const noFile = ""
const noLines = ""

type LogLevel struct {
	traditionalName string
	gccName         string
}

var (
	llFatal = &LogLevel{"FATAL", "fatal"}
	llError = &LogLevel{"ERROR", "error"}
	llWarn  = &LogLevel{"WARN", "warning"}
	llNote  = &LogLevel{"NOTE", "note"}
	llDebug = &LogLevel{"DEBUG", "debug"}
)

var dummyLine = NewLine(noFile, noLines, "", nil)

func logf(out io.Writer, level *LogLevel, fname, lineno, format string, args ...interface{}) bool {
	if fname != noFile {
		fname = cleanpath(fname)
	}

	var text, sep string
	if !G.opts.GccOutput {
		text += sep + level.traditionalName + ":"
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
		text += sep + level.gccName + ":"
		sep = " "
	}
	text += sep + sprintf(format, args...) + "\n"
	io.WriteString(out, text)
	return true
}

func fatalf(fname, lineno, format string, args ...interface{}) {
	logf(G.logErr, llFatal, fname, lineno, format, args...)
	panic(pkglintFatal{})
}
func errorf(fname, lineno, format string, args ...interface{}) bool {
	G.errors++
	return logf(G.logOut, llError, fname, lineno, format, args...)
}
func warnf(fname, lineno, format string, args ...interface{}) bool {
	G.warnings++
	return logf(G.logOut, llWarn, fname, lineno, format, args...)
}
func notef(fname, lineno, format string, args ...interface{}) bool {
	return logf(G.logOut, llNote, fname, lineno, format, args...)
}
func debugf(fname, lineno, format string, args ...interface{}) bool {
	return logf(G.logOut, llDebug, fname, lineno, format, args...)
}

type pkglintFatal struct{}
