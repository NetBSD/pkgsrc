package main

import (
	"fmt"
	"io"
	"io/ioutil"
	"os"
	"path"
	"path/filepath"
	"reflect"
	"regexp"
	"runtime"
	"sort"
	"strconv"
	"strings"
	"time"
)

// Short names for commonly used functions.
func contains(s, substr string) bool  { return strings.Contains(s, substr) }
func hasPrefix(s, prefix string) bool { return strings.HasPrefix(s, prefix) }
func hasSuffix(s, suffix string) bool { return strings.HasSuffix(s, suffix) }

func ifelseStr(cond bool, a, b string) string {
	if cond {
		return a
	}
	return b
}

func mustMatch(s, re string) []string {
	if m := match(s, re); m != nil {
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
		Fatalf(fname, noLines, "Cannot be read: %s", err)
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
	basename := path.Base(fname)
	lines, err := readLines(path.Dir(fname)+"/CVS/Entries", false)
	if err != nil {
		return false
	}
	for _, line := range lines {
		if hasPrefix(line.Text, "/"+basename+"/") {
			return true
		}
	}
	return false
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

func defineVar(mkline *MkLine, varname string) {
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
	return regcomp(`\s+`).Split(s, -1)
}

func fileExists(fname string) bool {
	st, err := os.Stat(fname)
	return err == nil && st.Mode().IsRegular()
}

func dirExists(fname string) bool {
	st, err := os.Stat(fname)
	return err == nil && st.Mode().IsDir()
}

var res = make(map[string]*regexp.Regexp)

func regcomp(re string) *regexp.Regexp {
	cre := res[re]
	if cre == nil {
		cre = regexp.MustCompile(re)
		res[re] = cre
	}
	return cre
}

func match(s, re string) []string {
	if !G.opts.Profiling {
		return regcomp(re).FindStringSubmatch(s)
	}

	before := time.Now()
	immediatelyBefore := time.Now()
	m := regcomp(re).FindStringSubmatch(s)
	after := time.Now()

	delay := immediatelyBefore.UnixNano() - before.UnixNano()
	timeTaken := after.UnixNano() - immediatelyBefore.UnixNano() - delay

	G.retime.Add(re, int(timeTaken))
	if m != nil {
		G.rematch.Add(re, 1)
	} else {
		G.renomatch.Add(re, 1)
	}
	return m
}

func matches(s, re string) bool {
	matches := regcomp(re).MatchString(s)
	if G.opts.Profiling {
		if matches {
			G.rematch.Add(re, 1)
		} else {
			G.renomatch.Add(re, 1)
		}
	}
	return matches
}

func matchn(s, re string, n int) []string {
	if m := match(s, re); m != nil {
		if len(m) != 1+n {
			panic(fmt.Sprintf("expected match%d, got match%d for %q", len(m)-1, n, re))
		}
		return m
	}
	return nil
}

func match1(s, re string) (matched bool, m1 string) {
	if m := matchn(s, re, 1); m != nil {
		return true, m[1]
	}
	return
}
func match2(s, re string) (matched bool, m1, m2 string) {
	if m := matchn(s, re, 2); m != nil {
		return true, m[1], m[2]
	}
	return
}
func match3(s, re string) (matched bool, m1, m2, m3 string) {
	if m := matchn(s, re, 3); m != nil {
		return true, m[1], m[2], m[3]
	}
	return
}
func match4(s, re string) (matched bool, m1, m2, m3, m4 string) {
	if m := matchn(s, re, 4); m != nil {
		return true, m[1], m[2], m[3], m[4]
	}
	return
}
func match5(s, re string) (matched bool, m1, m2, m3, m4, m5 string) {
	if m := matchn(s, re, 5); m != nil {
		return true, m[1], m[2], m[3], m[4], m[5]
	}
	return
}

func replaceFirst(s, re, replacement string) ([]string, string) {
	if G.opts.DebugTrace {
		defer tracecall(s, re, replacement)()
	}

	if m := regcomp(re).FindStringSubmatchIndex(s); m != nil {
		replaced := s[:m[0]] + replacement + s[m[1]:]
		mm := make([]string, len(m)/2)
		for i := 0; i < len(m); i += 2 {
			mm[i/2] = s[negToZero(m[i]):negToZero(m[i+1])]
		}
		return mm, replaced
	}
	return nil, s
}

type PrefixReplacer struct {
	rest string
	s    string   // The last match from a prefix
	m    []string // The last match from a regular expression
}

func NewPrefixReplacer(s string) *PrefixReplacer {
	return &PrefixReplacer{s, "", nil}
}

func (pr *PrefixReplacer) AdvanceBytes(bits0x00, bits0x20, bits0x40, bits0x60 uint32, re string) bool {
	if G.TestingData != nil {
		pr.verifyBits(bits0x00, bits0x20, bits0x40, bits0x60, re)
	}

	rest := pr.rest
	n := len(pr.rest)
	i := 0
loop:
	for ; i < n; i++ {
		b := rest[i]
		var mask uint32
		switch b & 0xE0 {
		case 0x00:
			mask = bits0x00
		case 0x20:
			mask = bits0x20
		case 0x40:
			mask = bits0x40
		case 0x60:
			mask = bits0x60
		}
		if (mask>>(b&0x1F))&1 == 0 {
			break loop
		}
	}
	pr.s = rest[:i]
	pr.rest = rest[i:]
	return i != 0
}

func (pr *PrefixReplacer) AdvanceStr(prefix string) bool {
	pr.m = nil
	pr.s = ""
	if hasPrefix(pr.rest, prefix) {
		if G.opts.DebugTrace {
			trace("", "PrefixReplacer.AdvanceStr", pr.rest, prefix)
		}
		pr.s = prefix
		pr.rest = pr.rest[len(prefix):]
		return true
	}
	return false
}
func (pr *PrefixReplacer) AdvanceRegexp(re string) bool {
	pr.m = nil
	pr.s = ""
	if !hasPrefix(re, "^") {
		panic(fmt.Sprintf("PrefixReplacer.AdvanceRegexp: regular expression %q must have prefix %q.", re, "^"))
	}
	if matches("", re) {
		panic(fmt.Sprintf("PrefixReplacer.AdvanceRegexp: the empty string must not match the regular expression %q.", re))
	}
	if m := match(pr.rest, re); m != nil {
		if G.opts.DebugTrace {
			trace("", "PrefixReplacer.AdvanceRegexp", pr.rest, re, m[0])
		}
		pr.rest = pr.rest[len(m[0]):]
		pr.m = m
		return true
	}
	return false
}

func (pr *PrefixReplacer) PeekByte() int {
	rest := pr.rest
	if len(rest) == 0 {
		return -1
	}
	return int(rest[0])
}

func (pr *PrefixReplacer) Mark() string {
	return pr.rest
}
func (pr *PrefixReplacer) Reset(mark string) {
	pr.rest = mark
}
func (pr *PrefixReplacer) Skip(n int) {
	pr.rest = pr.rest[n:]
}
func (pr *PrefixReplacer) SkipSpace() {
	pr.rest = strings.TrimLeft(pr.rest, " \t")
}
func (pr *PrefixReplacer) Since(mark string) string {
	return mark[:len(mark)-len(pr.rest)]
}
func (pr *PrefixReplacer) AdvanceRest() string {
	rest := pr.rest
	pr.rest = ""
	return rest
}

func (pr *PrefixReplacer) verifyBits(bits0x00, bits0x20, bits0x40, bits0x60 uint32, re string) {
	if G.TestingData.VerifiedBits[re] {
		return
	}
	G.TestingData.VerifiedBits[re] = true
	rec := regcomp(re)

	var actual0x00, actual0x20, actual0x40, actual0x60 uint32
	mask := uint32(0)
	for i := byte(0); i < 0x80; i++ {
		if rec.Match([]byte{i}) {
			mask |= uint32(1) << (i & 31)
		}
		switch i {
		case 0x1F:
			actual0x00 = mask
		case 0x3F:
			actual0x20 = mask
		case 0x5F:
			actual0x40 = mask
		case 0x7F:
			actual0x60 = mask
		}
		if i&0x1F == 0x1F {
			mask = 0
		}
	}
	if actual0x00 == bits0x00 && actual0x20 == bits0x20 && actual0x40 == bits0x40 && actual0x60 == bits0x60 {
		return
	}

	print(fmt.Sprintf(""+
		"Expected bits(%#08x, %#08x, %#08x, %#08x), "+
		"not bits(%#08x, %#08x, %#08x, %#08x) "+
		"for pattern %q.\n",
		actual0x00, actual0x20, actual0x40, actual0x60,
		bits0x00, bits0x20, bits0x40, bits0x60,
		re))
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

// http://stackoverflow.com/questions/13476349/check-for-nil-and-nil-interface-in-go
func isNil(a interface{}) bool {
	defer func() { recover() }()
	return a == nil || reflect.ValueOf(a).IsNil()
}

func argsStr(args ...interface{}) string {
	argsStr := ""
	for i, arg := range args {
		if i != 0 {
			argsStr += ", "
		}
		if str, ok := arg.(fmt.Stringer); ok && !isNil(str) {
			argsStr += str.String()
		} else {
			argsStr += fmt.Sprintf("%#v", arg)
		}
	}
	return argsStr
}

func trace(action, funcname string, args ...interface{}) {
	if G.opts.DebugTrace {
		io.WriteString(G.debugOut, fmt.Sprintf("TRACE: %s%s%s(%s)\n", strings.Repeat("| ", G.traceDepth), action, funcname, argsStr(args...)))
	}
}

func tracecallInternal(args ...interface{}) func() {
	if !G.opts.DebugTrace {
		panic("Internal pkglint error: calls to tracecall must only occur in tracing mode")
	}

	funcname := "?"
	if pc, _, _, ok := runtime.Caller(2); ok {
		if fn := runtime.FuncForPC(pc); fn != nil {
			funcname = strings.TrimSuffix(fn.Name(), "main.")
		}
	}
	trace("+ ", funcname, args...)
	G.traceDepth++

	return func() {
		G.traceDepth--
		trace("- ", funcname, args...)
	}
}
func tracecall0() func() {
	switch { // prevent inlining, for code size and performance
	}
	return tracecallInternal()
}
func tracecall1(arg1 string) func() {
	switch { // prevent inlining, for code size and performance
	}
	return tracecallInternal(arg1)
}
func tracecall2(arg1, arg2 string) func() {
	switch { // prevent inlining, for code size and performance
	}
	return tracecallInternal(arg1, arg2)
}
func tracecall(args ...interface{}) func() {
	switch { // prevent inlining, for code size and performance
	}
	return tracecallInternal(args...)
}

// Emulates make(1)’s :S substitution operator.
func mkopSubst(s string, left bool, from string, right bool, to string, all bool) string {
	re := ifelseStr(left, "^", "") + regexp.QuoteMeta(from) + ifelseStr(right, "$", "")
	done := false
	return regcomp(re).ReplaceAllStringFunc(s, func(match string) string {
		if all || !done {
			done = !all
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
		panic("relpath" + argsStr(from, to, err1, err2, err3))
	}
	result := filepath.ToSlash(rel)
	if G.opts.DebugTrace {
		trace("", "relpath", from, to, "=>", result)
	}
	return result
}

func stringBoolMapKeys(m map[string]bool) []string {
	var keys []string
	for k := range m {
		keys = append(keys, k)
	}
	sort.Strings(keys)
	return keys
}

func stringStringMapKeys(m map[string]string) []string {
	var keys []string
	for k := range m {
		keys = append(keys, k)
	}
	sort.Strings(keys)
	return keys
}

func abspath(fname string) string {
	abs, err := filepath.Abs(fname)
	if err != nil {
		Fatalf(fname, noLines, "Cannot determine absolute path.")
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

func reReplaceRepeatedly(from string, re string, to string) string {
	replaced := regcomp(re).ReplaceAllString(from, to)
	if replaced != from {
		return reReplaceRepeatedly(replaced, re, to)
	}
	return replaced
}

type Histogram struct {
	histo map[string]int
}

func NewHistogram() *Histogram {
	h := new(Histogram)
	h.histo = make(map[string]int)
	return h
}

func (h *Histogram) Add(s string, n int) {
	if G.opts.Profiling {
		h.histo[s] += n
	}
}

func (h *Histogram) PrintStats(caption string, out io.Writer, limit int) {
	entries := make([]HistogramEntry, len(h.histo))

	i := 0
	for s, count := range h.histo {
		entries[i] = HistogramEntry{s, count}
		i++
	}

	sort.Sort(ByCountDesc(entries))

	for i, entry := range entries {
		fmt.Fprintf(out, "%s %6d %s\n", caption, entry.count, entry.s)
		if limit > 0 && i >= limit {
			break
		}
	}
}

type HistogramEntry struct {
	s     string
	count int
}
type ByCountDesc []HistogramEntry

func (a ByCountDesc) Len() int {
	return len(a)
}
func (a ByCountDesc) Swap(i, j int) {
	a[i], a[j] = a[j], a[i]
}
func (a ByCountDesc) Less(i, j int) bool {
	if a[j].count < a[i].count {
		return true
	}
	return a[i].count == a[j].count && a[i].s < a[j].s
}

func hasAlnumPrefix(s string) bool {
	if s == "" {
		return false
	}
	b := s[0]
	return '0' <= b && b <= '9' || 'A' <= b && b <= 'Z' || b == '_' || 'a' <= b && b <= 'z'
}
