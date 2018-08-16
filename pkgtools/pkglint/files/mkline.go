package main

// Checks concerning single lines in Makefiles.

import (
	"fmt"
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/trace"
	"path"
	"strings"
)

// MkLine is a line from a Makefile fragment.
// There are several types of lines.
// The most common types in pkgsrc are variable assignments,
// shell commands and preprocessor instructions.
type MkLine = *MkLineImpl

type MkLineImpl struct {
	Line
	data interface{} // One of the following mkLine* types
}
type mkLineAssign struct {
	commented  bool       // Whether the whole variable assignment is commented out
	varname    string     // e.g. "HOMEPAGE", "SUBST_SED.perl"
	varcanon   string     // e.g. "HOMEPAGE", "SUBST_SED.*"
	varparam   string     // e.g. "", "perl"
	op         MkOperator //
	valueAlign string     // The text up to and including the assignment operator, e.g. VARNAME+=\t
	value      string     // The trimmed value
	comment    string
}
type mkLineShell struct {
	command string
}
type mkLineComment struct{}
type mkLineEmpty struct{}
type mkLineDirective struct {
	indent    string
	directive string
	args      string
	comment   string
	elseLine  MkLine // (filled in later)
}
type mkLineInclude struct {
	mustExist       bool
	sys             bool
	indent          string
	includeFile     string
	conditionalVars string // (filled in later)
}
type mkLineDependency struct {
	targets string
	sources string
}

func NewMkLine(line Line) *MkLineImpl {
	text := line.Text

	if hasPrefix(text, " ") {
		line.Warnf("Makefile lines should not start with space characters.")
		Explain(
			"If you want this line to contain a shell program, use a tab",
			"character for indentation.  Otherwise please remove the leading",
			"white-space.")
	}

	if m, commented, varname, spaceAfterVarname, op, valueAlign, value, spaceAfterValue, comment := MatchVarassign(text); m {
		if G.opts.WarnSpace && spaceAfterVarname != "" {
			switch {
			case hasSuffix(varname, "+") && op == "=":
				break
			case matches(varname, `^[a-z]`) && op == ":=":
				break
			default:
				fix := line.Autofix()
				fix.Warnf("Unnecessary space after variable name %q.", varname)
				fix.Replace(varname+spaceAfterVarname+op, varname+op)
				fix.Apply()
			}
		}

		if comment != "" && value != "" && spaceAfterValue == "" {
			line.Warnf("The # character starts a comment.")
			Explain(
				"In a variable assignment, an unescaped # starts a comment that",
				"continues until the end of the line.  To escape the #, write \\#.")
		}

		value = strings.Replace(value, "\\#", "#", -1)
		varparam := varnameParam(varname)

		return &MkLineImpl{line, mkLineAssign{
			commented,
			varname,
			varnameCanon(varname),
			varparam,
			NewMkOperator(op),
			valueAlign,
			value,
			comment}}
	}

	if hasPrefix(text, "\t") {
		shellcmd := text[1:]
		return &MkLineImpl{line, mkLineShell{shellcmd}}
	}

	trimmedText := strings.TrimSpace(text)
	if strings.HasPrefix(trimmedText, "#") {
		return &MkLineImpl{line, mkLineComment{}}
	}

	if trimmedText == "" {
		return &MkLineImpl{line, mkLineEmpty{}}
	}

	if m, indent, directive, args, comment := matchMkDirective(text); m {
		return &MkLineImpl{line, mkLineDirective{indent, directive, args, comment, nil}}
	}

	if m, indent, directive, includefile := MatchMkInclude(text); m {
		return &MkLineImpl{line, mkLineInclude{directive == "include", false, indent, includefile, ""}}
	}

	if m, indent, directive, includefile := match3(text, `^\.(\s*)(s?include)\s+<([^>]+)>\s*(?:#.*)?$`); m {
		return &MkLineImpl{line, mkLineInclude{directive == "include", true, indent, includefile, ""}}
	}

	if m, targets, whitespace, sources := match3(text, `^([^\s:]+(?:\s*[^\s:]+)*)(\s*):\s*([^#]*?)(?:\s*#.*)?$`); m {
		if whitespace != "" {
			line.Warnf("Space before colon in dependency line.")
		}
		return &MkLineImpl{line, mkLineDependency{targets, sources}}
	}

	if matches(text, `^(<<<<<<<|=======|>>>>>>>)`) {
		return &MkLineImpl{line, nil}
	}

	line.Errorf("Unknown Makefile line format.")
	return &MkLineImpl{line, nil}
}

func (mkline *MkLineImpl) String() string {
	return fmt.Sprintf("%s:%s", mkline.Filename, mkline.Linenos())
}

