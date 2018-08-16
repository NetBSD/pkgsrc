package main

import (
	"fmt"
	"gopkg.in/check.v1"
	"sort"
)

func (s *Suite) Test_MkLines_Check__autofix_directive_indentation(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--autofix", "-Wspace")
	lines := t.SetupFileLines("fname.mk",
		MkRcsID,
		".if defined(A)",
		".for a in ${A}",
		".if defined(C)",
		".endif",
		".endfor",
		".endif")
	mklines := NewMkLines(lines)

	mklines.Check()

	t.CheckOutputLines(
		"AUTOFIX: ~/fname.mk:3: Replacing \".\" with \".  \".",
		"AUTOFIX: ~/fname.mk:4: Replacing \".\" with \".    \".",
		"AUTOFIX: ~/fname.mk:5: Replacing \".\" with \".    \".",
		"AUTOFIX: ~/fname.mk:6: Replacing \".\" with \".  \".")
	t.CheckFileLines("fname.mk",
		"# $"+"NetBSD$",
		".if defined(A)",
		".  for a in ${A}",
		".    if defined(C)",
		".    endif",
		".  endfor",
		".endif")
}

func (s *Suite) Test_MkLines_Check__unusual_target(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"echo: echo.c",
		"\tcc -o ${.TARGET} ${.IMPSRC}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:3: Unusual target \"echo\".")
}

func (s *Suite) Test_MkLineChecker_checkInclude__Makefile(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine(t.File("Makefile"), 2, ".include \"../../other/package/Makefile\"")

	MkLineChecker{mkline}.checkInclude()

	t.CheckOutputLines(
		"ERROR: ~/Makefile:2: \"other/package/Makefile\" does not exist.",
		"ERROR: ~/Makefile:2: Other Makefiles must not be included directly.")
}

func (s *Suite) Test_MkLines_quoting_LDFLAGS_for_GNU_configure(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	G.Pkg = NewPackage(t.File("category/pkgbase"))
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"GNU_CONFIGURE=\tyes",
		"CONFIGURE_ENV+=\tX_LIBS=${X11_LDFLAGS:Q}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:3: Please use ${X11_LDFLAGS:M*:Q} instead of ${X11_LDFLAGS:Q}.",
		"WARN: Makefile:3: Please use ${X11_LDFLAGS:M*:Q} instead of ${X11_LDFLAGS:Q}.")
}

func (s *Suite) Test_MkLines__for_loop_multiple_variables(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupTool(&Tool{Name: "echo", Varname: "ECHO", Predefined: true})
	t.SetupTool(&Tool{Name: "find", Varname: "FIND", Predefined: true})
	t.SetupTool(&Tool{Name: "pax", Varname: "PAX", Predefined: true})
	mklines := t.NewMkLines("Makefile", // From audio/squeezeboxserver
		MkRcsID,
		"",
		".for _list_ _dir_ in ${SBS_COPY}",
		"\tcd ${WRKSRC} && ${FIND} ${${_list_}} -type f ! -name '*.orig' 2>/dev/null "+
			"| pax -rw -pm ${DESTDIR}${PREFIX}/${${_dir_}}",
		".endfor")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:3: Variable names starting with an underscore (_list_) are reserved for internal pkgsrc use.",
		"WARN: Makefile:3: Variable names starting with an underscore (_dir_) are reserved for internal pkgsrc use.",
		"WARN: Makefile:4: The exitcode of \"${FIND}\" at the left of the | operator is ignored.")
}

func (s *Suite) Test_MkLines__comparing_YesNo_variable_to_string(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	mklines := t.NewMkLines("databases/gdbm_compat/builtin.mk",
		MkRcsID,
		".if ${USE_BUILTIN.gdbm} == \"no\"",
		".endif",
		".if ${USE_BUILTIN.gdbm:tu} == \"no\"", // Can never be true, since "no" is not uppercase.
		".endif")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: databases/gdbm_compat/builtin.mk:2: " +
			"USE_BUILTIN.gdbm should be matched against \"[yY][eE][sS]\" or \"[nN][oO]\", not compared with \"no\".")
}

