package main

// Parsing and checking shell commands embedded in Makefiles

import (
	"netbsd.org/pkglint/textproc"
	"path"
)

const (
	reShVarname      = `(?:[!#*\-\d?@]|\$\$|[A-Za-z_]\w*)`
	reShVarexpansion = `(?:(?:#|##|%|%%|:-|:=|:\?|:\+|\+)[^$\\{}]*)`
	reShVaruse       = `\$\$` + `(?:` + reShVarname + `|` + `\{` + reShVarname + `(?:` + reShVarexpansion + `)?` + `\})`
	reShDollar       = `\\\$\$|` + reShVaruse + `|\$\$[,\-/]`
)

// TODO: Can ShellLine and ShellProgramChecker be merged into one type?

type ShellLine struct {
	mkline MkLine
}

func NewShellLine(mkline MkLine) *ShellLine {
	return &ShellLine{mkline}
}

var shellcommandsContextType = &Vartype{lkNone, BtShellCommands, []ACLEntry{{"*", aclpAllRuntime}}, false}
var shellwordVuc = &VarUseContext{shellcommandsContextType, vucTimeUnknown, vucQuotPlain, false}

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
	p := NewMkParser(line, token, false)
	if varuse := p.VarUse(); varuse != nil && p.EOF() {
		MkLineChecker{shline.mkline}.CheckVaruse(varuse, shellwordVuc)
		return
	}

	if matches(token, `\$\{PREFIX\}/man(?:$|/)`) {
		line.Warnf("Please use ${PKGMANDIR} instead of \"man\".")
	}
	if contains(token, "etc/rc.d") {
		line.Warnf("Please use the RCD_SCRIPTS mechanism to install rc.d scripts automatically to ${RCD_SCRIPTS_EXAMPLEDIR}.")
	}

	parser := NewMkParser(line, token, false)
	repl := parser.repl
	quoting := shqPlain