func (mkline *MkLineImpl) IsVarassign() bool {
	data, ok := mkline.data.(mkLineAssign)
	return ok && !data.commented
}

// IsCommentedVarassign returns true for commented-out variable assignments.
// In most cases these are treated as ordinary comments, but in some others
// they are treated like variable assignments, just inactive ones.
func (mkline *MkLineImpl) IsCommentedVarassign() bool {
	data, ok := mkline.data.(mkLineAssign)
	return ok && data.commented
}

// IsShellCommand returns true for tab-indented lines that are assigned to a Make
// target. Example:
//
//  pre-configure:    # IsDependency
//          ${ECHO}   # IsShellCommand
func (mkline *MkLineImpl) IsShellCommand() bool {
	_, ok := mkline.data.(mkLineShell)
	return ok
}

func (mkline *MkLineImpl) IsComment() bool {
	_, ok := mkline.data.(mkLineComment)
	return ok || mkline.IsCommentedVarassign()
}

func (mkline *MkLineImpl) IsEmpty() bool {
	_, ok := mkline.data.(mkLineEmpty)
	return ok
}

// IsDirective checks whether the line is a conditional (.if/.elif/.else/.if) or a loop (.for/.endfor).
func (mkline *MkLineImpl) IsDirective() bool {
	_, ok := mkline.data.(mkLineDirective)
	return ok
}

func (mkline *MkLineImpl) IsInclude() bool {
	incl, ok := mkline.data.(mkLineInclude)
	return ok && !incl.sys
}
func (mkline *MkLineImpl) IsSysinclude() bool {
	incl, ok := mkline.data.(mkLineInclude)
	return ok && incl.sys
}
func (mkline *MkLineImpl) IsDependency() bool {
	_, ok := mkline.data.(mkLineDependency)
	return ok
}

// Varname applies to variable assignments and returns the name
// of the variable that is assigned or appended to.
//
// Example:
//  VARNAME?=       value
func (mkline *MkLineImpl) Varname() string { return mkline.data.(mkLineAssign).varname }

// Varcanon applies to variable assignments and returns the canonicalized variable name for parameterized variables.
// Examples:
//  HOMEPAGE           => HOMEPAGE
//  SUBST_SED.anything => SUBST_SED.*
func (mkline *MkLineImpl) Varcanon() string { return mkline.data.(mkLineAssign).varcanon }

// Varparam applies to variable assignments and returns the parameter for parameterized variables.
// Examples:
//  HOMEPAGE           => ""
//  SUBST_SED.anything => anything
func (mkline *MkLineImpl) Varparam() string { return mkline.data.(mkLineAssign).varparam }

// Op applies to variable assignments and returns the assignment operator.
func (mkline *MkLineImpl) Op() MkOperator { return mkline.data.(mkLineAssign).op }

// ValueAlign applies to variable assignments and returns all the text
// before the variable value, e.g. "VARNAME+=\t".
func (mkline *MkLineImpl) ValueAlign() string { return mkline.data.(mkLineAssign).valueAlign }
func (mkline *MkLineImpl) Value() string      { return mkline.data.(mkLineAssign).value }

// VarassignComment applies to variable assignments and returns the comment.
// Example:
//  VAR=value # comment
// In the above line, the comment is "# comment".
// The leading "#" is included so that pkglint can distinguish between no comment at all and an empty comment.
func (mkline *MkLineImpl) VarassignComment() string { return mkline.data.(mkLineAssign).comment }
func (mkline *MkLineImpl) ShellCommand() string     { return mkline.data.(mkLineShell).command }
func (mkline *MkLineImpl) Indent() string {
	if mkline.IsDirective() {
		return mkline.data.(mkLineDirective).indent
	} else {
		return mkline.data.(mkLineInclude).indent
	}
}

// Directive returns one of "if", "ifdef", "ifndef", "else", "elif", "endif", "for", "endfor", "undef".
//
// See matchMkDirective.
func (mkline *MkLineImpl) Directive() string { return mkline.data.(mkLineDirective).directive }

// Args returns the arguments from an .if, .ifdef, .ifndef, .elif, .for, .undef.
func (mkline *MkLineImpl) Args() string { return mkline.data.(mkLineDirective).args }

// DirectiveComment is the trailing end-of-line comment, typically at a deeply nested .endif or .endfor.
func (mkline *MkLineImpl) DirectiveComment() string { return mkline.data.(mkLineDirective).comment }
func (mkline *MkLineImpl) HasElseBranch() bool      { return mkline.data.(mkLineDirective).elseLine != nil }
func (mkline *MkLineImpl) SetHasElseBranch(elseLine MkLine) {
	data := mkline.data.(mkLineDirective)
	data.elseLine = elseLine
	mkline.data = data
}

