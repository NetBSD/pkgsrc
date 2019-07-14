package pkglint

import (
	"gopkg.in/check.v1"
	"sort"
	"strings"
)

func (s *Suite) Test_MkLines_Check__unusual_target(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("cc", "CC", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
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
		MkCvsID,
		"GNU_CONFIGURE=\tyes",
		"CONFIGURE_ENV+=\tX_LIBS=${X11_LDFLAGS:Q}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:3: Please use ${X11_LDFLAGS:M*:Q} instead of ${X11_LDFLAGS:Q}.")
}

func (s *Suite) Test_MkLines__for_loop_multiple_variables(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("echo", "ECHO", AtRunTime)
	t.SetUpTool("find", "FIND", AtRunTime)
	t.SetUpTool("pax", "PAX", AtRunTime)
	mklines := t.NewMkLines("Makefile", // From audio/squeezeboxserver
		MkCvsID,
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
		MkCvsID,
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
		MkCvsID,
		"qore-version=\tqore --short-version | ${SED} -e s/-.*//",
		"PLIST_SUBST+=\tQORE_VERSION=\"${qore-version:sh}\"")

	var vars2 []string
	mklines.mklines[1].ForEachUsed(func(varUse *MkVarUse, time VucTime) {
		vars2 = append(vars2, varUse.varname)
	})

	t.CheckDeepEquals(vars2, []string{"SED"})

	var vars3 []string
	mklines.mklines[2].ForEachUsed(func(varUse *MkVarUse, time VucTime) {
		vars3 = append(vars3, varUse.varname)
	})

	// qore-version, despite its unusual name, is a pretty normal Make variable.
	t.CheckDeepEquals(vars3, []string{"qore-version"})

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
		MkCvsID,
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
		MkCvsID,
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
		MkCvsID,
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
		MkCvsID,
		"\tcd ${WRKSRC} && tr '\\r' '\\n' < ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} > chef.l")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: converters/chef/Makefile:2: The list variable DISTFILES should not be embedded in a word.")
}

func (s *Suite) Test_MkLines_Check__absolute_pathname_depending_on_OPSYS(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("games/heretic2-demo/Makefile",
		MkCvsID,
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

func (s *Suite) Test_MkLines_CheckUsedBy__show_autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--show-autofix")

	test := func(pkgpath string, lines []string, diagnostics []string) {
		mklines := t.NewMkLines("Makefile.common", lines...)

		mklines.CheckUsedBy(pkgpath)

		t.CheckOutput(diagnostics)
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
			MkCvsID),
		diagnostics())

	// Still too short.
	test(
		"category/package",
		lines(
			MkCvsID,
			""),
		diagnostics())

	// This file is correctly mentioned.
	test(
		"sysutils/mc",
		lines(
			MkCvsID,
			"",
			"# used by sysutils/mc"),
		diagnostics())

	// This file is not correctly mentioned, therefore the line is inserted.
	test(
		"category/package",
		lines(
			MkCvsID,
			"",
			"VARNAME=\tvalue"),
		diagnostics(
			"WARN: Makefile.common:1: Please add a line \"# used by category/package\" here.",
			"AUTOFIX: Makefile.common:1: Inserting a line \"# used by category/package\" after this line."))

	// The "used by" comments may either start in line 2 or in line 3.
	test(
		"category/package",
		lines(
			MkCvsID,
			"#",
			"#"),
		diagnostics(
			"WARN: Makefile.common:1: Please add a line \"# used by category/package\" here.",
			"AUTOFIX: Makefile.common:1: Inserting a line \"# used by category/package\" after this line."))

	// TODO: What if there is an introductory comment first? That should stay at the top of the file.
	// TODO: What if the "used by" comments appear in the second paragraph, preceded by only comments and empty lines?

	// Since the first paragraph already has some comments, the "used by"
	// comments need their separate paragraph, which is inserted after
	// the first paragraph.
	test("category/package",
		lines(
			MkCvsID,
			"# A normal comment",
			"# that spans",
			"# several lines"),
		diagnostics(
			"AUTOFIX: Makefile.common:4: Inserting a line \"\" after this line.",
			"WARN: Makefile.common:4: Please add a line \"# used by category/package\" here.",
			"AUTOFIX: Makefile.common:4: Inserting a line \"# used by category/package\" after this line."))

	t.CheckEquals(G.Logger.autofixAvailable, true)
}

