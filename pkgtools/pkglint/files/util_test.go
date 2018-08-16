package main

import (
	"gopkg.in/check.v1"
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/textproc"
	"testing"
)

func (s *Suite) Test_YesNoUnknown_String(c *check.C) {
	c.Check(yes.String(), equals, "yes")
	c.Check(no.String(), equals, "no")
	c.Check(unknown.String(), equals, "unknown")
}

func (s *Suite) Test_MkopSubst__middle(c *check.C) {
	c.Check(mkopSubst("pkgname", false, "kgna", false, "ri", ""), equals, "prime")
	c.Check(mkopSubst("pkgname", false, "pkgname", false, "replacement", ""), equals, "replacement")
}

func (s *Suite) Test_MkopSubst__left(c *check.C) {
	c.Check(mkopSubst("pkgname", true, "kgna", false, "ri", ""), equals, "pkgname")
	c.Check(mkopSubst("pkgname", true, "pkgname", false, "replacement", ""), equals, "replacement")
}

func (s *Suite) Test_MkopSubst__right(c *check.C) {
	c.Check(mkopSubst("pkgname", false, "kgna", true, "ri", ""), equals, "pkgname")
	c.Check(mkopSubst("pkgname", false, "pkgname", true, "replacement", ""), equals, "replacement")
}

func (s *Suite) Test_MkopSubst__leftRight(c *check.C) {
	c.Check(mkopSubst("pkgname", true, "kgna", true, "ri", ""), equals, "pkgname")
	c.Check(mkopSubst("pkgname", false, "pkgname", false, "replacement", ""), equals, "replacement")
}

func (s *Suite) Test_MkopSubst__gflag(c *check.C) {
	c.Check(mkopSubst("aaaaa", false, "a", false, "b", "g"), equals, "bbbbb")
	c.Check(mkopSubst("aaaaa", true, "a", false, "b", "g"), equals, "baaaa")
	c.Check(mkopSubst("aaaaa", false, "a", true, "b", "g"), equals, "aaaab")
	c.Check(mkopSubst("aaaaa", true, "a", true, "b", "g"), equals, "aaaaa")
}

func (s *Suite) Test_replaceFirst(c *check.C) {
	m, rest := regex.ReplaceFirst("a+b+c+d", `(\w)(.)(\w)`, "X")

	c.Assert(m, check.NotNil)
	c.Check(m, check.DeepEquals, []string{"a+b", "a", "+", "b"})
	c.Check(rest, equals, "X+c+d")
}

func (s *Suite) Test_tabLength(c *check.C) {
	c.Check(tabWidth("12345"), equals, 5)
	c.Check(tabWidth("\t"), equals, 8)
	c.Check(tabWidth("123\t"), equals, 8)
	c.Check(tabWidth("1234567\t"), equals, 8)
	c.Check(tabWidth("12345678\t"), equals, 16)
}

func (s *Suite) Test_cleanpath(c *check.C) {
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

func (s *Suite) Test_isEmptyDir_and_getSubdirs(c *check.C) {
	t := s.Init(c)

	t.SetupFileLines("CVS/Entries",
		"dummy")

	if dir := t.File("."); true {
		c.Check(isEmptyDir(dir), equals, true)
		c.Check(getSubdirs(dir), check.DeepEquals, []string(nil))

		t.SetupFileLines("somedir/file")

		c.Check(isEmptyDir(dir), equals, false)
		c.Check(getSubdirs(dir), check.DeepEquals, []string{"somedir"})
	}

	if absent := t.File("nonexistent"); true {
		c.Check(isEmptyDir(absent), equals, true) // Counts as empty.

		func() {
			defer t.ExpectFatalError()
			getSubdirs(absent) // Panics with a pkglintFatal.
		}()
		// The last group from the error message is localized, therefore the matching.
		c.Check(t.Output(), check.Matches, `FATAL: ~/nonexistent: Cannot be read: open ~/nonexistent: (.+)\n`)
	}
}

func (s *Suite) Test_PrefixReplacer_Since(c *check.C) {
	repl := textproc.NewPrefixReplacer("hello, world")
	mark := repl.Mark()
	repl.AdvanceRegexp(`^\w+`)
	c.Check(repl.Since(mark), equals, "hello")
}

func (s *Suite) Test_detab(c *check.C) {
	c.Check(detab(""), equals, "")
	c.Check(detab("\t"), equals, "        ")
	c.Check(detab("1234\t9"), equals, "1234    9")
	c.Check(detab("1234567\t"), equals, "1234567 ")
	c.Check(detab("12345678\t"), equals, "12345678        ")
}

const reMkIncludeBenchmark = `^\.(\s*)(s?include)\s+\"([^\"]+)\"\s*(?:#.*)?$`
const reMkIncludeBenchmarkPositive = `^\.(\s*)(s?include)\s+\"(.+)\"\s*(?:#.*)?$`

func Benchmark_match3_buildlink3(b *testing.B) {
	for i := 0; i < b.N; i++ {
		match3(".include \"../../category/package/buildlink3.mk\"", reMkIncludeBenchmark)
	}
}

func Benchmark_match3_bsd_pkg_mk(b *testing.B) {
	for i := 0; i < b.N; i++ {
		match3(".include \"../../mk/bsd.pkg.mk\"", reMkIncludeBenchmark)
	}
}

func Benchmark_match3_samedir(b *testing.B) {
	for i := 0; i < b.N; i++ {
		match3(".include \"options.mk\"", reMkIncludeBenchmark)
	}
}

func Benchmark_match3_bsd_pkg_mk_comment(b *testing.B) {
	for i := 0; i < b.N; i++ {
		match3(".include \"../../mk/bsd.pkg.mk\"          # infrastructure     ", reMkIncludeBenchmark)
	}
}

func Benchmark_match3_buildlink3_positive(b *testing.B) {
	for i := 0; i < b.N; i++ {
		match3(".include \"../../category/package/buildlink3.mk\"", reMkIncludeBenchmarkPositive)
	}
}

func Benchmark_match3_bsd_pkg_mk_positive(b *testing.B) {
	for i := 0; i < b.N; i++ {
		match3(".include \"../../mk/bsd.pkg.mk\"", reMkIncludeBenchmarkPositive)
	}
}

func Benchmark_match3_samedir_positive(b *testing.B) {
	for i := 0; i < b.N; i++ {
		match3(".include \"options.mk\"", reMkIncludeBenchmarkPositive)
	}
}

func Benchmark_match3_bsd_pkg_mk_comment_positive(b *testing.B) {
	for i := 0; i < b.N; i++ {
		match3(".include \"../../mk/bsd.pkg.mk\"          # infrastructure     ", reMkIncludeBenchmarkPositive)
	}
}

func Benchmark_match3_explicit(b *testing.B) {
	for i := 0; i < b.N; i++ {
		MatchMkInclude(".include \"../../mk/bsd.pkg.mk\"          # infrastructure     ")
	}
}

func emptyToNil(slice []string) []string {
	if len(slice) == 0 {
		return nil
	}
	return slice
}

func (s *Suite) Test_splitOnSpace(c *check.C) {
	c.Check(splitOnSpace("aaaaa"), deepEquals, []string{"aaaaa"})
	c.Check(splitOnSpace(" a b\tc\n"), deepEquals, []string{"a", "b", "c"})
	c.Check(splitOnSpace("     "), check.IsNil)
	c.Check(splitOnSpace(""), check.IsNil)
}
