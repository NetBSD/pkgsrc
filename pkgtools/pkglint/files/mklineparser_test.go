package pkglint

import "gopkg.in/check.v1"

// Exotic code examples from the pkgsrc infrastructure.
// Hopefully, pkgsrc packages don't need such complicated code.
// Still, pkglint needs to parse them correctly, or it would not
// be able to parse and check the infrastructure files as well.
//
// See Pkgsrc.loadUntypedVars.
func (s *Suite) Test_MkLineParser_Parse__infrastructure(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("infra.mk",
		MkCvsID,
		"         USE_BUILTIN.${_pkg_:S/^-//}:=no",
		".error \"Something went wrong\"",
		".export WRKDIR",
		".export",
		".unexport-env WRKDIR",
		"",
		".ifmake target1",    // Luckily, this is not used in the wild.
		".elifnmake target2", // Neither is this.
		".endif")

	t.CheckEquals(mklines.mklines[1].Varcanon(), "USE_BUILTIN.*")
	t.CheckEquals(mklines.mklines[2].Directive(), "error")
	t.CheckEquals(mklines.mklines[3].Directive(), "export")

	t.CheckOutputLines(
		"WARN: infra.mk:2: Makefile lines should not start with space characters.",
		"ERROR: infra.mk:8: Unknown Makefile line format: \".ifmake target1\".",
		"ERROR: infra.mk:9: Unknown Makefile line format: \".elifnmake target2\".")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: infra.mk:2: USE_BUILTIN.${_pkg_:S/^-//} is defined but not used.",
		"WARN: infra.mk:2: _pkg_ is used but not defined.",
		"ERROR: infra.mk:5: \".export\" requires arguments.",
		"NOTE: infra.mk:2: This variable value should be aligned to column 41 instead of 39.",
		"ERROR: infra.mk:10: Unmatched .endif.")
}

// In variable assignments, a plain '#' introduces a line comment, unless
// it is escaped by a backslash. In shell commands, on the other hand, it
// is interpreted literally.
func (s *Suite) Test_MkLineParser_Parse__comment_or_not(c *check.C) {
	t := s.Init(c)

	mklineVarassignEscaped := t.NewMkLine("filename.mk", 1, "SED_CMD=\t's,\\#,hash,g'")

	t.CheckEquals(mklineVarassignEscaped.Varname(), "SED_CMD")
	t.CheckEquals(mklineVarassignEscaped.Value(), "'s,#,hash,g'")

	mklineCommandEscaped := t.NewMkLine("filename.mk", 1, "\tsed -e 's,\\#,hash,g'")

	t.CheckEquals(mklineCommandEscaped.ShellCommand(), "sed -e 's,\\#,hash,g'")

	// From shells/zsh/Makefile.common, rev. 1.78
	mklineCommandUnescaped := t.NewMkLine("filename.mk", 1, "\t# $ sha1 patches/patch-ac")

	t.CheckEquals(mklineCommandUnescaped.IsComment(), true)
	t.CheckEquals(mklineCommandUnescaped.Comment(), " $ sha1 patches/patch-ac")
	t.CheckOutputEmpty() // No warning about parsing the lonely dollar sign.

	mklineVarassignUnescaped := t.NewMkLine("filename.mk", 1, "SED_CMD=\t's,#,hash,'")

	t.CheckEquals(mklineVarassignUnescaped.Value(), "'s,")
	t.CheckOutputLines(
		"WARN: filename.mk:1: The # character starts a Makefile comment.")
}

func (s *Suite) Test_MkLineParser_Parse__commented_lines(c *check.C) {
	t := s.Init(c)

	test := func(text string) {
		mkline := t.NewMkLines("filename.mk", text).mklines[0]
		t.CheckEquals(mkline.HasComment(), true)
		t.CheckEquals(mkline.Comment(), " the comment")
	}

	test("VAR=value # the comment")
	test("# the comment")
	test(".if 0 # the comment")
	test(".include \"other.mk\" # the comment")
	test(".include <other.mk> # the comment")
	test("target: source # the comment")
	test("\t\t# the comment")
}

func (s *Suite) Test_MkLineParser_parseVarassign(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("test.mk", 101,
		"VARNAME.param?=value # varassign comment")

	t.CheckEquals(mkline.IsVarassign(), true)
	t.CheckEquals(mkline.Varname(), "VARNAME.param")
	t.CheckEquals(mkline.Varcanon(), "VARNAME.*")
	t.CheckEquals(mkline.Varparam(), "param")
	t.CheckEquals(mkline.Op(), opAssignDefault)
	t.CheckEquals(mkline.Value(), "value")
	t.CheckEquals(mkline.Comment(), " varassign comment")
}

