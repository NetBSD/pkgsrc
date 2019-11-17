package pkglint

import (
	"errors"
	"gopkg.in/check.v1"
	"os"
	"testing"
	"time"
)

func (s *Suite) Test_YesNoUnknown_String(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(yes.String(), "yes")
	t.CheckEquals(no.String(), "no")
	t.CheckEquals(unknown.String(), "unknown")
}

func (s *Suite) Test_trimHspace(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(trimHspace("a b"), "a b")
	t.CheckEquals(trimHspace(" a b "), "a b")
	t.CheckEquals(trimHspace("\ta b\t"), "a b")
	t.CheckEquals(trimHspace(" \t a b\t \t"), "a b")
}

func (s *Suite) Test_trimCommon(c *check.C) {
	t := s.Init(c)

	test := func(a, b, trimmedA, trimmedB string) {
		ta, tb := trimCommon(a, b)
		t.CheckEquals(ta, trimmedA)
		t.CheckEquals(tb, trimmedB)
	}

	test("", "",
		"", "")

	test("equal", "equal",
		"", "")

	test("prefixA", "prefixB",
		"A", "B")

	test("ASuffix", "BSuffix",
		"A", "B")

	test("PreMiddlePost", "PreCenterPost",
		"Middle", "Center")

	test("", "b",
		"", "b")

	test("a", "",
		"a", "")
}

func (s *Suite) Test_assertNil(c *check.C) {
	t := s.Init(c)

	assertNil(nil, "this is not an error")

	t.ExpectPanic(
		func() { assertNil(errors.New("unexpected error"), "Oops") },
		"Pkglint internal error: Oops: unexpected error")
}

func (s *Suite) Test_assertNotNil(c *check.C) {
	t := s.Init(c)

	assertNotNil("this string is not nil")

	t.ExpectPanic(
		func() { assertNotNil(nil) },
		"Pkglint internal error: unexpected nil pointer")
	t.ExpectPanic(
		func() { var ptr *string; assertNotNil(ptr) },
		"Pkglint internal error: unexpected nil pointer")
}

func (s *Suite) Test_isEmptyDir(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("CVS/Entries",
		"dummy")
	t.CreateFileLines("subdir/CVS/Entries",
		"dummy")

	t.CheckEquals(isEmptyDir(t.File(".")), true)
	t.CheckEquals(isEmptyDir(t.File("CVS")), true)
}

func (s *Suite) Test_isEmptyDir__and_getSubdirs(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("CVS/Entries",
		"dummy")

	if dir := t.File("."); true {
		t.CheckEquals(isEmptyDir(dir), true)
		t.CheckDeepEquals(getSubdirs(dir), []string(nil))

		t.CreateFileLines("somedir/file")

		t.CheckEquals(isEmptyDir(dir), false)
		t.CheckDeepEquals(getSubdirs(dir), []string{"somedir"})
	}

	if absent := t.File("nonexistent"); true {
		t.CheckEquals(isEmptyDir(absent), true) // Counts as empty.

		// The last group from the error message is localized, therefore the matching.
		t.ExpectFatalMatches(
			func() { getSubdirs(absent) },
			`FATAL: ~/nonexistent: Cannot be read: open ~/nonexistent: (.+)\n`)
	}
}

func (s *Suite) Test_getSubdirs(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("subdir/file")
	t.CreateFileLines("empty/file")
	c.Check(os.Remove(t.File("empty/file")), check.IsNil)

	t.CheckDeepEquals(getSubdirs(t.File(".")), []string{"subdir"})
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
	t.CheckDeepEquals(st.ModTime().UTC(), modTime)

	modified := t.CreateFileLines("modified")

	t.CreateFileLines("CVS/Entries",
		"/unmodified//"+modTime.Format(time.ANSIC)+"//",
		"/modified//"+modTime.Format(time.ANSIC)+"//",
		"/enoent//"+modTime.Format(time.ANSIC)+"//")

	t.CheckEquals(isLocallyModified(unmodified), false)
	t.CheckEquals(isLocallyModified(modified), true)
	t.CheckEquals(isLocallyModified(t.File("enoent")), true)
	t.CheckEquals(isLocallyModified(t.File("not_mentioned")), false)
	t.CheckEquals(isLocallyModified(t.File("subdir/file")), false)

	t.DisableTracing()

	t.CheckEquals(isLocallyModified(t.File("unmodified")), false)
}

