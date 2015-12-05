package main

// Parsing and checking shell commands embedded in Makefiles

import (
	"path"
	"strings"
	"unicode"
)

func checklineMkShellword(line *Line, word string, checkQuoting bool) {
	NewMkShellLine(line).checklineMkShellword(word, checkQuoting)
}
func checklineMkShellcmdUse(line *Line, shellcmd string) {
	NewMkShellLine(line).checkCommandUse(shellcmd)
}
func checklineMkShellcmd(line *Line, shellcmd string) {
	checklineMkText(line, shellcmd)
	NewMkShellLine(line).checklineMkShelltext(shellcmd)
}

const (
	reMkShellvaruse = `(?:^|[^\$])\$\$\{?(\w+)\}?`
	reVarnameDirect = `(?:[-*+.0-9A-Z_a-z{}\[]+)`
	reShellword     = `^\s*(` +
		`#.*` + // shell comment
		`|(?:` +
		`'[^']*'` + // single quoted string
		`|"(?:\\.|[^"\\])*"` + // double quoted string
		"|`[^`]*`" + // backticks command execution
		`|\\\$\$` + // a shell-escaped dollar sign
		`|\\[^\$]` + // other escaped characters
		`|\$[\w_]` + // one-character make(1) variable
		`|\$\{[^{}]+\}` + // make(1) variable, ${...}
		`|\$\([^()]+\)` + // make(1) variable, $(...)
		`|\$[/@<^]` + // special make(1) variables
		`|\$\$[0-9A-Z_a-z]+` + // shell variable
		`|\$\$[#?@]` + // special shell variables
		`|\$\$[./]` + // unescaped dollar in shell, followed by punctuation
		`|\$\$\$\$` + // the special pid shell variable
		`|\$\$\{[0-9A-Z_a-z]+\}` + // shell variable in braces
		`|\$\$\(` + // POSIX-style backticks replacement
		`|[^\(\)'\"\\\s;&\|<>` + "`" + `\$]` + // non-special character
		`|\$\{[^\s\"'` + "`" + `]+` + // HACK: nested make(1) variables
		`)+` + // any of the above may be repeated
		`|;;?` +
		`|&&?` +
		`|\|\|?` +
		`|\(` +
		`|\)` +
		`|>&` +
		`|<<?` +
		`|>>?` +
		`|#.*)`
	reShVarassign = `^([A-Z_a-z]\w*)=`
)

// ShellCommandState
type scState string

const (
	scstStart         scState = "start"
	scstCont          scState = "continuation"
	scstInstall       scState = "install"
	scstInstallD      scState = "install -d"
	scstMkdir         scState = "mkdir"
	scstPax           scState = "pax"
	scstPaxS          scState = "pax -s"
	scstSed           scState = "sed"
	scstSedE          scState = "sed -e"
	scstSet           scState = "set"
	scstSetCont       scState = "set-continuation"
	scstCond          scState = "cond"
	scstCondCont      scState = "cond-continuation"
	scstCase          scState = "case"
	scstCaseIn        scState = "case in"
	scstCaseLabel     scState = "case label"
	scstCaseLabelCont scState = "case-label-continuation"
	scstFor           scState = "for"
	scstForIn         scState = "for-in"
	scstForCont       scState = "for-continuation"
	scstEcho          scState = "echo"
	scstInstallDir    scState = "install-dir"
	scstInstallDir2   scState = "install-dir2"
)

type MkShellLine struct {
	line *Line
}

func NewMkShellLine(line *Line) *MkShellLine {
	return &MkShellLine{line}
}

