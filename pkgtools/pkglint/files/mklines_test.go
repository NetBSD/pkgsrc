package main

import (
	check "gopkg.in/check.v1"
)

const mkrcsid = "# $" + "NetBSD$"

func (s *Suite) Test_MkLines_Check__autofix_conditional_indentation(c *check.C) {
	s.Init(c)
	s.UseCommandLine("--autofix", "-Wspace")
	tmpfile := s.CreateTmpFile("fname.mk", "")
	mklines := s.NewMkLines(tmpfile,
		mkrcsid,
		".if defined(A)",
		".for a in ${A}",
		".if defined(C)",
		".endif",
		".endfor",
		".endif")

	mklines.Check()

	s.CheckOutputLines(
		"AUTOFIX: ~/fname.mk:3: Replacing \".\" with \".  \".",
		"AUTOFIX: ~/fname.mk:4: Replacing \".\" with \".    \".",
		"AUTOFIX: ~/fname.mk:5: Replacing \".\" with \".    \".",
		"AUTOFIX: ~/fname.mk:6: Replacing \".\" with \".  \".",
		"AUTOFIX: ~/fname.mk: Has been auto-fixed. Please re-run pkglint.")
	c.Check(s.LoadTmpFile("fname.mk"), equals, ""+
		"# $"+"NetBSD$\n"+
		".if defined(A)\n"+
		".  for a in ${A}\n"+
		".    if defined(C)\n"+
		".    endif\n"+
		".  endfor\n"+
		".endif\n")
}

func (s *Suite) Test_MkLines_Check__unusual_target(c *check.C) {
	s.Init(c)
	mklines := s.NewMkLines("Makefile",
		mkrcsid,
		"",
		"echo: echo.c",
		"\tcc -o ${.TARGET} ${.IMPSRC}")

	mklines.Check()

	s.CheckOutputLines(
		"WARN: Makefile:3: Unusual target \"echo\".")
}

func (s *Suite) Test_MkLineChecker_checkInclude__Makefile(c *check.C) {
	s.Init(c)
	mkline := NewMkLine(NewLine("Makefile", 2, ".include \"../../other/package/Makefile\"", nil))

	MkLineChecker{mkline}.checkInclude()

	s.CheckOutputLines(
		"ERROR: Makefile:2: \"/other/package/Makefile\" does not exist.",
		"ERROR: Makefile:2: Other Makefiles must not be included directly.")
}

func (s *Suite) Test_MkLines_quoting_LDFLAGS_for_GNU_configure(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	G.Pkg = NewPackage("category/pkgbase")
	mklines := s.NewMkLines("Makefile",
		mkrcsid,
		"GNU_CONFIGURE=\tyes",
		"CONFIGURE_ENV+=\tX_LIBS=${X11_LDFLAGS:Q}")

	mklines.Check()

	s.CheckOutputLines(
		"WARN: Makefile:3: Please use ${X11_LDFLAGS:M*:Q} instead of ${X11_LDFLAGS:Q}.",
		"WARN: Makefile:3: Please use ${X11_LDFLAGS:M*:Q} instead of ${X11_LDFLAGS:Q}.")
}

