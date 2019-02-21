package pkglint

import (
	"gopkg.in/check.v1"
	"sort"
)

func (s *Suite) Test_MkLines_Check__unusual_target(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("cc", "CC", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"echo: echo.c",
		"\tcc -o ${.TARGET} ${.IMPSRC}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:3: Undeclared target \"echo\".")
}

func (s *Suite) Test_MkLines__quoting_LDFLAGS_for_GNU_configure(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
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

	t.SetUpVartypes()
	t.SetUpTool("echo", "ECHO", AtRunTime)
	t.SetUpTool("find", "FIND", AtRunTime)
	t.SetUpTool("pax", "PAX", AtRunTime)
	mklines := t.NewMkLines("Makefile", // From audio/squeezeboxserver
		MkRcsID,
		"",
		"SBS_COPY=\tsource target",
		"",
		".for _list_ _dir_ in ${SBS_COPY}",
		"\tcd ${WRKSRC} && ${FIND} ${${_list_}} -type f ! -name '*.orig' 2>/dev/null "+
			"| pax -rw -pm ${DESTDIR}${PREFIX}/${${_dir_}}",
		".endfor")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:5: Variable names starting with an underscore (_list_) "+
			"are reserved for internal pkgsrc use.",
		"WARN: Makefile:5: Variable names starting with an underscore (_dir_) "+
			"are reserved for internal pkgsrc use.",
		"WARN: Makefile:6: The exitcode of \"${FIND}\" at the left of the | operator is ignored.")
}

func (s *Suite) Test_MkLines__comparing_YesNo_variable_to_string(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("databases/gdbm_compat/builtin.mk",
		MkRcsID,
		".if ${USE_BUILTIN.gdbm} == \"no\"",
		".endif",
		".if ${USE_BUILTIN.gdbm:tu} == \"no\"", // Can never be true, since "no" is not uppercase.
		".endif")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: databases/gdbm_compat/builtin.mk:2: " +
			"USE_BUILTIN.gdbm should be matched against \"[yY][eE][sS]\" or \"[nN][oO]\", " +
			"not compared with \"no\".")
}

func (s *Suite) Test_MkLines__varuse_sh_modifier(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("sed", "SED", AfterPrefsMk)
	mklines := t.NewMkLines("lang/qore/module.mk",
		MkRcsID,
		"qore-version=\tqore --short-version | ${SED} -e s/-.*//",
		"PLIST_SUBST+=\tQORE_VERSION=\"${qore-version:sh}\"")

	vars2 := mklines.mklines[1].DetermineUsedVariables()

	c.Check(vars2, deepEquals, []string{"SED"})

	vars3 := mklines.mklines[2].DetermineUsedVariables()

	// qore-version, despite its unusual name, is a pretty normal Make variable.
	c.Check(vars3, deepEquals, []string{"qore-version"})

	mklines.Check()

	// No warnings about defined but not used or vice versa
	t.CheckOutputEmpty()
}

// For parameterized variables, the "defined but not used" and
// the "used but not defined" checks are loosened a bit.
// When VAR.param1 is defined or used, VAR.param2 is also regarded
// as defined or used since often in pkgsrc, parameterized variables
// are not referred to by their exact names but by VAR.${param}.
func (s *Suite) Test_MkLines__varuse_parameterized(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("converters/wv2/Makefile",
		MkRcsID,
		"CONFIGURE_ARGS+=\t\t${CONFIGURE_ARGS.${ICONV_TYPE}-iconv}",
		"CONFIGURE_ARGS.gnu-iconv=\t--with-libiconv=${BUILDLINK_PREFIX.iconv}")

	mklines.Check()

	// No warnings about CONFIGURE_ARGS.* being defined but not used or vice versa.
	t.CheckOutputLines(
		"WARN: converters/wv2/Makefile:2: ICONV_TYPE is used but not defined.")
}

