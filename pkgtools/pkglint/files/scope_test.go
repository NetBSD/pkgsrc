package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_Scope__no_tracing(c *check.C) {
	t := s.Init(c)

	scope := NewScope()
	scope.Define("VAR.param", t.NewMkLine("fname.mk", 3, "VAR.param=\tvalue"))
	t.DisableTracing()

	t.CheckEquals(scope.IsDefinedSimilar("VAR.param"), true)
	t.CheckEquals(scope.IsDefinedSimilar("VAR.other"), true)
	t.CheckEquals(scope.IsDefinedSimilar("OTHER"), false)
}

func (s *Suite) Test_Scope__commented_varassign(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("mk/defaults/mk.conf", 3, "#VAR=default")
	scope := NewScope()
	scope.Define("VAR", mkline)

	t.CheckEquals(scope.IsDefined("VAR"), false)
	t.Check(scope.FirstDefinition("VAR"), check.IsNil)
	t.Check(scope.LastDefinition("VAR"), check.IsNil)

	t.CheckEquals(scope.Mentioned("VAR"), mkline)
	t.CheckEquals(scope.Commented("VAR"), mkline)

	value, found, indeterminate := scope.LastValueFound("VAR")
	t.CheckEquals(value, "")
	t.CheckEquals(found, false)
	t.CheckEquals(indeterminate, false)
}

func (s *Suite) Test_NewScope(c *check.C) {
	t := s.Init(c)

	scope := NewScope()

	t.Check(scope.names, check.IsNil)
	t.Check(scope.vs, check.NotNil)
	t.Check(scope.vs, check.HasLen, 0)
}

func (s *Suite) Test_Scope_varnames(c *check.C) {
	t := s.Init(c)

	scope := NewScope()
	mkline := t.NewMkLine("filename.mk", 3, "DEFINED=\t${USED}")

	t.Check(scope.varnames(), check.IsNil)

	scope.Define("DEFINED", mkline)
	scope.Use("USED", mkline, VucRunTime)

	t.CheckDeepEquals(scope.varnames(), []string{"DEFINED", "USED"})
	scope.varnames()[0] = "modified" // just to demonstrate the caching
	t.CheckDeepEquals(scope.varnames(), []string{"modified", "USED"})
}

func (s *Suite) Test_Scope_create(c *check.C) {
	t := s.Init(c)

	scope := NewScope()

	v1 := scope.create("VAR")
	v2 := scope.create("VAR")

	t.CheckEquals(v1, v2)
}

func (s *Suite) Test_Scope_Define(c *check.C) {
	t := s.Init(c)

	scope := NewScope()

	test := func(line string, found, indeterminate bool, value string) {
		mkline := t.NewMkLine("file.mk", 123, line)
		scope.Define("BUILD_DIRS", mkline)

		actualValue, actualFound, actualIndeterminate := scope.LastValueFound("BUILD_DIRS")

		t.CheckDeepEquals(
			[]interface{}{actualFound, actualIndeterminate, actualValue},
			[]interface{}{found, indeterminate, value})
		t.CheckEquals(scope.vs["BUILD_DIRS"].value, value)
	}

	test("BUILD_DIRS?=\tdefault",
		true, false, "default")

	test(
		"BUILD_DIRS=\tone two three",
		true, false, "one two three")

	test(
		"BUILD_DIRS+=\tfour",
		true, false, "one two three four")

	// Later default assignments do not have an effect.
	test("BUILD_DIRS?=\tdefault",
		true, false, "one two three four")

	test("BUILD_DIRS!=\techo dynamic",
		true, true, "")

	// The shell assignment above sets the variable to an indeterminate
	// value, after which all further default assignments are ignored.
	test("BUILD_DIRS?=\tdefault after shell assignment",
		true, true, "")
}

func (s *Suite) Test_Scope_def(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 3, "VAR=\tvalue")
	scope := NewScope()

	scope.def("VAR.param", mkline)

	t.Check(scope.FirstDefinition("VAR"), check.IsNil)
	t.CheckEquals(scope.FirstDefinition("VAR.param"), mkline)
	t.Check(scope.FirstDefinition("VAR.*"), check.IsNil)
}

func (s *Suite) Test_Scope_Fallback(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 3, "VAR=\tvalue")
	scope := NewScope()
	scope.def("VAR.param", mkline)

	scope.Fallback("FALLBACK", "fallback")

	t.CheckEquals(scope.LastValue("VAR.param"), "value")
	t.CheckEquals(scope.LastValue("FALLBACK"), "fallback")
	t.CheckEquals(scope.LastValue("UNDEFINED"), "")
}

func (s *Suite) Test_Scope_Use(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 3, "VAR=\t${USED}")
	scope := NewScope()
	scope.Define("VAR", mkline)
	scope.Use("USED", mkline, VucRunTime)

	t.CheckEquals(scope.LastValue("VAR"), "${USED}")
	t.CheckEquals(scope.LastValue("USED"), "")
}

