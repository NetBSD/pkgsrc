package main

import (
	"io/ioutil"
	"path"
	"strings"
)

type LoadOptions uint8

const (
	MustSucceed LoadOptions = 1 << iota // It's a fatal error if loading fails.
	NotEmpty                            // It is an error if the file is empty.
	Makefile                            // Lines ending in a backslash are continued in the next line.
	LogErrors                           //
)

func Load(fileName string, options LoadOptions) Lines {
	if fromCache := G.fileCache.Get(fileName, options); fromCache != nil {
		return fromCache
	}

	rawBytes, err := ioutil.ReadFile(fileName)
	if err != nil {
		switch {
		case options&MustSucceed != 0:
			NewLineWhole(fileName).Fatalf("Cannot be read.")
		case options&LogErrors != 0:
			NewLineWhole(fileName).Errorf("Cannot be read.")
		}
		return nil
	}

	rawText := string(rawBytes)
	if rawText == "" && options&NotEmpty != 0 {
		switch {
		case options&MustSucceed != 0:
			NewLineWhole(fileName).Fatalf("Must not be empty.")
		case options&LogErrors != 0:
			NewLineWhole(fileName).Errorf("Must not be empty.")
		}
		return nil
	}

	if G.Opts.Profiling {
		G.loaded.Add(path.Clean(fileName), 1)
	}

	result := convertToLogicalLines(fileName, rawText, options&Makefile != 0)
	if hasSuffix(fileName, ".mk") {
		G.fileCache.Put(fileName, options, result)
	}
	return result
}

func LoadMk(fileName string, options LoadOptions) MkLines {
	lines := Load(fileName, options|Makefile)
	if lines == nil {
		return nil
	}
	return NewMkLines(lines)
}

func nextLogicalLine(fileName string, rawLines []*RawLine, index int) (Line, int) {
	{ // Handle the common case efficiently
		rawLine := rawLines[index]
		textnl := rawLine.textnl
		if hasSuffix(textnl, "\n") && !hasSuffix(textnl, "\\\n") {
			return NewLine(fileName, rawLine.Lineno, textnl[:len(textnl)-1], rawLines[index:index+1]), index + 1
		}
	}

	var text strings.Builder
	firstlineno := rawLines[index].Lineno
	var lineRawLines []*RawLine
	interestingRawLines := rawLines[index:]

	for i, rawLine := range interestingRawLines {
		indent, rawText, outdent, cont := matchContinuationLine(rawLine.textnl)

		if text.Len() == 0 {
			text.WriteString(indent)
		}
		text.WriteString(rawText)
		lineRawLines = append(lineRawLines, rawLine)

		if cont != "" && i != len(interestingRawLines)-1 {
			text.WriteString(" ")
			index++
		} else {
			text.WriteString(outdent)
			text.WriteString(cont)
			break
		}
	}

	lastlineno := rawLines[index].Lineno

	return NewLineMulti(fileName, firstlineno, lastlineno, text.String(), lineRawLines), index + 1
}

func matchContinuationLine(textnl string) (leadingWhitespace, text, trailingWhitespace, cont string) {
	j := len(textnl)

	if j > 0 && textnl[j-1] == '\n' {
		j--
	}

	backslashes := 0
	for j > 0 && textnl[j-1] == '\\' {
		j--
		backslashes++
	}
	cont = textnl[j : j+backslashes%2]
	j += backslashes / 2

	trailingEnd := j
	for j > 0 && isHspace(textnl[j-1]) {
		j--
	}
	trailingStart := j
	trailingWhitespace = textnl[trailingStart:trailingEnd]

	i := 0
	leadingStart := i
	for i < j && isHspace(textnl[i]) {
		i++
	}
	leadingEnd := i
	leadingWhitespace = textnl[leadingStart:leadingEnd]

	text = textnl[leadingEnd:trailingStart]
	return
}

func convertToLogicalLines(fileName string, rawText string, joinBackslashLines bool) Lines {
	var rawLines []*RawLine
	for lineno, rawLine := range strings.SplitAfter(rawText, "\n") {
		if rawLine != "" {
			rawLines = append(rawLines, &RawLine{1 + lineno, rawLine, rawLine})
		}
	}

	var loglines []Line
	if joinBackslashLines {
		for lineno := 0; lineno < len(rawLines); {
			line, nextLineno := nextLogicalLine(fileName, rawLines, lineno)
			loglines = append(loglines, line)
			lineno = nextLineno
		}
	} else {
		for _, rawLine := range rawLines {
			text := strings.TrimSuffix(rawLine.textnl, "\n")
			logline := NewLine(fileName, rawLine.Lineno, text, []*RawLine{rawLine})
			loglines = append(loglines, logline)
		}
	}

	if rawText != "" && !hasSuffix(rawText, "\n") {
		loglines[len(loglines)-1].Errorf("File must end with a newline.")
	}

	return NewLines(fileName, loglines)
}
