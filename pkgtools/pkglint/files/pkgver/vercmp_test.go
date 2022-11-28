package pkgver

import (
	"gopkg.in/check.v1"
	"netbsd.org/pkglint/intqa"
	"reflect"
	"testing"
)

type Suite struct{}

func Test(t *testing.T) {
	check.Suite(&Suite{})
	check.TestingT(t)
}

func (s *Suite) Test_Compare(c *check.C) {
	var versions = [][]string{
		{"0pre20160620"},
		{"0"},
		{"nb1"},
		{"0.0.1-SNAPSHOT"},
		{"1.0alpha"},
		{"1.0alpha3"},
		{"1", "1.0", "1.0.0"},
		{"1.0nb1"},
		{"1.0nb2", "1_0nb2"},
		{"1.0.aa"},
		{"1.0.a1"},
		{"1.0.k"},
		{"1.0.1a"},
		{"1.0.1z"},
		{"1.0.11", "1.0k"},
		{"2.0pre", "2.0rc"},
		{"2.0", "2.0pl"},
		{"2.0.1nb4"},
		{"2.0.1nb17"},
		{"2.5beta"},
		{"5.0"},
		{"5.0nb5"},
		{"5.5", "5.005"},
		{"2021.06.17", "2021.6.17"},
		{"2021.12.01", "2021.12.1"},
		{"20151110"},
	}

	op := func(cmp int) string {
		return [...]string{"<0", "==0", ">0"}[cmp+1]
	}

	test := func(i int, iVersion string, j int, jVersion string) {
		actual := icmp(Compare(iVersion, jVersion), 0)
		expected := icmp(i, j)
		if actual != expected {
			c.Check(
				[]interface{}{i, iVersion, j, jVersion, op(actual)},
				check.DeepEquals,
				[]interface{}{i, iVersion, j, jVersion, op(expected)})
		}
	}

	for i, iVersions := range versions {
		for j, jVersions := range versions {
			for _, iVersion := range iVersions {
				for _, jVersion := range jVersions {
					test(i, iVersion, j, jVersion)
				}
			}
		}
	}
}

func Test_newVersion(t *testing.T) {
	tests := []struct {
		name string
		v    version
	}{
		{"5.0", version{[]int{5, 0, 0}, 0}},
		{"5.0nb5", version{[]int{5, 0, 0}, 5}},
		{"0.0.1-SNAP", version{[]int{0, 0, 0, 0, 1, 0, 19, 0, 14, 0, 1, 0, 16}, 0}},
		{"1.0alpha3", version{[]int{1, 0, 0, -3, 3}, 0}},
		{"1_0alpha3", version{[]int{1, 0, 0, -3, 3}, 0}},
		{"2.5beta", version{[]int{2, 0, 5, -2}, 0}},
		{"20151110", version{[]int{20151110}, 0}},
		{"0", version{[]int{0}, 0}},
		{"nb1", version{nil, 1}},
		{"1.0.1a", version{[]int{1, 0, 0, 0, 1, 0, 1}, 0}},
		{"1.1.1dnb2", version{[]int{1, 0, 1, 0, 1, 0, 4}, 2}},
		{"1.0.1z", version{[]int{1, 0, 0, 0, 1, 0, 26}, 0}},
		{"0pre20160620", version{[]int{0, -1, 20160620}, 0}},
		{"3.5.DEV1710", version{[]int{3, 0, 5, 0, 0, 4, 0, 5, 0, 22, 1710}, 0}},

		// In the following edge case, the "nb" and "beta" overlap.
		// All the digits after the "nb" (which in this case are none at all)
		// end up in the nb version part, and parsing continues with the next
		// letter.
		//
		// Luckily this will not happen in practice since most version numbers
		// are completely numeric, and those that aren't might have suffixes
		// like "alpha", "beta", "public beta", "GA" (general availability),
		// "final", "snapshot". The word "nonbeta" is purely hypothetical, and
		// I didn't find any other word that would contain "nbeta". Commit
		// hashes are also safe since their hex encoding cannot contain "n".
		{"1.0nonbeta", version{[]int{1, 0, 0, 0, 14, 0, 15, 0, 5, 0, 20, 0, 1}, 0}},
	}
	for _, test := range tests {
		t.Run(test.name, func(t *testing.T) {
			actual := *newVersion(test.name)
			if !reflect.DeepEqual(actual, test.v) {
				t.Errorf("expected %#v for %q, got %#v", test.v, test.name, actual)
			}
		})
	}
}

func (s *Suite) Test_newVersion(c *check.C) {
	// See Test_newVersion.
	_ = c
}

func (s *Suite) Test__qa(c *check.C) {
	ck := intqa.NewQAChecker(c.Errorf)
	ck.Configure("*", "*", "*", -intqa.EMissingTest)
	ck.Check()
}
