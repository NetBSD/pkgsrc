package pkglint

import (
	"gopkg.in/check.v1"
	"strings"
)

func (s *Suite) Test_SimpleCommandChecker__case_continue_with_loop(c *check.C) {
	t := s.Init(c)

	code := "case $$fname in ${CHECK_PORTABILITY_SKIP:@p@${p}) continue;; @} esac"
	line := t.NewLine("filename.mk", 123, "\t"+code)

	program, err := parseShellProgram(line, code)
	assertNil(err, "parse error")
	t.CheckEquals(
		program.AndOrs[0].Pipes[0].Cmds[0].Compound.Case.Cases[0].Var.MkText,
		"${CHECK_PORTABILITY_SKIP:@p@${p}) continue;; @}")
}

func (s *Suite) Test_SimpleCommandChecker__case_continue_with_suffix(c *check.C) {
	t := s.Init(c)

	code := "case $$fname in ${CHECK_PORTABILITY_SKIP:=) continue;; } esac"
	line := t.NewLine("filename.mk", 123, "\t"+code)

	program, err := parseShellProgram(line, code)
	assertNil(err, "parse error: parse error at []string{\"esac\"}")

	t.CheckEquals(
		program.AndOrs[0].Pipes[0].Cmds[0].Compound.Case.Cases[0].Var.MkText,
		"${CHECK_PORTABILITY_SKIP:=) continue;; }")
}

// When pkglint is called without -Wextra, the check for unknown shell
// commands is disabled, as it is still unreliable. As of December 2019
// there are around 500 warnings in pkgsrc, and several of them are wrong.
func (s *Suite) Test_SimpleCommandChecker_checkCommandStart__unknown_default(c *check.C) {
	t := s.Init(c)

	var pkg *Package
	test := func(commandLineArg string, diagnostics ...string) {
		t.SetUpCommandLine(commandLineArg)
		mklines := t.NewMkLinesPkg("Makefile", pkg,
			MkCvsID,
			"",
			"MY_TOOL.i386=\t${PREFIX}/bin/tool-i386",
			"MY_TOOL.x86_64=\t${PREFIX}/bin/tool-x86_64",
			"",
			"pre-configure:",
			"\t${MY_TOOL.amd64} -e 'print 12345'",
			"\t${UNKNOWN_TOOL}")

		mklines.Check()

		t.CheckOutput(diagnostics)
	}

	t.SetUpPackage("category/package")
	pkg = NewPackage(t.File("category/package"))
	t.Chdir("category/package")
	t.FinishSetUp()

	test(".", // Override the default -Wall option.
		nil...)

	test("-Wall,no-extra",
		nil...)

	test("-Wall",
		"WARN: Makefile:8: Unknown shell command \"${UNKNOWN_TOOL}\".",
		"WARN: Makefile:8: UNKNOWN_TOOL is used but not defined.")
}

// Despite its name, the TOOLS_PATH.* name the whole shell command,
// not just the path of its executable.
func (s *Suite) Test_SimpleCommandChecker_checkCommandStart__TOOLS_PATH(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"CONFIG_SHELL=\t${TOOLS_PATH.bash}")
	t.Chdir("category/package")
	t.FinishSetUp()
	G.checkdirPackage(".")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_SimpleCommandChecker_checkInstallCommand(c *check.C) {
	t := s.Init(c)

	lines := func(lines ...string) []string { return lines }

	test := func(lines []string, diagnostics ...string) {
		mklines := t.NewMkLines("filename.mk",
			mapStr(lines, func(s string) string { return "\t" + s })...)
		mklines.checkAllData.target = "do-install"

		mklines.ForEach(func(mkline *MkLine) {
			program, err := parseShellProgram(nil, mkline.ShellCommand())
			assertNil(err, "")

			walker := NewMkShWalker()
			walker.Callback.SimpleCommand = func(command *MkShSimpleCommand) {
				scc := NewSimpleCommandChecker(command, RunTime, mkline, mklines)
				scc.checkInstallCommand(command.Name.MkText)
			}
			walker.Walk(program)
		})

		t.CheckOutput(diagnostics)
	}

	test(
		lines(
			"sed",
			"${SED}"),
		"WARN: filename.mk:1: The shell command \"sed\" "+
			"should not be used in the install phase.",
		"WARN: filename.mk:2: The shell command \"${SED}\" "+
			"should not be used in the install phase.")

	test(
		lines(
			"tr",
			"${TR}"),
		"WARN: filename.mk:1: The shell command \"tr\" "+
			"should not be used in the install phase.",
		"WARN: filename.mk:2: The shell command \"${TR}\" "+
			"should not be used in the install phase.")

	test(
		lines(
			"cp",
			"${CP}"),
		"WARN: filename.mk:1: ${CP} should not be used to install files.",
		"WARN: filename.mk:2: ${CP} should not be used to install files.")

	test(
		lines(
			"${INSTALL}",
			"${INSTALL_DATA}",
			"${INSTALL_DATA_DIR}",
			"${INSTALL_LIB}",
			"${INSTALL_LIB_DIR}",
			"${INSTALL_MAN}",
			"${INSTALL_MAN_DIR}",
			"${INSTALL_PROGRAM}",
			"${INSTALL_PROGRAM_DIR}",
			"${INSTALL_SCRIPT}",
			"${LIBTOOL}",
			"${LN}",
			"${PAX}"),
		nil...)
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

	t.SetUpVartypes()
	t.SetUpTool("runtime", "RUNTIME", AtRunTime)
	t.SetUpTool("nowhere", "NOWHERE", Nowhere)
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"RUNTIME_Q_CMD=\t${RUNTIME:Q}",
		"NOWHERE_Q_CMD=\t${NOWHERE:Q}",
		"RUNTIME_CMD=\t${RUNTIME}",
		"NOWHERE_CMD=\t${NOWHERE}",
		"",
		"pre-configure:",
		"\t: ${RUNTIME_Q_CMD} ${NOWHERE_Q_CMD}",
		"\t: ${RUNTIME_CMD} ${NOWHERE_CMD}",
		"\t${PKGNAME}") // This doesn't make sense; it's just for code coverage

	mklines.Check()

	// A tool that appears as the name of a shell command is exactly
	// intended to be used without quotes, so that its possible
	// command line options are treated as separate arguments.
	//
	// TODO: Add a warning that in lines 3 and 4, the :Q is wrong.
	t.CheckOutputLines(
		"WARN: Makefile:4: The \"${NOWHERE:Q}\" tool is used but not added to USE_TOOLS.",
		"WARN: Makefile:6: The \"${NOWHERE}\" tool is used but not added to USE_TOOLS.",
		"WARN: Makefile:11: Unknown shell command \"${PKGNAME}\".")
}

