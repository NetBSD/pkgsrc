package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_NewMkAssignChecker(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		"VAR=\t${OTHER}")

	ck := NewMkAssignChecker(mklines.mklines[0], mklines)

	ck.check()

	t.CheckOutputLines(
		"WARN: filename.mk:1: VAR is defined but not used.",
		"WARN: filename.mk:1: OTHER is used but not defined.")
}

func (s *Suite) Test_MkAssignChecker_check(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"ac_cv_libpari_libs+=\t-L${BUILDLINK_PREFIX.pari}/lib") // From math/clisp-pari/Makefile, rev. 1.8

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:2: ac_cv_libpari_libs is defined but not used.")
}

// Pkglint once interpreted all lists as consisting of shell tokens,
// splitting this URL at the ampersand.
func (s *Suite) Test_MkAssignChecker_check__URL_with_shell_special_characters(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("graphics/gimp-fix-ca"))
	t.SetUpVartypes()
	mklines := t.NewMkLinesPkg("filename.mk", pkg,
		MkCvsID,
		"MASTER_SITES=\thttp://registry.gimp.org/file/fix-ca.c?action=download&id=9884&file=")

	mklines.Check()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkAssignChecker_check__list(c *check.C) {
	t := s.Init(c)

	t.SetUpMasterSite("MASTER_SITE_GITHUB", "https://github.com/")
	t.SetUpVartypes()
	t.SetUpCommandLine("-Wall", "--explain")
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"SITES.distfile=\t-${MASTER_SITE_GITHUB:=project/}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:2: The list variable MASTER_SITE_GITHUB should not be embedded in a word.",
		"",
		"\tWhen a list variable has multiple elements, this expression expands",
		"\tto something unexpected:",
		"",
		"\tExample: ${MASTER_SITE_SOURCEFORGE}directory/ expands to",
		"",
		"\t\thttps://mirror1.sf.net/ https://mirror2.sf.net/directory/",
		"",
		"\tThe first URL is missing the directory. To fix this, write",
		"\t\t${MASTER_SITE_SOURCEFORGE:=directory/}.",
		"",
		"\tExample: -l${LIBS} expands to",
		"",
		"\t\t-llib1 lib2",
		"",
		"\tThe second library is missing the -l. To fix this, write",
		"\t${LIBS:S,^,-l,}.",
		"")
}

func (s *Suite) Test_MkAssignChecker_checkLeft(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("module.mk",
		MkCvsID,
		"_VARNAME=\tvalue")
	// Only to prevent "defined but not used".
	mklines.allVars.Use("_VARNAME", mklines.mklines[1], VucRunTime)

	mklines.Check()

	t.CheckOutputLines(
		"WARN: module.mk:2: Variable names starting with an underscore " +
			"(_VARNAME) are reserved for internal pkgsrc use.")
}

// Files from the pkgsrc infrastructure may define and use variables
// whose name starts with an underscore.
func (s *Suite) Test_MkAssignChecker_checkLeft__infrastructure(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/infra.mk",
		MkCvsID,
		"_VARNAME=\t\tvalue",
		"_SORTED_VARS.group=\tVARNAME")
	t.FinishSetUp()

	G.Check(t.File("mk/infra.mk"))

	t.CheckOutputLines(
		"WARN: ~/mk/infra.mk:2: _VARNAME is defined but not used.")
}

