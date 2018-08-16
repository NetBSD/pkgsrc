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
	"sort"
	"strconv"
	"strings"
	"time"
)

type YesNoUnknown uint8

const (
	no YesNoUnknown = iota
	yes
	unknown
)

func (ynu YesNoUnknown) String() string {
	return [...]string{"no", "yes", "unknown"}[ynu]
}

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

func keysJoined(m map[string]bool) string {
	var keys []string
	for key := range m {
		keys = append(keys, key)
	}
	sort.Strings(keys)
	return strings.Join(keys, " ")
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

	lines := Load(dir+"/CVS/Entries", 0)
	if lines == nil {
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
	return regex.Compile(`\S+`).FindAllString(s, -1)
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
			fnames = append(fnames, cleanpath(dirname+"/"+fi.Name()))
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

// relpath returns the relative path from `from` to `to`.
func relpath(from, to string) string {
	absFrom, err1 := filepath.Abs(from)
	absTo, err2 := filepath.Abs(to)
	rel, err3 := filepath.Rel(absFrom, absTo)
	if err1 != nil || err2 != nil || err3 != nil {
		trace.Stepf("relpath.panic", from, to, err1, err2, err3)
		panic(fmt.Sprintf("relpath %q, %q", from, to))
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
	if len(tmp) > 2 && hasSuffix(tmp, "/.") {
		tmp = tmp[:len(tmp)-2]
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

// The MIT License (MIT)
//
// Copyright (c) 2015 Frits van Bommel
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// Taken from https://github.com/fvbommel/util/blob/11997822f8/sortorder/natsort.go
func naturalLess(str1, str2 string) bool {

	isDigit := func(b byte) bool { return '0' <= b && b <= '9' }

	idx := 0
	len1, len2 := len(str1), len(str2)
	len := len1 + len2 - imax(len1, len2)
	for idx < len {
		c1, c2 := str1[idx], str2[idx]
		dig1, dig2 := isDigit(c1), isDigit(c2)
		switch {
		case dig1 != dig2: // Digits before other characters.
			return dig1 // True if LHS is a digit, false if the RHS is one.
		case !dig1: // && !dig2, because dig1 == dig2
			// UTF-8 compares bytewise-lexicographically, no need to decode
			// codepoints.
			if c1 != c2 {
				return c1 < c2
			}
			idx++
		default: // Digits
			// Eat zeros.
			idx1, idx2 := idx, idx
			for ; idx1 < len1 && str1[idx1] == '0'; idx1++ {
			}
			for ; idx2 < len2 && str2[idx2] == '0'; idx2++ {
			}
			// Eat all digits.
			nonZero1, nonZero2 := idx1, idx2
			for ; idx1 < len1 && isDigit(str1[idx1]); idx1++ {
			}
			for ; idx2 < len2 && isDigit(str2[idx2]); idx2++ {
			}
			// If lengths of numbers with non-zero prefix differ, the shorter
			// one is less.
			if len1, len2 := idx1-nonZero1, idx2-nonZero2; len1 != len2 {
				return len1 < len2
			}
			// If they're not equal, string comparison is correct.
			if nr1, nr2 := str1[nonZero1:idx1], str2[nonZero2:idx2]; nr1 != nr2 {
				return nr1 < nr2
			}
			// Otherwise, the one with less zeros is less.
			// Because everything up to the number is equal, comparing the index
			// after the zeros is sufficient.
			if nonZero1 != nonZero2 {
				return nonZero1 < nonZero2
			}
			idx = idx1
		}
		// They're identical so far, so continue comparing.
	}
	// So far they are identical. At least one is ended. If the other continues,
	// it sorts last.
	return len1 < len2
}

// RedundantScope checks for redundant variable definitions and accidentally
// overwriting variables. It tries to be as correct as possible by not flagging
// anything that is defined conditionally. There may be some edge cases though
// like defining PKGNAME, then evaluating it using :=, then defining it again.
// This pattern is so error-prone that it should not appear in pkgsrc at all,
// thus pkglint doesn't even expect it. (Well, except for the PKGNAME case,
// but that's deep in the infrastructure and only affects the "nb13" extension.)
type RedundantScope struct {
	vars        map[string]*redundantScopeVarinfo
	dirLevel    int
	OnIgnore    func(old, new MkLine)
	OnOverwrite func(old, new MkLine)
}
type redundantScopeVarinfo struct {
	mkline MkLine
	value  string
}

func NewRedundantScope() *RedundantScope {
	return &RedundantScope{vars: make(map[string]*redundantScopeVarinfo)}
}

func (s *RedundantScope) Handle(mkline MkLine) {
	switch {
	case mkline.IsVarassign():
		varname := mkline.Varname()
		if s.dirLevel != 0 {
			s.vars[varname] = nil
			break
		}

		op := mkline.Op()
		value := mkline.Value()
		valueNovar := mkline.WithoutMakeVariables(value)
		if op == opAssignEval && value == valueNovar {
			op = opAssign // They are effectively the same in this case.
		}
		existing, found := s.vars[varname]
		if !found {
			if op == opAssignShell || op == opAssignEval {
				s.vars[varname] = nil
			} else {
				if op == opAssignAppend {
					value = " " + value
				}
				s.vars[varname] = &redundantScopeVarinfo{mkline, value}
			}
		} else if existing != nil {
			if op == opAssign && existing.value == value {
				op = opAssignDefault
			}
			switch op {
			case opAssign:
				if s.OnOverwrite != nil {
					s.OnOverwrite(existing.mkline, mkline)
				}
				existing.value = value
			case opAssignAppend:
				existing.value += " " + value
			case opAssignDefault:
				if s.OnIgnore != nil {
					s.OnIgnore(existing.mkline, mkline)
				}
			case opAssignShell:
			case opAssignEval:
				s.vars[varname] = nil
			}
		}

	case mkline.IsDirective():
		switch mkline.Directive() {
		case "for", "if", "ifdef", "ifndef":
			s.dirLevel++
		case "endfor", "endif":
			s.dirLevel--
		}
	}
}

func (s *RedundantScope) IsConditional(varname string) bool {
	return s.vars[varname] != nil
}
