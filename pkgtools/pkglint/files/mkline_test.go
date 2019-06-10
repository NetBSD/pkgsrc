package pkglint

import (
	"gopkg.in/check.v1"
	"strings"
)

func (s *Suite) Test_MkLineParser_Parse__varassign(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("test.mk", 101,
		"VARNAME.param?=value # varassign comment")

	c.Check(mkline.IsVarassign(), equals, true)
	c.Check(mkline.Varname(), equals, "VARNAME.param")
	c.Check(mkline.Varcanon(), equals, "VARNAME.*")
	c.Check(mkline.Varparam(), equals, "param")
	c.Check(mkline.Op(), equals, opAssignDefault)
	c.Check(mkline.Value(), equals, "value")
	c.Check(mkline.VarassignComment(), equals, "# varassign comment")
}

func (s *Suite) Test_MkLineParser_Parse__varassign_space_around_operator(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--show-autofix", "--source")
	t.NewMkLine("test.mk", 101,
		"pkgbase = package")

	t.CheckOutputLines(
		"NOTE: test.mk:101: Unnecessary space after variable name \"pkgbase\".",
		"AUTOFIX: test.mk:101: Replacing \"pkgbase =\" with \"pkgbase=\".",
		"-\tpkgbase = package",
		"+\tpkgbase= package")
}

func (s *Suite) Test_MkLineParser_Parse__shellcmd(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("test.mk", 101,
		"\tshell command # shell comment")

	c.Check(mkline.IsShellCommand(), equals, true)
	c.Check(mkline.ShellCommand(), equals, "shell command # shell comment")
}

func (s *Suite) Test_MkLineParser_Parse__comment(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("test.mk", 101,
		"# whole line comment")

	c.Check(mkline.IsComment(), equals, true)
}

func (s *Suite) Test_MkLineParser_Parse__empty(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("test.mk", 101, "")

	c.Check(mkline.IsEmpty(), equals, true)
}

func (s *Suite) Test_MkLineParser_Parse__directive(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("test.mk", 101,
		".  if !empty(PKGNAME:M*-*) && ${RUBY_RAILS_SUPPORTED:[\\#]} == 1 # directive comment")

	c.Check(mkline.IsDirective(), equals, true)
	c.Check(mkline.Indent(), equals, "  ")
	c.Check(mkline.Directive(), equals, "if")
	c.Check(mkline.Args(), equals, "!empty(PKGNAME:M*-*) && ${RUBY_RAILS_SUPPORTED:[#]} == 1")
	c.Check(mkline.DirectiveComment(), equals, "directive comment")
}

func (s *Suite) Test_MkLineParser_Parse__include(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("test.mk", 101,
		".    include \"../../mk/bsd.prefs.mk\" # include comment")

	c.Check(mkline.IsInclude(), equals, true)
	c.Check(mkline.Indent(), equals, "    ")
	c.Check(mkline.MustExist(), equals, true)
	c.Check(mkline.IncludedFile(), equals, "../../mk/bsd.prefs.mk")

	c.Check(mkline.IsSysinclude(), equals, false)
}

func (s *Suite) Test_MkLineParser_Parse__sysinclude(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("test.mk", 101,
		".    include <subdir.mk> # sysinclude comment")

	c.Check(mkline.IsSysinclude(), equals, true)
	c.Check(mkline.Indent(), equals, "    ")
	c.Check(mkline.MustExist(), equals, true)
	c.Check(mkline.IncludedFile(), equals, "subdir.mk")

	c.Check(mkline.IsInclude(), equals, false)
}

func (s *Suite) Test_MkLineParser_Parse__dependency(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("test.mk", 101,
		"target1 target2: source1 source2")

	c.Check(mkline.IsDependency(), equals, true)
	c.Check(mkline.Targets(), equals, "target1 target2")
	c.Check(mkline.Sources(), equals, "source1 source2")
}

func (s *Suite) Test_MkLineParser_Parse__dependency_space(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("test.mk", 101,
		"target : source")

	c.Check(mkline.Targets(), equals, "target")
	c.Check(mkline.Sources(), equals, "source")
	t.CheckOutputLines(
		"NOTE: test.mk:101: Space before colon in dependency line.")
}

func (s *Suite) Test_MkLineParser_Parse__varassign_append(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("test.mk", 101,
		"VARNAME+=value")

	c.Check(mkline.IsVarassign(), equals, true)
	c.Check(mkline.Varname(), equals, "VARNAME")
	c.Check(mkline.Varcanon(), equals, "VARNAME")
	c.Check(mkline.Varparam(), equals, "")
}

func (s *Suite) Test_MkLineParser_Parse__merge_conflict(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("test.mk", 101,
		"<<<<<<<<<<<<<<<<<")

	// Merge conflicts are of neither type.
	c.Check(mkline.IsVarassign(), equals, false)
	c.Check(mkline.IsDirective(), equals, false)
	c.Check(mkline.IsInclude(), equals, false)
	c.Check(mkline.IsEmpty(), equals, false)
	c.Check(mkline.IsComment(), equals, false)
	c.Check(mkline.IsDependency(), equals, false)
	c.Check(mkline.IsShellCommand(), equals, false)
	c.Check(mkline.IsSysinclude(), equals, false)
}

func (s *Suite) Test_MkLineParser_Parse__autofix_space_after_varname(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wspace")
	filename := t.CreateFileLines("Makefile",
		MkRcsID,
		"VARNAME +=\t${VARNAME}",
		"VARNAME+ =\t${VARNAME+}",
		"VARNAME+ +=\t${VARNAME+}",
		"VARNAME+ ?=\t${VARNAME}",
		"pkgbase := pkglint")

	CheckFileMk(filename)

	t.CheckOutputLines(
		"NOTE: ~/Makefile:2: Unnecessary space after variable name \"VARNAME\".",

		// The assignment operators other than = and += cannot lead to ambiguities.
		"NOTE: ~/Makefile:5: Unnecessary space after variable name \"VARNAME+\".")

	t.SetUpCommandLine("-Wspace", "--autofix")

	CheckFileMk(filename)

	t.CheckOutputLines(
		"AUTOFIX: ~/Makefile:2: Replacing \"VARNAME +=\" with \"VARNAME+=\".",
		"AUTOFIX: ~/Makefile:5: Replacing \"VARNAME+ ?=\" with \"VARNAME+?=\".")
	t.CheckFileLines("Makefile",
		MkRcsID+"",
		"VARNAME+=\t${VARNAME}",
		"VARNAME+ =\t${VARNAME+}",
		"VARNAME+ +=\t${VARNAME+}",
		"VARNAME+?=\t${VARNAME}",
		"pkgbase := pkglint")
}

func (s *Suite) Test_MkLineParser_Parse__varname_with_hash(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("Makefile", 123, "VARNAME.#=\tvalue")

	// Parse error because the # starts a comment.
	c.Check(mkline.IsVarassign(), equals, false)

	mkline2 := t.NewMkLine("Makefile", 124, "VARNAME.\\#=\tvalue")

	c.Check(mkline2.IsVarassign(), equals, true)
	c.Check(mkline2.Varname(), equals, "VARNAME.#")

	t.CheckOutputLines(
		"ERROR: Makefile:123: Unknown Makefile line format: \"VARNAME.#=\\tvalue\".")
}

// Ensures that pkglint parses escaped # characters in the same way as bmake.
//
// To check that bmake parses them the same, set a breakpoint after the t.NewMkLines
// and look in t.tmpdir for the location of the file. Then run bmake with that file.
func (s *Suite) Test_MkLineParser_Parse__escaped_hash_in_value(c *check.C) {
	t := s.Init(c)

	mklines := t.SetUpFileMkLines("Makefile",
		"VAR0=\tvalue#",
		"VAR1=\tvalue\\#",
		"VAR2=\tvalue\\\\#",
		"VAR3=\tvalue\\\\\\#",
		"VAR4=\tvalue\\\\\\\\#",
		"",
		"all:",
		".for var in VAR0 VAR1 VAR2 VAR3 VAR4",
		"\t@printf '%s\\n' ${${var}}''",
		".endfor")
	parsed := mklines.mklines

	c.Check(parsed[0].Value(), equals, "value")
	c.Check(parsed[1].Value(), equals, "value#")
	c.Check(parsed[2].Value(), equals, "value\\\\")
	c.Check(parsed[3].Value(), equals, "value\\\\#")
	c.Check(parsed[4].Value(), equals, "value\\\\\\\\")

	t.CheckOutputLines(
		"WARN: ~/Makefile:1: The # character starts a Makefile comment.",
		"WARN: ~/Makefile:3: The # character starts a Makefile comment.",
		"WARN: ~/Makefile:5: The # character starts a Makefile comment.")
}

func (s *Suite) Test_MkLine_Varparam(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("Makefile", 2, "SUBST_SED.${param}=\tvalue")

	varparam := mkline.Varparam()

	c.Check(varparam, equals, "${param}")
}

func (s *Suite) Test_MkLine_ValueAlign__commented(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("Makefile", 2, "#SUBST_SED.${param}=\tvalue")

	valueAlign := mkline.ValueAlign()

	c.Check(mkline.IsCommentedVarassign(), equals, true)
	c.Check(valueAlign, equals, "#SUBST_SED.${param}=\t")
}

