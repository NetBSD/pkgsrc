package main

import (
	"io"
)

const NO_FILE = ""
const NO_LINES = ""

type LogLevel struct {
	traditionalName string
	gccName         string
}

var (
	LL_FATAL = LogLevel{"FATAL", "fatal"}
	LL_ERROR = LogLevel{"ERROR", "error"}
	LL_WARN  = LogLevel{"WARN", "warning"}
	LL_NOTE  = LogLevel{"NOTE", "note"}
	LL_DEBUG = LogLevel{"DEBUG", "debug"}
)

var dummyLine = NewLine(NO_FILE, NO_LINES, "", nil)

func logMessage(level LogLevel, fname, lineno, message string) {
	if fname != NO_FILE {
		fname = cleanpath(fname)
	}

	var text, sep string
	if !G.opts.GccOutput {
		text += sep + level.traditionalName + ":"
		sep = " "
	}
	if fname != NO_FILE {
		text += sep + fname
		sep = ": "
		if lineno != NO_LINES {
			text += ":" + lineno
		}
	}
	if G.opts.GccOutput {
		text += sep + level.gccName + ":"
		sep = " "
	}
	text += sep + message + "\n"
	if level != LL_FATAL {
		io.WriteString(G.logOut, text)
	} else {
		io.WriteString(G.logErr, text)
	}
}

func fatalf(fname, lineno, format string, args ...interface{}) bool {
	message := sprintf(format, args...)
	logMessage(LL_FATAL, fname, lineno, message)
	panic(pkglintFatal{})
}
func errorf(fname, lineno, format string, args ...interface{}) bool {
	message := sprintf(format, args...)
	logMessage(LL_ERROR, fname, lineno, message)
	G.errors++
	return true
}
func warnf(fname, lineno, format string, args ...interface{}) bool {
	message := sprintf(format, args...)
	logMessage(LL_WARN, fname, lineno, message)
	G.warnings++
	return true
}
func notef(fname, lineno, format string, args ...interface{}) bool {
	message := sprintf(format, args...)
	logMessage(LL_NOTE, fname, lineno, message)
	return true
}
func debugf(fname, lineno, format string, args ...interface{}) bool {
	message := sprintf(format, args...)
	logMessage(LL_DEBUG, fname, lineno, message)
	return true
}

type pkglintFatal struct{}
