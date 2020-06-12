package pkglint

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_MkLine__shell_varuse_in_backt_dquot(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("grep", "GREP", AtRunTime)
	mklines := t.NewMkLines("x11/motif/Makefile",
		MkCvsID,
		"post-patch:",
		"\tfiles=`${GREP} -l \".fB$${name}.fP(3)\" *.3`")

	mklines.Check()

	// Just ensure that there are no parse errors.
	t.CheckOutputEmpty()
}

// PR 51696, security/py-pbkdf2/Makefile, r1.2
func (s *Suite) Test_MkLine__comment_in_comment(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"COMMENT=\tPKCS#5 v2.0 PBKDF2 Module")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:2: The # character starts a Makefile comment.")
}

func (s *Suite) Test_MkLine_Varparam(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("Makefile", 2, "SUBST_SED.${param}=\tvalue")

	varparam := mkline.Varparam()

	t.CheckEquals(varparam, "${param}")
}

func (s *Suite) Test_MkLine_ValueAlign__commented(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("Makefile", 2, "#SUBST_SED.${param}=\tvalue")

	valueAlign := mkline.ValueAlign()

	t.CheckEquals(mkline.IsCommentedVarassign(), true)
	t.CheckEquals(valueAlign, "#SUBST_SED.${param}=\t")
}

func (s *Suite) Test_MkLine_FirstLineContainsValue(c *check.C) {
	t := s.Init(c)

	lines := func(texts ...string) []string { return texts }
	test := func(lines []string, expected bool) {
		mklines := t.NewMkLines("filename.mk", lines...)
		actual := mklines.mklines[0].FirstLineContainsValue()
		t.CheckEquals(actual, expected)
	}
	testAssert := func(lines ...string) {
		mklines := t.NewMkLines("filename.mk", lines...)
		t.ExpectAssert(func() { mklines.mklines[0].FirstLineContainsValue() })
	}

	// Not a variable assignment.
	testAssert(MkCvsID)

	// Not a multiline variable assignment.
	testAssert("VAR=\tvalue")

	test(
		lines(
			"VAR= value \\",
			"\tstarts in first line"),
		true)

	test(
		lines(
			"VAR= \\",
			"\tvalue starts in second line"),
		false)

	test(
		lines(
			"#VAR= value \\",
			"\tstarts in first line"),
		true)

	test(lines(
		"#VAR= \\",
		"\tvalue starts in second line"),
		false)
}

// Demonstrates how a simple condition is structured internally.
// For most of the checks, using cond.Walk is the simplest way to go.
func (s *Suite) Test_MkLine_Cond(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("Makefile", 2, ".if ${VAR} == Value")

	cond := mkline.Cond()

	t.CheckEquals(cond.Compare.Left.Var.varname, "VAR")
	t.CheckEquals(cond.Compare.Right.Str, "Value")
	t.CheckEquals(mkline.Cond(), cond)
}

func (s *Suite) Test_MkLine_IncludedFileFull(c *check.C) {
	t := s.Init(c)

	test := func(including CurrPath, included RelPath, resolved CurrPath) {
		text := sprintf(".include %q", included)
		mkline := t.NewMkLine(including, 123, text)

		t.CheckEquals(mkline.IncludedFileFull(), resolved)
	}

	test("Makefile", "options.mk", "options.mk")
	test("Makefile", "../options.mk", "../options.mk")
	test("Makefile", "../options.mk", "../options.mk")

	// Keep a bit of context information in the path.
	test(
		t.File("subdir/Makefile"), "../options.mk",
		t.File("subdir").JoinNoClean("../options.mk"))

	t.Chdir(".")
	test("category/package/Makefile", "../../devel/lib/buildlink3.mk",
		"category/package/../../devel/lib/buildlink3.mk")

	// Keep a bit of context information in the path.
	test("a/b/c.mk", "../../d/e/../../f/g/h.mk",
		"a/b/../../f/g/h.mk")
}

// Ensures that the conditional variables of a line can be set even
// after initializing the MkLine.
//
// If this test should fail, it is probably because mkLineDirective
// is not a pointer type anymore.
//
// See https://github.com/golang/go/issues/28045.
func (s *Suite) Test_MkLine_ConditionalVars(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("Makefile", 45, ".include \"../../category/package/buildlink3.mk\"")

	c.Check(mkline.ConditionalVars(), check.HasLen, 0)

	mkline.SetConditionalVars([]string{"OPSYS"})

	t.CheckDeepEquals(mkline.ConditionalVars(), []string{"OPSYS"})
}

func (s *Suite) Test_MkLine_Tokenize__commented_varassign(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 123, "#VAR=\tvalue ${VAR} suffix text")

	t.Check(mkline.Tokenize(mkline.Value(), false), check.HasLen, 3)
}

func (s *Suite) Test_MkLine_ValueSplit(c *check.C) {
	t := s.Init(c)

	test := func(value string, expected ...string) {
		mkline := t.NewMkLine("Makefile", 1, "PATH=\t"+value)
		split := mkline.ValueSplit(value, ":")
		t.CheckDeepEquals(split, expected)
	}

	test("Platform-independent C# compiler #5",
		"Platform-independent C# compiler #5")

	// This warning refers to the #5 since it starts a word, but not to the C#.
	t.CheckOutputLines(
		"WARN: Makefile:1: The # character starts a Makefile comment.")

	test("/bin",
		"/bin")

	test("/bin:/sbin",
		"/bin",
		"/sbin")

	test("${DESTDIR}/bin:/bin/${SUBDIR}",
		"${DESTDIR}/bin",
		"/bin/${SUBDIR}")

	test("/bin:${DESTDIR}${PREFIX}:${DESTDIR:S,/,\\:,:S,:,:,}/sbin",
		"/bin",
		"${DESTDIR}${PREFIX}",
		"${DESTDIR:S,/,\\:,:S,:,:,}/sbin")

	test("${VAR:Udefault}::${VAR2}two:words",
		"${VAR:Udefault}",
		"",
		"${VAR2}two",
		"words")

}

func (s *Suite) Test_MkLine_ValueSplit__invalid_argument(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 123, "VAR=\tvalue")

	t.ExpectAssert(func() { mkline.ValueSplit("value", "") })
}

