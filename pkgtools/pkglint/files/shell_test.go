package main

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_splitIntoShellTokens__line_continuation(c *check.C) {
	t := s.Init(c)

	words, rest := splitIntoShellTokens(dummyLine, "if true; then \\")

	c.Check(words, check.DeepEquals, []string{"if", "true", ";", "then"})
	c.Check(rest, equals, "\\")

	t.CheckOutputLines(
		"WARN: Pkglint parse error in ShTokenizer.ShAtom at \"\\\\\" (quoting=plain).")
}

func (s *Suite) Test_splitIntoShellTokens__dollar_slash(c *check.C) {
	words, rest := splitIntoShellTokens(dummyLine, "pax -s /.*~$$//g")

	c.Check(words, check.DeepEquals, []string{"pax", "-s", "/.*~$$//g"})
	c.Check(rest, equals, "")
}

func (s *Suite) Test_splitIntoShellTokens__dollar_subshell(c *check.C) {
	words, rest := splitIntoShellTokens(dummyLine, "id=$$(${AWK} '{print}' < ${WRKSRC}/idfile) && echo \"$$id\"")

	c.Check(words, deepEquals, []string{"id=$$(${AWK} '{print}' < ${WRKSRC}/idfile)", "&&", "echo", "\"$$id\""})
	c.Check(rest, equals, "")
}

func (s *Suite) Test_splitIntoShellTokens__semicolons(c *check.C) {
	words, rest := splitIntoShellTokens(dummyLine, "word1 word2;;;")

	c.Check(words, deepEquals, []string{"word1", "word2", ";;", ";"})
	c.Check(rest, equals, "")
}

func (s *Suite) Test_splitIntoShellTokens__whitespace(c *check.C) {
	text := "\t${RUN} cd ${WRKSRC}&&(${ECHO} ${PERL5:Q};${ECHO})|${BASH} ./install"
	words, rest := splitIntoShellTokens(dummyLine, text)

	c.Check(words, deepEquals, []string{
		"${RUN}",
		"cd", "${WRKSRC}",
		"&&", "(", "${ECHO}", "${PERL5:Q}", ";", "${ECHO}", ")",
		"|", "${BASH}", "./install"})
	c.Check(rest, equals, "")
}

func (s *Suite) Test_splitIntoShellTokens__finished_dquot(c *check.C) {
	text := "\"\""
	words, rest := splitIntoShellTokens(dummyLine, text)

	c.Check(words, deepEquals, []string{"\"\""})
	c.Check(rest, equals, "")
}

func (s *Suite) Test_splitIntoShellTokens__unfinished_dquot(c *check.C) {
	text := "\t\""
	words, rest := splitIntoShellTokens(dummyLine, text)

	c.Check(words, check.IsNil)
	c.Check(rest, equals, "\"")
}