func (s *Suite) Test_MkLines_CheckUsedBy(c *check.C) {
	t := s.Init(c)

	test := func(pkgpath string, lines []string, diagnostics []string) {
		mklines := t.NewMkLines("Makefile.common", lines...)

		mklines.CheckUsedBy(pkgpath)

		t.CheckOutput(diagnostics)
	}

	lines := func(lines ...string) []string { return lines }
	diagnostics := func(diagnostics ...string) []string { return diagnostics }

	// The including package is already mentioned in the single "used by"
	// paragraph. Nothing needs to be changed.
	test("category/package2/Makefile",
		lines(
			MkCvsID,
			"# This Makefile fragment is",
			"# used by category/package1/Makefile, as well as", // looks similar to the formal "used by".
			"# some others.",
			"",
			"# used by category/package2/Makefile"),
		diagnostics())

	// The including file is not yet mentioned. There is a single "used by"
	// paragraph, and the including file needs to be added to that paragraph.
	// It is added in the correct sorting order. The entries are simply
	// sorted alphabetically.
	test("category/package/Makefile",
		lines(
			MkCvsID,
			"# This Makefile fragment is",
			"# used by category/package1/Makefile, as well as", // looks similar to the formal "used by".
			"# some others.",
			"",
			"# used by category/package2/Makefile"),
		diagnostics(
			"WARN: Makefile.common:6: Please add a line \"# used by category/package/Makefile\" here."))

	// There are two separate paragraphs with "used by" lines. The first of
	// them is the interesting one. The new line is added to the first paragraph.
	test("category/package",
		lines(
			MkCvsID,
			"# used by category/package1",
			"",
			"# used by category/package2"),
		diagnostics(
			"WARN: Makefile.common:4: There should only be a single \"used by\" paragraph per file.",
			"WARN: Makefile.common:2: Please add a line \"# used by category/package\" here."))

	// The empty comment also separates the two paragraphs, like in the
	// previous test case.
	test("category/package",
		lines(
			MkCvsID,
			"# used by category/package1",
			"#",
			"# used by category/package2"),
		diagnostics(
			"WARN: Makefile.common:4: There should only be a single \"used by\" paragraph per file.",
			"WARN: Makefile.common:2: Please add a line \"# used by category/package\" here."))

	// Code coverage for hasOther being true and conflict being non-nil.
	// Ensures that the warning is printed in the first wrong line.
	test("category/package",
		lines(
			MkCvsID,
			"",
			"# Unrelated comment.",
			"# used by category/package1",
			"# used by category/package2"),
		diagnostics(
			"WARN: Makefile.common:4: The \"used by\" lines should be in a separate paragraph.",
			"WARN: Makefile.common:1: Please add a line \"# used by category/package\" here."))

	// Code coverage for hasUsedBy being true and conflict being non-nil.
	// Ensures that the warning is printed in the first wrong line.
	test("category/package",
		lines(
			MkCvsID,
			"",
			"# used by category/package1",
			"# Unrelated comment.",
			"# Unrelated comment 2."),
		diagnostics(
			"WARN: Makefile.common:4: The \"used by\" lines should be in a separate paragraph.",
			"WARN: Makefile.common:1: Please add a line \"# used by category/package\" here."))

	t.CheckEquals(G.Logger.autofixAvailable, true)
}

func (s *Suite) Test_MkLines_CheckUsedBy__separate_paragraph(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("Makefile.common",
		MkCvsID,
		"# a comment",
		"# used by category/package",
		"# a comment")

	mklines.CheckUsedBy("category/package")

	t.CheckOutputLines(
		"WARN: Makefile.common:3: The \"used by\" lines should be in a separate paragraph.")
}