func (s *Suite) Test_MkLine_ValueFields(c *check.C) {
	t := s.Init(c)

	test := func(value string, expected ...string) {
		mkline := t.NewMkLine("Makefile", 1, "VAR=\t"+value)
		split := mkline.ValueFields(value)
		t.CheckDeepEquals(split, expected)
	}

	test("one   two\t\t${THREE:Uthree:Nsome \tspaces}",
		"one",
		"two",
		"${THREE:Uthree:Nsome \tspaces}")

	// The example from the ValueFields documentation.
	test("${VAR:Udefault value} ${VAR2}two words;;; 'word three'",
		"${VAR:Udefault value}",
		"${VAR2}two",
		"words;;;",
		"'word three'")

	test("\"double quotes\" group words",
		"\"double quotes\"",
		"group",
		"words")

	test("\"unfinished",
		nil...) // the rest is silently discarded

	test("'single quotes' group words",
		"'single quotes'",
		"group",
		"words")

	test("'unfinished",
		nil...) // the rest is silently discarded

	// This is how it works in bmake.
	test("'\\' ' end",
		"'\\'") // the "' end" is silently discarded

	// This is how it works in pkglint.
	test("'\\' end",
		"'\\'",
		"end")

	test("`backticks do not group words`",
		"`backticks",
		"do",
		"not",
		"group",
		"words`")

	test("plain${VAR}plain",
		"plain${VAR}plain")

	test("\"${DOUBLE}\" \"\\${DOUBLE}\"",
		"\"${DOUBLE}\"",
		"\"\\${DOUBLE}\"")

	test("'${SINGLE}' '\\${SINGLE}'",
		"'${SINGLE}'",
		"'\\${SINGLE}'")

	test("\"\"''\"\"",
		"\"\"''\"\"")

	test("$@ $<",
		"$@",
		"$<")
}

// Before 2018-11-26, this test panicked.
func (s *Suite) Test_MkLine_ValueFields__adjacent_vars(c *check.C) {
	t := s.Init(c)

	test := func(value string, expected ...string) {
		mkline := t.NewMkLine("Makefile", 1, "")
		split := mkline.ValueFields(value)
		t.CheckDeepEquals(split, expected)
	}

	test("\t; ${RM} ${WRKSRC}",
		";",
		"${RM}",
		"${WRKSRC}")
}

func (s *Suite) Test_MkLine_ValueFields__compared_to_splitIntoShellTokens(c *check.C) {
	t := s.Init(c)
	url := "http://registry.gimp.org/file/fix-ca.c?action=download&id=9884&file="
	mkline := t.NewMkLine("filename.mk", 123, "MASTER_SITES=\t"+url)

	// Splitting a URL into shell tokens doesn't really make sense,
	// but is used here anyway.
	words, rest := splitIntoShellTokens(mkline.Line, url)

	t.CheckDeepEquals(words, []string{
		"http://registry.gimp.org/file/fix-ca.c?action=download",
		"&",
		"id=9884",
		"&",
		"file="})
	t.CheckEquals(rest, "")

	words = mkline.ValueFields(url)

	t.CheckDeepEquals(words, []string{url})

	words = mkline.ValueFields("a b \"c  c  c\" d;;d;; \"e\"''`` 'rest")

	t.CheckDeepEquals(words, []string{"a", "b", "\"c  c  c\"", "d;;d;;", "\"e\"''``"})
	// The rest "'rest" is silently discarded.
	// Most probably, the shell will complain about it when it is executed.
}

func (s *Suite) Test_MkLine_ValueTokens(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()
	text := b.TextToken
	varUseText := b.VaruseTextToken
	tokens := b.Tokens

	test := func(value string, expected []*MkToken, diagnostics ...string) {
		mkline := t.NewMkLine("Makefile", 1, "PATH=\t"+value)
		actualTokens, _ := mkline.ValueTokens()
		t.CheckDeepEquals(actualTokens, expected)
		t.CheckOutput(diagnostics)
	}

	t.Use(text, varUseText, tokens, test)

	test("#empty",
		tokens())

	test("value",
		tokens(text("value")))

	test("value ${VAR} rest",
		tokens(
			text("value "),
			varUseText("${VAR}", "VAR"),
			text(" rest")))

	test("value # comment",
		tokens(
			text("value")))

	test("value ${UNFINISHED",
		tokens(
			text("value "),
			varUseText("${UNFINISHED", "UNFINISHED")),

		"WARN: Makefile:1: Missing closing \"}\" for \"UNFINISHED\".")
}

func (s *Suite) Test_MkLine_ValueTokens__parse_error(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 123, "VAR=\t$")

	tokens, rest := mkline.ValueTokens()

	t.Check(tokens, check.IsNil)
	t.CheckEquals(rest, "$")

	// Returns the same values, this time from the cache.
	tokens, rest = mkline.ValueTokens()

	t.Check(tokens, check.IsNil)
	t.CheckEquals(rest, "$")
}

func (s *Suite) Test_MkLine_ValueTokens__caching(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	mkline := t.NewMkLine("Makefile", 1, "PATH=\tvalue ${UNFINISHED")
	valueTokens, rest := mkline.ValueTokens()

	t.CheckDeepEquals(valueTokens,
		b.Tokens(
			b.TextToken("value "),
			b.VaruseTextToken("${UNFINISHED", "UNFINISHED")))
	t.CheckEquals(rest, "")
	t.CheckOutputLines(
		"WARN: Makefile:1: Missing closing \"}\" for \"UNFINISHED\".")

	// This time the slice is taken from the cache.
	tokens2, rest2 := mkline.ValueTokens()

	t.CheckEquals(&tokens2[0], &valueTokens[0])
	t.CheckEquals(rest2, rest)
}

func (s *Suite) Test_MkLine_ValueTokens__caching_parse_error(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	mkline := t.NewMkLine("Makefile", 1, "PATH=\t${UNFINISHED")
	valueTokens, rest := mkline.ValueTokens()

	t.CheckDeepEquals(valueTokens, b.Tokens(b.VaruseTextToken("${UNFINISHED", "UNFINISHED")))
	t.CheckEquals(rest, "")
	t.CheckOutputLines(
		"WARN: Makefile:1: Missing closing \"}\" for \"UNFINISHED\".")

	// This time the slice is taken from the cache.
	tokens2, rest2 := mkline.ValueTokens()

	t.CheckEquals(&tokens2[0], &valueTokens[0])
	t.CheckEquals(rest2, rest)
}

func (s *Suite) Test_MkLine_ValueTokens__warnings(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"ROUND=\t$(ROUND)")

	mklines.mklines[1].ValueTokens()
	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:2: Please use curly braces {} instead of round parentheses () for ROUND.")
}

