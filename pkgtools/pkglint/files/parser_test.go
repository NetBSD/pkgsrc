package pkglint

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_Parser_PkgbasePattern(c *check.C) {

	testRest := func(pattern, expected, rest string) {
		parser := NewParser(dummyLine, pattern, false)
		actual := parser.PkgbasePattern()
		c.Check(actual, equals, expected)
		c.Check(parser.Rest(), equals, rest)
	}

	testRest("fltk", "fltk", "")
	testRest("fltk|", "fltk", "|")
	testRest("boost-build-1.59.*", "boost-build", "-1.59.*")
	testRest("${PHP_PKG_PREFIX}-pdo-5.*", "${PHP_PKG_PREFIX}-pdo", "-5.*")
	testRest("${PYPKGPREFIX}-metakit-[0-9]*", "${PYPKGPREFIX}-metakit", "-[0-9]*")
}

func (s *Suite) Test_Parser_Dependency(c *check.C) {

	testRest := func(pattern string, expected DependencyPattern, rest string) {
		parser := NewParser(dummyLine, pattern, false)
		dp := parser.Dependency()
		if c.Check(dp, check.NotNil) {
			c.Check(*dp, equals, expected)
			c.Check(parser.Rest(), equals, rest)
		}
	}

	testNil := func(pattern string) {
		parser := NewParser(dummyLine, pattern, false)
		dp := parser.Dependency()
		if c.Check(dp, check.IsNil) {
			c.Check(parser.Rest(), equals, pattern)
		}
	}

	test := func(pattern string, expected DependencyPattern) {
		testRest(pattern, expected, "")
	}

	test("fltk>=1.1.5rc1<1.3",
		DependencyPattern{"fltk", ">=", "1.1.5rc1", "<", "1.3", ""})

	test("libwcalc-1.0*",
		DependencyPattern{"libwcalc", "", "", "", "", "1.0*"})

	test("${PHP_PKG_PREFIX}-pdo-5.*",
		DependencyPattern{"${PHP_PKG_PREFIX}-pdo", "", "", "", "", "5.*"})

	test("${PYPKGPREFIX}-metakit-[0-9]*",
		DependencyPattern{"${PYPKGPREFIX}-metakit", "", "", "", "", "[0-9]*"})

	test("boost-build-1.59.*",
		DependencyPattern{"boost-build", "", "", "", "", "1.59.*"})

	test("${_EMACS_REQD}",
		DependencyPattern{"${_EMACS_REQD}", "", "", "", "", ""})

	test("{gcc46,gcc46-libs}>=4.6.0",
		DependencyPattern{"{gcc46,gcc46-libs}", ">=", "4.6.0", "", "", ""})

	test("perl5-*",
		DependencyPattern{"perl5", "", "", "", "", "*"})

	test("verilog{,-current}-[0-9]*",
		DependencyPattern{"verilog{,-current}", "", "", "", "", "[0-9]*"})

	test("mpg123{,-esound,-nas}>=0.59.18",
		DependencyPattern{"mpg123{,-esound,-nas}", ">=", "0.59.18", "", "", ""})

	test("mysql*-{client,server}-[0-9]*",
		DependencyPattern{"mysql*-{client,server}", "", "", "", "", "[0-9]*"})

	test("postgresql8[0-35-9]-${module}-[0-9]*",
		DependencyPattern{"postgresql8[0-35-9]-${module}", "", "", "", "", "[0-9]*"})

	test("ncurses-${NC_VERS}{,nb*}",
		DependencyPattern{"ncurses", "", "", "", "", "${NC_VERS}{,nb*}"})

	test("xulrunner10>=${MOZ_BRANCH}${MOZ_BRANCH_MINOR}",
		DependencyPattern{"xulrunner10", ">=", "${MOZ_BRANCH}${MOZ_BRANCH_MINOR}", "", "", ""})

	testRest("gnome-control-center>=2.20.1{,nb*}",
		DependencyPattern{"gnome-control-center", ">=", "2.20.1", "", "", ""}, "{,nb*}")

	testNil(">=2.20.1{,nb*}")

	testNil("pkgbase<=")

	// TODO: support this edge case someday.
	// "{ssh{,6}-[0-9]*,openssh-[0-9]*}" is not representable using the current data structure
}