func (mkline *MkLineImpl) MustExist() bool     { return mkline.data.(mkLineInclude).mustExist }
func (mkline *MkLineImpl) IncludeFile() string { return mkline.data.(mkLineInclude).includeFile }

func (mkline *MkLineImpl) Targets() string { return mkline.data.(mkLineDependency).targets }
func (mkline *MkLineImpl) Sources() string { return mkline.data.(mkLineDependency).sources }

// ConditionalVars is a space-separated list of those variable names
// on which the inclusion depends. It is initialized later,
// step by step, when parsing other lines
func (mkline *MkLineImpl) ConditionalVars() string { return mkline.data.(mkLineInclude).conditionalVars }
func (mkline *MkLineImpl) SetConditionalVars(varnames string) {
	include := mkline.data.(mkLineInclude)
	include.conditionalVars = varnames
	mkline.data = include
}

// Tokenize extracts variable uses and other text from the string.
//
// Example:
//  input:  ${PREFIX}/bin abc
//  output: [MkToken("${PREFIX}", MkVarUse("PREFIX")), MkToken("/bin abc")]
func (mkline *MkLineImpl) Tokenize(s string) []*MkToken {
	if trace.Tracing {
		defer trace.Call(mkline, s)()
	}

	p := NewMkParser(mkline.Line, s, true)
	tokens := p.MkTokens()
	if p.Rest() != "" {
		mkline.Warnf("Pkglint parse error in MkLine.Tokenize at %q.", p.Rest())
	}
	return tokens
}

// ValueSplit splits the variable value of an assignment line,
// taking care of variable references. For example, when the value
// "/bin:${PATH:S,::,::,}" is split at ":", it results in
// {"/bin", "${PATH:S,::,::,}"}.
//
// If the separator is empty, splitting is done on whitespace.
func (mkline *MkLineImpl) ValueSplit(value string, separator string) []string {
	tokens := mkline.Tokenize(value)
	var split []string
	for _, token := range tokens {
		if split == nil {
			split = []string{""}
		}
		if token.Varuse == nil && contains(token.Text, separator) {
			var subs []string
			if separator == "" {
				subs = splitOnSpace(token.Text)
			} else {
				subs = strings.Split(token.Text, separator)
			}
			split[len(split)-1] += subs[0]
			split = append(split, subs[1:]...)
		} else {
			split[len(split)-1] += token.Text
		}
	}
	return split
}

func (mkline *MkLineImpl) WithoutMakeVariables(value string) string {
	valueNovar := value
	for {
		var m []string
		// TODO: properly parse nested variables
		m, valueNovar = regex.ReplaceFirst(valueNovar, `\$\{[^{}]*\}`, "")
		if m == nil {
			return valueNovar
		}
	}
}

func (mkline *MkLineImpl) ResolveVarsInRelativePath(relativePath string, adjustDepth bool) string {

	var basedir string
	if G.Pkg != nil {
		basedir = G.Pkg.File(".")
	} else {
		basedir = path.Dir(mkline.Filename)
	}
	pkgsrcdir := relpath(basedir, G.Pkgsrc.File("."))

	tmp := relativePath
	tmp = strings.Replace(tmp, "${PKGSRCDIR}", pkgsrcdir, -1)
	tmp = strings.Replace(tmp, "${.CURDIR}", ".", -1)
	tmp = strings.Replace(tmp, "${.PARSEDIR}", ".", -1)
	if contains(tmp, "${LUA_PKGSRCDIR}") {
		tmp = strings.Replace(tmp, "${LUA_PKGSRCDIR}", G.Pkgsrc.Latest("lang", `^lua[0-9]+$`, "../../lang/$0"), -1)
	}
	if contains(tmp, "${PHPPKGSRCDIR}") {
		tmp = strings.Replace(tmp, "${PHPPKGSRCDIR}", G.Pkgsrc.Latest("lang", `^php[0-9]+$`, "../../lang/$0"), -1)
	}
	if contains(tmp, "${SUSE_DIR_PREFIX}") {
		suseDirPrefix := G.Pkgsrc.Latest("emulators", `^(suse[0-9]+)_base`, "$1")
		tmp = strings.Replace(tmp, "${SUSE_DIR_PREFIX}", suseDirPrefix, -1)
	}
	if contains(tmp, "${PYPKGSRCDIR}") {
		tmp = strings.Replace(tmp, "${PYPKGSRCDIR}", G.Pkgsrc.Latest("lang", `^python[0-9]+$`, "../../lang/$0"), -1)
	}
	if contains(tmp, "${PYPACKAGE}") {
		tmp = strings.Replace(tmp, "${PYPACKAGE}", G.Pkgsrc.Latest("lang", `^python[0-9]+$`, "$0"), -1)
	}
	if G.Pkg != nil {
		tmp = strings.Replace(tmp, "${FILESDIR}", G.Pkg.Filesdir, -1)
		tmp = strings.Replace(tmp, "${PKGDIR}", G.Pkg.Pkgdir, -1)
	}

	if adjustDepth {
		if m, pkgpath := match1(tmp, `^\.\./\.\./([^.].*)$`); m {
			tmp = pkgsrcdir + "/" + pkgpath
		}
	}

	tmp = cleanpath(tmp)

	if trace.Tracing {
		trace.Step2("resolveVarsInRelativePath: %q => %q", relativePath, tmp)
	}
	return tmp
}

