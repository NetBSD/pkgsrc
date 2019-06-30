package pkglint

import (
	"gopkg.in/check.v1"
	"strings"
)

func (s *Suite) Test_splitIntoShellTokens__line_continuation(c *check.C) {
	t := s.Init(c)

	words, rest := splitIntoShellTokens(dummyLine, "if true; then \\")

	c.Check(words, check.DeepEquals, []string{"if", "true", ";", "then"})
	c.Check(rest, equals, "\\")

	t.CheckOutputLines(
		"WARN: Internal pkglint error in ShTokenizer.ShAtom at \"\\\\\" (quoting=plain).")
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

// Two shell variables, next to each other,
// are two separate atoms but count as a single token.
func (s *Suite) Test_splitIntoShellTokens__two_shell_variables(c *check.C) {
	code := "echo $$i$$j"
	words, rest := splitIntoShellTokens(dummyLine, code)

	c.Check(words, deepEquals, []string{"echo", "$$i$$j"})
	c.Check(rest, equals, "")
}

func (s *Suite) Test_splitIntoShellTokens__varuse_with_embedded_space(c *check.C) {
	words, rest := splitIntoShellTokens(dummyLine, "${VAR:S/ /_/g}")

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

func (s *Suite) Test_ShellLineChecker_CheckShellCommandLine(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("awk", "AWK", AtRunTime)
	t.SetUpTool("cp", "CP", AtRunTime)
	t.SetUpTool("echo", "", AtRunTime)
	t.SetUpTool("mkdir", "MKDIR", AtRunTime) // This is actually "mkdir -p".
	t.SetUpTool("unzip", "UNZIP_CMD", AtRunTime)

	test := func(shellCommand string, diagnostics ...string) {
		mklines := t.NewMkLines("filename.mk",
			"\t"+shellCommand)
		ck := NewShellLineChecker(mklines, mklines.mklines[0])

		mklines.ForEach(func(mkline *MkLine) {
			ck.CheckShellCommandLine(ck.mkline.ShellCommand())
		})

		t.CheckOutput(diagnostics)
	}

	test("@# Comment",
		nil...)

	test("uname=`uname`; echo $$uname; echo; ${PREFIX}/bin/command",
		"WARN: filename.mk:1: Unknown shell command \"uname\".",
		"WARN: filename.mk:1: Please switch to \"set -e\" mode "+
			"before using a semicolon (after \"uname=`uname`\") to separate commands.")

	test("echo ${PKGNAME:Q}", // VucQuotPlain
		"NOTE: filename.mk:1: The :Q operator isn't necessary for ${PKGNAME} here.")

	test("echo \"${CFLAGS:Q}\"", // VucQuotDquot
		"WARN: filename.mk:1: The :Q modifier should not be used inside double quotes.",
		"WARN: filename.mk:1: Please use ${CFLAGS:M*:Q} instead of ${CFLAGS:Q} "+
			"and make sure the variable appears outside of any quoting characters.")

	test("echo '${COMMENT:Q}'", // VucQuotSquot
		"WARN: filename.mk:1: Please move ${COMMENT:Q} outside of any quoting characters.")

	test("echo target=$@ exitcode=$$? '$$' \"\\$$\"",
		"WARN: filename.mk:1: Please use \"${.TARGET}\" instead of \"$@\".",
		"WARN: filename.mk:1: The $? shell variable is often not available in \"set -e\" mode.")

	test("echo $$@",
		"WARN: filename.mk:1: The $@ shell variable should only be used in double quotes.")

	// No warning about a possibly missed variable name.
	// This occurs only rarely, and typically as part of a regular expression
	// where it is used intentionally.
	test("echo \"$$\"", // As seen by make(1); the shell sees: echo "$"
		nil...)

	test("echo \"\\n\"",
		nil...)

	test("${RUN} for f in *.c; do echo $${f%.c}; done",
		nil...)

	test("${RUN} set +x; echo $${variable+set}",
		nil...)

	// Based on mail/thunderbird/Makefile, rev. 1.159
	test("${RUN} subdir=\"`unzip -c \"$$e\" install.rdf | awk '/re/ { print \"hello\" }'`\"",
		"WARN: filename.mk:1: Double quotes inside backticks inside double quotes are error prone.",
		"WARN: filename.mk:1: The exitcode of \"unzip\" at the left of the | operator is ignored.")

	// From mail/thunderbird/Makefile, rev. 1.159
	test(""+
		"${RUN} for e in ${XPI_FILES}; do "+
		"  subdir=\"`${UNZIP_CMD} -c \"$$e\" install.rdf | "+
		""+"awk '/.../ {print;exit;}'`\" && "+
		"  ${MKDIR} \"${WRKDIR}/extensions/$$subdir\" && "+
		"  cd \"${WRKDIR}/extensions/$$subdir\" && "+
		"  ${UNZIP_CMD} -aqo $$e; "+
		"done",
		"WARN: filename.mk:1: XPI_FILES is used but not defined.",
		"WARN: filename.mk:1: Double quotes inside backticks inside double quotes are error prone.",
		"WARN: filename.mk:1: The exitcode of \"${UNZIP_CMD}\" at the left of the | operator is ignored.")

	// From x11/wxGTK28/Makefile
	// TODO: Why is TOOLS_PATH.msgfmt not recognized?
	//  At least, the warning should be more specific, mentioning USE_TOOLS.
	test(""+
		"set -e; cd ${WRKSRC}/locale; "+
		"for lang in *.po; do "+
		"  [ \"$${lang}\" = \"wxstd.po\" ] && continue; "+
		"  ${TOOLS_PATH.msgfmt} -c -o \"$${lang%.po}.mo\" \"$${lang}\"; "+
		"done",
		"WARN: filename.mk:1: Unknown shell command \"[\".",
		"WARN: filename.mk:1: Unknown shell command \"${TOOLS_PATH.msgfmt}\".")

	test("@cp from to",
		"WARN: filename.mk:1: The shell command \"cp\" should not be hidden.")

	test("-cp from to",
		"WARN: filename.mk:1: Using a leading \"-\" to suppress errors is deprecated.")

	test("-${MKDIR} deeply/nested/subdir",
		"WARN: filename.mk:1: Using a leading \"-\" to suppress errors is deprecated.")

	G.Pkg = NewPackage(t.File("category/pkgbase"))
	G.Pkg.Plist.Dirs["share/pkgbase"] = true

	// A directory that is found in the PLIST.
	// TODO: Add a test for using this command inside a conditional;
	//  the note should not appear then.
	test("${RUN} ${INSTALL_DATA_DIR} share/pkgbase ${PREFIX}/share/pkgbase",
		"NOTE: filename.mk:1: You can use AUTO_MKDIRS=yes or \"INSTALLATION_DIRS+= share/pkgbase\" "+
			"instead of \"${INSTALL_DATA_DIR}\".",
		"WARN: filename.mk:1: The INSTALL_*_DIR commands can only handle one directory at a time.")

	// A directory that is not found in the PLIST.
	test("${RUN} ${INSTALL_DATA_DIR} ${PREFIX}/share/other",
		"NOTE: filename.mk:1: You can use \"INSTALLATION_DIRS+= share/other\" instead of \"${INSTALL_DATA_DIR}\".")

	G.Pkg = nil

	// See PR 46570, item "1. It does not"
	// No warning about missing error checking ("set -e").
	test("for x in 1 2 3; do echo \"$$x\" || exit 1; done",
		nil...)
}

// TODO: Document in detail that strip is not a regular tool.
func (s *Suite) Test_ShellLineChecker_CheckShellCommandLine__strip(c *check.C) {
	t := s.Init(c)

	test := func(shellCommand string) {
		mklines := t.NewMkLines("filename.mk",
			"\t"+shellCommand)

		mklines.ForEach(func(mkline *MkLine) {
			ck := NewShellLineChecker(mklines, mkline)
			ck.CheckShellCommandLine(mkline.ShellCommand())
		})
	}

	test("${STRIP} executable")

	t.CheckOutputLines(
		"WARN: filename.mk:1: Unknown shell command \"${STRIP}\".",
		"WARN: filename.mk:1: STRIP is used but not defined.")

	t.SetUpVartypes()

	test("${STRIP} executable")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_ShellLineChecker_CheckShellCommandLine__nofix(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("echo", "", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		"\techo ${PKGNAME:Q}")
	ck := NewShellLineChecker(mklines, mklines.mklines[0])

	ck.CheckShellCommandLine("echo ${PKGNAME:Q}")

	t.CheckOutputLines(
		"NOTE: Makefile:1: The :Q operator isn't necessary for ${PKGNAME} here.")
}

func (s *Suite) Test_ShellLineChecker_CheckShellCommandLine__show_autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--show-autofix")
	t.SetUpVartypes()
	t.SetUpTool("echo", "", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		"\techo ${PKGNAME:Q}")
	ck := NewShellLineChecker(mklines, mklines.mklines[0])

	ck.CheckShellCommandLine("echo ${PKGNAME:Q}")

	t.CheckOutputLines(
		"NOTE: Makefile:1: The :Q operator isn't necessary for ${PKGNAME} here.",
		"AUTOFIX: Makefile:1: Replacing \"${PKGNAME:Q}\" with \"${PKGNAME}\".")
}

func (s *Suite) Test_ShellLineChecker_CheckShellCommandLine__autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--autofix")
	t.SetUpVartypes()
	t.SetUpTool("echo", "", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		"\techo ${PKGNAME:Q}")
	ck := NewShellLineChecker(mklines, mklines.mklines[0])

	ck.CheckShellCommandLine("echo ${PKGNAME:Q}")

	t.CheckOutputLines(
		"AUTOFIX: Makefile:1: Replacing \"${PKGNAME:Q}\" with \"${PKGNAME}\".")

	// TODO: There should be a general way of testing a code in the three modes:
	//  default, --show-autofix, --autofix.
}

func (s *Suite) Test_ShellProgramChecker_checkPipeExitcode(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("cat", "", AtRunTime)
	t.SetUpTool("echo", "", AtRunTime)
	t.SetUpTool("printf", "", AtRunTime)
	t.SetUpTool("sed", "", AtRunTime)
	t.SetUpTool("right-side", "", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		"\t echo | right-side",
		"\t sed s,s,s, | right-side",
		"\t printf | sed s,s,s, | right-side ",
		"\t cat | right-side",
		"\t cat | echo | right-side",
		"\t echo | cat | right-side",
		"\t sed s,s,s, filename | right-side",
		"\t sed s,s,s < input | right-side",
		"\t ./unknown | right-side",
		"\t var=value | right-side",
		"\t if :; then :; fi | right-side",
		"\t var=`cat file` | right-side")

	for _, mkline := range mklines.mklines {
		ck := NewShellLineChecker(mklines, mkline)
		ck.CheckShellCommandLine(mkline.ShellCommand())
	}

	t.CheckOutputLines(
		"WARN: Makefile:4: The exitcode of \"cat\" at the left of the | operator is ignored.",
		"WARN: Makefile:5: The exitcode of \"cat\" at the left of the | operator is ignored.",
		"WARN: Makefile:6: The exitcode of \"cat\" at the left of the | operator is ignored.",
		"WARN: Makefile:7: The exitcode of \"sed\" at the left of the | operator is ignored.",
		"WARN: Makefile:8: The exitcode of \"sed\" at the left of the | operator is ignored.",
		"WARN: Makefile:9: The exitcode of \"./unknown\" at the left of the | operator is ignored.",
		"WARN: Makefile:11: The exitcode of the command at the left of the | operator is ignored.",
		"WARN: Makefile:12: The exitcode of the command at the left of the | operator is ignored.")
}

// TODO: Document the exact purpose of this test, or split it into useful tests.
func (s *Suite) Test_ShellLineChecker_CheckShellCommandLine__implementation(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("filename.mk",
		"# dummy")
	ck := NewShellLineChecker(mklines, mklines.mklines[0])

	// foobar="`echo \"foo   bar\"`"
	text := "foobar=\"`echo \\\"foo   bar\\\"`\""

	tokens, rest := splitIntoShellTokens(dummyLine, text)

	c.Check(tokens, deepEquals, []string{text})
	c.Check(rest, equals, "")

	mklines.ForEach(func(mkline *MkLine) { ck.CheckWord(text, false, RunTime) })

	t.CheckOutputLines(
		"WARN: filename.mk:1: Unknown shell command \"echo\".")

	mklines.ForEach(func(mkline *MkLine) { ck.CheckShellCommandLine(text) })

	// No parse errors
	t.CheckOutputLines(
		"WARN: filename.mk:1: Unknown shell command \"echo\".")
}

func (s *Suite) Test_ShellLineChecker_CheckShellCommandLine__dollar_without_variable(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("pax", "", AtRunTime)
	mklines := t.NewMkLines("filename.mk",
		"# dummy")
	ck := NewShellLineChecker(mklines, mklines.mklines[0])

	ck.CheckShellCommandLine("pax -rwpp -s /.*~$$//g . ${DESTDIR}${PREFIX}")

	t.CheckOutputLines(
		"WARN: filename.mk:1: Substitution commands like \"/.*~$$//g\" should always be quoted.")
}

func (s *Suite) Test_ShellLineChecker_CheckWord(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	test := func(shellWord string, checkQuoting bool, diagnostics ...string) {
		// See checkVaruseUndefined and checkVarassignLeftNotUsed.
		ck := t.NewShellLineChecker("\t echo " + shellWord)
		ck.CheckWord(shellWord, checkQuoting, RunTime)
		t.CheckOutput(diagnostics)
	}

	// No warning for the outer variable since it is completely indirect.
	// The inner variable ${list} must still be defined, though.
	test("${${list}}", false,
		"WARN: filename.mk:1: list is used but not defined.")

	// No warning for variables that are partly indirect.
	// TODO: Why not?
	test("${SED_FILE.${id}}", false,
		"WARN: filename.mk:1: id is used but not defined.")

	// TODO: Since $@ refers to ${.TARGET} and not sh.argv, there is no point in checking for quotes.
	// TODO: Having the same tests for $$@ would be much more interesting.

	// The unquoted $@ takes a different code path in pkglint than the quoted $@.
	test("$@", false,
		"WARN: filename.mk:1: Please use \"${.TARGET}\" instead of \"$@\".")

	// When $@ appears as part of a shell token, it takes another code path in pkglint.
	test("-$@-", false,
		"WARN: filename.mk:1: Please use \"${.TARGET}\" instead of \"$@\".")

	// The unquoted $@ takes a different code path in pkglint than the quoted $@.
	test("\"$@\"", false,
		"WARN: filename.mk:1: Please use \"${.TARGET}\" instead of \"$@\".")

	test("${COMMENT:Q}", true,
		nil...)

	test("\"${DISTINFO_FILE:Q}\"", true,
		"NOTE: filename.mk:1: The :Q operator isn't necessary for ${DISTINFO_FILE} here.")

	test("embed${DISTINFO_FILE:Q}ded", true,
		"NOTE: filename.mk:1: The :Q operator isn't necessary for ${DISTINFO_FILE} here.")

	test("s,\\.,,", true,
		nil...)

	test("\"s,\\.,,\"", true,
		nil...)
}

func (s *Suite) Test_ShellLineChecker_CheckWord__dollar_without_variable(c *check.C) {
	t := s.Init(c)

	ck := t.NewShellLineChecker("# dummy")

	ck.CheckWord("/.*~$$//g", false, RunTime) // Typical argument to pax(1).

	t.CheckOutputEmpty()
}

func (s *Suite) Test_ShellLineChecker_CheckWord__backslash_plus(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("find", "FIND", AtRunTime)
	ck := t.NewShellLineChecker("\tfind . -exec rm -rf {} \\+")

	ck.CheckShellCommandLine(ck.mkline.ShellCommand())

	// A backslash before any other character than " \ ` is discarded by the parser.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_ShellLineChecker_CheckWord__squot_dollar(c *check.C) {
	t := s.Init(c)

	ck := t.NewShellLineChecker("\t'$")

	ck.CheckWord(ck.mkline.ShellCommand(), false, RunTime)

	// FIXME: Should be parsed correctly. Make passes the dollar through (probably),
	//  and the shell parser should complain about the unfinished string literal.
	t.CheckOutputLines(
		"WARN: filename.mk:1: Internal pkglint error in ShTokenizer.ShAtom at \"$\" (quoting=s).",
		"WARN: filename.mk:1: Internal pkglint error in ShellLine.CheckWord at \"'$\" (quoting=s), rest: $")
}

func (s *Suite) Test_ShellLineChecker_CheckWord__dquot_dollar(c *check.C) {
	t := s.Init(c)

	ck := t.NewShellLineChecker("\t\"$")

	ck.CheckWord(ck.mkline.ShellCommand(), false, RunTime)

	// FIXME: Make consumes the dollar silently.
	//  This could be worth another pkglint warning.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_ShellLineChecker_CheckWord__dollar_subshell(c *check.C) {
	t := s.Init(c)

	ck := t.NewShellLineChecker("\t$$(echo output)")

	ck.CheckWord(ck.mkline.ShellCommand(), false, RunTime)

	t.CheckOutputLines(
		"WARN: filename.mk:1: Invoking subshells via $(...) is not portable enough.")
}

func (s *Suite) Test_ShellLineChecker_CheckWord__PKGMANDIR(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("chat/ircII/Makefile",
		MkCvsID,
		"CONFIGURE_ARGS+=--mandir=${DESTDIR}${PREFIX}/man",
		"CONFIGURE_ARGS+=--mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: chat/ircII/Makefile:2: Please use ${PKGMANDIR} instead of \"man\".",
		"NOTE: chat/ircII/Makefile:2: This variable value should be aligned to column 25.",
		"NOTE: chat/ircII/Makefile:3: This variable value should be aligned to column 25.")
}

func (s *Suite) Test_ShellLineChecker_CheckWord__empty(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"JAVA_CLASSPATH=\t# empty")

	mklines.Check()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_ShellLineChecker_unescapeBackticks__unfinished(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"",
		"pre-configure:",
		"\t`${VAR}",      // Error in first shell word
		"\techo `${VAR}") // Error after first shell word

	// Breakpoint in ShellLine.CheckShellCommand
	// Breakpoint in ShellLine.CheckToken
	// Breakpoint in ShellLine.unescapeBackticks
	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:4: Pkglint ShellLine.CheckShellCommand: splitIntoShellTokens couldn't parse \"`${VAR}\"",
		"WARN: filename.mk:5: Pkglint ShellLine.CheckShellCommand: splitIntoShellTokens couldn't parse \"`${VAR}\"")
}

