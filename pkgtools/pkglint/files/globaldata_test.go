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

func (s *Suite) TestGlobalData_LoadTools(c *check.C) {
	s.UseCommandLine(c, "-Dtools")
	s.CreateTmpFile(c, "mk/tools/bsd.tools.mk", ""+
		".include \"flex.mk\"\n"+
		".include \"gettext.mk\"\n")
	s.CreateTmpFile(c, "mk/tools/defaults.mk", ""+
		"_TOOLS_VARNAME.chown=CHOWN\n"+
		"_TOOLS_VARNAME.mv=MV\n"+
		"_TOOLS_VARNAME.gawk=AWK\n")
	s.CreateTmpFile(c, "mk/tools/flex.mk", ""+
		"# empty\n")
	s.CreateTmpFile(c, "mk/tools/gettext.mk", ""+
		"USE_TOOLS+=msgfmt\n"+
		"TOOLS_CREATE+=msgfmt\n")
	s.CreateTmpFile(c, "mk/bsd.pkg.mk", "# empty\n")
	G.globalData.pkgsrcdir = s.tmpdir
	G.currentDir = s.tmpdir
	G.curPkgsrcdir = "."

	G.globalData.loadTools()

	c.Check(s.Output(), equals, ""+
		"DEBUG: tools: [chown gawk msgfmt mv]\n"+
		"DEBUG: vartools: [chown gawk mv]\n"+
		"DEBUG: predefinedTools: []\n"+
		"DEBUG: varnameToToolname: [AWK CHOWN MV]\n")
}
