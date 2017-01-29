package main

// Checks concerning single lines in Makefiles.

import (
	"fmt"
	"netbsd.org/pkglint/line"
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/trace"
	"strings"
)

type MkLine interface {
	line.Line

	IsVarassign() bool
	Varname() string
	Varcanon() string
	Varparam() string
	Op() MkOperator
	ValueAlign() string
	Value() string
	VarassignComment() string

	IsShellcmd() bool
	Shellcmd() string

	IsComment() bool

	IsEmpty() bool

	IsCond() bool
	Indent() string
	Directive() string
	Args() string

	IsInclude() bool
	IsSysinclude() bool
	// Indent() works here, too.
	MustExist() bool
	Includefile() string
	ConditionVars() string
	SetConditionVars(varnames string) // Initialized lazily

	IsDependency() bool
	Targets() string
	Sources() string

	VariableType(varname string) *Vartype
	ResolveVarsInRelativePath(relpath string, adjustDepth bool) string
	ExtractUsedVariables(value string) []string
	WithoutMakeVariables(value string) string
	VariableNeedsQuoting(varname string, vartype *Vartype, vuc *VarUseContext) NeedsQuoting
	DetermineUsedVariables() []string
	ExplainRelativeDirs()
}

type MkLineImpl struct {
	line.Line
	data interface{} // One of the following mkLine* types
}
type mkLineAssign struct {
	varname    string
	varcanon   string
	varparam   string
	op         MkOperator
	valueAlign string
	value      string
	comment    string
}
type mkLineShell struct {
	command string
}
type mkLineComment struct{}
type mkLineEmpty struct{}
type mkLineConditional struct {
	indent    string
	directive string
	args      string
}
type mkLineInclude struct {
	mustexist     bool
	sys           bool
	indent        string
	includeFile   string
	conditionVars string // (filled in later)
}
type mkLineDependency struct {
	targets string
	sources string
}