func (s *Suite) Test_MkLineParser_parseVarassign__empty_multiline(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("test.mk",
		"VAR=\t\\",
		"\t\\",
		"\t\\",
		"\t# nothing",
		"",
		"VAR=\t1\\",
		"\t\\",
		"\t\\",
		"\t# a single letter")

	// Bmake and pkglint agree that the variable value is an empty string.
	// They don't agree on the exact whitespace in the line, though,
	// but this doesn't matter in practice. To see the difference, run:
	//  bmake -dA 2>&1 | grep 'ParseReadLine.*VAR'
	// See devel/bmake/files/parse.c:/non-comment, non-blank line/
	t.CheckEquals(mklines.mklines[0].Text, "VAR=   # nothing")
	t.CheckEquals(mklines.mklines[2].Text, "VAR=\t1   # a single letter")

	mkline := mklines.mklines[0]
	t.CheckEquals(mkline.IsVarassign(), true)
	t.CheckEquals(mkline.Varname(), "VAR")
	t.CheckEquals(mkline.Op(), opAssign)
	t.CheckEquals(mkline.Value(), "")
	t.CheckEquals(mkline.Comment(), " nothing")
}

func (s *Suite) Test_MkLineParser_parseVarassign__leading_space(c *check.C) {
	t := s.Init(c)

	_ = t.NewMkLine("rubyversion.mk", 427, " _RUBYVER=\t2.15")
	_ = t.NewMkLine("bsd.buildlink3.mk", 132, "   ok:=yes")

	// In mk/buildlink3/bsd.buildlink3.mk, the leading space is really helpful,
	// therefore no warnings for that file.
	t.CheckOutputLines(
		"WARN: rubyversion.mk:427: Makefile lines should not start with space characters.")
}

func (s *Suite) Test_MkLineParser_parseVarassign__append(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("test.mk", 101,
		"VARNAME+=value")

	t.CheckEquals(mkline.IsVarassign(), true)
	t.CheckEquals(mkline.Varname(), "VARNAME")
	t.CheckEquals(mkline.Varcanon(), "VARNAME")
	t.CheckEquals(mkline.Varparam(), "")
}

func (s *Suite) Test_MkLineParser_parseVarassign__varname_with_hash(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("Makefile", 123, "VARNAME.#=\tvalue")

	// Parse error because the # starts a comment.
	t.CheckEquals(mkline.IsVarassign(), false)

	mkline2 := t.NewMkLine("Makefile", 124, "VARNAME.\\#=\tvalue")

	t.CheckEquals(mkline2.IsVarassign(), true)
	t.CheckEquals(mkline2.Varname(), "VARNAME.#")

	t.CheckOutputLines(
		"ERROR: Makefile:123: Unknown Makefile line format: \"VARNAME.#=\\tvalue\".")
}

// Ensures that pkglint parses escaped # characters in the same way as bmake.
//
// To check that bmake parses them the same, set a breakpoint after the t.NewMkLines
// and look in t.tmpdir for the location of the file. Then run bmake with that file.
func (s *Suite) Test_MkLineParser_parseVarassign__escaped_hash_in_value(c *check.C) {
	t := s.Init(c)

	mklines := t.SetUpFileMkLines("Makefile",
		"VAR0=\tvalue#",
		"VAR1=\tvalue\\#",
		"VAR2=\tvalue\\\\#",
		"VAR3=\tvalue\\\\\\#",
		"VAR4=\tvalue\\\\\\\\#",
		"",
		"all:",
		".for var in VAR0 VAR1 VAR2 VAR3 VAR4",
		"\t@printf '%s\\n' ${${var}}''",
		".endfor")
	parsed := mklines.mklines

	t.CheckEquals(parsed[0].Value(), "value")
	t.CheckEquals(parsed[1].Value(), "value#")
	t.CheckEquals(parsed[2].Value(), "value\\\\")
	t.CheckEquals(parsed[3].Value(), "value\\\\#")
	t.CheckEquals(parsed[4].Value(), "value\\\\\\\\")

	t.CheckOutputLines(
		"WARN: ~/Makefile:1: The # character starts a Makefile comment.",
		"WARN: ~/Makefile:3: The # character starts a Makefile comment.",
		"WARN: ~/Makefile:5: The # character starts a Makefile comment.")
}