func (s *Suite) Test_MkAssignChecker_checkLeft__documented_underscore(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("category/package/filename.mk",
		MkCvsID,
		"_SORTED_VARS.group=\tVARNAME")
	t.FinishSetUp()

	G.Check(t.File("category/package/filename.mk"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkAssignChecker_checkLeftNotUsed__procedure_call(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/pkg-build-options.mk")
	mklines := t.SetUpFileMkLines("category/package/filename.mk",
		MkCvsID,
		"",
		"pkgbase := glib2",
		".include \"../../mk/pkg-build-options.mk\"",
		"",
		"VAR=\tvalue")

	mklines.Check()

	// There is no warning for pkgbase although it looks unused as well.
	// The file pkg-build-options.mk is essentially a procedure call,
	// and pkgbase is its parameter.
	//
	// To distinguish these parameters from ordinary variables, they are
	// usually written with the := operator instead of the = operator.
	// This has the added benefit that the parameter is only evaluated
	// once, especially if it contains references to other variables.
	t.CheckOutputLines(
		"WARN: ~/category/package/filename.mk:6: VAR is defined but not used.")
}

func (s *Suite) Test_MkAssignChecker_checkLeftNotUsed__procedure_call_no_tracing(c *check.C) {
	t := s.Init(c)

	t.DisableTracing() // Just for code coverage
	t.CreateFileLines("mk/pkg-build-options.mk")
	mklines := t.SetUpFileMkLines("category/package/filename.mk",
		MkCvsID,
		"",
		"pkgbase := glib2",
		".include \"../../mk/pkg-build-options.mk\"")

	mklines.Check()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkAssignChecker_checkLeftNotUsed__infra(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/infra.mk",
		MkCvsID,
		"#",
		"# Package-settable variables:",
		"#",
		"# SHORT_DOCUMENTATION",
		"#\tIf set to no, ...",
		"#\tsecond line.",
		"#",
		"#",
		".if ${USED_IN_INFRASTRUCTURE:Uyes:tl} == yes",
		".endif")
	t.SetUpPackage("category/package",
		"USED_IN_INFRASTRUCTURE=\t${SHORT_DOCUMENTATION}",
		"",
		"UNUSED_INFRA=\t${UNDOCUMENTED}")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:22: UNUSED_INFRA is defined but not used.",
		"WARN: ~/category/package/Makefile:22: UNDOCUMENTED is used but not defined.")
}

func (s *Suite) Test_MkAssignChecker_checkLeftDeprecated(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.FinishSetUp()

	test := func(varname string, diagnostics ...string) {
		mklines := t.NewMkLines("filename.mk",
			varname+"=\t# none")
		ck := NewMkAssignChecker(mklines.mklines[0], mklines)

		ck.checkLeftDeprecated()

		t.CheckOutput(diagnostics)
	}

	test("FIX_RPATH",
		"WARN: filename.mk:1: Definition of FIX_RPATH is deprecated. "+
			"It has been removed from pkgsrc in 2003.")

	test("PKGNAME",
		nil...)
}

func (s *Suite) Test_MkAssignChecker_checkLeftBsdPrefs(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--only", "bsd.prefs.mk")
	t.SetUpVartypes()
	mklines := t.NewMkLines("module.mk",
		MkCvsID,
		"",
		"BUILDLINK_PKGSRCDIR.pkgbase?=\t${PREFIX}",
		"BUILDLINK_DEPMETHOD.pkgbase?=\tfull",
		"BUILDLINK_ABI_DEPENDS.pkgbase?=\tpkgbase>=1",
		"BUILDLINK_INCDIRS.pkgbase?=\t# none",
		"BUILDLINK_LIBDIRS.pkgbase?=\t# none",
		"",
		// User-settable, therefore bsd.prefs.mk must be included before.
		// To avoid frightening pkgsrc developers, this is currently a
		// warning instead of an error. An error would be better though.
		"MYSQL_USER?=\tmysqld",
		// Package-settable variables do not depend on the user settings,
		// therefore it is ok to give them default values without
		// including bsd.prefs.mk before.
		"PKGNAME?=\tpkgname-1.0")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: module.mk:9: " +
			"Please include \"../../mk/bsd.prefs.mk\" before using \"?=\".")
}

// Up to 2019-12-03, pkglint didn't issue a warning if a default assignment
// to a package-settable variable appeared before one to a user-settable
// variable. This was a mistake.
func (s *Suite) Test_MkAssignChecker_checkLeftBsdPrefs__first_time(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("module.mk",
		MkCvsID,
		"",
		"PKGNAME?=\tpkgname-1.0",
		"MYSQL_USER?=\tmysqld")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: module.mk:4: Please include \"../../mk/bsd.prefs.mk\" "+
			"before using \"?=\".",
		"WARN: module.mk:4: The variable MYSQL_USER should not "+
			"be given a default value by any package.")
}

func (s *Suite) Test_MkAssignChecker_checkLeftBsdPrefs__vartype_nil(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("builtin.mk",
		MkCvsID,
		"VAR_SH?=\tvalue")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: builtin.mk:2: VAR_SH is defined but not used.",
		"WARN: builtin.mk:2: Please include \"../../mk/bsd.prefs.mk\" before using \"?=\".")
}