func NewMkLine(line line.Line) (mkline *MkLineImpl) {
	mkline = &MkLineImpl{Line: line}

	text := line.Text()

	if hasPrefix(text, " ") {
		mkline.Warnf("Makefile lines should not start with space characters.")
		Explain(
			"If you want this line to contain a shell program, use a tab",
			"character for indentation.  Otherwise please remove the leading",
			"white-space.")
	}

	if m, varname, spaceAfterVarname, op, valueAlign, value, spaceAfterValue, comment := MatchVarassign(text); m {
		if G.opts.WarnSpace && spaceAfterVarname != "" {
			switch {
			case hasSuffix(varname, "+") && op == "=":
				break
			case matches(varname, `^[a-z]`) && op == ":=":
				break
			default:
				if !line.AutofixReplace(varname+spaceAfterVarname+op, varname+op) {
					line.Warnf("Unnecessary space after variable name %q.", varname)
				}
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

		mkline.data = mkLineAssign{
			varname,
			varnameCanon(varname),
			varparam,
			NewMkOperator(op),
			valueAlign,
			value,
			comment}
		mkline.Tokenize(value)
		return
	}

	if hasPrefix(text, "\t") {
		shellcmd := text[1:]
		mkline.data = mkLineShell{shellcmd}
		mkline.Tokenize(shellcmd)
		return
	}

	if index := strings.IndexByte(text, '#'); index != -1 && strings.TrimSpace(text[:index]) == "" {
		mkline.data = mkLineComment{}
		return
	}

	if strings.TrimSpace(text) == "" {
		mkline.data = mkLineEmpty{}
		return
	}

	if m, indent, directive, args := matchMkCond(text); m {
		mkline.data = mkLineConditional{indent, directive, args}
		return
	}

	if m, indent, directive, includefile := MatchMkInclude(text); m {
		mkline.data = mkLineInclude{directive == "include", false, indent, includefile, ""}
		return
	}

	if m, indent, directive, includefile := match3(text, `^\.(\s*)(s?include)\s+<([^>]+)>\s*(?:#.*)?$`); m {
		mkline.data = mkLineInclude{directive == "include", true, indent, includefile, ""}
		return
	}

	if m, targets, whitespace, sources := match3(text, `^([^\s:]+(?:\s*[^\s:]+)*)(\s*):\s*([^#]*?)(?:\s*#.*)?$`); m {
		mkline.data = mkLineDependency{targets, sources}
		if whitespace != "" {
			line.Warnf("Space before colon in dependency line.")
		}
		return
	}

	if matches(text, `^(<<<<<<<|=======|>>>>>>>)`) {
		return
	}

	line.Errorf("Unknown Makefile line format.")
	return mkline
}

func (mkline *MkLineImpl) String() string {
	return fmt.Sprintf("%s:%s", mkline.Filename(), mkline.Linenos())
}
func (mkline *MkLineImpl) IsVarassign() bool { _, ok := mkline.data.(mkLineAssign); return ok }
func (mkline *MkLineImpl) IsShellcmd() bool  { _, ok := mkline.data.(mkLineShell); return ok }
func (mkline *MkLineImpl) IsComment() bool   { _, ok := mkline.data.(mkLineComment); return ok }
func (mkline *MkLineImpl) IsEmpty() bool     { _, ok := mkline.data.(mkLineEmpty); return ok }
func (mkline *MkLineImpl) IsCond() bool      { _, ok := mkline.data.(mkLineConditional); return ok }
func (mkline *MkLineImpl) IsInclude() bool {
	incl, ok := mkline.data.(mkLineInclude)
	return ok && !incl.sys
}
func (mkline *MkLineImpl) IsSysinclude() bool {
	incl, ok := mkline.data.(mkLineInclude)
	return ok && incl.sys
}
func (mkline *MkLineImpl) IsDependency() bool       { _, ok := mkline.data.(mkLineDependency); return ok }
func (mkline *MkLineImpl) Varname() string          { return mkline.data.(mkLineAssign).varname }
func (mkline *MkLineImpl) Varcanon() string         { return mkline.data.(mkLineAssign).varcanon }
func (mkline *MkLineImpl) Varparam() string         { return mkline.data.(mkLineAssign).varparam }
func (mkline *MkLineImpl) Op() MkOperator           { return mkline.data.(mkLineAssign).op }
func (mkline *MkLineImpl) ValueAlign() string       { return mkline.data.(mkLineAssign).valueAlign }
func (mkline *MkLineImpl) Value() string            { return mkline.data.(mkLineAssign).value }
func (mkline *MkLineImpl) VarassignComment() string { return mkline.data.(mkLineAssign).comment }
func (mkline *MkLineImpl) Shellcmd() string         { return mkline.data.(mkLineShell).command }
func (mkline *MkLineImpl) Indent() string {
	if mkline.IsCond() {
		return mkline.data.(mkLineConditional).indent
	} else {
		return mkline.data.(mkLineInclude).indent
	}
}
func (mkline *MkLineImpl) Directive() string   { return mkline.data.(mkLineConditional).directive }
func (mkline *MkLineImpl) Args() string        { return mkline.data.(mkLineConditional).args }
func (mkline *MkLineImpl) MustExist() bool     { return mkline.data.(mkLineInclude).mustexist }
func (mkline *MkLineImpl) Includefile() string { return mkline.data.(mkLineInclude).includeFile }
func (mkline *MkLineImpl) Targets() string     { return mkline.data.(mkLineDependency).targets }
func (mkline *MkLineImpl) Sources() string     { return mkline.data.(mkLineDependency).sources }

func (mkline *MkLineImpl) ConditionVars() string { return mkline.data.(mkLineInclude).conditionVars }
func (mkline *MkLineImpl) SetConditionVars(varnames string) {
	include := mkline.data.(mkLineInclude)
	include.conditionVars = varnames
	mkline.data = include
}

func (mkline *MkLineImpl) Tokenize(s string) []*MkToken {
	if trace.Tracing {
		defer trace.Call(mkline, s)()
	}

	p := NewMkParser(mkline, s, true)
	tokens := p.MkTokens()
	if p.Rest() != "" {
		mkline.Warnf("Pkglint parse error in MkLine.Tokenize at %q.", p.Rest())
	}
	return tokens
}

func (mkline *MkLineImpl) WithoutMakeVariables(value string) string {
	valueNovar := value
	for {
		var m []string
		m, valueNovar = regex.ReplaceFirst(valueNovar, `\$\{[^{}]*\}`, "")
		if m == nil {
			return valueNovar
		}
	}
}

func (mkline *MkLineImpl) ResolveVarsInRelativePath(relpath string, adjustDepth bool) string {
	tmp := relpath
	tmp = strings.Replace(tmp, "${PKGSRCDIR}", G.CurPkgsrcdir, -1)
	tmp = strings.Replace(tmp, "${.CURDIR}", ".", -1)
	tmp = strings.Replace(tmp, "${.PARSEDIR}", ".", -1)
	if contains(tmp, "${LUA_PKGSRCDIR}") {
		tmp = strings.Replace(tmp, "${LUA_PKGSRCDIR}", G.globalData.Latest("lang", `^lua[0-9]+$`, "../../lang/$0"), -1)
	}
	if contains(tmp, "${PHPPKGSRCDIR}") {
		tmp = strings.Replace(tmp, "${PHPPKGSRCDIR}", G.globalData.Latest("lang", `^php[0-9]+$`, "../../lang/$0"), -1)
	}
	if contains(tmp, "${SUSE_DIR_PREFIX}") {
		suseDirPrefix := G.globalData.Latest("emulators", `^(suse[0-9]+)_base`, "$1")
		tmp = strings.Replace(tmp, "${SUSE_DIR_PREFIX}", suseDirPrefix, -1)
	}
	if contains(tmp, "${PYPKGSRCDIR}") {
		tmp = strings.Replace(tmp, "${PYPKGSRCDIR}", G.globalData.Latest("lang", `^python[0-9]+$`, "../../lang/$0"), -1)
	}
	if contains(tmp, "${PYPACKAGE}") {
		tmp = strings.Replace(tmp, "${PYPACKAGE}", G.globalData.Latest("lang", `^python[0-9]+$`, "$0"), -1)
	}
	if G.Pkg != nil {
		tmp = strings.Replace(tmp, "${FILESDIR}", G.Pkg.Filesdir, -1)
		tmp = strings.Replace(tmp, "${PKGDIR}", G.Pkg.Pkgdir, -1)
	}

	if adjustDepth {
		if m, pkgpath := match1(tmp, `^\.\./\.\./([^.].*)$`); m {
			tmp = G.CurPkgsrcdir + "/" + pkgpath
		}
	}

	if trace.Tracing {
		trace.Step2("resolveVarsInRelativePath: %q => %q", relpath, tmp)
	}
	return tmp
}

func (ind *Indentation) RememberUsedVariables(cond *Tree) {
	arg0varname := func(node *Tree) {
		varname := node.args[0].(string)
		ind.AddVar(varname)
	}
	arg0varuse := func(node *Tree) {
		varuse := node.args[0].(MkVarUse)
		ind.AddVar(varuse.varname)
	}
	arg2varuse := func(node *Tree) {
		varuse := node.args[2].(MkVarUse)
		ind.AddVar(varuse.varname)
	}
	cond.Visit("defined", arg0varname)
	cond.Visit("empty", arg0varuse)
	cond.Visit("compareVarNum", arg0varuse)
	cond.Visit("compareVarStr", arg0varuse)
	cond.Visit("compareVarVar", arg0varuse)
	cond.Visit("compareVarVar", arg2varuse)
}

func (mkline *MkLineImpl) ExplainRelativeDirs() {
	Explain(
		"Directories in the form \"../../category/package\" make it easier to",
		"move a package around in pkgsrc, for example from pkgsrc-wip to the",
		"main pkgsrc repository.")
}

func matchMkCond(text string) (m bool, indent, directive, args string) {
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
	for i < n && text[i] != '#' {
		i++
	}
	for i > argsStart && (text[i-1] == ' ' || text[i-1] == '\t') {
		i--
	}
	argsEnd := i

	m = true
	indent = text[indentStart:indentEnd]
	args = text[argsStart:argsEnd]
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

	// Determine whether the context expects a list of shell words or not.
	wantList := vuc.vartype.IsConsideredList()
	haveList := vartype.IsConsideredList()
	if trace.Tracing {
		trace.Stepf("wantList=%v, haveList=%v", wantList, haveList)
	}

	// A shell word may appear as part of a shell word, for example COMPILER_RPATH_FLAG.
	if vuc.IsWordPart && vuc.quoting == vucQuotPlain {
		if vartype.kindOfList == lkNone && vartype.basicType == BtShellWord {
			return nqNo
		}
	}

	// Both of these can be correct, depending on the situation:
	// 1. echo ${PERL5:Q}
	// 2. xargs ${PERL5}
	if !vuc.IsWordPart && vuc.quoting == vucQuotPlain {
		if wantList && haveList {
			return nqDontKnow
		}
	}

	// Assuming the tool definitions don't include very special characters,
	// so they can safely be used inside any quotes.
	if G.globalData.Tools.byVarname[varname] != nil {
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

	// Assigning lists to lists does not require any quoting, though
	// there may be cases like "CONFIGURE_ARGS+= -libs ${LDFLAGS:Q}"
	// where quoting is necessary.
	if wantList && haveList && !vuc.IsWordPart {
		return nqDoesntMatter
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

// Returns the type of the variable (maybe guessed based on the variable name),
// or nil if the type cannot even be guessed.
func (mkline *MkLineImpl) VariableType(varname string) *Vartype {
	if trace.Tracing {
		defer trace.Call1(varname)()
	}

	if vartype := G.globalData.vartypes[varname]; vartype != nil {
		return vartype
	}
	if vartype := G.globalData.vartypes[varnameCanon(varname)]; vartype != nil {
		return vartype
	}

	if tool := G.globalData.Tools.byVarname[varname]; tool != nil {
		perms := aclpUse
		if trace.Tracing {
			trace.Stepf("Use of tool %+v", tool)
		}
		if tool.UsableAtLoadtime {
			if G.Pkg == nil || G.Pkg.SeenBsdPrefsMk || G.Pkg.loadTimeTools[tool.Name] {
				perms |= aclpUseLoadtime
			}
		}
		return &Vartype{lkNone, BtShellCommand, []AclEntry{{"*", perms}}, false}
	}

	if m, toolvarname := match1(varname, `^TOOLS_(.*)`); m && G.globalData.Tools.byVarname[toolvarname] != nil {
		return &Vartype{lkNone, BtPathname, []AclEntry{{"*", aclpUse}}, false}
	}

	allowAll := []AclEntry{{"*", aclpAll}}
	allowRuntime := []AclEntry{{"*", aclpAllRuntime}}

	// Guess the datatype of the variable based on naming conventions.
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
	case hasPrefix(varbase, "PLIST."):
		gtype = &Vartype{lkNone, BtYes, allowAll, true}
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
	rest := mkline.Text()

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
	return
}

// VarUseContext defines the context in which a variable is defined
// or used. Whether that is allowed depends on:
//
// * The variable's data type, as defined in vardefs.go.
// * When used on the right-hand side of an assigment, the variable can
//   represent a list of words, a single word or even only part of a
//   word. This distinction decides upon the correct use of the :Q
//   operator.
// * When used in preprocessing statements like .if or .for, the other
//   operands of that statement should fit to the variable and are
//   checked against the variable type. For example, comparing OPSYS to
//   x86_64 doesn't make sense.
type VarUseContext struct {
	vartype    *Vartype
	time       vucTime
	quoting    vucQuoting
	IsWordPart bool // Example: echo ${LOCALBASE} LOCALBASE=${LOCALBASE}
}

type vucTime uint8

const (
	vucTimeUnknown vucTime = iota

	// When Makefiles are loaded, the operators := and != are evaluated,
	// as well as the conditionals .if, .elif and .for.
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
// indentation.  By convention, each directive is indented by 2 spaces.
// An excepting are multiple-inclusion guards, they don't increase the
// indentation.
type Indentation struct {
	depth         []int      // Number of space characters; always a multiple of 2
	conditionVars [][]string // Variables on which the current path depends
}

func (ind *Indentation) Len() int {
	return len(ind.depth)
}

func (ind *Indentation) Depth() int {
	return ind.depth[len(ind.depth)-1]
}

func (ind *Indentation) Pop() {
	newlen := ind.Len() - 1
	ind.depth = ind.depth[:newlen]
	ind.conditionVars = ind.conditionVars[:newlen]
}

func (ind *Indentation) Push(indent int) {
	ind.depth = append(ind.depth, indent)
	ind.conditionVars = append(ind.conditionVars, nil)
}

func (ind *Indentation) AddVar(varname string) {
	level := ind.Len() - 1
	if hasSuffix(varname, "_MK") {
		return
	}
	for _, existingVarname := range ind.conditionVars[level] {
		if varname == existingVarname {
			return
		}
	}

	ind.conditionVars[level] = append(ind.conditionVars[level], varname)
}

func (ind *Indentation) DependsOn(varname string) bool {
	for _, levelVarnames := range ind.conditionVars {
		for _, levelVarname := range levelVarnames {
			if varname == levelVarname {
				return true
			}
		}
	}
	return false
}

func (ind *Indentation) IsConditional() bool {
	for _, vars := range ind.conditionVars {
		if len(vars) > 0 {
			return true
		}
	}
	return false
}

func (ind *Indentation) Varnames() string {
	sep := ""
	varnames := ""
	for _, levelVarnames := range ind.conditionVars {
		for _, levelVarname := range levelVarnames {
			varnames += sep + levelVarname
			sep = ", "
		}
	}
	return varnames
}

func MatchVarassign(text string) (m bool, varname, spaceAfterVarname, op, valueAlign, value, spaceAfterValue, comment string) {
	i, n := 0, len(text)

	for i < n && text[i] == ' ' {
		i++
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
