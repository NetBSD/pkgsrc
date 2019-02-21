package pkglint

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
	t := s.Init(c)

	t.ExpectPanic(
		func() { mustMatch("aaa", `b`) },
		"Pkglint internal error: mustMatch \"aaa\" \"b\"")
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

	// Single dot components are removed, unless it's the only component of the path.
	c.Check(cleanpath("./././."), equals, ".")
	c.Check(cleanpath("./././"), equals, ".")
	c.Check(cleanpath("dir/multi/././/file"), equals, "dir/multi/file")
	c.Check(cleanpath("dir/"), equals, "dir")

	// Components like aa/bb/../.. are removed, but not in the initial part of the path,
	// and only if they are not followed by another "..".
	c.Check(cleanpath("dir/../dir/../dir/../dir/subdir/../../Makefile"), equals, "dir/../dir/../dir/../Makefile")
	c.Check(cleanpath("111/222/../../333/444/../../555/666/../../777/888/9"), equals, "111/222/../../777/888/9")
	c.Check(cleanpath("1/2/3/../../4/5/6/../../7/8/9/../../../../10"), equals, "1/2/3/../../4/7/8/9/../../../../10")
	c.Check(cleanpath("cat/pkg.v1/../../cat/pkg.v2/Makefile"), equals, "cat/pkg.v1/../../cat/pkg.v2/Makefile")
	c.Check(cleanpath("aa/../../../../../a/b/c/d"), equals, "aa/../../../../../a/b/c/d")
	c.Check(cleanpath("aa/bb/../../../../a/b/c/d"), equals, "aa/bb/../../../../a/b/c/d")
	c.Check(cleanpath("aa/bb/cc/../../../a/b/c/d"), equals, "aa/bb/cc/../../../a/b/c/d")
	c.Check(cleanpath("aa/bb/cc/dd/../../a/b/c/d"), equals, "aa/bb/a/b/c/d")
	c.Check(cleanpath("aa/bb/cc/dd/ee/../a/b/c/d"), equals, "aa/bb/cc/dd/ee/../a/b/c/d")
	c.Check(cleanpath("../../../../../a/b/c/d"), equals, "../../../../../a/b/c/d")
	c.Check(cleanpath("aa/../../../../a/b/c/d"), equals, "aa/../../../../a/b/c/d")
	c.Check(cleanpath("aa/bb/../../../a/b/c/d"), equals, "aa/bb/../../../a/b/c/d")
	c.Check(cleanpath("aa/bb/cc/../../a/b/c/d"), equals, "aa/bb/cc/../../a/b/c/d")
	c.Check(cleanpath("aa/bb/cc/dd/../a/b/c/d"), equals, "aa/bb/cc/dd/../a/b/c/d")
	c.Check(cleanpath("aa/../cc/../../a/b/c/d"), equals, "aa/../cc/../../a/b/c/d")

	// The initial 2 components of the path are typically category/package, when
	// pkglint is called from the pkgsrc top-level directory.
	// This path serves as the context and therefore is always kept.
	c.Check(cleanpath("aa/bb/../../cc/dd/../../ee/ff"), equals, "aa/bb/../../ee/ff")
	c.Check(cleanpath("aa/bb/../../cc/dd/../.."), equals, "aa/bb/../..")
	c.Check(cleanpath("aa/bb/cc/dd/../.."), equals, "aa/bb")
}

// Relpath is called so often that handling the most common calls
// without file system IO makes sense.
func (s *Suite) Test_relpath__quick(c *check.C) {

	test := func(from, to, result string) {
		c.Check(relpath(from, to), equals, result)
	}

	test("some/dir", "some/dir/../..", "../..")
	test("some/dir", "some/dir/./././../..", "../..")
	test("some/dir", "some/dir/", ".")
	test("some/dir", "some/directory", "../directory")

	test("category/package/.", ".", "../..")
}

// This is not really an internal error but won't happen in practice anyway.
// Therefore using ExpectPanic instead of ExpectFatal is ok.
func (s *Suite) Test_relpath__failure_on_Windows(c *check.C) {
	t := s.Init(c)

	if runtime.GOOS == "windows" {
		t.ExpectPanic(
			func() { relpath("c:/", "d:/") },
			"Pkglint internal error: relpath \"c:/\" \"d:/\": Rel: can't make d:/ relative to c:/")
	}
}