func (s *Suite) Test_ShellLineChecker_unescapeBackticks__unfinished_direct(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("dummy.mk",
		MkCvsID,
		"\t# shell command")

	// This call is unrealistic. It doesn't happen in practice, and this
	// direct, forcing test is only to reach the code coverage.
	atoms := []*ShAtom{
		NewShAtom(shtText, "`", shqBackt)}
	NewShellLineChecker(mklines, mklines.mklines[1]).
		unescapeBackticks(&atoms, shqBackt)

	t.CheckOutputLines(
		"ERROR: dummy.mk:2: Unfinished backticks after \"\".")
}

func (s *Suite) Test_ShellLineChecker_variableNeedsQuoting(c *check.C) {

	test := func(shVarname string, expected bool) {
		c.Check((*ShellLineChecker).variableNeedsQuoting(nil, shVarname), equals, expected)
	}

	test("#", false) // A length is always an integer.
	test("?", false) // The exit code is always an integer.
	test("$", false) // The PID is always an integer.

	// In most cases, file and directory names don't contain special characters,
	// and if they do, the package will probably not build. Therefore pkglint
	// doesn't require them to be quoted, but doing so does not hurt.
	test("d", false)    // Typically used for directories.
	test("f", false)    // Typically used for files.
	test("i", false)    // Typically used for literal values without special characters.
	test("id", false)   // Identifiers usually don't use special characters.
	test("dir", false)  // See d above.
	test("file", false) // See f above.
	test("src", false)  // Typically used when copying files or directories.
	test("dst", false)  // Typically used when copying files or directories.

	test("bindir", false) // A typical GNU-style directory.
	test("mandir", false) // A typical GNU-style directory.
	test("prefix", false) //

	test("bindirs", true) // A list of directories is typically separated by spaces.
	test("var", true)     // Other variables are unknown, so they should be quoted.
	test("0", true)       // The program name may contain special characters when given as full path.
	test("1", true)       // Command line arguments can be arbitrary strings.
}

