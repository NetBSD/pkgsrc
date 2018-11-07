package main

import (
	"fmt"
	"gopkg.in/check.v1"
	"sort"
)

func (s *Suite) Test_MkLines_Check__autofix_directive_indentation(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--autofix", "-Wspace")
	lines := t.SetupFileLines("fileName.mk",
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
		"AUTOFIX: ~/fileName.mk:3: Replacing \".\" with \".  \".",
		"AUTOFIX: ~/fileName.mk:4: Replacing \".\" with \".    \".",
		"AUTOFIX: ~/fileName.mk:5: Replacing \".\" with \".    \".",
		"AUTOFIX: ~/fileName.mk:6: Replacing \".\" with \".  \".")
	t.CheckFileLines("fileName.mk",
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

	// FIXME: .TARGET is always defined.
	// FIXME: .IMPSRC is always defined.
	t.CheckOutputLines(
		"WARN: Makefile:3: Unusual target \"echo\".",
		"WARN: Makefile:4: Unknown shell command \"cc\".",
		"WARN: Makefile:4: .TARGET is used but not defined.",
		"WARN: Makefile:4: .IMPSRC is used but not defined.")
}

func (s *Suite) Test_MkLines__quoting_LDFLAGS_for_GNU_configure(c *check.C) {
	t := s.Init(c)

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

	t.SetupVartypes()
	t.SetupTool("echo", "ECHO", AtRunTime)
	t.SetupTool("find", "FIND", AtRunTime)
	t.SetupTool("pax", "PAX", AtRunTime)
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
		"WARN: Makefile:3: SBS_COPY is used but not defined.",
		"WARN: Makefile:4: The exitcode of \"${FIND}\" at the left of the | operator is ignored.")
}

