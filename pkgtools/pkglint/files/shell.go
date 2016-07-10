package main

// Parsing and checking shell commands embedded in Makefiles

import (
	"path"
	"strings"
)

const (
	reShVarname      = `(?:[!#*\-\d?@]|\$\$|[A-Za-z_]\w*)`
	reShVarexpansion = `(?:(?:#|##|%|%%|:-|:=|:\?|:\+|\+)[^$\\{}]*)`
	reShVaruse       = `\$\$` + `(?:` + reShVarname + `|` + `\{` + reShVarname + `(?:` + reShVarexpansion + `)?` + `\})`
	reShDollar       = `\\\$\$|` + reShVaruse + `|\$\$[,\-/|]`
)

type ShellLine struct {
	line   *Line
	mkline *MkLine
}

func NewShellLine(mkline *MkLine) *ShellLine {
	return &ShellLine{mkline.Line, mkline}
}

var shellcommandsContextType = &Vartype{lkNone, BtShellCommands, []AclEntry{{"*", aclpAllRuntime}}, false}
var shellwordVuc = &VarUseContext{shellcommandsContextType, vucTimeUnknown, vucQuotPlain, false}

func (shline *ShellLine) CheckWord(token string, checkQuoting bool) {
	if G.opts.Debug {
		defer tracecall(token, checkQuoting)()
	}

	if token == "" || hasPrefix(token, "#") {
		return
	}

	line := shline.line

	p := NewMkParser(line, token, false)
	if varuse := p.VarUse(); varuse != nil && p.EOF() {
		shline.mkline.CheckVaruse(varuse, shellwordVuc)
		return
	}

	if matches(token, `\$\{PREFIX\}/man(?:$|/)`) {
		line.Warn0("Please use ${PKGMANDIR} instead of \"man\".")
	}
	if contains(token, "etc/rc.d") {
		line.Warn0("Please use the RCD_SCRIPTS mechanism to install rc.d scripts automatically to ${RCD_SCRIPTS_EXAMPLEDIR}.")
	}

	parser := NewMkParser(line, token, false)
	repl := parser.repl
	quoting := shqPlain
outer:
	for !parser.EOF() {
		if G.opts.Debug {
			traceStep("shell state %s: %q", quoting, parser.Rest())
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
			shline.CheckShellCommand(backtCommand, &setE)

			// Make(1) variables have the same syntax, no matter in which state we are currently.
		case shline.checkVaruseToken(parser, quoting):
			break

		case quoting == shqPlain:
			switch {
			case repl.AdvanceRegexp(`^[!#\%&\(\)*+,\-.\/0-9:;<=>?@A-Z\[\]^_a-z{|}~]+`),
				repl.AdvanceRegexp(`^\\(?:[ !"#'\(\)*./;?\\^{|}]|\$\$)`):
			case repl.AdvanceStr("'"):
				quoting = shqSquot
			case repl.AdvanceStr("\""):
				quoting = shqDquot
			case repl.AdvanceStr("`"):
				quoting = shqBackt
			case repl.AdvanceRegexp(`^\$\$([0-9A-Z_a-z]+|#)`),
				repl.AdvanceRegexp(`^\$\$\{([0-9A-Z_a-z]+|#)\}`),
				repl.AdvanceRegexp(`^\$\$(\$)\$`):
				shvarname := repl.m[1]
				if G.opts.WarnQuoting && checkQuoting && shline.variableNeedsQuoting(shvarname) {
					line.Warn1("Unquoted shell variable %q.", shvarname)
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
						"\tcp $fname /tmp",
						"\t# tries to copy the two files \"Curriculum\" and \"Vitae.doc\"",
						"\tcp \"$fname\" /tmp",
						"\t# copies one file, as intended")
				}
			case repl.AdvanceStr("$@"):
				line.Warn2("Please use %q instead of %q.", "${.TARGET}", "$@")
				Explain2(
					"It is more readable and prevents confusion with the shell variable of",
					"the same name.")

			case repl.AdvanceStr("$$@"):
				line.Warn0("The $@ shell variable should only be used in double quotes.")

			case repl.AdvanceStr("$$?"):
				line.Warn0("The $? shell variable is often not available in \"set -e\" mode.")

			case repl.AdvanceStr("$$("):
				line.Warn0("Invoking subshells via $(...) is not portable enough.")
				Explain2(
					"The Solaris /bin/sh does not know this way to execute a command in a",
					"subshell.  Please use backticks (`...`) as a replacement.")

			case repl.AdvanceStr("$$"): // Not part of a variable.
				break

			default:
				break outer
			}

		case quoting == shqSquot:
			switch {
			case repl.AdvanceRegexp(`^'`):
				quoting = shqPlain
			case repl.AdvanceRegexp(`^[^\$\']+`):
				// just skip
			case repl.AdvanceRegexp(`^\$\$`):
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
			case repl.AdvanceRegexp("^[^$\"\\\\`]+"):
				break
			case repl.AdvanceStr("\\$$"):
				break
			case repl.AdvanceRegexp(`^\\.`): // See http://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html#tag_02_02_01
				break
			case repl.AdvanceRegexp(`^\$\$\{\w+[#%+\-:]*[^{}]*\}`),
				repl.AdvanceRegexp(`^\$\$(?:\w+|[!#?@]|\$\$)`):
				break
			case repl.AdvanceStr("$$"):
				line.Warn0("Unescaped $ or strange shell variable found.")
			default:
				break outer
			}
		}
	}

	if strings.TrimSpace(parser.Rest()) != "" {
		line.Warnf("Pkglint parse error in ShellLine.CheckWord at %q (quoting=%s, rest=%q)", token, quoting, parser.Rest())
	}
}

