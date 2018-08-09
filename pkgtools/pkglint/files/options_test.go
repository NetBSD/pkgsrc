package main

import "gopkg.in/check.v1"

func (s *Suite) Test_ChecklinesOptionsMk(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wno-space")
	t.SetupVartypes()
	t.SetupOption("mc-charset", "")
	t.SetupOption("ncurses", "")
	t.SetupOption("slang", "")
	t.SetupOption("x11", "")

	t.SetupFileMkLines("mk/bsd.options.mk",
		MkRcsID)

	mklines := t.SetupFileMkLines("category/package/options.mk",
		MkRcsID,
		"",
		"PKG_OPTIONS_VAR=                PKG_OPTIONS.mc",
		"PKG_OPTIONS_REQUIRED_GROUPS=    screen",
		"PKG_OPTIONS_GROUP.screen=       ncurses slang",
		"PKG_SUPPORTED_OPTIONS=          mc-charset x11 lang-${l}",
		"PKG_SUGGESTED_OPTIONS=          mc-charset slang",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".if !empty(PKG_OPTIONS:Mx11)",
		".endif",
		"",
		".if !empty(PKG_OPTIONS:Mundeclared)",
		".endif")

	G.CurrentDir = t.TmpDir()
	G.CurPkgsrcdir = "."

	ChecklinesOptionsMk(mklines)

	t.CheckOutputLines(
		"WARN: ~/category/package/options.mk:14: Unknown option \"undeclared\".",
		"WARN: ~/category/package/options.mk:5: Option \"ncurses\" should be handled below in an .if block.",
		"WARN: ~/category/package/options.mk:5: Option \"slang\" should be handled below in an .if block.",
		"WARN: ~/category/package/options.mk:6: Option \"mc-charset\" should be handled below in an .if block.",
		"WARN: ~/category/package/options.mk:14: Option \"undeclared\" is handled but not declared above.")
}

func (s *Suite) Test_ChecklinesOptionsMk__unexpected_line(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wno-space")
	t.SetupVartypes()
	t.SetupOption("mc-charset", "")
	t.SetupOption("ncurses", "")
	t.SetupOption("slang", "")
	t.SetupOption("x11", "")

	t.SetupFileMkLines("mk/bsd.options.mk",
		MkRcsID)

	mklines := t.SetupFileMkLines("category/package/options.mk",
		MkRcsID,
		"",
		"PKG_OPTIONS_VAR=                PKG_OPTIONS.mc",
		"PKG_SUPPORTED_OPTIONS=          mc-charset x11 lang-${l}",
		"PKG_SUGGESTED_OPTIONS=          mc-charset",
		"",
		"pre-configure:",
		"\techo \"In the pre-configure stage.\"")

	G.CurrentDir = t.TmpDir()
	G.CurPkgsrcdir = "."

	ChecklinesOptionsMk(mklines)

	t.CheckOutputLines(
		"WARN: ~/category/package/options.mk:7: Expected inclusion of \"../../mk/bsd.options.mk\".")
}
