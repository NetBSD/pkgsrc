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

func (s *Suite) Test_ShAtomType_String(c *check.C) {
	c.Check(shtComment.String(), equals, "comment")
}

func (s *Suite) Test_ShAtom_String(c *check.C) {
	tokenizer := NewShTokenizer(dummyLine, "${ECHO} \"hello, world\"", false)

	atoms := tokenizer.ShAtoms()

	c.Check(len(atoms), equals, 5)
	c.Check(atoms[0].String(), equals, "varuse(\"ECHO\")")
	c.Check(atoms[1].String(), equals, "ShAtom(space, \" \", plain)")
	c.Check(atoms[2].String(), equals, "ShAtom(word, \"\\\"\", d)")
	c.Check(atoms[3].String(), equals, "ShAtom(word, \"hello, world\", d)")
	c.Check(atoms[4].String(), equals, "\"\\\"\"")
}

func (s *Suite) Test_ShQuoting_String(c *check.C) {
	c.Check(shqDquotBacktSquot.String(), equals, "dbs")
}

func (s *Suite) Test_ShToken_String(c *check.C) {
	tokenizer := NewShTokenizer(dummyLine, "${ECHO} \"hello, world\"", false)

	c.Check(tokenizer.ShToken().String(), equals, "ShToken([varuse(\"ECHO\")])")
	c.Check(tokenizer.ShToken().String(), equals, "ShToken([ShAtom(word, \"\\\"\", d) ShAtom(word, \"hello, world\", d) \"\\\"\"])")
}
