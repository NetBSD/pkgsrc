package pkglint

import (
	"gopkg.in/check.v1"
	"netbsd.org/pkglint/textproc"
)

func (s *Suite) Test_NewMkLexer__with_diag(c *check.C) {
	t := s.Init(c)

	diag := t.NewLine("filename.mk", 123, "")

	lex := NewMkLexer("${", diag)

	use := lex.VarUse()
	t.CheckDeepEquals(use, NewMkVarUse(""))
	t.CheckEquals(lex.Rest(), "")
	t.CheckOutputLines(
		"WARN: filename.mk:123: Missing closing \"}\" for \"\".")
}

func (s *Suite) Test_NewMkLexer__without_diag(c *check.C) {
	t := s.Init(c)

	lex := NewMkLexer("${", nil)

	use := lex.VarUse()
	t.CheckDeepEquals(use, NewMkVarUse(""))
	t.CheckEquals(lex.Rest(), "")
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLexer_MkTokens(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	testRest := func(input string, expectedTokens []*MkToken, expectedRest string) {
		line := t.NewLines("Test_MkLexer_MkTokens.mk", input).Lines[0]
		p := NewMkLexer(input, line)
		actualTokens, rest := p.MkTokens()
		t.CheckDeepEquals(actualTokens, expectedTokens)
		for i, expectedToken := range expectedTokens {
			if i < len(actualTokens) {
				t.CheckDeepEquals(*actualTokens[i], *expectedToken)
				t.CheckDeepEquals(actualTokens[i].Varuse, expectedToken.Varuse)
			}
		}
		t.CheckEquals(rest, expectedRest)
	}
	test := func(input string, expectedToken *MkToken) {
		testRest(input, b.Tokens(expectedToken), "")
	}
	literal := b.TextToken
	varuse := b.VaruseToken

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

	testRest("hello, ${W:L:tl}orld",
		b.Tokens(
			literal("hello, "),
			varuse("W", "L", "tl"),
			literal("orld")),
		"")

	testRest("ftp://${PKGNAME}/ ${MASTER_SITES:=subdir/}",
		b.Tokens(
			literal("ftp://"),
			varuse("PKGNAME"),
			literal("/ "),
			varuse("MASTER_SITES", "=subdir/")),
		"")

	testRest("${VAR:S,a,b,c,d,e,f}",
		b.Tokens(b.VaruseTextToken("${VAR:S,a,b,c,d,e,f}", "VAR", "S,a,b,")),
		"")
	t.CheckOutputLines(
		"WARN: Test_MkLexer_MkTokens.mk:1: Invalid variable modifier \"c,d,e,f\" for \"VAR\".")

	testRest("Text${VAR:Mmodifier}${VAR2}more text${VAR3}",
		b.Tokens(
			literal("Text"),
			varuse("VAR", "Mmodifier"),
			varuse("VAR2"),
			literal("more text"),
			varuse("VAR3")),
		"")
}

func (s *Suite) Test_MkLexer_MkToken(c *check.C) {
	t := s.Init(c)

	test := func(input string, expectedToken *MkToken, expectedRest string, diagnostics ...string) {
		lexer := NewMkLexer(input, t.NewLine("Test_MkLexer_VarUse.mk", 1, ""))
		actualToken := lexer.MkToken()
		rest := lexer.Rest()

		t.CheckDeepEquals(actualToken, expectedToken)
		t.CheckEquals(rest, expectedRest)
		t.CheckOutput(diagnostics)
	}

	test("${VARIABLE}rest",
		&MkToken{"${VARIABLE}", NewMkVarUse("VARIABLE")}, "rest")

	test("$@rest",
		&MkToken{"$@", NewMkVarUse("@")}, "rest")

	test("text$$",
		&MkToken{"text$$", nil}, "")

	test("text$$${REST}",
		&MkToken{"text$$", nil}, "${REST}")

	test("",
		nil, "")
}

func (s *Suite) Test_MkLexer_VarUse(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()
	varuse := b.VaruseToken
	varuseText := b.VaruseTextToken

	testRest := func(input string, expectedToken *MkToken, expectedRest string, diagnostics ...string) {
		lexer := NewMkLexer(input, t.NewLine("Test_MkLexer_VarUse.mk", 1, ""))
		actualToken := lexer.MkToken()
		rest := lexer.Rest()

		t.CheckDeepEquals(actualToken, expectedToken)
		t.CheckEquals(rest, expectedRest)
		t.CheckOutput(diagnostics)
	}
	test := func(input string, expectedToken *MkToken, diagnostics ...string) {
		testRest(input, expectedToken, "", diagnostics...)
	}

	t.Use(testRest, test, varuse, varuseText)

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

	// The $@ in the :S modifier refers to ${.TARGET}.
	// When used in a target called "target",
	// the whole expression evaluates to "-replaced-".
	test("${:U-target-:S/$@/replaced/:Q}",
		varuse("", "U-target-", "S/$@/replaced/", "Q"))
	test("${:U-target-:C/$@/replaced/:Q}",
		varuse("", "U-target-", "C/$@/replaced/", "Q"))

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

	test("${GZIP_CMD:[asdf]:Q}",
		varuseText("${GZIP_CMD:[asdf]:Q}", "GZIP_CMD", "Q"),
		"WARN: Test_MkLexer_VarUse.mk:1: Invalid variable modifier \"[asdf]\" for \"GZIP_CMD\".")

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

	// The variable name is optional; the variable with the empty name always
	// evaluates to the empty string. Bmake actively prevents this variable from
	// ever being defined. Therefore the :U branch is always taken, and this
	// in turn is used to implement the variables from the .for loops.
	test("${:U}",
		varuse("", "U"))

	test("${:Ufixed value}",
		varuse("", "Ufixed value"))

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

	test("$<",
		varuseText("$<", "<")) // Same as ${.IMPSRC}

	test("$(GNUSTEP_USER_ROOT)",
		varuseText("$(GNUSTEP_USER_ROOT)", "GNUSTEP_USER_ROOT"),
		"WARN: Test_MkLexer_VarUse.mk:1: Please use curly braces {} instead of round parentheses () for GNUSTEP_USER_ROOT.")

	// Opening brace, closing parenthesis.
	// Warnings are only printed for balanced expressions.
	test("${VAR)",
		varuseText("${VAR)", "VAR)"),
		"WARN: Test_MkLexer_VarUse.mk:1: Missing closing \"}\" for \"VAR)\".",
		"WARN: Test_MkLexer_VarUse.mk:1: Invalid part \")\" after variable name \"VAR\".")

	// Opening parenthesis, closing brace
	// Warnings are only printed for balanced expressions.
	test("$(VAR}",
		varuseText("$(VAR}", "VAR}"),
		"WARN: Test_MkLexer_VarUse.mk:1: Missing closing \")\" for \"VAR}\".",
		"WARN: Test_MkLexer_VarUse.mk:1: Invalid part \"}\" after variable name \"VAR\".")

	test("${PLIST_SUBST_VARS:@var@${var}=${${var}:Q}@}",
		varuse("PLIST_SUBST_VARS", "@var@${var}=${${var}:Q}@"))

	test("${PLIST_SUBST_VARS:@var@${var}=${${var}:Q}}",
		varuseText("${PLIST_SUBST_VARS:@var@${var}=${${var}:Q}}",
			"PLIST_SUBST_VARS", "@var@${var}=${${var}:Q}}"),
		"WARN: Test_MkLexer_VarUse.mk:1: Modifier ${PLIST_SUBST_VARS:@var@...@} is missing the final \"@\".",
		"WARN: Test_MkLexer_VarUse.mk:1: Missing closing \"}\" for \"PLIST_SUBST_VARS\".")

	// The replacement text may include closing braces, which is useful
	// for AWK programs.
	test("${PLIST_SUBST_VARS:@var@{${var}}@}",
		varuseText("${PLIST_SUBST_VARS:@var@{${var}}@}",
			"PLIST_SUBST_VARS", "@var@{${var}}@"),
		nil...)

	// Unfinished variable use
	test("${",
		varuseText("${", ""),
		"WARN: Test_MkLexer_VarUse.mk:1: Missing closing \"}\" for \"\".")

	// Unfinished nested variable use
	test("${${",
		varuseText("${${", "${"),
		"WARN: Test_MkLexer_VarUse.mk:1: Missing closing \"}\" for \"\".",
		"WARN: Test_MkLexer_VarUse.mk:1: Missing closing \"}\" for \"${\".")

	test("${arbitrary :Mpattern:---:Q}",
		varuseText("${arbitrary :Mpattern:---:Q}", "arbitrary ", "Mpattern", "Q"),
		// TODO: Swap the order of these message
		"WARN: Test_MkLexer_VarUse.mk:1: Invalid variable modifier \"---\" for \"arbitrary \".",
		"WARN: Test_MkLexer_VarUse.mk:1: Invalid part \" \" after variable name \"arbitrary\".")

	// Variable names containing spaces do not occur in pkgsrc.
	// Technically they are possible:
	//
	//  VARNAME=        name with spaces
	//  ${VARNAME}=     value
	//
	//  all:
	//         @echo ${name with spaces:Q}''
	test("${arbitrary text}",
		varuse("arbitrary text"),
		"WARN: Test_MkLexer_VarUse.mk:1: Invalid part \" text\" after variable name \"arbitrary\".")

	test("${:!command!:Q}",
		varuse("", "!command!", "Q"))
}

// Pkglint can replace $(VAR) with ${VAR}. It doesn't look at all components
// of nested variables though because this case is not important enough to
// invest much development time. It occurs so seldom that it is acceptable
// to run pkglint multiple times in such a case.
func (s *Suite) Test_MkLexer_varUseBrace__autofix_parentheses(c *check.C) {
	t := s.Init(c)

	test := func(autofix bool) {
		mklines := t.SetUpFileMkLines("Makefile",
			MkCvsID,
			"COMMENT=\t$(P1) $(P2)) $(P3:Q) ${BRACES} $(A.$(B.$(C))) $(A:M\\#)",
			"P1=\t\t${COMMENT}",
			"P2=\t\t# nothing",
			"P3=\t\t# nothing",
			"BRACES=\t\t# nothing",
			"C=\t\t# nothing",
			"A=\t\t# nothing")

		mklines.Check()
	}

	t.ExpectDiagnosticsAutofix(
		test,

		"WARN: ~/Makefile:2: Please use curly braces {} instead of round parentheses () for P1.",
		"WARN: ~/Makefile:2: Please use curly braces {} instead of round parentheses () for P2.",
		"WARN: ~/Makefile:2: Please use curly braces {} instead of round parentheses () for P3.",
		"WARN: ~/Makefile:2: Please use curly braces {} instead of round parentheses () for C.",
		"WARN: ~/Makefile:2: Please use curly braces {} instead of round parentheses () for B.$(C).",
		"WARN: ~/Makefile:2: Please use curly braces {} instead of round parentheses () for A.$(B.$(C)).",
		"WARN: ~/Makefile:2: Please use curly braces {} instead of round parentheses () for A.",
		"AUTOFIX: ~/Makefile:2: Replacing \"$(P1)\" with \"${P1}\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"$(P2)\" with \"${P2}\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"$(P3:Q)\" with \"${P3:Q}\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"$(C)\" with \"${C}\".")
}

func (s *Suite) Test_MkLexer_Varname(c *check.C) {
	t := s.Init(c)

	test := func(text string) {
		line := t.NewLine("filename.mk", 1, text)
		p := NewMkLexer(text, line)

		varname := p.Varname()

		t.CheckEquals(varname, text)
		t.CheckEquals(p.Rest(), "")
	}

	testRest := func(text string, expectedVarname string, expectedRest string) {
		line := t.NewLine("filename.mk", 1, text)
		p := NewMkLexer(text, line)

		varname := p.Varname()

		t.CheckEquals(varname, expectedVarname)
		t.CheckEquals(p.Rest(), expectedRest)
	}

	test("VARNAME")
	test("VARNAME.param")
	test("VARNAME.${param}")
	test("SITES_${param}")
	test("SITES_distfile-1.0.tar.gz")
	test("SITES.gtk+-2.0")
	test("PKGPATH.category/package")

	testRest("VARNAME/rest", "VARNAME", "/rest")
}

func (s *Suite) Test_MkLexer_varUseText(c *check.C) {
	t := s.Init(c)

	test := func(text string, expected string, diagnostics ...string) {
		line := t.NewLine("Makefile", 20, "\t"+text)
		p := NewMkLexer(text, line)

		actual := p.varUseText('}')

		t.CheckDeepEquals(actual, expected)
		t.CheckEquals(p.Rest(), text[len(expected):])
		t.CheckOutput(diagnostics)
	}

	test("", "")
	test("asdf", "asdf")

	test("a$$a b", "a$$a b")
	test("a$$a b", "a$$a b")

	test("a$a b", "a$a b",
		"WARN: Makefile:20: $a is ambiguous. Use ${a} if you mean "+
			"a Make variable or $$a if you mean a shell variable.")

	test("a${INNER} b", "a${INNER} b")

	test("a${${${${${$(NESTED)}}}}}", "a${${${${${$(NESTED)}}}}}",
		"WARN: Makefile:20: Please use curly braces {} "+
			"instead of round parentheses () for NESTED.")

	test("a)b", "a)b") // Since the closing character is '}', not ')'.

	test("a:b", "a")
	test("a\\ba", "a\\ba")
	test("a\\:a", "a\\:a")
	test("a\\\\:a", "a\\\\")
}

func (s *Suite) Test_MkLexer_varUseModifierSysV(c *check.C) {
	t := s.Init(c)

	test := func(input string, closing byte, mod, modNoVar string, rest string, diagnostics ...string) {
		diag := t.NewLine("filename.mk", 123, "")
		lex := NewMkLexer(input, diag)

		actualMod, actualModNoVar := lex.varUseModifierSysV(closing)

		t.CheckDeepEquals(
			[]interface{}{actualMod, actualModNoVar, lex.Rest()},
			[]interface{}{mod, modNoVar, rest})
		t.CheckOutput(diagnostics)
	}

	// The shortest possible SysV substitution:
	// replace nothing with nothing.
	test(":=}rest", '}',
		":=", ":=", "}rest",
		nil...)

	// Parsing the SysV modifier produces no parse error.
	// This will be done by the surrounding VarUse when it doesn't find
	// the closing parenthesis (in this case, or usually a brace).
	test(":=}rest", ')',
		":=}rest", ":=}rest", "",
		nil...)
}

func (s *Suite) Test_MkLexer_VarUseModifiers(c *check.C) {
	t := s.Init(c)

	varUse := NewMkTokenBuilder().VarUse
	test := func(text string, varUse *MkVarUse, diagnostics ...string) {
		line := t.NewLine("Makefile", 20, "\t"+text)
		p := NewMkLexer(text, line)

		actual := p.VarUse()

		t.CheckDeepEquals(actual, varUse)
		t.CheckEquals(p.Rest(), "")
		t.CheckOutput(diagnostics)
	}

	// The !command! modifier is used so seldom that pkglint does not
	// check whether the command is actually valid.
	// At least not while parsing the modifier since at this point it might
	// be still unknown which of the commands can be used and which cannot.
	test("${VAR:!command!}", varUse("VAR", "!command!"))

	test("${VAR:!command}", varUse("VAR"),
		"WARN: Makefile:20: Invalid variable modifier \"!command\" for \"VAR\".")

	test("${VAR:command!}", varUse("VAR"),
		"WARN: Makefile:20: Invalid variable modifier \"command!\" for \"VAR\".")

	// The :L modifier makes the variable value "echo hello", and the :[1]
	// modifier extracts the "echo".
	test("${echo hello:L:[1]}", varUse("echo hello", "L", "[1]"))

	// bmake ignores the :[3] modifier, and the :L modifier just returns the
	// variable name, in this case BUILD_DIRS.
	test("${BUILD_DIRS:[3]:L}", varUse("BUILD_DIRS", "[3]", "L"))

	// The :Q at the end is part of the right-hand side of the = modifier.
	// It does not quote anything.
	// See devel/bmake/files/var.c:/^VarGetPattern/.
	test("${VAR:old=new:Q}", varUse("VAR", "old=new:Q"),
		"WARN: Makefile:20: The text \":Q\" looks like a modifier but isn't.")
}

func (s *Suite) Test_MkLexer_varUseModifier(c *check.C) {
	t := s.Init(c)

	p := NewMkLexer("${VAR:R:E:Ox:tA:tW:tw}", nil)

	varUse := p.VarUse()

	t.CheckDeepEquals(
		varUse.modifiers,
		[]MkVarUseModifier{"R", "E", "Ox", "tA", "tW", "tw"})
}

func (s *Suite) Test_MkLexer_varUseModifier__S_parse_error(c *check.C) {
	t := s.Init(c)

	diag := t.NewLine("filename.mk", 123, "")
	p := NewMkLexer("S,}", diag)

	mod := p.varUseModifier("VAR", '}')

	t.CheckEquals(mod, MkVarUseModifier(""))
	// XXX: The "S," has just disappeared.
	t.CheckEquals(p.Rest(), "}")

	t.CheckOutputLines(
		"WARN: filename.mk:123: Invalid variable modifier \"S,\" for \"VAR\".")
}

func (s *Suite) Test_MkLexer_varUseModifier__invalid_ts_modifier_with_warning(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	line := t.NewLine("filename.mk", 123, "${VAR:tsabc}")
	p := NewMkLexer("tsabc}", line)

	modifier := p.varUseModifier("VAR", '}')

	t.CheckEquals(modifier, MkVarUseModifier("tsabc"))
	t.CheckEquals(p.Rest(), "}")
	t.CheckOutputLines(
		"WARN: filename.mk:123: Invalid separator \"abc\" for :ts modifier of \"VAR\".",
		"",
		"\tThe separator for the :ts modifier must be either a single character",
		"\tor an escape sequence like \\t or \\n or an octal or decimal escape",
		"\tsequence; see the bmake man page for further details.",
		"")
}

func (s *Suite) Test_MkLexer_varUseModifier__invalid_ts_modifier_without_warning(c *check.C) {
	t := s.Init(c)

	p := NewMkLexer("tsabc}", nil)

	modifier := p.varUseModifier("VAR", '}')

	t.CheckEquals(modifier, MkVarUseModifier("tsabc"))
	t.CheckEquals(p.Rest(), "}")
}

func (s *Suite) Test_MkLexer_varUseModifier__square_bracket(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename.mk", 123, "\t${VAR:[asdf]}")
	p := NewMkLexer("[asdf]", line)

	modifier := p.varUseModifier("VAR", '}')

	t.CheckEquals(modifier, MkVarUseModifier(""))
	t.CheckEquals(p.Rest(), "")

	t.CheckOutputLines(
		"WARN: filename.mk:123: Invalid variable modifier \"[asdf]\" for \"VAR\".")
}

func (s *Suite) Test_MkLexer_varUseModifier__condition_without_colon(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	line := t.NewLine("filename.mk", 123, "${${VAR}:?yes:no}${${VAR}:?yes}")
	p := NewMkLexer(line.Text, line)

	varUse1 := p.VarUse()
	varUse2 := p.VarUse()

	t.CheckDeepEquals(varUse1, b.VarUse("${VAR}", "?yes:no"))
	t.CheckDeepEquals(varUse2, b.VarUse("${VAR}"))
	t.CheckEquals(p.Rest(), "")

	t.CheckOutputLines(
		"WARN: filename.mk:123: Invalid variable modifier \"?yes\" for \"${VAR}\".")
}

func (s *Suite) Test_MkLexer_varUseModifier__malformed_in_parentheses(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	line := t.NewLine("filename.mk", 123, "$(${VAR}:?yes)")
	p := NewMkLexer(line.Text, line)

	varUse := p.VarUse()

	t.CheckDeepEquals(varUse, b.VarUse("${VAR}"))
	t.CheckEquals(p.Rest(), "")

	t.CheckOutputLines(
		"WARN: filename.mk:123: Invalid variable modifier \"?yes\" for \"${VAR}\".",
		"WARN: filename.mk:123: Please use curly braces {} instead of round parentheses () for ${VAR}.")
}

func (s *Suite) Test_MkLexer_varUseModifier__varuse_in_malformed_modifier(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	line := t.NewLine("filename.mk", 123, "${${VAR}:?yes${INNER}}")
	p := NewMkLexer(line.Text, line)

	varUse := p.VarUse()

	t.CheckDeepEquals(varUse, b.VarUse("${VAR}"))
	t.CheckEquals(p.Rest(), "")

	t.CheckOutputLines(
		"WARN: filename.mk:123: Invalid variable modifier \"?yes${INNER}\" for \"${VAR}\".")
}

func (s *Suite) Test_MkLexer_varUseModifier__eq_suffix_replacement(c *check.C) {
	t := s.Init(c)

	test := func(input string, modifier MkVarUseModifier, rest string, diagnostics ...string) {
		line := t.NewLine("filename.mk", 123, "")
		p := NewMkLexer(input, line)

		actual := p.varUseModifier("VARNAME", '}')

		t.CheckDeepEquals(actual, modifier)
		t.CheckEquals(p.Rest(), rest)
		t.CheckOutput(diagnostics)
	}

	test("%.c=%.o", "%.c=%.o", "")
	test("%\\:c=%.o", "%\\:c=%.o", "", // XXX: maybe someday remove the escaping.
		"WARN: filename.mk:123: The text \":c=%.o\" looks like a modifier but isn't.")
	test("%\\:c=%.o", "%\\:c=%.o", "", // XXX: maybe someday remove the escaping.
		"WARN: filename.mk:123: The text \":c=%.o\" looks like a modifier but isn't.")

	// The backslashes are only removed before parentheses,
	// braces and colons; see devel/bmake/files/var.c:/^VarGetPattern/
	test(".\\a\\b\\c=.abc", ".\\a\\b\\c=.abc", "")

	// See devel/bmake/files/var.c:/^#define IS_A_MATCH/.
	test("%.c=%.o:rest", "%.c=%.o:rest", "",
		"WARN: filename.mk:123: The text \":rest\" looks like a modifier but isn't.")
	test("\\}\\\\\\$=", "\\}\\\\\\$=", "")
	// XXX: maybe someday test("\\}\\\\\\$=", "}\\$=", "")
	test("=\\}\\\\\\$\\&", "=\\}\\\\\\$\\&", "")
	// XXX: maybe someday test("=\\}\\\\\\$\\&", "=}\\$&", "")

	// The colon in the nested variable expression does not count as
	// a separator for parsing the outer modifier.
	test("=${VAR:D/}}", "=${VAR:D/}", "}")
}

func (s *Suite) Test_MkLexer_varUseModifier__assigment(c *check.C) {
	t := s.Init(c)

	test := func(varname, input string, modifier MkVarUseModifier, rest string, diagnostics ...string) {
		line := t.NewLine("filename.mk", 123, "")
		p := NewMkLexer(input, line)

		actual := p.varUseModifier(varname, '}')

		t.CheckDeepEquals(actual, modifier)
		t.CheckEquals(p.Rest(), rest)
		t.CheckOutput(diagnostics)
	}

	test("VAR", ":!=${OTHER}:rest", ":!=${OTHER}", ":rest",
		"ERROR: filename.mk:123: "+
			"Assignment modifiers like \":!=\" must not be used at all.")
	test("VAR", ":=${OTHER}:rest", ":=${OTHER}", ":rest",
		"ERROR: filename.mk:123: "+
			"Assignment modifiers like \":=\" must not be used at all.")
	test("VAR", ":+=${OTHER}:rest", ":+=${OTHER}", ":rest",
		"ERROR: filename.mk:123: "+
			"Assignment modifiers like \":+=\" must not be used at all.")
	test("VAR", ":?=${OTHER}:rest", ":?=${OTHER}", ":rest",
		"ERROR: filename.mk:123: "+
			"Assignment modifiers like \":?=\" must not be used at all.")

	// This one is not treated as an assignment operator since at this
	// point the operators := and = are equivalent. There is no special
	// parsing code for this case, therefore it falls back to the SysV
	// interpretation of the :from=to modifier, which consumes all the
	// remaining text.
	//
	// See devel/bmake/files/var.c:/tstr\[2\] == '='/.
	test("VAR", "::=${OTHER}:rest", "::=${OTHER}:rest", "",
		"WARN: filename.mk:123: The text \"::=${OTHER}:rest\" "+
			"looks like a modifier but isn't.")

	test("", ":=value", ":=value", "",
		"ERROR: filename.mk:123: "+
			"Assignment to the empty variable is not possible.",
		"WARN: filename.mk:123: The text \":=value\" "+
			"looks like a modifier but isn't.")
}

func (s *Suite) Test_MkLexer_varUseModifierTs(c *check.C) {
	t := s.Init(c)

	test := func(input string, closing byte, mod MkVarUseModifier, rest string, diagnostics ...string) {
		diag := t.NewLine("filename.mk", 123, "")
		lex := NewMkLexer(input, diag)
		mark := lex.lexer.Mark()
		alnum := lex.lexer.NextBytesSet(textproc.Alnum)

		actualMod := lex.varUseModifierTs(alnum, closing, lex.lexer, "VAR", mark)

		t.CheckDeepEquals(
			[]interface{}{actualMod, lex.Rest()},
			[]interface{}{mod, rest})
		t.CheckOutput(diagnostics)
	}

	// The separator character can be left out, which means empty.
	test("ts}", '}',
		"ts", "}",
		nil...)

	// The separator character can be a long octal number.
	test("ts\\000012}", '}',
		"ts\\000012", "}",
		nil...)

	// Or even decimal.
	test("ts\\124}", '}',
		"ts\\124", "}",
		nil...)

	// The :ts modifier only takes single-character separators.
	test("ts---}", '}',
		"ts---", "}",
		"WARN: filename.mk:123: Invalid separator \"---\" for :ts modifier of \"VAR\".")

	// Using a colon as separator looks a bit strange but works.
	// The first colon is the separator, the second one starts the :Q.
	test("ts::Q}", '}',
		"ts:", ":Q}",
		nil...)
}

func (s *Suite) Test_MkLexer_varUseModifierMatch(c *check.C) {
	t := s.Init(c)

	testClosing := func(input string, closing byte, modifier MkVarUseModifier, rest string, diagnostics ...string) {
		line := t.NewLine("filename.mk", 123, "")
		p := NewMkLexer(input, line)

		actual := p.varUseModifier("VARNAME", closing)

		t.CheckDeepEquals(actual, modifier)
		t.CheckEquals(p.Rest(), rest)
		t.CheckOutput(diagnostics)
	}

	test := func(input string, modifier MkVarUseModifier, rest string, diagnostics ...string) {
		testClosing(input, '}', modifier, rest, diagnostics...)
	}
	testParen := func(input string, modifier MkVarUseModifier, rest string, diagnostics ...string) {
		testClosing(input, ')', modifier, rest, diagnostics...)
	}

	// Backslashes are removed only for : and the closing character.
	test("M\\(\\{\\}\\)\\::rest", "M\\(\\{}\\):", ":rest")

	// But not before other backslashes.
	// Therefore, the first backslash does not escape the second.
	// The second backslash doesn't have an effect either,
	// since the parenthesis is just an ordinary character here.
	test("M\\\\(:nested):rest", "M\\\\(:nested)", ":rest")

	// If the variable uses parentheses instead of braces,
	// the opening parenthesis is escaped by the second backslash
	// and thus doesn't increase the nesting level.
	// Nevertheless it is not unescaped. This is probably a bug in bmake.
	testParen("M\\\\(:rest", "M\\\\(", ":rest")
	testParen("M(:nested):rest", "M(:nested)", ":rest")

	test("Mpattern", "Mpattern", "")
	test("Mpattern}closed", "Mpattern", "}closed")
	test("Mpattern:rest", "Mpattern", ":rest")

	test("M{{{}}}}", "M{{{}}}", "}")

	// See devel/bmake/files/var.c:/== '\('/.
	test("M(}}", "M(}", "}")
}

// See src/usr.bin/make/unit-tests/varmod-edge.mk 1.4.
//
// The difference between this test and the bmake unit test is that in
// this test the pattern is visible, while in the bmake test it is hidden
// and can only be made visible by adding a fprintf to Str_Match or by
// carefully analyzing the result of Str_Match, which removes another level
// of backslashes.
func (s *Suite) Test_MkLexer_varUseModifierMatch__varmod_edge(c *check.C) {
	t := s.Init(c)

	test := func(input string, modifier MkVarUseModifier, rest string, diagnostics ...string) {
		line := t.NewLine("filename.mk", 123, "")
		p := NewMkLexer(input, line)

		actual := p.varUseModifier("VARNAME", '}')

		t.CheckDeepEquals(actual, modifier)
		t.CheckEquals(p.Rest(), rest)
		t.CheckOutput(diagnostics)
	}

	// M-paren
	test("M(*)}", "M(*)", "}")

	// M-mixed
	test("M(*}}", "M(*}", "}")

	// M-nest-mix
	test("M${:U*)}}", "M${:U*)", "}}")

	// M-nest-brk
	test("M${:U[[[[[]}}", "M${:U[[[[[]}", "}")

	// M-pat-err
	// TODO: Warn about the malformed pattern, since bmake doesn't.
	//  See devel/bmake/files/str.c:/^Str_Match/.
	test("M${:U[[}}", "M${:U[[}", "}")

	// M-bsbs
	test("M\\\\(}}", "M\\\\(}", "}")

	// M-bs1-par
	test("M\\(:M*}}", "M\\(:M*}", "}")

	// M-bs2-par
	test("M\\\\(:M*}}", "M\\\\(:M*}", "}")
}

func (s *Suite) Test_MkLexer_varUseModifierSubst(c *check.C) {
	t := s.Init(c)

	test := func(mod string, regex bool, from, to, options, rest string, diagnostics ...string) {
		line := t.NewLine("Makefile", 20, "")
		p := NewMkLexer(mod, line)

		ok, actualRegex, actualFrom, actualTo, actualOptions := p.varUseModifierSubst('}')

		t.CheckDeepEquals(
			[]interface{}{ok, actualRegex, actualFrom, actualTo, actualOptions, p.Rest()},
			[]interface{}{true, regex, from, to, options, rest})
		t.CheckOutput(diagnostics)
	}

	testFail := func(mod, rest string, diagnostics ...string) {
		line := t.NewLine("Makefile", 20, "")
		p := NewMkLexer(mod, line)

		ok, regex, from, to, options := p.varUseModifierSubst('}')
		if !ok {
			return
		}
		t.CheckDeepEquals(
			[]interface{}{ok, regex, from, to, options, p.Rest()},
			[]interface{}{false, false, "", "", "", rest})
		t.CheckOutput(diagnostics)
	}

	testFail("S", "S",
		nil...)

	testFail("S}", "S}",
		nil...)

	testFail("S,}", "S,}",
		"WARN: Makefile:20: Invalid variable modifier \"S,\" for \"VAR\".")

	testFail("S,from,to}", "",
		"WARN: Makefile:20: Invalid variable modifier \"S,from,to\" for \"VAR\".")

	// Up to 2019-12-05, these were considered valid substitutions,
	// having [ as the separator and ss] as the rest.
	testFail("M[Y][eE][sS]", "M[Y][eE][sS]",
		nil...)
	testFail("N[Y][eE][sS]", "M[Y][eE][sS]",
		nil...)

	test("S,from,to,}", false, "from", "to", "", "}")

	test("S,^from$,to,}", false, "^from$", "to", "", "}")

	test("S,@F@,${F},}", false, "@F@", "${F}", "", "}")

	test("S,from,to,1}", false, "from", "to", "1", "}")
	test("S,from,to,g}", false, "from", "to", "g", "}")
	test("S,from,to,W}", false, "from", "to", "W", "}")

	test("S,from,to,1gW}", false, "from", "to", "1gW", "}")

	// Inside the :S or :C modifiers, neither a colon nor the closing
	// brace need to be escaped. Otherwise these patterns would become
	// too difficult to read and write.
	test("C/[[:alnum:]]{2}/**/g}", true, "[[:alnum:]]{2}", "**", "g", "}")

	// Some pkgsrc users really explore the darkest corners of bmake by using
	// the backslash as the separator in the :S modifier. Sure, it works, it
	// just looks totally unexpected to the average pkgsrc reader.
	//
	// Using the backslash as separator means that it cannot be used for anything
	// else, not even for escaping other characters.
	test("S\\.post1\\\\1}", false, ".post1", "", "1", "}")
}

func (s *Suite) Test_MkLexer_varUseModifierAt__missing_at_after_variable_name(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	line := t.NewLine("filename.mk", 123, "${VAR:@varname}")
	p := NewMkLexer(line.Text, line)

	varUse := p.VarUse()

	t.CheckDeepEquals(varUse, b.VarUse("VAR"))
	t.CheckEquals(p.Rest(), "")
	t.CheckOutputLines(
		"WARN: filename.mk:123: Invalid variable modifier \"@varname\" for \"VAR\".")
}

func (s *Suite) Test_MkLexer_varUseModifierAt__dollar(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	line := t.NewLine("filename.mk", 123, "${VAR:@var@$$var@}")
	p := NewMkLexer(line.Text, line)

	varUse := p.VarUse()

	t.CheckDeepEquals(varUse, b.VarUse("VAR", "@var@$$var@"))
	t.CheckEquals(p.Rest(), "")
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLexer_varUseModifierAt__incomplete_without_warning(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	p := NewMkLexer("${VAR:@var@$$var}rest", nil)

	varUse := p.VarUse()

	t.CheckDeepEquals(varUse, b.VarUse("VAR", "@var@$$var}rest"))
	t.CheckEquals(p.Rest(), "")
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLexer_varUseModifierAt(c *check.C) {
	t := s.Init(c)

	varUse := NewMkTokenBuilder().VarUse
	test := func(text string, varUse *MkVarUse, rest string, diagnostics ...string) {
		line := t.NewLine("Makefile", 20, "\t"+text)
		p := NewMkLexer(text, line)

		actual := p.VarUse()

		t.CheckDeepEquals(actual, varUse)
		t.CheckEquals(p.Rest(), rest)
		t.CheckOutput(diagnostics)
	}

	test("${VAR:@",
		varUse("VAR"),
		"",
		"WARN: Makefile:20: Invalid variable modifier \"@\" for \"VAR\".",
		"WARN: Makefile:20: Missing closing \"}\" for \"VAR\".")

	test("${VAR:@i@${i}}", varUse("VAR", "@i@${i}}"), "",
		"WARN: Makefile:20: Modifier ${VAR:@i@...@} is missing the final \"@\".",
		"WARN: Makefile:20: Missing closing \"}\" for \"VAR\".")

	test("${VAR:@i@${i}@}", varUse("VAR", "@i@${i}@"), "")

	test("${PKG_GROUPS:@g@${g:Q}:${PKG_GID.${g}:Q}@:C/:*$//g}",
		varUse("PKG_GROUPS", "@g@${g:Q}:${PKG_GID.${g}:Q}@", "C/:*$//g"),
		"")
}

func (s *Suite) Test_MkLexer_varUseAlnum(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")

	test := func(input, varname, rest string, diagnostics ...string) {
		lex := NewMkLexer(input, t.NewLine("filename.mk", 123, ""))

		use := lex.varUseAlnum()

		t.CheckDeepEquals(use, NewMkVarUse(varname))
		t.CheckEquals(lex.Rest(), rest)
		t.CheckOutput(diagnostics)
	}

	test("$Varname:rest",
		"V", "arname:rest",

		"ERROR: filename.mk:123: $Varname is ambiguous. "+
			"Use ${Varname} if you mean a Make variable "+
			"or $$Varname if you mean a shell variable.",
		"",
		"\tOnly the first letter after the dollar is the variable name.",
		"\tEverything following it is normal text, even if it looks like a",
		"\tvariable name to human readers.",
		"")

	test("$X:rest",
		"X", ":rest",

		"WARN: filename.mk:123: $X is ambiguous. "+
			"Use ${X} if you mean a Make variable "+
			"or $$X if you mean a shell variable.",
		"",
		"\tIn its current form, this variable is parsed as a Make variable. For",
		"\thuman readers though, $x looks more like a shell variable than a",
		"\tMake variable, since Make variables are usually written using braces",
		"\t(BSD-style) or parentheses (GNU-style).",
		"")
}

func (s *Suite) Test_MkLexer_EOF(c *check.C) {
	t := s.Init(c)

	test := func(input string, eof bool) {
		lex := NewMkLexer(input, nil)
		t.CheckEquals(lex.EOF(), eof)
	}

	test("", true)
	test("x", false)
	test("$$", false)
	test("${VAR}", false)
}

func (s *Suite) Test_MkLexer_Rest(c *check.C) {
	t := s.Init(c)

	test := func(input, str, rest string) {
		lex := NewMkLexer(input, nil)

		lex.lexer.NextString(str)

		t.CheckEquals(lex.Rest(), rest)
	}

	test("", "", "")
	test("x", "", "x")
	test("x", "x", "")
	test("$$", "", "$$")
	test("${VAR}rest", "${VAR}", "rest")
}

func (s *Suite) Test_MkLexer_Errorf(c *check.C) {
	t := s.Init(c)

	test := func(diag Autofixer, diagnostics ...string) {
		lex := NewMkLexer("", diag)
		lex.Errorf("Must %q.", "arg")
		t.CheckOutput(diagnostics)
	}

	test(
		nil,

		nil...)

	test(
		t.NewLine("filename.mk", 123, ""),

		"ERROR: filename.mk:123: Must \"arg\".")
}

func (s *Suite) Test_MkLexer_Warnf(c *check.C) {
	t := s.Init(c)

	test := func(diag Autofixer, diagnostics ...string) {
		lex := NewMkLexer("", diag)
		lex.Warnf("Should %q.", "arg")
		t.CheckOutput(diagnostics)
	}

	test(
		nil,

		nil...)

	test(
		t.NewLine("filename.mk", 123, ""),

		"WARN: filename.mk:123: Should \"arg\".")
}

func (s *Suite) Test_MkLexer_Notef(c *check.C) {
	t := s.Init(c)

	test := func(diag Autofixer, diagnostics ...string) {
		lex := NewMkLexer("", diag)
		lex.Notef("Can %q.", "arg")
		t.CheckOutput(diagnostics)
	}

	test(
		nil,

		nil...)

	test(
		t.NewLine("filename.mk", 123, ""),

		"NOTE: filename.mk:123: Can \"arg\".")
}

func (s *Suite) Test_MkLexer_Explain(c *check.C) {
	t := s.Init(c)

	test := func(option string, diag Autofixer, diagnostics ...string) {
		t.SetUpCommandLine(option)
		lex := NewMkLexer("", diag)
		lex.Warnf("Should %q.", "arg")

		lex.Explain(
			"Explanation.")

		t.CheckOutput(diagnostics)
	}

	test(
		"--explain",
		nil,

		nil...)

	test(
		"--explain=no",
		nil,

		nil...)

	test(
		"--explain",
		t.NewLine("filename.mk", 123, ""),

		"WARN: filename.mk:123: Should \"arg\".",
		"",
		"\tExplanation.",
		"")

	test(
		"--explain=no",
		t.NewLine("filename.mk", 123, ""),

		"WARN: filename.mk:123: Should \"arg\".")
}

func (s *Suite) Test_MkLexer_Autofix(c *check.C) {
	t := s.Init(c)

	test := func(autofix bool) {
		mklines := t.SetUpFileMkLines("filename.mk",
			"# before")
		lex := NewMkLexer("", mklines.lines.Lines[0])

		fix := lex.Autofix()
		fix.Warnf("Warning.")
		fix.Replace("before", "after")
		fix.Apply()
	}

	t.ExpectDiagnosticsAutofix(
		test,
		"WARN: ~/filename.mk:1: Warning.",
		"AUTOFIX: ~/filename.mk:1: Replacing \"before\" with \"after\".")
}

func (s *Suite) Test_MkLexer_Autofix__nil(c *check.C) {
	t := s.Init(c)

	t.ExpectPanicMatches(
		func() { NewMkLexer("", nil).Autofix() },
		`^runtime error: invalid memory address or nil pointer dereference`)
}

func (s *Suite) Test_MkLexer_HasDiag(c *check.C) {
	t := s.Init(c)

	test := func(diag Autofixer, hasDiag bool) {
		t.CheckEquals(NewMkLexer("", diag).HasDiag(), hasDiag)
	}

	test(nil, false)
	test(t.NewLine("filename", 123, ""), true)
}