func (s *Suite) Test_tabWidth(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(tabWidth("12345"), 5)
	t.CheckEquals(tabWidth("\t"), 8)
	t.CheckEquals(tabWidth("123\t"), 8)
	t.CheckEquals(tabWidth("1234567\t"), 8)
	t.CheckEquals(tabWidth("12345678\t"), 16)
}

// Since tabWidthAppend is used with logical lines (Line.Text) as well as with
// raw lines (RawLine.textnl or RawLine.orignl), and since the width only
// makes sense for a single line, better panic.
func (s *Suite) Test_tabWidthAppend__panic(c *check.C) {
	t := s.Init(c)

	t.ExpectAssert(func() { tabWidthAppend(0, "\n") })
}

func (s *Suite) Test_detab(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(detab(""), "")
	t.CheckEquals(detab("\t"), "        ")
	t.CheckEquals(detab("1234\t9"), "1234    9")
	t.CheckEquals(detab("1234567\t"), "1234567 ")
	t.CheckEquals(detab("12345678\t"), "12345678        ")
}

func (s *Suite) Test_alignWith(c *check.C) {
	t := s.Init(c)

	test := func(str, other, expected string) {
		t.CheckEquals(alignWith(str, other), expected)
	}

	// At least one tab is _always_ added.
	test("", "", "\t")

	test("VAR=", "1234567", "VAR=\t")
	test("VAR=", "12345678", "VAR=\t")
	test("VAR=", "123456789", "VAR=\t\t")

	// At least one tab is added in any case,
	// even if the other string is shorter.
	test("1234567890=", "V=", "1234567890=\t")
}

func (s *Suite) Test_indent(c *check.C) {
	t := s.Init(c)

	test := func(width int, ind string) {
		actual := indent(width)

		t.CheckEquals(actual, ind)
	}

	test(0, "")
	test(1, " ")
	test(7, "       ")
	test(8, "\t")
	test(15, "\t       ")
	test(16, "\t\t")
	test(72, "\t\t\t\t\t\t\t\t\t")
}

func (s *Suite) Test_alignmentAfter(c *check.C) {
	t := s.Init(c)

	test := func(prefix string, width int, ind string) {
		actual := alignmentAfter(prefix, width)

		t.CheckEquals(actual, ind)
	}

	test("", 0, "")
	test("", 15, "\t       ")

	test("  ", 5, "   ")
	test("      ", 10, "\t  ")

	test("\t", 15, "       ")
	test(" \t", 15, "       ")
	test("       \t", 15, "       ")
	test("\t    ", 15, "   ")

	test("    ", 16, "\t\t")

	// The desired width must be at least the width of the prefix.
	t.ExpectAssert(func() { test("\t", 7, "") })
}

func (s *Suite) Test_shorten(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(shorten("aaaaa", 3), "aaa...")
	t.CheckEquals(shorten("aaaaa", 5), "aaaaa")
	t.CheckEquals(shorten("aaa", 5), "aaa")
}

func (s *Suite) Test_varnameBase(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(varnameBase("VAR"), "VAR")
	t.CheckEquals(varnameBase("VAR.param"), "VAR")
	t.CheckEquals(varnameBase(".CURDIR"), ".CURDIR")
}

func (s *Suite) Test_varnameCanon(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(varnameCanon("VAR"), "VAR")
	t.CheckEquals(varnameCanon("VAR.param"), "VAR.*")
	t.CheckEquals(varnameCanon(".CURDIR"), ".CURDIR")
}

func (s *Suite) Test_varnameParam(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(varnameParam("VAR"), "")
	t.CheckEquals(varnameParam("VAR.param"), "param")
	t.CheckEquals(varnameParam(".CURDIR"), "")
}

func (s *Suite) Test_fileExists(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("dir/file")

	t.CheckEquals(fileExists(t.File("nonexistent")), false)
	t.CheckEquals(fileExists(t.File("dir")), false)
	t.CheckEquals(fileExists(t.File("dir/nonexistent")), false)
	t.CheckEquals(fileExists(t.File("dir/file")), true)
}

func (s *Suite) Test_dirExists(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("dir/file")

	t.CheckEquals(dirExists(t.File("nonexistent")), false)
	t.CheckEquals(dirExists(t.File("dir")), true)
	t.CheckEquals(dirExists(t.File("dir/nonexistent")), false)
	t.CheckEquals(dirExists(t.File("dir/file")), false)
}

