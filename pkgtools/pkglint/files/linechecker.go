package pkglint

import (
	"fmt"
	"strings"
)

type LineChecker struct {
	line Line
}

// CheckAbsolutePathname checks whether any absolute pathnames occur in the line.
//
// XXX: Is this check really useful? It had been added 10 years ago because some
// style guide said that "absolute pathnames should be avoided", but there was no
// evidence for that.
func (ck LineChecker) CheckAbsolutePathname(text string) {
	if trace.Tracing {
		defer trace.Call1(text)()
	}

	// XXX: The following code only checks the first absolute pathname per line.
	// The remaining pathnames are ignored. This is probably harmless in practice
	// since it doesn't occur often.

	// In the GNU coding standards, DESTDIR is defined as a (usually
	// empty) prefix that can be used to install files to a different
	// location from what they have been built for. Therefore
	// everything following it is considered an absolute pathname.
	//
	// Another context where absolute pathnames usually appear is in
	// assignments like "bindir=/bin".
	if m, path := match1(text, `(?:^|[\t ]|\$[{(]DESTDIR[)}]|[\w_]+[\t ]*=[\t ]*)(/(?:[^"' \t\\]|"[^"*]"|'[^']*')*)`); m {
		if matches(path, `^/\w`) {

			// XXX: Why is the "before" text from the above regular expression
			// not passed on to this method?
			ck.CheckWordAbsolutePathname(path)
		}
	}
}

func (ck LineChecker) CheckLength(maxLength int) {
	if len(ck.line.Text) <= maxLength {
		return
	}

	prefix := ck.line.Text[0:maxLength]
	for i := 0; i < len(prefix); i++ {
		if isHspace(prefix[i]) {
			ck.line.Warnf("Line too long (should be no more than %d characters).", maxLength)
			G.Explain(
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

// CheckWordAbsolutePathname checks the given word (which is often part of a
// shell command) for absolute pathnames.
//
// XXX: Is this check really useful? It had been added 10 years ago because some
// style guide said that "absolute pathnames should be avoided", but there was no
// evidence for that.
func (ck LineChecker) CheckWordAbsolutePathname(word string) {
	if trace.Tracing {
		defer trace.Call1(word)()
	}

	if !G.Opts.WarnAbsname {
		return
	}

	switch {
	case matches(word, `^/dev/(?:null|tty|zero)$`):
		// These are defined by POSIX.

	case matches(word, `^/dev/(?:stdin|stdout|stderr)$`):
		ck.line.Warnf("The %q file is not portable.", word)
		G.Explain(
			"The special files /dev/{stdin,stdout,stderr}, although present",
			"on Linux systems, are not available on other systems, and POSIX",
			"explicitly mentions them as examples of system-specific filenames.",
			"",
			"See https://unix.stackexchange.com/q/36403.")

	case word == "/bin/sh":
		// This is usually correct, although on Solaris, it's pretty feature-crippled.

	case matches(word, `/s\W`):
		// Probably a sed(1) command, such as /find/s,replace,with,

	case matches(word, `^/(?:[a-z]|\$[({])`):
		// Absolute paths probably start with a lowercase letter.
		ck.line.Warnf("Found absolute pathname: %s", word)
		if contains(ck.line.Text, "DESTDIR") {
			G.Explain(
				"Absolute pathnames are often an indicator for unportable code.",
				"As pkgsrc aims to be a portable system,",
				"absolute pathnames should be avoided whenever possible.",
				"",
				"A special variable in this context is ${DESTDIR},",
				"which is used in GNU projects to specify a different directory",
				"for installation than what the programs see later when they are executed.",
				"Usually it is empty, so if anything after that variable starts with a slash,",
				"it is considered an absolute pathname.")
		} else {
			G.Explain(
				"Absolute pathnames are often an indicator for unportable code.",
				"As pkgsrc aims to be a portable system,",
				"absolute pathnames should be avoided whenever possible.")

			// TODO: Explain how to actually fix this warning properly.
		}
	}
}