func (ind *Indentation) RememberUsedVariables(cond MkCond) {
	NewMkCondWalker().Walk(cond, &MkCondCallback{
		Defined: func(varname string) {
			ind.AddVar(varname)
		},
		Empty: func(varuse *MkVarUse) {
			ind.AddVar(varuse.varname)
		},
		CompareVarNum: func(varuse *MkVarUse, op string, num string) {
			ind.AddVar(varuse.varname)
		},
		CompareVarStr: func(varuse *MkVarUse, op string, str string) {
			ind.AddVar(varuse.varname)
		},
		CompareVarVar: func(left *MkVarUse, op string, right *MkVarUse) {
			ind.AddVar(left.varname)
			ind.AddVar(right.varname)
		}})
}

func (mkline *MkLineImpl) ExplainRelativeDirs() {
	Explain(
		"Directories in the form \"../../category/package\" make it easier to",
		"move a package around in pkgsrc, for example from pkgsrc-wip to the",
		"main pkgsrc repository.")
}

func matchMkDirective(text string) (m bool, indent, directive, args, comment string) {
	i, n := 0, len(text)
	if i < n && text[i] == '.' {
		i++
	} else {
		return
	}

	indentStart := i
	for i < n && (text[i] == ' ' || text[i] == '\t') {
		i++
	}
	indentEnd := i

	directiveStart := i
	for i < n && 'a' <= text[i] && text[i] <= 'z' {
		i++
	}
	directiveEnd := i
	directive = text[directiveStart:directiveEnd]
	switch directive {
	case "if", "ifdef", "ifndef", "else", "elif", "endif", "for", "endfor", "undef":
		break
	default:
		return
	}

	for i < n && (text[i] == ' ' || text[i] == '\t') {
		i++
	}

	argsStart := i
	for i < n && (text[i] != '#' || text[i-1] == '\\') {
		i++
	}
	commentStart := i
	if commentStart < n {
		commentStart++
		for commentStart < n && (text[commentStart] == ' ' || text[commentStart] == '\t') {
			commentStart++
		}
	}
	for i > argsStart && (text[i-1] == ' ' || text[i-1] == '\t') {
		i--
	}
	argsEnd := i

	m = true
	indent = text[indentStart:indentEnd]
	args = strings.Replace(text[argsStart:argsEnd], "\\#", "#", -1)
	comment = text[commentStart:]
	return
}

type NeedsQuoting uint8

const (
	nqNo NeedsQuoting = iota
	nqYes
	nqDoesntMatter
	nqDontKnow
)

func (nq NeedsQuoting) String() string {
	return [...]string{"no", "yes", "doesn't matter", "don't know"}[nq]
}

