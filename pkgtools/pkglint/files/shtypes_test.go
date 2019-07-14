package pkglint

import (
	"gopkg.in/check.v1"
)

func NewShAtom(typ ShAtomType, text string, quoting ShQuoting) *ShAtom {
	return &ShAtom{typ, text, quoting, nil}
}

func (s *Suite) Test_ShAtomType_String(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(shtComment.String(), "comment")
}

func (s *Suite) Test_ShAtom_String(c *check.C) {
	t := s.Init(c)

	tokenizer := NewShTokenizer(dummyLine, "${ECHO} \"hello, world\"", false)

	atoms := tokenizer.ShAtoms()

	t.CheckEquals(len(atoms), 5)
	t.CheckEquals(atoms[0].String(), "varuse(\"ECHO\")")
	t.CheckEquals(atoms[1].String(), "ShAtom(space, \" \", plain)")
	t.CheckEquals(atoms[2].String(), "ShAtom(text, \"\\\"\", d)")
	t.CheckEquals(atoms[3].String(), "ShAtom(text, \"hello, world\", d)")
	t.CheckEquals(atoms[4].String(), "\"\\\"\"")
}

func (s *Suite) Test_ShQuoting_String(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(shqDquotBacktSquot.String(), "dbs")
}

func (s *Suite) Test_NewShToken__no_atoms(c *check.C) {
	t := s.Init(c)

	t.ExpectAssert(func() { NewShToken("", NewShAtom(shtText, "text", shqPlain)) })
	t.ExpectAssert(func() { NewShToken(" ", nil...) })
}

func (s *Suite) Test_ShToken_String(c *check.C) {
	t := s.Init(c)

	tokenizer := NewShTokenizer(dummyLine, "${ECHO} \"hello, world\"", false)

	t.CheckEquals(tokenizer.ShToken().String(), "ShToken([varuse(\"ECHO\")])")
	t.CheckEquals(tokenizer.ShToken().String(), "ShToken([ShAtom(text, \"\\\"\", d) ShAtom(text, \"hello, world\", d) \"\\\"\"])")
}
