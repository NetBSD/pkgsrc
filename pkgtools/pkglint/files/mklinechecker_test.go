package pkglint

import (
	"gopkg.in/check.v1"
	"runtime"
)

func (s *Suite) Test_MkLineChecker_checkVarassignLeft(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("module.mk",
		MkCvsID,
		"_VARNAME=\tvalue")
	// Only to prevent "defined but not used".
	mklines.vars.Use("_VARNAME", mklines.mklines[1], VucRunTime)

	mklines.Check()

	t.CheckOutputLines(
		"WARN: module.mk:2: Variable names starting with an underscore " +
			"(_VARNAME) are reserved for internal pkgsrc use.")
}

func (s *Suite) Test_MkLineChecker_checkVarassignLeftNotUsed__procedure_call(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_checkVarassignLeftNotUsed__procedure_call_no_tracing(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_checkVarassignLeftNotUsed__infra(c *check.C) {
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

// Files from the pkgsrc infrastructure may define and use variables
// whose name starts with an underscore.
func (s *Suite) Test_MkLineChecker_checkVarassignLeft__infrastructure(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_checkVarassignLeft__documented_underscore(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("category/package/filename.mk",
		MkCvsID,
		"_SORTED_VARS.group=\tVARNAME")
	t.FinishSetUp()

	G.Check(t.File("category/package/filename.mk"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLineChecker_checkVarassignLeftUserSettable(c *check.C) {
	t := s.Init(c)

	// TODO: Allow CreateFileLines before SetUpPackage, since it matches
	//  the expected reading order of human readers.

	t.SetUpPackage("category/package",
		"ASSIGN_DIFF=\tpkg",          // assignment, differs from default value
		"ASSIGN_DIFF2=\treally # ok", // ok because of the rationale in the comment
		"ASSIGN_SAME=\tdefault",      // assignment, same value as default
		"DEFAULT_DIFF?=\tpkg",        // default, differs from default value
		"DEFAULT_SAME?=\tdefault",    // same value as default
		"FETCH_USING=\tcurl",         // both user-settable and package-settable
		"APPEND_DIRS+=\tdir3",        // appending requires a separate diagnostic
		"COMMENTED_SAME?=\tdefault",  // commented default, same value as default
		"COMMENTED_DIFF?=\tpkg")      // commented default, differs from default value
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

func (s *Suite) Test_MkLineChecker_checkVarassignLeftUserSettable__before_prefs(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_checkVarassignLeftUserSettable__after_prefs(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_checkVarassignLeftUserSettable__vartype_nil(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("category/package/vars.mk",
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

func (s *Suite) Test_MkLineChecker_checkVarassignLeftBsdPrefs__vartype_nil(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("builtin.mk",
		MkCvsID,
		"VAR_SH?=\tvalue")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: builtin.mk:2: VAR_SH is defined but not used.",
		"WARN: builtin.mk:2: Please include \"../../mk/bsd.prefs.mk\" before using \"?=\".")
}

func (s *Suite) Test_MkLineChecker_Check__url2pkg(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"# url2pkg-marker")

	mklines.Check()

	t.CheckOutputLines(
		"ERROR: filename.mk:2: This comment indicates unfinished work (url2pkg).")
}

func (s *Suite) Test_MkLineChecker_Check__buildlink3_include_prefs(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	t.CreateFileLines("mk/bsd.prefs.mk")
	t.CreateFileLines("mk/bsd.fast.prefs.mk")
	mklines := t.SetUpFileMkLines("category/package/buildlink3.mk",
		MkCvsID,
		".include \"../../mk/bsd.prefs.mk\"",
		".include \"../../mk/bsd.fast.prefs.mk\"")

	// If the buildlink3.mk file doesn't actually exist, resolving the
	// relative path fails since that depends on the actual file system,
	// not on syntactical paths; see os.Stat in CheckRelativePath.
	//
	// TODO: Refactor relpath to be independent of a filesystem.

	mklines.Check()

	t.CheckOutputLines(
		"NOTE: ~/category/package/buildlink3.mk:2: For efficiency reasons, " +
			"please include bsd.fast.prefs.mk instead of bsd.prefs.mk.")
}

func (s *Suite) Test_MkLineChecker_checkInclude(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	t.CreateFileLines("pkgtools/x11-links/buildlink3.mk")
	t.CreateFileLines("graphics/jpeg/buildlink3.mk")
	t.CreateFileLines("devel/intltool/buildlink3.mk")
	t.CreateFileLines("devel/intltool/builtin.mk")
	mklines := t.SetUpFileMkLines("category/package/filename.mk",
		MkCvsID,
		"",
		".include \"../../pkgtools/x11-links/buildlink3.mk\"",
		".include \"../../graphics/jpeg/buildlink3.mk\"",
		".include \"../../devel/intltool/buildlink3.mk\"",
		".include \"../../devel/intltool/builtin.mk\"")

	mklines.Check()

	t.CheckOutputLines(
		"ERROR: ~/category/package/filename.mk:3: "+
			"../../pkgtools/x11-links/buildlink3.mk must not be included directly. "+
			"Include \"../../mk/x11.buildlink3.mk\" instead.",
		"ERROR: ~/category/package/filename.mk:4: "+
			"../../graphics/jpeg/buildlink3.mk must not be included directly. "+
			"Include \"../../mk/jpeg.buildlink3.mk\" instead.",
		"WARN: ~/category/package/filename.mk:5: "+
			"Please write \"USE_TOOLS+= intltool\" instead of this line.",
		"ERROR: ~/category/package/filename.mk:6: "+
			"../../devel/intltool/builtin.mk must not be included directly. "+
			"Include \"../../devel/intltool/buildlink3.mk\" instead.")
}

func (s *Suite) Test_MkLineChecker_checkInclude__Makefile(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines(t.File("Makefile"),
		MkCvsID,
		".include \"../../other/package/Makefile\"")

	mklines.Check()

	t.CheckOutputLines(
		"ERROR: ~/Makefile:2: Relative path \"../../other/package/Makefile\" does not exist.",
		"ERROR: ~/Makefile:2: Other Makefiles must not be included directly.")
}

func (s *Suite) Test_MkLineChecker_checkInclude__Makefile_exists(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("other/existing/Makefile")
	t.SetUpPackage("category/package",
		".include \"../../other/existing/Makefile\"",
		".include \"../../other/not-found/Makefile\"")
	t.FinishSetUp()

	G.checkdirPackage(t.File("category/package"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/Makefile:21: Cannot read \"../../other/not-found/Makefile\".")
}

func (s *Suite) Test_MkLineChecker_checkInclude__hacks(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/hacks.mk",
		MkCvsID,
		".include \"../../category/package/nonexistent.mk\"",
		".include \"../../category/package/builtin.mk\"")
	t.CreateFileLines("category/package/builtin.mk",
		MkCvsID)
	t.FinishSetUp()

	G.checkdirPackage(t.File("category/package"))

	// The purpose of this "nonexistent" diagnostic is only to show that
	// hacks.mk is indeed parsed and checked.
	t.CheckOutputLines(
		"ERROR: ~/category/package/hacks.mk:2: " +
			"Relative path \"../../category/package/nonexistent.mk\" does not exist.")
}

func (s *Suite) Test_MkLineChecker__permissions_in_hacks_mk(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_checkDirective(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("category/package/filename.mk",
		MkCvsID,
		"",
		".for",
		".endfor",
		"",
		".if",
		".else don't",
		".endif invalid-arg",
		"",
		".ifdef FNAME_MK",
		".endif",
		".ifndef FNAME_MK",
		".endif",
		"",
		".for var in a b c",
		".endfor",
		".undef var unrelated")

	mklines.Check()

	t.CheckOutputLines(
		"ERROR: category/package/filename.mk:3: \".for\" requires arguments.",
		"ERROR: category/package/filename.mk:6: \".if\" requires arguments.",
		"ERROR: category/package/filename.mk:7: \".else\" does not take arguments. "+
			"If you meant \"else if\", use \".elif\".",
		"ERROR: category/package/filename.mk:8: \".endif\" does not take arguments.",
		"WARN: category/package/filename.mk:10: The \".ifdef\" directive is deprecated. "+
			"Please use \".if defined(FNAME_MK)\" instead.",
		"WARN: category/package/filename.mk:12: The \".ifndef\" directive is deprecated. "+
			"Please use \".if !defined(FNAME_MK)\" instead.",
		"NOTE: category/package/filename.mk:17: Using \".undef\" after a \".for\" loop is unnecessary.")
}

func (s *Suite) Test_MkLineChecker_checkDirective__for_loop_varname(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"",
		".for VAR in a b c", // Should be lowercase.
		".endfor",
		"",
		".for _var_ in a b c", // Should be written without underscores.
		".endfor",
		"",
		".for .var. in a b c", // Should be written without dots.
		".endfor",
		"",
		".for ${VAR} in a b c", // The variable name really must be an identifier.
		".endfor")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:3: The variable name \"VAR\" in the .for loop should not contain uppercase letters.",
		"WARN: filename.mk:6: Variable names starting with an underscore (_var_) are reserved for internal pkgsrc use.",
		"ERROR: filename.mk:9: Invalid variable name \".var.\".",
		"ERROR: filename.mk:12: Invalid variable name \"${VAR}\".")
}

func (s *Suite) Test_MkLineChecker_checkDirectiveEnd__ending_comments(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("opsys.mk",
		MkCvsID,
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
		".endif # option", // Correct.
		"",
		".if ${PKG_OPTIONS:Moption}",
		".endif # opti", // This typo goes unnoticed since "opti" is a substring of the condition.
		"",
		".if ${OPSYS} == NetBSD",
		".elif ${OPSYS} == FreeBSD",
		".endif # NetBSD", // Wrong, should be FreeBSD from the .elif.
		"",
		".for ii in 1 2",
		".  for jj in 1 2",
		".  endfor # ii", // Note: a simple "i" would not generate a warning because it is found in the word "in".
		".endfor # ii")

	// See MkLineChecker.checkDirective
	mklines.Check()

	t.CheckOutputLines(
		"WARN: opsys.mk:7: Comment \"MACHINE_ARCH\" does not match condition \"${OS_VERSION:M8.*}\".",
		"WARN: opsys.mk:8: Comment \"OS_VERSION\" does not match condition \"${MACHINE_ARCH} == x86_64\".",
		"WARN: opsys.mk:10: Comment \"j\" does not match loop \"i in 1 2 3 4 5\".",
		"WARN: opsys.mk:12: Unknown option \"option\".",
		"WARN: opsys.mk:20: Comment \"NetBSD\" does not match condition \"${OPSYS} == FreeBSD\".",
		"WARN: opsys.mk:24: Comment \"ii\" does not match loop \"jj in 1 2\".")
}

// After removing the dummy indentation in commit d5a926af,
// there was a panic: runtime error: index out of range,
// in wip/jacorb-lib/buildlink3.mk.
func (s *Suite) Test_MkLineChecker_checkDirectiveEnd__unbalanced(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"",
		".endfor # comment",
		".endif # comment")

	mklines.Check()

	t.CheckOutputLines(
		"ERROR: filename.mk:3: Unmatched .endfor.",
		"ERROR: filename.mk:4: Unmatched .endif.")
}

func (s *Suite) Test_MkLineChecker_checkDirectiveFor(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("for.mk",
		MkCvsID,
		".for dir in ${PATH:C,:, ,g}",
		".endfor",
		"",
		".for dir in ${PATH}",
		".endfor",
		"",
		".for dir in ${PATH:M*/bin}",
		".endfor")

	mklines.Check()

	t.CheckOutputLines(
		// No warning about a missing :Q in line 2 since the :C modifier
		// converts the colon-separated list into a space-separated list,
		// as required by the .for loop.

		// This warning is correct since PATH is separated by colons, not by spaces.
		"WARN: for.mk:5: Please use ${PATH:Q} instead of ${PATH}.",

		// This warning is also correct since the :M modifier doesn't change the
		// word boundaries.
		"WARN: for.mk:8: Please use ${PATH:M*/bin:Q} instead of ${PATH:M*/bin}.")
}

func (s *Suite) Test_MkLineChecker_checkDirectiveFor__infrastructure(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/file.mk",
		MkCvsID,
		".for i = 1 2 3", // The "=" should rather be "in".
		".endfor",
		"",
		".for _i_ in 1 2 3", // Underscores are only allowed in infrastructure files.
		".endfor")
	t.FinishSetUp()

	G.Check(t.File("mk/file.mk"))

	// Pkglint doesn't care about trivial syntax errors like the "=" instead
	// of "in" above; bmake will already catch these.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLineChecker_checkDependencyRule(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("category/package/filename.mk",
		MkCvsID,
		"",
		".PHONY: target-1",
		"target-2: .PHONY",
		".ORDER: target-1 target-2",
		"target-1:",
		"target-2:",
		"target-3:")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: category/package/filename.mk:8: Undeclared target \"target-3\".")
}

func (s *Suite) Test_MkLineChecker_checkVartype__simple_type(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	// Since COMMENT is defined in vardefs.go its type is certain instead of guessed.
	vartype := G.Pkgsrc.VariableType(nil, "COMMENT")

	c.Assert(vartype, check.NotNil)
	c.Check(vartype.basicType.name, equals, "Comment")
	c.Check(vartype.Guessed(), equals, false)
	c.Check(vartype.List(), equals, false)

	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"COMMENT=\tA nice package")
	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:2: COMMENT should not begin with \"A\".")
}

func (s *Suite) Test_MkLineChecker_checkVartype(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"DISTNAME=\tgcc-${GCC_VERSION}")

	mklines.vars.Define("GCC_VERSION", mklines.mklines[1])
	mklines.Check()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLineChecker_checkVartype__append_to_non_list(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"DISTNAME+=\tsuffix",
		"COMMENT=\tComment for",
		"COMMENT+=\tthe package")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:2: The variable DISTNAME should not be appended to "+
			"(only set, or given a default value) in this file.",
		"WARN: filename.mk:2: The \"+=\" operator should only be used with lists, not with DISTNAME.")
}

func (s *Suite) Test_MkLineChecker_checkVartype__no_tracing(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"UNKNOWN=\tvalue",
		"CUR_DIR!=\tpwd")
	t.DisableTracing()

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:2: UNKNOWN is defined but not used.",
		"WARN: filename.mk:3: CUR_DIR is defined but not used.")
}

