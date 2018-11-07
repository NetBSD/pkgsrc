package main

import (
	"fmt"
	"netbsd.org/pkglint/regex"
	"strings"
)

func CheckLineAbsolutePathname(line Line, text string) {
	if trace.Tracing {
		defer trace.Call1(text)()
	}

	// In the GNU coding standards, DESTDIR is defined as a (usually
	// empty) prefix that can be used to install files to a different
	// location from what they have been built for. Therefore
	// everything following it is considered an absolute pathname.
	//
	// Another context where absolute pathnames usually appear is in
	// assignments like "bindir=/bin".
	if m, path := match1(text, `(?:^|[\t ]|\$[{(]DESTDIR[)}]|[\w_]+[\t ]*=[\t ]*)(/(?:[^"' \t\\]|"[^"*]"|'[^']*')*)`); m {
		if matches(path, `^/\w`) {
			CheckwordAbsolutePathname(line, path)
		}
	}
}

func CheckLineLength(line Line, maxlength int) {
	if len(line.Text) > maxlength {
		line.Warnf("Line too long (should be no more than %d characters).", maxlength)
		Explain(
			"Back in the old time, terminals with 80x25 characters were common.",
			"And this is still the default size of many terminal emulators.",
			"Moderately short lines also make reading easier.")
	}
}

func CheckLineValidCharacters(line Line) {
	uni := ""
	for _, r := range line.Text {
		if r != '\t' && !(' ' <= r && r <= '~') {
			uni += fmt.Sprintf(" %U", r)
		}
	}
	if uni != "" {
		line.Warnf("Line contains invalid characters (%s).", uni[1:])
	}
}

func CheckLineTrailingWhitespace(line Line) {
	if strings.HasSuffix(line.Text, " ") || strings.HasSuffix(line.Text, "\t") {
		fix := line.Autofix()
		fix.Notef("Trailing white-space.")
		fix.Explain(
			"When a line ends with some white-space, that space is in most cases",
			"irrelevant and can be removed.")
		fix.ReplaceRegex(`[ \t\r]+\n$`, "\n", 1)
		fix.Apply()
	}
}

func CheckLineRcsid(line Line, prefixRe regex.Pattern, suggestedPrefix string) bool {
	if trace.Tracing {
		defer trace.Call(prefixRe, suggestedPrefix)()
	}

	if matches(line.Text, `^`+prefixRe+`\$`+`NetBSD(?::[^\$]+)?\$$`) {
		return true
	}

	fix := line.Autofix()
	fix.Errorf("Expected %q.", suggestedPrefix+"$"+"NetBSD$")
	fix.Explain(
		"Several files in pkgsrc must contain the CVS Id, so that their",
		"current version can be traced back later from a binary package.",
		"This is to ensure reproducible builds, for example for finding bugs.")
	fix.InsertBefore(suggestedPrefix + "$" + "NetBSD$")
	fix.Apply()

	return false
}

func CheckwordAbsolutePathname(line Line, word string) {
	if trace.Tracing {
		defer trace.Call1(word)()
	}

	switch {
	case matches(word, `^/dev/(?:null|tty|zero)$`):
		// These are defined by POSIX.

	case word == "/bin/sh":
		// This is usually correct, although on Solaris, it's pretty feature-crippled.

	case matches(word, `/s\W`):
		// Probably a sed(1) command, e.g. /find/s,replace,with,

	case matches(word, `^/(?:[a-z]|\$[({])`):
		// Absolute paths probably start with a lowercase letter.
		line.Warnf("Found absolute pathname: %s", word)
		if contains(line.Text, "DESTDIR") {
			Explain(
				"Absolute pathnames are often an indicator for unportable code.  As",
				"pkgsrc aims to be a portable system, absolute pathnames should be",
				"avoided whenever possible.",
				"",
				"A special variable in this context is ${DESTDIR}, which is used in",
				"GNU projects to specify a different directory for installation than",
				"what the programs see later when they are executed.  Usually it is",
				"empty, so if anything after that variable starts with a slash, it is",
				"considered an absolute pathname.")
		} else {
			Explain(
				"Absolute pathnames are often an indicator for unportable code.  As",
				"pkgsrc aims to be a portable system, absolute pathnames should be",
				"avoided whenever possible.")
		}
	}
}
