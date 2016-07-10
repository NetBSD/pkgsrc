package main

import (
	check "gopkg.in/check.v1"
)

func NewShAtom(typ ShAtomType, text string, quoting ShQuoting) *ShAtom {
	return &ShAtom{typ, text, quoting, nil}
}

func NewShAtomVaruse(text string, quoting ShQuoting, varname string, modifiers ...string) *ShAtom {
	return &ShAtom{shtVaruse, text, quoting, NewMkVarUse(varname, modifiers...)}
}

func (s *Suite) Test_ShAtom_String(c *check.C) {
	c.Check(shtComment.String(), equals, "comment")
}

func (s *Suite) Test_ShQuoting_String(c *check.C) {
	c.Check(shqDquotBacktSquot.String(), equals, "dbs")
}