func (s *Suite) Test_MkLines__varuse_sh_modifier(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	mklines := t.NewMkLines("lang/qore/module.mk",
		MkRcsID,
		"qore-version=\tqore --short-version | ${SED} -e s/-.*//",
		"PLIST_SUBST+=\tQORE_VERSION=\"${qore-version:sh}\"")

	vars2 := mklines.mklines[1].DetermineUsedVariables()

	c.Check(vars2, deepEquals, []string{"SED"})

	vars3 := mklines.mklines[2].DetermineUsedVariables()

	c.Check(vars3, deepEquals, []string{"qore-version"})

	mklines.Check()

	// No warnings about defined but not used or vice versa
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines__varuse_parameterized(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	mklines := t.NewMkLines("converters/wv2/Makefile",
		MkRcsID,
		"CONFIGURE_ARGS+=\t\t${CONFIGURE_ARGS.${ICONV_TYPE}-iconv}",
		"CONFIGURE_ARGS.gnu-iconv=\t--with-libiconv=${BUILDLINK_PREFIX.iconv}")

	mklines.Check()

	// No warnings about defined but not used or vice versa
	t.CheckOutputEmpty()
}

// Even very complicated shell commands are parsed correctly.
// Since the variable is defined in this same Makefile, it is
// assumed to be a known shell command and therefore does not need
// USE_TOOLS or a similar declaration.
func (s *Suite) Test_MkLines__loop_modifier(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	mklines := t.NewMkLines("chat/xchat/Makefile",
		MkRcsID,
		"GCONF_SCHEMAS=\tapps_xchat_url_handler.schemas",
		"post-install:",
		"\t${GCONF_SCHEMAS:@.s.@"+
			"${INSTALL_DATA} ${WRKSRC}/src/common/dbus/${.s.} ${DESTDIR}${GCONF_SCHEMAS_DIR}/@}")

	mklines.Check()

	// Earlier versions of pkglint warned about a missing @ at the end.
	t.CheckOutputEmpty()
}

// PR 46570
func (s *Suite) Test_MkLines__PKG_SKIP_REASON_depending_on_OPSYS(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"PKG_SKIP_REASON+=\t\"Fails everywhere\"",
		".if ${OPSYS} == \"Cygwin\"",
		"PKG_SKIP_REASON+=\t\"Fails on Cygwin\"",
		".endif")

	mklines.Check()

	t.CheckOutputLines(
		"NOTE: Makefile:4: Consider defining NOT_FOR_PLATFORM instead of setting PKG_SKIP_REASON depending on ${OPSYS}.")
}

// PR 46570, item "15. net/uucp/Makefile has a make loop"
func (s *Suite) Test_MkLines__indirect_variables(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	mklines := t.NewMkLines("net/uucp/Makefile",
		MkRcsID,
		"",
		"post-configure:",
		".for var in MAIL_PROGRAM CMDPATH",
		"\t"+`${RUN} ${ECHO} "#define ${var} \""${UUCP_${var}}"\"`,
		".endfor")

	mklines.Check()

	// No warning about UUCP_${var} being used but not defined.
	t.CheckOutputLines(
		"WARN: net/uucp/Makefile:5: Unknown shell command \"${ECHO}\".")
}

func (s *Suite) Test_MkLines_Check__list_variable_as_part_of_word(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	mklines := t.NewMkLines("converters/chef/Makefile",
		MkRcsID,
		"\tcd ${WRKSRC} && tr '\\r' '\\n' < ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} > chef.l")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: converters/chef/Makefile:2: Unknown shell command \"tr\".",
		"WARN: converters/chef/Makefile:2: The list variable DISTFILES should not be embedded in a word.")
}

func (s *Suite) Test_MkLines_Check__absolute_pathname_depending_on_OPSYS(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	mklines := t.NewMkLines("games/heretic2-demo/Makefile",
		MkRcsID,
		".if ${OPSYS} == \"DragonFly\"",
		"TOOLS_PLATFORM.gtar=\t/usr/bin/bsdtar",
		".endif",
		"TOOLS_PLATFORM.gtar=\t/usr/bin/bsdtar")

	mklines.Check()

	// No warning about an unknown shell command in line 3,
	// since that line depends on OPSYS.
	t.CheckOutputLines(
		"WARN: games/heretic2-demo/Makefile:3: The variable TOOLS_PLATFORM.gtar may not be set by any package.",
		"WARN: games/heretic2-demo/Makefile:5: The variable TOOLS_PLATFORM.gtar may not be set by any package.",
		"WARN: games/heretic2-demo/Makefile:5: Unknown shell command \"/usr/bin/bsdtar\".")
}

