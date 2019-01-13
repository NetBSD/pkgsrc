package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_CheckLinesOptionsMk(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall,no-space")
	t.SetUpVartypes()
	t.SetUpOption("mc-charset", "")
	t.SetUpOption("mysql", "")
	t.SetUpOption("ncurses", "")
	t.SetUpOption("negative", "Demonstrates negated .if/.else")
	t.SetUpOption("slang", "")
	t.SetUpOption("sqlite", "")
	t.SetUpOption("x11", "")

	t.CreateFileLines("mk/bsd.options.mk",
		MkRcsID)

	mklines := t.SetUpFileMkLines("category/package/options.mk",
		MkRcsID,
		"",
		"PKG_OPTIONS_VAR=                PKG_OPTIONS.mc",
		"PKG_OPTIONS_REQUIRED_GROUPS=    screen",
		"PKG_OPTIONS_GROUP.screen=       ncurses slang",
		"PKG_SUPPORTED_OPTIONS=          mc-charset x11 lang-${l} negative",
		"PKG_SUGGESTED_OPTIONS=          mc-charset slang",
		"PKG_OPTIONS_NONEMPTY_SETS+=     db",
		"PKG_OPTIONS_SET.db=             mysql sqlite",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		"PKGNAME?=  default-pkgname-1.",
		"",
		".if !empty(PKG_OPTIONS:Mx11)",
		".endif",
		"",
		".if !empty(PKG_OPTIONS:Mundeclared)",
		".endif",
		"",
		".if empty(PKG_OPTIONS:Mnegative)",
		".else",
		".endif",
		"",
		".if empty(PKG_OPTIONS:Mnegative)",
		".endif",
		"",
		".if !empty(PKG_OPTIONS:Mncurses)",
		".elif !empty(PKG_OPTIONS:Mslang)",
		".endif",
		"",
		".if !empty(PKG_OPTIONS:Mmysql)",
		".elif !empty(PKG_OPTIONS:Msqlite)",
		".endif")

	CheckLinesOptionsMk(mklines)

	t.CheckOutputLines(
		"WARN: ~/category/package/options.mk:6: l is used but not defined.",
		"WARN: ~/category/package/options.mk:18: Unknown option \"undeclared\".",
		"NOTE: ~/category/package/options.mk:21: "+
			"The positive branch of the .if/.else should be the one where the option is set.",
		// TODO: The diagnostics should appear in the correct order.
		"WARN: ~/category/package/options.mk:6: "+
			"Option \"mc-charset\" should be handled below in an .if block.",
		"WARN: ~/category/package/options.mk:18: "+
			"Option \"undeclared\" is handled but not added to PKG_SUPPORTED_OPTIONS.")
}

// If there is no .include line after the declaration of the package-settable
// variables, the whole analysis stops.
//
// This case doesn't happen in practice and thus is not worth being handled in detail.
func (s *Suite) Test_CheckLinesOptionsMk__unexpected_line(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wno-space")
	t.SetUpVartypes()

	t.CreateFileLines("mk/bsd.options.mk",
		MkRcsID)

	mklines := t.SetUpFileMkLines("category/package/options.mk",
		MkRcsID,
		"",
		"PKG_OPTIONS_VAR=                PKG_OPTIONS.mc",
		"",
		"pre-configure:",
		"\techo \"In the pre-configure stage.\"")

	CheckLinesOptionsMk(mklines)

	t.CheckOutputLines(
		"WARN: ~/category/package/options.mk:5: Expected inclusion of \"../../mk/bsd.options.mk\".")
}

func (s *Suite) Test_CheckLinesOptionsMk__malformed_condition(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wno-space")
	t.SetUpVartypes()
	t.SetUpOption("mc-charset", "")
	t.SetUpOption("ncurses", "")
	t.SetUpOption("slang", "")
	t.SetUpOption("x11", "")

	t.CreateFileLines("mk/bsd.options.mk",
		MkRcsID)

	mklines := t.SetUpFileMkLines("category/package/options.mk",
		MkRcsID,
		"",
		"PKG_OPTIONS_VAR=                PKG_OPTIONS.mc",
		"PKG_SUPPORTED_OPTIONS=          # none",
		"PKG_SUGGESTED_OPTIONS=          # none",
		"",
		"# Comments and conditionals are allowed at this point.",
		".if ${OPSYS} == NetBSD",
		".endif",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".if ${OPSYS} == 'Darwin'",
		".endif")

	CheckLinesOptionsMk(mklines)

	t.CheckOutputLines(
		"WARN: ~/category/package/options.mk:13: Invalid condition, unrecognized part: \"${OPSYS} == 'Darwin'\".")
}