func (s *Suite) Test_MkLineParser_MatchVarassign(c *check.C) {
	t := s.Init(c)

	testLine := func(line *Line, commented bool, varname, spaceAfterVarname, op, align, value, spaceAfterValue, comment string, diagnostics ...string) {
		text := line.Text

		t.CheckOutputEmpty()
		mkline := NewMkLineParser().Parse(line)
		assert(mkline.IsVarassignMaybeCommented())
		valueAlign := mkline.ValueAlign()
		_ = t.Output()

		parser := NewMkLineParser()
		splitResult := parser.split(nil, text, true)
		m, actual := parser.MatchVarassign(line, text, &splitResult)

		assert(m)
		expected := mkLineAssign{
			commented:         commented,
			varname:           varname,
			varcanon:          varnameCanon(varname),
			varparam:          varnameParam(varname),
			spaceAfterVarname: spaceAfterVarname,
			op:                NewMkOperator(op),
			value:             value,
			valueMk:           nil,
			valueMkRest:       "",
			fields:            nil,
		}
		t.CheckDeepEquals(*actual, expected)
		t.CheckEquals(valueAlign, align)
		t.CheckEquals(splitResult.spaceBeforeComment, spaceAfterValue)
		t.CheckEquals(splitResult.hasComment, comment != "")
		t.CheckEquals(condStr(splitResult.hasComment, "#", "")+splitResult.comment, comment)
		t.CheckOutput(diagnostics)
	}

	test := func(text string, commented bool, varname, spaceAfterVarname, op, align, value, spaceAfterValue, comment string, diagnostics ...string) {
		line := t.NewLine("filename.mk", 123, text)
		testLine(line, commented, varname, spaceAfterVarname, op, align, value, spaceAfterValue, comment, diagnostics...)
	}

	testInvalid := func(text string, diagnostics ...string) {
		line := t.NewLine("filename.mk", 123, text)
		parser := NewMkLineParser()
		splitResult := parser.split(nil, text, true)
		m, _ := parser.MatchVarassign(line, text, &splitResult)
		if m {
			c.Errorf("Text %q matches variable assignment but shouldn't.", text)
		}
		t.CheckOutput(diagnostics)
	}

	lines := func(text ...string) *Line {
		mklines := t.NewMkLines("filename.mk",
			text...)
		return mklines.mklines[0].Line
	}

	test("C++=c11", false, "C+", "", "+=", "C++=", "c11", "", "")
	test("V=v", false, "V", "", "=", "V=", "v", "", "")
	test("VAR=#comment", false, "VAR", "", "=", "VAR=", "", "", "#comment")
	test("VAR=\\#comment", false, "VAR", "", "=", "VAR=", "#comment", "", "")
	test("VAR=\\\\\\##comment", false, "VAR", "", "=", "VAR=", "\\\\#", "", "#comment")
	test("VAR=\\", false, "VAR", "", "=", "VAR=", "\\", "", "")
	test("VAR += value", false, "VAR", " ", "+=", "VAR += ", "value", "", "")
	test(" VAR=value", false, "VAR", "", "=", " VAR=", "value", "", "")
	test("VAR=value #comment", false, "VAR", "", "=", "VAR=", "value", " ", "#comment")
	test("NFILES=${FILES:[#]}", false, "NFILES", "", "=", "NFILES=", "${FILES:[#]}", "", "")
	test(".VARNAME=value", false, ".VARNAME", "", "=", ".VARNAME=", "value", "", "")
	test(".VAR.param=value", false, ".VAR.param", "", "=", ".VAR.param=", "value", "", "")
	testInvalid("./=value", nil...)
	testInvalid("#./=value", nil...)

	// To humans, the base variable name seems to be SITES_, being parameterized
	// with distfile-1.0.tar.gz. For pkglint though, the base variable name is
	// SITES_distfile-1.
	test("SITES_distfile-1.0.tar.gz=https://example.org/",
		false,
		"SITES_distfile-1.0.tar.gz",
		"",
		"=",
		"SITES_distfile-1.0.tar.gz=",
		"https://example.org/",
		"",
		"")

	test("SITES_${distfile}=https://example.org/",
		false,
		"SITES_${distfile}",
		"",
		"=",
		"SITES_${distfile}=",
		"https://example.org/",
		"",
		"")

	t.ExpectAssert(func() { testInvalid("\tVAR=value") })
	testInvalid("?=value")
	testInvalid("<=value")
	testInvalid("#")
	testInvalid("VAR.$$=value")

	// A commented variable assignment must start immediately after the comment character.
	// There must be no additional whitespace before the variable name.
	test("#VAR=value", true, "VAR", "", "=", "#VAR=", "value", "", "")

	// A single space is typically used for writing documentation, not for commenting out code.
	// Therefore this line doesn't count as commented variable assignment.
	testInvalid("# VAR=value")

	// Ensure that the alignment for the variable value is correct.
	test("BUILD_DIRS=\tdir1 dir2",
		false,
		"BUILD_DIRS",
		"",
		"=",
		"BUILD_DIRS=\t",
		"dir1 dir2",
		"",
		"")

	// Ensure that the alignment for the variable value is correct,
	// even if the whole line is commented.
	test("#BUILD_DIRS=\tdir1 dir2",
		true,
		"BUILD_DIRS",
		"",
		"=",
		"#BUILD_DIRS=\t",
		"dir1 dir2",
		"",
		"")

	test("MASTER_SITES=\t#none",
		false,
		"MASTER_SITES",
		"",
		"=",
		"MASTER_SITES=\t",
		"",
		"",
		"#none")

	test("MASTER_SITES=\t# none",
		false,
		"MASTER_SITES",
		"",
		"=",
		"MASTER_SITES=\t",
		"",
		"",
		"# none")

	test("EGDIRS=\t${EGDIR/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d",

		false,
		"EGDIRS",
		"",
		"=",
		"EGDIRS=\t",
		"${EGDIR/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d",
		"",
		"")

	test("VAR:=\t${VAR:M-*:[\\#]}",
		false,
		"VAR",
		"",
		":=",
		"VAR:=\t",
		"${VAR:M-*:[#]}",
		"",
		"")

	test("#VAR=value",
		true, "VAR", "", "=", "#VAR=", "value", "", "")

	testInvalid("# VAR=value")
	testInvalid("#\tVAR=value")
	testInvalid(MkCvsID)

	testLine(
		lines(
			"VAR=\t\t\t\\",
			"\tvalue"),
		false,
		"VAR",
		"",
		"=",
		"VAR=\t\t\t",
		"value",
		"",
		"")

	testLine(
		lines(
			"#VAR=\t\t\t\\",
			"#\tvalue"),
		true,
		"VAR",
		"",
		"=",
		"#VAR=\t\t\t",
		"value",
		"",
		"")
}

