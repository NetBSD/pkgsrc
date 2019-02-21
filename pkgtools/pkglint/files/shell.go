package pkglint

// Parsing and checking shell commands embedded in Makefiles

import (
	"netbsd.org/pkglint/textproc"
	"path"
	"strings"
)

// TODO: Can ShellLine and ShellProgramChecker be merged into one type?

// ShellLine is either a line from a Makefile starting with a tab,
// thereby containing shell commands to be executed.
//
// Or it is a variable assignment line from a Makefile with a left-hand
// side variable that is of some shell-like type; see Vartype.IsShell.
type ShellLine struct {
	mkline MkLine
}

func NewShellLine(mkline MkLine) *ShellLine {
	return &ShellLine{mkline}
}

var shellCommandsType = &Vartype{lkNone, BtShellCommands, []ACLEntry{{"*", aclpAllRuntime}}, false}
var shellWordVuc = &VarUseContext{shellCommandsType, vucTimeUnknown, VucQuotPlain, false}

func (shline *ShellLine) CheckWord(token string, checkQuoting bool, time ToolTime) {
	if trace.Tracing {
		defer trace.Call(token, checkQuoting)()
	}

	if token == "" || hasPrefix(token, "#") {
		return
	}

	var line = shline.mkline.Line

	// Delegate check for shell words consisting of a single variable use
	// to the MkLineChecker. Examples for these are ${VAR:Mpattern} or $@.
	p := NewMkParser(nil, token, false)
	if varuse := p.VarUse(); varuse != nil && p.EOF() {
		MkLineChecker{shline.mkline}.CheckVaruse(varuse, shellWordVuc)
		return
	}

	if matches(token, `\$\{PREFIX\}/man(?:$|/)`) {
		line.Warnf("Please use ${PKGMANDIR} instead of \"man\".")
	}

	if contains(token, "etc/rc.d") {
		line.Warnf("Please use the RCD_SCRIPTS mechanism to install rc.d scripts automatically to ${RCD_SCRIPTS_EXAMPLEDIR}.")
	}

	shline.checkWordQuoting(token, checkQuoting, time)
}

