package main

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_MkLines_Check__autofix_conditional_indentation(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--autofix", "-Wspace")
	lines := t.SetupFileLines("fname.mk",
		MkRcsId,
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
		MkRcsId,
		"",
		"echo: echo.c",
		"\tcc -o ${.TARGET} ${.IMPSRC}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:3: Unusual target \"echo\".")
}

func (s *Suite) Test_MkLineChecker_checkInclude__Makefile(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("Makefile", 2, ".include \"../../other/package/Makefile\"")

	MkLineChecker{mkline}.checkInclude()

	t.CheckOutputLines(
		"ERROR: Makefile:2: \"/other/package/Makefile\" does not exist.",
		"ERROR: Makefile:2: Other Makefiles must not be included directly.")
}

func (s *Suite) Test_MkLines_quoting_LDFLAGS_for_GNU_configure(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	G.globalData.InitVartypes()
	G.Pkg = NewPackage("category/pkgbase")
	mklines := t.NewMkLines("Makefile",
		MkRcsId,
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
		MkRcsId,
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
	G.globalData.InitVartypes()
	mklines := t.NewMkLines("databases/gdbm_compat/builtin.mk",
		MkRcsId,
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
	G.globalData.InitVartypes()
	mklines := t.NewMkLines("lang/qore/module.mk",
		MkRcsId,
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
	G.globalData.InitVartypes()
	mklines := t.NewMkLines("converters/wv2/Makefile",
		MkRcsId,
		"CONFIGURE_ARGS+=\t\t${CONFIGURE_ARGS.${ICONV_TYPE}-iconv}",
		"CONFIGURE_ARGS.gnu-iconv=\t--with-libiconv=${BUILDLINK_PREFIX.iconv}")

	mklines.Check()

	// No warnings about defined but not used or vice versa
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines__loop_modifier(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	G.globalData.InitVartypes()
	mklines := t.NewMkLines("chat/xchat/Makefile",
		MkRcsId,
		"GCONF_SCHEMAS=\tapps_xchat_url_handler.schemas",
		"post-install:",
		"\t${GCONF_SCHEMAS:@.s.@"+
			"${INSTALL_DATA} ${WRKSRC}/src/common/dbus/${.s.} ${DESTDIR}${GCONF_SCHEMAS_DIR}/@}")

	mklines.Check()

	t.CheckOutputLines(
		// No warning about missing @ at the end
		"WARN: chat/xchat/Makefile:4: " +
			"Unknown shell command \"${GCONF_SCHEMAS:@.s.@" +
			"${INSTALL_DATA} ${WRKSRC}/src/common/dbus/${.s.} ${DESTDIR}${GCONF_SCHEMAS_DIR}/@}\".")
}

// PR 46570
func (s *Suite) Test_MkLines__PKG_SKIP_REASON_depending_on_OPSYS(c *check.C) {
	t := s.Init(c)

	G.globalData.InitVartypes()
	mklines := t.NewMkLines("Makefile",
		MkRcsId,
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
		MkRcsId,
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
		MkRcsId,
		"\tcd ${WRKSRC} && tr '\\r' '\\n' < ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} > chef.l")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: converters/chef/Makefile:2: Unknown shell command \"tr\".",
		"WARN: converters/chef/Makefile:2: The list variable DISTFILES should not be embedded in a word.")
}

func (s *Suite) Test_MkLines_Check__absolute_pathname_depending_on_OPSYS(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	G.globalData.InitVartypes()
	mklines := t.NewMkLines("games/heretic2-demo/Makefile",
		MkRcsId,
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
		MkRcsId,
		"",
		"# used by sysutils/mc",
	).checkForUsedComment("sysutils/mc")

	t.CheckOutputEmpty()

	t.NewMkLines("Makefile.common").checkForUsedComment("category/package")

	t.CheckOutputEmpty()

	t.NewMkLines("Makefile.common",
		MkRcsId,
	).checkForUsedComment("category/package")

	t.CheckOutputEmpty()

	t.NewMkLines("Makefile.common",
		MkRcsId,
		"",
	).checkForUsedComment("category/package")

	t.CheckOutputEmpty()

	t.NewMkLines("Makefile.common",
		MkRcsId,
		"",
		"VARNAME=\tvalue",
	).checkForUsedComment("category/package")

	t.CheckOutputLines(
		"WARN: Makefile.common:2: Please add a line \"# used by category/package\" here.",
		"AUTOFIX: Makefile.common:2: Inserting a line \"# used by category/package\" before this line.")

	t.NewMkLines("Makefile.common",
		MkRcsId,
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

	c.Check(len(mklines.varuse), equals, 1)
	c.Check(mklines.varuse["VAR"], equals, mkline)
}

func (s *Suite) Test_MkLines_DetermineUsedVariables__nested(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("fname",
		"\t${outer.${inner}}")
	mkline := mklines.mklines[0]
	G.Mk = mklines

	mklines.DetermineUsedVariables()

	c.Check(len(mklines.varuse), equals, 3)
	c.Check(mklines.varuse["inner"], equals, mkline)
	c.Check(mklines.varuse["outer."], equals, mkline)
	c.Check(mklines.varuse["outer.*"], equals, mkline)
}

func (s *Suite) Test_MkLines_PrivateTool_Undefined(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	G.globalData.InitVartypes()
	mklines := t.NewMkLines("fname",
		MkRcsId,
		"",
		"\tmd5sum filename")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: fname:3: Unknown shell command \"md5sum\".")
}

func (s *Suite) Test_MkLines_PrivateTool_Defined(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	G.globalData.InitVartypes()
	mklines := t.NewMkLines("fname",
		MkRcsId,
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
		MkRcsId,
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
		"ERROR: options.mk:11: \".else\" does not take arguments.",
		"NOTE: options.mk:11: If you meant \"else if\", use \".elif\".",
		"NOTE: options.mk:12: This directive should be indented by 2 spaces.",
		"NOTE: options.mk:13: This directive should be indented by 0 spaces.",
		"NOTE: options.mk:14: This directive should be indented by 0 spaces.",
		"ERROR: options.mk:15: Unmatched .endif.",
		"NOTE: options.mk:15: This directive should be indented by 0 spaces.")
}

// Demonstrates how to define your own make(1) targets.
func (s *Suite) Test_MkLines_wip_category_Makefile(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	G.globalData.InitVartypes()
	t.SetupTool(&Tool{Name: "rm", Varname: "RM", Predefined: true})
	mklines := t.NewMkLines("Makefile",
		MkRcsId,
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
		".include \"../../mk/misc/category.mk\"")

	mklines.Check()

	t.CheckOutputLines(
		"ERROR: Makefile:14: \"/mk/misc/category.mk\" does not exist.")
}