func (s *Suite) Test_MkAssignChecker_checkLeftUserSettable(c *check.C) {
	t := s.Init(c)

	// TODO: Allow CreateFileLines before SetUpPackage, since it matches
	//  the expected reading order of human readers.

	t.SetUpPackage("category/package",
		"ASSIGN_DIFF=\t\tpkg",          // assignment, differs from default value
		"ASSIGN_DIFF2=\t\treally # ok", // ok because of the rationale in the comment
		"ASSIGN_SAME=\t\tdefault",      // assignment, same value as default
		"DEFAULT_DIFF?=\t\tpkg",        // default, differs from default value
		"DEFAULT_SAME?=\t\tdefault",    // same value as default
		"FETCH_USING=\t\tcurl",         // both user-settable and package-settable
		"APPEND_DIRS+=\t\tdir3",        // appending requires a separate diagnostic
		"COMMENTED_SAME?=\tdefault",    // commented default, same value as default
		"COMMENTED_DIFF?=\tpkg")        // commented default, differs from default value
	t.CreateFileLines("mk/defaults/mk.conf",
		MkCvsID,
		"ASSIGN_DIFF?=default",
		"ASSIGN_DIFF2?=default",
		"ASSIGN_SAME?=default",
		"DEFAULT_DIFF?=\tdefault",
		"DEFAULT_SAME?=\tdefault",
		"FETCH_USING=\tauto",
		"APPEND_DIRS=\tdefault",
		"#COMMENTED_SAME?=\tdefault",
		"#COMMENTED_DIFF?=\tdefault")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"WARN: Makefile:20: Package sets user-defined \"ASSIGN_DIFF\" to \"pkg\", "+
			"which differs from the default value \"default\" from mk/defaults/mk.conf.",
		"NOTE: Makefile:22: Redundant definition for ASSIGN_SAME from mk/defaults/mk.conf.",
		"WARN: Makefile:23: Please include \"../../mk/bsd.prefs.mk\" before using \"?=\".",
		"WARN: Makefile:23: Package sets user-defined \"DEFAULT_DIFF\" to \"pkg\", "+
			"which differs from the default value \"default\" from mk/defaults/mk.conf.",
		"NOTE: Makefile:24: Redundant definition for DEFAULT_SAME from mk/defaults/mk.conf.",
		"WARN: Makefile:26: Packages should not append to user-settable APPEND_DIRS.",
		"WARN: Makefile:28: Package sets user-defined \"COMMENTED_DIFF\" to \"pkg\", "+
			"which differs from the default value \"default\" from mk/defaults/mk.conf.")
}

func (s *Suite) Test_MkAssignChecker_checkLeftUserSettable__before_prefs(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	t.SetUpPackage("category/package",
		"BEFORE=\tvalue",
		".include \"../../mk/bsd.prefs.mk\"")
	t.CreateFileLines("mk/defaults/mk.conf",
		MkCvsID,
		"BEFORE?=\tvalue")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"NOTE: Makefile:20: Redundant definition for BEFORE from mk/defaults/mk.conf.",
		"",
		"\tInstead of defining the variable redundantly, it suffices to include",
		"\t../../mk/bsd.prefs.mk, which provides all user-settable variables.",
		"")
}

func (s *Suite) Test_MkAssignChecker_checkLeftUserSettable__after_prefs(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	t.SetUpPackage("category/package",
		".include \"../../mk/bsd.prefs.mk\"",
		"AFTER=\tvalue")
	t.CreateFileLines("mk/defaults/mk.conf",
		MkCvsID,
		"AFTER?=\t\tvalue")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"NOTE: Makefile:21: Redundant definition for AFTER from mk/defaults/mk.conf.")
}

func (s *Suite) Test_MkAssignChecker_checkLeftUserSettable__vartype_nil(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("category/package/allVars.mk",
		MkCvsID,
		"#",
		"# User-settable variables:",
		"#",
		"# USER_SETTABLE",
		"#\tDocumentation for USER_SETTABLE.",
		"",
		".include \"../../mk/bsd.prefs.mk\"",
		"",
		"USER_SETTABLE?=\tdefault")
	t.SetUpPackage("category/package",
		"USER_SETTABLE=\tvalue")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	// TODO: As of June 2019, pkglint doesn't parse the "User-settable variables"
	//  comment. Therefore it doesn't know that USER_SETTABLE is intended to be
	//  used by other packages. There should be no warning.
	t.CheckOutputLines(
		"WARN: Makefile:20: USER_SETTABLE is defined but not used.")
}

func (s *Suite) Test_MkAssignChecker_checkLeftPermissions__hacks_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("hacks.mk",
		MkCvsID,
		"OPSYS=\t${PKGREVISION}")

	mklines.Check()

	// No matter how strange the definition or use of a variable sounds,
	// in hacks.mk it is allowed. Special problems sometimes need solutions
	// that violate all standards.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkAssignChecker_checkLeftPermissions(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("awk", "AWK", AtRunTime)
	t.SetUpType("SET_ONLY", BtUnknown, NoVartypeOptions,
		"options.mk: set")
	t.SetUpType("SET_ONLY_DEFAULT_ELSEWHERE", BtUnknown, NoVartypeOptions,
		"options.mk: set",
		"*.mk: default, set")
	mklines := t.NewMkLines("options.mk",
		MkCvsID,
		"PKG_DEVELOPER?=\tyes",
		"BUILD_DEFS?=\tVARBASE",
		"USE_TOOLS:=\t${USE_TOOLS:Nunwanted-tool}",
		"USE_TOOLS:=\t${MY_TOOLS}",
		"USE_TOOLS:=\tawk",
		"",
		"SET_ONLY=\tset",
		"SET_ONLY:=\teval",
		"SET_ONLY?=\tdefault",
		"",
		"SET_ONLY_DEFAULT_ELSEWHERE=\tset",
		"SET_ONLY_DEFAULT_ELSEWHERE:=\teval",
		"SET_ONLY_DEFAULT_ELSEWHERE?=\tdefault")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: options.mk:2: Please include \"../../mk/bsd.prefs.mk\" before using \"?=\".",
		"WARN: options.mk:2: The variable PKG_DEVELOPER should not be given a default value by any package.",
		"WARN: options.mk:3: The variable BUILD_DEFS should not be given a default value (only appended to) in this file.",
		"WARN: options.mk:4: USE_TOOLS should not be used at load time in this file; "+
			"it would be ok in Makefile.common or builtin.mk, but not buildlink3.mk or *.",
		"WARN: options.mk:5: MY_TOOLS is used but not defined.",
		"WARN: options.mk:10: "+
			"The variable SET_ONLY should not be given a default value "+
			"(only set) in this file.",
		"WARN: options.mk:14: "+
			"The variable SET_ONLY_DEFAULT_ELSEWHERE should not be given a "+
			"default value (only set) in this file; it would be ok in *.mk, "+
			"but not options.mk.")
}

