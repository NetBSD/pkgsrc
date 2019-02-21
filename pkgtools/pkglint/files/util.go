package pkglint

import (
	"fmt"
	"hash/crc64"
	"io/ioutil"
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/textproc"
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

// intern returns an independent copy of the given string.
//
// It should be called when only a small substring of a large string
// is needed for the rest of the program's lifetime.
//
// All strings allocated here will stay in memory forever,
// therefore it should only be used for long-lived strings.
func intern(str string) string { return G.interner.Intern(str) }

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
	m := G.res.Match(s, re)
	if m == nil {
		G.Assertf(false, "mustMatch %q %q", s, re)
	}
	return m
}

func isEmptyDir(filename string) bool {
	if hasSuffix(filename, "/CVS") {
		return true
	}

	dirents, err := ioutil.ReadDir(filename)
	if err != nil {
		return true
	}

	for _, dirent := range dirents {
		name := dirent.Name()
		if isIgnoredFilename(name) {
			continue
		}
		if dirent.IsDir() && isEmptyDir(filename+"/"+name) {
			continue
		}
		return false
	}
	return true
}

func getSubdirs(filename string) []string {
	dirents, err := ioutil.ReadDir(filename)
	if err != nil {
		NewLineWhole(filename).Fatalf("Cannot be read: %s", err)
	}

	var subdirs []string
	for _, dirent := range dirents {
		name := dirent.Name()
		if dirent.IsDir() && !isIgnoredFilename(name) && !isEmptyDir(filename+"/"+name) {
			subdirs = append(subdirs, name)
		}
	}
	return subdirs
}

func isIgnoredFilename(filename string) bool {
	switch filename {
	case ".", "..", "CVS", ".svn", ".git", ".hg":
		return true
	}
	return false
}

func dirglob(dirname string) []string {
	infos, err := ioutil.ReadDir(dirname)
	if err != nil {
		return nil
	}
	var filenames []string
	for _, info := range infos {
		if !(isIgnoredFilename(info.Name())) {
			filenames = append(filenames, cleanpath(dirname+"/"+info.Name()))
		}
	}
	return filenames
}

// Checks whether a file is already committed to the CVS repository.
func isCommitted(filename string) bool {
	lines := G.loadCvsEntries(filename)
	if lines == nil {
		return false
	}
	needle := "/" + path.Base(filename) + "/"
	for _, line := range lines.Lines {
		if hasPrefix(line.Text, needle) {
			return true
		}
	}
	return false
}