func (msline *MkShellLine) checklineMkShellword(shellword string, checkQuoting bool) {
	defer tracecall("MkShellLine.checklineMkShellword", shellword, checkQuoting)()

	if shellword == "" || hasPrefix(shellword, "#") {
		return
	}

	shellcommandContextType := &Vartype{lkNone, CheckvarShellCommand, []AclEntry{{"*", "adsu"}}, guNotGuessed}
	shellwordVuc := &VarUseContext{vucTimeUnknown, shellcommandContextType, vucQuotPlain, vucExtentWord}

	line := msline.line
	if m, varname, mod := match2(shellword, `^\$\{(`+reVarnameDirect+`)(:[^{}]+)?\}$`); m {
		checklineMkVaruse(line, varname, mod, shellwordVuc)
		return
	}

	if matches(shellword, `\$\{PREFIX\}/man(?:$|/)`) {
		line.warnf("Please use ${PKGMANDIR} instead of \"man\".")
	}
	if contains(shellword, "etc/rc.d") {
		line.warnf("Please use the RCD_SCRIPTS mechanism to install rc.d scripts automatically to ${RCD_SCRIPTS_EXAMPLEDIR}.")
	}

	type ShellwordState string
	const (
		swstPlain      ShellwordState = "plain"
		swstSquot      ShellwordState = "squot"
		swstDquot      ShellwordState = "dquot"
		swstDquotBackt ShellwordState = "dquot+backt"
		swstBackt      ShellwordState = "backt"
	)

	rest := shellword
	state := swstPlain
outer:
	for rest != "" {
		_ = G.opts.DebugShell && line.debugf("shell state %s: %q", state, rest)

		var m []string
		switch {
		// When parsing inside backticks, it is more
		// reasonable to check the whole shell command
		// recursively, instead of splitting off the first
		// make(1) variable.
		case state == swstBackt || state == swstDquotBackt:
			// Scan for the end of the backticks, checking
			// for single backslashes and removing one level
			// of backslashes. Backslashes are only removed
			// before a dollar, a backslash or a backtick.
			//
			// References:
			// * http://www.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html#tag_02_06_03
			stripped := ""
			for rest != "" {
				switch {
				case replacePrefix(&rest, &m, "^`"):
					if state == swstBackt {
						state = swstPlain
					} else {
						state = swstDquot
					}
					goto endOfBackticks

				case replacePrefix(&rest, &m, "^\\\\([\\\\`$])"):
					stripped += m[1]

				case replacePrefix(&rest, &m, `^(\\)`):
					line.warnf("Backslashes should be doubled inside backticks.")
					stripped += m[1]

				case state == swstDquotBackt && replacePrefix(&rest, &m, `^"`):
					line.warnf("Double quotes inside backticks inside double quotes are error prone.")
					line.explain(
						"According to the SUSv3, they produce undefined results.",
						"",
						"See the paragraph starting \"Within the backquoted ...\" in",
						"http://www.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html")

				case replacePrefix(&rest, &m, "^([^\\\\`]+)"):
					stripped += m[1]

				default:
					line.errorf("Internal pkglint error: checklineMkShellword shellword=%q rest=%q", shellword, rest)
				}
			}
			line.errorf("Unfinished backquotes: rest=%q", rest)

		endOfBackticks:
			msline.checklineMkShelltext(stripped)

		// Make(1) variables have the same syntax, no matter in which state we are currently.
		case replacePrefix(&rest, &m, `^\$\{(`+reVarnameDirect+`|@)(:[^\{]+)?\}`),
			replacePrefix(&rest, &m, `^\$\((`+reVarnameDirect+`|@])(:[^\)]+)?\)`),
			replacePrefix(&rest, &m, `^\$([\w@])()`):
			varname, mod := m[1], m[2]

			if varname == "@" {
				line.warnf("Please use \"${.TARGET}\" instead of \"$@\".")
				line.explain(
					"The variable $@ can easily be confused with the shell variable of the",
					"same name, which has a completely different meaning.")
				varname = ".TARGET"
			}

			switch {
			case state == swstPlain && hasSuffix(mod, ":Q"):
				// Fine.
			case state == swstBackt:
				// Don't check anything here, to avoid false positives for tool names.
			case (state == swstSquot || state == swstDquot) && matches(varname, `^(?:.*DIR|.*FILE|.*PATH|.*_VAR|PREFIX|.*BASE|PKGNAME)$`):
				// This is ok if we don't allow these variables to have embedded [\$\\\"\'\`].
			case state == swstDquot && hasSuffix(mod, ":Q"):
				line.warnf("Please don't use the :Q operator in double quotes.")
				line.explain(
					"Either remove the :Q or the double quotes. In most cases, it is more",
					"appropriate to remove the double quotes.")
			}

			if varname != "@" {
				vucstate := vucQuotUnknown
				switch state {
				case swstPlain:
					vucstate = vucQuotPlain
				case swstDquot:
					vucstate = vucQuotDquot
				case swstSquot:
					vucstate = vucQuotSquot
				case swstBackt:
					vucstate = vucQuotBackt
				}
				vuc := &VarUseContext{vucTimeUnknown, shellcommandContextType, vucstate, vucExtentWordpart}
				checklineMkVaruse(line, varname, mod, vuc)
			}

		// The syntax of the variable modifiers can get quite
		// hairy. In lack of motivation, we just skip anything
		// complicated, hoping that at least the braces are balanced.
		case replacePrefix(&rest, &m, `^\$\{`):
			braces := 1
		skip:
			for rest != "" && braces > 0 {
				switch {
				case replacePrefix(&rest, &m, `^\}`):
					braces--
				case replacePrefix(&rest, &m, `^\{`):
					braces++
				case replacePrefix(&rest, &m, `^[^{}]+`):
				// skip
				default:
					break skip
				}
			}

		case state == swstPlain:
			switch {
			case replacePrefix(&rest, &m, `^[!#\%&\(\)*+,\-.\/0-9:;<=>?@A-Z\[\]^_a-z{|}~]+`),
				replacePrefix(&rest, &m, `^\\(?:[ !"#'\(\)*;?\\^{|}]|\$\$)`):
			case replacePrefix(&rest, &m, `^'`):
				state = swstSquot
			case replacePrefix(&rest, &m, `^"`):
				state = swstDquot
			case replacePrefix(&rest, &m, "^`"):
				state = swstBackt
			case replacePrefix(&rest, &m, `^\$\$([0-9A-Z_a-z]+|\#)`),
				replacePrefix(&rest, &m, `^\$\$\{([0-9A-Z_a-z]+|\#)\}`),
				replacePrefix(&rest, &m, `^\$\$(\$)\$`):
				shvarname := m[1]
				if G.opts.WarnQuoting && checkQuoting && msline.variableNeedsQuoting(shvarname) {
					line.warnf("Unquoted shell variable %q.", shvarname)
					line.explain(
						"When a shell variable contains white-space, it is expanded (split into",
						"multiple words) when it is written as $variable in a shell script.",
						"If that is not intended, you should add quotation marks around it,",
						"like \"$variable\". Then, the variable will always expand to a single",
						"word, preserving all white-space and other special characters.",
						"",
						"Example:",
						"\tfname=\"Curriculum vitae.doc\"",
						"\tcp $fname /tmp",
						"\t# tries to copy the two files \"Curriculum\" and \"Vitae.doc\"",
						"\tcp \"$fname\" /tmp",
						"\t# copies one file, as intended")
				}
			case replacePrefix(&rest, &m, `^\$@`):
				line.warnf("Please use %q instead of %q.", "${.TARGET}", "$@")
				line.explain(
					"It is more readable and prevents confusion with the shell variable of",
					"the same name.")

			case replacePrefix(&rest, &m, `^\$\$@`):
				line.warnf("The $@ shell variable should only be used in double quotes.")

			case replacePrefix(&rest, &m, `^\$\$\?`):
				line.warnf("The $? shell variable is often not available in \"set -e\" mode.")

			case replacePrefix(&rest, &m, `^\$\$\(`):
				line.warnf("Invoking subshells via $(...) is not portable enough.")
				line.explain(
					"The Solaris /bin/sh does not know this way to execute a command in a",
					"subshell. Please use backticks (`...`) as a replacement.")

			default:
				break outer
			}

		case state == swstSquot:
			switch {
			case replacePrefix(&rest, &m, `^'`):
				state = swstPlain
			case replacePrefix(&rest, &m, `^[^\$\']+`):
				// just skip
			case replacePrefix(&rest, &m, `^\$\$`):
				// just skip
			default:
				break outer
			}

		case state == swstDquot:
			switch {
			case replacePrefix(&rest, &m, `^"`):
				state = swstPlain
			case replacePrefix(&rest, &m, "^`"):
				state = swstDquotBackt
			case replacePrefix(&rest, &m, "^[^$\"\\\\`]+"):
				// just skip
			case replacePrefix(&rest, &m, "^\\\\(?:[\\\\\"`]|\\$\\$)"):
				// just skip
			case replacePrefix(&rest, &m, `^\$\$\{([0-9A-Za-z_]+)\}`),
				replacePrefix(&rest, &m, `^\$\$([0-9A-Z_a-z]+|[!#?@]|\$\$)`):
				shvarname := m[1]
				_ = G.opts.DebugShell && line.debugf("checklineMkShellword: found double-quoted variable %q.", shvarname)
			case replacePrefix(&rest, &m, `^\$\$`):
				line.warnf("Unquoted $ or strange shell variable found.")
			case replacePrefix(&rest, &m, `^\\(.)`):
				char := m[1]
				line.warnf("Please use \"%s\" instead of \"%s\".", "\\\\"+char, "\\"+char)
				line.explain(
					"Although the current code may work, it is not good style to rely on",
					"the shell passing this escape sequence exactly as is, and not",
					"discarding the backslash. Alternatively you can use single quotes",
					"instead of double quotes.")
			default:
				break outer
			}
		}
	}

	if strings.TrimSpace(rest) != "" {
		line.errorf("Internal pkglint error: checklineMkShellword state=%s, rest=%q, shellword=%q", state, rest, shellword)
	}
}

