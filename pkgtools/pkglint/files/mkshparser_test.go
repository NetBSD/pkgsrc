package pkglint

import (
	"encoding/json"
	"fmt"
	"gopkg.in/check.v1"
)

func (s *Suite) Test_parseShellProgram__parse_error_for_dollar(c *check.C) {
	t := s.Init(c)

	test := func(text string, expProgram *MkShList, expError error, expDiagnostics ...string) {
		mklines := t.NewMkLines("module.mk", "\t"+text)

		mklines.ForEach(func(mkline *MkLine) {
			program, err := parseShellProgram(mkline.Line, text)

			if err == nil {
				c.Check(err, equals, expError)
			} else {
				c.Check(err, deepEquals, expError)
				c.Check(program, deepEquals, expProgram)
			}

			t.CheckOutput(expDiagnostics)
		})
	}

	test("$$",
		nil,
		nil,
		nil...)

	test(
		"$${",
		nil,
		fmt.Errorf("splitIntoShellTokens couldn't parse \"$${\""),
		"WARN: module.mk:1: Unclosed shell variable starting at \"$${\".")

	test(
		"$$;",
		nil,
		nil,
		nil...)

	test(
		"shell$$;",
		nil,
		nil,
		nil...)
}

type ShSuite struct {
	c *check.C
}

var _ = check.Suite(&ShSuite{})

func (s *ShSuite) SetUpTest(c *check.C) {
	G = NewPkglint()
}

func (s *ShSuite) TearDownTest(c *check.C) {
	G = unusablePkglint()
}

func (s *ShSuite) Test_ShellParser__program(c *check.C) {
	b := s.init(c)

	s.test("",
		b.List())

	s.test("echo ;",
		b.List().AddCommand(b.SimpleCommand("echo")).AddSemicolon())

	s.test("echo",
		b.List().AddCommand(b.SimpleCommand("echo")))

	s.test(""+
		"cd ${WRKSRC} "+
		"&& ${FIND} ${${_list_}} -type f ! -name '*.orig' 2> /dev/null "+
		"| pax -rw -pm ${DESTDIR}${PREFIX}/${${_dir_}}",
		b.List().AddAndOr(b.AndOr(
			b.Pipeline(false, b.SimpleCommand("cd", "${WRKSRC}"))).Add("&&",
			b.Pipeline(false,
				b.SimpleCommand("${FIND}", "${${_list_}}", "-type", "f", "!", "-name", "'*.orig'", "2>/dev/null"),
				b.SimpleCommand("pax", "-rw", "-pm", "${DESTDIR}${PREFIX}/${${_dir_}}")))))

	s.test("${CAT} ${PKGDIR}/PLIST | while read entry ; do : ; done",
		b.List().AddAndOr(b.AndOr(b.Pipeline(false,
			b.SimpleCommand("${CAT}", "${PKGDIR}/PLIST"),
			b.While(
				b.List().AddCommand(b.SimpleCommand("read", "entry")).AddSemicolon(),
				b.List().AddCommand(b.SimpleCommand(":")).AddSemicolon())))))

	s.test("while read entry ; do case \"$$entry\" in include/c-client/* ) ${INSTALL_DATA} $$src $$dest ; esac ; done",
		b.List().AddCommand(b.While(
			b.List().AddCommand(b.SimpleCommand("read", "entry")).AddSemicolon(),
			b.List().AddCommand(b.Case(
				b.Token("\"$$entry\""),
				b.CaseItem(
					b.Words("include/c-client/*"),
					b.List().AddCommand(b.SimpleCommand("${INSTALL_DATA}", "$$src", "$$dest")),
					sepSemicolon))).AddSemicolon())))

	s.test("command | while condition ; do case selector in pattern ) : ; esac ; done",
		b.List().AddAndOr(b.AndOr(b.Pipeline(false,
			b.SimpleCommand("command"),
			b.While(
				b.List().AddCommand(b.SimpleCommand("condition")).AddSemicolon(),
				b.List().AddCommand(b.Case(
					b.Token("selector"),
					b.CaseItem(
						b.Words("pattern"),
						b.List().AddCommand(b.SimpleCommand(":")),
						sepSemicolon))).AddSemicolon())))))

	s.test("command1 \n command2 \n command3",
		b.List().
			AddCommand(b.SimpleCommand("command1")).
			AddNewline().
			AddCommand(b.SimpleCommand("command2")).
			AddNewline().
			AddCommand(b.SimpleCommand("command3")))

	s.test("if condition; then action; else case selector in pattern) case-item-action ;; esac; fi",
		b.List().AddCommand(b.If(
			b.List().AddCommand(b.SimpleCommand("condition")).AddSemicolon(),
			b.List().AddCommand(b.SimpleCommand("action")).AddSemicolon(),
			b.List().AddCommand(b.Case(
				b.Token("selector"),
				b.CaseItem(
					b.Words("pattern"),
					b.List().AddCommand(b.SimpleCommand("case-item-action")), sepNone))).AddSemicolon())))

	s.test("if condition; then action; elif condition2; then action2; fi",
		b.List().AddCommand(b.If(
			b.List().AddCommand(b.SimpleCommand("condition")).AddSemicolon(),
			b.List().AddCommand(b.SimpleCommand("action")).AddSemicolon(),
			b.List().AddCommand(b.SimpleCommand("condition2")).AddSemicolon(),
			b.List().AddCommand(b.SimpleCommand("action2")).AddSemicolon())))
}

