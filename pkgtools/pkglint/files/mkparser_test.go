package pkglint

import (
	"gopkg.in/check.v1"
	"strings"
)

func (s *Suite) Test_MkParser_MkTokens(c *check.C) {
	t := s.Init(c)

	testRest := func(input string, expectedTokens []*MkToken, expectedRest string) {
		line := t.NewLines("Test_MkParser_MkTokens.mk", input).Lines[0]
		p := NewMkParser(line, input, true)
		actualTokens := p.MkTokens()
		c.Check(actualTokens, deepEquals, expectedTokens)
		for i, expectedToken := range expectedTokens {
			if i < len(actualTokens) {
				c.Check(*actualTokens[i], deepEquals, *expectedToken)
				c.Check(actualTokens[i].Varuse, deepEquals, expectedToken.Varuse)
			}
		}
		c.Check(p.Rest(), equals, expectedRest)
	}
	test := func(input string, expectedToken *MkToken) {
		testRest(input, []*MkToken{expectedToken}, "")
	}
	literal := func(text string) *MkToken {
		return &MkToken{Text: text}
	}
	varuse := func(varname string, modifiers ...string) *MkToken {
		text := "${" + varname
		for _, modifier := range modifiers {
			text += ":" + modifier
		}
		text += "}"
		return &MkToken{Text: text, Varuse: NewMkVarUse(varname, modifiers...)}
	}

	// Everything except VarUses is passed through unmodified.

	test("literal",
		literal("literal"))

	test("\\/share\\/ { print \"share directory\" }",
		literal("\\/share\\/ { print \"share directory\" }"))

	test("find . -name \\*.orig -o -name \\*.pre",
		literal("find . -name \\*.orig -o -name \\*.pre"))

	test("-e 's|\\$${EC2_HOME.*}|EC2_HOME}|g'",
		literal("-e 's|\\$${EC2_HOME.*}|EC2_HOME}|g'"))

	test("$$var1 $$var2 $$? $$",
		literal("$$var1 $$var2 $$? $$"))

	testRest("hello, ${W:L:tl}orld", []*MkToken{
		literal("hello, "),
		varuse("W", "L", "tl"),
		literal("orld")},
		"")

	testRest("ftp://${PKGNAME}/ ${MASTER_SITES:=subdir/}", []*MkToken{
		literal("ftp://"),
		varuse("PKGNAME"),
		literal("/ "),
		varuse("MASTER_SITES", "=subdir/")},
		"")

	// FIXME: Text must match modifiers.
	testRest("${VAR:S,a,b,c,d,e,f}",
		[]*MkToken{{
			Text:   "${VAR:S,a,b,c,d,e,f}",
			Varuse: NewMkVarUse("VAR", "S,a,b,")}},
		"")

	testRest("Text${VAR:Mmodifier}${VAR2}more text${VAR3}", []*MkToken{
		literal("Text"),
		varuse("VAR", "Mmodifier"),
		varuse("VAR2"),
		literal("more text"),
		varuse("VAR3")},
		"")
}