func (shline *ShellLine) checkVaruseToken(parser *MkParser, quoting ShQuoting) bool {
	if G.opts.Debug {
		defer tracecall(parser.Rest(), quoting)()
	}

	varuse := parser.VarUse()
	if varuse == nil {
		return false
	}
	varname := varuse.varname

	if varname == "@" {
		shline.line.Warn0("Please use \"${.TARGET}\" instead of \"$@\".")
		Explain2(
			"The variable $@ can easily be confused with the shell variable of",
			"the same name, which has a completely different meaning.")
		varname = ".TARGET"
		varuse = &MkVarUse{varname, varuse.modifiers}
	}

	switch {
	case quoting == shqPlain && varuse.IsQ():
		// Fine.
	case quoting == shqBackt:
		// Don't check anything here, to avoid false positives for tool names.
	case (quoting == shqSquot || quoting == shqDquot) && matches(varname, `^(?:.*DIR|.*FILE|.*PATH|.*_VAR|PREFIX|.*BASE|PKGNAME)$`):
		// This is ok if we don't allow these variables to have embedded [\$\\\"\'\`].
	case quoting == shqDquot && varuse.IsQ():
		shline.line.Warn0("Please don't use the :Q operator in double quotes.")
		Explain2(
			"Either remove the :Q or the double quotes.  In most cases, it is",
			"more appropriate to remove the double quotes.")
	}

	if varname != "@" {
		vucstate := quoting.ToVarUseContext()
		vuc := &VarUseContext{shellcommandsContextType, vucTimeUnknown, vucstate, true}
		shline.mkline.CheckVaruse(varuse, vuc)
	}
	return true
}

