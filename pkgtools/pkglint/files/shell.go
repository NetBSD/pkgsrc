package pkglint

import (
	"netbsd.org/pkglint/textproc"
	"path"
	"strings"
)

// Parsing and checking shell commands embedded in Makefiles

type SimpleCommandChecker struct {
	cmd    *MkShSimpleCommand
	strcmd *StrCommand
	time   ToolTime

	mkline  *MkLine
	mklines *MkLines
}

func NewSimpleCommandChecker(cmd *MkShSimpleCommand, time ToolTime, mkline *MkLine, mklines *MkLines) *SimpleCommandChecker {
	strcmd := NewStrCommand(cmd)
	return &SimpleCommandChecker{cmd, strcmd, time, mkline, mklines}

}

func (scc *SimpleCommandChecker) Check() {
	if trace.Tracing {
		defer trace.Call(scc.strcmd)()
	}

	scc.checkCommandStart()
	scc.checkRegexReplace()
	scc.checkAutoMkdirs()
	scc.checkInstallMulti()
	scc.checkPaxPe()
	scc.checkEchoN()
}

func (scc *SimpleCommandChecker) checkCommandStart() {
	if trace.Tracing {
		defer trace.Call0()()
	}

	shellword := scc.strcmd.Name
	scc.checkInstallCommand(shellword)

	switch {
	case shellword == "":
		break
	case scc.handleForbiddenCommand():
		break
	case scc.handleTool():
		break
	case scc.handleCommandVariable():
		break
	case scc.handleShellBuiltin():
		break
	case hasPrefix(shellword, "./"): // All commands from the current directory are fine.
		break
	default:
		if G.WarnExtra && !scc.mklines.indentation.DependsOn("OPSYS") {
			scc.mkline.Warnf("Unknown shell command %q.", shellword)
			scc.mkline.Explain(
				"To make the package portable to all platforms that pkgsrc supports,",
				"it should only use shell commands that are covered by the tools framework.",
				"",
				"To run custom shell commands, prefix them with \"./\" or with \"${PREFIX}/\".")
		}
	}
}

// Some shell commands should not be used in the install phase.
func (scc *SimpleCommandChecker) checkInstallCommand(shellcmd string) {
	if trace.Tracing {
		defer trace.Call0()()
	}

	if !matches(scc.mklines.checkAllData.target, `^(?:pre|do|post)-install$`) {
		return
	}

	line := scc.mkline.Line
	switch shellcmd {
	case "${INSTALL}",
		"${INSTALL_DATA}", "${INSTALL_DATA_DIR}",
		"${INSTALL_LIB}", "${INSTALL_LIB_DIR}",
		"${INSTALL_MAN}", "${INSTALL_MAN_DIR}",
		"${INSTALL_PROGRAM}", "${INSTALL_PROGRAM_DIR}",
		"${INSTALL_SCRIPT}",
		"${LIBTOOL}",
		"${LN}",
		"${PAX}":
		return

	case "sed", "${SED}",
		"tr", "${TR}":
		// TODO: Pkglint should not complain when sed and tr are used to transform filenames.
		line.Warnf("The shell command %q should not be used in the install phase.", shellcmd)
		line.Explain(
			"In the install phase, the only thing that should be done is to",
			"install the prepared files to their final location.",
			"The file's contents should not be changed anymore.")

	case "cp", "${CP}":
		line.Warnf("${CP} should not be used to install files.")
		line.Explain(
			"The ${CP} command is highly platform dependent and cannot overwrite read-only files.",
			"Please use ${PAX} instead.",
			"",
			"For example, instead of:",
			"\t${CP} -R ${WRKSRC}/* ${PREFIX}/foodir",
			"use:",
			"\tcd ${WRKSRC} && ${PAX} -wr * ${PREFIX}/foodir")
	}
}

func (scc *SimpleCommandChecker) handleForbiddenCommand() bool {
	if trace.Tracing {
		defer trace.Call0()()
	}

	shellword := scc.strcmd.Name
	switch path.Base(shellword) {
	case "mktexlsr", "texconfig":
		scc.Errorf("%q must not be used in Makefiles.", shellword)
		scc.Explain(
			"This command may only appear in INSTALL scripts, not in the package Makefile,",
			"so that the package also works if it is installed as a binary package.")
		return true
	}
	return false
}

// handleTool tests whether the shell command is one of the recognized pkgsrc tools
// and whether the package has added it to USE_TOOLS.
func (scc *SimpleCommandChecker) handleTool() bool {
	if trace.Tracing {
		defer trace.Call0()()
	}

	command := scc.strcmd.Name

	tool, usable := G.Tool(scc.mklines, command, scc.time)

	if tool != nil && !usable {
		scc.mkline.Warnf("The %q tool is used but not added to USE_TOOLS.", command)
	}

	if tool != nil && tool.MustUseVarForm && !containsVarUse(command) {
		scc.mkline.Warnf("Please use \"${%s}\" instead of %q.", tool.Varname, command)
	}

	return tool != nil
}

