package main

import (
	check "gopkg.in/check.v1"
	"strings"
)

func (s *Suite) TestChecklinesDescr(c *check.C) {
	lines := s.NewLines("DESCR",
		strings.Repeat("X", 90),
		"", "", "", "", "", "", "", "", "10",
		"Try ${PREFIX}",
		"", "", "", "", "", "", "", "", "20",
		"", "", "", "", "", "", "", "", "", "30")

	checklinesDescr(lines)

	c.Check(s.Output(), equals, ""+
		"WARN: DESCR:1: Line too long (should be no more than 80 characters).\n"+
		"NOTE: DESCR:11: Variables are not expanded in the DESCR file.\n"+
		"WARN: DESCR:25: File too long (should be no more than 24 lines).\n")
}
