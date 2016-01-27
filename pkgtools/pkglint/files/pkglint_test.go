package main

import (
	"strings"

	check "gopkg.in/check.v1"
)

func (s *Suite) TestDetermineUsedVariables_simple(c *check.C) {
	mklines := s.NewMkLines("fname",
		"\t${VAR}")
	mkline := mklines.mklines[0]
	G.Mk = mklines

	mklines.DetermineUsedVariables()

	c.Check(len(mklines.varuse), equals, 1)
	c.Check(mklines.varuse["VAR"], equals, mkline)
}

func (s *Suite) TestDetermineUsedVariables_nested(c *check.C) {
	mklines := s.NewMkLines("fname",
		"\t${outer.${inner}}")
	mkline := mklines.mklines[0]
	G.Mk = mklines

	mklines.DetermineUsedVariables()

	c.Check(len(mklines.varuse), equals, 3)
	c.Check(mklines.varuse["inner"], equals, mkline)
	c.Check(mklines.varuse["outer."], equals, mkline)
	c.Check(mklines.varuse["outer.*"], equals, mkline)
}

func (s *Suite) TestResolveVariableRefs_CircularReference(c *check.C) {
	mkline := NewMkLine(NewLine("fname", 1, "GCC_VERSION=${GCC_VERSION}", nil))
	G.Pkg = NewPackage(".")
	G.Pkg.vardef["GCC_VERSION"] = mkline

	resolved := resolveVariableRefs("gcc-${GCC_VERSION}")

	c.Check(resolved, equals, "gcc-${GCC_VERSION}")
}

func (s *Suite) TestResolveVariableRefs_Multilevel(c *check.C) {
	mkline1 := NewMkLine(NewLine("fname", 10, "_=${SECOND}", nil))
	mkline2 := NewMkLine(NewLine("fname", 11, "_=${THIRD}", nil))
	mkline3 := NewMkLine(NewLine("fname", 12, "_=got it", nil))
	G.Pkg = NewPackage(".")
	defineVar(mkline1, "FIRST")
	defineVar(mkline2, "SECOND")
	defineVar(mkline3, "THIRD")

	resolved := resolveVariableRefs("you ${FIRST}")

	c.Check(resolved, equals, "you got it")
}

func (s *Suite) TestResolveVariableRefs_SpecialChars(c *check.C) {
	mkline := NewMkLine(NewLine("fname", 10, "_=x11", nil))
	G.Pkg = NewPackage("category/pkg")
	G.Pkg.vardef["GST_PLUGINS0.10_TYPE"] = mkline

	resolved := resolveVariableRefs("gst-plugins0.10-${GST_PLUGINS0.10_TYPE}/distinfo")

	c.Check(resolved, equals, "gst-plugins0.10-x11/distinfo")
}

func (s *Suite) TestChecklineRcsid(c *check.C) {
	lines := s.NewLines("fname",
		"$"+"NetBSD: dummy $",
		"$"+"NetBSD$",
		"$"+"Id: dummy $",
		"$"+"Id$",
		"$"+"FreeBSD$")

	for _, line := range lines {
		line.CheckRcsid(``, "")
	}

	c.Check(s.Output(), equals, ""+
		"ERROR: fname:3: Expected \"$"+"NetBSD$\".\n"+
		"ERROR: fname:4: Expected \"$"+"NetBSD$\".\n"+
		"ERROR: fname:5: Expected \"$"+"NetBSD$\".\n")
}

func (s *Suite) TestMatchVarassign(c *check.C) {
	checkVarassign := func(text string, ck check.Checker, varname, op, align, value, comment string) {
		type va struct {
			varname, op, align, value, comment string
		}
		expected := va{varname, op, align, value, comment}
		am, avarname, aop, aalign, avalue, acomment := MatchVarassign(text)
		if !am {
			c.Errorf("Text %q doesn’t match variable assignment", text)
			return
		}
		actual := va{avarname, aop, aalign, avalue, acomment}
		c.Check(actual, ck, expected)
	}
	checkNotVarassign := func(text string) {
		m, _, _, _, _, _ := MatchVarassign(text)
		if m {
			c.Errorf("Text %q matches variable assignment, but shouldn’t.", text)
		}
	}

	checkVarassign("C++=c11", equals, "C+", "+=", "C++=", "c11", "")
	checkVarassign("V=v", equals, "V", "=", "V=", "v", "")
	checkVarassign("VAR=#comment", equals, "VAR", "=", "VAR=", "", "#comment")
	checkVarassign("VAR=\\#comment", equals, "VAR", "=", "VAR=", "#comment", "")
	checkVarassign("VAR=\\\\\\##comment", equals, "VAR", "=", "VAR=", "\\\\#", "#comment")
	checkVarassign("VAR=\\", equals, "VAR", "=", "VAR=", "\\", "")
	checkVarassign("VAR += value", equals, "VAR", "+=", "VAR += ", "value", "")
	checkVarassign(" VAR=value", equals, "VAR", "=", " VAR=", "value", "")
	checkNotVarassign("\tVAR=value")
	checkNotVarassign("?=value")
	checkNotVarassign("<=value")
}

func (s *Suite) TestPackage_LoadPackageMakefile(c *check.C) {
	makefile := s.CreateTmpFile(c, "category/package/Makefile", ""+
		"# $"+"NetBSD$\n"+
		"\n"+
		"PKGNAME=pkgname-1.67\n"+
		"DISTNAME=distfile_1_67\n"+
		".include \"../../category/package/Makefile\"\n")
	pkg := NewPackage("category/package")
	G.CurrentDir = s.tmpdir + "/category/package"
	G.CurPkgsrcdir = "../.."
	G.Pkg = pkg

	pkg.loadPackageMakefile(makefile)

	c.Check(s.Output(), equals, "")
}

func (s *Suite) TestChecklinesDescr(c *check.C) {
	lines := s.NewLines("DESCR",
		strings.Repeat("X", 90),
		"", "", "", "", "", "", "", "", "10",
		"Try ${PREFIX}",
		"", "", "", "", "", "", "", "", "20",
		"", "", "", "", "", "", "", "", "", "30")

	ChecklinesDescr(lines)

	c.Check(s.Output(), equals, ""+
		"WARN: DESCR:1: Line too long (should be no more than 80 characters).\n"+
		"NOTE: DESCR:11: Variables are not expanded in the DESCR file.\n"+
		"WARN: DESCR:25: File too long (should be no more than 24 lines).\n")
}

func (s *Suite) TestChecklinesMessage_short(c *check.C) {
	lines := s.NewLines("MESSAGE",
		"one line")

	ChecklinesMessage(lines)

	c.Check(s.Output(), equals, "WARN: MESSAGE:1: File too short.\n")
}

func (s *Suite) TestChecklinesMessage_malformed(c *check.C) {
	lines := s.NewLines("MESSAGE",
		"1",
		"2",
		"3",
		"4",
		"5")

	ChecklinesMessage(lines)

	c.Check(s.Output(), equals, ""+
		"WARN: MESSAGE:1: Expected a line of exactly 75 \"=\" characters.\n"+
		"ERROR: MESSAGE:2: Expected \"$"+"NetBSD$\".\n"+
		"WARN: MESSAGE:5: Expected a line of exactly 75 \"=\" characters.\n")
}