func (s *ShSuite) Test_ShellParser__list(c *check.C) {
	b := s.init(c)

	s.test("echo1 && echo2",
		b.List().AddAndOr(
			b.AndOr(b.Pipeline(false, b.SimpleCommand("echo1"))).
				Add("&&", b.Pipeline(false, b.SimpleCommand("echo2")))))

	s.test("echo1 ; echo2",
		b.List().
			AddCommand(b.SimpleCommand("echo1")).
			AddSemicolon().
			AddCommand(b.SimpleCommand("echo2")))

	s.test("echo1 ; echo2 &",
		b.List().
			AddCommand(b.SimpleCommand("echo1")).
			AddSemicolon().
			AddCommand(b.SimpleCommand("echo2")).
			AddBackground())
}

func (s *ShSuite) Test_ShellParser__and_or(c *check.C) {
	b := s.init(c)

	s.test("echo1 | echo2",
		b.List().AddAndOr(b.AndOr(b.Pipeline(false,
			b.SimpleCommand("echo1"),
			b.SimpleCommand("echo2")))))

	s.test("echo1 | echo2 && echo3 | echo4",
		b.List().AddAndOr(b.AndOr(
			b.Pipeline(false,
				b.SimpleCommand("echo1"),
				b.SimpleCommand("echo2")),
		).Add("&&",
			b.Pipeline(false,
				b.SimpleCommand("echo3"),
				b.SimpleCommand("echo4")))))

	s.test("echo1 | echo2 || ! echo3 | echo4",
		b.List().AddAndOr(b.AndOr(
			b.Pipeline(false,
				b.SimpleCommand("echo1"),
				b.SimpleCommand("echo2")),
		).Add("||",
			b.Pipeline(true,
				b.SimpleCommand("echo3"),
				b.SimpleCommand("echo4")))))
}

func (s *ShSuite) Test_ShellParser__pipeline(c *check.C) {
	b := s.init(c)

	s.test("command1 | command2",
		b.List().AddAndOr(b.AndOr(b.Pipeline(false,
			b.SimpleCommand("command1"),
			b.SimpleCommand("command2")))))

	s.test("! command1 | command2",
		b.List().AddAndOr(b.AndOr(b.Pipeline(true,
			b.SimpleCommand("command1"),
			b.SimpleCommand("command2")))))
}