func (s *Suite) Test_ShellLineChecker_variableNeedsQuoting__integration(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("cp", "", AtRunTime)
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"",
		// It's a bit silly to use shell variables in CONFIGURE_ARGS,
		// but as of January 2019 that's the only way to run ShellLine.variableNeedsQuoting.
		"CONFIGURE_ARGS+=\t; cp $$dir $$\\# $$target",
		"pre-configure:",
		"\tcp $$dir $$\\# $$target")

	mklines.Check()

	// As of January 2019, the quoting check is disabled for real shell commands.
	// See ShellLine.CheckShellCommand, spc.checkWord.
	t.CheckOutputLines(
		"WARN: filename.mk:3: Unquoted shell variable \"target\".")
}

func (s *Suite) Test_ShellLineChecker_CheckShellCommandLine__echo(c *check.C) {
	t := s.Init(c)

	echo := t.SetUpTool("echo", "ECHO", AtRunTime)
	echo.MustUseVarForm = true
	mklines := t.NewMkLines("filename.mk",
		"# dummy")
	mkline := t.NewMkLine("filename.mk", 3, "# dummy")

	MkLineChecker{mklines, mkline}.checkText("echo \"hello, world\"")

	t.CheckOutputEmpty()

	NewShellLineChecker(mklines, mkline).CheckShellCommandLine("echo \"hello, world\"")

	t.CheckOutputLines(
		"WARN: filename.mk:3: Please use \"${ECHO}\" instead of \"echo\".")
}

