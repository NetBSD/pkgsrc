package main

import (
	"gopkg.in/check.v1"
	"strings"
)

func (s *Suite) Test_ShTokenizer_ShAtom(c *check.C) {
	t := s.Init(c)

	// checkRest ensures that the given string is parsed to the expected
	// atoms, and returns the remaining text.
	checkRest := func(s string, expected ...*ShAtom) string {
		p := NewShTokenizer(dummyLine, s, false)
		q := shqPlain
		for _, exp := range expected {
			c.Check(p.ShAtom(q), deepEquals, exp)
			q = exp.Quoting
		}
		return p.Rest()
	}

	// test ensures that the given string is parsed to the expected
	// atoms, and that the text is completely consumed by the parser.
	test := func(str string, expected ...*ShAtom) {
		rest := checkRest(str, expected...)
		c.Check(rest, equals, "")
		t.CheckOutputEmpty()
	}

	atom := func(typ ShAtomType, text string) *ShAtom {
		return &ShAtom{typ, text, shqPlain, nil}
	}

	operator := func(s string) *ShAtom { return atom(shtOperator, s) }
	comment := func(s string) *ShAtom { return atom(shtComment, s) }
	mkvar := func(varname string, modifiers ...string) *ShAtom {
		text := "${" + varname
		for _, modifier := range modifiers {
			text += ":" + strings.Replace(strings.Replace(modifier, "\\", "\\\\", -1), ":", "\\:", -1)
		}
		text += "}"
		varuse := NewMkVarUse(varname, modifiers...)
		return &ShAtom{shtVaruse, text, shqPlain, varuse}
	}
	shvar := func(text, varname string) *ShAtom { return &ShAtom{shtShVarUse, text, shqPlain, varname} }
	text := func(s string) *ShAtom { return atom(shtText, s) }
	whitespace := func(s string) *ShAtom { return atom(shtSpace, s) }

	space := whitespace(" ")
	semicolon := operator(";")
	pipe := operator("|")
	subshell := atom(shtSubshell, "$$(")

	q := func(q ShQuoting, atom *ShAtom) *ShAtom {
		return &ShAtom{atom.Type, atom.MkText, q, atom.data}
	}
	backt := func(atom *ShAtom) *ShAtom { return q(shqBackt, atom) }
	dquot := func(atom *ShAtom) *ShAtom { return q(shqDquot, atom) }
	squot := func(atom *ShAtom) *ShAtom { return q(shqSquot, atom) }
	subsh := func(atom *ShAtom) *ShAtom { return q(shqSubsh, atom) }
	backtDquot := func(atom *ShAtom) *ShAtom { return q(shqBacktDquot, atom) }
	backtSquot := func(atom *ShAtom) *ShAtom { return q(shqBacktSquot, atom) }
	dquotBackt := func(atom *ShAtom) *ShAtom { return q(shqDquotBackt, atom) }
	subshDquot := func(atom *ShAtom) *ShAtom { return q(shqSubshDquot, atom) }
	subshSquot := func(atom *ShAtom) *ShAtom { return q(shqSubshSquot, atom) }
	dquotBacktDquot := func(atom *ShAtom) *ShAtom { return q(shqDquotBacktDquot, atom) }
	dquotBacktSquot := func(atom *ShAtom) *ShAtom { return q(shqDquotBacktSquot, atom) }

	// Ignore unused functions; useful for deleting some of the tests during debugging.
	use := func(args ...interface{}) {}
	use(checkRest, test)
	use(operator, comment, mkvar, text, whitespace)
	use(space, semicolon, pipe, subshell)
	use(backt, dquot, squot, subsh)
	use(backtDquot, backtSquot, dquotBackt, subshDquot, subshSquot)
	use(dquotBacktDquot, dquotBacktSquot)

	test("" /* none */)

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

	rest := checkRest("\"" /* none */)
	c.Check(rest, equals, "\"")

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

	rest = checkRest("COMMENT=\t\\Make $$$$ fast\"",
		text("COMMENT="),
		whitespace("\t"),
		text("\\Make"),
		space,
		shvar("$$$$", "$"),
		space,
		text("fast"))
	c.Check(rest, equals, "\"")

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
		text(")"))

	test("$$(cat 'file')",
		subsh(subshell),
		subsh(text("cat")),
		subsh(space),
		subshSquot(text("'")),
		subshSquot(text("file")),
		subsh(text("'")),
		text(")"))

	test("$$(# comment) arg",
		subsh(subshell),
		subsh(comment("# comment")),
		text(")"),
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
		text(")"))
}

