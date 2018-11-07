package main

import (
	"fmt"
	"io/ioutil"
	"netbsd.org/pkglint/regex"
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
func sprintf(format string, args ...interface{}) string {
	return fmt.Sprintf(format, args...)
}
func fields(s string) []string {
	return strings.Fields(s)
}
func matches(s string, re regex.Pattern) bool {
	return G.res.Matches(s, re)
}
func match1(s string, re regex.Pattern) (matched bool, m1 string) {
	return G.res.Match1(s, re)
}
func match2(s string, re regex.Pattern) (matched bool, m1, m2 string) {
	return G.res.Match2(s, re)
}
func match3(s string, re regex.Pattern) (matched bool, m1, m2, m3 string) {
	return G.res.Match3(s, re)
}
func match4(s string, re regex.Pattern) (matched bool, m1, m2, m3, m4 string) {
	return G.res.Match4(s, re)
}
func match5(s string, re regex.Pattern) (matched bool, m1, m2, m3, m4, m5 string) {
	return G.res.Match5(s, re)
}
func replaceAll(s string, re regex.Pattern, repl string) string {
	return G.res.Compile(re).ReplaceAllString(s, repl)
}
func replaceAllFunc(s string, re regex.Pattern, repl func(string) string) string {
	return G.res.Compile(re).ReplaceAllStringFunc(s, repl)
}

// trimHspace returns str, with leading and trailing space (U+0020)
// and tab (U+0009) removed.
//
// It is simpler and faster than strings.TrimSpace.
func trimHspace(str string) string {
	start := 0
	end := len(str)
	for start < end && isHspace(str[start]) {
		start++
	}
	for start < end && isHspace(str[end-1]) {
		end--
	}
	return str[start:end]
}

func isHspace(ch byte) bool {
	return ch == ' ' || ch == '\t'
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
	if m := G.res.Match(s, re); m != nil {
		return m
	}
	panic(fmt.Sprintf("mustMatch %q %q", s, re))
}

func isEmptyDir(fileName string) bool {
	dirents, err := ioutil.ReadDir(fileName)
	if err != nil || hasSuffix(fileName, "/CVS") {
		return true
	}
	for _, dirent := range dirents {
		name := dirent.Name()
		if isIgnoredFilename(name) {
			continue
		}
		if dirent.IsDir() && isEmptyDir(fileName+"/"+name) {
			continue
		}
		return false
	}
	return true
}

func getSubdirs(fileName string) []string {
	dirents, err := ioutil.ReadDir(fileName)
	if err != nil {
		NewLineWhole(fileName).Fatalf("Cannot be read: %s", err)
	}

	var subdirs []string
	for _, dirent := range dirents {
		name := dirent.Name()
		if dirent.IsDir() && !isIgnoredFilename(name) && !isEmptyDir(fileName+"/"+name) {
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
func isCommitted(fileName string) bool {
	lines := loadCvsEntries(fileName)
	if lines == nil {
		return false
	}
	needle := "/" + path.Base(fileName) + "/"
	for _, line := range lines.Lines {
		if hasPrefix(line.Text, needle) {
			return true
		}
	}
	return false
}

func isLocallyModified(fileName string) bool {
	baseName := path.Base(fileName)

	lines := loadCvsEntries(fileName)
	if lines == nil {
		return false
	}

	for _, line := range lines.Lines {
		fields := strings.Split(line.Text, "/")
		if 3 < len(fields) && fields[1] == baseName {
			st, err := os.Stat(fileName)
			if err != nil {
				return true
			}

			// According to http://cvsman.com/cvs-1.12.12/cvs_19.php, format both timestamps.
			cvsModTime := fields[3]
			fsModTime := st.ModTime().Format(time.ANSIC)
			if trace.Tracing {
				trace.Stepf("cvs.time=%q fs.time=%q", cvsModTime, fsModTime)
			}

			return cvsModTime != fsModTime
		}
	}
	return false
}

func loadCvsEntries(fileName string) Lines {
	dir := path.Dir(fileName)
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
	if dot > 0 {
		return varname[:dot]
	}
	return varname
}
func varnameCanon(varname string) string {
	dot := strings.IndexByte(varname, '.')
	if dot > 0 {
		return varname[:dot] + ".*"
	}
	return varname
}
func varnameParam(varname string) string {
	dot := strings.IndexByte(varname, '.')
	if dot > 0 {
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

// varIsDefinedSimilar tests whether the variable (or its canonicalized form)
// is defined in the current package or in the current file.
func varIsDefinedSimilar(varname string) bool {
	return G.Mk != nil && (G.Mk.vars.DefinedSimilar(varname) || G.Mk.forVars[varname]) ||
		G.Pkg != nil && G.Pkg.vars.DefinedSimilar(varname)
}

// varIsUsedSimilar tests whether the variable (or its canonicalized form)
// is used in the current package or in the current file.
func varIsUsedSimilar(varname string) bool {
	return G.Mk != nil && G.Mk.vars.UsedSimilar(varname) ||
		G.Pkg != nil && G.Pkg.vars.UsedSimilar(varname)
}

func fileExists(fileName string) bool {
	st, err := os.Stat(fileName)
	return err == nil && st.Mode().IsRegular()
}

func dirExists(fileName string) bool {
	st, err := os.Stat(fileName)
	return err == nil && st.Mode().IsDir()
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
	return replaceAllFunc(s, re, func(match string) string {
		if gflag || !done {
			done = !gflag
			return to
		}
		return match
	})
}

// relpath returns the relative path from `from` to `to`.
func relpath(from, to string) string {
	if hasPrefix(to, from) && len(to) > len(from)+1 && to[len(from)] == '/' {
		return path.Clean(to[len(from)+1:])
	}

	absFrom := abspath(from)
	absTo := abspath(to)
	rel, err := filepath.Rel(absFrom, absTo)
	G.Assertf(err == nil, "relpath %q %q.", from, to)
	result := filepath.ToSlash(rel)
	if trace.Tracing {
		trace.Stepf("relpath from %q to %q = %q", from, to, result)
	}
	return result
}

func abspath(fileName string) string {
	abs, err := filepath.Abs(fileName)
	G.Assertf(err == nil, "abspath %q.", fileName)
	return filepath.ToSlash(abs)
}

// Differs from path.Clean in that only "../../" is replaced, not "../".
// Also, the initial directory is always kept.
// This is to provide the package path as context in recursive invocations of pkglint.
func cleanpath(fileName string) string {
	tmp := fileName
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

	// Repeatedly replace `/[^.][^/]*/[^.][^/]*/\.\./\.\./` with "/"
again:
	slash0 := -1
	slash1 := -1
	slash2 := -1
	for i, ch := range []byte(tmp) {
		if ch == '/' {
			slash0 = slash1
			slash1 = slash2
			slash2 = i
			if slash0 != -1 && tmp[slash0+1:slash1] != ".." && tmp[slash1+1:slash2] != ".." && hasPrefix(tmp[i:], "/../../") {
				tmp = tmp[:slash0] + tmp[i+6:]
				goto again
			}
		}
	}

	tmp = strings.TrimSuffix(tmp, "/")
	return tmp
}

func containsVarRef(s string) bool {
	return contains(s, "${")
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
	defined  map[string]MkLine
	fallback map[string]string
	used     map[string]MkLine
}

func NewScope() Scope {
	return Scope{make(map[string]MkLine), make(map[string]string), make(map[string]MkLine)}
}

// Define marks the variable and its canonicalized form as defined.
func (s *Scope) Define(varname string, mkline MkLine) {
	if s.defined[varname] == nil {
		s.defined[varname] = mkline
		if trace.Tracing {
			trace.Step2("Defining %q in line %s", varname, mkline.Linenos())
		}
	}
	varcanon := varnameCanon(varname)
	if varcanon != varname && s.defined[varcanon] == nil {
		s.defined[varcanon] = mkline
		if trace.Tracing {
			trace.Step2("Defining %q in line %s", varcanon, mkline.Linenos())
		}
	}
}

func (s *Scope) Fallback(varname string, value string) {
	s.fallback[varname] = value
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
//
// Even if Defined returns true, FirstDefinition doesn't necessarily return true
// since the latter ignores the default definitions from vardefs.go, keyword dummyVardefMkline.
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

// FirstDefinition returns the line in which the variable has been defined first.
// Having multiple definitions is typical in the branches of "if" statements.
func (s *Scope) FirstDefinition(varname string) MkLine {
	mkline := s.defined[varname]
	if mkline != nil && mkline.IsVarassign() {
		return mkline
	}
	return nil // See NewPackage and G.Pkgsrc.UserDefinedVars
}

func (s *Scope) FirstUse(varname string) MkLine {
	return s.used[varname]
}

func (s *Scope) Value(varname string) (value string, found bool) {
	mkline := s.FirstDefinition(varname)
	if mkline != nil {
		return mkline.Value(), true
	}
	if fallback, ok := s.fallback[varname]; ok {
		return fallback, true
	}
	return "", false
}

func (s *Scope) DefineAll(other Scope) {
	var varnames []string
	for varname := range other.defined {
		varnames = append(varnames, varname)
	}
	sort.Strings(varnames)

	for _, varname := range varnames {
		s.Define(varname, other.defined[varname])
	}
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
			op = opAssign // The two operators are effectively the same in this case.
		}
		existing, found := s.vars[varname]
		if !found {
			if op == opAssignShell || op == opAssignEval {
				s.vars[varname] = nil // Won't be checked further.
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
			case opAssignShell, opAssignEval:
				s.vars[varname] = nil // Won't be checked further.
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

// IsPrefs returns whether the given file, when included, loads the user
// preferences.
func IsPrefs(fileName string) bool {
	switch path.Base(fileName) {
	case // See https://github.com/golang/go/issues/28057
		"bsd.prefs.mk",         // in mk/
		"bsd.fast.prefs.mk",    // in mk/
		"bsd.builtin.mk",       // in mk/buildlink3/
		"pkgconfig-builtin.mk", // in mk/buildlink3/
		"bsd.options.mk":       // in mk/
		return true
	}
	return false
}

func isalnum(s string) bool {
	for _, ch := range []byte(s) {
		if !('0' <= ch && ch <= '9' || 'A' <= ch && ch <= 'Z' || ch == '_' || 'a' <= ch && ch <= 'z') {
			return false
		}
	}
	return true
}

// FileCache reduces the IO load for commonly loaded files by about 50%,
// especially for buildlink3.mk and *.buildlink3.mk files.
type FileCache struct {
	table   []*fileCacheEntry
	mapping map[string]*fileCacheEntry // Pointers into FileCache.table
	hits    int
	misses  int
}

type fileCacheEntry struct {
	count   int
	key     string
	options LoadOptions
	lines   Lines
}

func NewFileCache(size int) *FileCache {
	return &FileCache{
		make([]*fileCacheEntry, 0, size),
		make(map[string]*fileCacheEntry),
		0,
		0}
}

func (c *FileCache) Put(fileName string, options LoadOptions, lines Lines) {
	key := c.key(fileName)

	entry := c.mapping[key]
	if entry == nil {
		if len(c.table) == cap(c.table) {
			c.removeOldEntries()
		}

		entry = new(fileCacheEntry)
		c.table = append(c.table, entry)
		c.mapping[key] = entry
	}

	entry.count = 1
	entry.key = key
	entry.options = options
	entry.lines = lines
}

func (c *FileCache) removeOldEntries() {
	sort.Slice(c.table, func(i, j int) bool { return c.table[j].count < c.table[i].count })

	if G.Testing {
		for _, e := range c.table {
			G.logOut.Printf("FileCache %q with count %d.\n", e.key, e.count)
		}
	}

	minCount := c.table[len(c.table)-1].count
	newLen := len(c.table)
	for newLen > 0 && c.table[newLen-1].count == minCount {
		e := c.table[newLen-1]
		if G.Testing {
			G.logOut.Printf("FileCache.Evict %q with count %d.\n", e.key, e.count)
		}
		delete(c.mapping, e.key)
		newLen--
	}
	c.table = c.table[0:newLen]

	// To avoid files getting stuck in the cache.
	for _, e := range c.table {
		if G.Testing {
			G.logOut.Printf("FileCache.Halve %q with count %d.\n", e.key, e.count)
		}
		e.count /= 2
	}
}

func (c *FileCache) Get(fileName string, options LoadOptions) Lines {
	key := c.key(fileName)
	entry, found := c.mapping[key]
	if found && entry.options == options {
		c.hits++
		entry.count++

		lines := make([]Line, entry.lines.Len())
		for i, line := range entry.lines.Lines {
			lines[i] = NewLineMulti(fileName, int(line.firstLine), int(line.lastLine), line.Text, line.raw)
		}
		return NewLines(fileName, lines)
	}
	c.misses++
	return nil
}

func (c *FileCache) Evict(fileName string) {
	key := c.key(fileName)
	entry, found := c.mapping[key]
	if found {
		delete(c.mapping, key)

		sort.Slice(c.table, func(i, j int) bool {
			return c.table[j] == entry && c.table[i] != entry
		})
		c.table = c.table[0 : len(c.table)-1]
	}
}

func (c *FileCache) key(fileName string) string {
	return path.Clean(fileName)
}

func makeHelp(topic string) string { return bmake("help topic=" + topic) }

func bmake(target string) string { return sprintf("%s %s", confMake, target) }
