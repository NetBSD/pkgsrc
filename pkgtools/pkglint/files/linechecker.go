package pkglint

import (
	"netbsd.org/pkglint/textproc"
	"strings"
)

type LineChecker struct {
	line *Line
}

func (ck LineChecker) CheckLength(maxLength int) {
	if len(ck.line.Text) <= maxLength {
		return
	}

	prefix := ck.line.Text[0:maxLength]
	if !strings.ContainsAny(prefix, " \t") {
		return
	}

	ck.line.Warnf("Line too long (should be no more than %d characters).",
		maxLength)
	ck.line.Explain(
		"Back in the old time, terminals with 80x25 characters were common.",
		"And this is still the default size of many terminal emulators.",
		"Moderately short lines also make reading easier.")
}

func (ck LineChecker) CheckValidCharacters() {
	invalid := invalidCharacters(ck.line.Text, textproc.XPrint)
	if invalid == "" {
		return
	}

	ck.line.Warnf("Line contains invalid characters (%s).", invalid)
}

func (ck LineChecker) CheckTrailingWhitespace() {

	// Markdown files may need trailing whitespace. If there should ever
	// be Markdown files in pkgsrc, this code has to be adjusted.

	rawIndex := len(ck.line.raw) - 1
	text := ck.line.RawText(rawIndex)
	trimmedLen := len(rtrimHspace(text))
	if trimmedLen == len(text) {
		return
	}

	fix := ck.line.Autofix()
	fix.Notef("Trailing whitespace.")
	fix.Explain(
		"This whitespace is irrelevant and can be removed.")
	fix.ReplaceAt(rawIndex, trimmedLen, text[trimmedLen:], "")
	fix.Apply()
}