func (s *Suite) Test_mkopSubst__middle(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(mkopSubst("pkgname", false, "kgna", false, "ri", ""), "prime")
	t.CheckEquals(mkopSubst("pkgname", false, "pkgname", false, "replacement", ""), "replacement")
	t.CheckEquals(mkopSubst("aaaaaaa", false, "a", false, "b", ""), "baaaaaa")
}

func (s *Suite) Test_mkopSubst__left(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(mkopSubst("pkgname", true, "kgna", false, "ri", ""), "pkgname")
	t.CheckEquals(mkopSubst("pkgname", true, "pkgname", false, "replacement", ""), "replacement")
}

func (s *Suite) Test_mkopSubst__right(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(mkopSubst("pkgname", false, "kgna", true, "ri", ""), "pkgname")
	t.CheckEquals(mkopSubst("pkgname", false, "pkgname", true, "replacement", ""), "replacement")
}

func (s *Suite) Test_mkopSubst__left_and_right(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(mkopSubst("pkgname", true, "kgna", true, "ri", ""), "pkgname")
	t.CheckEquals(mkopSubst("pkgname", false, "pkgname", false, "replacement", ""), "replacement")
}

func (s *Suite) Test_mkopSubst__gflag(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(mkopSubst("aaaaa", false, "a", false, "b", "g"), "bbbbb")
	t.CheckEquals(mkopSubst("aaaaa", true, "a", false, "b", "g"), "baaaa")
	t.CheckEquals(mkopSubst("aaaaa", false, "a", true, "b", "g"), "aaaab")
	t.CheckEquals(mkopSubst("aaaaa", true, "a", true, "b", "g"), "aaaaa")
}

func (s *Suite) Test__regex_ReplaceFirst(c *check.C) {
	t := s.Init(c)

	m, rest := G.res.ReplaceFirst("a+b+c+d", `(\w)(.)(\w)`, "X")

	c.Assert(m, check.NotNil)
	t.CheckDeepEquals(m, []string{"a+b", "a", "+", "b"})
	t.CheckEquals(rest, "X+c+d")
}

func (s *Suite) Test_relpath(c *check.C) {
	t := s.Init(c)

	t.Chdir(".")
	t.CheckEquals(G.Pkgsrc.topdir, t.tmpdir)

	test := func(from, to, result string) {
		t.CheckEquals(relpath(from, to), result)
	}

	test("some/dir", "some/directory", "../../some/directory")
	test("some/directory", "some/dir", "../../some/dir")

	test("category/package/.", ".", "../..")

	// This case is handled by one of the shortcuts that avoid file system access.
	test(
		"./.",
		"x11/frameworkintegration/../../meta-pkgs/kde/kf5.mk",
		"meta-pkgs/kde/kf5.mk")

	test(".hidden/dir", ".", "../..")
	test("dir/.hidden", ".", "../..")

	// This happens when "pkglint -r x11" is run.
	G.Pkgsrc.topdir = "x11/.."

	test(
		"./.",
		"x11/frameworkintegration/../../meta-pkgs/kde/kf5.mk",
		"meta-pkgs/kde/kf5.mk")
	test(
		"x11/..",
		"x11/frameworkintegration/../../meta-pkgs/kde/kf5.mk",
		"meta-pkgs/kde/kf5.mk")
}

// Relpath is called so often that handling the most common calls
// without file system IO makes sense.
func (s *Suite) Test_relpath__quick(c *check.C) {
	t := s.Init(c)

	test := func(from, to, result string) {
		t.CheckEquals(relpath(from, to), result)
	}

	test("some/dir", "some/dir/../..", "../..")
	test("some/dir", "some/dir/./././../..", "../..")
	test("some/dir", "some/dir/", ".")

	test("some/dir", ".", "../..")
	test("some/dir/.", ".", "../..")
}

