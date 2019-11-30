package pkglint

import (
	"gopkg.in/check.v1"
	"io"
	"os"
	"runtime"
	"strings"
)

func (s *Suite) Test_NewPath(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(NewPath("filename"), NewPath("filename"))
	t.CheckEquals(NewPath("\\"), NewPath("\\"))
	c.Check(NewPath("\\"), check.Not(check.Equals), NewPath("/"))
}

func (s *Suite) Test_NewPathSlash(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(NewPathSlash("filename"), NewPathSlash("filename"))
	t.CheckEquals(NewPathSlash("\\"), NewPathSlash("\\"))

	t.CheckEquals(
		NewPathSlash("\\"),
		NewPathSlash(condStr(runtime.GOOS == "windows", "/", "\\")))
}

func (s *Suite) Test_Path_String(c *check.C) {
	t := s.Init(c)

	for _, p := range []string{"", "filename", "a/b", "c\\d"} {
		t.CheckEquals(NewPath(p).String(), p)
	}
}

func (s *Suite) Test_Path_GoString(c *check.C) {
	t := s.Init(c)

	test := func(p Path, s string) {
		t.CheckEquals(p.GoString(), s)
	}

	test("", "\"\"")
	test("filename", "\"filename\"")
	test("a/b", "\"a/b\"")
	test("c\\d", "\"c\\\\d\"")
}

func (s *Suite) Test_Path_IsEmpty(c *check.C) {
	t := s.Init(c)

	test := func(p Path, isEmpty bool) {
		t.CheckEquals(p.IsEmpty(), isEmpty)
	}

	test("", true)
	test(".", false)
	test("/", false)
}

func (s *Suite) Test_Path_Dir(c *check.C) {
	t := s.Init(c)

	test := func(p, dir Path) {
		t.CheckEquals(p.Dir(), dir)
	}

	test("", ".")
	test("././././", ".")
	test("/root", "/")
	test("filename", ".")
	test("dir/filename", "dir")
	test("dir/filename\\with\\backslash", "dir")
}

func (s *Suite) Test_Path_Base(c *check.C) {
	t := s.Init(c)

	test := func(p Path, base string) {
		t.CheckEquals(p.Base(), base)
	}

	test("", ".") // That's a bit surprising
	test("././././", ".")
	test("/root", "root")
	test("filename", "filename")
	test("dir/filename", "filename")
	test("dir/filename\\with\\backslash", "filename\\with\\backslash")
}

func (s *Suite) Test_Path_Split(c *check.C) {
	t := s.Init(c)

	test := func(p, dir, base string) {
		actualDir, actualBase := NewPath(p).Split()

		t.CheckDeepEquals(
			[]string{actualDir.String(), actualBase},
			[]string{dir, base})
	}

	test("", "", "")
	test("././././", "././././", "")
	test("/root", "/", "root")
	test("filename", "", "filename")
	test("dir/filename", "dir/", "filename")
	test("dir/filename\\with\\backslash", "dir/", "filename\\with\\backslash")
}

func (s *Suite) Test_Path_Parts(c *check.C) {
	t := s.Init(c)

	test := func(p string, parts ...string) {
		t.CheckDeepEquals(NewPath(p).Parts(), parts)
	}

	// Only the empty path returns an empty slice.
	test("", nil...)

	// The standard cases for relative paths.
	test("relative", "relative")
	test("relative/subdir", "relative", "subdir")
	test("relative////subdir", "relative", "subdir")
	test("relative/..", "relative", "..")
	test("relative/.", "relative")

	// Leading dots are removed when they are followed by something.
	test("./relative", "relative")

	// A path consisting of only dots produces a single dot.
	test("./././.", ".")

	// Slashes at the end are treated like a single dot.
	test("././././", ".")
	test(".///////", ".")

	// Absolute paths have an empty first component.
	test("/", "")
	test("/.", "")
	test("/root", "", "root")

	// The backslash is not a path separator.
	test("dir/filename\\with\\backslash", "dir", "filename\\with\\backslash")
}

func (s *Suite) Test_Path_Count(c *check.C) {
	t := s.Init(c)

	test := func(p string, count int) {
		t.CheckEquals(NewPath(p).Count(), count)
	}

	test("././././", 1)
	test("/root", 2)
	test("filename", 1)
	test("dir/filename", 2)
	test("dir/filename\\with\\backslash", 2)

	// Only the empty path returns an empty slice.
	test("", 0)

	// The standard cases for canonical relative paths.
	test("relative", 1)
	test("relative/subdir", 2)
	test("relative////subdir", 2)
	test("relative/..", 2)
	test("relative/.", 1)

	// A path consisting of only dots produces a single dot.
	test("./././.", 1)

	// Slashes at the end are treated like a single dot.
	test("././././", 1)
	test(".///////", 1)

	// Absolute paths have an empty first component.
	test("/", 1)
	test("/.", 1)
	test("/root", 2)

	// The backslash is not a path separator.
	test("dir/filename\\with\\backslash", 2)
}

