package main

import "gopkg.in/check.v1"

func (s *Suite) Test_VaralignBlock_Check_autofix(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wspace", "--show-autofix")

	lines := t.NewLines("file.mk",
		"VAR=   value",    // Indentation 7, fixed to 8.
		"",                //
		"VAR=    value",   // Indentation 8, fixed to 8.
		"",                //
		"VAR=     value",  // Indentation 9, fixed to 8.
		"",                //
		"VAR= \tvalue",    // Mixed indentation 8, fixed to 8.
		"",                //
		"VAR=   \tvalue",  // Mixed indentation 8, fixed to 8.
		"",                //
		"VAR=    \tvalue", // Mixed indentation 16, fixed to 16.
		"",                //
		"VAR=\tvalue")     // Already aligned with tabs only, left unchanged.

	varalign := &VaralignBlock{}
	for _, line := range lines {
		varalign.Check(NewMkLine(line))
	}
	varalign.Finish()

	t.CheckOutputLines(
		"NOTE: file.mk:1: This variable value should be aligned with tabs, not spaces, to column 9.",
		"AUTOFIX: file.mk:1: Replacing \"   \" with \"\\t\".",
		"NOTE: file.mk:3: Variable values should be aligned with tabs, not spaces.",
		"AUTOFIX: file.mk:3: Replacing \"    \" with \"\\t\".",
		"NOTE: file.mk:5: This variable value should be aligned with tabs, not spaces, to column 9.",
		"AUTOFIX: file.mk:5: Replacing \"     \" with \"\\t\".",
		"NOTE: file.mk:7: Variable values should be aligned with tabs, not spaces.",
		"AUTOFIX: file.mk:7: Replacing \" \\t\" with \"\\t\".",
		"NOTE: file.mk:9: Variable values should be aligned with tabs, not spaces.",
		"AUTOFIX: file.mk:9: Replacing \"   \\t\" with \"\\t\".",
		"NOTE: file.mk:11: Variable values should be aligned with tabs, not spaces.",
		"AUTOFIX: file.mk:11: Replacing \"    \\t\" with \"\\t\\t\".")
}

func (s *Suite) Test_VaralignBlock_Check__reduce_indentation(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wspace")
	mklines := t.NewMkLines("file.mk",
		"VAR= \tvalue",
		"VAR=    \tvalue",
		"VAR=\t\t\t\tvalue",
		"",
		"VAR=\t\t\tneedlessly", // Nothing to be fixed here, since it looks good.
		"VAR=\t\t\tdeep",
		"VAR=\t\t\tindentation")

	varalign := new(VaralignBlock)
	for _, mkline := range mklines.mklines {
		varalign.Check(mkline)
	}
	varalign.Finish()

	t.CheckOutputLines(
		"NOTE: file.mk:1: Variable values should be aligned with tabs, not spaces.",
		"NOTE: file.mk:2: This variable value should be aligned with tabs, not spaces, to column 9.",
		"NOTE: file.mk:3: This variable value should be aligned to column 9.")
}

func (s *Suite) Test_VaralignBlock_Check_longest_line_no_space(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wspace")
	mklines := t.NewMkLines("file.mk",
		"SUBST_CLASSES+= aaaaaaaa",
		"SUBST_STAGE.aaaaaaaa= pre-configure",
		"SUBST_FILES.aaaaaaaa= *.pl",
		"SUBST_FILTER_CMD.aaaaaaaa=cat")

	varalign := new(VaralignBlock)
	for _, mkline := range mklines.mklines {
		varalign.Check(mkline)
	}
	varalign.Finish()

	t.CheckOutputLines(
		"NOTE: file.mk:1: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:2: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:3: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:4: This variable value should be aligned to column 33.")
}

func (s *Suite) Test_VaralignBlock_Check_only_spaces(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wspace")
	mklines := t.NewMkLines("file.mk",
		"SUBST_CLASSES+= aaaaaaaa",
		"SUBST_STAGE.aaaaaaaa= pre-configure",
		"SUBST_FILES.aaaaaaaa= *.pl",
		"SUBST_FILTER_CMD.aaaaaaaa= cat")

	varalign := new(VaralignBlock)
	for _, mkline := range mklines.mklines {
		varalign.Check(mkline)
	}
	varalign.Finish()

	t.CheckOutputLines(
		"NOTE: file.mk:1: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:2: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:3: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:4: This variable value should be aligned with tabs, not spaces, to column 33.")
}