func (mkline *MkLineImpl) VariableNeedsQuoting(varname string, vartype *Vartype, vuc *VarUseContext) (needsQuoting NeedsQuoting) {
	if trace.Tracing {
		defer trace.Call(varname, vartype, vuc, "=>", &needsQuoting)()
	}

	if vartype == nil || vuc.vartype == nil {
		return nqDontKnow
	}

	if vartype.basicType.IsEnum() || vartype.IsBasicSafe() {
		if vartype.kindOfList == lkNone {
			if vartype.guessed {
				return nqDontKnow
			}
			return nqDoesntMatter
		}
		if vartype.kindOfList == lkShell && !vuc.IsWordPart {
			return nqNo
		}
	}

	// In .for loops, the :Q operator is always misplaced, since
	// the items are broken up at white-space, not as shell words
	// like in all other parts of make(1).
	if vuc.quoting == vucQuotFor {
		return nqNo
	}

	// A shell word may appear as part of a shell word, for example COMPILER_RPATH_FLAG.
	if vuc.IsWordPart && vuc.quoting == vucQuotPlain {
		if vartype.kindOfList == lkNone && vartype.basicType == BtShellWord {
			return nqNo
		}
	}

	// Determine whether the context expects a list of shell words or not.
	wantList := vuc.vartype.IsConsideredList()
	haveList := vartype.IsConsideredList()
	if trace.Tracing {
		trace.Stepf("wantList=%v, haveList=%v", wantList, haveList)
	}

	// Both of these can be correct, depending on the situation:
	// 1. echo ${PERL5:Q}
	// 2. xargs ${PERL5}
	if !vuc.IsWordPart && vuc.quoting == vucQuotPlain {
		if wantList && haveList {
			return nqDontKnow
		}
	}

	// Pkglint assumes that the tool definitions don't include very
	// special characters, so they can safely be used inside any quotes.
	if G.Pkgsrc.Tools.ByVarname(varname) != nil {
		switch vuc.quoting {
		case vucQuotPlain:
			if !vuc.IsWordPart {
				return nqNo
			}
		case vucQuotBackt:
			return nqNo
		case vucQuotDquot, vucQuotSquot:
			return nqDoesntMatter
		}
	}

	// Variables that appear as parts of shell words generally need
	// to be quoted. An exception is in the case of backticks,
	// because the whole backticks expression is parsed as a single
	// shell word by pkglint.
	if vuc.IsWordPart && vuc.vartype != nil && vuc.vartype.IsShell() && vuc.quoting != vucQuotBackt {
		return nqYes
	}

	// SUBST_MESSAGE.perl= Replacing in ${REPLACE_PERL}
	if vuc.vartype != nil && vuc.vartype.IsPlainString() {
		return nqNo
	}

	if wantList != haveList {
		if vuc.vartype != nil && vartype != nil {
			if vuc.vartype.basicType == BtFetchURL && vartype.basicType == BtHomepage {
				return nqNo
			}
			if vuc.vartype.basicType == BtHomepage && vartype.basicType == BtFetchURL {
				return nqNo // Just for HOMEPAGE=${MASTER_SITE_*:=subdir/}.
			}
		}
		return nqYes
	}

	// Bad: LDADD += -l${LIBS}
	// Good: LDADD += ${LIBS:@lib@-l${lib} @}
	if wantList && haveList && vuc.IsWordPart {
		return nqYes
	}

	if trace.Tracing {
		trace.Step1("Don't know whether :Q is needed for %q", varname)
	}
	return nqDontKnow
}

// Returns the type of the variable (possibly guessed based on the variable name),
// or nil if the type cannot even be guessed.
func (mkline *MkLineImpl) VariableType(varname string) *Vartype {
	if trace.Tracing {
		defer trace.Call1(varname)()
	}

	if vartype := G.Pkgsrc.vartypes[varname]; vartype != nil {
		return vartype
	}
	if vartype := G.Pkgsrc.vartypes[varnameCanon(varname)]; vartype != nil {
		return vartype
	}

	if tool := G.Pkgsrc.Tools.ByVarname(varname); tool != nil {
		perms := aclpUse
		if trace.Tracing {
			trace.Stepf("Use of tool %+v", tool)
		}
		if tool.UsableAtLoadTime {
			if G.Pkg == nil || G.Pkg.SeenBsdPrefsMk || G.Pkg.loadTimeTools[tool.Name] {
				perms |= aclpUseLoadtime
			}
		}
		return &Vartype{lkNone, BtShellCommand, []ACLEntry{{"*", perms}}, false}
	}

	m, toolvarname := match1(varname, `^TOOLS_(.*)`)
	if m && G.Pkgsrc.Tools.ByVarname(toolvarname) != nil {
		return &Vartype{lkNone, BtPathname, []ACLEntry{{"*", aclpUse}}, false}
	}

	allowAll := []ACLEntry{{"*", aclpAll}}
	allowRuntime := []ACLEntry{{"*", aclpAllRuntime}}

	// Guess the data type of the variable based on naming conventions.
	varbase := varnameBase(varname)
	var gtype *Vartype
	switch {
	case hasSuffix(varbase, "DIRS"):
		gtype = &Vartype{lkShell, BtPathmask, allowRuntime, true}
	case hasSuffix(varbase, "DIR") && !hasSuffix(varbase, "DESTDIR"), hasSuffix(varname, "_HOME"):
		gtype = &Vartype{lkNone, BtPathname, allowRuntime, true}
	case hasSuffix(varbase, "FILES"):
		gtype = &Vartype{lkShell, BtPathmask, allowRuntime, true}
	case hasSuffix(varbase, "FILE"):
		gtype = &Vartype{lkNone, BtPathname, allowRuntime, true}
	case hasSuffix(varbase, "PATH"):
		gtype = &Vartype{lkNone, BtPathlist, allowRuntime, true}
	case hasSuffix(varbase, "PATHS"):
		gtype = &Vartype{lkShell, BtPathname, allowRuntime, true}
	case hasSuffix(varbase, "_USER"):
		gtype = &Vartype{lkNone, BtUserGroupName, allowAll, true}
	case hasSuffix(varbase, "_GROUP"):
		gtype = &Vartype{lkNone, BtUserGroupName, allowAll, true}
	case hasSuffix(varbase, "_ENV"):
		gtype = &Vartype{lkShell, BtShellWord, allowRuntime, true}
	case hasSuffix(varbase, "_CMD"):
		gtype = &Vartype{lkNone, BtShellCommand, allowRuntime, true}
	case hasSuffix(varbase, "_ARGS"):
		gtype = &Vartype{lkShell, BtShellWord, allowRuntime, true}
	case hasSuffix(varbase, "_CFLAGS"), hasSuffix(varname, "_CPPFLAGS"), hasSuffix(varname, "_CXXFLAGS"):
		gtype = &Vartype{lkShell, BtCFlag, allowRuntime, true}
	case hasSuffix(varname, "_LDFLAGS"):
		gtype = &Vartype{lkShell, BtLdFlag, allowRuntime, true}
	case hasSuffix(varbase, "_MK"):
		gtype = &Vartype{lkNone, BtUnknown, allowAll, true}
	}

	if trace.Tracing {
		if gtype != nil {
			trace.Step2("The guessed type of %q is %q.", varname, gtype.String())
		} else {
			trace.Step1("No type definition found for %q.", varname)
		}
	}
	return gtype
}