func (s *Suite) Test_MkLines_checkForUsedComment(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--show-autofix")
	t.NewMkLines("Makefile.common",
		MkRcsID,
		"",
		"# used by sysutils/mc",
	).checkForUsedComment("sysutils/mc")

	t.CheckOutputEmpty()

	t.NewMkLines("Makefile.common").checkForUsedComment("category/package")

	t.CheckOutputEmpty()

	t.NewMkLines("Makefile.common",
		MkRcsID,
	).checkForUsedComment("category/package")

	t.CheckOutputEmpty()

	t.NewMkLines("Makefile.common",
		MkRcsID,
		"",
	).checkForUsedComment("category/package")

	t.CheckOutputEmpty()

	t.NewMkLines("Makefile.common",
		MkRcsID,
		"",
		"VARNAME=\tvalue",
	).checkForUsedComment("category/package")

	t.CheckOutputLines(
		"WARN: Makefile.common:2: Please add a line \"# used by category/package\" here.",
		"AUTOFIX: Makefile.common:2: Inserting a line \"# used by category/package\" before this line.")

	t.NewMkLines("Makefile.common",
		MkRcsID,
		"#",
		"#",
	).checkForUsedComment("category/package")

	t.CheckOutputLines(
		"WARN: Makefile.common:3: Please add a line \"# used by category/package\" here.",
		"AUTOFIX: Makefile.common:3: Inserting a line \"# used by category/package\" before this line.")

	c.Check(G.autofixAvailable, equals, true)
}

func (s *Suite) Test_MkLines_DetermineUsedVariables__simple(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("fname",
		"\t${VAR}")
	mkline := mklines.mklines[0]
	G.Mk = mklines

	mklines.DetermineUsedVariables()

	c.Check(len(mklines.vars.used), equals, 1)
	c.Check(mklines.vars.FirstUse("VAR"), equals, mkline)
}

func (s *Suite) Test_MkLines_DetermineUsedVariables__nested(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("fname",
		"\t${outer.${inner}}")
	mkline := mklines.mklines[0]
	G.Mk = mklines

	mklines.DetermineUsedVariables()

	c.Check(len(mklines.vars.used), equals, 3)
	c.Check(mklines.vars.FirstUse("inner"), equals, mkline)
	c.Check(mklines.vars.FirstUse("outer."), equals, mkline) // XXX: why the . at the end?
	c.Check(mklines.vars.FirstUse("outer.*"), equals, mkline)
}

func (s *Suite) Test_MkLines_PrivateTool_Undefined(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	mklines := t.NewMkLines("fname",
		MkRcsID,
		"",
		"\tmd5sum filename")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: fname:3: Unknown shell command \"md5sum\".")
}