func (s *Suite) Test_MkLines__comparing_YesNo_variable_to_string(c *check.C) {
	t := s.Init(c)

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

	t.SetupVartypes()
	t.SetupTool("sed", "SED", AfterPrefsMk)
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

	t.SetupTool("echo", "ECHO", AfterPrefsMk)
	mklines := t.NewMkLines("net/uucp/Makefile",
		MkRcsID,
		"",
		"post-configure:",
		".for var in MAIL_PROGRAM CMDPATH",
		"\t"+`${RUN} ${ECHO} "#define ${var} \""${UUCP_${var}}"\""`,
		".endfor")

	mklines.Check()

	// No warning about UUCP_${var} being used but not defined.
	// Normally, parameterized variables use a dot instead of an
	// underscore as separator. This is one of the other cases,
	// and pkglint just doesn't warn about dynamic variable names
	// like UUCP_${var} or SITES_${distfile}.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines_Check__list_variable_as_part_of_word(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
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

func (s *Suite) Test_MkLines_CheckForUsedComment(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--show-autofix")
	t.NewMkLines("Makefile.common",
		MkRcsID,
		"",
		"# used by sysutils/mc",
	).CheckForUsedComment("sysutils/mc")

	t.CheckOutputEmpty()

	t.NewMkLines("Makefile.common").CheckForUsedComment("category/package")

	t.CheckOutputEmpty()

	t.NewMkLines("Makefile.common",
		MkRcsID,
	).CheckForUsedComment("category/package")

	t.CheckOutputEmpty()

	t.NewMkLines("Makefile.common",
		MkRcsID,
		"",
	).CheckForUsedComment("category/package")

	t.CheckOutputEmpty()

	t.NewMkLines("Makefile.common",
		MkRcsID,
		"",
		"VARNAME=\tvalue",
	).CheckForUsedComment("category/package")

	t.CheckOutputLines(
		"WARN: Makefile.common:2: Please add a line \"# used by category/package\" here.",
		"AUTOFIX: Makefile.common:2: Inserting a line \"# used by category/package\" before this line.")

	t.NewMkLines("Makefile.common",
		MkRcsID,
		"#",
		"#",
	).CheckForUsedComment("category/package")

	t.CheckOutputLines(
		"WARN: Makefile.common:3: Please add a line \"# used by category/package\" here.",
		"AUTOFIX: Makefile.common:3: Inserting a line \"# used by category/package\" before this line.")

	c.Check(G.autofixAvailable, equals, true)
}

func (s *Suite) Test_MkLines_DetermineDefinedVariables(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall,no-space")
	t.SetupPkgsrc()
	t.CreateFileLines("mk/tools/defaults.mk",
		"USE_TOOLS+=     autoconf autoconf213")
	G.Pkgsrc.LoadInfrastructure()
	mklines := t.NewMkLines("determine-defined-variables.mk",
		MkRcsID,
		"",
		"USE_TOOLS+=             autoconf213 autoconf",
		"USE_TOOLS:=             ${USE_TOOLS:Ntbl}",
		"",
		"OPSYSVARS+=             OSV",
		"OSV.NetBSD=             NetBSD-specific value",
		"",
		"SUBST_CLASSES+=         subst",
		"SUBST_STAGE.subst=      pre-configure",
		"SUBST_FILES.subst=      file",
		"SUBST_VARS.subst=       SUV",
		"SUV=                    value for substitution",
		"",
		"pre-configure:",
		"\t${RUN} autoreconf; autoheader-2.13; unknown-command",
		"\t${ECHO} ${OSV:Q}")

	mklines.Check()

	// The tools autoreconf and autoheader213 are known at this point because of the USE_TOOLS line.
	// The SUV variable is used implicitly by the SUBST framework, therefore no warning.
	// The OSV.NetBSD variable is used implicitly via the OSV variable, therefore no warning.
	t.CheckOutputLines(
		// FIXME: the below warning is wrong; it's ok to have SUBST blocks in all files, maybe except buildlink3.mk.
		"WARN: determine-defined-variables.mk:12: The variable SUBST_VARS.subst may not be set (only given a default value, appended to) in this file; it would be ok in Makefile, Makefile.common, options.mk.",
		"WARN: determine-defined-variables.mk:16: Unknown shell command \"unknown-command\".")
}

func (s *Suite) Test_MkLines_DetermineDefinedVariables__BUILTIN_FIND_FILES_VAR(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall,no-space")
	t.SetupPackage("category/package")
	t.CreateFileLines("mk/buildlink3/bsd.builtin.mk",
		MkRcsID)
	mklines := t.SetupFileMkLines("category/package/builtin.mk",
		MkRcsID,
		"",
		"BUILTIN_FIND_FILES_VAR:=        H_XFT2",
		"BUILTIN_FIND_FILES.H_XFT2=      ${X11BASE}/include/X11/Xft/Xft.h",
		"",
		".include \"../../mk/buildlink3/bsd.builtin.mk\"",
		"",
		".if ${H_XFT2:N__nonexistent__} && ${H_UNDEF:N__nonexistent__}",
		".endif")
	G.Pkgsrc.LoadInfrastructure()

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/category/package/builtin.mk:8: H_UNDEF is used but not defined.")
}

func (s *Suite) Test_MkLines_DetermineUsedVariables__simple(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("fileName",
		"\t${VAR}")
	mkline := mklines.mklines[0]
	G.Mk = mklines

	mklines.DetermineUsedVariables()

	c.Check(len(mklines.vars.used), equals, 1)
	c.Check(mklines.vars.FirstUse("VAR"), equals, mkline)
}

func (s *Suite) Test_MkLines_DetermineUsedVariables__nested(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("fileName",
		"\t${outer.${inner}}")
	mkline := mklines.mklines[0]
	G.Mk = mklines

	mklines.DetermineUsedVariables()

	c.Check(len(mklines.vars.used), equals, 3)
	c.Check(mklines.vars.FirstUse("inner"), equals, mkline)
	c.Check(mklines.vars.FirstUse("outer.*"), equals, mkline)
	c.Check(mklines.vars.FirstUse("outer.${inner}"), equals, mkline)
}

func (s *Suite) Test_MkLines__private_tool_undefined(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.NewMkLines("fileName",
		MkRcsID,
		"",
		"\tmd5sum fileName")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: fileName:3: Unknown shell command \"md5sum\".")
}

func (s *Suite) Test_MkLines__private_tool_defined(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.NewMkLines("fileName",
		MkRcsID,
		"TOOLS_CREATE+=\tmd5sum",
		"",
		"\tmd5sum fileName")

	mklines.Check()

	// TODO: Is it necessary to add the tool to USE_TOOLS? If not, why not?
	t.CheckOutputLines(
		"WARN: fileName:4: The \"md5sum\" tool is used but not added to USE_TOOLS.")
}

