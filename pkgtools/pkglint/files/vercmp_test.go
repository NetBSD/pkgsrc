package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestMkversion(c *check.C) {
	c.Check(newVersion("5.0"), check.DeepEquals, &version{[]int{5, 0, 0}, 0})
	c.Check(newVersion("5.0nb5"), check.DeepEquals, &version{[]int{5, 0, 0}, 5})
	c.Check(newVersion("0.0.1-SNAPSHOT"), check.DeepEquals, &version{[]int{0, 0, 0, 0, 1, 19, 14, 1, 16, 19, 8, 15, 20}, 0})
	c.Check(newVersion("1.0alpha3"), check.DeepEquals, &version{[]int{1, 0, 0, -3, 3}, 0})
	c.Check(newVersion("2.5beta"), check.DeepEquals, &version{[]int{2, 0, 5, -2}, 0})
	c.Check(newVersion("20151110"), check.DeepEquals, &version{[]int{20151110}, 0})
	c.Check(newVersion("0"), check.DeepEquals, &version{[]int{0}, 0})
	c.Check(newVersion("nb1"), check.DeepEquals, &version{nil, 1})
	c.Check(newVersion("1.0.1a"), deepEquals, &version{[]int{1, 0, 0, 0, 1, 1}, 0})
	c.Check(newVersion("1.0.1z"), deepEquals, &version{[]int{1, 0, 0, 0, 1, 26}, 0})
}

func (s *Suite) TestPkgverCmp(c *check.C) {
	c.Check(pkgverCmp("1.0", "1.0alpha"), equals, 1)
	c.Check(pkgverCmp("1.0alpha", "1.0"), equals, -1)
	c.Check(pkgverCmp("1.0nb1", "1.0"), equals, 1)
	c.Check(pkgverCmp("1.0nb2", "1.0nb1"), equals, 1)
	c.Check(pkgverCmp("2.0.1nb17", "2.0.1nb4"), equals, 1)
	c.Check(pkgverCmp("2.0.1nb4", "2.0.1nb17"), equals, -1)
	c.Check(pkgverCmp("2.0pre", "2.0rc"), equals, 0)
	c.Check(pkgverCmp("2.0pre", "2.0pl"), equals, -1)
}