// Scan for the end of the backticks, checking for single backslashes
// and removing one level of backslashes. Backslashes are only removed
// before a dollar, a backslash or a backtick.
//
// See http://www.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html#tag_02_06_03
func (shline *ShellLine) unescapeBackticks(shellword string, repl *PrefixReplacer, quoting ShQuoting) (unescaped string, newQuoting ShQuoting) {
	if G.opts.Debug {
		defer tracecall(shellword, quoting, "=>", ref(&unescaped))()
	}

	line := shline.line
	for repl.rest != "" {
		switch {
		case repl.AdvanceStr("`"):
			if quoting == shqBackt {
				quoting = shqPlain
			} else {
				quoting = shqDquot
			}
			return unescaped, quoting

		case repl.AdvanceRegexp("^\\\\([\"\\\\`$])"):
			unescaped += repl.m[1]

		case repl.AdvanceStr("\\"):
			line.Warn0("Backslashes should be doubled inside backticks.")
			unescaped += "\\"

		case quoting == shqDquotBackt && repl.AdvanceStr("\""):
			line.Warn0("Double quotes inside backticks inside double quotes are error prone.")
			Explain4(
				"According to the SUSv3, they produce undefined results.",
				"",
				"See the paragraph starting \"Within the backquoted ...\" in",
				"http://www.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html")

		case repl.AdvanceRegexp("^([^\\\\`]+)"):
			unescaped += repl.m[1]

		default:
			line.Errorf("Internal pkglint error in ShellLine.unescapeBackticks at %q (rest=%q)", shellword, repl.rest)
		}
	}
	line.Error1("Unfinished backquotes: rest=%q", repl.rest)
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
	if G.opts.Debug {
		defer tracecall1(shelltext)()
	}

	line := shline.line

	if contains(shelltext, "${SED}") && contains(shelltext, "${MV}") {
		line.Note0("Please use the SUBST framework instead of ${SED} and ${MV}.")
		Explain(
			"Using the SUBST framework instead of explicit commands is easier",
			"to understand, since all the complexity of using sed and mv is",
			"hidden behind the scenes.",
			"",
			"Run \"bmake help topic=subst\" for more information.")
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
		line.Note1("You don't need to use \"-\" before %q.", cmd)
	}

	repl := NewPrefixReplacer(shelltext)
	repl.AdvanceRegexp(`^\s+`)
	if repl.AdvanceRegexp(`^[-@]+`) {
		shline.checkHiddenAndSuppress(repl.m[0], repl.rest)
	}
	setE := false
	if repl.AdvanceStr("${RUN}") {
		setE = true
	} else {
		repl.AdvanceStr("${_PKG_SILENT}${_PKG_DEBUG}")
	}

	shline.CheckShellCommand(repl.rest, &setE)
}

func (shline *ShellLine) CheckShellCommand(shellcmd string, pSetE *bool) {
	if G.opts.Debug {
		defer tracecall()()
	}

	program, err := parseShellProgram(shline.line, shellcmd)
	if err != nil && contains(shellcmd, "$$(") { // Hack until the shell parser can handle subshells.
		shline.line.Warn0("Invoking subshells via $(...) is not portable enough.")
		return
	}
	if err != nil {
		shline.line.Warnf("Pkglint ShellLine.CheckShellCommand: %s", err)
		return
	}

	spc := &ShellProgramChecker{shline}
	spc.checkConditionalCd(program)

	(*MkShWalker).Walk(nil, program, func(node interface{}) {
		if cmd, ok := node.(*MkShSimpleCommand); ok {
			scc := NewSimpleCommandChecker(shline, cmd)
			scc.Check()
			if scc.strcmd.Name == "set" && scc.strcmd.AnyArgMatches(`^-.*e`) {
				*pSetE = true
			}
		}

		if cmd, ok := node.(*MkShList); ok {
			spc.checkSetE(cmd, pSetE)
		}

		if cmd, ok := node.(*MkShPipeline); ok {
			spc.checkPipeExitcode(shline.line, cmd)
		}

		if word, ok := node.(*ShToken); ok {
			spc.checkWord(word, false)
		}
	})
}

func (shline *ShellLine) CheckShellCommands(shellcmds string) {
	setE := true
	shline.CheckShellCommand(shellcmds, &setE)
	if !hasSuffix(shellcmds, ";") {
		shline.line.Warn0("This shell command list should end with a semicolon.")
	}
}

