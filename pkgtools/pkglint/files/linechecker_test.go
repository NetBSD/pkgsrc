package pkglint

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_LineChecker_CheckLength(c *check.C) {
	t := s.Init(c)

	line1 := t.NewLine("DESCR", 1, "A very long line with spaces")
	line2 := t.NewLine("DESCR", 2, "A_very_long_line_without_spaces")

	LineChecker{line1}.CheckLength(20)
	LineChecker{line2}.CheckLength(20)

	t.CheckOutputLines(
		"WARN: DESCR:1: Line too long (should be no more than 20 characters).")
}

func (s *Suite) Test_LineChecker_CheckValidCharacters(c *check.C) {
	t := s.Init(c)

	doTest := func(autofix bool) {
		line := t.NewLine("filename", 32, "The letter \u00DC is an umlaut.")

		LineChecker{line}.CheckValidCharacters()
	}

	t.ExpectDiagnosticsAutofix(
		doTest,
		"WARN: filename:32: Line contains invalid characters (U+00DC).")
}

func (s *Suite) Test_LineChecker_CheckTrailingWhitespace(c *check.C) {
	t := s.Init(c)

	doTest := func(autofix bool) {
		line := t.NewLine("Makefile", 32, "The line must go on   ")

		LineChecker{line}.CheckTrailingWhitespace()
	}

	t.ExpectDiagnosticsAutofix(
		doTest,
		"NOTE: Makefile:32: Trailing whitespace.",
		"AUTOFIX: Makefile:32: Replacing \"   \" with \"\".")
}

func (s *Suite) Test_LineChecker_CheckTrailingWhitespace__tab(c *check.C) {
	t := s.Init(c)

	doTest := func(autofix bool) {
		line := t.NewLine("Makefile", 32, "The line must go on\t")

		LineChecker{line}.CheckTrailingWhitespace()
	}

	t.ExpectDiagnosticsAutofix(
		doTest,
		"NOTE: Makefile:32: Trailing whitespace.",
		"AUTOFIX: Makefile:32: Replacing \"\\t\" with \"\".")
}

// Even though the logical text of the Makefile line ends with a space,
// the check for trailing whitespace doesn't catch it.
//
// The check only looks at the actual lines, not at the logical text after
// joining the continuation lines. Line 2 is empty and thus doesn't contain
// any whitespace that might be trailing.
//
// See Test_MkLineChecker_checkEmptyContinuation.
func (s *Suite) Test_LineChecker_CheckTrailingWhitespace__multi(c *check.C) {
	t := s.Init(c)

	doTest := func(autofix bool) {
		mklines := t.NewMkLines("Makefile",
			MkCvsID,
			"VAR=\tThis line \\",
			"")
		mkline := mklines.mklines[0]

		LineChecker{mkline.Line}.CheckTrailingWhitespace()
	}

	t.ExpectDiagnosticsAutofix(
		doTest,
		nil...)
}
