package pkglint

import (
	"gopkg.in/check.v1"
	"strings"
)

func (s *Suite) Test_MkParser_MkCond(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()
	varUse := b.VarUse

	testRest := func(input string, expectedTree *MkCond, expectedRest string) {
		// As of July 2019 p.MkCond does not emit warnings;
		// this is left to MkLineChecker.checkDirectiveCond.
		line := t.NewLine("filename.mk", 1, ".if "+input)
		p := NewMkParser(line, input)
		actualTree := p.MkCond()
		t.CheckDeepEquals(actualTree, expectedTree)
		t.CheckEquals(p.Rest(), expectedRest)
	}
	test := func(input string, expectedTree *MkCond) {
		testRest(input, expectedTree, "")
	}
	varTerm := func(name string, modifiers ...string) MkCondTerm {
		return MkCondTerm{Var: varUse(name, modifiers...)}
	}
	str := func(s string) MkCondTerm { return MkCondTerm{Str: s} }
	num := func(s string) MkCondTerm { return MkCondTerm{Num: s} }

	t.Use(testRest, test, varTerm)

	test("${OPSYS:MNetBSD}",
		&MkCond{Term: &MkCondTerm{Var: varUse("OPSYS", "MNetBSD")}})

	test("defined(VARNAME)",
		&MkCond{Defined: "VARNAME"})

	test("empty(VARNAME)",
		&MkCond{Empty: varUse("VARNAME")})

	test("!empty(VARNAME)",
		&MkCond{Not: &MkCond{Empty: varUse("VARNAME")}})

	test("!empty(VARNAME:M[yY][eE][sS])",
		&MkCond{Not: &MkCond{Empty: varUse("VARNAME", "M[yY][eE][sS]")}})

	// Colons are unescaped at this point because they cannot be mistaken for separators anymore.
	test("!empty(USE_TOOLS:Mautoconf\\:run)",
		&MkCond{Not: &MkCond{Empty: varUse("USE_TOOLS", "Mautoconf:run")}})

	test("${VARNAME} != \"Value\"",
		&MkCond{Compare: &MkCondCompare{varTerm("VARNAME"), "!=", str("Value")}})

	test("${VARNAME:Mi386} != \"Value\"",
		&MkCond{Compare: &MkCondCompare{varTerm("VARNAME", "Mi386"), "!=", str("Value")}})

	test("${VARNAME} != Value",
		&MkCond{Compare: &MkCondCompare{varTerm("VARNAME"), "!=", str("Value")}})

	test("\"${VARNAME}\" != Value",
		&MkCond{Compare: &MkCondCompare{varTerm("VARNAME"), "!=", str("Value")}})

	test("${pkg} == \"${name}\"",
		&MkCond{Compare: &MkCondCompare{varTerm("pkg"), "==", varTerm("name")}})

	test("\"${pkg}\" == \"${name}\"",
		&MkCond{Compare: &MkCondCompare{varTerm("pkg"), "==", varTerm("name")}})

	// The right-hand side is not analyzed further to keep the data types simple.
	test("${ABC} == \"${A}B${C}\"",
		&MkCond{Compare: &MkCondCompare{varTerm("ABC"), "==", str("${A}B${C}")}})

	test("${ABC} == \"${A}\\\"${B}\\\\${C}$${shellvar}${D}\"",
		&MkCond{Compare: &MkCondCompare{varTerm("ABC"), "==", str("${A}\"${B}\\${C}$${shellvar}${D}")}})

	test("exists(/etc/hosts)",
		&MkCond{Call: &MkCondCall{"exists", "/etc/hosts"}})

	test("exists(${PREFIX}/var)",
		&MkCond{Call: &MkCondCall{"exists", "${PREFIX}/var"}})

	test("${OPSYS} == \"NetBSD\" || ${OPSYS} == \"OpenBSD\"",
		&MkCond{Or: []*MkCond{
			{Compare: &MkCondCompare{varTerm("OPSYS"), "==", str("NetBSD")}},
			{Compare: &MkCondCompare{varTerm("OPSYS"), "==", str("OpenBSD")}}}})

	test("${OPSYS} == \"NetBSD\" && ${MACHINE_ARCH} == \"i386\"",
		&MkCond{And: []*MkCond{
			{Compare: &MkCondCompare{varTerm("OPSYS"), "==", str("NetBSD")}},
			{Compare: &MkCondCompare{varTerm("MACHINE_ARCH"), "==", str("i386")}}}})

	test("defined(A) && defined(B) || defined(C) && defined(D)",
		&MkCond{Or: []*MkCond{
			{And: []*MkCond{
				{Defined: "A"},
				{Defined: "B"}}},
			{And: []*MkCond{
				{Defined: "C"},
				{Defined: "D"}}}}})

	test("${MACHINE_ARCH:Mi386} || ${MACHINE_OPSYS:MNetBSD}",
		&MkCond{Or: []*MkCond{
			{Term: &MkCondTerm{Var: varUse("MACHINE_ARCH", "Mi386")}},
			{Term: &MkCondTerm{Var: varUse("MACHINE_OPSYS", "MNetBSD")}}}})

	test("${VAR} == \"${VAR}suffix\"",
		&MkCond{Compare: &MkCondCompare{varTerm("VAR"), "==", str("${VAR}suffix")}})

	// Exotic cases

	// ".if 0" can be used to skip over a block of code.
	test("0",
		&MkCond{Term: &MkCondTerm{Num: "0"}})

	test("0xCAFEBABE",
		&MkCond{Term: &MkCondTerm{Num: "0xCAFEBABE"}})

	test("${VAR} == 0xCAFEBABE",
		&MkCond{
			Compare: &MkCondCompare{
				varTerm("VAR"),
				"==",
				num("0xCAFEBABE")}})

	test("! ( defined(A)  && empty(VARNAME) )",
		&MkCond{Not: &MkCond{
			And: []*MkCond{
				{Defined: "A"},
				{Empty: varUse("VARNAME")}}}})

	test("${REQD_MAJOR} > ${MAJOR}",
		&MkCond{Compare: &MkCondCompare{varTerm("REQD_MAJOR"), ">", varTerm("MAJOR")}})

	test("${OS_VERSION} >= 6.5",
		&MkCond{Compare: &MkCondCompare{varTerm("OS_VERSION"), ">=", num("6.5")}})

	test("${OS_VERSION} == 5.3",
		&MkCond{Compare: &MkCondCompare{varTerm("OS_VERSION"), "==", num("5.3")}})

	test("!empty(${OS_VARIANT:MIllumos})", // Probably not intended
		&MkCond{Not: &MkCond{Empty: varUse("${OS_VARIANT:MIllumos}")}})

	// There may be whitespace before the parenthesis; see devel/bmake/files/cond.c:^compare_function.
	test("defined (VARNAME)",
		&MkCond{Defined: "VARNAME"})

	test("${\"${PKG_OPTIONS:Moption}\":?--enable-option:--disable-option}",
		&MkCond{Term: &MkCondTerm{Var: varUse("\"${PKG_OPTIONS:Moption}\"", "?--enable-option:--disable-option")}})

	// Contrary to most other programming languages, the == operator binds
	// more tightly that the ! operator.
	//
	// TODO: Since this operator precedence is surprising there should be a warning,
	//  suggesting to replace "!${VAR} == value" with "${VAR} != value".
	test("!${VAR} == value",
		&MkCond{Not: &MkCond{Compare: &MkCondCompare{varTerm("VAR"), "==", str("value")}}})

	// The left-hand side of the comparison can be a quoted string.
	test("\"${VAR}suffix\" == value",
		&MkCond{Compare: &MkCondCompare{MkCondTerm{Str: "${VAR}suffix"}, "==", MkCondTerm{Str: "value"}}})

	test("\"${VAR}str\"",
		&MkCond{Term: &MkCondTerm{Str: "${VAR}str"}})

	test("commands(show-var)",
		&MkCond{Call: &MkCondCall{"commands", "show-var"}})

	test("exists(/usr/bin)",
		&MkCond{Call: &MkCondCall{"exists", "/usr/bin"}})

	test("make(show-var)",
		&MkCond{Call: &MkCondCall{"make", "show-var"}})

	test("target(do-build)",
		&MkCond{Call: &MkCondCall{"target", "do-build"}})

	// Errors

	testRest("defined()",
		nil,
		"defined()")

	testRest("empty()",
		nil,
		"empty()")

	testRest("empty(UNFINISHED",
		nil,
		"empty(UNFINISHED")

	testRest("empty(UNFINISHED:Mpattern",
		nil,
		"empty(UNFINISHED:Mpattern")

	testRest("exists(/$$sys)",
		nil,
		"exists(/$$sys)")

	testRest("exists(/unfinished",
		nil,
		"exists(/unfinished")

	testRest("!empty(PKG_OPTIONS:Msndfile) || defined(PKG_OPTIONS:Msamplerate)",
		&MkCond{Not: &MkCond{Empty: varUse("PKG_OPTIONS", "Msndfile")}},
		"|| defined(PKG_OPTIONS:Msamplerate)")

	testRest("${LEFT} &&",
		&MkCond{Term: &MkCondTerm{Var: varUse("LEFT")}},
		"&&")

	testRest("\"unfinished string literal",
		nil,
		"\"unfinished string literal")

	// Parsing stops before the variable since the comparison between
	// a variable and a string is one of the smallest building blocks.
	// Letting the ${VAR} through and stopping at the == operator would
	// be misleading.
	//
	// Another possibility would be to fix the unfinished string literal
	// and continue parsing. As of April 2019, the error handling is not
	// robust enough to support this approach; magically fixing parse
	// errors might lead to wrong conclusions and warnings.
	testRest("${VAR} == \"unfinished string literal",
		nil,
		"${VAR} == \"unfinished string literal")

	// A logical not must always be followed by an expression.
	testRest("!<",
		nil,
		"<")

	// Empty parentheses are a syntax error.
	testRest("()",
		nil,
		"()")

	// Unfinished conditions are a syntax error.
	testRest("(${VAR}",
		nil,
		"(${VAR}")

	// Too many closing parentheses are a syntax error.
	testRest("(${VAR}))",
		&MkCond{Term: &MkCondTerm{Var: varUse("VAR")}},
		")")

	// The left-hand side of the comparison cannot be an unquoted string literal.
	// These would be rejected by bmake as well.
	testRest("value == \"${VAR}suffix\"",
		nil,
		"value == \"${VAR}suffix\"")

	// Function calls need round parentheses instead of curly braces.
	// As of July 2019, bmake silently accepts this wrong expression
	// and interprets it as !defined(empty{USE_CROSS_COMPILE:M[yY][eE][sS]}),
	// which is always true, except if a variable of this strange name
	// were actually defined.
	testRest("!empty{USE_CROSS_COMPILE:M[yY][eE][sS]}",
		nil,
		"empty{USE_CROSS_COMPILE:M[yY][eE][sS]}")

	testRest("unknown(arg)",
		nil,
		"unknown(arg)")
}