func (s *Suite) Test_MkParser_VarUse(c *check.C) {
	t := s.Init(c)

	testRest := func(input string, expectedTokens []*MkToken, expectedRest string) {
		line := t.NewLines("Test_MkParser_VarUse.mk", input).Lines[0]
		p := NewMkParser(line, input, true)
		actualTokens := p.MkTokens()
		c.Check(actualTokens, deepEquals, expectedTokens)
		for i, expectedToken := range expectedTokens {
			if i < len(actualTokens) {
				c.Check(*actualTokens[i], deepEquals, *expectedToken)
				c.Check(actualTokens[i].Varuse, deepEquals, expectedToken.Varuse)
			}
		}
		c.Check(p.Rest(), equals, expectedRest)
	}
	test := func(input string, expectedToken *MkToken) {
		testRest(input, []*MkToken{expectedToken}, "")
	}
	varuse := func(varname string, modifiers ...string) *MkToken {
		text := "${" + varname
		for _, modifier := range modifiers {
			text += ":" + modifier
		}
		text += "}"
		return &MkToken{Text: text, Varuse: NewMkVarUse(varname, modifiers...)}
	}
	varuseText := func(text, varname string, modifiers ...string) *MkToken {
		return &MkToken{Text: text, Varuse: NewMkVarUse(varname, modifiers...)}
	}

	test("${VARIABLE}",
		varuse("VARIABLE"))

	test("${VARIABLE.param}",
		varuse("VARIABLE.param"))

	test("${VARIABLE.${param}}",
		varuse("VARIABLE.${param}"))

	test("${VARIABLE.hicolor-icon-theme}",
		varuse("VARIABLE.hicolor-icon-theme"))

	test("${VARIABLE.gtk+extra}",
		varuse("VARIABLE.gtk+extra"))

	test("${VARIABLE:S/old/new/}",
		varuse("VARIABLE", "S/old/new/"))

	test("${GNUSTEP_LFLAGS:S/-L//g}",
		varuse("GNUSTEP_LFLAGS", "S/-L//g"))

	test("${SUSE_VERSION:S/.//}",
		varuse("SUSE_VERSION", "S/.//"))

	test("${MASTER_SITE_GNOME:=sources/alacarte/0.13/}",
		varuse("MASTER_SITE_GNOME", "=sources/alacarte/0.13/"))

	test("${INCLUDE_DIRS:H:T}",
		varuse("INCLUDE_DIRS", "H", "T"))

	test("${A.${B.${C.${D}}}}",
		varuse("A.${B.${C.${D}}}"))

	test("${RUBY_VERSION:C/([0-9]+)\\.([0-9]+)\\.([0-9]+)/\\1/}",
		varuse("RUBY_VERSION", "C/([0-9]+)\\.([0-9]+)\\.([0-9]+)/\\1/"))

	test("${PERL5_${_var_}:Q}",
		varuse("PERL5_${_var_}", "Q"))

	test("${PKGNAME_REQD:C/(^.*-|^)py([0-9][0-9])-.*/\\2/}",
		varuse("PKGNAME_REQD", "C/(^.*-|^)py([0-9][0-9])-.*/\\2/"))

	test("${PYLIB:S|/|\\\\/|g}",
		varuse("PYLIB", "S|/|\\\\/|g"))

	test("${PKGNAME_REQD:C/ruby([0-9][0-9]+)-.*/\\1/}",
		varuse("PKGNAME_REQD", "C/ruby([0-9][0-9]+)-.*/\\1/"))

	test("${RUBY_SHLIBALIAS:S/\\//\\\\\\//}",
		varuse("RUBY_SHLIBALIAS", "S/\\//\\\\\\//"))

	test("${RUBY_VER_MAP.${RUBY_VER}:U${RUBY_VER}}",
		varuse("RUBY_VER_MAP.${RUBY_VER}", "U${RUBY_VER}"))

	test("${RUBY_VER_MAP.${RUBY_VER}:U18}",
		varuse("RUBY_VER_MAP.${RUBY_VER}", "U18"))

	test("${CONFIGURE_ARGS:S/ENABLE_OSS=no/ENABLE_OSS=yes/g}",
		varuse("CONFIGURE_ARGS", "S/ENABLE_OSS=no/ENABLE_OSS=yes/g"))

	test("${PLIST_RUBY_DIRS:S,DIR=\"PREFIX/,DIR=\",}",
		varuse("PLIST_RUBY_DIRS", "S,DIR=\"PREFIX/,DIR=\","))

	test("${LDFLAGS:S/-Wl,//g:Q}",
		varuse("LDFLAGS", "S/-Wl,//g", "Q"))

	test("${_PERL5_REAL_PACKLIST:S/^/${DESTDIR}/}",
		varuse("_PERL5_REAL_PACKLIST", "S/^/${DESTDIR}/"))

	test("${_PYTHON_VERSION:C/^([0-9])/\\1./1}",
		varuse("_PYTHON_VERSION", "C/^([0-9])/\\1./1"))

	test("${PKGNAME:S/py${_PYTHON_VERSION}/py${i}/}",
		varuse("PKGNAME", "S/py${_PYTHON_VERSION}/py${i}/"))

	test("${PKGNAME:C/-[0-9].*$/-[0-9]*/}",
		varuse("PKGNAME", "C/-[0-9].*$/-[0-9]*/"))

	test("${PKGNAME:S/py${_PYTHON_VERSION}/py${i}/:C/-[0-9].*$/-[0-9]*/}",
		varuse("PKGNAME", "S/py${_PYTHON_VERSION}/py${i}/", "C/-[0-9].*$/-[0-9]*/"))

	test("${_PERL5_VARS:tl:S/^/-V:/}",
		varuse("_PERL5_VARS", "tl", "S/^/-V:/"))

	test("${_PERL5_VARS_OUT:M${_var_:tl}=*:S/^${_var_:tl}=${_PERL5_PREFIX:=/}//}",
		varuse("_PERL5_VARS_OUT", "M${_var_:tl}=*", "S/^${_var_:tl}=${_PERL5_PREFIX:=/}//"))

	test("${RUBY${RUBY_VER}_PATCHLEVEL}",
		varuse("RUBY${RUBY_VER}_PATCHLEVEL"))

	test("${DISTFILES:M*.gem}",
		varuse("DISTFILES", "M*.gem"))

	test("${LOCALBASE:S^/^_^}",
		varuse("LOCALBASE", "S^/^_^"))

	test("${SOURCES:%.c=%.o}",
		varuse("SOURCES", "%.c=%.o"))

	test("${GIT_TEMPLATES:@.t.@ ${EGDIR}/${GIT_TEMPLATEDIR}/${.t.} ${PREFIX}/${GIT_CORE_TEMPLATEDIR}/${.t.} @:M*}",
		varuse("GIT_TEMPLATES", "@.t.@ ${EGDIR}/${GIT_TEMPLATEDIR}/${.t.} ${PREFIX}/${GIT_CORE_TEMPLATEDIR}/${.t.} @", "M*"))

	test("${DISTNAME:C:_:-:}",
		varuse("DISTNAME", "C:_:-:"))

	test("${CF_FILES:H:O:u:S@^@${PKG_SYSCONFDIR}/@}",
		varuse("CF_FILES", "H", "O", "u", "S@^@${PKG_SYSCONFDIR}/@"))

	test("${ALT_GCC_RTS:S%${LOCALBASE}%%:S%/%%}",
		varuse("ALT_GCC_RTS", "S%${LOCALBASE}%%", "S%/%%"))

	test("${PREFIX:C;///*;/;g:C;/$;;}",
		varuse("PREFIX", "C;///*;/;g", "C;/$;;"))

	test("${GZIP_CMD:[1]:Q}",
		varuse("GZIP_CMD", "[1]", "Q"))

	test("${RUBY_RAILS_SUPPORTED:[#]}",
		varuse("RUBY_RAILS_SUPPORTED", "[#]"))

	test("${DISTNAME:C/-[0-9]+$$//:C/_/-/}",
		varuse("DISTNAME", "C/-[0-9]+$$//", "C/_/-/"))

	test("${DISTNAME:slang%=slang2%}",
		varuse("DISTNAME", "slang%=slang2%"))

	test("${OSMAP_SUBSTVARS:@v@-e 's,\\@${v}\\@,${${v}},g' @}",
		varuse("OSMAP_SUBSTVARS", "@v@-e 's,\\@${v}\\@,${${v}},g' @"))

	test("${BRANDELF:D${BRANDELF} -t Linux ${LINUX_LDCONFIG}:U${TRUE}}",
		varuse("BRANDELF", "D${BRANDELF} -t Linux ${LINUX_LDCONFIG}", "U${TRUE}"))

	test("${${_var_}.*}",
		varuse("${_var_}.*"))

	test("${OPTIONS:@opt@printf 'Option %s is selected\n' ${opt:Q}';@}",
		varuse("OPTIONS", "@opt@printf 'Option %s is selected\n' ${opt:Q}';@"))

	/* weird features */
	test("${${EMACS_VERSION_MAJOR}>22:?@comment :}",
		varuse("${EMACS_VERSION_MAJOR}>22", "?@comment :"))

	test("${empty(CFLAGS):?:-cflags ${CFLAGS:Q}}",
		varuse("empty(CFLAGS)", "?:-cflags ${CFLAGS:Q}"))

	test("${${PKGSRC_COMPILER}==gcc:?gcc:cc}",
		varuse("${PKGSRC_COMPILER}==gcc", "?gcc:cc"))

	test("${${XKBBASE}/xkbcomp:L:Q}",
		varuse("${XKBBASE}/xkbcomp", "L", "Q"))

	test("${${PKGBASE} ${PKGVERSION}:L}",
		varuse("${PKGBASE} ${PKGVERSION}", "L"))

	// This complicated expression returns the major.minor.patch version
	// of the package given in ${d}.
	//
	// The :L modifier interprets the variable name not as a variable name
	// but takes it as the variable value. Followed by the :sh modifier,
	// this combination evaluates to the output of pkg_info.
	//
	// In this output, all non-digit characters are replaced with spaces so
	// that the remaining value is a space-separated list of version parts.
	// From these parts, the first 3 are taken and joined using a dot as separator.
	test("${${${PKG_INFO} -E ${d} || echo:L:sh}:L:C/[^[0-9]]*/ /g:[1..3]:ts.}",
		varuse("${${PKG_INFO} -E ${d} || echo:L:sh}", "L", "C/[^[0-9]]*/ /g", "[1..3]", "ts."))

	// For :S and :C, the colon can be left out. It's confusing but possible.
	test("${VAR:S/-//S/.//}",
		varuseText("${VAR:S/-//S/.//}", "VAR", "S/-//", "S/.//"))

	// The :S and :C modifiers accept an arbitrary character as separator. Here it is "a".
	test("${VAR:Sahara}",
		varuse("VAR", "Sahara"))

	test("${VAR:ts}",
		varuse("VAR", "ts")) // The separator character can be left out, which means empty.

	test("${VAR:ts\\000012}",
		varuse("VAR", "ts\\000012")) // The separator character can be a long octal number.

	test("${VAR:ts\\124}",
		varuse("VAR", "ts\\124")) // Or even decimal.

	testRest("${VAR:ts---}", nil, "${VAR:ts---}") // The :ts modifier only takes single-character separators.

	test("$<",
		varuseText("$<", "<")) // Same as ${.IMPSRC}

	test("$(GNUSTEP_USER_ROOT)",
		varuseText("$(GNUSTEP_USER_ROOT)", "GNUSTEP_USER_ROOT"))

	t.CheckOutputLines(
		"WARN: Test_MkParser_VarUse.mk:1: Please use curly braces {} instead of round parentheses () for GNUSTEP_USER_ROOT.")

	testRest("${VAR)", nil, "${VAR)") // Opening brace, closing parenthesis
	testRest("$(VAR}", nil, "$(VAR}") // Opening parenthesis, closing brace
	t.CheckOutputEmpty()              // Warnings are only printed for balanced expressions.

	test("${PLIST_SUBST_VARS:@var@${var}=${${var}:Q}@}",
		varuse("PLIST_SUBST_VARS", "@var@${var}=${${var}:Q}@"))

	test("${PLIST_SUBST_VARS:@var@${var}=${${var}:Q}}",
		varuse("PLIST_SUBST_VARS", "@var@${var}=${${var}:Q}")) // Missing @ at the end

	t.CheckOutputLines(
		"WARN: Test_MkParser_VarUse.mk:1: Modifier ${PLIST_SUBST_VARS:@var@...@} is missing the final \"@\".")
}