func (s *Suite) Test_MkLines_PrivateTool_Defined(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	mklines := t.NewMkLines("fname",
		MkRcsID,
		"TOOLS_CREATE+=\tmd5sum",
		"",
		"\tmd5sum filename")

	mklines.Check()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines_Check_indentation(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	mklines := t.NewMkLines("options.mk",
		MkRcsID,
		". if !defined(GUARD_MK)",
		". if ${OPSYS} == ${OPSYS}",
		".   for i in ${FILES}",
		".     if !defined(GUARD2_MK)",
		".     else",
		".     endif",
		".   endfor",
		".   if ${COND1}",
		".   elif ${COND2}",
		".   else ${COND3}",
		".   endif",
		". endif",
		". endif",
		". endif")

	mklines.Check()

	t.CheckOutputLines(""+
		"NOTE: options.mk:2: This directive should be indented by 0 spaces.",
		"NOTE: options.mk:3: This directive should be indented by 0 spaces.",
		"NOTE: options.mk:4: This directive should be indented by 2 spaces.",
		"NOTE: options.mk:5: This directive should be indented by 4 spaces.",
		"NOTE: options.mk:6: This directive should be indented by 4 spaces.",
		"NOTE: options.mk:7: This directive should be indented by 4 spaces.",
		"NOTE: options.mk:8: This directive should be indented by 2 spaces.",
		"NOTE: options.mk:9: This directive should be indented by 2 spaces.",
		"NOTE: options.mk:10: This directive should be indented by 2 spaces.",
		"NOTE: options.mk:11: This directive should be indented by 2 spaces.",
		"ERROR: options.mk:11: \".else\" does not take arguments. If you meant \"else if\", use \".elif\".",
		"NOTE: options.mk:12: This directive should be indented by 2 spaces.",
		"NOTE: options.mk:13: This directive should be indented by 0 spaces.",
		"NOTE: options.mk:14: This directive should be indented by 0 spaces.",
		"NOTE: options.mk:15: This directive should be indented by 0 spaces.",
		"ERROR: options.mk:15: Unmatched .endif.")
}

func (s *Suite) Test_MkLines_Check__endif_comment(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	mklines := t.NewMkLines("opsys.mk",
		MkRcsID,
		"",
		".for i in 1 2 3 4 5",
		".  if ${OPSYS} == NetBSD",
		".    if ${ARCH} == x86_64",
		".      if ${OS_VERSION:M8.*}",
		".      endif # ARCH",     // Wrong, should be OS_VERSION.
		".    endif # OS_VERSION", // Wrong, should be ARCH.
		".  endif # OPSYS",        // Correct.
		".endfor # j",             // Wrong, should be i.
		"",
		".if ${PKG_OPTIONS:Moption}",
		".endif # option",
		"",
		".if ${PKG_OPTIONS:Moption}",
		".endif # opti", // This typo gets unnoticed since "opti" is a substring of the condition.
		"",
		".if ${OPSYS} == NetBSD",
		".elif ${OPSYS} == FreeBSD",
		".endif # NetBSD") // Wrong, should be FreeBSD from the .elif.

	// See MkLineChecker.checkDirective
	mklines.Check()

	t.CheckOutputLines(""+
		"WARN: opsys.mk:7: Comment \"ARCH\" does not match condition \"${OS_VERSION:M8.*}\".",
		"WARN: opsys.mk:8: Comment \"OS_VERSION\" does not match condition \"${ARCH} == x86_64\".",
		"WARN: opsys.mk:10: Comment \"j\" does not match loop \"i in 1 2 3 4 5\".",
		"WARN: opsys.mk:20: Comment \"NetBSD\" does not match condition \"${OPSYS} == FreeBSD\".")
}

// Demonstrates how to define your own make(1) targets for creating
// files in the current directory. The pkgsrc-wip category Makefile
// does this, while all other categories don't need any custom code.
func (s *Suite) Test_MkLines_wip_category_Makefile(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall", "--explain")
	t.SetupVartypes()
	t.SetupTool(&Tool{Name: "rm", Varname: "RM", Predefined: true})
	t.CreateFileLines("mk/misc/category.mk")
	mklines := t.SetupFileMkLines("wip/Makefile",
		MkRcsID,
		"",
		"COMMENT=\tWIP pkgsrc packages",
		"",
		"SUBDIR+=\taaa",
		"SUBDIR+=\tzzz",
		"",
		"${.CURDIR}/PKGDB:",
		"\t${RM} -f ${.CURDIR}/PKGDB",
		"",
		"${.CURDIR}/INDEX:",
		"\t${RM} -f ${.CURDIR}/INDEX",
		"",
		"clean-tmpdir:",
		"\t${RUN} rm -rf tmpdir",
		"",
		".include \"../mk/misc/category.mk\"")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/wip/Makefile:14: Unusual target \"clean-tmpdir\".",
		"",
		"\tIf you want to define your own target, declare it like this:",
		"\t",
		"\t\t.PHONY: my-target",
		"\t",
		"\tIn the rare case that you actually want a file-based make(1)",
		"\ttarget, write it like this:",
		"\t",
		"\t\t${.CURDIR}/my-filename:",
		"")
}

