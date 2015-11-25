package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestSubstContext_Incomplete(c *check.C) {
	G.opts.WarnExtra = true
	line := NewLine("Makefile", "1", "dummy", nil)
	ctx := new(SubstContext)

	ctx.Varassign(line, "PKGNAME", "=", "pkgname-1.0")

	c.Check(ctx.id, equals, "")

	ctx.Varassign(line, "SUBST_CLASSES", "+=", "interp")

	c.Check(ctx.id, equals, "interp")

	ctx.Varassign(line, "SUBST_FILES.interp", "=", "Makefile")

	c.Check(ctx.IsComplete(), equals, false)

	ctx.Varassign(line, "SUBST_SED.interp", "=", "s,@PREFIX@,${PREFIX},g")

	c.Check(ctx.IsComplete(), equals, false)

	ctx.Finish(line)

	c.Check(s.Output(), equals, "WARN: Makefile:1: Incomplete SUBST block: SUBST_STAGE.interp missing.\n")
}

func (s *Suite) TestSubstContext_Complete(c *check.C) {
	G.opts.WarnExtra = true
	line := NewLine("Makefile", "1", "dummy", nil)
	ctx := new(SubstContext)

	ctx.Varassign(line, "PKGNAME", "=", "pkgname-1.0")
	ctx.Varassign(line, "SUBST_CLASSES", "+=", "p")
	ctx.Varassign(line, "SUBST_FILES.p", "=", "Makefile")
	ctx.Varassign(line, "SUBST_SED.p", "=", "s,@PREFIX@,${PREFIX},g")

	c.Check(ctx.IsComplete(), equals, false)

	ctx.Varassign(line, "SUBST_STAGE.p", "=", "post-configure")

	c.Check(ctx.IsComplete(), equals, true)

	ctx.Finish(line)

	c.Check(s.Output(), equals, "")
}

func (s *Suite) TestSubstContext_NoClass(c *check.C) {
	s.UseCommandLine("-Wextra")
	line := NewLine("Makefile", "1", "dummy", nil)
	ctx := new(SubstContext)

	ctx.Varassign(line, "UNRELATED", "=", "anything")
	ctx.Varassign(line, "SUBST_FILES.repl", "+=", "Makefile.in")
	ctx.Varassign(line, "SUBST_SED.repl", "+=", "-e s,from,to,g")
	ctx.Finish(line)

	c.Check(s.Output(), equals, ""+
		"WARN: Makefile:1: SUBST_CLASSES should come before the definition of \"SUBST_FILES.repl\".\n"+
		"WARN: Makefile:1: Incomplete SUBST block: SUBST_STAGE.repl missing.\n")
}