outer:
	for !parser.EOF() {
		if trace.Tracing {
			trace.Stepf("shell state %s: %q", quoting, parser.Rest())
		}

		switch {
		// When parsing inside backticks, it is more
		// reasonable to check the whole shell command
		// recursively, instead of splitting off the first
		// make(1) variable.
		case quoting == shqBackt || quoting == shqDquotBackt:
			var backtCommand string
			backtCommand, quoting = shline.unescapeBackticks(token, repl, quoting)
			setE := true
			shline.CheckShellCommand(backtCommand, &setE, time)

			// Make(1) variables have the same syntax, no matter in which state we are currently.
		case shline.checkVaruseToken(parser, quoting):
			break

		case quoting == shqPlain:
			switch {
			// FIXME: These regular expressions don't belong here, they are the job of the tokenizer.
			case repl.AdvanceRegexp(`^[!#%&()*+,\-./0-9:;<=>?@A-Z\[\]^_a-z{|}~]+`),
				repl.AdvanceRegexp(`^\\(?:[ !"#'()*./;?\\^{|}]|\$\$)`):
			case repl.AdvanceStr("'"):
				quoting = shqSquot
			case repl.AdvanceStr("\""):
				quoting = shqDquot
			case repl.AdvanceStr("`"):
				quoting = shqBackt
			case repl.AdvanceRegexp(`^\$\$([0-9A-Z_a-z]+|#)`),
				repl.AdvanceRegexp(`^\$\$\{([0-9A-Z_a-z]+|#)\}`),
				repl.AdvanceRegexp(`^\$\$(\$)\$`):
				shvarname := repl.Group(1)
				if G.Opts.WarnQuoting && checkQuoting && shline.variableNeedsQuoting(shvarname) {
					line.Warnf("Unquoted shell variable %q.", shvarname)
					Explain(
						"When a shell variable contains white-space, it is expanded (split",
						"into multiple words) when it is written as $variable in a shell",
						"script.  If that is not intended, you should add quotation marks",
						"around it, like \"$variable\".  Then, the variable will always expand",
						"to a single word, preserving all white-space and other special",
						"characters.",
						"",
						"Example:",
						"\tfname=\"Curriculum vitae.doc\"",
						"\tcp $fileName /tmp",
						"\t# tries to copy the two files \"Curriculum\" and \"Vitae.doc\"",
						"\tcp \"$fileName\" /tmp",
						"\t# copies one file, as intended")
				}

			case repl.AdvanceStr("$$@"):
				line.Warnf("The $@ shell variable should only be used in double quotes.")

			case repl.AdvanceStr("$$?"):
				line.Warnf("The $? shell variable is often not available in \"set -e\" mode.")

			case repl.AdvanceStr("$$("):
				line.Warnf("Invoking subshells via $(...) is not portable enough.")
				Explain(
					"The Solaris /bin/sh does not know this way to execute a command in a",
					"subshell.  Please use backticks (`...`) as a replacement.")
				return // To avoid internal parse errors

			case repl.AdvanceStr("$$"): // Not part of a variable.
				break

			default:
				break outer
			}

		case quoting == shqSquot:
			switch {
			case repl.AdvanceStr("'"):
				quoting = shqPlain
			case repl.NextBytesFunc(func(b byte) bool { return b != '$' && b != '\'' }) != "":
				// just skip
			case repl.AdvanceStr("$$"):
				// just skip
			default:
				break outer
			}

		case quoting == shqDquot:
			switch {
			case repl.AdvanceStr("\""):
				quoting = shqPlain
			case repl.AdvanceStr("`"):
				quoting = shqDquotBackt
			case repl.NextBytesFunc(func(b byte) bool { return b != '$' && b != '"' && b != '\\' && b != '`' }) != "":
				break
			case repl.AdvanceStr("\\$$"):
				break
			case repl.AdvanceRegexp(`^\\.`): // See http://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html#tag_02_02_01
				break
			case repl.AdvanceRegexp(`^\$\$\{\w+[#%+\-:]*[^{}]*\}`),
				repl.AdvanceRegexp(`^\$\$(?:\w+|[!#?@]|\$\$)`):
				break
			case repl.AdvanceStr("$$"):
				line.Warnf("Unescaped $ or strange shell variable found.")
			default:
				break outer
			}
		}
	}

	if trimHspace(parser.Rest()) != "" {
		line.Warnf("Pkglint parse error in ShellLine.CheckWord at %q (quoting=%s), rest: %s", token, quoting, parser.Rest())
	}
}

func (shline *ShellLine) checkVaruseToken(parser *MkParser, quoting ShQuoting) bool {
	if trace.Tracing {
		defer trace.Call(parser.Rest(), quoting)()
	}

	varuse := parser.VarUse()
	if varuse == nil {
		return false
	}
	varname := varuse.varname

	if varname == "@" {
		shline.mkline.Warnf("Please use \"${.TARGET}\" instead of \"$@\".")
		Explain(
			"The variable $@ can easily be confused with the shell variable of",
			"the same name, which has a completely different meaning.")
		varname = ".TARGET"
		varuse = &MkVarUse{varname, varuse.modifiers}
	}

	switch {
	case quoting == shqPlain && varuse.IsQ():
		// Fine.

	case (quoting == shqSquot || quoting == shqDquot) && matches(varname, `^(?:.*DIR|.*FILE|.*PATH|.*_VAR|PREFIX|.*BASE|PKGNAME)$`):
		// This is ok if we don't allow these variables to have embedded [\$\\\"\'\`].

	case quoting == shqDquot && varuse.IsQ():
		shline.mkline.Warnf("Please don't use the :Q operator in double quotes.")
		Explain(
			"Either remove the :Q or the double quotes.  In most cases, it is",
			"more appropriate to remove the double quotes.")
	}

	if varname != "@" {
		vucstate := quoting.ToVarUseContext()
		vuc := &VarUseContext{shellcommandsContextType, vucTimeUnknown, vucstate, true}
		MkLineChecker{shline.mkline}.CheckVaruse(varuse, vuc)
	}
	return true
}