func (scc *SimpleCommandChecker) handleCommandVariable() bool {
	if trace.Tracing {
		defer trace.Call0()()
	}

	shellword := scc.strcmd.Name
	varuse := NewMkLexer(shellword, nil).VarUse()
	if varuse == nil {
		return false
	}

	varname := varuse.varname

	vartype := G.Pkgsrc.VariableType(scc.mklines, varname)
	if vartype != nil && (vartype.basicType == BtShellCommand || vartype.basicType == BtPathname) {
		scc.checkInstallCommand(shellword)
		return true
	}

	// When the package author has explicitly defined a command
	// variable, assume it to be valid.
	if scc.mklines.allVars.IsDefinedSimilar(varname) {
		return true
	}

	return scc.mklines.pkg != nil && scc.mklines.pkg.vars.IsDefinedSimilar(varname)
}

func (scc *SimpleCommandChecker) handleShellBuiltin() bool {
	switch scc.strcmd.Name {
	case ":", "break", "cd", "continue", "eval", "exec", "exit", "export", "read", "set", "shift", "umask", "unset":
		return true
	}
	return false
}

func (scc *SimpleCommandChecker) checkRegexReplace() {
	if trace.Tracing {
		defer trace.Call0()()
	}

	if !G.Testing {
		return
	}

	checkArg := func(arg string) {
		if matches(arg, `^["'].*["']$`) {
			return
		}

		// Substitution commands that consist only of safe characters cannot
		// have any side effects, therefore they don't need to be quoted.
		if matches(arg, `^([\w,.]|\\.)+$`) {
			return
		}

		scc.Warnf("Substitution commands like %q should always be quoted.", arg)
		scc.Explain(
			"Usually these substitution commands contain characters like '*' or",
			"other shell metacharacters that might lead to lookup of matching",
			"filenames and then expand to more than one word.")
	}

	checkArgAfter := func(opt string) {
		args := scc.strcmd.Args
		for i, arg := range args {
			if i > 0 && args[i-1] == opt {
				checkArg(arg)
			}
		}
	}

	switch scc.strcmd.Name {
	case "${PAX}", "pax":
		checkArgAfter("-s")
	case "${SED}", "sed":
		checkArgAfter("-e")
	}
}

func (scc *SimpleCommandChecker) checkAutoMkdirs() {
	if trace.Tracing {
		defer trace.Call0()()
	}

	cmdname := scc.strcmd.Name
	switch {
	case cmdname == "${MKDIR}":
		break
	case cmdname == "${INSTALL}" && scc.strcmd.HasOption("-d"):
		cmdname = "${INSTALL} -d"
	case matches(cmdname, `^\$\{INSTALL_.*_DIR\}$`):
		// TODO: Replace regex with proper VarUse.
		break
	default:
		return
	}

	containsIgnoredVar := func(arg string) bool {
		for _, token := range scc.mkline.Tokenize(arg, false) {
			if token.Varuse != nil && matches(token.Varuse.varname, `^[_.]*[a-z]`) {
				return true
			}
		}
		return false
	}

	for _, arg := range scc.strcmd.Args {
		if contains(arg, "$$") || containsIgnoredVar(arg) {
			continue
		}

		m, dirname := match1(arg, `^(?:\$\{DESTDIR\})?\$\{PREFIX(?:|:Q)\}/+([^/]\S*)$`)
		if !m {
			continue
		}

		prefixRel := NewRelPathString(dirname).Clean()
		if prefixRel == "." {
			continue
		}

		autoMkdirs := false
		if scc.mklines.pkg != nil {
			plistLine := scc.mklines.pkg.Plist.Dirs[prefixRel]
			if plistLine != nil && !containsVarUse(plistLine.Text) {
				autoMkdirs = true
			}
		}

		if autoMkdirs {
			scc.Notef("You can use AUTO_MKDIRS=yes or \"INSTALLATION_DIRS+= %s\" instead of %q.",
				prefixRel.String(), cmdname)
			scc.Explain(
				"Many packages include a list of all needed directories in their",
				"PLIST file.",
				"In such a case, you can just set AUTO_MKDIRS=yes and be done.",
				"The pkgsrc infrastructure will then create all directories in advance.",
				"",
				"To create directories that are not mentioned in the PLIST file,",
				"it is easier to just list them in INSTALLATION_DIRS than to execute the",
				"commands explicitly.",
				"That way, you don't have to think about which",
				"of the many INSTALL_*_DIR variables is appropriate, since",
				"INSTALLATION_DIRS takes care of that.")
		} else {
			scc.Notef("You can use \"INSTALLATION_DIRS+= %s\" instead of %q.",
				prefixRel.String(), cmdname)
			scc.Explain(
				"To create directories during installation, it is easier to just",
				"list them in INSTALLATION_DIRS than to execute the commands",
				"explicitly.",
				"That way, you don't have to think about which",
				"of the many INSTALL_*_DIR variables is appropriate,",
				"since INSTALLATION_DIRS takes care of that.")
		}
	}
}

