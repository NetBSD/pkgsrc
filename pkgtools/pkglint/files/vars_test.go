package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestVariableNeedsQuoting(c *check.C) {
	line := s.DummyLine()
	G.globalData.InitVartypes()
	pkgnameType := G.globalData.vartypes["PKGNAME"]

	// In Makefile: PKGNAME := ${UNKNOWN}
	vuc := &VarUseContext{VUC_TIME_LOAD, pkgnameType, VUC_SHW_UNKNOWN, VUC_EXTENT_UNKNOWN}
	nq := variableNeedsQuoting(line, "UNKNOWN", vuc)

	c.Check(nq, equals, NQ_DONT_KNOW)
}
