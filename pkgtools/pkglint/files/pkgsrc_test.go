package main

import "gopkg.in/check.v1"

// Ensures that pkglint can handle MASTER_SITES definitions with and
// without line continuations.
//
// See https://mail-index.netbsd.org/tech-pkg/2017/01/18/msg017698.html.
func (s *Suite) Test_Pkgsrc_loadMasterSites(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/fetch/sites.mk",
		MkRcsID,
		"",
		"MASTER_SITE_A+= https://example.org/distfiles/",
		"MASTER_SITE_B+= https://b.example.org/distfiles/ \\",
		"  https://b2.example.org/distfiles/",
		"MASTER_SITE_A+= https://a.example.org/distfiles/")

	G.Pkgsrc.loadMasterSites()

	c.Check(G.Pkgsrc.MasterSiteURLToVar["https://example.org/distfiles/"], equals, "MASTER_SITE_A")
	c.Check(G.Pkgsrc.MasterSiteURLToVar["https://b.example.org/distfiles/"], equals, "MASTER_SITE_B")
	c.Check(G.Pkgsrc.MasterSiteURLToVar["https://b2.example.org/distfiles/"], equals, "MASTER_SITE_B")
	c.Check(G.Pkgsrc.MasterSiteURLToVar["https://a.example.org/distfiles/"], equals, "MASTER_SITE_A")
	c.Check(G.Pkgsrc.MasterSiteVarToURL["MASTER_SITE_A"], equals, "https://example.org/distfiles/")
	c.Check(G.Pkgsrc.MasterSiteVarToURL["MASTER_SITE_B"], equals, "https://b.example.org/distfiles/")
}

func (s *Suite) Test_Pkgsrc_InitVartypes(c *check.C) {
	t := s.Init(c)

	src := NewPkgsrc(t.File("."))
	src.InitVartypes()

	c.Check(src.vartypes["BSD_MAKE_ENV"].basicType.name, equals, "ShellWord")
	c.Check(src.vartypes["USE_BUILTIN.*"].basicType.name, equals, "YesNoIndirectly")
}

func (s *Suite) Test_Pkgsrc_parseSuggestedUpdates(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("doc/TODO",
		"",
		"Suggested package updates",
		"==============",
		"For Perl updates \u2026",
		"",
		"\t"+"o CSP-0.34",
		"\t"+"o freeciv-client-2.5.0 (urgent)",
		"",
		"\t"+"o ignored-0.0")

	todo := G.Pkgsrc.parseSuggestedUpdates(lines)

	c.Check(todo, check.DeepEquals, []SuggestedUpdate{
		{lines[5], "CSP", "0.34", ""},
		{lines[6], "freeciv-client", "2.5.0", "(urgent)"}})
}