// TODO: merge with determineUsedVariables
func (mkline *MkLineImpl) ExtractUsedVariables(text string) []string {
	re := regex.Compile(`^(?:[^\$]+|\$[\$*<>?@]|\$\{([.0-9A-Z_a-z]+)(?::(?:[^\${}]|\$[^{])+)?\})`)
	rest := text
	var result []string
	for {
		m := re.FindStringSubmatchIndex(rest)
		if m == nil {
			break
		}
		varname := rest[negToZero(m[2]):negToZero(m[3])]
		rest = rest[:m[0]] + rest[m[1]:]
		if varname != "" {
			result = append(result, varname)
		}
	}

	if trace.Tracing && rest != "" {
		trace.Step1("extractUsedVariables: rest=%q", rest)
	}
	return result
}

func (mkline *MkLineImpl) DetermineUsedVariables() (varnames []string) {
	rest := mkline.Text

	if strings.HasPrefix(rest, "#") {
		return
	}

	for {
		p1 := strings.Index(rest, "${")
		p2 := strings.Index(rest, "$(")
		p3 := strings.Index(rest, "defined(")
		p4 := strings.Index(rest, "empty(")
		if p1 == -1 && p2 == -1 && p3 == -1 && p4 == -1 {
			return
		}
		min := -1
		if min == -1 || (p1 != -1 && p1 < min) {
			min = p1
		}
		if min == -1 || (p2 != -1 && p2 < min) {
			min = p2
		}
		if min == -1 || (p3 != -1 && p3 < min) {
			min = p3
		}
		if min == -1 || (p4 != -1 && p4 < min) {
			min = p4
		}
		rest = rest[min:]

		m := regex.Compile(`(?:\$\{|\$\(|defined\(|empty\()([*+\-.0-9A-Z_a-z]+)[:})]`).FindStringSubmatchIndex(rest)
		if m == nil {
			return
		}
		varname := rest[m[2]:m[3]]
		varnames = append(varnames, varname)
		rest = rest[:m[0]] + rest[m[1]:]
	}
}

// VarUseContext defines the context in which a variable is defined
// or used. Whether that is allowed depends on:
//
// * The variable's data type, as defined in vardefs.go.
//
// * When used on the right-hand side of an assigment, the variable can
// represent a list of words, a single word or even only part of a
// word. This distinction decides upon the correct use of the :Q
// operator.
//
// * When used in preprocessing statements like .if or .for, the other
// operands of that statement should fit to the variable and are
// checked against the variable type. For example, comparing OPSYS to
// x86_64 doesn't make sense.
type VarUseContext struct {
	vartype    *Vartype
	time       vucTime
	quoting    vucQuoting
	IsWordPart bool // Example: echo ${LOCALBASE} LOCALBASE=${LOCALBASE}
}

type vucTime uint8

const (
	vucTimeUnknown vucTime = iota

	// When Makefiles are loaded, the operators := and != evaluate their
	// right-hand side, as well as the directives .if, .elif and .for.
	// During loading, not all variables are available yet.
	// Variable values are still subject to change, especially lists.
	vucTimeParse

	// All files have been read, all variables can be referenced.
	// Variable values don't change anymore.
	vucTimeRun
)

func (t vucTime) String() string { return [...]string{"unknown", "parse", "run"}[t] }