func (s *Suite) Test_ShellLineChecker_CheckShellCommandLine__shell_variables(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("install", "INSTALL", AtRunTime)
	t.SetUpTool("cp", "CP", AtRunTime)
	t.SetUpTool("mv", "MV", AtRunTime)
	t.SetUpTool("sed", "SED", AtRunTime)
	text := "for f in *.pl; do ${SED} s,@PREFIX@,${PREFIX}, < $f > $f.tmp && ${MV} $f.tmp $f; done"
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"\t"+text)

	ck := NewShellLineChecker(mklines, mklines.mklines[2])
	ck.CheckShellCommandLine(text)

	t.CheckOutputLines(
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Make variable or $$f if you mean a shell variable.",
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Make variable or $$f if you mean a shell variable.",
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Make variable or $$f if you mean a shell variable.",
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Make variable or $$f if you mean a shell variable.",
		"NOTE: Makefile:3: Please use the SUBST framework instead of ${SED} and ${MV}.",
		"WARN: Makefile:3: f is used but not defined.")

	ck.CheckShellCommandLine("install -c manpage.1 ${PREFIX}/man/man1/manpage.1")

	t.CheckOutputLines(
		"WARN: Makefile:3: Please use ${PKGMANDIR} instead of \"man\".")

	ck.CheckShellCommandLine("cp init-script ${PREFIX}/etc/rc.d/service")

	t.CheckOutputLines(
		"WARN: Makefile:3: Please use the RCD_SCRIPTS mechanism to install rc.d scripts automatically to ${RCD_SCRIPTS_EXAMPLEDIR}.")
}

func (s *Suite) Test_ShellLineChecker_checkInstallCommand(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		"\t# dummy")
	mklines.target = "do-install"

	ck := NewShellLineChecker(mklines, mklines.mklines[0])

	ck.checkInstallCommand("sed")

	t.CheckOutputLines(
		"WARN: filename.mk:1: The shell command \"sed\" should not be used in the install phase.")

	ck.checkInstallCommand("cp")

	t.CheckOutputLines(
		"WARN: filename.mk:1: ${CP} should not be used to install files.")
}

func (s *Suite) Test_ShellLineChecker_CheckShellCommandLine__sed_and_mv(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("sed", "SED", AtRunTime)
	t.SetUpTool("mv", "MV", AtRunTime)
	ck := t.NewShellLineChecker("\t${RUN} ${SED} 's,#,// comment:,g' filename > filename.tmp; ${MV} filename.tmp filename")

	ck.CheckShellCommandLine(ck.mkline.ShellCommand())

	t.CheckOutputLines(
		"NOTE: filename.mk:1: Please use the SUBST framework instead of ${SED} and ${MV}.")
}

func (s *Suite) Test_ShellLineChecker_CheckShellCommandLine__subshell(c *check.C) {
	t := s.Init(c)

	ck := t.NewShellLineChecker("\t${RUN} uname=$$(uname)")

	ck.CheckShellCommandLine(ck.mkline.ShellCommand())

	t.CheckOutputLines(
		"WARN: filename.mk:1: Invoking subshells via $(...) is not portable enough.")
}