func (s *Suite) Test_cleanpath(c *check.C) {
	t := s.Init(c)

	test := func(from, to string) {
		t.CheckEquals(cleanpath(from), to)
	}

	test("simple/path", "simple/path")
	test("/absolute/path", "/absolute/path")

	// Single dot components are removed, unless it's the only component of the path.
	test("./././.", ".")
	test("./././", ".")
	test("dir/multi/././/file", "dir/multi/file")
	test("dir/", "dir")

	test("dir/", "dir")

	// Components like aa/bb/../.. are removed, but not in the initial part of the path,
	// and only if they are not followed by another "..".
	test("dir/../dir/../dir/../dir/subdir/../../Makefile", "dir/../dir/../dir/../Makefile")
	test("111/222/../../333/444/../../555/666/../../777/888/9", "111/222/../../777/888/9")
	test("1/2/3/../../4/5/6/../../7/8/9/../../../../10", "1/2/3/../../4/7/8/9/../../../../10")
	test("cat/pkg.v1/../../cat/pkg.v2/Makefile", "cat/pkg.v1/../../cat/pkg.v2/Makefile")
	test("aa/../../../../../a/b/c/d", "aa/../../../../../a/b/c/d")
	test("aa/bb/../../../../a/b/c/d", "aa/bb/../../../../a/b/c/d")
	test("aa/bb/cc/../../../a/b/c/d", "aa/bb/cc/../../../a/b/c/d")
	test("aa/bb/cc/dd/../../a/b/c/d", "aa/bb/a/b/c/d")
	test("aa/bb/cc/dd/ee/../a/b/c/d", "aa/bb/cc/dd/ee/../a/b/c/d")
	test("../../../../../a/b/c/d", "../../../../../a/b/c/d")
	test("aa/../../../../a/b/c/d", "aa/../../../../a/b/c/d")
	test("aa/bb/../../../a/b/c/d", "aa/bb/../../../a/b/c/d")
	test("aa/bb/cc/../../a/b/c/d", "aa/bb/cc/../../a/b/c/d")
	test("aa/bb/cc/dd/../a/b/c/d", "aa/bb/cc/dd/../a/b/c/d")
	test("aa/../cc/../../a/b/c/d", "aa/../cc/../../a/b/c/d")

	// The initial 2 components of the path are typically category/package, when
	// pkglint is called from the pkgsrc top-level directory.
	// This path serves as the context and therefore is always kept.
	test("aa/bb/../../cc/dd/../../ee/ff", "aa/bb/../../ee/ff")
	test("aa/bb/../../cc/dd/../..", "aa/bb/../..")
	test("aa/bb/cc/dd/../..", "aa/bb")
	test("aa/bb/../../cc/dd/../../ee/ff/buildlink3.mk", "aa/bb/../../ee/ff/buildlink3.mk")
	test("./aa/bb/../../cc/dd/../../ee/ff/buildlink3.mk", "aa/bb/../../ee/ff/buildlink3.mk")

	test("../.", "..")
	test("../././././././.", "..")
	test(".././././././././", "..")
}

func (s *Suite) Test_pathContains(c *check.C) {
	t := s.Init(c)

	test := func(haystack, needle string, expected bool) {
		actual := pathContains(haystack, needle)
		t.CheckEquals(actual, expected)
	}

	testPanic := func(haystack, needle string) {
		t.c.Check(
			func() { _ = pathContains(haystack, needle) },
			check.PanicMatches,
			`runtime error: index out of range.*`)
	}

	testPanic("", "")
	testPanic("a", "")
	testPanic("a/b/c", "")

	test("a", "a", true)
	test("a", "b", false)
	test("a", "A", false)
	test("a/b/c", "a", true)
	test("a/b/c", "b", true)
	test("a/b/c", "c", true)
	test("a/b/c", "a/b", true)
	test("a/b/c", "b/c", true)
	test("a/b/c", "a/b/c", true)
	test("aa/bb/cc", "a/b", false)
	test("aa/bb/cc", "a/bb", false)
	test("aa/bb/cc", "aa/b", false)
	test("aa/bb/cc", "aa/bb", true)
	test("aa/bb/cc", "a", false)
	test("aa/bb/cc", "b", false)
	test("aa/bb/cc", "c", false)
}