func (s *Suite) Test_Path_HasPrefixText(c *check.C) {
	t := s.Init(c)

	test := func(p, prefix string, hasPrefix bool) {
		t.CheckEquals(NewPath(p).HasPrefixText(prefix), hasPrefix)
	}

	test("", "", true)
	test("filename", "", true)
	test("", "x", false)
	test("/root", "/r", true)
	test("/root", "/root", true)
	test("/root", "/root/", false)
	test("/root", "root/", false)
}

func (s *Suite) Test_Path_HasPrefixPath(c *check.C) {
	t := s.Init(c)

	test := func(p, prefix Path, hasPrefix bool) {
		t.CheckEquals(p.HasPrefixPath(prefix), hasPrefix)
	}

	test("", "", true)
	test("filename", "", false)
	test("", "x", false)
	test("/root", "/r", false)
	test("/root", "/root", true)

	// Even though the textual representation of the prefix is longer than
	// the path. The trailing slash marks the path as a directory, and
	// there are only a few cases where the difference matters, such as
	// in rsync and mkdir.
	test("/root", "/root/", true)

	test("/root/", "/root", true)
	test("/root/", "root", false)
	test("/root/subdir", "/root", true)
	test("filename", ".", true)
	test("filename", "./filename", true)
	test("filename", "./file", false)
	test("filename", "./filename/sub", false)
	test("/anything", ".", false)
}

func (s *Suite) Test_Path_ContainsText(c *check.C) {
	t := s.Init(c)

	test := func(p Path, text string, contains bool) {
		t.CheckEquals(p.ContainsText(text), contains)
	}

	test("", "", true)
	test("filename", "", true)
	test("filename", ".", false)
	test("a.b", ".", true)
	test("..", ".", true)
	test("", "x", false)
	test("/root", "/r", true)
	test("/root", "/root", true)
	test("/root", "/root/", false)
	test("/root", "root/", false)
	test("/root", "ro", true)
	test("/root", "ot", true)
}