func (scc *SimpleCommandChecker) checkInstallMulti() {
	if trace.Tracing {
		defer trace.Call0()()
	}

	cmd := scc.strcmd

	if hasPrefix(cmd.Name, "${INSTALL_") && hasSuffix(cmd.Name, "_DIR}") {
		prevdir := ""
		for i, arg := range cmd.Args {
			switch {
			case hasPrefix(arg, "-"):
				break
			case i > 0 && (cmd.Args[i-1] == "-m" || cmd.Args[i-1] == "-o" || cmd.Args[i-1] == "-g"):
				break
			default:
				if prevdir != "" {
					scc.mkline.Warnf("The INSTALL_*_DIR commands can only handle one directory at a time.")
					scc.mkline.Explain(
						"Many implementations of install(1) can handle more, but pkgsrc aims",
						"at maximum portability.")
					return
				}
				prevdir = arg
			}
		}
	}
}

func (scc *SimpleCommandChecker) checkPaxPe() {
	if trace.Tracing {
		defer trace.Call0()()
	}

	if (scc.strcmd.Name == "${PAX}" || scc.strcmd.Name == "pax") && scc.strcmd.HasOption("-pe") {
		scc.Warnf("Please use the -pp option to pax(1) instead of -pe.")
		scc.Explain(
			"The -pe option tells pax to preserve the ownership of the files.",
			"",
			"When extracting distfiles as root user, this means that whatever numeric uid was",
			"used by the upstream package will also appear in the filesystem during the build.",
			"",
			"The {pre,do,post}-install targets are usually run as root.",
			"When pax -pe is used in these targets, this means that the installed files will",
			"belong to the user that has built the package.")
	}
}

func (scc *SimpleCommandChecker) checkEchoN() {
	if trace.Tracing {
		defer trace.Call0()()
	}

	if scc.strcmd.Name == "${ECHO}" && scc.strcmd.HasOption("-n") {
		scc.Warnf("Please use ${ECHO_N} instead of \"echo -n\".")
	}
}

func (scc *SimpleCommandChecker) Errorf(format string, args ...interface{}) {
	scc.mkline.Errorf(format, args...)
}
func (scc *SimpleCommandChecker) Warnf(format string, args ...interface{}) {
	scc.mkline.Warnf(format, args...)
}
func (scc *SimpleCommandChecker) Notef(format string, args ...interface{}) {
	scc.mkline.Notef(format, args...)
}
func (scc *SimpleCommandChecker) Explain(explanation ...string) {
	scc.mkline.Explain(explanation...)
}

// ShellLineChecker checks either a line from a Makefile starting with a tab,
// thereby containing shell commands to be executed.
//
// Or it checks a variable assignment line from a Makefile with a left-hand
// side variable that is of some shell-like type; see Vartype.IsShell.
type ShellLineChecker struct {
	MkLines *MkLines
	mkline  *MkLine

	// checkVarUse is set to false when checking a single shell word
	// in order to skip duplicate warnings in variable assignments.
	checkVarUse bool
}

func (ck *ShellLineChecker) checkConditionalCd(list *MkShList) {
	if trace.Tracing {
		defer trace.Call0()()
	}

	getSimple := func(list *MkShList) *MkShSimpleCommand {
		if len(list.AndOrs) == 1 {
			if len(list.AndOrs[0].Pipes) == 1 {
				if len(list.AndOrs[0].Pipes[0].Cmds) == 1 {
					return list.AndOrs[0].Pipes[0].Cmds[0].Simple
				}
			}
		}
		return nil
	}

	checkConditionalCd := func(cmd *MkShSimpleCommand) {
		if NewStrCommand(cmd).Name == "cd" {
			ck.Errorf("The Solaris /bin/sh cannot handle \"cd\" inside conditionals.")
			ck.Explain(
				"When the Solaris shell is in \"set -e\" mode and \"cd\" fails, the",
				"shell will exit, no matter if it is protected by an \"if\" or the",
				"\"||\" operator.")
		}
	}

	// TODO: It might be worth reversing the logic, like this:
	//  walker.Callback.Simple = { if inside if.cond || loop.cond { ... } }
	walker := NewMkShWalker()
	walker.Callback.If = func(ifClause *MkShIf) {
		for _, cond := range ifClause.Conds {
			if simple := getSimple(cond); simple != nil {
				checkConditionalCd(simple)
			}
		}
	}
	walker.Callback.Loop = func(loop *MkShLoop) {
		if simple := getSimple(loop.Cond); simple != nil {
			checkConditionalCd(simple)
		}
	}
	walker.Callback.Pipeline = func(pipeline *MkShPipeline) {
		if pipeline.Negated {
			ck.Warnf("The Solaris /bin/sh does not support negation of shell commands.")
			ck.Explain(
				"The GNU Autoconf manual has many more details of what shell",
				"features to avoid for portable programs.",
				"It can be read at:",
				"https://www.gnu.org/software/autoconf/manual/autoconf.html#Limitations-of-Builtins")
		}
	}
	walker.Walk(list)
}