func (s *ShSuite) Test_ShellParser__pipe_sequence(c *check.C) {
	b := s.init(c)

	s.test("command1 | if true ; then : ; fi",
		b.List().AddAndOr(b.AndOr(b.Pipeline(false,
			b.SimpleCommand("command1"),
			b.If(
				b.List().AddCommand(b.SimpleCommand("true")).AddSemicolon(),
				b.List().AddCommand(b.SimpleCommand(":")).AddSemicolon())))))
}

func (s *ShSuite) Test_ShellParser__command(c *check.C) {
	b := s.init(c)

	s.test("simple_command",
		b.List().AddAndOr(b.AndOr(b.Pipeline(false, b.SimpleCommand("simple_command")))))

	s.test("while 1; do 2; done",
		b.List().AddAndOr(b.AndOr(b.Pipeline(false,
			b.While(
				b.List().AddCommand(b.SimpleCommand("1")).AddSemicolon(),
				b.List().AddCommand(b.SimpleCommand("2")).AddSemicolon())))))

	s.test("while 1; do 2; done 1>&2",
		b.List().AddAndOr(b.AndOr(b.Pipeline(false,
			b.While(
				b.List().AddCommand(b.SimpleCommand("1")).AddSemicolon(),
				b.List().AddCommand(b.SimpleCommand("2")).AddSemicolon(),
				b.Redirection(1, ">&", "2"))))))

	s.test("func(){ echo hello;} 2>&1",
		b.List().AddCommand(b.Function(
			"func",
			b.Brace(b.List().AddCommand(b.SimpleCommand("echo", "hello")).AddSemicolon()).Compound,
			b.Redirection(2, ">&", "1"))))
}

func (s *ShSuite) Test_ShellParser__compound_command(c *check.C) {
	b := s.init(c)

	s.test("{ brace ; }",
		b.List().AddCommand(b.Brace(
			b.List().AddCommand(b.SimpleCommand("brace")).AddSemicolon())))

	s.test("( subshell )",
		b.List().AddCommand(b.Subshell(
			b.List().AddCommand(b.SimpleCommand("subshell")))))

	s.test("for i in * ; do echo $i ; done",
		b.List().AddCommand(b.For(
			"i",
			b.Words("*"),
			b.List().AddCommand(b.SimpleCommand("echo", "$i")).AddSemicolon())))

	s.test("case $i in esac",
		b.List().AddCommand(b.Case(
			b.Token("$i"))))

}

func (s *ShSuite) Test_ShellParser__subshell(c *check.C) {
	b := s.init(c)

	sub3 := b.Subshell(b.List().AddCommand(b.SimpleCommand("sub3")))
	sub2 := b.Subshell(b.List().AddCommand(sub3).AddSemicolon().AddCommand(b.SimpleCommand("sub2")))
	sub1 := b.Subshell(b.List().AddCommand(sub2).AddSemicolon().AddCommand(b.SimpleCommand("sub1")))
	s.test("( ( ( sub3 ) ; sub2 ) ; sub1 )", b.List().AddCommand(sub1))
}

func (s *ShSuite) Test_ShellParser__compound_list(c *check.C) {
	b := s.init(c)

	s.test("( \n echo )",
		b.List().AddCommand(b.Subshell(
			b.List().AddCommand(b.SimpleCommand("echo")))))
}

func (s *ShSuite) Test_ShellParser__term(c *check.C) {
	b := s.init(c)

	s.test("echo1 ; echo2 ;",
		b.List().
			AddCommand(b.SimpleCommand("echo1")).
			AddSemicolon().
			AddCommand(b.SimpleCommand("echo2")).
			AddSemicolon())
}

