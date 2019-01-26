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
