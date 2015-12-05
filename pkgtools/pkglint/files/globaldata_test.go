package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestGlobalDataVartypes(c *check.C) {
	G.globalData.InitVartypes()

	c.Check(G.globalData.vartypes["BSD_MAKE_ENV"].checker.name, equals, "ShellWord")
	c.Check(G.globalData.vartypes["USE_BUILTIN.*"].checker.name, equals, "YesNoIndirectly")
}

func (s *Suite) TestParselinesSuggestedUpdates(c *check.C) {
	lines := s.NewLines("doc/TODO",
		"",
		"Suggested package updates",
		"==============",
		"For Perl updates \u2026",
		"",
		"\t"+"o CSP-0.34",
		"\t"+"o freeciv-client-2.5.0 (urgent)",
		"",
		"\t"+"o ignored-0.0")

	todo := parselinesSuggestedUpdates(lines)

	c.Check(todo, check.DeepEquals, []SuggestedUpdate{
		{lines[5], "CSP", "0.34", ""},
		{lines[6], "freeciv-client", "2.5.0", "(urgent)"}})
}