func (shline *ShellLine) checkWordQuoting(token string, checkQuoting bool, time ToolTime) {
	line := shline.mkline.Line
	tok := NewShTokenizer(line, token, false)

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
			backtCommand := shline.unescapeBackticks(&atoms, quoting)
			if backtCommand != "" {
				// TODO: Wrap the setE into a struct.
				setE := true
				shline.CheckShellCommand(backtCommand, &setE, time)
			}
			continue

			// Make(1) variables have the same syntax, no matter in which state the shell parser is currently.
		case shline.checkVaruseToken(&atoms, quoting):
			continue

		case quoting == shqPlain:
			switch {
			case atom.Type == shtShVarUse:
				shline.checkShVarUsePlain(atom, checkQuoting)

			case atom.Type == shtSubshell:
				line.Warnf("Invoking subshells via $(...) is not portable enough.")
				G.Explain(
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
		line.Warnf("Internal pkglint error in ShellLine.CheckWord at %q (quoting=%s), rest: %s",
			token, quoting, tok.Rest())
	}
}

func (shline *ShellLine) checkShVarUsePlain(atom *ShAtom, checkQuoting bool) {
	line := shline.mkline.Line
	shVarname := atom.ShVarname()

	if shVarname == "@" {
		line.Warnf("The $@ shell variable should only be used in double quotes.")

	} else if G.Opts.WarnQuoting && checkQuoting && shline.variableNeedsQuoting(shVarname) {
		line.Warnf("Unquoted shell variable %q.", shVarname)
		G.Explain(
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
		line.Warnf("The $? shell variable is often not available in \"set -e\" mode.")
		// TODO: Explain how to properly fix this warning.
		// TODO: Make sure the warning is only shown when applicable.
	}
}

func (shline *ShellLine) checkVaruseToken(atoms *[]*ShAtom, quoting ShQuoting) bool {
	varuse := (*atoms)[0].VarUse()
	if varuse == nil {
		return false
	}

	*atoms = (*atoms)[1:]
	varname := varuse.varname

	if varname == "@" {
		shline.mkline.Warnf("Please use \"${.TARGET}\" instead of \"$@\".")
		G.Explain(
			"The variable $@ can easily be confused with the shell variable of",
			"the same name, which has a completely different meaning.")
		varname = ".TARGET"
		varuse = &MkVarUse{varname, varuse.modifiers}
	}

	switch {
	case quoting == shqPlain && varuse.IsQ():
		// Fine.

	case (quoting == shqSquot || quoting == shqDquot) && matches(varname, `^(?:.*DIR|.*FILE|.*PATH|.*_VAR|PREFIX|.*BASE|PKGNAME)$`):
		// This is ok as long as these variables don't have embedded [$\\"'`].

	case quoting == shqDquot && varuse.IsQ():
		shline.mkline.Warnf("The :Q modifier should not be used inside double quotes.")
		G.Explain(
			"To fix this warning, either remove the :Q or the double quotes.",
			"In most cases, it is more appropriate to remove the double quotes.")
	}

	vuc := VarUseContext{shellCommandsType, vucTimeUnknown, quoting.ToVarUseContext(), true}
	MkLineChecker{shline.mkline}.CheckVaruse(varuse, &vuc)

	return true
}

// unescapeBackticks takes a backticks expression like `echo \\"hello\\"` and
// returns the part inside the backticks, removing one level of backslashes.
//
// Backslashes are only removed before a dollar, a backslash or a backtick.
// Other backslashes generate a warning since it is easier to remember that
// all backslashes are unescaped.
//
// See http://www.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html#tag_02_06_03
func (shline *ShellLine) unescapeBackticks(atoms *[]*ShAtom, quoting ShQuoting) string {
	line := shline.mkline.Line

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
		// pkglint has a real parser for all shell constructs.
		if atom.Quoting == shqDquotBackt && matches(atom.MkText, `(^|[^\\])"`) {
			line.Warnf("Double quotes inside backticks inside double quotes are error prone.")
			G.Explain(
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

func (shline *ShellLine) variableNeedsQuoting(shVarname string) bool {
	switch shVarname {
	case "#", "?", "$":
		return false // Definitely ok
	case "d", "f", "i", "id", "file", "src", "dst", "prefix":
		return false // Probably ok
	}
	if hasSuffix(shVarname, "dir") {
		return false // Probably ok
	}
	return true
}

func (shline *ShellLine) CheckShellCommandLine(shelltext string) {
	if trace.Tracing {
		defer trace.Call1(shelltext)()
	}

	line := shline.mkline.Line

	// TODO: Add sed and mv in addition to ${SED} and ${MV}.
	// TODO: Now that a shell command parser is available, be more precise in the condition.
	if contains(shelltext, "${SED}") && contains(shelltext, "${MV}") {
		line.Notef("Please use the SUBST framework instead of ${SED} and ${MV}.")
		G.Explain(
			"Using the SUBST framework instead of explicit commands is easier",
			"to understand, since all the complexity of using sed and mv is",
			"hidden behind the scenes.",
			"",
			// TODO: Provide a copy-and-paste example.
			sprintf("Run %q for more information.", makeHelp("subst")))
		if contains(shelltext, "#") {
			G.Explain(
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
		shline.checkHiddenAndSuppress(hiddenAndSuppress, lexer.Rest())
	}
	setE := lexer.SkipString("${RUN}")
	if !setE {
		if lexer.NextString("${_PKG_SILENT}${_PKG_DEBUG}") != "" {
			line.Warnf("Use of _PKG_SILENT and _PKG_DEBUG is deprecated. Use ${RUN} instead.")
		}
	}

	shline.CheckShellCommand(lexer.Rest(), &setE, RunTime)
}

func (shline *ShellLine) CheckShellCommand(shellcmd string, pSetE *bool, time ToolTime) {
	if trace.Tracing {
		defer trace.Call0()()
	}

	line := shline.mkline.Line
	program, err := parseShellProgram(line, shellcmd)
	// FIXME: This code is duplicated in checkWordQuoting.
	if err != nil && contains(shellcmd, "$$(") { // Hack until the shell parser can handle subshells.
		line.Warnf("Invoking subshells via $(...) is not portable enough.")
		return
	}
	if err != nil {
		line.Warnf("Pkglint ShellLine.CheckShellCommand: %s", err)
		return
	}

	spc := ShellProgramChecker{shline}
	spc.checkConditionalCd(program)

	walker := NewMkShWalker()
	walker.Callback.SimpleCommand = func(command *MkShSimpleCommand) {
		scc := NewSimpleCommandChecker(shline, command, time)
		scc.Check()
		// TODO: Implement getopt parsing for StrCommand.
		if scc.strcmd.Name == "set" && scc.strcmd.AnyArgMatches(`^-.*e`) {
			*pSetE = true
		}
	}
	walker.Callback.AndOr = func(andor *MkShAndOr) {
		if G.Opts.WarnExtra && !*pSetE && walker.Current().Index != 0 {
			spc.checkSetE(walker.Parent(1).(*MkShList), walker.Current().Index, andor)
		}
	}
	walker.Callback.Pipeline = func(pipeline *MkShPipeline) {
		spc.checkPipeExitcode(line, pipeline)
	}
	walker.Callback.Word = func(word *ShToken) {
		// TODO: Try to replace false with true here; it had been set to false
		//  in 2016 for no apparent reason.
		spc.shline.CheckWord(word.MkText, false, time)
	}

	walker.Walk(program)
}

func (shline *ShellLine) CheckShellCommands(shellcmds string, time ToolTime) {
	setE := true
	shline.CheckShellCommand(shellcmds, &setE, time)
	if !hasSuffix(shellcmds, ";") {
		shline.mkline.Warnf("This shell command list should end with a semicolon.")
	}
}

func (shline *ShellLine) checkHiddenAndSuppress(hiddenAndSuppress, rest string) {
	if trace.Tracing {
		defer trace.Call(hiddenAndSuppress, rest)()
	}

	switch {
	case !contains(hiddenAndSuppress, "@"):
		// Nothing is hidden at all.

	case hasPrefix(G.Mk.target, "show-") || hasSuffix(G.Mk.target, "-message"):
		// In these targets, all commands may be hidden.

	case hasPrefix(rest, "#"):
		// Shell comments may be hidden, since they cannot have side effects.

	default:
		tokens, _ := splitIntoShellTokens(shline.mkline.Line, rest)
		if len(tokens) > 0 {
			cmd := tokens[0]
			switch cmd {
			case "${DELAYED_ERROR_MSG}", "${DELAYED_WARNING_MSG}",
				"${DO_NADA}",
				"${ECHO}", "${ECHO_MSG}", "${ECHO_N}", "${ERROR_CAT}", "${ERROR_MSG}",
				"${FAIL_MSG}",
				"${PHASE_MSG}", "${PRINTF}",
				"${SHCOMMENT}", "${STEP_MSG}",
				"${WARNING_CAT}", "${WARNING_MSG}":
				break
			default:
				shline.mkline.Warnf("The shell command %q should not be hidden.", cmd)
				G.Explain(
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
		shline.mkline.Warnf("Using a leading \"-\" to suppress errors is deprecated.")
		G.Explain(
			"If you really want to ignore any errors from this command, append \"|| ${TRUE}\" to the command.",
			"This is more visible than a single hyphen, and it should be.")
	}
}

type SimpleCommandChecker struct {
	shline *ShellLine
	cmd    *MkShSimpleCommand
	strcmd *StrCommand
	time   ToolTime
}

func NewSimpleCommandChecker(shline *ShellLine, cmd *MkShSimpleCommand, time ToolTime) *SimpleCommandChecker {
	strcmd := NewStrCommand(cmd)
	return &SimpleCommandChecker{shline, cmd, strcmd, time}

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
	scc.shline.checkInstallCommand(shellword)

	switch {
	case shellword == "${RUN}" || shellword == "":
		// FIXME: ${RUN} must never appear as a simple command.
		//  It should always be trimmed before passing the shell program to the SimpleCommandChecker.
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
	case matches(shellword, `\$\{(PKGSRCDIR|PREFIX)(:Q)?\}`):
		break
	case scc.handleComment():
		break
	default:
		if G.Opts.WarnExtra && !(G.Mk != nil && G.Mk.indentation.DependsOn("OPSYS")) {
			scc.shline.mkline.Warnf("Unknown shell command %q.", shellword)
			G.Explain(
				"To make the package portable to all platforms that pkgsrc supports,",
				"it should only use shell commands that are covered by the tools framework.",
				"",
				"To run custom shell commands, prefix them with \"./\" or with \"${PREFIX}/\".")
		}
	}
}

// handleTool tests whether the shell command is one of the recognized pkgsrc tools
// and whether the package has added it to USE_TOOLS.
func (scc *SimpleCommandChecker) handleTool() bool {
	if trace.Tracing {
		defer trace.Call0()()
	}

	command := scc.strcmd.Name

	tool, usable := G.Tool(command, scc.time)

	if tool != nil && !usable {
		scc.shline.mkline.Warnf("The %q tool is used but not added to USE_TOOLS.", command)
	}

	if tool != nil && tool.MustUseVarForm && !containsVarRef(command) {
		scc.shline.mkline.Warnf("Please use \"${%s}\" instead of %q.", tool.Varname, command)
	}

	return tool != nil
}

func (scc *SimpleCommandChecker) handleForbiddenCommand() bool {
	if trace.Tracing {
		defer trace.Call0()()
	}

	shellword := scc.strcmd.Name
	switch path.Base(shellword) {
	case "mktexlsr", "texconfig":
		scc.shline.mkline.Errorf("%q must not be used in Makefiles.", shellword)
		G.Explain(
			"This command may only appear in INSTALL scripts, not in the package Makefile,",
			"so that the package also works if it is installed as a binary package.")
		return true
	}
	return false
}

func (scc *SimpleCommandChecker) handleCommandVariable() bool {
	if trace.Tracing {
		defer trace.Call0()()
	}

	shellword := scc.strcmd.Name
	parser := NewMkParser(nil, shellword, false)
	if varuse := parser.VarUse(); varuse != nil && parser.EOF() {
		varname := varuse.varname

		if tool := G.ToolByVarname(varname); tool != nil {
			if tool.Validity == Nowhere {
				scc.shline.mkline.Warnf("The %q tool is used but not added to USE_TOOLS.", tool.Name)
			}
			scc.shline.checkInstallCommand(shellword)
			return true
		}

		if vartype := G.Pkgsrc.VariableType(varname); vartype != nil && vartype.basicType.name == "ShellCommand" {
			scc.shline.checkInstallCommand(shellword)
			return true
		}

		// When the package author has explicitly defined a command
		// variable, assume it to be valid.
		if G.Mk != nil && G.Mk.vars.DefinedSimilar(varname) {
			return true
		}
		if G.Pkg != nil && G.Pkg.vars.DefinedSimilar(varname) {
			return true
		}
	}
	return false
}

func (scc *SimpleCommandChecker) handleShellBuiltin() bool {
	switch scc.strcmd.Name {
	case ":", "break", "cd", "continue", "eval", "exec", "exit", "export", "read", "set", "shift", "umask", "unset":
		return true
	}
	return false
}

func (scc *SimpleCommandChecker) handleComment() bool {
	if trace.Tracing {
		defer trace.Call0()()
	}

	// FIXME: Research and explain how pkglint can ever interpret
	//  a shell comment as a simple command. That just doesn't fit.

	shellword := scc.strcmd.Name
	if trace.Tracing {
		defer trace.Call1(shellword)()
	}

	if !hasPrefix(shellword, "#") {
		return false
	}

	semicolon := contains(shellword, ";")
	multiline := scc.shline.mkline.IsMultiline()

	if semicolon {
		scc.shline.mkline.Warnf("A shell comment should not contain semicolons.")
		// TODO: Explain.
		// TODO: Check whether the existing warnings are useful.
	}

	if multiline {
		scc.shline.mkline.Warnf("A shell comment does not stop at the end of line.")
	}

	if semicolon || multiline {
		G.Explain(
			"When a shell command is split into multiple lines that are",
			"continued with a backslash, they will nevertheless be converted to",
			"a single line before the shell sees them.",
			"",
			"This means that even if it looks as if the comment only spanned",
			"one line in the Makefile, in fact it spans until the end of the whole",
			"shell command.",
			"",
			"To insert a comment into shell code, you can write it like this:",
			"",
			"\t"+"${SHCOMMENT} \"The following command might fail; this is ok.\"",
			"",
			"Note that any special characters in the comment are still",
			"interpreted by the shell.")
	}
	return true
}

func (scc *SimpleCommandChecker) checkRegexReplace() {
	if trace.Tracing {
		defer trace.Call0()()
	}

	cmdname := scc.strcmd.Name
	isSubst := false
	for _, arg := range scc.strcmd.Args {
		if G.Testing && isSubst && !matches(arg, `"^[\"\'].*[\"\']$`) {
			scc.shline.mkline.Warnf("Substitution commands like %q should always be quoted.", arg)
			G.Explain(
				"Usually these substitution commands contain characters like '*' or",
				"other shell metacharacters that might lead to lookup of matching",
				"filenames and then expand to more than one word.")
		}
		isSubst = cmdname == "${PAX}" && arg == "-s" || cmdname == "${SED}" && arg == "-e"
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

	for _, arg := range scc.strcmd.Args {
		// TODO: Replace regex with proper VarUse.
		if !contains(arg, "$$") && !matches(arg, `\$\{[_.]*[a-z]`) {
			if m, dirname := match1(arg, `^(?:\$\{DESTDIR\})?\$\{PREFIX(?:|:Q)\}/(.*)`); m {
				if G.Pkg != nil && G.Pkg.Plist.Dirs[dirname] {
					scc.shline.mkline.Notef("You can use AUTO_MKDIRS=yes or \"INSTALLATION_DIRS+= %s\" instead of %q.", dirname, cmdname)
					G.Explain(
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
					scc.shline.mkline.Notef("You can use \"INSTALLATION_DIRS+= %s\" instead of %q.", dirname, cmdname)
					G.Explain(
						"To create directories during installation, it is easier to just",
						"list them in INSTALLATION_DIRS than to execute the commands",
						"explicitly.",
						"That way, you don't have to think about which",
						"of the many INSTALL_*_DIR variables is appropriate,",
						"since INSTALLATION_DIRS takes care of that.")
				}
			}
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
					scc.shline.mkline.Warnf("The INSTALL_*_DIR commands can only handle one directory at a time.")
					G.Explain(
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
		scc.shline.mkline.Warnf("Please use the -pp option to pax(1) instead of -pe.")
		G.Explain(
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
		scc.shline.mkline.Warnf("Please use ${ECHO_N} instead of \"echo -n\".")
	}
}

type ShellProgramChecker struct {
	shline *ShellLine
}

func (spc *ShellProgramChecker) checkConditionalCd(list *MkShList) {
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
			spc.shline.mkline.Errorf("The Solaris /bin/sh cannot handle \"cd\" inside conditionals.")
			G.Explain(
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
			spc.shline.mkline.Warnf("The Solaris /bin/sh does not support negation of shell commands.")
			G.Explain(
				"The GNU Autoconf manual has many more details of what shell",
				"features to avoid for portable programs.",
				"It can be read at:",
				"https://www.gnu.org/software/autoconf/manual/autoconf.html#Limitations-of-Builtins")
		}
	}
	walker.Walk(list)
}

func (spc *ShellProgramChecker) checkPipeExitcode(line Line, pipeline *MkShPipeline) {
	if trace.Tracing {
		defer trace.Call0()()
	}

	canFail := func() (bool, string) {
		for _, cmd := range pipeline.Cmds[:len(pipeline.Cmds)-1] {
			if spc.canFail(cmd) {
				if cmd.Simple != nil && cmd.Simple.Name != nil {
					return true, cmd.Simple.Name.MkText
				}
				return true, ""
			}
		}
		return false, ""
	}

	if G.Opts.WarnExtra && len(pipeline.Cmds) > 1 {
		if canFail, cmd := canFail(); canFail {
			if cmd != "" {
				line.Warnf("The exitcode of %q at the left of the | operator is ignored.", cmd)
			} else {
				line.Warnf("The exitcode of the command at the left of the | operator is ignored.")
			}
			G.Explain(
				"In a shell command like \"cat *.txt | grep keyword\", if the command",
				"on the left side of the \"|\" fails, this failure is ignored.",
				"",
				"If you need to detect the failure of the left-hand-side command, use",
				"temporary files to save the output of the command.",
				"A good place to create those files is in ${WRKDIR}.")
		}
	}
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
func (spc *ShellProgramChecker) canFail(cmd *MkShCommand) bool {
	simple := cmd.Simple
	if simple == nil {
		return true
	}

	if simple.Name == nil {
		for _, assignment := range simple.Assignments {
			if contains(assignment.MkText, "`") || contains(assignment.MkText, "$(") {
				if !contains(assignment.MkText, "|| ${TRUE}") {
					return true
				}
			}
		}
		return false
	}

	for _, redirect := range simple.Redirections {
		if redirect.Target != nil && !hasSuffix(redirect.Op, "&") {
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

	tool, _ := G.Tool(cmdName, RunTime)
	if tool == nil {
		return true
	}

	toolName := tool.Name
	args := simple.Args
	argc := len(args)
	switch toolName {
	case "echo", "env", "printf", "tr":
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

func (spc *ShellProgramChecker) checkSetE(list *MkShList, index int, andor *MkShAndOr) {
	if trace.Tracing {
		defer trace.Call0()()
	}

	command := list.AndOrs[index-1].Pipes[0].Cmds[0]
	if command.Simple == nil || !spc.canFail(command) {
		return
	}

	line := spc.shline.mkline.Line
	if !line.FirstTime("switch to set -e") {
		return
	}

	line.Warnf("Please switch to \"set -e\" mode before using a semicolon (after %q) to separate commands.",
		NewStrCommand(command.Simple).String())
	G.Explain(
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

// Some shell commands should not be used in the install phase.
func (shline *ShellLine) checkInstallCommand(shellcmd string) {
	if trace.Tracing {
		defer trace.Call0()()
	}

	if G.Mk == nil || !matches(G.Mk.target, `^(?:pre|do|post)-install$`) {
		return
	}

	line := shline.mkline.Line
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
		G.Explain(
			"In the install phase, the only thing that should be done is to",
			"install the prepared files to their final location.",
			"The file's contents should not be changed anymore.")

	case "cp", "${CP}":
		line.Warnf("${CP} should not be used to install files.")
		G.Explain(
			"The ${CP} command is highly platform dependent and cannot overwrite read-only files.",
			"Please use ${PAX} instead.",
			"",
			"For example, instead of:",
			"\t${CP} -R ${WRKSRC}/* ${PREFIX}/foodir",
			"use:",
			"\tcd ${WRKSRC} && ${PAX} -wr * ${PREFIX}/foodir")
	}
}

// Example: "word1 word2;;;" => "word1", "word2", ";;", ";"
//
// TODO: Document what this function should be used for.
func splitIntoShellTokens(line Line, text string) (tokens []string, rest string) {
	if trace.Tracing {
		defer trace.Call(line, text)()
	}

	// TODO: Check whether this function is used correctly by all callers.
	//  It may be better to use a proper shell parser instead of this tokenizer.

	word := ""
	rest = text
	p := NewShTokenizer(line, text, false)
	emit := func() {
		if word != "" {
			tokens = append(tokens, word)
			word = ""
		}
		rest = p.parser.Rest()
	}

	q := shqPlain
	var prevAtom *ShAtom
	for {
		atom := p.ShAtom(q)
		if atom == nil {
			if prevAtom == nil || prevAtom.Quoting == shqPlain {
				emit()
			}
			break
		}

		q = atom.Quoting
		prevAtom = atom
		if atom.Type == shtSpace && q == shqPlain {
			emit()
		} else if atom.Type.IsWord() || atom.Quoting != shqPlain {
			word += atom.MkText
		} else {
			emit()
			tokens = append(tokens, atom.MkText)
		}
	}

	return
}

// Example: "word1 word2;;;" => "word1", "word2;;;"
// Compare devel/bmake/files/str.c, function brk_string.
//
// TODO: Move to mkline.go or mkparser.go.
//
// TODO: Document what this function should be used for.
//
// TODO: Compare with brk_string from devel/bmake, especially for backticks.
func splitIntoMkWords(line Line, text string) (words []string, rest string) {
	if trace.Tracing {
		defer trace.Call(line, text)()
	}

	p := NewShTokenizer(line, text, false)
	atoms := p.ShAtoms()
	word := ""
	for _, atom := range atoms {
		if atom.Type == shtSpace && atom.Quoting == shqPlain {
			words = append(words, word)
			word = ""
		} else {
			word += atom.MkText
		}
	}
	if word != "" && atoms[len(atoms)-1].Quoting == shqPlain {
		words = append(words, word)
		word = ""
	}
	return words, word + p.parser.Rest()
}