func (shline *ShellLine) checkHiddenAndSuppress(hiddenAndSuppress, rest string) {
	if G.opts.Debug {
		defer tracecall(hiddenAndSuppress, rest)()
	}

	switch {
	case !contains(hiddenAndSuppress, "@"):
		// Nothing is hidden at all.

	case hasPrefix(G.Mk.target, "show-") || hasSuffix(G.Mk.target, "-message"):
		// In these targets, all commands may be hidden.

	case hasPrefix(rest, "#"):
		// Shell comments may be hidden, since they cannot have side effects.

	default:
		tokens, _ := splitIntoShellTokens(shline.line, rest)
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
				shline.line.Warn1("The shell command %q should not be hidden.", cmd)
				Explain(
					"Hidden shell commands do not appear on the terminal or in the log",
					"file when they are executed.  When they fail, the error message",
					"cannot be assigned to the command, which is very difficult to debug.",
					"",
					"It is better to insert ${RUN} at the beginning of the whole command",
					"line.  This will hide the command by default, but shows it when",
					"PKG_DEBUG_LEVEL is set.")
			}
		}
	}

	if contains(hiddenAndSuppress, "-") {
		shline.line.Warn0("Using a leading \"-\" to suppress errors is deprecated.")
		Explain2(
			"If you really want to ignore any errors from this command, append",
			"\"|| ${TRUE}\" to the command.")
	}
}

type SimpleCommandChecker struct {
	shline *ShellLine
	cmd    *MkShSimpleCommand
	strcmd *StrCommand
}

func NewSimpleCommandChecker(shline *ShellLine, cmd *MkShSimpleCommand) *SimpleCommandChecker {
	strcmd := NewStrCommand(cmd)
	return &SimpleCommandChecker{shline, cmd, strcmd}

}

func (scc *SimpleCommandChecker) Check() {
	if G.opts.Debug {
		defer tracecall(scc.strcmd)()
	}

	scc.checkCommandStart()
	scc.checkAbsolutePathnames()
	scc.checkAutoMkdirs()
	scc.checkInstallMulti()
	scc.checkPaxPe()
	scc.checkEchoN()
}

func (scc *SimpleCommandChecker) checkCommandStart() {
	if G.opts.Debug {
		defer tracecall()()
	}

	shellword := scc.strcmd.Name
	switch {
	case shellword == "${RUN}" || shellword == "":
	case scc.handleForbiddenCommand():
	case scc.handleTool():
	case scc.handleCommandVariable():
	case matches(shellword, `^(?::|break|cd|continue|eval|exec|exit|export|read|set|shift|umask|unset)$`):
	case hasPrefix(shellword, "./"): // All commands from the current directory are fine.
	case hasPrefix(shellword, "${PKGSRCDIR"): // With or without the :Q modifier
	case scc.handleComment():
	default:
		if G.opts.WarnExtra && !(G.Mk != nil && G.Mk.indentation.DependsOn("OPSYS")) {
			scc.shline.line.Warn1("Unknown shell command %q.", shellword)
			Explain3(
				"If you want your package to be portable to all platforms that pkgsrc",
				"supports, you should only use shell commands that are covered by the",
				"tools framework.")
		}
	}
}

func (scc *SimpleCommandChecker) handleTool() bool {
	if G.opts.Debug {
		defer tracecall()()
	}

	shellword := scc.strcmd.Name
	tool := G.globalData.Tools.byName[shellword]
	if tool == nil {
		return false
	}

	if !G.Mk.tools[shellword] && !G.Mk.tools["g"+shellword] {
		scc.shline.line.Warn1("The %q tool is used but not added to USE_TOOLS.", shellword)
	}

	if tool.MustUseVarForm {
		scc.shline.line.Warn2("Please use \"${%s}\" instead of %q.", tool.Varname, shellword)
	}

	scc.shline.checkCommandUse(shellword)
	return true
}

func (scc *SimpleCommandChecker) handleForbiddenCommand() bool {
	if G.opts.Debug {
		defer tracecall()()
	}

	shellword := scc.strcmd.Name
	switch path.Base(shellword) {
	case "ktrace", "mktexlsr", "strace", "texconfig", "truss":
		scc.shline.line.Error1("%q must not be used in Makefiles.", shellword)
		Explain3(
			"This command must appear in INSTALL scripts, not in the package",
			"Makefile, so that the package also works if it is installed as a binary",
			"package via pkg_add.")
		return true
	}
	return false
}

