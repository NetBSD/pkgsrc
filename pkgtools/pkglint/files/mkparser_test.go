package pkglint

import (
	"encoding/json"
	"gopkg.in/check.v1"
	"strings"
)

func (s *Suite) Test_MkParser_MkCond(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	cmp := func(left MkCondTerm, op string, right MkCondTerm) *MkCond {
		return &MkCond{Compare: &MkCondCompare{left, op, right}}
	}
	cvar := func(name string, modifiers ...MkVarUseModifier) MkCondTerm {
		return MkCondTerm{Var: b.VarUse(name, modifiers...)}
	}
	cstr := func(s string) MkCondTerm { return MkCondTerm{Str: s} }
	cnum := func(s string) MkCondTerm { return MkCondTerm{Num: s} }

	termVar := func(varname string, mods ...MkVarUseModifier) *MkCond {
		return &MkCond{Term: &MkCondTerm{Var: b.VarUse(varname, mods...)}}
	}
	termNum := func(num string) *MkCond {
		return &MkCond{Term: &MkCondTerm{Num: num}}
	}
	termStr := func(str string) *MkCond {
		return &MkCond{Term: &MkCondTerm{Str: str}}
	}

	or := func(args ...*MkCond) *MkCond { return &MkCond{Or: args} }
	and := func(args ...*MkCond) *MkCond { return &MkCond{And: args} }
	not := func(cond *MkCond) *MkCond { return &MkCond{Not: cond} }
	call := func(name string, arg string) *MkCond {
		return &MkCond{Call: &MkCondCall{name, arg}}
	}
	empty := func(varname string, mods ...MkVarUseModifier) *MkCond {
		return &MkCond{Empty: b.VarUse(varname, mods...)}
	}
	defined := func(varname string) *MkCond { return &MkCond{Defined: varname} }
	paren := func(cond *MkCond) *MkCond { return &MkCond{Paren: cond} }

	toJSON := func(obj interface{}) string {
		var sb strings.Builder
		encoder := json.NewEncoder(&sb)
		encoder.SetIndent("", "  ")
		err := encoder.Encode(obj)
		t.AssertNil(err)
		return sb.String()
	}

	testRest := func(input string, expectedTree *MkCond, expectedRest string) {
		// As of July 2019 p.MkCond does not emit warnings;
		// this is left to MkCondChecker.Check.
		line := t.NewLine("filename.mk", 1, ".if "+input)
		p := NewMkParser(line, input)
		actualTree := p.MkCond()
		t.CheckDeepEquals(toJSON(actualTree), toJSON(expectedTree))
		t.CheckEquals(p.Rest(), expectedRest)
	}
	test := func(input string, expectedTree *MkCond) {
		testRest(input, expectedTree, "")
	}

	test("${OPSYS:MNetBSD}",
		termVar("OPSYS", "MNetBSD"))

	test("defined(VARNAME)",
		defined("VARNAME"))

	test("empty(VARNAME)",
		empty("VARNAME"))

	test("!empty(VARNAME)",
		not(empty("VARNAME")))

	test("!empty(VARNAME:M[yY][eE][sS])",
		not(empty("VARNAME", "M[yY][eE][sS]")))

	// Colons are unescaped at this point because they cannot be mistaken for separators anymore.
	test("!empty(USE_TOOLS:Mautoconf\\:run)",
		not(empty("USE_TOOLS", "Mautoconf:run")))

	test("${VARNAME} != \"Value\"",
		cmp(cvar("VARNAME"), "!=", cstr("Value")))

	test("${VARNAME:Mi386} != \"Value\"",
		cmp(cvar("VARNAME", "Mi386"), "!=", cstr("Value")))

	test("${VARNAME} != Value",
		cmp(cvar("VARNAME"), "!=", cstr("Value")))

	test("\"${VARNAME}\" != Value",
		cmp(cvar("VARNAME"), "!=", cstr("Value")))

	test("${pkg} == \"${name}\"",
		cmp(cvar("pkg"), "==", cvar("name")))

	test("\"${pkg}\" == \"${name}\"",
		cmp(cvar("pkg"), "==", cvar("name")))

	// The right-hand side is not analyzed further to keep the data types simple.
	test("${ABC} == \"${A}B${C}\"",
		cmp(cvar("ABC"), "==", cstr("${A}B${C}")))

	test("${ABC} == \"${A}\\\"${B}\\\\${C}$${shellvar}${D}\"",
		cmp(cvar("ABC"), "==", cstr("${A}\"${B}\\${C}$${shellvar}${D}")))

	test("exists(/etc/hosts)",
		call("exists", "/etc/hosts"))

	test("exists(${PREFIX}/var)",
		call("exists", "${PREFIX}/var"))

	test("${OPSYS} == \"NetBSD\" || ${OPSYS} == \"OpenBSD\"",
		or(
			cmp(cvar("OPSYS"), "==", cstr("NetBSD")),
			cmp(cvar("OPSYS"), "==", cstr("OpenBSD"))))

	test("${OPSYS} == \"NetBSD\" && ${MACHINE_ARCH} == \"i386\"",
		and(
			cmp(cvar("OPSYS"), "==", cstr("NetBSD")),
			cmp(cvar("MACHINE_ARCH"), "==", cstr("i386"))))

	test("defined(A) && defined(B) || defined(C) && defined(D)",
		or(
			and(defined("A"), defined("B")),
			and(defined("C"), defined("D"))))

	test("${MACHINE_ARCH:Mi386} || ${MACHINE_OPSYS:MNetBSD}",
		or(
			termVar("MACHINE_ARCH", "Mi386"),
			termVar("MACHINE_OPSYS", "MNetBSD")))

	test("${VAR} == \"${VAR}suffix\"",
		cmp(cvar("VAR"), "==", cstr("${VAR}suffix")))

	// Exotic cases

	// ".if 0" can be used to skip over a block of code.
	test("0",
		termNum("0"))

	test("0xCAFEBABE",
		termNum("0xCAFEBABE"))

	test("${VAR} == 0xCAFEBABE",
		cmp(cvar("VAR"), "==", cnum("0xCAFEBABE")))

	test("! ( defined(A)  && empty(VARNAME) )",
		not(paren(and(defined("A"), empty("VARNAME")))))

	test("${REQD_MAJOR} > ${MAJOR}",
		cmp(cvar("REQD_MAJOR"), ">", cvar("MAJOR")))

	test("${OS_VERSION} >= 6.5",
		cmp(cvar("OS_VERSION"), ">=", cnum("6.5")))

	test("${OS_VERSION} == 5.3",
		cmp(cvar("OS_VERSION"), "==", cnum("5.3")))

	test("!empty(${OS_VARIANT:MIllumos})", // Probably not intended
		not(empty("${OS_VARIANT:MIllumos}")))

	// There may be whitespace before the parenthesis.
	// See devel/bmake/files/cond.c:/^compare_function/.
	test("defined (VARNAME)",
		defined("VARNAME"))

	test("${\"${PKG_OPTIONS:Moption}\":?--enable-option:--disable-option}",
		termVar("\"${PKG_OPTIONS:Moption}\"", "?--enable-option:--disable-option"))

	// Contrary to most other programming languages, the == operator binds
	// more tightly than the ! operator.
	//
	// See MkCondChecker.checkNotCompare.
	test("!${VAR} == value",
		not(cmp(cvar("VAR"), "==", cstr("value"))))

	// The left-hand side of the comparison can be a quoted string.
	test("\"${VAR}suffix\" == value",
		cmp(cstr("${VAR}suffix"), "==", cstr("value")))

	test("\"${VAR}str\"",
		termStr("${VAR}str"))

	test("commands(show-var)",
		call("commands", "show-var"))

	test("exists(/usr/bin)",
		call("exists", "/usr/bin"))

	test("make(show-var)",
		call("make", "show-var"))

	test("target(do-build)",
		call("target", "do-build"))

	test("(!defined(VAR))",
		paren(not(defined("VAR"))))

	test("(((((!defined(VAR))))))",
		paren(paren(paren(paren(paren(not(defined("VAR"))))))))

	test("(${VAR} == \"value\")",
		paren(cmp(cvar("VAR"), "==", cstr("value"))))

	test("(((((${VAR} == \"value\")))))",
		paren(paren(paren(paren(paren(cmp(cvar("VAR"), "==", cstr("value"))))))))

	// TODO: ok "${q}text${q} == ${VAR}"
	// TODO: fail "text${q} == ${VAR}"
	// TODO: ok "${VAR} == ${q}text${q}"

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
		not(empty("PKG_OPTIONS", "Msndfile")),
		"|| defined(PKG_OPTIONS:Msamplerate)")

	testRest("${LEFT} &&",
		termVar("LEFT"),
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
		paren(termVar("VAR")),
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

func (s *Suite) Test_MkParser_DependencyPattern(c *check.C) {
	t := s.Init(c)

	testRest := func(pattern string, expected DependencyPattern, rest string) {
		parser := NewMkParser(nil, pattern)
		dp := parser.DependencyPattern()
		if t.CheckNotNil(dp) {
			t.CheckEquals(*dp, expected)
			t.CheckEquals(parser.Rest(), rest)
		}
	}

	testNil := func(pattern string) {
		parser := NewMkParser(nil, pattern)
		dp := parser.DependencyPattern()
		if t.CheckNil(dp) {
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
			strs[1+i] = mod.String()
		}
		return strings.Join(strs, ":")
	}

	addEvent := func(name string, args ...string) {
		events = append(events, sprintf("%14s  %s", name, strings.Join(args, ", ")))
	}

	// XXX: Add callbacks for Or if needed.
	//  A good use case would be to check for unsatisfiable .elif conditions.

	mkline.Cond().Walk(&MkCondCallback{
		func(conds []*MkCond) {
			addEvent("and")
		},
		func(cond *MkCond) {
			addEvent("not")
		},
		func(varname string) {
			addEvent("defined", varname)
		},
		func(varuse *MkVarUse) {
			addEvent("empty", varuseStr(varuse))
		},
		func(left *MkCondTerm, op string, right *MkCondTerm) {
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
		func(name string, arg string) {
			addEvent("call", name, arg)
		},
		func(cond *MkCond) {
			addEvent("paren")
		},
		func(varuse *MkVarUse) {
			addEvent("var", varuseStr(varuse))
		},
		func(varuse *MkVarUse) {
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
		"           and  ",
		" compareVarNum  NUM, 3",
		"        varUse  NUM",
		"       defined  VAR",
		"        varUse  VAR",
		"           not  ",
		"          call  exists, file.mk",
		"          call  exists, ${FILE}",
		"        varUse  FILE",
		"         paren  ",
		"         paren  ",
		"         paren  ",
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
