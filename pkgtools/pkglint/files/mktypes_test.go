package pkglint

import (
	"gopkg.in/check.v1"
)

func NewMkVarUse(varname string, modifiers ...string) *MkVarUse {
	var mods []MkVarUseModifier
	for _, modifier := range modifiers {
		mods = append(mods, MkVarUseModifier{modifier})
	}
	return &MkVarUse{varname, mods}
}

func (s *Suite) Test_MkVarUse_Mod(c *check.C) {
	varuse := NewMkVarUse("varname", "Q")

	c.Check(varuse.Mod(), equals, ":Q")
}

// AddCommand adds a command directly to a list of commands,
// creating all the intermediate nodes for the syntactic representation.
// As soon as that representation is replaced with a semantic representation,
// this method should no longer be necessary.
func (list *MkShList) AddCommand(command *MkShCommand) *MkShList {
	pipeline := NewMkShPipeline(false, []*MkShCommand{command})
	andOr := NewMkShAndOr(pipeline)
	return list.AddAndOr(andOr)
}

func (s *Suite) Test_MkVarUseModifier_ChangesWords(c *check.C) {
	t := s.Init(c)

	test := func(modifier string, changes bool) {
		mod := MkVarUseModifier{modifier}
		t.Check(mod.ChangesWords(), equals, changes)
	}

	test("E", false)
	test("R", false)
	test("Mpattern", false)
	test("Npattern", false)
	test("S,from,to,", true)
	test("C,from,to,", true)
	test("tl", false)
	test("tu", false)
	test("sh", true)

	test("unknown", true)
}

// Ensures that ChangesWords cannot be called with an empty string as modifier.
func (s *Suite) Test_MkVarUseModifier_ChangesWords__empty(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 123, "\t${VAR:}")

	n := 0
	mkline.ForEachUsed(func(varUse *MkVarUse, time vucTime) {
		n += 100
		for _, mod := range varUse.modifiers {
			mod.ChangesWords()
			n++
		}
	})

	t.CheckOutputEmpty()
	t.Check(n, equals, 100)
}

func (s *Suite) Test_MkVarUseModifier_MatchSubst(c *check.C) {
	mod := MkVarUseModifier{"S/from/to/1g"}

	ok, regex, from, to, options := mod.MatchSubst()

	c.Check(ok, equals, true)
	c.Check(regex, equals, false)
	c.Check(from, equals, "from")
	c.Check(to, equals, "to")
	c.Check(options, equals, "1g")
}

func (s *Suite) Test_MkVarUseModifier_MatchSubst__backslash(c *check.C) {
	mod := MkVarUseModifier{"S/\\//\\:/"}

	ok, regex, from, to, options := mod.MatchSubst()

	c.Check(ok, equals, true)
	c.Check(regex, equals, false)
	c.Check(from, equals, "\\/")
	c.Check(to, equals, "\\:")
	c.Check(options, equals, "")
}

// As of 2019-03-24, pkglint doesn't know how to handle complicated
// :C modifiers.
func (s *Suite) Test_MkVarUseModifier_Subst__regexp(c *check.C) {
	mod := MkVarUseModifier{"C,.*,,"}

	empty, ok := mod.Subst("anything")

	c.Check(ok, equals, false)
	c.Check(empty, equals, "")
}

// When given a modifier that is not actually a :S or :C, Subst
// doesn't do anything.
func (s *Suite) Test_MkVarUseModifier_Subst__invalid_argument(c *check.C) {
	mod := MkVarUseModifier{"Mpattern"}

	empty, ok := mod.Subst("anything")

	c.Check(ok, equals, false)
	c.Check(empty, equals, "")
}