func (s *Suite) Test_MkLines_Check__indentation(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
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

	t.CheckOutputLines(
		"NOTE: options.mk:2: This directive should be indented by 0 spaces.",
		"WARN: options.mk:2: GUARD_MK is used but not defined.",
		"NOTE: options.mk:3: This directive should be indented by 0 spaces.",
		"NOTE: options.mk:4: This directive should be indented by 2 spaces.",
		"WARN: options.mk:4: FILES is used but not defined.",
		"NOTE: options.mk:5: This directive should be indented by 4 spaces.",
		"WARN: options.mk:5: GUARD2_MK is used but not defined.",
		"NOTE: options.mk:6: This directive should be indented by 4 spaces.",
		"NOTE: options.mk:7: This directive should be indented by 4 spaces.",
		"NOTE: options.mk:8: This directive should be indented by 2 spaces.",
		"NOTE: options.mk:9: This directive should be indented by 2 spaces.",
		"WARN: options.mk:9: COND1 is used but not defined.",
		"NOTE: options.mk:10: This directive should be indented by 2 spaces.",
		"WARN: options.mk:10: COND2 is used but not defined.",
		"NOTE: options.mk:11: This directive should be indented by 2 spaces.",
		"ERROR: options.mk:11: \".else\" does not take arguments. If you meant \"else if\", use \".elif\".",
		"NOTE: options.mk:12: This directive should be indented by 2 spaces.",
		"NOTE: options.mk:13: This directive should be indented by 0 spaces.",
		"NOTE: options.mk:14: This directive should be indented by 0 spaces.",
		"NOTE: options.mk:15: This directive should be indented by 0 spaces.",
		"ERROR: options.mk:15: Unmatched .endif.")
}

// The .include directives do not need to be indented. They have the
// syntactical form of directives but cannot be nested in a single file.
// Therefore they may be either indented at the correct indentation depth
// or not indented at all.
func (s *Suite) Test_MkLines_Check__indentation_include(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.CreateFileLines("included.mk")
	mklines := t.SetupFileMkLines("module.mk",
		MkRcsID,
		"",
		".if ${PKGPATH} == \"category/package\"",
		".include \"included.mk\"",
		". include \"included.mk\"",
		".  include \"included.mk\"",
		".    include \"included.mk\"",
		".endif")

	mklines.Check()

	t.CheckOutputLines(
		"NOTE: ~/module.mk:5: This directive should be indented by 2 spaces.",
		"NOTE: ~/module.mk:7: This directive should be indented by 2 spaces.")
}

func (s *Suite) Test_MkLines_Check__endif_comment(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.NewMkLines("opsys.mk",
		MkRcsID,
		"",
		".for i in 1 2 3 4 5",
		".  if ${OPSYS} == NetBSD",
		".    if ${MACHINE_ARCH} == x86_64",
		".      if ${OS_VERSION:M8.*}",
		".      endif # MACHINE_ARCH", // Wrong, should be OS_VERSION.
		".    endif # OS_VERSION",     // Wrong, should be MACHINE_ARCH.
		".  endif # OPSYS",            // Correct.
		".endfor # j",                 // Wrong, should be i.
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

	t.CheckOutputLines(
		"WARN: opsys.mk:7: Comment \"MACHINE_ARCH\" does not match condition \"${OS_VERSION:M8.*}\".",
		"WARN: opsys.mk:8: Comment \"OS_VERSION\" does not match condition \"${MACHINE_ARCH} == x86_64\".",
		"WARN: opsys.mk:10: Comment \"j\" does not match loop \"i in 1 2 3 4 5\".",
		"WARN: opsys.mk:12: Unknown option \"option\".",
		"WARN: opsys.mk:20: Comment \"NetBSD\" does not match condition \"${OPSYS} == FreeBSD\".")
}

func (s *Suite) Test_MkLines_Check__unbalanced_directives(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.NewMkLines("opsys.mk",
		MkRcsID,
		"",
		".for i in 1 2 3 4 5",
		".  if ${OPSYS} == NetBSD",
		".    if ${MACHINE_ARCH} == x86_64",
		".      if ${OS_VERSION:M8.*}")

	mklines.Check()

	t.CheckOutputLines(
		"ERROR: opsys.mk:EOF: .if from line 6 must be closed.",
		"ERROR: opsys.mk:EOF: .if from line 5 must be closed.",
		"ERROR: opsys.mk:EOF: .if from line 4 must be closed.",
		"ERROR: opsys.mk:EOF: .for from line 3 must be closed.")
}

func (s *Suite) Test_MkLines_Check__incomplete_subst_at_end(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.NewMkLines("subst.mk",
		MkRcsID,
		"",
		"SUBST_CLASSES+=\tclass")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: subst.mk:EOF: Incomplete SUBST block: SUBST_STAGE.class missing.",
		"WARN: subst.mk:EOF: Incomplete SUBST block: SUBST_FILES.class missing.",
		"WARN: subst.mk:EOF: Incomplete SUBST block: SUBST_SED.class, SUBST_VARS.class or SUBST_FILTER_CMD.class missing.")
}

// Demonstrates how to define your own make(1) targets for creating
// files in the current directory. The pkgsrc-wip category Makefile
// does this, while all other categories don't need any custom code.
func (s *Suite) Test_MkLines__wip_category_Makefile(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall", "--explain")
	t.SetupVartypes()
	t.SetupTool("rm", "RM", AtRunTime)
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
		"\t\t${.CURDIR}/my-file:",
		"")
}