func (s *ShSuite) Test_ShellParser__for_clause(c *check.C) {
	b := s.init(c)

	// If this test fails, the cause might be in shell.y, in the for_clause rule.
	s.test("for var do echo $var ; done",
		b.List().AddCommand(b.For(
			"var",
			b.Words("\"$$@\""),
			b.List().AddCommand(b.SimpleCommand("echo", "$var")).AddSemicolon())))

	// Only linebreak is allowed, but not semicolon.
	s.test("for var \n do echo $var ; done",
		b.List().AddCommand(b.For(
			"var",
			b.Words("\"$$@\""),
			b.List().AddCommand(b.SimpleCommand("echo", "$var")).AddSemicolon())))

	s.test("for var in a b c ; do echo $var ; done",
		b.List().AddCommand(b.For(
			"var",
			b.Words("a", "b", "c"),
			b.List().AddCommand(b.SimpleCommand("echo", "$var")).AddSemicolon())))

	s.test("for var \n \n \n in a b c ; do echo $var ; done",
		b.List().AddCommand(b.For(
			"var",
			b.Words("a", "b", "c"),
			b.List().AddCommand(b.SimpleCommand("echo", "$var")).AddSemicolon())))

	s.test("for var in in esac ; do echo $var ; done",
		b.List().AddCommand(b.For(
			"var",
			b.Words("in", "esac"),
			b.List().AddCommand(b.SimpleCommand("echo", "$var")).AddSemicolon())))

	// No semicolon necessary between the two "done".
	s.test("for i in 1; do for j in 1; do echo $$i$$j; done done",
		b.List().AddCommand(b.For(
			"i",
			b.Words("1"),
			b.List().AddCommand(b.For(
				"j",
				b.Words("1"),
				b.List().AddCommand(b.SimpleCommand("echo", "$$i$$j")).AddSemicolon())))))
}

func (s *ShSuite) Test_ShellParser__case_clause(c *check.C) {
	b := s.init(c)

	s.test("case $var in esac",
		b.List().AddCommand(b.Case(b.Token("$var"))))

	s.test("case selector in pattern) ;; pattern) esac",
		b.List().AddCommand(b.Case(
			b.Token("selector"),
			b.CaseItem(b.Words("pattern"), b.List(), sepNone),
			b.CaseItem(b.Words("pattern"), b.List(), sepNone))))

	s.test("case $$i in *.c | *.h ) echo C ;; * ) echo Other ; esac",
		b.List().AddCommand(b.Case(
			b.Token("$$i"),
			b.CaseItem(b.Words("*.c", "*.h"), b.List().AddCommand(b.SimpleCommand("echo", "C")), sepNone),
			b.CaseItem(b.Words("*"), b.List().AddCommand(b.SimpleCommand("echo", "Other")), sepSemicolon))))

	s.test("case $$i in *.c ) echo ; esac",
		b.List().AddCommand(b.Case(
			b.Token("$$i"),
			b.CaseItem(b.Words("*.c"), b.List().AddCommand(b.SimpleCommand("echo")), sepSemicolon))))

	s.test("case selector in pattern) case-item-action ; esac",
		b.List().AddCommand(b.Case(
			b.Token("selector"),
			b.CaseItem(
				b.Words("pattern"),
				b.List().AddCommand(b.SimpleCommand("case-item-action")), sepSemicolon))))

	s.test("case selector in pattern) case-item-action ;; esac",
		b.List().AddCommand(b.Case(
			b.Token("selector"),
			b.CaseItem(
				b.Words("pattern"),
				b.List().AddCommand(b.SimpleCommand("case-item-action")), sepNone))))

	s.test("case $$expr in (if|then|else) ;; esac",
		b.List().AddCommand(b.Case(
			b.Token("$$expr"),
			b.CaseItem(
				b.Words("if", "then", "else"),
				b.List(), sepNone))))
}