func (s *Suite) Test_MkAssignChecker_checkLeftPermissions__no_tracing(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.DisableTracing() // Just to reach branch coverage for unknown permissions.
	mklines := t.NewMkLines("options.mk",
		MkCvsID,
		"COMMENT=\tShort package description")

	mklines.Check()
}

// Setting a default license is typical for big software projects
// like GNOME or KDE that consist of many packages, or for programming
// languages like Perl or Python that suggest certain licenses.
//
// The default license is typically set in a Makefile.common or module.mk.
func (s *Suite) Test_MkAssignChecker_checkLeftPermissions__license_default(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"LICENSE?=\tgnu-gpl-v2")
	t.FinishSetUp()

	mklines.Check()

	// LICENSE is a package-settable variable. Therefore bsd.prefs.mk
	// does not need to be included before setting a default for this
	// variable. Including bsd.prefs.mk is only necessary when setting a
	// default value for user-settable or system-defined variables.
	t.CheckOutputEmpty()
}

// Don't check the permissions for infrastructure files since they have their own rules.
func (s *Suite) Test_MkAssignChecker_checkLeftPermissions__infrastructure(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.CreateFileLines("mk/infra.mk",
		MkCvsID,
		"",
		"PKG_DEVELOPER?=\tyes")
	t.CreateFileLines("mk/bsd.pkg.mk")

	G.Check(t.File("mk/infra.mk"))

	t.CheckOutputEmpty()
}

// Seen in x11/gtkmm3 before 2020-06-07.
func (s *Suite) Test_MkAssignChecker_checkLeftAbiDepends(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"BUILDLINK_ABI_DEPENDS.lib+=\tlib>=1.0")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	// It may be a good idea to not only check the buildlink identifier
	// for ${BUILDLINK_PREFIX.*} but also for appending to
	// BUILDLINK_API_DEPENDS and BUILDLINK_ABI_DEPENDS.
	t.CheckOutputLines(
		"ERROR: Makefile:20: Packages must only require API versions, " +
			"not ABI versions of dependencies.")
}