func (msline *MkShellLine) variableNeedsQuoting(shvarname string) bool {
	switch shvarname {
	case "#", "?":
		return false // Definitely ok
	case "d", "f", "i", "dir", "file", "src", "dst":
		return false // Probably ok
	}
	return true
}

type ShelltextContext struct {
	line      *Line
	state     scState
	shellword string
}

func (msline *MkShellLine) checklineMkShelltext(shelltext string) {
	defer tracecall("MkShellLine.checklineMkShelltext", shelltext)()

	line := msline.line

	if contains(shelltext, "${SED}") && contains(shelltext, "${MV}") {
		line.notef("Please use the SUBST framework instead of ${SED} and ${MV}.")
		line.explain(
			"When converting things, pay attention to \"#\" characters. In shell",
			"commands make(1) does not interpret them as comment character, but",
			"in other lines it does. Therefore, instead of the shell command",
			"",
			"\tsed -e 's,#define foo,,'",
			"",
			"you need to write",
			"",
			"\tSUBST_SED.foo+=\t's,\\#define foo,,'")
	}

	if m, cmd := match1(shelltext, `^@*-(.*(?:MKDIR|INSTALL.*-d|INSTALL_.*_DIR).*)`); m {
		line.notef("You don't need to use \"-\" before %q.", cmd)
	}

	rest := shelltext

	setE := false
	var m []string
	if replacePrefix(&rest, &m, `^\s*([-@]*)(\$\{_PKG_SILENT\}\$\{_PKG_DEBUG\}|\$\{RUN\}|)`) {
		hidden, macro := m[1], m[2]
		msline.checkLineStart(hidden, macro, rest, &setE)
	}

	state := scstStart
	for replacePrefix(&rest, &m, reShellword) {
		shellword := m[1]

		_ = G.opts.DebugShell && line.debugf("checklineMkShelltext state=%v shellword=%q", state, shellword)

		{
			quotingNecessary := state != scstCase &&
				state != scstForCont &&
				state != scstSetCont &&
				!(state == scstStart && matches(shellword, reShVarassign))
			msline.checklineMkShellword(shellword, quotingNecessary)
		}

		st := &ShelltextContext{line, state, shellword}
		st.checkCommandStart()
		st.checkConditionalCd()
		if state != scstPaxS && state != scstSedE && state != scstCaseLabel {
			checklineMkAbsolutePathname(line, shellword)
		}
		st.checkAutoMkdirs()
		st.checkInstallMulti()
		st.checkPaxPe()
		st.checkQuoteSubstitution()
		st.checkEchoN()
		st.checkPipeExitcode()
		st.checkSetE(setE)

		if state == scstSet && matches(shellword, `^-.*e`) || state == scstStart && shellword == "${RUN}" {
			setE = true
		}

		state = nextState(line, state, shellword)
	}

	if !matches(rest, `^\s*$`) {
		line.errorf("Internal pkglint error: checklineMkShelltext state=%s rest=%q shellword=%q", state, rest, shelltext)
	}

}

