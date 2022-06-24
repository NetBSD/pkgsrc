package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_NewMkVarUseChecker(c *check.C) {
	t := s.Init(c)

	t.ExpectPanicMatches(
		func() { NewMkVarUseChecker(nil, nil, nil) },
		`runtime error: invalid memory address or nil pointer dereference`)
}

func (s *Suite) Test_MkVarUseChecker_Check(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"",
		"PKGNAME=\t${UNKNOWN}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:3: UNKNOWN is used but not defined.")
}

// The ${VARNAME:=suffix} expression should only be used with lists.
// It typically appears in MASTER_SITE definitions.
func (s *Suite) Test_MkVarUseChecker_Check__eq_nonlist(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpMasterSite("MASTER_SITE_GITHUB", "https://github.com/")
	mklines := t.SetUpFileMkLines("options.mk",
		MkCvsID,
		"WRKSRC=\t\t${WRKDIR:=/subdir}",
		"MASTER_SITES=\t${MASTER_SITE_GITHUB:=organization/}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/options.mk:2: The :from=to modifier should only be used with lists, not with WRKDIR.")
}

func (s *Suite) Test_MkVarUseChecker_Check__for(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpMasterSite("MASTER_SITE_GITHUB", "https://github.com/")
	mklines := t.SetUpFileMkLines("options.mk",
		MkCvsID,
		".for var in a b c",
		"\t: ${var}",
		".endfor")

	mklines.Check()

	t.CheckOutputEmpty()
}

// When a parameterized variable is defined in the pkgsrc infrastructure,
// it does not generate a warning about being "used but not defined".
// Even if the variable parameter differs, like .Linux and .SunOS in this
// case. This pattern is typical for pkgsrc, therefore pkglint doesn't
// check that the variable names match exactly.
func (s *Suite) Test_MkVarUseChecker_Check__varcanon(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/sys-vars.mk",
		MkCvsID,
		"CPPPATH.Linux=\t/usr/bin/cpp")
	t.FinishSetUp()

	mklines := t.NewMkLines("module.mk",
		MkCvsID,
		"COMMENT=\t${CPPPATH.SunOS}")
	ck := NewMkVarUseChecker(b.VarUse("CPPPATH.SunOS"), mklines, mklines.mklines[1])

	ck.Check(&VarUseContext{
		vartype: &Vartype{
			basicType:  BtPathname,
			options:    Guessed,
			aclEntries: nil,
		},
		time:       VucRunTime,
		quoting:    VucQuotPlain,
		IsWordPart: false,
	})

	t.CheckOutputEmpty()
}

// Any variable that is defined in the pkgsrc infrastructure in mk/**/*.mk is
// considered defined, and no "used but not defined" warning is logged for it.
//
// See Pkgsrc.loadUntypedVars.
func (s *Suite) Test_MkVarUseChecker_Check__defined_in_infrastructure(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/deeply/nested/infra.mk",
		MkCvsID,
		"INFRA_VAR?=\tvalue")
	t.FinishSetUp()
	mklines := t.SetUpFileMkLines("category/package/module.mk",
		MkCvsID,
		"do-fetch:",
		"\t: ${INFRA_VAR} ${UNDEFINED}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/category/package/module.mk:3: UNDEFINED is used but not defined.")
}

func (s *Suite) Test_MkVarUseChecker_Check__build_defs(c *check.C) {
	t := s.Init(c)

	// XXX: This paragraph should not be necessary since VARBASE and X11_TYPE
	//  are also defined in vardefs.go.
	t.SetUpPkgsrc()
	t.CreateFileLines("mk/defaults/mk.conf",
		"VARBASE?= /usr/pkg/var")
	t.FinishSetUp()

	mklines := t.SetUpFileMkLines("options.mk",
		MkCvsID,
		"COMMENT=\t\t${VARBASE} ${X11_TYPE}",
		"PKG_FAIL_REASON+=\t${VARBASE} ${X11_TYPE}",
		"BUILD_DEFS+=\t\tX11_TYPE")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/options.mk:2: The user-defined variable VARBASE is used but not added to BUILD_DEFS.",
		"WARN: ~/options.mk:3: PKG_FAIL_REASON should only get one item per line.")
}

// The LOCALBASE variable may be defined and used in the infrastructure.
// It is always equivalent to PREFIX and only exists for historic reasons.
func (s *Suite) Test_MkVarUseChecker_Check__LOCALBASE_in_infrastructure(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/infra.mk",
		MkCvsID,
		"LOCALBASE?=\t${PREFIX}",
		"DEFAULT_PREFIX=\t${LOCALBASE}")
	t.FinishSetUp()

	G.Check(t.File("mk/infra.mk"))

	// No warnings about LOCALBASE being used; the infrastructure files may
	// do this. In packages though, LOCALBASE is deprecated.

	// There is no warning about DEFAULT_PREFIX being "defined but not used"
	// since Pkgsrc.loadUntypedVars calls Pkgsrc.vartypes.DefineType, which
	// registers that variable globally.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkVarUseChecker_Check__user_defined_variable_and_BUILD_DEFS(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/defaults/mk.conf",
		"VARBASE?=\t${PREFIX}/var",
		"PYTHON_VER?=\t36")
	mklines := t.NewMkLines("file.mk",
		MkCvsID,
		"BUILD_DEFS+=\tPYTHON_VER",
		"\t: ${VARBASE}",
		"\t: ${VARBASE}",
		"\t: ${PYTHON_VER}")
	t.FinishSetUp()

	mklines.Check()

	t.CheckOutputLines(
		"WARN: file.mk:3: The user-defined variable VARBASE is used but not added to BUILD_DEFS.")
}

func (s *Suite) Test_MkVarUseChecker_Check__obsolete_PKG_DEBUG(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	G.Pkgsrc.initDeprecatedVars()

	mklines := t.NewMkLines("module.mk",
		MkCvsID,
		"\t${_PKG_SILENT}${_PKG_DEBUG} :")

	mklines.Check()

	t.CheckOutputLines(
		"ERROR: module.mk:2: Use of _PKG_SILENT and _PKG_DEBUG is obsolete. Use ${RUN} instead.")
}

func (s *Suite) Test_MkVarUseChecker_checkUndefined(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/infra.mk",
		MkCvsID,
		"#",
		"# User-settable variables:",
		"#",
		"# DOCUMENTED",
		"",
		"ASSIGNED=\tassigned",
		"#COMMENTED=\tcommented")
	t.FinishSetUp()

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"",
		"do-build:",
		"\t: ${ASSIGNED} ${COMMENTED} ${DOCUMENTED} ${UNKNOWN}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:4: UNKNOWN is used but not defined.")
}

// PR 46570, item "15. net/uucp/Makefile has a make loop"
func (s *Suite) Test_MkVarUseChecker_checkUndefined__indirect_variables(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("echo", "ECHO", AfterPrefsMk)
	mklines := t.NewMkLines("net/uucp/Makefile",
		MkCvsID,
		"\techo ${UUCP_${var}}")

	mklines.Check()

	// No warning about UUCP_${var} being used but not defined.
	//
	// Normally, parameterized variables use a dot instead of an underscore as separator.
	// This is one of the few other cases. Pkglint doesn't warn about dynamic variable
	// names like UUCP_${var} or SITES_${distfile}.
	//
	// It does warn about simple variable names though, like ${var} in this example.
	t.CheckOutputLines(
		"WARN: net/uucp/Makefile:2: var is used but not defined.")
}

