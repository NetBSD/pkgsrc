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

// TODO: Add test for :L in the middle of a MkVarUse.
// TODO: Add test for :L at the end of a MkVarUse.
