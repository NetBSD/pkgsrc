package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) Test_Parser_PkgbasePattern(c *check.C) {

	checkRest := func(pattern, expected, rest string) {
		parser := NewParser(dummyLine, pattern, false)
		actual := parser.PkgbasePattern()
		c.Check(actual, equals, expected)
		c.Check(parser.Rest(), equals, rest)
	}

	checkRest("fltk", "fltk", "")
	checkRest("fltk|", "fltk", "|")
	checkRest("boost-build-1.59.*", "boost-build", "-1.59.*")
	checkRest("${PHP_PKG_PREFIX}-pdo-5.*", "${PHP_PKG_PREFIX}-pdo", "-5.*")
	checkRest("${PYPKGPREFIX}-metakit-[0-9]*", "${PYPKGPREFIX}-metakit", "-[0-9]*")
}

func (s *Suite) Test_Parser_Dependency(c *check.C) {

	checkRest := func(pattern string, expected DependencyPattern, rest string) {
		parser := NewParser(dummyLine, pattern, false)
		dp := parser.Dependency()
		if c.Check(dp, check.NotNil) {
			c.Check(*dp, equals, expected)
			c.Check(parser.Rest(), equals, rest)
		}
	}

	checkNil := func(pattern string) {
		parser := NewParser(dummyLine, pattern, false)
		dp := parser.Dependency()
		if c.Check(dp, check.IsNil) {
			c.Check(parser.Rest(), equals, pattern)
		}
	}

	check := func(pattern string, expected DependencyPattern) {
		checkRest(pattern, expected, "")
	}

	check("fltk>=1.1.5rc1<1.3", DependencyPattern{"fltk", ">=", "1.1.5rc1", "<", "1.3", ""})
	check("libwcalc-1.0*", DependencyPattern{"libwcalc", "", "", "", "", "1.0*"})
	check("${PHP_PKG_PREFIX}-pdo-5.*", DependencyPattern{"${PHP_PKG_PREFIX}-pdo", "", "", "", "", "5.*"})
	check("${PYPKGPREFIX}-metakit-[0-9]*", DependencyPattern{"${PYPKGPREFIX}-metakit", "", "", "", "", "[0-9]*"})
	check("boost-build-1.59.*", DependencyPattern{"boost-build", "", "", "", "", "1.59.*"})
	check("${_EMACS_REQD}", DependencyPattern{"${_EMACS_REQD}", "", "", "", "", ""})
	check("{gcc46,gcc46-libs}>=4.6.0", DependencyPattern{"{gcc46,gcc46-libs}", ">=", "4.6.0", "", "", ""})
	check("perl5-*", DependencyPattern{"perl5", "", "", "", "", "*"})
	check("verilog{,-current}-[0-9]*", DependencyPattern{"verilog{,-current}", "", "", "", "", "[0-9]*"})
	check("mpg123{,-esound,-nas}>=0.59.18", DependencyPattern{"mpg123{,-esound,-nas}", ">=", "0.59.18", "", "", ""})
	check("mysql*-{client,server}-[0-9]*", DependencyPattern{"mysql*-{client,server}", "", "", "", "", "[0-9]*"})
	check("postgresql8[0-35-9]-${module}-[0-9]*", DependencyPattern{"postgresql8[0-35-9]-${module}", "", "", "", "", "[0-9]*"})
	check("ncurses-${NC_VERS}{,nb*}", DependencyPattern{"ncurses", "", "", "", "", "${NC_VERS}{,nb*}"})
	check("xulrunner10>=${MOZ_BRANCH}${MOZ_BRANCH_MINOR}", DependencyPattern{"xulrunner10", ">=", "${MOZ_BRANCH}${MOZ_BRANCH_MINOR}", "", "", ""})
	checkRest("gnome-control-center>=2.20.1{,nb*}", DependencyPattern{"gnome-control-center", ">=", "2.20.1", "", "", ""}, "{,nb*}")
	checkNil(">=2.20.1{,nb*}")
	checkNil("pkgbase<=")
	// "{ssh{,6}-[0-9]*,openssh-[0-9]*}" is not representable using the current data structure
}