func (s *Suite) Test_MkLine_FirstLineContainsValue(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		MkRcsID,
		"VAR=\tvalue",
		"VAR= value \\",
		"\tstarts in first line",
		"VAR= \\",
		"\tvalue starts in second line",
		"#VAR= value \\",
		"\tstarts in first line",
		"#VAR= \\",
		"\tvalue starts in second line")

	t.ExpectPanic(
		func() { mklines.mklines[0].FirstLineContainsValue() },
		"Pkglint internal error: Line must be a variable assignment.")

	t.ExpectPanic(
		func() { mklines.mklines[1].FirstLineContainsValue() },
		"Pkglint internal error: Line must be multiline.")

	t.Check(mklines.mklines[2].FirstLineContainsValue(), equals, true)
	t.Check(mklines.mklines[3].FirstLineContainsValue(), equals, false)
	t.Check(mklines.mklines[4].FirstLineContainsValue(), equals, true)
	t.Check(mklines.mklines[5].FirstLineContainsValue(), equals, false)
}

// Demonstrates how a simple condition is structured internally.
// For most of the checks, using cond.Walk is the simplest way to go.
func (s *Suite) Test_MkLine_Cond(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("Makefile", 2, ".if ${VAR} == Value")

	cond := mkline.Cond()

	c.Check(cond.CompareVarStr.Var.varname, equals, "VAR")
	c.Check(cond.CompareVarStr.Str, equals, "Value")
	c.Check(mkline.Cond(), equals, cond)
}

func (s *Suite) Test_VarUseContext_String(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	vartype := G.Pkgsrc.VariableType(nil, "PKGNAME")
	vuc := VarUseContext{vartype, vucTimeUnknown, VucQuotBackt, false}

	c.Check(vuc.String(), equals, "(Pkgname (package-settable) time:unknown quoting:backt wordpart:false)")
}

// In variable assignments, a plain '#' introduces a line comment, unless
// it is escaped by a backslash. In shell commands, on the other hand, it
// is interpreted literally.
func (s *Suite) Test_MkLineParser_Parse__number_sign(c *check.C) {
	t := s.Init(c)

	mklineVarassignEscaped := t.NewMkLine("filename.mk", 1, "SED_CMD=\t's,\\#,hash,g'")

	c.Check(mklineVarassignEscaped.Varname(), equals, "SED_CMD")
	c.Check(mklineVarassignEscaped.Value(), equals, "'s,#,hash,g'")

	mklineCommandEscaped := t.NewMkLine("filename.mk", 1, "\tsed -e 's,\\#,hash,g'")

	c.Check(mklineCommandEscaped.ShellCommand(), equals, "sed -e 's,\\#,hash,g'")

	// From shells/zsh/Makefile.common, rev. 1.78
	mklineCommandUnescaped := t.NewMkLine("filename.mk", 1, "\t# $ sha1 patches/patch-ac")

	c.Check(mklineCommandUnescaped.ShellCommand(), equals, "# $ sha1 patches/patch-ac")
	t.CheckOutputEmpty() // No warning about parsing the lonely dollar sign.

	mklineVarassignUnescaped := t.NewMkLine("filename.mk", 1, "SED_CMD=\t's,#,hash,'")

	c.Check(mklineVarassignUnescaped.Value(), equals, "'s,")
	t.CheckOutputLines(
		"WARN: filename.mk:1: The # character starts a Makefile comment.")
}

func (s *Suite) Test_MkLineParser_Parse__varassign_leading_space(c *check.C) {
	t := s.Init(c)

	_ = t.NewMkLine("rubyversion.mk", 427, " _RUBYVER=\t2.15")
	_ = t.NewMkLine("bsd.buildlink3.mk", 132, "   ok:=yes")

	// In mk/buildlink3/bsd.buildlink3.mk, the leading space is really helpful,
	// therefore no warnings for that file.
	t.CheckOutputLines(
		"WARN: rubyversion.mk:427: Makefile lines should not start with space characters.")
}

// Exotic code examples from the pkgsrc infrastructure.
// Hopefully, pkgsrc packages don't need such complicated code.
// Still, pkglint needs to parse them correctly, or it would not
// be able to parse and check the infrastructure files as well.
//
// See Pkgsrc.loadUntypedVars.
func (s *Suite) Test_MkLineParser_Parse__infrastructure(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("infra.mk",
		MkRcsID,
		"         USE_BUILTIN.${_pkg_:S/^-//}:=no",
		".error \"Something went wrong\"",
		".export WRKDIR",
		".export",
		".unexport-env WRKDIR",
		"",
		".ifmake target1",    // Luckily, this is not used in the wild.
		".elifnmake target2", // Neither is this.
		".endif")

	c.Check(mklines.mklines[1].Varcanon(), equals, "USE_BUILTIN.*")
	c.Check(mklines.mklines[2].Directive(), equals, "error")
	c.Check(mklines.mklines[3].Directive(), equals, "export")

	t.CheckOutputLines(
		"WARN: infra.mk:2: Makefile lines should not start with space characters.",
		"ERROR: infra.mk:8: Unknown Makefile line format: \".ifmake target1\".",
		"ERROR: infra.mk:9: Unknown Makefile line format: \".elifnmake target2\".")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: infra.mk:2: USE_BUILTIN.${_pkg_:S/^-//} is defined but not used.",
		"WARN: infra.mk:2: _pkg_ is used but not defined.",
		"ERROR: infra.mk:5: \".export\" requires arguments.",
		"NOTE: infra.mk:2: This variable value should be aligned to column 41.",
		"ERROR: infra.mk:10: Unmatched .endif.")
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__unknown_rhs(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 1, "PKGNAME:= ${UNKNOWN}")
	t.SetUpVartypes()

	vuc := VarUseContext{G.Pkgsrc.VariableType(nil, "PKGNAME"), vucTimeLoad, VucQuotUnknown, false}
	nq := mkline.VariableNeedsQuoting(nil, &MkVarUse{"UNKNOWN", nil}, nil, &vuc)

	c.Check(nq, equals, unknown)
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__append_URL_to_list_of_URLs(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpMasterSite("MASTER_SITE_SOURCEFORGE", "http://downloads.sourceforge.net/sourceforge/")
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"MASTER_SITES=\t${HOMEPAGE}")
	mkline := mklines.mklines[1]

	vuc := VarUseContext{G.Pkgsrc.vartypes.Canon("MASTER_SITES"), vucTimeRun, VucQuotPlain, false}
	nq := mkline.VariableNeedsQuoting(nil, &MkVarUse{"HOMEPAGE", nil}, G.Pkgsrc.vartypes.Canon("HOMEPAGE"), &vuc)

	c.Check(nq, equals, no)

	MkLineChecker{mklines, mkline}.checkVarassign()

	t.CheckOutputEmpty() // Up to version 5.3.6, pkglint warned about a missing :Q here, which was wrong.
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__append_list_to_list(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpMasterSite("MASTER_SITE_SOURCEFORGE", "http://downloads.sourceforge.net/sourceforge/")
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"MASTER_SITES=\t${MASTER_SITE_SOURCEFORGE:=squirrel-sql/}")

	MkLineChecker{mklines, mklines.mklines[1]}.checkVarassign()

	// Assigning lists to lists is ok.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__eval_shell(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("builtin.mk",
		MkRcsID,
		"USE_BUILTIN.Xfixes!=\t${PKG_ADMIN} pmatch 'pkg-[0-9]*' ${BUILTIN_PKG.Xfixes:Q}")

	MkLineChecker{mklines, mklines.mklines[1]}.checkVarassign()

	t.CheckOutputLines(
		"NOTE: builtin.mk:2: The :Q operator isn't necessary for ${BUILTIN_PKG.Xfixes} here.")
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__command_in_single_quotes(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"SUBST_SED.hpath=\t-e 's|^\\(INSTALL[\t:]*=\\).*|\\1${INSTALL}|'")

	MkLineChecker{mklines, mklines.mklines[1]}.checkVarassign()

	t.CheckOutputLines(
		"WARN: Makefile:2: Please use ${INSTALL:Q} instead of ${INSTALL} " +
			"and make sure the variable appears outside of any quoting characters.")
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__command_in_command(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("find", "FIND", AtRunTime)
	t.SetUpTool("sort", "SORT", AtRunTime)
	G.Pkg = NewPackage(t.File("category/pkgbase"))
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"GENERATE_PLIST= cd ${DESTDIR}${PREFIX}; ${FIND} * \\( -type f -or -type l \\) | ${SORT};")

	mklines.collectDefinedVariables()
	MkLineChecker{mklines, mklines.mklines[1]}.Check()

	t.CheckOutputLines(
		"WARN: Makefile:2: The exitcode of \"${FIND}\" at the left of the | operator is ignored.")
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__word_as_part_of_word(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"EGDIR=\t${EGDIR}/${MACHINE_GNU_PLATFORM}")

	MkLineChecker{mklines, mklines.mklines[1]}.Check()

	t.CheckOutputEmpty()
}

// As an argument to ${ECHO}, the :Q modifier should be used, but as of
// October 2018, pkglint does not know all shell commands and how they
// handle their arguments. As an argument to xargs(1), the :Q modifier
// would be misplaced, therefore no warning is issued in both these cases.
//
// Based on graphics/circos/Makefile.
func (s *Suite) Test_MkLine_VariableNeedsQuoting__command_as_command_argument(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("perl", "PERL5", AtRunTime)
	t.SetUpTool("bash", "BASH", AtRunTime)
	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"\t${RUN} cd ${WRKSRC} && ( ${ECHO} ${PERL5:Q} ; ${ECHO} ) | ${BASH} ./install",
		"\t${RUN} cd ${WRKSRC} && ( ${ECHO} ${PERL5} ; ${ECHO} ) | ${BASH} ./install")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:2: The exitcode of the command at the left of the | operator is ignored.",
		"WARN: Makefile:3: The exitcode of the command at the left of the | operator is ignored.")
}

