package pkglint

import (
	"gopkg.in/check.v1"
	"strings"
)

// This test demonstrates that the shell tokenizer is not perfect yet.
// There are still some corner cases that trigger a parse error.
// To get 100% code coverage, they have been found using the fuzzer
// and trimmed down to minimal examples.
func (s *Suite) Test_ShTokenizer__examples_from_fuzzing(c *check.C) {
	t := s.Init(c)

	test := func(input string, diagnostics ...string) {
		mklines := t.NewMkLines("filename.mk",
			MkCvsID,
			"\t"+input)
		mklines.Check()
		t.CheckOutput(diagnostics)
	}

	// Covers shAtomBacktDquot: return nil.
	// These are nested backticks with double quotes,
	// which should be avoided since POSIX marks them as unspecified.
	test(
		"`\"`",
		"WARN: filename.mk:2: Internal pkglint error in ShTokenizer.ShAtom at \"`\" (quoting=bd).",
		"WARN: filename.mk:2: Pkglint ShellLine.CheckShellCommand: splitIntoShellTokens couldn't parse \"`\\\"`\"")

	// Covers shAtomBacktSquot: return nil
	test(
		"`'$`",
		"WARN: filename.mk:2: Internal pkglint error in ShTokenizer.ShAtom at \"$`\" (quoting=bs).",
		"WARN: filename.mk:2: Pkglint ShellLine.CheckShellCommand: splitIntoShellTokens couldn't parse \"`'$`\"",
		"WARN: filename.mk:2: Internal pkglint error in MkLine.Tokenize at \"$`\".")

	// Covers shAtomDquotBacktSquot: return nil
	test(
		"\"`'`y",
		"WARN: filename.mk:2: Pkglint ShellLine.CheckShellCommand: splitIntoShellTokens couldn't parse \"\\\"`'`y\"")

	// Covers shAtomDquotBackt: return nil
	// XXX: Pkglint should parse unescaped dollar in the same way, everywhere.
	test(
		"\"`$|",
		"WARN: filename.mk:2: Internal pkglint error in ShTokenizer.ShAtom at \"$|\" (quoting=db).",
		"WARN: filename.mk:2: Pkglint ShellLine.CheckShellCommand: splitIntoShellTokens couldn't parse \"\\\"`$|\"",
		"WARN: filename.mk:2: Internal pkglint error in MkLine.Tokenize at \"$|\".")

	// Covers shAtomDquotBacktDquot: return nil
	// XXX: Pkglint should support unlimited nesting.
	test(
		"\"`\"`",
		"WARN: filename.mk:2: Internal pkglint error in ShTokenizer.ShAtom at \"`\" (quoting=dbd).",
		"WARN: filename.mk:2: Pkglint ShellLine.CheckShellCommand: splitIntoShellTokens couldn't parse \"\\\"`\\\"`\"")

	// Covers shAtomSubshDquot: return nil
	test(
		"$$(\"'",
		"WARN: filename.mk:2: Invoking subshells via $(...) is not portable enough.")

	// Covers shAtomSubsh: case lexer.AdvanceStr("`")
	test(
		"$$(`",
		"WARN: filename.mk:2: Invoking subshells via $(...) is not portable enough.")

	// Covers shAtomSubshSquot: return nil
	test(
		"$$('$)",
		"WARN: filename.mk:2: Internal pkglint error in ShTokenizer.ShAtom at \"$)\" (quoting=Ss).",
		"WARN: filename.mk:2: Invoking subshells via $(...) is not portable enough.",
		"WARN: filename.mk:2: Internal pkglint error in MkLine.Tokenize at \"$)\".")

	// Covers shAtomDquotBackt: case lexer.AdvanceRegexp("^#[^`]*")
	test(
		"\"`# comment",
		"WARN: filename.mk:2: Pkglint ShellLine.CheckShellCommand: splitIntoShellTokens couldn't parse \"\\\"`# comment\"")
}

