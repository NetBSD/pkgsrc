package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_CheckLinesOptionsMk__autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("opt", "")
	t.CreateFileLines("mk/bsd.options.mk")
	t.SetUpPackage("category/package",
		".include \"options.mk\"")
	t.CreateFileLines("category/package/options.mk",
		MkCvsID,
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
		MkCvsID,
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

func (s *Suite) Test_CheckLinesOptionsMk__literal(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("declared", "")
	t.SetUpOption("both", "")
	t.SetUpOption("handled", "")
	t.SetUpPackage("category/package",
		".include \"../../mk/bsd.options.mk\"")
	t.CreateFileLines("mk/bsd.options.mk",
		MkCvsID)
	mklines := t.SetUpFileMkLines("category/package/options.mk",
		MkCvsID,
		"",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.package",
		"PKG_SUPPORTED_OPTIONS=\tdeclared both",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".if ${PKG_OPTIONS:Mboth}",
		".endif",
		"",
		".if ${PKG_OPTIONS:Mhandled}",
		".endif")
	t.Chdir("category/package")
	t.FinishSetUp()

	CheckLinesOptionsMk(mklines, "")

	t.CheckOutputLines(
		"WARN: ~/category/package/options.mk:4: "+
			"Option \"declared\" should be handled below in an .if block.",
		"WARN: ~/category/package/options.mk:11: "+
			"Option \"handled\" is handled but not added to PKG_SUPPORTED_OPTIONS.")
}

func (s *Suite) Test_CheckLinesOptionsMk__literal_in_for_loop(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("declared", "")
	t.SetUpOption("both", "")
	t.SetUpOption("handled", "")
	t.SetUpPackage("category/package",
		".include \"../../mk/bsd.options.mk\"")
	t.CreateFileLines("mk/bsd.options.mk",
		MkCvsID)
	mklines := t.SetUpFileMkLines("category/package/options.mk",
		MkCvsID,
		"",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.package",
		".for declared_option in declared both",
		"PKG_SUPPORTED_OPTIONS=\t${declared_option}",
		".endfor",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".for handled_option in both handled",
		".  if ${PKG_OPTIONS:M${handled_option}}",
		".  endif",
		".endfor")
	t.Chdir("category/package")
	t.FinishSetUp()

	CheckLinesOptionsMk(mklines, "")

	t.CheckOutputLines(
		"WARN: ~/category/package/options.mk:5: "+
			"Option \"declared\" should be handled below in an .if block.",
		"WARN: ~/category/package/options.mk:11: "+
			"Option \"handled\" is handled but not added to PKG_SUPPORTED_OPTIONS.")
}

// Before version 19.3.5, pkglint warned when bsd.prefs.mk was
// included in the top half of the file.
func (s *Suite) Test_CheckLinesOptionsMk__prefs(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("option", "")
	t.SetUpPackage("category/package",
		".include \"../../mk/bsd.options.mk\"")
	t.CreateFileLines("mk/bsd.options.mk",
		MkCvsID)
	mklines := t.SetUpFileMkLines("category/package/options.mk",
		MkCvsID,
		"",
		".include \"../../mk/bsd.prefs.mk\"",
		"",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.package",
		"PKG_SUPPORTED_OPTIONS=\toption",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".if ${PKG_OPTIONS:Moption}",
		".endif")
	t.Chdir("category/package")
	t.FinishSetUp()

	CheckLinesOptionsMk(mklines, "")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_CheckLinesOptionsMk__variable_order(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("option", "")
	t.SetUpPackage("category/package",
		".include \"options.mk\"")
	t.CreateFileLines("mk/bsd.options.mk",
		MkCvsID)
	mklines := t.SetUpFileMkLines("category/package/options.mk",
		MkCvsID,
		"",
		"PKG_SUPPORTED_OPTIONS=\toption",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.package",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".if ${PKG_OPTIONS:Moption}",
		".endif")
	t.Chdir("category/package")
	t.FinishSetUp()

	CheckLinesOptionsMk(mklines, "")

	t.CheckOutputLines(
		"WARN: ~/category/package/options.mk:3: " +
			"Expected definition of PKG_OPTIONS_VAR.")
}

func (s *Suite) Test_CheckLinesOptionsMk__empty(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"options.mk\"")
	mklines := t.SetUpFileMkLines("category/package/options.mk",
		MkCvsID)
	t.Chdir("category/package")
	t.FinishSetUp()

	CheckLinesOptionsMk(mklines, "")

	t.CheckOutputLines(
		"ERROR: ~/category/package/options.mk: "+
			"Each options.mk file must define PKG_OPTIONS_VAR.",
		"ERROR: ~/category/package/options.mk: "+
			"Each options.mk file must .include \"../../mk/bsd.options.mk\".")
}

func (s *Suite) Test_CheckLinesOptionsMk__conditionals(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("option", "")
	t.SetUpPackage("category/package",
		".include \"../../mk/bsd.options.mk\"")
	t.CreateFileLines("mk/bsd.options.mk",
		MkCvsID)
	t.Chdir("category/package")
	mklines := t.SetUpFileMkLines("options.mk",
		MkCvsID,
		"",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.package",
		"PKG_SUPPORTED_OPTIONS=\toption",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".if ${PKG_OPTIONS}", // typo: should be ${PKG_OPTIONS:Moption}
		".endif",
		"",
		".if ${PKG_OPTIONS:Nnegative}", // :N instead of :M, is ignored
		".endif",
		"",
		".if ${PKG_OPTIONS:Ncodec-*}",
		".endif",
		"",
		".if ${PKG_OPTIONS:tl}", // doesn't make sense, just for branch coverage
		".endif")
	t.FinishSetUp()

	CheckLinesOptionsMk(mklines, "")

	t.CheckOutputLines(
		// This warning comes from VarTypeCheck.PkgOption
		"WARN: options.mk:11: Unknown option \"negative\".",
		"WARN: options.mk:4: "+
			"Option \"option\" should be handled below in an .if block.")
}

func (s *Suite) Test_CheckLinesOptionsMk(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpOption("mc-charset", "")
	t.SetUpOption("mysql", "")
	t.SetUpOption("ncurses", "")
	t.SetUpOption("negative", "Demonstrates negated .if/.else")
	t.SetUpOption("slang", "")
	t.SetUpOption("sqlite", "")
	t.SetUpOption("x11", "")

	t.CreateFileLines("mk/bsd.options.mk",
		MkCvsID)

	mklines := t.SetUpFileMkLines("category/package/options.mk",
		MkCvsID,
		"",
		"PKG_OPTIONS_VAR=\t\tPKG_OPTIONS.mc",
		"PKG_OPTIONS_REQUIRED_GROUPS=\tscreen",
		"PKG_OPTIONS_GROUP.screen=\tncurses slang",
		"PKG_SUPPORTED_OPTIONS=\t\tmc-charset x11 lang-${l} negative",
		"PKG_SUGGESTED_OPTIONS=\t\tmc-charset slang",
		"PKG_OPTIONS_NONEMPTY_SETS+=\tdb",
		"PKG_OPTIONS_SET.db=\t\tmysql sqlite",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		"PKGNAME?=\tdefault-pkgname-1.",
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

	CheckLinesOptionsMk(mklines, "")

	t.CheckOutputLines(
		"WARN: ~/category/package/options.mk:6: l is used but not defined.",
		"WARN: ~/category/package/options.mk:18: Unknown option \"undeclared\".",
		"WARN: ~/category/package/options.mk:21: "+
			"The positive branch of the .if/.else should be the one where the option is set.",
		// TODO: The diagnostics should appear in the correct order.
		"WARN: ~/category/package/options.mk:6: "+
			"Option \"mc-charset\" should be handled below in an .if block.")
	// TODO: There is no warning for the option "undeclared" since
	//  the option lang-${l} sets declaredArbitrary. This in turn
	//  disables possible wrong warnings, but a few too many.
}

// If there is no .include line after the declaration of the package-settable
// variables, the whole analysis stops.
//
// This case doesn't happen in practice and thus is not worth being handled in detail.
func (s *Suite) Test_CheckLinesOptionsMk__unexpected_line(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	t.CreateFileLines("mk/bsd.options.mk",
		MkCvsID)

	mklines := t.SetUpFileMkLines("category/package/options.mk",
		MkCvsID,
		"",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.mc",
		"",
		"pre-configure:",
		"\techo \"In the pre-configure stage.\"")

	CheckLinesOptionsMk(mklines, "")

	t.CheckOutputLines(
		"WARN: ~/category/package/options.mk:6: "+
			"Unknown shell command \"echo\".",
		"ERROR: ~/category/package/options.mk: "+
			"Each options.mk file must .include \"../../mk/bsd.options.mk\".")
}

func (s *Suite) Test_CheckLinesOptionsMk__malformed_condition(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.Chdir(".")
	t.SetUpOption("mc-charset", "")
	t.SetUpOption("ncurses", "")
	t.SetUpOption("slang", "")
	t.SetUpOption("x11", "")
	t.CreateFileLines("mk/bsd.options.mk",
		MkCvsID)
	t.FinishSetUp()

	mklines := t.SetUpFileMkLines("category/package/options.mk",
		MkCvsID,
		"",
		"PKG_OPTIONS_VAR=\t\tPKG_OPTIONS.mc",
		"PKG_SUPPORTED_OPTIONS=\t\t# none",
		"PKG_SUGGESTED_OPTIONS=\t\t# none",
		"",
		".include \"../../mk/bsd.fast.prefs.mk\"",
		"",
		"# Comments and conditionals are allowed at this point.",
		".if ${OPSYS} == NetBSD",
		".endif",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".if ${OPSYS} == 'Darwin'",
		".endif")

	CheckLinesOptionsMk(mklines, "")

	t.CheckOutputLines(
		"WARN: category/package/options.mk:15: Invalid condition, unrecognized part: \"${OPSYS} == 'Darwin'\".")
}

func (s *Suite) Test_CheckLinesOptionsMk__PLIST_VARS_based_on_PKG_SUPPORTED_OPTIONS(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("one", "")
	t.SetUpOption("two", "")
	t.SetUpOption("three", "")
	t.SetUpPackage("category/package")
	t.CreateFileLines("mk/bsd.options.mk")
	t.SetUpFileMkLines("category/package/options.mk",
		MkCvsID,
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

// A few packages (such as www/w3m) define several options that are
// handled by a single .if block in the lower part.
func (s *Suite) Test_CheckLinesOptionsMk__combined_option_handling(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("opt-variant1", "")
	t.SetUpOption("opt-variant2", "")
	t.SetUpOption("other", "")
	t.CreateFileLines("mk/bsd.options.mk")
	t.SetUpPackage("category/package",
		".include \"options.mk\"")
	t.CreateFileLines("category/package/options.mk",
		MkCvsID,
		"",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.package",
		"PKG_SUPPORTED_OPTIONS=\topt-variant1 opt-variant2",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".if ${PKG_OPTIONS:Mopt-variant*}",
		".endif")
	t.FinishSetUp()
	t.Chdir("category/package")

	G.Check(".")

	// Before 5.7.21 on 2019-08-17, pkglint issued an error about the
	// "invalid option name opt-variant*" and warnings about the
	// unhandled options "opt-variant1" and "opt-variant2".
	t.CheckOutputEmpty()
}

func (s *Suite) Test_CheckLinesOptionsMk__combined_option_handling_coverage(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("opt-variant", "")
	t.CreateFileLines("mk/bsd.options.mk")
	t.SetUpPackage("category/package",
		".include \"options.mk\"")
	t.CreateFileLines("category/package/options.mk",
		MkCvsID,
		"",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.package",
		"PKG_SUPPORTED_OPTIONS=\topt-variant",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".if ${PKG_OPTIONS:Mopt-[}", // intentional syntax error
		".endif",
		"",
		".if ${PKG_OPTIONS:Mother-*}",
		".endif")
	t.FinishSetUp()
	t.Chdir("category/package")

	G.Check(".")

	// The pattern "opt-[" does not match any of the declared options
	// since the pattern is malformed and pkglint does not distinguish
	// between invalid and non-matching patterns.
	//
	// The pattern "other-*" also doesn't match.
	//
	// Since the patterns don't match any of the variables from
	// PKG_SUPPORTED_OPTIONS, pkglint cannot analyze all possible cases
	// and therefore suppresses all warnings about options that are
	// declared but not handled.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_CheckLinesOptionsMk__options_in_for_loop(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("idea", "")
	t.SetUpOption("md2", "")
	t.SetUpOption("md5", "")
	t.SetUpOption("other", "")
	t.CreateFileLines("mk/bsd.options.mk")
	t.SetUpPackage("category/package",
		".include \"options.mk\"")
	t.CreateFileLines("category/package/options.mk",
		MkCvsID,
		"",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.package",
		"PKG_SUPPORTED_OPTIONS=\tidea md2 md5 other",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".for alg in idea md2 md5",
		".  if ${PKG_OPTIONS:M${alg}}",
		".  endif",
		".endfor")
	t.FinishSetUp()
	t.Chdir("category/package")

	G.Check(".")

	t.CheckOutputLines(
		"WARN: options.mk:4: Option \"other\" should be handled below in an .if block.")
}

func (s *Suite) Test_CheckLinesOptionsMk__indirect(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("generic", "")
	t.SetUpOption("netbsd", "")
	t.SetUpOption("os", "")
	t.CreateFileLines("mk/bsd.options.mk")
	t.SetUpPackage("category/package",
		".include \"options.mk\"")
	t.CreateFileLines("category/package/options.mk",
		MkCvsID,
		"",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.package",
		"PKG_SUPPORTED_OPTIONS=\tgeneric",
		"PKG_SUGGESTED_OPTIONS=\tgeneric",
		"",
		"PKG_SUPPORTED_OPTIONS.FreeBSD=\tos",
		"PKG_SUGGESTED_OPTIONS.FreeBSD=\tos",
		"",
		"PKG_SUPPORTED_OPTIONS.NetBSD+=\tnetbsd os",
		"PKG_SUGGESTED_OPTIONS.NetBSD+=\tnetbsd os",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		"PLIST_VARS+=\tgeneric netbsd os",
		"",
		".for option in ${PLIST_VARS}",
		".  if ${PKG_OPTIONS:M${option}}",
		"CONFIGURE_ARGS+=\t--enable-${option:S/-/_/}",
		"PLIST.${option}=\tyes",
		".  endif",
		".endfor")
	t.FinishSetUp()
	t.Chdir("category/package")

	G.Check(".")

	t.CheckOutputEmpty()
}

// An unrealistic scenario, but necessary for code coverage.
func (s *Suite) Test_CheckLinesOptionsMk__partly_indirect(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/bsd.options.mk")
	t.SetUpPackage("category/package",
		".include \"options.mk\"")
	t.CreateFileLines("category/package/options.mk",
		MkCvsID,
		"",
		"# Including bsd.prefs.mk is not necessary here since the OPSYS",
		"# in PKG_SUPPORTED_OPTIONS is only evaluated lazily inside",
		"# bsd.options.mk, at which point bsd.prefs.mk will be included",
		"# as well.",
		"",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.package",
		"PKG_SUPPORTED_OPTIONS=\tgeneric-${OPSYS}",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".for option in generic-${OPSYS}",
		".  if ${PKG_OPTIONS:M${option}}",
		".  endif",
		".endfor")
	t.FinishSetUp()
	t.Chdir("category/package")

	G.Check(".")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_CheckLinesOptionsMk__indirect_supported_options_parentheses(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("indirect", "")
	t.SetUpOption("direct", "")
	t.SetUpVartypes()
	t.CreateFileLines("mk/bsd.options.mk",
		MkCvsID)
	mklines := t.SetUpFileMkLines("category/package/options.mk",
		MkCvsID,
		"",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.package",
		"OPTIONS=\t\tindirect",
		"PKG_SUPPORTED_OPTIONS=\t$(OPTIONS) direct",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".for option in ${OPTIONS}",
		".  if ${PKG_OPTIONS:M${option}}",
		".  endif",
		".endfor")

	CheckLinesOptionsMk(mklines, "")

	t.CheckOutputLines(
		"WARN: ~/category/package/options.mk:5: "+
			"Please use curly braces {} instead of round parentheses () for OPTIONS.",
		"WARN: ~/category/package/options.mk:5: "+
			"Option \"direct\" should be handled below in an .if block.")
}

func (s *Suite) Test_CheckLinesOptionsMk__handled_but_not_supported(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("option", "")
	t.SetUpVartypes()
	t.CreateFileLines("mk/bsd.options.mk",
		MkCvsID)
	mklines := t.SetUpFileMkLines("category/package/options.mk",
		MkCvsID,
		"",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.package",
		"PKG_SUPPORTED_OPTIONS=\t# none",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".if ${PKG_OPTIONS:Moption}",
		".endif")

	CheckLinesOptionsMk(mklines, "")

	t.CheckOutputLines(
		"WARN: ~/category/package/options.mk:8: " +
			"Option \"option\" is handled but not added to PKG_SUPPORTED_OPTIONS.")
}

func (s *Suite) Test_CheckLinesOptionsMk__supported_but_not_checked(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("option", "")
	t.SetUpVartypes()
	t.CreateFileLines("mk/bsd.options.mk",
		MkCvsID)
	mklines := t.SetUpFileMkLines("category/package/options.mk",
		MkCvsID,
		"",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.package",
		"PKG_SUPPORTED_OPTIONS=\toption",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".if ${PKG_OPTIONS:Mopt${:Uion}}",
		".endif")

	CheckLinesOptionsMk(mklines, "")

	// Pkglint does not expand the ${:Uion}, therefore it doesn't know that
	// the option is indeed handled. Because of this uncertainty, pkglint
	// does not issue any warnings about possibly unhandled options at all.
	t.CheckOutputEmpty()
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
		MkCvsID,
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