// When an ODE runtime loop is used to expand variables to shell commands,
// pkglint only understands that there is a variable that is executed as
// shell command.
//
// In this example, GCONF_SCHEMAS is a list of filenames, but pkglint doesn't know this
// because there is no built-in rule saying *_SCHEMAS are filenames.
// If the variable name had been GCONF_SCHEMA_FILES, pkglint would know.
//
// As of November 2018, pkglint sees GCONF_SCHEMAS as being the shell command.
// It doesn't expand the @s@ loop to see what really happens.
//
// If it did that, it could notice that GCONF_SCHEMAS expands to a single shell command,
// and in that command INSTALL_DATA is used as the command for the first time,
// and as a regular command line argument in all other times.
// This combination is strange enough to warrant a warning.
//
// The bug here is the missing semicolon just before the @}.
//
// Pkglint could offer to either add the missing semicolon.
// Or, if it knows what INSTALL_DATA does, it could simply say that INSTALL_DATA
// can handle multiple files in a single invocation.
func (s *Suite) Test_MkLines__loop_modifier(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("chat/xchat/Makefile",
		MkRcsID,
		"GCONF_SCHEMAS=\tapps_xchat_url_handler.schemas",
		"post-install:",
		"\t${GCONF_SCHEMAS:@s@"+
			"${INSTALL_DATA} ${WRKSRC}/src/common/dbus/${s} ${DESTDIR}${GCONF_SCHEMAS_DIR}/@}")

	mklines.Check()

	// Earlier versions of pkglint warned about a missing @ at the end.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines__PKG_SKIP_REASON_depending_on_OPSYS(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"PKG_SKIP_REASON+=\t\"Fails everywhere\"",
		".if ${OPSYS} == \"Cygwin\"",
		"PKG_SKIP_REASON+=\t\"Fails on Cygwin\"",
		".endif")

	mklines.Check()

	t.CheckOutputLines(
		"NOTE: Makefile:4: Consider setting NOT_FOR_PLATFORM instead of PKG_SKIP_REASON depending on ${OPSYS}.")
}

func (s *Suite) Test_MkLines_Check__use_list_variable_as_part_of_word(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("tr", "", AtRunTime)
	mklines := t.NewMkLines("converters/chef/Makefile",
		MkRcsID,
		"\tcd ${WRKSRC} && tr '\\r' '\\n' < ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} > chef.l")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: converters/chef/Makefile:2: The list variable DISTFILES should not be embedded in a word.")
}

func (s *Suite) Test_MkLines_Check__absolute_pathname_depending_on_OPSYS(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("games/heretic2-demo/Makefile",
		MkRcsID,
		".if ${OPSYS} == \"DragonFly\"",
		"TAR_CMD=\t/usr/bin/bsdtar",
		".endif",
		"TAR_CMD=\t/usr/bin/bsdtar",
		"",
		"do-extract:",
		"\t${TAR_CMD}")

	mklines.Check()

	// No warning about an unknown shell command in line 3 since that line depends on OPSYS.
	// Shell commands that are specific to an operating system are probably defined
	// and used intentionally, so even commands that are not known tools are allowed.
	t.CheckOutputLines(
		"WARN: games/heretic2-demo/Makefile:5: Unknown shell command \"/usr/bin/bsdtar\".")
}