func (s *ShSuite) Test_ShellParser__if_clause(c *check.C) {
	b := s.init(c)

	s.test(
		"if true ; then echo yes ; else echo no ; fi",
		b.List().AddCommand(b.If(
			b.List().AddCommand(b.SimpleCommand("true")).AddSemicolon(),
			b.List().AddCommand(b.SimpleCommand("echo", "yes")).AddSemicolon(),
			b.List().AddCommand(b.SimpleCommand("echo", "no")).AddSemicolon())))

	// No semicolon necessary between the two "fi".
	s.test("if cond1; then if cond2; then action; fi fi",
		b.List().AddCommand(b.If(
			b.List().AddCommand(b.SimpleCommand("cond1")).AddSemicolon(),
			b.List().AddCommand(b.If(
				b.List().AddCommand(b.SimpleCommand("cond2")).AddSemicolon(),
				b.List().AddCommand(b.SimpleCommand("action")).AddSemicolon())))))
}

func (s *ShSuite) Test_ShellParser__while_clause(c *check.C) {
	b := s.init(c)

	s.test("while condition ; do action ; done",
		b.List().AddCommand(b.While(
			b.List().AddCommand(b.SimpleCommand("condition")).AddSemicolon(),
			b.List().AddCommand(b.SimpleCommand("action")).AddSemicolon())))
}

func (s *ShSuite) Test_ShellParser__until_clause(c *check.C) {
	b := s.init(c)

	s.test("until condition ; do action ; done",
		b.List().AddCommand(b.Until(
			b.List().AddCommand(b.SimpleCommand("condition")).AddSemicolon(),
			b.List().AddCommand(b.SimpleCommand("action")).AddSemicolon())))
}

func (s *ShSuite) Test_ShellParser__function_definition(c *check.C) {
	b := s.init(c)

	s.test("fn() { simple-command; }",
		b.List().AddCommand(b.Function(
			"fn",
			b.Brace(b.List().
				AddCommand(b.SimpleCommand("simple-command")).
				AddSemicolon()).
				Compound)))

	// For some reason the POSIX grammar does not allow function bodies that consist of
	// a single command without braces or parentheses.
}

func (s *ShSuite) Test_ShellParser__brace_group(c *check.C) {
	b := s.init(c)

	// No semicolon necessary after the closing brace.
	s.test("if true; then { echo yes; } fi",
		b.List().AddCommand(b.If(
			b.List().AddCommand(b.SimpleCommand("true")).AddSemicolon(),
			b.List().AddCommand(b.Brace(
				b.List().AddCommand(b.SimpleCommand("echo", "yes")).AddSemicolon())))))
}

func (s *ShSuite) Test_ShellParser__simple_command(c *check.C) {
	b := s.init(c)

	s.test(
		"echo hello, world",
		b.List().AddCommand(b.SimpleCommand("echo", "hello,", "world")))

	s.test("echo ${PKGNAME:Q}",
		b.List().AddCommand(b.SimpleCommand("echo", "${PKGNAME:Q}")))

	s.test("${ECHO} \"Double-quoted\" 'Single-quoted'",
		b.List().AddCommand(b.SimpleCommand("${ECHO}", "\"Double-quoted\"", "'Single-quoted'")))

	s.test("`cat plain` \"`cat double`\" '`cat single`'",
		b.List().AddCommand(b.SimpleCommand("`cat plain`", "\"`cat double`\"", "'`cat single`'")))

	s.test("`\"one word\"`",
		b.List().AddCommand(b.SimpleCommand("`\"one word\"`")))

	s.test("PAGES=\"`ls -1 | ${SED} -e 's,3qt$$,3,'`\"",
		b.List().AddCommand(b.SimpleCommand("PAGES=\"`ls -1 | ${SED} -e 's,3qt$$,3,'`\"")))

	s.test("var=Plain var=\"Dquot\" var='Squot' var=Plain\"Dquot\"'Squot'",
		b.List().AddCommand(b.SimpleCommand("var=Plain", "var=\"Dquot\"", "var='Squot'", "var=Plain\"Dquot\"'Squot'")))

	// RUN is a special Make variable since it ends with a semicolon;
	// therefore it needs to be split off before passing the rest of
	// the command to the shell command parser.
	// Otherwise it would be interpreted as a shell command,
	// and the real shell command would be its argument.
	s.test("${RUN} subdir=\"`unzip -c \"$$e\" install.rdf | awk '/re/ { print \"hello\" }'`\"",
		b.List().AddCommand(b.SimpleCommand("${RUN}", "subdir=\"`unzip -c \"$$e\" install.rdf | awk '/re/ { print \"hello\" }'`\"")))

	s.test("PATH=/nonexistent env PATH=${PATH:Q} true",
		b.List().AddCommand(b.SimpleCommand("PATH=/nonexistent", "env", "PATH=${PATH:Q}", "true")))

	// The opening curly brace only has its special meaning when it appears as a whole word.
	s.test("{OpenGrok args",
		b.List().AddCommand(b.SimpleCommand("{OpenGrok", "args")))
}