func (s *Suite) Test_MkLineParser_fixSpaceAfterVarname__show_autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--show-autofix", "--source")
	t.NewMkLine("test.mk", 101,
		"pkgbase = package")

	t.CheckOutputLines(
		"NOTE: test.mk:101: Unnecessary space after variable name \"pkgbase\".",
		"AUTOFIX: test.mk:101: Replacing \"pkgbase = \" with \"pkgbase=  \".",
		"-\tpkgbase = package",
		"+\tpkgbase=  package")
}

func (s *Suite) Test_MkLineParser_fixSpaceAfterVarname__autofix(c *check.C) {
	t := s.Init(c)

	filename := t.CreateFileLines("Makefile",
		MkCvsID,
		"VARNAME +=\t${VARNAME}",
		"VARNAME+ =\t${VARNAME+}",
		"VARNAME+ +=\t${VARNAME+}",
		"VARNAME+ ?=\t${VARNAME}",
		"pkgbase := pkglint")

	CheckFileMk(filename, nil)

	t.CheckOutputLines(
		"NOTE: ~/Makefile:2: Unnecessary space after variable name \"VARNAME\".",

		// The assignment operators other than = and += cannot lead to ambiguities.
		"NOTE: ~/Makefile:5: Unnecessary space after variable name \"VARNAME+\".",

		"WARN: ~/Makefile:5: "+
			"Please include \"../../mk/bsd.prefs.mk\" before using \"?=\".")

	t.SetUpCommandLine("-Wall", "--autofix")

	CheckFileMk(filename, nil)

	t.CheckOutputLines(
		"AUTOFIX: ~/Makefile:2: Replacing \"VARNAME +=\\t\" with \"VARNAME+=\\t\".",
		"AUTOFIX: ~/Makefile:5: Replacing \"VARNAME+ ?=\\t\" with \"VARNAME+?=\\t\".")
	t.CheckFileLines("Makefile",
		MkCvsID+"",
		"VARNAME+=\t${VARNAME}",
		"VARNAME+ =\t${VARNAME+}",
		"VARNAME+ +=\t${VARNAME+}",
		"VARNAME+?=\t${VARNAME}",
		"pkgbase := pkglint")
}

func (s *Suite) Test_MkLineParser_fixSpaceAfterVarname__preserve_alignment(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--show-autofix")

	test := func(before, after string, diagnostics ...string) {

		doTest := func(autofix bool) {
			mkline := t.NewMkLine("filename.mk", 123, before)
			t.CheckEquals(mkline.Text, condStr(autofix, after, before))
		}

		t.ExpectDiagnosticsAutofix(doTest, diagnostics...)
	}

	test(
		"V    +=         ${VARNAME}",
		"V+=\t\t${VARNAME}",

		"NOTE: filename.mk:123: Unnecessary space after variable name \"V\".",
		"AUTOFIX: filename.mk:123: Replacing \"V    +=         \" with \"V+=\\t\\t\".")

	test(
		"V    +=     ${VARNAME}",
		"V+=\t    ${VARNAME}",

		"NOTE: filename.mk:123: Unnecessary space after variable name \"V\".",
		"AUTOFIX: filename.mk:123: Replacing \"V    +=     \" with \"V+=\\t    \".")
}

func (s *Suite) Test_MkLineParser_parseShellcmd(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("test.mk", 101,
		"\tshell command # shell comment")

	t.CheckEquals(mkline.IsShellCommand(), true)
	t.CheckEquals(mkline.ShellCommand(), "shell command # shell comment")
}

func (s *Suite) Test_MkLineParser_parseCommentOrEmpty__comment(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("test.mk", 101,
		"# whole line comment")

	t.CheckEquals(mkline.IsComment(), true)
}

func (s *Suite) Test_MkLineParser_parseCommentOrEmpty__empty(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("test.mk", 101, "")

	t.CheckEquals(mkline.IsEmpty(), true)
}

func (s *Suite) Test_MkLineParser_parseDirective(c *check.C) {
	t := s.Init(c)

	test := func(input, expectedIndent, expectedDirective, expectedArgs, expectedComment string, diagnostics ...string) {
		line := t.NewLine("filename.mk", 123, input)
		parser := NewMkLineParser()
		splitResult := parser.split(line, input, true)
		mkline := parser.parseDirective(line, splitResult)
		if !c.Check(mkline, check.NotNil) {
			return
		}

		t.CheckDeepEquals(
			[]interface{}{mkline.Indent(), mkline.Directive(), mkline.Args(), mkline.DirectiveComment()},
			[]interface{}{expectedIndent, expectedDirective, expectedArgs, expectedComment})
		t.CheckOutput(diagnostics)
	}

	test(".if ${VAR} == value",
		"", "if", "${VAR} == value", "")

	test(".\tendif # comment",
		"\t", "endif", "", "comment")

	test(".if ${VAR} == \"#\"",
		"", "if", "${VAR} == \"", "\"")

	test(".if ${VAR:[#]}",
		"", "if", "${VAR:[#]}", "")

	test(".if ${VAR} == \\",
		"", "if", "${VAR} == \\", "")

	test(".if ${VAR",
		"", "if", "${VAR", "",
		"WARN: filename.mk:123: Missing closing \"}\" for \"VAR\".")
}