func (scc *SimpleCommandChecker) handleCommandVariable() bool {
	if G.opts.Debug {
		defer tracecall()()
	}

	shellword := scc.strcmd.Name
	if m, varname := match1(shellword, `^\$\{([\w_]+)\}$`); m {

		if tool := G.globalData.Tools.byVarname[varname]; tool != nil {
			if !G.Mk.tools[tool.Name] {
				scc.shline.line.Warn1("The %q tool is used but not added to USE_TOOLS.", tool.Name)
			}
			scc.shline.checkCommandUse(shellword)
			return true
		}

		if vartype := scc.shline.mkline.getVariableType(varname); vartype != nil && vartype.basicType.name == "ShellCommand" {
			scc.shline.checkCommandUse(shellword)
			return true
		}

		// When the package author has explicitly defined a command
		// variable, assume it to be valid.
		if G.Pkg != nil && G.Pkg.vardef[varname] != nil {
			return true
		}
	}
	return false
}

func (scc *SimpleCommandChecker) handleComment() bool {
	if G.opts.Debug {
		defer tracecall()()
	}

	shellword := scc.strcmd.Name
	if G.opts.Debug {
		defer tracecall1(shellword)()
	}

	if !hasPrefix(shellword, "#") {
		return false
	}

	semicolon := contains(shellword, ";")
	multiline := scc.shline.line.IsMultiline()

	if semicolon {
		scc.shline.line.Warn0("A shell comment should not contain semicolons.")
	}
	if multiline {
		scc.shline.line.Warn0("A shell comment does not stop at the end of line.")
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

func (scc *SimpleCommandChecker) checkAbsolutePathnames() {
	if G.opts.Debug {
		defer tracecall()()
	}

	cmdname := scc.strcmd.Name
	isSubst := false
	for _, arg := range scc.strcmd.Args {
		if !isSubst {
			scc.shline.line.CheckAbsolutePathname(arg)
		}
		if false && isSubst && !matches(arg, `"^[\"\'].*[\"\']$`) {
			scc.shline.line.Warn1("Substitution commands like %q should always be quoted.", arg)
			Explain3(
				"Usually these substitution commands contain characters like '*' or",
				"other shell metacharacters that might lead to lookup of matching",
				"filenames and then expand to more than one word.")
		}
		isSubst = cmdname == "${PAX}" && arg == "-s" || cmdname == "${SED}" && arg == "-e"
	}
}

func (scc *SimpleCommandChecker) checkAutoMkdirs() {
	if G.opts.Debug {
		defer tracecall()()
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
				scc.shline.line.Note2("You can use AUTO_MKDIRS=yes or \"INSTALLATION_DIRS+= %s\" instead of %q.", dirname, cmdname)
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
			}
		}
	}
}