// Documented variables are declared as both defined and used since, as
// of April 2019, pkglint doesn't yet interpret the "Package-settable
// variables" comment.
func (s *Suite) Test_MkVarUseChecker_checkUndefined__documented(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("interpreter.mk",
		MkCvsID,
		"#",
		"# Package-settable variables:",
		"#",
		"# REPLACE_INTERP",
		"#\tThe list of files whose interpreter will be corrected.",
		"",
		"REPLACE_INTERPRETER+=\tinterp",
		"REPLACE.interp.old=\t.*/interp",
		"REPLACE.interp.new=\t${PREFIX}/bin/interp",
		"REPLACE_FILES.interp=\t${REPLACE_INTERP}")

	mklines.Check()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkVarUseChecker_checkModifiers(c *check.C) {
	t := s.Init(c)

	test := func(text string, diagnostics ...string) {
		mklines := t.NewMkLines("filename.mk",
			text)
		mklines.ForEach(func(mkline *MkLine) {
			mkline.ForEachUsed(func(varUse *MkVarUse, time VucTime) {
				ck := NewMkVarUseChecker(varUse, mklines, mkline)
				ck.checkModifiers()
			})
		})
		t.CheckOutput(diagnostics)
	}

	test("\t${VAR}",
		nil...)

	test("\t${VAR:from=to:Q}",
		"WARN: filename.mk:1: The text \":Q\" looks like a modifier but isn't.")
}

func (s *Suite) Test_MkVarUseChecker_checkModifiersSuffix(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("file.mk",
		MkCvsID,
		"\t: ${HOMEPAGE:=subdir/:Q}", // wrong
		"\t: ${BUILD_DIRS:=subdir/}", // correct
		"\t: ${BIN_PROGRAMS:=.exe}")  // unknown since BIN_PROGRAMS doesn't have a type

	mklines.Check()

	t.CheckOutputLines(
		"WARN: file.mk:2: The text \":Q\" looks like a modifier but isn't.",
		"WARN: file.mk:2: The text \":Q\" looks like a modifier but isn't.",
		"WARN: file.mk:2: The :from=to modifier should only be used with lists, not with HOMEPAGE.",
		"WARN: file.mk:2: The text \":Q\" looks like a modifier but isn't.",
		"WARN: file.mk:4: BIN_PROGRAMS is used but not defined.")
}

func (s *Suite) Test_MkVarUseChecker_checkModifiersRange(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--show-autofix", "--source")
	t.SetUpVartypes()
	mklines := t.NewMkLines("mk/compiler/gcc.mk",
		MkCvsID,
		"CC:=\t${CC:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}")

	mklines.Check()

	t.CheckOutputLines(
		"NOTE: mk/compiler/gcc.mk:2: "+
			"The modifier \":C/^/_asdf_/1:M_asdf_*:S/^_asdf_//\" can be written as \":[1]\".",
		"AUTOFIX: mk/compiler/gcc.mk:2: "+
			"Replacing \":C/^/_asdf_/1:M_asdf_*:S/^_asdf_//\" with \":[1]\".",
		"-\tCC:=\t${CC:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}",
		"+\tCC:=\t${CC:[1]}")

	// Now go through all the "almost" cases, to reach full branch coverage.
	mklines = t.NewMkLines("gcc.mk",
		MkCvsID,
		"\t: ${CC:M1:M2:M3}",
		"\t: ${CC:C/^begin//:M2:M3}",                    // M1 pattern not exactly ^
		"\t: ${CC:C/^/_asdf_/g:M2:M3}",                  // M1 options != "1"
		"\t: ${CC:C/^/....../g:M2:M3}",                  // M1 replacement doesn't match \w+
		"\t: ${CC:C/^/_asdf_/1:O:M3}",                   // M2 is not a match modifier
		"\t: ${CC:C/^/_asdf_/1:N2:M3}",                  // M2 is :N instead of :M
		"\t: ${CC:C/^/_asdf_/1:M_asdf_:M3}",             // M2 pattern is missing the * at the end
		"\t: ${CC:C/^/_asdf_/1:Mother:M3}",              // M2 pattern differs from the M1 pattern
		"\t: ${CC:C/^/_asdf_/1:M_asdf_*:M3}",            // M3 ist not a substitution modifier
		"\t: ${CC:C/^/_asdf_/1:M_asdf_*:S,from,to,}",    // M3 pattern differs from the M1 pattern
		"\t: ${CC:C/^/_asdf_/1:M_asdf_*:S,^_asdf_,to,}", // M3 replacement is not empty
		"\t: ${CC:C/^/_asdf_/1:M_asdf_*:S,^_asdf_,,g}")  // M3 modifier has options

	mklines.Check()
}

func (s *Suite) Test_MkVarUseChecker_checkModifierLoop(c *check.C) {
	t := s.Init(c)

	autofixTest := func(before, after string, autofix bool) {
		mklines := t.NewMkLines("filename.mk",
			MkCvsID,
			"VAR=\t"+before)
		mklines.ForEach(func(mkline *MkLine) {
			mkline.ForEachUsed(func(varUse *MkVarUse, time VucTime) {
				ck := NewMkVarUseChecker(varUse, nil, mkline)
				ck.checkModifiers()
			})
		})
		if autofix {
			t.CheckEquals(mklines.mklines[1].Text, "VAR=\t"+after)
		}
	}

	test := func(before, after string, diagnostics ...string) {
		t.ExpectDiagnosticsAutofix(
			func(autofix bool) { autofixTest(before, after, autofix) },
			diagnostics...)
	}

	test("${VAR:@l@-l${l}@}", "${VAR:S,^,-l,}",
		"NOTE: filename.mk:2: The modifier \"@l@-l${l}@\" "+
			"can be replaced with the simpler \"S,^,-l,\".",
		"AUTOFIX: filename.mk:2: Replacing \"@l@-l${l}@\" with \"S,^,-l,\".")

	// The comma is used in the :S modifier as the separator,
	// therefore the modifier is left as-is.
	test("${VAR:@word@-Wl,${word}@}", "${VAR:@word@-Wl,${word}@}",
		nil...)

	test("${VAR:@l@${l}suffix@}", "${VAR:=suffix}",
		"NOTE: filename.mk:2: The modifier \"@l@${l}suffix@\" "+
			"can be replaced with the simpler \"=suffix\".",
		"AUTOFIX: filename.mk:2: Replacing \"@l@${l}suffix@\" with \"=suffix\".")

	// Escaping the colon is not yet supported.
	test("${VAR:@word@${word}: suffix@}", "${VAR:@word@${word}: suffix@}",
		nil...)

	// The loop variable must be mentioned exactly once.
	test("${VAR:@var@${var}${var}@}", "${VAR:@var@${var}${var}@}",
		nil...)

	// Other variables are fine though.
	test("${VAR:@var@${var}${OTHER}@}", "${VAR:=${OTHER}}",
		"NOTE: filename.mk:2: The modifier \"@var@${var}${OTHER}@\" "+
			"can be replaced with the simpler \"=${OTHER}\".",
		"AUTOFIX: filename.mk:2: Replacing \"@var@${var}${OTHER}@\" with \"=${OTHER}\".")

	// If the loop variable has modifiers, the :@var@ is probably appropriate.
	test("${VAR:@var@${var:Q}@}", "${VAR:@var@${var:Q}@}",
		nil...)

	test("${VAR:@p@${p}) continue;; @}", "${VAR:=) continue;; }",
		"NOTE: filename.mk:2: The modifier \"@p@${p}) continue;; @\" "+
			"can be replaced with the simpler \"=) continue;; \".",
		"AUTOFIX: filename.mk:2: Replacing \"@p@${p}) continue;; @\" with \"=) continue;; \".")
}

func (s *Suite) Test_MkVarUseChecker_checkVarname(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		"\t: $@",
		".if ${LOCALBASE} == /usr/pkg", // Use at load time
		"\t: ${LOCALBASE}",             // Use at run time
		".endif")

	doTest := func(autofix bool) {
		mklines.ForEach(func(mkline *MkLine) {
			mkline.ForEachUsed(func(varUse *MkVarUse, time VucTime) {
				ck := NewMkVarUseChecker(varUse, mklines, mkline)
				ck.checkVarname(time)
			})
		})
	}

	t.ExpectDiagnosticsAutofix(
		doTest,
		"WARN: filename.mk:1: Please use \"${.TARGET}\" instead of \"$@\".",
		"WARN: filename.mk:3: Please use PREFIX instead of LOCALBASE.",
		"AUTOFIX: filename.mk:3: Replacing \"LOCALBASE\" with \"PREFIX\".")
}