func (s *Suite) Test_MkAssignChecker_checkLeftRationale(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	testLines := func(lines []string, diagnostics ...string) {
		mklines := t.NewMkLines("filename.mk",
			lines...)

		mklines.Check()

		t.CheckOutput(diagnostics)
	}
	test := func(lines []string, diagnostics ...string) {
		testLines(append([]string{MkCvsID, ""}, lines...), diagnostics...)
	}
	lines := func(lines ...string) []string { return lines }

	test(
		lines(
			MkCvsID,
			"ONLY_FOR_PLATFORM=\t*-*-*", // The CVS Id above is not a rationale.
			"NOT_FOR_PLATFORM=\t*-*-*",  // Neither does this line have a rationale.
		),
		"WARN: filename.mk:4: Setting variable ONLY_FOR_PLATFORM should have a rationale.",
		"WARN: filename.mk:5: Setting variable NOT_FOR_PLATFORM should have a rationale.")

	test(
		lines(
			"ONLY_FOR_PLATFORM+=\t*-*-* # rationale in the same line"),
		nil...)

	test(
		lines(
			"",
			"# rationale in the line above",
			"ONLY_FOR_PLATFORM+=\t*-*-*"),
		nil...)

	// A commented variable assignment does not count as a rationale,
	// since it is not in plain text.
	test(
		lines(
			"#VAR=\tvalue",
			"ONLY_FOR_PLATFORM+=\t*-*-*"),
		"WARN: filename.mk:4: Setting variable ONLY_FOR_PLATFORM should have a rationale.")

	// Another variable assignment with comment does not count as a rationale.
	test(
		lines(
			"PKGNAME=\t\tpackage-1.0 # this is not a rationale",
			"ONLY_FOR_PLATFORM+=\t*-*-*"),
		"WARN: filename.mk:4: Setting variable ONLY_FOR_PLATFORM should have a rationale.")

	// A rationale applies to all variable assignments directly below it.
	test(
		lines(
			"# rationale",
			"BROKEN_ON_PLATFORM+=\t*-*-*",
			"BROKEN_ON_PLATFORM+=\t*-*-*"), // The rationale applies to this line, too.
		nil...)

	// Just for code coverage.
	test(
		lines(
			"PKGNAME=\tpackage-1.0", // Does not need a rationale.
			"UNKNOWN=\t${UNKNOWN}"), // Unknown type, does not need a rationale.
		nil...)

	// When a line requiring a rationale appears in the very first line
	// or in the second line of a file, there is no index out of bounds error.
	testLines(
		lines(
			"NOT_FOR_PLATFORM=\t*-*-*",
			"NOT_FOR_PLATFORM=\t*-*-*"),
		sprintf("ERROR: filename.mk:1: Expected %q.", MkCvsID),
		"WARN: filename.mk:1: Setting variable NOT_FOR_PLATFORM should have a rationale.",
		"WARN: filename.mk:2: Setting variable NOT_FOR_PLATFORM should have a rationale.")

	// The whole rationale check is only enabled when -Wextra is given.
	t.SetUpCommandLine()

	test(
		lines(
			MkCvsID,
			"ONLY_FOR_PLATFORM=\t*-*-*", // The CVS Id above is not a rationale.
			"NOT_FOR_PLATFORM=\t*-*-*",  // Neither does this line have a rationale.
		),
		nil...)
}

func (s *Suite) Test_MkAssignChecker_checkOp(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("uname", "UNAME", AfterPrefsMk)
	t.SetUpTool("echo", "", AtRunTime)
	t.SetUpPkgsrc()
	t.SetUpPackage("category/package",
		"OPSYS_NAME!=\t${UNAME}",
		"",
		"PKG_FAIL_REASON+=\t${OPSYS_NAME}")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:20: "+
			"Consider the :sh modifier instead of != for \"${UNAME}\".",
		"WARN: ~/category/package/Makefile:20: "+
			"To use the tool ${UNAME} at load time, "+
			"bsd.prefs.mk has to be included before.")
}

func (s *Suite) Test_MkAssignChecker_checkOpShell(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("uname", "UNAME", AfterPrefsMk)
	t.SetUpTool("echo", "", AtRunTime)
	t.SetUpPkgsrc()
	t.SetUpPackage("category/package",
		".include \"standalone.mk\"")
	t.CreateFileLines("category/package/standalone.mk",
		MkCvsID,
		"",
		".include \"../../mk/bsd.prefs.mk\"",
		"",
		"OPSYS_NAME!=\t${UNAME}",
		".if ${OPSYS_NAME} == \"NetBSD\"",
		".endif",
		"",
		"OS_NAME!=\t${UNAME}",
		"",
		"MUST_BE_EARLY!=\techo 123 # must be evaluated early",
		"",
		"show-package-allVars: .PHONY",
		"\techo OS_NAME=${OS_NAME:Q}",
		"\techo MUST_BE_EARLY=${MUST_BE_EARLY:Q}")
	t.FinishSetUp()

	G.Check(t.File("category/package/standalone.mk"))

	// There is no warning about any variable since no package is currently
	// being checked, therefore pkglint cannot decide whether the variable
	// is used a load time.
	t.CheckOutputLines(
		"WARN: ~/category/package/standalone.mk:14: Please use \"${ECHO}\" instead of \"echo\".",
		"WARN: ~/category/package/standalone.mk:15: Please use \"${ECHO}\" instead of \"echo\".")

	t.SetUpCommandLine("-Wall", "--explain")
	G.Check(t.File("category/package"))

	// There is no warning for OPSYS_NAME since that variable is used at
	// load time. In such a case the command has to be executed anyway,
	// and executing it exactly once is the best thing to do.
	//
	// There is no warning for MUST_BE_EARLY since the comment provides the
	// reason that this command really has to be executed at load time.
	t.CheckOutputLines(
		"NOTE: ~/category/package/standalone.mk:9: Consider the :sh modifier instead of != for \"${UNAME}\".",
		"",
		"\tFor variable assignments using the != operator, the shell command is",
		"\trun every time the file is parsed. In some cases this is too early,",
		"\tand the command may not yet be installed. In other cases the command",
		"\tis executed more often than necessary. Most commands don't need to",
		"\tbe executed for \"make clean\", for example.",
		"",
		"\tThe :sh modifier defers execution until the variable value is",
		"\tactually needed. On the other hand, this means the command is",
		"\texecuted each time the variable is evaluated.",
		"",
		"\tExample:",
		"",
		"\t\tEARLY_YEAR!=    date +%Y",
		"",
		"\t\tLATE_YEAR_CMD=  date +%Y",
		"\t\tLATE_YEAR=      ${LATE_YEAR_CMD:sh}",
		"",
		"\t\t# or, in a single line:",
		"\t\tLATE_YEAR=      ${date +%Y:L:sh}",
		"",
		"\tTo suppress this note, provide an explanation in a comment at the",
		"\tend of the line, or force the variable to be evaluated at load time,",
		"\tby using it at the right-hand side of the := operator, or in an .if",
		"\tor .for directive.",
		"",
		"WARN: ~/category/package/standalone.mk:14: Please use \"${ECHO}\" instead of \"echo\".",
		"WARN: ~/category/package/standalone.mk:15: Please use \"${ECHO}\" instead of \"echo\".")
}

