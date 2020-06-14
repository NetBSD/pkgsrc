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

	t.CheckEquals(scope.IsUsedSimilar("VAR.param"), true)
	t.CheckEquals(scope.IsUsedSimilar("VAR.other"), true)
	t.CheckEquals(scope.IsUsedSimilar("VARIABLE.*"), false)
}

func (s *Suite) Test_Scope_FirstDefinition(c *check.C) {
	t := s.Init(c)

	mkline1 := t.NewMkLine("fname.mk", 3, "VAR=\tvalue")
	mkline2 := t.NewMkLine("fname.mk", 3, ".if ${SNEAKY::=value}")

	scope := NewScope()
	scope.Define("VAR", mkline1)
	scope.Define("SNEAKY", mkline2)

	t.CheckEquals(scope.FirstDefinition("VAR"), mkline1)

	// This call returns nil because it's not a variable assignment
	// and the calling code typically assumes a variable definition.
	// These sneaky variables with implicit definition are an edge
	// case that only few people actually know. It's better that way.
	t.Check(scope.FirstDefinition("SNEAKY"), check.IsNil)

	t.CheckOutputLines(
		"ERROR: fname.mk:3: Assignment modifiers like \":=\" " +
			"must not be used at all.")
}

func (s *Suite) Test_Scope_Commented(c *check.C) {
	t := s.Init(c)

	assigned := t.NewMkLine("filename.mk", 3, "VAR=\tvalue")
	commented := t.NewMkLine("filename.mk", 4, "#COMMENTED=\tvalue")
	documented := t.NewMkLine("filename.mk", 5, "# DOCUMENTED is a variable.")

	scope := NewScope()
	scope.Define("VAR", assigned)
	scope.Define("COMMENTED", commented)
	scope.Define("DOCUMENTED", documented)

	t.Check(scope.Commented("VAR"), check.IsNil)
	t.CheckEquals(scope.Commented("COMMENTED"), commented)
	t.Check(scope.Commented("DOCUMENTED"), check.IsNil)
	t.Check(scope.Commented("UNKNOWN"), check.IsNil)
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

func (s *Suite) Test_Scope_DefineAll(c *check.C) {
	t := s.Init(c)

	src := NewScope()

	dst := NewScope()
	dst.DefineAll(&src)

	c.Check(dst.vs, check.HasLen, 0)

	src.Define("VAR", t.NewMkLine("file.mk", 1, "VAR=value"))
	dst.DefineAll(&src)

	t.CheckEquals(dst.IsDefined("VAR"), true)
}