func (s *Suite) Test_MkLineParser_parseDirective__escaped_hash(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("test.mk", 101,
		".  if !empty(PKGNAME:M*-*) && ${RUBY_RAILS_SUPPORTED:[\\#]} == 1 # directive comment")

	t.CheckEquals(mkline.IsDirective(), true)
	t.CheckEquals(mkline.Indent(), "  ")
	t.CheckEquals(mkline.Directive(), "if")
	t.CheckEquals(mkline.Args(), "!empty(PKGNAME:M*-*) && ${RUBY_RAILS_SUPPORTED:[#]} == 1")
	t.CheckEquals(mkline.DirectiveComment(), "directive comment")
}

func (s *Suite) Test_MkLineParser_parseInclude(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("test.mk", 101,
		".    include \"../../mk/bsd.prefs.mk\" # include comment")

	t.CheckEquals(mkline.IsInclude(), true)
	t.CheckEquals(mkline.Indent(), "    ")
	t.CheckEquals(mkline.MustExist(), true)
	t.CheckEquals(mkline.IncludedFile(), NewRelPathString("../../mk/bsd.prefs.mk"))

	t.CheckEquals(mkline.IsSysinclude(), false)
}

func (s *Suite) Test_MkLineParser_parseSysinclude(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("test.mk", 101,
		".    include <subdir.mk> # sysinclude comment")

	t.CheckEquals(mkline.IsSysinclude(), true)
	t.CheckEquals(mkline.Indent(), "    ")
	t.CheckEquals(mkline.MustExist(), true)
	t.CheckEquals(mkline.IncludedFile(), NewRelPathString("subdir.mk"))

	t.CheckEquals(mkline.IsInclude(), false)
}

func (s *Suite) Test_MkLineParser_parseDependency(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("test.mk", 101,
		"target1 target2: source1 source2")

	t.CheckEquals(mkline.IsDependency(), true)
	t.CheckEquals(mkline.Targets(), "target1 target2")
	t.CheckEquals(mkline.Sources(), "source1 source2")
}

func (s *Suite) Test_MkLineParser_parseDependency__space(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("test.mk", 101,
		"target : source")

	t.CheckEquals(mkline.Targets(), "target")
	t.CheckEquals(mkline.Sources(), "source")
	t.CheckOutputLines(
		"NOTE: test.mk:101: Space before colon in dependency line.")
}

func (s *Suite) Test_MkLineParser_parseMergeConflict(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("test.mk", 101,
		"<<<<<<<<<<<<<<<<<")

	// Merge conflicts are of neither type.
	t.CheckEquals(mkline.IsVarassign(), false)
	t.CheckEquals(mkline.IsDirective(), false)
	t.CheckEquals(mkline.IsInclude(), false)
	t.CheckEquals(mkline.IsEmpty(), false)
	t.CheckEquals(mkline.IsComment(), false)
	t.CheckEquals(mkline.IsDependency(), false)
	t.CheckEquals(mkline.IsShellCommand(), false)
	t.CheckEquals(mkline.IsSysinclude(), false)
}