func (s *Suite) Test_abspath__failure_on_Windows(c *check.C) {
	t := s.Init(c)

	if runtime.GOOS == "windows" {
		t.ExpectPanic(
			func() { abspath("file\u0000name") },
			"Pkglint internal error: abspath \"file\\x00name\": invalid argument")
	}
}

func (s *Suite) Test_fileExists(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("dir/file")

	t.Check(fileExists(t.File("nonexistent")), equals, false)
	t.Check(fileExists(t.File("dir")), equals, false)
	t.Check(fileExists(t.File("dir/nonexistent")), equals, false)
	t.Check(fileExists(t.File("dir/file")), equals, true)
}

func (s *Suite) Test_dirExists(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("dir/file")

	t.Check(dirExists(t.File("nonexistent")), equals, false)
	t.Check(dirExists(t.File("dir")), equals, true)
	t.Check(dirExists(t.File("dir/nonexistent")), equals, false)
	t.Check(dirExists(t.File("dir/file")), equals, false)
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

func (s *Suite) Test_isEmptyDir(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("CVS/Entries",
		"dummy")
	t.CreateFileLines("subdir/CVS/Entries",
		"dummy")

	c.Check(isEmptyDir(t.File(".")), equals, true)
	c.Check(isEmptyDir(t.File("CVS")), equals, true)
}

func (s *Suite) Test_getSubdirs(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("subdir/file")
	t.CreateFileLines("empty/file")
	c.Check(os.Remove(t.File("empty/file")), check.IsNil)

	c.Check(getSubdirs(t.File(".")), deepEquals, []string{"subdir"})
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
	modTime := time.Unix(1136239445, 0).UTC()

	err := os.Chtimes(unmodified, modTime, modTime)
	c.Check(err, check.IsNil)

	st, err := os.Lstat(unmodified)
	c.Check(err, check.IsNil)

	// Make sure that the file system has second precision and accuracy.
	c.Check(st.ModTime().UTC(), check.DeepEquals, modTime)

	modified := t.CreateFileLines("modified")

	t.CreateFileLines("CVS/Entries",
		"//", // Just for code coverage.
		"/unmodified//"+modTime.Format(time.ANSIC)+"//",
		"/modified//"+modTime.Format(time.ANSIC)+"//",
		"/enoent//"+modTime.Format(time.ANSIC)+"//")

	c.Check(isLocallyModified(unmodified), equals, false)
	c.Check(isLocallyModified(modified), equals, true)
	c.Check(isLocallyModified(t.File("enoent")), equals, true)
	c.Check(isLocallyModified(t.File("not_mentioned")), equals, false)
	c.Check(isLocallyModified(t.File("subdir/file")), equals, false)

	t.DisableTracing()

	c.Check(isLocallyModified(t.File("unmodified")), equals, false)
}

func (s *Suite) Test_Scope_Define(c *check.C) {
	t := s.Init(c)

	scope := NewScope()
	scope.Define("BUILD_DIRS", t.NewMkLine("file.mk", 121, "BUILD_DIRS=\tone two three"))

	c.Check(scope.LastValue("BUILD_DIRS"), equals, "one two three")

	scope.Define("BUILD_DIRS", t.NewMkLine("file.mk", 123, "BUILD_DIRS+=\tfour"))

	c.Check(scope.LastValue("BUILD_DIRS"), equals, "one two three four")

	// Later default assignments do not have an effect.
	scope.Define("BUILD_DIRS", t.NewMkLine("file.mk", 123, "BUILD_DIRS?=\tdefault"))

	c.Check(scope.LastValue("BUILD_DIRS"), equals, "one two three four")
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

	c.Check(dst.firstDef, check.HasLen, 0)
	c.Check(dst.lastDef, check.HasLen, 0)
	c.Check(dst.used, check.HasLen, 0)

	src.Define("VAR", t.NewMkLine("file.mk", 1, "VAR=value"))
	dst.DefineAll(src)

	c.Check(dst.Defined("VAR"), equals, true)
}

func (s *Suite) Test_Scope_FirstDefinition(c *check.C) {
	t := s.Init(c)

	mkline1 := t.NewMkLine("fname.mk", 3, "VAR=\tvalue")
	mkline2 := t.NewMkLine("fname.mk", 3, ".if ${SNEAKY::=value}")

	scope := NewScope()
	scope.Define("VAR", mkline1)
	scope.Define("SNEAKY", mkline2)

	t.Check(scope.FirstDefinition("VAR"), equals, mkline1)

	// This call returns nil because it's not a variable assignment
	// and the calling code typically assumes a variable definition.
	// These sneaky variables with implicit definition are an edge
	// case that only few people actually know. It's better that way.
	t.Check(scope.FirstDefinition("SNEAKY"), check.IsNil)
}

func (s *Suite) Test_Scope_LastValue(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		MkRcsID,
		"VAR=\tfirst",
		"VAR=\tsecond",
		".if 1",
		"VAR=\tthird (conditional)",
		".endif")

	mklines.Check()

	t.Check(mklines.vars.LastValue("VAR"), equals, "third (conditional)")

	t.CheckOutputLines(
		"WARN: file.mk:2: VAR is defined but not used.")
}