func (s *Suite) Test_Path_ContainsPath(c *check.C) {
	t := s.Init(c)

	test := func(p, sub Path, contains bool) {
		t.CheckEquals(p.ContainsPath(sub), contains)
	}

	test("", "", true)          // It doesn't make sense to search for empty paths.
	test(".", "", false)        // It doesn't make sense to search for empty paths.
	test("filename", ".", true) // Every relative path contains "." implicitly at the beginning
	test("a.b", ".", true)
	test("..", ".", true)
	test("filename", "", false)
	test("filename", "filename", true)
	test("a/b/c", "a", true)
	test("a/b/c", "b", true)
	test("a/b/c", "c", true)
	test("a/b/c", "a/b", true)
	test("a/b/c", "b/c", true)
	test("a/b/c", "a/b/c", true)
	test("aa/b/c", "a", false)
	test("a/bb/c", "b", false)
	test("a/bb/c", "b/c", false)
	test("mk/fetch/fetch.mk", "mk", true)
	test("category/package/../../wip/mk/../..", "mk", true)

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

func (s *Suite) Test_Path_ContainsPathCanonical(c *check.C) {
	t := s.Init(c)

	test := func(p, sub Path, contains bool) {
		t.CheckEquals(p.ContainsPathCanonical(sub), contains)
	}

	test("", "", false)
	test(".", "", false)
	test("filename", "", false)
	test("filename", "filename", true)
	test("a/b/c", "a", true)
	test("a/b/c", "b", true)
	test("a/b/c", "c", true)
	test("a/b/c", "a/b", true)
	test("a/b/c", "b/c", true)
	test("a/b/c", "a/b/c", true)
	test("aa/b/c", "a", false)
	test("a/bb/c", "b", false)
	test("a/bb/c", "b/c", false)
	test("mk/fetch/fetch.mk", "mk", true)
	test("category/package/../../wip/mk", "mk", true)
	test("category/package/../../wip/mk/..", "mk", true) // FIXME
	test("category/package/../../wip/mk/../..", "mk", false)
}

func (s *Suite) Test_Path_HasSuffixText(c *check.C) {
	t := s.Init(c)

	test := func(p Path, suffix string, has bool) {
		t.CheckEquals(p.HasSuffixText(suffix), has)
	}

	test("", "", true)
	test("a/bb/c", "", true)
	test("a/bb/c", "c", true)
	test("a/bb/c", "/c", true)
	test("a/bb/c", "b/c", true)
	test("aa/b/c", "bb", false)
}

func (s *Suite) Test_Path_HasSuffixPath(c *check.C) {
	t := s.Init(c)

	test := func(p, suffix Path, has bool) {
		t.CheckEquals(p.HasSuffixPath(suffix), has)
	}

	test("", "", true)
	test("a/bb/c", "", false)
	test("a/bb/c", "c", true)
	test("a/bb/c", "/c", false)
	test("a/bb/c", "b/c", false)
	test("aa/b/c", "bb", false)
}

func (s *Suite) Test_Path_HasBase(c *check.C) {
	t := s.Init(c)

	test := func(p Path, suffix string, hasBase bool) {
		t.CheckEquals(p.HasBase(suffix), hasBase)
	}

	test("dir/file", "e", false)
	test("dir/file", "file", true)
	test("dir/file", "file.ext", false)
	test("dir/file", "/file", false)
	test("dir/file", "dir/file", false)
}

func (s *Suite) Test_Path_TrimSuffix(c *check.C) {
	t := s.Init(c)

	test := func(p Path, suffix string, result Path) {
		t.CheckEquals(p.TrimSuffix(suffix), result)
	}

	test("dir/file", "e", "dir/fil")
	test("dir/file", "file", "dir/")
	test("dir/file", "/file", "dir")
	test("dir/file", "dir/file", "")
	test("dir/file", "subdir/file", "dir/file")
}

func (s *Suite) Test_Path_Replace(c *check.C) {
	t := s.Init(c)

	test := func(p Path, from, to string, result Path) {
		t.CheckEquals(p.Replace(from, to), result)
	}

	test("dir/file", "dir", "other", "other/file")
	test("dir/file", "r", "sk", "disk/file")
	test("aaa/file", "a", "sub/", "sub/sub/sub//file")
}

func (s *Suite) Test_Path_JoinClean(c *check.C) {
	t := s.Init(c)

	test := func(p Path, suffix Path, result Path) {
		t.CheckEquals(p.JoinClean(suffix), result)
	}

	test("dir", "file", "dir/file")
	test("dir", "///file", "dir/file")
	test("dir/./../dir/", "///file", "dir/file")
	test("dir", "..", ".")
}

func (s *Suite) Test_Path_JoinNoClean(c *check.C) {
	t := s.Init(c)

	test := func(p, suffix Path, result Path) {
		t.CheckEquals(p.JoinNoClean(suffix), result)
	}

	test("dir", "file", "dir/file")
	test("dir", "///file", "dir////file")
	test("dir/./../dir/", "///file", "dir/./../dir/////file")
	test("dir", "..", "dir/..")
}

func (s *Suite) Test_Path_Clean(c *check.C) {
	t := s.Init(c)

	test := func(p, result Path) {
		t.CheckEquals(p.Clean(), result)
	}

	test("", ".")
	test(".", ".")
	test("./././", ".")
	test("a/bb///../c", "a/c")
}

func (s *Suite) Test_Path_CleanDot(c *check.C) {
	t := s.Init(c)

	test := func(p, result Path) {
		t.CheckEquals(p.CleanDot(), result)
	}

	test("", "")
	test(".", ".")
	test("./././", ".")
	test("a/bb///../c", "a/bb/../c")
	test("./filename", "filename")
	test("/absolute", "/absolute")
	test("/usr/pkgsrc/wip/package", "/usr/pkgsrc/wip/package")
	test("/usr/pkgsrc/wip/package/../mk/git-package.mk", "/usr/pkgsrc/wip/package/../mk/git-package.mk")
}

func (s *Suite) Test_Path_IsAbs(c *check.C) {
	t := s.Init(c)

	test := func(p Path, abs bool) {
		t.CheckEquals(p.IsAbs(), abs)
	}

	test("", false)
	test(".", false)
	test("a/b", false)
	test("/a", true)
	test("C:/", runtime.GOOS == "windows")
	test("c:/", runtime.GOOS == "windows")
}

func (s *Suite) Test_Path_Rel(c *check.C) {
	t := s.Init(c)

	base := NewPath(".")
	abc := NewPath("a/b/c")
	defFile := NewPath("d/e/f/file")

	t.CheckEquals(abc.Rel(defFile), NewPath("../../../d/e/f/file"))
	t.CheckEquals(base.Rel(base), NewPath("."))
	t.CheckEquals(abc.Rel(base), NewPath("../../../."))
}

func (s *Suite) Test_Path_Rename(c *check.C) {
	t := s.Init(c)

	f := t.CreateFileLines("filename.old",
		"line 1")
	t.CheckEquals(f.IsFile(), true)
	dst := NewPath(f.TrimSuffix(".old").String() + ".new")

	err := f.Rename(dst)

	assertNil(err, "Rename")
	t.CheckEquals(f.IsFile(), false)
	t.CheckFileLines("filename.new",
		"line 1")
}

func (s *Suite) Test_Path_Lstat(c *check.C) {
	t := s.Init(c)

	testDir := func(f Path, isDir bool) {
		st, err := f.Lstat()
		assertNil(err, "Lstat")
		t.CheckEquals(st.Mode()&os.ModeDir != 0, isDir)
	}

	t.CreateFileLines("subdir/file")
	t.CreateFileLines("file")

	testDir(t.File("subdir"), true)
	testDir(t.File("file"), false)
}

func (s *Suite) Test_Path_Stat(c *check.C) {
	t := s.Init(c)

	testDir := func(f Path, isDir bool) {
		st, err := f.Stat()
		assertNil(err, "Stat")
		t.CheckEquals(st.Mode()&os.ModeDir != 0, isDir)
	}

	t.CreateFileLines("subdir/file")
	t.CreateFileLines("file")

	testDir(t.File("subdir"), true)
	testDir(t.File("file"), false)
}

func (s *Suite) Test_Path_Exists(c *check.C) {
	t := s.Init(c)

	test := func(f Path, exists bool) {
		t.CheckEquals(f.Exists(), exists)
	}

	t.CreateFileLines("subdir/file")
	t.CreateFileLines("file")

	test(t.File("subdir"), true)
	test(t.File("file"), true)
	test(t.File("enoent"), false)
}

func (s *Suite) Test_Path_IsFile(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("dir/file")

	t.CheckEquals(t.File("nonexistent").IsFile(), false)
	t.CheckEquals(t.File("dir").IsFile(), false)
	t.CheckEquals(t.File("dir/nonexistent").IsFile(), false)
	t.CheckEquals(t.File("dir/file").IsFile(), true)
}

func (s *Suite) Test_Path_IsDir(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("dir/file")

	t.CheckEquals(t.File("nonexistent").IsDir(), false)
	t.CheckEquals(t.File("dir").IsDir(), true)
	t.CheckEquals(t.File("dir/nonexistent").IsDir(), false)
	t.CheckEquals(t.File("dir/file").IsDir(), false)
}

func (s *Suite) Test_Path_Chmod(c *check.C) {
	t := s.Init(c)

	testWritable := func(f Path, writable bool) {
		lstat, err := f.Lstat()
		assertNil(err, "Lstat")
		t.CheckEquals(lstat.Mode().Perm()&0200 != 0, writable)
	}

	f := t.CreateFileLines("file")
	testWritable(f, true)

	err := f.Chmod(0444)
	assertNil(err, "Chmod")

	testWritable(f, false)
}

func (s *Suite) Test_Path_ReadDir(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("subdir/file")
	t.CreateFileLines("file")
	t.CreateFileLines("CVS/Entries")
	t.CreateFileLines(".git/info/exclude")

	infos, err := t.File(".").ReadDir()

	assertNil(err, "ReadDir")
	var names []string
	for _, info := range infos {
		names = append(names, info.Name())
	}

	t.CheckDeepEquals(names, []string{".git", "CVS", "file", "subdir"})
}

func (s *Suite) Test_Path_Open(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("filename",
		"line 1",
		"line 2")

	f, err := t.File("filename").Open()

	assertNil(err, "Open")
	defer func() { assertNil(f.Close(), "Close") }()
	var sb strings.Builder
	n, err := io.Copy(&sb, f)
	assertNil(err, "Copy")
	t.CheckEquals(n, int64(14))
	t.CheckEquals(sb.String(), "line 1\nline 2\n")
}

func (s *Suite) Test_Path_ReadString(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("filename",
		"line 1",
		"line 2")

	text, err := t.File("filename").ReadString()

	assertNil(err, "ReadString")
	t.CheckEquals(text, "line 1\nline 2\n")
}

func (s *Suite) Test_Path_WriteString(c *check.C) {
	t := s.Init(c)

	err := t.File("filename").WriteString("line 1\nline 2\n")

	assertNil(err, "WriteString")
	t.CheckFileLines("filename",
		"line 1",
		"line 2")
}