func (ck *ShellLineChecker) checkSetE(list *MkShList, index int) {
	if trace.Tracing {
		defer trace.Call0()()
	}

	command := list.AndOrs[index-1].Pipes[0].Cmds[0]
	if command.Simple == nil || !ck.canFail(command) {
		return
	}

	line := ck.mkline.Line
	if !line.once.FirstTime("switch to set -e") {
		return
	}

	line.Warnf("Please switch to \"set -e\" mode before using a semicolon (after %q) to separate commands.",
		NewStrCommand(command.Simple).String())
	line.Explain(
		"Normally, when a shell command fails (returns non-zero),",
		"the remaining commands are still executed.",
		"For example, the following commands would remove",
		"all files from the HOME directory:",
		"",
		"\tcd \"$HOME\"; cd /nonexistent; rm -rf *",
		"",
		"In \"set -e\" mode, the shell stops when a command fails.",
		"",
		"To fix this warning, you can:",
		"",
		"* insert ${RUN} at the beginning of the line",
		"  (which among other things does \"set -e\")",
		"* insert \"set -e\" explicitly at the beginning of the line",
		"* use \"&&\" instead of \";\" to separate the commands")
}

// canFail returns true if the given shell command can fail.
// Most shell commands can fail for various reasons, such as missing
// files or invalid arguments.
//
// Commands that can fail:
//  echo "hello" > file
//  sed 's,$, world,,' < input > output
//  find . -print
//  wc -l *
//
// Commands that cannot fail:
//  echo "hello"
//  sed 's,$, world,,'
//  wc -l
func (ck *ShellLineChecker) canFail(cmd *MkShCommand) bool {
	simple := cmd.Simple
	if simple == nil {
		return true
	}

	if simple.Name == nil {
		for _, assignment := range simple.Assignments {
			text := assignment.MkText
			if contains(text, "`") || contains(text, "$(") {
				if !contains(text, "|| ${TRUE}") && !contains(text, "|| true") {
					return true
				}
			}
		}
		return false
	}

	for _, redirect := range simple.Redirections {
		if !hasSuffix(redirect.Op, "&") {
			return true
		}
	}

	cmdName := simple.Name.MkText
	switch cmdName {
	case "${ECHO_MSG}", "${PHASE_MSG}", "${STEP_MSG}",
		"${INFO_MSG}", "${WARNING_MSG}", "${ERROR_MSG}",
		"${WARNING_CAT}", "${ERROR_CAT}",
		"${DO_NADA}":
		return false
	case "${FAIL_MSG}":
		return true
	case "set":
	}

	tool, _ := G.Tool(ck.MkLines, cmdName, RunTime)
	if tool == nil {
		return true
	}

	toolName := tool.Name
	args := simple.Args
	argc := len(args)
	switch toolName {
	case "basename", "dirname", "echo", "env", "printf", "tr":
		return false
	case "sed", "gsed":
		if argc == 2 && args[0].MkText == "-e" {
			return false
		}
		return argc != 1
	case "grep", "ggrep":
		return argc != 1
	}

	return true
}

func (ck *ShellLineChecker) checkPipeExitcode(pipeline *MkShPipeline) {
	if trace.Tracing {
		defer trace.Call0()()
	}

	canFail := func() (bool, string) {
		for _, cmd := range pipeline.Cmds[:len(pipeline.Cmds)-1] {
			if ck.canFail(cmd) {
				if cmd.Simple != nil && cmd.Simple.Name != nil {
					return true, cmd.Simple.Name.MkText
				}
				return true, ""
			}
		}
		return false, ""
	}

	if G.WarnExtra && len(pipeline.Cmds) > 1 {
		if canFail, cmd := canFail(); canFail {
			if cmd != "" {
				ck.Warnf("The exitcode of %q at the left of the | operator is ignored.", cmd)
			} else {
				ck.Warnf("The exitcode of the command at the left of the | operator is ignored.")
			}
			ck.Explain(
				"In a shell command like \"cat *.txt | grep keyword\", if the command",
				"on the left side of the \"|\" fails, this failure is ignored.",
				"",
				"If you need to detect the failure of the left-hand-side command, use",
				"temporary files to save the output of the command.",
				"A good place to create those files is in ${WRKDIR}.")
		}
	}
}