// Scan for the end of the backticks, checking for single backslashes
// and removing one level of backslashes. Backslashes are only removed
// before a dollar, a backslash or a backtick.
//
// See http://www.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html#tag_02_06_03
func (shline *ShellLine) unescapeBackticks(shellword string, repl *textproc.PrefixReplacer, quoting ShQuoting) (unescaped string, newQuoting ShQuoting) {
	if trace.Tracing {
		defer trace.Call(shellword, quoting, trace.Result(&unescaped))()
	}

	line := shline.mkline.Line
	for repl.Rest() != "" {
		switch {
		case repl.AdvanceStr("`"):
			if quoting == shqBackt {
				quoting = shqPlain
			} else {
				quoting = shqDquot
			}
			return unescaped, quoting

		case repl.AdvanceStr("\\\""), repl.AdvanceStr("\\\\"), repl.AdvanceStr("\\`"), repl.AdvanceStr("\\$"):
			unescaped += repl.Str()[1:]

		case repl.AdvanceStr("\\"):
			line.Warnf("Backslashes should be doubled inside backticks.")
			unescaped += "\\"

		case quoting == shqDquotBackt && repl.AdvanceStr("\""):
			line.Warnf("Double quotes inside backticks inside double quotes are error prone.")
			Explain(
				"According to the SUSv3, they produce undefined results.",
				"",
				"See the paragraph starting \"Within the backquoted ...\" in",
				"http://www.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html.",
				"",
				"To avoid this uncertainty, escape the double quotes using \\\".")

		default:
			G.Assertf(repl.AdvanceRegexp("^([^\\\\`]+)"), "incomplete switch")
			unescaped += repl.Group(1)
		}
	}
	line.Errorf("Unfinished backquotes: %s", repl.Rest())
	return unescaped, quoting
}

func (shline *ShellLine) variableNeedsQuoting(shvarname string) bool {
	switch shvarname {
	case "#", "?":
		return false // Definitely ok
	case "d", "f", "i", "dir", "file", "src", "dst":
		return false // Probably ok
	}
	return true
}

func (shline *ShellLine) CheckShellCommandLine(shelltext string) {
	if trace.Tracing {
		defer trace.Call1(shelltext)()
	}

	line := shline.mkline.Line

	if contains(shelltext, "${SED}") && contains(shelltext, "${MV}") {
		line.Notef("Please use the SUBST framework instead of ${SED} and ${MV}.")
		Explain(
			"Using the SUBST framework instead of explicit commands is easier",
			"to understand, since all the complexity of using sed and mv is",
			"hidden behind the scenes.",
			"",
			// TODO: Provide a copy-and-paste example.
			sprintf("Run %q for more information.", makeHelp("subst")))
		if contains(shelltext, "#") {
			Explain(
				"When migrating to the SUBST framework, pay attention to \"#\"",
				"characters.  In shell commands, make(1) does not interpret them as",
				"comment character, but in variable assignments it does.  Therefore,",
				"instead of the shell command",
				"",
				"\tsed -e 's,#define foo,,'",
				"",
				"you need to write",
				"",
				"\tSUBST_SED.foo+=\t's,\\#define foo,,'")
		}
	}

	if m, cmd := match1(shelltext, `^@*-(.*(?:MKDIR|INSTALL.*-d|INSTALL_.*_DIR).*)`); m {
		line.Notef("You don't need to use \"-\" before %q.", cmd)
	}

	lexer := textproc.NewLexer(shelltext)
	lexer.NextHspace()
	hiddenAndSuppress := lexer.NextBytesFunc(func(b byte) bool { return b == '-' || b == '@' })
	if hiddenAndSuppress != "" {
		shline.checkHiddenAndSuppress(hiddenAndSuppress, lexer.Rest())
	}
	setE := lexer.NextString("${RUN}") != ""
	if !setE {
		lexer.NextString("${_PKG_SILENT}${_PKG_DEBUG}")
	}

	shline.CheckShellCommand(lexer.Rest(), &setE, RunTime)
}

