package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_Var_ConditionalVars(c *check.C) {
	t := s.Init(c)

	v := NewVar("VARNAME")

	t.CheckEquals(v.IsConditional(), false)
	t.CheckNil(v.ConditionalVars())

	v.Write(t.NewMkLine("write.mk", 123, "VARNAME=\tconditional"), true, "OPSYS")

	t.CheckEquals(v.IsConstant(), false)
	t.CheckEquals(v.IsConditional(), true)
	t.CheckDeepEquals(v.ConditionalVars(), []string{"OPSYS"})

	v.Write(t.NewMkLine("write.mk", 124, "VARNAME=\tconditional"), true, "OPSYS")

	t.CheckEquals(v.IsConditional(), true)
	t.CheckDeepEquals(v.ConditionalVars(), []string{"OPSYS"})
}

func (s *Suite) Test_Var_Refs(c *check.C) {
	t := s.Init(c)

	v := NewVar("VAR")

	t.CheckNil(v.Refs())

	// The referenced variables are taken from the mkline.
	// They don't need to be passed separately.
	v.Write(t.NewMkLine("write.mk", 123, "VAR=${OTHER} ${${OPSYS} == NetBSD :? ${THEN} : ${ELSE}}"), true, "COND")

	v.AddRef("FOR")

	t.CheckDeepEquals(v.Refs(), []string{"OTHER", "OPSYS", "THEN", "ELSE", "COND", "FOR"})
}

func (s *Suite) Test_Var_ConstantValue__assign(c *check.C) {
	t := s.Init(c)

	v := NewVar("VARNAME")

	v.Write(t.NewMkLine("write.mk", 123, "VARNAME=\tvalue"), false)

	t.CheckEquals(v.ConstantValue(), "value")

	v.Write(t.NewMkLine("write.mk", 124, "VARNAME=\toverwritten"), false)

	t.CheckEquals(v.ConstantValue(), "overwritten")
}

// Variables that reference other variable are considered constants.
// Even if these referenced variables change their value in-between,
// this does not affect the constant-ness of this variable, since the
// references are resolved lazily.
func (s *Suite) Test_Var_ConstantValue__assign_reference(c *check.C) {
	t := s.Init(c)

	v := NewVar("VARNAME")

	v.Write(t.NewMkLine("write.mk", 123, "VARNAME=\tvalue"), false)

	t.CheckEquals(v.ConstantValue(), "value")

	v.Write(t.NewMkLine("write.mk", 124, "VARNAME=\t${OTHER}"), false)

	t.CheckEquals(v.IsConstant(), true)
}

func (s *Suite) Test_Var_ConstantValue__assign_eval_reference(c *check.C) {
	t := s.Init(c)

	v := NewVar("VARNAME")

	v.Write(t.NewMkLine("write.mk", 123, "VARNAME=\tvalue"), false)

	t.CheckEquals(v.ConstantValue(), "value")

	v.Write(t.NewMkLine("write.mk", 124, "VARNAME:=\t${OTHER}"), false)

	// To analyze this case correctly, pkglint would have to know
	// the current value of ${OTHER} in line 124. For that it would
	// need the complete scope including all other variables.
	//
	// As of March 2019 this is not implemented, therefore pkglint
	// doesn't treat the variable as constant, to prevent wrong warnings.
	t.CheckEquals(v.IsConstant(), false)
}

func (s *Suite) Test_Var_ConstantValue__assign_conditional(c *check.C) {
	t := s.Init(c)

	v := NewVar("VARNAME")

	t.CheckNil(v.ConditionalVars())

	v.Write(t.NewMkLine("write.mk", 123, "VARNAME=\tconditional"), true, "OPSYS")

	t.CheckEquals(v.IsConstant(), false)
}

func (s *Suite) Test_Var_ConstantValue__default(c *check.C) {
	t := s.Init(c)

	v := NewVar("VARNAME")

	v.Write(t.NewMkLine("write.mk", 123, "VARNAME?=\tvalue"), false)

	t.CheckEquals(v.ConstantValue(), "value")

	v.Write(t.NewMkLine("write.mk", 124, "VARNAME?=\tignored"), false)

	t.CheckEquals(v.ConstantValue(), "value")
}

