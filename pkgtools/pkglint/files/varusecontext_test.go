package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestVarUseContext_ToString(c *check.C) {
	G.globalData.InitVartypes()
	vartype := getVariableType(s.DummyLine(), "PKGNAME")
	vuc := &VarUseContext{VUC_TIME_UNKNOWN, vartype, VUC_SHW_BACKT, VUC_EXT_WORD}

	c.Check(vuc.String(), equals, "(unknown PkgName backt word)")
}
