package pkglint

import (
	"gopkg.in/check.v1"
	"strings"
)

func (s *Suite) Test_NewMkParser__invalid_arguments(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename.mk", 123, "")

	t.ExpectAssert(func() { NewMkParser(line, "", false) })
	t.ExpectAssert(func() { NewMkParser(nil, "", true) })
}

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

	testRest("${VAR:S,a,b,c,d,e,f}",
		[]*MkToken{{
			Text:   "${VAR:S,a,b,c,d,e,f}",
			Varuse: NewMkVarUse("VAR", "S,a,b,")}},
		"")
	t.CheckOutputLines(
		"WARN: Test_MkParser_MkTokens.mk:1: Invalid variable modifier \"c,d,e,f\" for \"VAR\".")

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

	testRest := func(input string, expectedTokens []*MkToken, expectedRest string, diagnostics ...string) {
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
		t.CheckOutput(diagnostics)
	}
	tokens := func(tokens ...*MkToken) []*MkToken { return tokens }
	test := func(input string, expectedToken *MkToken, diagnostics ...string) {
		testRest(input, []*MkToken{expectedToken}, "", diagnostics...)
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

	t.Use(testRest, tokens, test, varuse, varuseText)

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
		"WARN: Test_MkParser_VarUse.mk:1: Invalid variable modifier \"[asdf]\" for \"GZIP_CMD\".")

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
		"WARN: Test_MkParser_VarUse.mk:1: Invalid separator \"---\" for :ts modifier of \"VAR\".")

	test("$<",
		varuseText("$<", "<")) // Same as ${.IMPSRC}

	test("$(GNUSTEP_USER_ROOT)",
		varuseText("$(GNUSTEP_USER_ROOT)", "GNUSTEP_USER_ROOT"),
		"WARN: Test_MkParser_VarUse.mk:1: Please use curly braces {} instead of round parentheses () for GNUSTEP_USER_ROOT.")

	// Opening brace, closing parenthesis.
	// Warnings are only printed for balanced expressions.
	test("${VAR)",
		varuseText("${VAR)", "VAR)"),
		"WARN: Test_MkParser_VarUse.mk:1: Missing closing \"}\" for \"VAR)\".",
		"WARN: Test_MkParser_VarUse.mk:1: Invalid part \")\" after variable name \"VAR\".")

	// Opening parenthesis, closing brace
	// Warnings are only printed for balanced expressions.
	test("$(VAR}",
		varuseText("$(VAR}", "VAR}"),
		"WARN: Test_MkParser_VarUse.mk:1: Missing closing \")\" for \"VAR}\".",
		"WARN: Test_MkParser_VarUse.mk:1: Invalid part \"}\" after variable name \"VAR\".")

	test("${PLIST_SUBST_VARS:@var@${var}=${${var}:Q}@}",
		varuse("PLIST_SUBST_VARS", "@var@${var}=${${var}:Q}@"))

	test("${PLIST_SUBST_VARS:@var@${var}=${${var}:Q}}",
		varuseText("${PLIST_SUBST_VARS:@var@${var}=${${var}:Q}}",
			"PLIST_SUBST_VARS", "@var@${var}=${${var}:Q}}"),
		"WARN: Test_MkParser_VarUse.mk:1: Modifier ${PLIST_SUBST_VARS:@var@...@} is missing the final \"@\".",
		"WARN: Test_MkParser_VarUse.mk:1: Missing closing \"}\" for \"PLIST_SUBST_VARS\".")

	// Unfinished variable use
	test("${",
		varuseText("${", ""),
		"WARN: Test_MkParser_VarUse.mk:1: Missing closing \"}\" for \"\".")

	// Unfinished nested variable use
	test("${${",
		varuseText("${${", "${"),
		"WARN: Test_MkParser_VarUse.mk:1: Missing closing \"}\" for \"\".",
		"WARN: Test_MkParser_VarUse.mk:1: Missing closing \"}\" for \"${\".")
}