func (s *Suite) Test_Scope__no_tracing(c *check.C) {
	t := s.Init(c)

	scope := NewScope()
	scope.Define("VAR.param", t.NewMkLine("fname.mk", 3, "VAR.param=\tvalue"))
	t.DisableTracing()

	t.Check(scope.DefinedSimilar("VAR.param"), equals, true)
	t.Check(scope.DefinedSimilar("VAR.other"), equals, true)
	t.Check(scope.DefinedSimilar("OTHER"), equals, false)
}

func (s *Suite) Test_naturalLess(c *check.C) {
	c.Check(naturalLess("", "a"), equals, true)
	c.Check(naturalLess("a", ""), equals, false)

	c.Check(naturalLess("a", "b"), equals, true)
	c.Check(naturalLess("b", "a"), equals, false)

	// Numbers are always considered smaller than other characters.
	c.Check(naturalLess("0", "!"), equals, true)
	c.Check(naturalLess("!", "0"), equals, false)

	c.Check(naturalLess("0", "a"), equals, true)
	c.Check(naturalLess("a", "0"), equals, false)

	c.Check(naturalLess("5", "12"), equals, true)
	c.Check(naturalLess("12", "5"), equals, false)

	c.Check(naturalLess("5", "7"), equals, true)
	c.Check(naturalLess("7", "5"), equals, false)

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

func (s *Suite) Test_FileCache(c *check.C) {
	t := s.Init(c)

	t.EnableTracingToLog()

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
	c.Check(linesFromCache.Lines[0].Filename, equals, "Makefile")

	// Cache keys are normalized using path.Clean.
	linesFromCache2 := cache.Get("./Makefile", 0)
	c.Check(linesFromCache2.FileName, equals, "./Makefile")
	c.Check(linesFromCache2.Lines, check.HasLen, 2)
	c.Check(linesFromCache2.Lines[0].Filename, equals, "./Makefile")

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
		"TRACE:   FileCache \"Makefile\" with count 4.",
		"TRACE:   FileCache \"file1.mk\" with count 2.",
		"TRACE:   FileCache \"file2.mk\" with count 2.",
		"TRACE:   FileCache.Evict \"file2.mk\" with count 2.",
		"TRACE:   FileCache.Evict \"file1.mk\" with count 2.",
		"TRACE:   FileCache.Halve \"Makefile\" with count 4.")
}

func (s *Suite) Test_makeHelp(c *check.C) {
	c.Check(makeHelp("subst"), equals, confMake+" help topic=subst")
}

func (s *Suite) Test_hasAlnumPrefix(c *check.C) {
	t := s.Init(c)

	t.Check(hasAlnumPrefix(""), equals, false)
	t.Check(hasAlnumPrefix("A"), equals, true)
	t.Check(hasAlnumPrefix(","), equals, false)
}

func (s *Suite) Test_Once(c *check.C) {
	var once Once

	c.Check(once.FirstTime("str"), equals, true)
	c.Check(once.FirstTime("str"), equals, false)
	c.Check(once.FirstTimeSlice("str"), equals, false)
	c.Check(once.FirstTimeSlice("str", "str2"), equals, true)
	c.Check(once.FirstTimeSlice("str", "str2"), equals, false)
}

