package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestMkopSubst_middle(c *check.C) {
	c.Check(mkopSubst("pkgname", false, "kgna", false, "ri", false), equals, "prime")
	c.Check(mkopSubst("pkgname", false, "pkgname", false, "replacement", false), equals, "replacement")
}

func (s *Suite) TestMkopSubst_left(c *check.C) {
	c.Check(mkopSubst("pkgname", true, "kgna", false, "ri", false), equals, "pkgname")
	c.Check(mkopSubst("pkgname", true, "pkgname", false, "replacement", false), equals, "replacement")
}

func (s *Suite) TestMkopSubst_right(c *check.C) {
	c.Check(mkopSubst("pkgname", false, "kgna", true, "ri", false), equals, "pkgname")
	c.Check(mkopSubst("pkgname", false, "pkgname", true, "replacement", false), equals, "replacement")
}

func (s *Suite) TestMkopSubst_leftRight(c *check.C) {
	c.Check(mkopSubst("pkgname", true, "kgna", true, "ri", false), equals, "pkgname")
	c.Check(mkopSubst("pkgname", false, "pkgname", false, "replacement", false), equals, "replacement")
}

func (s *Suite) TestMkopSubst_all(c *check.C) {
	c.Check(mkopSubst("aaaaa", false, "a", false, "b", true), equals, "bbbbb")
	c.Check(mkopSubst("aaaaa", true, "a", false, "b", true), equals, "baaaa")
	c.Check(mkopSubst("aaaaa", false, "a", true, "b", true), equals, "aaaab")
	c.Check(mkopSubst("aaaaa", true, "a", true, "b", true), equals, "aaaaa")
}

func (s *Suite) TestReplaceFirst(c *check.C) {
	m, rest := replaceFirst("a+b+c+d", `(\w)(.)(\w)`, "X")

	c.Assert(m, check.NotNil)
	c.Check(m, check.DeepEquals, []string{"a+b", "a", "+", "b"})
	c.Check(rest, equals, "X+c+d")
}

func (s *Suite) TestTabLength(c *check.C) {
	c.Check(tabLength("12345"), equals, 5)
	c.Check(tabLength("\t"), equals, 8)
	c.Check(tabLength("123\t"), equals, 8)
	c.Check(tabLength("1234567\t"), equals, 8)
	c.Check(tabLength("12345678\t"), equals, 16)
}

func (s *Suite) TestCleanpath(c *check.C) {
	c.Check(cleanpath("simple/path"), equals, "simple/path")
	c.Check(cleanpath("/absolute/path"), equals, "/absolute/path")
	c.Check(cleanpath("./././."), equals, ".")
	c.Check(cleanpath("./././"), equals, ".")
	c.Check(cleanpath("dir/../dir/../dir/../dir/subdir/../../Makefile"), equals, "dir/../dir/../dir/../Makefile")
	c.Check(cleanpath("dir/multi/././/file"), equals, "dir/multi/file")
	c.Check(cleanpath("111/222/../../333/444/../../555/666/../../777/888/9"), equals, "111/222/../../777/888/9")
	c.Check(cleanpath("cat/pkg.v1/../../cat/pkg.v2/Makefile"), equals, "cat/pkg.v1/../../cat/pkg.v2/Makefile")
	c.Check(cleanpath("dir/"), equals, "dir")
}
