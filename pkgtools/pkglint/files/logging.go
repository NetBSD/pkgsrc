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
	llFatal = LogLevel{"FATAL", "fatal"}
	llError = LogLevel{"ERROR", "error"}
	llWarn  = LogLevel{"WARN", "warning"}
	llNote  = LogLevel{"NOTE", "note"}
	llDebug = LogLevel{"DEBUG", "debug"}
)

var dummyLine = NewLine(noFile, noLines, "", nil)

func logMessage(level LogLevel, fname, lineno, message string) {
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
	text += sep + message + "\n"
	if level != llFatal {
		io.WriteString(G.logOut, text)
	} else {
		io.WriteString(G.logErr, text)
	}
}

func fatalf(fname, lineno, format string, args ...interface{}) bool {
	message := sprintf(format, args...)
	logMessage(llFatal, fname, lineno, message)
	panic(pkglintFatal{})
}
func errorf(fname, lineno, format string, args ...interface{}) bool {
	message := sprintf(format, args...)
	logMessage(llError, fname, lineno, message)
	G.errors++
	return true
}
func warnf(fname, lineno, format string, args ...interface{}) bool {
	message := sprintf(format, args...)
	logMessage(llWarn, fname, lineno, message)
	G.warnings++
	return true
}
func notef(fname, lineno, format string, args ...interface{}) bool {
	message := sprintf(format, args...)
	logMessage(llNote, fname, lineno, message)
	return true
}
func debugf(fname, lineno, format string, args ...interface{}) bool {
	message := sprintf(format, args...)
	logMessage(llDebug, fname, lineno, message)
	return true
}

type pkglintFatal struct{}
