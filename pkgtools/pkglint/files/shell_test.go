package main

import (
	"gopkg.in/check.v1"
	"netbsd.org/pkglint/textproc"
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
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()

	checkShellCommandLine := func(shellCommand string) {
		G.Mk = t.NewMkLines("fname",
			"\t"+shellCommand)
		shline := NewShellLine(G.Mk.mklines[0])

		G.Mk.ForEach(
			func(mkline MkLine) bool {
				shline.CheckShellCommandLine(shline.mkline.ShellCommand())
				return true
			},
			func(mkline MkLine) {})
	}

	checkShellCommandLine("@# Comment")

	t.CheckOutputEmpty()

	checkShellCommandLine("uname=`uname`; echo $$uname; echo; ${PREFIX}/bin/command")

	t.CheckOutputLines(
		"WARN: fname:1: Unknown shell command \"uname\".",
		"WARN: fname:1: Unknown shell command \"echo\".",
		"WARN: fname:1: Unknown shell command \"echo\".")

	t.SetupTool(&Tool{Name: "echo", Predefined: true})
	t.SetupVartypes()

	checkShellCommandLine("echo ${PKGNAME:Q}") // vucQuotPlain

	t.CheckOutputLines(
		"WARN: fname:1: PKGNAME may not be used in this file; it would be ok in Makefile, Makefile.*, *.mk.",
		"NOTE: fname:1: The :Q operator isn't necessary for ${PKGNAME} here.")

	checkShellCommandLine("echo \"${CFLAGS:Q}\"") // vucQuotDquot

	t.CheckOutputLines(
		"WARN: fname:1: Please don't use the :Q operator in double quotes.",
		"WARN: fname:1: CFLAGS may not be used in this file; "+
			"it would be ok in Makefile, Makefile.common, options.mk, *.mk.",
		"WARN: fname:1: Please use ${CFLAGS:M*:Q} instead of ${CFLAGS:Q} "+
			"and make sure the variable appears outside of any quoting characters.")

	checkShellCommandLine("echo '${COMMENT:Q}'") // vucQuotSquot

	t.CheckOutputLines(
		"WARN: fname:1: COMMENT may not be used in any file; it is a write-only variable.",
		"WARN: fname:1: Please move ${COMMENT:Q} outside of any quoting characters.")

	checkShellCommandLine("echo target=$@ exitcode=$$? '$$' \"\\$$\"")

	t.CheckOutputLines(
		"WARN: fname:1: Please use \"${.TARGET}\" instead of \"$@\".",
		"WARN: fname:1: The $? shell variable is often not available in \"set -e\" mode.")

	checkShellCommandLine("echo $$@")

	t.CheckOutputLines(
		"WARN: fname:1: The $@ shell variable should only be used in double quotes.")

	checkShellCommandLine("echo \"$$\"") // As seen by make(1); the shell sees: echo "$"

	t.CheckOutputLines(
		"WARN: fname:1: Pkglint parse error in ShTokenizer.ShAtom at \"$$\\\"\" (quoting=d).",
		"WARN: fname:1: Pkglint ShellLine.CheckShellCommand: parse error at [\"]")

	checkShellCommandLine("echo \"\\n\"")

	t.CheckOutputEmpty()

	checkShellCommandLine("${RUN} for f in *.c; do echo $${f%.c}; done")

	t.CheckOutputEmpty()

	checkShellCommandLine("${RUN} set +x; echo $${variable+set}")

	t.CheckOutputEmpty()

	// Based on mail/thunderbird/Makefile, rev. 1.159
	checkShellCommandLine("${RUN} subdir=\"`unzip -c \"$$e\" install.rdf | awk '/re/ { print \"hello\" }'`\"")

	t.CheckOutputLines(
		"WARN: fname:1: The exitcode of \"unzip\" at the left of the | operator is ignored.",
		"WARN: fname:1: Unknown shell command \"unzip\".",
		"WARN: fname:1: Unknown shell command \"awk\".")

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
		"WARN: fname:1: XPI_FILES is used but not defined.",
		"WARN: fname:1: The exitcode of \"${UNZIP_CMD}\" at the left of the | operator is ignored.",
		"WARN: fname:1: UNZIP_CMD is used but not defined.",
		"WARN: fname:1: Unknown shell command \"awk\".",
		"WARN: fname:1: Unknown shell command \"${MKDIR}\".",
		"WARN: fname:1: MKDIR is used but not defined.",
		"WARN: fname:1: UNZIP_CMD is used but not defined.")

	// From x11/wxGTK28/Makefile
	checkShellCommandLine("" +
		"set -e; cd ${WRKSRC}/locale; " +
		"for lang in *.po; do " +
		"  [ \"$${lang}\" = \"wxstd.po\" ] && continue; " +
		"  ${TOOLS_PATH.msgfmt} -c -o \"$${lang%.po}.mo\" \"$${lang}\"; " +
		"done")

	t.CheckOutputLines(
		"WARN: fname:1: WRKSRC may not be used in this file; it would be ok in Makefile, Makefile.*, *.mk.",
		"WARN: fname:1: Unknown shell command \"[\".",
		"WARN: fname:1: Unknown shell command \"${TOOLS_PATH.msgfmt}\".")

	checkShellCommandLine("@cp from to")

	t.CheckOutputLines(
		"WARN: fname:1: The shell command \"cp\" should not be hidden.",
		"WARN: fname:1: Unknown shell command \"cp\".")

	G.Pkg = NewPackage(t.File("category/pkgbase"))
	G.Pkg.PlistDirs["share/pkgbase"] = true

	// A directory that is found in the PLIST.
	checkShellCommandLine("${RUN} ${INSTALL_DATA_DIR} share/pkgbase ${PREFIX}/share/pkgbase")

	t.CheckOutputLines(
		"NOTE: fname:1: You can use AUTO_MKDIRS=yes or \"INSTALLATION_DIRS+= share/pkgbase\" "+
			"instead of \"${INSTALL_DATA_DIR}\".",
		"WARN: fname:1: The INSTALL_*_DIR commands can only handle one directory at a time.")

	// A directory that is not found in the PLIST.
	checkShellCommandLine("${RUN} ${INSTALL_DATA_DIR} ${PREFIX}/share/other")

	t.CheckOutputLines(
		"NOTE: fname:1: You can use \"INSTALLATION_DIRS+= share/other\" instead of \"${INSTALL_DATA_DIR}\".")

	G.Pkg = nil

	// See PR 46570, item "1. It does not"
	checkShellCommandLine("for x in 1 2 3; do echo \"$$x\" || exit 1; done")

	t.CheckOutputEmpty() // No warning about missing error checking.
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine_strip(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")

	checkShellCommandLine := func(shellCommand string) {
		G.Mk = t.NewMkLines("fname",
			"\t"+shellCommand)

		G.Mk.ForEach(
			func(mkline MkLine) bool {
				shline := NewShellLine(mkline)
				shline.CheckShellCommandLine(mkline.ShellCommand())
				return true
			},
			func(mkline MkLine) {})
	}

	checkShellCommandLine("${STRIP} executable")

	t.CheckOutputLines(
		"WARN: fname:1: Unknown shell command \"${STRIP}\".",
		"WARN: fname:1: STRIP is used but not defined.")

	t.SetupVartypes()

	checkShellCommandLine("${STRIP} executable")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__nofix(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	t.SetupTool(&Tool{Name: "echo", Predefined: true})
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
	t.SetupTool(&Tool{Name: "echo", Predefined: true})
	G.Mk = t.NewMkLines("Makefile",
		"\techo ${PKGNAME:Q}")
	shline := NewShellLine(G.Mk.mklines[0])

	shline.CheckShellCommandLine("echo ${PKGNAME:Q}")

	t.CheckOutputLines(
		"NOTE: Makefile:1: The :Q operator isn't necessary for ${PKGNAME} here.",
		"AUTOFIX: Makefile:1: Replacing \"${PKGNAME:Q}\" with \"${PKGNAME}\".")
}

// Simple commands like echo(1) or printf(1) are assumed to never fail.
func (s *Suite) Test_ShellLine_CheckShellCommandLine__exitcode(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	t.SetupTool(&Tool{Name: "cat", Predefined: true})
	t.SetupTool(&Tool{Name: "echo", Predefined: true})
	t.SetupTool(&Tool{Name: "printf", Predefined: true})
	t.SetupTool(&Tool{Name: "sed", Predefined: true})
	t.SetupTool(&Tool{Name: "right-side", Predefined: true})
	G.Mk = t.NewMkLines("Makefile",
		"\t echo | right-side",
		"\t sed s,s,s, | right-side",
		"\t printf | sed s,s,s, | right-side ",
		"\t cat | right-side",
		"\t cat | echo | right-side",
		"\t echo | cat | right-side",
		"\t sed s,s,s, filename | right-side",
		"\t sed s,s,s < input | right-side")

	for _, mkline := range G.Mk.mklines {
		shline := NewShellLine(mkline)
		shline.CheckShellCommandLine(mkline.ShellCommand())
	}

	t.CheckOutputLines(
		"WARN: Makefile:4: The exitcode of \"cat\" at the left of the | operator is ignored.",
		"WARN: Makefile:5: The exitcode of \"cat\" at the left of the | operator is ignored.",
		"WARN: Makefile:6: The exitcode of \"cat\" at the left of the | operator is ignored.",
		"WARN: Makefile:7: The exitcode of \"sed\" at the left of the | operator is ignored.",
		"WARN: Makefile:8: The exitcode of \"sed\" at the left of the | operator is ignored.")
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__autofix(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall", "--autofix")
	t.SetupVartypes()
	t.SetupTool(&Tool{Name: "echo", Predefined: true})
	G.Mk = t.NewMkLines("Makefile",
		"\techo ${PKGNAME:Q}")
	shline := NewShellLine(G.Mk.mklines[0])

	shline.CheckShellCommandLine("echo ${PKGNAME:Q}")

	t.CheckOutputLines(
		"AUTOFIX: Makefile:1: Replacing \"${PKGNAME:Q}\" with \"${PKGNAME}\".")
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__implementation(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	G.Mk = t.NewMkLines("fname",
		"# dummy")
	shline := NewShellLine(G.Mk.mklines[0])

	// foobar="`echo \"foo   bar\"`"
	text := "foobar=\"`echo \\\"foo   bar\\\"`\""

	tokens, rest := splitIntoShellTokens(dummyLine, text)

	c.Check(tokens, deepEquals, []string{text})
	c.Check(rest, equals, "")

	G.Mk.ForEach(
		func(mkline MkLine) bool {
			shline.CheckWord(text, false)
			return true
		},
		func(mkline MkLine) {})

	t.CheckOutputLines(
		"WARN: fname:1: Unknown shell command \"echo\".")

	G.Mk.ForEach(
		func(mkline MkLine) bool {
			shline.CheckShellCommandLine(text)
			return true
		},
		func(mkline MkLine) {})

	// No parse errors
	t.CheckOutputLines(
		"WARN: fname:1: Unknown shell command \"echo\".")
}

func (s *Suite) Test_ShellLine_CheckShelltext__dollar_without_variable(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	G.Mk = t.NewMkLines("fname",
		"# dummy")
	shline := NewShellLine(G.Mk.mklines[0])
	t.SetupTool(&Tool{Name: "pax", Varname: "PAX"})
	G.Mk.tools["pax"] = true

	shline.CheckShellCommandLine("pax -rwpp -s /.*~$$//g . ${DESTDIR}${PREFIX}")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_ShellLine_CheckWord(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()

	checkWord := func(shellWord string, checkQuoting bool) {
		shline := t.NewShellLine("dummy.mk", 1, "\t echo "+shellWord)

		shline.CheckWord(shellWord, checkQuoting)
	}

	checkWord("${${list}}", false)

	checkWord("${${list}}", false)

	t.CheckOutputEmpty() // No warning for variables that are completely indirect.

	checkWord("${SED_FILE.${id}}", false)

	t.CheckOutputEmpty() // No warning for variables that are partly indirect.

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

	shline := t.NewShellLine("fname", 1, "# dummy")

	shline.CheckWord("/.*~$$//g", false) // Typical argument to pax(1).

	t.CheckOutputEmpty()
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__echo(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupTool(&Tool{Name: "echo", Varname: "ECHO", MustUseVarForm: true, Predefined: true})
	G.Mk = t.NewMkLines("fname",
		"# dummy")
	mkline := t.NewMkLine("fname", 3, "# dummy")

	MkLineChecker{mkline}.checkText("echo \"hello, world\"")

	t.CheckOutputEmpty()

	NewShellLine(mkline).CheckShellCommandLine("echo \"hello, world\"")

	t.CheckOutputLines(
		"WARN: fname:3: Please use \"${ECHO}\" instead of \"echo\".")
}

func (s *Suite) Test_ShellLine_CheckShellCommandLine__shell_variables(c *check.C) {
	t := s.Init(c)

	text := "\tfor f in *.pl; do ${SED} s,@PREFIX@,${PREFIX}, < $f > $f.tmp && ${MV} $f.tmp $f; done"

	shline := t.NewShellLine("Makefile", 3, text)
	shline.mkline.Tokenize(shline.mkline.ShellCommand())
	shline.CheckShellCommandLine(text)

	t.CheckOutputLines(
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Makefile variable or $$f if you mean a shell variable.",
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Makefile variable or $$f if you mean a shell variable.",
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Makefile variable or $$f if you mean a shell variable.",
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Makefile variable or $$f if you mean a shell variable.",
		"NOTE: Makefile:3: Please use the SUBST framework instead of ${SED} and ${MV}.")

	shline.CheckShellCommandLine("install -c manpage.1 ${PREFIX}/man/man1/manpage.1")

	t.CheckOutputLines(
		"WARN: Makefile:3: Please use ${PKGMANDIR} instead of \"man\".")

	shline.CheckShellCommandLine("cp init-script ${PREFIX}/etc/rc.d/service")

	t.CheckOutputLines(
		"WARN: Makefile:3: Please use the RCD_SCRIPTS mechanism to install rc.d scripts automatically to ${RCD_SCRIPTS_EXAMPLEDIR}.")
}

func (s *Suite) Test_ShellLine_checkCommandUse(c *check.C) {
	t := s.Init(c)

	G.Mk = t.NewMkLines("fname",
		"# dummy")
	G.Mk.target = "do-install"

	shline := t.NewShellLine("fname", 1, "\tdummy")

	shline.checkCommandUse("sed")

	t.CheckOutputLines(
		"WARN: fname:1: The shell command \"sed\" should not be used in the install phase.")

	shline.checkCommandUse("cp")

	t.CheckOutputLines(
		"WARN: fname:1: ${CP} should not be used to install files.")
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

	shline := t.NewShellLine("Makefile", 85, "\t${RUN} ${SED} 's,#,// comment:,g' fname > fname.tmp; ${MV} fname.tmp fname")

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
	// foobar="`echo \"foo   bar\"`"
	text := "foobar=\"`echo \\\"foo   bar\\\"`\""
	repl := textproc.NewPrefixReplacer(text)
	repl.AdvanceStr("foobar=\"`")

	backtCommand, newQuoting := shline.unescapeBackticks(text, repl, shqDquotBackt)

	c.Check(backtCommand, equals, "echo \"foo   bar\"")
	c.Check(newQuoting, equals, shqDquot)
	c.Check(repl.Rest(), equals, "\"")
}

func (s *Suite) Test_ShellLine__variable_outside_quotes(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
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

	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"\t${RUN} if ! test -f /etc/passwd; then echo \"passwd is missing.\"; fi")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:3: The Solaris /bin/sh does not support negation of shell commands.",
		"WARN: Makefile:3: Found absolute pathname: /etc/passwd")
}