func (msline *MkShellLine) checkLineStart(hidden, macro, rest string, eflag *bool) {
	defer tracecall("MkShellLine.checkLineStart", hidden, macro, rest, eflag)()

	line := msline.line

	switch {
	case !contains(hidden, "@"):
		// Nothing is hidden at all.

	case hasPrefix(G.mkContext.target, "show-") || hasSuffix(G.mkContext.target, "-message"):
		// In these targets commands may be hidden.

	case hasPrefix(rest, "#"):
		// Shell comments may be hidden, since they cannot have side effects.

	default:
		if m, cmd := match1(rest, reShellword); m {
			switch cmd {
			case "${DELAYED_ERROR_MSG}", "${DELAYED_WARNING_MSG}",
				"${DO_NADA}",
				"${ECHO}", "${ECHO_MSG}", "${ECHO_N}", "${ERROR_CAT}", "${ERROR_MSG}",
				"${FAIL_MSG}",
				"${PHASE_MSG}", "${PRINTF}",
				"${SHCOMMENT}", "${STEP_MSG}",
				"${WARNING_CAT}", "${WARNING_MSG}":
			default:
				line.warnf("The shell command %q should not be hidden.", cmd)
				line.explain(
					"Hidden shell commands do not appear on the terminal or in the log file",
					"when they are executed. When they fail, the error message cannot be",
					"assigned to the command, which is very difficult to debug.")
			}
		}
	}

	if contains(hidden, "-") {
		line.warnf("The use of a leading \"-\" to suppress errors is deprecated.")
		line.explain(
			"If you really want to ignore any errors from this command (including",
			"all errors you never thought of), append \"|| ${TRUE}\" to the",
			"command.")
	}

	if macro == "${RUN}" {
		*eflag = true
	}
}

