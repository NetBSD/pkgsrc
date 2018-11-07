package main

import (
	"fmt"
	"gopkg.in/check.v1"
	"strings"
)

func (s *Suite) Test_MkParser_MkTokens(c *check.C) {
	t := s.Init(c)

	checkRest := func(input string, expectedTokens []*MkToken, expectedRest string) {
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
	check := func(input string, expectedToken *MkToken) {
		checkRest(input, []*MkToken{expectedToken}, "")
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
	varuseText := func(text, varname string, modifiers ...string) *MkToken {
		return &MkToken{Text: text, Varuse: NewMkVarUse(varname, modifiers...)}
	}

	check("literal", literal("literal"))
	check("\\/share\\/ { print \"share directory\" }", literal("\\/share\\/ { print \"share directory\" }"))
	check("find . -name \\*.orig -o -name \\*.pre", literal("find . -name \\*.orig -o -name \\*.pre"))
	check("-e 's|\\$${EC2_HOME.*}|EC2_HOME}|g'", literal("-e 's|\\$${EC2_HOME.*}|EC2_HOME}|g'"))

	check("${VARIABLE}", varuse("VARIABLE"))
	check("${VARIABLE.param}", varuse("VARIABLE.param"))
	check("${VARIABLE.${param}}", varuse("VARIABLE.${param}"))
	check("${VARIABLE.hicolor-icon-theme}", varuse("VARIABLE.hicolor-icon-theme"))
	check("${VARIABLE.gtk+extra}", varuse("VARIABLE.gtk+extra"))
	check("${VARIABLE:S/old/new/}", varuse("VARIABLE", "S/old/new/"))
	check("${GNUSTEP_LFLAGS:S/-L//g}", varuse("GNUSTEP_LFLAGS", "S/-L//g"))
	check("${SUSE_VERSION:S/.//}", varuse("SUSE_VERSION", "S/.//"))
	check("${MASTER_SITE_GNOME:=sources/alacarte/0.13/}", varuse("MASTER_SITE_GNOME", "=sources/alacarte/0.13/"))
	check("${INCLUDE_DIRS:H:T}", varuse("INCLUDE_DIRS", "H", "T"))
	check("${A.${B.${C.${D}}}}", varuse("A.${B.${C.${D}}}"))
	check("${RUBY_VERSION:C/([0-9]+)\\.([0-9]+)\\.([0-9]+)/\\1/}", varuse("RUBY_VERSION", "C/([0-9]+)\\.([0-9]+)\\.([0-9]+)/\\1/"))
	check("${PERL5_${_var_}:Q}", varuse("PERL5_${_var_}", "Q"))
	check("${PKGNAME_REQD:C/(^.*-|^)py([0-9][0-9])-.*/\\2/}", varuse("PKGNAME_REQD", "C/(^.*-|^)py([0-9][0-9])-.*/\\2/"))
	check("${PYLIB:S|/|\\\\/|g}", varuse("PYLIB", "S|/|\\\\/|g"))
	check("${PKGNAME_REQD:C/ruby([0-9][0-9]+)-.*/\\1/}", varuse("PKGNAME_REQD", "C/ruby([0-9][0-9]+)-.*/\\1/"))
	check("${RUBY_SHLIBALIAS:S/\\//\\\\\\//}", varuse("RUBY_SHLIBALIAS", "S/\\//\\\\\\//"))
	check("${RUBY_VER_MAP.${RUBY_VER}:U${RUBY_VER}}", varuse("RUBY_VER_MAP.${RUBY_VER}", "U${RUBY_VER}"))
	check("${RUBY_VER_MAP.${RUBY_VER}:U18}", varuse("RUBY_VER_MAP.${RUBY_VER}", "U18"))
	check("${CONFIGURE_ARGS:S/ENABLE_OSS=no/ENABLE_OSS=yes/g}", varuse("CONFIGURE_ARGS", "S/ENABLE_OSS=no/ENABLE_OSS=yes/g"))
	check("${PLIST_RUBY_DIRS:S,DIR=\"PREFIX/,DIR=\",}", varuse("PLIST_RUBY_DIRS", "S,DIR=\"PREFIX/,DIR=\","))
	check("${LDFLAGS:S/-Wl,//g:Q}", varuse("LDFLAGS", "S/-Wl,//g", "Q"))
	check("${_PERL5_REAL_PACKLIST:S/^/${DESTDIR}/}", varuse("_PERL5_REAL_PACKLIST", "S/^/${DESTDIR}/"))
	check("${_PYTHON_VERSION:C/^([0-9])/\\1./1}", varuse("_PYTHON_VERSION", "C/^([0-9])/\\1./1"))
	check("${PKGNAME:S/py${_PYTHON_VERSION}/py${i}/}", varuse("PKGNAME", "S/py${_PYTHON_VERSION}/py${i}/"))
	check("${PKGNAME:C/-[0-9].*$/-[0-9]*/}", varuse("PKGNAME", "C/-[0-9].*$/-[0-9]*/"))
	check("${PKGNAME:S/py${_PYTHON_VERSION}/py${i}/:C/-[0-9].*$/-[0-9]*/}", varuse("PKGNAME", "S/py${_PYTHON_VERSION}/py${i}/", "C/-[0-9].*$/-[0-9]*/"))
	check("${_PERL5_VARS:tl:S/^/-V:/}", varuse("_PERL5_VARS", "tl", "S/^/-V:/"))
	check("${_PERL5_VARS_OUT:M${_var_:tl}=*:S/^${_var_:tl}=${_PERL5_PREFIX:=/}//}", varuse("_PERL5_VARS_OUT", "M${_var_:tl}=*", "S/^${_var_:tl}=${_PERL5_PREFIX:=/}//"))
	check("${RUBY${RUBY_VER}_PATCHLEVEL}", varuse("RUBY${RUBY_VER}_PATCHLEVEL"))
	check("${DISTFILES:M*.gem}", varuse("DISTFILES", "M*.gem"))
	check("${LOCALBASE:S^/^_^}", varuse("LOCALBASE", "S^/^_^"))
	check("${SOURCES:%.c=%.o}", varuse("SOURCES", "%.c=%.o"))
	check("${GIT_TEMPLATES:@.t.@ ${EGDIR}/${GIT_TEMPLATEDIR}/${.t.} ${PREFIX}/${GIT_CORE_TEMPLATEDIR}/${.t.} @:M*}",
		varuse("GIT_TEMPLATES", "@.t.@ ${EGDIR}/${GIT_TEMPLATEDIR}/${.t.} ${PREFIX}/${GIT_CORE_TEMPLATEDIR}/${.t.} @", "M*"))
	check("${DISTNAME:C:_:-:}", varuse("DISTNAME", "C:_:-:"))
	check("${CF_FILES:H:O:u:S@^@${PKG_SYSCONFDIR}/@}", varuse("CF_FILES", "H", "O", "u", "S@^@${PKG_SYSCONFDIR}/@"))
	check("${ALT_GCC_RTS:S%${LOCALBASE}%%:S%/%%}", varuse("ALT_GCC_RTS", "S%${LOCALBASE}%%", "S%/%%"))
	check("${PREFIX:C;///*;/;g:C;/$;;}", varuse("PREFIX", "C;///*;/;g", "C;/$;;"))
	check("${GZIP_CMD:[1]:Q}", varuse("GZIP_CMD", "[1]", "Q"))
	check("${RUBY_RAILS_SUPPORTED:[#]}", varuse("RUBY_RAILS_SUPPORTED", "[#]"))
	check("${DISTNAME:C/-[0-9]+$$//:C/_/-/}", varuse("DISTNAME", "C/-[0-9]+$$//", "C/_/-/"))
	check("${DISTNAME:slang%=slang2%}", varuse("DISTNAME", "slang%=slang2%"))
	check("${OSMAP_SUBSTVARS:@v@-e 's,\\@${v}\\@,${${v}},g' @}", varuse("OSMAP_SUBSTVARS", "@v@-e 's,\\@${v}\\@,${${v}},g' @"))
	check("${BRANDELF:D${BRANDELF} -t Linux ${LINUX_LDCONFIG}:U${TRUE}}", varuse("BRANDELF", "D${BRANDELF} -t Linux ${LINUX_LDCONFIG}", "U${TRUE}"))
	check("${${_var_}.*}", varuse("${_var_}.*"))

	check("${GCONF_SCHEMAS:@.s.@${INSTALL_DATA} ${WRKSRC}/src/common/dbus/${.s.} ${DESTDIR}${GCONF_SCHEMAS_DIR}/@}",
		varuse("GCONF_SCHEMAS", "@.s.@${INSTALL_DATA} ${WRKSRC}/src/common/dbus/${.s.} ${DESTDIR}${GCONF_SCHEMAS_DIR}/@"))

	/* weird features */
	check("${${EMACS_VERSION_MAJOR}>22:?@comment :}", varuse("${EMACS_VERSION_MAJOR}>22", "?@comment :"))
	check("${empty(CFLAGS):?:-cflags ${CFLAGS:Q}}", varuse("empty(CFLAGS)", "?:-cflags ${CFLAGS:Q}"))
	check("${${PKGSRC_COMPILER}==gcc:?gcc:cc}", varuse("${PKGSRC_COMPILER}==gcc", "?gcc:cc"))

	check("${${XKBBASE}/xkbcomp:L:Q}", varuse("${XKBBASE}/xkbcomp", "L", "Q"))
	check("${${PKGBASE} ${PKGVERSION}:L}", varuse("${PKGBASE} ${PKGVERSION}", "L"))

	check("${${${PKG_INFO} -E ${d} || echo:L:sh}:L:C/[^[0-9]]*/ /g:[1..3]:ts.}",
		varuse("${${PKG_INFO} -E ${d} || echo:L:sh}", "L", "C/[^[0-9]]*/ /g", "[1..3]", "ts."))

	// For :S and :C, the colon can be left out.
	check("${VAR:S/-//S/.//}",
		varuseText("${VAR:S/-//S/.//}", "VAR", "S/-//", "S/.//"))

	check("${VAR:ts}", varuse("VAR", "ts"))                 // The separator character can be left out.
	check("${VAR:ts\\000012}", varuse("VAR", "ts\\000012")) // The separator character can be a long octal number.
	check("${VAR:ts\\124}", varuse("VAR", "ts\\124"))       // Or even decimal.

	checkRest("${VAR:ts---}", nil, "${VAR:ts---}") // The :ts modifier only takes single-character separators.

	check("$<", varuseText("$<", "<")) // Same as ${.IMPSRC}

	check("$(GNUSTEP_USER_ROOT)", varuseText("$(GNUSTEP_USER_ROOT)", "GNUSTEP_USER_ROOT"))
	t.CheckOutputLines(
		"WARN: Test_MkParser_MkTokens.mk:1: Please use curly braces {} instead of round parentheses () for GNUSTEP_USER_ROOT.")

	checkRest("${VAR)", nil, "${VAR)") // Opening brace, closing parenthesis
	checkRest("$(VAR}", nil, "$(VAR}") // Opening parenthesis, closing brace
	t.CheckOutputEmpty()               // Warnings are only printed for balanced expressions.

	check("${PLIST_SUBST_VARS:@var@${var}=${${var}:Q}@}", varuse("PLIST_SUBST_VARS", "@var@${var}=${${var}:Q}@"))
	check("${PLIST_SUBST_VARS:@var@${var}=${${var}:Q}}", varuse("PLIST_SUBST_VARS", "@var@${var}=${${var}:Q}")) // Missing @ at the end
	t.CheckOutputLines(
		"WARN: Test_MkParser_MkTokens.mk:1: Modifier ${PLIST_SUBST_VARS:@var@...@} is missing the final \"@\".")

	checkRest("hello, ${W:L:tl}orld", []*MkToken{
		literal("hello, "),
		varuse("W", "L", "tl"),
		literal("orld")},
		"")
	checkRest("ftp://${PKGNAME}/ ${MASTER_SITES:=subdir/}", []*MkToken{
		literal("ftp://"),
		varuse("PKGNAME"),
		literal("/ "),
		varuse("MASTER_SITES", "=subdir/")},
		"")

	// FIXME: Text must match modifiers.
	checkRest("${VAR:S,a,b,c,d,e,f}",
		[]*MkToken{{
			Text:   "${VAR:S,a,b,c,d,e,f}",
			Varuse: NewMkVarUse("VAR", "S,a,b,")}},
		"")
}

func (s *Suite) Test_MkParser_MkCond(c *check.C) {
	checkRest := func(input string, expectedTree MkCond, expectedRest string) {
		p := NewMkParser(dummyLine, input, false)
		actualTree := p.MkCond()
		c.Check(actualTree, deepEquals, expectedTree)
		c.Check(p.Rest(), equals, expectedRest)
	}
	check := func(input string, expectedTree MkCond) {
		checkRest(input, expectedTree, "")
	}
	varuse := NewMkVarUse

	check("${OPSYS:MNetBSD}",
		&mkCond{Not: &mkCond{Empty: varuse("OPSYS", "MNetBSD")}})
	check("defined(VARNAME)",
		&mkCond{Defined: "VARNAME"})
	check("empty(VARNAME)",
		&mkCond{Empty: varuse("VARNAME")})
	check("!empty(VARNAME)",
		&mkCond{Not: &mkCond{Empty: varuse("VARNAME")}})
	check("!empty(VARNAME:M[yY][eE][sS])",
		&mkCond{Not: &mkCond{Empty: varuse("VARNAME", "M[yY][eE][sS]")}})
	check("!empty(USE_TOOLS:Mautoconf\\:run)",
		&mkCond{Not: &mkCond{Empty: varuse("USE_TOOLS", "Mautoconf:run")}})
	check("${VARNAME} != \"Value\"",
		&mkCond{CompareVarStr: &MkCondCompareVarStr{varuse("VARNAME"), "!=", "Value"}})
	check("${VARNAME:Mi386} != \"Value\"",
		&mkCond{CompareVarStr: &MkCondCompareVarStr{varuse("VARNAME", "Mi386"), "!=", "Value"}})
	check("${VARNAME} != Value",
		&mkCond{CompareVarStr: &MkCondCompareVarStr{varuse("VARNAME"), "!=", "Value"}})
	check("\"${VARNAME}\" != Value",
		&mkCond{CompareVarStr: &MkCondCompareVarStr{varuse("VARNAME"), "!=", "Value"}})
	check("${pkg} == \"${name}\"",
		&mkCond{CompareVarVar: &MkCondCompareVarVar{varuse("pkg"), "==", varuse("name")}})
	check("\"${pkg}\" == \"${name}\"",
		&mkCond{CompareVarVar: &MkCondCompareVarVar{varuse("pkg"), "==", varuse("name")}})
	check("(defined(VARNAME))",
		&mkCond{Defined: "VARNAME"})
	check("exists(/etc/hosts)",
		&mkCond{Call: &MkCondCall{"exists", "/etc/hosts"}})
	check("exists(${PREFIX}/var)",
		&mkCond{Call: &MkCondCall{"exists", "${PREFIX}/var"}})
	check("${OPSYS} == \"NetBSD\" || ${OPSYS} == \"OpenBSD\"",
		&mkCond{Or: []*mkCond{
			{CompareVarStr: &MkCondCompareVarStr{varuse("OPSYS"), "==", "NetBSD"}},
			{CompareVarStr: &MkCondCompareVarStr{varuse("OPSYS"), "==", "OpenBSD"}}}})
	check("${OPSYS} == \"NetBSD\" && ${MACHINE_ARCH} == \"i386\"",
		&mkCond{And: []*mkCond{
			{CompareVarStr: &MkCondCompareVarStr{varuse("OPSYS"), "==", "NetBSD"}},
			{CompareVarStr: &MkCondCompareVarStr{varuse("MACHINE_ARCH"), "==", "i386"}}}})
	check("defined(A) && defined(B) || defined(C) && defined(D)",
		&mkCond{Or: []*mkCond{
			{And: []*mkCond{
				{Defined: "A"},
				{Defined: "B"}}},
			{And: []*mkCond{
				{Defined: "C"},
				{Defined: "D"}}}}})
	check("${MACHINE_ARCH:Mi386} || ${MACHINE_OPSYS:MNetBSD}",
		&mkCond{Or: []*mkCond{
			{Not: &mkCond{Empty: varuse("MACHINE_ARCH", "Mi386")}},
			{Not: &mkCond{Empty: varuse("MACHINE_OPSYS", "MNetBSD")}}}})

	// Exotic cases
	check("0",
		&mkCond{Num: "0"})
	check("! ( defined(A)  && empty(VARNAME) )",
		&mkCond{Not: &mkCond{
			And: []*mkCond{
				{Defined: "A"},
				{Empty: varuse("VARNAME")}}}})
	check("${REQD_MAJOR} > ${MAJOR}",
		&mkCond{CompareVarVar: &MkCondCompareVarVar{varuse("REQD_MAJOR"), ">", varuse("MAJOR")}})
	check("${OS_VERSION} >= 6.5",
		&mkCond{CompareVarNum: &MkCondCompareVarNum{varuse("OS_VERSION"), ">=", "6.5"}})
	check("${OS_VERSION} == 5.3",
		&mkCond{CompareVarNum: &MkCondCompareVarNum{varuse("OS_VERSION"), "==", "5.3"}})
	check("!empty(${OS_VARIANT:MIllumos})", // Probably not intended
		&mkCond{Not: &mkCond{Empty: varuse("${OS_VARIANT:MIllumos}")}})
	check("defined (VARNAME)", // There may be whitespace before the parenthesis; see devel/bmake/files/cond.c:^compare_function.
		&mkCond{Defined: "VARNAME"})
	check("${\"${PKG_OPTIONS:Moption}\":?--enable-option:--disable-option}",
		&mkCond{Not: &mkCond{Empty: varuse("\"${PKG_OPTIONS:Moption}\"", "?--enable-option:--disable-option")}})

	// Errors
	checkRest("!empty(PKG_OPTIONS:Msndfile) || defined(PKG_OPTIONS:Msamplerate)",
		&mkCond{Not: &mkCond{Empty: varuse("PKG_OPTIONS", "Msndfile")}},
		" || defined(PKG_OPTIONS:Msamplerate)")
	checkRest("${LEFT} &&",
		&mkCond{Not: &mkCond{Empty: varuse("LEFT")}},
		"&&")
	checkRest("\"unfinished string literal",
		nil,
		"\"unfinished string literal")
	checkRest("${VAR} == \"unfinished string literal",
		nil, // Not even the ${VAR} gets through here, although that can be expected.
		"${VAR} == \"unfinished string literal")
}

func (s *Suite) Test_MkParser__varuse_parentheses_autofix(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--autofix")
	t.SetupVartypes()
	lines := t.SetupFileLines("Makefile",
		MkRcsID,
		"COMMENT=$(P1) $(P2)) $(P3:Q) ${BRACES}")
	mklines := NewMkLines(lines)

	mklines.Check()

	t.CheckOutputLines(
		"AUTOFIX: ~/Makefile:2: Replacing \"$(P1)\" with \"${P1}\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"$(P2)\" with \"${P2}\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"$(P3:Q)\" with \"${P3:Q}\".")
	t.CheckFileLines("Makefile",
		MkRcsID,
		"COMMENT=${P1} ${P2}) ${P3:Q} ${BRACES}")
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
		events = append(events, fmt.Sprintf("%14s  %s", name, strings.Join(args, ", ")))
	}

	NewMkCondWalker().Walk(mkline.Cond(), &MkCondCallback{
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