func (s *Suite) Test_ShTokenizer_ShAtom__quoting(c *check.C) {
	checkQuotingChange := func(input, expectedOutput string) {
		p := NewShTokenizer(dummyLine, input, false)
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
		c.Check(result, equals, expectedOutput)
		c.Check(p.Rest(), equals, "")
	}

	checkQuotingChange("hello, world", "hello, world")
	checkQuotingChange("hello, \"world\"", "hello, \"[d]world\"[plain]")
	checkQuotingChange("1 \"\" 2 '' 3 `` 4", "1 \"[d]\"[plain] 2 '[s]'[plain] 3 `[b]`[plain] 4")
	checkQuotingChange("\"\"", "\"[d]\"[plain]")
	checkQuotingChange("''", "'[s]'[plain]")
	checkQuotingChange("``", "`[b]`[plain]")
	checkQuotingChange("x\"x`x`x\"x'x\"x'", "x\"[d]x`[db]x`[d]x\"[plain]x'[s]x\"x'[plain]")
	checkQuotingChange("x\"x`x'x'x`x\"", "x\"[d]x`[db]x'[dbs]x'[db]x`[d]x\"[plain]")
	checkQuotingChange("x\\\"x\\'x\\`x\\\\", "x\\\"x\\'x\\`x\\\\")
	checkQuotingChange("x\"x\\\"x\\'x\\`x\\\\", "x\"[d]x\\\"x\\'x\\`x\\\\")
	checkQuotingChange("x'x\\\"x\\'x\\`x\\\\", "x'[s]x\\\"x\\'[plain]x\\`x\\\\")
	checkQuotingChange("x`x\\\"x\\'x\\`x\\\\", "x`[b]x\\\"x\\'x\\`x\\\\")
}

func (s *Suite) Test_ShTokenizer_ShToken(c *check.C) {
	t := s.Init(c)

	// testRest ensures that the given string is parsed to the expected
	// tokens, and returns the remaining text.
	testRest := func(str string, expected ...string) string {
		p := NewShTokenizer(dummyLine, str, false)
		for _, exp := range expected {
			c.Check(p.ShToken().MkText, equals, exp)
		}
		return p.Rest()
	}
	test := func(str string, expected ...string) {
		p := NewShTokenizer(dummyLine, str, false)
		for _, exp := range expected {
			c.Check(p.ShToken().MkText, equals, exp)
		}
		c.Check(p.Rest(), equals, "")
		t.CheckOutputEmpty()
	}
	checkNil := func(str string) {
		p := NewShTokenizer(dummyLine, str, false)
		c.Check(p.ShToken(), check.IsNil)
		c.Check(p.Rest(), equals, "")
		t.CheckOutputEmpty()
	}

	checkNil("")
	checkNil(" ")
	rest := testRest("\t\t\t\n\n\n\n\t ",
		"\n",
		"\n", // TODO: Why three separators? One should be enough. What does the grammar say?
		"\n")
	c.Check(rest, equals, "\n\t ") // TODO: Why is the newline still here?

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

	test("id=$$(${AWK} '{print}' < ${WRKSRC}/idfile)",
		"id=$$(${AWK} '{print}' < ${WRKSRC}/idfile)")

	test("id=`${AWK} '{print}' < ${WRKSRC}/idfile`",
		"id=`${AWK} '{print}' < ${WRKSRC}/idfile`")
}