func (ctx *ShelltextContext) checkCommandStart() {
	defer tracecall("ShelltextContext.checkCommandStart", ctx.state, ctx.shellword)()

	line, state, shellword := ctx.line, ctx.state, ctx.shellword
	if state != scstStart && state != scstCond {
		return
	}

	switch {
	case shellword == "${RUN}":
	case ctx.handleForbiddenCommand():
	case ctx.handleTool():
	case ctx.handleCommandVariable():
	case matches(shellword, `^(?:\(|\)|:|;|;;|&&|\|\||\{|\}|break|case|cd|continue|do|done|elif|else|esac|eval|exec|exit|export|fi|for|if|read|set|shift|then|umask|unset|while)$`):
	case matches(shellword, `^[\w_]+=.*$`): // Variable assignment
	case hasPrefix(shellword, "./"): // All commands from the current directory are fine.
	case ctx.handleComment():
	default:
		if G.opts.WarnExtra {
			line.warnf("Unknown shell command %q.", shellword)
			line.explain(
				"If you want your package to be portable to all platforms that pkgsrc",
				"supports, you should only use shell commands that are covered by the",
				"tools framework.")
		}
	}
}

func (ctx *ShelltextContext) handleTool() bool {
	defer tracecall("ShelltextContext.handleTool", ctx.shellword)()

	shellword := ctx.shellword
	if !G.globalData.tools[shellword] {
		return false
	}

	if !G.mkContext.tools[shellword] && !G.mkContext.tools["g"+shellword] {
		ctx.line.warnf("The %q tool is used but not added to USE_TOOLS.", shellword)
	}

	if G.globalData.toolsVarRequired[shellword] {
		ctx.line.warnf("Please use \"${%s}\" instead of %q.", G.globalData.vartools[shellword], shellword)
	}

	checklineMkShellcmdUse(ctx.line, shellword)
	return true
}

