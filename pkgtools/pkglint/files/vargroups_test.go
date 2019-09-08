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
		"",
		"VAR.param=\tvalue")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:6: VAR.param is defined but not used.",
		// FIXME: Hmmm, that's going to be complicated to get right.
		"WARN: Makefile:6: Variable VAR.param is defined but not mentioned in the _VARGROUPS section.")
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
