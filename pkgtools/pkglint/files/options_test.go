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

// This test is provided for code coverage. Similarities to existing files are purely coincidental.
func (s *Suite) Test_CheckLinesOptionsMk__edge_cases(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall,no-space")
	t.SetUpVartypes()
	t.SetUpOption("option1", "Description for option1")
	t.CreateFileLines("mk/compiler.mk",
		MkRcsID)
	t.CreateFileLines("mk/bsd.options.mk",
		MkRcsID)
	t.DisableTracing()

	mklines := t.SetUpFileMkLines("category/package/options.mk",
		MkRcsID)

	CheckLinesOptionsMk(mklines)

	t.CheckOutputLines(
		"WARN: ~/category/package/options.mk:EOF: Expected definition of PKG_OPTIONS_VAR.")

	mklines = t.SetUpFileMkLines("category/package/options.mk",
		MkRcsID,
		"PKG_SUPPORTED_OPTIONS=\toption1")

	CheckLinesOptionsMk(mklines)

	t.CheckOutputLines(
		"WARN: ~/category/package/options.mk:2: Expected definition of PKG_OPTIONS_VAR.")

	mklines = t.SetUpFileMkLines("category/package/options.mk",
		MkRcsID,
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.pkgbase",
		"PKG_SUPPORTED_OPTIONS=\toption1",
		".include \"../../mk/compiler.mk\"")

	CheckLinesOptionsMk(mklines)

	t.CheckOutputLines(
		"WARN: ~/category/package/options.mk:3: " +
			"Option \"option1\" should be handled below in an .if block.")

	mklines = t.SetUpFileMkLines("category/package/options.mk",
		MkRcsID,
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.pkgbase",
		"PKG_SUPPORTED_OPTIONS=\toption1",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".if !empty(PKG_OPTIONS:O:u:Moption1) "+
			"|| !empty(PKG_OPTIONS:Noption1) "+
			"|| !empty(PKG_OPTIONS:O) "+
			"|| !empty(X11_TYPE) "+
			"|| !empty(PKG_OPTIONS:M${X11_TYPE})",
		".endif")

	CheckLinesOptionsMk(mklines)

	// Although technically this option is handled by the :Noption1 modifier,
	// this is so unusual that the warning is justified.
	t.CheckOutputLines(
		"WARN: ~/category/package/options.mk:3: Option \"option1\" should be handled below in an .if block.")
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

func (s *Suite) Test_CheckLinesOptionsMk__PLIST_VARS_based_on_PKG_SUPPORTED_OPTIONS(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("one", "")
	t.SetUpOption("two", "")
	t.SetUpOption("three", "")
	t.SetUpPackage("category/package")
	t.CreateFileLines("mk/bsd.options.mk")
	t.SetUpFileMkLines("category/package/options.mk",
		MkRcsID,
		"",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.package",
		"PKG_SUPPORTED_OPTIONS+=\tone",
		"PKG_SUPPORTED_OPTIONS+=\ttwo",
		"PKG_SUPPORTED_OPTIONS+=\tthree",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		"PLIST_VARS+=\t${PKG_SUPPORTED_OPTIONS}",
		"",
		".if ${PKG_OPTIONS:Mone}",
		"PLIST.one=\tyes",
		".endif",
		"",
		".if ${PKG_OPTIONS:Mthree}",
		"PLIST.three=\tyes",
		".endif")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	// Even though PLIST_VARS is defined indirectly by referencing
	// PKG_SUPPORTED_OPTIONS and that variable is defined in several
	// lines, pkglint gets all the facts correct and knows that
	// only PLIST.two is missing.
	t.CheckOutputLines(
		"WARN: options.mk:10: "+
			"\"two\" is added to PLIST_VARS, but PLIST.two is not defined in this file.",
		"WARN: options.mk:5: Option \"two\" should be handled below in an .if block.")
}

// Up to April 2019, pkglint logged a wrong note saying that OTHER_VARIABLE
// should have the positive branch first. That note was only ever intended
// for PKG_OPTIONS.
func (s *Suite) Test_OptionsLinesChecker_handleLowerCondition__foreign_variable(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("opt", "")
	t.CreateFileLines("mk/bsd.options.mk")
	t.SetUpPackage("category/package",
		".include \"options.mk\"")
	t.CreateFileLines("category/package/options.mk",
		MkRcsID,
		"",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.package",
		"PKG_SUPPORTED_OPTIONS=\topt",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".if empty(OTHER_VARIABLE)",
		".else",
		".endif")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/package/options.mk:8: OTHER_VARIABLE is used but not defined.",
		"WARN: ~/category/package/options.mk:4: Option \"opt\" should be handled below in an .if block.")
}

func (s *Suite) Test_CheckLinesOptionsMk__autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("opt", "")
	t.CreateFileLines("mk/bsd.options.mk")
	t.SetUpPackage("category/package",
		".include \"options.mk\"")
	t.CreateFileLines("category/package/options.mk",
		MkRcsID,
		"",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.package",
		"PKG_SUPPORTED_OPTIONS=\t# none",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".if 0",
		".if 0",
		".endif",
		".endif")
	t.FinishSetUp()
	t.Chdir("category/package")

	G.Check(".")

	t.CheckOutputLines(
		"NOTE: options.mk:9: This directive should be indented by 2 spaces.",
		"NOTE: options.mk:10: This directive should be indented by 2 spaces.")

	t.SetUpCommandLine("-Wall", "--show-autofix")

	G.Check(".")

	t.CheckOutputLines(
		"NOTE: options.mk:9: This directive should be indented by 2 spaces.",
		"AUTOFIX: options.mk:9: Replacing \".\" with \".  \".",
		"NOTE: options.mk:10: This directive should be indented by 2 spaces.",
		"AUTOFIX: options.mk:10: Replacing \".\" with \".  \".")

	t.SetUpCommandLine("-Wall", "--autofix")

	G.Check(".")

	t.CheckOutputLines(
		"AUTOFIX: options.mk:9: Replacing \".\" with \".  \".",
		"AUTOFIX: options.mk:10: Replacing \".\" with \".  \".")

	t.CheckFileLinesDetab("options.mk",
		MkRcsID,
		"",
		"PKG_OPTIONS_VAR=        PKG_OPTIONS.package",
		"PKG_SUPPORTED_OPTIONS=  # none",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".if 0",
		".  if 0",
		".  endif",
		".endif")
}
