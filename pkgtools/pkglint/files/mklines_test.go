package main

import (
	check "gopkg.in/check.v1"
)

const mkrcsid = "# $" + "NetBSD$"

func (s *Suite) Test_MkLines_Check__autofix_conditional_indentation(c *check.C) {
	s.UseCommandLine(c, "--autofix", "-Wspace")
	tmpfile := s.CreateTmpFile(c, "fname.mk", "")
	mklines := s.NewMkLines(tmpfile,
		"# $"+"NetBSD$",
		".if defined(A)",
		".for a in ${A}",
		".if defined(C)",
		".endif",
		".endfor",
		".endif")

	mklines.Check()

	c.Check(s.Output(), equals, ""+
		"AUTOFIX: ~/fname.mk:3: Replacing \".\" with \".  \".\n"+
		"AUTOFIX: ~/fname.mk:4: Replacing \".\" with \".    \".\n"+
		"AUTOFIX: ~/fname.mk:5: Replacing \".\" with \".    \".\n"+
		"AUTOFIX: ~/fname.mk:6: Replacing \".\" with \".  \".\n"+
		"AUTOFIX: ~/fname.mk: Has been auto-fixed. Please re-run pkglint.\n")
	c.Check(s.LoadTmpFile(c, "fname.mk"), equals, ""+
		"# $"+"NetBSD$\n"+
		".if defined(A)\n"+
		".  for a in ${A}\n"+
		".    if defined(C)\n"+
		".    endif\n"+
		".  endfor\n"+
		".endif\n")
}

func (s *Suite) Test_MkLines_Check__unusual_target(c *check.C) {
	mklines := s.NewMkLines("Makefile",
		"# $"+"NetBSD$",
		"",
		"echo: echo.c",
		"\tcc -o ${.TARGET} ${.IMPSRC}")

	mklines.Check()

	c.Check(s.Output(), equals, "WARN: Makefile:3: Unusual target \"echo\".\n")
}

func (s *Suite) Test_MkLine_checklineInclude_Makefile(c *check.C) {
	mkline := NewMkLine(NewLine("Makefile", 2, ".include \"../../other/package/Makefile\"", nil))

	mkline.checkInclude()

	c.Check(s.Output(), equals, ""+
		"ERROR: Makefile:2: \"/other/package/Makefile\" does not exist.\n"+
		"ERROR: Makefile:2: Other Makefiles must not be included directly.\n")
}

func (s *Suite) Test_MkLines_quoting_LDFLAGS_for_GNU_configure(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	G.Pkg = NewPackage("category/pkgbase")
	mklines := s.NewMkLines("Makefile",
		"# $"+"NetBSD$",
		"GNU_CONFIGURE=\tyes",
		"CONFIGURE_ENV+=\tX_LIBS=${X11_LDFLAGS:Q}")

	mklines.Check()

	c.Check(s.Output(), equals, ""+
		"WARN: Makefile:3: Please use ${X11_LDFLAGS:M*:Q} instead of ${X11_LDFLAGS:Q}.\n"+
		"WARN: Makefile:3: Please use ${X11_LDFLAGS:M*:Q} instead of ${X11_LDFLAGS:Q}.\n")
}