func (s *Suite) Test_MkVarUseChecker_checkVarnameBuildlink(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("option", "Description.")
	t.CreateFileLines("mk/bsd.options.mk")
	t.SetUpPackage("category/library")
	t.CreateFileBuildlink3Id("category/library/buildlink3.mk", "lib")
	t.SetUpPackage("category/package",
		"CONFIGURE_ARGS+=\t--with-library=${BUILDLINK_PREFIX.library}",
		"CONFIGURE_ARGS+=\t--with-lib=${BUILDLINK_PREFIX.lib}",
		"CONFIGURE_ARGS+=\t--with-package=${BUILDLINK_PREFIX.package}",
		"CONFIGURE_ARGS+=\t--with-package=${BUILDLINK_PREFIX.${PKGBASE}}",
		"",
		".include \"../../category/library/buildlink3.mk\"")
	t.CreateFileLines("category/package/options.mk",
		MkCvsID,
		"",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.package",
		"PKG_SUPPORTED_OPTIONS=\toption",
		".include \"../../mk/bsd.options.mk\"",
		".if ${PKG_OPTIONS:Moption}",
		"CONFIGURE_ARGS+=\t--with-option=${BUILDLINK_PREFIX.package}",
		".endif")
	t.CreateFileBuildlink3("category/package/buildlink3.mk",
		"BL3=\t${BUILDLINK_PREFIX.unknown-bl3}",
		"BL3+=\t${BUILDLINK_PREFIX.package}")
	t.CreateFileLines("category/package/builtin.mk",
		MkCvsID,
		"BUILTIN=\t${BUILDLINK_PREFIX.unknown-builtin}",
		"BUILTIN+=\t${BUILDLINK_PREFIX.package}")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"WARN: Makefile:20: Buildlink identifier \"library\" is not known in this package.",
		"WARN: Makefile:22: Buildlink identifier \"package\" is not known in this package.",
		"WARN: buildlink3.mk:12: BL3 is defined but not used.",
		"WARN: buildlink3.mk:12: Buildlink identifier \"unknown-bl3\" is not known in this package.",
		"WARN: builtin.mk:2: BUILTIN is defined but not used.",
		"WARN: builtin.mk:2: Buildlink identifier \"unknown-builtin\" is not known in this package.",
		"WARN: options.mk:7: Buildlink identifier \"package\" is not known in this package.")
}

func (s *Suite) Test_MkVarUseChecker_checkVarnameBuildlink__no_buildlink3_file(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/module.mk",
		MkCvsID,
		"CONFIGURE_ARGS+=\t--prefix=${BUILDLINK_PREFIX.package}")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"WARN: module.mk:2: Buildlink identifier \"package\" is not known in this package.")
}

func (s *Suite) Test_MkVarUseChecker_checkVarnameBuildlink__no_buildlink3_data(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/module.mk",
		MkCvsID,
		"CONFIGURE_ARGS+=\t--prefix=${BUILDLINK_PREFIX.package}")
	t.CreateFileLines("category/package/buildlink3.mk",
		MkCvsID,
		"# Empty, for whatever reason.  This doesn't happen in practice.")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"NOTE: buildlink3.mk:2: Empty line expected below this line.",
		"WARN: buildlink3.mk:EOF: Expected a BUILDLINK_TREE line.",
		"WARN: module.mk:2: Buildlink identifier \"package\" is not known in this package.")
}

func (s *Suite) Test_MkVarUseChecker_checkVarnameBuildlink__curses_ok(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("mk/curses.buildlink3.mk")
	t.CreateFileLines("category/package/module.mk",
		MkCvsID,
		"CONFIGURE_ARGS+=\t--prefix=${BUILDLINK_PREFIX.curses}",
		".include \"../../mk/curses.buildlink3.mk\"")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkVarUseChecker_checkVarnameBuildlink__curses_bad(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("mk/curses.buildlink3.mk")
	t.CreateFileLines("category/package/module.mk",
		MkCvsID,
		"CONFIGURE_ARGS+=\t--prefix=${BUILDLINK_PREFIX.curses}",
		// does not include mk/curses.buildlink3.mk
	)
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"WARN: module.mk:2: Buildlink identifier \"curses\" is not known in this package.")
}

func (s *Suite) Test_MkVarUseChecker_checkVarnameBuildlink__mysql_ok(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("mk/mysql.buildlink3.mk")
	t.CreateFileLines("category/package/module.mk",
		MkCvsID,
		"CONFIGURE_ARGS+=\t--prefix=${BUILDLINK_PREFIX.mysql-client}",
		".include \"../../mk/mysql.buildlink3.mk\"")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkVarUseChecker_checkVarnameBuildlink__mysql_bad(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("mk/mysql.buildlink3.mk")
	t.CreateFileLines("category/package/module.mk",
		MkCvsID,
		"CONFIGURE_ARGS+=\t--prefix=${BUILDLINK_PREFIX.mysql-client}")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"WARN: module.mk:2: Buildlink identifier \"mysql-client\" is not known in this package.")
}