var shellCommandsType = NewVartype(BtShellCommands, NoVartypeOptions, NewACLEntry("*", aclpAllRuntime))

var shellCommandsVuc = &VarUseContext{shellCommandsType, VucUnknownTime, VucQuotPlain, false}

func NewShellLineChecker(mklines *MkLines, mkline *MkLine) *ShellLineChecker {
	assertNotNil(mklines)
	return &ShellLineChecker{mklines, mkline, true}
}

// CheckShellCommands checks for a list of shell commands, of which each one
// is terminated with a semicolon. These are used in GENERATE_PLIST.
func (ck *ShellLineChecker) CheckShellCommands(shellcmds string, time ToolTime) {
	setE := true
	ck.CheckShellCommand(shellcmds, &setE, time)
	if !hasSuffix(shellcmds, ";") {
		ck.mkline.Warnf("This shell command list should end with a semicolon.")
	}
}

func (ck *ShellLineChecker) CheckShellCommandLine(shelltext string) {
	if trace.Tracing {
		defer trace.Call1(shelltext)()
	}

	line := ck.mkline.Line

	// TODO: Add sed and mv in addition to ${SED} and ${MV}.
	// TODO: Now that a shell command parser is available, be more precise in the condition.
	if contains(shelltext, "${SED}") && contains(shelltext, "${MV}") {
		line.Notef("Please use the SUBST framework instead of ${SED} and ${MV}.")
		line.Explain(
			"Using the SUBST framework instead of explicit commands is easier",
			"to understand, since all the complexity of using sed and mv is",
			"hidden behind the scenes.",
			"",
			sprintf("Run %q for more information.", bmakeHelp("subst")))
		if contains(shelltext, "#") {
			line.Explain(
				"When migrating to the SUBST framework, pay attention to \"#\" characters.",
				"In shell commands, make(1) does not interpret them as",
				"comment character, but in variable assignments it does.",
				"Therefore, instead of the shell command",
				"",
				"\tsed -e 's,#define foo,,'",
				"",
				"you need to write",
				"",
				"\tSUBST_SED.foo+=\t's,\\#define foo,,'")
		}
	}

	lexer := textproc.NewLexer(shelltext)
	lexer.NextHspace()
	hiddenAndSuppress := lexer.NextBytesFunc(func(b byte) bool { return b == '-' || b == '@' })
	if hiddenAndSuppress != "" {
		ck.checkHiddenAndSuppress(hiddenAndSuppress, lexer.Rest())
	}
	setE := lexer.SkipString("${RUN}")
	if !setE {
		if lexer.NextString("${_PKG_SILENT}${_PKG_DEBUG}") != "" {
			line.Errorf("Use of _PKG_SILENT and _PKG_DEBUG is obsolete. Use ${RUN} instead.")
		}
	}
	lexer.SkipHspace()
	lexer.SkipString("${_ULIMIT_CMD}") // It brings its own semicolon, just like ${RUN}.

	ck.CheckShellCommand(lexer.Rest(), &setE, RunTime)
	ck.checkMultiLineComment()
}

func (ck *ShellLineChecker) checkHiddenAndSuppress(hiddenAndSuppress, rest string) {
	if trace.Tracing {
		defer trace.Call(hiddenAndSuppress, rest)()
	}

	switch {
	case !contains(hiddenAndSuppress, "@"):
		// Nothing is hidden at all.

	case hasPrefix(ck.MkLines.checkAllData.target, "show-"),
		hasSuffix(ck.MkLines.checkAllData.target, "-message"):
		// In these targets, all commands may be hidden.

	case hasPrefix(rest, "#"):
		// Shell comments may be hidden, since they cannot have side effects.

	default:
		tokens, _ := splitIntoShellTokens(ck.mkline.Line, rest)
		if len(tokens) > 0 {
			cmd := tokens[0]
			switch cmd {
			case "${DELAYED_ERROR_MSG}", "${DELAYED_WARNING_MSG}",
				"${DO_NADA}",
				"${ECHO}", "${ECHO_MSG}", "${ECHO_N}", "${ERROR_CAT}", "${ERROR_MSG}",
				"${FAIL_MSG}",
				"${INFO_MSG}",
				"${PHASE_MSG}", "${PRINTF}",
				"${SHCOMMENT}", "${STEP_MSG}",
				"${WARNING_CAT}", "${WARNING_MSG}":
				break
			default:
				ck.mkline.Warnf("The shell command %q should not be hidden.", cmd)
				ck.mkline.Explain(
					"Hidden shell commands do not appear on the terminal",
					"or in the log file when they are executed.",
					"When they fail, the error message cannot be related to the command,",
					"which makes debugging more difficult.",
					"",
					"It is better to insert ${RUN} at the beginning of the whole command line.",
					"This will hide the command by default but shows it when PKG_DEBUG_LEVEL is set.")
			}
		}
	}

	if contains(hiddenAndSuppress, "-") {
		ck.mkline.Warnf("Using a leading \"-\" to suppress errors is deprecated.")
		ck.mkline.Explain(
			"If you really want to ignore any errors from this command, append \"|| ${TRUE}\" to the command.",
			"This is more visible than a single hyphen, and it should be.")
	}
}

