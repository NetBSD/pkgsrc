package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_Var_Constant(c *check.C) {
	v := NewVar("VARNAME")

	// FIXME: Replace this test with an actual use case.

	c.Check(v.Constant(), equals, false)
}

func (s *Suite) Test_Var_ConstantValue(c *check.C) {
	v := NewVar("VARNAME")

	// FIXME: Replace this test with an actual use case.

	c.Check(v.ConstantValue(), equals, "")
}