func (s *Suite) Test_ShellLineChecker_CheckShellCommandLine__install_dir(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	ck := t.NewShellLineChecker("\t${RUN} ${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/dir1 ${DESTDIR}${PREFIX}/dir2")

	ck.CheckShellCommandLine(ck.mkline.ShellCommand())

	t.CheckOutputLines(
		"NOTE: filename.mk:1: You can use \"INSTALLATION_DIRS+= dir1\" instead of \"${INSTALL_DATA_DIR}\".",
		"NOTE: filename.mk:1: You can use \"INSTALLATION_DIRS+= dir2\" instead of \"${INSTALL_DATA_DIR}\".",
		"WARN: filename.mk:1: The INSTALL_*_DIR commands can only handle one directory at a time.")

	ck.CheckShellCommandLine("${INSTALL_DATA_DIR} -d -m 0755 ${DESTDIR}${PREFIX}/share/examples/gdchart")

	// No warning about multiple directories, since 0755 is an option, not an argument.
	t.CheckOutputLines(
		"NOTE: filename.mk:1: You can use \"INSTALLATION_DIRS+= share/examples/gdchart\" instead of \"${INSTALL_DATA_DIR}\".")

	ck.CheckShellCommandLine("${INSTALL_DATA_DIR} -d -m 0755 ${DESTDIR}${PREFIX}/dir1 ${PREFIX}/dir2")

	t.CheckOutputLines(
		"NOTE: filename.mk:1: You can use \"INSTALLATION_DIRS+= dir1\" instead of \"${INSTALL_DATA_DIR}\".",
		"NOTE: filename.mk:1: You can use \"INSTALLATION_DIRS+= dir2\" instead of \"${INSTALL_DATA_DIR}\".",
		"WARN: filename.mk:1: The INSTALL_*_DIR commands can only handle one directory at a time.")
}

func (s *Suite) Test_ShellLineChecker_CheckShellCommandLine__install_option_d(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	ck := t.NewShellLineChecker("\t${RUN} ${INSTALL} -d ${DESTDIR}${PREFIX}/dir1 ${DESTDIR}${PREFIX}/dir2")

	ck.CheckShellCommandLine(ck.mkline.ShellCommand())

	t.CheckOutputLines(
		"NOTE: filename.mk:1: You can use \"INSTALLATION_DIRS+= dir1\" instead of \"${INSTALL} -d\".",
		"NOTE: filename.mk:1: You can use \"INSTALLATION_DIRS+= dir2\" instead of \"${INSTALL} -d\".")
}

func (s *Suite) Test_ShellLineChecker__shell_comment_with_line_continuation(c *check.C) {
	t := s.Init(c)

	mklines := t.SetUpFileMkLines("Makefile",
		MkCvsID,
		"pre-install:",
		"\t"+"# comment\\",
		"\t"+"echo \"hello\"")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/Makefile:3--4: A shell comment does not stop at the end of line.")
}

func (s *Suite) Test_ShellLineChecker_checkWordQuoting(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("grep", "GREP", AtRunTime)

	test := func(input string, diagnostics ...string) {
		mklines := t.NewMkLines("module.mk",
			"\t"+input)
		ck := NewShellLineChecker(mklines, mklines.mklines[0])

		ck.checkWordQuoting(ck.mkline.ShellCommand(), true, RunTime)

		t.CheckOutput(diagnostics)
	}

	test(
		"socklen=`${GREP} 'expr' ${WRKSRC}/config.h`",
		nil...)

	test(
		"s,$$from,$$to,",
		"WARN: module.mk:1: Unquoted shell variable \"from\".",
		"WARN: module.mk:1: Unquoted shell variable \"to\".")

	// This variable is typically defined by GNU Configure,
	// which cannot handle directories with special characters.
	// Therefore using it unquoted is considered safe.
	test(
		"${PREFIX}/$$bindir/program",
		nil...)

	test(
		"$$@",
		"WARN: module.mk:1: The $@ shell variable should only be used in double quotes.")

	// TODO: Add separate tests for "set +e" and "set -e".
	test(
		"$$?",
		"WARN: module.mk:1: The $? shell variable is often not available in \"set -e\" mode.")

	test(
		"$$(cat /bin/true)",
		"WARN: module.mk:1: Invoking subshells via $(...) is not portable enough.")

	test(
		"\"$$\"",
		nil...)

	test(
		"$$$$",
		nil...)

	test(
		"``",
		nil...)
}

func (s *Suite) Test_ShellLineChecker_checkShVarUsePlain__default_warning_level(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine( /* none */ )
	t.SetUpVartypes()
	t.SetUpTool("echo", "", AtRunTime)

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"CONFIGURE_ARGS+=\techo $$@ $$var",
		"",
		"pre-configure:",
		"\techo $$@ $$var")

	mklines.Check()

	// Using $@ outside of double quotes is so obviously wrong that
	// the warning is issued by default.
	t.CheckOutputLines(
		"WARN: filename.mk:2: The $@ shell variable should only be used in double quotes.",
		"WARN: filename.mk:5: The $@ shell variable should only be used in double quotes.")
}

func (s *Suite) Test_ShellLineChecker_checkShVarUsePlain__Wall(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("echo", "", AtRunTime)

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"CONFIGURE_ARGS+=\techo $$@ $$var",
		"",
		"pre-configure:",
		"\techo $$@ $$var")

	mklines.Check()

	// FIXME: It is inconsistent that the check for unquoted shell
	//  variables is enabled for CONFIGURE_ARGS (where shell variables
	//  don't make sense at all) but not for real shell commands.
	t.CheckOutputLines(
		"WARN: filename.mk:2: The $@ shell variable should only be used in double quotes.",
		"WARN: filename.mk:2: Unquoted shell variable \"var\".",
		"WARN: filename.mk:5: The $@ shell variable should only be used in double quotes.")
}