func (s *Suite) Test_MkLines__variable_alignment_advanced(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wspace")
	fname := s.CreateTmpFileLines("Makefile",
		mkrcsid,
		"",
		"VAR= \\", // In continuation lines, indenting with spaces is ok
		"\tvalue",
		"",
		"VAR= indented with one space",   // Exactly one space is ok in general
		"VAR=  indented with two spaces", // Two spaces are uncommon
		"",
		"BLOCK=\tindented with tab",
		"BLOCK_LONGVAR= indented with space", // This is ok, to prevent the block from being indented further
		"",
		"BLOCK=\tshort",
		"BLOCK_LONGVAR=\tlong",
		"",
		"GRP_A= avalue", // The values in a block should be aligned
		"GRP_AA= value",
		"GRP_AAA= value",
		"GRP_AAAA= value",
		"",
		"VAR=\t${VAR}${BLOCK}${BLOCK_LONGVAR} # suppress warnings about unused variables",
		"VAR=\t${GRP_A}${GRP_AA}${GRP_AAA}${GRP_AAAA}")
	mklines := NewMkLines(LoadExistingLines(fname, true))

	mklines.Check()

	s.CheckOutputLines(
		"NOTE: ~/Makefile:6: This variable value should be aligned with tabs, not spaces, to column 9.",
		"NOTE: ~/Makefile:7: This variable value should be aligned with tabs, not spaces, to column 9.",
		"NOTE: ~/Makefile:12: This variable value should be aligned to column 17.",
		"NOTE: ~/Makefile:15: This variable value should be aligned with tabs, not spaces, to column 17.",
		"NOTE: ~/Makefile:16: This variable value should be aligned with tabs, not spaces, to column 17.",
		"NOTE: ~/Makefile:17: This variable value should be aligned with tabs, not spaces, to column 17.",
		"NOTE: ~/Makefile:18: This variable value should be aligned with tabs, not spaces, to column 17.")

	s.UseCommandLine("-Wspace", "--autofix")

	mklines.Check()

	s.CheckOutputLines(
		"AUTOFIX: ~/Makefile:6: Replacing \"VAR= \" with \"VAR=\\t\".",
		"AUTOFIX: ~/Makefile:7: Replacing \"VAR=  \" with \"VAR=\\t\".",
		"AUTOFIX: ~/Makefile:12: Replacing \"BLOCK=\\t\" with \"BLOCK=\\t\\t\".",
		"AUTOFIX: ~/Makefile:15: Replacing \"GRP_A= \" with \"GRP_A=\\t\\t\".",
		"AUTOFIX: ~/Makefile:16: Replacing \"GRP_AA= \" with \"GRP_AA=\\t\\t\".",
		"AUTOFIX: ~/Makefile:17: Replacing \"GRP_AAA= \" with \"GRP_AAA=\\t\".",
		"AUTOFIX: ~/Makefile:18: Replacing \"GRP_AAAA= \" with \"GRP_AAAA=\\t\".",
		"AUTOFIX: ~/Makefile: Has been auto-fixed. Please re-run pkglint.")
	c.Check(s.LoadTmpFile("Makefile"), equals, ""+
		"# $"+"NetBSD$\n"+
		"\n"+
		"VAR= \\\n"+
		"\tvalue\n"+
		"\n"+
		"VAR=\tindented with one space\n"+
		"VAR=\tindented with two spaces\n"+
		"\n"+
		"BLOCK=\tindented with tab\n"+
		"BLOCK_LONGVAR= indented with space\n"+
		"\n"+
		"BLOCK=\t\tshort\n"+
		"BLOCK_LONGVAR=\tlong\n"+
		"\n"+
		"GRP_A=\t\tavalue\n"+
		"GRP_AA=\t\tvalue\n"+
		"GRP_AAA=\tvalue\n"+
		"GRP_AAAA=\tvalue\n"+
		"\n"+
		"VAR=\t${VAR}${BLOCK}${BLOCK_LONGVAR} # suppress warnings about unused variables\n"+
		"VAR=\t${GRP_A}${GRP_AA}${GRP_AAA}${GRP_AAAA}\n")
}

func (s *Suite) Test_MkLines__variable_alignment_space_and_tab(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wspace")
	mklines := s.NewMkLines("Makefile",
		mkrcsid,
		"",
		"VAR=    space",
		"VAR=\ttab ${VAR}")

	mklines.Check()

	s.CheckOutputLines(
		"NOTE: Makefile:3: Variable values should be aligned with tabs, not spaces.")
}

func (s *Suite) Test_MkLines__for_loop_multiple_variables(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	s.RegisterTool(&Tool{Name: "echo", Varname: "ECHO", Predefined: true})
	s.RegisterTool(&Tool{Name: "find", Varname: "FIND", Predefined: true})
	s.RegisterTool(&Tool{Name: "pax", Varname: "PAX", Predefined: true})
	mklines := s.NewMkLines("audio/squeezeboxserver/Makefile",
		mkrcsid,
		"",
		".for _list_ _dir_ in ${SBS_COPY}",
		"\tcd ${WRKSRC} && ${FIND} ${${_list_}} -type f ! -name '*.orig' 2>/dev/null "+
			"| pax -rw -pm ${DESTDIR}${PREFIX}/${${_dir_}}",
		".endfor")

	mklines.Check()

	s.CheckOutputLines(
		"WARN: audio/squeezeboxserver/Makefile:3: Variable names starting with an underscore (_list_) are reserved for internal pkgsrc use.",
		"WARN: audio/squeezeboxserver/Makefile:3: Variable names starting with an underscore (_dir_) are reserved for internal pkgsrc use.",
		"WARN: audio/squeezeboxserver/Makefile:4: The exitcode of the left-hand-side command of the pipe operator is ignored.")
}

func (s *Suite) Test_MkLines__comparing_YesNo_variable_to_string(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("databases/gdbm_compat/builtin.mk",
		mkrcsid,
		".if ${USE_BUILTIN.gdbm} == \"no\"",
		".endif",
		".if ${USE_BUILTIN.gdbm:tu} == \"no\"", // Can never be true, since "no" is not uppercase.
		".endif")

	mklines.Check()

	c.Check(s.Output(), equals, "WARN: databases/gdbm_compat/builtin.mk:2: "+
		"USE_BUILTIN.gdbm should be matched against \"[yY][eE][sS]\" or \"[nN][oO]\", not compared with \"no\".\n")
}