func (s *Suite) Test_MkLines_CheckForUsedComment(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--show-autofix")

	test := func(pkgpath string, lines []string, diagnostics []string) {
		mklines := t.NewMkLines("Makefile.common", lines...)

		mklines.CheckForUsedComment(pkgpath)

		if len(diagnostics) > 0 {
			t.CheckOutputLines(diagnostics...)
		} else {
			t.CheckOutputEmpty()
		}
	}

	lines := func(lines ...string) []string { return lines }
	diagnostics := func(diagnostics ...string) []string { return diagnostics }

	// This file is too short to be checked.
	test(
		"category/package",
		lines(),
		diagnostics())

	// Still too short.
	test(
		"category/package",
		lines(
			MkRcsID),
		diagnostics())

	// Still too short.
	test(
		"category/package",
		lines(
			MkRcsID,
			""),
		diagnostics())

	// This file is correctly mentioned.
	test(
		"sysutils/mc",
		lines(
			MkRcsID,
			"",
			"# used by sysutils/mc"),
		diagnostics())

	// This file is not correctly mentioned, therefore the line is inserted.
	// TODO: Since the following line is of a different type, an additional empty line should be inserted.
	test(
		"category/package",
		lines(
			MkRcsID,
			"",
			"VARNAME=\tvalue"),
		diagnostics(
			"WARN: Makefile.common:2: Please add a line \"# used by category/package\" here.",
			"AUTOFIX: Makefile.common:2: Inserting a line \"# used by category/package\" before this line."))

	// The "used by" comments may either start in line 2 or in line 3.
	test(
		"category/package",
		lines(
			MkRcsID,
			"#",
			"#"),
		diagnostics(
			"WARN: Makefile.common:3: Please add a line \"# used by category/package\" here.",
			"AUTOFIX: Makefile.common:3: Inserting a line \"# used by category/package\" before this line."))

	// TODO: What if there is an introductory comment first? That should stay at the top of the file.
	// TODO: What if the "used by" comments appear in the second paragraph, preceded by only comments and empty lines?

	c.Check(G.autofixAvailable, equals, true)
}

func (s *Suite) Test_MkLines_collectDefinedVariables(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall,no-space")
	t.SetUpPkgsrc()
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
		"\t${RUN} autoreconf; autoheader-2.13",
		"\t${ECHO} ${OSV:Q}")

	mklines.Check()

	// The tools autoreconf and autoheader213 are known at this point because of the USE_TOOLS line.
	// The SUV variable is used implicitly by the SUBST framework, therefore no warning.
	// The OSV.NetBSD variable is used implicitly via the OSV variable, therefore no warning.
	t.CheckOutputLines(
		// FIXME: the below warning is wrong; it's ok to have SUBST blocks in all files,
		// maybe except buildlink3.mk.
		"WARN: determine-defined-variables.mk:12: The variable SUBST_VARS.subst may not be set " +
			"(only given a default value, or appended to) in this file; " +
			"it would be ok in Makefile, Makefile.common or options.mk.")
}

func (s *Suite) Test_MkLines_collectDefinedVariables__BUILTIN_FIND_FILES_VAR(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall,no-space")
	t.SetUpPackage("category/package")
	t.CreateFileLines("mk/buildlink3/bsd.builtin.mk",
		MkRcsID)
	mklines := t.SetUpFileMkLines("category/package/builtin.mk",
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

func (s *Suite) Test_MkLines_collectUsedVariables__simple(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename",
		"\t${VAR}")
	mkline := mklines.mklines[0]
	G.Mk = mklines

	mklines.collectUsedVariables()

	c.Check(mklines.vars.used, deepEquals, map[string]MkLine{"VAR": mkline})
	c.Check(mklines.vars.FirstUse("VAR"), equals, mkline)
}

func (s *Suite) Test_MkLines_collectUsedVariables__nested(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		MkRcsID,
		"",
		"LHS.${lparam}=\tRHS.${rparam}",
		"",
		"target:",
		"\t${outer.${inner}}")
	assignMkline := mklines.mklines[2]
	shellMkline := mklines.mklines[5]
	G.Mk = mklines

	mklines.collectUsedVariables()

	c.Check(len(mklines.vars.used), equals, 5)
	c.Check(mklines.vars.FirstUse("lparam"), equals, assignMkline)
	c.Check(mklines.vars.FirstUse("rparam"), equals, assignMkline)
	c.Check(mklines.vars.FirstUse("inner"), equals, shellMkline)
	c.Check(mklines.vars.FirstUse("outer.*"), equals, shellMkline)
	c.Check(mklines.vars.FirstUse("outer.${inner}"), equals, shellMkline)
}