func (s *Suite) Test_NewMkLine(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wspace")
	mklines := t.NewMkLines("test.mk",
		"VARNAME.param?=value # varassign comment",
		"\tshell command # shell comment",
		"# whole line comment",
		"",
		".  if !empty(PKGNAME:M*-*) && ${RUBY_RAILS_SUPPORTED:[\\#]} == 1 # directive comment",
		".    include \"../../mk/bsd.prefs.mk\" # include comment",
		".    include <subdir.mk> # sysinclude comment",
		"target1 target2: source1 source2",
		"target : source",
		"VARNAME+=value",
		"<<<<<<<<<<<<<<<<<")
	ln := mklines.mklines

	c.Check(ln[0].IsVarassign(), equals, true)
	c.Check(ln[0].Varname(), equals, "VARNAME.param")
	c.Check(ln[0].Varcanon(), equals, "VARNAME.*")
	c.Check(ln[0].Varparam(), equals, "param")
	c.Check(ln[0].Op(), equals, opAssignDefault)
	c.Check(ln[0].Value(), equals, "value")
	c.Check(ln[0].VarassignComment(), equals, "# varassign comment")

	c.Check(ln[1].IsShellCommand(), equals, true)
	c.Check(ln[1].ShellCommand(), equals, "shell command # shell comment")

	c.Check(ln[2].IsComment(), equals, true)

	c.Check(ln[3].IsEmpty(), equals, true)

	c.Check(ln[4].IsDirective(), equals, true)
	c.Check(ln[4].Indent(), equals, "  ")
	c.Check(ln[4].Directive(), equals, "if")
	c.Check(ln[4].Args(), equals, "!empty(PKGNAME:M*-*) && ${RUBY_RAILS_SUPPORTED:[#]} == 1")
	c.Check(ln[4].DirectiveComment(), equals, "directive comment")

	c.Check(ln[5].IsInclude(), equals, true)
	c.Check(ln[5].Indent(), equals, "    ")
	c.Check(ln[5].MustExist(), equals, true)
	c.Check(ln[5].IncludeFile(), equals, "../../mk/bsd.prefs.mk")

	c.Check(ln[6].IsSysinclude(), equals, true)
	c.Check(ln[6].Indent(), equals, "    ")
	c.Check(ln[6].MustExist(), equals, true)
	c.Check(ln[6].IncludeFile(), equals, "subdir.mk")

	c.Check(ln[7].IsDependency(), equals, true)
	c.Check(ln[7].Targets(), equals, "target1 target2")
	c.Check(ln[7].Sources(), equals, "source1 source2")

	c.Check(ln[9].IsVarassign(), equals, true)
	c.Check(ln[9].Varname(), equals, "VARNAME")
	c.Check(ln[9].Varcanon(), equals, "VARNAME")
	c.Check(ln[9].Varparam(), equals, "")

	// Merge conflicts are of neither type.
	c.Check(ln[10].IsVarassign(), equals, false)
	c.Check(ln[10].IsDirective(), equals, false)
	c.Check(ln[10].IsInclude(), equals, false)
	c.Check(ln[10].IsEmpty(), equals, false)
	c.Check(ln[10].IsComment(), equals, false)
	c.Check(ln[10].IsDependency(), equals, false)
	c.Check(ln[10].IsShellCommand(), equals, false)
	c.Check(ln[10].IsSysinclude(), equals, false)

	t.CheckOutputLines(
		"WARN: test.mk:9: Space before colon in dependency line.")
}

func (s *Suite) Test_NewMkLine__autofix_space_after_varname(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wspace")
	fname := t.CreateFileLines("Makefile",
		MkRcsID,
		"VARNAME +=\t${VARNAME}",
		"VARNAME+ =\t${VARNAME+}",
		"VARNAME+ +=\t${VARNAME+}",
		"pkgbase := pkglint")

	CheckfileMk(fname)

	t.CheckOutputLines(
		"WARN: ~/Makefile:2: Unnecessary space after variable name \"VARNAME\".",
		"WARN: ~/Makefile:4: Unnecessary space after variable name \"VARNAME+\".")

	t.SetupCommandLine("-Wspace", "--autofix")

	CheckfileMk(fname)

	t.CheckOutputLines(
		"AUTOFIX: ~/Makefile:2: Replacing \"VARNAME +=\" with \"VARNAME+=\".",
		"AUTOFIX: ~/Makefile:4: Replacing \"VARNAME+ +=\" with \"VARNAME++=\".")
	t.CheckFileLines("Makefile",
		MkRcsID+"",
		"VARNAME+=\t${VARNAME}",
		"VARNAME+ =\t${VARNAME+}",
		"VARNAME++=\t${VARNAME+}",
		"pkgbase := pkglint")
}

// Guessing the variable type works for both plain and parameterized variable names.
func (s *Suite) Test_MkLine_VariableType_varparam(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("fname", 1, "# dummy")
	t.SetupVartypes()

	t1 := mkline.VariableType("FONT_DIRS")

	c.Assert(t1, check.NotNil)
	c.Check(t1.String(), equals, "ShellList of Pathmask (guessed)")

	t2 := mkline.VariableType("FONT_DIRS.ttf")

	c.Assert(t2, check.NotNil)
	c.Check(t2.String(), equals, "ShellList of Pathmask (guessed)")
}

func (s *Suite) Test_VarUseContext_String(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mkline := t.NewMkLine("fname", 1, "# dummy")
	vartype := mkline.VariableType("PKGNAME")
	vuc := &VarUseContext{vartype, vucTimeUnknown, vucQuotBackt, false}

	c.Check(vuc.String(), equals, "(PkgName time:unknown quoting:backt wordpart:false)")
}

