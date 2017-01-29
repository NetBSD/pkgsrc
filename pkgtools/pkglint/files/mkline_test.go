package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) Test_VaralignBlock_Check_autofix(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wspace", "-f")
	lines := s.NewLines("file.mk",
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
		"VAR=    \tvalue", // Mixed indentation 16, fixed to 8.
		"",                //
		"VAR=\tvalue")     // Already aligned with tabs only, left unchanged.

	varalign := &VaralignBlock{}
	for _, line := range lines {
		varalign.Check(NewMkLine(line))
	}
	varalign.Finish()

	c.Check(lines[0].IsChanged(), equals, true)
	c.Check(lines[0].(*LineImpl).raw[0].String(), equals, "1:VAR=\tvalue\n")
	c.Check(lines[2].IsChanged(), equals, true)
	c.Check(lines[2].(*LineImpl).raw[0].String(), equals, "3:VAR=\tvalue\n")
	c.Check(lines[4].IsChanged(), equals, true)
	c.Check(lines[4].(*LineImpl).raw[0].String(), equals, "5:VAR=\tvalue\n")
	c.Check(lines[6].IsChanged(), equals, true)
	c.Check(lines[6].(*LineImpl).raw[0].String(), equals, "7:VAR=\tvalue\n")
	c.Check(lines[8].IsChanged(), equals, true)
	c.Check(lines[8].(*LineImpl).raw[0].String(), equals, "9:VAR=\tvalue\n")
	c.Check(lines[10].IsChanged(), equals, true)
	c.Check(lines[10].(*LineImpl).raw[0].String(), equals, "11:VAR=\tvalue\n")
	c.Check(lines[12].IsChanged(), equals, false)
	c.Check(lines[12].(*LineImpl).raw[0].String(), equals, "13:VAR=\tvalue\n")
	c.Check(s.Output(), equals, ""+
		"NOTE: file.mk:1: This variable value should be aligned with tabs, not spaces, to column 9.\n"+
		"AUTOFIX: file.mk:1: Replacing \"VAR=   \" with \"VAR=\\t\".\n"+
		"NOTE: file.mk:3: Variable values should be aligned with tabs, not spaces.\n"+
		"AUTOFIX: file.mk:3: Replacing \"VAR=    \" with \"VAR=\\t\".\n"+
		"NOTE: file.mk:5: This variable value should be aligned with tabs, not spaces, to column 9.\n"+
		"AUTOFIX: file.mk:5: Replacing \"VAR=     \" with \"VAR=\\t\".\n"+
		"NOTE: file.mk:7: Variable values should be aligned with tabs, not spaces.\n"+
		"AUTOFIX: file.mk:7: Replacing \"VAR= \\t\" with \"VAR=\\t\".\n"+
		"NOTE: file.mk:9: Variable values should be aligned with tabs, not spaces.\n"+
		"AUTOFIX: file.mk:9: Replacing \"VAR=   \\t\" with \"VAR=\\t\".\n"+
		"NOTE: file.mk:11: This variable value should be aligned with tabs, not spaces, to column 9.\n"+
		"AUTOFIX: file.mk:11: Replacing \"VAR=    \\t\" with \"VAR=\\t\".\n")
}