// The quoting context in which the variable is used.
// Depending on this context, the modifiers :Q or :M can be allowed or not.
type vucQuoting uint8

const (
	vucQuotUnknown vucQuoting = iota
	vucQuotPlain              // Example: echo LOCALBASE=${LOCALBASE}
	vucQuotDquot              // Example: echo "The version is ${PKGVERSION}."
	vucQuotSquot              // Example: echo 'The version is ${PKGVERSION}.'
	vucQuotBackt              // Example: echo \`sed 1q ${WRKSRC}/README\`

	// The .for loop in Makefiles. This is the only place where
	// variables are split on whitespace. Everywhere else (:Q, :M)
	// they are split like in the shell.
	//
	// Example: .for f in ${EXAMPLE_FILES}
	vucQuotFor
)

func (q vucQuoting) String() string {
	return [...]string{"unknown", "plain", "dquot", "squot", "backt", "mk-for"}[q]
}

func (vuc *VarUseContext) String() string {
	typename := "no-type"
	if vuc.vartype != nil {
		typename = vuc.vartype.String()
	}
	return fmt.Sprintf("(%s time:%s quoting:%s wordpart:%v)", typename, vuc.time, vuc.quoting, vuc.IsWordPart)
}

// Indentation remembers the stack of preprocessing directives and their
// indentation. By convention, each directive is indented by 2 spaces.
// An excepting are multiple-inclusion guards, they don't increase the
// indentation.
type Indentation struct {
	levels []indentationLevel
}

func NewIndentation() *Indentation {
	ind := &Indentation{}
	ind.Push(nil, 0, "") // Dummy
	return ind
}

func (ind *Indentation) String() string {
	s := ""
	for _, level := range ind.levels[1:] {
		s += fmt.Sprintf(" %d", level.depth)
		if len(level.conditionalVars) != 0 {
			s += " (" + strings.Join(level.conditionalVars, " ") + ")"
		}
	}
	return "[" + strings.TrimSpace(s) + "]"
}

type indentationLevel struct {
	mkline          MkLine   // The line in which the indentation started; the .if/.for
	depth           int      // Number of space characters; always a multiple of 2
	condition       string   // The corresponding condition from the .if or latest .elif
	conditionalVars []string // Variables on which the current path depends

	// Files whose existence has been checked in a related path.
	// The check counts for both the "if" and the "else" branch,
	// but that sloppiness will be discovered by functional tests.
	checkedFiles []string
}

func (ind *Indentation) Len() int {
	return len(ind.levels)
}

func (ind *Indentation) top() *indentationLevel {
	return &ind.levels[ind.Len()-1]
}

// Depth returns the number of space characters by which the directive
// should be indented.
func (ind *Indentation) Depth(directive string) int {
	switch directive {
	case "if", "elif", "else", "endfor", "endif":
		return ind.levels[imax(0, ind.Len()-2)].depth
	}
	return ind.top().depth
}

func (ind *Indentation) Pop() {
	ind.levels = ind.levels[:ind.Len()-1]
}

func (ind *Indentation) Push(mkline MkLine, indent int, condition string) {
	ind.levels = append(ind.levels, indentationLevel{mkline, indent, condition, nil, nil})
}

func (ind *Indentation) AddVar(varname string) {
	vars := &ind.top().conditionalVars
	for _, existingVarname := range *vars {
		if varname == existingVarname {
			return
		}
	}

	*vars = append(*vars, varname)
}

func (ind *Indentation) DependsOn(varname string) bool {
	for _, level := range ind.levels {
		for _, levelVarname := range level.conditionalVars {
			if varname == levelVarname {
				return true
			}
		}
	}
	return false
}

// IsConditional returns whether the current line depends on evaluating
// any variable in an .if or .elif expression or from a .for loop.
func (ind *Indentation) IsConditional() bool {
	for _, level := range ind.levels {
		for _, varname := range level.conditionalVars {
			if !hasSuffix(varname, "_MK") {
				return true
			}
		}
	}
	return false
}

// Varnames returns the list of all variables that are mentioned in any
// condition or loop surrounding the current line.
// Variables named *_MK are excluded since they are usually not interesting.
func (ind *Indentation) Varnames() string {
	sep := ""
	varnames := ""
	for _, level := range ind.levels {
		for _, levelVarname := range level.conditionalVars {
			if !hasSuffix(levelVarname, "_MK") {
				varnames += sep + levelVarname
				sep = ", "
			}
		}
	}
	return varnames
}

// Condition returns the condition of the innermost .if, .elif or .for.
func (ind *Indentation) Condition() string {
	return ind.top().condition
}

func (ind *Indentation) AddCheckedFile(filename string) {
	top := ind.top()
	top.checkedFiles = append(top.checkedFiles, filename)
}