func (s *Suite) Test_MkLine_Fields__varassign(c *check.C) {
	t := s.Init(c)

	test := func(value string, expected ...string) {
		mkline := t.NewMkLine("Makefile", 1, "PATH=\t"+value)
		fields := mkline.Fields()
		t.CheckDeepEquals(fields, expected)

		// Repeated calls get the cached value.
		if len(fields) > 0 {
			cached := mkline.Fields()
			t.CheckEquals(&cached[0], &fields[0])
		}
	}

	test("# empty",
		nil...)

	test("word",
		"word")

	test("word '${VAR}single ${VAR}' \"\t\"",
		"word",
		"'${VAR}single ${VAR}'",
		"\"\t\"")
}

func (s *Suite) Test_MkLine_Fields__for(c *check.C) {
	t := s.Init(c)

	test := func(value string, expected ...string) {
		mkline := t.NewMkLine("Makefile", 1, ".for "+value)
		fields := mkline.Fields()
		t.CheckDeepEquals(fields, expected)

		// Repeated calls get the cached value.
		if len(fields) > 0 {
			cached := mkline.Fields()
			t.CheckEquals(&cached[0], &fields[0])
		}
	}

	// Unrealistic, but needed for full code coverage.
	test("# empty",
		nil...)

	// Still unrealistic.
	test("i in # empty",
		"i",
		"in")

	test("i in word '${VAR}single ${VAR}' \"\t\"",
		"i",
		"in",
		"word",
		"'${VAR}single ${VAR}'",
		"\"\t\"")
}

func (s *Suite) Test_MkLine_Fields__semicolons(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 123, "VAR=\tword1 word2;;;")
	words := mkline.Fields()

	t.CheckDeepEquals(words, []string{"word1", "word2;;;"})
}

func (s *Suite) Test_MkLine_Fields__varuse_with_embedded_space(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 123, "VAR=\t${VAR:S/ /_/g}")

	words := mkline.Fields()

	t.CheckDeepEquals(words, []string{"${VAR:S/ /_/g}"})
}

func (s *Suite) Test_MkLine_ResolveVarsInRelativePath(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("lang/lua53/Makefile")
	t.CreateFileLines("lang/php72/Makefile")
	t.CreateFileLines("emulators/suse100_base/Makefile")
	t.CreateFileLines("lang/python36/Makefile")
	mklines := t.SetUpFileMkLines("Makefile",
		MkCvsID)
	mkline := mklines.mklines[0]
	var pkg *Package = nil

	test := func(before PackagePath, after PackagePath) {
		t.CheckEquals(mkline.ResolveVarsInRelativePath(before, pkg), after)
	}

	test("", ".")
	test("${PKGSRCDIR}", ".")
	test("${LUA_PKGSRCDIR}", "../../lang/lua53")
	test("${PHPPKGSRCDIR}", "../../lang/php72")
	test("${SUSE_DIR_PREFIX}", "suse100")
	test("${PYPKGSRCDIR}", "../../lang/python36")
	test("${PYPACKAGE}", "python36")
	test("${FILESDIR}", "${FILESDIR}")
	test("${PKGDIR}", "${PKGDIR}")

	pkg = NewPackage(t.File("category/package"))

	test("${FILESDIR}", "files")
	test("${PKGDIR}", ".")

	// Just for branch coverage.
	G.Testing = false
	test("${PKGSRCDIR}", "../..")
}

func (s *Suite) Test_MkLine_ResolveVarsInRelativePath__directory_depth(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.SetUpFileMkLines("multimedia/totem/filename.mk",
		MkCvsID,
		"BUILDLINK_PKGSRCDIR.totem?=\t../../multimedia/totem")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/multimedia/totem/filename.mk:2: "+
			"The variable BUILDLINK_PKGSRCDIR.totem should not be given a default value in this file; "+
			"it would be ok in buildlink3.mk.",
		"ERROR: ~/multimedia/totem/filename.mk:2: Relative path \"../../multimedia/totem/Makefile\" does not exist.")
}

// Just for code coverage
func (s *Suite) Test_MkLine_ResolveVarsInRelativePath__without_tracing(c *check.C) {
	t := s.Init(c)

	t.DisableTracing()
	t.SetUpVartypes()
	mklines := t.SetUpFileMkLines("buildlink3.mk",
		MkCvsID,
		"BUILDLINK_PKGSRCDIR.totem?=\t../../${PKGPATH.multimedia/totem}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/buildlink3.mk:2: PKGPATH.multimedia/totem is used but not defined.")
}

func (s *Suite) Test_MkLine_ResolveVarsInRelativePath__assertion(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.Chdir(".")
	mkline := t.NewMkLine("a/b/c/d/e/f/g.mk", 123, "")

	t.ExpectPanic(
		func() { mkline.ResolveVarsInRelativePath("${PKGSRCDIR}", nil) },
		"Pkglint internal error: "+
			"Relative path \"../../../../../..\" for \"a/b/c/d/e/f\" is too deep "+
			"below the pkgsrc root \".\".")

}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__unknown_rhs(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 1, "PKGNAME:= ${UNKNOWN}")
	t.SetUpVartypes()

	vuc := VarUseContext{G.Pkgsrc.VariableType(nil, "PKGNAME"), VucLoadTime, VucQuotUnknown, false}
	nq := mkline.VariableNeedsQuoting(nil, NewMkVarUse("UNKNOWN"), nil, &vuc)

	t.CheckEquals(nq, unknown)
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__append_URL_to_list_of_URLs(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpMasterSite("MASTER_SITE_SOURCEFORGE", "http://downloads.sourceforge.net/sourceforge/")
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"MASTER_SITES=\t${HOMEPAGE}")
	mkline := mklines.mklines[1]

	vuc := VarUseContext{G.Pkgsrc.vartypes.Canon("MASTER_SITES"), VucRunTime, VucQuotPlain, false}
	nq := mkline.VariableNeedsQuoting(nil, NewMkVarUse("HOMEPAGE"), G.Pkgsrc.vartypes.Canon("HOMEPAGE"), &vuc)

	t.CheckEquals(nq, no)

	NewMkAssignChecker(mkline, mklines).check()

	t.CheckOutputEmpty() // Up to version 5.3.6, pkglint warned about a missing :Q here, which was wrong.
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__append_list_to_list(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpMasterSite("MASTER_SITE_SOURCEFORGE", "http://downloads.sourceforge.net/sourceforge/")
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"MASTER_SITES=\t${MASTER_SITE_SOURCEFORGE:=squirrel-sql/}")

	NewMkAssignChecker(mklines.mklines[1], mklines).check()

	// Assigning lists to lists is ok.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__eval_shell(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.Chdir("category/package")
	t.FinishSetUp()
	mklines := t.NewMkLines("builtin.mk",
		MkCvsID,
		"",
		".include \"../../mk/bsd.fast.prefs.mk\"",
		"",
		"USE_BUILTIN.Xfixes!=\t${PKG_ADMIN} pmatch 'pkg-[0-9]*' ${BUILTIN_PKG.Xfixes:Q}")

	mklines.ForEach(func(mkline *MkLine) {
		if mkline.IsVarassign() {
			NewMkAssignChecker(mkline, mklines).check()
		}
	})

	t.CheckOutputLines(
		"NOTE: builtin.mk:5: The :Q modifier isn't necessary for ${BUILTIN_PKG.Xfixes} here.")
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__command_in_single_quotes(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"SUBST_SED.hpath=\t-e 's|^\\(INSTALL[\t:]*=\\).*|\\1${INSTALL}|'")

	NewMkAssignChecker(mklines.mklines[1], mklines).check()

	t.CheckOutputLines(
		"WARN: Makefile:2: Please use ${INSTALL:Q} instead of ${INSTALL} " +
			"and make sure the variable appears outside of any quoting characters.")
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__command_in_command(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("find", "FIND", AtRunTime)
	t.SetUpTool("sort", "SORT", AtRunTime)
	pkg := NewPackage(t.File("category/pkgbase"))
	mklines := t.NewMkLinesPkg("Makefile", pkg,
		MkCvsID,
		"GENERATE_PLIST= cd ${DESTDIR}${PREFIX}; ${FIND} * \\( -type f -or -type l \\) | ${SORT};")

	mklines.collectVariables()
	MkLineChecker{mklines, mklines.mklines[1]}.Check()

	t.CheckOutputLines(
		"WARN: Makefile:2: The exitcode of \"${FIND}\" at the left of the | operator is ignored.")
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__word_as_part_of_word(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"EGDIR=\t${EGDIR}/${MACHINE_GNU_PLATFORM}")

	MkLineChecker{mklines, mklines.mklines[1]}.Check()

	t.CheckOutputEmpty()
}