func (s *Suite) Test_MkLines__varuse_sh_modifier(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("lang/qore/module.mk",
		mkrcsid,
		"qore-version=\tqore --short-version | ${SED} -e s/-.*//",
		"PLIST_SUBST+=\tQORE_VERSION=\"${qore-version:sh}\"")

	vars2 := mklines.mklines[1].DetermineUsedVariables()

	c.Check(vars2, deepEquals, []string{"SED"})

	vars3 := mklines.mklines[2].DetermineUsedVariables()

	c.Check(vars3, deepEquals, []string{"qore-version"})

	mklines.Check()

	s.CheckOutputEmpty() // No warnings about defined but not used or vice versa
}

func (s *Suite) Test_MkLines__varuse_parameterized(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("converters/wv2/Makefile",
		mkrcsid,
		"CONFIGURE_ARGS+=\t\t${CONFIGURE_ARGS.${ICONV_TYPE}-iconv}",
		"CONFIGURE_ARGS.gnu-iconv=\t--with-libiconv=${BUILDLINK_PREFIX.iconv}")

	mklines.Check()

	s.CheckOutputEmpty() // No warnings about defined but not used or vice versa
}

func (s *Suite) Test_MkLines__loop_modifier(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("chat/xchat/Makefile",
		mkrcsid,
		"GCONF_SCHEMAS=\tapps_xchat_url_handler.schemas",
		"post-install:",
		"\t${GCONF_SCHEMAS:@.s.@"+
			"${INSTALL_DATA} ${WRKSRC}/src/common/dbus/${.s.} ${DESTDIR}${GCONF_SCHEMAS_DIR}/@}")

	mklines.Check()

	c.Check(s.Output(), equals, ""+ // No warning about missing @ at the end
		"WARN: chat/xchat/Makefile:4: Unknown shell command \"${GCONF_SCHEMAS:@.s.@"+
		"${INSTALL_DATA} ${WRKSRC}/src/common/dbus/${.s.} ${DESTDIR}${GCONF_SCHEMAS_DIR}/@}\".\n")
}

// PR 46570
func (s *Suite) Test_MkLines__PKG_SKIP_REASON_depending_on_OPSYS(c *check.C) {
	s.Init(c)
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("Makefile",
		mkrcsid,
		"PKG_SKIP_REASON+=\t\"Fails everywhere\"",
		".if ${OPSYS} == \"Cygwin\"",
		"PKG_SKIP_REASON+=\t\"Fails on Cygwin\"",
		".endif")

	mklines.Check()

	s.CheckOutputLines(
		"NOTE: Makefile:4: Consider defining NOT_FOR_PLATFORM instead of setting PKG_SKIP_REASON depending on ${OPSYS}.")
}

// PR 46570, item "15. net/uucp/Makefile has a make loop"
func (s *Suite) Test_MkLines__indirect_variables(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	mklines := s.NewMkLines("net/uucp/Makefile",
		mkrcsid,
		"",
		"post-configure:",
		".for var in MAIL_PROGRAM CMDPATH",
		"\t"+`${RUN} ${ECHO} "#define ${var} \""${UUCP_${var}}"\"`,
		".endfor")

	mklines.Check()

	// No warning about UUCP_${var} being used but not defined.
	s.CheckOutputLines(
		"WARN: net/uucp/Makefile:5: Unknown shell command \"${ECHO}\".")
}

func (s *Suite) Test_MkLines_Check__list_variable_as_part_of_word(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	mklines := s.NewMkLines("converters/chef/Makefile",
		mkrcsid,
		"\tcd ${WRKSRC} && tr '\\r' '\\n' < ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} > chef.l")

	mklines.Check()

	s.CheckOutputLines(
		"WARN: converters/chef/Makefile:2: Unknown shell command \"tr\".",
		"WARN: converters/chef/Makefile:2: The list variable DISTFILES should not be embedded in a word.")
}