func (ind *Indentation) IsCheckedFile(filename string) bool {
	for _, level := range ind.levels {
		for _, levelFilename := range level.checkedFiles {
			if filename == levelFilename {
				return true
			}
		}
	}
	return false
}

func (ind *Indentation) TrackBefore(mkline MkLine) {
	if !mkline.IsDirective() {
		return
	}
	if trace.Tracing {
		trace.Stepf("Indentation before line %s: %s", mkline.Linenos(), ind)
	}

	directive := mkline.Directive()
	args := mkline.Args()

	switch directive {
	case "for", "if", "ifdef", "ifndef":
		ind.Push(mkline, ind.top().depth, args)
	}
}

func (ind *Indentation) TrackAfter(mkline MkLine) {
	if !mkline.IsDirective() {
		return
	}

	directive := mkline.Directive()
	args := mkline.Args()

	switch directive {
	case "if":
		// For multiple-inclusion guards, the indentation stays at the same level.
		if m, varname := match1(args, `^!defined\(([\w]+_MK)\)$`); m {
			ind.AddVar(varname)
		} else {
			ind.top().depth += 2
		}

		// Note: adding the used variables for arbitrary conditions
		// happens in MkLineChecker.checkDirectiveCond for performance reasons.

		if contains(args, "exists") {
			cond := NewMkParser(mkline.Line, args, false).MkCond()
			if cond != nil {
				NewMkCondWalker().Walk(cond, &MkCondCallback{
					Call: func(name string, arg string) {
						if name == "exists" {
							ind.AddCheckedFile(arg)
						}
					}})
			}
		}

	case "for", "ifdef", "ifndef":
		ind.top().depth += 2

	case "elif":
		// Handled here instead of TrackBefore to allow the action to access the previous condition.
		ind.top().condition = args

	case "else":
		top := ind.top()
		if top.mkline != nil {
			top.mkline.SetHasElseBranch(mkline)
		}

	case "endfor", "endif":
		if ind.Len() > 1 { // Can only be false in unbalanced files.
			ind.Pop()
		}
	}

	if trace.Tracing {
		trace.Stepf("Indentation after line %s: %s", mkline.Linenos(), ind)
	}
}

func MatchVarassign(text string) (m, commented bool, varname, spaceAfterVarname, op, valueAlign, value, spaceAfterValue, comment string) {
	i, n := 0, len(text)

	if i < n && text[i] == '#' {
		commented = true
		i++
	} else {
		for i < n && text[i] == ' ' {
			i++
		}
	}

	varnameStart := i
	for ; i < n; i++ {
		b := text[i]
		switch {
		case 'A' <= b && b <= 'Z',
			'a' <= b && b <= 'z',
			b == '_',
			'0' <= b && b <= '9',
			'$' <= b && b <= '.' && (b == '$' || b == '*' || b == '+' || b == '-' || b == '.'),
			b == '[',
			b == '{', b == '}':
			continue
		}
		break
	}
	varnameEnd := i

	if varnameEnd == varnameStart {
		return
	}

	for i < n && (text[i] == ' ' || text[i] == '\t') {
		i++
	}

	opStart := i
	if i < n {
		if b := text[i]; b == '!' || b == '+' || b == ':' || b == '?' {
			i++
		}
	}
	if i < n && text[i] == '=' {
		i++
	} else {
		return
	}
	opEnd := i

	if text[varnameEnd-1] == '+' && varnameEnd == opStart && text[opStart] == '=' {
		varnameEnd--
		opStart--
	}

	for i < n && (text[i] == ' ' || text[i] == '\t') {
		i++
	}

	valueStart := i
	valuebuf := make([]byte, n-valueStart)
	j := 0
	for ; i < n; i++ {
		b := text[i]
		if b == '#' && (i == valueStart || text[i-1] != '\\') {
			break
		} else if b != '\\' || i+1 >= n || text[i+1] != '#' {
			valuebuf[j] = b
			j++
		}
	}

	commentStart := i
	for text[i-1] == ' ' || text[i-1] == '\t' {
		i--
	}
	valueEnd := i

	commentEnd := n

	m = true
	varname = text[varnameStart:varnameEnd]
	spaceAfterVarname = text[varnameEnd:opStart]
	op = text[opStart:opEnd]
	valueAlign = text[0:valueStart]
	value = strings.TrimSpace(string(valuebuf[:j]))
	spaceAfterValue = text[valueEnd:commentStart]
	comment = text[commentStart:commentEnd]
	return
}

func MatchMkInclude(text string) (m bool, indentation, directive, filename string) {
	return match3(text, `^\.(\s*)(s?include)\s+\"([^\"]+)\"\s*(?:#.*)?$`)
}