// As seen in mail/mailfront/Makefile.
func (s *Suite) Test_MkLine_VariableNeedsQuoting__URL_as_part_of_word_in_list(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"MASTER_SITES=${HOMEPAGE}archive/")

	MkLineChecker{mklines, mklines.mklines[1]}.Check()

	t.CheckOutputEmpty() // Don't suggest to use ${HOMEPAGE:Q}.
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__MASTER_SITES_and_HOMEPAGE(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"MASTER_SITES=\t${HOMEPAGE}",
		"MASTER_SITES=\t${PATH}", // Some nonsense just for branch coverage.
		"HOMEPAGE=\t${MASTER_SITES}",
		"HOMEPAGE=\t${BUILD_DIRS}") // Some nonsense just for branch coverage.

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:3: Please use ${PATH:Q} instead of ${PATH}.",
		"WARN: Makefile:4: HOMEPAGE should not be defined in terms of MASTER_SITEs.",
		"WARN: Makefile:5: Please use ${BUILD_DIRS:Q} instead of ${BUILD_DIRS}.")
}

// Before November 2018, pkglint did not parse $$(subshell) commands very well.
// As a side effect, it sometimes issued wrong warnings about the :Q modifier.
//
// As seen in www/firefox31/xpi.mk.
func (s *Suite) Test_MkLine_VariableNeedsQuoting__command_in_subshell(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("awk", "AWK", AtRunTime)
	t.SetUpTool("echo", "ECHO", AtRunTime)
	mklines := t.NewMkLines("xpi.mk",
		MkRcsID,
		"\t id=$$(${AWK} '{print}' < ${WRKSRC}/idfile) && echo \"$$id\"",
		"\t id=`${AWK} '{print}' < ${WRKSRC}/idfile` && echo \"$$id\"")

	MkLineChecker{mklines, mklines.mklines[1]}.Check()
	MkLineChecker{mklines, mklines.mklines[2]}.Check()

	// Don't suggest to use ${AWK:Q}.
	t.CheckOutputLines(
		"WARN: xpi.mk:2: Invoking subshells via $(...) is not portable enough.")
}

// LDFLAGS (and even more so CPPFLAGS and CFLAGS) may contain special
// shell characters like quotes or backslashes. Therefore, quoting them
// correctly is trickier than with other variables.
func (s *Suite) Test_MkLine_VariableNeedsQuoting__LDFLAGS_in_single_quotes(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("x11/mlterm/Makefile",
		MkRcsID,
		"SUBST_SED.link=-e 's|(LIBTOOL_LINK).*(LIBS)|& ${LDFLAGS:M*:Q}|g'",
		"SUBST_SED.link=-e 's|(LIBTOOL_LINK).*(LIBS)|& '${LDFLAGS:M*:Q}'|g'")

	MkLineChecker{mklines, mklines.mklines[1]}.Check()
	MkLineChecker{mklines, mklines.mklines[2]}.Check()

	t.CheckOutputLines(
		"WARN: x11/mlterm/Makefile:2: Please move ${LDFLAGS:M*:Q} outside of any quoting characters.")
}

// No quoting is necessary when lists of options are appended to each other.
func (s *Suite) Test_MkLine_VariableNeedsQuoting__package_options(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"PKG_SUGGESTED_OPTIONS+=\t${PKG_DEFAULT_OPTIONS:Mcdecimal} ${PKG_OPTIONS.py-trytond:Mcdecimal}")

	MkLineChecker{mklines, mklines.mklines[1]}.Check()

	// No warning about a missing :Q modifier.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__tool_in_quotes_in_subshell_in_shellwords(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("echo", "ECHO", AtRunTime)
	t.SetUpTool("sh", "SH", AtRunTime)
	t.SetUpVartypes()
	mklines := t.NewMkLines("x11/labltk/Makefile",
		MkRcsID,
		"CONFIGURE_ARGS+=\t-tklibs \"`${SH} -c '${ECHO} $$TK_LD_FLAGS'`\"")

	MkLineChecker{mklines, mklines.mklines[1]}.Check()

	// Don't suggest ${ECHO:Q} here.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__LDADD_in_BUILDLINK_TRANSFORM(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("x11/qt5-qtbase/Makefile.common",
		"BUILDLINK_TRANSFORM+=opt:-ldl:${BUILDLINK_LDADD.dl:M*}")

	MkLineChecker{mklines, mklines.mklines[0]}.Check()

	// Note: The :M* modifier is not necessary, since this is not a GNU Configure package.
	t.CheckOutputLines(
		"WARN: x11/qt5-qtbase/Makefile.common:1: Please use ${BUILDLINK_LDADD.dl:Q} instead of ${BUILDLINK_LDADD.dl:M*}.")
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__command_in_message(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("benchmarks/iozone/Makefile",
		"SUBST_MESSAGE.crlf=\tStripping EOL CR in ${REPLACE_PERL}")

	MkLineChecker{mklines, mklines.mklines[0]}.Check()

	// Don't suggest ${REPLACE_PERL:Q}.
	t.CheckOutputEmpty()
}