func (ctx *ShelltextContext) handleForbiddenCommand() bool {
	switch path.Base(ctx.shellword) {
	case "ktrace", "mktexlsr", "strace", "texconfig", "truss":
	default:
		return false
	}

	ctx.line.errorf("%q must not be used in Makefiles.", ctx.shellword)
	ctx.line.explain(
		"This command must appear in INSTALL scripts, not in the package",
		"Makefile, so that the package also works if it is installed as a binary",
		"package via pkg_add.")
	return true
}

func (ctx *ShelltextContext) handleCommandVariable() bool {
	defer tracecall("ShelltextContext.handleCommandVariable", ctx.shellword)()

	shellword := ctx.shellword
	if m, varname := match1(shellword, `^\$\{([\w_]+)\}$`); m {

		if toolname := G.globalData.varnameToToolname[varname]; toolname != "" {
			if !G.mkContext.tools[toolname] {
				ctx.line.warnf("The %q tool is used but not added to USE_TOOLS.", toolname)
			}
			checklineMkShellcmdUse(ctx.line, shellword)
			return true
		}

		if vartype := getVariableType(ctx.line, varname); vartype != nil && vartype.checker.name == "ShellCommand" {
			checklineMkShellcmdUse(ctx.line, shellword)
			return true
		}

		// When the package author has explicitly defined a command
		// variable, assume it to be valid.
		if G.pkgContext != nil && G.pkgContext.vardef[varname] != nil {
			return true
		}
	}
	return false
}

func (ctx *ShelltextContext) handleComment() bool {
	defer tracecall("ShelltextContext.handleComment", ctx.shellword)()

	shellword := ctx.shellword
	if !hasPrefix(shellword, "#") {
		return false
	}

	line := ctx.line
	semicolon := contains(shellword, ";")
	multiline := contains(line.lines, "--")

	if semicolon {
		line.warnf("A shell comment should not contain semicolons.")
	}
	if multiline {
		line.warnf("A shell comment does not stop at the end of line.")
	}

	if semicolon || multiline {
		line.explain(
			"When you split a shell command into multiple lines that are continued",
			"with a backslash, they will nevertheless be converted to a single line",
			"before the shell sees them. That means that even if it _looks_ like that",
			"the comment only spans one line in the Makefile, in fact it spans until",
			"the end of the whole shell command. To insert a comment into shell code,",
			"you can pass it as an argument to the ${SHCOMMENT} macro, which expands",
			"to a command doing nothing. Note that any special characters are",
			"nevertheless interpreted by the shell.")
	}
	return true
}

func (ctx *ShelltextContext) checkConditionalCd() {
	line, state, shellword := ctx.line, ctx.state, ctx.shellword

	if state == scstCond && shellword == "cd" {
		line.errorf("The Solaris /bin/sh cannot handle \"cd\" inside conditionals.")
		line.explain(
			"When the Solaris shell is in \"set -e\" mode and \"cd\" fails, the",
			"shell will exit, no matter if it is protected by an \"if\" or the",
			"\"||\" operator.")
	}
}

func (ctx *ShelltextContext) checkAutoMkdirs() {
	line, state, shellword := ctx.line, ctx.state, ctx.shellword

	if (state == scstInstallD || state == scstMkdir) && matches(shellword, `^(?:\$\{DESTDIR\})?\$\{PREFIX(?:|:Q)\}/`) {
		line.warnf("Please use AUTO_MKDIRS instead of %q.",
			ifelseStr(state == scstMkdir, "${MKDIR}", "${INSTALL} -d"))
		line.explain(
			"Setting AUTO_MKDIRS=yes automatically creates all directories that are",
			"mentioned in the PLIST. If you need additional directories, specify",
			"them in INSTALLATION_DIRS, which is a list of directories relative to",
			"${PREFIX}.")
	}

	if (state == scstInstallDir || state == scstInstallDir2) && !matches(shellword, reMkShellvaruse) {
		if m, dirname := match1(shellword, `^(?:\$\{DESTDIR\})?\$\{PREFIX(?:|:Q)\}/(.*)`); m {
			line.notef("You can use AUTO_MKDIRS=yes or \"INSTALLATION_DIRS+= %s\" instead of this command.", dirname)
			line.explain(
				"This saves you some typing. You also don't have to think about which of",
				"the many INSTALL_*_DIR macros is appropriate, since INSTALLATION_DIRS",
				"takes care of that.",
				"",
				"Note that you should only do this if the package creates _all_",
				"directories it needs before trying to install files into them.",
				"",
				"Many packages include a list of all needed directories in their PLIST",
				"file. In that case, you can just set AUTO_MKDIRS=yes and be done.")
		}
	}
}