func (ck *ShellLineChecker) CheckShellCommand(shellcmd string, pSetE *bool, time ToolTime) {
	if trace.Tracing {
		defer trace.Call0()()
	}

	line := ck.mkline.Line
	program, err := parseShellProgram(line, shellcmd)
	// XXX: This code is duplicated in checkWordQuoting.
	if err != nil && contains(shellcmd, "$$(") { // Hack until the shell parser can handle subshells.
		line.Warnf("Invoking subshells via $(...) is not portable enough.")
		return
	}
	if err != nil {
		line.Warnf("Pkglint ShellLine.CheckShellCommand: %s", err)
		return
	}

	ck.checkConditionalCd(program)

	walker := NewMkShWalker()
	walker.Callback.SimpleCommand = func(command *MkShSimpleCommand) {
		scc := NewSimpleCommandChecker(command, time, ck.mkline, ck.MkLines)
		scc.Check()
		// TODO: Implement getopt parsing for StrCommand.
		if scc.strcmd.Name == "set" && scc.strcmd.AnyArgMatches(`^-.*e`) {
			*pSetE = true
		}
	}
	walker.Callback.AndOr = func(andor *MkShAndOr) {
		if G.WarnExtra && !*pSetE && walker.Current().Index != 0 {
			ck.checkSetE(walker.Parent(1).(*MkShList), walker.Current().Index)
		}
	}
	walker.Callback.Pipeline = func(pipeline *MkShPipeline) {
		ck.checkPipeExitcode(pipeline)
	}
	walker.Callback.Word = func(word *ShToken) {
		// TODO: Try to replace false with true here; it had been set to false
		//  in 2016 for no apparent reason.
		ck.CheckWord(word.MkText, false, time)
	}

	walker.Walk(program)
}

func (ck *ShellLineChecker) CheckWord(token string, checkQuoting bool, time ToolTime) {
	if trace.Tracing {
		defer trace.Call(token, checkQuoting)()
	}

	if token == "" {
		return
	}

	var line = ck.mkline.Line

	// Delegate check for shell words consisting of a single variable use
	// to the MkLineChecker. Examples for these are ${VAR:Mpattern} or $@.
	if varuse := ToVarUse(token); varuse != nil {
		if ck.checkVarUse {
			varUseChecker := NewMkVarUseChecker(varuse, ck.MkLines, ck.mkline)
			varUseChecker.Check(shellCommandsVuc)
		}
		return
	}

	if matches(token, `\$\{PREFIX\}/man(?:$|/)`) {
		line.Warnf("Please use ${PKGMANDIR} instead of \"man\".")
	}

	if contains(token, "etc/rc.d") {
		line.Warnf("Please use the RCD_SCRIPTS mechanism to install rc.d scripts automatically to ${RCD_SCRIPTS_EXAMPLEDIR}.")
	}

	ck.checkWordQuoting(token, checkQuoting, time)
}

func (ck *ShellLineChecker) checkWordQuoting(token string, checkQuoting bool, time ToolTime) {
	tok := NewShTokenizer(ck.mkline.Line, token)

	atoms := tok.ShAtoms()
	quoting := shqPlain
outer:
	for len(atoms) > 0 {
		atom := atoms[0]
		// Cutting off the first atom is done at the end of the loop since in
		// some cases the called methods need to see the current atom.

		if trace.Tracing {
			trace.Stepf("shell state %s: %q", quoting, atom)
		}

		switch {
		case atom.Quoting == shqBackt || atom.Quoting == shqDquotBackt:
			backtCommand := ck.unescapeBackticks(&atoms, quoting)
			if backtCommand != "" {
				// TODO: Wrap the setE into a struct.
				setE := true
				ck.CheckShellCommand(backtCommand, &setE, time)
			}
			continue

			// Make(1) variables have the same syntax, no matter in which state the shell parser is currently.
		case ck.checkVaruseToken(&atoms, quoting):
			continue

		case quoting == shqPlain:
			switch {
			case atom.Type == shtShVarUse:
				ck.checkShVarUsePlain(atom, checkQuoting)

			case atom.Type == shtSubshell:
				ck.Warnf("Invoking subshells via $(...) is not portable enough.")
				ck.Explain(
					"The Solaris /bin/sh does not know this way to execute a command in a subshell.",
					"Please use backticks (`...`) as a replacement.")

				// Early return to avoid further parse errors.
				// As of December 2018, it might be worth continuing again since the
				// shell parser has improved in 2018.
				return

			case atom.Type == shtText:
				break

			default:
				break outer
			}
		}

		quoting = atom.Quoting
		atoms = atoms[1:]
	}

	if trimHspace(tok.Rest()) != "" {
		ck.Warnf("Internal pkglint error in ShellLine.CheckWord at %q (quoting=%s), rest: %s",
			token, quoting.String(), tok.Rest())
	}
}