func (s *ShSuite) Test_ShellParser__io_redirect(c *check.C) {
	b := s.init(c)

	s.test("echo >> ${PLIST_SRC}",
		b.List().AddCommand(b.SimpleCommand("echo", ">>${PLIST_SRC}")))

	s.test("echo 1>output 2>>append 3>|clobber 4>&5 6<input >>append",
		b.List().AddCommand(&MkShCommand{Simple: &MkShSimpleCommand{
			Assignments: nil,
			Name:        b.Token("echo"),
			Args:        nil,
			Redirections: []*MkShRedirection{
				{1, ">", b.Token("output")},
				{2, ">>", b.Token("append")},
				{3, ">|", b.Token("clobber")},
				{4, ">&", b.Token("5")},
				{6, "<", b.Token("input")},
				{-1, ">>", b.Token("append")}}}}))

	s.test("echo 1> output 2>> append 3>| clobber 4>& 5 6< input >> append",
		b.List().AddCommand(&MkShCommand{Simple: &MkShSimpleCommand{
			Assignments: nil,
			Name:        b.Token("echo"),
			Args:        nil,
			Redirections: []*MkShRedirection{
				{1, ">", b.Token("output")},
				{2, ">>", b.Token("append")},
				{3, ">|", b.Token("clobber")},
				{4, ">&", b.Token("5")},
				{6, "<", b.Token("input")},
				{-1, ">>", b.Token("append")}}}}))

	s.test("${MAKE} print-summary-data  2>&1 > /dev/stderr",
		b.List().AddCommand(&MkShCommand{Simple: &MkShSimpleCommand{
			Assignments: nil,
			Name:        b.Token("${MAKE}"),
			Args:        []*ShToken{b.Token("print-summary-data")},
			Redirections: []*MkShRedirection{
				{2, ">&", b.Token("1")},
				{-1, ">", b.Token("/dev/stderr")}}}}))
}

func (s *ShSuite) Test_ShellParser__io_here(c *check.C) {
	// In pkgsrc Makefiles, the IO here-documents cannot be used since all the text
	// is joined into a single line. Therefore there are no tests here.
}

func (s *ShSuite) init(c *check.C) *MkShBuilder {
	s.c = c
	return NewMkShBuilder()
}

func (s *ShSuite) test(program string, expected *MkShList) {
	tokens, rest := splitIntoShellTokens(dummyLine, program)
	s.c.Check(rest, equals, "")
	lexer := ShellLexer{
		current:        "",
		remaining:      tokens,
		atCommandStart: true,
		error:          ""}
	parser := shyyParserImpl{}

	succeeded := parser.Parse(&lexer)

	c := s.c

	if c.Check(succeeded, equals, 0) && c.Check(lexer.error, equals, "") {
		if !c.Check(lexer.result, deepEquals, expected) {
			actualJSON, actualErr := json.MarshalIndent(lexer.result, "", "  ")
			expectedJSON, expectedErr := json.MarshalIndent(expected, "", "  ")
			if c.Check(actualErr, check.IsNil) && c.Check(expectedErr, check.IsNil) {
				c.Check(string(actualJSON), deepEquals, string(expectedJSON))
			}
		}
	} else {
		c.Check(lexer.remaining, deepEquals, []string{})
	}
}