func (s *Suite) Test_MkVarUseChecker_checkPermissions(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("options.mk",
		MkCvsID,
		"COMMENT=\t${GAMES_USER}",
		"COMMENT:=\t${PKGBASE}",
		"PYPKGPREFIX=\t${PKGBASE}")
	G.Pkgsrc.loadDefaultBuildDefs()
	G.Pkgsrc.UserDefinedVars.Define("GAMES_USER", mklines.mklines[0])

	mklines.Check()

	t.CheckOutputLines(
		"WARN: options.mk:3: PKGBASE should not be used at load time in any file.",
		"WARN: options.mk:4: The variable PYPKGPREFIX should not be set in this file; "+
			"it would be ok in pyversion.mk only.")
}

func (s *Suite) Test_MkVarUseChecker_checkPermissions__explain(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	t.SetUpVartypes()
	mklines := t.NewMkLines("options.mk",
		MkCvsID,
		"COMMENT=\t${GAMES_USER}",
		"COMMENT:=\t${PKGBASE}",
		"PYPKGPREFIX=\t${PKGBASE}")
	G.Pkgsrc.loadDefaultBuildDefs()
	G.Pkgsrc.UserDefinedVars.Define("GAMES_USER", mklines.mklines[0])

	mklines.Check()

	t.CheckOutputLines(
		"WARN: options.mk:3: PKGBASE should not be used at load time in any file.",
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
		"\tname in which the variable is used or defined. The rules for PKGBASE",
		"\tare:",
		"",
		"\t* in buildlink3.mk, it should not be accessed at all",
		"\t* in any file, it may be used",
		"",
		"\tIf these rules seem to be incorrect, please ask on the",
		"\ttech-pkg@NetBSD.org mailing list.",
		"",
		"WARN: options.mk:4: The variable PYPKGPREFIX should not be set in this file; "+
			"it would be ok in pyversion.mk only.",
		"",
		"\tThe allowed actions for a variable are determined based on the file",
		"\tname in which the variable is used or defined. The rules for",
		"\tPYPKGPREFIX are:",
		"",
		"\t* in pyversion.mk, it may be set",
		"\t* in any file, it may be used at load time, or used",
		"",
		"\tIf these rules seem to be incorrect, please ask on the",
		"\ttech-pkg@NetBSD.org mailing list.", "")
}

func (s *Suite) Test_MkVarUseChecker_checkPermissions__load_time_in_condition(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.SetUpVarType("LOAD_TIME", BtPathPattern, List,
		"special:filename.mk: use-loadtime")
	t.SetUpVarType("RUN_TIME", BtPathPattern, List,
		"special:filename.mk: use")
	t.Chdir(".")
	t.FinishSetUp()

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		".if ${LOAD_TIME} && ${RUN_TIME}",
		".endif")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:2: To use LOAD_TIME at load time, "+
			".include \"mk/bsd.prefs.mk\" first.",
		"WARN: filename.mk:2: RUN_TIME should not be used at load time in any file.")
}

func (s *Suite) Test_MkVarUseChecker_checkPermissions__load_time_in_for_loop(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.SetUpVarType("LOAD_TIME", BtPathPattern, List,
		"special:filename.mk: use-loadtime")
	t.SetUpVarType("RUN_TIME", BtPathPattern, List,
		"special:filename.mk: use")
	t.Chdir(".")
	t.FinishSetUp()

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		".for pattern in ${LOAD_TIME} ${RUN_TIME}",
		".endfor")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:2: To use LOAD_TIME at load time, "+
			".include \"mk/bsd.prefs.mk\" first.",
		"WARN: filename.mk:2: RUN_TIME should not be used at load time in any file.")
}

func (s *Suite) Test_MkVarUseChecker_checkPermissions__load_time_guessed(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("install", "", AtRunTime)
	mklines := t.NewMkLines("install-docfiles.mk",
		MkCvsID,
		"DOCFILES=\ta b c",
		"do-install:",
		".for f in ${DOCFILES}",
		"\tinstall -c ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${f}",
		".endfor")

	mklines.Check()

	// No warning for using DOCFILES at compile-time. Since the variable
	// name is not one of the predefined names from vardefs.go, the
	// variable's type is guessed based on the name (see
	// Pkgsrc.VariableType).
	//
	// These guessed variables are typically defined and used only in
	// a single file, and in this context, mistakes are usually found
	// quickly.
	t.CheckOutputEmpty()
}

// Ensures that the warning "should not be evaluated at load time" is issued
// only if using the variable at run time is allowed. If the latter were not
// allowed, this warning would be confusing.
func (s *Suite) Test_MkVarUseChecker_checkPermissions__load_time_run_time(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.SetUpVarType("LOAD_TIME", BtUnknown, NoVartypeOptions,
		"*.mk: use, use-loadtime")
	t.SetUpVarType("RUN_TIME", BtUnknown, NoVartypeOptions,
		"*.mk: use")
	t.SetUpVarType("WRITE_ONLY", BtUnknown, NoVartypeOptions,
		"*.mk: set")
	t.SetUpVarType("LOAD_TIME_ELSEWHERE", BtUnknown, NoVartypeOptions,
		"Makefile: use-loadtime",
		"*.mk: set")
	t.SetUpVarType("RUN_TIME_ELSEWHERE", BtUnknown, NoVartypeOptions,
		"Makefile: use",
		"*.mk: set")
	t.Chdir(".")
	t.FinishSetUp()

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		".if ${LOAD_TIME} && ${RUN_TIME} && ${WRITE_ONLY}",
		".elif ${LOAD_TIME_ELSEWHERE} && ${RUN_TIME_ELSEWHERE}",
		".endif")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:2: To use LOAD_TIME at load time, "+
			".include \"mk/bsd.prefs.mk\" first.",
		"WARN: filename.mk:2: RUN_TIME should not be used at load time in any file.",
		"WARN: filename.mk:2: "+
			"WRITE_ONLY should not be used in any file; "+
			"it is a write-only variable.",
		"WARN: filename.mk:3: "+
			"LOAD_TIME_ELSEWHERE should not be used at load time in this file; "+
			"it would be ok in Makefile, but not *.mk.",
		"WARN: filename.mk:3: "+
			"RUN_TIME_ELSEWHERE should not be used at load time in any file.")
}

func (s *Suite) Test_MkVarUseChecker_checkPermissions__PKGREVISION(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("any.mk",
		MkCvsID,
		".if defined(PKGREVISION)",
		".endif")

	mklines.Check()

	// Since PKGREVISION may only be set in the package Makefile directly,
	// there is no other file that could be mentioned as "it would be ok in".
	t.CheckOutputLines(
		"WARN: any.mk:2: PKGREVISION should not be used in any file; it is a write-only variable.")
}

func (s *Suite) Test_MkVarUseChecker_checkPermissions__indirectly(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("file.mk",
		MkCvsID,
		"IGNORE_PKG.package=\t${NOT_FOR_UNPRIVILEGED}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: file.mk:2: IGNORE_PKG.package should be set to YES or yes.",
		"WARN: file.mk:2: NOT_FOR_UNPRIVILEGED should not be used indirectly at load time (via IGNORE_PKG.package).")
}