// Since a comment may be appended to, it is not necessary to mention
// BtComment in the SUBST_MESSAGE case in VariableNeedsQuoting.
func (s *Suite) Test_MkLine_VariableNeedsQuoting__command_in_package_comment(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("benchmarks/iozone/Makefile",
		"COMMENT=\tUtility for replacing ${REPLACE_PERL}")

	MkLineChecker{mklines, mklines.mklines[0]}.Check()

	// Don't suggest ${REPLACE_PERL:Q}.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__guessed_list_variable_in_quotes(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("audio/jack-rack/Makefile",
		MkRcsID,
		"LADSPA_PLUGIN_PATH=\t${PREFIX}/lib/ladspa",
		"CPPFLAGS+=\t\t-DLADSPA_PATH=\"\\\"${LADSPA_PLUGIN_PATH}\\\"\"")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: audio/jack-rack/Makefile:3: The variable LADSPA_PLUGIN_PATH should be quoted as part of a shell word.")
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__list_in_list(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("x11/eterm/Makefile",
		MkRcsID,
		"DISTFILES=\t${DEFAULT_DISTFILES} ${PIXMAP_FILES}")

	mklines.Check()

	// Don't warn about missing :Q modifiers.
	t.CheckOutputLines(
		"WARN: x11/eterm/Makefile:2: PIXMAP_FILES is used but not defined.")
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__PKGNAME_and_URL_list_in_URL_list(c *check.C) {
	t := s.Init(c)

	t.SetUpMasterSite("MASTER_SITE_GNOME", "http://ftp.gnome.org/")
	t.SetUpVartypes()
	mklines := t.NewMkLines("x11/gtk3/Makefile",
		MkRcsID,
		"MASTER_SITES=\tftp://ftp.gtk.org/${PKGNAME}/ ${MASTER_SITE_GNOME:=subdir/}")

	MkLineChecker{mklines, mklines.mklines[1]}.checkVarassignRightVaruse()

	t.CheckOutputEmpty() // Don't warn about missing :Q modifiers.
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__tool_in_CONFIGURE_ENV(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("tar", "TAR", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"CONFIGURE_ENV+=\tSYS_TAR_COMMAND_PATH=${TOOLS_TAR:Q}")

	MkLineChecker{mklines, mklines.mklines[2]}.checkVarassignRightVaruse()

	// The TOOLS_* variables only contain the path to the tool,
	// without any additional arguments that might be necessary
	// for invoking the tool properly (e.g. touch -t).
	// Therefore, no quoting is necessary.
	t.CheckOutputLines(
		"NOTE: Makefile:3: The :Q operator isn't necessary for ${TOOLS_TAR} here.")
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__backticks(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("cat", "CAT", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"COMPILE_CMD=\tcc `${CAT} ${WRKDIR}/compileflags`",
		"COMMENT_CMD=\techo `echo ${COMMENT}`")

	MkLineChecker{mklines, mklines.mklines[2]}.checkVarassignRightVaruse()
	MkLineChecker{mklines, mklines.mklines[3]}.checkVarassignRightVaruse()

	// Both CAT and WRKDIR are safe from quoting, therefore no warnings.
	// But COMMENT may contain arbitrary characters and therefore must
	// only appear completely unquoted. There is no practical way of
	// using it inside backticks, and luckily there is no need for it.
	t.CheckOutputLines(
		// TODO: Better suggest that COMMENT should not be used inside backticks or other quotes.
		"WARN: Makefile:4: The variable COMMENT should be quoted as part of a shell word.")
}

// For some well-known directory variables like WRKDIR, PREFIX, LOCALBASE,
// the :Q modifier can be safely removed since pkgsrc will never support
// having special characters in these directory names.
// For guessed variable types be cautious and don't autofix them.
func (s *Suite) Test_MkLine_VariableNeedsQuoting__only_remove_known(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--autofix")
	t.SetUpVartypes()

	mklines := t.SetUpFileMkLines("Makefile",
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
//  defined in vardefs.go; examine why.
func (s *Suite) Test_MkLine_VariableNeedsQuoting__shellword_part(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall,no-space")
	t.SetUpVartypes()

	mklines := t.SetUpFileMkLines("Makefile",
		MkRcsID,
		"",
		"SUBST_CLASSES+=    class",
		"SUBST_STAGE.class= pre-configure",
		"SUBST_FILES.class= files",
		"SUBST_SED.class=-e s:@LINKER_RPATH_FLAG@:${LINKER_RPATH_FLAG}:g")

	mklines.Check()

	t.CheckOutputLines(
		"NOTE: ~/Makefile:6: The substitution command \"s:@LINKER_RPATH_FLAG@:${LINKER_RPATH_FLAG}:g\" " +
			"can be replaced with \"SUBST_VARS.class= LINKER_RPATH_FLAG\".")
}

// Tools, when used in a shell command, must not be quoted.
func (s *Suite) Test_MkLine_VariableNeedsQuoting__tool_in_shell_command(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall,no-space")
	t.SetUpVartypes()
	t.SetUpTool("bash", "BASH", AtRunTime)

	mklines := t.SetUpFileMkLines("Makefile",
		MkRcsID,
		"",
		"CONFIG_SHELL= ${BASH}")

	mklines.Check()

	t.CheckOutputEmpty()
}

// As of October 2018, these examples from real pkgsrc end up in the
// final "unknown" case.
func (s *Suite) Test_MkLine_VariableNeedsQuoting__uncovered_cases(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall,no-space", "--explain")
	t.SetUpVartypes()

	mklines := t.SetUpFileMkLines("Makefile",
		MkRcsID,
		"",
		"GO_SRCPATH=             ${HOMEPAGE:S,https://,,}",
		"LINKER_RPATH_FLAG:=     ${LINKER_RPATH_FLAG:S/-rpath/& /}",
		"HOMEPAGE=               http://godoc.org/${GO_SRCPATH}",
		"PATH:=                  ${PREFIX}/cross/bin:${PATH}",
		"NO_SRC_ON_FTP=          ${RESTRICTED}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/Makefile:4: The variable LINKER_RPATH_FLAG should not be set by any package.",
		"",
		"\tThe allowed actions for a variable are determined based on the file",
		"\tname in which the variable is used or defined. The rules for",
		"\tLINKER_RPATH_FLAG are:",
		"",
		"\t* in buildlink3.mk, it should not be accessed at all",
		"\t* in any file, it may be used",
		"",
		"\tIf these rules seem to be incorrect, please ask on the",
		"\ttech-pkg@NetBSD.org mailing list.",
		"",
		"WARN: ~/Makefile:4: LINKER_RPATH_FLAG should not be used at load time in any file.",
		"",
		"\tMany variables, especially lists of something, get their values",
		"\tincrementally. Therefore it is generally unsafe to rely on their",
		"\tvalue until it is clear that it will never change again. This point",
		"\tis reached when the whole package Makefile is loaded and execution",
		"\tof the shell commands starts; in some cases earlier.",
		"",
		"\tAdditionally, when using the \":=\" operator, each $$ is replaced with",
		"\ta single $, so variables that have references to shell variables or",
		"\tregular expressions are modified in a subtle way.",
		"",
		"\tThe allowed actions for a variable are determined based on the file",
		"\tname in which the variable is used or defined. The rules for",
		"\tLINKER_RPATH_FLAG are:",
		"",
		"\t* in buildlink3.mk, it should not be accessed at all",
		"\t* in any file, it may be used",
		"",
		"\tIf these rules seem to be incorrect, please ask on the",
		"\ttech-pkg@NetBSD.org mailing list.",
		"",
		"WARN: ~/Makefile:6: The variable PATH should not be set by any package.",
		"",
		"\tThe allowed actions for a variable are determined based on the file",
		"\tname in which the variable is used or defined. The rules for PATH",
		"\tare:",
		"",
		"\t* in any file, it may be used at load time, or used",
		"",
		"\tIf these rules seem to be incorrect, please ask on the",
		"\ttech-pkg@NetBSD.org mailing list.",
		"",
		"WARN: ~/Makefile:6: PREFIX should not be used at load time in any file.",
		"",
		"\tMany variables, especially lists of something, get their values",
		"\tincrementally. Therefore it is generally unsafe to rely on their",
		"\tvalue until it is clear that it will never change again. This point",
		"\tis reached when the whole package Makefile is loaded and execution",
		"\tof the shell commands starts; in some cases earlier.",
		"",
		"\tAdditionally, when using the \":=\" operator, each $$ is replaced with",
		"\ta single $, so variables that have references to shell variables or",
		"\tregular expressions are modified in a subtle way.",
		"",
		"\tThe allowed actions for a variable are determined based on the file",
		"\tname in which the variable is used or defined. The rules for PREFIX",
		"\tare:",
		"",
		"\t* in any file, it may be used",
		"",
		"\tIf these rules seem to be incorrect, please ask on the",
		"\ttech-pkg@NetBSD.org mailing list.",
		"")

	// Just for branch coverage.
	trace.Tracing = false
	MkLineChecker{mklines, mklines.mklines[2]}.Check()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLine__shell_varuse_in_backt_dquot(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("grep", "GREP", AtRunTime)
	mklines := t.NewMkLines("x11/motif/Makefile",
		MkRcsID,
		"post-patch:",
		"\tfiles=`${GREP} -l \".fB$${name}.fP(3)\" *.3`")

	mklines.Check()

	// Just ensure that there are no parse errors.
	t.CheckOutputEmpty()
}

// PR 51696, security/py-pbkdf2/Makefile, r1.2
func (s *Suite) Test_MkLine__comment_in_comment(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"COMMENT=\tPKCS#5 v2.0 PBKDF2 Module")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:2: The # character starts a Makefile comment.")
}

// Ensures that the conditional variables of a line can be set even
// after initializing the MkLine.
//
// If this test should fail, it is probably because mkLineDirective
// is not a pointer type anymore.
//
// See https://github.com/golang/go/issues/28045.
func (s *Suite) Test_MkLine_ConditionalVars(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("Makefile", 45, ".include \"../../category/package/buildlink3.mk\"")

	c.Check(mkline.ConditionalVars(), check.HasLen, 0)

	mkline.SetConditionalVars([]string{"OPSYS"})

	c.Check(mkline.ConditionalVars(), deepEquals, []string{"OPSYS"})
}

func (s *Suite) Test_MkLine_ValueSplit(c *check.C) {
	t := s.Init(c)

	test := func(value string, expected ...string) {
		mkline := t.NewMkLine("Makefile", 1, "PATH=\t"+value)
		split := mkline.ValueSplit(value, ":")
		c.Check(split, deepEquals, expected)
	}

	test("Platform-independent C# compiler #5",
		"Platform-independent C# compiler #5")

	// This warning refers to the #5 since it starts a word, but not to the C#.
	t.CheckOutputLines(
		"WARN: Makefile:1: The # character starts a Makefile comment.")

	test("/bin",
		"/bin")

	test("/bin:/sbin",
		"/bin",
		"/sbin")

	test("${DESTDIR}/bin:/bin/${SUBDIR}",
		"${DESTDIR}/bin",
		"/bin/${SUBDIR}")

	test("/bin:${DESTDIR}${PREFIX}:${DESTDIR:S,/,\\:,:S,:,:,}/sbin",
		"/bin",
		"${DESTDIR}${PREFIX}",
		"${DESTDIR:S,/,\\:,:S,:,:,}/sbin")

	test("${VAR:Udefault}::${VAR2}two:words",
		"${VAR:Udefault}",
		"",
		"${VAR2}two",
		"words")

}

func (s *Suite) Test_MkLine_ValueSplit__invalid_argument(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 123, "VAR=\tvalue")

	t.ExpectPanic(
		func() { mkline.ValueSplit("value", "") },
		"Pkglint internal error: Separator must not be empty; use ValueFields to split on whitespace")
}

func (s *Suite) Test_MkLine_Fields__varassign(c *check.C) {
	t := s.Init(c)

	test := func(value string, expected ...string) {
		mkline := t.NewMkLine("Makefile", 1, "PATH=\t"+value)
		fields := mkline.Fields()
		c.Check(fields, deepEquals, expected)

		// Repeated calls get the cached value.
		if len(fields) > 0 {
			cached := mkline.Fields()
			c.Check(&cached[0], equals, &fields[0])
		}
	}

	test("# empty",
		nil...)

	test("word",
		"word")

	test("word '${VAR}single ${VAR}' \"\t\"",
		"word",
		"'${VAR}single ${VAR}'",
		"\"\t\"")
}

func (s *Suite) Test_MkLine_Fields__for(c *check.C) {
	t := s.Init(c)

	test := func(value string, expected ...string) {
		mkline := t.NewMkLine("Makefile", 1, ".for "+value)
		fields := mkline.Fields()
		c.Check(fields, deepEquals, expected)

		// Repeated calls get the cached value.
		if len(fields) > 0 {
			cached := mkline.Fields()
			c.Check(&cached[0], equals, &fields[0])
		}
	}

	// Unrealistic, but needed for full code coverage.
	test("# empty",
		nil...)

	// Still unrealistic.
	test("i in # empty",
		"i",
		"in")

	test("i in word '${VAR}single ${VAR}' \"\t\"",
		"i",
		"in",
		"word",
		"'${VAR}single ${VAR}'",
		"\"\t\"")
}

func (s *Suite) Test_MkLine_Fields__semicolons(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 123, "VAR=\tword1 word2;;;")
	words := mkline.Fields()

	c.Check(words, deepEquals, []string{"word1", "word2;;;"})
}

func (s *Suite) Test_MkLine_Fields__varuse_with_embedded_space(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 123, "VAR=\t${VAR:S/ /_/g}")

	words := mkline.Fields()

	c.Check(words, deepEquals, []string{"${VAR:S/ /_/g}"})
}

func (s *Suite) Test_MkLine_ValueFields(c *check.C) {
	t := s.Init(c)

	test := func(value string, expected ...string) {
		mkline := t.NewMkLine("Makefile", 1, "VAR=\t"+value)
		split := mkline.ValueFields(value)
		c.Check(split, deepEquals, expected)
	}

	test("one   two\t\t${THREE:Uthree:Nsome \tspaces}",
		"one",
		"two",
		"${THREE:Uthree:Nsome \tspaces}")

	// The example from the ValueFields documentation.
	test("${VAR:Udefault value} ${VAR2}two words;;; 'word three'",
		"${VAR:Udefault value}",
		"${VAR2}two",
		"words;;;",
		"'word three'")
}

// Before 2018-11-26, this test panicked.
func (s *Suite) Test_MkLine_ValueFields__adjacent_vars(c *check.C) {
	t := s.Init(c)

	test := func(value string, expected ...string) {
		mkline := t.NewMkLine("Makefile", 1, "")
		split := mkline.ValueFields(value)
		c.Check(split, deepEquals, expected)
	}

	test("\t; ${RM} ${WRKSRC}",
		";",
		"${RM}",
		"${WRKSRC}")
}

func (s *Suite) Test_MkLine_ValueFields__compared_to_splitIntoShellTokens(c *check.C) {
	t := s.Init(c)
	url := "http://registry.gimp.org/file/fix-ca.c?action=download&id=9884&file="
	mkline := t.NewMkLine("filename.mk", 123, "MASTER_SITES=\t"+url)

	words, rest := splitIntoShellTokens(dummyLine, url) // Doesn't really make sense

	c.Check(words, check.DeepEquals, []string{
		"http://registry.gimp.org/file/fix-ca.c?action=download",
		"&",
		"id=9884",
		"&",
		"file="})
	c.Check(rest, equals, "")

	words = mkline.ValueFields(url)

	c.Check(words, check.DeepEquals, []string{url})

	words = mkline.ValueFields("a b \"c  c  c\" d;;d;; \"e\"''`` 'rest")

	c.Check(words, check.DeepEquals, []string{"a", "b", "\"c  c  c\"", "d;;d;;", "\"e\"''``"})
	// TODO: c.Check(rest, equals, "'rest")
}

func (s *Suite) Test_MkLine_ValueTokens(c *check.C) {
	t := s.Init(c)

	text := func(text string) *MkToken { return &MkToken{text, nil} }
	varUseText := func(text string, varname string, modifiers ...string) *MkToken {
		return &MkToken{text, NewMkVarUse(varname, modifiers...)}
	}
	tokens := func(tokens ...*MkToken) []*MkToken { return tokens }
	test := func(value string, expected []*MkToken, diagnostics ...string) {
		mkline := t.NewMkLine("Makefile", 1, "PATH=\t"+value)
		actualTokens, _ := mkline.ValueTokens()
		c.Check(actualTokens, deepEquals, expected)
		t.CheckOutput(diagnostics)
	}

	t.Use(text, varUseText, tokens, test)

	test("#empty",
		tokens())

	test("value",
		tokens(text("value")))

	test("value ${VAR} rest",
		tokens(
			text("value "),
			varUseText("${VAR}", "VAR"),
			text(" rest")))

	test("value # comment",
		tokens(
			text("value")))

	test("value ${UNFINISHED",
		tokens(
			text("value "),
			varUseText("${UNFINISHED", "UNFINISHED")),

		"WARN: Makefile:1: Missing closing \"}\" for \"UNFINISHED\".")
}

func (s *Suite) Test_MkLine_ValueTokens__parse_error(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 123, "VAR=\t$")

	tokens, rest := mkline.ValueTokens()

	t.Check(tokens, check.IsNil)
	t.Check(rest, equals, "$")

	// Returns the same values, this time from the cache.
	tokens, rest = mkline.ValueTokens()

	t.Check(tokens, check.IsNil)
	t.Check(rest, equals, "$")
}

func (s *Suite) Test_MkLine_ValueTokens__caching(c *check.C) {
	t := s.Init(c)

	tokens := func(tokens ...*MkToken) []*MkToken { return tokens }

	mkline := t.NewMkLine("Makefile", 1, "PATH=\tvalue ${UNFINISHED")
	valueTokens, rest := mkline.ValueTokens()

	c.Check(valueTokens, deepEquals,
		tokens(
			&MkToken{"value ", nil},
			&MkToken{"${UNFINISHED", NewMkVarUse("UNFINISHED")}))
	c.Check(rest, equals, "")
	t.CheckOutputLines(
		"WARN: Makefile:1: Missing closing \"}\" for \"UNFINISHED\".")

	// This time the slice is taken from the cache.
	tokens2, rest2 := mkline.ValueTokens()

	c.Check(&tokens2[0], equals, &valueTokens[0])
	c.Check(rest2, equals, rest)
}

func (s *Suite) Test_MkLine_ValueTokens__caching_parse_error(c *check.C) {
	t := s.Init(c)

	tokens := func(tokens ...*MkToken) []*MkToken { return tokens }
	varuseText := func(text, varname string, modifiers ...string) *MkToken {
		return &MkToken{Text: text, Varuse: NewMkVarUse(varname, modifiers...)}
	}

	mkline := t.NewMkLine("Makefile", 1, "PATH=\t${UNFINISHED")
	valueTokens, rest := mkline.ValueTokens()

	c.Check(valueTokens, deepEquals, tokens(varuseText("${UNFINISHED", "UNFINISHED")))
	c.Check(rest, equals, "")
	t.CheckOutputLines(
		"WARN: Makefile:1: Missing closing \"}\" for \"UNFINISHED\".")

	// This time the slice is taken from the cache.
	tokens2, rest2 := mkline.ValueTokens()

	c.Check(&tokens2[0], equals, &valueTokens[0])
	c.Check(rest2, equals, rest)
}

func (s *Suite) Test_MkLine_ValueTokens__warnings(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"ROUND=\t$(ROUND)")

	mklines.mklines[1].ValueTokens()
	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:2: Please use curly braces {} instead of round parentheses () for ROUND.")
}

