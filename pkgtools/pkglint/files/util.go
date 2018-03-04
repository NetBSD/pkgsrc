package main

import (
	"fmt"
	"io/ioutil"
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
func matches(s string, re regex.Pattern) bool {
	return regex.Matches(s, re)
}
func match1(s string, re regex.Pattern) (matched bool, m1 string) {
	return regex.Match1(s, re)
}
func match2(s string, re regex.Pattern) (matched bool, m1, m2 string) {
	return regex.Match2(s, re)
}
func match3(s string, re regex.Pattern) (matched bool, m1, m2, m3 string) {
	return regex.Match3(s, re)
}
func match4(s string, re regex.Pattern) (matched bool, m1, m2, m3, m4 string) {
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

func mustMatch(s string, re regex.Pattern) []string {
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
		if isIgnoredFilename(name) {
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
		if dirent.IsDir() && !isIgnoredFilename(name) && !isEmptyDir(fname+"/"+name) {
			subdirs = append(subdirs, name)
		}
	}
	return subdirs
}

func isIgnoredFilename(fileName string) bool {
	switch fileName {
	case ".", "..", "CVS", ".svn", ".git", ".hg":
		return true
	}
	return false
}

// Checks whether a file is already committed to the CVS repository.
func isCommitted(fname string) bool {
	lines := loadCvsEntries(fname)
	needle := "/" + path.Base(fname) + "/"
	for _, line := range lines {
		if hasPrefix(line.Text, needle) {
			return true
		}
	}
	return false
}

func isLocallyModified(fname string) bool {
	lines := loadCvsEntries(fname)
	needle := "/" + path.Base(fname) + "/"
	for _, line := range lines {
		if hasPrefix(line.Text, needle) {
			cvsModTime, err := time.Parse(time.ANSIC, strings.Split(line.Text, "/")[3])
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

func loadCvsEntries(fname string) []Line {
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
func tabWidth(s string) int {
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

func detab(s string) string {
	detabbed := ""
	for _, r := range s {
		if r == '\t' {
			detabbed += "        "[:8-len(detabbed)%8]
		} else {
			detabbed += string(r)
		}
	}
	return detabbed
}

func shorten(s string, maxChars int) string {
	chars := 0
	for i := range s {
		if chars >= maxChars {
			return s[:i] + "..."
			break
		}
		chars++
	}
	return s
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

// defineVar marks a variable as defined in both the current package and the current file.
func defineVar(mkline MkLine, varname string) {
	if G.Mk != nil {
		G.Mk.vars.Define(varname, mkline)
	}
	if G.Pkg != nil {
		G.Pkg.vars.Define(varname, mkline)
	}
}

// varIsDefined tests whether the variable (or its canonicalized form)
// is defined in the current package or in the current file.
// TODO: rename to similar
func varIsDefined(varname string) bool {
	return G.Mk != nil && G.Mk.vars.DefinedSimilar(varname) ||
		G.Pkg != nil && G.Pkg.vars.DefinedSimilar(varname)
}

// varIsUsed tests whether the variable (or its canonicalized form)
// is used in the current package or in the current file.
// TODO: rename to similar
func varIsUsed(varname string) bool {
	return G.Mk != nil && G.Mk.vars.UsedSimilar(varname) ||
		G.Pkg != nil && G.Pkg.vars.UsedSimilar(varname)
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
	var fnames []string
	for _, fi := range fis {
		if !(isIgnoredFilename(fi.Name())) {
			fnames = append(fnames, dirname+"/"+fi.Name())
		}
	}
	return fnames
}

// Emulates make(1)'s :S substitution operator.
func mkopSubst(s string, left bool, from string, right bool, to string, flags string) string {
	if trace.Tracing {
		defer trace.Call(s, left, from, right, to, flags)()
	}
	re := regex.Pattern(ifelseStr(left, "^", "") + regexp.QuoteMeta(from) + ifelseStr(right, "$", ""))
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

func reReplaceRepeatedly(from string, re regex.Pattern, to string) string {
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

// Once remembers with which arguments its FirstTime method has been called
// and only returns true on each first call.
type Once struct {
	seen map[string]bool
}

func (o *Once) FirstTime(what string) bool {
	if o.seen == nil {
		o.seen = make(map[string]bool)
	}
	if _, ok := o.seen[what]; ok {
		return false
	}
	o.seen[what] = true
	return true
}

// Scope remembers which variables are defined and which are used
// in a certain scope, such as a package or a file.
type Scope struct {
	defined map[string]MkLine
	used    map[string]MkLine
}

func NewScope() Scope {
	return Scope{make(map[string]MkLine), make(map[string]MkLine)}
}

// Define marks the variable and its canonicalized form as defined.
func (s *Scope) Define(varname string, line MkLine) {
	if s.defined[varname] == nil {
		s.defined[varname] = line
		if trace.Tracing {
			trace.Step2("Defining %q in line %s", varname, line.Linenos())
		}
	}
	varcanon := varnameCanon(varname)
	if varcanon != varname && s.defined[varcanon] == nil {
		s.defined[varcanon] = line
		if trace.Tracing {
			trace.Step2("Defining %q in line %s", varcanon, line.Linenos())
		}
	}
}

// Use marks the variable and its canonicalized form as used.
func (s *Scope) Use(varname string, line MkLine) {
	if s.used[varname] == nil {
		s.used[varname] = line
		if trace.Tracing {
			trace.Step2("Using %q in line %s", varname, line.Linenos())
		}
	}
	varcanon := varnameCanon(varname)
	if varcanon != varname && s.used[varcanon] == nil {
		s.used[varcanon] = line
		if trace.Tracing {
			trace.Step2("Using %q in line %s", varcanon, line.Linenos())
		}
	}
}

// Defined tests whether the variable is defined.
// It does NOT test the canonicalized variable name.
func (s *Scope) Defined(varname string) bool {
	return s.defined[varname] != nil
}

// DefinedSimilar tests whether the variable or its canonicalized form is defined.
func (s *Scope) DefinedSimilar(varname string) bool {
	if s.defined[varname] != nil {
		if trace.Tracing {
			trace.Step1("Variable %q is defined", varname)
		}
		return true
	}
	varcanon := varnameCanon(varname)
	if s.defined[varcanon] != nil {
		if trace.Tracing {
			trace.Step2("Variable %q (similar to %q) is defined", varcanon, varname)
		}
		return true
	}
	return false
}

// Used tests whether the variable is used.
// It does NOT test the canonicalized variable name.
func (s *Scope) Used(varname string) bool {
	return s.used[varname] != nil
}

// UsedSimilar tests whether the variable or its canonicalized form is used.
func (s *Scope) UsedSimilar(varname string) bool {
	if s.used[varname] != nil {
		return true
	}
	return s.used[varnameCanon(varname)] != nil
}

func (s *Scope) FirstDefinition(varname string) MkLine {
	return s.defined[varname]
}

func (s *Scope) FirstUse(varname string) MkLine {
	return s.used[varname]
}
