package main

import (
	"gopkg.in/check.v1"
	"os"
	"runtime"
	"testing"
	"time"
)

func (s *Suite) Test_YesNoUnknown_String(c *check.C) {
	c.Check(yes.String(), equals, "yes")
	c.Check(no.String(), equals, "no")
	c.Check(unknown.String(), equals, "unknown")
}

func (s *Suite) Test_mkopSubst__middle(c *check.C) {
	c.Check(mkopSubst("pkgname", false, "kgna", false, "ri", ""), equals, "prime")
	c.Check(mkopSubst("pkgname", false, "pkgname", false, "replacement", ""), equals, "replacement")
	c.Check(mkopSubst("aaaaaaa", false, "a", false, "b", ""), equals, "baaaaaa")
}

func (s *Suite) Test_mkopSubst__left(c *check.C) {
	c.Check(mkopSubst("pkgname", true, "kgna", false, "ri", ""), equals, "pkgname")
	c.Check(mkopSubst("pkgname", true, "pkgname", false, "replacement", ""), equals, "replacement")
}

func (s *Suite) Test_mkopSubst__right(c *check.C) {
	c.Check(mkopSubst("pkgname", false, "kgna", true, "ri", ""), equals, "pkgname")
	c.Check(mkopSubst("pkgname", false, "pkgname", true, "replacement", ""), equals, "replacement")
}

func (s *Suite) Test_mkopSubst__left_and_right(c *check.C) {
	c.Check(mkopSubst("pkgname", true, "kgna", true, "ri", ""), equals, "pkgname")
	c.Check(mkopSubst("pkgname", false, "pkgname", false, "replacement", ""), equals, "replacement")
}

func (s *Suite) Test_mkopSubst__gflag(c *check.C) {
	c.Check(mkopSubst("aaaaa", false, "a", false, "b", "g"), equals, "bbbbb")
	c.Check(mkopSubst("aaaaa", true, "a", false, "b", "g"), equals, "baaaa")
	c.Check(mkopSubst("aaaaa", false, "a", true, "b", "g"), equals, "aaaab")
	c.Check(mkopSubst("aaaaa", true, "a", true, "b", "g"), equals, "aaaaa")
}

func (s *Suite) Test__regex_ReplaceFirst(c *check.C) {
	m, rest := G.res.ReplaceFirst("a+b+c+d", `(\w)(.)(\w)`, "X")

	c.Assert(m, check.NotNil)
	c.Check(m, check.DeepEquals, []string{"a+b", "a", "+", "b"})
	c.Check(rest, equals, "X+c+d")
}

func (s *Suite) Test_mustMatch(c *check.C) {
	c.Check(
		func() { mustMatch("aaa", `b`) },
		check.Panics,
		"mustMatch \"aaa\" \"b\"")
}

func (s *Suite) Test_shorten(c *check.C) {
	c.Check(shorten("aaaaa", 3), equals, "aaa...")
	c.Check(shorten("aaaaa", 5), equals, "aaaaa")
	c.Check(shorten("aaa", 5), equals, "aaa")
}

func (s *Suite) Test_tabWidth(c *check.C) {
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
	c.Check(cleanpath("1/2/3/../../4/5/6/../../7/8/9/../../../../10"), equals, "1/10")
	c.Check(cleanpath("cat/pkg.v1/../../cat/pkg.v2/Makefile"), equals, "cat/pkg.v1/../../cat/pkg.v2/Makefile")
	c.Check(cleanpath("dir/"), equals, "dir")
}

// Relpath is called so often that handling the most common calls
// without file system IO makes sense.
func (s *Suite) Test_relpath__quick(c *check.C) {
	c.Check(relpath("some/dir", "some/dir/../.."), equals, "../..")
	c.Check(relpath("some/dir", "some/dir/./././../.."), equals, "../..")
	c.Check(relpath("some/dir", "some/dir/"), equals, ".")
	c.Check(relpath("some/dir", "some/directory"), equals, "../directory")
}

// This is not really an internal error but won't happen in practice anyway.
// Therefore using ExpectPanic instead of ExpectFatal is ok.
func (s *Suite) Test_relpath__failure_on_Windows(c *check.C) {
	t := s.Init(c)

	if runtime.GOOS == "windows" {
		t.ExpectPanic(
			func() { relpath("c:/", "d:/") },
			"Pkglint internal error: relpath \"c:/\" \"d:/\".")
	}
}

func (s *Suite) Test_abspath__on_Windows(c *check.C) {
	t := s.Init(c)

	if runtime.GOOS == "windows" {
		t.ExpectPanic(
			func() { abspath("file\u0000name") },
			"Pkglint internal error: abspath \"file\\x00name\".")
	}
}