func (s *Suite) Test_MkParser_mkCondCompare(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	mkline := t.NewMkLine("Makefile", 123, ".if ${PKGPATH} == category/pack.age-3+")
	p := NewMkParser(mkline.Line, mkline.Args())
	cond := p.MkCond()

	t.CheckEquals(p.Rest(), "")
	t.CheckDeepEquals(
		cond,
		&MkCond{
			Compare: &MkCondCompare{
				Left:  MkCondTerm{Var: b.VarUse("PKGPATH")},
				Op:    "==",
				Right: MkCondTerm{Str: "category/pack.age-3+"}}})

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkParser_PkgbasePattern(c *check.C) {
	t := s.Init(c)

	test := func(pattern, expected, rest string) {
		parser := NewMkParser(nil, pattern)

		actual := parser.PkgbasePattern()

		t.CheckEquals(actual, expected)
		t.CheckEquals(parser.Rest(), rest)
	}

	test("fltk", "fltk", "")
	test("fltk-", "fltk", "-")
	test("fltk|", "fltk", "|")
	test("boost-build-1.59.*", "boost-build", "-1.59.*")
	test("${PHP_PKG_PREFIX}-pdo-5.*", "${PHP_PKG_PREFIX}-pdo", "-5.*")
	test("${PYPKGPREFIX}-metakit-[0-9]*", "${PYPKGPREFIX}-metakit", "-[0-9]*")

	test("pkgbase-[0-9]*", "pkgbase", "-[0-9]*")

	test("pkgbase-client-[0-9]*", "pkgbase-client", "-[0-9]*")

	test("pkgbase-${VARIANT}-[0-9]*", "pkgbase-${VARIANT}", "-[0-9]*")

	test("pkgbase-${VERSION}-[0-9]*", "pkgbase", "-${VERSION}-[0-9]*")

	// This PKGNAME pattern is the one from bsd.pkg.mk.
	// The pattern assumes that the version number does not contain a hyphen,
	// which feels a bit too simple.
	//
	// Since variable substitutions are more common for version numbers
	// than for parts of the package name, pkglint treats the PKGNAME
	// as a version number.
	test("pkgbase-${PKGNAME:C/^.*-//}-[0-9]*", "pkgbase", "-${PKGNAME:C/^.*-//}-[0-9]*")

	// Using the [a-z] pattern in the package base is only rarely seen in the wild.
	test("pkgbase-[a-z]*-1.0", "pkgbase-[a-z]*", "-1.0")

	// This is a valid dependency pattern, but it's more complicated
	// than the patterns pkglint can handle as of January 2019.
	//
	// This pattern doesn't have a single package base, which means it cannot be parsed at all.
	test("{ssh{,6}-[0-9]*,openssh-[0-9]*}", "", "{ssh{,6}-[0-9]*,openssh-[0-9]*}")
}

func (s *Suite) Test_MkParser_isPkgbasePart(c *check.C) {
	t := s.Init(c)

	test := func(str string, expected bool) {
		actual := (*MkParser)(nil).isPkgbasePart(str)

		t.CheckEquals(actual, expected)
	}

	test("X11", true)
	test("client", true)
	test("${PKGNAME}", true)
	test("[a-z]", true)
	test("{client,server}", true)

	test("1.2", false)
	test("[0-9]*", false)
	test("{5.[1-7].*,6.[0-9]*}", false)
	test("${PKGVERSION}", false)
	test("${PKGNAME:C/^.*-//}", false)
	test(">=1.0", false)
	test("_client", false) // The combination foo-_client looks strange.
}

func (s *Suite) Test_MkParser_Dependency(c *check.C) {
	t := s.Init(c)

	testRest := func(pattern string, expected DependencyPattern, rest string) {
		parser := NewMkParser(nil, pattern)
		dp := parser.Dependency()
		if c.Check(dp, check.NotNil) {
			t.CheckEquals(*dp, expected)
			t.CheckEquals(parser.Rest(), rest)
		}
	}

	testNil := func(pattern string) {
		parser := NewMkParser(nil, pattern)
		dp := parser.Dependency()
		if c.Check(dp, check.IsNil) {
			t.CheckEquals(parser.Rest(), pattern)
		}
	}

	test := func(pattern string, expected DependencyPattern) {
		testRest(pattern, expected, "")
	}

	test("pkgbase>=1.0",
		DependencyPattern{"pkgbase", ">=", "1.0", "", "", ""})

	test("pkgbase>1.0",
		DependencyPattern{"pkgbase", ">", "1.0", "", "", ""})

	test("pkgbase<=1.0",
		DependencyPattern{"pkgbase", "", "", "<=", "1.0", ""})

	test("pkgbase<1.0",
		DependencyPattern{"pkgbase", "", "", "<", "1.0", ""})

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

	testNil("pkgbase")

	testNil("pkgbase-")

	testNil("pkgbase-client")

	testNil(">=2.20.1{,nb*}")

	testNil("pkgbase<=")

	// TODO: support this edge case someday.
	// "{ssh{,6}-[0-9]*,openssh-[0-9]*}" is not representable using the current data structure

	// TODO: More test cases from current pkgsrc:
	// R-jsonlite>=0.9.6*
	//
	// {ezmlm>=0.53,ezmlm-idx>=0.40}
	// {samba>=2.0,ja-samba>=2.0}
	// {mecab-ipadic>=2.7.0,mecab-jumandic>=5.1}
	//
	// ${_EMACS_CONFLICTS.${_EMACS_FLAVOR}}
	// ${DISTNAME:S/gnome-vfs/gnome-vfs2-${GNOME_VFS_NAME}/}
}

func (s *Suite) Test_MkCondWalker_Walk(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("Makefile", 4, ""+
		".if ${VAR:Mmatch} == ${OTHER} || "+
		"${STR} == Str || "+
		"${VAR} == \"${PRE}text${POST}\" || "+
		"${NUM} == 3 && "+
		"defined(VAR) && "+
		"!exists(file.mk) && "+
		"exists(${FILE}) && "+
		"(((${NONEMPTY})))")
	var events []string

	varuseStr := func(varuse *MkVarUse) string {
		strs := make([]string, 1+len(varuse.modifiers))
		strs[0] = varuse.varname
		for i, mod := range varuse.modifiers {
			strs[1+i] = mod.Text
		}
		return strings.Join(strs, ":")
	}

	addEvent := func(name string, args ...string) {
		events = append(events, sprintf("%14s  %s", name, strings.Join(args, ", ")))
	}

	// TODO: Add callbacks for And, Or, Not if needed.
	//  Especially Not(Empty(VARNAME)) should be an interesting case.

	mkline.Cond().Walk(&MkCondCallback{
		Defined: func(varname string) {
			addEvent("defined", varname)
		},
		Empty: func(varuse *MkVarUse) {
			addEvent("empty", varuseStr(varuse))
		},
		Compare: func(left *MkCondTerm, op string, right *MkCondTerm) {
			assert(left.Var != nil)
			switch {
			case right.Var != nil:
				addEvent("compareVarVar", varuseStr(left.Var), varuseStr(right.Var))
			case right.Num != "":
				addEvent("compareVarNum", varuseStr(left.Var), right.Num)
			default:
				addEvent("compareVarStr", varuseStr(left.Var), right.Str)
			}
		},
		Call: func(name string, arg string) {
			addEvent("call", name, arg)
		},
		Var: func(varuse *MkVarUse) {
			addEvent("var", varuseStr(varuse))
		},
		VarUse: func(varuse *MkVarUse) {
			addEvent("varUse", varuseStr(varuse))
		}})

	t.CheckDeepEquals(events, []string{
		" compareVarVar  VAR:Mmatch, OTHER",
		"        varUse  VAR:Mmatch",
		"        varUse  OTHER",
		" compareVarStr  STR, Str",
		"        varUse  STR",
		" compareVarStr  VAR, ${PRE}text${POST}",
		"        varUse  VAR",
		"        varUse  PRE",
		"        varUse  POST",
		" compareVarNum  NUM, 3",
		"        varUse  NUM",
		"       defined  VAR",
		"        varUse  VAR",
		"          call  exists, file.mk",
		"          call  exists, ${FILE}",
		"        varUse  FILE",
		"           var  NONEMPTY",
		"        varUse  NONEMPTY"})
}

// Ensure that the code works even if none of the callbacks are set.
// This is only for code coverage.
func (s *Suite) Test_MkCondWalker_Walk__empty_callbacks(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("Makefile", 4, ""+
		".if ${VAR:Mmatch} == ${OTHER} || "+
		"${STR} == Str || "+
		"${VAR} == \"${PRE}text${POST}\" || "+
		"${NUM} == 3 && "+
		"defined(VAR) && "+
		"!exists(file.mk) && "+
		"exists(${FILE}) && "+
		"(((${NONEMPTY})))")

	mkline.Cond().Walk(&MkCondCallback{})

	t.CheckOutputEmpty()
}