func (s *Suite) Test_MkLines_ExpandLoopVar(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"",
		".for file in a b c d e f g h",
		".  for rank in 1 2 3 4 5 6 7 8",
		"CHESS_BOARD+=\t${file}${rank}",
		".  endfor",
		".endfor")

	var files []string
	var ranks []string
	var diagonals []string
	mklines.ForEach(func(mkline *MkLine) {
		if mkline.IsVarassign() {
			ranks = mklines.ExpandLoopVar("rank")
			files = mklines.ExpandLoopVar("file")
			diagonals = mklines.ExpandLoopVar("diagonals")
		}
	})

	t.CheckDeepEquals(files, strings.Split("abcdefgh", ""))
	t.CheckDeepEquals(ranks, strings.Split("12345678", ""))
	t.Check(diagonals, check.HasLen, 0)
}

func (s *Suite) Test_MkLines_ExpandLoopVar__multi(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"",
		".if 1",
		".  for key value in 1 one 2 two 3 three",
		"VAR.${key}=\t${value}",
		".  endfor",
		".endif")

	var keys []string
	var values []string
	mklines.ForEach(func(mkline *MkLine) {
		if mkline.IsVarassign() {
			keys = mklines.ExpandLoopVar("key")
			values = mklines.ExpandLoopVar("value")
		}
	})

	// As of June 2019, multi-variable .for loops are not yet implemented.
	t.Check(keys, check.HasLen, 0)
	t.Check(values, check.HasLen, 0)
}

func (s *Suite) Test_MkLines_ExpandLoopVar__malformed_for(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"",
		".for var in",
		"VAR=\t${var}",
		".endfor")

	var values = []string{"uninitialized"}
	mklines.ForEach(func(mkline *MkLine) {
		if mkline.IsVarassign() {
			values = mklines.ExpandLoopVar("key")
		}
	})

	t.Check(values, check.HasLen, 0)
}

func (s *Suite) Test_MkLines_collectVariables(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall,no-space")
	t.SetUpPkgsrc()
	t.CreateFileLines("mk/tools/defaults.mk",
		"USE_TOOLS+=     autoconf autoconf213")
	mklines := t.NewMkLines("determine-defined-variables.mk",
		MkCvsID,
		"",
		"USE_TOOLS+=             autoconf213 autoconf",
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
		"#BUILD_DEFS+=           VARBASE",
		"",
		"pre-configure:",
		"\t${RUN} autoreconf; autoheader-2.13",
		"\t${ECHO} ${OSV:Q}")
	t.FinishSetUp()

	mklines.Check()

	// The tools autoreconf and autoheader213 are known at this point because of the USE_TOOLS line.
	// The SUV variable is used implicitly by the SUBST framework, therefore no warning.
	// The OSV.NetBSD variable is used indirectly because OSV is declared
	// as being OPSYS-specific, therefore no warning.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines_collectVariables__BUILTIN_FIND_FILES_VAR(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall,no-space")
	t.SetUpPackage("category/package")
	t.CreateFileLines("mk/buildlink3/bsd.builtin.mk",
		MkCvsID)
	mklines := t.SetUpFileMkLines("category/package/builtin.mk",
		MkCvsID,
		"",
		"BUILTIN_FIND_FILES_VAR:=        H_XFT2",
		"BUILTIN_FIND_FILES.H_XFT2=      ${X11BASE}/include/X11/Xft/Xft.h",
		"",
		".include \"../../mk/buildlink3/bsd.builtin.mk\"",
		"",
		".if ${H_XFT2:N__nonexistent__} && ${H_UNDEF:N__nonexistent__}",
		".endif")
	t.FinishSetUp()

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/category/package/builtin.mk:8: H_UNDEF is used but not defined.")
}

func (s *Suite) Test_MkLines_collectVariables__no_tracing(c *check.C) {
	t := s.Init(c)

	mklines := t.SetUpFileMkLines("filename.mk",
		MkCvsID,
		"",
		"BUILD_DEFS+=\tVAR1",
		"PLIST_VARS+=\tvar2",
		"SUBST_VARS.id+=\tVAR3")
	t.DisableTracing()

	mklines.collectVariables()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines_collectUsedVariables__simple(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		"\t${VAR}")
	mkline := mklines.mklines[0]

	mklines.collectUsedVariables()

	t.CheckDeepEquals(mklines.vars.used, map[string]*MkLine{"VAR": mkline})
	t.CheckEquals(mklines.vars.FirstUse("VAR"), mkline)
}