func (s *Suite) Test_MkParser_varUseModifier__invalid_ts_modifier_with_warning(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	line := t.NewLine("filename.mk", 123, "${VAR:tsabc}")
	p := NewMkParser(line, "tsabc}", true)

	modifier := p.varUseModifier("VAR", '}')

	t.Check(modifier, equals, "tsabc")
	t.Check(p.Rest(), equals, "}")
	t.CheckOutputLines(
		"WARN: filename.mk:123: Invalid separator \"abc\" for :ts modifier of \"VAR\".",
		"",
		"\tThe separator for the :ts modifier must be either a single character",
		"\tor an escape sequence like \\t or \\n or an octal or decimal escape",
		"\tsequence; see the bmake man page for further details.",
		"")
}

func (s *Suite) Test_MkParser_varUseModifier__invalid_ts_modifier_without_warning(c *check.C) {
	t := s.Init(c)

	p := NewMkParser(nil, "tsabc}", false)

	modifier := p.varUseModifier("VAR", '}')

	t.Check(modifier, equals, "tsabc")
	t.Check(p.Rest(), equals, "}")
}

func (s *Suite) Test_MkParser_varUseModifier__square_bracket(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename.mk", 123, "\t${VAR:[asdf]}")
	p := NewMkParser(line, "[asdf]", true)

	modifier := p.varUseModifier("VAR", '}')

	t.Check(modifier, equals, "")
	t.Check(p.Rest(), equals, "")

	t.CheckOutputLines(
		"WARN: filename.mk:123: Invalid variable modifier \"[asdf]\" for \"VAR\".")
}

func (s *Suite) Test_MkParser_varUseModifier__condition_without_colon(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename.mk", 123, "${${VAR}:?yes:no}${${VAR}:?yes}")
	p := NewMkParser(line, line.Text, true)

	varUse1 := p.VarUse()
	varUse2 := p.VarUse()

	t.Check(varUse1, deepEquals, NewMkVarUse("${VAR}", "?yes:no"))
	t.Check(varUse2, deepEquals, NewMkVarUse("${VAR}"))
	t.Check(p.Rest(), equals, "")

	t.CheckOutputLines(
		"WARN: filename.mk:123: Invalid variable modifier \"?yes\" for \"${VAR}\".")
}

func (s *Suite) Test_MkParser_varUseModifier__malformed_in_parentheses(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename.mk", 123, "$(${VAR}:?yes)")
	p := NewMkParser(line, line.Text, true)

	varUse := p.VarUse()

	t.Check(varUse, deepEquals, NewMkVarUse("${VAR}"))
	t.Check(p.Rest(), equals, "")

	t.CheckOutputLines(
		"WARN: filename.mk:123: Invalid variable modifier \"?yes\" for \"${VAR}\".",
		"WARN: filename.mk:123: Please use curly braces {} instead of round parentheses () for ${VAR}.")
}

func (s *Suite) Test_MkParser_varUseModifier__varuse_in_malformed_modifier(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename.mk", 123, "${${VAR}:?yes${INNER}}")
	p := NewMkParser(line, line.Text, true)

	varUse := p.VarUse()

	t.Check(varUse, deepEquals, NewMkVarUse("${VAR}"))
	t.Check(p.Rest(), equals, "")

	t.CheckOutputLines(
		"WARN: filename.mk:123: Invalid variable modifier \"?yes${INNER}\" for \"${VAR}\".")
}

func (s *Suite) Test_MkParser_varUseModifierAt__missing_at_after_variable_name(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename.mk", 123, "${VAR:@varname}")
	p := NewMkParser(line, line.Text, true)

	varUse := p.VarUse()

	t.Check(varUse, deepEquals, NewMkVarUse("VAR"))
	t.Check(p.Rest(), equals, "")
	t.CheckOutputLines(
		"WARN: filename.mk:123: Invalid variable modifier \"@varname\" for \"VAR\".")
}

