package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestSplitIntoShellwords_LineContinuation(c *check.C) {
	line := NewLine("fname", "1", "dummy", nil)

	words, rest := splitIntoShellwords(line, "if true; then \\")

	c.Check(words, check.DeepEquals, []string{"if", "true", ";", "then"})
	c.Check(rest, equals, "\\")

	words, rest = splitIntoShellwords(line, "pax -s /.*~$$//g")

	c.Check(words, check.DeepEquals, []string{"pax", "-s", "/.*~$$//g"})
	c.Check(rest, equals, "")
}

func (s *Suite) TestChecklineMkShelltext(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.mkContext = newMkContext()
	msline := NewMkShellLine(NewLine("fname", "1", "# dummy", nil))

	msline.checkShelltext("@# Comment")

	c.Check(s.Output(), equals, "")

	msline.checkShelltext("uname=`uname`; echo $$uname")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: Unknown shell command \"uname\".\n"+
		"WARN: fname:1: Please switch to \"set -e\" mode before using a semicolon to separate commands.\n"+
		"WARN: fname:1: Unknown shell command \"echo\".\n"+
		"WARN: fname:1: Unquoted shell variable \"uname\".\n")

	G.globalData.tools = map[string]bool{"echo": true}
	G.globalData.predefinedTools = map[string]bool{"echo": true}
	G.mkContext = newMkContext()
	G.globalData.InitVartypes()

	msline.checkShelltext("echo ${PKGNAME:Q}") // vucQuotPlain

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: PKGNAME may not be used in this file.\n"+
		"NOTE: fname:1: The :Q operator isn't necessary for ${PKGNAME} here.\n")

	msline.checkShelltext("echo \"${CFLAGS:Q}\"") // vucQuotDquot

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: Please don't use the :Q operator in double quotes.\n"+
		"WARN: fname:1: CFLAGS may not be used in this file.\n"+
		"WARN: fname:1: Please use ${CFLAGS:M*:Q} instead of ${CFLAGS:Q} and make sure the variable appears outside of any quoting characters.\n")

	msline.checkShelltext("echo '${COMMENT:Q}'") // vucQuotSquot

	c.Check(s.Output(), equals, "WARN: fname:1: COMMENT may not be used in this file.\n")

	msline.checkShelltext("echo $$@")

	c.Check(s.Output(), equals, "WARN: fname:1: The $@ shell variable should only be used in double quotes.\n")

	msline.checkShelltext("echo \"$$\"") // As seen by make(1); the shell sees: echo $

	c.Check(s.Output(), equals, "WARN: fname:1: Unquoted $ or strange shell variable found.\n")

	msline.checkShelltext("echo \"\\n\"") // As seen by make(1); the shell sees: echo "\n"

	c.Check(s.Output(), equals, "WARN: fname:1: Please use \"\\\\n\" instead of \"\\n\".\n")
}

func (s *Suite) TestMkShellLine_CheckShelltext_InternalError1(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	G.mkContext = newMkContext()
	msline := NewMkShellLine(NewLine("fname", "1", "# dummy", nil))

	// foobar="`echo \"foo   bar\"`"
	msline.checkShelltext("foobar=\"`echo \\\"foo   bar\\\"`\"")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: Backslashes should be doubled inside backticks.\n"+
		"WARN: fname:1: Double quotes inside backticks inside double quotes are error prone.\n"+
		"WARN: fname:1: Backslashes should be doubled inside backticks.\n"+
		"WARN: fname:1: Double quotes inside backticks inside double quotes are error prone.\n"+
		"WARN: fname:1: Unknown shell command \"echo\".\n"+
		"ERROR: fname:1: Internal pkglint error: checklineMkShellword state=plain, rest=\"\\\\foo\", shellword=\"\\\\foo\"\n"+
		"ERROR: fname:1: Internal pkglint error: checklineMkShelltext state=continuation rest=\"\\\\\" shellword=\"echo \\\\foo   bar\\\\\"\n")
}