func (s *Suite) Test_pathContainsDir(c *check.C) {
	t := s.Init(c)

	test := func(haystack, needle string, expected bool) {
		actual := pathContainsDir(haystack, needle)
		t.CheckEquals(actual, expected)
	}

	testPanic := func(haystack, needle string) {
		t.c.Check(
			func() { _ = pathContainsDir(haystack, needle) },
			check.PanicMatches,
			`^runtime error: index out of range.*`)
	}

	testPanic("", "")
	testPanic("a", "")
	testPanic("a/b/c", "")

	test("a", "a", false)
	test("a", "b", false)
	test("a", "A", false)
	test("a/b/c", "a", true)
	test("a/b/c", "b", true)
	test("a/b/c", "c", false)
	test("a/b/c", "a/b", true)
	test("a/b/c", "b/c", false)
	test("a/b/c", "a/b/c", false)
	test("aa/bb/cc", "a/b", false)
	test("aa/bb/cc", "a/bb", false)
	test("aa/bb/cc", "aa/b", false)
	test("aa/bb/cc", "aa/bb", true)
	test("aa/bb/cc", "a", false)
	test("aa/bb/cc", "b", false)
	test("aa/bb/cc", "c", false)
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

func (s *Suite) Test_hasAlnumPrefix(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(hasAlnumPrefix(""), false)
	t.CheckEquals(hasAlnumPrefix("A"), true)
	t.CheckEquals(hasAlnumPrefix(","), false)
}

func (s *Suite) Test_Once(c *check.C) {
	t := s.Init(c)

	var once Once

	t.CheckEquals(once.FirstTime("str"), true)
	t.CheckEquals(once.FirstTime("str"), false)
	t.CheckEquals(once.FirstTimeSlice("str"), false)
	t.CheckEquals(once.FirstTimeSlice("str", "str2"), true)
	t.CheckEquals(once.FirstTimeSlice("str", "str2"), false)
}

func (s *Suite) Test_Once__trace(c *check.C) {
	t := s.Init(c)

	var once Once
	once.Trace = true

	t.CheckEquals(once.FirstTime("str"), true)
	t.CheckEquals(once.FirstTime("str"), false)
	t.CheckEquals(once.FirstTimeSlice("str"), false)
	t.CheckEquals(once.FirstTimeSlice("str", "str2"), true)
	t.CheckEquals(once.FirstTimeSlice("str", "str2"), false)

	t.CheckOutputLines(
		"FirstTime: str",
		"FirstTime: str, str2")
}

func (s *Suite) Test_Scope__no_tracing(c *check.C) {
	t := s.Init(c)

	scope := NewScope()
	scope.Define("VAR.param", t.NewMkLine("fname.mk", 3, "VAR.param=\tvalue"))
	t.DisableTracing()

	t.CheckEquals(scope.IsDefinedSimilar("VAR.param"), true)
	t.CheckEquals(scope.IsDefinedSimilar("VAR.other"), true)
	t.CheckEquals(scope.IsDefinedSimilar("OTHER"), false)
}

func (s *Suite) Test_Scope__commented_varassign(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("mk/defaults/mk.conf", 3, "#VAR=default")
	scope := NewScope()
	scope.Define("VAR", mkline)

	t.CheckEquals(scope.IsDefined("VAR"), false)
	t.Check(scope.FirstDefinition("VAR"), check.IsNil)
	t.Check(scope.LastDefinition("VAR"), check.IsNil)

	t.CheckEquals(scope.Mentioned("VAR"), mkline)
	t.CheckEquals(scope.Commented("VAR"), mkline)

	value, found := scope.LastValueFound("VAR")
	t.CheckEquals(value, "")
	t.CheckEquals(found, false)
}

func (s *Suite) Test_Scope_Define(c *check.C) {
	t := s.Init(c)

	scope := NewScope()
	scope.Define("BUILD_DIRS", t.NewMkLine("file.mk", 121, "BUILD_DIRS=\tone two three"))

	t.CheckEquals(scope.LastValue("BUILD_DIRS"), "one two three")

	scope.Define("BUILD_DIRS", t.NewMkLine("file.mk", 123, "BUILD_DIRS+=\tfour"))

	t.CheckEquals(scope.LastValue("BUILD_DIRS"), "one two three four")

	// Later default assignments do not have an effect.
	scope.Define("BUILD_DIRS", t.NewMkLine("file.mk", 123, "BUILD_DIRS?=\tdefault"))

	t.CheckEquals(scope.LastValue("BUILD_DIRS"), "one two three four")
}

func (s *Suite) Test_Scope_Mentioned(c *check.C) {
	t := s.Init(c)

	assigned := t.NewMkLine("filename.mk", 3, "VAR=\tvalue")
	commented := t.NewMkLine("filename.mk", 4, "#COMMENTED=\tvalue")
	documented := t.NewMkLine("filename.mk", 5, "# DOCUMENTED is a variable.")

	scope := NewScope()
	scope.Define("VAR", assigned)
	scope.Define("COMMENTED", commented)
	scope.Define("DOCUMENTED", documented)

	t.CheckEquals(scope.Mentioned("VAR"), assigned)
	t.CheckEquals(scope.Mentioned("COMMENTED"), commented)
	t.CheckEquals(scope.Mentioned("DOCUMENTED"), documented)
	t.Check(scope.Mentioned("UNKNOWN"), check.IsNil)
}

func (s *Suite) Test_Scope_IsDefined(c *check.C) {
	t := s.Init(c)

	scope := NewScope()
	scope.Define("VAR.param", t.NewMkLine("file.mk", 1, "VAR.param=value"))

	t.CheckEquals(scope.IsDefined("VAR.param"), true)
	t.CheckEquals(scope.IsDefined("VAR.other"), false)
	t.CheckEquals(scope.IsDefined("VARIABLE.*"), false)

	t.CheckEquals(scope.IsDefinedSimilar("VAR.param"), true)
	t.CheckEquals(scope.IsDefinedSimilar("VAR.other"), true)
	t.CheckEquals(scope.IsDefinedSimilar("VARIABLE.*"), false)
}

func (s *Suite) Test_Scope_IsUsed(c *check.C) {
	t := s.Init(c)

	scope := NewScope()
	mkline := t.NewMkLine("file.mk", 1, "\techo ${VAR.param}")
	scope.Use("VAR.param", mkline, VucRunTime)

	t.CheckEquals(scope.IsUsed("VAR.param"), true)
	t.CheckEquals(scope.IsUsed("VAR.other"), false)
	t.CheckEquals(scope.IsUsed("VARIABLE.*"), false)

	t.CheckEquals(scope.IsUsedSimilar("VAR.param"), true)
	t.CheckEquals(scope.IsUsedSimilar("VAR.other"), true)
	t.CheckEquals(scope.IsUsedSimilar("VARIABLE.*"), false)
}

func (s *Suite) Test_Scope_FirstDefinition(c *check.C) {
	t := s.Init(c)

	mkline1 := t.NewMkLine("fname.mk", 3, "VAR=\tvalue")
	mkline2 := t.NewMkLine("fname.mk", 3, ".if ${SNEAKY::=value}")

	scope := NewScope()
	scope.Define("VAR", mkline1)
	scope.Define("SNEAKY", mkline2)

	t.CheckEquals(scope.FirstDefinition("VAR"), mkline1)

	// This call returns nil because it's not a variable assignment
	// and the calling code typically assumes a variable definition.
	// These sneaky variables with implicit definition are an edge
	// case that only few people actually know. It's better that way.
	t.Check(scope.FirstDefinition("SNEAKY"), check.IsNil)
}

func (s *Suite) Test_Scope_Commented(c *check.C) {
	t := s.Init(c)

	assigned := t.NewMkLine("filename.mk", 3, "VAR=\tvalue")
	commented := t.NewMkLine("filename.mk", 4, "#COMMENTED=\tvalue")
	documented := t.NewMkLine("filename.mk", 5, "# DOCUMENTED is a variable.")

	scope := NewScope()
	scope.Define("VAR", assigned)
	scope.Define("COMMENTED", commented)
	scope.Define("DOCUMENTED", documented)

	t.Check(scope.Commented("VAR"), check.IsNil)
	t.CheckEquals(scope.Commented("COMMENTED"), commented)
	t.Check(scope.Commented("DOCUMENTED"), check.IsNil)
	t.Check(scope.Commented("UNKNOWN"), check.IsNil)
}

func (s *Suite) Test_Scope_LastValue(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		MkCvsID,
		"VAR=\tfirst",
		"VAR=\tsecond",
		".if 1",
		"VAR=\tthird (conditional)",
		".endif")

	mklines.Check()

	t.CheckEquals(mklines.vars.LastValue("VAR"), "third (conditional)")

	t.CheckOutputLines(
		"WARN: file.mk:2: VAR is defined but not used.")
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

	t.CheckEquals(dst.IsDefined("VAR"), true)
}