func (s *Suite) Test_MkLines_ExtractDocumentedVariables(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	t.SetupTool(&Tool{Name: "rm", Varname: "RM", Predefined: true})
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"#",
		"# User-settable variables:",
		"#",
		"# PKG_DEBUG_LEVEL",
		"#\tHow verbose should pkgsrc be when running shell commands?",
		"#",
		"#\t* 0:\tdon't show most shell ...",
		"",
		"# PKG_VERBOSE",
		"#\tWhen this variable is defined, pkgsrc gets a bit more verbose",
		"#\t(i.e. \"-v\" option is passed to some commands ...",
		"",
		"# VARIABLE",
		"#\tA paragraph of a single line is not enough to be recognized as \"relevant\".",
		"",
		"# VARBASE1.<param1>",
		"# VARBASE2.*",
		"# VARBASE3.${id}")

	// The variables that appear in the documentation are marked as
	// used, to prevent the "defined but not used" warnings.
	mklines.determineDocumentedVariables()

	var varnames []string
	for varname, mkline := range mklines.vars.used {
		varnames = append(varnames, fmt.Sprintf("%s (line %s)", varname, mkline.Linenos()))
	}
	sort.Strings(varnames)

	expected := []string{
		"PKG_DEBUG_LEVEL (line 5)",
		"PKG_VERBOSE (line 10)",
		"VARBASE1.* (line 17)",
		"VARBASE2.* (line 18)",
		"VARBASE3.${id} (line 19)",
		"VARBASE3.* (line 19)"}
	c.Check(varnames, deepEquals, expected)
}

func (s *Suite) Test_MkLines__shell_command_indentation(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"#",
		"pre-configure:",
		"\tcd 'indented correctly'",
		"\t\tcd 'indented needlessly'",
		"\tcd 'indented correctly' \\",
		"\t\t&& cd 'with indented continuation'")

	mklines.Check()

	t.CheckOutputLines(
		"NOTE: Makefile:5: Shell programs should be indented with a single tab.")
}

func (s *Suite) Test_MkLines__unknown_options(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	t.SetupOption("known", "")
	mklines := t.NewMkLines("options.mk",
		MkRcsID,
		"#",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.pkgbase",
		"PKG_SUPPORTED_OPTIONS=\tknown unknown",
		"PKG_SUGGESTED_OPTIONS=\tknown unknown")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: options.mk:4: Unknown option \"unknown\".")
}

func (s *Suite) Test_MkLines_CheckRedundantVariables(c *check.C) {
	t := s.Init(c)
	included := t.NewMkLines("module.mk",
		"VAR=\tvalue ${OTHER}",
		"VAR?=\tvalue ${OTHER}",
		"VAR=\tnew value")
	makefile := t.NewMkLines("Makefile",
		"VAR=\tthe package may overwrite variables from other files")
	allLines := append(append([]Line(nil), included.lines...), makefile.lines...)
	mklines := NewMkLines(allLines)

	// XXX: The warnings from here are not in the same order as the other warnings.
	// XXX: There may be some warnings for the same file separated by warnings for other files.
	mklines.CheckRedundantVariables()

	t.CheckOutputLines(
		"NOTE: module.mk:1: Definition of VAR is redundant because of line 2.",
		"WARN: module.mk:1: Variable VAR is overwritten in line 3.")
}