func (s *Suite) Test_isEmptyDir__and_getSubdirs(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("CVS/Entries",
		"dummy")

	if dir := t.File("."); true {
		c.Check(isEmptyDir(dir), equals, true)
		c.Check(getSubdirs(dir), check.DeepEquals, []string(nil))

		t.CreateFileLines("somedir/file")

		c.Check(isEmptyDir(dir), equals, false)
		c.Check(getSubdirs(dir), check.DeepEquals, []string{"somedir"})
	}

	if absent := t.File("nonexistent"); true {
		c.Check(isEmptyDir(absent), equals, true) // Counts as empty.

		// The last group from the error message is localized, therefore the matching.
		t.ExpectFatalMatches(
			func() { getSubdirs(absent) },
			`FATAL: ~/nonexistent: Cannot be read: open ~/nonexistent: (.+)\n`)
	}
}

func (s *Suite) Test_isEmptyDir__empty_subdir(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("CVS/Entries",
		"dummy")
	t.CreateFileLines("subdir/CVS/Entries",
		"dummy")

	c.Check(isEmptyDir(t.File(".")), equals, true)
}

func (s *Suite) Test__PrefixReplacer_Since(c *check.C) {
	repl := G.NewPrefixReplacer("hello, world")
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

const reMkIncludeBenchmark = `^\.([\t ]*)(s?include)[\t ]+\"([^\"]+)\"[\t ]*(?:#.*)?$`
const reMkIncludeBenchmarkPositive = `^\.([\t ]*)(s?include)[\t ]+\"(.+)\"[\t ]*(?:#.*)?$`

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

func Benchmark_match3_same_dir(b *testing.B) {
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

func Benchmark_match3_same_dir_positive(b *testing.B) {
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

func (s *Suite) Test_isLocallyModified(c *check.C) {
	t := s.Init(c)

	unmodified := t.CreateFileLines("unmodified")
	modTime := time.Unix(1136239445, 0)

	err := os.Chtimes(unmodified, modTime, modTime)
	c.Check(err, check.IsNil)

	st, err := os.Lstat(unmodified)
	c.Check(err, check.IsNil)

	// Make sure that the file system has second precision and accuracy.
	c.Check(st.ModTime(), check.DeepEquals, modTime)

	modified := t.CreateFileLines("modified")

	t.CreateFileLines("CVS/Entries",
		"/unmodified//"+modTime.Format(time.ANSIC)+"//",
		"/modified//"+modTime.Format(time.ANSIC)+"//",
		"/enoent//"+modTime.Format(time.ANSIC)+"//")

	c.Check(isLocallyModified(unmodified), equals, false)
	c.Check(isLocallyModified(modified), equals, true)
	c.Check(isLocallyModified(t.File("enoent")), equals, true)
	c.Check(isLocallyModified(t.File("not_mentioned")), equals, false)
	c.Check(isLocallyModified(t.File("subdir/file")), equals, false)
}

func (s *Suite) Test_Scope_Defined(c *check.C) {
	t := s.Init(c)

	scope := NewScope()
	scope.Define("VAR.param", t.NewMkLine("file.mk", 1, "VAR.param=value"))

	c.Check(scope.Defined("VAR.param"), equals, true)
	c.Check(scope.Defined("VAR.other"), equals, false)
	c.Check(scope.Defined("VARIABLE.*"), equals, false)

	c.Check(scope.DefinedSimilar("VAR.param"), equals, true)
	c.Check(scope.DefinedSimilar("VAR.other"), equals, true)
	c.Check(scope.DefinedSimilar("VARIABLE.*"), equals, false)
}

func (s *Suite) Test_Scope_Used(c *check.C) {
	t := s.Init(c)

	scope := NewScope()
	scope.Use("VAR.param", t.NewMkLine("file.mk", 1, "\techo ${VAR.param}"))

	c.Check(scope.Used("VAR.param"), equals, true)
	c.Check(scope.Used("VAR.other"), equals, false)
	c.Check(scope.Used("VARIABLE.*"), equals, false)

	c.Check(scope.UsedSimilar("VAR.param"), equals, true)
	c.Check(scope.UsedSimilar("VAR.other"), equals, true)
	c.Check(scope.UsedSimilar("VARIABLE.*"), equals, false)
}

func (s *Suite) Test_Scope_DefineAll(c *check.C) {
	t := s.Init(c)

	src := NewScope()

	dst := NewScope()
	dst.DefineAll(src)

	c.Check(dst.defined, check.HasLen, 0)
	c.Check(dst.used, check.HasLen, 0)

	src.Define("VAR", t.NewMkLine("file.mk", 1, "VAR=value"))
	dst.DefineAll(src)

	c.Check(dst.Defined("VAR"), equals, true)
}

func (s *Suite) Test_naturalLess(c *check.C) {
	c.Check(naturalLess("0", "a"), equals, true)
	c.Check(naturalLess("a", "0"), equals, false)
	c.Check(naturalLess("000", "0000"), equals, true)
	c.Check(naturalLess("0000", "000"), equals, false)
	c.Check(naturalLess("000", "000"), equals, false)
	c.Check(naturalLess("00011", "000111"), equals, true)
	c.Check(naturalLess("00011", "00012"), equals, true)
}

func (s *Suite) Test_varnameBase(c *check.C) {
	c.Check(varnameBase("VAR"), equals, "VAR")
	c.Check(varnameBase("VAR.param"), equals, "VAR")
	c.Check(varnameBase(".CURDIR"), equals, ".CURDIR")
}

func (s *Suite) Test_varnameParam(c *check.C) {
	c.Check(varnameParam("VAR"), equals, "")
	c.Check(varnameParam("VAR.param"), equals, "param")
	c.Check(varnameParam(".CURDIR"), equals, "")
}

func (s *Suite) Test_varnameCanon(c *check.C) {
	c.Check(varnameCanon("VAR"), equals, "VAR")
	c.Check(varnameCanon("VAR.param"), equals, "VAR.*")
	c.Check(varnameCanon(".CURDIR"), equals, ".CURDIR")
}

func (s *Suite) Test_isalnum(c *check.C) {
	c.Check(isalnum(""), equals, true)
	c.Check(isalnum("/"), equals, false)
	c.Check(isalnum("0"), equals, true)
	c.Check(isalnum("9"), equals, true)
	c.Check(isalnum(":"), equals, false)
	c.Check(isalnum("@"), equals, false)
	c.Check(isalnum("A"), equals, true)
	c.Check(isalnum("Z"), equals, true)
	c.Check(isalnum("["), equals, false)
	c.Check(isalnum("_"), equals, true)
	c.Check(isalnum("`"), equals, false)
	c.Check(isalnum("a"), equals, true)
	c.Check(isalnum("z"), equals, true)
	c.Check(isalnum("{"), equals, false)
	c.Check(isalnum("Hello_world005"), equals, true)
	c.Check(isalnum("Hello,world005"), equals, false)
}

func (s *Suite) Test_FileCache(c *check.C) {
	t := s.Init(c)

	cache := NewFileCache(3)

	lines := t.NewLines("Makefile",
		MkRcsID,
		"# line 2")

	c.Check(cache.Get("Makefile", 0), check.IsNil)
	c.Check(cache.hits, equals, 0)
	c.Check(cache.misses, equals, 1)

	cache.Put("Makefile", 0, lines)
	c.Check(cache.Get("Makefile", MustSucceed|LogErrors), check.IsNil) // Wrong LoadOptions.

	linesFromCache := cache.Get("Makefile", 0)
	c.Check(linesFromCache.FileName, equals, "Makefile")
	c.Check(linesFromCache.Lines, check.HasLen, 2)
	c.Check(linesFromCache.Lines[0].FileName, equals, "Makefile")

	// Cache keys are normalized using path.Clean.
	linesFromCache2 := cache.Get("./Makefile", 0)
	c.Check(linesFromCache2.FileName, equals, "./Makefile")
	c.Check(linesFromCache2.Lines, check.HasLen, 2)
	c.Check(linesFromCache2.Lines[0].FileName, equals, "./Makefile")

	cache.Put("file1.mk", 0, lines)
	cache.Put("file2.mk", 0, lines)

	// Now the cache is full. All three entries can be retrieved.
	c.Check(cache.Get("Makefile", 0), check.NotNil)
	c.Check(cache.Get("file1.mk", 0), check.NotNil)
	c.Check(cache.Get("file2.mk", 0), check.NotNil)

	// Adding another entry removes all entries with minimum count,
	// which currently are file1.mk and file2.mk.
	// Makefile is still in the cache because it was accessed once.
	cache.Put("file3.mk", 0, lines)

	c.Check(cache.Get("Makefile", 0), check.NotNil)
	c.Check(cache.Get("file1.mk", 0), check.IsNil)
	c.Check(cache.Get("file2.mk", 0), check.IsNil)
	c.Check(cache.Get("file3.mk", 0), check.NotNil)

	cache.Evict("Makefile")

	c.Check(cache.Get("Makefile", 0), check.IsNil)
	c.Check(cache.table, check.HasLen, 1)
	c.Check(cache.mapping, check.HasLen, 1)
	c.Check(cache.hits, equals, 7)
	c.Check(cache.misses, equals, 5)

	t.CheckOutputLines(
		"FileCache \"Makefile\" with count 4.",
		"FileCache \"file1.mk\" with count 2.",
		"FileCache \"file2.mk\" with count 2.",
		"FileCache.Evict \"file2.mk\" with count 2.",
		"FileCache.Evict \"file1.mk\" with count 2.",
		"FileCache.Halve \"Makefile\" with count 4.")
}

func (s *Suite) Test_makeHelp(c *check.C) {
	c.Check(makeHelp("subst"), equals, confMake+" help topic=subst")
}
