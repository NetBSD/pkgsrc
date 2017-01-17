package textproc

import (
	"fmt"
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/trace"
	"strings"
)

var Testing bool

type PrefixReplacerMark string

type PrefixReplacer struct {
	rest string
	s    string
	m    []string
}

func NewPrefixReplacer(s string) *PrefixReplacer {
	return &PrefixReplacer{s, "", nil}
}

func (pr *PrefixReplacer) EOF() bool {
	return pr.rest == ""
}

func (pr *PrefixReplacer) Rest() string {
	return pr.rest
}

// Match returns a matching group from the last matched AdvanceRegexp.
func (pr *PrefixReplacer) Group(index int) string {
	return pr.m[index]
}

// Rest returns the last match from AdvanceStr, AdvanceBytesFunc or AdvanceHspace.
func (pr *PrefixReplacer) Str() string {
	return pr.s
}

func (pr *PrefixReplacer) AdvanceStr(prefix string) bool {
	pr.m = nil
	pr.s = ""
	if strings.HasPrefix(pr.rest, prefix) {
		if trace.Tracing {
			trace.Stepf("PrefixReplacer.AdvanceStr(%q, %q)", pr.rest, prefix)
		}
		pr.s = prefix
		pr.rest = pr.rest[len(prefix):]
		return true
	}
	return false
}

func (pr *PrefixReplacer) AdvanceBytesFunc(fn func(c byte) bool) bool {
	i := 0
	for i < len(pr.rest) && fn(pr.rest[i]) {
		i++
	}
	if i != 0 {
		pr.s = pr.rest[:i]
		pr.rest = pr.rest[i:]
		return true
	}
	return false
}

func (pr *PrefixReplacer) AdvanceHspace() bool {
	i := 0
	rest := pr.rest
	for i < len(rest) && (rest[i] == ' ' || rest[i] == '\t') {
		i++
	}
	if i != 0 {
		pr.s = pr.rest[:i]
		pr.rest = pr.rest[i:]
		return true
	}
	return false
}

func (pr *PrefixReplacer) AdvanceRegexp(re regex.RegexPattern) bool {
	pr.m = nil
	pr.s = ""
	if !strings.HasPrefix(string(re), "^") {
		panic(fmt.Sprintf("PrefixReplacer.AdvanceRegexp: regular expression %q must have prefix %q.", re, "^"))
	}
	if Testing && regex.Matches("", re) {
		panic(fmt.Sprintf("PrefixReplacer.AdvanceRegexp: the empty string must not match the regular expression %q.", re))
	}
	if m := regex.Match(pr.rest, re); m != nil {
		if trace.Tracing {
			trace.Stepf("PrefixReplacer.AdvanceRegexp(%q, %q, %q)", pr.rest, re, m[0])
		}
		pr.rest = pr.rest[len(m[0]):]
		pr.m = m
		pr.s = m[0]
		return true
	}
	return false
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

func (pr *PrefixReplacer) SkipSpace() {
	pr.rest = strings.TrimLeft(pr.rest, " \t")
}

func (pr *PrefixReplacer) Since(mark PrefixReplacerMark) string {
	return string(mark[:len(mark)-len(pr.rest)])
}

func (pr *PrefixReplacer) AdvanceRest() string {
	rest := pr.rest
	pr.rest = ""
	return rest
}