// In order to get 100% code coverage for the shell tokenizer, a panic() statement has been
// added to each uncovered basic block. After that, this fuzzer quickly found relatively
// small example programs that led to the uncovered code.
//
// This test is not useful as-is.
func (s *Suite) Test_ShTokenizer__fuzzing(c *check.C) {
	t := s.Init(c)

	fuzzer := NewFuzzer()
	fuzzer.Char("\"'`$();|_#", 10)
	fuzzer.Range('a', 'z', 5)

	// This "real" line is necessary because the autofix
	// in MkParser.varUseBrace checks this.
	line := t.NewLine("Makefile", 1, "\t:")

	defer fuzzer.CheckOk()
	for i := 0; i < 1000; i++ {
		tokenizer := NewShTokenizer(line, fuzzer.Generate(50))
		tokenizer.ShAtoms()
		t.Output() // Discard the output, only react on panics.
	}
	fuzzer.Ok()
}

func (s *Suite) Test_ShTokenizer_ShAtom(c *check.C) {
	t := s.Init(c)

	// testRest ensures that the given string is parsed to the expected
	// atoms, and returns the remaining text.
	testRest := func(s string, expectedAtoms []*ShAtom, expectedRest string) {
		line := t.NewLine("filename.mk", 1, "")
		p := NewShTokenizer(line, s)

		actualAtoms := p.ShAtoms()

		t.CheckEquals(p.Rest(), expectedRest)
		t.CheckEquals(len(actualAtoms), len(expectedAtoms))

		for i, actualAtom := range actualAtoms {
			if i < len(expectedAtoms) {
				t.CheckDeepEquals(actualAtom, expectedAtoms[i])
			} else {
				t.CheckDeepEquals(actualAtom, nil)
			}
		}
	}
	atoms := func(atoms ...*ShAtom) []*ShAtom { return atoms }

	// test ensures that the given string is parsed to the expected
	// atoms, and that the text is completely consumed by the parser.
	test := func(str string, expected ...*ShAtom) {
		testRest(str, expected, "")
		t.CheckOutputEmpty()
	}

	atom := func(typ ShAtomType, text string) *ShAtom {
		return &ShAtom{typ, text, shqPlain, nil}
	}

	operator := func(s string) *ShAtom { return atom(shtOperator, s) }
	comment := func(s string) *ShAtom { return atom(shtComment, s) }
	mkvar := func(varname string, modifiers ...MkVarUseModifier) *ShAtom {
		text := "${" + varname
		for _, modifier := range modifiers {
			escapedBackslash := strings.Replace(modifier.String(), "\\", "\\\\", -1)
			escapedColon := strings.Replace(escapedBackslash, ":", "\\:", -1)
			text += ":" + escapedColon // TODO: modifier.Quoted
		}
		text += "}"
		varuse := NewMkTokenBuilder().VarUse(varname, modifiers...)
		return &ShAtom{shtVaruse, text, shqPlain, varuse}
	}
	shvar := func(text, varname string) *ShAtom { return &ShAtom{shtShVarUse, text, shqPlain, varname} }
	text := func(s string) *ShAtom { return atom(shtText, s) }
	whitespace := func(s string) *ShAtom { return atom(shtSpace, s) }

	space := whitespace(" ")
	semicolon := operator(";")
	pipe := operator("|")
	subshell := atom(shtSubshell, "$$(")

	q := func(q ShQuoting) func(atom *ShAtom) *ShAtom {
		return func(atom *ShAtom) *ShAtom {
			return &ShAtom{atom.Type, atom.MkText, q, atom.data}
		}
	}
	backt := q(shqBackt)
	dquot := q(shqDquot)
	squot := q(shqSquot)
	subsh := q(shqSubsh)
	backtDquot := q(shqBacktDquot)
	backtSquot := q(shqBacktSquot)
	dquotBackt := q(shqDquotBackt)
	subshDquot := q(shqSubshDquot)
	subshSquot := q(shqSubshSquot)
	subshBackt := q(shqSubshBackt)
	dquotBacktDquot := q(shqDquotBacktDquot)
	dquotBacktSquot := q(shqDquotBacktSquot)

	// Ignore unused functions; useful for deleting some of the tests during debugging.
	use := func(args ...interface{}) {}
	use(testRest, test, atoms)
	use(operator, comment, mkvar, text, whitespace)
	use(space, semicolon, pipe, subshell, shvar)
	use(backt, dquot, squot, subsh)
	use(backtDquot, backtSquot, dquotBackt, subshDquot, subshSquot)
	use(dquotBacktDquot, dquotBacktSquot)

	test("",
		nil...)

	test("$$var",
		shvar("$$var", "var"))

	test("$$var$$var",
		shvar("$$var", "var"),
		shvar("$$var", "var"))

	test("$$var;;",
		shvar("$$var", "var"),
		operator(";;"))

	test("'single-quoted'",
		squot(text("'")),
		squot(text("single-quoted")),
		text("'"))

	test("\"",
		dquot(text("\"")))

	test("$${file%.c}.o",
		shvar("$${file%.c}", "file"),
		text(".o"))

	test("hello",
		text("hello"))

	test("hello, world",
		text("hello,"),
		space,
		text("world"))

	test("\"",
		dquot(text("\"")))

	test("`",
		backt(text("`")))

	test("`cat filename`",
		backt(text("`")),
		backt(text("cat")),
		backt(space),
		backt(text("filename")),
		text("`"))

	test("hello, \"world\"",
		text("hello,"),
		space,
		dquot(text("\"")),
		dquot(text("world")),
		text("\""))

	test("set -e;",
		text("set"),
		space,
		text("-e"),
		semicolon)

	test("cd ${WRKSRC}/doc/man/man3; PAGES=\"`ls -1 | ${SED} -e 's,3qt$$,3,'`\";",
		text("cd"),
		space,
		mkvar("WRKSRC"),
		text("/doc/man/man3"),
		semicolon,
		space,
		text("PAGES="),
		dquot(text("\"")),
		dquotBackt(text("`")),
		dquotBackt(text("ls")),
		dquotBackt(space),
		dquotBackt(text("-1")),
		dquotBackt(space),
		dquotBackt(operator("|")),
		dquotBackt(space),
		dquotBackt(mkvar("SED")),
		dquotBackt(space),
		dquotBackt(text("-e")),
		dquotBackt(space),
		dquotBacktSquot(text("'")),
		dquotBacktSquot(text("s,3qt$$,3,")),
		dquotBackt(text("'")),
		dquot(text("`")),
		text("\""),
		semicolon)

	test("ls -1 | ${SED} -e 's,3qt$$,3,'",
		text("ls"), space, text("-1"), space,
		pipe, space,
		mkvar("SED"), space, text("-e"), space,
		squot(text("'")), squot(text("s,3qt$$,3,")), text("'"))

	test("(for PAGE in $$PAGES; do ",
		operator("("),
		text("for"),
		space,
		text("PAGE"),
		space,
		text("in"),
		space,
		shvar("$$PAGES", "PAGES"),
		semicolon,
		space,
		text("do"),
		space)

	test("    ${ECHO} installing ${DESTDIR}${QTPREFIX}/man/man3/$${PAGE}; ",
		whitespace("    "),
		mkvar("ECHO"),
		space,
		text("installing"),
		space,
		mkvar("DESTDIR"),
		mkvar("QTPREFIX"),
		text("/man/man3/"),
		shvar("$${PAGE}", "PAGE"),
		semicolon,
		space)

	test("    set - X `head -1 $${PAGE}qt`; ",
		whitespace("    "),
		text("set"),
		space,
		text("-"),
		space,
		text("X"),
		space,
		backt(text("`")),
		backt(text("head")),
		backt(space),
		backt(text("-1")),
		backt(space),
		backt(shvar("$${PAGE}", "PAGE")),
		backt(text("qt")),
		text("`"),
		semicolon,
		space)

	test("`\"one word\"`",
		backt(text("`")),
		backtDquot(text("\"")),
		backtDquot(text("one word")),
		backt(text("\"")),
		text("`"))

	test("$$var \"$$var\" '$$var' `$$var`",
		shvar("$$var", "var"),
		space,
		dquot(text("\"")),
		dquot(shvar("$$var", "var")),
		text("\""),
		space,
		squot(text("'")),
		squot(shvar("$$var", "var")),
		text("'"),
		space,
		backt(text("`")),
		backt(shvar("$$var", "var")),
		text("`"))

	test("\"`'echo;echo'`\"",
		dquot(text("\"")),
		dquotBackt(text("`")),
		dquotBacktSquot(text("'")),
		dquotBacktSquot(text("echo;echo")),
		dquotBackt(text("'")),
		dquot(text("`")),
		text("\""))

	test("cat<file",
		text("cat"),
		operator("<"),
		text("file"))

	test("\\$$escaped",
		text("\\$$escaped"))

	test("-e \"s,\\$$sysconfdir/jabberd,\\$$sysconfdir,g\"",
		text("-e"),
		space,
		dquot(text("\"")),
		dquot(text("s,\\$$sysconfdir/jabberd,\\$$sysconfdir,g")),
		text("\""))

	test("echo $$, $$- $$/ $$; $$| $$,$$/$$;$$-",
		text("echo"),
		space,
		text("$$,"),
		space,
		shvar("$$-", "-"),
		space,
		text("$$/"),
		space,
		text("$$"),
		semicolon,
		space,
		text("$$"),
		pipe,
		space,
		text("$$,$$/$$"),
		semicolon,
		shvar("$$-", "-"))

	test("COMMENT=\t\\Make $$$$ fast\"",

		text("COMMENT="),
		whitespace("\t"),
		text("\\Make"),
		space,
		shvar("$$$$", "$"),
		space,
		text("fast"),
		dquot(text("\"")))

	test("var=`echo;echo|echo&echo||echo&&echo>echo`",
		text("var="),
		backt(text("`")),
		backt(text("echo")),
		backt(semicolon),
		backt(text("echo")),
		backt(operator("|")),
		backt(text("echo")),
		backt(operator("&")),
		backt(text("echo")),
		backt(operator("||")),
		backt(text("echo")),
		backt(operator("&&")),
		backt(text("echo")),
		backt(operator(">")),
		backt(text("echo")),
		text("`"))

	test("# comment",
		comment("# comment"))
	test("no#comment",
		text("no#comment"))
	test("`# comment`continue",
		backt(text("`")),
		backt(comment("# comment")),
		text("`"),
		text("continue"))
	test("`no#comment`continue",
		backt(text("`")),
		backt(text("no#comment")),
		text("`"),
		text("continue"))

	test("var=`tr 'A-Z' 'a-z'`",
		text("var="),
		backt(text("`")),
		backt(text("tr")),
		backt(space),
		backtSquot(text("'")),
		backtSquot(text("A-Z")),
		backt(text("'")),
		backt(space),
		backtSquot(text("'")),
		backtSquot(text("a-z")),
		backt(text("'")),
		text("`"))

	test("var=\"`echo \"\\`echo foo\\`\"`\"",
		text("var="),
		dquot(text("\"")),
		dquotBackt(text("`")),
		dquotBackt(text("echo")),
		dquotBackt(space),
		dquotBacktDquot(text("\"")),
		dquotBacktDquot(text("\\`echo foo\\`")), // One atom, since it doesn't influence parsing.
		dquotBackt(text("\"")),
		dquot(text("`")),
		text("\""))

	test("if cond1; then action1; elif cond2; then action2; else action3; fi",
		text("if"), space, text("cond1"), semicolon, space,
		text("then"), space, text("action1"), semicolon, space,
		text("elif"), space, text("cond2"), semicolon, space,
		text("then"), space, text("action2"), semicolon, space,
		text("else"), space, text("action3"), semicolon, space,
		text("fi"))

	test("$$(cat)",
		subsh(subshell),
		subsh(text("cat")),
		operator(")"))

	test("$$(cat 'file')",
		subsh(subshell),
		subsh(text("cat")),
		subsh(space),
		subshSquot(text("'")),
		subshSquot(text("file")),
		subsh(text("'")),
		operator(")"))

	test("$$(# comment) arg",
		subsh(subshell),
		subsh(comment("# comment")),
		operator(")"),
		space,
		text("arg"))

	test("$$(echo \"first\" 'second')",
		subsh(subshell),
		subsh(text("echo")),
		subsh(space),
		subshDquot(text("\"")),
		subshDquot(text("first")),
		subsh(text("\"")),
		subsh(space),
		subshSquot(text("'")),
		subshSquot(text("second")),
		subsh(text("'")),
		operator(")"))

	test("$$(echo `echo nested-subshell`)",
		subsh(subshell),
		subsh(text("echo")),
		subsh(space),
		subshBackt(text("`")),
		subshBackt(text("echo")),
		subshBackt(space),
		subshBackt(text("nested-subshell")),
		subsh(operator("`")),
		operator(")"))

	// Subshell with unbalanced parentheses. Many shells (and pkglint)
	// fail this test, therefore please don't write code like this.
	//
	// See NetBSD/src/build.sh, around line 160.
	test("var=$$(case x in x) still-subshell;; esac);",
		text("var="), subsh(subshell),
		subsh(text("case")), subsh(space), subsh(text("x")), subsh(space),
		subsh(text("in")), subsh(space), subsh(text("x")),
		// XXX: The parenthesis is for the case pattern, not the end of the subshell.
		operator(")"), space,
		text("still-subshell"), operator(";;"), space,
		text("esac"), operator(")"), operator(";"))

	testRest("`echo \\${VAR}`",
		atoms(
			backt(text("`")),
			backt(text("echo")),
			backt(space)),
		"\\${VAR}`")
	t.CheckOutputLines(
		"WARN: filename.mk:1: Internal pkglint error " +
			"in ShTokenizer.ShAtom at \"\\\\${VAR}`\" (quoting=b).")

	// The remaining tokens are shortened in the warning.
	testRest("`echo \\${VAR.123456789012345678901234567890}`",
		atoms(
			backt(text("`")),
			backt(text("echo")),
			backt(space)),
		"\\${VAR.123456789012345678901234567890}`")
	t.CheckOutputLines(
		"WARN: filename.mk:1: Internal pkglint error in ShTokenizer.ShAtom " +
			"at \"\\\\${VAR.1234567890123...\" (quoting=b).")
}