func (s *Suite) Test_MkLines_collectUsedVariables__nested(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"",
		"LHS.${lparam}=\tRHS.${rparam}",
		"",
		"target:",
		"\t${outer.${inner}}")
	assignMkline := mklines.mklines[2]
	shellMkline := mklines.mklines[5]

	mklines.collectUsedVariables()

	t.CheckEquals(len(mklines.vars.used), 5)
	t.CheckEquals(mklines.vars.FirstUse("lparam"), assignMkline)
	t.CheckEquals(mklines.vars.FirstUse("rparam"), assignMkline)
	t.CheckEquals(mklines.vars.FirstUse("inner"), shellMkline)
	t.CheckEquals(mklines.vars.FirstUse("outer.*"), shellMkline)
	t.CheckEquals(mklines.vars.FirstUse("outer.${inner}"), shellMkline)
}

func (s *Suite) Test_MkLines__private_tool_undefined(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"",
		"\tmd5sum filename")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:3: Unknown shell command \"md5sum\".")
}

// Tools that are defined by a package by adding to TOOLS_CREATE can
// be used without adding them to USE_TOOLS again.
func (s *Suite) Test_MkLines__private_tool_defined(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"TOOLS_CREATE+=\tmd5sum",
		"",
		"\tmd5sum filename")

	mklines.Check()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines_Check__indentation(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("options.mk",
		MkCvsID,
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
		MkCvsID,
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
		MkCvsID,
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
		MkCvsID,
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
		MkCvsID,
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
		MkCvsID,
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
		MkCvsID,
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
		"# PARAGRAPH",
		"#\tA paragraph may end in a",
		"#\tPARA_END_VARNAME.",
		"",
		"# VARBASE1.<param1>",
		"# VARBASE2.*",
		"# VARBASE3.${id}",
		"",
		"# NETBSD/amd64",
		"#\tThis is not a variable name.",
		"#\tThe slash must not appear in a variable name.",
		"",
		"# _____",
		"#\tThis is not a variable name.",
		"#\tVariable names must have at least one letter.")

	// The variables that appear in the documentation are marked as
	// both used and defined, to prevent the "defined but not used" warnings.
	mklines.collectDocumentedVariables()

	var varnames []string
	for varname, mkline := range mklines.vars.used {
		varnames = append(varnames, sprintf("%s (line %s)", varname, mkline.Linenos()))
	}
	sort.Strings(varnames)

	expected := []string{
		"PARAGRAPH (line 23)",
		"PKG_DEBUG_LEVEL (line 11)",
		"PKG_VERBOSE (line 16)",
		"VARBASE1.* (line 27)",
		"VARBASE2.* (line 28)",
		"VARBASE3.* (line 29)"}
	t.CheckDeepEquals(varnames, expected)
}

func (s *Suite) Test_MkLines__shell_command_indentation(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
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
		MkCvsID,
		"#",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.pkgbase",
		"PKG_SUPPORTED_OPTIONS=\tknown unknown",
		"PKG_SUGGESTED_OPTIONS=\tknown unknown")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: options.mk:4: Unknown option \"unknown\".")
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
		MkCvsID,
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
		MkCvsID,
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
		MkCvsID,
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
		MkCvsID,
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

	t.CheckEquals(mklines.mklines[2].HasElseBranch(), false)
	t.CheckEquals(mklines.mklines[5].HasElseBranch(), true)
	t.CheckEquals(mklines.mklines[9].HasElseBranch(), false)
}

