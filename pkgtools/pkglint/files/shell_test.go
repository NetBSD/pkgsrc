package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) Test_splitIntoShellTokens__line_continuation(c *check.C) {
	words, rest := splitIntoShellTokens(dummyLine, "if true; then \\")

	c.Check(words, check.DeepEquals, []string{"if", "true", ";", "then"})
	c.Check(rest, equals, "\\")

	c.Check(s.Output(), equals, "WARN: Pkglint parse error in ShTokenizer.ShAtom at \"\\\\\" (quoting=plain)\n")
}

func (s *Suite) Test_splitIntoShellTokens__dollar_slash(c *check.C) {
	words, rest := splitIntoShellTokens(dummyLine, "pax -s /.*~$$//g")

	c.Check(words, check.DeepEquals, []string{"pax", "-s", "/.*~$$//g"})
	c.Check(rest, equals, "")
}

func (s *Suite) Test_splitIntoShellTokens__dollar_subshell(c *check.C) {
	words, rest := splitIntoShellTokens(dummyLine, "id=$$(${AWK} '{print}' < ${WRKSRC}/idfile) && echo \"$$id\"")

	c.Check(words, deepEquals, []string{"id=", "$$(", "${AWK}", "'{print}'", "<", "${WRKSRC}/idfile", ")", "&&", "echo", "\"$$id\""})
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
	s.UseCommandLine(c, "-Wall")
	G.Mk = s.NewMkLines("fname",
		"# dummy")
	shline := NewShellLine(G.Mk.mklines[0])

	shline.CheckShellCommandLine("@# Comment")

	c.Check(s.Output(), equals, "")

	shline.CheckShellCommandLine("uname=`uname`; echo $$uname; echo")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: Unknown shell command \"uname\".\n"+
		"WARN: fname:1: Unknown shell command \"echo\".\n"+
		"WARN: fname:1: Unknown shell command \"echo\".\n")

	s.RegisterTool(&Tool{Name: "echo", Predefined: true})
	G.Mk = s.NewMkLines("fname",
		"# dummy")
	G.globalData.InitVartypes()

	shline.CheckShellCommandLine("echo ${PKGNAME:Q}") // vucQuotPlain

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: PKGNAME may not be used in this file; it would be ok in Makefile, Makefile.*, *.mk.\n"+
		"NOTE: fname:1: The :Q operator isn't necessary for ${PKGNAME} here.\n")

	shline.CheckShellCommandLine("echo \"${CFLAGS:Q}\"") // vucQuotDquot

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: Please don't use the :Q operator in double quotes.\n"+
		"WARN: fname:1: CFLAGS may not be used in this file; it would be ok in Makefile, Makefile.common, options.mk, *.mk.\n"+
		"WARN: fname:1: Please use ${CFLAGS:M*:Q} instead of ${CFLAGS:Q} and make sure the variable appears outside of any quoting characters.\n")

	shline.CheckShellCommandLine("echo '${COMMENT:Q}'") // vucQuotSquot

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: COMMENT may not be used in any file; it is a write-only variable.\n"+
		"WARN: fname:1: Please move ${COMMENT:Q} outside of any quoting characters.\n")

	shline.CheckShellCommandLine("echo target=$@ exitcode=$$? '$$' \"\\$$\"")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: Please use \"${.TARGET}\" instead of \"$@\".\n"+
		"WARN: fname:1: The $? shell variable is often not available in \"set -e\" mode.\n")

	shline.CheckShellCommandLine("echo $$@")

	c.Check(s.Output(), equals, "WARN: fname:1: The $@ shell variable should only be used in double quotes.\n")

	shline.CheckShellCommandLine("echo \"$$\"") // As seen by make(1); the shell sees: echo "$"

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: Pkglint parse error in ShTokenizer.ShAtom at \"$$\\\"\" (quoting=d)\n"+
		"WARN: fname:1: Pkglint ShellLine.CheckShellCommand: parse error at [\"]\n")

	shline.CheckShellCommandLine("echo \"\\n\"")

	c.Check(s.Output(), equals, "")

	shline.CheckShellCommandLine("${RUN} for f in *.c; do echo $${f%.c}; done")

	c.Check(s.Output(), equals, "")

	shline.CheckShellCommandLine("${RUN} echo $${variable+set}")

	c.Check(s.Output(), equals, "")

	// Based on mail/thunderbird/Makefile, rev. 1.159
	shline.CheckShellCommandLine("${RUN} subdir=\"`unzip -c \"$$e\" install.rdf | awk '/re/ { print \"hello\" }'`\"")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: The exitcode of the left-hand-side command of the pipe operator is ignored.\n"+
		"WARN: fname:1: Unknown shell command \"unzip\".\n"+
		"WARN: fname:1: Unknown shell command \"awk\".\n")

	// From mail/thunderbird/Makefile, rev. 1.159
	shline.CheckShellCommandLine("" +
		"${RUN} for e in ${XPI_FILES}; do " +
		"  subdir=\"`${UNZIP_CMD} -c \"$$e\" install.rdf | awk '/^    <em:id>/ {sub(\".*<em:id>\",\"\");sub(\"</em:id>.*\",\"\");print;exit;}'`\" && " +
		"  ${MKDIR} \"${WRKDIR}/extensions/$$subdir\" && " +
		"  cd \"${WRKDIR}/extensions/$$subdir\" && " +
		"  ${UNZIP_CMD} -aqo $$e; " +
		"done")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: XPI_FILES is used but not defined. Spelling mistake?\n"+
		"WARN: fname:1: The exitcode of the left-hand-side command of the pipe operator is ignored.\n"+
		"WARN: fname:1: UNZIP_CMD is used but not defined. Spelling mistake?\n"+
		"WARN: fname:1: Unknown shell command \"awk\".\n"+
		"WARN: fname:1: Unknown shell command \"${MKDIR}\".\n"+
		"WARN: fname:1: MKDIR is used but not defined. Spelling mistake?\n"+
		"WARN: fname:1: UNZIP_CMD is used but not defined. Spelling mistake?\n")

	// From x11/wxGTK28/Makefile
	shline.CheckShellCommandLine("" +
		"set -e; cd ${WRKSRC}/locale; " +
		"for lang in *.po; do " +
		"  [ \"$${lang}\" = \"wxstd.po\" ] && continue; " +
		"  ${TOOLS_PATH.msgfmt} -c -o \"$${lang%.po}.mo\" \"$${lang}\"; " +
		"done")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: WRKSRC may not be used in this file; it would be ok in Makefile, Makefile.*, *.mk.\n"+
		"WARN: fname:1: Unknown shell command \"[\".\n"+
		"WARN: fname:1: Unknown shell command \"${TOOLS_PATH.msgfmt}\".\n")

	shline.CheckShellCommandLine("@cp from to")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: The shell command \"cp\" should not be hidden.\n"+
		"WARN: fname:1: Unknown shell command \"cp\".\n")

	shline.CheckShellCommandLine("${RUN} ${INSTALL_DATA_DIR} share/pkgbase ${PREFIX}/share/pkgbase")

	c.Check(s.Output(), equals, ""+
		"NOTE: fname:1: You can use AUTO_MKDIRS=yes or \"INSTALLATION_DIRS+= share/pkgbase\" instead of \"${INSTALL_DATA_DIR}\".\n"+
		"WARN: fname:1: The INSTALL_*_DIR commands can only handle one directory at a time.\n")

	// See PR 46570, item "1. It does not"
	shline.CheckShellCommandLine("for x in 1 2 3; do echo \"$$x\" || exit 1; done")

	c.Check(s.Output(), equals, "") // No warning about missing error checking.
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__nofix(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	s.RegisterTool(&Tool{Name: "echo", Predefined: true})
	G.Mk = s.NewMkLines("Makefile",
		"\techo ${PKGNAME:Q}")
	shline := NewShellLine(G.Mk.mklines[0])

	c.Check(shline.line.raw[0].textnl, equals, "\techo ${PKGNAME:Q}\n")
	c.Check(shline.line.raw[0].Lineno, equals, 1)

	shline.CheckShellCommandLine("echo ${PKGNAME:Q}")

	c.Check(s.Output(), equals, ""+
		"NOTE: Makefile:1: The :Q operator isn't necessary for ${PKGNAME} here.\n")
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__show_autofix(c *check.C) {
	s.UseCommandLine(c, "-Wall", "--show-autofix")
	G.globalData.InitVartypes()
	s.RegisterTool(&Tool{Name: "echo", Predefined: true})
	G.Mk = s.NewMkLines("Makefile",
		"\techo ${PKGNAME:Q}")
	shline := NewShellLine(G.Mk.mklines[0])

	shline.CheckShellCommandLine("echo ${PKGNAME:Q}")

	c.Check(s.Output(), equals, ""+
		"NOTE: Makefile:1: The :Q operator isn't necessary for ${PKGNAME} here.\n"+
		"AUTOFIX: Makefile:1: Replacing \"${PKGNAME:Q}\" with \"${PKGNAME}\".\n")
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__autofix(c *check.C) {
	s.UseCommandLine(c, "-Wall", "--autofix")
	G.globalData.InitVartypes()
	s.RegisterTool(&Tool{Name: "echo", Predefined: true})
	G.Mk = s.NewMkLines("Makefile",
		"\techo ${PKGNAME:Q}")
	shline := NewShellLine(G.Mk.mklines[0])

	shline.CheckShellCommandLine("echo ${PKGNAME:Q}")

	c.Check(s.Output(), equals, ""+
		"AUTOFIX: Makefile:1: Replacing \"${PKGNAME:Q}\" with \"${PKGNAME}\".\n")
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__implementation(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("fname",
		"# dummy")
	shline := NewShellLine(G.Mk.mklines[0])

	// foobar="`echo \"foo   bar\"`"
	text := "foobar=\"`echo \\\"foo   bar\\\"`\""

	tokens, rest := splitIntoShellTokens(dummyLine, text)

	c.Check(tokens, deepEquals, []string{text})
	c.Check(rest, equals, "")

	shline.CheckWord(text, false)

	c.Check(s.Output(), equals, "WARN: fname:1: Unknown shell command \"echo\".\n")

	shline.CheckShellCommandLine(text)

	c.Check(s.Output(), equals, ""+ // No parse errors
		"WARN: fname:1: Unknown shell command \"echo\".\n")
}

func (s *Suite) Test_ShellLine_CheckShelltext__dollar_without_variable(c *check.C) {
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("fname",
		"# dummy")
	shline := NewShellLine(G.Mk.mklines[0])
	s.RegisterTool(&Tool{Name: "pax", Varname: "PAX"})
	G.Mk.tools["pax"] = true

	shline.CheckShellCommandLine("pax -rwpp -s /.*~$$//g . ${DESTDIR}${PREFIX}")

	c.Check(s.Output(), equals, "")
}

func (s *Suite) Test_ShellLine_CheckWord(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	shline := NewShellLine(NewMkLine(NewLine("fname", 1, "# dummy", nil)))

	shline.CheckWord("${${list}}", false)

	c.Check(s.Output(), equals, "") // No warning for variables that are completely indirect.

	shline.CheckWord("${SED_FILE.${id}}", false)

	c.Check(s.Output(), equals, "") // No warning for variables that are partly indirect.

	shline.CheckWord("\"$@\"", false)

	c.Check(s.Output(), equals, "WARN: fname:1: Please use \"${.TARGET}\" instead of \"$@\".\n")

	shline.CheckWord("${COMMENT:Q}", true)

	c.Check(s.Output(), equals, "WARN: fname:1: COMMENT may not be used in any file; it is a write-only variable.\n")

	shline.CheckWord("\"${DISTINFO_FILE:Q}\"", true)

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: DISTINFO_FILE may not be used in this file; it would be ok in Makefile, Makefile.*, *.mk.\n"+
		"NOTE: fname:1: The :Q operator isn't necessary for ${DISTINFO_FILE} here.\n")

	shline.CheckWord("embed${DISTINFO_FILE:Q}ded", true)

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: DISTINFO_FILE may not be used in this file; it would be ok in Makefile, Makefile.*, *.mk.\n"+
		"NOTE: fname:1: The :Q operator isn't necessary for ${DISTINFO_FILE} here.\n")

	shline.CheckWord("s,\\.,,", true)

	c.Check(s.Output(), equals, "")

	shline.CheckWord("\"s,\\.,,\"", true)

	c.Check(s.Output(), equals, "")
}

func (s *Suite) Test_ShellLine_CheckWord__dollar_without_variable(c *check.C) {
	shline := NewShellLine(NewMkLine(NewLine("fname", 1, "# dummy", nil)))

	shline.CheckWord("/.*~$$//g", false) // Typical argument to pax(1).

	c.Check(s.Output(), equals, "")
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__echo(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	s.RegisterTool(&Tool{Name: "echo", Varname: "ECHO", MustUseVarForm: true, Predefined: true})
	G.Mk = s.NewMkLines("fname",
		"# dummy")
	mkline := NewMkLine(NewLine("fname", 3, "# dummy", nil))

	mkline.checkText("echo \"hello, world\"")

	c.Check(s.Output(), equals, "")

	NewShellLine(mkline).CheckShellCommandLine("echo \"hello, world\"")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:3: Please use \"${ECHO}\" instead of \"echo\".\n")
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__shell_variables(c *check.C) {
	text := "\tfor f in *.pl; do ${SED} s,@PREFIX@,${PREFIX}, < $f > $f.tmp && ${MV} $f.tmp $f; done"

	shline := NewShellLine(NewMkLine(NewLine("Makefile", 3, text, nil)))
	shline.CheckShellCommandLine(text)

	c.Check(s.Output(), equals, ""+
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Makefile variable or $$f if you mean a shell variable.\n"+
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Makefile variable or $$f if you mean a shell variable.\n"+
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Makefile variable or $$f if you mean a shell variable.\n"+
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Makefile variable or $$f if you mean a shell variable.\n"+
		"NOTE: Makefile:3: Please use the SUBST framework instead of ${SED} and ${MV}.\n")

	shline.CheckShellCommandLine("install -c manpage.1 ${PREFIX}/man/man1/manpage.1")

	c.Check(s.Output(), equals, "WARN: Makefile:3: Please use ${PKGMANDIR} instead of \"man\".\n")

	shline.CheckShellCommandLine("cp init-script ${PREFIX}/etc/rc.d/service")

	c.Check(s.Output(), equals, "WARN: Makefile:3: Please use the RCD_SCRIPTS mechanism to install rc.d scripts automatically to ${RCD_SCRIPTS_EXAMPLEDIR}.\n")
}

func (s *Suite) Test_ShellLine_checkCommandUse(c *check.C) {
	G.Mk = s.NewMkLines("fname",
		"# dummy")
	G.Mk.target = "do-install"

	shline := NewShellLine(NewMkLine(NewLine("fname", 1, "\tdummy", nil)))

	shline.checkCommandUse("sed")

	c.Check(s.Output(), equals, "WARN: fname:1: The shell command \"sed\" should not be used in the install phase.\n")

	shline.checkCommandUse("cp")

	c.Check(s.Output(), equals, "WARN: fname:1: ${CP} should not be used to install files.\n")
}

func (s *Suite) Test_splitIntoMkWords(c *check.C) {
	url := "http://registry.gimp.org/file/fix-ca.c?action=download&id=9884&file="

	words, rest := splitIntoShellTokens(dummyLine, url) // Doesn’t really make sense

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
	shline := NewShellLine(NewMkLine(NewLine("Makefile", 85, "\t${RUN} ${SED} 's,#,// comment:,g' fname > fname.tmp; ${MV} fname.tmp fname", nil)))

	shline.CheckShellCommandLine(shline.mkline.Shellcmd())

	c.Check(s.Output(), equals, "NOTE: Makefile:85: Please use the SUBST framework instead of ${SED} and ${MV}.\n")
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__subshell(c *check.C) {
	shline := NewShellLine(NewMkLine(NewLine("Makefile", 85, "\t${RUN} uname=$$(uname)", nil)))

	shline.CheckShellCommandLine(shline.mkline.Shellcmd())

	c.Check(s.Output(), equals, "WARN: Makefile:85: Invoking subshells via $(...) is not portable enough.\n")
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__install_dir(c *check.C) {
	shline := NewShellLine(NewMkLine(NewLine("Makefile", 85, "\t${RUN} ${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/dir1 ${DESTDIR}${PREFIX}/dir2", nil)))

	shline.CheckShellCommandLine(shline.mkline.Shellcmd())

	c.Check(s.Output(), equals, ""+
		"NOTE: Makefile:85: You can use AUTO_MKDIRS=yes or \"INSTALLATION_DIRS+= dir1\" instead of \"${INSTALL_DATA_DIR}\".\n"+
		"NOTE: Makefile:85: You can use AUTO_MKDIRS=yes or \"INSTALLATION_DIRS+= dir2\" instead of \"${INSTALL_DATA_DIR}\".\n"+
		"WARN: Makefile:85: The INSTALL_*_DIR commands can only handle one directory at a time.\n")

	shline.CheckShellCommandLine("${INSTALL_DATA_DIR} -d -m 0755 ${DESTDIR}${PREFIX}/share/examples/gdchart")

	// No warning about multiple directories, since 0755 is an option, not an argument.
	c.Check(s.Output(), equals, ""+
		"NOTE: Makefile:85: You can use AUTO_MKDIRS=yes or \"INSTALLATION_DIRS+= share/examples/gdchart\" instead of \"${INSTALL_DATA_DIR}\".\n")

	shline.CheckShellCommandLine("${INSTALL_DATA_DIR} -d -m 0755 ${DESTDIR}${PREFIX}/dir1 ${PREFIX}/dir2")

	c.Check(s.Output(), equals, ""+
		"NOTE: Makefile:85: You can use AUTO_MKDIRS=yes or \"INSTALLATION_DIRS+= dir1\" instead of \"${INSTALL_DATA_DIR}\".\n"+
		"NOTE: Makefile:85: You can use AUTO_MKDIRS=yes or \"INSTALLATION_DIRS+= dir2\" instead of \"${INSTALL_DATA_DIR}\".\n"+
		"WARN: Makefile:85: The INSTALL_*_DIR commands can only handle one directory at a time.\n")
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__install_option_d(c *check.C) {
	shline := NewShellLine(NewMkLine(NewLine("Makefile", 85, "\t${RUN} ${INSTALL} -d ${DESTDIR}${PREFIX}/dir1 ${DESTDIR}${PREFIX}/dir2", nil)))

	shline.CheckShellCommandLine(shline.mkline.Shellcmd())

	c.Check(s.Output(), equals, ""+
		"NOTE: Makefile:85: You can use AUTO_MKDIRS=yes or \"INSTALLATION_DIRS+= dir1\" instead of \"${INSTALL} -d\".\n"+
		"NOTE: Makefile:85: You can use AUTO_MKDIRS=yes or \"INSTALLATION_DIRS+= dir2\" instead of \"${INSTALL} -d\".\n")
}

func (s *Suite) Test_ShellLine__shell_comment_with_line_continuation(c *check.C) {
	tmpfile := s.CreateTmpFile(c, "Makefile", ""+
		"# $"+"NetBSD$\n"+
		"pre-install:\n"+
		"\t"+"# comment\\\n"+
		"\t"+"echo \"hello\"\n")
	lines := LoadNonemptyLines(tmpfile, true)

	NewMkLines(lines).Check()

	c.Check(s.Output(), equals, "WARN: ~/Makefile:3--4: A shell comment does not stop at the end of line.\n")
}

func (s *Suite) Test_ShellLine_unescapeBackticks(c *check.C) {
	shline := NewShellLine(NewMkLine(dummyLine))
	// foobar="`echo \"foo   bar\"`"
	text := "foobar=\"`echo \\\"foo   bar\\\"`\""
	repl := NewPrefixReplacer(text)
	repl.AdvanceStr("foobar=\"`")

	backtCommand, newQuoting := shline.unescapeBackticks(text, repl, shqDquotBackt)
	c.Check(backtCommand, equals, "echo \"foo   bar\"")
	c.Check(newQuoting, equals, shqDquot)
	c.Check(repl.rest, equals, "\"")
}