// As an argument to ${ECHO}, the :Q modifier should be used, but as of
// October 2018, pkglint does not know all shell commands and how they
// handle their arguments. As an argument to xargs(1), the :Q modifier
// would be misplaced, therefore no warning is issued in both these cases.
//
// Based on graphics/circos/Makefile.
func (s *Suite) Test_MkLine_VariableNeedsQuoting__command_as_command_argument(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("perl", "PERL5", AtRunTime)
	t.SetUpTool("bash", "BASH", AtRunTime)
	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"\t${RUN} cd ${WRKSRC} && ( ${ECHO} ${PERL5:Q} ; ${ECHO} ) | ${BASH} ./install",
		"\t${RUN} cd ${WRKSRC} && ( ${ECHO} ${PERL5} ; ${ECHO} ) | ${BASH} ./install")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:2: The exitcode of the command at the left of the | operator is ignored.",
		"WARN: Makefile:3: The exitcode of the command at the left of the | operator is ignored.")
}

// As seen in mail/mailfront/Makefile.
func (s *Suite) Test_MkLine_VariableNeedsQuoting__URL_as_part_of_word_in_list(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"MASTER_SITES=${HOMEPAGE}archive/")

	MkLineChecker{mklines, mklines.mklines[1]}.Check()

	t.CheckOutputEmpty() // Don't suggest to use ${HOMEPAGE:Q}.
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__MASTER_SITES_and_HOMEPAGE(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"MASTER_SITES=\t${HOMEPAGE}",
		"MASTER_SITES=\t${PATH}", // Some nonsense just for branch coverage.
		"HOMEPAGE=\t${MASTER_SITES}",
		"HOMEPAGE=\t${BUILD_DIRS}") // Some nonsense just for branch coverage.

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:3: Please use ${PATH:Q} instead of ${PATH}.",
		"WARN: Makefile:4: HOMEPAGE should not be defined in terms of MASTER_SITEs.",
		"WARN: Makefile:5: Please use ${BUILD_DIRS:Q} instead of ${BUILD_DIRS}.")
}

// Before November 2018, pkglint did not parse $$(subshell) commands very well.
// As a side effect, it sometimes issued wrong warnings about the :Q modifier.
//
// As seen in www/firefox31/xpi.mk.
func (s *Suite) Test_MkLine_VariableNeedsQuoting__command_in_subshell(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("awk", "AWK", AtRunTime)
	t.SetUpTool("echo", "ECHO", AtRunTime)
	mklines := t.NewMkLines("xpi.mk",
		MkCvsID,
		"\t id=$$(${AWK} '{print}' < ${WRKSRC}/idfile) && echo \"$$id\"",
		"\t id=`${AWK} '{print}' < ${WRKSRC}/idfile` && echo \"$$id\"")

	MkLineChecker{mklines, mklines.mklines[1]}.Check()
	MkLineChecker{mklines, mklines.mklines[2]}.Check()

	// Don't suggest to use ${AWK:Q}.
	t.CheckOutputEmpty()
}

// LDFLAGS (and even more so CPPFLAGS and CFLAGS) may contain special
// shell characters like quotes or backslashes. Therefore, quoting them
// correctly is trickier than with other variables.
func (s *Suite) Test_MkLine_VariableNeedsQuoting__LDFLAGS_in_single_quotes(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("x11/mlterm/Makefile",
		MkCvsID,
		"SUBST_SED.link=-e 's|(LIBTOOL_LINK).*(LIBS)|& ${LDFLAGS:M*:Q}|g'",
		"SUBST_SED.link=-e 's|(LIBTOOL_LINK).*(LIBS)|& '${LDFLAGS:M*:Q}'|g'")

	MkLineChecker{mklines, mklines.mklines[1]}.Check()
	MkLineChecker{mklines, mklines.mklines[2]}.Check()

	t.CheckOutputLines(
		"WARN: x11/mlterm/Makefile:2: Please move ${LDFLAGS:M*:Q} outside of any quoting characters.")
}

