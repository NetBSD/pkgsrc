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
				t.CheckEquals(err, expError)
			} else {
				t.CheckDeepEquals(err, expError)
				t.CheckDeepEquals(err.Error(), expError.Error()) // Just for code coverage
				t.CheckDeepEquals(program, expProgram)
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

	test(
		"case ;;",
		nil,
		&ParseError{[]string{";;"}},
		nil...)
}

type ShSuite struct {
	t *Tester
	c *check.C
}

var _ = check.Suite(&ShSuite{})

func (s *ShSuite) SetUpTest(*check.C) {
	G = NewPkglint(nil, nil)
}

func (s *ShSuite) TearDownTest(*check.C) {
	G = unusablePkglint()
}

func (s *ShSuite) Test_parseShellProgram__program(c *check.C) {
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

func (s *ShSuite) Test_parseShellProgram__list(c *check.C) {
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

func (s *ShSuite) Test_parseShellProgram__and_or(c *check.C) {
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

func (s *ShSuite) Test_parseShellProgram__pipeline(c *check.C) {
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

func (s *ShSuite) Test_parseShellProgram__pipe_sequence(c *check.C) {
	b := s.init(c)

	s.test("command1 | if true ; then : ; fi",
		b.List().AddAndOr(b.AndOr(b.Pipeline(false,
			b.SimpleCommand("command1"),
			b.If(
				b.List().AddCommand(b.SimpleCommand("true")).AddSemicolon(),
				b.List().AddCommand(b.SimpleCommand(":")).AddSemicolon())))))
}

func (s *ShSuite) Test_parseShellProgram__command(c *check.C) {
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

func (s *ShSuite) Test_parseShellProgram__compound_command(c *check.C) {
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

func (s *ShSuite) Test_parseShellProgram__subshell(c *check.C) {
	b := s.init(c)

	sub3 := b.Subshell(b.List().AddCommand(b.SimpleCommand("sub3")))
	sub2 := b.Subshell(b.List().AddCommand(sub3).AddSemicolon().AddCommand(b.SimpleCommand("sub2")))
	sub1 := b.Subshell(b.List().AddCommand(sub2).AddSemicolon().AddCommand(b.SimpleCommand("sub1")))
	s.test("( ( ( sub3 ) ; sub2 ) ; sub1 )", b.List().AddCommand(sub1))
}

func (s *ShSuite) Test_parseShellProgram__compound_list(c *check.C) {
	b := s.init(c)

	s.test("( \n echo )",
		b.List().AddCommand(b.Subshell(
			b.List().AddCommand(b.SimpleCommand("echo")))))
}

func (s *ShSuite) Test_parseShellProgram__term(c *check.C) {
	b := s.init(c)

	s.test("echo1 ; echo2 ;",
		b.List().
			AddCommand(b.SimpleCommand("echo1")).
			AddSemicolon().
			AddCommand(b.SimpleCommand("echo2")).
			AddSemicolon())
}

func (s *ShSuite) Test_parseShellProgram__for_clause(c *check.C) {
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

	s.test("for var \n in ; do echo $var ; done",
		b.List().AddCommand(b.For(
			"var",
			nil,
			b.List().AddCommand(b.SimpleCommand("echo", "$var")).AddSemicolon())))

	s.test("for var in in esac ; do echo $var ; done",
		b.List().AddCommand(b.For(
			"var",
			b.Words("in", "esac"),
			b.List().AddCommand(b.SimpleCommand("echo", "$var")).AddSemicolon())))

	s.test("for var in \n do : ; done",
		b.List().AddCommand(b.For(
			"var",
			nil,
			b.List().AddCommand(b.SimpleCommand(":")).AddSemicolon())))

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

func (s *ShSuite) Test_parseShellProgram__case_clause(c *check.C) {
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

	s.test("case selector in pattern) \n case-item-action ; esac",
		b.List().AddCommand(b.Case(
			b.Token("selector"),
			b.CaseItem(
				b.Words("pattern"),
				b.List().AddCommand(b.SimpleCommand("case-item-action")), sepSemicolon))))

	s.test("case selector in pattern) action \n esac",
		b.List().AddCommand(b.Case(
			b.Token("selector"),
			b.CaseItem(
				b.Words("pattern"),
				b.List().AddCommand(b.SimpleCommand("action")), sepNone))))

	s.test("case $$expr in (if|then|else) ;; esac",
		b.List().AddCommand(b.Case(
			b.Token("$$expr"),
			b.CaseItem(
				b.Words("if", "then", "else"),
				b.List(), sepNone))))

	// This could be regarded an evil preprocessor hack, but it's used
	// in practice and is somewhat established, even though it is
	// difficult to parse and understand, even for humans.
	s.test("case $$expr in ${PATTERNS:@p@ (${p}) action ;; @} (*) ;; esac",
		b.List().AddCommand(b.Case(
			b.Token("$$expr"),
			b.CaseItemVar("${PATTERNS:@p@ (${p}) action ;; @}"),
			b.CaseItem(
				b.Words("*"),
				b.List(), sepNone))))

	// The default case may even be omitted.
	s.test("case $$expr in ${PATTERNS:@p@ (${p}) action ;; @} esac",
		b.List().AddCommand(b.Case(
			b.Token("$$expr"),
			b.CaseItemVar("${PATTERNS:@p@ (${p}) action ;; @}"))))

	// Only variables that end with a :@ modifier may be used in this
	// construct. All others are tokenized as normal words and lead
	// to a syntax error in the shell parser.
	s.testFail("case $$expr in ${PATTERNS} esac",
		[]string{}...)
}

func (s *ShSuite) Test_parseShellProgram__if_clause(c *check.C) {
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

	s.test("if cond1; then action1; elif cond2; then action2; else action3; fi",
		b.List().AddCommand(b.If(
			b.List().AddCommand(b.SimpleCommand("cond1")).AddSemicolon(),
			b.List().AddCommand(b.SimpleCommand("action1")).AddSemicolon(),
			b.List().AddCommand(b.SimpleCommand("cond2")).AddSemicolon(),
			b.List().AddCommand(b.SimpleCommand("action2")).AddSemicolon(),
			b.List().AddCommand(b.SimpleCommand("action3")).AddSemicolon())))
}

func (s *ShSuite) Test_parseShellProgram__while_clause(c *check.C) {
	b := s.init(c)

	s.test("while condition ; do action ; done",
		b.List().AddCommand(b.While(
			b.List().AddCommand(b.SimpleCommand("condition")).AddSemicolon(),
			b.List().AddCommand(b.SimpleCommand("action")).AddSemicolon())))
}

func (s *ShSuite) Test_parseShellProgram__until_clause(c *check.C) {
	b := s.init(c)

	s.test("until condition ; do action ; done",
		b.List().AddCommand(b.Until(
			b.List().AddCommand(b.SimpleCommand("condition")).AddSemicolon(),
			b.List().AddCommand(b.SimpleCommand("action")).AddSemicolon())))
}

func (s *ShSuite) Test_parseShellProgram__function_definition(c *check.C) {
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

func (s *ShSuite) Test_parseShellProgram__brace_group(c *check.C) {
	b := s.init(c)

	// No semicolon necessary after the closing brace.
	s.test("if true; then { echo yes; } fi",
		b.List().AddCommand(b.If(
			b.List().AddCommand(b.SimpleCommand("true")).AddSemicolon(),
			b.List().AddCommand(b.Brace(
				b.List().AddCommand(b.SimpleCommand("echo", "yes")).AddSemicolon())))))
}

func (s *ShSuite) Test_parseShellProgram__simple_command(c *check.C) {
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

func (s *ShSuite) Test_parseShellProgram__io_redirect(c *check.C) {
	b := s.init(c)

	s.test("echo >> ${PLIST_SRC}",
		b.List().AddCommand(b.SimpleCommand("echo", ">>${PLIST_SRC}")))

	s.test("echo 1>output 2>>append 3>|clobber 4>&5 6<input >>append <&input <>diamond <<-here",
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
				{-1, ">>", b.Token("append")},
				{-1, "<&", b.Token("input")},
				{-1, "<>", b.Token("diamond")},
				{-1, "<<-", b.Token("here")}}}}))

	s.test("echo 1> output 2>> append 3>| clobber 4>& 5 6< input >> append <& input <> diamond <<- here",
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
				{-1, ">>", b.Token("append")},
				{-1, "<&", b.Token("input")},
				{-1, "<>", b.Token("diamond")},
				{-1, "<<-", b.Token("here")}}}}))

	s.test("${MAKE} print-summary-data  2>&1 > /dev/stderr",
		b.List().AddCommand(&MkShCommand{Simple: &MkShSimpleCommand{
			Assignments: nil,
			Name:        b.Token("${MAKE}"),
			Args:        []*ShToken{b.Token("print-summary-data")},
			Redirections: []*MkShRedirection{
				{2, ">&", b.Token("1")},
				{-1, ">", b.Token("/dev/stderr")}}}}))

	s.test("1> output command",
		b.List().AddCommand(&MkShCommand{Simple: &MkShSimpleCommand{
			Name: b.Token("command"),
			Redirections: []*MkShRedirection{
				{1, ">", b.Token("output")}}}}))

	s.test("ENV=value 1> output command",
		b.List().AddCommand(&MkShCommand{Simple: &MkShSimpleCommand{
			Assignments: []*ShToken{b.Token("ENV=value")},
			Name:        b.Token("command"),
			Redirections: []*MkShRedirection{
				{1, ">", b.Token("output")}}}}))
}

func (s *ShSuite) Test_parseShellProgram__redirect_list(c *check.C) {
	b := s.init(c)

	s.test("(:) 1>out",
		b.List().AddCommand(
			b.Redirected(
				b.Subshell(b.List().AddCommand(b.SimpleCommand(":"))),
				b.Redirection(1, ">", "out"))))

	s.test("(:) 1>out 2>out",
		b.List().AddCommand(
			b.Redirected(
				b.Subshell(b.List().AddCommand(b.SimpleCommand(":"))),
				b.Redirection(1, ">", "out"),
				b.Redirection(2, ">", "out"))))
}

func (s *ShSuite) Test_parseShellProgram__io_here(c *check.C) {
	// In pkgsrc Makefiles, the IO here-documents cannot be used since
	// all the text is joined into a single line. Therefore these test
	// cases only show that pkglint can indeed not parse <<EOF
	// redirections.
	b := s.init(c)

	s.test("<<EOF\ntext\nEOF",
		b.List().
			AddCommand(b.SimpleCommand("<<EOF")).
			AddNewline().
			AddCommand(b.SimpleCommand("text")). // This is wrong.
			AddNewline().
			AddCommand(b.SimpleCommand("EOF"))) // This is wrong.

	s.test("1<<EOF\ntext\nEOF",
		b.List().
			AddCommand(b.SimpleCommand("1<<EOF")).
			AddNewline().
			AddCommand(b.SimpleCommand("text")). // This is wrong.
			AddNewline().
			AddCommand(b.SimpleCommand("EOF"))) // This is wrong.
}

func (s *ShSuite) init(c *check.C) *MkShBuilder {
	s.c = c
	s.t = &Tester{c: c, testName: c.TestName()}
	return NewMkShBuilder()
}

func (s *ShSuite) test(program string, expected *MkShList) {
	t := s.t

	// See parseShellProgram
	tokens, rest := splitIntoShellTokens(dummyLine, program)
	t.CheckEquals(rest, "")
	lexer := NewShellLexer(tokens, rest)
	parser := shyyParserImpl{}

	zeroMeansSuccess := parser.Parse(lexer)

	c := s.c

	if t.CheckEquals(zeroMeansSuccess, 0) && t.CheckEquals(lexer.error, "") {
		if !t.CheckDeepEquals(lexer.result, expected) {
			actualJSON, actualErr := json.MarshalIndent(lexer.result, "", "  ")
			expectedJSON, expectedErr := json.MarshalIndent(expected, "", "  ")
			if c.Check(actualErr, check.IsNil) && c.Check(expectedErr, check.IsNil) {
				t.CheckDeepEquals(string(actualJSON), string(expectedJSON))
			}
		}
	} else {
		t.CheckDeepEquals(lexer.remaining, []string{})
	}
}

func (s *ShSuite) testFail(program string, expectedRemaining ...string) {
	t := s.t

	tokens, rest := splitIntoShellTokens(dummyLine, program)
	t.CheckEquals(rest, "")
	lexer := ShellLexer{remaining: tokens, atCommandStart: true}
	parser := shyyParserImpl{}

	zeroMeansSuccess := parser.Parse(&lexer)

	if t.CheckEquals(zeroMeansSuccess, 1) && t.Check(lexer.error, check.Not(check.Equals), "") {
		t.CheckDeepEquals(lexer.remaining, expectedRemaining)
	}
}

func (s *ShSuite) Test_ShellLexer_Lex__redirects(c *check.C) {
	t := s.t

	tokens, rest := splitIntoShellTokens(dummyLine, "2>&1 <& <>file >>file <<EOF <<-EOF > /dev/stderr")

	t.CheckDeepEquals(tokens, []string{"2>&", "1", "<&", "<>", "file", ">>", "file", "<<", "EOF", "<<-", "EOF", ">", "/dev/stderr"})
	t.CheckEquals(rest, "")

	lexer := NewShellLexer(tokens, rest)
	var llval shyySymType

	t.CheckEquals(lexer.Lex(&llval), tkIO_NUMBER)
	t.CheckEquals(llval.IONum, 2)

	t.CheckEquals(lexer.Lex(&llval), tkGTAND)

	t.CheckEquals(lexer.Lex(&llval), tkWORD)
	t.CheckEquals(llval.Word.MkText, "1")

	t.CheckEquals(lexer.Lex(&llval), tkLTAND)

	t.CheckEquals(lexer.Lex(&llval), tkLTGT)

	t.CheckEquals(lexer.Lex(&llval), tkWORD)
	t.CheckEquals(llval.Word.MkText, "file")

	t.CheckEquals(lexer.Lex(&llval), tkGTGT)

	t.CheckEquals(lexer.Lex(&llval), tkWORD)
	t.CheckEquals(llval.Word.MkText, "file")

	t.CheckEquals(lexer.Lex(&llval), tkLTLT)

	t.CheckEquals(lexer.Lex(&llval), tkWORD)
	t.CheckEquals(llval.Word.MkText, "EOF")

	t.CheckEquals(lexer.Lex(&llval), tkLTLTDASH)

	t.CheckEquals(lexer.Lex(&llval), tkWORD)
	t.CheckEquals(llval.Word.MkText, "EOF")

	t.CheckEquals(lexer.Lex(&llval), tkGT)

	t.CheckEquals(lexer.Lex(&llval), tkWORD)
	t.CheckEquals(llval.Word.MkText, "/dev/stderr")

	t.CheckEquals(lexer.Lex(&llval), 0)
}

func (s *ShSuite) Test_ShellLexer_Lex__keywords(c *check.C) {
	b := s.init(c)
	t := s.t

	testErr := func(program, error, remaining string) {
		tokens, rest := splitIntoShellTokens(dummyLine, program)
		t.CheckEquals(rest, "")

		lexer := ShellLexer{
			current:        "",
			remaining:      tokens,
			atCommandStart: true,
			error:          ""}
		parser := shyyParserImpl{}

		succeeded := parser.Parse(&lexer)

		t.CheckEquals(succeeded, 1)
		t.CheckEquals(lexer.error, error)
		t.CheckEquals(joinSkipEmpty(" ", append([]string{lexer.current}, lexer.remaining...)...), remaining)
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

func (s *Suite) Test_ShellLexer_Lex__case_patterns(c *check.C) {
	t := s.Init(c)

	test := func(shellProgram string, expectedTokens ...int) {
		tokens, rest := splitIntoShellTokens(nil, shellProgram)
		lexer := NewShellLexer(tokens, rest)

		var actualTokens []int
		for {
			var token shyySymType
			tokenType := lexer.Lex(&token)
			if tokenType <= 0 {
				break
			}
			actualTokens = append(actualTokens, tokenType)
		}
		t.CheckDeepEquals(actualTokens, expectedTokens)
	}

	test(
		"case $$expr in ${PATTERNS:@p@(${p}) action ;; @} esac",

		tkCASE,
		tkWORD,
		tkIN,
		tkWORD,
		tkESAC)

	test(
		"case $$expr in ${PATTERNS:Mpattern} esac",

		tkCASE,
		tkWORD,
		tkIN,
		tkWORD,
		tkWORD) // No tkESAC since there is no :@ modifier.
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

// SimpleCommand classifies the given arguments into variable assignments
// (only at the beginning of the command), the command name, arguments and
// redirections. It is not intended to cover any edge cases.
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

// If creates an if-then-elif-then-else sequence.
// The first arguments are pairs of conditions and actions.
// The remaining argument, if any, is the else action.
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
	return &MkShCaseItem{patterns, action, separator, nil}
}

func (b *MkShBuilder) CaseItemVar(varUseText string) *MkShCaseItem {
	return &MkShCaseItem{nil, nil, sepNone, b.Token(varUseText)}
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

func (b *MkShBuilder) Redirected(cmd *MkShCommand, redirects ...*MkShRedirection) *MkShCommand {
	cmd.Redirects = redirects
	return cmd
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