func (s *Suite) Test_MkLines_determineDocumentedVariables(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.SetupTool("rm", "RM", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"#",
		"# Copyright 2000-2018",
		"#",
		"# This whole comment is ignored, until the next empty line.",
		"",
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
		"PKG_DEBUG_LEVEL (line 9)",
		"PKG_VERBOSE (line 14)",
		"VARBASE1.* (line 21)",
		"VARBASE2.* (line 22)",
		"VARBASE3.${id} (line 23)",
		"VARBASE3.* (line 23)"}
	c.Check(varnames, deepEquals, expected)
}

func (s *Suite) Test_MkLines__shell_command_indentation(c *check.C) {
	t := s.Init(c)

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
	allLines := append(append([]Line(nil), included.lines.Lines...), makefile.lines.Lines...)
	mklines := NewMkLines(NewLines(included.lines.FileName, allLines))

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

func (s *Suite) Test_MkLines_CheckRedundantVariables__shell_and_eval(c *check.C) {
	t := s.Init(c)
	mklines := t.NewMkLines("module.mk",
		"VAR:=\tvalue ${OTHER}",
		"VAR!=\tvalue ${OTHER}")

	mklines.CheckRedundantVariables()

	// Combining := and != is too complicated to be analyzed by pkglint,
	// therefore no warning.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines_CheckRedundantVariables__shell_and_eval_literal(c *check.C) {
	t := s.Init(c)
	mklines := t.NewMkLines("module.mk",
		"VAR:=\tvalue",
		"VAR!=\tvalue")

	mklines.CheckRedundantVariables()

	// Even when := is used with a literal value (which is usually
	// only done for procedure calls), the shell evaluation can have
	// so many different side effects that pkglint cannot reliably
	// help in this situation.
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

func (s *Suite) Test_MkLines_Check__hacks_mk(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall,no-space")
	t.SetupVartypes()
	mklines := t.NewMkLines("hacks.mk",
		MkRcsID,
		"",
		"PKGNAME?=       pkgbase-1.0")

	mklines.Check()

	// No warning about including bsd.prefs.mk before using the ?= operator.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines_Check__MASTER_SITE_in_HOMEPAGE(c *check.C) {
	t := s.Init(c)

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

func (s *Suite) Test_MkLines_Check__VERSION_as_wordpart_in_MASTER_SITES(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.NewMkLines("geography/viking/Makefile",
		MkRcsID,
		"MASTER_SITES=\t${MASTER_SITE_SOURCEFORGE:=viking/}${VERSION}/")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: geography/viking/Makefile:2: "+
			"The list variable MASTER_SITE_SOURCEFORGE should not be embedded in a word.",
		"WARN: geography/viking/Makefile:2: VERSION is used but not defined.")
}

func (s *Suite) Test_MkLines_Check__shell_command_as_word_part_in_ENV_list(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.NewMkLines("x11/lablgtk1/Makefile",
		MkRcsID,
		"CONFIGURE_ENV+=\tCC=${CC}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: x11/lablgtk1/Makefile:2: Please use ${CC:Q} instead of ${CC}.",
		"WARN: x11/lablgtk1/Makefile:2: Please use ${CC:Q} instead of ${CC}.")
}

func (s *Suite) Test_MkLines_Check__extra_warnings(c *check.C) {
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

func (s *Suite) Test_MkLines_ForEach__conditional_variables(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall,no-space")
	t.SetupVartypes()
	mklines := t.NewMkLines("conditional.mk",
		MkRcsID,
		"",
		".if defined(PKG_DEVELOPER)",
		"DEVELOPER=\tyes",
		".endif",
		"",
		".if ${USE_TOOLS:Mgettext}",
		"USES_GETTEXT=\tyes",
		".endif")

	seenDeveloper := false
	seenUsesGettext := false

	mklines.ForEach(func(mkline MkLine) {
		if mkline.IsVarassign() {
			switch mkline.Varname() {
			case "DEVELOPER":
				c.Check(mklines.indentation.IsConditional(), equals, true)
				seenDeveloper = true
			case "USES_GETTEXT":
				c.Check(mklines.indentation.IsConditional(), equals, true)
				seenUsesGettext = true
			}
		}
	})

	c.Check(seenDeveloper, equals, true)
	c.Check(seenUsesGettext, equals, true)
}

func (s *Suite) Test_VaralignBlock_Check__autofix(c *check.C) {
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
	for _, line := range lines.Lines {
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

func (s *Suite) Test_VaralignBlock_Check__longest_line_no_space(c *check.C) {
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

func (s *Suite) Test_VaralignBlock_Check__only_spaces(c *check.C) {
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
