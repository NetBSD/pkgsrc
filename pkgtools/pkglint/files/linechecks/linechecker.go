package linechecks

import (
	"fmt"
	"netbsd.org/pkglint/line"
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/trace"
	"strings"
)

var Explain func(...string)

func CheckAbsolutePathname(line line.Line, text string) {
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
	if m, path := regex.Match1(text, `(?:^|\$[{(]DESTDIR[)}]|[\w_]+\s*=\s*)(/(?:[^"'\s]|"[^"*]"|'[^']*')*)`); m {
		if regex.Matches(path, `^/\w`) {
			CheckwordAbsolutePathname(line, path)
		}
	}
}

func CheckLength(line line.Line, maxlength int) {
	if len(line.Text()) > maxlength {
		line.Warnf("Line too long (should be no more than %d characters).", maxlength)
		Explain(
			"Back in the old time, terminals with 80x25 characters were common.",
			"And this is still the default size of many terminal emulators.",
			"Moderately short lines also make reading easier.")
	}
}

func CheckValidCharacters(line line.Line, reChar regex.Pattern) {
	rest := regex.Compile(reChar).ReplaceAllString(line.Text(), "")
	if rest != "" {
		uni := ""
		for _, c := range rest {
			uni += fmt.Sprintf(" %U", c)
		}
		line.Warnf("Line contains invalid characters (%s).", uni[1:])
	}
}

func CheckTrailingWhitespace(line line.Line) {
	if strings.HasSuffix(line.Text(), " ") || strings.HasSuffix(line.Text(), "\t") {
		if !line.AutofixReplaceRegexp(`\s+\n$`, "\n") {
			line.Notef("Trailing white-space.")
			Explain(
				"When a line ends with some white-space, that space is in most cases",
				"irrelevant and can be removed.")
		}
	}
}

func CheckRcsid(line line.Line, prefixRe regex.Pattern, suggestedPrefix string) bool {
	if trace.Tracing {
		defer trace.Call(prefixRe, suggestedPrefix)()
	}

	if regex.Matches(line.Text(), `^`+prefixRe+`\$`+`NetBSD(?::[^\$]+)?\$$`) {
		return true
	}

	if !line.AutofixInsertBefore(suggestedPrefix + "$" + "NetBSD$") {
		line.Errorf("Expected %q.", suggestedPrefix+"$"+"NetBSD$")
		Explain(
			"Several files in pkgsrc must contain the CVS Id, so that their",
			"current version can be traced back later from a binary package.",
			"This is to ensure reproducible builds, for example for finding bugs.")
	}
	return false
}

func CheckwordAbsolutePathname(line line.Line, word string) {
	if trace.Tracing {
		defer trace.Call1(word)()
	}

	switch {
	case regex.Matches(word, `^/dev/(?:null|tty|zero)$`):
	// These are defined by POSIX.
	case word == "/bin/sh":
	// This is usually correct, although on Solaris, it's pretty feature-crippled.
	case regex.Matches(word, `^/s\W`):
	// Probably a sed(1) command
	case regex.Matches(word, `^/(?:[a-z]|\$[({])`):
		// Absolute paths probably start with a lowercase letter.
		line.Warnf("Found absolute pathname: %s", word)
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
	}
}