// In variable assignments, a plain '#' introduces a line comment, unless
// it is escaped by a backslash. In shell commands, on the other hand, it
// is interpreted literally.
func (s *Suite) Test_NewMkLine_numbersign(c *check.C) {
	t := s.Init(c)

	mklineVarassignEscaped := t.NewMkLine("fname", 1, "SED_CMD=\t's,\\#,hash,g'")

	c.Check(mklineVarassignEscaped.Varname(), equals, "SED_CMD")
	c.Check(mklineVarassignEscaped.Value(), equals, "'s,#,hash,g'")

	mklineCommandEscaped := t.NewMkLine("fname", 1, "\tsed -e 's,\\#,hash,g'")

	c.Check(mklineCommandEscaped.ShellCommand(), equals, "sed -e 's,\\#,hash,g'")

	// From shells/zsh/Makefile.common, rev. 1.78
	mklineCommandUnescaped := t.NewMkLine("fname", 1, "\t# $ sha1 patches/patch-ac")

	c.Check(mklineCommandUnescaped.ShellCommand(), equals, "# $ sha1 patches/patch-ac")
	t.CheckOutputEmpty() // No warning about parsing the lonely dollar sign.

	mklineVarassignUnescaped := t.NewMkLine("fname", 1, "SED_CMD=\t's,#,hash,'")

	c.Check(mklineVarassignUnescaped.Value(), equals, "'s,")
	t.CheckOutputLines(
		"WARN: fname:1: The # character starts a comment.")
}

func (s *Suite) Test_NewMkLine_leading_space(c *check.C) {
	t := s.Init(c)

	_ = t.NewMkLine("rubyversion.mk", 427, " _RUBYVER=\t2.15")

	t.CheckOutputLines(
		"WARN: rubyversion.mk:427: Makefile lines should not start with space characters.")
}