// Pkglint once interpreted all lists as consisting of shell tokens,
// splitting this URL at the ampersand.
func (s *Suite) Test_MkLineChecker_checkVarassign__URL_with_shell_special_characters(c *check.C) {
	t := s.Init(c)

	G.Pkg = NewPackage(t.File("graphics/gimp-fix-ca"))
	t.SetUpVartypes()
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"MASTER_SITES=\thttp://registry.gimp.org/file/fix-ca.c?action=download&id=9884&file=")

	mklines.Check()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLineChecker_checkVarassign__list(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_checkDirectiveCond(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	test := func(cond string, output ...string) {
		mklines := t.NewMkLines("filename.mk",
			cond)
		mklines.ForEach(func(mkline *MkLine) {
			MkLineChecker{mklines, mkline}.checkDirectiveCond()
		})
		t.CheckOutput(output)
	}

	test(
		".if !empty(PKGSRC_COMPILER:Mmycc)",
		"WARN: filename.mk:1: The pattern \"mycc\" cannot match any of "+
			"{ ccache ccc clang distcc f2c gcc hp icc ido "+
			"mipspro mipspro-ucode pcc sunpro xlc } for PKGSRC_COMPILER.")

	test(
		".elif ${A} != ${B}",
		"WARN: filename.mk:1: A is used but not defined.",
		"WARN: filename.mk:1: B is used but not defined.")

	test(".if ${HOMEPAGE} == \"mailto:someone@example.org\"",
		"WARN: filename.mk:1: \"mailto:someone@example.org\" is not a valid URL.",
		"WARN: filename.mk:1: HOMEPAGE should not be used at load time in any file.")

	test(".if !empty(PKGSRC_RUN_TEST:M[Y][eE][sS])",
		"WARN: filename.mk:1: PKGSRC_RUN_TEST should be matched "+
			"against \"[yY][eE][sS]\" or \"[nN][oO]\", not \"[Y][eE][sS]\".")

	test(".if !empty(IS_BUILTIN.Xfixes:M[yY][eE][sS])")

	test(".if !empty(${IS_BUILTIN.Xfixes:M[yY][eE][sS]})",
		"WARN: filename.mk:1: The empty() function takes a variable name as parameter, "+
			"not a variable expression.")

	test(".if ${PKGSRC_COMPILER} == \"msvc\"",
		"WARN: filename.mk:1: \"msvc\" is not valid for PKGSRC_COMPILER. "+
			"Use one of { ccache ccc clang distcc f2c gcc hp icc ido mipspro mipspro-ucode pcc sunpro xlc } instead.",
		"WARN: filename.mk:1: Use ${PKGSRC_COMPILER:Mmsvc} instead of the == operator.")

	test(".if ${PKG_LIBTOOL:Mlibtool}",
		"NOTE: filename.mk:1: PKG_LIBTOOL should be compared using == instead of matching against \":Mlibtool\".",
		"WARN: filename.mk:1: PKG_LIBTOOL should not be used at load time in any file.")

	test(".if ${MACHINE_PLATFORM:MUnknownOS-*-*} || ${MACHINE_ARCH:Mx86}",
		"WARN: filename.mk:1: "+
			"The pattern \"UnknownOS\" cannot match any of "+
			"{ AIX BSDOS Bitrig Cygwin Darwin DragonFly FreeBSD FreeMiNT GNUkFreeBSD HPUX Haiku "+
			"IRIX Interix Linux Minix MirBSD NetBSD OSF1 OpenBSD QNX SCO_SV SunOS UnixWare "+
			"} for the operating system part of MACHINE_PLATFORM.",
		"WARN: filename.mk:1: "+
			"The pattern \"x86\" cannot match any of "+
			"{ aarch64 aarch64eb alpha amd64 arc arm arm26 arm32 cobalt coldfire convex dreamcast earm "+
			"earmeb earmhf earmhfeb earmv4 earmv4eb earmv5 earmv5eb earmv6 earmv6eb earmv6hf earmv6hfeb "+
			"earmv7 earmv7eb earmv7hf earmv7hfeb evbarm hpcmips hpcsh hppa hppa64 i386 i586 i686 ia64 "+
			"m68000 m68k m88k mips mips64 mips64eb mips64el mipseb mipsel mipsn32 mlrisc ns32k pc532 pmax "+
			"powerpc powerpc64 rs6000 s390 sh3eb sh3el sparc sparc64 vax x86_64 "+
			"} for MACHINE_ARCH.",
		"NOTE: filename.mk:1: MACHINE_ARCH should be compared using == instead of matching against \":Mx86\".")

	test(".if ${MASTER_SITES:Mftp://*} == \"ftp://netbsd.org/\"",
		"WARN: filename.mk:1: Invalid variable modifier \"//*\" for \"MASTER_SITES\".",
		"WARN: filename.mk:1: \"ftp\" is not a valid URL.",
		"WARN: filename.mk:1: MASTER_SITES should not be used at load time in any file.",
		"WARN: filename.mk:1: Invalid variable modifier \"//*\" for \"MASTER_SITES\".")

	// The only interesting line from the below tracing output is the one
	// containing "checkCompareVarStr".
	t.EnableTracingToLog()
	test(".if ${VAR:Mpattern1:Mpattern2} == comparison",
		"TRACE:   Indentation before line 1: []",
		"TRACE: + MkLineChecker.checkDirectiveCond(\"${VAR:Mpattern1:Mpattern2} == comparison\")",
		"TRACE: 1 + (*MkParser).mkCondAtom(\"${VAR:Mpattern1:Mpattern2} == comparison\")",
		"TRACE: 1 - (*MkParser).mkCondAtom(\"${VAR:Mpattern1:Mpattern2} == comparison\")",
		"TRACE: 1   checkCompareVarStr ${VAR:Mpattern1:Mpattern2} == comparison",
		"TRACE: 1 + MkLineChecker.CheckVaruse(filename.mk:1, ${VAR:Mpattern1:Mpattern2}, (no-type time:load quoting:plain wordpart:false))",
		"TRACE: 1 2 + (*Pkgsrc).VariableType(\"VAR\")",
		"TRACE: 1 2 3   No type definition found for \"VAR\".",
		"TRACE: 1 2 - (*Pkgsrc).VariableType(\"VAR\", \"=>\", (*pkglint.Vartype)(nil))",
		"WARN: filename.mk:1: VAR is used but not defined.",
		"TRACE: 1 2 + MkLineChecker.checkVarusePermissions(\"VAR\", (no-type time:load quoting:plain wordpart:false))",
		"TRACE: 1 2 3   No type definition found for \"VAR\".",
		"TRACE: 1 2 - MkLineChecker.checkVarusePermissions(\"VAR\", (no-type time:load quoting:plain wordpart:false))",
		"TRACE: 1 2 + (*MkLine).VariableNeedsQuoting(${VAR:Mpattern1:Mpattern2}, (*pkglint.Vartype)(nil), (no-type time:load quoting:plain wordpart:false))",
		"TRACE: 1 2 - (*MkLine).VariableNeedsQuoting(${VAR:Mpattern1:Mpattern2}, (*pkglint.Vartype)(nil), (no-type time:load quoting:plain wordpart:false), \"=>\", unknown)",
		"TRACE: 1 - MkLineChecker.CheckVaruse(filename.mk:1, ${VAR:Mpattern1:Mpattern2}, (no-type time:load quoting:plain wordpart:false))",
		"TRACE: - MkLineChecker.checkDirectiveCond(\"${VAR:Mpattern1:Mpattern2} == comparison\")",
		"TRACE: + (*MkParser).mkCondAtom(\"${VAR:Mpattern1:Mpattern2} == comparison\")",
		"TRACE: - (*MkParser).mkCondAtom(\"${VAR:Mpattern1:Mpattern2} == comparison\")",
		"TRACE:   Indentation after line 1: [2 (VAR)]")
	t.EnableSilentTracing()
}

func (s *Suite) Test_MkLineChecker_checkVarassign(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"ac_cv_libpari_libs+=\t-L${BUILDLINK_PREFIX.pari}/lib") // From math/clisp-pari/Makefile, rev. 1.8

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:2: ac_cv_libpari_libs is defined but not used.")
}