func (s *Suite) Test_splitIntoShellTokens__unescaped_dollar_in_dquot(c *check.C) {
	t := s.Init(c)

	text := "echo \"$$\""
	words, rest := splitIntoShellTokens(dummyLine, text)

	c.Check(words, deepEquals, []string{"echo", "\"$$\""})
	c.Check(rest, equals, "")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_splitIntoShellTokens__varuse_with_embedded_space_and_other_vars(c *check.C) {
	varuseWord := "${GCONF_SCHEMAS:@.s.@${INSTALL_DATA} ${WRKSRC}/src/common/dbus/${.s.} ${DESTDIR}${GCONF_SCHEMAS_DIR}/@}"
	words, rest := splitIntoShellTokens(dummyLine, varuseWord)

	c.Check(words, deepEquals, []string{varuseWord})
	c.Check(rest, equals, "")
}

func (s *Suite) Test_splitIntoMkWords__semicolons(c *check.C) {
	words, rest := splitIntoMkWords(dummyLine, "word1 word2;;;")

	c.Check(words, deepEquals, []string{"word1", "word2;;;"})
	c.Check(rest, equals, "")
}

func (s *Suite) Test_splitIntoShellTokens__varuse_with_embedded_space(c *check.C) {
	words, rest := splitIntoShellTokens(dummyLine, "${VAR:S/ /_/g}")

	c.Check(words, deepEquals, []string{"${VAR:S/ /_/g}"})
	c.Check(rest, equals, "")
}

func (s *Suite) Test_splitIntoMkWords__varuse_with_embedded_space(c *check.C) {
	words, rest := splitIntoMkWords(dummyLine, "${VAR:S/ /_/g}")

	c.Check(words, deepEquals, []string{"${VAR:S/ /_/g}"})
	c.Check(rest, equals, "")
}

func (s *Suite) Test_splitIntoShellTokens__redirect(c *check.C) {
	words, rest := splitIntoShellTokens(dummyLine, "echo 1>output 2>>append 3>|clobber 4>&5 6<input >>append")

	c.Check(words, deepEquals, []string{
		"echo",
		"1>", "output",
		"2>>", "append",
		"3>|", "clobber",
		"4>&", "5",
		"6<", "input",
		">>", "append"})
	c.Check(rest, equals, "")

	words, rest = splitIntoShellTokens(dummyLine, "echo 1> output 2>> append 3>| clobber 4>& 5 6< input >> append")

	c.Check(words, deepEquals, []string{
		"echo",
		"1>", "output",
		"2>>", "append",
		"3>|", "clobber",
		"4>&", "5",
		"6<", "input",
		">>", "append"})
	c.Check(rest, equals, "")
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.SetupTool("awk", "AWK", AtRunTime)
	t.SetupTool("cp", "CP", AtRunTime)
	t.SetupTool("mkdir", "MKDIR", AtRunTime) // This is actually "mkdir -p".
	t.SetupTool("unzip", "UNZIP_CMD", AtRunTime)

	checkShellCommandLine := func(shellCommand string) {
		G.Mk = t.NewMkLines("fileName",
			"\t"+shellCommand)
		shline := NewShellLine(G.Mk.mklines[0])

		G.Mk.ForEach(func(mkline MkLine) {
			shline.CheckShellCommandLine(shline.mkline.ShellCommand())
		})
	}

	checkShellCommandLine("@# Comment")

	t.CheckOutputEmpty()

	checkShellCommandLine("uname=`uname`; echo $$uname; echo; ${PREFIX}/bin/command")

	t.CheckOutputLines(
		"WARN: fileName:1: Unknown shell command \"uname\".",
		"WARN: fileName:1: Please switch to \"set -e\" mode before using a semicolon (after \"uname=`uname`\") to separate commands.",
		"WARN: fileName:1: Unknown shell command \"echo\".",
		"WARN: fileName:1: Unknown shell command \"echo\".")

	t.SetupTool("echo", "", AtRunTime)
	t.SetupVartypes()

	checkShellCommandLine("echo ${PKGNAME:Q}") // vucQuotPlain

	t.CheckOutputLines(
		"WARN: fileName:1: PKGNAME may not be used in this file; it would be ok in Makefile, Makefile.*, *.mk.",
		"NOTE: fileName:1: The :Q operator isn't necessary for ${PKGNAME} here.")

	checkShellCommandLine("echo \"${CFLAGS:Q}\"") // vucQuotDquot

	t.CheckOutputLines(
		"WARN: fileName:1: Please don't use the :Q operator in double quotes.",
		"WARN: fileName:1: CFLAGS may not be used in this file; "+
			"it would be ok in Makefile, Makefile.common, options.mk, *.mk.",
		"WARN: fileName:1: Please use ${CFLAGS:M*:Q} instead of ${CFLAGS:Q} "+
			"and make sure the variable appears outside of any quoting characters.")

	checkShellCommandLine("echo '${COMMENT:Q}'") // vucQuotSquot

	t.CheckOutputLines(
		"WARN: fileName:1: COMMENT may not be used in any file; it is a write-only variable.",
		"WARN: fileName:1: Please move ${COMMENT:Q} outside of any quoting characters.")

	checkShellCommandLine("echo target=$@ exitcode=$$? '$$' \"\\$$\"")

	t.CheckOutputLines(
		"WARN: fileName:1: Please use \"${.TARGET}\" instead of \"$@\".",
		"WARN: fileName:1: The $? shell variable is often not available in \"set -e\" mode.")

	checkShellCommandLine("echo $$@")

	t.CheckOutputLines(
		"WARN: fileName:1: The $@ shell variable should only be used in double quotes.")

	checkShellCommandLine("echo \"$$\"") // As seen by make(1); the shell sees: echo "$"

	t.CheckOutputLines(
		"WARN: fileName:1: Unescaped $ or strange shell variable found.")

	checkShellCommandLine("echo \"\\n\"")

	t.CheckOutputEmpty()

	checkShellCommandLine("${RUN} for f in *.c; do echo $${f%.c}; done")

	t.CheckOutputEmpty()

	checkShellCommandLine("${RUN} set +x; echo $${variable+set}")

	t.CheckOutputEmpty()

	// Based on mail/thunderbird/Makefile, rev. 1.159
	checkShellCommandLine("${RUN} subdir=\"`unzip -c \"$$e\" install.rdf | awk '/re/ { print \"hello\" }'`\"")

	t.CheckOutputLines(
		"WARN: fileName:1: The exitcode of \"unzip\" at the left of the | operator is ignored.")

	// From mail/thunderbird/Makefile, rev. 1.159
	checkShellCommandLine("" +
		"${RUN} for e in ${XPI_FILES}; do " +
		"  subdir=\"`${UNZIP_CMD} -c \"$$e\" install.rdf | " +
		"" + "awk '/^    <em:id>/ {sub(\".*<em:id>\",\"\");sub(\"</em:id>.*\",\"\");print;exit;}'`\" && " +
		"  ${MKDIR} \"${WRKDIR}/extensions/$$subdir\" && " +
		"  cd \"${WRKDIR}/extensions/$$subdir\" && " +
		"  ${UNZIP_CMD} -aqo $$e; " +
		"done")

	t.CheckOutputLines(
		"WARN: fileName:1: XPI_FILES is used but not defined.",
		"WARN: fileName:1: The exitcode of \"${UNZIP_CMD}\" at the left of the | operator is ignored.")

	// From x11/wxGTK28/Makefile
	checkShellCommandLine("" +
		"set -e; cd ${WRKSRC}/locale; " +
		"for lang in *.po; do " +
		"  [ \"$${lang}\" = \"wxstd.po\" ] && continue; " +
		"  ${TOOLS_PATH.msgfmt} -c -o \"$${lang%.po}.mo\" \"$${lang}\"; " +
		"done")

	t.CheckOutputLines(
		"WARN: fileName:1: WRKSRC may not be used in this file; it would be ok in Makefile, Makefile.*, *.mk.",
		"WARN: fileName:1: Unknown shell command \"[\".",
		"WARN: fileName:1: Unknown shell command \"${TOOLS_PATH.msgfmt}\".")

	checkShellCommandLine("@cp from to")

	t.CheckOutputLines(
		"WARN: fileName:1: The shell command \"cp\" should not be hidden.")

	checkShellCommandLine("-cp from to")

	t.CheckOutputLines(
		"WARN: fileName:1: Using a leading \"-\" to suppress errors is deprecated.")

	checkShellCommandLine("-${MKDIR} deeply/nested/subdir")

	t.CheckOutputLines(
		"NOTE: fileName:1: You don't need to use \"-\" before \"${MKDIR} deeply/nested/subdir\".",
		"WARN: fileName:1: Using a leading \"-\" to suppress errors is deprecated.")

	G.Pkg = NewPackage(t.File("category/pkgbase"))
	G.Pkg.Plist.Dirs["share/pkgbase"] = true

	// A directory that is found in the PLIST.
	checkShellCommandLine("${RUN} ${INSTALL_DATA_DIR} share/pkgbase ${PREFIX}/share/pkgbase")

	t.CheckOutputLines(
		"NOTE: fileName:1: You can use AUTO_MKDIRS=yes or \"INSTALLATION_DIRS+= share/pkgbase\" "+
			"instead of \"${INSTALL_DATA_DIR}\".",
		"WARN: fileName:1: The INSTALL_*_DIR commands can only handle one directory at a time.")

	// A directory that is not found in the PLIST.
	checkShellCommandLine("${RUN} ${INSTALL_DATA_DIR} ${PREFIX}/share/other")

	t.CheckOutputLines(
		"NOTE: fileName:1: You can use \"INSTALLATION_DIRS+= share/other\" instead of \"${INSTALL_DATA_DIR}\".")

	G.Pkg = nil

	// See PR 46570, item "1. It does not"
	checkShellCommandLine("for x in 1 2 3; do echo \"$$x\" || exit 1; done")

	t.CheckOutputEmpty() // No warning about missing error checking.
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__strip(c *check.C) {
	t := s.Init(c)

	checkShellCommandLine := func(shellCommand string) {
		G.Mk = t.NewMkLines("fileName",
			"\t"+shellCommand)

		G.Mk.ForEach(func(mkline MkLine) {
			shline := NewShellLine(mkline)
			shline.CheckShellCommandLine(mkline.ShellCommand())
		})
	}

	checkShellCommandLine("${STRIP} executable")

	t.CheckOutputLines(
		"WARN: fileName:1: Unknown shell command \"${STRIP}\".",
		"WARN: fileName:1: STRIP is used but not defined.")

	t.SetupVartypes()

	checkShellCommandLine("${STRIP} executable")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__nofix(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.SetupTool("echo", "", AtRunTime)
	G.Mk = t.NewMkLines("Makefile",
		"\techo ${PKGNAME:Q}")
	shline := NewShellLine(G.Mk.mklines[0])

	shline.CheckShellCommandLine("echo ${PKGNAME:Q}")

	t.CheckOutputLines(
		"NOTE: Makefile:1: The :Q operator isn't necessary for ${PKGNAME} here.")
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__show_autofix(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall", "--show-autofix")
	t.SetupVartypes()
	t.SetupTool("echo", "", AtRunTime)
	G.Mk = t.NewMkLines("Makefile",
		"\techo ${PKGNAME:Q}")
	shline := NewShellLine(G.Mk.mklines[0])

	shline.CheckShellCommandLine("echo ${PKGNAME:Q}")

	t.CheckOutputLines(
		"NOTE: Makefile:1: The :Q operator isn't necessary for ${PKGNAME} here.",
		"AUTOFIX: Makefile:1: Replacing \"${PKGNAME:Q}\" with \"${PKGNAME}\".")
}

func (s *Suite) Test_ShellProgramChecker_checkPipeExitcode(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.SetupTool("cat", "", AtRunTime)
	t.SetupTool("echo", "", AtRunTime)
	t.SetupTool("printf", "", AtRunTime)
	t.SetupTool("sed", "", AtRunTime)
	t.SetupTool("right-side", "", AtRunTime)
	G.Mk = t.NewMkLines("Makefile",
		"\t echo | right-side",
		"\t sed s,s,s, | right-side",
		"\t printf | sed s,s,s, | right-side ",
		"\t cat | right-side",
		"\t cat | echo | right-side",
		"\t echo | cat | right-side",
		"\t sed s,s,s, fileName | right-side",
		"\t sed s,s,s < input | right-side",
		"\t ./unknown | right-side",
		"\t var=value | right-side",
		"\t if :; then :; fi | right-side")

	for _, mkline := range G.Mk.mklines {
		shline := NewShellLine(mkline)
		shline.CheckShellCommandLine(mkline.ShellCommand())
	}

	t.CheckOutputLines(
		"WARN: Makefile:4: The exitcode of \"cat\" at the left of the | operator is ignored.",
		"WARN: Makefile:5: The exitcode of \"cat\" at the left of the | operator is ignored.",
		"WARN: Makefile:6: The exitcode of \"cat\" at the left of the | operator is ignored.",
		"WARN: Makefile:7: The exitcode of \"sed\" at the left of the | operator is ignored.",
		"WARN: Makefile:8: The exitcode of \"sed\" at the left of the | operator is ignored.",
		"WARN: Makefile:9: The exitcode of \"./unknown\" at the left of the | operator is ignored.",
		"WARN: Makefile:11: The exitcode of the command at the left of the | operator is ignored.")
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__autofix(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall", "--autofix")
	t.SetupVartypes()
	t.SetupTool("echo", "", AtRunTime)
	G.Mk = t.NewMkLines("Makefile",
		"\techo ${PKGNAME:Q}")
	shline := NewShellLine(G.Mk.mklines[0])

	shline.CheckShellCommandLine("echo ${PKGNAME:Q}")

	t.CheckOutputLines(
		"AUTOFIX: Makefile:1: Replacing \"${PKGNAME:Q}\" with \"${PKGNAME}\".")
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__implementation(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	G.Mk = t.NewMkLines("fileName",
		"# dummy")
	shline := NewShellLine(G.Mk.mklines[0])

	// foobar="`echo \"foo   bar\"`"
	text := "foobar=\"`echo \\\"foo   bar\\\"`\""

	tokens, rest := splitIntoShellTokens(dummyLine, text)

	c.Check(tokens, deepEquals, []string{text})
	c.Check(rest, equals, "")

	G.Mk.ForEach(func(mkline MkLine) { shline.CheckWord(text, false, RunTime) })

	t.CheckOutputLines(
		"WARN: fileName:1: Unknown shell command \"echo\".")

	G.Mk.ForEach(func(mkline MkLine) { shline.CheckShellCommandLine(text) })

	// No parse errors
	t.CheckOutputLines(
		"WARN: fileName:1: Unknown shell command \"echo\".")
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__dollar_without_variable(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.SetupTool("pax", "", AtRunTime)
	G.Mk = t.NewMkLines("fileName",
		"# dummy")
	shline := NewShellLine(G.Mk.mklines[0])

	shline.CheckShellCommandLine("pax -rwpp -s /.*~$$//g . ${DESTDIR}${PREFIX}")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_ShellLine_CheckWord(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()

	checkWord := func(shellWord string, checkQuoting bool) {
		shline := t.NewShellLine("dummy.mk", 1, "\t echo "+shellWord)

		shline.CheckWord(shellWord, checkQuoting, RunTime)
	}

	checkWord("${${list}}", false)

	checkWord("${${list}}", false)

	t.CheckOutputEmpty() // No warning for variables that are completely indirect.

	checkWord("${SED_FILE.${id}}", false)

	t.CheckOutputEmpty() // No warning for variables that are partly indirect.

	// The unquoted $@ takes a different code path in pkglint than the quoted $@.
	checkWord("$@", false)

	t.CheckOutputLines(
		"WARN: dummy.mk:1: Please use \"${.TARGET}\" instead of \"$@\".")

	// When $@ appears as part of a shell token, it takes another code path in pkglint.
	checkWord("-$@-", false)

	t.CheckOutputLines(
		"WARN: dummy.mk:1: Please use \"${.TARGET}\" instead of \"$@\".")

	// The unquoted $@ takes a different code path in pkglint than the quoted $@.
	checkWord("\"$@\"", false)

	t.CheckOutputLines(
		"WARN: dummy.mk:1: Please use \"${.TARGET}\" instead of \"$@\".")

	checkWord("${COMMENT:Q}", true)

	t.CheckOutputLines(
		"WARN: dummy.mk:1: COMMENT may not be used in any file; it is a write-only variable.")

	checkWord("\"${DISTINFO_FILE:Q}\"", true)

	t.CheckOutputLines(
		"NOTE: dummy.mk:1: The :Q operator isn't necessary for ${DISTINFO_FILE} here.")

	checkWord("embed${DISTINFO_FILE:Q}ded", true)

	t.CheckOutputLines(
		"NOTE: dummy.mk:1: The :Q operator isn't necessary for ${DISTINFO_FILE} here.")

	checkWord("s,\\.,,", true)

	t.CheckOutputEmpty()

	checkWord("\"s,\\.,,\"", true)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_ShellLine_CheckWord__dollar_without_variable(c *check.C) {
	t := s.Init(c)

	shline := t.NewShellLine("fileName", 1, "# dummy")

	shline.CheckWord("/.*~$$//g", false, RunTime) // Typical argument to pax(1).

	t.CheckOutputEmpty()
}

func (s *Suite) Test_ShellLine_CheckWord__backslash_plus(c *check.C) {
	t := s.Init(c)

	t.SetupTool("find", "FIND", AtRunTime)
	shline := t.NewShellLine("fileName", 1, "\tfind . -exec rm -rf {} \\+")

	shline.CheckShellCommandLine(shline.mkline.ShellCommand())

	// FIXME: A backslash before any other character than "\` keeps its original meaning.
	t.CheckOutputLines(
		"WARN: fileName:1: Pkglint parse error in ShellLine.CheckWord at \"\\\\+\" (quoting=plain), rest: \\+")
}

func (s *Suite) Test_ShellLine_CheckWord__squot_dollar(c *check.C) {
	t := s.Init(c)

	shline := t.NewShellLine("fileName", 1, "\t'$")

	shline.CheckWord(shline.mkline.ShellCommand(), false, RunTime)

	// FIXME: Should be parsed correctly. Make passes the dollar through (probably),
	// and the shell parser should complain about the unfinished string literal.
	t.CheckOutputLines(
		"WARN: fileName:1: Pkglint parse error in ShellLine.CheckWord at \"'$\" (quoting=s), rest: $")
}

func (s *Suite) Test_ShellLine_CheckWord__dquot_dollar(c *check.C) {
	t := s.Init(c)

	shline := t.NewShellLine("fileName", 1, "\t\"$")

	shline.CheckWord(shline.mkline.ShellCommand(), false, RunTime)

	// FIXME: Should be parsed correctly. Make passes the dollar through (probably),
	// and the shell parser should complain about the unfinished string literal.
	t.CheckOutputLines(
		"WARN: fileName:1: Pkglint parse error in ShellLine.CheckWord at \"\\\"$\" (quoting=d), rest: $")
}

func (s *Suite) Test_ShellLine_CheckWord__dollar_subshell(c *check.C) {
	t := s.Init(c)

	shline := t.NewShellLine("fileName", 1, "\t$$(echo output)")

	shline.CheckWord(shline.mkline.ShellCommand(), false, RunTime)

	t.CheckOutputLines(
		"WARN: fileName:1: Invoking subshells via $(...) is not portable enough.")
}

func (s *Suite) Test_ShellLine_CheckWord__PKGMANDIR(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	G.Mk = t.NewMkLines("chat/ircII/Makefile",
		MkRcsID,
		"CONFIGURE_ARGS+=--mandir=${DESTDIR}${PREFIX}/man",
		"CONFIGURE_ARGS+=--mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}")

	G.Mk.Check()

	t.CheckOutputLines(
		"WARN: chat/ircII/Makefile:2: Please use ${PKGMANDIR} instead of \"man\".",
		"NOTE: chat/ircII/Makefile:2: This variable value should be aligned to column 25.",
		"NOTE: chat/ircII/Makefile:3: This variable value should be aligned to column 25.")
}

func (s *Suite) Test_ShellLine_unescapeBackticks__unfinished(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("fileName.mk",
		MkRcsID,
		"",
		"pre-configure:",
		"\t`${VAR}",      // Error in first shell word
		"\techo `${VAR}") // Error after first shell word

	// Breakpoint in ShellLine.CheckShellCommand
	// Breakpoint in ShellLine.CheckToken
	// Breakpoint in ShellLine.unescapeBackticks
	mklines.Check()

	// FIXME: Mention the unfinished backquote.
	t.CheckOutputLines(
		"WARN: fileName.mk:4: Pkglint ShellLine.CheckShellCommand: parse error at []string{\"\"}",
		"WARN: fileName.mk:5: Pkglint ShellLine.CheckShellCommand: parse error at []string{\"echo\"}")
}

func (s *Suite) Test_ShellLine_unescapeBackticks__unfinished_direct(c *check.C) {
	t := s.Init(c)

	// This call is unrealistic. It doesn't happen in practice, and this
	// direct, forcing test is only to reach the code coverage.
	NewShellLine(dummyMkLine).unescapeBackticks(
		"dummy",
		G.NewPrefixReplacer(""),
		shqBackt)

	t.CheckOutputLines(
		"ERROR: Unfinished backquotes: ")
}

func (s *Suite) Test_ShellLine_variableNeedsQuoting(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.SetupTool("cp", "", AtRunTime)
	mklines := t.NewMkLines("fileName.mk",
		MkRcsID,
		"",
		// It's a bit silly to use shell variables in CONFIGURE_ARGS,
		// but currently that's the only way to run ShellLine.variableNeedsQuoting.
		"CONFIGURE_ARGS+=\t; cp $$dir $$\\# $$target",
		"pre-configure:",
		"\tcp $$dir $$\\# $$target")

	mklines.Check()

	// Quoting check is currently disabled for real shell commands.
	// See ShellLine.CheckShellCommand, spc.checkWord.
	t.CheckOutputLines(
		"WARN: fileName.mk:3: Unquoted shell variable \"target\".")
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__echo(c *check.C) {
	t := s.Init(c)

	echo := t.SetupTool("echo", "ECHO", AtRunTime)
	echo.MustUseVarForm = true
	G.Mk = t.NewMkLines("fileName",
		"# dummy")
	mkline := t.NewMkLine("fileName", 3, "# dummy")

	MkLineChecker{mkline}.checkText("echo \"hello, world\"")

	t.CheckOutputEmpty()

	NewShellLine(mkline).CheckShellCommandLine("echo \"hello, world\"")

	t.CheckOutputLines(
		"WARN: fileName:3: Please use \"${ECHO}\" instead of \"echo\".")
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__shell_variables(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.SetupTool("install", "INSTALL", AtRunTime)
	t.SetupTool("cp", "CP", AtRunTime)
	t.SetupTool("mv", "MV", AtRunTime)
	t.SetupTool("sed", "SED", AtRunTime)
	text := "\tfor f in *.pl; do ${SED} s,@PREFIX@,${PREFIX}, < $f > $f.tmp && ${MV} $f.tmp $f; done"

	shline := t.NewShellLine("Makefile", 3, text)
	shline.mkline.Tokenize(shline.mkline.ShellCommand(), true)
	shline.CheckShellCommandLine(text)

	t.CheckOutputLines(
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Makefile variable or $$f if you mean a shell variable.",
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Makefile variable or $$f if you mean a shell variable.",
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Makefile variable or $$f if you mean a shell variable.",
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Makefile variable or $$f if you mean a shell variable.",
		"NOTE: Makefile:3: Please use the SUBST framework instead of ${SED} and ${MV}.",
		"WARN: Makefile:3: f is used but not defined.",
		"WARN: Makefile:3: f is used but not defined.",
		"WARN: Makefile:3: f is used but not defined.",
		"WARN: Makefile:3: f is used but not defined.")

	shline.CheckShellCommandLine("install -c manpage.1 ${PREFIX}/man/man1/manpage.1")

	t.CheckOutputLines(
		"WARN: Makefile:3: Please use ${PKGMANDIR} instead of \"man\".")

	shline.CheckShellCommandLine("cp init-script ${PREFIX}/etc/rc.d/service")

	t.CheckOutputLines(
		"WARN: Makefile:3: Please use the RCD_SCRIPTS mechanism to install rc.d scripts automatically to ${RCD_SCRIPTS_EXAMPLEDIR}.")
}

func (s *Suite) Test_ShellLine_checkInstallCommand(c *check.C) {
	t := s.Init(c)

	G.Mk = t.NewMkLines("fileName",
		"# dummy")
	G.Mk.target = "do-install"

	shline := t.NewShellLine("fileName", 1, "\tdummy")

	shline.checkInstallCommand("sed")

	t.CheckOutputLines(
		"WARN: fileName:1: The shell command \"sed\" should not be used in the install phase.")

	shline.checkInstallCommand("cp")

	t.CheckOutputLines(
		"WARN: fileName:1: ${CP} should not be used to install files.")
}

func (s *Suite) Test_splitIntoMkWords(c *check.C) {
	url := "http://registry.gimp.org/file/fix-ca.c?action=download&id=9884&file="

	words, rest := splitIntoShellTokens(dummyLine, url) // Doesn't really make sense

	c.Check(words, check.DeepEquals, []string{"http://registry.gimp.org/file/fix-ca.c?action=download", "&", "id=9884", "&", "file="})
	c.Check(rest, equals, "")

	words, rest = splitIntoMkWords(dummyLine, url)

	c.Check(words, check.DeepEquals, []string{"http://registry.gimp.org/file/fix-ca.c?action=download&id=9884&file="})
	c.Check(rest, equals, "")

	words, rest = splitIntoMkWords(dummyLine, "a b \"c  c  c\" d;;d;; \"e\"''`` 'rest")

	c.Check(words, check.DeepEquals, []string{"a", "b", "\"c  c  c\"", "d;;d;;", "\"e\"''``"})
	c.Check(rest, equals, "'rest")
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__sed_and_mv(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.SetupTool("sed", "SED", AtRunTime)
	t.SetupTool("mv", "MV", AtRunTime)
	shline := t.NewShellLine("Makefile", 85, "\t${RUN} ${SED} 's,#,// comment:,g' fileName > fileName.tmp; ${MV} fileName.tmp fileName")

	shline.CheckShellCommandLine(shline.mkline.ShellCommand())

	t.CheckOutputLines(
		"NOTE: Makefile:85: Please use the SUBST framework instead of ${SED} and ${MV}.")
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__subshell(c *check.C) {
	t := s.Init(c)

	shline := t.NewShellLine("Makefile", 85, "\t${RUN} uname=$$(uname)")

	shline.CheckShellCommandLine(shline.mkline.ShellCommand())

	t.CheckOutputLines(
		"WARN: Makefile:85: Invoking subshells via $(...) is not portable enough.")
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__install_dir(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	shline := t.NewShellLine("Makefile", 85, "\t${RUN} ${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/dir1 ${DESTDIR}${PREFIX}/dir2")

	shline.CheckShellCommandLine(shline.mkline.ShellCommand())

	t.CheckOutputLines(
		"NOTE: Makefile:85: You can use \"INSTALLATION_DIRS+= dir1\" instead of \"${INSTALL_DATA_DIR}\".",
		"NOTE: Makefile:85: You can use \"INSTALLATION_DIRS+= dir2\" instead of \"${INSTALL_DATA_DIR}\".",
		"WARN: Makefile:85: The INSTALL_*_DIR commands can only handle one directory at a time.")

	shline.CheckShellCommandLine("${INSTALL_DATA_DIR} -d -m 0755 ${DESTDIR}${PREFIX}/share/examples/gdchart")

	// No warning about multiple directories, since 0755 is an option, not an argument.
	t.CheckOutputLines(
		"NOTE: Makefile:85: You can use \"INSTALLATION_DIRS+= share/examples/gdchart\" instead of \"${INSTALL_DATA_DIR}\".")

	shline.CheckShellCommandLine("${INSTALL_DATA_DIR} -d -m 0755 ${DESTDIR}${PREFIX}/dir1 ${PREFIX}/dir2")

	t.CheckOutputLines(
		"NOTE: Makefile:85: You can use \"INSTALLATION_DIRS+= dir1\" instead of \"${INSTALL_DATA_DIR}\".",
		"NOTE: Makefile:85: You can use \"INSTALLATION_DIRS+= dir2\" instead of \"${INSTALL_DATA_DIR}\".",
		"WARN: Makefile:85: The INSTALL_*_DIR commands can only handle one directory at a time.")
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__install_option_d(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	shline := t.NewShellLine("Makefile", 85, "\t${RUN} ${INSTALL} -d ${DESTDIR}${PREFIX}/dir1 ${DESTDIR}${PREFIX}/dir2")

	shline.CheckShellCommandLine(shline.mkline.ShellCommand())

	t.CheckOutputLines(
		"NOTE: Makefile:85: You can use \"INSTALLATION_DIRS+= dir1\" instead of \"${INSTALL} -d\".",
		"NOTE: Makefile:85: You can use \"INSTALLATION_DIRS+= dir2\" instead of \"${INSTALL} -d\".")
}

func (s *Suite) Test_ShellLine__shell_comment_with_line_continuation(c *check.C) {
	t := s.Init(c)

	mklines := t.SetupFileMkLines("Makefile",
		MkRcsID,
		"pre-install:",
		"\t"+"# comment\\",
		"\t"+"echo \"hello\"")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/Makefile:3--4: A shell comment does not stop at the end of line.")
}

func (s *Suite) Test_ShellLine_unescapeBackticks(c *check.C) {
	t := s.Init(c)

	shline := t.NewShellLine("dummy.mk", 13, "# dummy")
	// foobar="`echo \"foo   bar\" "\ " "three"`"
	text := "foobar=\"`echo \\\"foo   bar\\\" \"\\ \" \"three\"`\""
	repl := G.NewPrefixReplacer(text)
	repl.AdvanceStr("foobar=\"`")

	backtCommand, newQuoting := shline.unescapeBackticks(text, repl, shqDquotBackt)

	c.Check(backtCommand, equals, "echo \"foo   bar\" \"\\ \" \"three\"")
	c.Check(newQuoting, equals, shqDquot)
	c.Check(repl.Rest(), equals, "\"")

	t.CheckOutputLines(
		"WARN: dummy.mk:13: Backslashes should be doubled inside backticks.")
}

func (s *Suite) Test_ShellLine_unescapeBackticks__dquotBacktDquot(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("dummy.mk", 13, "\t var=\"`\"\"`\"")

	MkLineChecker{mkline}.Check()

	t.CheckOutputLines(
		"WARN: dummy.mk:13: Double quotes inside backticks inside double quotes are error prone.",
		"WARN: dummy.mk:13: Double quotes inside backticks inside double quotes are error prone.")
}

func (s *Suite) Test_ShellLine__variable_outside_quotes(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.NewMkLines("dummy.mk",
		MkRcsID,
		"GZIP=\t${ECHO} $$comment")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: dummy.mk:2: The variable GZIP may not be set by any package.",
		"WARN: dummy.mk:2: Unquoted shell variable \"comment\".",
		"WARN: dummy.mk:2: ECHO should not be evaluated indirectly at load time.")
}

func (s *Suite) Test_ShellLine_CheckShellCommand__cd_inside_if(c *check.C) {
	t := s.Init(c)

	t.SetupTool("echo", "ECHO", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"\t${RUN} if cd /bin; then echo \"/bin exists.\"; fi")

	mklines.Check()

	t.CheckOutputLines(
		"ERROR: Makefile:3: The Solaris /bin/sh cannot handle \"cd\" inside conditionals.",
		"WARN: Makefile:3: Found absolute pathname: /bin")
}

func (s *Suite) Test_ShellLine_CheckShellCommand__negated_pipe(c *check.C) {
	t := s.Init(c)

	t.SetupTool("echo", "ECHO", AtRunTime)
	t.SetupTool("test", "TEST", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"\t${RUN} if ! test -f /etc/passwd; then echo \"passwd is missing.\"; fi")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:3: The Solaris /bin/sh does not support negation of shell commands.",
		"WARN: Makefile:3: Found absolute pathname: /etc/passwd")
}

func (s *Suite) Test_ShellLine_CheckShellCommand__subshell(c *check.C) {
	t := s.Init(c)

	t.SetupTool("echo", "ECHO", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"pre-configure:",
		"\t@(echo ok)",
		"\techo $$(uname -r); echo $$(expr 4 '*' $$(echo 1024))",
		"\t@(echo nb$$(uname -r) $$(${EXPR} 4 \\* $$(echo 1024)))")

	mklines.Check()

	// FIXME: Fix the parse errors (nested subshells).
	// FIXME: Fix the duplicate diagnostic in line 6.
	// FIXME: "(" is not a shell command, it's an operator.
	t.CheckOutputLines(
		"WARN: Makefile:4: The shell command \"(\" should not be hidden.",
		"WARN: Makefile:5: Pkglint parse error in ShTokenizer.ShAtom at \"$$(echo 1024))\" (quoting=S).",
		"WARN: Makefile:5: Invoking subshells via $(...) is not portable enough.",
		"WARN: Makefile:6: Pkglint parse error in ShTokenizer.ShAtom at \"$$(echo 1024)))\" (quoting=S).",
		"WARN: Makefile:6: The shell command \"(\" should not be hidden.",
		"WARN: Makefile:6: Pkglint parse error in ShTokenizer.ShAtom at \"$$(echo 1024)))\" (quoting=S).",
		"WARN: Makefile:6: Invoking subshells via $(...) is not portable enough.")
}

func (s *Suite) Test_ShellLine_CheckShellCommand__case_patterns_from_variable(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"pre-configure:",
		"\tcase $$file in ${CHECK_PERMS_SKIP:@pattern@${pattern}) ;;@} *) continue; esac")

	mklines.Check()

	// FIXME: Support the above variable expansion.
	t.CheckOutputLines(
		"WARN: Makefile:4: Pkglint ShellLine.CheckShellCommand: " +
			"parse error at []string{\"*\", \")\", \"continue\", \";\", \"esac\"}")
}

func (s *Suite) Test_ShellLine_checkHiddenAndSuppress(c *check.C) {
	t := s.Init(c)

	t.SetupTool("echo", "ECHO", AtRunTime)
	t.SetupTool("ls", "LS", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"show-all-targets: .PHONY",
		"\t@echo 'hello'",
		"\t@ls -l")

	mklines.Check()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_SimpleCommandChecker_handleForbiddenCommand(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"\t${RUN} ktrace; mktexlsr; strace; texconfig; truss")

	mklines.Check()

	t.CheckOutputLines(
		"ERROR: Makefile:3: \"ktrace\" must not be used in Makefiles.",
		"ERROR: Makefile:3: \"mktexlsr\" must not be used in Makefiles.",
		"ERROR: Makefile:3: \"strace\" must not be used in Makefiles.",
		"ERROR: Makefile:3: \"texconfig\" must not be used in Makefiles.",
		"ERROR: Makefile:3: \"truss\" must not be used in Makefiles.")
}

func (s *Suite) Test_SimpleCommandChecker_handleCommandVariable(c *check.C) {
	t := s.Init(c)

	t.SetupTool("perl", "PERL5", AtRunTime)
	t.SetupTool("perl6", "PERL6", Nowhere)
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"PERL5_VARS_CMD=\t${PERL5:Q}",
		"PERL5_VARS_CMD=\t${PERL6:Q}")

	mklines.Check()

	// FIXME: In PERL5:Q and PERL6:Q, the :Q is wrong.
	t.CheckOutputLines(
		"WARN: Makefile:3: PERL5_VARS_CMD is defined but not used.",
		"WARN: Makefile:4: The \"perl6\" tool is used but not added to USE_TOOLS.")
}

// The package Makefile and other .mk files in a package directory
// may use any shell commands defined by any included files.
// But only if the package is checked as a whole.
//
// On the contrary, when pkglint checks a single .mk file, these
// commands are not guaranteed to be defined, not even when the
// .mk file includes the file defining the command.
// FIXME: This paragraph sounds wrong. All commands from included files should be valid.
//
// The variable must not be called *_CMD, or another code path is taken.
func (s *Suite) Test_SimpleCommandChecker_handleCommandVariable__from_package(c *check.C) {
	t := s.Init(c)

	pkg := t.SetupPackage("category/package",
		"post-install:",
		"\t${PYTHON_BIN}",
		"",
		".include \"extra.mk\"")
	t.CreateFileLines("category/package/extra.mk",
		MkRcsID,
		"PYTHON_BIN=\tmy_cmd")

	G.CheckDirent(pkg)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_SimpleCommandChecker_handleComment(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("file.mk", 3, "\t# comment; continuation")

	MkLineChecker{mkline}.Check()

	t.CheckOutputLines(
		"WARN: file.mk:3: A shell comment should not contain semicolons.")
}

func (s *Suite) Test_SimpleCommandChecker_checkPaxPe(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.SetupTool("pax", "PAX", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"do-install:",
		"\t${RUN} pax -pe ${WRKSRC} ${DESTDIR}${PREFIX}",
		"\t${RUN} ${PAX} -pe ${WRKSRC} ${DESTDIR}${PREFIX}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:4: Please use the -pp option to pax(1) instead of -pe.",
		"WARN: Makefile:5: Please use the -pp option to pax(1) instead of -pe.")
}

func (s *Suite) Test_SimpleCommandChecker_checkEchoN(c *check.C) {
	t := s.Init(c)

	t.SetupTool("echo", "ECHO", AtRunTime)
	t.SetupTool("echo -n", "ECHO_N", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"do-install:",
		"\t${RUN} ${ECHO} -n 'Computing...'",
		"\t${RUN} ${ECHO_N} 'Computing...'",
		"\t${RUN} ${ECHO} 'Computing...'")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:4: Please use ${ECHO_N} instead of \"echo -n\".")
}

func (s *Suite) Test_ShellProgramChecker_checkConditionalCd(c *check.C) {
	t := s.Init(c)

	t.SetupTool("ls", "LS", AtRunTime)
	t.SetupTool("printf", "PRINTF", AtRunTime)
	t.SetupTool("tr", "TR", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"pre-configure:",
		"\t${RUN} while cd ..; do printf .; done",
		// TODO: "\t${RUN} if ls | tr -d $$; then :; fi",
		"\t${RUN} if ls | tr -d shell$$; then :; fi")

	mklines.Check()

	// FIXME: Fix the parse error.
	t.CheckOutputLines(
		"ERROR: Makefile:3: The Solaris /bin/sh cannot handle \"cd\" inside conditionals.",
		"WARN: Pkglint parse error in ShTokenizer.ShAtom at \"$$\" (quoting=plain).",
		"WARN: Makefile:4: The exitcode of \"ls\" at the left of the | operator is ignored.")
}

func (s *Suite) Test_SimpleCommandChecker_checkRegexReplace(c *check.C) {
	t := s.Init(c)

	t.SetupTool("pax", "PAX", AtRunTime)
	t.SetupTool("sed", "SED", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"pre-configure:",
		"\t${PAX} -s s,.*,, src dst",
		"\tpax -s s,.*,, src dst",
		"\t${SED} -e s,.*,, src dst",
		"\tsed -e s,.*,, src dst",
		"\tpax -s s,\\.orig,, src dst",
		"\tsed -e s,a,b,g src dst")

	mklines.Check()

	// FIXME: warn for "pax -s".
	// FIXME: warn for "sed -e".
	// TODO: don't warn for "pax .orig".
	// TODO: don't warn for "s,a,b,g".
	t.CheckOutputLines(
		"WARN: Makefile:3: Substitution commands like \"s,.*,,\" should always be quoted.",
		"WARN: Makefile:5: Substitution commands like \"s,.*,,\" should always be quoted.")

}

func (s *Suite) Test_ShellProgramChecker_checkSetE__simple_commands(c *check.C) {
	t := s.Init(c)

	t.SetupTool("echo", "", AtRunTime)
	t.SetupTool("rm", "", AtRunTime)
	t.SetupTool("touch", "", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"pre-configure:",
		"\techo 1; echo 2; echo 3",
		"\techo 1; touch file; rm file",
		"\techo 1; var=value; echo 3")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:4: Please switch to \"set -e\" mode before using a semicolon (after \"touch file\") to separate commands.")
}

func (s *Suite) Test_ShellProgramChecker_checkSetE__compound_commands(c *check.C) {
	t := s.Init(c)

	t.SetupTool("echo", "", AtRunTime)
	t.SetupTool("touch", "", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"pre-configure:",
		"\ttouch file; for f in file; do echo \"$$f\"; done",
		"\tfor f in file; do echo \"$$f\"; done; touch file")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:3: Please switch to \"set -e\" mode before using a semicolon (after \"touch file\") to separate commands.")
}

func (s *Suite) Test_ShellProgramChecker_canFail(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.SetupTool("echo", "", AtRunTime)
	t.SetupTool("grep", "GREP", AtRunTime)
	t.SetupTool("sed", "", AtRunTime)
	t.SetupTool("touch", "", AtRunTime)
	t.SetupTool("tr", "tr", AtRunTime)
	t.SetupTool("true", "TRUE", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"pre-configure:",
		"\tsocklen=`${GREP} 'expr' ${WRKSRC}/config.h`; echo 'done.'",
		"\tsocklen=`${GREP} 'expr' ${WRKSRC}/config.h || ${TRUE}`; echo 'done.'",
		"\t${ECHO_MSG} \"Message\"; echo 'done.'",
		"\t${FAIL_MSG} \"Failure\"; echo 'done.'",
		"\tset -x; echo 'done.'",
		"\techo 'input' | sed -e s,in,out,; echo 'done.'",
		"\tsed -e s,in,out,; echo 'done.'",
		"\tsed s,in,out,; echo 'done.'",
		"\tgrep input; echo 'done.'",
		"\ttouch file; echo 'done.'",
		"\techo 'starting'; echo 'done.'",
		"\techo 'logging' > log; echo 'done.'",
		"\techo 'to stderr' 1>&2; echo 'done.'",
		"\techo 'hello' | tr -d 'aeiou'")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:3: Please switch to \"set -e\" mode before using a semicolon (after \"socklen=`${GREP} 'expr' ${WRKSRC}/config.h`\") to separate commands.",
		"WARN: Makefile:6: Please switch to \"set -e\" mode before using a semicolon (after \"${FAIL_MSG} \\\"Failure\\\"\") to separate commands.",
		"WARN: Makefile:7: Please switch to \"set -e\" mode before using a semicolon (after \"set -x\") to separate commands.",
		"WARN: Makefile:12: Please switch to \"set -e\" mode before using a semicolon (after \"touch file\") to separate commands.",
		"WARN: Makefile:14: Please switch to \"set -e\" mode before using a semicolon (after \"echo 'logging'\") to separate commands.")
}