func (s *Suite) Test_MkLines_Check__extra(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wextra")
	t.SetupVartypes()
	G.Pkg = NewPackage(t.File("category/pkgbase"))
	G.Mk = t.NewMkLines("options.mk",
		MkRcsID,
		".for word in ${PKG_FAIL_REASON}",
		"PYTHON_VERSIONS_ACCEPTED=\t27 35 30",
		"CONFIGURE_ARGS+=\t--sharedir=${PREFIX}/share/kde",
		"COMMENT=\t# defined",
		".endfor",
		"GAMES_USER?=pkggames",
		"GAMES_GROUP?=pkggames",
		"PLIST_SUBST+= CONDITIONAL=${CONDITIONAL}",
		"CONDITIONAL=\"@comment\"",
		"BUILD_DIRS=\t${WRKSRC}/../build")

	G.Mk.Check()

	t.CheckOutputLines(
		"WARN: options.mk:3: The values for PYTHON_VERSIONS_ACCEPTED should be in decreasing order.",
		"NOTE: options.mk:5: Please use \"# empty\", \"# none\" or \"yes\" instead of \"# defined\".",
		"WARN: options.mk:7: Please include \"../../mk/bsd.prefs.mk\" before using \"?=\".",
		"WARN: options.mk:11: Building the package should take place entirely inside ${WRKSRC}, not \"${WRKSRC}/..\".",
		"NOTE: options.mk:11: You can use \"../build\" instead of \"${WRKSRC}/../build\".")
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__unknown_rhs(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("fname", 1, "PKGNAME := ${UNKNOWN}")
	t.SetupVartypes()

	vuc := &VarUseContext{G.Pkgsrc.vartypes["PKGNAME"], vucTimeParse, vucQuotUnknown, false}
	nq := mkline.VariableNeedsQuoting("UNKNOWN", nil, vuc)

	c.Check(nq, equals, nqDontKnow)
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__append_URL_to_list_of_URLs(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	t.SetupMasterSite("MASTER_SITE_SOURCEFORGE", "http://downloads.sourceforge.net/sourceforge/")
	mkline := t.NewMkLine("Makefile", 95, "MASTER_SITES=\t${HOMEPAGE}")

	vuc := &VarUseContext{G.Pkgsrc.vartypes["MASTER_SITES"], vucTimeRun, vucQuotPlain, false}
	nq := mkline.VariableNeedsQuoting("HOMEPAGE", G.Pkgsrc.vartypes["HOMEPAGE"], vuc)

	c.Check(nq, equals, nqNo)

	MkLineChecker{mkline}.checkVarassign()

	t.CheckOutputEmpty() // Up to pkglint 5.3.6, it warned about a missing :Q here, which was wrong.
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__append_list_to_list(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	t.SetupMasterSite("MASTER_SITE_SOURCEFORGE", "http://downloads.sourceforge.net/sourceforge/")
	mkline := t.NewMkLine("Makefile", 96, "MASTER_SITES=\t${MASTER_SITE_SOURCEFORGE:=squirrel-sql/}")

	MkLineChecker{mkline}.checkVarassign()

	// Assigning lists to lists is ok.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__eval_shell(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	mkline := t.NewMkLine("builtin.mk", 3, "USE_BUILTIN.Xfixes!=\t${PKG_ADMIN} pmatch 'pkg-[0-9]*' ${BUILTIN_PKG.Xfixes:Q}")

	MkLineChecker{mkline}.checkVarassign()

	t.CheckOutputLines(
		"WARN: builtin.mk:3: PKG_ADMIN should not be evaluated at load time.",
		"NOTE: builtin.mk:3: The :Q operator isn't necessary for ${BUILTIN_PKG.Xfixes} here.")
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__command_in_single_quotes(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	mkline := t.NewMkLine("Makefile", 3, "SUBST_SED.hpath=\t-e 's|^\\(INSTALL[\t:]*=\\).*|\\1${INSTALL}|'")

	MkLineChecker{mkline}.checkVarassign()

	t.CheckOutputLines(
		"WARN: Makefile:3: Please use ${INSTALL:Q} instead of ${INSTALL} and make sure the variable appears outside of any quoting characters.")
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__command_in_command(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	t.SetupTool(&Tool{Name: "find", Varname: "FIND", Predefined: true})
	t.SetupTool(&Tool{Name: "sort", Varname: "SORT", Predefined: true})
	G.Pkg = NewPackage(t.File("category/pkgbase"))
	G.Mk = t.NewMkLines("Makefile",
		MkRcsID,
		"GENERATE_PLIST= cd ${DESTDIR}${PREFIX}; ${FIND} * \\( -type f -or -type l \\) | ${SORT};")

	G.Mk.DetermineDefinedVariables()
	MkLineChecker{G.Mk.mklines[1]}.Check()

	t.CheckOutputLines(
		"WARN: Makefile:2: The exitcode of \"${FIND}\" at the left of the | operator is ignored.")
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__word_as_part_of_word(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	G.Mk = t.NewMkLines("Makefile",
		MkRcsID,
		"EGDIR=\t${EGDIR}/${MACHINE_GNU_PLATFORM}")

	MkLineChecker{G.Mk.mklines[1]}.Check()

	t.CheckOutputEmpty()
}

// As an argument to ${ECHO}, the :Q modifier should be used, but pkglint
// currently does not know all shell commands and how they handle their
// arguments. As an argument to xargs(1), the :Q modifier would be misplaced,
// therefore no warning is issued in both these cases.
//
// Based on graphics/circos/Makefile.
func (s *Suite) Test_MkLine_variableNeedsQuoting__command_as_command_argument(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupTool(&Tool{Name: "perl", Varname: "PERL5", Predefined: true})
	t.SetupTool(&Tool{Name: "bash", Varname: "BASH", Predefined: true})
	t.SetupVartypes()
	G.Mk = t.NewMkLines("Makefile",
		MkRcsID,
		"\t${RUN} cd ${WRKSRC} && ( ${ECHO} ${PERL5:Q} ; ${ECHO} ) | ${BASH} ./install",
		"\t${RUN} cd ${WRKSRC} && ( ${ECHO} ${PERL5} ; ${ECHO} ) | ${BASH} ./install")

	MkLineChecker{G.Mk.mklines[1]}.Check()
	MkLineChecker{G.Mk.mklines[2]}.Check()

	t.CheckOutputLines(
		"WARN: Makefile:2: The exitcode of the command at the left of the | operator is ignored.",
		"WARN: Makefile:3: The exitcode of the command at the left of the | operator is ignored.")
}

// Based on mail/mailfront/Makefile.
func (s *Suite) Test_MkLine_variableNeedsQuoting__URL_as_part_of_word_in_list(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	G.Mk = t.NewMkLines("Makefile",
		MkRcsID,
		"MASTER_SITES=${HOMEPAGE}archive/")

	MkLineChecker{G.Mk.mklines[1]}.Check()

	t.CheckOutputEmpty() // Don't suggest to use ${HOMEPAGE:Q}.
}

// Pkglint currently does not parse $$(subshell) commands very well. As
// a side effect, it sometimes issues wrong warnings about the :Q
// modifier.
//
// Based on www/firefox31/xpi.mk.
func (s *Suite) Test_MkLine_variableNeedsQuoting__command_in_subshell(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	t.SetupTool(&Tool{Name: "awk", Varname: "AWK", Predefined: true})
	t.SetupTool(&Tool{Name: "echo", Varname: "ECHO", Predefined: true})
	G.Mk = t.NewMkLines("xpi.mk",
		MkRcsID,
		"\t id=$$(${AWK} '{print}' < ${WRKSRC}/idfile) && echo \"$$id\"",
		"\t id=`${AWK} '{print}' < ${WRKSRC}/idfile` && echo \"$$id\"")

	MkLineChecker{G.Mk.mklines[1]}.Check()
	MkLineChecker{G.Mk.mklines[2]}.Check()

	// Don't suggest to use ${AWK:Q}.
	t.CheckOutputLines(
		"WARN: xpi.mk:2: Invoking subshells via $(...) is not portable enough.")
}

// LDFLAGS (and even more so CPPFLAGS and CFLAGS) may contain special
// shell characters like quotes or backslashes. Therefore, quoting them
// correctly is more tricky than with other variables.
func (s *Suite) Test_MkLine_variableNeedsQuoting__LDFLAGS_in_single_quotes(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	G.Mk = t.NewMkLines("x11/mlterm/Makefile",
		MkRcsID,
		"SUBST_SED.link=-e 's|(LIBTOOL_LINK).*(LIBS)|& ${LDFLAGS:M*:Q}|g'",
		"SUBST_SED.link=-e 's|(LIBTOOL_LINK).*(LIBS)|& '${LDFLAGS:M*:Q}'|g'")

	MkLineChecker{G.Mk.mklines[1]}.Check()
	MkLineChecker{G.Mk.mklines[2]}.Check()

	t.CheckOutputLines(
		"WARN: x11/mlterm/Makefile:2: Please move ${LDFLAGS:M*:Q} outside of any quoting characters.")
}

// No quoting is necessary here.
// PKG_OPTIONS are declared as "lkShell" although they are processed
// using make's .for loop, which splits them at whitespace and usually
// requires the variable to be declared as "lkSpace".
// In this case it doesn't matter though since each option is an identifier,
// and these do not pose any quoting or escaping problems.
func (s *Suite) Test_MkLine_variableNeedsQuoting__package_options(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	G.Mk = t.NewMkLines("Makefile",
		MkRcsID,
		"PKG_SUGGESTED_OPTIONS+=\t${PKG_DEFAULT_OPTIONS:Mcdecimal} ${PKG_OPTIONS.py-trytond:Mcdecimal}")

	MkLineChecker{G.Mk.mklines[1]}.Check()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines_Check__MASTER_SITE_in_HOMEPAGE(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupMasterSite("MASTER_SITE_GITHUB", "https://github.com/")
	t.SetupVartypes()
	G.Mk = t.NewMkLines("devel/catch/Makefile",
		MkRcsID,
		"HOMEPAGE=\t${MASTER_SITE_GITHUB:=philsquared/Catch/}",
		"HOMEPAGE=\t${MASTER_SITE_GITHUB}",
		"HOMEPAGE=\t${MASTER_SITES}",
		"HOMEPAGE=\t${MASTER_SITES}${GITHUB_PROJECT}")

	G.Mk.Check()

	t.CheckOutputLines(
		"WARN: devel/catch/Makefile:2: HOMEPAGE should not be defined in terms of MASTER_SITEs. Use https://github.com/philsquared/Catch/ directly.",
		"WARN: devel/catch/Makefile:3: HOMEPAGE should not be defined in terms of MASTER_SITEs. Use https://github.com/ directly.",
		"WARN: devel/catch/Makefile:4: HOMEPAGE should not be defined in terms of MASTER_SITEs.",
		"WARN: devel/catch/Makefile:5: HOMEPAGE should not be defined in terms of MASTER_SITEs.")
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__tool_in_quotes_in_subshell_in_shellwords(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupTool(&Tool{Name: "echo", Varname: "ECHO", Predefined: true})
	t.SetupTool(&Tool{Name: "sh", Varname: "SH", Predefined: true})
	t.SetupVartypes()
	G.Mk = t.NewMkLines("x11/labltk/Makefile",
		MkRcsID,
		"CONFIGURE_ARGS+=\t-tklibs \"`${SH} -c '${ECHO} $$TK_LD_FLAGS'`\"")

	MkLineChecker{G.Mk.mklines[1]}.Check()

	// Don't suggest ${ECHO:Q} here.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__LDADD_in_BUILDLINK_TRANSFORM(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	G.Mk = t.NewMkLines("x11/qt5-qtbase/Makefile.common",
		"BUILDLINK_TRANSFORM+=opt:-ldl:${BUILDLINK_LDADD.dl:M*}")

	MkLineChecker{G.Mk.mklines[0]}.Check()

	// Note: The :M* modifier is not necessary, since this is not a GNU Configure package.
	t.CheckOutputLines(
		"WARN: x11/qt5-qtbase/Makefile.common:1: Please use ${BUILDLINK_LDADD.dl:Q} instead of ${BUILDLINK_LDADD.dl:M*}.")
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__command_in_message(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	G.Mk = t.NewMkLines("benchmarks/iozone/Makefile",
		"SUBST_MESSAGE.crlf=\tStripping EOL CR in ${REPLACE_PERL}")

	MkLineChecker{G.Mk.mklines[0]}.Check()

	// Don't suggest ${REPLACE_PERL:Q}.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__guessed_list_variable_in_quotes(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	G.Mk = t.NewMkLines("audio/jack-rack/Makefile",
		MkRcsID,
		"LADSPA_PLUGIN_PATH?=\t${PREFIX}/lib/ladspa",
		"CPPFLAGS+=\t\t-DLADSPA_PATH=\"\\\"${LADSPA_PLUGIN_PATH}\\\"\"")

	G.Mk.Check()

	t.CheckOutputLines(
		"WARN: audio/jack-rack/Makefile:3: The variable LADSPA_PLUGIN_PATH should be quoted as part of a shell word.")
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__list_in_list(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	G.Mk = t.NewMkLines("x11/eterm/Makefile",
		MkRcsID,
		"DISTFILES=\t${DEFAULT_DISTFILES} ${PIXMAP_FILES}")

	G.Mk.Check()

	t.CheckOutputEmpty() // Don't warn about missing :Q modifiers.
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__PKGNAME_and_URL_list_in_URL_list(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupMasterSite("MASTER_SITE_GNOME", "http://ftp.gnome.org/")
	t.SetupVartypes()
	G.Mk = t.NewMkLines("x11/gtk3/Makefile",
		MkRcsID,
		"MASTER_SITES=\tftp://ftp.gtk.org/${PKGNAME}/ ${MASTER_SITE_GNOME:=subdir/}")

	MkLineChecker{G.Mk.mklines[1]}.checkVarassignVaruse()

	t.CheckOutputEmpty() // Don't warn about missing :Q modifiers.
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__tool_in_CONFIGURE_ENV(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	G.Pkgsrc.Tools.RegisterVarname("tar", "TAR", dummyMkLine)
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"CONFIGURE_ENV+=\tSYS_TAR_COMMAND_PATH=${TOOLS_TAR:Q}")

	MkLineChecker{mklines.mklines[2]}.checkVarassignVaruse()

	// The TOOLS_* variables only contain the path to the tool,
	// without any additional arguments that might be necessary
	// for invoking the tool properly (e.g. touch -t).
	// Therefore, no quoting is necessary.
	t.CheckOutputLines(
		"NOTE: Makefile:3: The :Q operator isn't necessary for ${TOOLS_TAR} here.")
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__backticks(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	G.Pkgsrc.Tools.RegisterVarname("cat", "CAT", dummyMkLine)
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"COMPILE_CMD=\tcc `${CAT} ${WRKDIR}/compileflags`",
		"COMMENT_CMD=\techo `echo ${COMMENT}`")

	MkLineChecker{mklines.mklines[2]}.checkVarassignVaruse()
	MkLineChecker{mklines.mklines[3]}.checkVarassignVaruse()

	// Both CAT and WRKDIR are safe from quoting, therefore no warnings.
	// But COMMENT may contain arbitrary characters and therefore must
	// only appear completely unquoted. There is no practical way of
	// using it inside backticks, and luckily there is no need for it.
	t.CheckOutputLines(
		"WARN: Makefile:4: COMMENT may not be used in any file; it is a write-only variable.",
		"WARN: Makefile:4: The variable COMMENT should be quoted as part of a shell word.")
}

// For some well-known directory variables like WRKDIR, PREFIX, LOCALBASE,
// the :Q modifier can be safely removed since pkgsrc will never support
// having special characters in these directory names.
// For guessed variable types be cautious and don't autofix them.
func (s *Suite) Test_MkLine_variableNeedsQuoting__only_remove_known(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall", "--autofix")
	t.SetupVartypes()

	mklines := t.SetupFileMkLines("Makefile",
		MkRcsID,
		"",
		"demo: .PHONY",
		"\t${ECHO} ${WRKSRC:Q}",
		"\t${ECHO} ${FOODIR:Q}")

	mklines.Check()

	t.CheckOutputLines(
		"AUTOFIX: ~/Makefile:4: Replacing \"${WRKSRC:Q}\" with \"${WRKSRC}\".")
	t.CheckFileLines("Makefile",
		MkRcsID,
		"",
		"demo: .PHONY",
		"\t${ECHO} ${WRKSRC}",
		"\t${ECHO} ${FOODIR:Q}")
}

// TODO: COMPILER_RPATH_FLAG and LINKER_RPATH_FLAG have different types
// defined in vardefs.go; examine why.
func (s *Suite) Test_MkLine_variableNeedsQuoting__shellword_part(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall,no-space")
	t.SetupVartypes()

	mklines := t.SetupFileMkLines("Makefile",
		MkRcsID,
		"",
		"SUBST_CLASSES+=    class",
		"SUBST_STAGE.class= pre-configure",
		"SUBST_FILES.class= files",
		"SUBST_SED.class=-e s:@LINKER_RPATH_FLAG@:${LINKER_RPATH_FLAG}:g")

	mklines.Check()

	t.CheckOutputEmpty()
}

// Tools, when used in a shell command, must not be quoted.
func (s *Suite) Test_MkLine_variableNeedsQuoting__tool_in_shell_command(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall,no-space")
	t.SetupVartypes()
	t.SetupTool(&Tool{Varname: "BASH"})

	mklines := t.SetupFileMkLines("Makefile",
		MkRcsID,
		"",
		"CONFIG_SHELL= ${BASH}")

	mklines.Check()

	t.CheckOutputEmpty()
}

// These examples from real pkgsrc end up in the final nqDontKnow case.
func (s *Suite) Test_MkLine_variableNeedsQuoting__uncovered_cases(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall,no-space")
	t.SetupVartypes()

	mklines := t.SetupFileMkLines("Makefile",
		MkRcsID,
		"",
		"GO_SRCPATH=             ${HOMEPAGE:S,https://,,}",
		"LINKER_RPATH_FLAG:=     ${LINKER_RPATH_FLAG:S/-rpath/& /}",
		"HOMEPAGE=               http://godoc.org/${GO_SRCPATH}",
		"PATH:=                  ${PREFIX}/cross/bin:${PATH}",
		"NO_SRC_ON_FTP=          ${RESTRICTED}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/Makefile:4: The variable LINKER_RPATH_FLAG may not be set by any package.",
		"WARN: ~/Makefile:4: Please use ${LINKER_RPATH_FLAG:S/-rpath/& /:Q} instead of ${LINKER_RPATH_FLAG:S/-rpath/& /}.",
		"WARN: ~/Makefile:4: LINKER_RPATH_FLAG should not be evaluated at load time.")
}

func (s *Suite) Test_MkLine_Pkgmandir(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	G.Mk = t.NewMkLines("chat/ircII/Makefile",
		MkRcsID,
		"CONFIGURE_ARGS+=--mandir=${DESTDIR}${PREFIX}/man",
		"CONFIGURE_ARGS+=--mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}")

	G.Mk.Check()

	t.CheckOutputLines(
		"WARN: chat/ircII/Makefile:2: Please use ${PKGMANDIR} instead of \"man\".",
		"NOTE: chat/ircII/Makefile:2: This variable value should be aligned to column 25.",
		"NOTE: chat/ircII/Makefile:3: This variable value should be aligned to column 25.")
}

func (s *Suite) Test_MkLines_Check__VERSION_as_wordpart_in_MASTER_SITES(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	mklines := t.NewMkLines("geography/viking/Makefile",
		MkRcsID,
		"MASTER_SITES=\t${MASTER_SITE_SOURCEFORGE:=viking/}${VERSION}/")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: geography/viking/Makefile:2: " +
			"The list variable MASTER_SITE_SOURCEFORGE should not be embedded in a word.")
}

func (s *Suite) Test_MkLines_Check__shell_command_as_wordpart_in_ENV_list(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	mklines := t.NewMkLines("x11/lablgtk1/Makefile",
		MkRcsID,
		"CONFIGURE_ENV+=\tCC=${CC}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: x11/lablgtk1/Makefile:2: Please use ${CC:Q} instead of ${CC}.",
		"WARN: x11/lablgtk1/Makefile:2: Please use ${CC:Q} instead of ${CC}.")
}

func (s *Suite) Test_MkLine_shell_varuse_in_backt_dquot(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	mklines := t.NewMkLines("x11/motif/Makefile",
		MkRcsID,
		"post-patch:",
		"\tfiles=`${GREP} -l \".fB$${name}.fP(3)\" *.3`")

	mklines.Check()

	// Just ensure that there are no parse errors.
	t.CheckOutputLines(
		"WARN: x11/motif/Makefile:3: Unknown shell command \"${GREP}\".")
}

// See PR 46570, Ctrl+F "3. In lang/perl5".
func (s *Suite) Test_MkLine_VariableType(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()

	checkType := func(varname string, vartype string) {
		actualType := dummyMkLine.VariableType(varname)
		if vartype == "" {
			c.Check(actualType, check.IsNil)
		} else {
			if c.Check(actualType, check.NotNil) {
				c.Check(actualType.String(), equals, vartype)
			}
		}
	}

	checkType("_PERL5_PACKLIST_AWK_STRIP_DESTDIR", "")
	checkType("SOME_DIR", "Pathname (guessed)")
	checkType("SOMEDIR", "Pathname (guessed)")
	checkType("SEARCHPATHS", "ShellList of Pathname (guessed)")
	checkType("APACHE_USER", "UserGroupName (guessed)")
	checkType("APACHE_GROUP", "UserGroupName (guessed)")
	checkType("MY_CMD_ENV", "ShellList of ShellWord (guessed)")
	checkType("MY_CMD_ARGS", "ShellList of ShellWord (guessed)")
	checkType("MY_CMD_CFLAGS", "ShellList of CFlag (guessed)")
	checkType("PLIST.abcde", "Yes")
}

// PR 51696, security/py-pbkdf2/Makefile, r1.2
func (s *Suite) Test_MkLine__comment_in_comment(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"COMMENT=\tPKCS#5 v2.0 PBKDF2 Module")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:2: The # character starts a comment.")
}

func (s *Suite) Test_MkLine_ConditionalVars(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("Makefile", 45, ".include \"../../category/package/buildlink3.mk\"")

	c.Check(mkline.ConditionalVars(), equals, "")

	mkline.SetConditionalVars("OPSYS")

	c.Check(mkline.ConditionalVars(), equals, "OPSYS")
}

func (s *Suite) Test_MkLine_ValueSplit(c *check.C) {
	t := s.Init(c)

	checkSplit := func(value string, expected ...string) {
		mkline := t.NewMkLine("Makefile", 1, "PATH=\t"+value)
		split := mkline.ValueSplit(value, ":")
		c.Check(split, deepEquals, expected)
	}

	checkSplit("#empty",
		[]string(nil)...)

	checkSplit("/bin",
		"/bin")

	checkSplit("/bin:/sbin",
		"/bin",
		"/sbin")

	checkSplit("${DESTDIR}/bin:/bin/${SUBDIR}",
		"${DESTDIR}/bin",
		"/bin/${SUBDIR}")

	checkSplit("/bin:${DESTDIR}${PREFIX}:${DESTDIR:S,/,\\:,:S,:,:,}/sbin",
		"/bin",
		"${DESTDIR}${PREFIX}",
		"${DESTDIR:S,/,\\:,:S,:,:,}/sbin")
}

func (s *Suite) Test_MkLine_ResolveVarsInRelativePath(c *check.C) {
	t := s.Init(c)

	checkResolve := func(before string, after string) {
		c.Check(dummyMkLine.ResolveVarsInRelativePath(before, false), equals, after)
	}

	t.CreateFileLines("lang/lua53/Makefile")
	t.CreateFileLines("lang/php72/Makefile")
	t.CreateFileLines("emulators/suse100_base/Makefile")
	t.CreateFileLines("lang/python36/Makefile")

	checkResolve("", "")
	checkResolve("${LUA_PKGSRCDIR}", "../../lang/lua53")
	checkResolve("${PHPPKGSRCDIR}", "../../lang/php72")
	checkResolve("${SUSE_DIR_PREFIX}", "suse100")
	checkResolve("${PYPKGSRCDIR}", "../../lang/python36")
	checkResolve("${PYPACKAGE}", "python36")
	checkResolve("${FILESDIR}", "${FILESDIR}")
	checkResolve("${PKGDIR}", "${PKGDIR}")

	G.Pkg = NewPackage(t.File("category/package"))

	checkResolve("${FILESDIR}", "files")
	checkResolve("${PKGDIR}", ".")
}

func (s *Suite) Test_MatchVarassign(c *check.C) {
	s.Init(c)

	checkVarassign := func(text string, commented bool, varname, spaceAfterVarname, op, align, value, spaceAfterValue, comment string) {
		type VarAssign struct {
			commented                                                              bool
			varname, spaceAfterVarname, op, align, value, spaceAfterValue, comment string
		}
		expected := VarAssign{commented, varname, spaceAfterVarname, op, align, value, spaceAfterValue, comment}
		am, acommented, avarname, aspaceAfterVarname, aop, aalign, avalue, aspaceAfterValue, acomment := MatchVarassign(text)
		if !am {
			c.Errorf("Text %q doesn't match variable assignment", text)
			return
		}
		actual := VarAssign{acommented, avarname, aspaceAfterVarname, aop, aalign, avalue, aspaceAfterValue, acomment}
		c.Check(actual, equals, expected)
	}
	checkNotVarassign := func(text string) {
		m, _, _, _, _, _, _, _, _ := MatchVarassign(text)
		if m {
			c.Errorf("Text %q matches variable assignment, but shouldn't.", text)
		}
	}

	checkVarassign("C++=c11", false, "C+", "", "+=", "C++=", "c11", "", "")
	checkVarassign("V=v", false, "V", "", "=", "V=", "v", "", "")
	checkVarassign("VAR=#comment", false, "VAR", "", "=", "VAR=", "", "", "#comment")
	checkVarassign("VAR=\\#comment", false, "VAR", "", "=", "VAR=", "#comment", "", "")
	checkVarassign("VAR=\\\\\\##comment", false, "VAR", "", "=", "VAR=", "\\\\#", "", "#comment")
	checkVarassign("VAR=\\", false, "VAR", "", "=", "VAR=", "\\", "", "")
	checkVarassign("VAR += value", false, "VAR", " ", "+=", "VAR += ", "value", "", "")
	checkVarassign(" VAR=value", false, "VAR", "", "=", " VAR=", "value", "", "")
	checkVarassign("VAR=value #comment", false, "VAR", "", "=", "VAR=", "value", " ", "#comment")
	checkVarassign("#VAR=value", true, "VAR", "", "=", "#VAR=", "value", "", "")

	checkNotVarassign("\tVAR=value")
	checkNotVarassign("?=value")
	checkNotVarassign("<=value")
	checkNotVarassign("#")

	// A single space is typically used for writing documentation,
	// not for commenting out code.
	checkNotVarassign("# VAR=value")
}

func (s *Suite) Test_Indentation(c *check.C) {
	t := s.Init(c)

	ind := NewIndentation()

	mkline := t.NewMkLine("dummy.mk", 5, ".if 0")

	c.Check(ind.Depth("if"), equals, 0)
	c.Check(ind.DependsOn("VARNAME"), equals, false)

	ind.Push(mkline, 2, "")

	c.Check(ind.Depth("if"), equals, 0) // Because "if" is handled in MkLines.TrackBefore.
	c.Check(ind.Depth("endfor"), equals, 0)

	ind.AddVar("LEVEL1.VAR1")

	c.Check(ind.Varnames(), equals, "LEVEL1.VAR1")

	ind.AddVar("LEVEL1.VAR2")

	c.Check(ind.Varnames(), equals, "LEVEL1.VAR1, LEVEL1.VAR2")
	c.Check(ind.DependsOn("LEVEL1.VAR1"), equals, true)
	c.Check(ind.DependsOn("OTHER_VAR"), equals, false)

	ind.Push(mkline, 2, "")

	ind.AddVar("LEVEL2.VAR")

	c.Check(ind.Varnames(), equals, "LEVEL1.VAR1, LEVEL1.VAR2, LEVEL2.VAR")
	c.Check(ind.String(), equals, "[2 (LEVEL1.VAR1 LEVEL1.VAR2) 2 (LEVEL2.VAR)]")

	ind.Pop()

	c.Check(ind.Varnames(), equals, "LEVEL1.VAR1, LEVEL1.VAR2")
	c.Check(ind.IsConditional(), equals, true)

	ind.Pop()

	c.Check(ind.Varnames(), equals, "")
	c.Check(ind.IsConditional(), equals, false)
	c.Check(ind.String(), equals, "[]")
}

func (s *Suite) Test_Indentation_RememberUsedVariables(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("Makefile", 123, ".if ${PKGREVISION} > 0")
	ind := NewIndentation()
	cond := NewMkParser(mkline.Line, mkline.Args(), false)

	ind.RememberUsedVariables(cond.MkCond())

	t.CheckOutputEmpty()
	c.Check(ind.Varnames(), equals, "PKGREVISION")
}

func (s *Suite) Test_MkLine_ExtractUsedVariables(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("Makefile", 123, "")

	nestedVarnames := mkline.ExtractUsedVariables("${VAR.${param}}")

	// ExtractUsedVariables is very old code, should be more advanced.
	c.Check(nestedVarnames, check.IsNil)

	plainVarnames := mkline.ExtractUsedVariables("${VAR}and${VAR2}")

	c.Check(plainVarnames, deepEquals, []string{"VAR", "VAR2"})
}
