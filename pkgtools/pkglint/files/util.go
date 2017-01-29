package main

import (
	"fmt"
	"io/ioutil"
	"netbsd.org/pkglint/line"
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/trace"
	"os"
	"path"
	"path/filepath"
	"regexp"
	"strconv"
	"strings"
	"time"
)

// Short names for commonly used functions.
func contains(s, substr string) bool {
	return strings.Contains(s, substr)
}
func hasPrefix(s, prefix string) bool {
	return strings.HasPrefix(s, prefix)
}
func hasSuffix(s, suffix string) bool {
	return strings.HasSuffix(s, suffix)
}
func matches(s string, re regex.RegexPattern) bool {
	return regex.Matches(s, re)
}
func match1(s string, re regex.RegexPattern) (matched bool, m1 string) {
	return regex.Match1(s, re)
}
func match2(s string, re regex.RegexPattern) (matched bool, m1, m2 string) {
	return regex.Match2(s, re)
}
func match3(s string, re regex.RegexPattern) (matched bool, m1, m2, m3 string) {
	return regex.Match3(s, re)
}
func match4(s string, re regex.RegexPattern) (matched bool, m1, m2, m3, m4 string) {
	return regex.Match4(s, re)
}

func ifelseStr(cond bool, a, b string) string {
	if cond {
		return a
	}
	return b
}

