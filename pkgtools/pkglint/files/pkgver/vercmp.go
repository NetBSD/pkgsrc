package pkgver

// See pkgtools/pkg_install/files/lib/dewey.c

import (
	"netbsd.org/pkglint/textproc"
	"strconv"
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

func Compare(left, right string) int {
	lv := newVersion(left)
	rv := newVersion(right)

	m := imax(len(lv.v), len(rv.v))
	for i := 0; i < m; i++ {
		if c := icmp(lv.field(i), rv.field(i)); c != 0 {
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
	lex := textproc.NewLexer(strings.ToLower(vstr))
	for !lex.EOF() {

		switch {
		case lex.TestByteSet(textproc.Digit):
			num := lex.NextBytesSet(textproc.Digit)
			n, _ := strconv.Atoi(num)
			v.add(n)
		case lex.SkipByte('_') || lex.SkipByte('.'):
			v.add(0)
		case lex.SkipString("alpha"):
			v.add(-3)
		case lex.SkipString("beta"):
			v.add(-2)
		case lex.SkipString("pre"):
			v.add(-1)
		case lex.SkipString("rc"):
			v.add(-1)
		case lex.SkipString("pl"):
			v.add(0)
		case lex.SkipString("nb"):
			num := lex.NextBytesSet(textproc.Digit)
			v.nb, _ = strconv.Atoi(num)
		case lex.TestByteSet(textproc.Lower):
			v.add(int(lex.Rest()[0] - 'a' + 1))
			lex.Skip(1)
		default:
			lex.Skip(1)
		}
	}
	return v
}

//go:noinline
func (v *version) add(i int) {
	v.v = append(v.v, i)
}

func (v *version) field(i int) int {
	if i < len(v.v) {
		return v.v[i]
	}
	return 0
}