func (s *Suite) Test_SimpleCommandChecker_handleCommandVariable__parameterized(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	pkg := NewPackage(t.File("category/package"))
	t.FinishSetUp()

	mklines := t.NewMkLinesPkg("Makefile", pkg,
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
	pkg := NewPackage(t.File("category/package"))
	t.FinishSetUp()

	mklines := t.NewMkLinesPkg("Makefile", pkg,
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
// TODO: This paragraph sounds wrong. All commands from included files should be valid.
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

func (s *Suite) Test_SimpleCommandChecker_handleShellBuiltin(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		"\t:")
	mkline := mklines.mklines[0]

	test := func(command string, isBuiltin bool) {
		token := NewShToken(command, NewShAtom(shtText, command, shqPlain))
		simpleCommand := &MkShSimpleCommand{Name: token}
		scc := NewSimpleCommandChecker(simpleCommand, RunTime, mkline, mklines)
		t.CheckEquals(scc.handleShellBuiltin(), isBuiltin)
	}

	test(":", true)
	test("break", true)
	test("cd", true)
	test("continue", true)
	test("eval", true)
	test("exec", true)
	test("exit", true)
	test("export", true)
	test("read", true)
	test("set", true)
	test("shift", true)
	test("umask", true)
	test("unset", true)

	test("git", false)
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
	// TODO: Check whether these tools are actually necessary for this test.
	t.SetUpTool("awk", "AWK", AtRunTime)
	t.SetUpTool("cp", "CP", AtRunTime)
	t.SetUpTool("echo", "", AtRunTime)
	t.SetUpTool("mkdir", "MKDIR", AtRunTime) // This is actually "mkdir -p".
	t.SetUpTool("unzip", "UNZIP_CMD", AtRunTime)

	var pkg *Package

	test := func(shellCommand string, diagnostics ...string) {
		mklines := t.NewMkLinesPkg("filename.mk", pkg,
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

	pkg = NewPackage(t.File("category/pkgbase"))
	pkg.Plist.UnconditionalDirs["share/pkgbase"] = &PlistLine{
		t.NewLine("PLIST", 123, "share/pkgbase/file"),
		nil,
		"share/pkgbase/file"}

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

func (s *Suite) Test_SimpleCommandChecker_checkAutoMkdirs__redundant(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"AUTO_MKDIRS=\t\tyes",
		"INSTALLATION_DIRS+=\tshare/redundant",
		"INSTALLATION_DIRS+=\tnot/redundant ${EGDIR}")
	t.CreateFileLines("category/package/PLIST",
		PlistCvsID,
		"share/redundant/file",
		"${EGDIR}/file")

	t.Main("-Wall", "-q", "category/package")

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:21: The directory \"share/redundant\" "+
			"is redundant in INSTALLATION_DIRS.",
		// The below is not proven to be always correct. It assumes that a
		// variable in the Makefile has the same value as the corresponding
		// variable from PLIST_SUBST. Violating this assumption would be
		// confusing to the pkgsrc developers, therefore it's a safe bet.
		// A notable counterexample is PKGNAME in PLIST, which corresponds
		// to PKGNAME_NOREV in the package Makefile.
		"NOTE: ~/category/package/Makefile:22: The directory \"${EGDIR}\" "+
			"is redundant in INSTALLATION_DIRS.")
}

// The AUTO_MKDIRS code in mk/install/install.mk (install-dirs-from-PLIST)
// skips conditional directories, as well as directories with placeholders.
func (s *Suite) Test_SimpleCommandChecker_checkAutoMkdirs__conditional_PLIST(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"LIB_SUBDIR=\tsubdir",
		"",
		"do-install:",
		"\t${RUN} ${INSTALL_DATA_DIR} ${PREFIX}/libexec/always",
		"\t${RUN} ${INSTALL_DATA_DIR} ${PREFIX}/libexec/conditional",
		"\t${RUN} ${INSTALL_DATA_DIR} ${PREFIX}/${LIB_SUBDIR}",
	)
	t.Chdir("category/package")
	t.CreateFileLines("PLIST",
		PlistCvsID,
		"libexec/always/always",
		"${LIB_SUBDIR}/file",
		"${PLIST.cond}libexec/conditional/conditional")
	t.FinishSetUp()

	G.checkdirPackage(".")

	// As libexec/conditional will not be created automatically,
	// AUTO_MKDIRS must not be suggested in that line.
	t.CheckOutputLines(
		"NOTE: Makefile:23: You can use AUTO_MKDIRS=yes "+
			"or \"INSTALLATION_DIRS+= libexec/always\" "+
			"instead of \"${INSTALL_DATA_DIR}\".",
		"NOTE: Makefile:24: You can use "+
			"\"INSTALLATION_DIRS+= libexec/conditional\" "+
			"instead of \"${INSTALL_DATA_DIR}\".",
		"NOTE: Makefile:25: You can use "+
			"\"INSTALLATION_DIRS+= ${LIB_SUBDIR}\" "+
			"instead of \"${INSTALL_DATA_DIR}\".")
}

func (s *Suite) Test_SimpleCommandChecker_checkAutoMkdirs__strange_paths(c *check.C) {
	t := s.Init(c)

	test := func(path string, diagnostics ...string) {
		mklines := t.NewMkLines("filename.mk",
			"\t${INSTALL_DATA_DIR} "+path)
		mklines.ForEach(func(mkline *MkLine) {
			program, err := parseShellProgram(nil, mkline.ShellCommand())
			assertNil(err, "")

			walker := NewMkShWalker()
			walker.Callback.SimpleCommand = func(command *MkShSimpleCommand) {
				scc := NewSimpleCommandChecker(command, RunTime, mkline, mklines)
				scc.checkAutoMkdirs()
			}
			walker.Walk(program)
		})
		t.CheckOutput(diagnostics)
	}

	t.Chdir("category/package")

	test("${PREFIX}",
		nil...)

	test("${PREFIX}/",
		nil...)

	test("${PREFIX}//",
		nil...)

	test("${PREFIX}/.",
		nil...)

	test("${PREFIX}//non-canonical",
		"NOTE: filename.mk:1: You can use \"INSTALLATION_DIRS+= non-canonical\" "+
			"instead of \"${INSTALL_DATA_DIR}\".")

	test("${PREFIX}/non-canonical/////",
		"NOTE: filename.mk:1: You can use \"INSTALLATION_DIRS+= non-canonical\" "+
			"instead of \"${INSTALL_DATA_DIR}\".")

	test("${PREFIX}/${VAR}",
		"NOTE: filename.mk:1: You can use \"INSTALLATION_DIRS+= ${VAR}\" "+
			"instead of \"${INSTALL_DATA_DIR}\".")

	test("${PREFIX}/${VAR.param}",
		"NOTE: filename.mk:1: You can use \"INSTALLATION_DIRS+= ${VAR.param}\" "+
			"instead of \"${INSTALL_DATA_DIR}\".")

	test("${PREFIX}/${.CURDIR}",
		"NOTE: filename.mk:1: You can use \"INSTALLATION_DIRS+= ${.CURDIR}\" "+
			"instead of \"${INSTALL_DATA_DIR}\".")

	// Internal variables are ok.
	test("${PREFIX}/${_INTERNAL}",
		"NOTE: filename.mk:1: You can use \"INSTALLATION_DIRS+= ${_INTERNAL}\" "+
			"instead of \"${INSTALL_DATA_DIR}\".")

	// Ignore variables from a :@ modifier.
	test("${PREFIX}/${.f.}",
		nil...)

	// Ignore variables from a .for loop.
	test("${PREFIX}/${f}",
		nil...)

	// Ignore variables from a .for loop.
	test("${PREFIX}/${_f_}",
		nil...)

	// Ignore paths containing shell variables as it is hard to
	// predict their values using static analysis.
	test("${PREFIX}/$$f",
		nil...)
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

// Before 2020-03-25, pkglint ran into a parse error since it didn't
// know that _ULIMIT_CMD brings its own semicolon.
func (s *Suite) Test_ShellLineChecker__skip_ULIMIT_CMD(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"pre-configure:",
		"\t${RUN} ${_ULIMIT_CMD} while :; do :; done")

	mklines.Check()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_ShellLineChecker_checkSetE__simple_commands(c *check.C) {
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

func (s *Suite) Test_ShellLineChecker_checkSetE__compound_commands(c *check.C) {
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

func (s *Suite) Test_ShellLineChecker_checkSetE__no_tracing(c *check.C) {
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

func (s *Suite) Test_ShellLineChecker_canFail(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("basename", "", AtRunTime)
	t.SetUpTool("dirname", "", AtRunTime)
	t.SetUpTool("echo", "", AtRunTime)
	t.SetUpTool("env", "", AtRunTime)
	t.SetUpTool("ggrep", "", AtRunTime)
	t.SetUpTool("grep", "GREP", AtRunTime)
	t.SetUpTool("sed", "", AtRunTime)
	t.SetUpTool("gsed", "", AtRunTime)
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
		"WARN: Makefile:3: Please switch to \"set -e\" mode before using a semicolon "+
			"(after \"socklen=$$(expr 16)\") to separate commands.")

	test("socklen=$$(expr 16 || true)",
		nil...)

	test("socklen=$$(expr 16 || ${TRUE})",
		nil...)

	test("${ECHO_MSG} \"Message\"",
		nil...)

	test("${PHASE_MSG} \"Message\"",
		nil...)

	test("${STEP_MSG} \"Message\"",
		nil...)

	test("${INFO_MSG} \"Message\"",
		nil...)

	test("${WARNING_MSG} \"Message\"",
		nil...)

	test("${ERROR_MSG} \"Message\"",
		nil...)

	test("${WARNING_CAT} \"Message\"",
		nil...)

	test("${ERROR_CAT} \"Message\"",
		nil...)

	test("${DO_NADA} \"Message\"",
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

	test("gsed -e s,in,out,",
		nil...)

	test("gsed s,in,out,",
		nil...)

	test("gsed s,in,out, filename",
		"WARN: Makefile:3: Please switch to \"set -e\" mode "+
			"before using a semicolon (after \"gsed s,in,out, filename\") "+
			"to separate commands.")

	test("ggrep input",
		nil...)

	test("ggrep pattern file...",
		"WARN: Makefile:3: Please switch to \"set -e\" mode before using a semicolon "+
			"(after \"ggrep pattern file...\") to separate commands.")

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

	test("tr A-Z a-z",
		nil...)
}

func (s *Suite) Test_ShellLineChecker_checkPipeExitcode(c *check.C) {
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

func (s *Suite) Test_ShellLineChecker_CheckShellCommandLine(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("[", "TEST", AtRunTime)
	t.SetUpTool("awk", "AWK", AtRunTime)
	t.SetUpTool("cp", "CP", AtRunTime)
	t.SetUpTool("echo", "", AtRunTime)
	t.SetUpTool("mkdir", "MKDIR", AtRunTime) // This is actually "mkdir -p".
	t.SetUpTool("unzip", "UNZIP_CMD", AtRunTime)

	var pkg *Package
	test := func(shellCommand string, diagnostics ...string) {
		mklines := t.NewMkLinesPkg("filename.mk", pkg,
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
		"NOTE: filename.mk:1: The :Q modifier isn't necessary for ${PKGNAME} here.")

	test("echo \"${CFLAGS:Q}\"", // VucQuotDquot

		// ShellLineChecker.checkVaruseToken
		"WARN: filename.mk:1: The :Q modifier should not be used inside quotes.",

		// ShellLineChecker.checkVaruseToken
		//     MkLineChecker.CheckVaruse
		//         MkVarUseChecker.checkQuoting
		"WARN: filename.mk:1: Please use ${CFLAGS:M*:Q} instead of ${CFLAGS:Q} "+
			"and make sure the variable appears outside of any quoting characters.")

	test("echo '${COMMENT:Q}'", // VucQuotSquot
		"WARN: filename.mk:1: The :Q modifier should not be used inside quotes.",
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
	test(""+
		"set -e; cd ${WRKSRC}/locale; "+
		"for lang in *.po; do "+
		"  [ \"$${lang}\" = \"wxstd.po\" ] && continue; "+
		"  ${TOOLS_PATH.msgfmt} -c -o \"$${lang%.po}.mo\" \"$${lang}\"; "+
		"done",
		nil...)

	test("@cp from to",
		"WARN: filename.mk:1: The shell command \"cp\" should not be hidden.")

	test("-cp from to",
		"WARN: filename.mk:1: Using a leading \"-\" to suppress errors is deprecated.")

	test("-${MKDIR} deeply/nested/subdir",
		"WARN: filename.mk:1: Using a leading \"-\" to suppress errors is deprecated.")

	pkg = NewPackage(t.File("category/pkgbase"))
	pkg.Plist.UnconditionalDirs["share/pkgbase"] = &PlistLine{
		t.NewLine("PLIST", 123, "share/pkgbase/file"),
		nil,
		"share/pkgbase/file"}

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

	pkg = nil

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

// After working a lot with usr.bin/make, I thought that lines containing
// the cd command would differ in behavior between compatibility mode and
// parallel mode.  But since pkgsrc does not support parallel mode and also
// actively warns when someone tries to run it in parallel mode, there is
// no point checking for chdir that might spill over to the next line.
// That will not happen in compat mode.
func (s *Suite) Test_ShellLineChecker_CheckShellCommandLine__chdir(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("echo", "", AfterPrefsMk)
	t.SetUpTool("sed", "", AfterPrefsMk)
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"",
		"pre-configure:",
		// This command is run in the current directory.
		"\techo command 1",
		// This chdir affects the remaining commands.
		// It might be possible to warn here about chdir.
		"\tcd ..",
		// In subshells, chdir is ok.
		"\t(cd ..)",
		// In pipes, chdir is ok.
		"\t{ cd .. && echo sender; } | { cd .. && sed s,sender,receiver; }",
		// The && operator does not run in a subshell.
		// It might be possible to warn here about chdir.
		"\tcd .. && echo",
		// The || operator does not run in a subshell.
		// It might be possible to warn here about chdir.
		"\tcd .. || echo",
		// The current directory of this command depends on the preceding
		// commands.
		"\techo command 2",
		// In the final command of a target, chdir is ok since there are
		// no further commands that could be affected.
		"\tcd ..")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:7: The exitcode of the command at the left of " +
			"the | operator is ignored.")
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
		"NOTE: Makefile:1: The :Q modifier isn't necessary for ${PKGNAME} here.")
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
		"NOTE: Makefile:1: The :Q modifier isn't necessary for ${PKGNAME} here.",
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

// TODO: Document the exact purpose of this test, or split it into useful tests.
func (s *Suite) Test_ShellLineChecker_CheckShellCommandLine__implementation(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("filename.mk",
		"# dummy")
	ck := NewShellLineChecker(mklines, mklines.mklines[0])

	// foobar="`echo \"foo   bar\"`"
	text := "foobar=\"`echo \\\"foo   bar\\\"`\""

	tokens, rest := splitIntoShellTokens(ck.mkline.Line, text)

	t.CheckDeepEquals(tokens, []string{text})
	t.CheckEquals(rest, "")

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
		// TODO: Avoid these duplicate diagnostics.
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Make variable or $$f if you mean a shell variable.",
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Make variable or $$f if you mean a shell variable.",
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Make variable or $$f if you mean a shell variable.",
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Make variable or $$f if you mean a shell variable.",
		"NOTE: Makefile:3: Please use the SUBST framework instead of ${SED} and ${MV}.",
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Make variable or $$f if you mean a shell variable.",
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Make variable or $$f if you mean a shell variable.",
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Make variable or $$f if you mean a shell variable.",
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Make variable or $$f if you mean a shell variable.",
		"WARN: Makefile:3: f is used but not defined.",
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Make variable or $$f if you mean a shell variable.",
		"WARN: Makefile:3: $f is ambiguous. Use ${f} if you mean a Make variable or $$f if you mean a shell variable.")

	ck.CheckShellCommandLine("install -c manpage.1 ${PREFIX}/man/man1/manpage.1")

	t.CheckOutputLines(
		"WARN: Makefile:3: Please use ${PKGMANDIR} instead of \"man\".")

	ck.CheckShellCommandLine("cp init-script ${PREFIX}/etc/rc.d/service")

	t.CheckOutputLines(
		"WARN: Makefile:3: Please use the RCD_SCRIPTS mechanism to install rc.d scripts automatically to ${RCD_SCRIPTS_EXAMPLEDIR}.")
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

func (s *Suite) Test_ShellLineChecker_CheckShellCommandLine__sed_and_mv_explained(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	t.SetUpVartypes()
	t.SetUpTool("sed", "SED", AtRunTime)
	t.SetUpTool("mv", "MV", AtRunTime)
	ck := t.NewShellLineChecker("\t${RUN} ${SED} 's,#,// comment:,g' filename > filename.tmp; ${MV} filename.tmp filename")

	ck.CheckShellCommandLine(ck.mkline.ShellCommand())

	t.CheckOutputLines(
		"NOTE: filename.mk:1: Please use the SUBST framework instead of ${SED} and ${MV}.",
		"",
		"\tUsing the SUBST framework instead of explicit commands is easier to",
		"\tunderstand, since all the complexity of using sed and mv is hidden",
		"\tbehind the scenes.",
		"",
		sprintf("\tRun %q for more information.", bmakeHelp("subst")),
		"",
		"\tWhen migrating to the SUBST framework, pay attention to \"#\"",
		"\tcharacters. In shell commands, make(1) does not interpret them as",
		"\tcomment character, but in variable assignments it does. Therefore,",
		"\tinstead of the shell command",
		"",
		"\t\tsed -e 's,#define foo,,'",
		"",
		"\tyou need to write",
		"",
		"\t\tSUBST_SED.foo+=\t's,\\#define foo,,'",
		"")
}

func (s *Suite) Test_ShellLineChecker_CheckShellCommandLine__sed_and_mv_autofix_explained(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain", "--autofix")
	t.SetUpVartypes()
	t.SetUpTool("sed", "SED", AtRunTime)
	t.SetUpTool("mv", "MV", AtRunTime)
	ck := t.NewShellLineChecker("\t${RUN} ${SED} 's,#,// comment:,g' filename > filename.tmp; ${MV} filename.tmp filename")

	ck.CheckShellCommandLine(ck.mkline.ShellCommand())

	// Only ever output an explanation if there's a corresponding diagnostic.
	// Even if Explain is called twice in a row.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_ShellLineChecker_CheckShellCommandLine__subshell(c *check.C) {
	t := s.Init(c)

	ck := t.NewShellLineChecker("\t${RUN} uname=$$(uname)")

	ck.CheckShellCommandLine(ck.mkline.ShellCommand())

	// Up to 2020-05-09, pkglint had warned that $(...) were not portable
	// enough. The shell used in devel/bmake can handle these subshell
	// command substitutions though.
	t.CheckOutputEmpty()
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

func (s *Suite) Test_ShellLineChecker_checkHiddenAndSuppress(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("echo", "ECHO", AtRunTime)
	t.SetUpTool("ls", "LS", AtRunTime)
	t.SetUpTool("mkdir", "MKDIR", AtRunTime)
	t.SetUpTool("printf", "PRINTF", AtRunTime)
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
		"\t@",
		"\t@mkdir ${WRKSRC}",
		"\t@${DELAYED_ERROR_MSG} 'ok'",
		"\t@${DELAYED_WARNING_MSG} 'ok'",
		"\t@${DO_NADA} 'ok'",
		"\t@${ECHO} 'ok'",
		"\t@${ECHO_MSG} 'ok'",
		"\t@${ECHO_N} 'ok'",
		"\t@${ERROR_CAT} 'ok'",
		"\t@${ERROR_MSG} 'ok'",
		"\t@${FAIL_MSG} 'ok'",
		"\t@${INFO_MSG} 'ok'",
		"\t@${PHASE_MSG} 'ok'",
		"\t@${PRINTF} 'ok'",
		"\t@${SHCOMMENT} 'ok'",
		"\t@${STEP_MSG} 'ok'",
		"\t@${WARNING_CAT} 'ok'",
		"\t@${WARNING_MSG} 'ok'")

	mklines.Check()

	// No warning about the hidden ls since the target names start
	// with "show-" or end with "-message".
	t.CheckOutputLines(
		"WARN: Makefile:13: The shell command \"mkdir\" should not be hidden.")
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

	// XXX: Fix the parse errors (nested subshells).
	// XXX: Fix the duplicate diagnostic in line 6.
	// TODO: "(" is not a shell command, it's an operator.
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

	// TODO: Ensure that the shell word is really only one variable use.
	// TODO: Ensure that the last modifier is :@@@.
	// TODO: Ensure that the replacement is a well-formed case-item.
	// TODO: Ensure that the replacement contains ";;" as the last shell token.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_ShellLineChecker_CheckWord(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	test := func(shellWord string, checkQuoting bool, diagnostics ...string) {
		// See MkVarUseChecker.checkUndefined and MkAssignChecker.checkLeftNotUsed.
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
	//  The corresponding code in ShellLineChecker.CheckWord should be removed.
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
		"NOTE: filename.mk:1: The :Q modifier isn't necessary for ${DISTINFO_FILE} here.")

	test("embed${DISTINFO_FILE:Q}ded", true,
		"NOTE: filename.mk:1: The :Q modifier isn't necessary for ${DISTINFO_FILE} here.")

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

	// XXX: Should be parsed correctly. Make passes the dollar through (probably),
	//  and the shell parser should complain about the unfinished string literal.
	t.CheckOutputLines(
		"WARN: filename.mk:1: Internal pkglint error in ShTokenizer.ShAtom at \"$\" (quoting=s).",
		"WARN: filename.mk:1: Internal pkglint error in ShellLine.CheckWord at \"'$\" (quoting=s), rest: $")
}

func (s *Suite) Test_ShellLineChecker_CheckWord__dquot_dollar(c *check.C) {
	t := s.Init(c)

	ck := t.NewShellLineChecker("\t\"$")

	ck.CheckWord(ck.mkline.ShellCommand(), false, RunTime)

	// XXX: Make consumes the dollar silently.
	//  This could be worth another pkglint warning.
	t.CheckOutputEmpty()
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
		"NOTE: chat/ircII/Makefile:2: This variable value should be aligned to column 25 instead of 17.",
		"NOTE: chat/ircII/Makefile:3: This variable value should be aligned to column 25 instead of 17.")
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
		nil...)

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

func (s *Suite) Test_ShellLineChecker_unescapeBackticks(c *check.C) {
	t := s.Init(c)

	test := func(input string, expectedOutput string, expectedRest string, diagnostics ...string) {
		ck := t.NewShellLineChecker("# dummy")

		tok := NewShTokenizer(nil, input)
		atoms := tok.ShAtoms()

		// Set up the correct quoting mode for the test by skipping
		// uninteresting atoms at the beginning.
		q := shqPlain
		for atoms[0].MkText != "`" {
			q = atoms[0].Quoting
			atoms = atoms[1:]
		}
		t.CheckEquals(tok.Rest(), "")

		backtCommand := ck.unescapeBackticks(&atoms, q)

		var actualRest strings.Builder
		for _, atom := range atoms {
			actualRest.WriteString(atom.MkText)
		}

		t.CheckEquals(backtCommand, expectedOutput)
		t.CheckEquals(actualRest.String(), expectedRest)
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

	// The inner shell command in the backticks is malformed since it
	// contains an unpaired backtick.
	test("`echo \\``rest", "echo `", "rest")

	// Enclosing the inner backtick in single quotes makes it valid.
	test("`echo '\\`'`rest", "echo '`'", "rest")

	test("`echo \\$$var`rest", "echo $$var", "rest")
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

	// XXX: It is inconsistent that the check for unquoted shell
	//  variables is enabled for CONFIGURE_ARGS (where shell variables
	//  don't make sense at all) but not for real shell commands.
	t.CheckOutputLines(
		"WARN: filename.mk:2: The $@ shell variable should only be used in double quotes.",
		"WARN: filename.mk:2: Unquoted shell variable \"var\".",
		"WARN: filename.mk:5: The $@ shell variable should only be used in double quotes.")
}

func (s *Suite) Test_ShellLineChecker_variableNeedsQuoting(c *check.C) {
	t := s.Init(c)

	test := func(shVarname string, expected bool) {
		t.CheckEquals((*ShellLineChecker).variableNeedsQuoting(nil, shVarname), expected)
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
	test("comment", true) // Comments can be arbitrary strings.
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

func (s *Suite) Test_ShellLineChecker_checkMultiLineComment(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("echo", "", AtRunTime)
	t.SetUpTool("sed", "", AtRunTime)
	t.SetUpVartypes()

	test := func(lines ...string) {
		i := 0
		for ; i < len(lines) && hasPrefix(lines[i], "\t"); i++ {
		}

		mklines := t.SetUpFileMkLines("Makefile",
			append([]string{MkCvsID, "pre-build:"},
				lines[:i]...)...)

		mklines.Check()

		t.CheckOutput(lines[i:])
	}

	// The comment can start at the beginning of a follow-up line.
	test(
		"\techo first; \\",
		"\t# comment at the beginning of a command \\",
		"\techo \"hello\"",

		"WARN: ~/Makefile:4: "+
			"The shell comment does not stop at the end of this line.")

	// The comment can start at the beginning of a simple command.
	test(
		"\techo first; # comment at the beginning of a command \\",
		"\techo \"hello\"",

		"WARN: ~/Makefile:3: "+
			"The shell comment does not stop at the end of this line.")

	// The comment can start at a word in the middle of a command.
	test(
		"\techo # comment starts inside a command \\",
		"\techo \"hello\"",

		"WARN: ~/Makefile:3: "+
			"The shell comment does not stop at the end of this line.")

	// If the comment starts in the last line, there's no further
	// line that might be commented out accidentally.
	test(
		"\techo 'first line'; \\",
		"\t# comment in last line")

	// If there's a shell token that extends over several lines,
	// that's unusual enough that pkglint refuses to check this.
	test(
		"\techo 'before \\",
		"\t\tafter'; \\",
		"\t# comment \\",
		"\techo 'still a comment'")

	test(
		"\tsed -e s#@PREFIX@#${PREFIX}#g \\",
		"\tfilename",

		"WARN: ~/Makefile:3--4: Substitution commands like "+
			"\"s#@PREFIX@#${PREFIX}#g\" should always be quoted.")
}

func (s *Suite) Test_splitIntoShellTokens__line_continuation(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename.mk", 1, "")
	words, rest := splitIntoShellTokens(line, "if true; then \\")

	t.CheckDeepEquals(words, []string{"if", "true", ";", "then"})
	t.CheckEquals(rest, "\\")

	t.CheckOutputLines(
		"WARN: filename.mk:1: Internal pkglint error in ShTokenizer.ShAtom at \"\\\\\" (quoting=plain).")
}

func (s *Suite) Test_splitIntoShellTokens__dollar_slash(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename.mk", 1, "")
	words, rest := splitIntoShellTokens(line, "pax -s /.*~$$//g")

	t.CheckDeepEquals(words, []string{"pax", "-s", "/.*~$$//g"})
	t.CheckEquals(rest, "")
}

func (s *Suite) Test_splitIntoShellTokens__dollar_subshell(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename.mk", 1, "")
	words, rest := splitIntoShellTokens(line, "id=$$(${AWK} '{print}' < ${WRKSRC}/idfile) && echo \"$$id\"")

	t.CheckDeepEquals(words, []string{"id=$$(${AWK} '{print}' < ${WRKSRC}/idfile)", "&&", "echo", "\"$$id\""})
	t.CheckEquals(rest, "")
}

func (s *Suite) Test_splitIntoShellTokens__semicolons(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename.mk", 1, "")
	words, rest := splitIntoShellTokens(line, "word1 word2;;;")

	t.CheckDeepEquals(words, []string{"word1", "word2", ";;", ";"})
	t.CheckEquals(rest, "")
}

func (s *Suite) Test_splitIntoShellTokens__whitespace(c *check.C) {
	t := s.Init(c)

	text := "\t${RUN} cd ${WRKSRC}&&(${ECHO} ${PERL5:Q};${ECHO})|${BASH} ./install"
	line := t.NewLine("filename.mk", 1, "")
	words, rest := splitIntoShellTokens(line, text)

	t.CheckDeepEquals(words, []string{
		"${RUN}",
		"cd", "${WRKSRC}",
		"&&", "(", "${ECHO}", "${PERL5:Q}", ";", "${ECHO}", ")",
		"|", "${BASH}", "./install"})
	t.CheckEquals(rest, "")
}

func (s *Suite) Test_splitIntoShellTokens__finished_dquot(c *check.C) {
	t := s.Init(c)

	text := "\"\""
	line := t.NewLine("filename.mk", 1, "")
	words, rest := splitIntoShellTokens(line, text)

	t.CheckDeepEquals(words, []string{"\"\""})
	t.CheckEquals(rest, "")
}

func (s *Suite) Test_splitIntoShellTokens__unfinished_dquot(c *check.C) {
	t := s.Init(c)

	text := "\t\""
	line := t.NewLine("filename.mk", 1, "")
	words, rest := splitIntoShellTokens(line, text)

	t.CheckNil(words)
	t.CheckEquals(rest, "\"")
}

func (s *Suite) Test_splitIntoShellTokens__unescaped_dollar_in_dquot(c *check.C) {
	t := s.Init(c)

	text := "echo \"$$\""
	line := t.NewLine("filename.mk", 1, "")
	words, rest := splitIntoShellTokens(line, text)

	t.CheckDeepEquals(words, []string{"echo", "\"$$\""})
	t.CheckEquals(rest, "")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_splitIntoShellTokens__varuse_with_embedded_space_and_other_vars(c *check.C) {
	t := s.Init(c)

	varuseWord := "${GCONF_SCHEMAS:@.s.@${INSTALL_DATA} ${WRKSRC}/src/common/dbus/${.s.} ${DESTDIR}${GCONF_SCHEMAS_DIR}/@}"
	line := t.NewLine("filename.mk", 1, "")
	words, rest := splitIntoShellTokens(line, varuseWord)

	t.CheckDeepEquals(words, []string{varuseWord})
	t.CheckEquals(rest, "")
}

// Two shell variables, next to each other,
// are two separate atoms but count as a single token.
func (s *Suite) Test_splitIntoShellTokens__two_shell_variables(c *check.C) {
	t := s.Init(c)

	code := "echo $$i$$j"
	line := t.NewLine("filename.mk", 1, "")
	words, rest := splitIntoShellTokens(line, code)

	t.CheckDeepEquals(words, []string{"echo", "$$i$$j"})
	t.CheckEquals(rest, "")
}

func (s *Suite) Test_splitIntoShellTokens__varuse_with_embedded_space(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename.mk", 1, "")
	words, rest := splitIntoShellTokens(line, "${VAR:S/ /_/g}")

	t.CheckDeepEquals(words, []string{"${VAR:S/ /_/g}"})
	t.CheckEquals(rest, "")
}

func (s *Suite) Test_splitIntoShellTokens__redirect(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename.mk", 1, "")
	words, rest := splitIntoShellTokens(line, "echo 1>output 2>>append 3>|clobber 4>&5 6<input >>append")

	t.CheckDeepEquals(words, []string{
		"echo",
		"1>", "output",
		"2>>", "append",
		"3>|", "clobber",
		"4>&", "5",
		"6<", "input",
		">>", "append"})
	t.CheckEquals(rest, "")

	words, rest = splitIntoShellTokens(line, "echo 1> output 2>> append 3>| clobber 4>& 5 6< input >> append")

	t.CheckDeepEquals(words, []string{
		"echo",
		"1>", "output",
		"2>>", "append",
		"3>|", "clobber",
		"4>&", "5",
		"6<", "input",
		">>", "append"})
	t.CheckEquals(rest, "")
}

func (s *Suite) Test_splitIntoShellTokens__varuse(c *check.C) {
	t := s.Init(c)

	test := func(text string, tokens ...string) {
		line := t.NewLine("filename.mk", 1, "")

		words, rest := splitIntoShellTokens(line, text)

		t.CheckDeepEquals(words, tokens)
		t.CheckEquals(rest, "")
	}

	test(
		"sed -e s#@PREFIX@#${PREFIX}#g filename",

		"sed",
		"-e",
		"s#@PREFIX@#${PREFIX}#g",
		"filename")
}