func (s *Suite) Test_wrap(c *check.C) {

	wrapped := wrap(20,
		"See the pkgsrc guide, section \"Package components, Makefile\":",
		"https://www.NetBSD.org/doc/pkgsrc/pkgsrc.html#components.Makefile.",
		"",
		"For more information, ask on the tech-pkg@NetBSD.org mailing list.",
		"",
		"\tpreformatted line 1",
		"\tpreformatted line 2",
		"",
		"    intentionally indented",
		"*   itemization",
		"",
		"Normal",
		"text",
		"continues",
		"here",
		"with",
		"linebreaks.",
		"",
		"Sentence one.  Sentence two.",
		"",
		"A\tB\tC\tD",
		"E\tveryVeryVeryVeryVeryVeryVeryVeryLong")

	expected := []string{
		"See the pkgsrc",
		"guide, section",
		"\"Package components,",
		"Makefile\":",
		"https://www.NetBSD.org/doc/pkgsrc/pkgsrc.html#components.Makefile.",
		"",
		"For more",
		"information, ask on",
		"the",
		"tech-pkg@NetBSD.org",
		"mailing list.",
		"",
		"\tpreformatted line 1",
		"\tpreformatted line 2",
		"",
		"    intentionally indented",
		"*   itemization",
		"",
		"Normal text",
		"continues here with",
		"linebreaks.",
		"",
		"Sentence one.",
		"Sentence two.",
		"",
		"A\tB\tC\tD E",
		"veryVeryVeryVeryVeryVeryVeryVeryLong"}

	c.Check(wrapped, deepEquals, expected)
}

func (s *Suite) Test_escapePrintable(c *check.C) {
	c.Check(escapePrintable(""), equals, "")
	c.Check(escapePrintable("ASCII only~\n\t"), equals, "ASCII only~\n\t")
	c.Check(escapePrintable("Beep \u0007 control \u001F"), equals, "Beep <U+0007> control <U+001F>")
	c.Check(escapePrintable("Bad \xFF character"), equals, "Bad <\\xFF> character")
	c.Check(escapePrintable("Unicode \uFFFD replacement"), equals, "Unicode <U+FFFD> replacement")
}

func (s *Suite) Test_stringSliceLess(c *check.C) {
	var elements = [][][]string{
		{nil, {}},
		{{"a"}},
		{{"a", "a"}},
		{{"a", "b"}},
		{{"b"}},
		{{"b", "a"}}}

	test := func(i int, iElement []string, j int, jElement []string) {
		actual := stringSliceLess(iElement, jElement)
		expected := i < j
		if actual != expected {
			c.Check(
				[]interface{}{i, iElement, j, jElement, actual},
				check.DeepEquals,
				[]interface{}{i, iElement, j, jElement, expected})
		}
	}

	for i, iElements := range elements {
		for j, jElements := range elements {
			for _, iElement := range iElements {
				for _, jElement := range jElements {
					test(i, iElement, j, jElement)
				}
			}
		}
	}
}

func (s *Suite) Test_joinSkipEmpty(c *check.C) {
	t := s.Init(c)

	t.Check(
		joinSkipEmpty(", ", "", "one", "", "", "two", "", "three"),
		deepEquals,
		"one, two, three")
}

func (s *Suite) Test_joinSkipEmptyCambridge(c *check.C) {
	t := s.Init(c)

	t.Check(
		joinSkipEmptyCambridge("and", "", "one", "", "", "two", "", "three"),
		deepEquals,
		"one, two and three")

	t.Check(
		joinSkipEmptyCambridge("and", "", "one", "", ""),
		deepEquals,
		"one")
}

func (s *Suite) Test_joinSkipEmptyOxford(c *check.C) {
	t := s.Init(c)

	t.Check(
		joinSkipEmptyOxford("and", "", "one", "", "", "two", "", "three"),
		deepEquals,
		"one, two, and three")
}

func (s *Suite) Test_StringInterner(c *check.C) {
	t := s.Init(c)

	si := NewStringInterner()

	t.Check(si.Intern(""), equals, "")
	t.Check(si.Intern("Hello"), equals, "Hello")
	t.Check(si.Intern("Hello, world"), equals, "Hello, world")
	t.Check(si.Intern("Hello, world"[0:5]), equals, "Hello")
}

func (s *Suite) Test_includePath_includes(c *check.C) {
	t := s.Init(c)

	path := func(locations ...string) includePath {
		return includePath{locations}
	}

	var (
		m   = path("Makefile")
		mc  = path("Makefile", "Makefile.common")
		mco = path("Makefile", "Makefile.common", "other.mk")
		mo  = path("Makefile", "other.mk")
	)

	t.Check(m.includes(m), equals, false)

	t.Check(m.includes(mc), equals, true)
	t.Check(m.includes(mco), equals, true)
	t.Check(mc.includes(mco), equals, true)

	t.Check(mc.includes(m), equals, false)
	t.Check(mc.includes(mo), equals, false)
	t.Check(mo.includes(mc), equals, false)
}