func (ctx *ShelltextContext) checkInstallMulti() {
	line, state, shellword := ctx.line, ctx.state, ctx.shellword

	if state == scstInstallDir2 && hasPrefix(shellword, "$") {
		line.warnf("The INSTALL_*_DIR commands can only handle one directory at a time.")
		line.explain(
			"Many implementations of install(1) can handle more, but pkgsrc aims at",
			"maximum portability.")
	}
}

func (ctx *ShelltextContext) checkPaxPe() {
	line, state, shellword := ctx.line, ctx.state, ctx.shellword

	if state == scstPax && shellword == "-pe" {
		line.warnf("Please use the -pp option to pax(1) instead of -pe.")
		line.explain(
			"The -pe option tells pax to preserve the ownership of the files, which",
			"means that the installed files will belong to the user that has built",
			"the package.")
	}
}

func (ctx *ShelltextContext) checkQuoteSubstitution() {
	line, state, shellword := ctx.line, ctx.state, ctx.shellword

	if state == scstPaxS || state == scstSedE {
		if false && !matches(shellword, `"^[\"\'].*[\"\']$`) {
			line.warnf("Substitution commands like %q should always be quoted.", shellword)
			line.explain(
				"Usually these substitution commands contain characters like '*' or",
				"other shell metacharacters that might lead to lookup of matching",
				"filenames and then expand to more than one word.")
		}
	}
}

func (ctx *ShelltextContext) checkEchoN() {
	line, state, shellword := ctx.line, ctx.state, ctx.shellword

	if state == scstEcho && shellword == "-n" {
		line.warnf("Please use ${ECHO_N} instead of \"echo -n\".")
	}
}

func (ctx *ShelltextContext) checkPipeExitcode() {
	line, state, shellword := ctx.line, ctx.state, ctx.shellword

	if G.opts.WarnExtra && state != scstCaseLabelCont && shellword == "|" {
		line.warnf("The exitcode of the left-hand-side command of the pipe operator is ignored.")
		line.explain(
			"In a shell command like \"cat *.txt | grep keyword\", if the command",
			"on the left side of the \"|\" fails, this failure is ignored.",
			"",
			"If you need to detect the failure of the left-hand-side command, use",
			"temporary files to save the output of the command.")
	}
}

func (ctx *ShelltextContext) checkSetE(eflag bool) {
	line, state, shellword := ctx.line, ctx.state, ctx.shellword

	if G.opts.WarnExtra && shellword == ";" && state != scstCondCont && state != scstForCont && !eflag {
		line.warnf("Please switch to \"set -e\" mode before using a semicolon to separate commands.")
		line.explain(
			"Older versions of the NetBSD make(1) had run the shell commands using",
			"the \"-e\" option of /bin/sh. In 2004, this behavior has been changed to",
			"follow the POSIX conventions, which is to not use the \"-e\" option.",
			"The consequence of this change is that shell programs don't terminate",
			"as soon as an error occurs, but try to continue with the next command.",
			"Imagine what would happen for these commands:",
			"    cd \"HOME\"; cd /nonexistent; rm -rf *",
			"To fix this warning, either insert \"set -e\" at the beginning of this",
			"line or use the \"&&\" operator instead of the semicolon.")
	}
}