func (s *Suite) Test_naturalLess(c *check.C) {
	t := s.Init(c)

	var elements = []string{
		"",
		// Numbers are always considered smaller than other characters.
		"0", "000", "0000", "5", "7", "00011", "12", "00012", "000111",
		"!", "a", "a0", "a ", "aa", "ab", "b"}

	test := func(i int, ie string, j int, je string) {
		actual := naturalLess(ie, je)
		expected := i < j
		if actual != expected {
			t.CheckDeepEquals(
				[]interface{}{i, ie, j, je, actual},
				[]interface{}{i, ie, j, je, expected})
		}
	}

	for i, ie := range elements {
		for j, je := range elements {
			test(i, ie, j, je)
		}
	}
}

func (s *Suite) Test_FileCache(c *check.C) {
	t := s.Init(c)

	t.EnableTracingToLog()

	cache := NewFileCache(3)

	lines := t.NewLines("Makefile",
		MkCvsID,
		"# line 2")

	c.Check(cache.Get("Makefile", 0), check.IsNil)
	t.CheckEquals(cache.hits, 0)
	t.CheckEquals(cache.misses, 1)

	cache.Put("Makefile", 0, lines)
	c.Check(cache.Get("Makefile", MustSucceed|LogErrors), check.IsNil) // Wrong LoadOptions.

	linesFromCache := cache.Get("Makefile", 0)
	t.CheckEquals(linesFromCache.Filename, "Makefile")
	c.Check(linesFromCache.Lines, check.HasLen, 2)
	t.CheckEquals(linesFromCache.Lines[0].Filename, "Makefile")

	// Cache keys are normalized using path.Clean.
	linesFromCache2 := cache.Get("./Makefile", 0)
	t.CheckEquals(linesFromCache2.Filename, "./Makefile")
	c.Check(linesFromCache2.Lines, check.HasLen, 2)
	t.CheckEquals(linesFromCache2.Lines[0].Filename, "./Makefile")

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
	t.CheckEquals(cache.hits, 7)
	t.CheckEquals(cache.misses, 5)

	t.CheckOutputLines(
		"TRACE:   FileCache \"Makefile\" with count 4.",
		"TRACE:   FileCache \"file1.mk\" with count 2.",
		"TRACE:   FileCache \"file2.mk\" with count 2.",
		"TRACE:   FileCache.Evict \"file2.mk\" with count 2.",
		"TRACE:   FileCache.Evict \"file1.mk\" with count 2.",
		"TRACE:   FileCache.Halve \"Makefile\" with count 4.")
}

