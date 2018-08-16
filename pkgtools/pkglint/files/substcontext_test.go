package main

import (
	"fmt"
	"gopkg.in/check.v1"
)

func (s *Suite) Test_SubstContext__incomplete(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wextra")
	ctx := NewSubstContext()

	ctx.Varassign(newSubstLine(t, 10, "PKGNAME=pkgname-1.0"))

	c.Check(ctx.id, equals, "")

	ctx.Varassign(newSubstLine(t, 11, "SUBST_CLASSES+=interp"))

	c.Check(ctx.id, equals, "interp")

	ctx.Varassign(newSubstLine(t, 12, "SUBST_FILES.interp=Makefile"))

	c.Check(ctx.IsComplete(), equals, false)

	ctx.Varassign(newSubstLine(t, 13, "SUBST_SED.interp=s,@PREFIX@,${PREFIX},g"))

	c.Check(ctx.IsComplete(), equals, false)

	ctx.Finish(newSubstLine(t, 14, ""))

	t.CheckOutputLines(
		"WARN: Makefile:14: Incomplete SUBST block: SUBST_STAGE.interp missing.")
}

func (s *Suite) Test_SubstContext__complete(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wextra")
	ctx := NewSubstContext()

	ctx.Varassign(newSubstLine(t, 10, "PKGNAME=pkgname-1.0"))
	ctx.Varassign(newSubstLine(t, 11, "SUBST_CLASSES+=p"))
	ctx.Varassign(newSubstLine(t, 12, "SUBST_FILES.p=Makefile"))
	ctx.Varassign(newSubstLine(t, 13, "SUBST_SED.p=s,@PREFIX@,${PREFIX},g"))

	c.Check(ctx.IsComplete(), equals, false)

	ctx.Varassign(newSubstLine(t, 14, "SUBST_STAGE.p=post-configure"))

	c.Check(ctx.IsComplete(), equals, true)

	ctx.Finish(newSubstLine(t, 15, ""))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_SubstContext__OPSYSVARS(c *check.C) {
	t := s.Init(c)

	G.opts.WarnExtra = true
	ctx := NewSubstContext()

	ctx.Varassign(newSubstLine(t, 11, "SUBST_CLASSES.SunOS+=prefix"))
	ctx.Varassign(newSubstLine(t, 12, "SUBST_CLASSES.NetBSD+=prefix"))
	ctx.Varassign(newSubstLine(t, 13, "SUBST_FILES.prefix=Makefile"))
	ctx.Varassign(newSubstLine(t, 14, "SUBST_SED.prefix=s,@PREFIX@,${PREFIX},g"))
	ctx.Varassign(newSubstLine(t, 15, "SUBST_STAGE.prefix=post-configure"))

	c.Check(ctx.IsComplete(), equals, true)

	ctx.Finish(newSubstLine(t, 15, ""))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_SubstContext__no_class(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wextra")
	ctx := NewSubstContext()

	ctx.Varassign(newSubstLine(t, 10, "UNRELATED=anything"))
	ctx.Varassign(newSubstLine(t, 11, "SUBST_FILES.repl+=Makefile.in"))
	ctx.Varassign(newSubstLine(t, 12, "SUBST_SED.repl+=-e s,from,to,g"))
	ctx.Finish(newSubstLine(t, 13, ""))

	t.CheckOutputLines(
		"WARN: Makefile:11: SUBST_CLASSES should come before the definition of \"SUBST_FILES.repl\".",
		"WARN: Makefile:13: Incomplete SUBST block: SUBST_STAGE.repl missing.")
}

func (s *Suite) Test_SubstContext__directives(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wextra")

	simulateSubstLines(t,
		"10: SUBST_CLASSES+=         os",
		"11: SUBST_STAGE.os=         post-configure",
		"12: SUBST_MESSAGE.os=       Guessing operating system",
		"13: SUBST_FILES.os=         guess-os.h",
		"14: .if ${OPSYS} == NetBSD",
		"15: SUBST_FILTER_CMD.os=    ${SED} -e s,@OPSYS@,NetBSD,",
		"16: .elif ${OPSYS} == Darwin",
		"17: SUBST_SED.os=           -e s,@OPSYS@,Darwin1,",
		"18: SUBST_SED.os=           -e s,@OPSYS@,Darwin2,",
		"19: .elif ${OPSYS} == Linux",
		"18: SUBST_SED.os=           -e s,@OPSYS@,Linux,",
		"19: .else",
		"20: SUBST_VARS.os=           OPSYS",
		"21: .endif",
		"22: ")

	// All the other lines are correctly determined as being alternatives
	// to each other. And since every branch contains some transformation
	// (SED, VARS, FILTER_CMD), everything is fine.
	t.CheckOutputLines(
		"WARN: Makefile:18: All but the first \"SUBST_SED.os\" lines should use the \"+=\" operator.")
}

func (s *Suite) Test_SubstContext__missing_transformation_in_one_branch(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wextra")

	simulateSubstLines(t,
		"10: SUBST_CLASSES+=         os",
		"11: SUBST_STAGE.os=         post-configure",
		"12: SUBST_MESSAGE.os=       Guessing operating system",
		"13: SUBST_FILES.os=         guess-os.h",
		"14: .if ${OPSYS} == NetBSD",
		"15: SUBST_FILES.os=         -e s,@OpSYS@,NetBSD,", // A simple typo, this should be SUBST_SED.
		"16: .elif ${OPSYS} == Darwin",
		"17: SUBST_SED.os=           -e s,@OPSYS@,Darwin1,",
		"18: SUBST_SED.os=           -e s,@OPSYS@,Darwin2,",
		"19: .else",
		"20: SUBST_VARS.os=           OPSYS",
		"21: .endif",
		"22: ")

	t.CheckOutputLines(
		"WARN: Makefile:15: All but the first \"SUBST_FILES.os\" lines should use the \"+=\" operator.",
		"WARN: Makefile:18: All but the first \"SUBST_SED.os\" lines should use the \"+=\" operator.",
		"WARN: Makefile:22: Incomplete SUBST block: SUBST_SED.os, SUBST_VARS.os or SUBST_FILTER_CMD.os missing.")
}

func (s *Suite) Test_SubstContext__nested_conditionals(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wextra")

	simulateSubstLines(t,
		"10: SUBST_CLASSES+=         os",
		"11: SUBST_STAGE.os=         post-configure",
		"12: SUBST_MESSAGE.os=       Guessing operating system",
		"14: .if ${OPSYS} == NetBSD",
		"13: SUBST_FILES.os=         guess-netbsd.h",
		"15: .  if ${ARCH} == i386",
		"16: SUBST_FILTER_CMD.os=    ${SED} -e s,@OPSYS,NetBSD-i386,",
		"17: .  elif ${ARCH} == x86_64",
		"18: SUBST_VARS.os=          OPSYS",
		"19: .  else",
		"20: SUBST_SED.os=           -e s,@OPSYS,NetBSD-unknown",
		"21: .  endif",
		"22: .else",
		"23: SUBST_SED.os=           -e s,@OPSYS@,unknown,",
		"24: .endif",
		"25: ")

	// The branch in line 23 omits SUBST_FILES.
	t.CheckOutputLines(
		"WARN: Makefile:25: Incomplete SUBST block: SUBST_FILES.os missing.")
}

func (s *Suite) Test_SubstContext__post_patch(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wextra,no-space", "--show-autofix")
	t.SetupVartypes()

	mklines := t.NewMkLines("os.mk",
		MkRcsID,
		"",
		"SUBST_CLASSES+=         os",
		"SUBST_STAGE.os=         post-patch",
		"SUBST_FILES.os=         guess-os.h",
		"SUBST_SED.os=           -e s,@OPSYS@,Darwin,")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: os.mk:4: Substitutions should not happen in the patch phase.",
		"AUTOFIX: os.mk:4: Replacing \"post-patch\" with \"pre-configure\".")
}

func (s *Suite) Test_SubstContext__adjacent(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wextra")
	t.SetupVartypes()

	mklines := t.NewMkLines("os.mk",
		MkRcsID,
		"",
		"SUBST_CLASSES+=         1",
		"SUBST_STAGE.1=          pre-configure",
		"SUBST_FILES.1=          file1",
		"SUBST_SED.1=            -e s,subst1,repl1,",
		"SUBST_CLASSES+=         2",
		"SUBST_SED.1+=           -e s,subst1b,repl1b,", // Misplaced
		"SUBST_STAGE.2=          pre-configure",
		"SUBST_FILES.2=          file2",
		"SUBST_SED.2=            -e s,subst2,repl2,")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: os.mk:8: Variable \"SUBST_SED.1\" does not match SUBST class \"2\".")
}