func (s *Suite) Test_MkParser_VarUse__ambiguous(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--explain")

	mkline := t.NewMkLine("module.mk", 123, "\t$Varname $X")
	p := NewMkParser(mkline.Line, mkline.ShellCommand(), true)

	tokens := p.MkTokens()
	c.Check(tokens, deepEquals, []*MkToken{
		{"$V", NewMkVarUse("V")},
		{"arname ", nil},
		{"$X", NewMkVarUse("X")}})

	t.CheckOutputLines(
		"ERROR: module.mk:123: $Varname is ambiguous. Use ${Varname} if you mean a Make variable or $$Varname if you mean a shell variable.",
		"",
		"\tOnly the first letter after the dollar is the variable name.",
		"\tEverything following it is normal text, even if it looks like a",
		"\tvariable name to human readers.",
		"",
		"WARN: module.mk:123: $X is ambiguous. Use ${X} if you mean a Make variable or $$X if you mean a shell variable.",
		"",
		"\tIn its current form, this variable is parsed as a Make variable. For",
		"\thuman readers though, $x looks more like a shell variable than a",
		"\tMake variable, since Make variables are usually written using braces",
		"\t(BSD-style) or parentheses (GNU-style).",
		"")
}

func (s *Suite) Test_MkParser_MkCond(c *check.C) {
	testRest := func(input string, expectedTree MkCond, expectedRest string) {
		p := NewMkParser(nil, input, false)
		actualTree := p.MkCond()
		c.Check(actualTree, deepEquals, expectedTree)
		c.Check(p.Rest(), equals, expectedRest)
	}
	test := func(input string, expectedTree MkCond) {
		testRest(input, expectedTree, "")
	}
	varuse := NewMkVarUse

	// TODO: Add tests for &&, ||, !.

	// TODO: Add test for !empty(VAR:M}).

	test("${OPSYS:MNetBSD}",
		&mkCond{Not: &mkCond{Empty: varuse("OPSYS", "MNetBSD")}})

	test("defined(VARNAME)",
		&mkCond{Defined: "VARNAME"})

	test("empty(VARNAME)",
		&mkCond{Empty: varuse("VARNAME")})

	test("!empty(VARNAME)",
		&mkCond{Not: &mkCond{Empty: varuse("VARNAME")}})

	test("!empty(VARNAME:M[yY][eE][sS])",
		&mkCond{Not: &mkCond{Empty: varuse("VARNAME", "M[yY][eE][sS]")}})

	// Colons are unescaped at this point because they cannot be mistaken for separators anymore.
	test("!empty(USE_TOOLS:Mautoconf\\:run)",
		&mkCond{Not: &mkCond{Empty: varuse("USE_TOOLS", "Mautoconf:run")}})

	test("${VARNAME} != \"Value\"",
		&mkCond{CompareVarStr: &MkCondCompareVarStr{varuse("VARNAME"), "!=", "Value"}})

	test("${VARNAME:Mi386} != \"Value\"",
		&mkCond{CompareVarStr: &MkCondCompareVarStr{varuse("VARNAME", "Mi386"), "!=", "Value"}})

	test("${VARNAME} != Value",
		&mkCond{CompareVarStr: &MkCondCompareVarStr{varuse("VARNAME"), "!=", "Value"}})

	test("\"${VARNAME}\" != Value",
		&mkCond{CompareVarStr: &MkCondCompareVarStr{varuse("VARNAME"), "!=", "Value"}})

	test("${pkg} == \"${name}\"",
		&mkCond{CompareVarVar: &MkCondCompareVarVar{varuse("pkg"), "==", varuse("name")}})

	test("\"${pkg}\" == \"${name}\"",
		&mkCond{CompareVarVar: &MkCondCompareVarVar{varuse("pkg"), "==", varuse("name")}})

	test("exists(/etc/hosts)",
		&mkCond{Call: &MkCondCall{"exists", "/etc/hosts"}})

	test("exists(${PREFIX}/var)",
		&mkCond{Call: &MkCondCall{"exists", "${PREFIX}/var"}})

	test("${OPSYS} == \"NetBSD\" || ${OPSYS} == \"OpenBSD\"",
		&mkCond{Or: []*mkCond{
			{CompareVarStr: &MkCondCompareVarStr{varuse("OPSYS"), "==", "NetBSD"}},
			{CompareVarStr: &MkCondCompareVarStr{varuse("OPSYS"), "==", "OpenBSD"}}}})

	test("${OPSYS} == \"NetBSD\" && ${MACHINE_ARCH} == \"i386\"",
		&mkCond{And: []*mkCond{
			{CompareVarStr: &MkCondCompareVarStr{varuse("OPSYS"), "==", "NetBSD"}},
			{CompareVarStr: &MkCondCompareVarStr{varuse("MACHINE_ARCH"), "==", "i386"}}}})

	test("defined(A) && defined(B) || defined(C) && defined(D)",
		&mkCond{Or: []*mkCond{
			{And: []*mkCond{
				{Defined: "A"},
				{Defined: "B"}}},
			{And: []*mkCond{
				{Defined: "C"},
				{Defined: "D"}}}}})

	test("${MACHINE_ARCH:Mi386} || ${MACHINE_OPSYS:MNetBSD}",
		&mkCond{Or: []*mkCond{
			{Not: &mkCond{Empty: varuse("MACHINE_ARCH", "Mi386")}},
			{Not: &mkCond{Empty: varuse("MACHINE_OPSYS", "MNetBSD")}}}})

	// Exotic cases

	// ".if 0" can be used to skip over a block of code.
	test("0",
		&mkCond{Num: "0"})

	test("0xCAFEBABE",
		&mkCond{Num: "0xCAFEBABE"})

	test("${VAR} == 0xCAFEBABE",
		&mkCond{
			CompareVarNum: &MkCondCompareVarNum{
				Var: varuse("VAR"),
				Op:  "==",
				Num: "0xCAFEBABE"}})

	test("! ( defined(A)  && empty(VARNAME) )",
		&mkCond{Not: &mkCond{
			And: []*mkCond{
				{Defined: "A"},
				{Empty: varuse("VARNAME")}}}})

	test("${REQD_MAJOR} > ${MAJOR}",
		&mkCond{CompareVarVar: &MkCondCompareVarVar{varuse("REQD_MAJOR"), ">", varuse("MAJOR")}})

	test("${OS_VERSION} >= 6.5",
		&mkCond{CompareVarNum: &MkCondCompareVarNum{varuse("OS_VERSION"), ">=", "6.5"}})

	test("${OS_VERSION} == 5.3",
		&mkCond{CompareVarNum: &MkCondCompareVarNum{varuse("OS_VERSION"), "==", "5.3"}})

	test("!empty(${OS_VARIANT:MIllumos})", // Probably not intended
		&mkCond{Not: &mkCond{Empty: varuse("${OS_VARIANT:MIllumos}")}})

	// There may be whitespace before the parenthesis; see devel/bmake/files/cond.c:^compare_function.
	test("defined (VARNAME)",
		&mkCond{Defined: "VARNAME"})

	test("${\"${PKG_OPTIONS:Moption}\":?--enable-option:--disable-option}",
		&mkCond{Not: &mkCond{Empty: varuse("\"${PKG_OPTIONS:Moption}\"", "?--enable-option:--disable-option")}})

	// Errors

	testRest("!empty(PKG_OPTIONS:Msndfile) || defined(PKG_OPTIONS:Msamplerate)",
		&mkCond{Not: &mkCond{Empty: varuse("PKG_OPTIONS", "Msndfile")}},
		"|| defined(PKG_OPTIONS:Msamplerate)")

	testRest("${LEFT} &&",
		&mkCond{Not: &mkCond{Empty: varuse("LEFT")}},
		"&&")

	testRest("\"unfinished string literal",
		nil,
		"\"unfinished string literal")

	// Not even the ${VAR} gets through here, although that can be expected. FIXME: Why?
	testRest("${VAR} == \"unfinished string literal",
		nil,
		"${VAR} == \"unfinished string literal")
}