func imax(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func mustMatch(s string, re regex.RegexPattern) []string {
	if m := regex.Match(s, re); m != nil {
		return m
	}
	panic(fmt.Sprintf("mustMatch %q %q", s, re))
}

func isEmptyDir(fname string) bool {
	dirents, err := ioutil.ReadDir(fname)
	if err != nil || hasSuffix(fname, "/CVS") {
		return true
	}
	for _, dirent := range dirents {
		name := dirent.Name()
		if name == "." || name == ".." || name == "CVS" {
			continue
		}
		if dirent.IsDir() && isEmptyDir(fname+"/"+name) {
			continue
		}
		return false
	}
	return true
}

func getSubdirs(fname string) []string {
	dirents, err := ioutil.ReadDir(fname)
	if err != nil {
		NewLineWhole(fname).Fatalf("Cannot be read: %s", err)
	}

	var subdirs []string
	for _, dirent := range dirents {
		name := dirent.Name()
		if name != "." && name != ".." && name != "CVS" && dirent.IsDir() && !isEmptyDir(fname+"/"+name) {
			subdirs = append(subdirs, name)
		}
	}
	return subdirs
}

// Checks whether a file is already committed to the CVS repository.
func isCommitted(fname string) bool {
	lines := loadCvsEntries(fname)
	needle := "/" + path.Base(fname) + "/"
	for _, line := range lines {
		if hasPrefix(line.Text(), needle) {
			return true
		}
	}
	return false
}

func isLocallyModified(fname string) bool {
	lines := loadCvsEntries(fname)
	needle := "/" + path.Base(fname) + "/"
	for _, line := range lines {
		if hasPrefix(line.Text(), needle) {
			cvsModTime, err := time.Parse(time.ANSIC, strings.Split(line.Text(), "/")[3])
			if err != nil {
				return false
			}
			st, err := os.Stat(fname)
			if err != nil {
				return false
			}

			// https://msdn.microsoft.com/en-us/library/windows/desktop/ms724290(v=vs.85).aspx
			// (System Services > Windows System Information > Time > About Time > File Times)
			delta := cvsModTime.Unix() - st.ModTime().Unix()
			if trace.Tracing {
				trace.Stepf("cvs.time=%v fs.time=%v delta=%v", cvsModTime, st.ModTime(), delta)
			}
			return !(-2 <= delta && delta <= 2)
		}
	}
	return false
}

func loadCvsEntries(fname string) []line.Line {
	dir := path.Dir(fname)
	if dir == G.CvsEntriesDir {
		return G.CvsEntriesLines
	}

	lines, err := readLines(dir+"/CVS/Entries", false)
	if err != nil {
		return nil
	}
	G.CvsEntriesDir = dir
	G.CvsEntriesLines = lines
	return lines
}

// Returns the number of columns that a string occupies when printed with
// a tabulator size of 8.
func tabLength(s string) int {
	length := 0
	for _, r := range s {
		if r == '\t' {
			length = length - length%8 + 8
		} else {
			length++
		}
	}
	return length
}

func varnameBase(varname string) string {
	dot := strings.IndexByte(varname, '.')
	if dot != -1 {
		return varname[:dot]
	}
	return varname
}
func varnameCanon(varname string) string {
	dot := strings.IndexByte(varname, '.')
	if dot != -1 {
		return varname[:dot] + ".*"
	}
	return varname
}
func varnameParam(varname string) string {
	dot := strings.IndexByte(varname, '.')
	if dot != -1 {
		return varname[dot+1:]
	}
	return ""
}

func defineVar(mkline MkLine, varname string) {
	if G.Mk != nil {
		G.Mk.DefineVar(mkline, varname)
	}
	if G.Pkg != nil {
		G.Pkg.defineVar(mkline, varname)
	}
}
func varIsDefined(varname string) bool {
	varcanon := varnameCanon(varname)
	if G.Mk != nil && (G.Mk.vardef[varname] != nil || G.Mk.vardef[varcanon] != nil) {
		return true
	}
	if G.Pkg != nil && (G.Pkg.vardef[varname] != nil || G.Pkg.vardef[varcanon] != nil) {
		return true
	}
	return false
}

func varIsUsed(varname string) bool {
	varcanon := varnameCanon(varname)
	if G.Mk != nil && (G.Mk.varuse[varname] != nil || G.Mk.varuse[varcanon] != nil) {
		return true
	}
	if G.Pkg != nil && (G.Pkg.varuse[varname] != nil || G.Pkg.varuse[varcanon] != nil) {
		return true
	}
	return false
}

func splitOnSpace(s string) []string {
	return regex.Compile(`\s+`).Split(s, -1)
}

func fileExists(fname string) bool {
	st, err := os.Stat(fname)
	return err == nil && st.Mode().IsRegular()
}

func dirExists(fname string) bool {
	st, err := os.Stat(fname)
	return err == nil && st.Mode().IsDir()
}

// Useful in combination with regex.Find*Index
func negToZero(i int) int {
	if i >= 0 {
		return i
	}
	return 0
}

func toInt(s string, def int) int {
	if n, err := strconv.Atoi(s); err == nil {
		return n
	}
	return def
}

func dirglob(dirname string) []string {
	fis, err := ioutil.ReadDir(dirname)
	if err != nil {
		return nil
	}
	fnames := make([]string, len(fis))
	for i, fi := range fis {
		fnames[i] = dirname + "/" + fi.Name()
	}
	return fnames
}

// Emulates make(1)'s :S substitution operator.
func mkopSubst(s string, left bool, from string, right bool, to string, flags string) string {
	if trace.Tracing {
		defer trace.Call(s, left, from, right, to, flags)()
	}
	re := regex.RegexPattern(ifelseStr(left, "^", "") + regexp.QuoteMeta(from) + ifelseStr(right, "$", ""))
	done := false
	gflag := contains(flags, "g")
	return regex.Compile(re).ReplaceAllStringFunc(s, func(match string) string {
		if gflag || !done {
			done = !gflag
			return to
		}
		return match
	})
}

func relpath(from, to string) string {
	absFrom, err1 := filepath.Abs(from)
	absTo, err2 := filepath.Abs(to)
	rel, err3 := filepath.Rel(absFrom, absTo)
	if err1 != nil || err2 != nil || err3 != nil {
		trace.Stepf("relpath.panic", from, to, err1, err2, err3)
		panic("relpath")
	}
	result := filepath.ToSlash(rel)
	if trace.Tracing {
		trace.Stepf("relpath from %q to %q = %q", from, to, result)
	}
	return result
}

func abspath(fname string) string {
	abs, err := filepath.Abs(fname)
	if err != nil {
		NewLineWhole(fname).Fatalf("Cannot determine absolute path.")
	}
	return filepath.ToSlash(abs)
}

// Differs from path.Clean in that only "../../" is replaced, not "../".
// Also, the initial directory is always kept.
// This is to provide the package path as context in recursive invocations of pkglint.
func cleanpath(fname string) string {
	tmp := fname
	for len(tmp) > 2 && hasPrefix(tmp, "./") {
		tmp = tmp[2:]
	}
	for contains(tmp, "/./") {
		tmp = strings.Replace(tmp, "/./", "/", -1)
	}
	for contains(tmp, "//") {
		tmp = strings.Replace(tmp, "//", "/", -1)
	}
	tmp = reReplaceRepeatedly(tmp, `/[^.][^/]*/[^.][^/]*/\.\./\.\./`, "/")
	tmp = strings.TrimSuffix(tmp, "/")
	return tmp
}

func containsVarRef(s string) bool {
	return contains(s, "${")
}

func reReplaceRepeatedly(from string, re regex.RegexPattern, to string) string {
	replaced := regex.Compile(re).ReplaceAllString(from, to)
	if replaced != from {
		return reReplaceRepeatedly(replaced, re, to)
	}
	return replaced
}

func hasAlnumPrefix(s string) bool {
	if s == "" {
		return false
	}
	b := s[0]
	return '0' <= b && b <= '9' || 'A' <= b && b <= 'Z' || b == '_' || 'a' <= b && b <= 'z'
}