// No quoting is necessary when lists of options are appended to each other.
func (s *Suite) Test_MkLine_VariableNeedsQuoting__package_options(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"PKG_SUGGESTED_OPTIONS+=\t${PKG_DEFAULT_OPTIONS:Mcdecimal} ${PKG_OPTIONS.py-trytond:Mcdecimal}")

	MkLineChecker{mklines, mklines.mklines[1]}.Check()

	// No warning about a missing :Q modifier.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__tool_in_quotes_in_subshell_in_shellwords(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("echo", "ECHO", AtRunTime)
	t.SetUpTool("sh", "SH", AtRunTime)
	t.SetUpVartypes()
	mklines := t.NewMkLines("x11/labltk/Makefile",
		MkCvsID,
		"CONFIGURE_ARGS+=\t-tklibs \"`${SH} -c '${ECHO} $$TK_LD_FLAGS'`\"")

	MkLineChecker{mklines, mklines.mklines[1]}.Check()

	// Don't suggest ${ECHO:Q} here.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__LDADD_in_BUILDLINK_TRANSFORM(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("x11/qt5-qtbase/Makefile.common",
		"BUILDLINK_TRANSFORM+=opt:-ldl:${BUILDLINK_LDADD.dl:M*}")

	MkLineChecker{mklines, mklines.mklines[0]}.Check()

	// Note: The :M* modifier is not necessary, since this is not a GNU Configure package.
	t.CheckOutputLines(
		"WARN: x11/qt5-qtbase/Makefile.common:1: Please use ${BUILDLINK_LDADD.dl:Q} instead of ${BUILDLINK_LDADD.dl:M*}.")
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__command_in_message(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("benchmarks/iozone/Makefile",
		"SUBST_MESSAGE.crlf=\tStripping EOL CR in ${REPLACE_PERL}")

	MkLineChecker{mklines, mklines.mklines[0]}.Check()

	// Don't suggest ${REPLACE_PERL:Q}.
	t.CheckOutputEmpty()
}