// Pkglint can replace $(VAR) with ${VAR}. It doesn't look at all components
// of nested variables though because this case is not important enough to
// invest much development time. It occurs so seldom that it is acceptable
// to run pkglint multiple times in such a case.
func (s *Suite) Test_MkParser_VarUse__parentheses_autofix(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--autofix")
	t.SetupVartypes()
	lines := t.SetupFileLines("Makefile",
		MkRcsID,
		"COMMENT=$(P1) $(P2)) $(P3:Q) ${BRACES} $(A.$(B.$(C)))")
	mklines := NewMkLines(lines)

	mklines.Check()

	t.CheckOutputLines(
		"AUTOFIX: ~/Makefile:2: Replacing \"$(P1)\" with \"${P1}\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"$(P2)\" with \"${P2}\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"$(P3:Q)\" with \"${P3:Q}\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"$(C)\" with \"${C}\".")
	t.CheckFileLines("Makefile",
		MkRcsID,
		"COMMENT=${P1} ${P2}) ${P3:Q} ${BRACES} $(A.$(B.${C}))")
}

func (s *Suite) Test_MkCondWalker_Walk(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("Makefile", 4, ""+
		".if ${VAR:Mmatch} == ${OTHER} || "+
		"${STR} == Str || "+
		"${NUM} == 3 && "+
		"defined(VAR) && "+
		"!exists(file.mk) && "+
		"(((${NONEMPTY})))")
	var events []string

	varuseStr := func(varuse *MkVarUse) string {
		strs := make([]string, 1+len(varuse.modifiers), 1+len(varuse.modifiers))
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
	// Especially Not(Empty(VARNAME)) should be an interesting case.

	mkline.Cond().Walk(&MkCondCallback{
		Defined: func(varname string) {
			addEvent("defined", varname)
		},
		Empty: func(varuse *MkVarUse) {
			addEvent("empty", varuseStr(varuse))
		},
		CompareVarNum: func(varuse *MkVarUse, op string, num string) {
			addEvent("compareVarNum", varuseStr(varuse), num)
		},
		CompareVarStr: func(varuse *MkVarUse, op string, str string) {
			addEvent("compareVarStr", varuseStr(varuse), str)
		},
		CompareVarVar: func(left *MkVarUse, op string, right *MkVarUse) {
			addEvent("compareVarVar", varuseStr(left), varuseStr(right))
		},
		Call: func(name string, arg string) {
			addEvent("call", name, arg)
		},
		VarUse: func(varuse *MkVarUse) {
			addEvent("varUse", varuseStr(varuse))
		}})

	c.Check(events, deepEquals, []string{
		" compareVarVar  VAR:Mmatch, OTHER",
		"        varUse  VAR:Mmatch",
		"        varUse  OTHER",
		" compareVarStr  STR, Str",
		"        varUse  STR",
		" compareVarNum  NUM, 3",
		"        varUse  NUM",
		"       defined  VAR",
		"        varUse  VAR",
		"          call  exists, file.mk",
		"         empty  NONEMPTY",
		"        varUse  NONEMPTY"})
}
