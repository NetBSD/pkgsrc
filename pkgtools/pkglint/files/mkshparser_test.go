package main

import (
	"encoding/json"
	"gopkg.in/check.v1"
	"strconv"
)

type ShSuite struct {
	c *check.C
}

var _ = check.Suite(&ShSuite{})

func (s *ShSuite) Test_ShellParser_program(c *check.C) {
	b := s.init(c)

	s.test("",
		b.List())

	s.test("echo ;",
		b.List().AddCommand(b.SimpleCommand("echo")).AddSeparator(";"))

	s.test("echo",
		b.List().AddCommand(b.SimpleCommand("echo")))

	s.test(""+
		"cd ${WRKSRC} && ${FIND} ${${_list_}} -type f ! -name '*.orig' 2> /dev/null "+
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
				b.List().AddCommand(b.SimpleCommand("read", "entry")).AddSeparator(";"),
				b.List().AddCommand(b.SimpleCommand(":")).AddSeparator(";"))))))

	s.test("while read entry ; do case \"$$entry\" in include/c-client/* ) ${INSTALL_DATA} $$src $$dest ; esac ; done",
		b.List().AddCommand(b.While(
			b.List().AddCommand(b.SimpleCommand("read", "entry")).AddSeparator(";"),
			b.List().AddCommand(b.Case(
				b.Token("\"$$entry\""),
				b.CaseItem(
					b.Words("include/c-client/*"),
					b.List().AddCommand(b.SimpleCommand("${INSTALL_DATA}", "$$src", "$$dest")),
					&SEP_SEMI))).AddSeparator(";"))))

	s.test("command | while condition ; do case selector in pattern ) : ; esac ; done",
		b.List().AddAndOr(b.AndOr(b.Pipeline(false,
			b.SimpleCommand("command"),
			b.While(
				b.List().AddCommand(b.SimpleCommand("condition")).AddSeparator(";"),
				b.List().AddCommand(b.Case(
					b.Token("selector"),
					b.CaseItem(
						b.Words("pattern"),
						b.List().AddCommand(b.SimpleCommand(":")),
						&SEP_SEMI))).AddSeparator(";"))))))

	s.test("command1 \n command2 \n command3",
		b.List().
			AddCommand(b.SimpleCommand("command1")).
			AddSeparator(SEP_NEWLINE).
			AddCommand(b.SimpleCommand("command2")).
			AddSeparator(SEP_NEWLINE).
			AddCommand(b.SimpleCommand("command3")))

	s.test("if condition; then action; else case selector in pattern) case-item-action ;; esac; fi",
		b.List().AddCommand(b.If(
			b.List().AddCommand(b.SimpleCommand("condition")).AddSeparator(";"),
			b.List().AddCommand(b.SimpleCommand("action")).AddSeparator(";"),
			b.List().AddCommand(b.Case(
				b.Token("selector"),
				b.CaseItem(
					b.Words("pattern"),
					b.List().AddCommand(b.SimpleCommand("case-item-action")), nil))).AddSeparator(";"))))
}

func (s *ShSuite) Test_ShellParser_list(c *check.C) {
	b := s.init(c)

	s.test("echo1 && echo2",
		b.List().AddAndOr(
			b.AndOr(b.Pipeline(false, b.SimpleCommand("echo1"))).
				Add("&&", b.Pipeline(false, b.SimpleCommand("echo2")))))

	s.test("echo1 ; echo2",
		b.List().
			AddCommand(b.SimpleCommand("echo1")).
			AddSeparator(";").
			AddCommand(b.SimpleCommand("echo2")))

	s.test("echo1 ; echo2 &",
		b.List().
			AddCommand(b.SimpleCommand("echo1")).
			AddSeparator(";").
			AddCommand(b.SimpleCommand("echo2")).
			AddSeparator("&"))
}