func (s *Suite) Test_MkLine_Tokenize__commented_varassign(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 123, "#VAR=\tvalue ${VAR} suffix text")

	t.Check(mkline.Tokenize(mkline.Value(), false), check.HasLen, 3)
}

func (s *Suite) Test_MkLine_ResolveVarsInRelativePath(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("lang/lua53/Makefile")
	t.CreateFileLines("lang/php72/Makefile")
	t.CreateFileLines("emulators/suse100_base/Makefile")
	t.CreateFileLines("lang/python36/Makefile")
	mklines := t.SetUpFileMkLines("Makefile",
		MkRcsID)
	mkline := mklines.mklines[0]

	test := func(before string, after string) {
		c.Check(mkline.ResolveVarsInRelativePath(before), equals, after)
	}

	test("", ".")
	test("${PKGSRCDIR}", ".")
	test("${LUA_PKGSRCDIR}", "../../lang/lua53")
	test("${PHPPKGSRCDIR}", "../../lang/php72")
	test("${SUSE_DIR_PREFIX}", "suse100")
	test("${PYPKGSRCDIR}", "../../lang/python36")
	test("${PYPACKAGE}", "python36")
	test("${FILESDIR}", "${FILESDIR}")
	test("${PKGDIR}", "${PKGDIR}")

	G.Pkg = NewPackage(t.File("category/package"))

	test("${FILESDIR}", "files")
	test("${PKGDIR}", ".")

	// Just for branch coverage.
	G.Testing = false
	test("${PKGSRCDIR}", "../..")
}

func (s *Suite) Test_MkLine_ResolveVarsInRelativePath__directory_depth(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.SetUpFileMkLines("multimedia/totem/bla.mk",
		MkRcsID,
		"BUILDLINK_PKGSRCDIR.totem?=\t../../multimedia/totem")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/multimedia/totem/bla.mk:2: "+
			"The variable BUILDLINK_PKGSRCDIR.totem should not be given a default value in this file; "+
			"it would be ok in buildlink3.mk.",
		"ERROR: ~/multimedia/totem/bla.mk:2: Relative path \"../../multimedia/totem/Makefile\" does not exist.")
}

// Just for code coverage
func (s *Suite) Test_MkLine_ResolveVarsInRelativePath__without_tracing(c *check.C) {
	t := s.Init(c)

	t.DisableTracing()
	t.SetUpVartypes()
	mklines := t.SetUpFileMkLines("buildlink3.mk",
		MkRcsID,
		"BUILDLINK_PKGSRCDIR.totem?=\t../../${PKGPATH.multimedia/totem}")

	mklines.Check()

	t.CheckOutputLines(
		// FIXME: It's ok to have variable parameters including a slash.
		"WARN: ~/buildlink3.mk:2: Invalid part \"/totem\" after variable name \"PKGPATH.multimedia\".",
		"WARN: ~/buildlink3.mk:2: PKGPATH.multimedia/totem is used but not defined.")
}