func (s *Suite) Test_ShTokenizer_shVarUse(c *check.C) {

	test := func(input string, output *ShAtom, rest string) {
		tok := NewShTokenizer(nil, input, false)
		actual := tok.shVarUse(shqPlain)

		c.Check(actual, deepEquals, output)
		c.Check(tok.Rest(), equals, rest)
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

func (s *Suite) Test_ShTokenizer__examples_from_fuzzing(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("fuzzing.mk",
		MkRcsID,
		"",
		"pre-configure:",

		// Covers shAtomBacktDquot: return nil.
		// These are nested backticks with double quotes,
		// which should be avoided since POSIX marks them as unspecified.
		"\t"+"`\"`",

		// Covers shAtomBacktSquot: return nil
		"\t"+"`'$`",

		// Covers shAtomDquotBacktSquot: return nil
		"\t"+"\"`'`y",

		// Covers shAtomDquotBackt: return nil
		// FIXME: Pkglint must parse unescaped dollar in the same way, everywhere.
		"\t"+"\"`$|",

		// Covers shAtomDquotBacktDquot: return nil
		// FIXME: Pkglint must support unlimited nesting.
		"\t"+"\"`\"`",

		// Covers shAtomSubshDquot: return nil
		"\t"+"$$(\"'",

		// Covers shAtomSubsh: case lexer.AdvanceStr("`")
		"\t"+"$$(`",

		// Covers shAtomSubshSquot: return nil
		"\t"+"$$('$)",

		// Covers shAtomDquotBackt: case lexer.AdvanceRegexp("^#[^`]*")
		"\t"+"\"`# comment")

	mklines.Check()

	// Just good that these redundant error messages don't occur every day.
	t.CheckOutputLines(
		"WARN: fuzzing.mk:4: Pkglint parse error in ShTokenizer.ShAtom at \"`\" (quoting=bd).",
		"WARN: fuzzing.mk:4: Pkglint ShellLine.CheckShellCommand: parse error at []string{\"\"}",

		"WARN: fuzzing.mk:5: Pkglint parse error in ShTokenizer.ShAtom at \"$`\" (quoting=bs).",
		"WARN: fuzzing.mk:5: Pkglint ShellLine.CheckShellCommand: parse error at []string{\"\"}",
		"WARN: fuzzing.mk:5: Pkglint parse error in MkLine.Tokenize at \"$`\".",

		"WARN: fuzzing.mk:6: Pkglint ShellLine.CheckShellCommand: parse error at []string{\"\"}",

		"WARN: fuzzing.mk:7: Pkglint parse error in ShTokenizer.ShAtom at \"$|\" (quoting=db).",
		"WARN: fuzzing.mk:7: Pkglint ShellLine.CheckShellCommand: parse error at []string{\"\"}",
		"WARN: fuzzing.mk:7: Pkglint parse error in MkLine.Tokenize at \"$|\".",

		"WARN: fuzzing.mk:8: Pkglint parse error in ShTokenizer.ShAtom at \"`\" (quoting=dbd).",
		"WARN: fuzzing.mk:8: Pkglint ShellLine.CheckShellCommand: parse error at []string{\"\"}",

		"WARN: fuzzing.mk:9: Invoking subshells via $(...) is not portable enough.",

		"WARN: fuzzing.mk:10: Pkglint parse error in ShTokenizer.ShAtom at \"`\" (quoting=S).",
		"WARN: fuzzing.mk:10: Invoking subshells via $(...) is not portable enough.",

		"WARN: fuzzing.mk:11: Pkglint parse error in ShTokenizer.ShAtom at \"$)\" (quoting=Ss).",
		"WARN: fuzzing.mk:11: Invoking subshells via $(...) is not portable enough.",
		"WARN: fuzzing.mk:11: Pkglint parse error in MkLine.Tokenize at \"$)\".",

		"WARN: fuzzing.mk:12: Pkglint ShellLine.CheckShellCommand: parse error at []string{\"\"}")
}

func (s *Suite) Test_ShTokenizer__fuzzing(c *check.C) {
	t := s.Init(c)

	fuzzer := NewFuzzer()
	fuzzer.Char("\"'`$();|_#", 10)
	fuzzer.Range('a', 'z', 5)

	defer fuzzer.CheckOk()
	for i := 0; i < 1000; i++ {
		tokenizer := NewShTokenizer(dummyLine, fuzzer.Generate(50), false)
		tokenizer.ShAtoms()
		t.Output() // Discard the output, only react on fatal errors.
	}
	fuzzer.Ok()
}