func (s *Suite) Test_MkLineParser_split(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	varuse := b.VaruseToken
	varuseText := b.VaruseTextToken
	text := b.TextToken
	tokens := b.Tokens

	test := func(text string, expected mkLineSplitResult, diagnostics ...string) {
		line := t.NewLine("filename.mk", 123, text)
		actual := NewMkLineParser().split(line, text, true)

		t.CheckOutput(diagnostics)
		t.CheckDeepEquals([]interface{}{text, actual}, []interface{}{text, expected})
	}

	t.Use(text, varuse, varuseText, tokens)

	test(
		"",
		mkLineSplitResult{})

	test(
		"text",
		mkLineSplitResult{
			main:   "text",
			tokens: tokens(text("text")),
		})

	// Leading space is always kept.
	test(
		" text",
		mkLineSplitResult{
			main:   " text",
			tokens: tokens(text(" text")),
		})

	// Trailing space does not end up in the tokens since it is usually
	// ignored.
	test(
		"text\t",
		mkLineSplitResult{
			main:               "text",
			tokens:             tokens(text("text")),
			spaceBeforeComment: "\t",
		})

	test(
		"text\t# intended comment",
		mkLineSplitResult{
			main:               "text",
			tokens:             tokens(text("text")),
			spaceBeforeComment: "\t",
			hasComment:         true,
			comment:            " intended comment",
		})

	// Trailing space is saved in a separate field to detect accidental
	// unescaped # in the middle of a word, like the URL fragment in this
	// example.
	test(
		"url#fragment",
		mkLineSplitResult{
			main:       "url",
			tokens:     tokens(text("url")),
			hasComment: true,
			comment:    "fragment",
		})

	// The leading space from the comment is preserved to make parsing as exact
	// as possible.
	//
	// The difference between "#defined" and "# defined" is relevant in a few
	// cases, such as the API documentation of the infrastructure files.
	test("# comment",
		mkLineSplitResult{
			hasComment: true,
			comment:    " comment",
		})

	test("#\tcomment",
		mkLineSplitResult{
			hasComment: true,
			comment:    "\tcomment",
		})

	test("#   comment",
		mkLineSplitResult{
			hasComment: true,
			comment:    "   comment",
		})

	test(
		"#VAR=#value",
		mkLineSplitResult{
			hasComment: true,
			comment:    "VAR=#value"})

	// When parsing a commented variable assignment, the code assumes that
	// the whole comment is left uninterpreted.
	test(
		"#VAR=\\#value",
		mkLineSplitResult{
			hasComment: true,
			comment:    "VAR=\\#value"})

	// Other than in the shell, # also starts a comment in the middle of a word.
	test("COMMENT=\tThe C# compiler",
		mkLineSplitResult{
			main:       "COMMENT=\tThe C",
			tokens:     tokens(text("COMMENT=\tThe C")),
			hasComment: true,
			comment:    " compiler",
		})

	test("COMMENT=\tThe C\\# compiler",
		mkLineSplitResult{
			main:       "COMMENT=\tThe C# compiler",
			tokens:     tokens(text("COMMENT=\tThe C# compiler")),
			hasComment: false,
			comment:    "",
		})

	test("${TARGET}: ${SOURCES} # comment",
		mkLineSplitResult{
			main:               "${TARGET}: ${SOURCES}",
			tokens:             tokens(varuse("TARGET"), text(": "), varuse("SOURCES")),
			spaceBeforeComment: " ",
			hasComment:         true,
			comment:            " comment",
		})

	// A # starts a comment, except if it immediately follows a [.
	// This is done so that the length modifier :[#] can be written without
	// escaping the #.
	test("VAR=\t${OTHER:[#]} # comment",
		mkLineSplitResult{
			main:               "VAR=\t${OTHER:[#]}",
			tokens:             tokens(text("VAR=\t"), varuse("OTHER", "[#]")),
			spaceBeforeComment: " ",
			hasComment:         true,
			comment:            " comment",
		})

	// The # in the :[#] modifier may be escaped or not. Both forms are equivalent.
	test("VAR:=\t${VAR:M-*:[\\#]}",
		mkLineSplitResult{
			main:   "VAR:=\t${VAR:M-*:[#]}",
			tokens: tokens(text("VAR:=\t"), varuse("VAR", "M-*", "[#]")),
		})

	// A backslash always escapes the next character, be it a # for a comment
	// or something else. This makes it difficult to write a literal \# in a
	// Makefile, but that's an edge case anyway.
	test("VAR0=\t#comment",
		mkLineSplitResult{
			main:   "VAR0=",
			tokens: tokens(text("VAR0=")),
			// Later, when converting this result into a proper variable assignment,
			// this "space before comment" is reclassified as "space before the value",
			// in order to align the "#comment" with the other variable values.
			spaceBeforeComment: "\t",
			hasComment:         true,
			comment:            "comment",
		})

	test("VAR1=\t\\#no-comment",
		mkLineSplitResult{
			main:   "VAR1=\t#no-comment",
			tokens: tokens(text("VAR1=\t#no-comment")),
		})

	test("VAR2=\t\\\\#comment",
		mkLineSplitResult{
			main:       "VAR2=\t\\\\",
			tokens:     tokens(text("VAR2=\t\\\\")),
			hasComment: true,
			comment:    "comment",
		})

	// The backslash is only removed when it escapes a comment.
	// In particular, it cannot be used to escape a dollar that starts a
	// variable use.
	test("VAR0=\t$T",
		mkLineSplitResult{
			main:   "VAR0=\t$T",
			tokens: tokens(text("VAR0=\t"), varuseText("$T", "T")),
		},
		"WARN: filename.mk:123: $T is ambiguous. Use ${T} if you mean a Make variable or $$T if you mean a shell variable.")

	test("VAR1=\t\\$T",
		mkLineSplitResult{
			main:   "VAR1=\t\\$T",
			tokens: tokens(text("VAR1=\t\\"), varuseText("$T", "T")),
		},
		"WARN: filename.mk:123: $T is ambiguous. Use ${T} if you mean a Make variable or $$T if you mean a shell variable.")

	test("VAR2=\t\\\\$T",
		mkLineSplitResult{
			main:   "VAR2=\t\\\\$T",
			tokens: tokens(text("VAR2=\t\\\\"), varuseText("$T", "T")),
		},
		"WARN: filename.mk:123: $T is ambiguous. Use ${T} if you mean a Make variable or $$T if you mean a shell variable.")

	// To escape a dollar, write it twice.
	test("$$shellvar $${shellvar} \\${MKVAR} [] \\x",
		mkLineSplitResult{
			main:   "$$shellvar $${shellvar} \\${MKVAR} [] \\x",
			tokens: tokens(text("$$shellvar $${shellvar} \\"), varuse("MKVAR"), text(" [] \\x")),
		})

	// Parse errors are recorded in the rest return value.
	test("${UNCLOSED",
		mkLineSplitResult{
			main:   "${UNCLOSED",
			tokens: tokens(varuseText("${UNCLOSED", "UNCLOSED")),
		},
		"WARN: filename.mk:123: Missing closing \"}\" for \"UNCLOSED\".")

	// Even if there is a parse error in the main part,
	// the comment is extracted.
	test("text before ${UNCLOSED# comment",
		mkLineSplitResult{
			main: "text before ${UNCLOSED",
			tokens: tokens(
				text("text before "),
				varuseText("${UNCLOSED", "UNCLOSED")),
			hasComment: true,
			comment:    " comment",
		},
		"WARN: filename.mk:123: Missing closing \"}\" for \"UNCLOSED\".")

	// Even in case of parse errors, the space before the comment is parsed
	// correctly.
	test("text before ${UNCLOSED # comment",
		mkLineSplitResult{
			main: "text before ${UNCLOSED",
			tokens: tokens(
				text("text before "),
				// It's a bit inconsistent that the varname includes the space
				// but the text doesn't; anyway, it's an edge case.
				varuseText("${UNCLOSED", "UNCLOSED ")),
			spaceBeforeComment: " ",
			hasComment:         true,
			comment:            " comment",
		},
		"WARN: filename.mk:123: Missing closing \"}\" for \"UNCLOSED \".",
		"WARN: filename.mk:123: Invalid part \" \" after variable name \"UNCLOSED\".")

	// The dollar-space refers to a normal Make variable named " ".
	// The lonely dollar at the very end refers to the variable named "",
	// which is specially protected in bmake to always contain the empty string.
	// It is heavily used in .for loops in the form ${:Uvalue}.
	//
	// TODO: The rest of pkglint assumes that the empty string is not a valid
	//  variable name, mainly because the empty variable name is not visible
	//  outside of the bmake debugging mode.
	test("Lonely $ character $",
		mkLineSplitResult{
			main: "Lonely $ character $",
			tokens: tokens(
				text("Lonely "),
				varuseText("$ " /* instead of "${ }" */, " "),
				text("character "),
				text("$")),
		})

	// The character [ prevents the following # from starting a comment, even
	// outside of variable modifiers.
	test("COMMENT=\t[#] $$\\# $$# comment",
		mkLineSplitResult{
			main:       "COMMENT=\t[#] $$# $$",
			tokens:     tokens(text("COMMENT=\t[#] $$# $$")),
			hasComment: true,
			comment:    " comment",
		})

	test("VAR2=\t\\\\#comment",
		mkLineSplitResult{
			main:       "VAR2=\t\\\\",
			tokens:     tokens(text("VAR2=\t\\\\")),
			hasComment: true,
			comment:    "comment",
		})

	// At this stage, MkLine.split doesn't know that empty(...) takes
	// a variable use. Instead it just sees ordinary characters and
	// other uses of variables.
	test(".if empty(${VAR.${tool}}:C/\\:.*$//:M${pattern})",
		mkLineSplitResult{
			main: ".if empty(${VAR.${tool}}:C/\\:.*$//:M${pattern})",
			tokens: tokens(
				text(".if empty("),
				varuse("VAR.${tool}"),
				text(":C/\\:.*"),
				text("$"),
				text("//:M"),
				varuse("pattern"),
				text(")")),
		})

	test("   # comment after spaces",
		mkLineSplitResult{
			spaceBeforeComment: "   ",
			hasComment:         true,
			comment:            " comment after spaces",
		})

	// XXX: This theoretical edge case is interpreted differently
	//  between bmake and pkglint. Pkglint treats the # as a comment,
	//  while bmake interprets it as a regular character.
	test("\\[#",
		mkLineSplitResult{
			main:       "\\[",
			tokens:     tokens(text("\\[")),
			hasComment: true,
		})

	test("\\\\[#",
		mkLineSplitResult{
			main:   "\\\\[#",
			tokens: tokens(text("\\\\[#")),
		})
}