// Since a comment may be appended to, it is not necessary to mention
// BtComment in the SUBST_MESSAGE case in VariableNeedsQuoting.
func (s *Suite) Test_MkLine_VariableNeedsQuoting__command_in_package_comment(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("benchmarks/iozone/Makefile",
		"COMMENT=\tUtility for replacing ${REPLACE_PERL}")

	MkLineChecker{mklines, mklines.mklines[0]}.Check()

	// Don't suggest ${REPLACE_PERL:Q}.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__guessed_list_variable_in_quotes(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("audio/jack-rack/Makefile",
		MkCvsID,
		"LADSPA_PLUGIN_PATH=\t${PREFIX}/lib/ladspa",
		"CPPFLAGS+=\t\t-DLADSPA_PATH=\"\\\"${LADSPA_PLUGIN_PATH}\\\"\"")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: audio/jack-rack/Makefile:3: The variable LADSPA_PLUGIN_PATH should be quoted as part of a shell word.")
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__list_in_list(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("x11/eterm/Makefile",
		MkCvsID,
		"DISTFILES=\t${DEFAULT_DISTFILES} ${PIXMAP_FILES}")

	mklines.Check()

	// Don't warn about missing :Q modifiers.
	t.CheckOutputLines(
		"WARN: x11/eterm/Makefile:2: PIXMAP_FILES is used but not defined.")
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__PKGNAME_and_URL_list_in_URL_list(c *check.C) {
	t := s.Init(c)

	t.SetUpMasterSite("MASTER_SITE_GNOME", "http://ftp.gnome.org/")
	t.SetUpVartypes()
	mklines := t.NewMkLines("x11/gtk3/Makefile",
		MkCvsID,
		"MASTER_SITES=\tftp://ftp.gtk.org/${PKGNAME}/ ${MASTER_SITE_GNOME:=subdir/}")

	NewMkAssignChecker(mklines.mklines[1], mklines).checkRightVaruse()

	t.CheckOutputEmpty() // Don't warn about missing :Q modifiers.
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__tool_in_CONFIGURE_ENV(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("tar", "TAR", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"CONFIGURE_ENV+=\tSYS_TAR_COMMAND_PATH=${TOOLS_TAR:Q}")

	NewMkAssignChecker(mklines.mklines[2], mklines).checkRightVaruse()

	// The TOOLS_* variables only contain the path to the tool,
	// without any additional arguments that might be necessary
	// for invoking the tool properly (e.g. touch -t).
	// Therefore, no quoting is necessary.
	t.CheckOutputLines(
		"NOTE: Makefile:3: The :Q modifier isn't necessary for ${TOOLS_TAR} here.")
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__backticks(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("cat", "CAT", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"COMPILE_CMD=\tcc `${CAT} ${WRKDIR}/compileflags`",
		"COMMENT_CMD=\techo `echo ${COMMENT}`")

	NewMkAssignChecker(mklines.mklines[2], mklines).checkRightVaruse()
	NewMkAssignChecker(mklines.mklines[3], mklines).checkRightVaruse()

	// Both CAT and WRKDIR are safe from quoting, therefore no warnings.
	// But COMMENT may contain arbitrary characters and therefore must
	// only appear completely unquoted. There is no practical way of
	// using it inside backticks, and luckily there is no need for it.
	t.CheckOutputLines(
		// TODO: Better suggest that COMMENT should not be used inside backticks or other quotes.
		"WARN: Makefile:4: The variable COMMENT should be quoted as part of a shell word.")
}

// For some well-known directory variables like WRKDIR, PREFIX, LOCALBASE,
// the :Q modifier can be safely removed since pkgsrc will never support
// having special characters in these directory names.
// For guessed variable types be cautious and don't autofix them.
func (s *Suite) Test_MkLine_VariableNeedsQuoting__only_remove_known(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--autofix")
	t.SetUpVartypes()

	mklines := t.SetUpFileMkLines("Makefile",
		MkCvsID,
		"",
		"demo: .PHONY",
		"\t${ECHO} ${WRKSRC:Q}",
		"\t${ECHO} ${FOODIR:Q}")

	mklines.Check()

	t.CheckOutputLines(
		"AUTOFIX: ~/Makefile:4: Replacing \"${WRKSRC:Q}\" with \"${WRKSRC}\".")
	t.CheckFileLines("Makefile",
		MkCvsID,
		"",
		"demo: .PHONY",
		"\t${ECHO} ${WRKSRC}",
		"\t${ECHO} ${FOODIR:Q}")
}

// TODO: COMPILER_RPATH_FLAG and LINKER_RPATH_FLAG have different types
//  defined in vardefs.go; examine why.
func (s *Suite) Test_MkLine_VariableNeedsQuoting__shellword_part(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.SetUpFileMkLines("Makefile",
		MkCvsID,
		"",
		"SUBST_CLASSES+=\t\tclass",
		"SUBST_STAGE.class=\tpre-configure",
		"SUBST_FILES.class=\tfiles",
		"SUBST_SED.class=\t-e s:@LINKER_RPATH_FLAG@:${LINKER_RPATH_FLAG}:g")

	mklines.Check()

	t.CheckOutputLines(
		"NOTE: ~/Makefile:6: The substitution command \"s:@LINKER_RPATH_FLAG@:${LINKER_RPATH_FLAG}:g\" " +
			"can be replaced with \"SUBST_VARS.class= LINKER_RPATH_FLAG\".")
}

// Tools, when used in a shell command, must not be quoted.
// Shell commands may have command line arguments, pathnames must not.
// The original intention of having both CONFIG_SHELL and CONFIG_SHELL_FLAGS
// was to separate the command from its arguments.
// It doesn't hurt though if the command includes some of the arguments as well.
func (s *Suite) Test_MkLine_VariableNeedsQuoting__tool_in_shell_command(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("bash", "BASH", AtRunTime)

	mklines := t.SetUpFileMkLines("Makefile",
		MkCvsID,
		"",
		"CONFIG_SHELL=\t${BASH}",
		"DIST_SUBDIR=\t${BASH}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/Makefile:4: Incompatible types: " +
			"BASH (type \"ShellCommand\") cannot be assigned to type \"Pathname\".")
}

// This test provides code coverage for the "switch vuc.quoting" in the case
// that vuc.quoting is VucQuotUnknown.
//
// It is not possible to construct this scenario by calling mklines.Check(),
// therefore it is specially crafted.
func (s *Suite) Test_MkLine_VariableNeedsQuoting__tool_in_unknown_quotes(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("bash", "BASH", AtRunTime)

	mklines := t.SetUpFileMkLines("Makefile",
		"\t:")
	mkline := mklines.mklines[0]

	varUse := NewMkVarUse("BASH")
	vartype := G.Pkgsrc.VariableType(mklines, "BASH")
	vuc := VarUseContext{
		vartype:    NewVartype(BtShellWord, NoVartypeOptions, NewACLEntry("*", aclpAll)),
		time:       VucRunTime,
		quoting:    VucQuotUnknown,
		IsWordPart: false}
	needsQuoting := mkline.VariableNeedsQuoting(mklines, varUse, vartype, &vuc)

	// This "yes" comes from the end of the "wantList != haveList" branch.
	t.CheckEquals(needsQuoting, yes)
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__tool_in_quoted_word_part(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("tool", "TOOL", AtRunTime)

	test := func(line string, diagnostics ...string) {
		mklines := t.SetUpFileMkLines("Makefile",
			MkCvsID,
			line)

		mklines.Check()

		t.CheckOutput(diagnostics)
	}

	test("\t: x${TOOL}",
		"WARN: ~/Makefile:2: Please use ${TOOL:Q} instead of ${TOOL}.")

	test("\t: \"x${TOOL}\"")

	test("\t: 'x${TOOL}'")

	test("\t: `x${TOOL}`",
		"WARN: ~/Makefile:2: Unknown shell command \"x${TOOL}\".",
		"WARN: ~/Makefile:2: Please use ${TOOL:Q} instead of ${TOOL}.")
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__D_and_U_modifiers(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.SetUpFileMkLines("Makefile",
		MkCvsID,
		"",
		"SUBST_CLASSES+=\t\turl2pkg",
		"SUBST_STAGE.url2pkg=\tpost-configure",
		"SUBST_FILES.url2pkg=\t*.in",
		"SUBST_SED.url2pkg=\t-e 's,@PKGSRCDIR@,${BATCH:D/usr/pkg:U${PKGSRCDIR}},'")

	mklines.Check()

	// Since the value of the BATCH variable does not appear in the output,
	// there should be no warning saying that "BATCH should be quoted".
	// If any, the variable PKGSRCDIR should be quoted, but that is a safe
	// variable since it is a pkgsrc-specific directory.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLine_VariableNeedsQuoting__only_D_modifier(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.SetUpFileMkLines("Makefile",
		MkCvsID,
		"",
		"SUBST_CLASSES+=\t\turl2pkg",
		"SUBST_STAGE.url2pkg=\tpost-configure",
		"SUBST_FILES.url2pkg=\t*.in",
		"SUBST_SED.url2pkg=\t-e 's,@PKGSRCDIR@,${BATCH:D${PKGSRCDIR}},'")

	mklines.Check()

	// Since the value of the BATCH variable does not appear in the output,
	// there should be no warning saying that "BATCH should be quoted".
	// If any, the variable PKGSRCDIR should be quoted, but that is a safe
	// variable since it is a pkgsrc-specific directory and it appears as
	// part of a word, therefore it cannot result in an empty string.
	t.CheckOutputEmpty()
}

// As of October 2018, these examples from real pkgsrc end up in the
// final "unknown" case.
func (s *Suite) Test_MkLine_VariableNeedsQuoting__uncovered_cases(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	t.SetUpVartypes()

	mklines := t.SetUpFileMkLines("Makefile",
		MkCvsID,
		"",
		"GO_SRCPATH=\t\t${HOMEPAGE:S,https://,,}",
		"LINKER_RPATH_FLAG:=\t${LINKER_RPATH_FLAG:S/-rpath/& /}",
		"HOMEPAGE=\t\thttps://godoc.org/${GO_SRCPATH}",
		"PATH:=\t\t\t${PREFIX}/cross/bin:${PATH}",
		"NO_SRC_ON_FTP=\t\t${RESTRICTED}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/Makefile:4: The variable LINKER_RPATH_FLAG should not be set by any package.",
		"",
		"\tThe allowed actions for a variable are determined based on the file",
		"\tname in which the variable is used or defined. The rules for",
		"\tLINKER_RPATH_FLAG are:",
		"",
		"\t* in buildlink3.mk, it should not be accessed at all",
		"\t* in any file, it may be used",
		"",
		"\tIf these rules seem to be incorrect, please ask on the",
		"\ttech-pkg@NetBSD.org mailing list.",
		"",
		"WARN: ~/Makefile:4: LINKER_RPATH_FLAG should not be used at load time in any file.",
		"",
		"\tMany variables, especially lists of something, get their values",
		"\tincrementally. Therefore it is generally unsafe to rely on their",
		"\tvalue until it is clear that it will never change again. This point",
		"\tis reached when the whole package Makefile is loaded and execution",
		"\tof the shell commands starts; in some cases earlier.",
		"",
		"\tAdditionally, when using the \":=\" operator, each $$ is replaced with",
		"\ta single $, so variables that have references to shell variables or",
		"\tregular expressions are modified in a subtle way.",
		"",
		"\tThe allowed actions for a variable are determined based on the file",
		"\tname in which the variable is used or defined. The rules for",
		"\tLINKER_RPATH_FLAG are:",
		"",
		"\t* in buildlink3.mk, it should not be accessed at all",
		"\t* in any file, it may be used",
		"",
		"\tIf these rules seem to be incorrect, please ask on the",
		"\ttech-pkg@NetBSD.org mailing list.",
		"",
		"WARN: ~/Makefile:6: The variable PATH should not be set by any package.",
		"",
		"\tThe allowed actions for a variable are determined based on the file",
		"\tname in which the variable is used or defined. The rules for PATH",
		"\tare:",
		"",
		"\t* in any file, it may be used at load time, or used",
		"",
		"\tIf these rules seem to be incorrect, please ask on the",
		"\ttech-pkg@NetBSD.org mailing list.",
		"",
		"WARN: ~/Makefile:6: PREFIX should not be used at load time in any file.",
		"",
		"\tMany variables, especially lists of something, get their values",
		"\tincrementally. Therefore it is generally unsafe to rely on their",
		"\tvalue until it is clear that it will never change again. This point",
		"\tis reached when the whole package Makefile is loaded and execution",
		"\tof the shell commands starts; in some cases earlier.",
		"",
		"\tAdditionally, when using the \":=\" operator, each $$ is replaced with",
		"\ta single $, so variables that have references to shell variables or",
		"\tregular expressions are modified in a subtle way.",
		"",
		"\tThe allowed actions for a variable are determined based on the file",
		"\tname in which the variable is used or defined. The rules for PREFIX",
		"\tare:",
		"",
		"\t* in any file, it may be used",
		"",
		"\tIf these rules seem to be incorrect, please ask on the",
		"\ttech-pkg@NetBSD.org mailing list.",
		"")

	// Just for branch coverage.
	t.DisableTracing()
	MkLineChecker{mklines, mklines.mklines[2]}.Check()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLine_ForEachUsed(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"VAR=\t${VALUE} # ${varassign.comment}",
		".if ${OPSYS:M${endianness}} == ${Hello:L} # ${if.comment}",
		".for var in one ${two} three # ${for.comment}",
		"# ${empty.comment}",
		"${TARGETS}: ${SOURCES} # ${dependency.comment}",
		".include \"${OTHER_FILE}\"",
		"",
		"\t${VAR.${param}}",
		"\t${VAR}and${VAR2}",
		"\t${VAR:M${pattern}}",
		"\t$(ROUND_PARENTHESES)",
		"\t$$shellvar",
		"\t$< $@ $x")

	var varnames []string
	for _, mkline := range mklines.mklines {
		mkline.ForEachUsed(func(varUse *MkVarUse, time VucTime) {
			varnames = append(varnames, time.String()+" "+varUse.varname)
		})
	}

	t.CheckDeepEquals(varnames, []string{
		"run VALUE",
		"load OPSYS",
		"load endianness",
		// "Hello" is not a variable name, the :L modifier makes it an expression.
		"load two",
		"load TARGETS",
		"load SOURCES",
		"load OTHER_FILE",

		"run VAR.${param}",
		"run param",
		"run VAR",
		"run VAR2",
		"run VAR",
		"run pattern",
		"run ROUND_PARENTHESES",
		// Shell variables are ignored here.
		"run <",
		"run @",
		"run x"})
	t.CheckOutputLines(
		"WARN: Makefile:12: Please use curly braces {} instead of round parentheses () for ROUND_PARENTHESES.",
		"WARN: Makefile:14: $x is ambiguous. Use ${x} if you mean a Make variable or $$x if you mean a shell variable.")
}

func (s *Suite) Test_MkLine_UnquoteShell(c *check.C) {
	t := s.Init(c)

	test := func(input, output string, diagnostics ...string) {
		mkline := t.NewMkLine("filename.mk", 1, "")
		unquoted := mkline.UnquoteShell(input, true)
		t.CheckEquals(unquoted, output)
		t.CheckOutput(diagnostics)
	}

	test("", "")
	test("plain", "plain")
	test("plain words", "plain words")
	test("\"dquot\"", "dquot")
	test("\"dquot \\\"escaped\\\\\"", "dquot \"escaped\\")
	test("'squot \\\"escaped\\\\'", "squot \\\"escaped\\\\")
	test("'squot,''squot'", "squot,squot")
	test("\"dquot,\"'squot'", "dquot,squot")
	test("\"'\",'\"'", "',\"")
	test("\\\" \\\\", "\" \\")

	// UnquoteShell does not parse shell variable expansions or even subshells.
	// It therefore must cope with unexpected input and make the best out of it.

	test("\\", "")
	test("\"\\", "")
	test("'", "")

	test("\"$(\"", "$(\"")

	test("`", "`")

	// Quotes inside a varuse are not unquoted.
	test("${VAR}", "${VAR}")
	test("${VAR:S,',',g}", "${VAR:S,',',g}")

	test("\"*?[\"", "*?[")
	test("'*?['", "*?[")

	test("*?[", "*?[",
		"WARN: filename.mk:1: The \"*\" in the word \"*?[\" may lead to unintended file globbing.",
		"WARN: filename.mk:1: The \"?\" in the word \"*?[\" may lead to unintended file globbing.",
		"WARN: filename.mk:1: The \"[\" in the word \"*?[\" may lead to unintended file globbing.")

	test("'single'*\"double\"", "single*double",
		"WARN: filename.mk:1: The \"*\" in the word \"'single'*\\\"double\\\"\" "+
			"may lead to unintended file globbing.")
}

func (s *Suite) Test_NewMkOperator(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(NewMkOperator(":="), opAssignEval)
	t.CheckEquals(NewMkOperator("="), opAssign)

	c.Check(func() { NewMkOperator("???") }, check.Panics, "Invalid operator: ???")
}

func (s *Suite) Test_VarUseContext_String(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	vartype := G.Pkgsrc.VariableType(nil, "PKGNAME")
	vuc := VarUseContext{vartype, VucUnknownTime, VucQuotBackt, false}

	t.CheckEquals(vuc.String(), "(Pkgname (package-settable) time:unknown quoting:backt wordpart:false)")
}

func (s *Suite) Test_Indentation(c *check.C) {
	t := s.Init(c)

	ind := NewIndentation()

	mkline := t.NewMkLine("dummy.mk", 5, ".if 0")

	t.CheckEquals(ind.Depth("if"), 0)
	t.CheckEquals(ind.DependsOn("VARNAME"), false)

	ind.Push(mkline, 2, "", false)

	t.CheckEquals(ind.Depth("if"), 2)
	t.CheckEquals(ind.Depth("endfor"), 0)

	ind.AddVar("LEVEL1.VAR1")

	t.CheckDeepEquals(ind.Varnames(), []string{"LEVEL1.VAR1"})

	ind.AddVar("LEVEL1.VAR2")

	t.CheckDeepEquals(ind.Varnames(), []string{"LEVEL1.VAR1", "LEVEL1.VAR2"})
	t.CheckEquals(ind.DependsOn("LEVEL1.VAR1"), true)
	t.CheckEquals(ind.DependsOn("OTHER_VAR"), false)

	ind.Push(mkline, 2, "", false)

	ind.AddVar("LEVEL2.VAR")

	t.CheckDeepEquals(ind.Varnames(), []string{"LEVEL1.VAR1", "LEVEL1.VAR2", "LEVEL2.VAR"})
	t.CheckEquals(ind.String(), "[2 (LEVEL1.VAR1 LEVEL1.VAR2) 2 (LEVEL2.VAR)]")

	ind.Pop()

	t.CheckDeepEquals(ind.Varnames(), []string{"LEVEL1.VAR1", "LEVEL1.VAR2"})
	t.CheckEquals(ind.IsConditional(), true)

	ind.Pop()

	c.Check(ind.Varnames(), check.HasLen, 0)
	t.CheckEquals(ind.IsConditional(), false)
	t.CheckEquals(ind.String(), "[]")
}

func (s *Suite) Test_Indentation__realistic(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"",
		".if 1",
		".  if !defined(GUARD_MK)",
		".  for var in 1 2 3",
		".    if !defined(GUARD_MK)", // well, not entirely realistic
		".    if 3",
		".    endif",
		".    endif",
		".  endfor",
		".  endif",
		".elif 1",
		".  for var in 1 2 3",
		".  endfor",
		".else",
		".  for var in 1 2 3",
		".  endfor",
		".endif")

	mklines.ForEach(func(mkline *MkLine) {})

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Indentation_String(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		".if exists(/bin)",
		"# probably POSIX",
		".endif")
	var str string

	mklines.ForEach(func(mkline *MkLine) {
		if mkline.IsComment() {
			t.CheckEquals(mklines.indentation.IsConditional(), true)
			t.Check(mklines.indentation.Varnames(), check.IsNil)
			str = mklines.indentation.String()
		}
	})

	t.CheckEquals(str, "[2]")
}

func (s *Suite) Test_Indentation_RememberUsedVariables(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("Makefile", 123, ".if ${PKGREVISION} > 0")
	ind := NewIndentation()

	ind.TrackBefore(mkline)
	ind.RememberUsedVariables(mkline.Cond())

	t.CheckOutputEmpty()
	t.CheckDeepEquals(ind.Varnames(), []string{"PKGREVISION"})
}

func (s *Suite) Test_Indentation_Varnames__repetition(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/other")
	t.CreateFileBuildlink3("category/other/buildlink3.mk")
	t.SetUpPackage("category/package",
		"DISTNAME=\tpackage-1.0",
		".include \"../../category/other/buildlink3.mk\"")
	t.CreateFileBuildlink3("category/package/buildlink3.mk",
		".include \"../../mk/bsd.fast.prefs.mk\"",
		"",
		".if ${OPSYS} == NetBSD || ${OPSYS} == FreeBSD",
		".  if ${OPSYS} == NetBSD",
		".    include \"../../category/other/buildlink3.mk\"",
		".  endif",
		".endif")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:20: " +
			"\"../../category/other/buildlink3.mk\" is included " +
			"unconditionally here and " +
			"conditionally in buildlink3.mk:16 (depending on OPSYS).")
}

// Multiple-inclusion guards are too technical to be of any use on
// the application level. Therefore they are filtered out early, in
// Indentation.AddVar.
func (s *Suite) Test_Indentation_Varnames__guard(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		".if !defined(GUARD_MK)",
		".  if !defined(VAR)",
		"VAR=\tvalue",
		".  endif",
		".endif")

	var varnames []string
	mklines.ForEach(func(mkline *MkLine) {
		if mkline.IsVarassign() {
			varnames = mklines.indentation.Varnames()
		}
	})

	t.CheckDeepEquals(varnames, []string{"VAR"})
}

func (s *Suite) Test_Indentation_TrackAfter__checked_files(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		MkCvsID,
		"",
		".if make(other.mk)",
		".  include \"other.mk\"",
		".endif",
		"",
		".if exists(checked.mk)",
		".  include \"checked.mk\"",
		".elif exists(other-checked.mk)",
		".  include \"other-checked.mk\"",
		".endif")

	mklines.Check()

	t.CheckOutputLines(
		"ERROR: file.mk:4: Relative path \"other.mk\" does not exist.")
}

