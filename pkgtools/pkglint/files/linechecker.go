package main

import (
	"fmt"
	"netbsd.org/pkglint/line"
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/trace"
)

type LineChecker struct {
	Line line.Line
}

func (ck LineChecker) CheckAbsolutePathname(text string) {
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
	if m, path := match1(text, `(?:^|\$[{(]DESTDIR[)}]|[\w_]+\s*=\s*)(/(?:[^"'\s]|"[^"*]"|'[^']*')*)`); m {
		if matches(path, `^/\w`) {
			checkwordAbsolutePathname(ck.Line, path)
		}
	}
}

func (ck LineChecker) CheckLength(maxlength int) {
	if len(ck.Line.Text()) > maxlength {
		ck.Line.Warnf("Line too long (should be no more than %d characters).", maxlength)
		Explain(
			"Back in the old time, terminals with 80x25 characters were common.",
			"And this is still the default size of many terminal emulators.",
			"Moderately short lines also make reading easier.")
	}
}

func (ck LineChecker) CheckValidCharacters(reChar regex.RegexPattern) {
	rest := regex.Compile(reChar).ReplaceAllString(ck.Line.Text(), "")
	if rest != "" {
		uni := ""
		for _, c := range rest {
			uni += fmt.Sprintf(" %U", c)
		}
		ck.Line.Warnf("Line contains invalid characters (%s).", uni[1:])
	}
}

func (ck LineChecker) CheckTrailingWhitespace() {
	if hasSuffix(ck.Line.Text(), " ") || hasSuffix(ck.Line.Text(), "\t") {
		if !ck.Line.AutofixReplaceRegexp(`\s+\n$`, "\n") {
			ck.Line.Notef("Trailing white-space.")
			Explain(
				"When a line ends with some white-space, that space is in most cases",
				"irrelevant and can be removed.")
		}
	}
}

func (ck LineChecker) CheckRcsid(prefixRe regex.RegexPattern, suggestedPrefix string) bool {
	if trace.Tracing {
		defer trace.Call(prefixRe, suggestedPrefix)()
	}

	if matches(ck.Line.Text(), `^`+prefixRe+`\$`+`NetBSD(?::[^\$]+)?\$$`) {
		return true
	}

	if !ck.Line.AutofixInsertBefore(suggestedPrefix + "$" + "NetBSD$") {
		ck.Line.Errorf("Expected %q.", suggestedPrefix+"$"+"NetBSD$")
		Explain(
			"Several files in pkgsrc must contain the CVS Id, so that their",
			"current version can be traced back later from a binary package.",
			"This is to ensure reproducible builds, for example for finding bugs.")
	}
	return false
}