func (s *Suite) Test_FileCache_removeOldEntries__branch_coverage(c *check.C) {
	t := s.Init(c)

	t.EnableTracingToLog()
	G.Testing = false

	lines := t.NewLines("filename.mk",
		MkCvsID)
	cache := NewFileCache(3)
	cache.Put("filename1.mk", 0, lines)
	cache.Put("filename2.mk", 0, lines)
	cache.Get("filename2.mk", 0)
	cache.Get("filename2.mk", 0)
	cache.Put("filename3.mk", 0, lines)
	cache.Put("filename4.mk", 0, lines)

	t.CheckOutputLines(
		"TRACE:   FileCache.Evict \"filename3.mk\" with count 1.",
		"TRACE:   FileCache.Evict \"filename1.mk\" with count 1.",
		"TRACE:   FileCache.Halve \"filename2.mk\" with count 3.")
}

func (s *Suite) Test_FileCache_removeOldEntries__no_tracing(c *check.C) {
	t := s.Init(c)

	t.DisableTracing()

	lines := t.NewLines("filename.mk",
		MkCvsID)
	cache := NewFileCache(3)
	cache.Put("filename1.mk", 0, lines)
	cache.Put("filename2.mk", 0, lines)
	cache.Get("filename2.mk", 0)
	cache.Get("filename2.mk", 0)
	cache.Put("filename3.mk", 0, lines)
	cache.Put("filename4.mk", 0, lines)

	t.CheckOutputEmpty()
}

// Covers the newLen > 0 condition.
func (s *Suite) Test_FileCache_removeOldEntries__zero_capacity(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("filename.mk",
		MkCvsID)
	cache := NewFileCache(1)
	cache.Put("filename1.mk", 0, lines)

	// This call removes all existing entries from the cache,
	// as the cache's capacity is only 1.
	cache.Put("filename2.mk", 0, lines)
}

func (s *Suite) Test_FileCache_Evict__sort(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("filename.mk",
		MkCvsID)
	cache := NewFileCache(10)
	cache.Put("filename0.mk", 0, lines)
	cache.Put("filename1.mk", 0, lines)
	cache.Put("filename2.mk", 0, lines)
	cache.Put("filename3.mk", 0, lines)
	cache.Put("filename4.mk", 0, lines)
	cache.Put("filename5.mk", 0, lines)
	cache.Put("filename6.mk", 0, lines)
	cache.Put("filename7.mk", 0, lines)
	cache.Put("filename8.mk", 0, lines)
	cache.Put("filename9.mk", 0, lines)

	cache.Evict("filename5.mk")

	t.Check(cache.table, check.HasLen, 9)
	t.Check(cache.Get("filename5.mk", 0), check.IsNil)
	t.Check(cache.Get("filename6.mk", 0), check.NotNil)
}