func (shline *ShellLine) CheckShellCommand(shellcmd string, pSetE *bool, time ToolTime) {
	if trace.Tracing {
		defer trace.Call()()
	}

	line := shline.mkline.Line
	program, err := parseShellProgram(line, shellcmd)
	if err != nil && contains(shellcmd, "$$(") { // Hack until the shell parser can handle subshells.
		line.Warnf("Invoking subshells via $(...) is not portable enough.")
		return
	}
	if err != nil {
		line.Warnf("Pkglint ShellLine.CheckShellCommand: %s", err)
		return
	}

	spc := &ShellProgramChecker{shline}
	spc.checkConditionalCd(program)

	walker := NewMkShWalker()
	walker.Callback.SimpleCommand = func(command *MkShSimpleCommand) {
		scc := NewSimpleCommandChecker(shline, command, time)
		scc.Check()
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
		// TODO: in 2016 for no apparent reason.
		spc.checkWord(word, false, time)
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
				Explain(
					"Hidden shell commands do not appear on the terminal or in the log",
					"file when they are executed.  When they fail, the error message",
					"cannot be assigned to the command, which is very difficult to debug.",
					"",
					"It is better to insert ${RUN} at the beginning of the whole command",
					"line.  This will hide the command by default but shows it when",
					"PKG_DEBUG_LEVEL is set.")
			}
		}
	}

	if contains(hiddenAndSuppress, "-") {
		shline.mkline.Warnf("Using a leading \"-\" to suppress errors is deprecated.")
		Explain(
			"If you really want to ignore any errors from this command, append",
			"\"|| ${TRUE}\" to the command.")
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
		defer trace.Call()()
	}

	shellword := scc.strcmd.Name
	scc.shline.checkInstallCommand(shellword)

	switch {
	case shellword == "${RUN}" || shellword == "":
	case scc.handleForbiddenCommand():
	case scc.handleTool():
	case scc.handleCommandVariable():
	case matches(shellword, `^(?::|break|cd|continue|eval|exec|exit|export|read|set|shift|umask|unset)$`):
	case hasPrefix(shellword, "./"): // All commands from the current directory are fine.
	case matches(shellword, `\$\{(PKGSRCDIR|PREFIX)(:Q)?\}`):
	case scc.handleComment():
	default:
		if G.Opts.WarnExtra && !(G.Mk != nil && G.Mk.indentation.DependsOn("OPSYS")) {
			scc.shline.mkline.Warnf("Unknown shell command %q.", shellword)
			Explain(
				"If you want your package to be portable to all platforms that pkgsrc",
				"supports, you should only use shell commands that are covered by the",
				"tools framework.")
		}
	}
}

// handleTool tests whether the shell command is one of the recognized pkgsrc tools
// and whether the package has added it to USE_TOOLS.
func (scc *SimpleCommandChecker) handleTool() bool {
	if trace.Tracing {
		defer trace.Call()()
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
		defer trace.Call()()
	}

	shellword := scc.strcmd.Name
	switch path.Base(shellword) {
	case "ktrace", "mktexlsr", "strace", "texconfig", "truss":
		scc.shline.mkline.Errorf("%q must not be used in Makefiles.", shellword)
		Explain(
			"This command must appear in INSTALL scripts, not in the package",
			"Makefile, so that the package also works if it is installed as a",
			"binary package via pkg_add.")
		return true
	}
	return false
}

