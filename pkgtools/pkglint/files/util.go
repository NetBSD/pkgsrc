package main

import (
	"fmt"
	"io"
	"io/ioutil"
	"os"
	"path"
	"path/filepath"
	"regexp"
	"sort"
	"strconv"
	"strings"
)

// Short names for commonly used functions.
var (
	sprintf   = fmt.Sprintf
	contains  = strings.Contains
	hasPrefix = strings.HasPrefix
	hasSuffix = strings.HasSuffix
)

func ifelseStr(cond bool, a, b string) string {
	if cond {
		return a
	}
	return b
}

func mustMatch(pattern string, s string) []string {
	if m := regcomp(pattern).FindStringSubmatch(s); m != nil {
		return m
	}
	panic(sprintf("mustMatch %q %q", pattern, s))
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
		fatalf(fname, NO_LINES, "Cannot be read: %s", err)
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
		if hasPrefix(line.text, "/"+basename+"/") {
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
	return strings.Split(varname, ".")[0]
}
func varnameCanon(varname string) string {
	parts := strings.SplitN(varname, ".", 2)
	if len(parts) == 2 {
		return parts[0] + ".*"
	}
	return parts[0]
}
func varnameParam(varname string) string {
	parts := strings.SplitN(varname, ".", 2)
	return parts[len(parts)-1]
}

func defineVar(line *Line, varname string) {
	if mk := G.mkContext; mk != nil {
		mk.defineVar(line, varname)
	}
	if pkg := G.pkgContext; pkg != nil {
		pkg.defineVar(line, varname)
	}
}
func varIsDefined(varname string) bool {
	varcanon := varnameCanon(varname)
	if mk := G.mkContext; mk != nil && (mk.vardef[varname] != nil || mk.vardef[varcanon] != nil) {
		return true
	}
	if pkg := G.pkgContext; pkg != nil && (pkg.vardef[varname] != nil || pkg.vardef[varcanon] != nil) {
		return true
	}
	return false
}
func useVar(line *Line, varname string) {
	varcanon := varnameCanon(varname)
	if mk := G.mkContext; mk != nil {
		mk.varuse[varname] = line
		mk.varuse[varcanon] = line
	}
	if pkg := G.pkgContext; pkg != nil {
		pkg.varuse[varname] = line
		pkg.varuse[varcanon] = line
	}
}

func varIsUsed(varname string) bool {
	varcanon := varnameCanon(varname)
	if mk := G.mkContext; mk != nil && (mk.varuse[varname] != nil || mk.varuse[varcanon] != nil) {
		return true
	}
	if pkg := G.pkgContext; pkg != nil && (pkg.varuse[varname] != nil || pkg.varuse[varcanon] != nil) {
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
	m := regcomp(re).FindStringSubmatch(s)
	if G.opts.Profiling {
		if m != nil {
			G.rematch.add(re)
		} else {
			G.renomatch.add(re)
		}
	}
	return m
}

func matches(s, re string) bool {
	matches := regcomp(re).MatchString(s)
	if G.opts.Profiling {
		if matches {
			G.rematch.add(re)
		} else {
			G.renomatch.add(re)
		}
	}
	return matches
}

func matchn(s, re string, n int) []string {
	if m := match(s, re); m != nil {
		if len(m) != 1+n {
			panic(sprintf("expected match%d, got match%d for %q", len(m)-1, n, re))
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
	defer tracecall("replaceFirst", s, re, replacement)()

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

func replacePrefix(ps *string, pm *[]string, re string) bool {
	if m := regcomp(re).FindStringSubmatch(*ps); m != nil {
		*ps = (*ps)[len(m[0]):]
		*pm = m
		return true
	}
	return false
}

// Useful in combination with regex.Find*Index
func negToZero(i int) int {
	if i >= 0 {
		return i
	}
	return 0
}

func toInt(s string) int {
	n, _ := strconv.Atoi(s)
	return n
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

func argsStr(args ...interface{}) string {
	argsStr := ""
	for i, arg := range args {
		if i != 0 {
			argsStr += ", "
		}
		argsStr += sprintf("%#v", arg)
	}
	return argsStr
}

func trace(action, funcname string, args ...interface{}) {
	if G.opts.DebugTrace {
		io.WriteString(G.traceOut, sprintf("TRACE: %s%s%s(%s)\n", strings.Repeat("| ", G.traceDepth), action, funcname, argsStr(args...)))
	}
}

func tracecall(funcname string, args ...interface{}) func() {
	if G.opts.DebugTrace {
		trace("+ ", funcname, args...)
		G.traceDepth++
		return func() {
			G.traceDepth--
			trace("- ", funcname, args...)
		}
	} else {
		return func() {}
	}
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
	trace("", "relpath", from, to, "=>", result)
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
		fatalf(fname, NO_LINES, "Cannot determine absolute path.")
	}
	return filepath.ToSlash(abs)
}

// Differs from path.Clean in that only "../../" is replaced, not "../".
// Also, the initial directory is always kept.
// This is to provide the package path as context in recursive invocations of pkglint.
func cleanpath(fname string) string {
	defer tracecall("cleanpath", fname)()

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

func (h *Histogram) add(s string) {
	if G.opts.Profiling {
		h.histo[s]++
	}
}

func (h *Histogram) printStats(caption string, out io.Writer) {
	entries := make([]HistogramEntry, len(h.histo))

	i := 0
	for s, count := range h.histo {
		entries[i] = HistogramEntry{s, count}
		i++
	}

	sort.Sort(ByCountDesc(entries))

	for i, entry := range entries {
		fmt.Fprintf(out, "%s %6d %s\n", caption, entry.count, entry.s)
		if i >= 10 {
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