func (s *Suite) Test_ShTokenizer_ShAtom__quoting(c *check.C) {
	t := s.Init(c)

	test := func(input, expectedOutput string) {
		line := t.NewLine("filename.mk", 1, "")
		p := NewShTokenizer(line, input)
		q := shqPlain
		result := ""
		for {
			token := p.ShAtom(q)
			if token == nil {
				break
			}
			result += token.MkText
			if token.Quoting != q {
				q = token.Quoting
				result += "[" + q.String() + "]"
			}
		}
		t.CheckEquals(result, expectedOutput)
		t.CheckEquals(p.Rest(), "")
	}

	test("hello, world", "hello, world")
	test("hello, \"world\"", "hello, \"[d]world\"[plain]")
	test("1 \"\" 2 '' 3 `` 4", "1 \"[d]\"[plain] 2 '[s]'[plain] 3 `[b]`[plain] 4")
	test("\"\"", "\"[d]\"[plain]")
	test("''", "'[s]'[plain]")
	test("``", "`[b]`[plain]")
	test("x\"x`x`x\"x'x\"x'", "x\"[d]x`[db]x`[d]x\"[plain]x'[s]x\"x'[plain]")
	test("x\"x`x'x'x`x\"", "x\"[d]x`[db]x'[dbs]x'[db]x`[d]x\"[plain]")
	test("x\\\"x\\'x\\`x\\\\", "x\\\"x\\'x\\`x\\\\")
	test("x\"x\\\"x\\'x\\`x\\\\", "x\"[d]x\\\"x\\'x\\`x\\\\")
	test("x'x\\\"x\\'x\\`x\\\\", "x'[s]x\\\"x\\'[plain]x\\`x\\\\")
	test("x`x\\\"x\\'x\\`x\\\\", "x`[b]x\\\"x\\'x\\`x\\\\")
}