// This test is only here for branch coverage.
// It does not demonstrate anything useful.
func (s *Suite) Test_MkVarUseChecker_checkPermissions__indirectly_tool(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("file.mk",
		MkCvsID,
		"USE_TOOLS+=\t${PKGREVISION}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: file.mk:2: PKGREVISION should not be used in any file; it is a write-only variable.")
}

func (s *Suite) Test_MkVarUseChecker_checkPermissions__write_only_usable_in_other_file(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkCvsID,
		"VAR=\t${VAR} ${AUTO_MKDIRS}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: buildlink3.mk:2: " +
			"AUTO_MKDIRS should not be used in this file; " +
			"it would be ok in Makefile, Makefile.* or *.mk, " +
			"but not buildlink3.mk or builtin.mk.")
}

func (s *Suite) Test_MkVarUseChecker_checkPermissions__usable_only_at_loadtime_in_other_file(c *check.C) {
	t := s.Init(c)

	t.SetUpVarType("VAR", BtFilename, NoVartypeOptions,
		"*: set, use-loadtime")
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"VAR=\t${VAR}")

	mklines.Check()

	// Since the variable is usable at load time, pkglint assumes it is also
	// usable at run time. This is not the case for VAR, but probably doesn't
	// happen in practice anyway.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkVarUseChecker_checkPermissions__assigned_to_infrastructure_variable(c *check.C) {
	t := s.Init(c)

	// This combination of BtUnknown and all permissions is typical for
	// otherwise unknown variables from the pkgsrc infrastructure.
	t.SetUpVarType("INFRA", BtUnknown, NoVartypeOptions)
	t.SetUpVarType("VAR", BtUnknown, NoVartypeOptions,
		"buildlink3.mk: none",
		"*: use")
	mklines := t.NewMkLines("buildlink3.mk",
		MkCvsID,
		"INFRA=\t${VAR}")

	mklines.Check()

	// Since INFRA is defined in the infrastructure and pkglint
	// knows nothing else about this variable, it assumes that INFRA
	// may be used at load time. This is done to prevent wrong warnings.
	//
	// This in turn has consequences when INFRA is used on the left-hand
	// side of an assignment since pkglint assumes that the right-hand
	// side may now be evaluated at load time.
	//
	// Therefore the check is skipped when such a variable appears at the
	// left-hand side of an assignment.
	//
	// Even in this case involving an unknown infrastructure variable,
	// it is possible to issue a warning since VAR should not be used at all,
	// independent of any properties of INFRA.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkVarUseChecker_checkPermissions__assigned_to_load_time(c *check.C) {
	t := s.Init(c)

	// LOAD_TIME may be used at load time in other.mk.
	// Since VAR must not be used at load time at all, it would be dangerous
	// to use its value in LOAD_TIME, as the latter might be evaluated later
	// at load time, and at that point VAR would be evaluated as well.

	t.SetUpVarType("LOAD_TIME", BtMessage, NoVartypeOptions,
		"buildlink3.mk: set",
		"*.mk: use-loadtime")
	t.SetUpVarType("VAR", BtUnknown, NoVartypeOptions,
		"buildlink3.mk: none",
		"*.mk: use")
	mklines := t.NewMkLines("buildlink3.mk",
		MkCvsID,
		"LOAD_TIME=\t${VAR}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: buildlink3.mk:2: VAR should not be used indirectly " +
			"at load time (via LOAD_TIME).")
}

func (s *Suite) Test_MkVarUseChecker_checkPermissions__multiple_times_per_file(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkCvsID,
		"VAR=\t${VAR} ${AUTO_MKDIRS} ${AUTO_MKDIRS} ${PKGREVISION} ${PKGREVISION}",
		"VAR=\t${VAR} ${AUTO_MKDIRS} ${AUTO_MKDIRS} ${PKGREVISION} ${PKGREVISION}")

	mklines.Check()

	// Since these warnings are valid for the whole file, duplicates are suppressed.
	t.CheckOutputLines(
		"WARN: buildlink3.mk:2: "+
			"AUTO_MKDIRS should not be used in this file; "+
			"it would be ok in Makefile, Makefile.* or *.mk, "+
			"but not buildlink3.mk or builtin.mk.",
		"WARN: buildlink3.mk:2: "+
			"PKGREVISION should not be used in any file; "+
			"it is a write-only variable.")
}

func (s *Suite) Test_MkVarUseChecker_warnPermissions__not_directly_and_no_alternative_files(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("mk-c.mk",
		MkCvsID,
		"",
		"# GUESSED_FLAGS",
		"#\tDocumented here to suppress the \"defined but not used\"",
		"#\twarning.",
		"",
		"TOOL_DEPENDS+=\t${BUILDLINK_API_DEPENDS.mk-c}:${BUILDLINK_PKGSRCDIR.mk-c}",
		"GUESSED_FLAGS+=\t${BUILDLINK_CPPFLAGS}")

	mklines.Check()

	toolDependsType := G.Pkgsrc.VariableType(nil, "TOOL_DEPENDS")
	t.CheckEquals(toolDependsType.String(), "DependencyWithPath (list, package-settable)")
	t.CheckEquals(toolDependsType.AlternativeFiles(aclpAppend), "Makefile, Makefile.* or *.mk")
	t.CheckEquals(toolDependsType.AlternativeFiles(aclpUse), "Makefile, Makefile.* or *.mk")
	t.CheckEquals(toolDependsType.AlternativeFiles(aclpUseLoadtime), "")

	apiDependsType := G.Pkgsrc.VariableType(nil, "BUILDLINK_API_DEPENDS.*")
	t.CheckEquals(apiDependsType.String(), "DependencyPattern (list, package-settable)")
	t.CheckEquals(apiDependsType.AlternativeFiles(aclpUse), "")
	t.CheckEquals(apiDependsType.AlternativeFiles(aclpUseLoadtime), "buildlink3.mk or builtin.mk only")

	t.CheckOutputLines(
		"WARN: mk-c.mk:7: BUILDLINK_API_DEPENDS.mk-c should not be used in any file.",
		"WARN: mk-c.mk:7: The list variable BUILDLINK_API_DEPENDS.mk-c should not be embedded in a word.",
		"WARN: mk-c.mk:7: BUILDLINK_PKGSRCDIR.mk-c should not be used in any file.")
}

func (s *Suite) Test_MkVarUseChecker_explainPermissions(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	t.SetUpVartypes()

	mklines := t.NewMkLines("buildlink3.mk",
		MkCvsID,
		"AUTO_MKDIRS=\tyes")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: buildlink3.mk:2: The variable AUTO_MKDIRS should not be set in this file; "+
			"it would be ok in Makefile, Makefile.* or *.mk, "+
			"but not buildlink3.mk or builtin.mk.",
		"",
		"\tThe allowed actions for a variable are determined based on the file",
		"\tname in which the variable is used or defined. The rules for",
		"\tAUTO_MKDIRS are:",
		"",
		"\t* in buildlink3.mk, it should not be accessed at all",
		"\t* in builtin.mk, it should not be accessed at all",
		"\t* in Makefile, it may be set, given a default value, or used",
		"\t* in Makefile.*, it may be set, given a default value, or used",
		"\t* in *.mk, it may be set, given a default value, or used",
		// TODO: Add a check for infrastructure permissions
		//  when the "infra:" prefix is added.
		"",
		"\tIf these rules seem to be incorrect, please ask on the",
		"\ttech-pkg@NetBSD.org mailing list.",
		"")
}