func (s *Suite) Test_MkParser_varUseModifierAt__dollar(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename.mk", 123, "${VAR:@var@$$var@}")
	p := NewMkParser(line, line.Text, true)

	varUse := p.VarUse()

	t.Check(varUse, deepEquals, NewMkVarUse("VAR", "@var@$$var@"))
	t.Check(p.Rest(), equals, "")
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkParser_varUseModifierAt__incomplete_without_warning(c *check.C) {
	t := s.Init(c)

	p := NewMkParser(nil, "${VAR:@var@$$var}rest", false)

	varUse := p.VarUse()

	// TODO: It's inconsistent that this syntax error still produces a
	//  variable modifier, while most other syntax errors don't.
	// FIXME: The } must not be part of the variable modifier.
	t.Check(varUse, deepEquals, NewMkVarUse("VAR", "@var@$$var}rest"))
	t.Check(p.Rest(), equals, "")
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkParser_VarUse__ambiguous(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--explain")

	line := t.NewLine("module.mk", 123, "\t$Varname $X")
	p := NewMkParser(line, line.Text[1:], true)

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
	t := s.Init(c)

	testRest := func(input string, expectedTree *MkCond, expectedRest string) {
		p := NewMkParser(nil, input, false)
		actualTree := p.MkCond()
		c.Check(actualTree, deepEquals, expectedTree)
		c.Check(p.Rest(), equals, expectedRest)
	}
	test := func(input string, expectedTree *MkCond) {
		testRest(input, expectedTree, "")
	}
	varuse := NewMkVarUse

	t.Use(testRest, test, varuse)

	test("${OPSYS:MNetBSD}",
		&MkCond{Var: varuse("OPSYS", "MNetBSD")})

	test("defined(VARNAME)",
		&MkCond{Defined: "VARNAME"})

	test("empty(VARNAME)",
		&MkCond{Empty: varuse("VARNAME")})

	test("!empty(VARNAME)",
		&MkCond{Not: &MkCond{Empty: varuse("VARNAME")}})

	test("!empty(VARNAME:M[yY][eE][sS])",
		&MkCond{Not: &MkCond{Empty: varuse("VARNAME", "M[yY][eE][sS]")}})

	// Colons are unescaped at this point because they cannot be mistaken for separators anymore.
	test("!empty(USE_TOOLS:Mautoconf\\:run)",
		&MkCond{Not: &MkCond{Empty: varuse("USE_TOOLS", "Mautoconf:run")}})

	test("${VARNAME} != \"Value\"",
		&MkCond{CompareVarStr: &MkCondCompareVarStr{varuse("VARNAME"), "!=", "Value"}})

	test("${VARNAME:Mi386} != \"Value\"",
		&MkCond{CompareVarStr: &MkCondCompareVarStr{varuse("VARNAME", "Mi386"), "!=", "Value"}})

	test("${VARNAME} != Value",
		&MkCond{CompareVarStr: &MkCondCompareVarStr{varuse("VARNAME"), "!=", "Value"}})

	test("\"${VARNAME}\" != Value",
		&MkCond{CompareVarStr: &MkCondCompareVarStr{varuse("VARNAME"), "!=", "Value"}})

	test("${pkg} == \"${name}\"",
		&MkCond{CompareVarVar: &MkCondCompareVarVar{varuse("pkg"), "==", varuse("name")}})

	test("\"${pkg}\" == \"${name}\"",
		&MkCond{CompareVarVar: &MkCondCompareVarVar{varuse("pkg"), "==", varuse("name")}})

	// The right-hand side is not analyzed further to keep the data types simple.
	test("${ABC} == \"${A}B${C}\"",
		&MkCond{CompareVarStr: &MkCondCompareVarStr{varuse("ABC"), "==", "${A}B${C}"}})

	test("${ABC} == \"${A}\\\"${B}\\\\${C}$${shellvar}${D}\"",
		&MkCond{CompareVarStr: &MkCondCompareVarStr{varuse("ABC"), "==", "${A}\"${B}\\${C}$${shellvar}${D}"}})

	test("exists(/etc/hosts)",
		&MkCond{Call: &MkCondCall{"exists", "/etc/hosts"}})

	test("exists(${PREFIX}/var)",
		&MkCond{Call: &MkCondCall{"exists", "${PREFIX}/var"}})

	test("${OPSYS} == \"NetBSD\" || ${OPSYS} == \"OpenBSD\"",
		&MkCond{Or: []*MkCond{
			{CompareVarStr: &MkCondCompareVarStr{varuse("OPSYS"), "==", "NetBSD"}},
			{CompareVarStr: &MkCondCompareVarStr{varuse("OPSYS"), "==", "OpenBSD"}}}})

	test("${OPSYS} == \"NetBSD\" && ${MACHINE_ARCH} == \"i386\"",
		&MkCond{And: []*MkCond{
			{CompareVarStr: &MkCondCompareVarStr{varuse("OPSYS"), "==", "NetBSD"}},
			{CompareVarStr: &MkCondCompareVarStr{varuse("MACHINE_ARCH"), "==", "i386"}}}})

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
			{Var: varuse("MACHINE_ARCH", "Mi386")},
			{Var: varuse("MACHINE_OPSYS", "MNetBSD")}}})

	test("${VAR} == \"${VAR}suffix\"",
		&MkCond{CompareVarStr: &MkCondCompareVarStr{varuse("VAR"), "==", "${VAR}suffix"}})

	// Exotic cases

	// ".if 0" can be used to skip over a block of code.
	test("0",
		&MkCond{Num: "0"})

	test("0xCAFEBABE",
		&MkCond{Num: "0xCAFEBABE"})

	test("${VAR} == 0xCAFEBABE",
		&MkCond{
			CompareVarNum: &MkCondCompareVarNum{
				Var: varuse("VAR"),
				Op:  "==",
				Num: "0xCAFEBABE"}})

	test("! ( defined(A)  && empty(VARNAME) )",
		&MkCond{Not: &MkCond{
			And: []*MkCond{
				{Defined: "A"},
				{Empty: varuse("VARNAME")}}}})

	test("${REQD_MAJOR} > ${MAJOR}",
		&MkCond{CompareVarVar: &MkCondCompareVarVar{varuse("REQD_MAJOR"), ">", varuse("MAJOR")}})

	test("${OS_VERSION} >= 6.5",
		&MkCond{CompareVarNum: &MkCondCompareVarNum{varuse("OS_VERSION"), ">=", "6.5"}})

	test("${OS_VERSION} == 5.3",
		&MkCond{CompareVarNum: &MkCondCompareVarNum{varuse("OS_VERSION"), "==", "5.3"}})

	test("!empty(${OS_VARIANT:MIllumos})", // Probably not intended
		&MkCond{Not: &MkCond{Empty: varuse("${OS_VARIANT:MIllumos}")}})

	// There may be whitespace before the parenthesis; see devel/bmake/files/cond.c:^compare_function.
	test("defined (VARNAME)",
		&MkCond{Defined: "VARNAME"})

	test("${\"${PKG_OPTIONS:Moption}\":?--enable-option:--disable-option}",
		&MkCond{Var: varuse("\"${PKG_OPTIONS:Moption}\"", "?--enable-option:--disable-option")})

	// Contrary to most other programming languages, the == operator binds
	// more tightly that the ! operator.
	//
	// TODO: Since this operator precedence is surprising there should be a warning,
	//  suggesting to replace "!${VAR} == value" with "${VAR} != value".
	test("!${VAR} == value",
		&MkCond{Not: &MkCond{CompareVarStr: &MkCondCompareVarStr{varuse("VAR"), "==", "value"}}})

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
		&MkCond{Not: &MkCond{Empty: varuse("PKG_OPTIONS", "Msndfile")}},
		"|| defined(PKG_OPTIONS:Msamplerate)")

	testRest("${LEFT} &&",
		&MkCond{Var: varuse("LEFT")},
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
		"!<")

	// Empty parentheses are a syntax error.
	testRest("()",
		nil,
		"()")

	// Unfinished conditions are a syntax error.
	testRest("(${VAR}",
		nil,
		"(${VAR}")

	// The left-hand side of the comparison can only be a variable.
	// FIXME: bmake accepts this, and so should pkglint.
	testRest("\"${VAR}suffix\" == value",
		nil,
		"\"${VAR}suffix\" == value")
}

