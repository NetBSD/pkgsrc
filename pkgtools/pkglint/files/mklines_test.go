package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestMkLines_AutofixConditionalIndentation(c *check.C) {
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

func (s *Suite) TestMkLines_UnusualTarget(c *check.C) {
	mklines := s.NewMkLines("Makefile",
		"# $"+"NetBSD$",
		"",
		"echo: echo.c",
		"\tcc -o ${.TARGET} ${.IMPSRC}")

	mklines.Check()

	c.Check(s.Output(), equals, "WARN: Makefile:3: Unusual target \"echo\".\n")
}

func (s *Suite) TestMkLines_checklineInclude_Makefile(c *check.C) {
	mklines := s.NewMkLines("Makefile",
		"# $"+"NetBSD$",
		".include \"../../other/package/Makefile\"")

	mklines.Check()

	c.Check(s.Output(), equals, ""+
		"ERROR: Makefile:2: \"/other/package/Makefile\" does not exist.\n"+
		"ERROR: Makefile:2: Other Makefiles must not be included directly.\n")
}

func (s *Suite) TestMkLines_Quoting(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	G.Pkg = NewPackage("category/pkgbase")
	mklines := s.NewMkLines("Makefile",
		"# $"+"NetBSD$",
		"GNU_CONFIGURE=\tyes",
		"CONFIGURE_ENV+=\tX_LIBS=${X11_LDFLAGS:Q}")

	mklines.Check()

	c.Check(s.Output(), equals, "WARN: Makefile:3: Please use ${X11_LDFLAGS:M*:Q} instead of ${X11_LDFLAGS:Q}.\n")
}

func (s *Suite) Test_MkLines_Varalign_Advanced(c *check.C) {
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

func (s *Suite) Test_MkLines_Varalign_Misc(c *check.C) {
	s.UseCommandLine(c, "-Wspace")
	mklines := s.NewMkLines("Makefile",
		"# $"+"NetBSD$",
		"",
		"VAR=    space",
		"VAR=\ttab ${VAR}")

	mklines.Check()

	c.Check(s.Output(), equals, "NOTE: Makefile:3: Variable values should be aligned with tabs, not spaces.\n")
}

func (s *Suite) Test_MkLines_ForLoop_Multivar(c *check.C) {
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

func (s *Suite) Test_MkLines_Cond_Compare_YesNo(c *check.C) {
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

func (s *Suite) Test_MkLines_Varuse_sh_Modifier(c *check.C) {
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

func (s *Suite) Test_MkLines_Varuse_parameterized(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("converters/wv2/Makefile",
		"# $"+"NetBSD$",
		"CONFIGURE_ARGS+=\t\t${CONFIGURE_ARGS.${ICONV_TYPE}-iconv}",
		"CONFIGURE_ARGS.gnu-iconv=\t--with-libiconv=${BUILDLINK_PREFIX.iconv}")

	mklines.Check()

	c.Check(s.Output(), equals, "") // No warnings about defined but not used or vice versa
}

func (s *Suite) Test_MkLines_LoopModifier(c *check.C) {
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

func (s *Suite) Test_MkLines_Indentation_DependsOn(c *check.C) {
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