func (s *Suite) Test_MkLineParser_MatchVarassign(c *check.C) {
	t := s.Init(c)

	test := func(text string, commented bool, varname, spaceAfterVarname, op, align, value, spaceAfterValue, comment string, diagnostics ...string) {
		line := t.NewLine("filename.mk", 123, text)
		data := MkLineParser{}.split(line, text)
		m, actual := MkLineParser{}.MatchVarassign(line, text, data)
		if !m {
			c.Errorf("Text %q doesn't match variable assignment", text)
			return
		}

		expected := mkLineAssignImpl{
			commented:         commented,
			varname:           varname,
			varcanon:          varnameCanon(varname),
			varparam:          varnameParam(varname),
			spaceAfterVarname: spaceAfterVarname,
			op:                NewMkOperator(op),
			valueAlign:        align,
			value:             value,
			valueMk:           nil,
			valueMkRest:       "",
			fields:            nil,
			spaceAfterValue:   spaceAfterValue,
			comment:           comment,
		}
		c.Check(*actual, deepEquals, expected)
		t.CheckOutput(diagnostics)
	}

	testInvalid := func(text string, diagnostics ...string) {
		line := t.NewLine("filename.mk", 123, text)
		data := MkLineParser{}.split(nil, text)
		m, _ := MkLineParser{}.MatchVarassign(line, text, data)
		if m {
			c.Errorf("Text %q matches variable assignment but shouldn't.", text)
		}
		t.CheckOutput(diagnostics)
	}

	test("C++=c11", false, "C+", "", "+=", "C++=", "c11", "", "")
	test("V=v", false, "V", "", "=", "V=", "v", "", "")
	test("VAR=#comment", false, "VAR", "", "=", "VAR=", "", "", "#comment")
	test("VAR=\\#comment", false, "VAR", "", "=", "VAR=", "#comment", "", "")
	test("VAR=\\\\\\##comment", false, "VAR", "", "=", "VAR=", "\\\\#", "", "#comment")
	test("VAR=\\", false, "VAR", "", "=", "VAR=", "\\", "", "")
	test("VAR += value", false, "VAR", " ", "+=", "VAR += ", "value", "", "")
	test(" VAR=value", false, "VAR", "", "=", " VAR=", "value", "", "")
	test("VAR=value #comment", false, "VAR", "", "=", "VAR=", "value", " ", "#comment")
	test("NFILES=${FILES:[#]}", false, "NFILES", "", "=", "NFILES=", "${FILES:[#]}", "", "")

	// To humans, the base variable name seems to be SITES_, being parameterized
	// with distfile-1.0.tar.gz. For pkglint though, the base variable name is
	// SITES_distfile-1.
	test("SITES_distfile-1.0.tar.gz=https://example.org/",
		false,
		"SITES_distfile-1.0.tar.gz",
		"",
		"=",
		"SITES_distfile-1.0.tar.gz=",
		"https://example.org/",
		"",
		"")

	test("SITES_${distfile}=https://example.org/",
		false,
		"SITES_${distfile}",
		"",
		"=",
		"SITES_${distfile}=",
		"https://example.org/",
		"",
		"")

	testInvalid("\tVAR=value")
	testInvalid("?=value")
	testInvalid("<=value")
	testInvalid("#")
	testInvalid("VAR.$$=value")

	// A commented variable assignment must start immediately after the comment character.
	// There must be no additional whitespace before the variable name.
	test("#VAR=value", true, "VAR", "", "=", "#VAR=", "value", "", "")

	// A single space is typically used for writing documentation, not for commenting out code.
	// Therefore this line doesn't count as commented variable assignment.
	testInvalid("# VAR=value")

	// Ensure that the alignment for the variable value is correct.
	test("BUILD_DIRS=\tdir1 dir2",
		false,
		"BUILD_DIRS",
		"",
		"=",
		"BUILD_DIRS=\t",
		"dir1 dir2",
		"",
		"")

	// Ensure that the alignment for the variable value is correct,
	// even if the whole line is commented.
	test("#BUILD_DIRS=\tdir1 dir2",
		true,
		"BUILD_DIRS",
		"",
		"=",
		"#BUILD_DIRS=\t",
		"dir1 dir2",
		"",
		"")

	test("MASTER_SITES=\t#none",
		false,
		"MASTER_SITES",
		"",
		"=",
		"MASTER_SITES=\t",
		"",
		"",
		"#none")

	test("MASTER_SITES=\t# none",
		false,
		"MASTER_SITES",
		"",
		"=",
		"MASTER_SITES=\t",
		"",
		"",
		"# none")

	test("EGDIRS=\t${EGDIR/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d",

		false,
		"EGDIRS",
		"",
		"=",
		"EGDIRS=\t",
		"${EGDIR/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d",
		"",
		"",

		"WARN: filename.mk:123: Missing closing \"}\" for \"EGDIR/pam.d\".",
		"WARN: filename.mk:123: Invalid part \"/pam.d\" after variable name \"EGDIR\".",
		"WARN: filename.mk:123: Missing closing \"}\" for \"EGDIR/dbus-1/system.d ${EGDIR/pam.d\".",
		"WARN: filename.mk:123: Invalid part \"/dbus-1/system.d ${EGDIR/pam.d\" after variable name \"EGDIR\".",
		"WARN: filename.mk:123: Missing closing \"}\" for \"EGDIR/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d\".",
		"WARN: filename.mk:123: Invalid part \"/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d\" after variable name \"EGDIR\".")

	test("VAR:=\t${VAR:M-*:[\\#]}",
		false,
		"VAR",
		"",
		":=",
		"VAR:=\t",
		"${VAR:M-*:[#]}",
		"",
		"")

	test("#VAR=value",
		true, "VAR", "", "=", "#VAR=", "value", "", "")

	testInvalid("# VAR=value")
	testInvalid("#\tVAR=value")
	testInvalid(MkRcsID)
}

func (s *Suite) Test_NewMkOperator(c *check.C) {
	c.Check(NewMkOperator(":="), equals, opAssignEval)
	c.Check(NewMkOperator("="), equals, opAssign)

	c.Check(func() { NewMkOperator("???") }, check.Panics, "Invalid operator: ???")
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

	c.Check(ind.Varnames(), deepEquals, []string{"LEVEL1.VAR1"})

	ind.AddVar("LEVEL1.VAR2")

	c.Check(ind.Varnames(), deepEquals, []string{"LEVEL1.VAR1", "LEVEL1.VAR2"})
	c.Check(ind.DependsOn("LEVEL1.VAR1"), equals, true)
	c.Check(ind.DependsOn("OTHER_VAR"), equals, false)

	ind.Push(mkline, 2, "")

	ind.AddVar("LEVEL2.VAR")

	c.Check(ind.Varnames(), deepEquals, []string{"LEVEL1.VAR1", "LEVEL1.VAR2", "LEVEL2.VAR"})
	c.Check(ind.String(), equals, "[2 (LEVEL1.VAR1 LEVEL1.VAR2) 2 (LEVEL2.VAR)]")

	ind.Pop()

	c.Check(ind.Varnames(), deepEquals, []string{"LEVEL1.VAR1", "LEVEL1.VAR2"})
	c.Check(ind.IsConditional(), equals, true)

	ind.Pop()

	c.Check(ind.Varnames(), check.HasLen, 0)
	c.Check(ind.IsConditional(), equals, false)
	c.Check(ind.String(), equals, "[]")
}

func (s *Suite) Test_Indentation_RememberUsedVariables(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("Makefile", 123, ".if ${PKGREVISION} > 0")
	ind := NewIndentation()

	ind.RememberUsedVariables(mkline.Cond())

	t.CheckOutputEmpty()
	c.Check(ind.Varnames(), deepEquals, []string{"PKGREVISION"})
}

func (s *Suite) Test_Indentation_TrackAfter__checked_files(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		MkRcsID,
		"",
		".if make(other.mk)",
		".  include \"other.mk\"",
		".endif",
		"",
		".if exists(checked.mk)",
		".  include \"checked.mk\"",
		".elif exists(other-checked.mk)",
		".  include \"other-checked.mk\"",
		".endif")

	mklines.Check()

	t.CheckOutputLines(
		"ERROR: file.mk:4: Relative path \"other.mk\" does not exist.")
}

func (s *Suite) Test_Indentation_TrackAfter__lonely_else(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		MkRcsID,
		"",
		".else")

	mklines.Check()

	// Surprisingly, pkglint doesn't report an error about this trivial bug.
	// This will be caught by bmake, though. Therefore the only purpose of
	// this test is the branch coverage in the "top.mkline != nil" case.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Indentation_Varnames__repetition(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/other")
	t.CreateFileDummyBuildlink3("category/other/buildlink3.mk")
	t.SetUpPackage("category/package",
		"DISTNAME=\tpackage-1.0",
		".include \"../../category/other/buildlink3.mk\"")
	t.CreateFileDummyBuildlink3("category/package/buildlink3.mk",
		".if ${OPSYS} == NetBSD || ${OPSYS} == FreeBSD",
		".  if ${OPSYS} == NetBSD",
		".    include \"../../category/other/buildlink3.mk\"",
		".  endif",
		".endif")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// TODO: It feels wrong that OPSYS is mentioned twice here.
	//  Why only twice and not three times?
	t.CheckOutputLines(
		"WARN: ~/category/package/buildlink3.mk:14: " +
			"\"../../category/other/buildlink3.mk\" is included conditionally here " +
			"(depending on OPSYS, OPSYS) and unconditionally in Makefile:20.")
}

