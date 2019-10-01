package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_VargroupsChecker__typo_in_group_name(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"_VARGROUPS+=\t\tgroup",
		"_DEF_VARS.typo=\t\t# none",
		"_LISTED_VARS.typo=\t# none")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:4: Expected _DEF_VARS.group, but found \"typo\".",
		"WARN: Makefile:5: Expected _LISTED_VARS.group, but found \"typo\".")
}

func (s *Suite) Test_VargroupsChecker__duplicate_variable_name(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"_VARGROUPS+=\t\tgroup",
		"_USER_VARS.group=\tVAR",
		"_PKG_VARS.group=\tVAR",
		"_SYS_VARS.group=\tVAR",
		"_DEF_VARS.group=\tVAR",
		"_USE_VARS.group=\tVAR",
		"_IGN_VARS.group=\tVAR",
		"_SORTED_VARS.group=\tVAR",
		"_LISTED_VARS.group=\tVAR",
		"",
		"VAR=\t${VAR}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:5: Duplicate variable name VAR, already appeared in line 4.",
		"WARN: Makefile:6: Duplicate variable name VAR, already appeared in line 4.",
		"WARN: Makefile:7: Duplicate variable name VAR, already appeared in line 4.",
		"WARN: Makefile:8: Duplicate variable name VAR, already appeared in line 4.",
		"WARN: Makefile:9: Duplicate variable name VAR, already appeared in line 4.")
}

func (s *Suite) Test_VargroupsChecker__variable_reference(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"_VARGROUPS+=\t\tgroup",
		"_USER_VARS.group=\t${:Uparam:@param@VAR.${param}@}",
		"_LISTED_VARS.group=\t${:Uparam:@param@VAR.${param}@}",
		"",
		"VAR.param=\tvalue")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:7: VAR.param is defined but not used.",
		// FIXME: Hmmm, that's going to be complicated to get right.
		"WARN: Makefile:7: Variable VAR.param is defined but not mentioned in the _VARGROUPS section.")
}

func (s *Suite) Test_VargroupsChecker__public_underscore(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"_VARGROUPS+=\t\tgroup",
		"_USER_VARS.group=\t_VARGROUPS")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:4: _USER_VARS.group should list only variables that " +
			"start with a letter, not \"_VARGROUPS\".")
}

func (s *Suite) Test_VargroupsChecker__declared_but_undefined(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"# UNDECLARED", // Documented to avoid a warning about being defined but unused.
		"#\tDocumentation",
		"#\tDocumentation",
		"",
		"_VARGROUPS+=\t\tgroup",
		"_DEF_VARS.group=\tUNDEFINED",
		"",
		"UNDECLARED=\tvalue",
		"UNDECLARED=\tvalue")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:10: Variable UNDECLARED is defined but not mentioned in the _VARGROUPS section.",
		"WARN: Makefile:8: The variable UNDEFINED is not actually defined in this file.")
}

func (s *Suite) Test_VargroupsChecker__defined_but_undeclared(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		".if !defined(MAKEFILE_MK)",
		"MAKEFILE_MK=",
		"",
		"_VARGROUPS+=\t\tgroup",
		"",
		"PKG_FAIL_REASON+=\tReason",
		"",
		".endif")

	mklines.Check()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_VargroupsChecker__used_but_undeclared(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("touch", "TOUCH", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"_VARGROUPS+=\tgroup",
		"",
		"pre-configure:",
		"\t${TOOLS_SHELL} -c ':'",
		"\t${TOUCH} ${TOUCH_FLAGS} ${.TARGET}",
		"\t: ${PKGNAME}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:8: Variable PKGNAME is used " +
			"but not mentioned in the _VARGROUPS section.")
}

func (s *Suite) Test_VargroupsChecker__declared_but_unused(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"# UNDECLARED", // Documented to avoid a "used but not defined" warning.
		"#\tDocumentation",
		"#\tDocumentation",
		"",
		"_VARGROUPS+=\t\tgroup",
		"_USE_VARS.group=\tUNUSED",
		"",
		"target: .PHONY",
		"\t: ${UNDECLARED}",
		"\t: ${UNDECLARED}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:11: Variable UNDECLARED is used but not mentioned in the _VARGROUPS section.",
		"WARN: Makefile:8: The variable UNUSED is not actually used in this file.")
}

func (s *Suite) Test_VargroupsChecker__used_in_BUILD_DEFS(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"# USER_VAR",
		"#\tDocumentation.",
		"#\tDocumentation.",
		"",
		"_VARGROUPS+=\t\tgroup",
		"_USER_VARS.group=\tUSER_VAR",
		"",
		".if ${USER_VAR:U}",
		".endif",
		"BUILD_DEFS+=\t\t${_USER_VARS.group}",
		"BUILD_DEFS_EFFECTS+=\t${_SYS_VARS.group}")

	mklines.Check()

	// No warning about _USER_VARS.group being a write-only variable.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_VargroupsChecker__ignore(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"_VARGROUPS+=\t\tgroup",
		"_IGN_VARS.group=\tPREFER_*",
		"_IGN_VARS.group+=\t[",
		"_UNDERSCORE=\t\t_", // This is not an isVargroups name.
		"",
		".if ${PREFER_PKGSRC:U} || ${WRKOBJDIR:U}",
		".endif")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:5: \"[\" is not a valid variable name pattern.",
		"WARN: Makefile:6: Variable names starting with an underscore (_UNDERSCORE) "+
			"are reserved for internal pkgsrc use.",
		"WARN: Makefile:6: _UNDERSCORE is defined but not used.",
		"WARN: Makefile:6: Variable _UNDERSCORE is defined but not mentioned in the _VARGROUPS section.",
		"WARN: Makefile:8: Variable WRKOBJDIR is used but not mentioned in the _VARGROUPS section.")
}

func (s *Suite) Test_VargroupsChecker__private_before_public(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"_VARGROUPS+=\t\tgroup",
		"_DEF_VARS.group=\t_PRIVATE1 _PRIVATE2 PUBLIC",
		"_PRIVATE1=\t\tprivate",
		"_PRIVATE2=\t\tprivate",
		"PUBLIC=\t\t\tpublic")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:4: The public variable PUBLIC should be listed "+
			"before the private variable _PRIVATE1.",
		"WARN: Makefile:5: Variable names starting with an underscore (_PRIVATE1) "+
			"are reserved for internal pkgsrc use.",
		"WARN: Makefile:5: _PRIVATE1 is defined but not used.",
		"WARN: Makefile:6: Variable names starting with an underscore (_PRIVATE2) "+
			"are reserved for internal pkgsrc use.",
		"WARN: Makefile:6: _PRIVATE2 is defined but not used.",
		"WARN: Makefile:7: PUBLIC is defined but not used.")
}