// unescapeBackticks takes a backticks expression like `echo \\"hello\\"` and
// returns the part inside the backticks, removing one level of backslashes.
//
// Backslashes are only removed before a dollar, a backslash or a backtick.
// Other backslashes generate a warning since it is easier to remember that
// all backslashes are unescaped.
//
// See http://www.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html#tag_02_06_03
func (ck *ShellLineChecker) unescapeBackticks(atoms *[]*ShAtom, quoting ShQuoting) string {
	line := ck.mkline.Line

	// Skip the initial backtick.
	*atoms = (*atoms)[1:]

	var unescaped strings.Builder
	for len(*atoms) > 0 {
		atom := (*atoms)[0]
		*atoms = (*atoms)[1:]

		if atom.Quoting == quoting {
			return unescaped.String()
		}

		if atom.Type != shtText {
			unescaped.WriteString(atom.MkText)
			continue
		}

		lex := textproc.NewLexer(atom.MkText)
		for !lex.EOF() {
			unescaped.WriteString(lex.NextBytesFunc(func(b byte) bool { return b != '\\' }))
			if lex.SkipByte('\\') {
				switch lex.PeekByte() {
				case '"', '\\', '`', '$':
					unescaped.WriteByte(byte(lex.PeekByte()))
					lex.Skip(1)
				default:
					line.Warnf("Backslashes should be doubled inside backticks.")
					unescaped.WriteByte('\\')
				}
			}
		}

		// XXX: The regular expression is a bit cheated but is good enough until
		//  pkglint has a real parser for all shell constructs.
		if atom.Quoting == shqDquotBackt && matches(atom.MkText, `(^|[^\\])"`) {
			line.Warnf("Double quotes inside backticks inside double quotes are error prone.")
			line.Explain(
				"According to the SUSv3, they produce undefined results.",
				"",
				"See the paragraph starting \"Within the backquoted ...\" in",
				"http://www.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html.",
				"",
				"To avoid this uncertainty, escape the double quotes using \\\".")
		}
	}

	line.Errorf("Unfinished backticks after %q.", unescaped.String())
	return unescaped.String()
}

func (ck *ShellLineChecker) checkShVarUsePlain(atom *ShAtom, checkQuoting bool) {
	shVarname := atom.ShVarname()

	if shVarname == "@" {
		ck.Warnf("The $@ shell variable should only be used in double quotes.")

	} else if G.WarnQuoting && checkQuoting && ck.variableNeedsQuoting(shVarname) {
		ck.Warnf("Unquoted shell variable %q.", shVarname)
		ck.Explain(
			"When a shell variable contains whitespace, it is expanded (split into multiple words)",
			"when it is written as $variable in a shell script.",
			"If that is not intended, it should be surrounded by quotation marks, like \"$variable\".",
			"This way it always expands to a single word, preserving all whitespace and other special characters.",
			"",
			"Example:",
			"\tfname=\"Curriculum vitae.doc\"",
			"\tcp $filename /tmp",
			"\t# tries to copy the two files \"Curriculum\" and \"Vitae.doc\"",
			"",
			"\tcp \"$filename\" /tmp",
			"\t# copies one file, as intended")
	}

	if shVarname == "?" {
		ck.Warnf("The $? shell variable is often not available in \"set -e\" mode.")
		// TODO: Explain how to properly fix this warning.
		// TODO: Make sure the warning is only shown when applicable.
	}
}

func (ck *ShellLineChecker) variableNeedsQuoting(shVarname string) bool {
	switch shVarname {
	case "#", "?", "$":
		return false // Definitely ok
	case "d", "f", "i", "id", "file", "src", "dst", "prefix":
		return false // Probably ok
	}
	return !hasSuffix(shVarname, "dir") // Probably ok
}