// The switch statement in ShTokenizer.ShAtom is exhaustive.
// If a new quoting mode is added (in which case the shell tokenizer
// should rather be rewritten completely and correctly), it is ok
// to panic if ShQuoting is not adjusted in the same commit.
func (s *Suite) Test_ShTokenizer_ShAtom__internal_error(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename.mk", 123, "\ttoken")
	tok := NewShTokenizer(line, line.Text)
	t.ExpectPanicMatches(
		func() { tok.ShAtom(^ShQuoting(0)) },
		// Normalize the panic message, for Go < 12 if I remember correctly.
		`^runtime error: index out of range.*`)
}

func (s *Suite) Test_ShTokenizer_shVarUse(c *check.C) {
	t := s.Init(c)

	test := func(input string, output *ShAtom, rest string) {
		tok := NewShTokenizer(nil, input)
		actual := tok.shVarUse(shqPlain)

		t.CheckDeepEquals(actual, output)
		t.CheckEquals(tok.Rest(), rest)
	}

	shvar := func(text, varname string) *ShAtom {
		return &ShAtom{shtShVarUse, text, shqPlain, varname}
	}

	test("$", nil, "$")
	test("$$", nil, "$$")
	test("${MKVAR}", nil, "${MKVAR}")

	test("$$a", shvar("$$a", "a"), "")
	test("$$a.", shvar("$$a", "a"), ".")
	test("$$a_b_123:", shvar("$$a_b_123", "a_b_123"), ":")
	test("$$123", shvar("$$1", "1"), "23")

	test("$${varname}", shvar("$${varname}", "varname"), "")
	test("$${varname}.", shvar("$${varname}", "varname"), ".")
	test("$${0123}.", shvar("$${0123}", "0123"), ".")
	test("$${varname", nil, "$${varname")

	test("$${var:=value}", shvar("$${var:=value}", "var"), "")
	test("$${var#value}", shvar("$${var#value}", "var"), "")
	test("$${var##value}", shvar("$${var##value}", "var"), "")
	test("$${var##*}", shvar("$${var##*}", "var"), "")
	test("$${var%\".gz\"}", shvar("$${var%\".gz\"}", "var"), "")

	// TODO: allow variables in patterns.
	test("$${var%.${ext}}", nil, "$${var%.${ext}}")

	test("$${var##*", nil, "$${var##*")
	test("$${var\"", nil, "$${var\"")

	// TODO: test("$${var%${EXT}}", shvar("$${var%${EXT}}", "var"), "")
	test("$${var%${EXT}}", nil, "$${var%${EXT}}")

	// TODO: length of var
	test("$${#var}", nil, "$${#var}")

	test("$${/}", nil, "$${/}")
	test("$${\\}", nil, "$${\\}")
}