func (s *Suite) Test_SubstContext__do_patch(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wextra,no-space")
	t.SetupVartypes()

	mklines := t.NewMkLines("os.mk",
		MkRcsID,
		"",
		"SUBST_CLASSES+=         os",
		"SUBST_STAGE.os=         do-patch",
		"SUBST_FILES.os=         guess-os.h",
		"SUBST_SED.os=           -e s,@OPSYS@,Darwin,")

	mklines.Check()

	// No warning, since there is nothing to fix automatically.
	// This case also doesn't occur in practice.
	t.CheckOutputEmpty()
}

// simulateSubstLines only tests some of the inner workings of SubstContext.
// It is not realistic for all cases. If in doubt, use MkLines.Check.
func simulateSubstLines(t *Tester, texts ...string) {
	ctx := NewSubstContext()
	for _, lineText := range texts {
		var lineno int
		fmt.Sscanf(lineText[0:4], "%d: ", &lineno)
		text := lineText[4:]
		line := newSubstLine(t, lineno, text)

		switch {
		case text == "":
			ctx.Finish(line)
		case hasPrefix(text, "."):
			ctx.Directive(line)
		default:
			ctx.Varassign(line)
		}
	}
}

func newSubstLine(t *Tester, lineno int, text string) MkLine {
	return t.NewMkLine("Makefile", lineno, text)
}