func (s *Suite) Test_MkLines_Check__defined_and_used_variables(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wno-space")
	t.SetUpVartypes()

	mklines := t.NewMkLines("module.mk",
		MkCvsID,
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
		MkCvsID,
		"",
		"PKGNAME?=       pkgbase-1.0")

	mklines.Check()

	// No warning about including bsd.prefs.mk before using the ?= operator.
	// This is because the hacks.mk files are included implicitly by the
	// pkgsrc infrastructure right after bsd.prefs.mk.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLines_Check__MASTER_SITE_in_HOMEPAGE(c *check.C) {
	t := s.Init(c)

	t.SetUpMasterSite("MASTER_SITE_GITHUB", "https://github.com/")
	t.SetUpVartypes()
	mklines := t.NewMkLines("devel/catch/Makefile",
		MkCvsID,
		"HOMEPAGE=\t${MASTER_SITE_GITHUB:=philsquared/Catch/}",
		"HOMEPAGE=\t${MASTER_SITE_GITHUB}",
		"HOMEPAGE=\t${MASTER_SITES}",
		"HOMEPAGE=\t${MASTER_SITES}${GITHUB_PROJECT}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: devel/catch/Makefile:2: HOMEPAGE should not be defined in terms of MASTER_SITEs. "+
			"Use https://github.com/philsquared/Catch/ directly.",
		"WARN: devel/catch/Makefile:3: HOMEPAGE should not be defined in terms of MASTER_SITEs. "+
			"Use https://github.com/ directly.",
		"WARN: devel/catch/Makefile:4: HOMEPAGE should not be defined in terms of MASTER_SITEs.",
		"WARN: devel/catch/Makefile:5: HOMEPAGE should not be defined in terms of MASTER_SITEs.")
}

// Up to June 2019, pkglint wrongly replaced the HOMEPAGE
// with an empty string.
func (s *Suite) Test_MkLines_Check__autofix_MASTER_SITE_in_HOMEPAGE(c *check.C) {
	t := s.Init(c)

	test := func(diagnostics ...string) {
		mklines := t.NewMkLines("Makefile",
			MkCvsID,
			"",
			"MASTER_SITES= \\",
			"\thttps://cdn1.example.org/ \\",
			"\thttps://cdn2.example.org/",
			"",
			"HOMEPAGE=\t${MASTER_SITES}")

		mklines.Check()

		t.CheckOutput(diagnostics)
	}

	t.SetUpVartypes()

	t.SetUpCommandLine("-Wall")
	test(
		"WARN: Makefile:7: HOMEPAGE should not be defined in terms of MASTER_SITEs.")

	t.SetUpCommandLine("-Wall", "--autofix")
	test(
		nil...)

}

func (s *Suite) Test_MkLines_Check__autofix_MASTER_SITE_in_HOMEPAGE_in_package(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--autofix")
	t.SetUpPackage("category/package",
		"MASTER_SITES=\thttps://cdn1.example.org/ https://cdn2.example.org/",
		"HOMEPAGE=\t${MASTER_SITES}")

	t.Main("-Wall", "-q", "category/package")

	// When MASTER_SITES consists of several URLs, take the first one,
	// assuming that it is the most appropriate.
	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:9: " +
			"HOMEPAGE should not be defined in terms of MASTER_SITEs. " +
			"Use https://cdn1.example.org/ directly.")

	t.Main("-Wall", "-q", "--autofix", "category/package")

	t.CheckOutputLines(
		"AUTOFIX: ~/category/package/Makefile:9: " +
			"Replacing \"${MASTER_SITES}\" " +
			"with \"https://cdn1.example.org/\".")
}

func (s *Suite) Test_MkLines_Check__VERSION_as_word_part_in_MASTER_SITES(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpMasterSite("MASTER_SITE_SOURCEFORGE", "https://download.sf.net/")
	mklines := t.NewMkLines("geography/viking/Makefile",
		MkCvsID,
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
		MkCvsID,
		"CONFIGURE_ENV+=\tCC=${CC}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: x11/lablgtk1/Makefile:2: Please use ${CC:Q} instead of ${CC}.")
}