func (s *Suite) Test_MkVarUseChecker_checkUseAtLoadTime__buildlink3_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileBuildlink3("category/package/buildlink3.mk",
		".if ${OPSYS} == NetBSD",
		".endif")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check("buildlink3.mk")

	t.CheckOutputLines(
		"WARN: buildlink3.mk:12: To use OPSYS at load time, " +
			".include \"../../mk/bsd.fast.prefs.mk\" first.")
}

func (s *Suite) Test_MkVarUseChecker_checkUseAtLoadTime__pkg_build_options_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("option", "An example option")
	t.CreateFileLines("mk/pkg-build-options.mk",
		MkCvsID)
	t.SetUpPackage("category/package")

	t.CreateFileBuildlink3("category/package/buildlink3.mk",
		"pkgbase := package",
		".include \"../../mk/pkg-build-options.mk\"",
		".if ${PKG_BUILD_OPTIONS.package:Moption}",
		".endif")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check("buildlink3.mk")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkVarUseChecker_checkUseAtLoadTime__other_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/filename.mk",
		MkCvsID,
		".if ${OPSYS} == NetBSD",
		".endif")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check("filename.mk")

	t.CheckOutputLines(
		"WARN: filename.mk:2: To use OPSYS at load time, " +
			".include \"../../mk/bsd.prefs.mk\" first.")
}

func (s *Suite) Test_MkVarUseChecker_checkUseAtLoadTime__PKG_SYSCONFDIR(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.Chdir("category/package")
	mklines := t.NewMkLines("options.mk",
		MkCvsID,
		".if ${PKG_SYSCONFDIR.gdm} != \"etc\"",
		".endif")

	mklines.Check()

	// The PKG_SYSCONFDIR.* directories typically start with ${PREFIX}.
	// Since PREFIX is not defined until bsd.pkg.mk, including bsd.prefs.mk
	// wouldn't help, therefore pkglint doesn't suggest it.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkVarUseChecker_checkUseAtLoadTime__package_settable(c *check.C) {
	t := s.Init(c)

	btAnything := &BasicType{"Anything", func(cv *VartypeCheck) {}}
	t.SetUpVarType("PKG", btAnything, PackageSettable)
	t.Chdir("category/package")

	test := func(filename CurrPath, diagnostics ...string) {
		mklines := t.NewMkLines(filename,
			MkCvsID,
			".if ${PKG} != \"etc\"",
			".endif")

		mklines.Check()

		t.CheckOutput(diagnostics)
	}

	test("Makefile",
		nil...)

	test("options.mk",
		nil...)

	test("other.mk",
		nil...)
}

func (s *Suite) Test_MkVarUseChecker_warnToolLoadTime(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("nowhere", "NOWHERE", Nowhere)
	t.SetUpTool("after-prefs", "AFTER_PREFS", AfterPrefsMk)
	t.SetUpTool("at-runtime", "AT_RUNTIME", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		".if ${NOWHERE} && ${AFTER_PREFS} && ${AT_RUNTIME} && ${MK_TOOL}",
		".endif",
		"",
		"TOOLS_CREATE+=\t\tmk-tool",
		"_TOOLS_VARNAME.mk-tool=\tMK_TOOL")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:2: To use the tool ${NOWHERE} at load time, "+
			"it has to be added to USE_TOOLS before including bsd.prefs.mk.",
		"WARN: Makefile:2: To use the tool ${AFTER_PREFS} at load time, "+
			"bsd.prefs.mk has to be included before.",
		"WARN: Makefile:2: The tool ${AT_RUNTIME} cannot be used at load time.",
		"WARN: Makefile:2: To use the tool ${MK_TOOL} at load time, "+
			"bsd.prefs.mk has to be included before.",
		"WARN: Makefile:6: Variable names starting with an underscore "+
			"(_TOOLS_VARNAME.mk-tool) are reserved for internal pkgsrc use.",
		"WARN: Makefile:6: _TOOLS_VARNAME.mk-tool is defined but not used.")
}

// This somewhat unrealistic case demonstrates how there can be a tool in a
// Makefile that is not known to the global pkgsrc.
//
// This test covers the "pkgsrcTool != nil" condition.
func (s *Suite) Test_MkVarUseChecker_warnToolLoadTime__local_tool(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.CreateFileLines("mk/bsd.prefs.mk")
	mklines := t.SetUpFileMkLines("category/package/Makefile",
		MkCvsID,
		".include \"../../mk/bsd.prefs.mk\"",
		"",
		"TOOLS_CREATE+=\t\tmk-tool",
		"_TOOLS_VARNAME.mk-tool=\tMK_TOOL",
		"",
		"TOOL_OUTPUT!=\t${MK_TOOL}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:5: Variable names starting with an underscore (_TOOLS_VARNAME.mk-tool) are reserved for internal pkgsrc use.",
		"WARN: ~/category/package/Makefile:5: _TOOLS_VARNAME.mk-tool is defined but not used.",
		"WARN: ~/category/package/Makefile:7: TOOL_OUTPUT is defined but not used.",
		"WARN: ~/category/package/Makefile:7: The tool ${MK_TOOL} cannot be used at load time.")
}

func (s *Suite) Test_MkVarUseChecker_checkAssignable(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("filename.mk",
		"BUILTIN_FIND_FILES_VAR:=\tBIN_FILE",
		"BUILTIN_FIND_FILES.BIN_FILE=\t${TOOLS_PLATFORM.file} /bin/file /usr/bin/file",
		"PKG_SHELL.user=\t${TOOLS_PLATFORM.false:Q}")

	mklines.ForEach(func(mkline *MkLine) {
		ck := NewMkAssignChecker(mkline, mklines)
		ck.checkRight()
	})

	t.CheckOutputLines(
		"WARN: filename.mk:2: Incompatible types: "+
			"TOOLS_PLATFORM.file (type \"ShellCommand\") "+
			"cannot be assigned to type \"Pathname\".",
		"WARN: filename.mk:3: Incompatible types: "+
			"TOOLS_PLATFORM.false (type \"ShellCommand\") "+
			"cannot be assigned to type \"Pathname\".")
}