func (s *Suite) Test_ShellLineChecker_unescapeBackticks(c *check.C) {
	t := s.Init(c)

	test := func(input string, expectedOutput string, expectedRest string, diagnostics ...string) {
		ck := t.NewShellLineChecker("# dummy")

		tok := NewShTokenizer(nil, input, false)
		atoms := tok.ShAtoms()

		// Set up the correct quoting mode for the test by skipping
		// uninteresting atoms at the beginning.
		q := shqPlain
		for atoms[0].MkText != "`" {
			q = atoms[0].Quoting
			atoms = atoms[1:]
		}
		c.Check(tok.Rest(), equals, "")

		backtCommand := ck.unescapeBackticks(&atoms, q)

		var actualRest strings.Builder
		for _, atom := range atoms {
			actualRest.WriteString(atom.MkText)
		}

		c.Check(backtCommand, equals, expectedOutput)
		c.Check(actualRest.String(), equals, expectedRest)
		t.CheckOutput(diagnostics)
	}

	test("`echo`end", "echo", "end")
	test("`echo $$var`end", "echo $$var", "end")
	test("``end", "", "end")
	test("`echo \"hello\"`end", "echo \"hello\"", "end")
	test("`echo 'hello'`end", "echo 'hello'", "end")
	test("`echo '\\\\\\\\'`end", "echo '\\\\'", "end")

	// Only the characters " $ ` \ are unescaped. All others stay the same.
	test("`echo '\\n'`end", "echo '\\n'", "end",
		// TODO: Add more details regarding which backslash is meant.
		"WARN: filename.mk:1: Backslashes should be doubled inside backticks.")
	test("\tsocklen=`${GREP} 'expr' ${WRKSRC}/config.h`", "${GREP} 'expr' ${WRKSRC}/config.h", "")

	// The 2xx test cases are in shqDquot mode.

	test("\"`echo`\"", "echo", "\"")
	test("\"`echo \"\"`\"", "echo \"\"", "\"",
		"WARN: filename.mk:1: Double quotes inside backticks inside double quotes are error prone.")

	// varname="`echo \"one   two\" "\ " "three"`"
	test(
		"varname=\"`echo \\\"one   two\\\" \"\\ \" \"three\"`\"",
		"echo \"one   two\" \"\\ \" \"three\"",
		"\"",

		// TODO: Add more details regarding which backslash and backtick is meant.
		"WARN: filename.mk:1: Backslashes should be doubled inside backticks.",
		"WARN: filename.mk:1: Double quotes inside backticks inside double quotes are error prone.",
		"WARN: filename.mk:1: Double quotes inside backticks inside double quotes are error prone.")
}

func (s *Suite) Test_ShellLineChecker_unescapeBackticks__dquotBacktDquot(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("echo", "", AtRunTime)
	mklines := t.NewMkLines("dummy.mk",
		MkCvsID,
		"\t var=\"`echo \"\"`\"")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: dummy.mk:2: Double quotes inside backticks inside double quotes are error prone.")
}

func (s *Suite) Test_ShellLineChecker__variable_outside_quotes(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("dummy.mk",
		MkCvsID,
		"GZIP=\t${ECHO} $$comment")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: dummy.mk:2: The variable GZIP should not be set by any package.",
		"WARN: dummy.mk:2: Unquoted shell variable \"comment\".",
		"WARN: dummy.mk:2: ECHO should not be used indirectly at load time (via GZIP).")
}

func (s *Suite) Test_ShellLineChecker_CheckShellCommand__cd_inside_if(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("echo", "ECHO", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"\t${RUN} if cd /bin; then echo \"/bin exists.\"; fi")

	mklines.Check()

	t.CheckOutputLines(
		"ERROR: Makefile:3: The Solaris /bin/sh cannot handle \"cd\" inside conditionals.")
}

func (s *Suite) Test_ShellLineChecker_CheckShellCommand__negated_pipe(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("echo", "ECHO", AtRunTime)
	t.SetUpTool("test", "TEST", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"\t${RUN} if ! test -f /etc/passwd; then echo \"passwd is missing.\"; fi")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:3: The Solaris /bin/sh does not support negation of shell commands.")
}

func (s *Suite) Test_ShellLineChecker_CheckShellCommand__subshell(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("echo", "ECHO", AtRunTime)
	t.SetUpTool("expr", "EXPR", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
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
		"WARN: Makefile:5: Internal pkglint error in ShTokenizer.ShAtom at \"$$(echo 1024))\" (quoting=S).",
		"WARN: Makefile:5: Invoking subshells via $(...) is not portable enough.",
		"WARN: Makefile:6: Internal pkglint error in ShTokenizer.ShAtom at \"$$(echo 1024)))\" (quoting=S).",
		"WARN: Makefile:6: The shell command \"(\" should not be hidden.",
		"WARN: Makefile:6: Internal pkglint error in ShTokenizer.ShAtom at \"$$(echo 1024)))\" (quoting=S).",
		"WARN: Makefile:6: Invoking subshells via $(...) is not portable enough.")
}

func (s *Suite) Test_ShellLineChecker_CheckShellCommand__case_patterns_from_variable(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"pre-configure:",
		"\tcase $$file in ${CHECK_PERMS_SKIP:@pattern@${pattern}) ;;@} *) continue; esac")

	mklines.Check()

	// FIXME: Support the above variable expansion.
	t.CheckOutputLines(
		"WARN: Makefile:4: Pkglint ShellLine.CheckShellCommand: " +
			"parse error at []string{\"*\", \")\", \"continue\", \";\", \"esac\"}")
}

func (s *Suite) Test_ShellLineChecker_checkHiddenAndSuppress(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("echo", "ECHO", AtRunTime)
	t.SetUpTool("ls", "LS", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"show-all-targets: .PHONY",
		"\t@echo 'hello'",
		"\t@ls -l",
		"",
		"anything-message: .PHONY",
		"\t@echo 'may be hidden'",
		"\t@ls 'may be hidden'",
		"",
		"pre-configure:",
		"\t@")

	mklines.Check()

	// No warning about the hidden ls since the target names start
	// with "show-" or end with "-message".
	t.CheckOutputEmpty()
}

func (s *Suite) Test_ShellLineChecker_checkHiddenAndSuppress__no_tracing(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("ls", "LS", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"pre-configure:",
		"\t@ls -l")
	t.DisableTracing()

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:4: The shell command \"ls\" should not be hidden.")
}

func (s *Suite) Test_SimpleCommandChecker_handleForbiddenCommand(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"\t${RUN} mktexlsr; texconfig")

	mklines.Check()

	t.CheckOutputLines(
		"ERROR: Makefile:3: \"mktexlsr\" must not be used in Makefiles.",
		"ERROR: Makefile:3: \"texconfig\" must not be used in Makefiles.")
}

func (s *Suite) Test_SimpleCommandChecker_handleCommandVariable(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("perl", "PERL5", AtRunTime)
	t.SetUpTool("perl6", "PERL6", Nowhere)
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"PERL5_VARS_CMD=\t${PERL5:Q}",
		"PERL5_VARS_CMD=\t${PERL6:Q}",
		"",
		"pre-configure:",
		"\t${PERL5_VARS_CMD} -e 'print 12345'")

	mklines.Check()

	// FIXME: In PERL5:Q and PERL6:Q, the :Q is wrong.
	t.CheckOutputLines(
		"WARN: Makefile:4: The \"${PERL6:Q}\" tool is used but not added to USE_TOOLS.")
}

