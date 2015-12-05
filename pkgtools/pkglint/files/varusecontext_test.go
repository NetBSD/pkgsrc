package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestVarUseContext_ToString(c *check.C) {
	G.globalData.InitVartypes()
	vartype := getVariableType(NewLine("fname", "1", "dummy", nil), "PKGNAME")
	vuc := &VarUseContext{vucTimeUnknown, vartype, vucQuotBackt, vucExtentWord}

	c.Check(vuc.String(), equals, "(unknown PkgName backt word)")
}