// NetBSD's chsh program only allows a simple pathname for the shell, without
// any command line arguments. This makes sense since the shell is started
// using execve, not system (which would require shell-like argument parsing).
//
// Under the assumption that TOOLS_PLATFORM.sh does not contain any command
// line arguments, it's ok in that special case. This covers most of the
// real-life situations where this type mismatch (Pathname := ShellCommand)
// occurs.
func (s *Suite) Test_MkVarUseChecker_checkAssignable__shell_command_to_pathname(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("sh", "SH", AtRunTime)
	t.SetUpTool("bash", "BASH", AtRunTime)
	mklines := t.NewMkLines("filename.mk",
		"PKG_SHELL.user=\t${TOOLS_PLATFORM.sh}",
		"PKG_SHELL.user=\t${SH}",
		"PKG_SHELL.user=\t${BASH}",
		"PKG_SHELL.user=\t/bin/sh")

	mklines.ForEach(func(mkline *MkLine) {
		ck := NewMkAssignChecker(mkline, mklines)
		ck.checkRight()
	})

	t.CheckOutputLines(
		"WARN: filename.mk:1: Please use ${TOOLS_PLATFORM.sh:Q} " +
			"instead of ${TOOLS_PLATFORM.sh}.")
}

func (s *Suite) Test_MkVarUseChecker_checkAssignable__shell_command_in_exists(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("sh", "SH", AfterPrefsMk)
	t.SetUpTool("bash", "BASH", AfterPrefsMk)
	t.SetUpPkgsrc()
	t.Chdir(".")
	t.FinishSetUp()
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		".include \"mk/bsd.prefs.mk\"",
		".if exists(${TOOLS_PLATFORM.sh})",
		".elif exists(${SH})",
		".elif exists(${BASH})",
		".endif")

	mklines.Check()

	// TODO: Call MkVarUseChecker.checkAssignable with a VarUseContext of type
	//  BtPathname here.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkVarUseChecker_checkQuoting(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.SetUpFileMkLines("options.mk",
		MkCvsID,
		"GOPATH=\t${WRKDIR}",
		"",
		"CONFIGURE_ENV+=\tNAME=${R_PKGNAME} VER=${R_PKGVER}",
		"",
		"do-build:",
		"\tcd ${WRKSRC} && GOPATH=${GOPATH} PATH=${PATH} :")

	mklines.Check()

	// For WRKSRC and GOPATH, no quoting is necessary since pkgsrc directories by
	// definition don't contain special characters. Therefore they don't need the
	// :Q, not even when used as part of a shell word.

	// For PATH, the quoting is necessary because it may contain directories outside
	// of pkgsrc, and these may contain special characters.

	t.CheckOutputLines(
		"WARN: ~/options.mk:7: The variable PATH should be quoted as part of a shell word.")
}

func (s *Suite) Test_MkVarUseChecker_checkQuoting__mstar(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.SetUpFileMkLines("options.mk",
		MkCvsID,
		"CONFIGURE_ARGS+=\tCFLAGS=${CFLAGS:Q}",
		"CONFIGURE_ARGS+=\tCFLAGS=${CFLAGS:M*:Q}",
		"CONFIGURE_ARGS+=\tADA_FLAGS=${ADA_FLAGS:Q}",
		"CONFIGURE_ARGS+=\tADA_FLAGS=${ADA_FLAGS:M*:Q}",
		"CONFIGURE_ENV+=\t\tCFLAGS=${CFLAGS:Q}",
		"CONFIGURE_ENV+=\t\tCFLAGS=${CFLAGS:M*:Q}",
		"CONFIGURE_ENV+=\t\tADA_FLAGS=${ADA_FLAGS:Q}",
		"CONFIGURE_ENV+=\t\tADA_FLAGS=${ADA_FLAGS:M*:Q}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/options.mk:2: Please use ${CFLAGS:M*:Q} instead of ${CFLAGS:Q}.",
		"WARN: ~/options.mk:4: ADA_FLAGS is used but not defined.",
		"WARN: ~/options.mk:6: Please use ${CFLAGS:M*:Q} instead of ${CFLAGS:Q}.")
}

func (s *Suite) Test_MkVarUseChecker_checkQuoting__mstar_not_needed(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"MAKE_FLAGS+=\tCFLAGS=${CFLAGS:M*:Q}",
		"MAKE_FLAGS+=\tLFLAGS=${LDFLAGS:M*:Q}")
	t.FinishSetUp()

	// This package is guaranteed to not use GNU_CONFIGURE.
	// Since the :M* hack is only needed for GNU_CONFIGURE, it is not necessary here.
	G.Check(pkg)

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:20: The :M* modifier is not needed here.",
		"NOTE: ~/category/package/Makefile:21: The :M* modifier is not needed here.")
}

func (s *Suite) Test_MkVarUseChecker_checkQuoting__q_not_needed(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"MASTER_SITES=\t${HOMEPAGE:Q}")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:6: The :Q modifier isn't necessary for ${HOMEPAGE} here.")
}

func (s *Suite) Test_MkVarUseChecker_checkQuoting__undefined_list_in_word_in_shell_command(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"\t${ECHO} ./${DISTFILES}")
	t.FinishSetUp()

	G.Check(pkg)

	// The variable DISTFILES is declared by the infrastructure.
	// It is not defined by this package, therefore it doesn't
	// appear in the RedundantScope.
	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:20: The list variable DISTFILES should not be embedded in a word.")
}

func (s *Suite) Test_MkVarUseChecker_checkQuoting__list_variable_with_single_constant_value(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"BUILD_DIRS=\tonly-dir",
		"",
		"do-install:",
		"\t${INSTALL_PROGRAM} ${WRKSRC}/${BUILD_DIRS}/program ${DESTDIR}${PREFIX}/bin/")
	t.FinishSetUp()

	G.Check(pkg)

	// Don't warn here since BUILD_DIRS, although being a list
	// variable, contains only a single value.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkVarUseChecker_checkQuoting__list_variable_with_single_conditional_value(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"BUILD_DIRS=\tonly-dir",
		".if 0",
		"BUILD_DIRS=\tother-dir",
		".endif",
		"",
		"do-install:",
		"\t${INSTALL_PROGRAM} ${WRKSRC}/${BUILD_DIRS}/program ${DESTDIR}${PREFIX}/bin/")
	t.FinishSetUp()

	G.Check(pkg)

	// TODO: Don't warn here since BUILD_DIRS, although being a list
	//  variable, contains only a single value,
	//  no matter which of the branches is taken.
	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:26: " +
			"The list variable BUILD_DIRS should not be embedded in a word.")
}

func (s *Suite) Test_MkVarUseChecker_checkQuoting__list_variable_with_two_constant_words(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"BUILD_DIRS=\tfirst-dir second-dir",
		"",
		"do-install:",
		"\t${INSTALL_PROGRAM} ${WRKSRC}/${BUILD_DIRS}/program ${DESTDIR}${PREFIX}/bin/")
	t.FinishSetUp()

	G.Check(pkg)

	// Since BUILD_DIRS consists of two words, it would destroy the installation command.
	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:23: " +
			"The list variable BUILD_DIRS should not be embedded in a word.")
}

func (s *Suite) Test_MkVarUseChecker_checkQuotingQM(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"",
		"CONFIGURE_ENV+=\tCFLAGS=${CFLAGS:Q}",
		"CONFIGURE_ENV+=\tCFLAGS=${CFLAGS:M*:Q}",
		"CONFIGURE_ENV+=\tCFLAGS=${CFLAGS:N*:Q}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:3: Please use ${CFLAGS:M*:Q} instead of ${CFLAGS:Q}.",
		// XXX: Doesn't matter in this case since :N* results in an empty list.
		"WARN: filename.mk:5: Please use ${CFLAGS:N*:M*:Q} instead of ${CFLAGS:N*:Q}.")
}