func (s *Suite) Test_MkLines_Check__absolute_pathname_depending_on_OPSYS(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("games/heretic2-demo/Makefile",
		mkrcsid,
		".if ${OPSYS} == \"DragonFly\"",
		"TOOLS_PLATFORM.gtar=\t/usr/bin/bsdtar",
		".endif",
		"TOOLS_PLATFORM.gtar=\t/usr/bin/bsdtar")

	mklines.Check()

	// No warning about an unknown shell command in line 3,
	// since that line depends on OPSYS.
	s.CheckOutputLines(
		"WARN: games/heretic2-demo/Makefile:3: The variable TOOLS_PLATFORM.gtar may not be set by any package.",
		"WARN: games/heretic2-demo/Makefile:5: The variable TOOLS_PLATFORM.gtar may not be set by any package.",
		"WARN: games/heretic2-demo/Makefile:5: Unknown shell command \"/usr/bin/bsdtar\".")
}

func (s *Suite) Test_MkLines_checkForUsedComment(c *check.C) {
	s.Init(c)
	s.UseCommandLine("--show-autofix")
	s.NewMkLines("Makefile.common",
		mkrcsid,
		"",
		"# used by sysutils/mc",
	).checkForUsedComment("sysutils/mc")

	s.CheckOutputEmpty()

	s.NewMkLines("Makefile.common").checkForUsedComment("category/package")

	s.CheckOutputEmpty()

	s.NewMkLines("Makefile.common",
		mkrcsid,
	).checkForUsedComment("category/package")

	s.CheckOutputEmpty()

	s.NewMkLines("Makefile.common",
		mkrcsid,
		"",
	).checkForUsedComment("category/package")

	s.CheckOutputEmpty()

	s.NewMkLines("Makefile.common",
		mkrcsid,
		"",
		"VARNAME=\tvalue",
	).checkForUsedComment("category/package")

	s.CheckOutputLines(
		"WARN: Makefile.common:2: Please add a line \"# used by category/package\" here.",
		"AUTOFIX: Makefile.common:2: Inserting a line \"# used by category/package\" before this line.")

	s.NewMkLines("Makefile.common",
		mkrcsid,
		"#",
		"#",
	).checkForUsedComment("category/package")

	s.CheckOutputLines(
		"WARN: Makefile.common:3: Please add a line \"# used by category/package\" here.",
		"AUTOFIX: Makefile.common:3: Inserting a line \"# used by category/package\" before this line.")
}

func (s *Suite) Test_MkLines_DetermineUsedVariables__simple(c *check.C) {
	mklines := s.NewMkLines("fname",
		"\t${VAR}")
	mkline := mklines.mklines[0]
	G.Mk = mklines

	mklines.DetermineUsedVariables()

	c.Check(len(mklines.varuse), equals, 1)
	c.Check(mklines.varuse["VAR"], equals, mkline)
}

func (s *Suite) Test_MkLines_DetermineUsedVariables__nested(c *check.C) {
	mklines := s.NewMkLines("fname",
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
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("fname",
		mkrcsid,
		"",
		"\tmd5sum filename")

	mklines.Check()

	s.CheckOutputLines(
		"WARN: fname:3: Unknown shell command \"md5sum\".")
}

func (s *Suite) Test_MkLines_PrivateTool_Defined(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("fname",
		mkrcsid,
		"TOOLS_CREATE+=\tmd5sum",
		"",
		"\tmd5sum filename")

	mklines.Check()

	s.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines_Check_indentation(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	mklines := s.NewMkLines("options.mk",
		mkrcsid,
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

	c.Check(s.Output(), equals, ""+
		"NOTE: options.mk:2: This directive should be indented by 0 spaces.\n"+
		"NOTE: options.mk:3: This directive should be indented by 0 spaces.\n"+
		"NOTE: options.mk:4: This directive should be indented by 2 spaces.\n"+
		"NOTE: options.mk:5: This directive should be indented by 4 spaces.\n"+
		"NOTE: options.mk:6: This directive should be indented by 4 spaces.\n"+
		"NOTE: options.mk:7: This directive should be indented by 4 spaces.\n"+
		"NOTE: options.mk:8: This directive should be indented by 2 spaces.\n"+
		"NOTE: options.mk:9: This directive should be indented by 2 spaces.\n"+
		"NOTE: options.mk:10: This directive should be indented by 2 spaces.\n"+
		"NOTE: options.mk:11: This directive should be indented by 2 spaces.\n"+
		"ERROR: options.mk:11: \".else\" does not take arguments.\n"+
		"NOTE: options.mk:11: If you meant \"else if\", use \".elif\".\n"+
		"NOTE: options.mk:12: This directive should be indented by 2 spaces.\n"+
		"NOTE: options.mk:13: This directive should be indented by 0 spaces.\n"+
		"NOTE: options.mk:14: This directive should be indented by 0 spaces.\n"+
		"ERROR: options.mk:15: Unmatched .endif.\n"+
		"NOTE: options.mk:15: This directive should be indented by 0 spaces.\n")
}
