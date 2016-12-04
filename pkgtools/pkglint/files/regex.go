package main

import (
	"fmt"
	"regexp"
	"time"
)

type RegexPattern string

func regcomp(re RegexPattern) *regexp.Regexp {
	if G.res == nil {
		G.res = make(map[RegexPattern]*regexp.Regexp)
	}
	cre := G.res[re]
	if cre == nil {
		cre = regexp.MustCompile(string(re))
		G.res[re] = cre
	}
	return cre
}

func match(s string, re RegexPattern) []string {
	if !G.opts.Profiling {
		return regcomp(re).FindStringSubmatch(s)
	}

	before := time.Now()
	immediatelyBefore := time.Now()
	m := regcomp(re).FindStringSubmatch(s)
	after := time.Now()

	delay := immediatelyBefore.UnixNano() - before.UnixNano()
	timeTaken := after.UnixNano() - immediatelyBefore.UnixNano() - delay

	G.retime.Add(string(re), int(timeTaken))
	if m != nil {
		G.rematch.Add(string(re), 1)
	} else {
		G.renomatch.Add(string(re), 1)
	}
	return m
}

func matches(s string, re RegexPattern) bool {
	matches := regcomp(re).MatchString(s)
	if G.opts.Profiling {
		if matches {
			G.rematch.Add(string(re), 1)
		} else {
			G.renomatch.Add(string(re), 1)
		}
	}
	return matches
}

func matchn(s string, re RegexPattern, n int) []string {
	if m := match(s, re); m != nil {
		if len(m) != 1+n {
			panic(fmt.Sprintf("expected match%d, got match%d for %q", len(m)-1, n, re))
		}
		return m
	}
	return nil
}

func match1(s string, re RegexPattern) (matched bool, m1 string) {
	if m := matchn(s, re, 1); m != nil {
		return true, m[1]
	}
	return
}
func match2(s string, re RegexPattern) (matched bool, m1, m2 string) {
	if m := matchn(s, re, 2); m != nil {
		return true, m[1], m[2]
	}
	return
}
func match3(s string, re RegexPattern) (matched bool, m1, m2, m3 string) {
	if m := matchn(s, re, 3); m != nil {
		return true, m[1], m[2], m[3]
	}
	return
}
func match4(s string, re RegexPattern) (matched bool, m1, m2, m3, m4 string) {
	if m := matchn(s, re, 4); m != nil {
		return true, m[1], m[2], m[3], m[4]
	}
	return
}
func match5(s string, re RegexPattern) (matched bool, m1, m2, m3, m4, m5 string) {
	if m := matchn(s, re, 5); m != nil {
		return true, m[1], m[2], m[3], m[4], m[5]
	}
	return
}

func replaceFirst(s string, re RegexPattern, replacement string) ([]string, string) {
	if G.opts.Debug {
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
