package pkglint

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_LineChecker_CheckAbsolutePathname(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wabsname", "--explain")
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"\tbindir=/bin",
		"\tbindir=/../lib",
		"\tcat /dev/null",
		"\tcat /dev/tty",
		"\tcat /dev/zero",
		"\tcat /dev/stdin",
		"\tcat /dev/stdout",
		"\tcat /dev/stderr",
		"\tprintf '#! /bin/sh\\nexit 0'",
		"\tprogram=$$bindir/program",
		"\tbindir=${PREFIX}/bin",
		"\tbindir=${DESTDIR}${PREFIX}/bin",
		"\tbindir=${DESTDIR}/bin",

		// This is not a filename at all, but certainly looks like one.
		// Nevertheless, pkglint doesn't fall into the trap.
		"\tsed -e /usr/s/usr/var/g")

	mklines.ForEach(func(mkline MkLine) {
		if !mkline.IsComment() {
			LineChecker{mkline.Line}.CheckAbsolutePathname(mkline.ShellCommand())
		}
	})

	t.CheckOutputLines(
		"WARN: Makefile:2: Found absolute pathname: /bin",
		"",
		"\tAbsolute pathnames are often an indicator for unportable code. As",
		"\tpkgsrc aims to be a portable system, absolute pathnames should be",
		"\tavoided whenever possible.",
		"",
		"WARN: Makefile:7: The \"/dev/stdin\" file is not portable.",
		"",
		"\tThe special files /dev/{stdin,stdout,stderr}, although present on",
		"\tLinux systems, are not available on other systems, and POSIX",
		"\texplicitly mentions them as examples of system-specific filenames.",
		"",
		"\tSee https://unix.stackexchange.com/q/36403.",
		"",
		"WARN: Makefile:8: The \"/dev/stdout\" file is not portable.",
		"WARN: Makefile:9: The \"/dev/stderr\" file is not portable.",
		"WARN: Makefile:14: Found absolute pathname: /bin",
		"",
		"\tAbsolute pathnames are often an indicator for unportable code. As",
		"\tpkgsrc aims to be a portable system, absolute pathnames should be",
		"\tavoided whenever possible.",
		"",
		"\tA special variable in this context is ${DESTDIR}, which is used in",
		"\tGNU projects to specify a different directory for installation than",
		"\twhat the programs see later when they are executed. Usually it is",
		"\tempty, so if anything after that variable starts with a slash, it is",
		"\tconsidered an absolute pathname.",
		"")
}

// It is unclear whether pkglint should check for absolute pathnames by default.
// It might be useful, but all the code surrounding this check was added for
// theoretical reasons instead of a practical bug. Therefore the code is still
// there, it is just not enabled by default.
func (s *Suite) Test_LineChecker_CheckAbsolutePathname__disabled_by_default(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine( /* none, which means -Wall is suppressed */ )
	line := t.NewLine("Makefile", 1, "# dummy")

	LineChecker{line}.CheckAbsolutePathname("bindir=/bin")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_LineChecker_CheckTrailingWhitespace(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("Makefile", 32, "The line must go on   ")

	LineChecker{line}.CheckTrailingWhitespace()

	t.CheckOutputLines(
		"NOTE: Makefile:32: Trailing whitespace.")
}

func (s *Suite) Test_LineChecker_CheckTrailingWhitespace__tab(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("Makefile", 32, "The line must go on\t")

	LineChecker{line}.CheckTrailingWhitespace()

	t.CheckOutputLines(
		"NOTE: Makefile:32: Trailing whitespace.")
}