func (s *Suite) Test_MkVarUseChecker_fixQuotingModifiers(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	test := func(autofix bool) {
		mklines := t.SetUpFileMkLines("filename.mk",
			MkCvsID,
			"",
			"CONFIGURE_ENV+=\tCFLAGS=${CFLAGS:Q}",
			"CONFIGURE_ENV+=\tCFLAGS=${CFLAGS:M*:Q}",
			"CONFIGURE_ENV+=\tCFLAGS=${CFLAGS:N*:Q}")

		mklines.Check()
	}

	t.ExpectDiagnosticsAutofix(
		test,
		"WARN: ~/filename.mk:3: Please use ${CFLAGS:M*:Q} instead of ${CFLAGS:Q}.",
		"WARN: ~/filename.mk:5: Please use ${CFLAGS:N*:M*:Q} instead of ${CFLAGS:N*:Q}.",
		"AUTOFIX: ~/filename.mk:3: Replacing \"${CFLAGS:Q}\" with \"${CFLAGS:M*:Q}\".",
		"AUTOFIX: ~/filename.mk:5: Replacing \"${CFLAGS:N*:Q}\" with \"${CFLAGS:N*:M*:Q}\".")
}

func (s *Suite) Test_MkVarUseChecker_checkToolsPlatform(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.SetUpTool("available", "", AfterPrefsMk)
	t.SetUpTool("cond1", "", AfterPrefsMk)
	t.SetUpTool("cond2", "", AfterPrefsMk)
	t.SetUpTool("undefined", "", AfterPrefsMk)
	t.SetUpTool("non-const", "", AfterPrefsMk)
	t.CreateFileLines("mk/tools/tools.NetBSD.mk",
		"OTHER_VAR?=\tother value", // Just for code coverage
		"TOOLS_PLATFORM.available?=\t/bin/available",
		"TOOLS_PLATFORM.cond1?=\t/usr/cond1",
		"TOOLS_PLATFORM.cond2?=\t/usr/cond2",
		"TOOLS_PLATFORM.undefined?=\t/usr/undefined",
		"",
		"TOOLS_PLATFORM.non-const?=\t/non-const-initial",
		"READ=\t${TOOLS_PLATFORM.non-const}", // Make the variable non-const
		"TOOLS_PLATFORM.non-const?=\t/non-const-final")
	t.CreateFileLines("mk/tools/tools.SunOS.mk",
		"TOOLS_PLATFORM.available?=\t/bin/available",
		"",
		".if exists(/usr/gnu/bin/cond1)",
		"TOOLS_PLATFORM.cond1?=\t/usr/gnu/bin/cond1",
		".endif",
		"",
		".if exists(/usr/gnu/bin/cond2)",
		"TOOLS_PLATFORM.cond2?=\t/usr/gnu/bin/cond2",
		".else",
		"TOOLS_PLATFORM.cond2?=\t/usr/sfw/bin/cond2",
		".endif",
		"",
		"# No definition for undefined.")
	t.Chdir(".")
	t.FinishSetUp()
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"",
		".include \"mk/bsd.prefs.mk\"",
		"",
		".if ${OPSYS} == SunOS",
		"post-build:",
		"\t${TOOLS_PLATFORM.available}",
		"\t${TOOLS_PLATFORM.cond1}",
		"\t${TOOLS_PLATFORM.cond2}",
		"\t${TOOLS_PLATFORM.undefined}",
		".endif",
		"",
		"do-build:",
		"\t${TOOLS_PLATFORM.available}",
		"\t${TOOLS_PLATFORM.cond1}",
		"\t${TOOLS_PLATFORM.cond2}",
		"\t${TOOLS_PLATFORM.undefined}",
		"",
		".if defined(TOOLS_PLATFORM.undefined)",
		"\t${TOOLS_PLATFORM.undefined}",
		".endif")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:15: TOOLS_PLATFORM.cond1 may be undefined on SunOS.",
		"WARN: filename.mk:17: TOOLS_PLATFORM.undefined is undefined on SunOS.")
}

func (s *Suite) Test_MkVarUseChecker_checkBuildDefs(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/defaults/mk.conf",
		MkCvsID,
		"USER_SETTABLE_OK?=\tyes",
		"USER_SETTABLE_MISSING?=\tyes")
	t.FinishSetUp()
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"",
		"BUILD_DEFS+=\tUSER_SETTABLE_OK",
		"",
		"\t: ${USER_SETTABLE_OK}",
		"\t: ${USER_SETTABLE_MISSING}",
		"\t: ${PKGNAME}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:6: The user-defined variable " +
			"USER_SETTABLE_MISSING is used but not added to BUILD_DEFS.")
}

func (s *Suite) Test_MkVarUseChecker_checkDeprecated(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.FinishSetUp()
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"",
		"\t: ${USE_CROSSBASE}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:3: USE_CROSSBASE is used but not defined.",
		"WARN: filename.mk:3: Use of \"USE_CROSSBASE\" is deprecated. "+
			"Has been removed.")
}

// This test demonstrates some typos that an inexperienced pkgsrc developer
// might make. This scenario is not intended to be realistic.
func (s *Suite) Test_MkVarUseChecker_checkPkgBuildOptions(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("option", "")
	t.SetUpPackage("category/package",
		".include \"../../category/lib/buildlink3.mk\"")
	t.SetUpPackage("category/lib")
	t.CreateFileLines("mk/pkg-build-options.mk")
	t.CreateFileBuildlink3("category/package/buildlink3.mk",
		".include \"../../mk/bsd.fast.prefs.mk\"",
		"",
		".if ${PKG_BUILD_OPTIONS.lib:Moption}", // Too early
		".endif",
		"",
		".if ${PKG_BUILD_OPTIONS.unrelated:Moption}",
		".include \"../../category/lib/buildlink3.mk\"",
		".endif",
		"",
		".if ${PKG_BUILD_OPTIONS.lib:Moption}", // Only defined conditionally
		".endif")
	t.CreateFileBuildlink3("category/lib/buildlink3.mk",
		"pkgbase := lib",
		".include \"../../mk/pkg-build-options.mk\"")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"WARN: Makefile:20: \"../../category/lib/buildlink3.mk\" is included unconditionally here "+
			"and conditionally in buildlink3.mk:18 (depending on PKG_BUILD_OPTIONS.unrelated).",
		"WARN: buildlink3.mk:17: The PKG_BUILD_OPTIONS for \"unrelated\" are not available to this package.",
		"WARN: buildlink3.mk:14: Wrong PKG_BUILD_OPTIONS, expected \"package\" instead of \"lib\".",
		"WARN: buildlink3.mk:17: Wrong PKG_BUILD_OPTIONS, expected \"package\" instead of \"unrelated\".",
		"WARN: buildlink3.mk:21: Wrong PKG_BUILD_OPTIONS, expected \"package\" instead of \"lib\".")
}