func (s *Suite) Test_Var_ConstantValue__eval_then_default(c *check.C) {
	t := s.Init(c)

	v := NewVar("VARNAME")

	v.Write(t.NewMkLine("buildlink3.mk", 123, "VARNAME:=\tvalue"), false)

	t.CheckEquals(v.ConstantValue(), "value")

	v.Write(t.NewMkLine("builtin.mk", 124, "VARNAME?=\tignored"), false)

	t.CheckEquals(v.ConstantValue(), "value")
}

func (s *Suite) Test_Var_ConstantValue__append(c *check.C) {
	t := s.Init(c)

	v := NewVar("VARNAME")

	v.Write(t.NewMkLine("write.mk", 123, "VARNAME+=\tvalue"), false)

	t.CheckEquals(v.ConstantValue(), "value")

	v.Write(t.NewMkLine("write.mk", 124, "VARNAME+=\tappended"), false)

	t.CheckEquals(v.ConstantValue(), "value appended")
}

func (s *Suite) Test_Var_ConstantValue__eval(c *check.C) {
	t := s.Init(c)

	v := NewVar("VARNAME")

	v.Write(t.NewMkLine("write.mk", 123, "VARNAME:=\tvalue"), false)

	t.CheckEquals(v.ConstantValue(), "value")

	v.Write(t.NewMkLine("write.mk", 124, "VARNAME:=\toverwritten"), false)

	t.CheckEquals(v.ConstantValue(), "overwritten")
}

// Variables that are based on running shell commands are never constant.
func (s *Suite) Test_Var_ConstantValue__shell(c *check.C) {
	t := s.Init(c)

	v := NewVar("VARNAME")

	v.Write(t.NewMkLine("write.mk", 123, "VARNAME=\tvalue"), false)

	t.CheckEquals(v.ConstantValue(), "value")

	v.Write(t.NewMkLine("write.mk", 124, "VARNAME!=\techo hello"), false)

	t.CheckEquals(v.IsConstant(), false)
}

func (s *Suite) Test_Var_ConstantValue__referenced_before(c *check.C) {
	t := s.Init(c)

	v := NewVar("VARNAME")

	// Since the value of VARNAME escapes here, the value is not
	// guaranteed to be the same in all evaluations of ${VARNAME}.
	// For example, OTHER may be used at load time in an .if
	// condition.
	v.Read(t.NewMkLine("readwrite.mk", 123, "OTHER=\t${VARNAME}"))

	t.CheckEquals(v.IsConstant(), false)

	v.Write(t.NewMkLine("readwrite.mk", 124, "VARNAME=\tvalue"), false)

	t.CheckEquals(v.IsConstant(), false)
}

func (s *Suite) Test_Var_ConstantValue__referenced_in_between(c *check.C) {
	t := s.Init(c)

	v := NewVar("VARNAME")

	v.Write(t.NewMkLine("readwrite.mk", 123, "VARNAME=\tvalue"), false)

	t.CheckEquals(v.ConstantValue(), "value")

	// Since the value of VARNAME escapes here, the value is not
	// guaranteed to be the same in all evaluations of ${VARNAME}.
	// For example, OTHER may be used at load time in an .if
	// condition.
	v.Read(t.NewMkLine("readwrite.mk", 124, "OTHER=\t${VARNAME}"))

	t.CheckEquals(v.ConstantValue(), "value")

	v.Write(t.NewMkLine("write.mk", 125, "VARNAME=\toverwritten"), false)

	t.CheckEquals(v.IsConstant(), false)
}

func (s *Suite) Test_Var_Value__conditional_write_after_unconditional(c *check.C) {
	t := s.Init(c)

	v := NewVar("VARNAME")

	v.Write(t.NewMkLine("write.mk", 123, "VARNAME=\tvalue"), false)

	t.CheckEquals(v.Value(), "value")

	v.Write(t.NewMkLine("write.mk", 124, "VARNAME+=\tappended"), false)

	t.CheckEquals(v.Value(), "value appended")

	v.Write(t.NewMkLine("write.mk", 124, "VARNAME:=\toverwritten conditionally"), true, "OPSYS")

	// When there is a previous value, it's probably best to keep
	// that value since this way the following code results in the
	// most generic value:
	//  VAR=    generic
	//  .if ${OPSYS} == NetBSD
	//  VAR=    specific
	//  .endif
	// The value stays the same, still it is marked as conditional and therefore
	// not constant anymore.
	t.CheckEquals(v.IsConditional(), true)
	t.CheckEquals(v.IsConstant(), false)
	t.CheckEquals(v.Value(), "value appended")
}