func (s *Suite) TestMkShellLine_CheckShelltext_InternalError2(c *check.C) {
	G.globalData.InitVartypes()
	msline := NewMkShellLine(NewLine("fname", "1", "# dummy", nil))
	G.mkContext = newMkContext()
	s.RegisterTool("pax", "PAX", false)
	G.mkContext.tools["pax"] = true

	msline.checkShelltext("pax -rwpp -s /.*~$$//g . ${DESTDIR}${PREFIX}")

	c.Check(s.Output(), equals, "ERROR: fname:1: Internal pkglint error: checklineMkShellword state=plain, rest=\"$$//g\", shellword=\"/.*~$$//g\"\n")
}

func (s *Suite) TestChecklineMkShellword(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	msline := NewMkShellLine(NewLine("fname", "1", "# dummy", nil))

	c.Check(matches("${list}", `^`+reVarnameDirect+`$`), equals, false)

	msline.checkShellword("${${list}}", false)

	c.Check(s.Output(), equals, "")

	msline.checkShellword("\"$@\"", false)

	c.Check(s.Output(), equals, "WARN: fname:1: Please use \"${.TARGET}\" instead of \"$@\".\n")
}

func (s *Suite) TestMkShellLine_CheckShellword_InternalError(c *check.C) {
	msline := NewMkShellLine(NewLine("fname", "1", "# dummy", nil))

	msline.checkShellword("/.*~$$//g", false)

	c.Check(s.Output(), equals, "ERROR: fname:1: Internal pkglint error: checklineMkShellword state=plain, rest=\"$$//g\", shellword=\"/.*~$$//g\"\n")
}

func (s *Suite) TestShelltextContext_CheckCommandStart(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	s.RegisterTool("echo", "ECHO", true)
	G.mkContext = newMkContext()
	line := NewLine("fname", "3", "# dummy", nil)

	shellcmd := "echo \"hello, world\""
	NewMkLine(line).checkText(shellcmd)
	NewMkShellLine(line).checkShelltext(shellcmd)

	c.Check(s.Output(), equals, ""+
		"WARN: fname:3: The \"echo\" tool is used but not added to USE_TOOLS.\n"+
		"WARN: fname:3: Please use \"${ECHO}\" instead of \"echo\".\n")
}

func (s *Suite) TestMkShellLine_checklineMkShelltext(c *check.C) {

	msline := NewMkShellLine(NewLine("Makefile", "3", "# dummy", nil))

	msline.checkShelltext("for f in *.pl; do ${SED} s,@PREFIX@,${PREFIX}, < $f > $f.tmp && ${MV} $f.tmp $f; done")

	c.Check(s.Output(), equals, "NOTE: Makefile:3: Please use the SUBST framework instead of ${SED} and ${MV}.\n")

	msline.checkShelltext("install -c manpage.1 ${PREFIX}/man/man1/manpage.1")

	c.Check(s.Output(), equals, "WARN: Makefile:3: Please use ${PKGMANDIR} instead of \"man\".\n")

	msline.checkShelltext("cp init-script ${PREFIX}/etc/rc.d/service")

	c.Check(s.Output(), equals, "WARN: Makefile:3: Please use the RCD_SCRIPTS mechanism to install rc.d scripts automatically to ${RCD_SCRIPTS_EXAMPLEDIR}.\n")
}

func (s *Suite) TestMkShellLine_checkCommandUse(c *check.C) {
	G.mkContext = newMkContext()
	G.mkContext.target = "do-install"

	shline := NewMkShellLine(NewLine("fname", "1", "dummy", nil))

	shline.checkCommandUse("sed")

	c.Check(s.Output(), equals, "WARN: fname:1: The shell command \"sed\" should not be used in the install phase.\n")

	shline.checkCommandUse("cp")

	c.Check(s.Output(), equals, "WARN: fname:1: ${CP} should not be used to install files.\n")
}
