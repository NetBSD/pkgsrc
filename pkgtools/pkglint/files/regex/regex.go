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

var (
	Profiling bool
)

var (
	res       = make(map[Pattern]*regexp.Regexp)
	rematch   = histogram.New()
	renomatch = histogram.New()
	retime    = histogram.New()
)

func Compile(re Pattern) *regexp.Regexp {
	cre := res[re]
	if cre == nil {
		cre = regexp.MustCompile(string(re))
		res[re] = cre
	}
	return cre
}

func Match(s string, re Pattern) []string {
	if !Profiling {
		return Compile(re).FindStringSubmatch(s)
	}

	before := time.Now()
	immediatelyBefore := time.Now()
	m := Compile(re).FindStringSubmatch(s)
	after := time.Now()

	delay := immediatelyBefore.UnixNano() - before.UnixNano()
	timeTaken := after.UnixNano() - immediatelyBefore.UnixNano() - delay

	retime.Add(string(re), int(timeTaken))
	if m != nil {
		rematch.Add(string(re), 1)
	} else {
		renomatch.Add(string(re), 1)
	}
	return m
}

func Matches(s string, re Pattern) bool {
	matches := Compile(re).MatchString(s)
	if Profiling {
		if matches {
			rematch.Add(string(re), 1)
		} else {
			renomatch.Add(string(re), 1)
		}
	}
	return matches
}

func Match1(s string, re Pattern) (matched bool, m1 string) {
	if m := matchn(s, re, 1); m != nil {
		return true, m[1]
	}
	return
}

func Match2(s string, re Pattern) (matched bool, m1, m2 string) {
	if m := matchn(s, re, 2); m != nil {
		return true, m[1], m[2]
	}
	return
}

func Match3(s string, re Pattern) (matched bool, m1, m2, m3 string) {
	if m := matchn(s, re, 3); m != nil {
		return true, m[1], m[2], m[3]
	}
	return
}

func Match4(s string, re Pattern) (matched bool, m1, m2, m3, m4 string) {
	if m := matchn(s, re, 4); m != nil {
		return true, m[1], m[2], m[3], m[4]
	}
	return
}

func Match5(s string, re Pattern) (matched bool, m1, m2, m3, m4, m5 string) {
	if m := matchn(s, re, 5); m != nil {
		return true, m[1], m[2], m[3], m[4], m[5]
	}
	return
}

func ReplaceFirst(s string, re Pattern, replacement string) ([]string, string) {
	if m := Compile(re).FindStringSubmatchIndex(s); m != nil {
		replaced := s[:m[0]] + replacement + s[m[1]:]
		mm := make([]string, len(m)/2)
		for i := 0; i < len(m); i += 2 {
			mm[i/2] = s[max0(m[i]):max0(m[i+1])]
		}
		return mm, replaced
	}
	return nil, s
}

func PrintStats(out io.Writer) {
	if Profiling {
		rematch.PrintStats("rematch", out, 10)
		renomatch.PrintStats("renomatch", out, 10)
		retime.PrintStats("retime", out, 10)
	}
}

func matchn(s string, re Pattern, n int) []string {
	if m := Match(s, re); m != nil {
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