func (s *ShSuite) Test_ShellLexer_Lex__redirects(c *check.C) {
	tokens, rest := splitIntoShellTokens(dummyLine, "2>&1 <& <>file >>file <<EOF <<-EOF > /dev/stderr")

	c.Check(tokens, deepEquals, []string{"2>&", "1", "<&", "<>", "file", ">>", "file", "<<", "EOF", "<<-", "EOF", ">", "/dev/stderr"})
	c.Check(rest, equals, "")

	lexer := NewShellLexer(tokens, rest)
	var llval shyySymType

	c.Check(lexer.Lex(&llval), equals, tkIO_NUMBER)
	c.Check(llval.IONum, equals, 2)

	c.Check(lexer.Lex(&llval), equals, tkGTAND)

	c.Check(lexer.Lex(&llval), equals, tkWORD)
	c.Check(llval.Word.MkText, equals, "1")

	c.Check(lexer.Lex(&llval), equals, tkLTAND)

	c.Check(lexer.Lex(&llval), equals, tkLTGT)

	c.Check(lexer.Lex(&llval), equals, tkWORD)
	c.Check(llval.Word.MkText, equals, "file")

	c.Check(lexer.Lex(&llval), equals, tkGTGT)

	c.Check(lexer.Lex(&llval), equals, tkWORD)
	c.Check(llval.Word.MkText, equals, "file")

	c.Check(lexer.Lex(&llval), equals, tkLTLT)

	c.Check(lexer.Lex(&llval), equals, tkWORD)
	c.Check(llval.Word.MkText, equals, "EOF")

	c.Check(lexer.Lex(&llval), equals, tkLTLTDASH)

	c.Check(lexer.Lex(&llval), equals, tkWORD)
	c.Check(llval.Word.MkText, equals, "EOF")

	c.Check(lexer.Lex(&llval), equals, tkGT)

	c.Check(lexer.Lex(&llval), equals, tkWORD)
	c.Check(llval.Word.MkText, equals, "/dev/stderr")

	c.Check(lexer.Lex(&llval), equals, 0)
}

func (s *ShSuite) Test_ShellLexer_Lex__keywords(c *check.C) {
	b := s.init(c)

	testErr := func(program, error, remaining string) {
		tokens, rest := splitIntoShellTokens(dummyLine, program)
		s.c.Check(rest, equals, "")

		lexer := ShellLexer{
			current:        "",
			remaining:      tokens,
			atCommandStart: true,
			error:          ""}
		parser := shyyParserImpl{}

		succeeded := parser.Parse(&lexer)

		c.Check(succeeded, equals, 1)
		c.Check(lexer.error, equals, error)
		c.Check(joinSkipEmpty(" ", append([]string{lexer.current}, lexer.remaining...)...), equals, remaining)
	}

	s.test(
		"echo if then elif else fi for in do done while until case esac",
		b.List().AddCommand(b.SimpleCommand("echo",
			"if", "then", "elif", "else", "fi",
			"for", "in", "do", "done", "while", "until", "case", "esac")))

	testErr(
		"echo ;; remaining",
		"syntax error",
		";; remaining")

	testErr(
		"echo (subshell-command args)",
		"syntax error",
		"subshell-command args )")

	testErr("while :; do :; done if cond; then :; fi",
		"syntax error",
		"if cond ; then : ; fi")
}

type MkShBuilder struct {
}

func NewMkShBuilder() *MkShBuilder {
	return &MkShBuilder{}
}

func (b *MkShBuilder) List() *MkShList {
	return NewMkShList()
}

func (b *MkShBuilder) AndOr(pipeline *MkShPipeline) *MkShAndOr {
	return NewMkShAndOr(pipeline)
}

func (b *MkShBuilder) Pipeline(negated bool, cmds ...*MkShCommand) *MkShPipeline {
	return NewMkShPipeline(negated, cmds)
}