func (s *Suite) Test_ShTokenizer_ShToken(c *check.C) {
	t := s.Init(c)

	// testRest ensures that the given string is parsed to the expected
	// tokens, and returns the remaining text.
	testRest := func(str string, expected ...string) string {
		line := t.NewLine("testRest.mk", 1, "")
		p := NewShTokenizer(line, str)
		for _, exp := range expected {
			t.CheckEquals(p.ShToken().MkText, exp)
		}
		return p.Rest()
	}

	test := func(str string, expected ...string) {
		line := t.NewLine("test.mk", 1, "")
		p := NewShTokenizer(line, str)
		for _, exp := range expected {
			t.CheckEquals(p.ShToken().MkText, exp)
		}
		t.CheckEquals(p.Rest(), "")
		t.CheckOutputEmpty()
	}

	testNil := func(str string) {
		line := t.NewLine("testNil.mk", 1, "")
		p := NewShTokenizer(line, str)
		t.CheckNil(p.ShToken())
		t.CheckEquals(p.Rest(), "")
		t.CheckOutputEmpty()
	}

	testNil("")
	testNil(" ")
	rest := testRest("\t\t\t\n\n\n\n\t ",
		"\n\n\n\n")
	t.CheckEquals(rest, "\t ")

	test("echo",
		"echo")

	test("`cat file`",
		"`cat file`")

	test("PAGES=\"`ls -1 | ${SED} -e 's,3qt$$,3,'`\"",
		"PAGES=\"`ls -1 | ${SED} -e 's,3qt$$,3,'`\"")

	test("echo hello, world",
		"echo",
		"hello,",
		"world")

	test("if cond1; then action1; elif cond2; then action2; else action3; fi",
		"if", "cond1", ";", "then",
		"action1", ";",
		"elif", "cond2", ";", "then",
		"action2", ";",
		"else", "action3", ";",
		"fi")

	test("PATH=/nonexistent env PATH=${PATH:Q} true",
		"PATH=/nonexistent",
		"env",
		"PATH=${PATH:Q}",
		"true")

	test("id=$$(id)",
		"id=$$(id)")

	test("id=$$(${AWK} '{print}' < ${WRKSRC}/idfile)",
		"id=$$(${AWK} '{print}' < ${WRKSRC}/idfile)")

	test("id=`${AWK} '{print}' < ${WRKSRC}/idfile`",
		"id=`${AWK} '{print}' < ${WRKSRC}/idfile`")
}