func (s *Suite) Test_Scope_Mentioned(c *check.C) {
	t := s.Init(c)

	assigned := t.NewMkLine("filename.mk", 3, "VAR=\tvalue")
	commented := t.NewMkLine("filename.mk", 4, "#COMMENTED=\tvalue")
	documented := t.NewMkLine("filename.mk", 5, "# DOCUMENTED is a variable.")

	scope := NewScope()
	scope.Define("VAR", assigned)
	scope.Define("COMMENTED", commented)
	scope.Define("DOCUMENTED", documented)

	t.CheckEquals(scope.Mentioned("VAR"), assigned)
	t.CheckEquals(scope.Mentioned("COMMENTED"), commented)
	t.CheckEquals(scope.Mentioned("DOCUMENTED"), documented)
	t.Check(scope.Mentioned("UNKNOWN"), check.IsNil)
}

func (s *Suite) Test_Scope_IsDefined(c *check.C) {
	t := s.Init(c)

	scope := NewScope()
	scope.Define("VAR.param", t.NewMkLine("file.mk", 1, "VAR.param=value"))

	t.CheckEquals(scope.IsDefined("VAR.param"), true)
	t.CheckEquals(scope.IsDefined("VAR.other"), false)
	t.CheckEquals(scope.IsDefined("VARIABLE.*"), false)
}

func (s *Suite) Test_Scope_IsDefinedSimilar(c *check.C) {
	t := s.Init(c)

	scope := NewScope()
	scope.Define("VAR.param", t.NewMkLine("file.mk", 1, "VAR.param=value"))

	t.CheckEquals(scope.IsDefinedSimilar("VAR.param"), true)
	t.CheckEquals(scope.IsDefinedSimilar("VAR.other"), true)
	t.CheckEquals(scope.IsDefinedSimilar("VARIABLE.*"), false)
}

func (s *Suite) Test_Scope_IsUsed(c *check.C) {
	t := s.Init(c)

	scope := NewScope()
	mkline := t.NewMkLine("file.mk", 1, "\techo ${VAR.param}")
	scope.Use("VAR.param", mkline, VucRunTime)

	t.CheckEquals(scope.IsUsed("VAR.param"), true)
	t.CheckEquals(scope.IsUsed("VAR.other"), false)
	t.CheckEquals(scope.IsUsed("VARIABLE.*"), false)
}

func (s *Suite) Test_Scope_IsUsedSimilar(c *check.C) {
	t := s.Init(c)

	scope := NewScope()
	mkline := t.NewMkLine("file.mk", 1, "\techo ${VAR.param}")
	scope.Use("VAR.param", mkline, VucRunTime)

	t.CheckEquals(scope.IsUsedSimilar("VAR.param"), true)
	t.CheckEquals(scope.IsUsedSimilar("VAR.other"), true)
	t.CheckEquals(scope.IsUsedSimilar("VARIABLE.*"), false)
}

func (s *Suite) Test_Scope_IsUsedAtLoadTime(c *check.C) {
	t := s.Init(c)

	scope := NewScope()
	mkline := t.NewMkLine("file.mk", 1, "\techo ${VAR.param}")

	scope.Use("LOAD_TIME", mkline, VucLoadTime)
	scope.Use("RUN_TIME", mkline, VucRunTime)

	t.CheckEquals(scope.IsUsedAtLoadTime("LOAD_TIME"), true)
	t.CheckEquals(scope.IsUsedAtLoadTime("RUN_TIME"), false)
	t.CheckEquals(scope.IsUsedAtLoadTime("UNDEFINED"), false)
}

func (s *Suite) Test_Scope_FirstDefinition(c *check.C) {
	t := s.Init(c)

	mkline3 := t.NewMkLine("fname.mk", 3, "VAR=\tvalue")
	mkline4 := t.NewMkLine("fname.mk", 4, ".if ${SNEAKY::=value}")
	mkline5 := t.NewMkLine("fname.mk", 5, ".if ${USED}")

	scope := NewScope()
	scope.Define("VAR", mkline3)
	scope.Define("SNEAKY", mkline4)
	scope.Use("USED", mkline5, VucLoadTime)

	t.CheckEquals(scope.FirstDefinition("VAR"), mkline3)

	// This call returns nil because it's not a variable assignment
	// and the calling code typically assumes a variable definition.
	// These sneaky variables with implicit definition are an edge
	// case that only few people actually know. It's better that way.
	t.Check(scope.FirstDefinition("SNEAKY"), check.IsNil)

	t.Check(scope.FirstDefinition("USED"), check.IsNil)

	t.CheckOutputLines(
		"ERROR: fname.mk:4: Assignment modifiers like \":=\" " +
			"must not be used at all.")
}

