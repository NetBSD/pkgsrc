package main

import (
	"io/ioutil"
	"os"
	"strings"
)

func LoadNonemptyLines(fname string, joinContinuationLines bool) []*Line {
	lines, err := readLines(fname, joinContinuationLines)
	if err != nil {
		errorf(fname, NO_LINES, "Cannot be read.")
		return nil
	}
	if len(lines) == 0 {
		errorf(fname, NO_LINES, "Must not be empty.")
		return nil
	}
	return lines
}

func LoadExistingLines(fname string, foldBackslashLines bool) []*Line {
	lines, err := readLines(fname, foldBackslashLines)
	if lines == nil || err != nil {
		fatalf(fname, NO_LINES, "Cannot be read.")
	}
	return lines
}

func getLogicalLine(fname string, rawLines []*RawLine, pindex *int) *Line {
	text := ""
	index := *pindex
	firstlineno := rawLines[index].lineno
	var lineRawLines []*RawLine
	interestingRawLines := rawLines[index:]

	for i, rawLine := range interestingRawLines {
		indent, rawText, outdent, cont := splitRawLine(rawLine.textnl)

		if text == "" {
			text += indent
		}
		text += rawText
		lineRawLines = append(lineRawLines, rawLine)

		if cont == "\\" && i != len(interestingRawLines)-1 {
			text += " "
			index++
		} else {
			text += outdent + cont
			break
		}
	}

	lastlineno := rawLines[index].lineno
	*pindex = index + 1

	if firstlineno == lastlineno {
		return NewLine(fname, sprintf("%d", firstlineno), text, lineRawLines)
	} else {
		return NewLine(fname, sprintf("%d--%d", firstlineno, lastlineno), text, lineRawLines)
	}
}

func splitRawLine(textnl string) (leadingWhitespace, text, trailingWhitespace, cont string) {
	m1234 := strings.TrimSuffix(textnl, "\n")
	m234 := strings.TrimLeft(m1234, " \t")
	m23 := strings.TrimSuffix(m234, "\\")
	m2 := strings.TrimRight(m23, " \t")
	return m1234[:len(m1234)-len(m234)], m2, m23[len(m2):], m234[len(m23):]
}

func readLines(fname string, joinContinuationLines bool) ([]*Line, error) {
	rawText, err := ioutil.ReadFile(fname)
	if err != nil {
		return nil, err
	}

	return convertToLogicalLines(fname, string(rawText), joinContinuationLines), nil
}

func convertToLogicalLines(fname string, rawText string, joinContinuationLines bool) []*Line {
	var rawLines []*RawLine
	for lineno, rawLine := range strings.SplitAfter(rawText, "\n") {
		if rawLine != "" {
			rawLines = append(rawLines, &RawLine{1 + lineno, rawLine})
		}
	}

	var loglines []*Line
	if joinContinuationLines {
		for lineno := 0; lineno < len(rawLines); {
			loglines = append(loglines, getLogicalLine(fname, rawLines, &lineno))
		}
	} else {
		for _, rawLine := range rawLines {
			loglines = append(loglines, NewLine(fname, sprintf("%d", rawLine.lineno), strings.TrimSuffix(rawLine.textnl, "\n"), []*RawLine{rawLine}))
		}
	}

	if 0 < len(rawLines) && !hasSuffix(rawLines[len(rawLines)-1].textnl, "\n") {
		errorf(fname, sprintf("%d", rawLines[len(rawLines)-1].lineno), "File must end with a newline.")
	}

	return loglines
}

func saveAutofixChanges(lines []*Line) {
	if !G.opts.Autofix || !G.autofixAvailable {
		return
	}

	changes := make(map[string][]*RawLine)
	changed := make(map[string]bool)
	for _, line := range lines {
		if line.changed {
			changed[line.fname] = true
		}
		changes[line.fname] = append(changes[line.fname], line.rawLines()...)
	}

	for fname := range changed {
		rawLines := changes[fname]
		tmpname := fname + ".pkglint.tmp"
		text := ""
		for _, rawLine := range rawLines {
			text += rawLine.textnl
		}
		err := ioutil.WriteFile(tmpname, []byte(text), 0777)
		if err != nil {
			errorf(tmpname, NO_LINES, "Cannot write.")
			continue
		}
		err = os.Rename(tmpname, fname)
		if err != nil {
			errorf(fname, NO_LINES, "Cannot overwrite with auto-fixed content.")
			continue
		}
		notef(fname, NO_LINES, "Has been auto-fixed. Please re-run pkglint.")
	}
}