func (s *Suite) Test_Indentation_TrackAfter__lonely_else(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		MkCvsID,
		"",
		".else")

	mklines.Check()

	// Surprisingly, pkglint doesn't report an error about this trivial bug.
	// This will be caught by bmake, though. Therefore the only purpose of
	// this test is the branch coverage in the "top.mkline != nil" case.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MatchMkInclude(c *check.C) {
	t := s.Init(c)

	test := func(input, expectedIndent, expectedDirective string, expectedFilename RelPath, expectedComment string) {
		splitResult := NewMkLineParser().split(nil, input, true)
		m, indent, directive, args := MatchMkInclude(splitResult.main)
		t.CheckDeepEquals(
			[]interface{}{m, indent, directive, args, condStr(splitResult.hasComment, "#", "") + splitResult.comment},
			[]interface{}{true, expectedIndent, expectedDirective, expectedFilename, expectedComment})
	}

	testFail := func(input string) {
		m, _, _, _ := MatchMkInclude(input)
		if m {
			c.Errorf("Text %q unexpectedly matched.", input)
		}
	}

	test(".include \"other.mk\"",
		"", "include", "other.mk", "")

	test(".include \"other.mk\"\t",
		"", "include", "other.mk", "")

	test(".include \"other.mk\"\t#",
		"", "include", "other.mk", "#")

	test(".include \"other.mk\"\t# comment",
		"", "include", "other.mk", "# comment")

	test(".  include \"${DIR}/file.mk\"",
		"  ", "include", "${DIR}/file.mk", "")

	test(".  include \"${DIR:S,\",',g}/file.mk\"",
		"  ", "include", "${DIR:S,\",',g}/file.mk", "")

	test(".include \"${}\"",
		"", "include", "${}", "")

	testFail("")
	testFail(".")
	testFail(".include")
	testFail(".include \"")
	testFail(".include \"\"")
	testFail(".include \"$\"")
	testFail(".include \"$$\"")
	testFail(".include \"other.mk")
	testFail(".include \"other.mk\" \"")
	testFail(".include \"/absolute\"")
	testFail(".include \"/absolute\"rest")
	testFail(".include \"/absolute\" rest")
}