func (s *Suite) Test_bmakeHelp(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(bmakeHelp("subst"), confMake+" help topic=subst")
}

func (s *Suite) Test_wrap(c *check.C) {
	t := s.Init(c)

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

	t.CheckDeepEquals(wrapped, expected)
}

func (s *Suite) Test_escapePrintable(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(escapePrintable(""), "")
	t.CheckEquals(escapePrintable("ASCII only~\n\t"), "ASCII only~\n\t")
	t.CheckEquals(escapePrintable("Beep \u0007 control \u001F"), "Beep <U+0007> control <U+001F>")
	t.CheckEquals(escapePrintable("Bad \xFF character"), "Bad <0xFF> character")
	t.CheckEquals(escapePrintable("Unicode \uFFFD replacement"), "Unicode <U+FFFD> replacement")
}

func (s *Suite) Test_stringSliceLess(c *check.C) {
	t := s.Init(c)

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
			t.CheckDeepEquals(
				[]interface{}{i, iElement, j, jElement, actual},
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

	t.CheckDeepEquals(
		joinSkipEmpty(", ", "", "one", "", "", "two", "", "three"),
		"one, two, three")
}

func (s *Suite) Test_joinSkipEmptyCambridge(c *check.C) {
	t := s.Init(c)

	t.CheckDeepEquals(
		joinSkipEmptyCambridge("and", "", "one", "", "", "two", "", "three"),
		"one, two and three")

	t.CheckDeepEquals(
		joinSkipEmptyCambridge("and", "", "one", "", ""),
		"one")
}

func (s *Suite) Test_joinSkipEmptyOxford(c *check.C) {
	t := s.Init(c)

	t.CheckDeepEquals(
		joinSkipEmptyOxford("and", "", "one", "", "", "two", "", "three"),
		"one, two, and three")
}

func (s *Suite) Test_newPathMatcher(c *check.C) {
	t := s.Init(c)

	test := func(pattern string, matchType pathMatchType, matchPattern string) {
		t.CheckEquals(*newPathMatcher(pattern), pathMatcher{matchType, matchPattern, pattern})
	}

	testPanic := func(pattern string) {
		t.ExpectPanic(
			func() { _ = newPathMatcher(pattern) },
			"Pkglint internal error")
	}

	testPanic("*.[0123456]")
	testPanic("file.???")
	testPanic("*.???")
	test("", pmExact, "")
	test("exact", pmExact, "exact")
	test("*.mk", pmSuffix, ".mk")
	test("Makefile.*", pmPrefix, "Makefile.")
	testPanic("*.*")
	testPanic("**")
	testPanic("a*b")
	testPanic("[")
	testPanic("malformed[")
}

func (s *Suite) Test_pathMatcher_matches(c *check.C) {
	t := s.Init(c)

	test := func(pattern string, subject string, expected bool) {
		matcher := newPathMatcher(pattern)
		t.CheckEquals(matcher.matches(subject), expected)
	}

	test("", "", true)
	test("", "any", false)
	test("exact", "exact", true)
	test("exact", "different", false)

	test("*.mk", "filename.mk", true)
	test("*.mk", "filename.txt", false)
	test("*.mk", "filename.mkx", false)
	test("*.mk", ".mk", true)

	test("Makefile.*", "Makefile", false)
	test("Makefile.*", "Makefile.", true)
	test("Makefile.*", "Makefile.txt", true)
	test("Makefile.*", "makefile.txt", false)
}

func (s *Suite) Test_StringInterner(c *check.C) {
	t := s.Init(c)

	si := NewStringInterner()

	t.CheckEquals(si.Intern(""), "")
	t.CheckEquals(si.Intern("Hello"), "Hello")
	t.CheckEquals(si.Intern("Hello, world"), "Hello, world")
	t.CheckEquals(si.Intern("Hello, world"[0:5]), "Hello")
}

func (s *Suite) Test_shquote(c *check.C) {
	t := s.Init(c)

	test := func(in, out string) {
		t.CheckEquals(shquote(in), out)
	}

	test("", "''")
	test("'", "''\\'''")
	test("simple", "simple")
	test("~", "'~'")
}