func (s *Suite) Test_Var_Value__infrastructure(c *check.C) {
	t := s.Init(c)

	v := NewVar("VARNAME")

	v.Write(t.NewMkLine(t.File("write.mk"), 123, "VARNAME=\tvalue"), false)

	t.CheckEquals(v.Value(), "value")

	v.Write(t.NewMkLine(t.File("mk/write.mk"), 123, "VARNAME=\tinfra"), false)

	t.CheckEquals(v.Value(), "value")

	v.Write(t.NewMkLine(t.File("wip/mk/write.mk"), 123, "VARNAME=\twip infra"), false)

	t.CheckEquals(v.Value(), "value")
}

func (s *Suite) Test_Var_Value__initial_conditional_write(c *check.C) {
	t := s.Init(c)

	v := NewVar("VARNAME")

	v.Write(t.NewMkLine("write.mk", 124, "VARNAME:=\toverwritten conditionally"), true, "OPSYS")

	// Since there is no previous value, the simplest choice is to just
	// take the first seen value, no matter if that value is conditional
	// or not.
	t.CheckEquals(v.IsConditional(), true)
	t.CheckEquals(v.IsConstant(), false)
	t.CheckEquals(v.Value(), "overwritten conditionally")
}

func (s *Suite) Test_Var_ValueInfra(c *check.C) {
	t := s.Init(c)

	v := NewVar("VARNAME")

	v.Write(t.NewMkLine(t.File("write.mk"), 123, "VARNAME=\tvalue"), false)

	t.CheckEquals(v.ValueInfra(), "value")

	v.Write(t.NewMkLine(t.File("mk/write.mk"), 123, "VARNAME=\tinfra"), false)

	t.CheckEquals(v.ValueInfra(), "infra")

	v.Write(t.NewMkLine(t.File("wip/mk/write.mk"), 123, "VARNAME=\twip infra"), false)

	t.CheckEquals(v.ValueInfra(), "wip infra")
}

func (s *Suite) Test_Var_ReadLocations(c *check.C) {
	t := s.Init(c)

	v := NewVar("VAR")

	t.CheckNil(v.ReadLocations())

	mkline123 := t.NewMkLine("read.mk", 123, "OTHER=\t${VAR}")
	v.Read(mkline123)

	t.CheckDeepEquals(v.ReadLocations(), []*MkLine{mkline123})

	mkline124 := t.NewMkLine("read.mk", 124, "OTHER=\t${VAR} ${VAR}")
	v.Read(mkline124)
	v.Read(mkline124)

	// For now, count every read of the variable. I'm not yet sure
	// whether that's the best way or whether to make the lines unique.
	t.CheckDeepEquals(v.ReadLocations(), []*MkLine{mkline123, mkline124, mkline124})
}

func (s *Suite) Test_Var_WriteLocations(c *check.C) {
	t := s.Init(c)

	v := NewVar("VAR")

	t.CheckNil(v.WriteLocations())

	mkline123 := t.NewMkLine("write.mk", 123, "VAR=\tvalue")
	v.Write(mkline123, false)

	t.CheckDeepEquals(v.WriteLocations(), []*MkLine{mkline123})

	// Multiple writes from the same line may happen because of a .for loop.
	mkline125 := t.NewMkLine("write.mk", 125, "VAR+=\t${var}")
	v.Write(mkline125, false)
	v.Write(mkline125, false)

	// For now, count every write of the variable. I'm not yet sure
	// whether that's the best way or whether to make the lines unique.
	t.CheckDeepEquals(v.WriteLocations(), []*MkLine{mkline123, mkline125, mkline125})
}

func (s *Suite) Test_Var_Write__conditional_without_variables(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		".if exists(/usr/bin)",
		"VAR=\tvalue",
		".endif")

	scope := NewRedundantScope()
	mklines.ForEach(func(mkline *MkLine) {
		if mkline.IsVarassign() {
			t.CheckEquals(scope.get("VAR").vari.IsConditional(), false)
		}

		scope.checkLine(mklines, mkline)

		if mkline.IsVarassign() {
			t.CheckEquals(scope.get("VAR").vari.IsConditional(), true)
		}
	})
}

func (s *Suite) Test_Var_Write__assertion(c *check.C) {
	t := s.Init(c)

	v := NewVar("VAR")
	t.ExpectAssert(
		func() { v.Write(t.NewMkLine("filename.mk", 1, "OTHER=value"), false, nil...) })
}
