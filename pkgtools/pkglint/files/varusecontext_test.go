package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestVarUseContext_ToString(c *check.C) {
	G.globalData.InitVartypes()
	vartype := getVariableType(s.DummyLine(), "PKGNAME")
	vuc := &VarUseContext{vucTimeUnknown, vartype, vucQuotBackt, vucExtentWord}

	c.Check(vuc.String(), equals, "(unknown PkgName backt word)")
}