func (s *Suite) Test_VaralignBlock_Check__reduce_indentation(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wspace")
	mklines := s.NewMkLines("file.mk",
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

	s.CheckOutputLines(
		"NOTE: file.mk:1: Variable values should be aligned with tabs, not spaces.",
		"NOTE: file.mk:2: This variable value should be aligned with tabs, not spaces, to column 9.",
		"NOTE: file.mk:3: This variable value should be aligned to column 9.")
}

func (s *Suite) Test_VaralignBlock_Check_longest_line_no_space(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wspace")
	mklines := s.NewMkLines("file.mk",
		"SUBST_CLASSES+= aaaaaaaa",
		"SUBST_STAGE.aaaaaaaa= pre-configure",
		"SUBST_FILES.aaaaaaaa= *.pl",
		"SUBST_FILTER_CMD.aaaaaaaa=cat")

	varalign := new(VaralignBlock)
	for _, mkline := range mklines.mklines {
		varalign.Check(mkline)
	}
	varalign.Finish()

	s.CheckOutputLines(
		"NOTE: file.mk:1: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:2: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:3: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:4: This variable value should be aligned to column 33.")
}

func (s *Suite) Test_VaralignBlock_Check_only_spaces(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wspace")
	mklines := s.NewMkLines("file.mk",
		"SUBST_CLASSES+= aaaaaaaa",
		"SUBST_STAGE.aaaaaaaa= pre-configure",
		"SUBST_FILES.aaaaaaaa= *.pl",
		"SUBST_FILTER_CMD.aaaaaaaa= cat")

	varalign := new(VaralignBlock)
	for _, mkline := range mklines.mklines {
		varalign.Check(mkline)
	}
	varalign.Finish()

	s.CheckOutputLines(
		"NOTE: file.mk:1: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:2: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:3: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:4: This variable value should be aligned with tabs, not spaces, to column 33.")
}

func (s *Suite) Test_NewMkLine(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wspace")
	mklines := NewMkLines(s.NewLines("test.mk",
		"VARNAME.param?=value # varassign comment",
		"\tshell command # shell comment",
		"# whole line comment",
		"",
		".  if !empty(PKGNAME:M*-*) # cond comment",
		".    include \"../../mk/bsd.prefs.mk\" # include comment",
		".    include <subdir.mk> # sysinclude comment",
		"target1 target2: source1 source2",
		"target : source",
		"VARNAME+=value"))
	ln := mklines.mklines

	c.Check(ln[0].IsVarassign(), equals, true)
	c.Check(ln[0].Varname(), equals, "VARNAME.param")
	c.Check(ln[0].Varcanon(), equals, "VARNAME.*")
	c.Check(ln[0].Varparam(), equals, "param")
	c.Check(ln[0].Op(), equals, opAssignDefault)
	c.Check(ln[0].Value(), equals, "value")
	c.Check(ln[0].VarassignComment(), equals, "# varassign comment")

	c.Check(ln[1].IsShellcmd(), equals, true)
	c.Check(ln[1].Shellcmd(), equals, "shell command # shell comment")

	c.Check(ln[2].IsComment(), equals, true)

	c.Check(ln[3].IsEmpty(), equals, true)

	c.Check(ln[4].IsCond(), equals, true)
	c.Check(ln[4].Indent(), equals, "  ")
	c.Check(ln[4].Directive(), equals, "if")
	c.Check(ln[4].Args(), equals, "!empty(PKGNAME:M*-*)")

	c.Check(ln[5].IsInclude(), equals, true)
	c.Check(ln[5].Indent(), equals, "    ")
	c.Check(ln[5].MustExist(), equals, true)
	c.Check(ln[5].Includefile(), equals, "../../mk/bsd.prefs.mk")

	c.Check(ln[6].IsSysinclude(), equals, true)
	c.Check(ln[6].Indent(), equals, "    ")
	c.Check(ln[6].MustExist(), equals, true)
	c.Check(ln[6].Includefile(), equals, "subdir.mk")

	c.Check(ln[7].IsDependency(), equals, true)
	c.Check(ln[7].Targets(), equals, "target1 target2")
	c.Check(ln[7].Sources(), equals, "source1 source2")

	c.Check(ln[9].IsVarassign(), equals, true)
	c.Check(ln[9].Varname(), equals, "VARNAME")
	c.Check(ln[9].Varcanon(), equals, "VARNAME")
	c.Check(ln[9].Varparam(), equals, "")

	s.CheckOutputLines(
		"WARN: test.mk:9: Space before colon in dependency line.")
}

func (s *Suite) Test_NewMkLine__autofix_space_after_varname(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wspace")
	fname := s.CreateTmpFileLines("Makefile",
		mkrcsid,
		"VARNAME +=\t${VARNAME}",
		"VARNAME+ =\t${VARNAME+}",
		"VARNAME+ +=\t${VARNAME+}",
		"pkgbase := pkglint")

	CheckfileMk(fname)

	s.CheckOutputLines(
		"WARN: ~/Makefile:2: Unnecessary space after variable name \"VARNAME\".",
		"WARN: ~/Makefile:4: Unnecessary space after variable name \"VARNAME+\".")

	s.UseCommandLine("-Wspace", "--autofix")

	CheckfileMk(fname)

	s.CheckOutputLines(
		"AUTOFIX: ~/Makefile:2: Replacing \"VARNAME +=\" with \"VARNAME+=\".",
		"AUTOFIX: ~/Makefile:4: Replacing \"VARNAME+ +=\" with \"VARNAME++=\".",
		"AUTOFIX: ~/Makefile: Has been auto-fixed. Please re-run pkglint.",
		"AUTOFIX: ~/Makefile: Has been auto-fixed. Please re-run pkglint.")
	c.Check(s.LoadTmpFile("Makefile"), equals, ""+
		mkrcsid+"\n"+
		"VARNAME+=\t${VARNAME}\n"+
		"VARNAME+ =\t${VARNAME+}\n"+
		"VARNAME++=\t${VARNAME+}\n"+
		"pkgbase := pkglint\n")
}

func (s *Suite) Test_MkLine_VariableType_varparam(c *check.C) {
	mkline := NewMkLine(NewLine("fname", 1, "# dummy", nil))
	G.globalData.InitVartypes()

	t1 := mkline.VariableType("FONT_DIRS")

	c.Assert(t1, check.NotNil)
	c.Check(t1.String(), equals, "ShellList of Pathmask")

	t2 := mkline.VariableType("FONT_DIRS.ttf")

	c.Assert(t2, check.NotNil)
	c.Check(t2.String(), equals, "ShellList of Pathmask")
}

func (s *Suite) Test_VarUseContext_String(c *check.C) {
	G.globalData.InitVartypes()
	mkline := NewMkLine(NewLine("fname", 1, "# dummy", nil))
	vartype := mkline.VariableType("PKGNAME")
	vuc := &VarUseContext{vartype, vucTimeUnknown, vucQuotBackt, false}

	c.Check(vuc.String(), equals, "(PkgName time:unknown quoting:backt wordpart:false)")
}

// In variable assignments, a plain '#' introduces a line comment, unless
// it is escaped by a backslash. In shell commands, on the other hand, it
// is interpreted literally.
func (s *Suite) Test_NewMkLine_numbersign(c *check.C) {
	s.Init(c)
	mklineVarassignEscaped := NewMkLine(NewLine("fname", 1, "SED_CMD=\t's,\\#,hash,g'", nil))

	c.Check(mklineVarassignEscaped.Varname(), equals, "SED_CMD")
	c.Check(mklineVarassignEscaped.Value(), equals, "'s,#,hash,g'")

	mklineCommandEscaped := NewMkLine(NewLine("fname", 1, "\tsed -e 's,\\#,hash,g'", nil))

	c.Check(mklineCommandEscaped.Shellcmd(), equals, "sed -e 's,\\#,hash,g'")

	// From shells/zsh/Makefile.common, rev. 1.78
	mklineCommandUnescaped := NewMkLine(NewLine("fname", 1, "\t# $ sha1 patches/patch-ac", nil))

	c.Check(mklineCommandUnescaped.Shellcmd(), equals, "# $ sha1 patches/patch-ac")
	s.CheckOutputEmpty() // No warning about parsing the lonely dollar sign.

	mklineVarassignUnescaped := NewMkLine(NewLine("fname", 1, "SED_CMD=\t's,#,hash,'", nil))

	c.Check(mklineVarassignUnescaped.Value(), equals, "'s,")
	s.CheckOutputLines(
		"WARN: fname:1: The # character starts a comment.")
}

func (s *Suite) Test_NewMkLine_leading_space(c *check.C) {
	s.Init(c)
	_ = NewMkLine(NewLine("rubyversion.mk", 427, " _RUBYVER=\t2.15", nil))

	s.CheckOutputLines(
		"WARN: rubyversion.mk:427: Makefile lines should not start with space characters.")
}

func (s *Suite) Test_MkLines_Check__extra(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wextra")
	G.globalData.InitVartypes()
	G.Pkg = NewPackage("category/pkgbase")
	G.Mk = s.NewMkLines("options.mk",
		mkrcsid,
		".for word in ${PKG_FAIL_REASON}",
		"PYTHON_VERSIONS_ACCEPTED=\t27 35 30",
		"CONFIGURE_ARGS+=\t--sharedir=${PREFIX}/share/kde",
		"COMMENT=\t# defined",
		".endfor",
		"GAMES_USER?=pkggames",
		"PLIST_SUBST+= CONDITIONAL=${CONDITIONAL}",
		"CONDITIONAL=\"@comment\"",
		"BUILD_DIRS=\t${WRKSRC}/../build")

	G.Mk.Check()

	s.CheckOutputLines(
		"WARN: options.mk:3: The values for PYTHON_VERSIONS_ACCEPTED should be in decreasing order.",
		"NOTE: options.mk:4: Please .include \"../../meta-pkgs/kde3/kde3.mk\" instead of this line.",
		"NOTE: options.mk:5: Please use \"# empty\", \"# none\" or \"yes\" instead of \"# defined\".",
		"WARN: options.mk:7: Please include \"../../mk/bsd.prefs.mk\" before using \"?=\".",
		"WARN: options.mk:10: Building the package should take place entirely inside ${WRKSRC}, not \"${WRKSRC}/..\".",
		"NOTE: options.mk:10: You can use \"../build\" instead of \"${WRKSRC}/../build\".")
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__unknown_rhs(c *check.C) {
	mkline := NewMkLine(NewLine("fname", 1, "PKGNAME := ${UNKNOWN}", nil))
	G.globalData.InitVartypes()

	vuc := &VarUseContext{G.globalData.vartypes["PKGNAME"], vucTimeParse, vucQuotUnknown, false}
	nq := mkline.VariableNeedsQuoting("UNKNOWN", nil, vuc)

	c.Check(nq, equals, nqDontKnow)
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__append_URL_to_list_of_URLs(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	s.RegisterMasterSite("MASTER_SITE_SOURCEFORGE", "http://downloads.sourceforge.net/sourceforge/")
	mkline := NewMkLine(NewLine("Makefile", 95, "MASTER_SITES=\t${HOMEPAGE}", nil))

	vuc := &VarUseContext{G.globalData.vartypes["MASTER_SITES"], vucTimeRun, vucQuotPlain, false}
	nq := mkline.VariableNeedsQuoting("HOMEPAGE", G.globalData.vartypes["HOMEPAGE"], vuc)

	c.Check(nq, equals, nqNo)

	MkLineChecker{mkline}.checkVarassign()

	s.CheckOutputEmpty() // Up to pkglint 5.3.6, it warned about a missing :Q here, which was wrong.
}

// Assigning lists to lists is ok.
func (s *Suite) Test_MkLine_variableNeedsQuoting__append_list_to_list(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	s.RegisterMasterSite("MASTER_SITE_SOURCEFORGE", "http://downloads.sourceforge.net/sourceforge/")
	mkline := NewMkLine(NewLine("Makefile", 96, "MASTER_SITES=\t${MASTER_SITE_SOURCEFORGE:=squirrel-sql/}", nil))

	MkLineChecker{mkline}.checkVarassign()

	s.CheckOutputEmpty()
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__eval_shell(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	mkline := NewMkLine(NewLine("builtin.mk", 3, "USE_BUILTIN.Xfixes!=\t${PKG_ADMIN} pmatch 'pkg-[0-9]*' ${BUILTIN_PKG.Xfixes:Q}", nil))

	MkLineChecker{mkline}.checkVarassign()

	s.CheckOutputLines(
		"WARN: builtin.mk:3: PKG_ADMIN should not be evaluated at load time.",
		"NOTE: builtin.mk:3: The :Q operator isn't necessary for ${BUILTIN_PKG.Xfixes} here.")
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__command_in_single_quotes(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	mkline := NewMkLine(NewLine("Makefile", 3, "SUBST_SED.hpath=\t-e 's|^\\(INSTALL[\t:]*=\\).*|\\1${INSTALL}|'", nil))

	MkLineChecker{mkline}.checkVarassign()

	s.CheckOutputLines(
		"WARN: Makefile:3: Please use ${INSTALL:Q} instead of ${INSTALL} and make sure the variable appears outside of any quoting characters.")
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__command_in_command(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	s.RegisterTool(&Tool{Name: "find", Varname: "FIND", Predefined: true})
	s.RegisterTool(&Tool{Name: "sort", Varname: "SORT", Predefined: true})
	G.Pkg = NewPackage("category/pkgbase")
	G.Mk = s.NewMkLines("Makefile",
		mkrcsid,
		"GENERATE_PLIST= cd ${DESTDIR}${PREFIX}; ${FIND} * \\( -type f -or -type l \\) | ${SORT};")

	G.Mk.DetermineDefinedVariables()
	MkLineChecker{G.Mk.mklines[1]}.Check()

	s.CheckOutputLines(
		"WARN: Makefile:2: The exitcode of the left-hand-side command of the pipe operator is ignored.")
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__word_as_part_of_word(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("Makefile",
		mkrcsid,
		"EGDIR=\t${EGDIR}/${MACHINE_GNU_PLATFORM}")

	MkLineChecker{G.Mk.mklines[1]}.Check()

	s.CheckOutputEmpty()
}

// As an argument to ${ECHO}, the :Q modifier should be used, but pkglint
// currently does not know all shell commands and how they handle their
// arguments. As an argument to xargs(1), the :Q modifier would be misplaced,
// therefore no warning is issued.
//
// Based on graphics/circos/Makefile.
func (s *Suite) Test_MkLine_variableNeedsQuoting__command_as_command_argument(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	s.RegisterTool(&Tool{Name: "perl", Varname: "PERL5", Predefined: true})
	s.RegisterTool(&Tool{Name: "bash", Varname: "BASH", Predefined: true})
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("Makefile",
		mkrcsid,
		"\t${RUN} cd ${WRKSRC} && ( ${ECHO} ${PERL5:Q} ; ${ECHO} ) | ${BASH} ./install",
		"\t${RUN} cd ${WRKSRC} && ( ${ECHO} ${PERL5} ; ${ECHO} ) | ${BASH} ./install")

	MkLineChecker{G.Mk.mklines[1]}.Check()
	MkLineChecker{G.Mk.mklines[2]}.Check()

	s.CheckOutputLines(
		"WARN: Makefile:2: The exitcode of the left-hand-side command of the pipe operator is ignored.",
		"WARN: Makefile:3: The exitcode of the left-hand-side command of the pipe operator is ignored.")
}

// Based on mail/mailfront/Makefile.
func (s *Suite) Test_MkLine_variableNeedsQuoting__URL_as_part_of_word_in_list(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("Makefile",
		mkrcsid,
		"MASTER_SITES=${HOMEPAGE}archive/")

	MkLineChecker{G.Mk.mklines[1]}.Check()

	s.CheckOutputEmpty() // Don't suggest to use ${HOMEPAGE:Q}.
}

// Pkglint currently does not parse $$(subshell) commands very well. As
// a side effect, it sometimes issues wrong warnings about the :Q
// modifier.
//
// Based on www/firefox31/xpi.mk.
func (s *Suite) Test_MkLine_variableNeedsQuoting__command_in_subshell(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	s.RegisterTool(&Tool{Name: "awk", Varname: "AWK", Predefined: true})
	s.RegisterTool(&Tool{Name: "echo", Varname: "ECHO", Predefined: true})
	G.Mk = s.NewMkLines("xpi.mk",
		mkrcsid,
		"\t id=$$(${AWK} '{print}' < ${WRKSRC}/idfile) && echo \"$$id\"",
		"\t id=`${AWK} '{print}' < ${WRKSRC}/idfile` && echo \"$$id\"")

	MkLineChecker{G.Mk.mklines[1]}.Check()
	MkLineChecker{G.Mk.mklines[2]}.Check()

	s.CheckOutputLines(
		"WARN: xpi.mk:2: Invoking subshells via $(...) is not portable enough.") // Don't suggest to use ${AWK:Q}.
}

// LDFLAGS (and even more so CPPFLAGS and CFLAGS) may contain special
// shell characters like quotes or backslashes. Therefore, quoting them
// correctly is more tricky than with other variables.
func (s *Suite) Test_MkLine_variableNeedsQuoting__LDFLAGS_in_single_quotes(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("x11/mlterm/Makefile",
		mkrcsid,
		"SUBST_SED.link=-e 's|(LIBTOOL_LINK).*(LIBS)|& ${LDFLAGS:M*:Q}|g'",
		"SUBST_SED.link=-e 's|(LIBTOOL_LINK).*(LIBS)|& '${LDFLAGS:M*:Q}'|g'")

	MkLineChecker{G.Mk.mklines[1]}.Check()
	MkLineChecker{G.Mk.mklines[2]}.Check()

	s.CheckOutputLines(
		"WARN: x11/mlterm/Makefile:2: Please move ${LDFLAGS:M*:Q} outside of any quoting characters.")
}

func (s *Suite) Test_MkLines_Check__MASTER_SITE_in_HOMEPAGE(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	s.RegisterMasterSite("MASTER_SITE_GITHUB", "https://github.com/")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("devel/catch/Makefile",
		mkrcsid,
		"HOMEPAGE=\t${MASTER_SITE_GITHUB:=philsquared/Catch/}",
		"HOMEPAGE=\t${MASTER_SITE_GITHUB}",
		"HOMEPAGE=\t${MASTER_SITES}",
		"HOMEPAGE=\t${MASTER_SITES}${GITHUB_PROJECT}")

	G.Mk.Check()

	s.CheckOutputLines(
		"WARN: devel/catch/Makefile:2: HOMEPAGE should not be defined in terms of MASTER_SITEs. Use https://github.com/philsquared/Catch/ directly.",
		"WARN: devel/catch/Makefile:3: HOMEPAGE should not be defined in terms of MASTER_SITEs. Use https://github.com/ directly.",
		"WARN: devel/catch/Makefile:4: HOMEPAGE should not be defined in terms of MASTER_SITEs.",
		"WARN: devel/catch/Makefile:5: HOMEPAGE should not be defined in terms of MASTER_SITEs.")
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__tool_in_quotes_in_subshell_in_shellwords(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	s.RegisterTool(&Tool{Name: "echo", Varname: "ECHO", Predefined: true})
	s.RegisterTool(&Tool{Name: "sh", Varname: "SH", Predefined: true})
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("x11/labltk/Makefile",
		mkrcsid,
		"CONFIGURE_ARGS+=\t-tklibs \"`${SH} -c '${ECHO} $$TK_LD_FLAGS'`\"")

	MkLineChecker{G.Mk.mklines[1]}.Check()

	s.CheckOutputEmpty() // Don't suggest ${ECHO:Q} here.
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__LDADD_in_BUILDLINK_TRANSFORM(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("x11/qt5-qtbase/Makefile.common",
		"BUILDLINK_TRANSFORM+=opt:-ldl:${BUILDLINK_LDADD.dl:M*}")

	MkLineChecker{G.Mk.mklines[0]}.Check()

	// Note: The :M* modifier is not necessary, since this is not a GNU Configure package.
	s.CheckOutputLines(
		"WARN: x11/qt5-qtbase/Makefile.common:1: Please use ${BUILDLINK_LDADD.dl:Q} instead of ${BUILDLINK_LDADD.dl:M*}.")
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__command_in_message(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("benchmarks/iozone/Makefile",
		"SUBST_MESSAGE.crlf=\tStripping EOL CR in ${REPLACE_PERL}")

	MkLineChecker{G.Mk.mklines[0]}.Check()

	s.CheckOutputEmpty() // Don't suggest ${REPLACE_PERL:Q}.
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__guessed_list_variable_in_quotes(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("audio/jack-rack/Makefile",
		mkrcsid,
		"LADSPA_PLUGIN_PATH?=\t${PREFIX}/lib/ladspa",
		"CPPFLAGS+=\t\t-DLADSPA_PATH=\"\\\"${LADSPA_PLUGIN_PATH}\\\"\"")

	G.Mk.Check()

	s.CheckOutputLines(
		"WARN: audio/jack-rack/Makefile:3: The list variable LADSPA_PLUGIN_PATH should not be embedded in a word.")
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__list_in_list(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("x11/eterm/Makefile",
		mkrcsid,
		"DISTFILES=\t${DEFAULT_DISTFILES} ${PIXMAP_FILES}")

	G.Mk.Check()

	s.CheckOutputEmpty() // Don't warn about missing :Q modifiers.
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__PKGNAME_and_URL_list_in_URL_list(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	s.RegisterMasterSite("MASTER_SITE_GNOME", "http://ftp.gnome.org/")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("x11/gtk3/Makefile",
		mkrcsid,
		"MASTER_SITES=\tftp://ftp.gtk.org/${PKGNAME}/ ${MASTER_SITE_GNOME:=subdir/}")

	MkLineChecker{G.Mk.mklines[1]}.checkVarassignVaruse()

	s.CheckOutputEmpty() // Don't warn about missing :Q modifiers.
}

func (s *Suite) Test_MkLine_variableNeedsQuoting__tool_in_CONFIGURE_ENV(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	G.globalData.Tools = NewToolRegistry()
	G.globalData.Tools.RegisterVarname("tar", "TAR")

	mklines := s.NewMkLines("Makefile",
		mkrcsid,
		"",
		"CONFIGURE_ENV+=\tSYS_TAR_COMMAND_PATH=${TOOLS_TAR:Q}")

	MkLineChecker{mklines.mklines[2]}.checkVarassignVaruse()

	// The TOOLS_* variables only contain the path to the tool,
	// without any additional arguments that might be necessary.
	s.CheckOutputLines(
		"NOTE: Makefile:3: The :Q operator isn't necessary for ${TOOLS_TAR} here.")
}

func (s *Suite) Test_MkLine_Pkgmandir(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("chat/ircII/Makefile",
		mkrcsid,
		"CONFIGURE_ARGS+=--mandir=${DESTDIR}${PREFIX}/man",
		"CONFIGURE_ARGS+=--mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}")

	G.Mk.Check()

	s.CheckOutputLines(
		"WARN: chat/ircII/Makefile:2: Please use ${PKGMANDIR} instead of \"man\".")
}

func (s *Suite) Test_MkLines_Check__VERSION_as_wordpart_in_MASTER_SITES(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("geography/viking/Makefile",
		mkrcsid,
		"MASTER_SITES=\t${MASTER_SITE_SOURCEFORGE:=viking/}${VERSION}/")

	mklines.Check()

	c.Check(s.Output(), equals, "WARN: geography/viking/Makefile:2: "+
		"The list variable MASTER_SITE_SOURCEFORGE should not be embedded in a word.\n")
}

func (s *Suite) Test_MkLines_Check__shell_command_as_wordpart_in_ENV_list(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("x11/lablgtk1/Makefile",
		mkrcsid,
		"CONFIGURE_ENV+=\tCC=${CC}")

	mklines.Check()

	s.CheckOutputLines(
		"WARN: x11/lablgtk1/Makefile:2: Please use ${CC:Q} instead of ${CC}.",
		"WARN: x11/lablgtk1/Makefile:2: Please use ${CC:Q} instead of ${CC}.")
}

func (s *Suite) Test_MkLine_shell_varuse_in_backt_dquot(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("x11/motif/Makefile",
		mkrcsid,
		"post-patch:",
		"\tfiles=`${GREP} -l \".fB$${name}.fP(3)\" *.3`")

	mklines.Check()

	s.CheckOutputLines(
		"WARN: x11/motif/Makefile:3: Unknown shell command \"${GREP}\".") // No parse errors.
}

// See PR 46570, Ctrl+F "3. In lang/perl5".
func (s *Suite) Test_MkLine_VariableType(c *check.C) {
	mkline := NewMkLine(dummyLine)

	c.Check(mkline.VariableType("_PERL5_PACKLIST_AWK_STRIP_DESTDIR"), check.IsNil)
	c.Check(mkline.VariableType("SOME_DIR").guessed, equals, true)
	c.Check(mkline.VariableType("SOMEDIR").guessed, equals, true)
}

// PR 51696, security/py-pbkdf2/Makefile, r1.2
func (s *Suite) Test_MkLine__comment_in_comment(c *check.C) {
	s.Init(c)
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("Makefile",
		mkrcsid,
		"COMMENT=\tPKCS#5 v2.0 PBKDF2 Module")

	mklines.Check()

	s.CheckOutputLines(
		"WARN: Makefile:2: The # character starts a comment.")
}

func (s *Suite) Test_MkLine_ConditionVars(c *check.C) {
	s.Init(c)
	var mkline MkLine = NewMkLine(NewLine("Makefile", 45, ".include \"../../category/package/buildlink3.mk\"", nil))

	c.Check(mkline.ConditionVars(), equals, "")

	mkline.SetConditionVars("OPSYS")

	c.Check(mkline.ConditionVars(), equals, "OPSYS")
}

func (s *Suite) Test_MatchVarassign(c *check.C) {
	s.Init(c)
	checkVarassign := func(text string, ck check.Checker, varname, spaceAfterVarname, op, align, value, spaceAfterValue, comment string) {
		type va struct {
			varname, spaceAfterVarname, op, align, value, spaceAfterValue, comment string
		}
		expected := va{varname, spaceAfterVarname, op, align, value, spaceAfterValue, comment}
		am, avarname, aspaceAfterVarname, aop, aalign, avalue, aspaceAfterValue, acomment := MatchVarassign(text)
		if !am {
			c.Errorf("Text %q doesn't match variable assignment", text)
			return
		}
		actual := va{avarname, aspaceAfterVarname, aop, aalign, avalue, aspaceAfterValue, acomment}
		c.Check(actual, ck, expected)
	}
	checkNotVarassign := func(text string) {
		m, _, _, _, _, _, _, _ := MatchVarassign(text)
		if m {
			c.Errorf("Text %q matches variable assignment, but shouldn't.", text)
		}
	}

	checkVarassign("C++=c11", equals, "C+", "", "+=", "C++=", "c11", "", "")
	checkVarassign("V=v", equals, "V", "", "=", "V=", "v", "", "")
	checkVarassign("VAR=#comment", equals, "VAR", "", "=", "VAR=", "", "", "#comment")
	checkVarassign("VAR=\\#comment", equals, "VAR", "", "=", "VAR=", "#comment", "", "")
	checkVarassign("VAR=\\\\\\##comment", equals, "VAR", "", "=", "VAR=", "\\\\#", "", "#comment")
	checkVarassign("VAR=\\", equals, "VAR", "", "=", "VAR=", "\\", "", "")
	checkVarassign("VAR += value", equals, "VAR", " ", "+=", "VAR += ", "value", "", "")
	checkVarassign(" VAR=value", equals, "VAR", "", "=", " VAR=", "value", "", "")
	checkVarassign("VAR=value #comment", equals, "VAR", "", "=", "VAR=", "value", " ", "#comment")
	checkNotVarassign("\tVAR=value")
	checkNotVarassign("?=value")
	checkNotVarassign("<=value")
}

func (s *Suite) Test_Indentation(c *check.C) {
	ind := &Indentation{}

	ind.Push(0)

	c.Check(ind.Depth(), equals, 0)
	c.Check(ind.DependsOn("VARNAME"), equals, false)

	ind.Push(2)

	c.Check(ind.Depth(), equals, 2)

	ind.AddVar("LEVEL1.VAR1")

	c.Check(ind.Varnames(), equals, "LEVEL1.VAR1")

	ind.AddVar("LEVEL1.VAR2")

	c.Check(ind.Varnames(), equals, "LEVEL1.VAR1, LEVEL1.VAR2")
	c.Check(ind.DependsOn("LEVEL1.VAR1"), equals, true)
	c.Check(ind.DependsOn("OTHER_VAR"), equals, false)

	ind.Push(2)

	ind.AddVar("LEVEL2.VAR")

	c.Check(ind.Varnames(), equals, "LEVEL1.VAR1, LEVEL1.VAR2, LEVEL2.VAR")

	ind.Pop()

	c.Check(ind.Varnames(), equals, "LEVEL1.VAR1, LEVEL1.VAR2")
	c.Check(ind.IsConditional(), equals, true)

	ind.Pop()

	c.Check(ind.Varnames(), equals, "")
	c.Check(ind.IsConditional(), equals, false)

}
