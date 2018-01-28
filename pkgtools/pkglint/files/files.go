package main

import (
	"io/ioutil"
	"strings"
)

func LoadNonemptyLines(fname string, joinBackslashLines bool) []Line {
	lines, err := readLines(fname, joinBackslashLines)
	if err != nil {
		NewLineWhole(fname).Errorf("Cannot be read.")
		return nil
	}
	if len(lines) == 0 {
		NewLineWhole(fname).Errorf("Must not be empty.")
		return nil
	}
	return lines
}

func LoadExistingLines(fname string, joinBackslashLines bool) []Line {
	lines, err := readLines(fname, joinBackslashLines)
	if err != nil {
		NewLineWhole(fname).Fatalf("Cannot be read.")
	}
	return lines
}

func nextLogicalLine(fname string, rawLines []*RawLine, pindex *int) Line {
	{ // Handle the common case efficiently
		index := *pindex
		rawLine := rawLines[index]
		textnl := rawLine.textnl
		if hasSuffix(textnl, "\n") && !hasSuffix(textnl, "\\\n") {
			*pindex = index + 1
			return NewLine(fname, rawLine.Lineno, textnl[:len(textnl)-1], rawLines[index:index+1])
		}
	}

	text := ""
	index := *pindex
	firstlineno := rawLines[index].Lineno
	var lineRawLines []*RawLine
	interestingRawLines := rawLines[index:]

	for i, rawLine := range interestingRawLines {
		indent, rawText, outdent, cont := splitRawLine(rawLine.textnl)

		if text == "" {
			text += indent
		}
		text += rawText
		lineRawLines = append(lineRawLines, rawLine)

		if cont != "" && i != len(interestingRawLines)-1 {
			text += " "
			index++
		} else {
			text += outdent + cont
			break
		}
	}

	lastlineno := rawLines[index].Lineno
	*pindex = index + 1

	return NewLineMulti(fname, firstlineno, lastlineno, text, lineRawLines)
}

func splitRawLine(textnl string) (leadingWhitespace, text, trailingWhitespace, cont string) {
	end := len(textnl)

	if end-1 >= 0 && textnl[end-1] == '\n' {
		end--
	}

	backslashes := 0
	for end-1 >= 0 && textnl[end-1] == '\\' {
		end--
		backslashes++
	}
	cont = textnl[end : end+backslashes%2]
	end += backslashes / 2

	trailingEnd := end
	for end-1 >= 0 && (textnl[end-1] == ' ' || textnl[end-1] == '\t') {
		end--
	}
	trailingStart := end
	trailingWhitespace = textnl[trailingStart:trailingEnd]

	i := 0
	leadingStart := i
	for i < end && (textnl[i] == ' ' || textnl[i] == '\t') {
		i++
	}
	leadingEnd := i
	leadingWhitespace = textnl[leadingStart:leadingEnd]

	text = textnl[leadingEnd:trailingStart]
	return
}

func readLines(fname string, joinBackslashLines bool) ([]Line, error) {
	rawText, err := ioutil.ReadFile(fname)
	if err != nil {
		return nil, err
	}

	return convertToLogicalLines(fname, string(rawText), joinBackslashLines), nil
}

func convertToLogicalLines(fname string, rawText string, joinBackslashLines bool) []Line {
	var rawLines []*RawLine
	for lineno, rawLine := range strings.SplitAfter(rawText, "\n") {
		if rawLine != "" {
			rawLines = append(rawLines, &RawLine{1 + lineno, rawLine, rawLine})
		}
	}

	var loglines []Line
	if joinBackslashLines {
		for lineno := 0; lineno < len(rawLines); {
			loglines = append(loglines, nextLogicalLine(fname, rawLines, &lineno))
		}
	} else {
		for _, rawLine := range rawLines {
			text := strings.TrimSuffix(rawLine.textnl, "\n")
			logline := NewLine(fname, rawLine.Lineno, text, []*RawLine{rawLine})
			loglines = append(loglines, logline)
		}
	}

	if 0 < len(rawLines) && !hasSuffix(rawLines[len(rawLines)-1].textnl, "\n") {
		NewLineEOF(fname).Errorf("File must end with a newline.")
	}

	return loglines
}