func isLocallyModified(filename string) bool {
	baseName := path.Base(filename)

	lines := G.loadCvsEntries(filename)
	if lines == nil {
		return false
	}

	for _, line := range lines.Lines {
		fields := strings.Split(line.Text, "/")
		if 3 < len(fields) && fields[1] == baseName {
			st, err := os.Stat(filename)
			if err != nil {
				return true
			}

			// Following http://cvsman.com/cvs-1.12.12/cvs_19.php, format both timestamps.
			cvsModTime := fields[3]
			fsModTime := st.ModTime().UTC().Format(time.ANSIC)
			if trace.Tracing {
				trace.Stepf("cvs.time=%q fs.time=%q", cvsModTime, fsModTime)
			}

			return cvsModTime != fsModTime
		}
	}
	return false
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
	codePoints := 0
	for i := range s {
		if codePoints >= maxChars {
			return s[:i] + "..."
		}
		codePoints++
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

func fileExists(filename string) bool {
	st, err := os.Stat(filename)
	return err == nil && st.Mode().IsRegular()
}

func dirExists(filename string) bool {
	st, err := os.Stat(filename)
	return err == nil && st.Mode().IsDir()
}

func toInt(s string, def int) int {
	if n, err := strconv.Atoi(s); err == nil {
		return n
	}
	return def
}

// mkopSubst evaluates make(1)'s :S substitution operator.
func mkopSubst(s string, left bool, from string, right bool, to string, flags string) string {
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

// relpath returns the relative path from the directory "from"
// to the filesystem entry "to".
func relpath(from, to string) string {

	// From "dir" to "dir/subdir/...".
	if hasPrefix(to, from) && len(to) > len(from)+1 && to[len(from)] == '/' {
		return path.Clean(to[len(from)+1:])
	}

	// Take a shortcut for the most common variant in a complete pkgsrc scan,
	// which is to resolve the relative path from a package to the pkgsrc root.
	// This avoids unnecessary calls to the filesystem API.
	if to == "." {
		fromParts := strings.FieldsFunc(from, func(r rune) bool { return r == '/' })
		if len(fromParts) == 3 && !hasPrefix(fromParts[0], ".") && !hasPrefix(fromParts[1], ".") && fromParts[2] == "." {
			return "../.."
		}
	}

	absFrom := abspath(from)
	absTo := abspath(to)
	rel, err := filepath.Rel(absFrom, absTo)
	G.AssertNil(err, "relpath %q %q", from, to)
	result := filepath.ToSlash(rel)
	if trace.Tracing {
		trace.Stepf("relpath from %q to %q = %q", from, to, result)
	}
	return result
}

func abspath(filename string) string {
	abs, err := filepath.Abs(filename)
	G.AssertNil(err, "abspath %q", filename)
	return filepath.ToSlash(abs)
}

// Differs from path.Clean in that only "../../" is replaced, not "../".
// Also, the initial directory is always kept.
// This is to provide the package path as context in recursive invocations of pkglint.
func cleanpath(filename string) string {
	parts := make([]string, 0, 5)
	lex := textproc.NewLexer(filename)
	for lex.SkipString("./") {
	}

	for !lex.EOF() {
		part := lex.NextBytesFunc(func(b byte) bool { return b != '/' })
		parts = append(parts, part)
		if lex.SkipByte('/') {
			for lex.SkipByte('/') || lex.SkipString("./") {
			}
		}
	}

	for i := 2; i+3 < len(parts); /* nothing */ {
		if parts[i] != ".." && parts[i+1] != ".." && parts[i+2] == ".." && parts[i+3] == ".." {
			if i+4 == len(parts) || parts[i+4] != ".." {
				parts = append(parts[:i], parts[i+4:]...)
				continue
			}
		}
		i++
	}

	if len(parts) == 0 {
		return "."
	}
	return strings.Join(parts, "/")
}

func containsVarRef(s string) bool {
	return contains(s, "${")
}

func hasAlnumPrefix(s string) bool { return s != "" && textproc.AlnumU.Contains(s[0]) }

// Once remembers with which arguments its FirstTime method has been called
// and only returns true on each first call.
type Once struct {
	seen map[uint64]struct{}
}

func (o *Once) FirstTime(what string) bool {
	return o.check(crc64.Checksum([]byte(what), crc64.MakeTable(crc64.ECMA)))
}

func (o *Once) FirstTimeSlice(whats ...string) bool {
	crc := crc64.New(crc64.MakeTable(crc64.ECMA))
	for _, what := range whats {
		_, _ = crc.Write([]byte(what))
	}
	return o.check(crc.Sum64())
}

func (o *Once) check(key uint64) bool {
	if _, ok := o.seen[key]; ok {
		return false
	}
	if o.seen == nil {
		o.seen = make(map[uint64]struct{})
	}
	o.seen[key] = struct{}{}
	return true
}

// Scope remembers which variables are defined and which are used
// in a certain scope, such as a package or a file.
type Scope struct {
	firstDef map[string]MkLine // TODO: Can this be removed?
	lastDef  map[string]MkLine
	value    map[string]string
	used     map[string]MkLine
	fallback map[string]string
}

func NewScope() Scope {
	return Scope{
		make(map[string]MkLine),
		make(map[string]MkLine),
		make(map[string]string),
		make(map[string]MkLine),
		make(map[string]string)}
}

// Define marks the variable and its canonicalized form as defined.
func (s *Scope) Define(varname string, mkline MkLine) {
	def := func(name string) {
		if s.firstDef[name] == nil {
			s.firstDef[name] = mkline
			if trace.Tracing {
				trace.Step2("Defining %q for the first time in %s", name, mkline.String())
			}
		} else if trace.Tracing {
			trace.Step2("Defining %q in %s", name, mkline.String())
		}

		s.lastDef[name] = mkline

		// In most cases the defining lines are indeed variable assignments.
		// Exceptions are comments that only document the variable but still mark
		// it as defined so that it doesn't produce the "used but not defined" warning.
		if mkline.IsVarassign() || mkline.IsCommentedVarassign() {

			switch mkline.Op() {
			case opAssign, opAssignEval, opAssignShell:
				s.value[name] = mkline.Value()
			case opAssignAppend:
				s.value[name] += " " + mkline.Value()
			case opAssignDefault:
				// No change to the value.
			}
		}
	}

	def(varname)
	varcanon := varnameCanon(varname)
	if varcanon != varname {
		def(varcanon)
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
			trace.Step2("Using %q in %s", varname, line.String())
		}
	}

	varcanon := varnameCanon(varname)
	if varcanon != varname && s.used[varcanon] == nil {
		s.used[varcanon] = line
		if trace.Tracing {
			trace.Step2("Using %q in %s", varcanon, line.String())
		}
	}
}

// Defined tests whether the variable is defined.
// It does NOT test the canonicalized variable name.
//
// Even if Defined returns true, FirstDefinition doesn't necessarily return true
// since the latter ignores the default definitions from vardefs.go, keyword dummyVardefMkline.
func (s *Scope) Defined(varname string) bool {
	return s.firstDef[varname] != nil
}

// DefinedSimilar tests whether the variable or its canonicalized form is defined.
func (s *Scope) DefinedSimilar(varname string) bool {
	if s.firstDef[varname] != nil {
		if trace.Tracing {
			trace.Step1("Variable %q is defined", varname)
		}
		return true
	}

	varcanon := varnameCanon(varname)
	if s.firstDef[varcanon] != nil {
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
//
// Having multiple definitions is typical in the branches of "if" statements.
func (s *Scope) FirstDefinition(varname string) MkLine {
	mkline := s.firstDef[varname]
	if mkline != nil && mkline.IsVarassign() {
		lastLine := s.LastDefinition(varname)
		if lastLine != mkline {
			//mkline.Notef("FirstDefinition differs from LastDefinition in %s.", mkline.RefTo(lastLine))
		}
		return mkline
	}
	return nil // See NewPackage and G.Pkgsrc.UserDefinedVars
}

// LastDefinition returns the line in which the variable has been defined last.
//
// Having multiple definitions is typical in the branches of "if" statements.
//
// Another typical case involves two files: the included file defines a default
// value, and the including file later overrides that value.
func (s *Scope) LastDefinition(varname string) MkLine {
	mkline := s.lastDef[varname]
	if mkline != nil && mkline.IsVarassign() {
		return mkline
	}
	return nil // See NewPackage and G.Pkgsrc.UserDefinedVars
}

func (s *Scope) FirstUse(varname string) MkLine {
	return s.used[varname]
}

// LastValue returns the value from the last variable definition.
//
// If an empty string is returned this can mean either that the
// variable value is indeed the empty string or that the variable
// was not found. To distinguish these cases, call LastValueFound instead.
func (s *Scope) LastValue(varname string) string {
	value, _ := s.LastValueFound(varname)
	return value
}

func (s *Scope) LastValueFound(varname string) (value string, found bool) {
	value, found = s.value[varname]
	if found {
		return
	}

	mkline := s.LastDefinition(varname)
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
	for varname := range other.firstDef {
		varnames = append(varnames, varname)
	}
	sort.Strings(varnames)

	for _, varname := range varnames {
		s.Define(varname, other.firstDef[varname])
		s.Define(varname, other.lastDef[varname])
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
	minLen := len1 + len2 - imax(len1, len2)
	for idx < minLen {
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

// RedundantScope checks for redundant variable definitions and for variables
// that are accidentally overwritten. It tries to be as correct as possible
// by not flagging anything that is defined conditionally.
//
// There may be some edge cases though like defining PKGNAME, then evaluating
// it using :=, then defining it again. This pattern is so error-prone that
// it should not appear in pkgsrc at all, thus pkglint doesn't even expect it.
// (Well, except for the PKGNAME case, but that's deep in the infrastructure
// and only affects the "nb13" extension.)
type RedundantScope struct {
	vars        map[string]*redundantScopeVarinfo
	dirLevel    int // The number of enclosing directives (.if, .for).
	includePath includePath
	OnRedundant func(old, new MkLine)
	OnOverwrite func(old, new MkLine)
}
type redundantScopeVarinfo struct {
	mkline      MkLine
	includePath includePath
	value       string
}

func NewRedundantScope() *RedundantScope {
	return &RedundantScope{vars: make(map[string]*redundantScopeVarinfo)}
}

func (s *RedundantScope) Handle(mkline MkLine) {
	if mkline.firstLine == 1 {
		s.includePath.push(mkline.Location.Filename)
	} else {
		s.includePath.popUntil(mkline.Location.Filename)
	}

	switch {
	case mkline.IsVarassign():
		varname := mkline.Varname()
		if s.dirLevel != 0 {
			// Since the variable is defined or assigned conditionally,
			// it becomes too complicated for pkglint to check all possible
			// code paths. Therefore ignore the variable from now on.
			s.vars[varname] = nil
			break
		}

		op := mkline.Op()
		value := mkline.Value()
		valueNovar := mkline.WithoutMakeVariables(value)
		if op == opAssignEval && value == valueNovar {
			op = /* effectively */ opAssign
		}

		existing, found := s.vars[varname]
		if !found {
			if op == opAssignShell || op == opAssignEval {
				s.vars[varname] = nil // Won't be checked further.
			} else {
				if op == opAssignAppend {
					value = " " + value
				}
				s.vars[varname] = &redundantScopeVarinfo{mkline, s.includePath.copy(), value}
			}

		} else if existing != nil {
			if op == opAssign && existing.value == value {
				op = /* effectively */ opAssignDefault
			}

			switch op {
			case opAssign:
				if s.includePath.includes(existing.includePath) {
					// This is the usual pattern of including a file and
					// then overwriting some of them. Although technically
					// this overwrites the previous definition, it is not
					// worth a warning since this is used a lot and
					// intentionally.
				} else {
					s.OnOverwrite(existing.mkline, mkline)
				}
				existing.value = value
			case opAssignAppend:
				existing.value += " " + value
			case opAssignDefault:
				if existing.includePath.includes(s.includePath) {
					s.OnRedundant(mkline, existing.mkline)
				} else if s.includePath.includes(existing.includePath) || s.includePath.equals(existing.includePath) {
					s.OnRedundant(existing.mkline, mkline)
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

type includePath struct {
	files []string
}

func (p *includePath) push(filename string) {
	p.files = append(p.files, filename)
}

func (p *includePath) popUntil(filename string) {
	for p.files[len(p.files)-1] != filename {
		p.files = p.files[:len(p.files)-1]
	}
}

func (p *includePath) includes(other includePath) bool {
	for i, filename := range p.files {
		if i < len(other.files) && other.files[i] == filename {
			continue
		}
		return false
	}
	return len(p.files) < len(other.files)
}

func (p *includePath) equals(other includePath) bool {
	if len(p.files) != len(other.files) {
		return false
	}
	for i, filename := range p.files {
		if other.files[i] != filename {
			return false
		}
	}
	return true
}

func (p *includePath) copy() includePath {
	return includePath{append([]string(nil), p.files...)}
}

// IsPrefs returns whether the given file, when included, loads the user
// preferences.
func IsPrefs(filename string) bool {
	switch path.Base(filename) {
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

func (c *FileCache) Put(filename string, options LoadOptions, lines Lines) {
	key := c.key(filename)

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
			if trace.Tracing {
				trace.Stepf("FileCache %q with count %d.", e.key, e.count)
			}
		}
	}

	minCount := c.table[len(c.table)-1].count
	newLen := len(c.table)
	for newLen > 0 && c.table[newLen-1].count == minCount {
		e := c.table[newLen-1]
		if trace.Tracing {
			trace.Stepf("FileCache.Evict %q with count %d.", e.key, e.count)
		}
		delete(c.mapping, e.key)
		newLen--
	}
	c.table = c.table[0:newLen]

	// To avoid files getting stuck in the cache.
	for _, e := range c.table {
		if trace.Tracing {
			trace.Stepf("FileCache.Halve %q with count %d.", e.key, e.count)
		}
		e.count /= 2
	}
}

func (c *FileCache) Get(filename string, options LoadOptions) Lines {
	key := c.key(filename)
	entry, found := c.mapping[key]
	if found && entry.options == options {
		c.hits++
		entry.count++

		lines := make([]Line, entry.lines.Len())
		for i, line := range entry.lines.Lines {
			lines[i] = NewLineMulti(filename, int(line.firstLine), int(line.lastLine), line.Text, line.raw)
		}
		return NewLines(filename, lines)
	}
	c.misses++
	return nil
}

func (c *FileCache) Evict(filename string) {
	key := c.key(filename)
	entry, found := c.mapping[key]
	if found {
		delete(c.mapping, key)

		sort.Slice(c.table, func(i, j int) bool {
			return c.table[j] == entry && c.table[i] != entry
		})
		c.table = c.table[0 : len(c.table)-1]
	}
}

func (c *FileCache) key(filename string) string {
	return path.Clean(filename)
}

func makeHelp(topic string) string { return bmake("help topic=" + topic) }

func bmake(target string) string { return sprintf("%s %s", confMake, target) }

func seeGuide(sectionName, sectionID string) string {
	return sprintf("See the pkgsrc guide, section %q: https://www.NetBSD.org/docs/pkgsrc/pkgsrc.html#%s",
		sectionName, sectionID)
}

// wrap performs automatic word wrapping on the given lines.
//
// Empty lines, indented lines and lines starting with "*" are kept as-is.
func wrap(max int, lines ...string) []string {
	var wrapped []string
	var sb strings.Builder
	nonSpace := textproc.Space.Inverse()

	for _, line := range lines {

		if line == "" || isHspace(line[0]) || line[0] == '*' {

			// Finish current paragraph.
			if sb.Len() > 0 {
				wrapped = append(wrapped, sb.String())
				sb.Reset()
			}

			wrapped = append(wrapped, line)
			continue
		}

		lexer := textproc.NewLexer(line)
		for !lexer.EOF() {
			bol := len(lexer.Rest()) == len(line)
			space := lexer.NextBytesSet(textproc.Space)
			word := lexer.NextBytesSet(nonSpace)

			if bol && sb.Len() > 0 {
				space = " "
			}

			if sb.Len() > 0 && sb.Len()+len(space)+len(word) > max {
				wrapped = append(wrapped, sb.String())
				sb.Reset()
				space = ""
			}

			sb.WriteString(space)
			sb.WriteString(word)
		}
	}

	if sb.Len() > 0 {
		wrapped = append(wrapped, sb.String())
	}

	return wrapped
}

// escapePrintable returns an ASCII-only string that represents the given string
// very closely, but without putting any physical terminal or terminal emulator
// at the risk of interpreting malicious data from the files checked by pkglint.
// This escaping is not reversible, and it doesn't need to.
func escapePrintable(s string) string {
	i := 0
	for i < len(s) && textproc.XPrint.Contains(s[i]) {
		i++
	}
	if i == len(s) {
		return s
	}

	var escaped strings.Builder
	escaped.WriteString(s[:i])
	rest := s[i:]
	for j, r := range rest {
		switch {
		case rune(byte(r)) == r && textproc.XPrint.Contains(byte(rest[j])):
			escaped.WriteByte(byte(r))
		case r == 0xFFFD && !hasPrefix(rest[j:], "\uFFFD"):
			_, _ = fmt.Fprintf(&escaped, "<\\x%02X>", rest[j])
		default:
			_, _ = fmt.Fprintf(&escaped, "<%U>", r)
		}
	}
	return escaped.String()
}

func stringSliceLess(a, b []string) bool {
	limit := len(a)
	if len(b) < limit {
		limit = len(b)
	}

	for i := 0; i < limit; i++ {
		if a[i] != b[i] {
			return a[i] < b[i]
		}
	}

	return len(a) < len(b)
}

func joinSkipEmpty(sep string, elements ...string) string {
	var nonempty []string
	for _, element := range elements {
		if element != "" {
			nonempty = append(nonempty, element)
		}
	}
	return strings.Join(nonempty, sep)
}

func joinSkipEmptyCambridge(conn string, elements ...string) string {
	var nonempty []string
	for _, element := range elements {
		if element != "" {
			nonempty = append(nonempty, element)
		}
	}

	var sb strings.Builder
	for i, element := range nonempty {
		if i > 0 {
			if i == len(nonempty)-1 {
				sb.WriteRune(' ')
				sb.WriteString(conn)
				sb.WriteRune(' ')
			} else {
				sb.WriteString(", ")
			}
		}
		sb.WriteString(element)
	}

	return sb.String()
}

func joinSkipEmptyOxford(conn string, elements ...string) string {
	var nonempty []string
	for _, element := range elements {
		if element != "" {
			nonempty = append(nonempty, element)
		}
	}

	if lastIndex := len(nonempty) - 1; lastIndex >= 1 {
		nonempty[lastIndex] = conn + " " + nonempty[lastIndex]
	}

	return strings.Join(nonempty, ", ")
}

// StringInterner collects commonly used strings to avoid wasting heap memory
// by duplicated strings.
type StringInterner struct {
	strs map[string]string
}

func NewStringInterner() StringInterner {
	return StringInterner{make(map[string]string)}
}

func (si *StringInterner) Intern(str string) string {
	interned, found := si.strs[str]
	if found {
		return interned
	}

	// Ensure that the original string is never stored directly in the map
	// since it might be a substring of a very large string. The interned
	// strings must be completely independent of anything from the outside,
	// so that the large source string can be freed afterwards.
	var sb strings.Builder
	sb.WriteString(str)
	key := sb.String()

	si.strs[key] = key
	return key
}