func (s *Suite) Test_Scope_LastDefinition(c *check.C) {
	t := s.Init(c)

	mkline3 := t.NewMkLine("fname.mk", 3, "VAR=\tfirst")
	mkline4 := t.NewMkLine("fname.mk", 4, "VAR=\t${USED}")

	scope := NewScope()
	scope.Define("VAR", mkline3)
	scope.Define("VAR", mkline4)
	scope.Use("USED", mkline4, VucRunTime)

	t.CheckEquals(scope.LastDefinition("VAR"), mkline4)
	t.Check(scope.LastDefinition("UNDEFINED"), check.IsNil)
	t.Check(scope.LastDefinition("USED"), check.IsNil)
}

func (s *Suite) Test_Scope_Commented(c *check.C) {
	t := s.Init(c)

	assigned := t.NewMkLine("filename.mk", 3, "VAR=\tvalue")
	commented := t.NewMkLine("filename.mk", 4, "#COMMENTED=\tvalue")
	documented := t.NewMkLine("filename.mk", 5, "# DOCUMENTED is a variable.")
	used := t.NewMkLine("filename.mk", 6, "ANY=\t${USED}")

	scope := NewScope()
	scope.Define("VAR", assigned)
	scope.Define("COMMENTED", commented)
	scope.Define("DOCUMENTED", documented)
	scope.Use("USED", used, VucRunTime)

	t.Check(scope.Commented("VAR"), check.IsNil)
	t.CheckEquals(scope.Commented("COMMENTED"), commented)
	t.Check(scope.Commented("DOCUMENTED"), check.IsNil)
	t.Check(scope.Commented("UNKNOWN"), check.IsNil)
	t.Check(scope.Commented("USED"), check.IsNil)
}

func (s *Suite) Test_Scope_FirstUse(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		MkCvsID,
		"VAR1=\t${USED}",
		"VAR2=\t${USED}")

	mklines.Check()

	scope := mklines.allVars
	t.CheckEquals(scope.FirstUse("USED"), mklines.mklines[1])
	t.Check(scope.FirstUse("UNUSED"), check.IsNil)

	t.CheckOutputLines(
		"WARN: file.mk:2: VAR1 is defined but not used.",
		"WARN: file.mk:2: USED is used but not defined.",
		"WARN: file.mk:3: VAR2 is defined but not used.")
}

func (s *Suite) Test_Scope_LastValue(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		MkCvsID,
		"VAR=\tfirst",
		"VAR=\tsecond",
		".if 1",
		"VAR=\tthird (conditional)",
		".endif")

	mklines.Check()

	// TODO: At load time, use loadVars instead of allVars.
	t.CheckEquals(mklines.allVars.LastValue("VAR"), "third (conditional)")

	t.CheckOutputLines(
		"WARN: file.mk:2: VAR is defined but not used.")
}

// Up to 2020-01-06, pkglint wrongly returned "one" as the variable value,
// even though Makefile.common is included before appending "two".
func (s *Suite) Test_Scope_LastValue__append_in_multiple_files(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"Makefile.common\"",
		"PLIST_VARS+=\ttwo",
		"PLIST.two=\tyes")
	t.Chdir("category/package")
	t.CreateFileLines("PLIST",
		PlistCvsID,
		"${PLIST.one}${PLIST.two}bin/program")
	t.CreateFileLines("Makefile.common",
		MkCvsID,
		"PLIST_VARS=\tone",
		"PLIST.one=\tyes")
	pkg := NewPackage(".")
	t.FinishSetUp()

	pkg.Check()

	t.CheckEquals(pkg.vars.LastValue("PLIST_VARS"), "one two")
}

func (s *Suite) Test_Scope_LastValueFound(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		MkCvsID,
		"VAR=\tfirst",
		"VAR=\tsecond",
		".if 1",
		"VAR=\tthird (conditional)",
		".endif")

	mklines.Check()

	value, found, indeterminate := mklines.allVars.LastValueFound("VAR")
	t.CheckEquals(value, "third (conditional)")
	t.CheckEquals(found, true)
	t.CheckEquals(indeterminate, false) // TODO: why?

	t.CheckOutputLines(
		"WARN: file.mk:2: VAR is defined but not used.")
}

// Scope.DefineAll copies only the variable definitions,
// but not the uses of variables.
func (s *Suite) Test_Scope_DefineAll(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 123, "VAR=\t${USED}")

	src := NewScope()
	src.Use("USED", mkline, VucRunTime)

	dst := NewScope()
	dst.DefineAll(&src)

	c.Check(dst.vs, check.HasLen, 0)

	src.Define("VAR", t.NewMkLine("file.mk", 1, "VAR=value"))
	dst.DefineAll(&src)

	t.CheckEquals(dst.IsDefined("VAR"), true)
}

func (s *Suite) Test_Scope_forEach(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 123, "VAR=\t${USED}")

	scope := NewScope()
	scope.Define("VAR", mkline)
	scope.Use("USED", mkline, VucRunTime)

	var result []string
	scope.forEach(func(varname string, data *scopeVar) {
		result = append(result, varname+"="+data.value)
	})

	t.CheckDeepEquals(result, []string{
		"USED=",
		"VAR=${USED}"})
}