func (s *Suite) Test_MkAssignChecker_checkRight(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("filename.mk",
		"BUILD_CMD.${UNKNOWN}=\tcd ${WRKSRC}/.. && make")

	mklines.ForEach(func(mkline *MkLine) {
		ck := NewMkAssignChecker(mkline, mklines)
		ck.checkRight()
	})

	// No warning about the UNKNOWN variable on the left-hand side,
	// since that is out of scope.
	t.CheckOutputLines(
		"WARN: filename.mk:1: Building the package should take place "+
			"entirely inside ${WRKSRC}, not \"${WRKSRC}/..\".",
		"WARN: filename.mk:1: Unknown shell command \"make\".")
}

func (s *Suite) Test_MkAssignChecker_checkRightCategory__none(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("obscure/package",
		"CATEGORIES=\t# none")
	t.FinishSetUp()

	G.Check(t.File("obscure/package"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkAssignChecker_checkRightCategory__indirect(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("obscure/package",
		"CATEGORIES=\t${PKGPATH:C,/.*,,}")
	t.FinishSetUp()

	G.Check(t.File("obscure/package"))

	// This case does not occur in practice,
	// therefore it's ok to have these warnings.
	t.CheckOutputLines(
		"WARN: ~/obscure/package/Makefile:5: "+
			"The primary category should be \"obscure\", not \"${PKGPATH:C,/.*,,}\".",
		"ERROR: ~/obscure/package/Makefile:5: "+
			"Invalid category \"${PKGPATH:C,/.*,,}\".")
}

func (s *Suite) Test_MkAssignChecker_checkRightCategory__wrong(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("obscure/package",
		"CATEGORIES=\tperl5")
	t.FinishSetUp()

	G.Check(t.File("obscure/package"))

	t.CheckOutputLines(
		"WARN: ~/obscure/package/Makefile:5: The primary category should be \"obscure\", not \"perl5\".")
}

func (s *Suite) Test_MkAssignChecker_checkRightCategory__wrong_in_package_directory(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("obscure/package",
		"CATEGORIES=\tperl5")
	t.FinishSetUp()
	t.Chdir("obscure/package")

	G.Check(".")

	t.CheckOutputLines(
		"WARN: Makefile:5: The primary category should be \"obscure\", not \"perl5\".")
}

// Allow any primary category in "packages" from regress/*.
// These packages won't be installed in a regular pkgsrc installation anyway.
func (s *Suite) Test_MkAssignChecker_checkRightCategory__regress(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("regress/regress-package",
		"CATEGORIES=\tregress")
	t.SetUpPackage("regress/misc-package",
		"CATEGORIES=\tmisc")
	t.SetUpCategory("misc")
	t.FinishSetUp()
	t.Chdir(".")

	G.Check("regress/regress-package")
	G.Check("regress/misc-package")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkAssignChecker_checkRightCategory__append(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("obscure/package",
		"CATEGORIES+=\tperl5")
	t.FinishSetUp()

	G.Check(t.File("obscure/package"))

	// Appending is ok.
	// In this particular case, appending has the same effect as assigning,
	// but that can be checked somewhere else.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkAssignChecker_checkRightCategory__default(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("obscure/package",
		"CATEGORIES?=\tperl5")
	t.FinishSetUp()

	G.Check(t.File("obscure/package"))

	// Default assignments set the primary category, just like simple assignments.
	t.CheckOutputLines(
		"WARN: ~/obscure/package/Makefile:5: The primary category should be \"obscure\", not \"perl5\".")
}

func (s *Suite) Test_MkAssignChecker_checkRightCategory__autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--autofix")
	t.SetUpPackage("obscure/package",
		"CATEGORIES=\tperl5 obscure python")
	t.FinishSetUp()

	G.Check(t.File("obscure/package"))

	t.CheckOutputLines(
		"AUTOFIX: ~/obscure/package/Makefile:5: " +
			"Replacing \"perl5 obscure\" with \"obscure perl5\".")
}

func (s *Suite) Test_MkAssignChecker_checkRightCategory__third(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("obscure/package",
		"CATEGORIES=\tperl5 python obscure")
	t.FinishSetUp()

	G.Check(t.File("obscure/package"))

	t.CheckOutputLines(
		"WARN: ~/obscure/package/Makefile:5: " +
			"The primary category should be \"obscure\", not \"perl5\".")

	t.SetUpCommandLine("-Wall", "--show-autofix")

	G.Check(t.File("obscure/package"))
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkAssignChecker_checkRightCategory__other_file(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("obscure/package",
		"CATEGORIES=\tperl5 obscure python")
	mklines := t.SetUpFileMkLines("obscure/package/module.mk",
		MkCvsID,
		"",
		"CATEGORIES=\tperl5")
	t.FinishSetUp()

	mklines.Check()

	// It doesn't matter in which file the CATEGORIES= line appears.
	// If it's a plain assignment, it will end up as the primary category.
	t.CheckOutputLines(
		"WARN: ~/obscure/package/module.mk:3: " +
			"The primary category should be \"obscure\", not \"perl5\".")
}

func (s *Suite) Test_MkAssignChecker_checkMisc(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.SetUpMasterSite("MASTER_SITE_GITHUB", "https://download.github.com/")
	t.FinishSetUp()

	test := func(text string, diagnostics ...string) {
		mklines := t.NewMkLines("filename.mk",
			MkCvsID,
			text)

		mklines.Check()

		t.CheckOutput(diagnostics)
	}

	test(
		"EGDIR=\t\t\t${PREFIX}/etc/rc.d",
		"WARN: filename.mk:2: Please use the RCD_SCRIPTS mechanism "+
			"to install rc.d scripts automatically "+
			"to ${RCD_SCRIPTS_EXAMPLEDIR}.")

	// Since RPMIGNOREPATH effectively excludes the path, it is ok to
	// mention etc/rc.d there.
	test(
		"RPMIGNOREPATH+=\t\t${PREFIX}/etc/rc.d",
		nil...)

	test(
		"_TOOLS_VARNAME.sed=\tSED",
		"WARN: filename.mk:2: Variable names starting with an underscore "+
			"(_TOOLS_VARNAME.sed) are reserved for internal pkgsrc use.",
		"WARN: filename.mk:2: _TOOLS_VARNAME.sed is defined but not used.")

	test(
		"DIST_SUBDIR=\t\t${PKGNAME}",
		"WARN: filename.mk:2: PKGNAME should not be used in DIST_SUBDIR "+
			"as it includes the PKGREVISION. Please use PKGNAME_NOREV instead.")

	test(
		"WRKSRC=\t\t\t${PKGNAME}",
		"WARN: filename.mk:2: PKGNAME should not be used in WRKSRC "+
			"as it includes the PKGREVISION. Please use PKGNAME_NOREV instead.")

	test(
		"SITES_distfile.tar.gz=\t${MASTER_SITE_GITHUB:=user/}",
		"WARN: filename.mk:2: SITES_distfile.tar.gz is defined but not used.",
		"WARN: filename.mk:2: SITES_* is deprecated. Please use SITES.* instead.")

	test(
		"MASTER_SITES=\t\thttps://cdn.example.org/${PKGNAME}/",
		"WARN: filename.mk:2: PKGNAME should not be used in MASTER_SITES "+
			"as it includes the PKGREVISION. Please use PKGNAME_NOREV instead.")

	test(
		"MASTER_SITES=\t\thttps://cdn.example.org/distname-${PKGVERSION}/",
		"WARN: filename.mk:2: PKGVERSION should not be used in MASTER_SITES "+
			"as it includes the PKGREVISION. Please use PKGVERSION_NOREV instead.")
}

func (s *Suite) Test_MkAssignChecker_checkMisc__multiple_inclusion_guards(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("filename.mk",
		MkCvsID,
		".if !defined(FILENAME_MK)",
		"FILENAME_MK=\t# defined",
		".endif")
	t.CreateFileLines("Makefile.common",
		MkCvsID,
		".if !defined(MAKEFILE_COMMON)",
		"MAKEFILE_COMMON=\t# defined",
		"",
		".endif")
	t.CreateFileLines("other.mk",
		MkCvsID,
		"COMMENT=\t# defined")
	t.FinishSetUp()

	G.Check(t.File("filename.mk"))
	G.Check(t.File("Makefile.common"))
	G.Check(t.File("other.mk"))

	// For multiple-inclusion guards, the meaning of the variable value
	// is clear, therefore they are exempted from the warnings.
	t.CheckOutputLines(
		"NOTE: ~/other.mk:2: Please use \"# empty\", \"# none\" or \"# yes\" " +
			"instead of \"# defined\".")
}

func (s *Suite) Test_MkAssignChecker_checkDecreasingVersions(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"PYTHON_VERSIONS_ACCEPTED=\t36 __future__ # rationale",
		"PYTHON_VERSIONS_ACCEPTED=\t36 -13 # rationale",
		"PYTHON_VERSIONS_ACCEPTED=\t36 ${PKGVERSION_NOREV} # rationale",
		"PYTHON_VERSIONS_ACCEPTED=\t36 37 # rationale",
		"PYTHON_VERSIONS_ACCEPTED=\t37 36 27 25 # rationale")

	// TODO: All but the last of the above assignments should be flagged as
	//  redundant by RedundantScope; as of March 2019, that check is only
	//  implemented for package Makefiles, not for individual files.

	mklines.Check()

	// Half of these warnings are from VartypeCheck.Enum,
	// the other half are from checkDecreasingVersions.
	// Strictly speaking some of them are redundant, but that's ok.
	// They all need to be fixed in the end.
	t.CheckOutputLines(
		"WARN: Makefile:2: \"__future__\" is not valid for PYTHON_VERSIONS_ACCEPTED. "+
			"Use one of { 27 36 37 38 } instead.",
		"ERROR: Makefile:2: Value \"__future__\" for "+
			"PYTHON_VERSIONS_ACCEPTED must be a positive integer.",
		"WARN: Makefile:3: \"-13\" is not valid for PYTHON_VERSIONS_ACCEPTED. "+
			"Use one of { 27 36 37 38 } instead.",
		"ERROR: Makefile:3: Value \"-13\" for "+
			"PYTHON_VERSIONS_ACCEPTED must be a positive integer.",
		"ERROR: Makefile:4: Value \"${PKGVERSION_NOREV}\" for "+
			"PYTHON_VERSIONS_ACCEPTED must be a positive integer.",
		"WARN: Makefile:5: The values for PYTHON_VERSIONS_ACCEPTED "+
			"should be in decreasing order (37 before 36).",
		"WARN: Makefile:6: \"25\" is not valid for PYTHON_VERSIONS_ACCEPTED. "+
			"Use one of { 27 36 37 38 } instead.")
}

func (s *Suite) Test_MkAssignChecker_checkMiscRedundantInstallationDirs__AUTO_MKDIRS_yes(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"INSTALLATION_DIRS=\tbin man ${PKGMANDIR}",
		"AUTO_MKDIRS=\t\tyes")
	t.CreateFileLines("category/package/PLIST",
		PlistCvsID,
		"bin/program",
		"man/man1/program.1")
	t.FinishSetUp()

	G.checkdirPackage(t.File("category/package"))

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:20: "+
			"The directory \"bin\" is redundant in INSTALLATION_DIRS.",
		"NOTE: ~/category/package/Makefile:20: "+
			"The directory \"man\" is redundant in INSTALLATION_DIRS.")
}