func (s *Suite) Test_Pkgsrc_loadTools(c *check.C) {
	t := s.Init(c)

	t.SetupFileLines("mk/tools/bsd.tools.mk",
		".include \"flex.mk\"",
		".include \"gettext.mk\"",
		".include \"strip.mk\"",
		".include \"replace.mk\"")
	t.SetupFileLines("mk/tools/defaults.mk",
		"_TOOLS_VARNAME.chown=CHOWN",
		"_TOOLS_VARNAME.gawk=AWK",
		"_TOOLS_VARNAME.mv=MV",
		"_TOOLS_VARNAME.pwd=PWD")
	t.SetupFileLines("mk/tools/flex.mk",
		"# empty")
	t.SetupFileLines("mk/tools/gettext.mk",
		"USE_TOOLS+=msgfmt",
		"TOOLS_CREATE+=msgfmt")
	t.SetupFileLines("mk/tools/strip.mk",
		".if defined(_INSTALL_UNSTRIPPED) || !defined(TOOLS_PLATFORM.strip)",
		"TOOLS_NOOP+=            strip",
		".else",
		"TOOLS_CREATE+=          strip",
		"TOOLS_PATH.strip=       ${TOOLS_PLATFORM.strip}",
		".endif",
		"STRIP?=         strip")
	t.SetupFileLines("mk/tools/replace.mk",
		"_TOOLS.bzip2=\tbzip2 bzcat",
		"#TOOLS_CREATE+=commented out",
		"_UNRELATED_VAR=\t# empty")
	t.SetupFileLines("mk/bsd.prefs.mk",
		"USE_TOOLS+=\tpwd",
		"USE_TOOLS+=\tm4:pkgsrc")
	t.SetupFileLines("mk/bsd.pkg.mk",
		"USE_TOOLS+=\tmv")

	G.Pkgsrc.loadTools()

	t.EnableTracingToLog()
	G.Pkgsrc.Tools.Trace()
	t.DisableTracing()

	t.CheckOutputLines(
		"TRACE: + (*ToolRegistry).Trace()",
		"TRACE: 1   tool &{Name:bzcat Varname: MustUseVarForm:false Predefined:false UsableAtLoadTime:false}",
		"TRACE: 1   tool &{Name:bzip2 Varname: MustUseVarForm:false Predefined:false UsableAtLoadTime:false}",
		"TRACE: 1   tool &{Name:chown Varname:CHOWN MustUseVarForm:false Predefined:false UsableAtLoadTime:false}",
		"TRACE: 1   tool &{Name:echo Varname:ECHO MustUseVarForm:true Predefined:true UsableAtLoadTime:true}",
		"TRACE: 1   tool &{Name:echo -n Varname:ECHO_N MustUseVarForm:true Predefined:true UsableAtLoadTime:true}",
		"TRACE: 1   tool &{Name:false Varname:FALSE MustUseVarForm:true Predefined:true UsableAtLoadTime:false}",
		"TRACE: 1   tool &{Name:gawk Varname:AWK MustUseVarForm:false Predefined:false UsableAtLoadTime:false}",
		"TRACE: 1   tool &{Name:m4 Varname: MustUseVarForm:false Predefined:true UsableAtLoadTime:true}",
		"TRACE: 1   tool &{Name:msgfmt Varname: MustUseVarForm:false Predefined:false UsableAtLoadTime:false}",
		"TRACE: 1   tool &{Name:mv Varname:MV MustUseVarForm:false Predefined:true UsableAtLoadTime:false}",
		"TRACE: 1   tool &{Name:pwd Varname:PWD MustUseVarForm:false Predefined:true UsableAtLoadTime:true}",
		"TRACE: 1   tool &{Name:strip Varname: MustUseVarForm:false Predefined:false UsableAtLoadTime:false}",
		"TRACE: 1   tool &{Name:test Varname:TEST MustUseVarForm:true Predefined:true UsableAtLoadTime:true}",
		"TRACE: 1   tool &{Name:true Varname:TRUE MustUseVarForm:true Predefined:true UsableAtLoadTime:true}",
		"TRACE: - (*ToolRegistry).Trace()")
}

func (s *Suite) Test_Pkgsrc_loadDocChangesFromFile(c *check.C) {
	t := s.Init(c)

	t.SetupFileLines("doc/CHANGES-2018",
		"\tAdded category/package version 1.0 [author1 2015-01-01]", // Wrong year
		"\tUpdated category/package to 1.5 [author2 2018-01-02]",
		"\tRenamed category/package to category/pkg [author3 2018-01-03]",
		"\tMoved category/package to other/package [author4 2018-01-04]",
		"\tRemoved category/package [author5 2018-01-09]", // Too far in the future
		"\tRemoved category/package successor category/package2 [author6 2018-01-06]",
		"\tDowngraded category/package to 1.2 [author7 2018-01-07]")

	changes := G.Pkgsrc.loadDocChangesFromFile(t.File("doc/CHANGES-2018"))

	c.Assert(len(changes), equals, 7)
	c.Check(*changes[0], equals, Change{changes[0].Line, "Added", "category/package", "1.0", "author1", "2015-01-01"})
	c.Check(*changes[1], equals, Change{changes[1].Line, "Updated", "category/package", "1.5", "author2", "2018-01-02"})
	c.Check(*changes[2], equals, Change{changes[2].Line, "Renamed", "category/package", "", "author3", "2018-01-03"})
	c.Check(*changes[3], equals, Change{changes[3].Line, "Moved", "category/package", "", "author4", "2018-01-04"})
	c.Check(*changes[4], equals, Change{changes[4].Line, "Removed", "category/package", "", "author5", "2018-01-09"})
	c.Check(*changes[5], equals, Change{changes[5].Line, "Removed", "category/package", "", "author6", "2018-01-06"})
	c.Check(*changes[6], equals, Change{changes[6].Line, "Downgraded", "category/package", "1.2", "author7", "2018-01-07"})

	t.CheckOutputLines(
		"WARN: ~/doc/CHANGES-2018:1: Year 2015 for category/package does not match the file name ~/doc/CHANGES-2018.",
		"WARN: ~/doc/CHANGES-2018:6: Date 2018-01-06 for category/package is earlier than 2018-01-09 for category/package.")
}

func (s *Suite) Test_Pkgsrc_deprecated(c *check.C) {
	t := s.Init(c)

	G.Pkgsrc.initDeprecatedVars()
	mkline := t.NewMkLine("Makefile", 5, "USE_PERL5=\tyes")

	MkLineChecker{mkline}.checkVarassign()

	t.CheckOutputLines(
		"WARN: Makefile:5: Definition of USE_PERL5 is deprecated. Use USE_TOOLS+=perl or USE_TOOLS+=perl:run instead.")
}
