// Package regex provides a registry of precompiled regular expressions
// to allow reusing them without the syntactic overhead of declaring
// pattern variables everywhere in the code.
// The registry is not thread-safe, but the precompiled patterns are.
package regex

import (
	"fmt"
	"io"
	"netbsd.org/pkglint/histogram"
	"regexp"
	"time"
)

type Pattern string

type Registry struct {
	res       map[Pattern]*regexp.Regexp
	rematch   *histogram.Histogram
	renomatch *histogram.Histogram
	retime    *histogram.Histogram
	profiling bool
}

func NewRegistry() Registry {
	return Registry{make(map[Pattern]*regexp.Regexp), nil, nil, nil, false}
}

func (r *Registry) Profiling() {
	if !r.profiling {
		r.rematch = histogram.New()
		r.renomatch = histogram.New()
		r.retime = histogram.New()
		r.profiling = true
	}
}

func (r *Registry) Compile(re Pattern) *regexp.Regexp {
	cre := r.res[re]
	if cre == nil {
		cre = regexp.MustCompile(string(re))
		r.res[re] = cre
	}
	return cre
}

// Consider defining an alternative CompileX method that implements the
// /x modifier to allow whitespace in the regular expression.
// This makes the regular expressions more readable.

func (r *Registry) Match(s string, re Pattern) []string {
	if !r.profiling {
		return r.Compile(re).FindStringSubmatch(s)
	}

	before := time.Now()
	immediatelyBefore := time.Now()
	m := r.Compile(re).FindStringSubmatch(s)
	after := time.Now()

	delay := immediatelyBefore.UnixNano() - before.UnixNano()
	timeTaken := after.UnixNano() - immediatelyBefore.UnixNano() - delay

	r.retime.Add(string(re), int(timeTaken))
	if m != nil {
		r.rematch.Add(string(re), 1)
	} else {
		r.renomatch.Add(string(re), 1)
	}
	return m
}

func (r *Registry) Matches(s string, re Pattern) bool {
	matches := r.Compile(re).MatchString(s)
	if r.profiling {
		if matches {
			r.rematch.Add(string(re), 1)
		} else {
			r.renomatch.Add(string(re), 1)
		}
	}
	return matches
}

func (r *Registry) Match1(s string, re Pattern) (matched bool, m1 string) {
	if m := r.matchn(s, re, 1); m != nil {
		return true, m[1]
	}
	return
}

func (r *Registry) Match2(s string, re Pattern) (matched bool, m1, m2 string) {
	if m := r.matchn(s, re, 2); m != nil {
		return true, m[1], m[2]
	}
	return
}

func (r *Registry) Match3(s string, re Pattern) (matched bool, m1, m2, m3 string) {
	if m := r.matchn(s, re, 3); m != nil {
		return true, m[1], m[2], m[3]
	}
	return
}

func (r *Registry) Match4(s string, re Pattern) (matched bool, m1, m2, m3, m4 string) {
	if m := r.matchn(s, re, 4); m != nil {
		return true, m[1], m[2], m[3], m[4]
	}
	return
}

func (r *Registry) Match5(s string, re Pattern) (matched bool, m1, m2, m3, m4, m5 string) {
	if m := r.matchn(s, re, 5); m != nil {
		return true, m[1], m[2], m[3], m[4], m[5]
	}
	return
}

func (r *Registry) ReplaceFirst(s string, re Pattern, replacement string) ([]string, string) {
	if m := r.Compile(re).FindStringSubmatchIndex(s); m != nil {
		replaced := s[:m[0]] + replacement + s[m[1]:]
		mm := make([]string, len(m)/2)
		for i := 0; i < len(m); i += 2 {
			mm[i/2] = s[max0(m[i]):max0(m[i+1])]
		}
		return mm, replaced
	}
	return nil, s
}

func (r *Registry) PrintStats(out io.Writer) {
	if r.profiling {
		r.rematch.PrintStats(out, "rematch", 10)
		r.renomatch.PrintStats(out, "renomatch", 10)
		r.retime.PrintStats(out, "retime", 10)
	}
}

func (r *Registry) matchn(s string, re Pattern, n int) []string {
	if m := r.Match(s, re); m != nil {
		if len(m) != 1+n {
			panic(fmt.Sprintf("expected match%d, got match%d for %q", len(m)-1, n, re))
		}
		return m
	}
	return nil
}

func max0(a int) int {
	if a >= 0 {
		return a
	}
	return 0
}