func (s *Suite) Test_MkLine_ForEachUsed(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"VAR=\t${VALUE} # ${varassign.comment}",
		".if ${OPSYS:M${endianness}} == ${Hello:L} # ${if.comment}",
		".for var in one ${two} three # ${for.comment}",
		"# ${empty.comment}",
		"${TARGETS}: ${SOURCES} # ${dependency.comment}",
		".include \"${OTHER_FILE}\"",
		"",
		"\t${VAR.${param}}",
		"\t${VAR}and${VAR2}",
		"\t${VAR:M${pattern}}",
		"\t$(ROUND_PARENTHESES)",
		"\t$$shellvar",
		"\t$< $@ $x")

	var varnames []string
	for _, mkline := range mklines.mklines {
		mkline.ForEachUsed(func(varUse *MkVarUse, time vucTime) {
			varnames = append(varnames, time.String()+" "+varUse.varname)
		})
	}

	c.Check(varnames, deepEquals, []string{
		"run VALUE",
		"parse OPSYS",
		"parse endianness",
		// "Hello" is not a variable name, the :L modifier makes it an expression.
		"parse two",
		"parse TARGETS",
		"parse SOURCES",
		"parse OTHER_FILE",

		"run VAR.${param}",
		"run param",
		"run VAR",
		"run VAR2",
		"run VAR",
		"run pattern",
		"run ROUND_PARENTHESES",
		// Shell variables are ignored here.
		"run <",
		"run @",
		"run x"})
	t.CheckOutputLines(
		"WARN: Makefile:12: Please use curly braces {} instead of round parentheses () for ROUND_PARENTHESES.",
		"WARN: Makefile:14: $x is ambiguous. Use ${x} if you mean a Make variable or $$x if you mean a shell variable.")
}

func (s *Suite) Test_MkLine_UnquoteShell(c *check.C) {
	t := s.Init(c)

	test := func(input, output string) {
		unquoted := (*MkLineImpl).UnquoteShell(nil, input)
		t.Check(unquoted, equals, output)
	}

	test("", "")
	test("plain", "plain")
	test("plain words", "plain words")
	test("\"dquot\"", "dquot")
	test("\"dquot \\\"escaped\\\\\"", "dquot \"escaped\\")
	test("'squot \\\"escaped\\\\'", "squot \\\"escaped\\\\")
	test("'squot,''squot'", "squot,squot")
	test("\"dquot,\"'squot'", "dquot,squot")
	test("\"'\",'\"'", "',\"")
	test("\\\" \\\\", "\" \\")

	// UnquoteShell does not parse shell variable expansions or even subshells.
	// It therefore must cope with unexpected input and make the best out of it.

	test("\\", "")
	test("\"\\", "")
	test("'", "")
	test("\"$(\"", "$(")
	test("`", "`")
}

func (s *Suite) Test_MkLineParser_unescapeComment(c *check.C) {
	t := s.Init(c)

	test := func(text string, main, comment string) {
		aMain, aComment := MkLineParser{}.unescapeComment(text)
		t.Check(
			[]interface{}{text, aMain, aComment},
			deepEquals,
			[]interface{}{text, main, comment})
	}

	test("",
		"",
		"")
	test("text",
		"text",
		"")

	// The leading space from the comment is preserved to make parsing as exact
	// as possible.
	//
	// The difference between "#defined" and "# defined" is relevant in a few
	// cases, such as the API documentation of the infrastructure files.
	test("# comment",
		"",
		"# comment")
	test("#\tcomment",
		"",
		"#\tcomment")
	test("#   comment",
		"",
		"#   comment")

	// Other than in the shell, # also starts a comment in the middle of a word.
	test("COMMENT=\tThe C# compiler",
		"COMMENT=\tThe C",
		"# compiler")
	test("COMMENT=\tThe C\\# compiler",
		"COMMENT=\tThe C# compiler",
		"")

	test("${TARGET}: ${SOURCES} # comment",
		"${TARGET}: ${SOURCES} ",
		"# comment")

	// A # starts a comment, except if it immediately follows a [.
	// This is done so that the length modifier :[#] can be written without
	// escaping the #.
	test("VAR=\t${OTHER:[#]} # comment",
		"VAR=\t${OTHER:[#]} ",
		"# comment")

	// The # in the :[#] modifier may be escaped or not. Both forms are equivalent.
	test("VAR:=\t${VAR:M-*:[\\#]}",
		"VAR:=\t${VAR:M-*:[#]}",
		"")

	// The character [ prevents the following # from starting a comment, even
	// outside of variable modifiers.
	test("COMMENT=\t[#] $$\\# $$# comment",
		"COMMENT=\t[#] $$# $$",
		"# comment")

	// A backslash always escapes the next character, be it a # for a comment
	// or something else. This makes it difficult to write a literal \# in a
	// Makefile, but that's an edge case anyway.
	test("VAR0=\t#comment",
		"VAR0=\t",
		"#comment")
	test("VAR1=\t\\#no-comment",
		"VAR1=\t#no-comment",
		"")
	test("VAR2=\t\\\\#comment",
		"VAR2=\t\\\\",
		"#comment")

	// The backslash is only removed when it escapes a comment.
	// In particular, it cannot be used to escape a dollar that starts a
	// variable use.
	test("VAR0=\t$T",
		"VAR0=\t$T",
		"")
	test("VAR1=\t\\$T",
		"VAR1=\t\\$T",
		"")
	test("VAR2=\t\\\\$T",
		"VAR2=\t\\\\$T",
		"")

	// To escape a dollar, write it twice.
	test("$$shellvar $${shellvar} \\${MKVAR} [] \\x",
		"$$shellvar $${shellvar} \\${MKVAR} [] \\x",
		"")

	// Parse errors are recorded in the rest return value.
	test("${UNCLOSED",
		"${UNCLOSED",
		"")

	// In this early phase of parsing, unfinished variable uses are not
	// interpreted and do not influence the detection of the comment start.
	test("text before ${UNCLOSED # comment",
		"text before ${UNCLOSED ",
		"# comment")

	// The dollar-space refers to a normal Make variable named " ".
	// The lonely dollar at the very end refers to the variable named "",
	// which is specially protected in bmake to always contain the empty string.
	// It is heavily used in .for loops in the form ${:Uvalue}.
	test("Lonely $ character $",
		"Lonely $ character $",
		"")

	// An even number of backslashes does not escape the #.
	// Therefore it starts a comment here.
	test("VAR2=\t\\\\#comment",
		"VAR2=\t\\\\",
		"#comment")
}