func (b *MkShBuilder) SimpleCommand(words ...string) *MkShCommand {
	cmd := MkShSimpleCommand{}
	assignments := true
	for _, word := range words {
		if assignments && matches(word, `^[A-Za-z_]\w*=`) {
			cmd.Assignments = append(cmd.Assignments, b.Token(word))
		} else if m, fdstr, op, rest := match3(word, `^(\d*)(<<-|<<|<&|>>|>&|>\||<|>)(.*)$`); m {
			fd := toInt(fdstr, -1)
			cmd.Redirections = append(cmd.Redirections, b.Redirection(fd, op, rest))
		} else {
			assignments = false
			if cmd.Name == nil {
				cmd.Name = b.Token(word)
			} else {
				cmd.Args = append(cmd.Args, b.Token(word))
			}
		}
	}
	return &MkShCommand{Simple: &cmd}
}

func (b *MkShBuilder) If(condActionElse ...*MkShList) *MkShCommand {
	ifClause := MkShIf{}
	for i, part := range condActionElse {
		switch {
		case i%2 == 0 && i != len(condActionElse)-1:
			ifClause.Conds = append(ifClause.Conds, part)
		case i%2 == 1:
			ifClause.Actions = append(ifClause.Actions, part)
		default:
			ifClause.Else = part
		}
	}
	return &MkShCommand{Compound: &MkShCompoundCommand{If: &ifClause}}
}

func (b *MkShBuilder) For(varname string, items []*ShToken, action *MkShList) *MkShCommand {
	return &MkShCommand{Compound: &MkShCompoundCommand{For: &MkShFor{varname, items, action}}}
}

func (b *MkShBuilder) Case(selector *ShToken, items ...*MkShCaseItem) *MkShCommand {
	return &MkShCommand{Compound: &MkShCompoundCommand{Case: &MkShCase{selector, items}}}
}

func (b *MkShBuilder) CaseItem(patterns []*ShToken, action *MkShList, separator MkShSeparator) *MkShCaseItem {
	return &MkShCaseItem{patterns, action, separator}
}

func (b *MkShBuilder) While(cond, action *MkShList, redirects ...*MkShRedirection) *MkShCommand {
	return &MkShCommand{
		Compound: &MkShCompoundCommand{
			Loop: &MkShLoop{cond, action, false}},
		Redirects: redirects}
}

func (b *MkShBuilder) Until(cond, action *MkShList, redirects ...*MkShRedirection) *MkShCommand {
	return &MkShCommand{
		Compound: &MkShCompoundCommand{
			Loop: &MkShLoop{cond, action, true}},
		Redirects: redirects}
}

func (b *MkShBuilder) Function(name string, body *MkShCompoundCommand, redirects ...*MkShRedirection) *MkShCommand {
	return &MkShCommand{
		FuncDef:   &MkShFunctionDefinition{name, body},
		Redirects: redirects}
}

func (b *MkShBuilder) Brace(list *MkShList) *MkShCommand {
	return &MkShCommand{Compound: &MkShCompoundCommand{Brace: list}}
}

func (b *MkShBuilder) Subshell(list *MkShList) *MkShCommand {
	return &MkShCommand{Compound: &MkShCompoundCommand{Subshell: list}}
}

func (b *MkShBuilder) Token(mktext string) *ShToken {
	tokenizer := NewShTokenizer(dummyLine, mktext, false)
	token := tokenizer.ShToken()
	assertf(tokenizer.parser.EOF(), "Invalid token: %q", tokenizer.parser.Rest())
	return token
}

func (b *MkShBuilder) Words(words ...string) []*ShToken {
	tokens := make([]*ShToken, len(words))
	for i, word := range words {
		tokens[i] = b.Token(word)
	}
	return tokens
}

func (b *MkShBuilder) Redirection(fd int, op string, target string) *MkShRedirection {
	return &MkShRedirection{fd, op, b.Token(target)}
}
