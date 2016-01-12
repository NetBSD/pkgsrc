package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestSubstContext_Incomplete(c *check.C) {
	G.opts.WarnExtra = true
	ctx := new(SubstContext)

	ctx.Varassign(newSubstLine(10, "PKGNAME=pkgname-1.0"))

	c.Check(ctx.id, equals, "")

	ctx.Varassign(newSubstLine(11, "SUBST_CLASSES+=interp"))

	c.Check(ctx.id, equals, "interp")

	ctx.Varassign(newSubstLine(12, "SUBST_FILES.interp=Makefile"))

	c.Check(ctx.IsComplete(), equals, false)

	ctx.Varassign(newSubstLine(13, "SUBST_SED.interp=s,@PREFIX@,${PREFIX},g"))

	c.Check(ctx.IsComplete(), equals, false)

	ctx.Finish(newSubstLine(14, ""))

	c.Check(s.Output(), equals, "WARN: Makefile:14: Incomplete SUBST block: SUBST_STAGE.interp missing.\n")
}

func (s *Suite) TestSubstContext_Complete(c *check.C) {
	G.opts.WarnExtra = true
	ctx := new(SubstContext)

	ctx.Varassign(newSubstLine(10, "PKGNAME=pkgname-1.0"))
	ctx.Varassign(newSubstLine(11, "SUBST_CLASSES+=p"))
	ctx.Varassign(newSubstLine(12, "SUBST_FILES.p=Makefile"))
	ctx.Varassign(newSubstLine(13, "SUBST_SED.p=s,@PREFIX@,${PREFIX},g"))

	c.Check(ctx.IsComplete(), equals, false)

	ctx.Varassign(newSubstLine(14, "SUBST_STAGE.p=post-configure"))

	c.Check(ctx.IsComplete(), equals, true)

	ctx.Finish(newSubstLine(15, ""))

	c.Check(s.Output(), equals, "")
}

func (s *Suite) TestSubstContext_NoClass(c *check.C) {
	s.UseCommandLine(c, "-Wextra")
	ctx := new(SubstContext)

	ctx.Varassign(newSubstLine(10, "UNRELATED=anything"))
	ctx.Varassign(newSubstLine(11, "SUBST_FILES.repl+=Makefile.in"))
	ctx.Varassign(newSubstLine(12, "SUBST_SED.repl+=-e s,from,to,g"))
	ctx.Finish(newSubstLine(13, ""))

	c.Check(s.Output(), equals, ""+
		"WARN: Makefile:11: SUBST_CLASSES should come before the definition of \"SUBST_FILES.repl\".\n"+
		"WARN: Makefile:13: Incomplete SUBST block: SUBST_STAGE.repl missing.\n")
}

func newSubstLine(lineno int, text string) *MkLine {
	return NewMkLine(NewLine("Makefile", lineno, text, nil))
}