func (s *Suite) Test_MkLineParser_split(c *check.C) {
	t := s.Init(c)

	varuse := func(varname string, modifiers ...string) *MkToken {
		var text strings.Builder
		text.WriteString("${")
		text.WriteString(varname)
		for _, modifier := range modifiers {
			text.WriteString(":")
			text.WriteString(modifier)
		}
		text.WriteString("}")
		return &MkToken{Text: text.String(), Varuse: NewMkVarUse(varname, modifiers...)}
	}
	varuseText := func(text, varname string, modifiers ...string) *MkToken {
		return &MkToken{Text: text, Varuse: NewMkVarUse(varname, modifiers...)}
	}
	text := func(text string) *MkToken {
		return &MkToken{text, nil}
	}
	tokens := func(tokens ...*MkToken) []*MkToken {
		return tokens
	}

	test := func(text string, data mkLineSplitResult, diagnostics ...string) {
		line := t.NewLine("filename.mk", 123, text)
		actualData := MkLineParser{}.split(line, text)

		t.CheckOutput(diagnostics)
		t.Check([]interface{}{text, actualData}, deepEquals, []interface{}{text, data})
	}

	t.Use(text, varuse, varuseText, tokens)

	test(
		"",
		mkLineSplitResult{})

	test(
		"text",
		mkLineSplitResult{
			main:   "text",
			tokens: tokens(text("text")),
		})

	// Leading space is always kept.
	test(
		" text",
		mkLineSplitResult{
			main:   " text",
			tokens: tokens(text(" text")),
		})

	// Trailing space does not end up in the tokens since it is usually
	// ignored.
	test(
		"text\t",
		mkLineSplitResult{
			main:               "text",
			tokens:             tokens(text("text")),
			spaceBeforeComment: "\t",
		})

	test(
		"text\t# intended comment",
		mkLineSplitResult{
			main:               "text",
			tokens:             tokens(text("text")),
			spaceBeforeComment: "\t",
			hasComment:         true,
			comment:            " intended comment",
		})

	// Trailing space is saved in a separate field to detect accidental
	// unescaped # in the middle of a word, like the URL fragment in this
	// example.
	test(
		"url#fragment",
		mkLineSplitResult{
			main:       "url",
			tokens:     tokens(text("url")),
			hasComment: true,
			comment:    "fragment",
		})

	// The leading space from the comment is preserved to make parsing as exact
	// as possible.
	//
	// The difference between "#defined" and "# defined" is relevant in a few
	// cases, such as the API documentation of the infrastructure files.
	test("# comment",
		mkLineSplitResult{
			hasComment: true,
			comment:    " comment",
		})

	test("#\tcomment",
		mkLineSplitResult{
			hasComment: true,
			comment:    "\tcomment",
		})

	test("#   comment",
		mkLineSplitResult{
			hasComment: true,
			comment:    "   comment",
		})

	// Other than in the shell, # also starts a comment in the middle of a word.
	test("COMMENT=\tThe C# compiler",
		mkLineSplitResult{
			main:       "COMMENT=\tThe C",
			tokens:     tokens(text("COMMENT=\tThe C")),
			hasComment: true,
			comment:    " compiler",
		})

	test("COMMENT=\tThe C\\# compiler",
		mkLineSplitResult{
			main:       "COMMENT=\tThe C# compiler",
			tokens:     tokens(text("COMMENT=\tThe C# compiler")),
			hasComment: false,
			comment:    "",
		})

	test("${TARGET}: ${SOURCES} # comment",
		mkLineSplitResult{
			main:               "${TARGET}: ${SOURCES}",
			tokens:             tokens(varuse("TARGET"), text(": "), varuse("SOURCES")),
			spaceBeforeComment: " ",
			hasComment:         true,
			comment:            " comment",
		})

	// A # starts a comment, except if it immediately follows a [.
	// This is done so that the length modifier :[#] can be written without
	// escaping the #.
	test("VAR=\t${OTHER:[#]} # comment",
		mkLineSplitResult{
			main:               "VAR=\t${OTHER:[#]}",
			tokens:             tokens(text("VAR=\t"), varuse("OTHER", "[#]")),
			spaceBeforeComment: " ",
			hasComment:         true,
			comment:            " comment",
		})

	// The # in the :[#] modifier may be escaped or not. Both forms are equivalent.
	test("VAR:=\t${VAR:M-*:[\\#]}",
		mkLineSplitResult{
			main:   "VAR:=\t${VAR:M-*:[#]}",
			tokens: tokens(text("VAR:=\t"), varuse("VAR", "M-*", "[#]")),
		})

	// A backslash always escapes the next character, be it a # for a comment
	// or something else. This makes it difficult to write a literal \# in a
	// Makefile, but that's an edge case anyway.
	test("VAR0=\t#comment",
		mkLineSplitResult{
			main:   "VAR0=",
			tokens: tokens(text("VAR0=")),
			// Later, when converting this result into a proper variable assignment,
			// this "space before comment" is reclassified as "space before the value",
			// in order to align the "#comment" with the other variable values.
			spaceBeforeComment: "\t",
			hasComment:         true,
			comment:            "comment",
		})

	test("VAR1=\t\\#no-comment",
		mkLineSplitResult{
			main:   "VAR1=\t#no-comment",
			tokens: tokens(text("VAR1=\t#no-comment")),
		})

	test("VAR2=\t\\\\#comment",
		mkLineSplitResult{
			main:       "VAR2=\t\\\\",
			tokens:     tokens(text("VAR2=\t\\\\")),
			hasComment: true,
			comment:    "comment",
		})

	// The backslash is only removed when it escapes a comment.
	// In particular, it cannot be used to escape a dollar that starts a
	// variable use.
	test("VAR0=\t$T",
		mkLineSplitResult{
			main:   "VAR0=\t$T",
			tokens: tokens(text("VAR0=\t"), varuseText("$T", "T")),
		},
		"WARN: filename.mk:123: $T is ambiguous. Use ${T} if you mean a Make variable or $$T if you mean a shell variable.")

	test("VAR1=\t\\$T",
		mkLineSplitResult{
			main:   "VAR1=\t\\$T",
			tokens: tokens(text("VAR1=\t\\"), varuseText("$T", "T")),
		},
		"WARN: filename.mk:123: $T is ambiguous. Use ${T} if you mean a Make variable or $$T if you mean a shell variable.")

	test("VAR2=\t\\\\$T",
		mkLineSplitResult{
			main:   "VAR2=\t\\\\$T",
			tokens: tokens(text("VAR2=\t\\\\"), varuseText("$T", "T")),
		},
		"WARN: filename.mk:123: $T is ambiguous. Use ${T} if you mean a Make variable or $$T if you mean a shell variable.")

	// To escape a dollar, write it twice.
	test("$$shellvar $${shellvar} \\${MKVAR} [] \\x",
		mkLineSplitResult{
			main:   "$$shellvar $${shellvar} \\${MKVAR} [] \\x",
			tokens: tokens(text("$$shellvar $${shellvar} \\"), varuse("MKVAR"), text(" [] \\x")),
		})

	// Parse errors are recorded in the rest return value.
	test("${UNCLOSED",
		mkLineSplitResult{
			main:   "${UNCLOSED",
			tokens: tokens(varuseText("${UNCLOSED", "UNCLOSED")),
		},
		"WARN: filename.mk:123: Missing closing \"}\" for \"UNCLOSED\".")

	// Even if there is a parse error in the main part,
	// the comment is extracted.
	test("text before ${UNCLOSED# comment",
		mkLineSplitResult{
			main: "text before ${UNCLOSED",
			tokens: tokens(
				text("text before "),
				varuseText("${UNCLOSED", "UNCLOSED")),
			hasComment: true,
			comment:    " comment",
		},
		"WARN: filename.mk:123: Missing closing \"}\" for \"UNCLOSED\".")

	// Even in case of parse errors, the space before the comment is parsed
	// correctly.
	test("text before ${UNCLOSED # comment",
		mkLineSplitResult{
			main: "text before ${UNCLOSED",
			tokens: tokens(
				text("text before "),
				// It's a bit inconsistent that the varname includes the space
				// but the text doesn't; anyway, it's an edge case.
				varuseText("${UNCLOSED", "UNCLOSED ")),
			spaceBeforeComment: " ",
			hasComment:         true,
			comment:            " comment",
		},
		"WARN: filename.mk:123: Missing closing \"}\" for \"UNCLOSED \".",
		"WARN: filename.mk:123: Invalid part \" \" after variable name \"UNCLOSED\".")

	// The dollar-space refers to a normal Make variable named " ".
	// The lonely dollar at the very end refers to the variable named "",
	// which is specially protected in bmake to always contain the empty string.
	// It is heavily used in .for loops in the form ${:Uvalue}.
	//
	// TODO: The rest of pkglint assumes that the empty string is not a valid
	//  variable name, mainly because the empty variable name is not visible
	//  outside of the bmake debugging mode.
	test("Lonely $ character $",
		mkLineSplitResult{
			main: "Lonely $ character $",
			tokens: tokens(
				text("Lonely "),
				varuseText("$ " /* instead of "${ }" */, " "),
				text("character "),
				text("$")),
		})

	// The character [ prevents the following # from starting a comment, even
	// outside of variable modifiers.
	test("COMMENT=\t[#] $$\\# $$# comment",
		mkLineSplitResult{
			main:       "COMMENT=\t[#] $$# $$",
			tokens:     tokens(text("COMMENT=\t[#] $$# $$")),
			hasComment: true,
			comment:    " comment",
		})

	test("VAR2=\t\\\\#comment",
		mkLineSplitResult{
			main:       "VAR2=\t\\\\",
			tokens:     tokens(text("VAR2=\t\\\\")),
			hasComment: true,
			comment:    "comment",
		})

	// At this stage, MkLine.split doesn't know that empty(...) takes
	// a variable use. Instead it just sees ordinary characters and
	// other uses of variables.
	test(".if empty(${VAR.${tool}}:C/\\:.*$//:M${pattern})",
		mkLineSplitResult{
			main: ".if empty(${VAR.${tool}}:C/\\:.*$//:M${pattern})",
			tokens: tokens(
				text(".if empty("),
				varuse("VAR.${tool}"),
				text(":C/\\:.*"),
				text("$"),
				text("//:M"),
				varuse("pattern"),
				text(")")),
		})

	test("   # comment after spaces",
		mkLineSplitResult{
			spaceBeforeComment: "   ",
			hasComment:         true,
			comment:            " comment after spaces",
		})
}

func (s *Suite) Test_MkLineParser_parseDirective(c *check.C) {
	t := s.Init(c)

	test := func(input, expectedIndent, expectedDirective, expectedArgs, expectedComment string, diagnostics ...string) {
		line := t.NewLine("filename.mk", 123, input)
		data := MkLineParser{}.split(line, input)
		mkline := MkLineParser{}.parseDirective(line, data)
		if !c.Check(mkline, check.NotNil) {
			return
		}

		c.Check(
			[]interface{}{mkline.Indent(), mkline.Directive(), mkline.Args(), mkline.DirectiveComment()},
			deepEquals,
			[]interface{}{expectedIndent, expectedDirective, expectedArgs, expectedComment})
		t.CheckOutput(diagnostics)
	}

	test(".if ${VAR} == value",
		"", "if", "${VAR} == value", "")

	test(".\tendif # comment",
		"\t", "endif", "", "comment")

	test(".if ${VAR} == \"#\"",
		"", "if", "${VAR} == \"", "\"")

	test(".if ${VAR:[#]}",
		"", "if", "${VAR:[#]}", "")

	test(".if ${VAR} == \\",
		"", "if", "${VAR} == \\", "")

	test(".if ${VAR",
		"", "if", "${VAR", "",
		"WARN: filename.mk:123: Missing closing \"}\" for \"VAR\".")
}

func (s *Suite) Test_MatchMkInclude(c *check.C) {
	t := s.Init(c)

	test := func(input, expectedIndent, expectedDirective, expectedFilename string) {
		m, indent, directive, args := MatchMkInclude(input)
		c.Check(
			[]interface{}{m, indent, directive, args},
			deepEquals,
			[]interface{}{true, expectedIndent, expectedDirective, expectedFilename})
	}

	testFail := func(input string) {
		m, _, _, _ := MatchMkInclude(input)
		if m {
			c.Errorf("Text %q unexpectedly matched.", input)
		}
	}

	testFail("")
	testFail(".")
	testFail(".include")
	testFail(".include \"")
	testFail(".include \"other.mk")
	testFail(".include \"other.mk\" \"")

	test(".include \"other.mk\"",
		"", "include", "other.mk")

	test(".include \"other.mk\"\t",
		"", "include", "other.mk")

	test(".include \"other.mk\"\t#",
		"", "include", "other.mk")

	test(".include \"other.mk\"\t# comment",
		"", "include", "other.mk")

	t.CheckOutputEmpty()
}
