package textproc

import (
	"fmt"
	"netbsd.org/pkglint/regex"
	"strings"
)

var Testing bool

type PrefixReplacerMark string

// PrefixReplacer parses an arbitrary string into its components by repeatedly
// stripping off a prefix matched by a literal string or a regular expression.
type PrefixReplacer struct {
	rest string
	s    string
	m    []string
	res  *regex.Registry
}

func NewPrefixReplacer(s string, res *regex.Registry) *PrefixReplacer {
	return &PrefixReplacer{s, "", nil, res}
}

func (pr *PrefixReplacer) Rest() string {
	return pr.rest
}

// Group returns a matching group from the last matched AdvanceRegexp.
func (pr *PrefixReplacer) Group(index int) string {
	return pr.m[index]
}

// Str returns the last match from AdvanceStr, AdvanceBytesFunc or AdvanceHspace.
func (pr *PrefixReplacer) Str() string {
	return pr.s
}

func (pr *PrefixReplacer) AdvanceStr(prefix string) bool {
	pr.m = nil
	pr.s = ""
	if strings.HasPrefix(pr.rest, prefix) {
		pr.s = prefix
		pr.rest = pr.rest[len(prefix):]
		return true
	}
	return false
}

// AdvanceHspace advances over as many spaces and tabs as possible.
func (pr *PrefixReplacer) AdvanceHspace() bool {
	i := initialHspace(pr.rest)
	if i != 0 {
		pr.s = pr.rest[:i]
		pr.rest = pr.rest[i:]
		return true
	}
	return false
}

func (pr *PrefixReplacer) AdvanceRegexp(re regex.Pattern) bool {
	pr.m = nil
	pr.s = ""
	if !strings.HasPrefix(string(re), "^") {
		panic(fmt.Sprintf("PrefixReplacer.AdvanceRegexp: regular expression %q must have prefix %q.", re, "^"))
	}
	if Testing && pr.res.Matches("", re) {
		panic(fmt.Sprintf("PrefixReplacer.AdvanceRegexp: the empty string must not match the regular expression %q.", re))
	}
	if m := pr.res.Match(pr.rest, re); m != nil {
		pr.rest = pr.rest[len(m[0]):]
		pr.m = m
		pr.s = m[0]
		return true
	}
	return false
}

// NextBytesFunc chops off the longest prefix (possibly empty) consisting
// solely of bytes for which fn returns true.
func (pr *PrefixReplacer) NextBytesFunc(fn func(b byte) bool) string {
	i := 0
	rest := pr.rest
	for i < len(rest) && fn(rest[i]) {
		i++
	}
	if i != 0 {
		pr.rest = rest[i:]
	}
	return rest[:i]
}

func (pr *PrefixReplacer) PeekByte() int {
	rest := pr.rest
	if rest == "" {
		return -1
	}
	return int(rest[0])
}

func (pr *PrefixReplacer) Mark() PrefixReplacerMark {
	return PrefixReplacerMark(pr.rest)
}

func (pr *PrefixReplacer) Reset(mark PrefixReplacerMark) {
	pr.rest = string(mark)
}

func (pr *PrefixReplacer) Skip(n int) {
	pr.rest = pr.rest[n:]
}

func (pr *PrefixReplacer) SkipHspace() {
	pr.rest = pr.rest[initialHspace(pr.rest):]
}

// Since returns the substring between the mark and the current position.
func (pr *PrefixReplacer) Since(mark PrefixReplacerMark) string {
	return string(mark[:len(mark)-len(pr.rest)])
}

func (pr *PrefixReplacer) AdvanceRest() string {
	rest := pr.rest
	pr.rest = ""
	return rest
}

func (pr *PrefixReplacer) HasPrefix(str string) bool {
	return strings.HasPrefix(pr.rest, str)
}

func (pr *PrefixReplacer) HasPrefixRegexp(re regex.Pattern) bool {
	return pr.res.Matches(pr.rest, re)
}

func initialHspace(s string) int {
	i := 0
	for i < len(s) && (s[i] == ' ' || s[i] == '\t') {
		i++
	}
	return i
}