func (s *Suite) Test_MkLineParser_split__preserve_comment(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	tokens := b.Tokens
	text := b.TextToken
	varUse := b.VaruseToken

	test := func(text string, expected mkLineSplitResult, diagnostics ...string) {
		line := t.NewLine("filename.mk", 123, text)
		actual := NewMkLineParser().split(line, text, false)

		t.CheckDeepEquals(actual, expected)
		t.CheckOutput(diagnostics)
	}

	test(
		"text\t# no comment",
		mkLineSplitResult{
			main:   "text\t# no comment",
			tokens: tokens(text("text\t# no comment"))})

	test(
		"url#fragment",
		mkLineSplitResult{
			main:   "url#fragment",
			tokens: tokens(text("url#fragment"))})

	test("# no comment",
		mkLineSplitResult{
			main:   "# no comment",
			tokens: tokens(text("# no comment"))})

	// Other than in the shell, # also starts a comment in the middle of a word.
	test("The C# compiler",
		mkLineSplitResult{
			main:   "The C# compiler",
			tokens: tokens(text("The C# compiler"))})

	test("The C\\# compiler",
		mkLineSplitResult{
			main:   "The C\\# compiler",
			tokens: tokens(text("The C\\# compiler"))})

	test("# ${VAR}",
		mkLineSplitResult{
			main:   "# ${VAR}",
			tokens: tokens(text("# "), varUse("VAR"))})

	test("# ",
		mkLineSplitResult{
			main:               "#",
			tokens:             tokens(text("#")),
			spaceBeforeComment: " "})
}