func (s *Suite) Test_MkAssignChecker_checkMiscRedundantInstallationDirs__AUTO_MKDIRS_no(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"INSTALLATION_DIRS=\tbin man ${PKGMANDIR}",
		"AUTO_MKDIRS=\t\tno")
	t.CreateFileLines("category/package/PLIST",
		PlistCvsID,
		"bin/program",
		"man/man1/program.1")
	t.FinishSetUp()

	G.checkdirPackage(t.File("category/package"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkAssignChecker_checkMiscRedundantInstallationDirs__absolute(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"INSTALLATION_DIRS=\t/bin",
		"AUTO_MKDIRS=\t\tyes")
	t.CreateFileLines("category/package/PLIST",
		PlistCvsID,
		"bin/program",
		"man/man1/program.1")
	t.FinishSetUp()

	G.checkdirPackage(t.File("category/package"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/Makefile:20: " +
			"The pathname \"/bin\" in INSTALLATION_DIRS " +
			"must be relative to ${PREFIX}.")
}

func (s *Suite) Test_MkAssignChecker_checkRightVaruse(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("module.mk",
		MkCvsID,
		"PLIST_SUBST+=\tLOCALBASE=${LOCALBASE:Q}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: module.mk:2: Please use PREFIX instead of LOCALBASE.",
		"NOTE: module.mk:2: The :Q modifier isn't necessary for ${LOCALBASE} here.")
}

func (s *Suite) Test_MkAssignChecker_checkVaruseShell(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		"EXAMPLE_CMD=\tgrep word ${EXAMPLE_FILES}; continue")

	mklines.ForEach(func(mkline *MkLine) {
		ck := NewMkAssignChecker(mkline, mklines)
		ck.checkRight()
	})

	t.CheckOutputLines(
		"WARN: filename.mk:1: Unknown shell command \"grep\".",
		"WARN: filename.mk:1: EXAMPLE_FILES is used but not defined.")
}