func (s *ShSuite) Test_ShellParser_and_or(c *check.C) {
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

func (s *ShSuite) Test_ShellParser_pipeline(c *check.C) {
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

func (s *ShSuite) Test_ShellParser_pipe_sequence(c *check.C) {
	b := s.init(c)

	s.test("command1 | if true ; then : ; fi",
		b.List().AddAndOr(b.AndOr(b.Pipeline(false,
			b.SimpleCommand("command1"),
			b.If(
				b.List().AddCommand(b.SimpleCommand("true")).AddSeparator(";"),
				b.List().AddCommand(b.SimpleCommand(":")).AddSeparator(";"))))))
}

func (s *ShSuite) Test_ShellParser_command(c *check.C) {
	b := s.init(c)

	s.test("simple_command",
		b.List().AddAndOr(b.AndOr(b.Pipeline(false, b.SimpleCommand("simple_command")))))

	s.test("while 1; do 2; done",
		b.List().AddAndOr(b.AndOr(b.Pipeline(false,
			b.While(
				b.List().AddCommand(b.SimpleCommand("1")).AddSeparator(";"),
				b.List().AddCommand(b.SimpleCommand("2")).AddSeparator(";"))))))

	s.test("while 1; do 2; done 1>&2",
		b.List().AddAndOr(b.AndOr(b.Pipeline(false,
			b.While(
				b.List().AddCommand(b.SimpleCommand("1")).AddSeparator(";"),
				b.List().AddCommand(b.SimpleCommand("2")).AddSeparator(";"),
				b.Redirection(1, ">&", "2"))))))

	s.test("func(){ echo hello;} 2>&1",
		b.List().AddCommand(b.Function(
			"func",
			b.Brace(b.List().AddCommand(b.SimpleCommand("echo", "hello")).AddSeparator(";")).Compound,
			b.Redirection(2, ">&", "1"))))
}

func (s *ShSuite) Test_ShellParser_compound_command(c *check.C) {
	b := s.init(c)

	s.test("{ brace ; }",
		b.List().AddCommand(b.Brace(
			b.List().AddCommand(b.SimpleCommand("brace")).AddSeparator(";"))))

	s.test("( subshell )",
		b.List().AddCommand(b.Subshell(
			b.List().AddCommand(b.SimpleCommand("subshell")))))

	s.test("for i in * ; do echo $i ; done",
		b.List().AddCommand(b.For(
			"i",
			b.Words("*"),
			b.List().AddCommand(b.SimpleCommand("echo", "$i")).AddSeparator(";"))))

	s.test("case $i in esac",
		b.List().AddCommand(b.Case(
			b.Token("$i"))))

}

func (s *ShSuite) Test_ShellParser_subshell(c *check.C) {
	b := s.init(c)

	sub3 := b.Subshell(b.List().AddCommand(b.SimpleCommand("sub3")))
	sub2 := b.Subshell(b.List().AddCommand(sub3).AddSeparator(";").AddCommand(b.SimpleCommand("sub2")))
	sub1 := b.Subshell(b.List().AddCommand(sub2).AddSeparator(";").AddCommand(b.SimpleCommand("sub1")))
	s.test("( ( ( sub3 ) ; sub2 ) ; sub1 )", b.List().AddCommand(sub1))
}

func (s *ShSuite) Test_ShellParser_compound_list(c *check.C) {
	b := s.init(c)

	s.test("( \n echo )",
		b.List().AddCommand(b.Subshell(
			b.List().AddCommand(b.SimpleCommand("echo")))))
}

func (s *ShSuite) Test_ShellParser_term(c *check.C) {
	b := s.init(c)

	_ = b
}

func (s *ShSuite) Test_ShellParser_for_clause(c *check.C) {
	b := s.init(c)

	s.test("for var do echo $var ; done",
		b.List().AddCommand(b.For(
			"var",
			b.Words("\"$$@\""),
			b.List().AddCommand(b.SimpleCommand("echo", "$var")).AddSeparator(";"))))

	// Only linebreak is allowed, but not semicolon.
	s.test("for var \n do echo $var ; done",
		b.List().AddCommand(b.For(
			"var",
			b.Words("\"$$@\""),
			b.List().AddCommand(b.SimpleCommand("echo", "$var")).AddSeparator(";"))))

	s.test("for var in a b c ; do echo $var ; done",
		b.List().AddCommand(b.For(
			"var",
			b.Words("a", "b", "c"),
			b.List().AddCommand(b.SimpleCommand("echo", "$var")).AddSeparator(";"))))

	s.test("for var \n \n \n in a b c ; do echo $var ; done",
		b.List().AddCommand(b.For(
			"var",
			b.Words("a", "b", "c"),
			b.List().AddCommand(b.SimpleCommand("echo", "$var")).AddSeparator(";"))))

	s.test("for var in in esac ; do echo $var ; done",
		b.List().AddCommand(b.For(
			"var",
			b.Words("in", "esac"),
			b.List().AddCommand(b.SimpleCommand("echo", "$var")).AddSeparator(";"))))

	// No semicolon necessary between the two “done”.
	s.test("for i in 1; do for j in 1; do echo $$i$$j; done done",
		b.List().AddCommand(b.For(
			"i",
			b.Words("1"),
			b.List().AddCommand(b.For(
				"j",
				b.Words("1"),
				b.List().AddCommand(b.SimpleCommand("echo", "$$i$$j")).AddSeparator(";"))))))
}

func (s *ShSuite) Test_ShellParser_case_clause(c *check.C) {
	b := s.init(c)

	s.test("case $var in esac",
		b.List().AddCommand(b.Case(b.Token("$var"))))

	s.test("case selector in pattern) ;; pattern) esac",
		b.List().AddCommand(b.Case(
			b.Token("selector"),
			b.CaseItem(b.Words("pattern"), b.List(), nil),
			b.CaseItem(b.Words("pattern"), b.List(), nil))))

	s.test("case $$i in *.c | *.h ) echo C ;; * ) echo Other ; esac",
		b.List().AddCommand(b.Case(
			b.Token("$$i"),
			b.CaseItem(b.Words("*.c", "*.h"), b.List().AddCommand(b.SimpleCommand("echo", "C")), nil),
			b.CaseItem(b.Words("*"), b.List().AddCommand(b.SimpleCommand("echo", "Other")), &SEP_SEMI))))

	s.test("case $$i in *.c ) echo ; esac",
		b.List().AddCommand(b.Case(
			b.Token("$$i"),
			b.CaseItem(b.Words("*.c"), b.List().AddCommand(b.SimpleCommand("echo")), &SEP_SEMI))))

	s.test("case selector in pattern) case-item-action ; esac",
		b.List().AddCommand(b.Case(
			b.Token("selector"),
			b.CaseItem(
				b.Words("pattern"),
				b.List().AddCommand(b.SimpleCommand("case-item-action")), &SEP_SEMI))))

	s.test("case selector in pattern) case-item-action ;; esac",
		b.List().AddCommand(b.Case(
			b.Token("selector"),
			b.CaseItem(
				b.Words("pattern"),
				b.List().AddCommand(b.SimpleCommand("case-item-action")), nil))))

}

func (s *ShSuite) Test_ShellParser_if_clause(c *check.C) {
	b := s.init(c)

	s.test(
		"if true ; then echo yes ; else echo no ; fi",
		b.List().AddCommand(b.If(
			b.List().AddCommand(b.SimpleCommand("true")).AddSeparator(";"),
			b.List().AddCommand(b.SimpleCommand("echo", "yes")).AddSeparator(";"),
			b.List().AddCommand(b.SimpleCommand("echo", "no")).AddSeparator(";"))))

	// No semicolon necessary between the two “fi”.
	s.test("if cond1; then if cond2; then action; fi fi",
		b.List().AddCommand(b.If(
			b.List().AddCommand(b.SimpleCommand("cond1")).AddSeparator(";"),
			b.List().AddCommand(b.If(
				b.List().AddCommand(b.SimpleCommand("cond2")).AddSeparator(";"),
				b.List().AddCommand(b.SimpleCommand("action")).AddSeparator(";"))))))
}

func (s *ShSuite) Test_ShellParser_while_clause(c *check.C) {
	b := s.init(c)

	s.test("while condition ; do action ; done",
		b.List().AddCommand(b.While(
			b.List().AddCommand(b.SimpleCommand("condition")).AddSeparator(";"),
			b.List().AddCommand(b.SimpleCommand("action")).AddSeparator(";"))))
}

func (s *ShSuite) Test_ShellParser_until_clause(c *check.C) {
	b := s.init(c)

	s.test("until condition ; do action ; done",
		b.List().AddCommand(b.Until(
			b.List().AddCommand(b.SimpleCommand("condition")).AddSeparator(";"),
			b.List().AddCommand(b.SimpleCommand("action")).AddSeparator(";"))))
}

func (s *ShSuite) Test_ShellParser_function_definition(c *check.C) {
	b := s.init(c)

	_ = b
}

func (s *ShSuite) Test_ShellParser_brace_group(c *check.C) {
	b := s.init(c)

	// No semicolon necessary after the closing brace.
	s.test("if true; then { echo yes; } fi",
		b.List().AddCommand(b.If(
			b.List().AddCommand(b.SimpleCommand("true")).AddSeparator(";"),
			b.List().AddCommand(b.Brace(
				b.List().AddCommand(b.SimpleCommand("echo", "yes")).AddSeparator(";"))))))
}

func (s *ShSuite) Test_ShellParser_simple_command(c *check.C) {
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
	s.test("${RUN} subdir=\"`unzip -c \"$$e\" install.rdf | awk '/re/ { print \"hello\" }'`\"",
		b.List().AddCommand(b.SimpleCommand("${RUN}", "subdir=\"`unzip -c \"$$e\" install.rdf | awk '/re/ { print \"hello\" }'`\"")))

	s.test("PATH=/nonexistent env PATH=${PATH:Q} true",
		b.List().AddCommand(b.SimpleCommand("PATH=/nonexistent", "env", "PATH=${PATH:Q}", "true")))

	s.test("{OpenGrok args",
		b.List().AddCommand(b.SimpleCommand("{OpenGrok", "args")))
}

func (s *ShSuite) Test_ShellParser_io_redirect(c *check.C) {
	b := s.init(c)

	s.test("echo >> ${PLIST_SRC}",
		b.List().AddCommand(b.SimpleCommand("echo", ">>${PLIST_SRC}")))

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

func (s *ShSuite) Test_ShellParser_io_here(c *check.C) {
	b := s.init(c)

	_ = b
}

func (s *ShSuite) init(c *check.C) *MkShBuilder {
	s.c = c
	return NewMkShBuilder()
}

func (s *ShSuite) test(program string, expected *MkShList) {
	tokens, rest := splitIntoShellTokens(dummyLine, program)
	s.c.Check(rest, equals, "")
	lexer := &ShellLexer{
		current:        "",
		remaining:      tokens,
		atCommandStart: true,
		error:          ""}
	parser := &shyyParserImpl{}

	succeeded := parser.Parse(lexer)

	c := s.c

	if ok1, ok2 := c.Check(succeeded, equals, 0), c.Check(lexer.error, equals, ""); ok1 && ok2 {
		if !c.Check(lexer.result, deepEquals, expected) {
			actualJson, actualErr := json.MarshalIndent(lexer.result, "", "  ")
			expectedJson, expectedErr := json.MarshalIndent(expected, "", "  ")
			if c.Check(actualErr, check.IsNil) && c.Check(expectedErr, check.IsNil) {
				c.Check(string(actualJson), deepEquals, string(expectedJson))
			}
		}
	} else {
		c.Check(lexer.remaining, deepEquals, []string{})
	}
}

func (s *ShSuite) Test_ShellLexer_Lex__redirects(c *check.C) {
	tokens, rest := splitIntoShellTokens(dummyLine, "${MAKE} print-summary-data  2>&1 > /dev/stderr")

	c.Check(tokens, deepEquals, []string{"${MAKE}", "print-summary-data", "2>&", "1", ">", "/dev/stderr"})
	c.Check(rest, equals, "")

	lexer := NewShellLexer(tokens, rest)
	var llval shyySymType

	c.Check(lexer.Lex(&llval), equals, tkWORD)
	c.Check(llval.Word.MkText, equals, "${MAKE}")

	c.Check(lexer.Lex(&llval), equals, tkWORD)
	c.Check(llval.Word.MkText, equals, "print-summary-data")

	c.Check(lexer.Lex(&llval), equals, tkIO_NUMBER)
	c.Check(llval.IONum, equals, 2)

	c.Check(lexer.Lex(&llval), equals, tkGTAND)

	c.Check(lexer.Lex(&llval), equals, tkWORD)
	c.Check(llval.Word.MkText, equals, "1")

	c.Check(lexer.Lex(&llval), equals, tkGT)

	c.Check(lexer.Lex(&llval), equals, tkWORD)
	c.Check(llval.Word.MkText, equals, "/dev/stderr")

	c.Check(lexer.Lex(&llval), equals, 0)
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
	return NewMkShPipeline(negated, cmds...)
}

func (b *MkShBuilder) SimpleCommand(words ...string) *MkShCommand {
	cmd := &MkShSimpleCommand{}
	assignments := true
	for _, word := range words {
		if assignments && matches(word, `^\w+=`) {
			cmd.Assignments = append(cmd.Assignments, b.Token(word))
		} else if m, fdstr, op, rest := match3(word, `^(\d*)(<<-|<<|<&|>>|>&|>\||<|>)(.*)$`); m {
			fd, err := strconv.Atoi(fdstr)
			if err != nil {
				fd = -1
			}
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
	return &MkShCommand{Simple: cmd}
}

func (b *MkShBuilder) If(condActionElse ...*MkShList) *MkShCommand {
	ifclause := &MkShIfClause{}
	for i, part := range condActionElse {
		if i%2 == 0 && i != len(condActionElse)-1 {
			ifclause.Conds = append(ifclause.Conds, part)
		} else if i%2 == 1 {
			ifclause.Actions = append(ifclause.Actions, part)
		} else {
			ifclause.Else = part
		}
	}
	return &MkShCommand{Compound: &MkShCompoundCommand{If: ifclause}}
}

func (b *MkShBuilder) For(varname string, items []*ShToken, action *MkShList) *MkShCommand {
	return &MkShCommand{Compound: &MkShCompoundCommand{For: &MkShForClause{varname, items, action}}}
}

func (b *MkShBuilder) Case(selector *ShToken, items ...*MkShCaseItem) *MkShCommand {
	return &MkShCommand{Compound: &MkShCompoundCommand{Case: &MkShCaseClause{selector, items}}}
}

func (b *MkShBuilder) CaseItem(patterns []*ShToken, action *MkShList, separator *MkShSeparator) *MkShCaseItem {
	return &MkShCaseItem{patterns, action, separator}
}

func (b *MkShBuilder) While(cond, action *MkShList, redirects ...*MkShRedirection) *MkShCommand {
	return &MkShCommand{
		Compound: &MkShCompoundCommand{
			Loop: &MkShLoopClause{cond, action, false}},
		Redirects: redirects}
}

func (b *MkShBuilder) Until(cond, action *MkShList, redirects ...*MkShRedirection) *MkShCommand {
	return &MkShCommand{
		Compound: &MkShCompoundCommand{
			Loop: &MkShLoopClause{cond, action, true}},
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