func (scc *SimpleCommandChecker) handleCommandVariable() bool {
	if trace.Tracing {
		defer trace.Call()()
	}

	shellword := scc.strcmd.Name
	parser := NewMkParser(scc.shline.mkline.Line, shellword, false)
	if varuse := parser.VarUse(); varuse != nil && parser.EOF() {
		varname := varuse.varname

		if tool := G.ToolByVarname(varname, RunTime /* LoadTime would also work */); tool != nil {
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

func (scc *SimpleCommandChecker) handleComment() bool {
	if trace.Tracing {
		defer trace.Call()()
	}

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
	}
	if multiline {
		scc.shline.mkline.Warnf("A shell comment does not stop at the end of line.")
	}

	if semicolon || multiline {
		Explain(
			"When you split a shell command into multiple lines that are",
			"continued with a backslash, they will nevertheless be converted to",
			"a single line before the shell sees them.  That means that even if",
			"it _looks_ like that the comment only spans one line in the",
			"Makefile, in fact it spans until the end of the whole shell command.",
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
		defer trace.Call()()
	}

	cmdname := scc.strcmd.Name
	isSubst := false
	for _, arg := range scc.strcmd.Args {
		if !isSubst {
			CheckLineAbsolutePathname(scc.shline.mkline.Line, arg)
		}
		if G.Testing && isSubst && !matches(arg, `"^[\"\'].*[\"\']$`) {
			scc.shline.mkline.Warnf("Substitution commands like %q should always be quoted.", arg)
			Explain(
				"Usually these substitution commands contain characters like '*' or",
				"other shell metacharacters that might lead to lookup of matching",
				"filenames and then expand to more than one word.")
		}
		isSubst = cmdname == "${PAX}" && arg == "-s" || cmdname == "${SED}" && arg == "-e"
	}
}

func (scc *SimpleCommandChecker) checkAutoMkdirs() {
	if trace.Tracing {
		defer trace.Call()()
	}

	cmdname := scc.strcmd.Name
	switch {
	case cmdname == "${MKDIR}":
		break
	case cmdname == "${INSTALL}" && scc.strcmd.HasOption("-d"):
		cmdname = "${INSTALL} -d"
	case matches(cmdname, `^\$\{INSTALL_.*_DIR\}$`):
		break
	default:
		return
	}

	for _, arg := range scc.strcmd.Args {
		if !contains(arg, "$$") && !matches(arg, `\$\{[_.]*[a-z]`) {
			if m, dirname := match1(arg, `^(?:\$\{DESTDIR\})?\$\{PREFIX(?:|:Q)\}/(.*)`); m {
				if G.Pkg != nil && G.Pkg.Plist.Dirs[dirname] {
					scc.shline.mkline.Notef("You can use AUTO_MKDIRS=yes or \"INSTALLATION_DIRS+= %s\" instead of %q.", dirname, cmdname)
					Explain(
						"Many packages include a list of all needed directories in their",
						"PLIST file.  In such a case, you can just set AUTO_MKDIRS=yes and",
						"be done.  The pkgsrc infrastructure will then create all directories",
						"in advance.",
						"",
						"To create directories that are not mentioned in the PLIST file, it",
						"is easier to just list them in INSTALLATION_DIRS than to execute the",
						"commands explicitly.  That way, you don't have to think about which",
						"of the many INSTALL_*_DIR variables is appropriate, since",
						"INSTALLATION_DIRS takes care of that.")
				} else {
					scc.shline.mkline.Notef("You can use \"INSTALLATION_DIRS+= %s\" instead of %q.", dirname, cmdname)
					Explain(
						"To create directories during installation, it is easier to just",
						"list them in INSTALLATION_DIRS than to execute the commands",
						"explicitly.  That way, you don't have to think about which",
						"of the many INSTALL_*_DIR variables is appropriate, since",
						"INSTALLATION_DIRS takes care of that.")
				}
			}
		}
	}
}

func (scc *SimpleCommandChecker) checkInstallMulti() {
	if trace.Tracing {
		defer trace.Call()()
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
					Explain(
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
		defer trace.Call()()
	}

	if (scc.strcmd.Name == "${PAX}" || scc.strcmd.Name == "pax") && scc.strcmd.HasOption("-pe") {
		scc.shline.mkline.Warnf("Please use the -pp option to pax(1) instead of -pe.")
		Explain(
			"The -pe option tells pax to preserve the ownership of the files,",
			"which means that the installed files will belong to the user that",
			"has built the package.")
	}
}

func (scc *SimpleCommandChecker) checkEchoN() {
	if trace.Tracing {
		defer trace.Call()()
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
		defer trace.Call()()
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
			Explain(
				"When the Solaris shell is in \"set -e\" mode and \"cd\" fails, the",
				"shell will exit, no matter if it is protected by an \"if\" or the",
				"\"||\" operator.")
		}
	}

	walker := NewMkShWalker()
	walker.Callback.If = func(ifClause *MkShIfClause) {
		for _, cond := range ifClause.Conds {
			if simple := getSimple(cond); simple != nil {
				checkConditionalCd(simple)
			}
		}
	}
	walker.Callback.Loop = func(loop *MkShLoopClause) {
		if simple := getSimple(loop.Cond); simple != nil {
			checkConditionalCd(simple)
		}
	}
	walker.Callback.Pipeline = func(pipeline *MkShPipeline) {
		if pipeline.Negated {
			spc.shline.mkline.Warnf("The Solaris /bin/sh does not support negation of shell commands.")
			Explain(
				"The GNU Autoconf manual has many more details of what shell",
				"features to avoid for portable programs.  It can be read at:",
				"https://www.gnu.org/software/autoconf/manual/autoconf.html#Limitations-of-Builtins")
		}
	}
	walker.Walk(list)
}

func (spc *ShellProgramChecker) checkWord(word *ShToken, checkQuoting bool, time ToolTime) {
	if trace.Tracing {
		defer trace.Call(word.MkText)()
	}

	spc.shline.CheckWord(word.MkText, checkQuoting, time)
}

func (spc *ShellProgramChecker) checkPipeExitcode(line Line, pipeline *MkShPipeline) {
	if trace.Tracing {
		defer trace.Call()()
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
			Explain(
				"In a shell command like \"cat *.txt | grep keyword\", if the command",
				"on the left side of the \"|\" fails, this failure is ignored.",
				"",
				"If you need to detect the failure of the left-hand-side command, use",
				"temporary files to save the output of the command.  A good place to",
				"create those files is in ${WRKDIR}.")
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
	case "echo", "printf", "tr":
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
		defer trace.Call()()
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
	Explain(
		"Normally, when a shell command fails (returns non-zero), the",
		"remaining commands are still executed.  For example, the following",
		"commands would remove all files from the HOME directory:",
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
		defer trace.Call()()
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
		line.Warnf("The shell command %q should not be used in the install phase.", shellcmd)
		Explain(
			"In the install phase, the only thing that should be done is to",
			"install the prepared files to their final location.  The file's",
			"contents should not be changed anymore.")

	case "cp", "${CP}":
		line.Warnf("${CP} should not be used to install files.")
		Explain(
			"The ${CP} command is highly platform dependent and cannot overwrite",
			"read-only files.  Please use ${PAX} instead.",
			"",
			"For example, instead of",
			"\t${CP} -R ${WRKSRC}/* ${PREFIX}/foodir",
			"you should use",
			"\tcd ${WRKSRC} && ${PAX} -wr * ${PREFIX}/foodir")
	}
}

// Example: "word1 word2;;;" => "word1", "word2", ";;", ";"
func splitIntoShellTokens(line Line, text string) (tokens []string, rest string) {
	if trace.Tracing {
		defer trace.Call(line, text)()
	}

	word := ""
	rest = text
	p := NewShTokenizer(line, text, false)
	emit := func() {
		if word != "" {
			tokens = append(tokens, word)
			word = ""
		}
		rest = p.mkp.Rest()
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
		} else if atom.Type == shtWord || atom.Type == shtVaruse || atom.Quoting != shqPlain {
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
	return words, word + p.mkp.Rest()
}
