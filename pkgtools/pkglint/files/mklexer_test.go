package pkglint

import "gopkg.in/check.v1"

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

func (s *Suite) Test_MkLexer_VarUse(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()
	varuse := b.VaruseToken
	varuseText := b.VaruseTextToken

	testRest := func(input string, expectedTokens []*MkToken, expectedRest string, diagnostics ...string) {
		line := t.NewLines("Test_MkLexer_VarUse.mk", input).Lines[0]
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
		t.CheckOutput(diagnostics)
	}
	test := func(input string, expectedToken *MkToken, diagnostics ...string) {
		testRest(input, b.Tokens(expectedToken), "", diagnostics...)
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

	// TODO: Does the $@ refer to ${.TARGET}, or is it just an unmatchable
	//  regular expression?
	test("${PKGNAME:C/$@/target?/}",
		varuse("PKGNAME", "C/$@/target?/"))

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

	// The separator character can be left out, which means empty.
	test("${VAR:ts}",
		varuse("VAR", "ts"))

	// The separator character can be a long octal number.
	test("${VAR:ts\\000012}",
		varuse("VAR", "ts\\000012"))

	// Or even decimal.
	test("${VAR:ts\\124}",
		varuse("VAR", "ts\\124"))

	// The :ts modifier only takes single-character separators.
	test("${VAR:ts---}",
		varuse("VAR", "ts---"),
		"WARN: Test_MkLexer_VarUse.mk:1: Invalid separator \"---\" for :ts modifier of \"VAR\".")

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
}

func (s *Suite) Test_MkLexer_VarUse__ambiguous(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	t.SetUpCommandLine("--explain")

	line := t.NewLine("module.mk", 123, "\t$Varname $X")
	p := NewMkLexer(line.Text[1:], line)

	tokens, rest := p.MkTokens()
	t.CheckDeepEquals(tokens, b.Tokens(
		b.VaruseTextToken("$V", "V"),
		b.TextToken("arname "),
		b.VaruseTextToken("$X", "X")))
	t.CheckEquals(rest, "")

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

// Pkglint can replace $(VAR) with ${VAR}. It doesn't look at all components
// of nested variables though because this case is not important enough to
// invest much development time. It occurs so seldom that it is acceptable
// to run pkglint multiple times in such a case.
func (s *Suite) Test_MkLexer_varUseBrace__autofix_parentheses(c *check.C) {
	t := s.Init(c)

	test := func() {
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

	test("${PATH:ts::Q}", varUse("PATH", "ts:", "Q"))
}

func (s *Suite) Test_MkLexer_varUseModifier__invalid_ts_modifier_with_warning(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	line := t.NewLine("filename.mk", 123, "${VAR:tsabc}")
	p := NewMkLexer("tsabc}", line)

	modifier := p.varUseModifier("VAR", '}')

	t.CheckEquals(modifier, "tsabc")
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

	t.CheckEquals(modifier, "tsabc")
	t.CheckEquals(p.Rest(), "}")
}

func (s *Suite) Test_MkLexer_varUseModifier__square_bracket(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename.mk", 123, "\t${VAR:[asdf]}")
	p := NewMkLexer("[asdf]", line)

	modifier := p.varUseModifier("VAR", '}')

	t.CheckEquals(modifier, "")
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

func (s *Suite) Test_MkLexer_varUseModifierSubst(c *check.C) {
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

	test("${VAR:S", varUse("VAR"), "",
		"WARN: Makefile:20: Invalid variable modifier \"S\" for \"VAR\".",
		"WARN: Makefile:20: Missing closing \"}\" for \"VAR\".")

	test("${VAR:S}", varUse("VAR"), "",
		"WARN: Makefile:20: Invalid variable modifier \"S\" for \"VAR\".")

	test("${VAR:S,}", varUse("VAR"), "",
		"WARN: Makefile:20: Invalid variable modifier \"S,\" for \"VAR\".")

	test("${VAR:S,from,to}", varUse("VAR"), "",
		"WARN: Makefile:20: Invalid variable modifier \"S,from,to\" for \"VAR\".")

	test("${VAR:S,from,to,}", varUse("VAR", "S,from,to,"), "")

	test("${VAR:S,^from$,to,}", varUse("VAR", "S,^from$,to,"), "")

	test("${VAR:S,@F@,${F},}", varUse("VAR", "S,@F@,${F},"), "")

	test("${VAR:S,from,to,1}", varUse("VAR", "S,from,to,1"), "")
	test("${VAR:S,from,to,g}", varUse("VAR", "S,from,to,g"), "")
	test("${VAR:S,from,to,W}", varUse("VAR", "S,from,to,W"), "")

	test("${VAR:S,from,to,1gW}", varUse("VAR", "S,from,to,1gW"), "")

	// Inside the :S or :C modifiers, neither a colon nor the closing
	// brace need to be escaped. Otherwise these patterns would become
	// too difficult to read and write.
	test("${VAR:C/[[:alnum:]]{2}/**/g}",
		varUse("VAR", "C/[[:alnum:]]{2}/**/g"),
		"")

	// Some pkgsrc users really explore the darkest corners of bmake by using
	// the backslash as the separator in the :S modifier. Sure, it works, it
	// just looks totally unexpected to the average pkgsrc reader.
	//
	// Using the backslash as separator means that it cannot be used for anything
	// else, not even for escaping other characters.
	test("${VAR:S\\.post1\\\\1}",
		varUse("VAR", "S\\.post1\\\\1"),
		"")
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