func (ck *ShellLineChecker) checkVaruseToken(atoms *[]*ShAtom, quoting ShQuoting) bool {
	varuse := (*atoms)[0].VarUse()
	if varuse == nil {
		return false
	}

	*atoms = (*atoms)[1:]
	varname := varuse.varname

	if varname == "@" {
		// No autofix here since it may be a simple typo.
		// Maybe the package developer meant the shell variable instead.
		ck.Warnf("Please use \"${.TARGET}\" instead of \"$@\".")
		ck.Explain(
			"The variable $@ can easily be confused with the shell variable of",
			"the same name, which has a completely different meaning.")

		varname = ".TARGET"
		varuse = NewMkVarUse(varname, varuse.modifiers...)
	}

	switch {
	case quoting == shqPlain && varuse.IsQ():
		// Fine.

	case (quoting == shqSquot || quoting == shqDquot) && matches(varname, `^(?:.*DIR|.*FILE|.*PATH|.*_VAR|PREFIX|.*BASE|PKGNAME)$`):
		// This is ok as long as these variables don't have embedded [$\\"'`].

	case quoting != shqPlain && varuse.IsQ():
		ck.Warnf("The :Q modifier should not be used inside quotes.")
		ck.Explain(
			"The :Q modifier is intended for embedding a string into a shell program.",
			"It escapes all characters that have a special meaning in shell programs.",
			"It only works correctly when it appears outside of \"double\" or 'single'",
			"quotes or `backticks`.",
			"",
			"When it is used inside double quotes or backticks, the resulting string may",
			"contain more backslashes than intended.",
			"",
			"When it is used inside single quotes and the string contains a single quote",
			"itself, it produces syntax errors in the shell.",
			"",
			"To fix this warning, either remove the :Q or the double quotes.",
			"In most cases, it is more appropriate to remove the double quotes.",
			"",
			"A special case is for empty strings.",
			"If the empty string should be preserved as an empty string,",
			"the correct form is ${VAR:Q}'' with either leading or trailing single or double quotes.",
			"If the empty string should just be skipped,",
			"a simple ${VAR:Q} without any surrounding quotes is correct.")
	}

	if ck.checkVarUse {
		vuc := VarUseContext{shellCommandsType, VucUnknownTime, quoting.ToVarUseContext(), true}
		NewMkVarUseChecker(varuse, ck.MkLines, ck.mkline).Check(&vuc)
	}

	return true
}

func (ck *ShellLineChecker) checkMultiLineComment() {
	mkline := ck.mkline
	if !mkline.IsMultiline() || !contains(mkline.Text, "#") {
		return
	}

	for rawIndex, rawLine := range mkline.raw[:len(mkline.raw)-1] {
		text := strings.TrimSuffix(mkline.RawText(rawIndex), "\\")
		tokens, rest := splitIntoShellTokens(nil, text)
		if rest != "" {
			return
		}

		for _, token := range tokens {
			if hasPrefix(token, "#") {
				ck.warnMultiLineComment(rawIndex, rawLine)
				return
			}
		}
	}
}

func (ck *ShellLineChecker) warnMultiLineComment(rawIndex int, raw *RawLine) {
	line := ck.mkline.Line
	singleLine := NewLine(
		line.Filename(),
		line.Location.Lineno(rawIndex),
		line.RawText(rawIndex),
		raw)

	singleLine.Warnf("The shell comment does not stop at the end of this line.")
	singleLine.Explain(
		"When a shell command is spread out on multiple lines that are",
		"continued with a backslash, they will nevertheless be converted to",
		"a single line before the shell sees them.",
		"",
		"This means that even if it looks as if the comment only spanned",
		"one line in the Makefile, in fact it spans until the end of the whole",
		"shell command.",
		"",
		"To insert a comment into shell code, you can write it like this:",
		"",
		"\t${SHCOMMENT} \"The following command might fail; this is ok.\"",
		"",
		"Note that any special characters in the comment are still",
		"interpreted by the shell.",
		"",
		"If that is not possible, you can apply the :D modifier to the",
		"variable with the empty name, which is guaranteed to be undefined:",
		"",
		"\t${:D this is commented out}")
}

func (ck *ShellLineChecker) Errorf(format string, args ...interface{}) {
	ck.mkline.Errorf(format, args...)
}

func (ck *ShellLineChecker) Warnf(format string, args ...interface{}) {
	ck.mkline.Warnf(format, args...)
}

func (ck *ShellLineChecker) Explain(explanation ...string) {
	ck.mkline.Explain(explanation...)
}

// Example: "word1 word2;;;" => "word1", "word2", ";;", ";"
//
// TODO: Document what this function should be used for.
func splitIntoShellTokens(line Autofixer, text string) (tokens []string, rest string) {
	if trace.Tracing {
		defer trace.Call(line, text)()
	}

	// TODO: Check whether this function is used correctly by all callers.
	//  It may be better to use a proper shell parser instead of this tokenizer.

	p := NewShTokenizer(line, text)
	for {
		token := p.ShToken()
		if token == nil {
			break
		}
		tokens = append(tokens, token.MkText)
	}

	rest = p.parser.Rest()

	return
}
