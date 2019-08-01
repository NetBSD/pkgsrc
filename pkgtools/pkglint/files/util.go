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

func rtrimHspace(str string) string {
	end := len(str)
	for end > 0 && isHspace(str[end-1]) {
		end--
	}
	return str[:end]
}

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

func isEmptyDir(filename string) bool {
	if hasSuffix(filename, "/CVS") {
		return true
	}

	dirents, err := ioutil.ReadDir(filename)
	if err != nil {
		return true // XXX: Why not false?
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
	entries := G.loadCvsEntries(filename)
	_, found := entries[path.Base(filename)]
	return found
}

// isLocallyModified tests whether a file (not a directory) is modified,
// as seen by CVS.
//
// There is no corresponding test for Git (as used by pkgsrc-wip) since that
// is more difficult to implement than simply reading a CVS/Entries file.
func isLocallyModified(filename string) bool {
	entries := G.loadCvsEntries(filename)
	entry, found := entries[path.Base(filename)]
	if !found {
		return false
	}

	st, err := os.Stat(filename)
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
	Name      string
	Revision  string
	Timestamp string
	Options   string
	TagDate   string
}

// Returns the number of columns that a string occupies when printed with
// a tabulator size of 8.
func tabWidth(s string) int {
	length := 0
	for _, r := range s {
		if r == '\t' {
			length = length&-8 + 8
		} else {
			length++
		}
	}
	return length
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

// alignWith extends str with as many tabs as needed to reach
// the same screen width as the other string.
func alignWith(str, other string) string {
	alignBefore := (tabWidth(other) + 7) & -8
	alignAfter := tabWidth(str) & -8
	tabsNeeded := imax((alignBefore-alignAfter)/8, 1)
	return str + strings.Repeat("\t", tabsNeeded)
}

func indent(width int) string {
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
	re := regex.Pattern(condStr(left, "^", "") + regexp.QuoteMeta(from) + condStr(right, "$", ""))
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
//
// The relative path is built by going from the "from" directory via the
// pkgsrc root to the "to" filename. This produces the form
// "../../category/package" that is found in DEPENDS and .include lines.
//
// Both from and to are interpreted relative to the current working directory,
// unless they are absolute paths.
//
// This function should only be used if the relative path from one file to
// another cannot be computed in another way. The preferred way is to take
// the relative filenames directly from the .include or exists() where they
// appear.
//
// TODO: Invent data types for all kinds of relative paths that occur in pkgsrc
//  and pkglint. Make sure that these paths cannot be accidentally mixed.
func relpath(from, to string) (result string) {

	if trace.Tracing {
		defer trace.Call(from, to, trace.Result(&result))()
	}

	cfrom := cleanpath(from)
	cto := cleanpath(to)

	if cfrom == cto {
		return "."
	}

	// Take a shortcut for the common case from "dir" to "dir/subdir/...".
	if hasPrefix(cto, cfrom) && hasPrefix(cto[len(cfrom):], "/") {
		return cleanpath(cto[len(cfrom)+1:])
	}

	// Take a shortcut for the common case from "category/package" to ".".
	// This is the most common variant in a complete pkgsrc scan.
	if cto == "." {
		fromParts := strings.FieldsFunc(cfrom, func(r rune) bool { return r == '/' })
		if len(fromParts) == 2 && !hasPrefix(fromParts[0], ".") && !hasPrefix(fromParts[1], ".") {
			return "../.."
		}
	}

	if cfrom == "." && !filepath.IsAbs(cto) {
		return path.Clean(cto)
	}

	absFrom := abspath(cfrom)
	absTopdir := abspath(G.Pkgsrc.topdir)
	absTo := abspath(cto)

	toTop, err := filepath.Rel(absFrom, absTopdir)
	assertNil(err, "relpath from %q to topdir %q", absFrom, absTopdir)

	fromTop, err := filepath.Rel(absTopdir, absTo)
	assertNil(err, "relpath from topdir %q to %q", absTopdir, absTo)

	result = cleanpath(filepath.ToSlash(toTop) + "/" + filepath.ToSlash(fromTop))

	if trace.Tracing {
		trace.Stepf("relpath from %q to %q = %q", cfrom, cto, result)
	}
	return
}

func abspath(filename string) string {
	abs := filename
	if !filepath.IsAbs(filename) {
		abs = G.cwd + "/" + abs
	}
	return path.Clean(abs)
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

	for len(parts) > 1 && parts[len(parts)-1] == "." {
		parts = parts[:len(parts)-1]
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

func pathContains(haystack, needle string) bool {
	n0 := needle[0]
	for i := 0; i < 1+len(haystack)-len(needle); i++ {
		if haystack[i] == n0 && hasPrefix(haystack[i:], needle) {
			if i == 0 || haystack[i-1] == '/' {
				if i+len(needle) == len(haystack) || haystack[i+len(needle)] == '/' {
					return true
				}
			}
		}
	}
	return false
}

func pathContainsDir(haystack, needle string) bool {
	n0 := needle[0]
	for i := 0; i < 1+len(haystack)-len(needle); i++ {
		if haystack[i] == n0 && hasPrefix(haystack[i:], needle) {
			if i == 0 || haystack[i-1] == '/' {
				if i+len(needle) < len(haystack) && haystack[i+len(needle)] == '/' {
					return true
				}
			}
		}
	}
	return false
}

func containsVarRef(s string) bool {
	return contains(s, "${")
}

func hasAlnumPrefix(s string) bool { return s != "" && textproc.AlnumU.Contains(s[0]) }

// Once remembers with which arguments its FirstTime method has been called
// and only returns true on each first call.
type Once struct {
	seen map[uint64]struct{}

	// Only used during testing, to trace the actual arguments,
	// since hashing is a one-way function.
	Trace bool
}

func (o *Once) FirstTime(what string) bool {
	firstTime := o.check(o.keyString(what))
	if firstTime && o.Trace {
		G.Logger.out.WriteLine(sprintf("FirstTime: %s", what))
	}
	return firstTime
}

func (o *Once) FirstTimeSlice(whats ...string) bool {
	firstTime := o.check(o.keyStrings(whats))
	if firstTime && o.Trace {
		G.Logger.out.WriteLine(sprintf("FirstTime: %s", strings.Join(whats, ", ")))
	}
	return firstTime
}

func (o *Once) Seen(what string) bool {
	_, seen := o.seen[o.keyString(what)]
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
type Scope struct {
	firstDef       map[string]*MkLine // TODO: Can this be removed?
	lastDef        map[string]*MkLine
	value          map[string]string
	used           map[string]*MkLine
	usedAtLoadTime map[string]bool
	fallback       map[string]string
}

func NewScope() Scope {
	return Scope{
		make(map[string]*MkLine),
		make(map[string]*MkLine),
		make(map[string]string),
		make(map[string]*MkLine),
		make(map[string]bool),
		make(map[string]string)}
}

// Define marks the variable and its canonicalized form as defined.
func (s *Scope) Define(varname string, mkline *MkLine) {
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
		// Exceptions are comments from documentation sections, which still mark
		// it as defined so that it doesn't produce the "used but not defined" warning;
		// see MkLines.collectDocumentedVariables.
		if mkline.IsVarassign() {
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
func (s *Scope) Use(varname string, line *MkLine, time VucTime) {
	use := func(name string) {
		if s.used[name] == nil {
			s.used[name] = line
			if trace.Tracing {
				trace.Step2("Using %q in %s", name, line.String())
			}
		}
		if time == VucLoadTime {
			s.usedAtLoadTime[name] = true
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
	return s.firstDef[varname]
}

// Defined tests whether the variable is defined.
// It does NOT test the canonicalized variable name.
//
// Even if Defined returns true, FirstDefinition doesn't necessarily return true
// since the latter ignores the default definitions from vardefs.go, keyword dummyVardefMkline.
func (s *Scope) Defined(varname string) bool {
	mkline := s.firstDef[varname]
	return mkline != nil && mkline.IsVarassign()
}

// DefinedSimilar tests whether the variable or its canonicalized form is defined.
func (s *Scope) DefinedSimilar(varname string) bool {
	if s.Defined(varname) {
		if trace.Tracing {
			trace.Step1("Variable %q is defined", varname)
		}
		return true
	}

	varcanon := varnameCanon(varname)
	if s.Defined(varcanon) {
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

// UsedAtLoadTime returns true if the variable is used at load time
// somewhere.
func (s *Scope) UsedAtLoadTime(varname string) bool {
	return s.usedAtLoadTime[varname]
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
	mkline := s.firstDef[varname]
	if mkline != nil && mkline.IsVarassign() {
		lastLine := s.LastDefinition(varname)
		if trace.Tracing && lastLine != mkline {
			trace.Stepf("%s: FirstDefinition differs from LastDefinition in %s.",
				mkline.String(), mkline.RefTo(lastLine))
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
	mkline := s.lastDef[varname]
	if mkline != nil && mkline.IsVarassign() {
		return mkline
	}
	return nil // See NewPackage and G.Pkgsrc.UserDefinedVars
}

// Commented returns whether the variable has only been defined in commented
// variable assignments. These are ignored by bmake but used heavily in
// mk/defaults/mk.conf for documentation.
func (s *Scope) Commented(varname string) *MkLine {
	var mklines []*MkLine
	if first := s.firstDef[varname]; first != nil {
		mklines = append(mklines, first)
	}
	if last := s.lastDef[varname]; last != nil {
		mklines = append(mklines, last)
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
	lines   *Lines
}

func NewFileCache(size int) *FileCache {
	return &FileCache{
		make([]*fileCacheEntry, 0, size),
		make(map[string]*fileCacheEntry),
		0,
		0}
}

func (c *FileCache) Put(filename string, options LoadOptions, lines *Lines) {
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

func (c *FileCache) Get(filename string, options LoadOptions) *Lines {
	key := c.key(filename)
	entry, found := c.mapping[key]
	if found && entry.options == options {
		c.hits++
		entry.count++

		lines := make([]*Line, entry.lines.Len())
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
			_, _ = fmt.Fprintf(&escaped, "<0x%02X>", rest[j])
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

type pathMatcher struct {
	matchType       pathMatchType
	pattern         string
	originalPattern string
}

func newPathMatcher(pattern string) *pathMatcher {
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