func (s *Suite) Test_MkLineChecker_checkVarassignLeftPermissions(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("awk", "AWK", AtRunTime)
	G.Pkgsrc.vartypes.DefineParse("SET_ONLY", BtUnknown, NoVartypeOptions,
		"options.mk: set")
	G.Pkgsrc.vartypes.DefineParse("SET_ONLY_DEFAULT_ELSEWHERE", BtUnknown, NoVartypeOptions,
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

func (s *Suite) Test_MkLineChecker_checkVarassignLeftPermissions__no_tracing(c *check.C) {
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
func (s *Suite) Test_MkLineChecker_checkVarassignLeftPermissions__license_default(c *check.C) {
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
func (s *Suite) Test_MkLineChecker_checkVarassignLeftPermissions__infrastructure(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_checkVarassignLeftRationale(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_checkVarassignOpShell(c *check.C) {
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
		"show-package-vars: .PHONY",
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

func (s *Suite) Test_MkLineChecker_checkVarassignRightVaruse(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("module.mk",
		MkCvsID,
		"PLIST_SUBST+=\tLOCALBASE=${LOCALBASE:Q}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: module.mk:2: Please use PREFIX instead of LOCALBASE.",
		"NOTE: module.mk:2: The :Q operator isn't necessary for ${LOCALBASE} here.")
}

func (s *Suite) Test_MkLineChecker_checkVarusePermissions(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_checkVarusePermissions__explain(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_explainPermissions(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_checkVarusePermissions__load_time(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("options.mk",
		MkCvsID,
		"WRKSRC:=${.CURDIR}",
		".if ${PKG_SYSCONFDIR.gdm} != \"etc\"",
		".endif")

	mklines.Check()

	// Evaluating PKG_SYSCONFDIR.* at load time is probably ok,
	// though pkglint cannot prove anything here.
	//
	// Evaluating .CURDIR at load time is definitely ok since it is defined from the beginning.
	t.CheckOutputLines(
		"NOTE: options.mk:2: This variable value should be aligned to column 17.")
}

func (s *Suite) Test_MkLineChecker_checkVarusePermissions__load_time_in_condition(c *check.C) {
	t := s.Init(c)

	G.Pkgsrc.vartypes.DefineParse("LOAD_TIME", BtPathmask, List,
		"special:filename.mk: use-loadtime")
	G.Pkgsrc.vartypes.DefineParse("RUN_TIME", BtPathmask, List,
		"special:filename.mk: use")

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		".if ${LOAD_TIME} && ${RUN_TIME}",
		".endif")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:2: RUN_TIME should not be used at load time in any file.")
}

func (s *Suite) Test_MkLineChecker_checkVarusePermissions__load_time_in_for_loop(c *check.C) {
	t := s.Init(c)

	G.Pkgsrc.vartypes.DefineParse("LOAD_TIME", BtPathmask, List,
		"special:filename.mk: use-loadtime")
	G.Pkgsrc.vartypes.DefineParse("RUN_TIME", BtPathmask, List,
		"special:filename.mk: use")

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		".for pattern in ${LOAD_TIME} ${RUN_TIME}",
		".endfor")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:2: RUN_TIME should not be used at load time in any file.")
}

func (s *Suite) Test_MkLineChecker_checkVarusePermissions__load_time_guessed(c *check.C) {
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
func (s *Suite) Test_MkLineChecker_checkVarusePermissions__load_time_run_time(c *check.C) {
	t := s.Init(c)

	G.Pkgsrc.vartypes.DefineParse("LOAD_TIME", BtUnknown, NoVartypeOptions,
		"*.mk: use, use-loadtime")
	G.Pkgsrc.vartypes.DefineParse("RUN_TIME", BtUnknown, NoVartypeOptions,
		"*.mk: use")
	G.Pkgsrc.vartypes.DefineParse("WRITE_ONLY", BtUnknown, NoVartypeOptions,
		"*.mk: set")
	G.Pkgsrc.vartypes.DefineParse("LOAD_TIME_ELSEWHERE", BtUnknown, NoVartypeOptions,
		"Makefile: use-loadtime",
		"*.mk: set")
	G.Pkgsrc.vartypes.DefineParse("RUN_TIME_ELSEWHERE", BtUnknown, NoVartypeOptions,
		"Makefile: use",
		"*.mk: set")

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		".if ${LOAD_TIME} && ${RUN_TIME} && ${WRITE_ONLY}",
		".elif ${LOAD_TIME_ELSEWHERE} && ${RUN_TIME_ELSEWHERE}",
		".endif")

	mklines.Check()

	t.CheckOutputLines(
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

func (s *Suite) Test_MkLineChecker_checkVarusePermissions__PKGREVISION(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_checkVarusePermissions__indirectly(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("file.mk",
		MkCvsID,
		"IGNORE_PKG.package=\t${ONLY_FOR_UNPRIVILEGED}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: file.mk:2: IGNORE_PKG.package should be set to YES or yes.",
		"WARN: file.mk:2: ONLY_FOR_UNPRIVILEGED should not be used indirectly at load time (via IGNORE_PKG.package).")
}

// This test is only here for branch coverage.
// It does not demonstrate anything useful.
func (s *Suite) Test_MkLineChecker_checkVarusePermissions__indirectly_tool(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("file.mk",
		MkCvsID,
		"USE_TOOLS+=\t${PKGREVISION}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: file.mk:2: PKGREVISION should not be used in any file; it is a write-only variable.")
}

func (s *Suite) Test_MkLineChecker_checkVarusePermissions__write_only_usable_in_other_file(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_checkVarusePermissions__usable_only_at_loadtime_in_other_file(c *check.C) {
	t := s.Init(c)

	G.Pkgsrc.vartypes.DefineParse("VAR", BtFileName, NoVartypeOptions,
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

func (s *Suite) Test_MkLineChecker_checkVarusePermissions__assigned_to_infrastructure_variable(c *check.C) {
	t := s.Init(c)

	// This combination of BtUnknown and all permissions is typical for
	// otherwise unknown variables from the pkgsrc infrastructure.
	G.Pkgsrc.vartypes.Define("INFRA", BtUnknown, NoVartypeOptions,
		NewACLEntry("*", aclpAll))
	G.Pkgsrc.vartypes.DefineParse("VAR", BtUnknown, NoVartypeOptions,
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

func (s *Suite) Test_MkLineChecker_checkVarusePermissions__assigned_to_load_time(c *check.C) {
	t := s.Init(c)

	// LOAD_TIME may be used at load time in other.mk.
	// Since VAR must not be used at load time at all, it would be dangerous
	// to use its value in LOAD_TIME, as the latter might be evaluated later
	// at load time, and at that point VAR would be evaluated as well.

	G.Pkgsrc.vartypes.DefineParse("LOAD_TIME", BtMessage, NoVartypeOptions,
		"buildlink3.mk: set",
		"*.mk: use-loadtime")
	G.Pkgsrc.vartypes.DefineParse("VAR", BtUnknown, NoVartypeOptions,
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

func (s *Suite) Test_MkLineChecker_checkVarusePermissions__multiple_times_per_file(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_warnVarusePermissions__not_directly_and_no_alternative_files(c *check.C) {
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
	t.Check(toolDependsType.String(), equals, "DependencyWithPath (list, package-settable)")
	t.Check(toolDependsType.AlternativeFiles(aclpAppend), equals, "Makefile, Makefile.* or *.mk")
	t.Check(toolDependsType.AlternativeFiles(aclpUse), equals, "Makefile, Makefile.* or *.mk")
	t.Check(toolDependsType.AlternativeFiles(aclpUseLoadtime), equals, "")

	apiDependsType := G.Pkgsrc.VariableType(nil, "BUILDLINK_API_DEPENDS.*")
	t.Check(apiDependsType.String(), equals, "Dependency (list, package-settable)")
	t.Check(apiDependsType.AlternativeFiles(aclpUse), equals, "")
	t.Check(apiDependsType.AlternativeFiles(aclpUseLoadtime), equals, "buildlink3.mk or builtin.mk only")

	t.CheckOutputLines(
		"WARN: mk-c.mk:7: BUILDLINK_API_DEPENDS.mk-c should not be used in any file.",
		"WARN: mk-c.mk:7: The list variable BUILDLINK_API_DEPENDS.mk-c should not be embedded in a word.",
		"WARN: mk-c.mk:7: BUILDLINK_PKGSRCDIR.mk-c should not be used in any file.")
}

func (s *Suite) Test_MkLineChecker_checkVarassignDecreasingVersions(c *check.C) {
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

	// Half of these warnings are from VartypeCheck.Version, the
	// other half are from checkVarassignDecreasingVersions.
	// Strictly speaking some of them are redundant, but that would
	// mean to reject only variable references in checkVarassignDecreasingVersions.
	// This is probably ok.
	// TODO: Fix this.
	t.CheckOutputLines(
		"WARN: Makefile:2: Invalid version number \"__future__\".",
		"ERROR: Makefile:2: Value \"__future__\" for "+
			"PYTHON_VERSIONS_ACCEPTED must be a positive integer.",
		"WARN: Makefile:3: Invalid version number \"-13\".",
		"ERROR: Makefile:3: Value \"-13\" for "+
			"PYTHON_VERSIONS_ACCEPTED must be a positive integer.",
		"ERROR: Makefile:4: Value \"${PKGVERSION_NOREV}\" for "+
			"PYTHON_VERSIONS_ACCEPTED must be a positive integer.",
		"WARN: Makefile:5: The values for PYTHON_VERSIONS_ACCEPTED "+
			"should be in decreasing order (37 before 36).")
}

func (s *Suite) Test_MkLineChecker_warnVaruseToolLoadTime(c *check.C) {
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
func (s *Suite) Test_MkLineChecker_warnVaruseToolLoadTime__local_tool(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_Check__warn_varuse_LOCALBASE(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("options.mk",
		MkCvsID,
		"PKGNAME=\t${LOCALBASE}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: options.mk:2: Please use PREFIX instead of LOCALBASE.")
}

func (s *Suite) Test_MkLineChecker_CheckRelativePkgdir(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("other/package/Makefile")

	test := func(relativePkgdir string, diagnostics ...string) {
		// Must be in the filesystem because of directory references.
		mklines := t.SetUpFileMkLines("category/package/Makefile",
			"# dummy")

		checkRelativePkgdir := func(mkline *MkLine) {
			MkLineChecker{mklines, mkline}.CheckRelativePkgdir(relativePkgdir)
		}

		mklines.ForEach(checkRelativePkgdir)

		t.CheckOutput(diagnostics)
	}

	test("../pkgbase",
		"ERROR: ~/category/package/Makefile:1: Relative path \"../pkgbase/Makefile\" does not exist.",
		"WARN: ~/category/package/Makefile:1: \"../pkgbase\" is not a valid relative package directory.")

	test("../../other/package",
		nil...)

	test("../../other/does-not-exist",
		"ERROR: ~/category/package/Makefile:1: Relative path \"../../other/does-not-exist/Makefile\" does not exist.")
}

// PR pkg/46570, item 2
func (s *Suite) Test_MkLineChecker__unclosed_varuse(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"EGDIRS=\t${EGDIR/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:2: Missing closing \"}\" for \"EGDIR/pam.d\".",
		"WARN: Makefile:2: Invalid part \"/pam.d\" after variable name \"EGDIR\".",
		"WARN: Makefile:2: Missing closing \"}\" for \"EGDIR/dbus-1/system.d ${EGDIR/pam.d\".",
		"WARN: Makefile:2: Invalid part \"/dbus-1/system.d ${EGDIR/pam.d\" after variable name \"EGDIR\".",
		"WARN: Makefile:2: Missing closing \"}\" for \"EGDIR/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d\".",
		"WARN: Makefile:2: Invalid part \"/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d\" after variable name \"EGDIR\".",
		"WARN: Makefile:2: EGDIRS is defined but not used.",
		"WARN: Makefile:2: EGDIR/pam.d is used but not defined.")
}

func (s *Suite) Test_MkLineChecker_Check__varuse_modifier_L(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("x11/xkeyboard-config/Makefile",
		"FILES_SUBST+=XKBCOMP_SYMLINK=${${XKBBASE}/xkbcomp:L:Q}",
		"FILES_SUBST+=XKBCOMP_SYMLINK=${${XKBBASE}/xkbcomp:Q}")

	MkLineChecker{mklines, mklines.mklines[0]}.Check()
	MkLineChecker{mklines, mklines.mklines[1]}.Check()

	// In line 1, don't warn that ${XKBBASE}/xkbcomp is used but not defined.
	// This is because the :L modifier interprets everything before as an expression
	// instead of a variable name.
	//
	// In line 2 the :L modifier is missing, therefore ${XKBBASE}/xkbcomp is the
	// name of another variable, and that variable is not known. Only XKBBASE is known.
	//
	// In line 2, warn about the invalid "/" as part of the variable name.
	t.CheckOutputLines(
		"WARN: x11/xkeyboard-config/Makefile:2: "+
			"Invalid part \"/xkbcomp\" after variable name \"${XKBBASE}\".",
		"WARN: x11/xkeyboard-config/Makefile:2: XKBBASE is used but not defined.")
}

func (s *Suite) Test_MkLineChecker_checkDirectiveCond__comparison_with_shell_command(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("security/openssl/Makefile",
		MkCvsID,
		".if ${PKGSRC_COMPILER} == \"gcc\" && ${CC} == \"cc\"",
		".endif")

	mklines.Check()

	// Don't warn about unknown shell command "cc".
	t.CheckOutputLines(
		"WARN: security/openssl/Makefile:2: Use ${PKGSRC_COMPILER:Mgcc} instead of the == operator.")
}

// The :N modifier filters unwanted values. After this filter, any variable value
// may be compared with the empty string, regardless of the variable type.
// Effectively, the :N modifier changes the type from T to Option(T).
func (s *Suite) Test_MkLineChecker_checkDirectiveCond__compare_pattern_with_empty(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		".if ${X11BASE:Npattern} == \"\"",
		".endif",
		"",
		".if ${X11BASE:N<>} == \"*\"",
		".endif",
		"",
		".if !(${OPSYS:M*BSD} != \"\")",
		".endif")

	mklines.Check()

	// TODO: There should be a warning about "<>" containing invalid
	//  characters for a path. See VartypeCheck.Pathname
	t.CheckOutputLines(
		"WARN: filename.mk:5: The pathname pattern \"<>\" contains the invalid characters \"<>\".",
		"WARN: filename.mk:5: The pathname \"*\" contains the invalid character \"*\".")
}

func (s *Suite) Test_MkLineChecker_checkDirectiveCondEmpty(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.Chdir(".")

	test := func(before string, diagnosticsAndAfter ...string) {

		mklines := t.SetUpFileMkLines("module.mk",
			MkCvsID,
			before,
			".endif")
		ck := MkLineChecker{mklines, mklines.mklines[1]}

		t.SetUpCommandLine("-Wall")
		ck.checkDirectiveCond()

		t.SetUpCommandLine("-Wall", "--autofix")
		ck.checkDirectiveCond()

		mklines.SaveAutofixChanges()
		afterMklines := t.LoadMkInclude("module.mk")

		if len(diagnosticsAndAfter) > 0 {
			diagLen := len(diagnosticsAndAfter)
			diagnostics := diagnosticsAndAfter[:diagLen-1]
			after := diagnosticsAndAfter[diagLen-1]

			t.CheckOutput(diagnostics)
			t.Check(afterMklines.mklines[1].Text, equals, after)
		} else {
			t.CheckOutputEmpty()
		}
	}

	test(
		".if ${PKGPATH:Mpattern}",

		"NOTE: module.mk:2: PKGPATH should be compared using == instead of matching against \":Mpattern\".",
		"AUTOFIX: module.mk:2: Replacing \"${PKGPATH:Mpattern}\" with \"${PKGPATH} == pattern\".",

		".if ${PKGPATH} == pattern")

	// When the pattern contains placeholders, it cannot be converted to == or !=.
	test(
		".if ${PKGPATH:Mpa*n}",
		nil...)

	// The :tl modifier prevents the autofix.
	test(
		".if ${PKGPATH:tl:Mpattern}",

		"NOTE: module.mk:2: PKGPATH should be compared using == instead of matching against \":Mpattern\".",

		".if ${PKGPATH:tl:Mpattern}")

	test(
		".if ${PKGPATH:Ncategory/package}",

		"NOTE: module.mk:2: PKGPATH should be compared using != instead of matching against \":Ncategory/package\".",
		"AUTOFIX: module.mk:2: Replacing \"${PKGPATH:Ncategory/package}\" with \"${PKGPATH} != category/package\".",

		".if ${PKGPATH} != category/package")

	// ${PKGPATH:None:Ntwo} is a short variant of ${PKGPATH} != "one" &&
	// ${PKGPATH} != "two". Applying the transformation would make the
	// condition longer than before, therefore nothing is done here.
	test(
		".if ${PKGPATH:None:Ntwo}",
		nil...)

	// Note: this combination doesn't make sense since the patterns "one" and "two" don't overlap.
	test(".if ${PKGPATH:Mone:Mtwo}",

		"NOTE: module.mk:2: PKGPATH should be compared using == instead of matching against \":Mone\".",
		"NOTE: module.mk:2: PKGPATH should be compared using == instead of matching against \":Mtwo\".",

		".if ${PKGPATH:Mone:Mtwo}")

	test(".if !empty(PKGPATH:Mpattern)",

		"NOTE: module.mk:2: PKGPATH should be compared using == instead of matching against \":Mpattern\".",
		"AUTOFIX: module.mk:2: Replacing \"!empty(PKGPATH:Mpattern)\" with \"${PKGPATH} == pattern\".",

		".if ${PKGPATH} == pattern")

	test(".if empty(PKGPATH:Mpattern)",

		"NOTE: module.mk:2: PKGPATH should be compared using != instead of matching against \":Mpattern\".",
		"AUTOFIX: module.mk:2: Replacing \"empty(PKGPATH:Mpattern)\" with \"${PKGPATH} != pattern\".",

		".if ${PKGPATH} != pattern")

	test(".if !!empty(PKGPATH:Mpattern)",

		// TODO: When taking all the ! into account, this is actually a
		//  test for emptiness, therefore the diagnostics should suggest
		//  the != operator instead of ==.
		"NOTE: module.mk:2: PKGPATH should be compared using == instead of matching against \":Mpattern\".",
		"AUTOFIX: module.mk:2: Replacing \"!empty(PKGPATH:Mpattern)\" with \"(${PKGPATH} == pattern)\".",

		// TODO: This condition could be simplified even more.
		//  Luckily the !! pattern doesn't occur in practice.
		".if !(${PKGPATH} == pattern)")

	test(".if empty(PKGPATH:Mpattern) || 0",

		"NOTE: module.mk:2: PKGPATH should be compared using != instead of matching against \":Mpattern\".",
		"AUTOFIX: module.mk:2: Replacing \"empty(PKGPATH:Mpattern)\" with \"(${PKGPATH} != pattern)\".",

		".if (${PKGPATH} != pattern) || 0")

	// No note in this case since there is no implicit !empty around the varUse.
	test(".if ${PKGPATH:Mpattern} != ${OTHER}",

		"WARN: module.mk:2: OTHER is used but not defined.",

		".if ${PKGPATH:Mpattern} != ${OTHER}")

	test(
		".if ${PKGPATH:Mpattern}",

		"NOTE: module.mk:2: PKGPATH should be compared using == instead of matching against \":Mpattern\".",
		"AUTOFIX: module.mk:2: Replacing \"${PKGPATH:Mpattern}\" with \"${PKGPATH} == pattern\".",

		".if ${PKGPATH} == pattern")

	test(
		".if !${PKGPATH:Mpattern}",

		"NOTE: module.mk:2: PKGPATH should be compared using != instead of matching against \":Mpattern\".",
		"AUTOFIX: module.mk:2: Replacing \"!${PKGPATH:Mpattern}\" with \"${PKGPATH} != pattern\".",

		".if ${PKGPATH} != pattern")

	test(
		".if !!${PKGPATH:Mpattern}",

		"NOTE: module.mk:2: PKGPATH should be compared using != instead of matching against \":Mpattern\".",
		"AUTOFIX: module.mk:2: Replacing \"!${PKGPATH:Mpattern}\" with \"(${PKGPATH} != pattern)\".",

		".if !(${PKGPATH} != pattern)")

	// This pattern with spaces doesn't make sense at all in the :M
	// modifier since it can never match.
	// Or can it, if the PKGPATH contains quotes?
	// How exactly does bmake apply the matching here, are both values unquoted?
	test(
		".if ${PKGPATH:Mpattern with spaces}",

		"WARN: module.mk:2: The pathname pattern \"pattern with spaces\" contains the invalid characters \"  \".",

		".if ${PKGPATH:Mpattern with spaces}")
	// TODO: ".if ${PKGPATH} == \"pattern with spaces\"")

	test(
		".if ${PKGPATH:M'pattern with spaces'}",

		"WARN: module.mk:2: The pathname pattern \"'pattern with spaces'\" contains the invalid characters \"'  '\".",

		".if ${PKGPATH:M'pattern with spaces'}")
	// TODO: ".if ${PKGPATH} == 'pattern with spaces'")

	test(
		".if ${PKGPATH:M&&}",

		"WARN: module.mk:2: The pathname pattern \"&&\" contains the invalid characters \"&&\".",

		".if ${PKGPATH:M&&}")
	// TODO: ".if ${PKGPATH} == '&&'")

	// If PKGPATH is "", the condition is false.
	// If PKGPATH is "negative-pattern", the condition is false.
	// In all other cases, the condition is true.
	//
	// Therefore this condition cannot simply be transformed into
	// ${PKGPATH} != negative-pattern, since that would produce a
	// different result in the case where PKGPATH is empty.
	//
	// For system-provided variables that are guaranteed to be non-empty,
	// such as OPSYS or PKGPATH, this replacement is valid.
	// These variables are only guaranteed to be defined after bsd.prefs.mk
	// has been included, like everywhere else.
	test(
		".if ${PKGPATH:Nnegative-pattern}",

		"NOTE: module.mk:2: PKGPATH should be compared using != instead of matching against \":Nnegative-pattern\".",
		"AUTOFIX: module.mk:2: Replacing \"${PKGPATH:Nnegative-pattern}\" with \"${PKGPATH} != negative-pattern\".",

		".if ${PKGPATH} != negative-pattern")

	// Since UNKNOWN is not a well-known system-provided variable that is
	// guaranteed to be non-empty (see the previous example), it is not
	// transformed at all.
	test(
		".if ${UNKNOWN:Nnegative-pattern}",

		"WARN: module.mk:2: UNKNOWN is used but not defined.",

		".if ${UNKNOWN:Nnegative-pattern}")

	test(
		".if ${PKGPATH:Mpath1} || ${PKGPATH:Mpath2}",

		"NOTE: module.mk:2: PKGPATH should be compared using == instead of matching against \":Mpath1\".",
		"NOTE: module.mk:2: PKGPATH should be compared using == instead of matching against \":Mpath2\".",
		"AUTOFIX: module.mk:2: Replacing \"${PKGPATH:Mpath1}\" with \"(${PKGPATH} == path1)\".",
		"AUTOFIX: module.mk:2: Replacing \"${PKGPATH:Mpath2}\" with \"(${PKGPATH} == path2)\".",

		// TODO: remove the redundant parentheses
		".if (${PKGPATH} == path1) || (${PKGPATH} == path2)")

	test(
		".if (((((${PKGPATH:Mpath})))))",

		"NOTE: module.mk:2: PKGPATH should be compared using == instead of matching against \":Mpath\".",
		"AUTOFIX: module.mk:2: Replacing \"${PKGPATH:Mpath}\" with \"${PKGPATH} == path\".",

		".if (((((${PKGPATH} == path)))))")
}

func (s *Suite) Test_MkLineChecker_checkDirectiveCond__comparing_PKGSRC_COMPILER_with_eqeq(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		".if ${PKGSRC_COMPILER} == \"clang\"",
		".elif ${PKGSRC_COMPILER} != \"gcc\"",
		".endif")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:2: Use ${PKGSRC_COMPILER:Mclang} instead of the == operator.",
		"WARN: Makefile:3: Use ${PKGSRC_COMPILER:Ngcc} instead of the != operator.")
}

func (s *Suite) Test_MkLineChecker_checkDirectiveCondCompareVarStr__no_tracing(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("filename.mk",
		".if ${DISTFILES:Mpattern:O:u} == NetBSD")
	t.DisableTracing()

	ck := MkLineChecker{mklines, mklines.mklines[0]}
	varUse := NewMkVarUse("DISTFILES", "Mpattern", "O", "u")
	ck.checkDirectiveCondCompareVarStr(varUse, "==", "distfile-1.0.tar.gz")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLineChecker_checkVartype__CFLAGS_with_backticks(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("chat/pidgin-icb/Makefile",
		MkCvsID,
		"CFLAGS+=\t`pkg-config pidgin --cflags`")
	mkline := mklines.mklines[1]

	words := mkline.Fields()

	c.Check(words, deepEquals, []string{"`pkg-config pidgin --cflags`"})

	ck := MkLineChecker{mklines, mklines.mklines[1]}
	ck.checkVartype("CFLAGS", opAssignAppend, "`pkg-config pidgin --cflags`", "")

	// No warning about "`pkg-config" being an unknown CFlag.
	t.CheckOutputEmpty()
}

// See PR 46570, Ctrl+F "4. Shell quoting".
// Pkglint is correct, since the shell sees this definition for
// CPPFLAGS as three words, not one word.
func (s *Suite) Test_MkLineChecker_checkVartype__CFLAGS(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"CPPFLAGS.SunOS+=\t-DPIPECOMMAND=\\\"/usr/sbin/sendmail -bs %s\\\"")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:2: Compiler flag \"-DPIPECOMMAND=\\\\\\\"/usr/sbin/sendmail\" has unbalanced double quotes.",
		"WARN: Makefile:2: Compiler flag \"%s\\\\\\\"\" has unbalanced double quotes.")
}

func (s *Suite) Test_MkLineChecker_checkDirectiveIndentation__autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--autofix", "-Wspace")
	lines := t.SetUpFileLines("filename.mk",
		MkCvsID,
		".if defined(A)",
		".for a in ${A}",
		".if defined(C)",
		".endif",
		".endfor",
		".endif")
	mklines := NewMkLines(lines)

	mklines.Check()

	t.CheckOutputLines(
		"AUTOFIX: ~/filename.mk:3: Replacing \".\" with \".  \".",
		"AUTOFIX: ~/filename.mk:4: Replacing \".\" with \".    \".",
		"AUTOFIX: ~/filename.mk:5: Replacing \".\" with \".    \".",
		"AUTOFIX: ~/filename.mk:6: Replacing \".\" with \".  \".")
	t.CheckFileLines("filename.mk",
		"# $"+"NetBSD$",
		".if defined(A)",
		".  for a in ${A}",
		".    if defined(C)",
		".    endif",
		".  endfor",
		".endif")
}

// Up to 2018-01-28, pkglint applied the autofix also to the continuation
// lines, which is incorrect. It replaced the dot in "4.*" with spaces.
func (s *Suite) Test_MkLineChecker_checkDirectiveIndentation__autofix_multiline(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--autofix")
	t.SetUpVartypes()
	mklines := t.SetUpFileMkLines("options.mk",
		MkCvsID,
		".if ${PKGNAME} == pkgname",
		".if \\",
		"   ${PLATFORM:MNetBSD-4.*}",
		".endif",
		".endif")

	mklines.Check()

	t.CheckOutputLines(
		"AUTOFIX: ~/options.mk:3: Replacing \".\" with \".  \".",
		"AUTOFIX: ~/options.mk:5: Replacing \".\" with \".  \".")

	t.CheckFileLines("options.mk",
		MkCvsID,
		".if ${PKGNAME} == pkgname",
		".  if \\",
		"   ${PLATFORM:MNetBSD-4.*}",
		".  endif",
		".endif")
}

func (s *Suite) Test_MkLineChecker_checkVarUseQuoting(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.SetUpFileMkLines("options.mk",
		MkCvsID,
		"GOPATH=\t${WRKDIR}",
		"do-build:",
		"\tcd ${WRKSRC} && GOPATH=${GOPATH} PATH=${PATH} :")

	mklines.Check()

	// For WRKSRC and GOPATH, no quoting is necessary since pkgsrc directories by
	// definition don't contain special characters. Therefore they don't need the
	// :Q, not even when used as part of a shell word.

	// For PATH, the quoting is necessary because it may contain directories outside
	// of pkgsrc, and these may contain special characters.

	t.CheckOutputLines(
		"WARN: ~/options.mk:4: The variable PATH should be quoted as part of a shell word.")
}

func (s *Suite) Test_MkLineChecker_checkVarUseQuoting__mstar(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall,no-space")
	t.SetUpVartypes()
	mklines := t.SetUpFileMkLines("options.mk",
		MkCvsID,
		"CONFIGURE_ARGS+=        CFLAGS=${CFLAGS:Q}",
		"CONFIGURE_ARGS+=        CFLAGS=${CFLAGS:M*:Q}",
		"CONFIGURE_ARGS+=        ADA_FLAGS=${ADA_FLAGS:Q}",
		"CONFIGURE_ARGS+=        ADA_FLAGS=${ADA_FLAGS:M*:Q}",
		"CONFIGURE_ENV+=         CFLAGS=${CFLAGS:Q}",
		"CONFIGURE_ENV+=         CFLAGS=${CFLAGS:M*:Q}",
		"CONFIGURE_ENV+=         ADA_FLAGS=${ADA_FLAGS:Q}",
		"CONFIGURE_ENV+=         ADA_FLAGS=${ADA_FLAGS:M*:Q}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/options.mk:2: Please use ${CFLAGS:M*:Q} instead of ${CFLAGS:Q}.",
		"WARN: ~/options.mk:4: ADA_FLAGS is used but not defined.",
		"WARN: ~/options.mk:6: Please use ${CFLAGS:M*:Q} instead of ${CFLAGS:Q}.")
}

func (s *Suite) Test_MkLineChecker_checkVarUseQuoting__mstar_not_needed(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall,no-space")
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

func (s *Suite) Test_MkLineChecker_checkVarUseQuoting__q_not_needed(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"MASTER_SITES=\t${HOMEPAGE:Q}")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:6: The :Q operator isn't necessary for ${HOMEPAGE} here.")
}

func (s *Suite) Test_MkLineChecker_checkVarUseQuoting__undefined_list_in_word_in_shell_command(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_checkVarUseQuoting__list_variable_with_single_constant_value(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_checkVarUseQuoting__list_variable_with_single_conditional_value(c *check.C) {
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
	//  variable, contains only a single value.
	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:26: " +
			"The list variable BUILD_DIRS should not be embedded in a word.")
}

func (s *Suite) Test_MkLineChecker_checkVarUseQuoting__list_variable_with_two_constant_words(c *check.C) {
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

// The ${VARNAME:=suffix} expression should only be used with lists.
// It typically appears in MASTER_SITE definitions.
func (s *Suite) Test_MkLineChecker_CheckVaruse__eq_nonlist(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_CheckVaruse__for(c *check.C) {
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
func (s *Suite) Test_MkLineChecker_CheckVaruse__varcanon(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/sys-vars.mk",
		MkCvsID,
		"CPPPATH.Linux=\t/usr/bin/cpp")
	t.FinishSetUp()

	mklines := t.NewMkLines("module.mk",
		MkCvsID,
		"COMMENT=\t${CPPPATH.SunOS}")

	ck := MkLineChecker{mklines, mklines.mklines[1]}

	ck.CheckVaruse(NewMkVarUse("CPPPATH.SunOS"), &VarUseContext{
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
func (s *Suite) Test_MkLineChecker_CheckVaruse__defined_in_infrastructure(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_CheckVaruse__build_defs(c *check.C) {
	t := s.Init(c)

	// XXX: This paragraph should not be necessary since VARBASE and X11_TYPE
	// are also defined in vardefs.go.
	t.SetUpPkgsrc()
	t.CreateFileLines("mk/defaults/mk.conf",
		"VARBASE?= /usr/pkg/var")
	t.SetUpCommandLine("-Wall,no-space")
	t.FinishSetUp()

	mklines := t.SetUpFileMkLines("options.mk",
		MkCvsID,
		"COMMENT=                ${VARBASE} ${X11_TYPE}",
		"PKG_FAIL_REASON+=       ${VARBASE} ${X11_TYPE}",
		"BUILD_DEFS+=            X11_TYPE")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/options.mk:2: The user-defined variable VARBASE is used but not added to BUILD_DEFS.")
}

// The LOCALBASE variable may be defined and used in the infrastructure.
// It is always equivalent to PREFIX and only exists for historic reasons.
func (s *Suite) Test_MkLineChecker_CheckVaruse__LOCALBASE_in_infrastructure(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_CheckVaruse__user_defined_variable_and_BUILD_DEFS(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_checkVaruseModifiersSuffix(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("file.mk",
		MkCvsID,
		"\t: ${HOMEPAGE:=subdir/:Q}", // wrong
		"\t: ${BUILD_DIRS:=subdir/}", // correct
		"\t: ${BIN_PROGRAMS:=.exe}")  // unknown since BIN_PROGRAMS doesn't have a type

	mklines.Check()

	t.CheckOutputLines(
		"WARN: file.mk:2: The :from=to modifier should only be used with lists, not with HOMEPAGE.",
		"WARN: file.mk:4: BIN_PROGRAMS is used but not defined.")
}

func (s *Suite) Test_MkLineChecker_checkVaruseModifiersRange(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_CheckVaruse__deprecated_PKG_DEBUG(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	G.Pkgsrc.initDeprecatedVars()

	mklines := t.NewMkLines("module.mk",
		MkCvsID,
		"\t${_PKG_SILENT}${_PKG_DEBUG} :")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: module.mk:2: Use of _PKG_SILENT and _PKG_DEBUG is deprecated. Use ${RUN} instead.")
}

func (s *Suite) Test_MkLineChecker_checkVaruseUndefined(c *check.C) {
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
func (s *Suite) Test_MkLineChecker_checkVaruseUndefined__indirect_variables(c *check.C) {
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
func (s *Suite) Test_MkLineChecker_checkVaruseUndefined__documented(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_checkVarassignMisc(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.SetUpMasterSite("MASTER_SITE_GITHUB", "https://download.github.com/")
	t.SetUpCommandLine("-Wall,no-space")
	mklines := t.SetUpFileMkLines("module.mk",
		MkCvsID,
		"EGDIR=                  ${PREFIX}/etc/rc.d",
		"RPMIGNOREPATH+=         ${PREFIX}/etc/rc.d",
		"_TOOLS_VARNAME.sed=     SED",
		"DIST_SUBDIR=            ${PKGNAME}",
		"WRKSRC=                 ${PKGNAME}",
		"SITES_distfile.tar.gz=  ${MASTER_SITE_GITHUB:=user/}",
		"MASTER_SITES=           https://cdn.example.org/${PKGNAME}/",
		"MASTER_SITES=           https://cdn.example.org/distname-${PKGVERSION}/")
	t.FinishSetUp()

	mklines.Check()

	// TODO: Split this test into several, one for each topic.
	t.CheckOutputLines(
		"WARN: ~/module.mk:2: Please use the RCD_SCRIPTS mechanism to install rc.d scripts automatically to ${RCD_SCRIPTS_EXAMPLEDIR}.",
		"WARN: ~/module.mk:4: Variable names starting with an underscore (_TOOLS_VARNAME.sed) are reserved for internal pkgsrc use.",
		"WARN: ~/module.mk:4: _TOOLS_VARNAME.sed is defined but not used.",
		"WARN: ~/module.mk:5: PKGNAME should not be used in DIST_SUBDIR as it includes the PKGREVISION. Please use PKGNAME_NOREV instead.",
		"WARN: ~/module.mk:6: PKGNAME should not be used in WRKSRC as it includes the PKGREVISION. Please use PKGNAME_NOREV instead.",
		"WARN: ~/module.mk:7: SITES_distfile.tar.gz is defined but not used.",
		"WARN: ~/module.mk:7: SITES_* is deprecated. Please use SITES.* instead.",
		"WARN: ~/module.mk:8: PKGNAME should not be used in MASTER_SITES as it includes the PKGREVISION. Please use PKGNAME_NOREV instead.",
		"WARN: ~/module.mk:9: PKGVERSION should not be used in MASTER_SITES as it includes the PKGREVISION. Please use PKGVERSION_NOREV instead.")
}

func (s *Suite) Test_MkLineChecker_checkVarassignMisc__multiple_inclusion_guards(c *check.C) {
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

func (s *Suite) Test_MkLineChecker_checkText(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()

	t.SetUpCommandLine("-Wall,no-space")
	mklines := t.SetUpFileMkLines("module.mk",
		MkCvsID,
		"CFLAGS+=                -Wl,--rpath,${PREFIX}/lib",
		"PKG_FAIL_REASON+=       \"Group ${GAMEGRP} doesn't exist.\"")
	t.FinishSetUp()

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/module.mk:2: Please use ${COMPILER_RPATH_FLAG} instead of \"-Wl,--rpath,\".",
		"WARN: ~/module.mk:3: Use of \"GAMEGRP\" is deprecated. Use GAMES_GROUP instead.")
}

func (s *Suite) Test_MkLineChecker_checkText__WRKSRC(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	mklines := t.SetUpFileMkLines("module.mk",
		MkCvsID,
		"pre-configure:",
		"\tcd ${WRKSRC}/..")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/module.mk:3: Building the package should take place entirely inside ${WRKSRC}, not \"${WRKSRC}/..\".",
		"",
		"\tWRKSRC should be defined so that there is no need to do anything",
		"\toutside of this directory.",
		"",
		"\tExample:",
		"",
		"\t\tWRKSRC=\t${WRKDIR}",
		"\t\tCONFIGURE_DIRS=\t${WRKSRC}/lib ${WRKSRC}/src",
		"\t\tBUILD_DIRS=\t${WRKSRC}/lib ${WRKSRC}/src ${WRKSRC}/cmd",
		"",
		"\tSee the pkgsrc guide, section \"Directories used during the build",
		"\tprocess\":",
		"\thttps://www.NetBSD.org/docs/pkgsrc/pkgsrc.html#build.builddirs",
		"",
		"WARN: ~/module.mk:3: WRKSRC is used but not defined.")
}

func (s *Suite) Test_MkLineChecker_CheckRelativePath(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("wip/package/Makefile")
	t.CreateFileLines("wip/package/module.mk")
	mklines := t.SetUpFileMkLines("category/package/module.mk",
		MkCvsID,
		"DEPENDS+=       wip-package-[0-9]*:../../wip/package",
		".include \"../../wip/package/module.mk\"",
		"",
		"DEPENDS+=       unresolvable-[0-9]*:../../lang/${LATEST_PYTHON}",
		".include \"../../lang/${LATEST_PYTHON}/module.mk\"",
		"",
		".include \"module.mk\"",
		".include \"../../category/../category/package/module.mk\"", // Oops
		".include \"../../mk/bsd.prefs.mk\"",
		".include \"../package/module.mk\"",
		// TODO: warn about this as well, since ${.CURDIR} is essentially
		//  equivalent to ".".
		".include \"${.CURDIR}/../package/module.mk\"")
	t.FinishSetUp()

	mklines.Check()

	t.CheckOutputLines(
		"ERROR: ~/category/package/module.mk:2: A main pkgsrc package must not depend on a pkgsrc-wip package.",
		"ERROR: ~/category/package/module.mk:3: A main pkgsrc package must not depend on a pkgsrc-wip package.",
		"WARN: ~/category/package/module.mk:5: LATEST_PYTHON is used but not defined.",
		"WARN: ~/category/package/module.mk:11: References to other packages should "+
			"look like \"../../category/package\", not \"../package\".",
		"WARN: ~/category/package/module.mk:12: References to other packages should "+
			"look like \"../../category/package\", not \"../package\".")
}

func (s *Suite) Test_MkLineChecker_CheckRelativePath__absolute_path(c *check.C) {
	t := s.Init(c)

	absDir := ifelseStr(runtime.GOOS == "windows", "C:/", "/")
	// Just a random UUID, to really guarantee that the file does not exist.
	absPath := absDir + "0f5c2d56-8a7a-4c9d-9caa-859b52bbc8c7"

	t.SetUpPkgsrc()
	mklines := t.SetUpFileMkLines("category/package/module.mk",
		MkCvsID,
		"DISTINFO_FILE=\t"+absPath)
	t.FinishSetUp()

	mklines.Check()

	t.CheckOutputLines(
		"ERROR: ~/category/package/module.mk:2: The path \"" + absPath + "\" must be relative.")
}

func (s *Suite) Test_MkLineChecker_CheckRelativePath__include_if_exists(c *check.C) {
	t := s.Init(c)

	mklines := t.SetUpFileMkLines("filename.mk",
		MkCvsID,
		".include \"included.mk\"",
		".sinclude \"included.mk\"")

	mklines.Check()

	// There is no warning for line 3 because of the "s" in "sinclude".
	t.CheckOutputLines(
		"ERROR: ~/filename.mk:2: Relative path \"included.mk\" does not exist.")
}

func (s *Suite) Test_MkLineChecker_CheckRelativePath__wip_mk(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("wip/mk/git-package.mk",
		MkCvsID)
	t.CreateFileLines("wip/other/version.mk",
		MkCvsID)
	t.SetUpPackage("wip/package",
		".include \"../mk/git-package.mk\"",
		".include \"../other/version.mk\"")
	t.FinishSetUp()

	G.Check(t.File("wip/package"))

	t.CheckOutputLines(
		"WARN: ~/wip/package/Makefile:20: References to the pkgsrc-wip "+
			"infrastructure should look like \"../../wip/mk\", not \"../mk\".",
		"WARN: ~/wip/package/Makefile:21: References to other packages "+
			"should look like \"../../category/package\", not \"../package\".")
}