func (s *Suite) Test_MkLines_Check__extra_warnings(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wextra")
	t.SetUpVartypes()
	G.Pkg = NewPackage(t.File("category/pkgbase"))
	mklines := t.NewMkLines("options.mk",
		MkCvsID,
		"",
		".for word in ${PKG_FAIL_REASON}",
		"CONFIGURE_ARGS+=\t--sharedir=${PREFIX}/share/kde",
		"COMMENT=\t# defined",
		".endfor",
		"GAMES_USER?=pkggames",
		"GAMES_GROUP?=pkggames",
		"PLIST_SUBST+= CONDITIONAL=${CONDITIONAL}",
		"CONDITIONAL=\"@comment\"",
		"BUILD_DIRS=\t${WRKSRC}/../build")

	mklines.Check()

	t.CheckOutputLines(
		"NOTE: options.mk:5: Please use \"# empty\", \"# none\" or \"# yes\" instead of \"# defined\".",
		"WARN: options.mk:7: Please include \"../../mk/bsd.prefs.mk\" before using \"?=\".",
		"WARN: options.mk:11: Building the package should take place entirely inside ${WRKSRC}, not \"${WRKSRC}/..\".",
		"NOTE: options.mk:11: You can use \"../build\" instead of \"${WRKSRC}/../build\".")
}

func (s *Suite) Test_MkLines_SplitToParagraphs(c *check.C) {
	t := s.Init(c)

	type lineRange struct {
		from, to int
	}

	test := func(mklines *MkLines, ranges ...lineRange) {
		paras := mklines.SplitToParagraphs()

		var exp []*Paragraph
		for _, r := range ranges {
			exp = append(exp, NewParagraph(mklines, r.from, r.to))
		}

		t.CheckDeepEquals(paras, exp)
	}

	para := func(from, to int) lineRange { return lineRange{from, to} }

	test(
		t.NewMkLines("filename.mk",
			MkCvsID,
			"",
			"# paragraph 2",
			"#",
			"VAR=\tstill paragraph 2",
			"",
			"# paragraph 3",
			"#",
			"# paragraph 4"),
		para(0, 1),
		para(2, 5),
		para(6, 7),
		para(8, 9))

	test(
		t.NewMkLines("filename.mk",
			""),
		nil...)

	// Test coverage for i == 0.
	test(
		t.NewMkLines("filename.mk",
			"#"),
		nil...)

	// The empty comment line is not a paragraph separator. To be a
	// separator, it would have to be enclosed by comment lines.
	test(
		t.NewMkLines("filename.mk",
			"VAR=\tvalue",
			"#"),
		para(0, 2))

	// The empty comment line is not a paragraph separator because
	// below it there is no comment. This is a typical way of separating
	// a multi-line comment from a variable definition.
	test(
		t.NewMkLines("filename.mk",
			"# This comment spans",
			"# multiple lines.",
			"#",
			"VAR=\tvalue"),
		para(0, 4))
}

// Ensures that during MkLines.ForEach, the conditional variables in
// MkLines.Indentation are correctly updated for each line.
func (s *Suite) Test_MkLines_ForEach__conditional_variables(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall,no-space")
	t.SetUpVartypes()
	mklines := t.NewMkLines("conditional.mk",
		MkCvsID,
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

	mklines.ForEach(func(mkline *MkLine) {
		if mkline.IsVarassign() {
			switch mkline.Varname() {
			case "DEVELOPER":
				t.CheckEquals(mklines.indentation.IsConditional(), true)
				seenDeveloper = true
			case "USES_GETTEXT":
				t.CheckEquals(mklines.indentation.IsConditional(), true)
				seenUsesGettext = true
			}
		}
	})

	t.CheckEquals(seenDeveloper, true)
	t.CheckEquals(seenUsesGettext, true)
}

// At 2018-12-02, pkglint had resolved ${MY_PLIST_VARS} into a single word,
// whereas the correct behavior is to resolve it into two words.
// It had produced warnings about mismatched PLIST_VARS IDs.
func (s *Suite) Test_MkLines_checkVarassignPlist__indirect(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.SetUpFileMkLines("plist.mk",
		MkCvsID,
		"",
		"MY_PLIST_VARS=\tvar1 var2",
		"PLIST_VARS+=\t${MY_PLIST_VARS}",
		"",
		"PLIST.var1=\tyes",
		"PLIST.var2=\tyes")

	mklines.Check()

	t.CheckOutputEmpty()
}