// Some shell commands should not be used in the install phase.
func (msline *MkShellLine) checkCommandUse(shellcmd string) {
	line := msline.line

	if G.mkContext == nil || !matches(G.mkContext.target, `^(?:pre|do|post)-install$`) {
		return
	}

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
		line.warnf("The shell command %q should not be used in the install phase.", shellcmd)
		line.explain(
			"In the install phase, the only thing that should be done is to install",
			"the prepared files to their final location. The file's contents should",
			"not be changed anymore.")

	case "cp", "${CP}":
		line.warnf("${CP} should not be used to install files.")
		line.explain(
			"The ${CP} command is highly platform dependent and cannot overwrite",
			"files that don't have write permission. Please use ${PAX} instead.",
			"",
			"For example, instead of",
			"\t${CP} -R ${WRKSRC}/* ${PREFIX}/foodir",
			"you should use",
			"\tcd ${WRKSRC} && ${PAX} -wr * ${PREFIX}/foodir")
	}
}

func nextState(line *Line, state scState, shellword string) scState {
	switch {
	case shellword == ";;":
		return scstCaseLabel
	case state == scstCaseLabelCont && shellword == "|":
		return scstCaseLabel
	case matches(shellword, `^[;&\|]+$`):
		return scstStart
	case state == scstStart:
		switch shellword {
		case "${INSTALL}":
			return scstInstall
		case "${MKDIR}":
			return scstMkdir
		case "${PAX}":
			return scstPax
		case "${SED}":
			return scstSed
		case "${ECHO}", "echo":
			return scstEcho
		case "${RUN}", "then", "else", "do", "(":
			return scstStart
		case "set":
			return scstSet
		case "if", "elif", "while":
			return scstCond
		case "case":
			return scstCase
		case "for":
			return scstFor
		default:
			switch {
			case matches(shellword, `^\$\{INSTALL_[A-Z]+_DIR\}$`):
				return scstInstallDir
			case matches(shellword, reShVarassign):
				return scstStart
			default:
				return scstCont
			}
		}
	case state == scstMkdir:
		return scstMkdir
	case state == scstInstall && shellword == "-d":
		return scstInstallD
	case state == scstInstall, state == scstInstallD:
		if matches(shellword, `^-[ogm]$`) {
			return scstCont // XXX: why not keep the state?
		}
		return state
	case state == scstInstallDir && hasPrefix(shellword, "-"):
		return scstCont
	case state == scstInstallDir && hasPrefix(shellword, "$"):
		return scstInstallDir2
	case state == scstInstallDir || state == scstInstallDir2:
		return state
	case state == scstPax && shellword == "-s":
		return scstPaxS
	case state == scstPax && hasPrefix(shellword, "-"):
		return scstPax
	case state == scstPax:
		return scstCont
	case state == scstPaxS:
		return scstPax
	case state == scstSed && shellword == "-e":
		return scstSedE
	case state == scstSed && hasPrefix(shellword, "-"):
		return scstSed
	case state == scstSed:
		return scstCont
	case state == scstSedE:
		return scstSed
	case state == scstSet:
		return scstSetCont
	case state == scstSetCont:
		return scstSetCont
	case state == scstCase:
		return scstCaseIn
	case state == scstCaseIn && shellword == "in":
		return scstCaseLabel
	case state == scstCaseLabel && shellword == "esac":
		return scstCont
	case state == scstCaseLabel:
		return scstCaseLabelCont
	case state == scstCaseLabelCont && shellword == ")":
		return scstStart
	case state == scstCont:
		return scstCont
	case state == scstCond:
		return scstCondCont
	case state == scstCondCont:
		return scstCondCont
	case state == scstFor:
		return scstForIn
	case state == scstForIn && shellword == "in":
		return scstForCont
	case state == scstForCont:
		return scstForCont
	case state == scstEcho:
		return scstCont
	default:
		_ = G.opts.DebugShell && line.errorf("Internal pkglint error: shellword.nextState state=%s shellword=%q", state, shellword)
		return scstStart
	}
}

func splitIntoShellwords(line *Line, text string) ([]string, string) {
	var words []string

	rest := text
	var m []string
	for replacePrefix(&rest, &m, reShellword) {
		words = append(words, m[1])
	}

	rest = strings.TrimLeftFunc(rest, unicode.IsSpace)
	return words, rest
}
