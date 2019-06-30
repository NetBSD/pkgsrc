package pkglint

import (
	"fmt"
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
	for i := 0; i < len(prefix); i++ {
		if isHspace(prefix[i]) {
			ck.line.Warnf("Line too long (should be no more than %d characters).", maxLength)
			ck.line.Explain(
				"Back in the old time, terminals with 80x25 characters were common.",
				"And this is still the default size of many terminal emulators.",
				"Moderately short lines also make reading easier.")
			return
		}
	}
}

func (ck LineChecker) CheckValidCharacters() {
	var uni strings.Builder
	for _, r := range ck.line.Text {
		if r != '\t' && !(' ' <= r && r <= '~') {
			_, _ = fmt.Fprintf(&uni, " %U", r)
		}
	}
	if uni.Len() > 0 {
		ck.line.Warnf("Line contains invalid characters (%s).", uni.String()[1:])
	}
}

func (ck LineChecker) CheckTrailingWhitespace() {

	// XXX: Markdown files may need trailing whitespace. If there should ever
	// be Markdown files in pkgsrc, this code has to be adjusted.

	if strings.HasSuffix(ck.line.Text, " ") || strings.HasSuffix(ck.line.Text, "\t") {
		fix := ck.line.Autofix()
		fix.Notef("Trailing whitespace.")
		fix.Explain(
			"When a line ends with some whitespace, that space is in most cases",
			"irrelevant and can be removed.")
		fix.ReplaceRegex(`[ \t\r]+\n$`, "\n", 1)
		fix.Apply()
	}
}