func (s *Suite) Test_SimpleCommandChecker_handleCommandVariable__parameterized(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	G.Pkg = NewPackage(t.File("category/package"))
	t.FinishSetUp()

	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"MY_TOOL.i386=\t${PREFIX}/bin/tool-i386",
		"MY_TOOL.x86_64=\t${PREFIX}/bin/tool-x86_64",
		"",
		"pre-configure:",
		"\t${MY_TOOL.amd64} -e 'print 12345'",
		"\t${UNKNOWN_TOOL}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:8: Unknown shell command \"${UNKNOWN_TOOL}\".",
		"WARN: Makefile:8: UNKNOWN_TOOL is used but not defined.")
}

func (s *Suite) Test_SimpleCommandChecker_handleCommandVariable__followed_by_literal(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	G.Pkg = NewPackage(t.File("category/package"))
	t.FinishSetUp()

	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"QTDIR=\t${PREFIX}",
		"",
		"pre-configure:",
		"\t${QTDIR}/bin/release")

	mklines.Check()

	t.CheckOutputEmpty()
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
// The PYTHON_BIN variable below must not be called *_CMD, or another code path is taken.
func (s *Suite) Test_SimpleCommandChecker_handleCommandVariable__from_package(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"post-install:",
		"\t${PYTHON_BIN}",
		"",
		".include \"extra.mk\"")
	t.CreateFileLines("category/package/extra.mk",
		MkCvsID,
		"PYTHON_BIN=\tmy_cmd")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_SimpleCommandChecker_handleComment(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		MkCvsID,
		"\t# comment; continuation")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: file.mk:2: A shell comment should not contain semicolons.")
}

// This test ensures that the command line options to INSTALL_*_DIR are properly
// parsed and do not lead to "can only handle one directory at a time" warnings.
func (s *Suite) Test_SimpleCommandChecker_checkInstallMulti(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("install.mk",
		MkCvsID,
		"",
		"do-install:",
		"\t${INSTALL_PROGRAM_DIR} -m 0555 -g ${APACHE_GROUP} -o ${APACHE_USER} \\",
		"\t\t${DESTDIR}${PREFIX}/lib/apache-modules")

	mklines.Check()

	t.CheckOutputLines(
		"NOTE: install.mk:4--5: You can use \"INSTALLATION_DIRS+= lib/apache-modules\" " +
			"instead of \"${INSTALL_PROGRAM_DIR}\".")
}

func (s *Suite) Test_SimpleCommandChecker_checkPaxPe(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("pax", "PAX", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
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

	t.SetUpTool("echo", "ECHO", AtRunTime)
	t.SetUpTool("echo -n", "ECHO_N", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
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

	t.SetUpTool("ls", "", AtRunTime)
	t.SetUpTool("printf", "", AtRunTime)
	t.SetUpTool("wc", "", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"pre-configure:",
		"\t${RUN} while cd ..; do printf .; done",
		"\t${RUN} while cd .. && cd ..; do printf .; done", // Unusual, therefore no warning.
		"\t${RUN} if cd ..; then printf .; fi",
		"\t${RUN} ! cd ..",
		"\t${RUN} if cd ..; printf 'ok\\n'; then printf .; fi",
		"\t${RUN} if cd .. | wc -l; then printf .; fi",  // Unusual, therefore no warning.
		"\t${RUN} if cd .. && cd ..; then printf .; fi") // Unusual, therefore no warning.

	mklines.Check()

	t.CheckOutputLines(
		"ERROR: Makefile:3: The Solaris /bin/sh cannot handle \"cd\" inside conditionals.",
		"ERROR: Makefile:5: The Solaris /bin/sh cannot handle \"cd\" inside conditionals.",
		"WARN: Makefile:6: The Solaris /bin/sh does not support negation of shell commands.",
		"WARN: Makefile:8: The exitcode of \"cd\" at the left of the | operator is ignored.")
}

func (s *Suite) Test_SimpleCommandChecker_checkRegexReplace(c *check.C) {
	t := s.Init(c)

	test := func(cmd string, diagnostics ...string) {
		t.SetUpTool("pax", "PAX", AtRunTime)
		t.SetUpTool("sed", "SED", AtRunTime)
		mklines := t.NewMkLines("Makefile",
			MkCvsID,
			"pre-configure:",
			"\t"+cmd)

		mklines.Check()

		t.CheckOutput(diagnostics)
	}

	test("${PAX} -s s,.*,, src dst",
		"WARN: Makefile:3: Substitution commands like \"s,.*,,\" should always be quoted.")

	test("pax -s s,.*,, src dst",
		"WARN: Makefile:3: Substitution commands like \"s,.*,,\" should always be quoted.")

	test("${SED} -e s,.*,, src dst",
		"WARN: Makefile:3: Substitution commands like \"s,.*,,\" should always be quoted.")

	test("sed -e s,.*,, src dst",
		"WARN: Makefile:3: Substitution commands like \"s,.*,,\" should always be quoted.")

	// The * is properly enclosed in quotes.
	test("sed -e 's,.*,,' -e \"s,-*,,\"",
		nil...)

	// The * is properly escaped.
	test("sed -e s,.\\*,,",
		nil...)

	test("pax -s s,\\.orig,, src dst",
		nil...)

	test("sed -e s,a,b,g src dst",
		nil...)

	// TODO: Merge the code with BtSedCommands.

	// TODO: Finally, remove the G.Testing from the main code.
	//  Then, remove this test case.
	G.Testing = false
	test("sed -e s,.*,match,",
		nil...)
	G.Testing = true
}

func (s *Suite) Test_SimpleCommandChecker_checkAutoMkdirs(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("awk", "AWK", AtRunTime)
	t.SetUpTool("cp", "CP", AtRunTime)
	t.SetUpTool("echo", "", AtRunTime)
	t.SetUpTool("mkdir", "MKDIR", AtRunTime) // This is actually "mkdir -p".
	t.SetUpTool("unzip", "UNZIP_CMD", AtRunTime)

	test := func(shellCommand string, diagnostics ...string) {
		mklines := t.NewMkLines("filename.mk",
			"\t"+shellCommand)
		ck := NewShellLineChecker(mklines, mklines.mklines[0])

		mklines.ForEach(func(mkline *MkLine) {
			ck.CheckShellCommandLine(ck.mkline.ShellCommand())
		})

		t.CheckOutput(diagnostics)
	}

	// AUTO_MKDIRS applies only when installing directories.
	test("${RUN} ${INSTALL} -c ${WRKSRC}/file ${PREFIX}/bin/",
		nil...)

	// TODO: Warn that ${INSTALL} -d can only handle a single directory.
	test("${RUN} ${INSTALL} -m 0755 -d ${PREFIX}/first ${PREFIX}/second",
		"NOTE: filename.mk:1: You can use \"INSTALLATION_DIRS+= first\" instead of \"${INSTALL} -d\".",
		"NOTE: filename.mk:1: You can use \"INSTALLATION_DIRS+= second\" instead of \"${INSTALL} -d\".")

	G.Pkg = NewPackage(t.File("category/pkgbase"))
	G.Pkg.Plist.Dirs["share/pkgbase"] = true

	// A directory that is found in the PLIST.
	// TODO: Add a test for using this command inside a conditional;
	//  the note should not appear then.
	test("${RUN} ${INSTALL_DATA_DIR} share/pkgbase ${PREFIX}/share/pkgbase",
		"NOTE: filename.mk:1: You can use AUTO_MKDIRS=yes or \"INSTALLATION_DIRS+= share/pkgbase\" "+
			"instead of \"${INSTALL_DATA_DIR}\".",
		"WARN: filename.mk:1: The INSTALL_*_DIR commands can only handle one directory at a time.")

	// Directories from .for loops are too dynamic to be replaced with AUTO_MKDIRS.
	// TODO: Expand simple .for loops.
	test("${RUN} ${INSTALL_DATA_DIR} ${PREFIX}/${dir}",
		"WARN: filename.mk:1: dir is used but not defined.")

	// A directory that is not found in the PLIST would not be created by AUTO_MKDIRS,
	// therefore only INSTALLATION_DIRS is suggested.
	test("${RUN} ${INSTALL_DATA_DIR} ${PREFIX}/share/other",
		"NOTE: filename.mk:1: You can use \"INSTALLATION_DIRS+= share/other\" instead of \"${INSTALL_DATA_DIR}\".")
}

func (s *Suite) Test_ShellProgramChecker_checkSetE__simple_commands(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("echo", "", AtRunTime)
	t.SetUpTool("rm", "", AtRunTime)
	t.SetUpTool("touch", "", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"pre-configure:",
		"\techo 1; echo 2; echo 3",
		"\techo 1; touch file; rm file",
		"\techo 1; var=value; echo 3")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:4: Please switch to \"set -e\" mode before using a semicolon " +
			"(after \"touch file\") to separate commands.")
}

func (s *Suite) Test_ShellProgramChecker_checkSetE__compound_commands(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("echo", "", AtRunTime)
	t.SetUpTool("touch", "", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"pre-configure:",
		"\ttouch file; for f in file; do echo \"$$f\"; done",
		"\tfor f in file; do echo \"$$f\"; done; touch file",
		"\ttouch 1; touch 2; touch 3; touch 4")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:3: Please switch to \"set -e\" mode before using a semicolon "+
			"(after \"touch file\") to separate commands.",
		"WARN: Makefile:5: Please switch to \"set -e\" mode before using a semicolon "+
			"(after \"touch 1\") to separate commands.")
}