func (s *Suite) Test_MkParser_Varname(c *check.C) {
	t := s.Init(c)

	test := func(text string) {
		line := t.NewLine("filename.mk", 1, text)
		p := NewMkParser(line, text, true)

		varname := p.Varname()

		t.Check(varname, equals, text)
		t.Check(p.Rest(), equals, "")
	}

	testRest := func(text string, expectedVarname string, expectedRest string) {
		line := t.NewLine("filename.mk", 1, text)
		p := NewMkParser(line, text, true)

		varname := p.Varname()

		t.Check(varname, equals, expectedVarname)
		t.Check(p.Rest(), equals, expectedRest)
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

// Pkglint can replace $(VAR) with ${VAR}. It doesn't look at all components
// of nested variables though because this case is not important enough to
// invest much development time. It occurs so seldom that it is acceptable
// to run pkglint multiple times in such a case.
func (s *Suite) Test_MkParser_VarUse__parentheses_autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--autofix")
	t.SetUpVartypes()
	lines := t.SetUpFileLines("Makefile",
		MkCvsID,
		"COMMENT=$(P1) $(P2)) $(P3:Q) ${BRACES} $(A.$(B.$(C)))")
	mklines := NewMkLines(lines)

	mklines.Check()

	t.CheckOutputLines(
		"AUTOFIX: ~/Makefile:2: Replacing \"$(P1)\" with \"${P1}\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"$(P2)\" with \"${P2}\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"$(P3:Q)\" with \"${P3:Q}\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"$(C)\" with \"${C}\".")
	t.CheckFileLines("Makefile",
		MkCvsID,
		"COMMENT=${P1} ${P2}) ${P3:Q} ${BRACES} $(A.$(B.${C}))")
}

func (s *Suite) Test_MkParser_VarUseModifiers(c *check.C) {
	t := s.Init(c)

	varUse := NewMkVarUse
	test := func(text string, varUse *MkVarUse, diagnostics ...string) {
		line := t.NewLine("Makefile", 20, "\t"+text)
		p := NewMkParser(line, text, true)

		actual := p.VarUse()

		t.Check(actual, deepEquals, varUse)
		t.Check(p.Rest(), equals, "")
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

func (s *Suite) Test_MkParser_varUseModifierSubst(c *check.C) {
	t := s.Init(c)

	varUse := NewMkVarUse
	test := func(text string, varUse *MkVarUse, rest string, diagnostics ...string) {
		line := t.NewLine("Makefile", 20, "\t"+text)
		p := NewMkParser(line, text, true)

		actual := p.VarUse()

		t.Check(actual, deepEquals, varUse)
		t.Check(p.Rest(), equals, rest)
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

func (s *Suite) Test_MkParser_varUseModifierAt(c *check.C) {
	t := s.Init(c)

	varUse := NewMkVarUse
	test := func(text string, varUse *MkVarUse, rest string, diagnostics ...string) {
		line := t.NewLine("Makefile", 20, "\t"+text)
		p := NewMkParser(line, text, true)

		actual := p.VarUse()

		t.Check(actual, deepEquals, varUse)
		t.Check(p.Rest(), equals, rest)
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

func (s *Suite) Test_MkParser_isPkgbasePart(c *check.C) {

	test := func(str string, expected bool) {
		actual := (*MkParser)(nil).isPkgbasePart(str)

		c.Check(actual, equals, expected)
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

func (s *Suite) Test_MkParser_PkgbasePattern(c *check.C) {

	test := func(pattern, expected, rest string) {
		parser := NewMkParser(nil, pattern, false)

		actual := parser.PkgbasePattern()

		c.Check(actual, equals, expected)
		c.Check(parser.Rest(), equals, rest)
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

func (s *Suite) Test_MkParser_Dependency(c *check.C) {

	testRest := func(pattern string, expected DependencyPattern, rest string) {
		parser := NewMkParser(nil, pattern, false)
		dp := parser.Dependency()
		if c.Check(dp, check.NotNil) {
			c.Check(*dp, equals, expected)
			c.Check(parser.Rest(), equals, rest)
		}
	}

	testNil := func(pattern string) {
		parser := NewMkParser(nil, pattern, false)
		dp := parser.Dependency()
		if c.Check(dp, check.IsNil) {
			c.Check(parser.Rest(), equals, pattern)
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
		Var: func(varuse *MkVarUse) {
			addEvent("var", varuseStr(varuse))
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
