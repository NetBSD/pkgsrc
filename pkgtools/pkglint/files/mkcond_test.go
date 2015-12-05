package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestParseMkCond_NotEmptyMatch(c *check.C) {
	line := NewLine("fname", "1", "dummy", nil)

	cond := parseMkCond(line, "!empty(USE_LIBTOOL:M[Yy][Ee][Ss])")

	c.Check(cond, check.DeepEquals, NewTree("not", NewTree("empty", NewTree("match", "USE_LIBTOOL", "[Yy][Ee][Ss]"))))
}

func (s *Suite) TestParseMkCond_Compare(c *check.C) {
	line := NewLine("fname", "1", "dummy", nil)

	cond := parseMkCond(line, "${VARNAME} != \"Value\"")

	c.Check(cond, check.DeepEquals, NewTree("compareVarStr", "VARNAME", "!=", "Value"))
}

func (s *Suite) TestChecklineMkCondition(c *check.C) {
	s.UseCommandLine(c, "-Wtypes")
	G.globalData.InitVartypes()

	NewMkLine(NewLine("fname", "1", ".if !empty(PKGSRC_COMPILER:Mmycc)", nil)).checkIf()

	c.Check(s.Stdout(), equals, "WARN: fname:1: Invalid :M value \"mycc\". "+
		"Only { ccache ccc clang distcc f2c gcc hp icc ido gcc mipspro "+
		"mipspro-ucode pcc sunpro xlc } are allowed.\n")

	NewMkLine(NewLine("fname", "1", ".elif ${A} != ${B}", nil)).checkIf()

	c.Check(s.Stdout(), equals, "") // Unknown condition types are silently ignored

	NewMkLine(NewLine("fname", "1", ".if ${HOMEPAGE} == \"mailto:someone@example.org\"", nil)).checkIf()

	c.Check(s.Output(), equals, "WARN: fname:1: \"mailto:someone@example.org\" is not a valid URL.\n")
}
