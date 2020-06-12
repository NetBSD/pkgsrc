package pkglint

import (
	"fmt"
	"hash/crc64"
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/textproc"
	"path"
	"reflect"
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
func regcomp(re regex.Pattern) *regexp.Regexp {
	return G.res.Compile(re)
}
func match(s string, re regex.Pattern) []string {
	return G.res.Match(s, re)
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
func replaceAll(s string, re regex.Pattern, repl string) string {
	return G.res.Compile(re).ReplaceAllString(s, repl)
}
func replaceAllFunc(s string, re regex.Pattern, repl func(string) string) string {
	return G.res.Compile(re).ReplaceAllStringFunc(s, repl)
}

func containsStr(slice []string, s string) bool {
	for _, str := range slice {
		if s == str {
			return true
		}
	}
	return false
}

func mapStr(slice []string, fn func(s string) string) []string {
	result := make([]string, len(slice))
	for i, str := range slice {
		result[i] = fn(str)
	}
	return result
}

func anyStr(slice []string, fn func(s string) bool) bool {
	for _, str := range slice {
		if fn(str) {
			return true
		}
	}
	return false
}

func filterStr(slice []string, fn func(s string) bool) []string {
	result := make([]string, 0, len(slice))
	for _, str := range slice {
		if fn(str) {
			result = append(result, str)
		}
	}
	return result
}

func invalidCharacters(s string, valid *textproc.ByteSet) string {
	var unis strings.Builder

	for _, r := range s {
		switch {
		case r == rune(byte(r)) && valid.Contains(byte(r)):
			continue
		case '!' <= r && r <= '~':
			unis.WriteByte(' ')
			unis.WriteByte(byte(r))
		case r == ' ':
			unis.WriteString(" space")
		case r == '\t':
			unis.WriteString(" tab")
		default:
			_, _ = fmt.Fprintf(&unis, " %U", r)
		}
	}

	if unis.Len() == 0 {
		return ""
	}
	return unis.String()[1:]
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

func rtrimHspace(str string) string {
	end := len(str)
	for end > 0 && isHspace(str[end-1]) {
		end--
	}
	return str[:end]
}

// trimCommon returns the middle portion of the given strings that differs.
func trimCommon(a, b string) (string, string) {
	// trim common prefix
	for len(a) > 0 && len(b) > 0 && a[0] == b[0] {
		a = a[1:]
		b = b[1:]
	}

	// trim common suffix
	for len(a) > 0 && len(b) > 0 && a[len(a)-1] == b[len(b)-1] {
		a = a[:len(a)-1]
		b = b[:len(b)-1]
	}

	return a, b
}

func replaceOnce(s, from, to string) (ok bool, replaced string) {

	index := strings.Index(s, from)
	if index != -1 && index == strings.LastIndex(s, from) {
		return true, s[:index] + to + s[index+len(from):]
	}
	return false, s
}

func isHspace(ch byte) bool {
	return ch == ' ' || ch == '\t'
}

func condStr(cond bool, a, b string) string {
	if cond {
		return a
	}
	return b
}

func condInt(cond bool, trueValue, falseValue int) int {
	if cond {
		return trueValue
	}
	return falseValue
}

func keysJoined(m map[string]bool) string {
	return strings.Join(keysSorted(m), " ")
}

func keysSorted(m map[string]bool) []string {
	var keys []string
	for key := range m {
		keys = append(keys, key)
	}
	sort.Strings(keys)
	return keys
}

func copyStringMkLine(m map[string]*MkLine) map[string]*MkLine {
	c := make(map[string]*MkLine, len(m))
	for k, v := range m {
		c[k] = v
	}
	return c
}

func forEachStringMkLine(m map[string]*MkLine, action func(s string, mkline *MkLine)) {
	var keys []string
	for key := range m {
		keys = append(keys, key)
	}
	sort.Strings(keys)
	for _, key := range keys {
		action(key, m[key])
	}
}

func imax(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func imin(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// assertNil ensures that the given error is nil.
//
// Contrary to other diagnostics, the format should not end in a period
// since it is followed by the error.
//
// Other than Assertf, this method does not require any comparison operator in the calling code.
// This makes it possible to get 100% branch coverage for cases that "really can never fail".
func assertNil(err error, format string, args ...interface{}) {
	if err != nil {
		panic("Pkglint internal error: " + sprintf(format, args...) + ": " + err.Error())
	}
}

func assertNotNil(obj interface{}) {

	// https://stackoverflow.com/questions/13476349/check-for-nil-and-nil-interface-in-go
	isNil := func() bool {
		defer func() { _ = recover() }()
		return reflect.ValueOf(obj).IsNil()
	}

	if obj == nil || isNil() {
		panic("Pkglint internal error: unexpected nil pointer")
	}
}

// assert checks that the condition is true. Otherwise it terminates the
// process with a fatal error message, prefixed with "Pkglint internal error".
//
// This method must only be used for programming errors.
// For runtime errors, use dummyLine.Fatalf.
func assert(cond bool) {
	if !cond {
		panic("Pkglint internal error")
	}
}

// assertf checks that the condition is true. Otherwise it terminates the
// process with a fatal error message, prefixed with "Pkglint internal error".
//
// This method must only be used for programming errors.
// For runtime errors, use dummyLine.Fatalf.
func assertf(cond bool, format string, args ...interface{}) {
	if !cond {
		panic("Pkglint internal error: " + sprintf(format, args...))
	}
}

func isEmptyDir(filename CurrPath) bool {
	if filename.HasSuffixPath("CVS") {
		return true
	}

	dirents, err := filename.ReadDir()
	if err != nil {
		return true // XXX: Why not false?
	}

	for _, dirent := range dirents {
		name := dirent.Name()
		if isIgnoredFilename(name) {
			continue
		}
		if dirent.IsDir() && isEmptyDir(filename.JoinNoClean(NewRelPathString(name))) {
			continue
		}
		return false
	}
	return true
}

func getSubdirs(filename CurrPath) []RelPath {
	dirents, err := filename.ReadDir()
	if err != nil {
		G.Logger.TechFatalf(filename, "Cannot be read: %s", err)
	}

	var subdirs []RelPath
	for _, dirent := range dirents {
		name := dirent.Name()
		if dirent.IsDir() && !isIgnoredFilename(name) && !isEmptyDir(filename.JoinNoClean(NewRelPathString(name))) {
			subdirs = append(subdirs, NewRelPathString(name))
		}
	}
	return subdirs
}

func isIgnoredFilename(filename string) bool {
	switch filename {
	case "CVS", ".svn", ".git", ".hg", ".idea":
		return true
	}
	return hasPrefix(filename, ".#")
}

// Checks whether a file is already committed to the CVS repository.
func isCommitted(filename CurrPath) bool {
	entries := G.loadCvsEntries(filename)
	_, found := entries[filename.Base()]
	return found
}

// isLocallyModified tests whether a file (not a directory) is modified,
// as seen by CVS.
//
// There is no corresponding test for Git (as used by pkgsrc-wip) since that
// is more difficult to implement than simply reading a CVS/Entries file.
func isLocallyModified(filename CurrPath) bool {
	entries := G.loadCvsEntries(filename)
	entry, found := entries[filename.Base()]
	if !found {
		return false
	}

	st, err := filename.Stat()
	if err != nil {
		return true
	}

	// Following http://cvsman.com/cvs-1.12.12/cvs_19.php, format both timestamps.
	cvsModTime := entry.Timestamp
	fsModTime := st.ModTime().UTC().Format(time.ANSIC)
	if trace.Tracing {
		trace.Stepf("cvs.time=%q fs.time=%q", cvsModTime, fsModTime)
	}

	return cvsModTime != fsModTime
}

// CvsEntry is one of the entries in a CVS/Entries file.
//
// See http://cvsman.com/cvs-1.12.12/cvs_19.php.
type CvsEntry struct {
	Name      RelPath
	Revision  string
	Timestamp string
	Options   string
	TagDate   string
}

// Returns the number of columns that a string occupies when printed with
// a tabulator size of 8.
func tabWidth(s string) int { return tabWidthAppend(0, s) }

func tabWidthSlice(strs ...string) int {
	w := 0
	for _, str := range strs {
		w = tabWidthAppend(w, str)
	}
	return w
}

func tabWidthAppend(width int, s string) int {
	for _, r := range s {
		assert(r != '\n')
		if r == '\t' {
			width = width&-8 + 8
		} else {
			width++
		}
	}
	return width
}

func detab(s string) string {
	var detabbed strings.Builder
	for _, r := range s {
		if r == '\t' {
			detabbed.WriteString("        "[:8-detabbed.Len()&7])
		} else {
			detabbed.WriteRune(r)
		}
	}
	return detabbed.String()
}

// alignWith extends str with as many tabs and spaces as needed to reach
// the same screen width as the other string.
func alignWith(str, other string) string {
	return str + alignmentTo(str, other)
}

// alignmentTo returns the whitespace that is necessary to
// bring str to the same width as other.
func alignmentTo(str, other string) string {
	strWidth := tabWidth(str)
	otherWidth := tabWidth(other)
	return alignmentToWidths(strWidth, otherWidth)
}

func alignmentToWidths(strWidth, otherWidth int) string {
	if otherWidth <= strWidth {
		return ""
	}
	if strWidth&-8 != otherWidth&-8 {
		strWidth &= -8
	}
	return indent(otherWidth - strWidth)
}

func indent(width int) string {
	const tabsAndSpaces = "\t\t\t\t\t\t\t\t\t       "
	middle := len(tabsAndSpaces) - 7
	if width <= 8*middle+7 {
		start := middle - width>>3
		end := middle + width&7
		return tabsAndSpaces[start:end]
	}
	return strings.Repeat("\t", width>>3) + "       "[:width&7]
}

// alignmentAfter returns the indentation that is necessary to get
// from the given prefix to the desired width.
func alignmentAfter(prefix string, width int) string {
	pw := tabWidth(prefix)
	assert(width >= pw)
	return indent(width - condInt(pw&-8 != width&-8, pw&-8, pw))
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

func toInt(s string, def int) int {
	if n, err := strconv.Atoi(s); err == nil {
		return n
	}
	return def
}

func containsVarUse(s string) bool {
	if !contains(s, "$") {
		return false
	}
	lex := NewMkLexer(s, nil)
	tokens, _ := lex.MkTokens()
	for _, token := range tokens {
		if token.Varuse != nil {
			return true
		}
	}
	return false
}

func containsVarRefLong(s string) bool {
	if !contains(s, "$") {
		return false
	}
	lex := NewMkLexer(s, nil)
	tokens, _ := lex.MkTokens()
	for _, token := range tokens {
		if token.Varuse != nil && len(token.Text) > 2 {
			return true
		}
	}
	return false
}

// Once remembers with which arguments its FirstTime method has been called
// and only returns true on each first call.
type Once struct {
	seen map[uint64]struct{}

	// Only used during testing, to trace the actual arguments,
	// since hashing is a one-way function.
	Trace bool
}

func (o *Once) FirstTime(what string) bool {
	key := o.keyString(what)
	firstTime := o.check(key)
	if firstTime && o.Trace {
		G.Logger.out.WriteLine("FirstTime: " + what)
	}
	return firstTime
}

func (o *Once) FirstTimeSlice(whats ...string) bool {
	key := o.keyStrings(whats)
	firstTime := o.check(key)
	if firstTime && o.Trace {
		G.Logger.out.WriteLine("FirstTime: " + strings.Join(whats, ", "))
	}
	return firstTime
}

func (o *Once) Seen(what string) bool {
	_, seen := o.seen[o.keyString(what)]
	return seen
}

func (o *Once) SeenSlice(whats ...string) bool {
	_, seen := o.seen[o.keyStrings(whats)]
	return seen
}

func (*Once) keyString(what string) uint64 {
	return crc64.Checksum([]byte(what), crc64.MakeTable(crc64.ECMA))
}

func (*Once) keyStrings(whats []string) uint64 {
	crc := crc64.New(crc64.MakeTable(crc64.ECMA))
	for i, what := range whats {
		if i != 0 {
			_, _ = crc.Write([]byte{0})
		}
		_, _ = crc.Write([]byte(what))
	}
	return crc.Sum64()
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
//
// TODO: Decide whether the scope should consider variable assignments
//  from the pkgsrc infrastructure. For Package.checkGnuConfigureUseLanguages
//  it would be better to ignore them completely.
//
// TODO: Merge this code with Var, which defines essentially the
//  same features.
//
// See also substScope, which already analyzes the possible variable values
// based on the conditional code paths.
//
// See also RedundantScope.
type Scope struct {
	vs    map[string]*scopeVar
	names []string
}

type scopeVar struct {
	firstDef       *MkLine
	lastDef        *MkLine
	value          string
	used           *MkLine
	fallback       string
	usedAtLoadTime bool
	indeterminate  bool
}

func NewScope() Scope {
	return Scope{make(map[string]*scopeVar), nil}
}

func (s *Scope) varnames() []string {
	if len(s.names) == 0 && len(s.vs) > 0 {
		varnames := make([]string, len(s.vs))
		i := 0
		for varname := range s.vs {
			varnames[i] = varname
			i++
		}
		sort.Strings(varnames)
		s.names = varnames
	}
	return s.names
}

func (s *Scope) create(varname string) *scopeVar {
	if v := s.vs[varname]; v != nil {
		return v
	}
	var sv scopeVar
	s.vs[varname] = &sv
	s.names = nil
	return &sv
}

// Define marks the variable and its canonicalized form as defined.
func (s *Scope) Define(varname string, mkline *MkLine) {
	s.def(varname, mkline)
	varcanon := varnameCanon(varname)
	if varcanon != varname {
		s.def(varcanon, mkline)
	}
}

func (s *Scope) def(name string, mkline *MkLine) {
	v := s.create(name)
	if v.firstDef == nil {
		v.firstDef = mkline
		if trace.Tracing {
			trace.Step2("Defining %q for the first time in %s", name, mkline.String())
		}
	} else if trace.Tracing {
		trace.Step2("Defining %q in %s", name, mkline.String())
	}

	v.lastDef = mkline

	// In most cases the defining lines are indeed variable assignments.
	// Exceptions are comments from documentation sections, which still mark
	// the variable as defined so that it doesn't produce the "used but not defined" warning;
	// see MkLines.collectDocumentedVariables.
	if !mkline.IsVarassign() {
		return
	}

	switch mkline.Op() {
	case opAssignAppend:
		value := mkline.Value()
		if trace.Tracing {
			trace.Stepf("Scope.Define.append %s: %s = %q + %q",
				mkline.String(), name, v.value, value)
		}
		v.value += " " + value
	case opAssignDefault:
		if v.value == "" && !v.indeterminate {
			v.value = mkline.Value()
		}
	case opAssignShell:
		v.value = ""
		v.indeterminate = true
	default:
		v.value = mkline.Value()
	}
}

func (s *Scope) Fallback(varname string, value string) {
	s.create(varname).fallback = value
}

// Use marks the variable and its canonicalized form as used.
func (s *Scope) Use(varname string, line *MkLine, time VucTime) {
	use := func(name string) {
		v := s.create(name)
		if v.used == nil {
			v.used = line
			if trace.Tracing {
				trace.Step2("Using %q in %s", name, line.String())
			}
		}
		if time == VucLoadTime {
			v.usedAtLoadTime = true
		}
	}

	use(varname)
	use(varnameCanon(varname))
}

// Mentioned returns the first line in which the variable is either:
//  - defined,
//  - mentioned in a commented variable assignment,
//  - mentioned in a documentation comment.
func (s *Scope) Mentioned(varname string) *MkLine {
	if v := s.vs[varname]; v != nil {
		return v.firstDef
	}
	return nil
}

// IsDefined tests whether the variable is defined.
// It does NOT test the canonicalized variable name.
//
// Even if IsDefined returns true, FirstDefinition doesn't necessarily return true
// since the latter ignores the default definitions from vardefs.go, keyword dummyVardefMkline.
func (s *Scope) IsDefined(varname string) bool {
	mkline := s.Mentioned(varname)
	return mkline != nil && mkline.IsVarassign()
}

// IsDefinedSimilar tests whether the variable or its canonicalized form is defined.
func (s *Scope) IsDefinedSimilar(varname string) bool {
	if s.IsDefined(varname) {
		if trace.Tracing {
			trace.Step1("Variable %q is defined", varname)
		}
		return true
	}

	varcanon := varnameCanon(varname)
	if s.IsDefined(varcanon) {
		if trace.Tracing {
			trace.Step2("Variable %q (similar to %q) is defined", varcanon, varname)
		}
		return true
	}
	return false
}

// IsUsed tests whether the variable is used.
// It does NOT test the canonicalized variable name.
func (s *Scope) IsUsed(varname string) bool {
	return s.FirstUse(varname) != nil
}

// IsUsedSimilar tests whether the variable or its canonicalized form is used.
func (s *Scope) IsUsedSimilar(varname string) bool {
	return s.FirstUse(varname) != nil || s.FirstUse(varnameCanon(varname)) != nil
}

// IsUsedAtLoadTime returns true if the variable is used at load time
// somewhere.
func (s *Scope) IsUsedAtLoadTime(varname string) bool {
	v := s.vs[varname]
	return v != nil && v.usedAtLoadTime
}

// FirstDefinition returns the line in which the variable has been defined first.
//
// Having multiple definitions is typical in the branches of "if" statements.
//
// Another typical case involves two files: the included file defines a default
// value, and the including file later overrides that value. Or the other way
// round: the including file sets a value first, and the included file then
// assigns a default value using ?=.
func (s *Scope) FirstDefinition(varname string) *MkLine {
	v := s.vs[varname]
	if v == nil {
		return nil
	}

	mkline := v.firstDef
	if mkline != nil && mkline.IsVarassign() {
		lastLine := s.LastDefinition(varname)
		if trace.Tracing && lastLine != mkline {
			trace.Stepf("%s: FirstDefinition differs from LastDefinition in %s.",
				mkline.String(), mkline.RelMkLine(lastLine))
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
// value, and the including file later overrides that value. Or the other way
// round: the including file sets a value first, and the included file then
// assigns a default value using ?=.
func (s *Scope) LastDefinition(varname string) *MkLine {
	v := s.vs[varname]
	if v == nil {
		return nil
	}

	mkline := v.lastDef
	if mkline != nil && mkline.IsVarassign() {
		return mkline
	}
	return nil // See NewPackage and G.Pkgsrc.UserDefinedVars
}

// Commented returns whether the variable has only been defined in commented
// variable assignments. These are ignored by bmake but used heavily in
// mk/defaults/mk.conf for documentation.
func (s *Scope) Commented(varname string) *MkLine {
	v := s.vs[varname]
	if v == nil {
		return nil
	}

	mklines := make([]*MkLine, 0, 2)
	if v.firstDef != nil {
		mklines = append(mklines, v.firstDef)
	}
	if v.lastDef != nil {
		mklines = append(mklines, v.lastDef)
	}

	for _, mkline := range mklines {
		if mkline.IsVarassign() {
			return nil
		}
	}

	for _, mkline := range mklines {
		if mkline.IsCommentedVarassign() {
			return mkline
		}
	}

	return nil
}

func (s *Scope) FirstUse(varname string) *MkLine {
	v := s.vs[varname]
	if v == nil {
		return nil
	}
	return v.used
}

// LastValue returns the value from the last variable definition.
//
// If an empty string is returned, this can mean either that the
// variable value is indeed the empty string or that the variable
// was not found, or that the variable value cannot be determined
// reliably. To distinguish these cases, call LastValueFound instead.
func (s *Scope) LastValue(varname string) string {
	value, _, _ := s.LastValueFound(varname)
	return value
}

func (s *Scope) LastValueFound(varname string) (value string, found bool, indeterminate bool) {
	v := s.vs[varname]
	if v == nil {
		return
	}

	value = v.value
	found = v.firstDef != nil && v.firstDef.IsVarassign()
	indeterminate = v.indeterminate
	if found {
		return
	}

	return v.fallback, v.fallback != "", v.indeterminate
}

func (s *Scope) DefineAll(other *Scope) {
	for _, varname := range other.varnames() {
		v := other.vs[varname]
		if v.firstDef != nil {
			s.Define(varname, v.firstDef)
			s.Define(varname, v.lastDef)
		}
	}
}

func (s *Scope) forEach(action func(varname string, data *scopeVar)) {
	var keys []string
	for key := range s.vs {
		keys = append(keys, key)
	}
	sort.Strings(keys)
	for _, key := range keys {
		action(key, s.vs[key])
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
			// Otherwise, the one with fewer zeros is less.
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

// LoadsPrefs returns whether the given file, when included, loads the user
// preferences.
func LoadsPrefs(filename RelPath) bool {
	switch filename.Base() {
	case // See https://github.com/golang/go/issues/28057
		"bsd.prefs.mk",         // in mk/
		"bsd.fast.prefs.mk",    // in mk/
		"bsd.builtin.mk",       // in mk/buildlink3/
		"pkgconfig-builtin.mk", // in mk/buildlink3/
		"pkg-build-options.mk", // in mk/
		"compiler.mk",          // in mk/
		"options.mk",           // in package directories
		"bsd.options.mk":       // in mk/
		return true
	}

	// Just assume that every pkgsrc infrastructure file includes
	// bsd.prefs.mk, at least indirectly.
	return filename.ContainsPath("mk")
}

func IsPrefs(filename RelPath) bool {
	base := filename.Base()
	return base == "bsd.prefs.mk" || base == "bsd.fast.prefs.mk"
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
	lines   *Lines
}

func NewFileCache(size int) *FileCache {
	return &FileCache{
		make([]*fileCacheEntry, 0, size),
		make(map[string]*fileCacheEntry),
		0,
		0}
}

func (c *FileCache) Put(filename CurrPath, options LoadOptions, lines *Lines) {
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
	sort.Slice(c.table, func(i, j int) bool {
		return c.table[j].count < c.table[i].count
	})

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

func (c *FileCache) Get(filename CurrPath, options LoadOptions) *Lines {
	key := c.key(filename)
	entry, found := c.mapping[key]
	if found && entry.options == options {
		c.hits++
		entry.count++

		lines := make([]*Line, entry.lines.Len())
		for i, line := range entry.lines.Lines {
			lines[i] = NewLineMulti(filename, line.Location.lineno, line.Text, line.raw)
		}
		return NewLines(filename, lines)
	}
	c.misses++
	return nil
}

func (c *FileCache) Evict(filename CurrPath) {
	key := c.key(filename)
	entry, found := c.mapping[key]
	if !found {
		return
	}

	delete(c.mapping, key)

	for i, e := range c.table {
		if e == entry {
			c.table[i] = c.table[len(c.table)-1]
			c.table = c.table[:len(c.table)-1]
			return
		}
	}
}

func (c *FileCache) key(filename CurrPath) string { return filename.Clean().String() }

func bmakeHelp(topic string) string { return bmake("help topic=" + topic) }

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
			word := lexer.NextBytesSet(notSpace)

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
	escaped := NewLazyStringBuilder(s)
	for i, r := range s {
		switch {
		case rune(byte(r)) == r && textproc.XPrint.Contains(s[i]):
			escaped.WriteByte(byte(r))
		case r == 0xFFFD && !hasPrefix(s[i:], "\uFFFD"):
			_, _ = fmt.Fprintf(&escaped, "<0x%02X>", s[i])
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

// joinCambridge returns "first, second conn third".
// It is used when each element is a single word.
// Empty elements are ignored completely.
func joinCambridge(conn string, elements ...string) string {
	parts := make([]string, 0, 2+2*len(elements))
	for _, element := range elements {
		if element != "" {
			parts = append(parts, ", ", element)
		}
	}

	if len(parts) == 0 {
		return ""
	}
	if len(parts) < 4 {
		return parts[1]
	}

	parts = append(parts[1:len(parts)-2], " ", conn, " ", parts[len(parts)-1])
	return strings.Join(parts, "")
}

// joinOxford returns "first, second, conn third".
// It is used when each element may consist of multiple words.
// Empty elements are ignored completely.
func joinOxford(conn string, elements ...string) string {
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

var pathMatchers = make(map[string]*pathMatcher)

type pathMatcher struct {
	matchType       pathMatchType
	pattern         string
	originalPattern string
}

func newPathMatcher(pattern string) *pathMatcher {
	matcher := pathMatchers[pattern]
	if matcher == nil {
		matcher = newPathMatcherUncached(pattern)
		pathMatchers[pattern] = matcher
	}
	return matcher
}

func newPathMatcherUncached(pattern string) *pathMatcher {
	assert(strings.IndexByte(pattern, '[') == -1)
	assert(strings.IndexByte(pattern, '?') == -1)

	stars := strings.Count(pattern, "*")
	assert(stars == 0 || stars == 1)
	switch {
	case stars == 0:
		return &pathMatcher{pmExact, pattern, pattern}
	case pattern[0] == '*':
		return &pathMatcher{pmSuffix, pattern[1:], pattern}
	default:
		assert(pattern[len(pattern)-1] == '*')
		return &pathMatcher{pmPrefix, pattern[:len(pattern)-1], pattern}
	}
}

func (m pathMatcher) matches(subject string) bool {
	switch m.matchType {
	case pmPrefix:
		return hasPrefix(subject, m.pattern)
	case pmSuffix:
		return hasSuffix(subject, m.pattern)
	default:
		return subject == m.pattern
	}
}

type pathMatchType uint8

const (
	pmExact pathMatchType = iota
	pmPrefix
	pmSuffix
)

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

// StringSet stores unique strings in insertion order.
type StringSet struct {
	Elements []string
	seen     map[string]struct{}
}

func NewStringSet() StringSet {
	return StringSet{nil, make(map[string]struct{})}
}

func (s *StringSet) Add(element string) {
	if _, found := s.seen[element]; !found {
		s.seen[element] = struct{}{}
		s.Elements = append(s.Elements, element)
	}
}

func (s *StringSet) AddAll(elements []string) {
	for _, element := range elements {
		s.Add(element)
	}
}

// See mk/tools/shquote.sh.
func shquote(s string) string {
	if matches(s, `^[!%+,\-./0-9:=@A-Z_a-z]+$`) {
		return s
	}
	return "'" + strings.Replace(s, "'", "'\\''", -1) + "'"
}

func pathMatches(pattern, s string) bool {
	matched, err := path.Match(pattern, s)
	return err == nil && matched
}

type CurrPathQueue struct {
	entries []CurrPath
}

func (q *CurrPathQueue) PushFront(entries ...CurrPath) {
	q.entries = append(append([]CurrPath(nil), entries...), q.entries...)
}

func (q *CurrPathQueue) Push(entries ...CurrPath) {
	q.entries = append(q.entries, entries...)
}

func (q *CurrPathQueue) IsEmpty() bool {
	return len(q.entries) == 0
}

func (q *CurrPathQueue) Front() CurrPath {
	return q.entries[0]
}

func (q *CurrPathQueue) Pop() CurrPath {
	front := q.entries[0]
	q.entries = q.entries[1:]
	return front
}

// LazyStringBuilder builds a string that is most probably equal to an
// already existing string. In that case, it avoids any memory allocations.
type LazyStringBuilder struct {
	expected string
	len      int
	usingBuf bool
	buf      []byte
}

func NewLazyStringBuilder(expected string) LazyStringBuilder {
	return LazyStringBuilder{expected: expected}
}

func (b *LazyStringBuilder) Write(p []byte) (n int, err error) {
	for _, c := range p {
		b.WriteByte(c)
	}
	return len(p), nil
}

func (b *LazyStringBuilder) Len() int {
	return b.len
}

func (b *LazyStringBuilder) WriteString(s string) {
	if !b.usingBuf && b.len+len(s) <= len(b.expected) && hasPrefix(b.expected[b.len:], s) {
		b.len += len(s)
		return
	}
	for _, c := range []byte(s) {
		b.WriteByte(c)
	}
}

func (b *LazyStringBuilder) WriteByte(c byte) {
	if !b.usingBuf && b.len < len(b.expected) && b.expected[b.len] == c {
		b.len++
		return
	}
	b.writeToBuf(c)
}

func (b *LazyStringBuilder) writeToBuf(c byte) {
	if !b.usingBuf {
		if cap(b.buf) >= b.len {
			b.buf = b.buf[:b.len]
			assert(copy(b.buf, b.expected) == b.len)
		} else {
			b.buf = []byte(b.expected)[:b.len]
		}
		b.usingBuf = true
	}

	b.buf = append(b.buf, c)
	b.len++
}

func (b *LazyStringBuilder) Reset(expected string) {
	b.expected = expected
	b.usingBuf = false
	b.len = 0
}

func (b *LazyStringBuilder) String() string {
	if b.usingBuf {
		return string(b.buf[:b.len])
	}
	return b.expected[:b.len]
}

type interval struct {
	min int
	max int
}

func newInterval() *interval {
	return &interval{int(^uint(0) >> 1), ^int(^uint(0) >> 1)}
}

func (i *interval) add(x int) {
	if x < i.min {
		i.min = x
	}
	if x > i.max {
		i.max = x
	}
}

type optInt struct {
	isSet bool
	value int
}

func (i *optInt) get() int {
	assert(i.isSet)
	return i.value
}

func (i *optInt) set(value int) {
	i.value = value
	i.isSet = true
}

type bag struct {
	// Wrapping the slice in an extra struct avoids 'receiver might be nil'
	// warnings.

	entries []bagEntry
}

func (b *bag) sortDesc() {
	es := b.entries
	less := func(i, j int) bool { return es[j].count < es[i].count }
	sort.SliceStable(es, less)
}

func (b *bag) opt(index int) int {
	if uint(index) < uint(len(b.entries)) {
		return b.entries[index].count
	}
	return 0
}

func (b *bag) key(index int) interface{} { return b.entries[index].key }

func (b *bag) add(key interface{}, count int) {
	b.entries = append(b.entries, bagEntry{key, count})
}

func (b *bag) len() int { return len(b.entries) }

type bagEntry struct {
	key   interface{}
	count int
}

type lazyBool struct {
	fn    func() bool
	value bool
}

func newLazyBool(fn func() bool) *lazyBool { return &lazyBool{fn, false} }

func (b *lazyBool) get() bool {
	if b.fn != nil {
		b.value = b.fn()
		b.fn = nil
	}
	return b.value
}