func (scc *SimpleCommandChecker) checkInstallMulti() {
	if G.opts.Debug {
		defer tracecall()()
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
					scc.shline.line.Warn0("The INSTALL_*_DIR commands can only handle one directory at a time.")
					Explain2(
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
	if G.opts.Debug {
		defer tracecall()()
	}

	if scc.strcmd.Name == "${PAX}" && scc.strcmd.HasOption("-pe") {
		scc.shline.line.Warn0("Please use the -pp option to pax(1) instead of -pe.")
		Explain3(
			"The -pe option tells pax to preserve the ownership of the files, which",
			"means that the installed files will belong to the user that has built",
			"the package.")
	}
}

func (scc *SimpleCommandChecker) checkEchoN() {
	if G.opts.Debug {
		defer tracecall()()
	}

	if scc.strcmd.Name == "${ECHO}" && scc.strcmd.HasOption("-n") {
		scc.shline.line.Warn0("Please use ${ECHO_N} instead of \"echo -n\".")
	}
}

type ShellProgramChecker struct {
	shline *ShellLine
}

func (spc *ShellProgramChecker) checkConditionalCd(list *MkShList) {
	if G.opts.Debug {
		defer tracecall()()
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
			spc.shline.line.Error0("The Solaris /bin/sh cannot handle \"cd\" inside conditionals.")
			Explain3(
				"When the Solaris shell is in \"set -e\" mode and \"cd\" fails, the",
				"shell will exit, no matter if it is protected by an \"if\" or the",
				"\"||\" operator.")
		}
	}

	(*MkShWalker).Walk(nil, list, func(node interface{}) {
		if cmd, ok := node.(*MkShIfClause); ok {
			for _, cond := range cmd.Conds {
				if simple := getSimple(cond); simple != nil {
					checkConditionalCd(simple)
				}
			}
		}
		if cmd, ok := node.(*MkShLoopClause); ok {
			if simple := getSimple(cmd.Cond); simple != nil {
				checkConditionalCd(simple)
			}
		}
	})
}

func (spc *ShellProgramChecker) checkWords(words []*ShToken, checkQuoting bool) {
	if G.opts.Debug {
		defer tracecall()()
	}

	for _, word := range words {
		spc.checkWord(word, checkQuoting)
	}
}

func (spc *ShellProgramChecker) checkWord(word *ShToken, checkQuoting bool) {
	if G.opts.Debug {
		defer tracecall(word.MkText)()
	}

	spc.shline.CheckWord(word.MkText, checkQuoting)
}

func (scc *ShellProgramChecker) checkPipeExitcode(line *Line, pipeline *MkShPipeline) {
	if G.opts.Debug {
		defer tracecall()()
	}

	if G.opts.WarnExtra && len(pipeline.Cmds) > 1 {
		line.Warn0("The exitcode of the left-hand-side command of the pipe operator is ignored.")
		Explain(
			"In a shell command like \"cat *.txt | grep keyword\", if the command",
			"on the left side of the \"|\" fails, this failure is ignored.",
			"",
			"If you need to detect the failure of the left-hand-side command, use",
			"temporary files to save the output of the command.")
	}
}

func (scc *ShellProgramChecker) checkSetE(list *MkShList, eflag *bool) {
	if G.opts.Debug {
		defer tracecall()()
	}

	// Disabled until the shell parser can recognize "command || exit 1" reliably.
	if false && G.opts.WarnExtra && !*eflag && "the current token" == ";" {
		*eflag = true
		scc.shline.line.Warn1("Please switch to \"set -e\" mode before using a semicolon (the one after %q) to separate commands.", "previous token")
		Explain(
			"Normally, when a shell command fails (returns non-zero), the",
			"remaining commands are still executed.  For example, the following",
			"commands would remove all files from the HOME directory:",
			"",
			"\tcd \"$HOME\"; cd /nonexistent; rm -rf *",
			"",
			"To fix this warning, you can:",
			"",
			"* insert ${RUN} at the beginning of the line",
			"  (which among other things does \"set -e\")",
			"* insert \"set -e\" explicitly at the beginning of the line",
			"* use \"&&\" instead of \";\" to separate the commands")
	}
}

// Some shell commands should not be used in the install phase.
func (shline *ShellLine) checkCommandUse(shellcmd string) {
	if G.opts.Debug {
		defer tracecall()()
	}

	if G.Mk == nil || !matches(G.Mk.target, `^(?:pre|do|post)-install$`) {
		return
	}

	line := shline.line
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
		line.Warn1("The shell command %q should not be used in the install phase.", shellcmd)
		Explain3(
			"In the install phase, the only thing that should be done is to",
			"install the prepared files to their final location.  The file's",
			"contents should not be changed anymore.")

	case "cp", "${CP}":
		line.Warn0("${CP} should not be used to install files.")
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
func splitIntoShellTokens(line *Line, text string) (tokens []string, rest string) {
	if G.opts.Debug {
		defer tracecall(line, text)()
	}

	word := ""
	emit := func() {
		if word != "" {
			tokens = append(tokens, word)
			word = ""
		}
	}
	p := NewShTokenizer(line, text, false)
	atoms := p.ShAtoms()
	q := shqPlain
	for _, atom := range atoms {
		q = atom.Quoting
		if atom.Type == shtSpace && q == shqPlain {
			emit()
		} else if atom.Type == shtWord || atom.Type == shtVaruse || atom.Quoting != shqPlain {
			word += atom.MkText
		} else {
			emit()
			tokens = append(tokens, atom.MkText)
		}
	}
	emit()
	return tokens, word + p.mkp.Rest()
}

// Example: "word1 word2;;;" => "word1", "word2;;;"
// Compare devel/bmake/files/str.c, function brk_string.
func splitIntoMkWords(line *Line, text string) (words []string, rest string) {
	if G.opts.Debug {
		defer tracecall(line, text)()
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