func (s *Suite) Test_MkLines__private_tool_undefined(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("filename",
		MkRcsID,
		"",
		"\tmd5sum filename")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename:3: Unknown shell command \"md5sum\".")
}

func (s *Suite) Test_MkLines__private_tool_defined(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("filename",
		MkRcsID,
		"TOOLS_CREATE+=\tmd5sum",
		"",
		"\tmd5sum filename")

	mklines.Check()

	// TODO: Is it necessary to add the tool to USE_TOOLS? If not, why not?
	t.CheckOutputLines(
		"WARN: filename:4: The \"md5sum\" tool is used but not added to USE_TOOLS.")
}

func (s *Suite) Test_MkLines_Check__indentation(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
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

	t.SetUpVartypes()
	t.CreateFileLines("included.mk")
	mklines := t.SetUpFileMkLines("module.mk",
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

func (s *Suite) Test_MkLines_Check__unfinished_directives(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
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

func (s *Suite) Test_MkLines_Check__unbalanced_directives(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("opsys.mk",
		MkRcsID,
		"",
		".for i in 1 2 3 4 5",
		".  if ${OPSYS} == NetBSD",
		".  endfor",
		".endif")

	mklines.Check()

	// As of November 2018 pkglint doesn't find that the inner .if is closed by an .endfor.
	// This is checked by bmake, though.
	//
	// As soon as pkglint starts to analyze .if/.for as regular statements
	// like in most programming languages, it will find this inconsistency, too.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines_Check__incomplete_subst_at_end(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
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

	t.SetUpCommandLine("-Wall", "--explain")
	t.SetUpVartypes()
	t.SetUpTool("rm", "RM", AtRunTime)
	t.CreateFileLines("mk/misc/category.mk")
	mklines := t.SetUpFileMkLines("wip/Makefile",
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
		"WARN: ~/wip/Makefile:14: Undeclared target \"clean-tmpdir\".",
		"",
		"\tTo define a custom target in a package, declare it like this:",
		"",
		"\t\t.PHONY: my-target",
		"",
		"\tTo define a custom target that creates a file (should be rarely",
		"\tneeded), declare it like this:",
		"",
		"\t\t${.CURDIR}/my-file:",
		"")
}

func (s *Suite) Test_MkLines_collectDocumentedVariables(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("rm", "RM", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"#",
		"# Copyright 2000-2018",
		"#",
		"# This whole comment is ignored, until the next empty line.",
		"# Since it contains the word \"copyright\", it's probably legalese",
		"# instead of documentation.",
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
	// both used and defined, to prevent the "defined but not used" warnings.
	mklines.collectDocumentedVariables()

	var varnames []string
	for varname, mkline := range mklines.vars.used {
		varnames = append(varnames, sprintf("%s (line %s)", varname, mkline.Linenos()))
	}
	sort.Strings(varnames)

	expected := []string{
		"PKG_DEBUG_LEVEL (line 11)",
		"PKG_VERBOSE (line 16)",
		"VARBASE1.* (line 23)",
		"VARBASE2.* (line 24)",
		"VARBASE3.* (line 25)"}
	c.Check(varnames, deepEquals, expected)
}

func (s *Suite) Test_MkLines__shell_command_indentation(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
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

	t.SetUpVartypes()
	t.SetUpOption("known", "")
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

func (s *Suite) Test_MkLines_CheckRedundantAssignments__override_in_mk(c *check.C) {
	t := s.Init(c)
	included := t.NewMkLines("included.mk",
		"OVERRIDE=\tprevious value",
		"REDUNDANT=\tredundant")
	including := t.NewMkLines("including.mk",
		".include \"included.mk\"",
		"OVERRIDE=\toverridden value",
		"REDUNDANT=\tredundant")

	var allLines []Line
	allLines = append(allLines, including.lines.Lines[:1]...)
	allLines = append(allLines, included.lines.Lines...)
	allLines = append(allLines, including.lines.Lines[1:]...)
	mklines := NewMkLines(NewLines(included.lines.FileName, allLines))

	// XXX: The warnings from here are not in the same order as the other warnings.
	// XXX: There may be some warnings for the same file separated by warnings for other files.
	mklines.CheckRedundantAssignments()

	t.CheckOutputLines(
		"NOTE: including.mk:3: Definition of REDUNDANT is redundant because of included.mk:2.")
}

func (s *Suite) Test_MkLines_CheckRedundantAssignments__override_in_Makefile(c *check.C) {
	t := s.Init(c)
	included := t.NewMkLines("module.mk",
		"VAR=\tvalue ${OTHER}",
		"VAR?=\tvalue ${OTHER}",
		"VAR=\tnew value")
	including := t.NewMkLines("Makefile",
		".include \"module.mk\"",
		"VAR=\tthe package may overwrite variables from other files")

	var allLines []Line
	allLines = append(allLines, including.lines.Lines[:1]...)
	allLines = append(allLines, included.lines.Lines...)
	allLines = append(allLines, including.lines.Lines[1:]...)
	mklines := NewMkLines(NewLines(including.lines.FileName, allLines))

	// XXX: The warnings from here are not in the same order as the other warnings.
	// XXX: There may be some warnings for the same file separated by warnings for other files.
	mklines.CheckRedundantAssignments()

	// No warning for VAR=... in Makefile since it makes sense to have common files
	// with default values for variables, overriding some of them in each package.
	t.CheckOutputLines(
		"NOTE: module.mk:2: Definition of VAR is redundant because of line 1.",
		"WARN: module.mk:1: Variable VAR is overwritten in line 3.")
}

func (s *Suite) Test_MkLines_CheckRedundantAssignments__default_value_definitely_unused(c *check.C) {
	t := s.Init(c)
	mklines := t.NewMkLines("module.mk",
		"VAR=\tvalue ${OTHER}",
		"VAR?=\tdifferent value")

	mklines.CheckRedundantAssignments()

	// FIXME: A default assignment after an unconditional assignment is redundant.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines_CheckRedundantAssignments__default_value_overridden(c *check.C) {
	t := s.Init(c)
	mklines := t.NewMkLines("module.mk",
		"VAR?=\tdefault value",
		"VAR=\toverridden value")

	mklines.CheckRedundantAssignments()

	t.CheckOutputLines(
		"WARN: module.mk:1: Variable VAR is overwritten in line 2.")
}

func (s *Suite) Test_MkLines_CheckRedundantAssignments__overwrite_same_value(c *check.C) {
	t := s.Init(c)
	mklines := t.NewMkLines("module.mk",
		"VAR=\tvalue ${OTHER}",
		"VAR=\tvalue ${OTHER}")

	mklines.CheckRedundantAssignments()

	t.CheckOutputLines(
		"NOTE: module.mk:2: Definition of VAR is redundant because of line 1.")
}

func (s *Suite) Test_MkLines_CheckRedundantAssignments__conditional_overwrite(c *check.C) {
	t := s.Init(c)
	mklines := t.NewMkLines("module.mk",
		"VAR=\tdefault",
		".if ${OPSYS} == NetBSD",
		"VAR=\topsys",
		".endif")

	mklines.CheckRedundantAssignments()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines_CheckRedundantAssignments__conditional_default(c *check.C) {
	t := s.Init(c)
	mklines := t.NewMkLines("module.mk",
		"VAR=\tdefault",
		".if ${OPSYS} == NetBSD",
		"VAR?=\topsys",
		".endif")

	mklines.CheckRedundantAssignments()

	// TODO: WARN: module.mk:3: The value \"opsys\" will never be assigned to VAR because it is defined unconditionally in line 1.
	t.CheckOutputEmpty()
}

// These warnings are precise and accurate since the value of VAR is not used between line 2 and 4.
func (s *Suite) Test_MkLines_CheckRedundantAssignments__overwrite_same_variable_different_value(c *check.C) {
	t := s.Init(c)
	mklines := t.NewMkLines("module.mk",
		"OTHER=\tvalue before",
		"VAR=\tvalue ${OTHER}",
		"OTHER=\tvalue after",
		"VAR=\tvalue ${OTHER}")

	mklines.CheckRedundantAssignments()

	t.CheckOutputLines(
		"WARN: module.mk:1: Variable OTHER is overwritten in line 3.",
		"NOTE: module.mk:4: Definition of VAR is redundant because of line 2.")
}

func (s *Suite) Test_MkLines_CheckRedundantAssignments__overwrite_different_value_used_between(c *check.C) {
	t := s.Init(c)
	mklines := t.NewMkLines("module.mk",
		"OTHER=\tvalue before",
		"VAR=\tvalue ${OTHER}",

		// VAR is used here at load time, therefore it must be defined at this point.
		// At this point, VAR uses the \"before\" value of OTHER.
		"RESULT1:=\t${VAR}",

		"OTHER=\tvalue after",

		// VAR is used here again at load time, this time using the \"after\" value of OTHER.
		"RESULT2:=\t${VAR}",

		// Still this definition is redundant.
		"VAR=\tvalue ${OTHER}")

	mklines.CheckRedundantAssignments()

	t.CheckOutputLines(
		"WARN: module.mk:1: Variable OTHER is overwritten in line 4.",
		"NOTE: module.mk:6: Definition of VAR is redundant because of line 2.")
}

func (s *Suite) Test_MkLines_CheckRedundantAssignments__procedure_call(c *check.C) {
	t := s.Init(c)
	mklines := t.NewMkLines("mk/pthread.buildlink3.mk",
		"CHECK_BUILTIN.pthread:=\tyes",
		".include \"../../mk/pthread.builtin.mk\"",
		"CHECK_BUILTIN.pthread:=\tno")

	mklines.CheckRedundantAssignments()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines_CheckRedundantAssignments__shell_and_eval(c *check.C) {
	t := s.Init(c)
	mklines := t.NewMkLines("module.mk",
		"VAR:=\tvalue ${OTHER}",
		"VAR!=\tvalue ${OTHER}")

	mklines.CheckRedundantAssignments()

	// As of November 2018, pkglint doesn't check redundancies that involve the := or != operators.
	//
	// What happens here is:
	//
	// Line 1 evaluates OTHER at load time.
	// Line 1 assigns its value to VAR.
	// Line 2 evaluates OTHER at load time.
	// Line 2 passes its value through the shell and assigns the result to VAR.
	//
	// Since VAR is defined in line 1, not used afterwards and overwritten in line 2, it is redundant.
	// Well, not quite, because evaluating ${OTHER} might have side-effects from :sh or ::= modifiers,
	// but these are so rare that they are frowned upon and are not considered by pkglint.
	//
	// Expected result:
	// WARN: module.mk:2: Previous definition of VAR in line 1 is unused.

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines_CheckRedundantAssignments__shell_and_eval_literal(c *check.C) {
	t := s.Init(c)
	mklines := t.NewMkLines("module.mk",
		"VAR:=\tvalue",
		"VAR!=\tvalue")

	mklines.CheckRedundantAssignments()

	// Even when := is used with a literal value (which is usually
	// only done for procedure calls), the shell evaluation can have
	// so many different side effects that pkglint cannot reliably
	// help in this situation.
	//
	// TODO: Why not? The evaluation in line 1 is trivial to analyze.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines_CheckRedundantAssignments__included_OPSYS_variable(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"../../category/dependency/buildlink3.mk\"",
		"CONFIGURE_ARGS+=\tone",
		"CONFIGURE_ARGS=\ttwo",
		"CONFIGURE_ARGS+=\tthree")
	t.SetUpPackage("category/dependency")
	t.CreateFileDummyBuildlink3("category/dependency/buildlink3.mk")
	t.CreateFileLines("category/dependency/builtin.mk",
		MkRcsID,
		"CONFIGURE_ARGS.Darwin+=\tdarwin")

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:21: Variable CONFIGURE_ARGS is overwritten in line 22.")
}

func (s *Suite) Test_MkLines_Check__PLIST_VARS(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wno-space")
	t.SetUpVartypes()
	t.SetUpOption("both", "")
	t.SetUpOption("only-added", "")
	t.SetUpOption("only-defined", "")
	t.CreateFileLines("mk/bsd.options.mk")

	mklines := t.SetUpFileMkLines("category/package/options.mk",
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
		"WARN: ~/category/package/options.mk:9: \"only-added\" is added to PLIST_VARS, but PLIST.only-added is not defined in this file.",
		"WARN: ~/category/package/options.mk:16: PLIST.only-defined is defined, but \"only-defined\" is not added to PLIST_VARS in this file.")
}

func (s *Suite) Test_MkLines_Check__PLIST_VARS_indirect(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wno-space")
	t.SetUpVartypes()
	t.SetUpOption("option1", "")
	t.SetUpOption("option2", "")

	mklines := t.SetUpFileMkLines("module.mk",
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

	// As of November 2018, pkglint doesn't analyze the .if 0 block.
	// Therefore it doesn't know that the option1 block will never match because of the 0.
	// This is ok though since it could be a temporary workaround from the package maintainer.
	//
	// As of November 2018, pkglint doesn't analyze the .for loop.
	// Therefore it doesn't know that an .if block for option3 is missing.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines_Check__PLIST_VARS_indirect_2(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wno-space")
	t.SetUpVartypes()
	t.SetUpOption("a", "")
	t.SetUpOption("b", "")
	t.SetUpOption("c", "")

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

func (s *Suite) Test_MkLines_collectElse(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wno-space")
	t.SetUpVartypes()

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

	t.SetUpCommandLine("-Wno-space")
	t.SetUpVartypes()

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

func (s *Suite) Test_MkLines_Check__hacks_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall,no-space")
	t.SetUpVartypes()
	mklines := t.NewMkLines("hacks.mk",
		MkRcsID,
		"",
		"PKGNAME?=       pkgbase-1.0")

	mklines.Check()

	// No warning about including bsd.prefs.mk before using the ?= operator.
	// FIXME: Why not?
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines_Check__MASTER_SITE_in_HOMEPAGE(c *check.C) {
	t := s.Init(c)

	t.SetUpMasterSite("MASTER_SITE_GITHUB", "https://github.com/")
	t.SetUpVartypes()
	G.Mk = t.NewMkLines("devel/catch/Makefile",
		MkRcsID,
		"HOMEPAGE=\t${MASTER_SITE_GITHUB:=philsquared/Catch/}",
		"HOMEPAGE=\t${MASTER_SITE_GITHUB}",
		"HOMEPAGE=\t${MASTER_SITES}",
		"HOMEPAGE=\t${MASTER_SITES}${GITHUB_PROJECT}")

	G.Mk.Check()

	t.CheckOutputLines(
		"WARN: devel/catch/Makefile:2: HOMEPAGE should not be defined in terms of MASTER_SITEs. "+
			"Use https://github.com/philsquared/Catch/ directly.",
		"WARN: devel/catch/Makefile:3: HOMEPAGE should not be defined in terms of MASTER_SITEs. "+
			"Use https://github.com/ directly.",
		"WARN: devel/catch/Makefile:4: HOMEPAGE should not be defined in terms of MASTER_SITEs.",
		"WARN: devel/catch/Makefile:5: HOMEPAGE should not be defined in terms of MASTER_SITEs.")
}

func (s *Suite) Test_MkLines_Check__VERSION_as_word_part_in_MASTER_SITES(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
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

	t.SetUpVartypes()
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

	t.SetUpCommandLine("-Wextra")
	t.SetUpVartypes()
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
		"NOTE: options.mk:5: Please use \"# empty\", \"# none\" or \"# yes\" instead of \"# defined\".",
		"WARN: options.mk:7: Please include \"../../mk/bsd.prefs.mk\" before using \"?=\".",
		"WARN: options.mk:11: Building the package should take place entirely inside ${WRKSRC}, not \"${WRKSRC}/..\".",
		"NOTE: options.mk:11: You can use \"../build\" instead of \"${WRKSRC}/../build\".")
}

// Ensures that during MkLines.ForEach, the conditional variables in
// MkLines.Indentation are correctly updated for each line.
func (s *Suite) Test_MkLines_ForEach__conditional_variables(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall,no-space")
	t.SetUpVartypes()
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

// At 2018-12-02, pkglint had resolved ${MY_PLIST_VARS} into a single word,
// whereas the correct behavior is to resolve it into two words.
// It had produced warnings about mismatched PLIST_VARS IDs.
func (s *Suite) Test_MkLines_checkVarassignPlist__indirect(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.SetUpFileMkLines("plist.mk",
		MkRcsID,
		"",
		"MY_PLIST_VARS=\tvar1 var2",
		"PLIST_VARS+=\t${MY_PLIST_VARS}",
		"",
		"PLIST.var1=\tyes",
		"PLIST.var2=\tyes")

	mklines.Check()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_VaralignBlock_Process__autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wspace", "--show-autofix")

	mklines := t.NewMkLines("file.mk",
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

	var varalign VaralignBlock
	for _, line := range mklines.mklines {
		varalign.Process(line)
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

// When the lines of a paragraph are inconsistently aligned,
// they are realigned to the minimum required width.
func (s *Suite) Test_VaralignBlock_Process__reduce_indentation(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		"VAR= \tvalue",
		"VAR=    \tvalue",
		"VAR=\t\t\t\tvalue",
		"",
		"VAR=\t\t\tneedlessly", // Nothing to be fixed here, since it looks good.
		"VAR=\t\t\tdeep",
		"VAR=\t\t\tindentation")

	var varalign VaralignBlock
	for _, mkline := range mklines.mklines {
		varalign.Process(mkline)
	}
	varalign.Finish()

	t.CheckOutputLines(
		"NOTE: file.mk:1: Variable values should be aligned with tabs, not spaces.",
		"NOTE: file.mk:2: This variable value should be aligned with tabs, not spaces, to column 9.",
		"NOTE: file.mk:3: This variable value should be aligned to column 9.")
}

// For every variable assignment, there is at least one space or tab between the variable
// name and the value. Even if it is the longest line, and even if the value would start
// exactly at a tab stop.
func (s *Suite) Test_VaralignBlock_Process__longest_line_no_space(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wspace")
	mklines := t.NewMkLines("file.mk",
		"SUBST_CLASSES+= aaaaaaaa",
		"SUBST_STAGE.aaaaaaaa= pre-configure",
		"SUBST_FILES.aaaaaaaa= *.pl",
		"SUBST_FILTER_CMD.aaaaaa=cat")

	var varalign VaralignBlock
	for _, mkline := range mklines.mklines {
		varalign.Process(mkline)
	}
	varalign.Finish()

	t.CheckOutputLines(
		"NOTE: file.mk:1: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:2: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:3: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:4: This variable value should be aligned to column 33.")
}

func (s *Suite) Test_VaralignBlock_Process__only_spaces(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wspace")
	mklines := t.NewMkLines("file.mk",
		"SUBST_CLASSES+= aaaaaaaa",
		"SUBST_STAGE.aaaaaaaa= pre-configure",
		"SUBST_FILES.aaaaaaaa= *.pl",
		"SUBST_FILTER_CMD.aaaaaaaa= cat")

	var varalign VaralignBlock
	for _, mkline := range mklines.mklines {
		varalign.Process(mkline)
	}
	varalign.Finish()

	t.CheckOutputLines(
		"NOTE: file.mk:1: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:2: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:3: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:4: This variable value should be aligned with tabs, not spaces, to column 33.")
}