func (s *Suite) Test_MkLines__variable_alignment_advanced(c *check.C) {
	s.UseCommandLine(c, "-Wspace")
	fname := s.CreateTmpFileLines(c, "Makefile",
		"# $"+"NetBSD$",
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

	c.Check(s.Output(), equals, ""+
		"NOTE: ~/Makefile:6: This variable value should be aligned with tabs, not spaces, to column 9.\n"+
		"NOTE: ~/Makefile:7: This variable value should be aligned with tabs, not spaces, to column 9.\n"+
		"NOTE: ~/Makefile:12: This variable value should be aligned to column 17.\n"+
		"NOTE: ~/Makefile:15: This variable value should be aligned with tabs, not spaces, to column 17.\n"+
		"NOTE: ~/Makefile:16: This variable value should be aligned with tabs, not spaces, to column 17.\n"+
		"NOTE: ~/Makefile:17: This variable value should be aligned with tabs, not spaces, to column 17.\n"+
		"NOTE: ~/Makefile:18: This variable value should be aligned with tabs, not spaces, to column 17.\n")

	s.UseCommandLine(c, "-Wspace", "--autofix")

	mklines.Check()

	c.Check(s.Output(), equals, ""+
		"AUTOFIX: ~/Makefile:6: Replacing \"VAR= \" with \"VAR=\\t\".\n"+
		"AUTOFIX: ~/Makefile:7: Replacing \"VAR=  \" with \"VAR=\\t\".\n"+
		"AUTOFIX: ~/Makefile:12: Replacing \"BLOCK=\\t\" with \"BLOCK=\\t\\t\".\n"+
		"AUTOFIX: ~/Makefile:15: Replacing \"GRP_A= \" with \"GRP_A=\\t\\t\".\n"+
		"AUTOFIX: ~/Makefile:16: Replacing \"GRP_AA= \" with \"GRP_AA=\\t\\t\".\n"+
		"AUTOFIX: ~/Makefile:17: Replacing \"GRP_AAA= \" with \"GRP_AAA=\\t\".\n"+
		"AUTOFIX: ~/Makefile:18: Replacing \"GRP_AAAA= \" with \"GRP_AAAA=\\t\".\n"+
		"AUTOFIX: ~/Makefile: Has been auto-fixed. Please re-run pkglint.\n")
	c.Check(s.LoadTmpFile(c, "Makefile"), equals, ""+
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
	s.UseCommandLine(c, "-Wspace")
	mklines := s.NewMkLines("Makefile",
		"# $"+"NetBSD$",
		"",
		"VAR=    space",
		"VAR=\ttab ${VAR}")

	mklines.Check()

	c.Check(s.Output(), equals, "NOTE: Makefile:3: Variable values should be aligned with tabs, not spaces.\n")
}

func (s *Suite) Test_MkLines__for_loop_multiple_variables(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	s.RegisterTool(&Tool{Name: "echo", Varname: "ECHO", Predefined: true})
	s.RegisterTool(&Tool{Name: "find", Varname: "FIND", Predefined: true})
	s.RegisterTool(&Tool{Name: "pax", Varname: "PAX", Predefined: true})
	mklines := s.NewMkLines("audio/squeezeboxserver/Makefile",
		"# $"+"NetBSD$",
		"",
		".for _list_ _dir_ in ${SBS_COPY}",
		"\tcd ${WRKSRC} && ${FIND} ${${_list_}} -type f ! -name '*.orig' 2>/dev/null "+
			"| pax -rw -pm ${DESTDIR}${PREFIX}/${${_dir_}}",
		".endfor")

	mklines.Check()

	c.Check(s.Output(), equals, ""+
		"WARN: audio/squeezeboxserver/Makefile:3: Variable names starting with an underscore (_list_) are reserved for internal pkgsrc use.\n"+
		"WARN: audio/squeezeboxserver/Makefile:3: Variable names starting with an underscore (_dir_) are reserved for internal pkgsrc use.\n"+
		"WARN: audio/squeezeboxserver/Makefile:4: The exitcode of the left-hand-side command of the pipe operator is ignored.\n")
}

func (s *Suite) Test_MkLines__comparing_YesNo_variable_to_string(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("databases/gdbm_compat/builtin.mk",
		"# $"+"NetBSD$",
		".if ${USE_BUILTIN.gdbm} == \"no\"",
		".endif")

	mklines.Check()

	c.Check(s.Output(), equals, "WARN: databases/gdbm_compat/builtin.mk:2: "+
		"USE_BUILTIN.gdbm should be matched against \"[yY][eE][sS]\" or \"[nN][oO]\", not compared with \"no\".\n")
}

func (s *Suite) Test_MkLines__varuse_sh_modifier(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("lang/qore/module.mk",
		"# $"+"NetBSD$",
		"qore-version=\tqore --short-version | ${SED} -e s/-.*//",
		"PLIST_SUBST+=\tQORE_VERSION=\"${qore-version:sh}\"")

	vars2 := mklines.mklines[1].determineUsedVariables()

	c.Check(vars2, deepEquals, []string{"SED"})

	vars3 := mklines.mklines[2].determineUsedVariables()

	c.Check(vars3, deepEquals, []string{"qore-version"})

	mklines.Check()

	c.Check(s.Output(), equals, "") // No warnings about defined but not used or vice versa
}

func (s *Suite) Test_MkLines__varuse_parameterized(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("converters/wv2/Makefile",
		"# $"+"NetBSD$",
		"CONFIGURE_ARGS+=\t\t${CONFIGURE_ARGS.${ICONV_TYPE}-iconv}",
		"CONFIGURE_ARGS.gnu-iconv=\t--with-libiconv=${BUILDLINK_PREFIX.iconv}")

	mklines.Check()

	c.Check(s.Output(), equals, "") // No warnings about defined but not used or vice versa
}

func (s *Suite) Test_MkLines__loop_modifier(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("chat/xchat/Makefile",
		"# $"+"NetBSD$",
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
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("Makefile",
		"# $"+"NetBSD$",
		"PKG_SKIP_REASON+=\t\"Fails everywhere\"",
		".if ${OPSYS} == \"Cygwin\"",
		"PKG_SKIP_REASON+=\t\"Fails on Cygwin\"",
		".endif")

	mklines.Check()

	c.Check(s.Output(), equals, "NOTE: Makefile:4: Consider defining NOT_FOR_PLATFORM instead of setting PKG_SKIP_REASON depending on ${OPSYS}.\n")
}

// PR 46570, item "15. net/uucp/Makefile has a make loop"
func (s *Suite) Test_MkLines__indirect_variables(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	mklines := s.NewMkLines("net/uucp/Makefile",
		"# $"+"NetBSD$",
		"",
		"post-configure:",
		".for var in MAIL_PROGRAM CMDPATH",
		"\t"+`${RUN} ${ECHO} "#define ${var} \""${UUCP_${var}}"\"`,
		".endfor")

	mklines.Check()

	// No warning about UUCP_${var} being used but not defined.
	c.Check(s.Output(), equals, ""+
		"WARN: net/uucp/Makefile:5: Unknown shell command \"${ECHO}\".\n")
}

func (s *Suite) Test_MkLines_Check__list_variable_as_part_of_word(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	mklines := s.NewMkLines("converters/chef/Makefile",
		mkrcsid,
		"\tcd ${WRKSRC} && tr '\\r' '\\n' < ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} > chef.l")

	mklines.Check()

	c.Check(s.Output(), equals, ""+
		"WARN: converters/chef/Makefile:2: Unknown shell command \"tr\".\n"+
		"WARN: converters/chef/Makefile:2: The list variable DISTFILES should not be embedded in a word.\n")
}

func (s *Suite) Test_MkLines_Check__absolute_pathname_depending_on_OPSYS(c *check.C) {
	s.UseCommandLine(c, "-Wall")
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
	c.Check(s.Output(), equals, ""+
		"WARN: games/heretic2-demo/Makefile:3: The variable TOOLS_PLATFORM.gtar may not be set by any package.\n"+
		"WARN: games/heretic2-demo/Makefile:5: The variable TOOLS_PLATFORM.gtar may not be set by any package.\n"+
		"WARN: games/heretic2-demo/Makefile:5: Unknown shell command \"/usr/bin/bsdtar\".\n")
}

func (s *Suite) Test_MkLines_checkForUsedComment(c *check.C) {
	s.UseCommandLine(c, "--show-autofix")
	s.NewMkLines("Makefile.common",
		"# $"+"NetBSD$",
		"",
		"# used by sysutils/mc",
	).checkForUsedComment("sysutils/mc")

	c.Check(s.Output(), equals, "")

	s.NewMkLines("Makefile.common").checkForUsedComment("category/package")

	c.Check(s.Output(), equals, "")

	s.NewMkLines("Makefile.common",
		"# $"+"NetBSD$",
	).checkForUsedComment("category/package")

	c.Check(s.Output(), equals, "")

	s.NewMkLines("Makefile.common",
		"# $"+"NetBSD$",
		"",
	).checkForUsedComment("category/package")

	c.Check(s.Output(), equals, "")

	s.NewMkLines("Makefile.common",
		"# $"+"NetBSD$",
		"",
		"VARNAME=\tvalue",
	).checkForUsedComment("category/package")

	c.Check(s.Output(), equals, ""+
		"WARN: Makefile.common:2: Please add a line \"# used by category/package\" here.\n"+
		"AUTOFIX: Makefile.common:2: Inserting a line \"# used by category/package\" before this line.\n")

	s.NewMkLines("Makefile.common",
		"# $"+"NetBSD$",
		"#",
		"#",
	).checkForUsedComment("category/package")

	c.Check(s.Output(), equals, ""+
		"WARN: Makefile.common:3: Please add a line \"# used by category/package\" here.\n"+
		"AUTOFIX: Makefile.common:3: Inserting a line \"# used by category/package\" before this line.\n")
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