func (s *Suite) Test_MkLineParser_split__unclosed_varuse(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	test := func(text string, expected mkLineSplitResult, diagnostics ...string) {
		line := t.NewLine("filename.mk", 123, text)

		splitResult := NewMkLineParser().split(line, text, true)

		t.CheckDeepEquals(splitResult, expected)
		t.CheckOutput(diagnostics)
	}

	test(
		"EGDIRS=\t${EGDIR/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d",

		mkLineSplitResult{
			"EGDIRS=\t${EGDIR/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d",
			b.Tokens(
				b.TextToken("EGDIRS=\t"),
				b.VaruseTextToken(
					"${EGDIR/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d",
					"EGDIR/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d")),
			"",
			false,
			"",
			"",
		},

		"WARN: filename.mk:123: Missing closing \"}\" for \"EGDIR/pam.d\".",
		"WARN: filename.mk:123: Invalid part \"/pam.d\" after variable name \"EGDIR\".",
		"WARN: filename.mk:123: Missing closing \"}\" for \"EGDIR/dbus-1/system.d ${EGDIR/pam.d\".",
		"WARN: filename.mk:123: Invalid part \"/dbus-1/system.d ${EGDIR/pam.d\" after variable name \"EGDIR\".",
		"WARN: filename.mk:123: Missing closing \"}\" for \"EGDIR/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d\".",
		"WARN: filename.mk:123: Invalid part \"/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d\" after variable name \"EGDIR\".")
}

func (s *Suite) Test_MkLineParser_unescapeComment(c *check.C) {
	t := s.Init(c)

	test := func(text string, main, comment string) {
		aMain, aComment := NewMkLineParser().unescapeComment(text)
		t.CheckDeepEquals(
			[]interface{}{text, aMain, aComment},
			[]interface{}{text, main, comment})
	}

	test("",
		"",
		"")
	test("text",
		"text",
		"")

	// The leading space from the comment is preserved to make parsing as exact
	// as possible.
	//
	// The difference between "#defined" and "# defined" is relevant in a few
	// cases, such as the API documentation of the infrastructure files.
	test("# comment",
		"",
		"# comment")
	test("#\tcomment",
		"",
		"#\tcomment")
	test("#   comment",
		"",
		"#   comment")

	// Other than in the shell, # also starts a comment in the middle of a word.
	test("COMMENT=\tThe C# compiler",
		"COMMENT=\tThe C",
		"# compiler")
	test("COMMENT=\tThe C\\# compiler",
		"COMMENT=\tThe C# compiler",
		"")

	test("${TARGET}: ${SOURCES} # comment",
		"${TARGET}: ${SOURCES} ",
		"# comment")

	// A # starts a comment, except if it immediately follows a [.
	// This is done so that the length modifier :[#] can be written without
	// escaping the #.
	test("VAR=\t${OTHER:[#]} # comment",
		"VAR=\t${OTHER:[#]} ",
		"# comment")

	// The # in the :[#] modifier may be escaped or not. Both forms are equivalent.
	test("VAR:=\t${VAR:M-*:[\\#]}",
		"VAR:=\t${VAR:M-*:[#]}",
		"")

	// The character [ prevents the following # from starting a comment, even
	// outside of variable modifiers.
	test("COMMENT=\t[#] $$\\# $$# comment",
		"COMMENT=\t[#] $$# $$",
		"# comment")

	// A backslash always escapes the next character, be it a # for a comment
	// or something else. This makes it difficult to write a literal \# in a
	// Makefile, but that's an edge case anyway.
	test("VAR0=\t#comment",
		"VAR0=\t",
		"#comment")
	test("VAR1=\t\\#no-comment",
		"VAR1=\t#no-comment",
		"")
	test("VAR2=\t\\\\#comment",
		"VAR2=\t\\\\",
		"#comment")

	// The backslash is only removed when it escapes a comment.
	// In particular, it cannot be used to escape a dollar that starts a
	// variable use.
	test("VAR0=\t$T",
		"VAR0=\t$T",
		"")
	test("VAR1=\t\\$T",
		"VAR1=\t\\$T",
		"")
	test("VAR2=\t\\\\$T",
		"VAR2=\t\\\\$T",
		"")

	// To escape a dollar, write it twice.
	test("$$shellvar $${shellvar} \\${MKVAR} [] \\x",
		"$$shellvar $${shellvar} \\${MKVAR} [] \\x",
		"")

	// Parse errors are recorded in the rest return value.
	test("${UNCLOSED",
		"${UNCLOSED",
		"")

	// In this early phase of parsing, unfinished variable uses are not
	// interpreted and do not influence the detection of the comment start.
	test("text before ${UNCLOSED # comment",
		"text before ${UNCLOSED ",
		"# comment")

	// The dollar-space refers to a normal Make variable named " ".
	// The lonely dollar at the very end refers to the variable named "",
	// which is specially protected in bmake to always contain the empty string.
	// It is heavily used in .for loops in the form ${:Uvalue}.
	test("Lonely $ character $",
		"Lonely $ character $",
		"")

	// An even number of backslashes does not escape the #.
	// Therefore it starts a comment here.
	test("VAR2=\t\\\\#comment",
		"VAR2=\t\\\\",
		"#comment")
}

func (s *Suite) Test_MkLineParser_getRawValueAlign__assertion(c *check.C) {
	t := s.Init(c)

	var p MkLineParser

	// This is unrealistic; just for code coverage of the assertion.
	t.ExpectAssert(func() { p.getRawValueAlign("a", "b") })
}
