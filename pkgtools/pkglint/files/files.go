package pkglint

import (
	"netbsd.org/pkglint/textproc"
	"strings"
)

type LoadOptions uint8

const (
	MustSucceed LoadOptions = 1 << iota // It's a fatal error if loading fails.
	NotEmpty                            // It is an error if the file is empty.
	Makefile                            // Lines ending in a backslash are continued in the next line.
	LogErrors                           //
)

func LoadMk(filename CurrPath, pkg *Package, options LoadOptions) *MkLines {
	lines := Load(filename, options|Makefile)
	if lines == nil {
		return nil
	}
	return NewMkLines(lines, pkg)
}

func Load(filename CurrPath, options LoadOptions) *Lines {
	if fromCache := G.fileCache.Get(filename, options); fromCache != nil {
		return fromCache
	}

	rawText, err := filename.ReadString()
	if err != nil {
		switch {
		case options&MustSucceed != 0:
			NewLineWhole(filename).Fatalf("Cannot be read.")
		case options&LogErrors != 0:
			NewLineWhole(filename).Errorf("Cannot be read.")
		}
		return nil
	}

	if rawText == "" && options&NotEmpty != 0 {
		switch {
		case options&MustSucceed != 0:
			NewLineWhole(filename).Fatalf("Must not be empty.")
		case options&LogErrors != 0:
			NewLineWhole(filename).Errorf("Must not be empty.")
		}
		return nil
	}

	if G.Opts.Profiling {
		G.loaded.Add(filename.Clean().String(), 1)
	}

	result := convertToLogicalLines(filename, rawText, options&Makefile != 0)
	if filename.HasSuffixText(".mk") {
		G.fileCache.Put(filename, options, result)
	}
	return result
}

func convertToLogicalLines(filename CurrPath, rawText string, joinBackslashLines bool) *Lines {
	var rawLines []*RawLine
	for lineno, rawLine := range strings.SplitAfter(rawText, "\n") {
		if rawLine != "" {
			rawLines = append(rawLines, &RawLine{1 + lineno, rawLine, rawLine})
		}
	}

	var loglines []*Line
	if joinBackslashLines {
		for lineno := 0; lineno < len(rawLines); {
			line, nextLineno := nextLogicalLine(filename, rawLines, lineno)
			loglines = append(loglines, line)
			lineno = nextLineno
		}
	} else {
		for _, rawLine := range rawLines {
			text := rawLine.Text()
			logline := NewLine(filename, rawLine.Lineno, text, rawLine)
			loglines = append(loglines, logline)
		}
	}

	if rawText != "" && !hasSuffix(rawText, "\n") {
		loglines[len(loglines)-1].Errorf("File must end with a newline.")
	}

	return NewLines(filename, loglines)
}

func nextLogicalLine(filename CurrPath, rawLines []*RawLine, index int) (*Line, int) {
	{ // Handle the common case efficiently
		rawLine := rawLines[index]
		text := rawLine.Text()
		if !hasSuffix(text, "\\") {
			return NewLine(filename, rawLine.Lineno, text, rawLines[index]), index + 1
		}
	}

	var text strings.Builder
	firstlineno := rawLines[index].Lineno
	var lineRawLines []*RawLine
	interestingRawLines := rawLines[index:]
	trim := ""

	for i, rawLine := range interestingRawLines {
		indent, rawText, outdent, cont := matchContinuationLine(rawLine.Text())

		if text.Len() == 0 {
			text.WriteString(indent)
		}
		text.WriteString(strings.TrimPrefix(rawText, trim))

		lineRawLines = append(lineRawLines, rawLine)

		if cont != "" && i != len(interestingRawLines)-1 {
			text.WriteString(" ")
			index++
			trim = textproc.NewLexer(rawText).NextString("#")
		} else {
			text.WriteString(outdent)
			text.WriteString(cont)
			break
		}
	}

	lastlineno := rawLines[index].Lineno

	return NewLineMulti(filename, firstlineno, lastlineno, text.String(), lineRawLines), index + 1
}

func matchContinuationLine(text string) (leadingWhitespace, result, trailingWhitespace, cont string) {
	end := len(text)

	j := end
	for j > 0 && text[j-1] == '\\' {
		j--
	}
	backslashes := (end - j) % 2
	j = end - backslashes
	cont = text[j:end]

	trailingEnd := j
	for j > 0 && isHspace(text[j-1]) {
		j--
	}
	trailingStart := j
	trailingWhitespace = text[trailingStart:trailingEnd]

	i := 0
	leadingStart := i
	for i < j && isHspace(text[i]) {
		i++
	}
	leadingEnd := i
	leadingWhitespace = text[leadingStart:leadingEnd]

	result = text[leadingEnd:trailingStart]
	return
}