func (s *Suite) Test_MkLines_CheckRedundantVariables__different_value(c *check.C) {
	t := s.Init(c)
	mklines := t.NewMkLines("module.mk",
		"VAR=\tvalue ${OTHER}",
		"VAR?=\tdifferent value")

	mklines.CheckRedundantVariables()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines_CheckRedundantVariables__overwrite_same_value(c *check.C) {
	t := s.Init(c)
	mklines := t.NewMkLines("module.mk",
		"VAR=\tvalue ${OTHER}",
		"VAR=\tvalue ${OTHER}")

	mklines.CheckRedundantVariables()

	t.CheckOutputLines(
		"NOTE: module.mk:1: Definition of VAR is redundant because of line 2.")
}

func (s *Suite) Test_MkLines_CheckRedundantVariables__procedure_call(c *check.C) {
	t := s.Init(c)
	mklines := t.NewMkLines("mk/pthread.buildlink3.mk",
		"CHECK_BUILTIN.pthread:=\tyes",
		".include \"../../mk/pthread.builtin.mk\"",
		"CHECK_BUILTIN.pthread:=\tno")

	mklines.CheckRedundantVariables()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines_Check__PLIST_VARS(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wno-space")
	t.SetupVartypes()
	t.SetupOption("both", "")
	t.SetupOption("only-added", "")
	t.SetupOption("only-defined", "")

	mklines := t.SetupFileMkLines("options.mk",
		MkRcsID,
		"",
		"PKG_OPTIONS_VAR=        PKG_OPTIONS.pkg",
		"PKG_SUPPORTED_OPTIONS=  both only-added only-defined",
		"PKG_SUGGESTED_OPTIONS=  # none",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		"PLIST_VARS+=            both only-added",
		"",
		".if !empty(PKG_OPTIONS:Mboth)",
		"PLIST.both=             yes",
		".endif",
		"",
		".if !empty(PKG_OPTIONS:Monly-defined)",
		"PLIST.only-defined=     yes",
		".endif")

	mklines.Check()

	t.CheckOutputLines(
		"ERROR: ~/options.mk:7: \"mk/bsd.options.mk\" does not exist.", // Not relevant for this test.
		"WARN: ~/options.mk:9: \"only-added\" is added to PLIST_VARS, but PLIST.only-added is not defined in this file.",
		"WARN: ~/options.mk:16: PLIST.only-defined is defined, but \"only-defined\" is not added to PLIST_VARS in this file.")
}

func (s *Suite) Test_MkLines_Check__PLIST_VARS_indirect(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wno-space")
	t.SetupVartypes()
	t.SetupOption("option1", "")
	t.SetupOption("option2", "")

	mklines := t.SetupFileMkLines("module.mk",
		MkRcsID,
		"",
		"MY_PLIST_VARS=  option1 option2",
		"PLIST_VARS+=    ${MY_PLIST_VARS}",
		".for option in option3",
		"PLIST_VARS+=    ${option}",
		".endfor",
		"",
		".if 0",
		"PLIST.option1=  yes",
		".endif",
		"",
		".if 1",
		"PLIST.option2=  yes",
		".endif")

	mklines.Check()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines_Check__if_else(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wno-space")
	t.SetupVartypes()

	mklines := t.NewMkLines("module.mk",
		MkRcsID,
		"",
		".if 0",
		".endif",
		"",
		".if 0",
		".else",
		".endif",
		"",
		".if 0",
		".elif 0",
		".endif")

	mklines.collectElse()

	c.Check(mklines.mklines[2].HasElseBranch(), equals, false)
	c.Check(mklines.mklines[5].HasElseBranch(), equals, true)
	c.Check(mklines.mklines[9].HasElseBranch(), equals, false)
}

func (s *Suite) Test_MkLines_Check__defined_and_used_variables(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wno-space")
	t.SetupVartypes()

	mklines := t.NewMkLines("module.mk",
		MkRcsID,
		"",
		".for lang in de fr",
		"PLIST_VARS+=            ${lang}",
		".endif",
		"",
		".for language in de fr",
		"PLIST.${language}=      yes",
		".endif",
		"",
		"PLIST.other=            yes")

	mklines.Check()

	// If there are variable involved in the definition of PLIST_VARS or PLIST.*,
	// it becomes too difficult for pkglint to decide whether the IDs can still match.
	// Therefore, in such a case, no diagnostics are logged at all.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines_Check__indirect_PLIST_VARS(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wno-space")
	t.SetupVartypes()
	t.SetupOption("a", "")
	t.SetupOption("b", "")
	t.SetupOption("c", "")

	mklines := t.NewMkLines("module.mk",
		MkRcsID,
		"",
		"PKG_SUPPORTED_OPTIONS=  a b c",
		"PLIST_VARS+=            ${PKG_SUPPORTED_OPTIONS:S,a,,g}",
		"",
		"PLIST_VARS+=            only-added",
		"",
		"PLIST.only-defined=     yes")

	mklines.Check()

	// If the PLIST_VARS contain complex expressions that involve other variables,
	// it becomes too difficult for pkglint to decide whether the IDs can still match.
	// Therefore, in such a case, no diagnostics are logged at all.
	t.CheckOutputEmpty()
}