func (s *Suite) Test_ShellProgramChecker_checkSetE__no_tracing(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("touch", "", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"pre-configure:",
		"\ttouch 1; touch 2")
	t.DisableTracing()

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:3: Please switch to \"set -e\" mode before using a semicolon " +
			"(after \"touch 1\") to separate commands.")
}

func (s *Suite) Test_ShellProgramChecker_canFail(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("basename", "", AtRunTime)
	t.SetUpTool("dirname", "", AtRunTime)
	t.SetUpTool("echo", "", AtRunTime)
	t.SetUpTool("env", "", AtRunTime)
	t.SetUpTool("grep", "GREP", AtRunTime)
	t.SetUpTool("sed", "", AtRunTime)
	t.SetUpTool("touch", "", AtRunTime)
	t.SetUpTool("tr", "tr", AtRunTime)
	t.SetUpTool("true", "TRUE", AtRunTime)

	test := func(cmd string, diagnostics ...string) {
		mklines := t.NewMkLines("Makefile",
			MkCvsID,
			"pre-configure:",
			"\t"+cmd+" ; echo 'done.'")

		mklines.Check()

		t.CheckOutput(diagnostics)
	}

	test("socklen=`${GREP} 'expr' ${WRKSRC}/config.h`",
		"WARN: Makefile:3: Please switch to \"set -e\" mode before using a semicolon "+
			"(after \"socklen=`${GREP} 'expr' ${WRKSRC}/config.h`\") to separate commands.")

	test("socklen=`${GREP} 'expr' ${WRKSRC}/config.h || ${TRUE}`",
		nil...)

	test("socklen=$$(expr 16)",
		"WARN: Makefile:3: Invoking subshells via $(...) is not portable enough.",
		"WARN: Makefile:3: Please switch to \"set -e\" mode before using a semicolon "+
			"(after \"socklen=$$(expr 16)\") to separate commands.")

	test("socklen=$$(expr 16 || true)",
		"WARN: Makefile:3: Invoking subshells via $(...) is not portable enough.")

	test("socklen=$$(expr 16 || ${TRUE})",
		"WARN: Makefile:3: Invoking subshells via $(...) is not portable enough.")

	test("${ECHO_MSG} \"Message\"",
		nil...)

	test("${FAIL_MSG} \"Failure\"",
		"WARN: Makefile:3: Please switch to \"set -e\" mode before using a semicolon "+
			"(after \"${FAIL_MSG} \\\"Failure\\\"\") to separate commands.")

	test("set -x",
		"WARN: Makefile:3: Please switch to \"set -e\" mode before using a semicolon "+
			"(after \"set -x\") to separate commands.")

	test("echo 'input' | sed -e s,in,out,",
		nil...)

	test("sed -e s,in,out,",
		nil...)

	test("sed s,in,out,",
		nil...)

	test("grep input",
		nil...)

	test("grep pattern file...",
		"WARN: Makefile:3: Please switch to \"set -e\" mode before using a semicolon "+
			"(after \"grep pattern file...\") to separate commands.")

	test("touch file",
		"WARN: Makefile:3: Please switch to \"set -e\" mode before using a semicolon "+
			"(after \"touch file\") to separate commands.")

	test("echo 'starting'",
		nil...)

	test("echo 'logging' > log",
		"WARN: Makefile:3: Please switch to \"set -e\" mode before using a semicolon "+
			"(after \"echo 'logging'\") to separate commands.")

	test("echo 'to stderr' 1>&2",
		nil...)

	test("echo 'hello' | tr -d 'aeiou'",
		nil...)

	test("env | grep '^PATH='",
		nil...)

	test("basename dir/file",
		nil...)

	test("dirname dir/file",
		nil...)
}
