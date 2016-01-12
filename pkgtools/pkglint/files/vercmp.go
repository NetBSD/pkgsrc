package main

// See pkgtools/pkg_install/files/lib/dewey.c

import (
	"strings"
)

func imax(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func icmp(a, b int) int {
	if a < b {
		return -1
	}
	if a > b {
		return 1
	}
	return 0
}

func pkgverCmp(left, right string) int {
	lv := newVersion(left)
	rv := newVersion(right)

	m := imax(len(lv.v), len(rv.v))
	for i := 0; i < m; i++ {
		if c := icmp(lv.Place(i), rv.Place(i)); c != 0 {
			return c
		}
	}
	return icmp(lv.nb, rv.nb)
}

type version struct {
	v  []int
	nb int
}

func newVersion(vstr string) *version {
	v := new(version)
	rest := strings.ToLower(vstr)
	for rest != "" {
		switch {
		case isdigit(rest[0]):
			n := 0
			i := 0
			for i < len(rest) && isdigit(rest[i]) {
				n = 10*n + int(rest[i]-'0')
				i++
			}
			rest = rest[i:]
			v.Add(n)
		case rest[0] == '_' || rest[0] == '.':
			v.Add(0)
			rest = rest[1:]
		case hasPrefix(rest, "alpha"):
			v.Add(-3)
			rest = rest[5:]
		case hasPrefix(rest, "beta"):
			v.Add(-2)
			rest = rest[4:]
		case hasPrefix(rest, "pre"):
			v.Add(-1)
			rest = rest[3:]
		case hasPrefix(rest, "rc"):
			v.Add(-1)
			rest = rest[2:]
		case hasPrefix(rest, "pl"):
			v.Add(0)
			rest = rest[2:]
		case hasPrefix(rest, "nb"):
			i := 2
			n := 0
			for i < len(rest) && isdigit(rest[i]) {
				n = 10*n + int(rest[i]-'0')
				i++
			}
			v.nb = n
			rest = rest[i:]
		case rest[0]-'a' <= 'z'-'a':
			v.Add(int(rest[0] - 'a' + 1))
			rest = rest[1:]
		default:
			rest = rest[1:]
		}
	}
	return v
}

func (v *version) Add(i int) {
	v.v = append(v.v, i)
}
func isdigit(b byte) bool {
	return b-'0' <= 9
}
func (v *version) Place(i int) int {
	if i < len(v.v) {
		return v.v[i]
	}
	return 0
}
