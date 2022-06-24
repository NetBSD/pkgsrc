package pkglint

import (
	"fmt"
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/textproc"
	"regexp"
	"strings"
)

// MkLine is a line from a Makefile fragment.
// There are several types of lines.
// The most common types in pkgsrc are variable assignments,
// shell commands and directives like .if and .for.
type MkLine struct {
	*Line

	splitResult mkLineSplitResult

	// One of the following mkLine* types.
	//
	// For the larger of these types, a pointer is used instead of a direct
	// struct because of https://github.com/golang/go/issues/28045.
	data interface{}
}

type mkLineAssign struct {
	commented         bool   // Whether the whole variable assignment is commented out
	varname           string // e.g. "HOMEPAGE", "SUBST_SED.perl"
	varcanon          string // e.g. "HOMEPAGE", "SUBST_SED.*"
	varparam          string // e.g. "", "perl"
	spaceAfterVarname string
	op                MkOperator //
	value             string     // The trimmed value
	valueMk           []*MkToken // The value, sent through splitIntoMkWords
	valueMkRest       string     // nonempty in case of parse errors
	fields            []string   // The value, space-separated according to shell quoting rules
}

type mkLineShell struct {
	command string
}

type mkLineComment struct{} // See mkLineAssign.commented for another type of comment line

type mkLineEmpty struct{}

type mkLineDirective struct {
	indent    string // the space between the leading "." and the directive
	directive string // "if", "else", "for", etc.
	args      string
	comment   string   // mainly interesting for .endif and .endfor
	elseLine  *MkLine  // for .if (filled in later)
	cond      *MkCond  // for .if and .elif (filled in on first access)
	fields    []string // the arguments for the .for loop (filled in on first access)
}

type mkLineInclude struct {
	mustExist       bool     // for .sinclude, nonexistent files are ignored
	sys             bool     // whether the include uses <file.mk> (very rare) instead of "file.mk"
	indent          string   // the space between the leading "." and the directive
	includedFile    RelPath  // the text between the <brackets> or "quotes"
	conditionalVars []string // variables on which this inclusion depends (filled in later, as needed)
}

type mkLineDependency struct {
	targets string
	sources string
}

// String returns the filename and line numbers.
func (mkline *MkLine) String() string {
	return sprintf("%s:%s", mkline.Filename(), mkline.Linenos())
}

func (mkline *MkLine) HasComment() bool { return mkline.splitResult.hasComment }

// HasRationale returns true if the comments that are close enough to
// this line contain a rationale for suppressing a diagnostic.
//
// These comments are used to suppress pkglint warnings,
// such as for BROKEN, NOT_FOR_PLATFORMS, MAKE_JOBS_SAFE,
// and HOMEPAGE using http instead of https.
//
// To qualify as a rationale, the comment must contain any of the given
// keywords. If no keywords are given, any nonempty comment qualifies.
func (mkline *MkLine) HasRationale(keywords ...string) bool {
	rationale := mkline.splitResult.rationale
	if rationale == "" {
		return false
	}
	if len(keywords) == 0 {
		return true
	}

	// Avoid expensive regular expression search.
	rationaleContains := func(keyword string) bool {
		return contains(rationale, keyword)
	}
	if !anyStr(keywords, rationaleContains) {
		return false
	}

	for _, keyword := range keywords {
		pattern := regex.Pattern(`\b` + regexp.QuoteMeta(keyword) + `\b`)
		if matches(rationale, pattern) {
			return true
		}
	}
	return false
}

// Comment returns the comment after the first unescaped #.
//
// A special case are variable assignments. If these are commented out
// entirely, they still count as variable assignments, which means that
// their comment is the one after the value, if any.
//
// In shell commands (lines that start with a tab), comments can only start at
// the beginning of a line, as the first non-whitespace character. Any later
// '#' is passed uninterpreted to the shell.
//
// Example:
//  VAR=value # comment
//
// In the above line, the comment is " comment", including the leading space.
func (mkline *MkLine) Comment() string { return mkline.splitResult.comment }

// IsVarassign returns true for variable assignments of the form VAR=value.
//
// See IsCommentedVarassign.
func (mkline *MkLine) IsVarassign() bool {
	// See https://github.com/golang/go/issues/28045 for the reason why
	// a pointer type is used here instead of a direct struct.
	data, ok := mkline.data.(*mkLineAssign)
	return ok && !data.commented
}

// IsCommentedVarassign returns true for commented-out variable assignments.
// In most cases these are treated as ordinary comments, but in some others
// they are treated like variable assignments, just inactive ones.
//
// To qualify as a commented variable assignment, there must be no
// space between the # and the variable name.
//
// Example:
//  #VAR=   value
// Counterexample:
//  # VAR=  value
func (mkline *MkLine) IsCommentedVarassign() bool {
	data, ok := mkline.data.(*mkLineAssign)
	return ok && data.commented
}

// IsVarassignMaybeCommented returns true for variable assignments of the
// form VAR=value, no matter if they are commented out like #VAR=value or
// not. To qualify as a commented variable assignment, there must be no
// space between the # and the variable name.
//
// Example:
//  #VAR=   value
// Counterexample:
//  # VAR=  value
func (mkline *MkLine) IsVarassignMaybeCommented() bool {
	_, ok := mkline.data.(*mkLineAssign)
	return ok
}

// IsShellCommand returns true for tab-indented lines that are assigned to a Make
// target.
//
// Example:
//  pre-configure:    # IsDependency
//          ${ECHO}   # IsShellCommand
func (mkline *MkLine) IsShellCommand() bool {
	_, ok := mkline.data.(mkLineShell)
	return ok
}

// IsComment returns true for lines that consist entirely of a comment.
func (mkline *MkLine) IsComment() bool {
	_, ok := mkline.data.(mkLineComment)
	return ok || mkline.IsCommentedVarassign()
}

func (mkline *MkLine) IsEmpty() bool {
	_, ok := mkline.data.(mkLineEmpty)
	return ok
}

// IsDirective returns true for conditionals (.if/.elif/.else/.if) or loops (.for/.endfor).
//
// See IsInclude.
func (mkline *MkLine) IsDirective() bool {
	_, ok := mkline.data.(*mkLineDirective)
	return ok
}

// IsInclude returns true for lines like: .include "other.mk"
//
// See IsSysinclude for lines like: .include <sys.mk>
func (mkline *MkLine) IsInclude() bool {
	incl, ok := mkline.data.(*mkLineInclude)
	return ok && !incl.sys
}

// IsSysinclude returns true for lines like: .include <sys.mk>
//
// See IsInclude for lines like: .include "other.mk"
func (mkline *MkLine) IsSysinclude() bool {
	incl, ok := mkline.data.(*mkLineInclude)
	return ok && incl.sys
}

// IsDependency returns true for dependency lines like "target: source".
func (mkline *MkLine) IsDependency() bool {
	_, ok := mkline.data.(mkLineDependency)
	return ok
}

// Varname applies to variable assignments and returns the name
// of the variable that is assigned or appended to.
//
// Example:
//  VARNAME.${param}?=      value   # Varname is "VARNAME.${param}"
func (mkline *MkLine) Varname() string { return mkline.data.(*mkLineAssign).varname }

// Varcanon applies to variable assignments and returns the canonicalized variable name for parameterized variables.
// Examples:
//  HOMEPAGE           => "HOMEPAGE"
//  SUBST_SED.anything => "SUBST_SED.*"
//  SUBST_SED.${param} => "SUBST_SED.*"
func (mkline *MkLine) Varcanon() string { return mkline.data.(*mkLineAssign).varcanon }

// Varparam applies to variable assignments and returns the parameter for parameterized variables.
// Examples:
//  HOMEPAGE           => ""
//  SUBST_SED.anything => "anything"
//  SUBST_SED.${param} => "${param}"
func (mkline *MkLine) Varparam() string { return mkline.data.(*mkLineAssign).varparam }

// Op applies to variable assignments and returns the assignment operator.
func (mkline *MkLine) Op() MkOperator { return mkline.data.(*mkLineAssign).op }

// ValueAlign applies to variable assignments and returns all the text
// to the left of the variable value, e.g. "VARNAME+=\t".
func (mkline *MkLine) ValueAlign() string {
	parts := NewVaralignSplitter().split(mkline.Line.RawText(0), true)
	return parts.leadingComment + parts.varnameOp + parts.spaceBeforeValue
}

func (mkline *MkLine) Value() string { return mkline.data.(*mkLineAssign).value }

// FirstLineContainsValue returns whether the variable assignment of a
// multiline contains a textual value in the first line.
//
//  VALUE_IN_FIRST_LINE= value \
//          starts in first line
//  NO_VALUE_IN_FIRST_LINE= \
//          value starts in second line
func (mkline *MkLine) FirstLineContainsValue() bool {
	assert(mkline.IsVarassignMaybeCommented())
	assert(mkline.IsMultiline())

	// Parsing the continuation marker as variable value is cheating but works well.
	text := mkline.raw[0].Orig()
	parser := NewMkLineParser()
	splitResult := parser.split(nil, text, true)
	_, a := parser.MatchVarassign(mkline.Line, text, &splitResult)
	return a.value != "\\"
}

func (mkline *MkLine) ShellCommand() string { return mkline.data.(mkLineShell).command }

// Indent returns the whitespace between the dot and the directive.
//
// For the following example line it returns two spaces:
//  .  include "other.mk"
func (mkline *MkLine) Indent() string {
	if mkline.IsDirective() {
		return mkline.data.(*mkLineDirective).indent
	} else {
		return mkline.data.(*mkLineInclude).indent
	}
}

// Directive returns the preprocessing directive, like "if", "for", "endfor", etc.
//
// See matchMkDirective.
func (mkline *MkLine) Directive() string { return mkline.data.(*mkLineDirective).directive }

// Args returns the arguments from an .if, .ifdef, .ifndef, .elif, .for, .undef.
func (mkline *MkLine) Args() string { return mkline.data.(*mkLineDirective).args }

// Cond applies to an .if or .elif line and returns the parsed condition.
//
// If a parse error occurs, it is silently swallowed, returning a
// best-effort part of the condition, or even nil.
func (mkline *MkLine) Cond() *MkCond {
	cond := mkline.data.(*mkLineDirective).cond
	if cond == nil {
		assert(mkline.NeedsCond())
		cond = NewMkParser(mkline.Line, mkline.Args()).MkCond()
		mkline.data.(*mkLineDirective).cond = cond
	}
	return cond
}

// NeedsCond returns whether the directive requires a condition as argument.
func (mkline *MkLine) NeedsCond() bool {
	directive := mkline.Directive()
	return directive == "if" || directive == "elif"
}

// DirectiveComment is the trailing end-of-line comment, typically at a deeply nested .endif or .endfor.
func (mkline *MkLine) DirectiveComment() string { return mkline.data.(*mkLineDirective).comment }

func (mkline *MkLine) HasElseBranch() bool { return mkline.data.(*mkLineDirective).elseLine != nil }

func (mkline *MkLine) SetHasElseBranch(elseLine *MkLine) {
	data := mkline.data.(*mkLineDirective)
	data.elseLine = elseLine
	mkline.data = data
}

func (mkline *MkLine) MustExist() bool { return mkline.data.(*mkLineInclude).mustExist }

func (mkline *MkLine) IncludedFile() RelPath { return mkline.data.(*mkLineInclude).includedFile }

// IncludedFileFull returns the path to the included file.
func (mkline *MkLine) IncludedFileFull() CurrPath {
	dir := mkline.Filename().Dir()
	joined := dir.JoinNoClean(mkline.IncludedFile())
	return joined.CleanPath()
}

func (mkline *MkLine) Targets() string { return mkline.data.(mkLineDependency).targets }

func (mkline *MkLine) Sources() string { return mkline.data.(mkLineDependency).sources }

// ConditionalVars applies to .include lines and contains the
// variable names on which the inclusion depends.
//
// It is initialized later, step by step, when parsing other lines.
func (mkline *MkLine) ConditionalVars() []string {
	return mkline.data.(*mkLineInclude).conditionalVars
}
func (mkline *MkLine) SetConditionalVars(varnames []string) {
	include := mkline.data.(*mkLineInclude)
	include.conditionalVars = varnames
	mkline.data = include
}

// Tokenize extracts variable uses and other text from the given text.
//
// When used in IsVarassign lines, the given text must have the format
// after stripping the end-of-line comment. Such text is available from
// Value. A shell comment is therefore marked by a simple #, not an escaped
// \# like in Makefiles.
//
// When used in IsShellCommand lines, # does not mark a Makefile comment
// and may thus still appear in the text. Therefore, # marks a shell comment.
//
// Example:
//  input:  ${PREFIX}/bin abc
//  output: [MkToken("${PREFIX}", MkVarUse("PREFIX")), MkToken("/bin abc")]
//
// See ValueTokens, which is the tokenized version of Value.
func (mkline *MkLine) Tokenize(text string, warn bool) []*MkToken {
	if trace.Tracing {
		defer trace.Call(mkline, text)()
	}

	var tokens []*MkToken
	var rest string
	if mkline.IsVarassignMaybeCommented() && text == mkline.Value() {
		tokens, rest = mkline.ValueTokens()
	} else {
		var diag Autofixer
		if warn {
			diag = mkline.Line
		}
		p := NewMkLexer(text, diag)
		tokens, rest = p.MkTokens()
	}

	if warn && rest != "" {
		mkline.Warnf("Internal pkglint error in MkLine.Tokenize at %q.", rest)
	}
	return tokens
}

// ValueSplit splits the given value, taking care of variable references.
// Example:
//
//  ValueSplit("${VAR:Udefault}::${VAR2}two:words", ":")
//  => "${VAR:Udefault}"
//     ""
//     "${VAR2}two"
//     "words"
//
// Note that even though the first word contains a colon, it is not split
// at that point since the colon is inside a variable use.
//
// When several separators are adjacent, this results in empty words in the output.
func (mkline *MkLine) ValueSplit(value string, separator string) []string {
	assert(separator != "") // Separator must not be empty; use ValueFields to split on whitespace.

	tokens := mkline.Tokenize(value, false)
	var split []string
	cont := false

	out := func(s string) {
		if cont {
			split[len(split)-1] += s
		} else {
			split = append(split, s)
		}
	}

	for _, token := range tokens {
		if token.Varuse != nil {
			out(token.Text)
			cont = true
		} else {
			lexer := textproc.NewLexer(token.Text)
			for !lexer.EOF() {
				if lexer.SkipString(separator) {
					out("")
					cont = false
				}
				idx := strings.Index(lexer.Rest(), separator)
				if idx == -1 {
					idx = len(lexer.Rest())
				}
				if idx > 0 {
					out(lexer.NextString(lexer.Rest()[:idx]))
					cont = true
				}
			}
		}
	}
	return split
}

var notSpace = textproc.Space.Inverse()

// ValueFields splits the given value in the same way as the :M variable
// modifier, taking care of variable references. Example:
//
//  ValueFields("${VAR:Udefault value} ${VAR2}two words;;; 'word three'")
//  => "${VAR:Udefault value}"
//     "${VAR2}two"
//     "words;;;"
//     "'word three'"
//
// Note that even though the first word contains a space, it is not split
// at that point since the space is inside a variable use. Shell tokens
// such as semicolons are also treated as normal characters. Only double
// and single quotes are interpreted.
//
// Compare devel/bmake/files/str.c, function brk_string.
//
// See UnquoteShell.
func (mkline *MkLine) ValueFields(value string) []string {
	var fields []string

	lexer := NewMkTokensLexer(mkline.Tokenize(value, false))
	lexer.SkipHspace()

	field := NewLazyStringBuilder(lexer.Rest())

	emit := func() {
		if field.Len() > 0 {
			fields = append(fields, field.String())
			field.Reset(lexer.Rest())
		}
	}

	plain := func() {
		varUse := lexer.NextVarUse()
		if varUse != nil {
			field.WriteString(varUse.Text)
		} else {
			field.WriteByte(lexer.NextByte())
		}
	}

	for !lexer.EOF() {
		switch {
		case lexer.SkipByte('\''):
			// Note: bmake's brk_string treats single quotes and double
			// quotes in the same way regarding backslash escape sequences.
			// It seems this is a mistake, and until this is confirmed to
			// not be a bug, pkglint parses single quotes like in the shell.
			field.WriteByte('\'')
			for {
				if lexer.EOF() {
					return fields // without the incomplete last field
				} else if lexer.SkipByte('\'') {
					field.WriteByte('\'')
					break
				} else {
					plain()
				}
			}

		case lexer.SkipByte('"'):
			field.WriteByte('"')
			for {
				if lexer.EOF() {
					return fields // without the incomplete last field
				} else if lexer.SkipByte('"') {
					field.WriteByte('"')
					break
				} else if lexer.SkipByte('\\') {
					field.WriteByte('\\')
					plain()
				} else {
					plain()
				}
			}

		case lexer.SkipByte(' '), lexer.SkipByte('\t'), lexer.SkipByte('\n'):
			emit()

		case lexer.SkipByte('\\'):
			field.WriteByte('\\')
			if !lexer.EOF() {
				plain()
			}

		default:
			plain()
		}
	}
	emit()

	return fields
}

func (mkline *MkLine) ValueFieldsLiteral() []string {
	return filterStr(
		mkline.ValueFields(mkline.Value()),
		func(s string) bool { return !containsVarUse(s) })
}

func (mkline *MkLine) ValueTokens() ([]*MkToken, string) {
	value := mkline.Value()
	if value == "" {
		return nil, ""
	}

	assign := mkline.data.(*mkLineAssign)
	if assign.valueMk != nil || assign.valueMkRest != "" {
		return assign.valueMk, assign.valueMkRest
	}

	// No error checking here since all this has already been done when the
	// whole line was parsed in MkLineParser.Parse.
	p := NewMkLexer(value, nil)
	assign.valueMk, assign.valueMkRest = p.MkTokens()
	return assign.valueMk, assign.valueMkRest
}

// Fields applies to variable assignments and .for loops.
// For variable assignments, it returns the right-hand side, properly split into words.
// For .for loops, it returns all arguments (including variable names), properly split into words.
func (mkline *MkLine) Fields() []string {
	if mkline.IsVarassignMaybeCommented() {
		value := mkline.Value()
		if value == "" {
			return nil
		}

		assign := mkline.data.(*mkLineAssign)
		if assign.fields != nil {
			return assign.fields
		}

		assign.fields = mkline.ValueFields(value)
		return assign.fields
	}

	// For .for loops.
	args := mkline.Args()
	if args == "" {
		return nil
	}

	directive := mkline.data.(*mkLineDirective)
	if directive.fields != nil {
		return directive.fields
	}

	directive.fields = mkline.ValueFields(args)
	return directive.fields

}

func (*MkLine) WithoutMakeVariables(value string) string {
	valueNovar := NewLazyStringBuilder(value)
	tokens, _ := NewMkLexer(value, nil).MkTokens()
	for _, token := range tokens {
		if token.Varuse == nil {
			valueNovar.WriteString(token.Text)
		}
	}
	return valueNovar.String()
}

func (mkline *MkLine) ResolveVarsInRelativePath(relativePath PackagePath, pkg *Package) PackagePath {
	// TODO: Not every path is relative to the package directory.
	if !containsVarUse(relativePath.String()) {
		return relativePath.CleanPath()
	}

	var basedir CurrPath
	if pkg != nil {
		basedir = pkg.File(".")
	} else {
		basedir = mkline.Filename().Dir()
	}

	tmp := relativePath
	if tmp.ContainsText("PKGSRCDIR") {
		pkgsrcdir := G.Pkgsrc.Relpath(basedir, G.Pkgsrc.File("."))

		if G.Testing {
			// Relative pkgsrc paths usually only contain two or three levels.
			// A possible reason for reaching this assertion is a pkglint unit test
			// that uses t.NewMkLines instead of the correct t.SetUpFileMkLines.
			assertf(!pkgsrcdir.ContainsPath("../../../../.."),
				"Relative path %q for %q is too deep below the pkgsrc root %q.",
				pkgsrcdir, basedir, G.Pkgsrc.File("."))
		}
		tmp = tmp.Replace("${PKGSRCDIR}", pkgsrcdir.String())
	}

	// Strictly speaking, the .CURDIR should be replaced with the basedir.
	// Depending on whether pkglint is executed with a relative or an absolute
	// path, this would produce diagnostics that "this relative path must not
	// be absolute". Since ${.CURDIR} is usually used in package Makefiles and
	// followed by "../.." anyway, the exact directory doesn't matter.
	tmp = tmp.Replace("${.CURDIR}", ".")

	// TODO: Add test for exists(${.PARSEDIR}/file).
	// TODO: Add test for evaluating ${.PARSEDIR} in an included package.
	// TODO: Add test for including ${.PARSEDIR}/other.mk.
	// TODO: Add test for evaluating ${.PARSEDIR} in the infrastructure.
	//  This is the only practically relevant use case since the category
	//  directories don't contain any *.mk files that could be included.
	// TODO: Add test that suggests ${.PARSEDIR} in .include to be omitted.
	tmp = tmp.Replace("${.PARSEDIR}", ".")

	replaceLatest := func(varuse string, category PkgsrcPath, pattern regex.Pattern, replacement string) {
		if tmp.ContainsText(varuse) {
			latest := G.Pkgsrc.Latest(category, pattern, replacement)
			tmp = tmp.Replace(varuse, latest)
		}
	}

	// These variables are only used in pkgsrc packages, therefore they
	// are replaced with the fixed "../.." regardless of where the text appears.
	replaceLatest("${LUA_PKGSRCDIR}", "lang", `^lua[0-9]+$`, "../../lang/$0")
	replaceLatest("${PHPPKGSRCDIR}", "lang", `^php[0-9]+$`, "../../lang/$0")
	replaceLatest("${PYPKGSRCDIR}", "lang", `^python[0-9]+$`, "../../lang/$0")

	replaceLatest("${PYPACKAGE}", "lang", `^python[0-9]+$`, "$0")
	replaceLatest("${SUSE_DIR_PREFIX}", "emulators", `^(suse[0-9]+)_base$`, "$1")

	if pkg != nil {
		// XXX: Even if these variables are defined indirectly,
		// pkglint should be able to resolve them properly.
		// There is already G.Pkg.Value, maybe that can be used here.
		tmp = tmp.Replace("${FILESDIR}", pkg.Filesdir.String())
		tmp = tmp.Replace("${PKGDIR}", pkg.Pkgdir.String())
	}

	tmp = tmp.CleanPath()

	if trace.Tracing && relativePath != tmp {
		trace.Stepf("resolveVarsInRelativePath: %q => %q", relativePath, tmp)
	}
	return tmp
}

func (mkline *MkLine) ExplainRelativeDirs() {
	mkline.Explain(
		"Directories in the form \"../../category/package\" make it easier to",
		"move a package around in pkgsrc, for example from pkgsrc-wip to the",
		"main pkgsrc repository.")
}

// RelMkLine returns a reference to another line,
// which can be in the same file or in a different file.
//
// If there is a type mismatch when calling this function, try to add ".line" to
// either the method receiver or the other line.
func (mkline *MkLine) RelMkLine(other *MkLine) string {
	return mkline.Line.RelLine(other.Line)
}

var (
	LowerDash                  = textproc.NewByteSet("a-z-")
	AlnumDot                   = textproc.NewByteSet("A-Za-z0-9_.")
	unescapeMkCommentSafeChars = textproc.NewByteSet("\\#[\n").Inverse()
)

// VariableNeedsQuoting determines whether the given variable needs the :Q
// modifier in the given context.
//
// This decision depends on many factors, such as whether the type of the
// context is a list of things, whether the variable is a list, whether it
// can contain only safe characters, and so on.
func (mkline *MkLine) VariableNeedsQuoting(mklines *MkLines, varuse *MkVarUse, vartype *Vartype, vuc *VarUseContext) (needsQuoting YesNoUnknown) {
	if trace.Tracing {
		defer trace.Call(varuse, vartype, vuc, trace.Result(&needsQuoting))()
	}

	// TODO: Systematically test this function, each and every case, from top to bottom.
	// TODO: Re-check the order of all these if clauses whether it really makes sense.

	if varuse.HasModifier("D") {
		// The :D modifier discards the value of the original variable and
		// replaces it with the expression from the :D modifier.
		// Therefore the original variable does not need to be quoted.
		return unknown
	}

	vucVartype := vuc.vartype
	if vartype == nil || vucVartype == nil || vartype.basicType == BtUnknown {
		return unknown
	}

	if !vartype.basicType.NeedsQ() {
		if !vartype.IsList() {
			if vartype.IsGuessed() {
				return unknown
			}
			return no
		}
		if !vuc.IsWordPart {
			return no
		}
	}

	// A shell word may appear as part of a shell word, for example COMPILER_RPATH_FLAG.
	if vuc.IsWordPart && vuc.quoting == VucQuotPlain {
		if !vartype.IsList() && vartype.basicType == BtShellWord {
			return no
		}
	}

	// Determine whether the context expects a list of shell words or not.
	wantList := vucVartype.MayBeAppendedTo()
	haveList := vartype.MayBeAppendedTo()
	if trace.Tracing {
		trace.Stepf("wantList=%v, haveList=%v", wantList, haveList)
	}

	// Both of these can be correct, depending on the situation:
	// 1. echo ${PERL5:Q}
	// 2. xargs ${PERL5}
	if !vuc.IsWordPart && wantList && haveList {
		return unknown
	}

	// Pkglint assumes that the tool definitions don't include very
	// special characters, so they can safely be used inside any quotes.
	if tool := G.ToolByVarname(mklines, varuse.varname); tool != nil {
		switch vuc.quoting {
		case VucQuotPlain:
			if !vuc.IsWordPart {
				return no
			}
			// XXX: Should there be a return here? It looks as if it could have been forgotten.
		case VucQuotBackt:
			return no
		case VucQuotDquot, VucQuotSquot:
			return unknown
		}
	}

	// Variables that appear as parts of shell words generally need to be quoted.
	//
	// An exception is in the case of backticks, because the whole backticks expression
	// is parsed as a single shell word by pkglint. (XXX: This comment may be outdated.)
	if vuc.IsWordPart && vucVartype.IsShell() && vuc.quoting != VucQuotBackt {
		return yes
	}

	// SUBST_MESSAGE.perl= Replacing in ${REPLACE_PERL}
	if vucVartype.basicType == BtMessage {
		return no
	}

	if wantList != haveList {
		if vucVartype.basicType == BtFetchURL && vartype.basicType == BtHomepage {
			return no
		}
		if vucVartype.basicType == BtHomepage && vartype.basicType == BtFetchURL {
			return no // Just for HOMEPAGE=${MASTER_SITE_*:=subdir/}.
		}

		// .for dir in ${PATH:C,:, ,g}
		for _, modifier := range varuse.modifiers {
			if modifier.ChangesList() {
				return unknown
			}
		}

		return yes
	}

	// Bad: LDADD+= -l${LIBS}
	// Good: LDADD+= ${LIBS:S,^,-l,}
	if wantList {
		return yes
	}

	if trace.Tracing {
		trace.Step1("Don't know whether :Q is needed for %q", varuse.varname)
	}
	return unknown
}

// ForEachUsed calls the action for each variable that is used in the line.
func (mkline *MkLine) ForEachUsed(action func(varUse *MkVarUse, time VucTime)) {
	switch {

	case mkline.IsVarassign():
		mkline.ForEachUsedText(mkline.Varname(), VucLoadTime, action)
		mkline.ForEachUsedText(mkline.Value(), mkline.Op().Time(), action)

	case mkline.IsDirective() && mkline.Directive() == "for":
		mkline.ForEachUsedText(mkline.Args(), VucLoadTime, action)

	case mkline.IsDirective() && (mkline.Directive() == "if" || mkline.Directive() == "elif") && mkline.Cond() != nil:
		mkline.Cond().Walk(&MkCondCallback{
			VarUse: func(varuse *MkVarUse) {
				mkline.ForEachUsedVarUse(varuse, VucLoadTime, action)
			}})

	case mkline.IsShellCommand():
		mkline.ForEachUsedText(mkline.ShellCommand(), VucRunTime, action)

	case mkline.IsDependency():
		mkline.ForEachUsedText(mkline.Targets(), VucLoadTime, action)
		mkline.ForEachUsedText(mkline.Sources(), VucLoadTime, action)

	case mkline.IsInclude():
		mkline.ForEachUsedText(mkline.IncludedFile().String(), VucLoadTime, action)
	}
}

func (mkline *MkLine) ForEachUsedText(text string, time VucTime, action func(varUse *MkVarUse, time VucTime)) {
	if !contains(text, "$") {
		return
	}

	tokens, _ := NewMkLexer(text, nil).MkTokens()
	for _, token := range tokens {
		if token.Varuse != nil {
			mkline.ForEachUsedVarUse(token.Varuse, time, action)
		}
	}
}

func (mkline *MkLine) ForEachUsedVarUse(varuse *MkVarUse, time VucTime, action func(varUse *MkVarUse, time VucTime)) {
	varname := varuse.varname
	if !varuse.IsExpression() {
		action(varuse, time)
	}
	mkline.ForEachUsedText(varname, time, action)
	for _, mod := range varuse.modifiers {
		mkline.ForEachUsedText(mod.String(), time, action)
	}
}

// UnquoteShell removes one level of double and single quotes,
// like in the shell.
//
// See ValueFields.
func (mkline *MkLine) UnquoteShell(str string, warn bool) string {
	sb := NewLazyStringBuilder(str)
	lexer := NewMkTokensLexer(mkline.Tokenize(str, false))

	plain := func() {
		varUse := lexer.NextVarUse()
		if varUse != nil {
			sb.WriteString(varUse.Text)
		} else {
			sb.WriteByte(lexer.NextByte())
		}
	}

outer:
	for !lexer.EOF() {
		switch {
		case lexer.SkipByte('"'):
			for !lexer.EOF() {
				if lexer.SkipByte('"') {
					continue outer
				} else if lexer.SkipByte('\\') {
					if !lexer.EOF() {
						plain()
					}
				} else {
					plain()
				}
			}

		case lexer.SkipByte('\''):
			for !lexer.EOF() && !lexer.SkipByte('\'') {
				plain()
			}

		case lexer.SkipByte('\\'):
			if !lexer.EOF() {
				plain()
			}

		default:
			if warn {
				mkline.checkFileGlobbing(lexer.PeekByte(), str)
			}
			plain()
		}
	}

	return sb.String()
}

func (mkline *MkLine) checkFileGlobbing(ch int, str string) {
	if !(ch == '*' || ch == '?' || ch == '[') {
		return
	}

	chStr := string(rune(ch))
	if !mkline.once.FirstTimeSlice("unintended file globbing", chStr) {
		return
	}

	mkline.Warnf("The %q in the word %q may lead to unintended file globbing.",
		chStr, str)
	mkline.Explain(
		"To fix this, enclose the word in \"double\" or 'single' quotes.")
}

type MkOperator uint8

const (
	opAssign        MkOperator = iota // =
	opAssignShell                     // !=
	opAssignEval                      // :=
	opAssignAppend                    // +=
	opAssignDefault                   // ?=
	opUseCompare                      // A variable is compared to a value, e.g. in a condition.
	opUseMatch                        // A variable is matched using the :M or :N modifier.
)

func NewMkOperator(op string) MkOperator {
	switch op {
	case "=":
		return opAssign
	case "!=":
		return opAssignShell
	case ":=":
		return opAssignEval
	case "+=":
		return opAssignAppend
	case "?=":
		return opAssignDefault
	}
	panic("Invalid operator: " + op)
}

func (op MkOperator) String() string {
	return [...]string{"=", "!=", ":=", "+=", "?=", "use", "use-loadtime", "use-match"}[op]
}

// Time returns the time at which the right-hand side of the assignment is
// evaluated.
func (op MkOperator) Time() VucTime {
	if op == opAssignShell || op == opAssignEval {
		return VucLoadTime
	}
	return VucRunTime
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
	time       VucTime
	quoting    VucQuoting
	IsWordPart bool // Example: LOCALBASE=${LOCALBASE}
}

// VucTime is the time at which a variable is used.
//
// See ToolTime, which is the same except that there is no unknown.
type VucTime uint8

const (
	VucUnknownTime VucTime = iota

	// VucLoadTime marks a variable use that happens directly when
	// the Makefile fragment is loaded.
	//
	// When Makefiles are loaded, the operators := and != evaluate their
	// right-hand side, as well as the directives .if, .elif and .for.
	// During loading, not all variables are available yet.
	// Variable values are still subject to change, especially lists.
	VucLoadTime

	// VucRunTime marks a variable use that happens after all files have been loaded.
	//
	// At this time, all variables can be referenced.
	//
	// At this time, variable values don't change anymore.
	// Well, except for the ::= modifier.
	// But that modifier is usually not used in pkgsrc.
	VucRunTime
)

func (t VucTime) String() string { return [...]string{"unknown", "load", "run"}[t] }

// VucQuoting describes in what level of quoting the variable is used.
// Depending on this context, the modifiers :Q or :M can be allowed or not.
//
// The shell tokenizer knows multi-level quoting modes (see ShQuoting),
// but for deciding whether :Q is necessary or not, a single level is enough.
type VucQuoting uint8

const (
	VucQuotUnknown VucQuoting = iota
	VucQuotPlain              // Example: echo LOCALBASE=${LOCALBASE}
	VucQuotDquot              // Example: echo "The version is ${PKGVERSION}."
	VucQuotSquot              // Example: echo 'The version is ${PKGVERSION}.'
	VucQuotBackt              // Example: echo `sed 1q ${WRKSRC}/README`
)

func (q VucQuoting) String() string {
	return [...]string{"unknown", "plain", "dquot", "squot", "backt", "mk-for"}[q]
}

func (vuc *VarUseContext) String() string {
	typename := "no-type"
	if vuc.vartype != nil {
		typename = vuc.vartype.String()
	}
	return sprintf("(%s time:%s quoting:%s wordpart:%v)", typename, vuc.time, vuc.quoting, vuc.IsWordPart)
}

// Indentation remembers the stack of preprocessing directives and their
// indentation. By convention, each directive is indented by 2 spaces.
// An excepting are multiple-inclusion guards, they don't increase the
// indentation.
//
//  Indentation starts with 0 spaces.
//  Each .if or .for indents all inner directives by 2.
//  Except for .if with multiple-inclusion guard, which indents all inner directives by 0.
//  Each .elif, .else, .endif, .endfor uses the outer indentation instead.
type Indentation struct {
	levels []indentationLevel
}

type indentationLevel struct {
	mkline          *MkLine  // The line in which the indentation started; the .if/.for
	depth           int      // Number of space characters; always a multiple of 2
	args            string   // The arguments from the .if or .for, or the latest .elif
	argsLine        *MkLine  //
	conditionalVars []string // Variables on which the current path depends

	// Files whose existence has been checked in an if branch that is
	// related to the current indentation. After a .if exists(fname),
	// pkglint will happily accept .include "fname" in both the then and
	// the else branch. This is ok since the primary job of this file list
	// is to prevent wrong pkglint warnings about missing files.
	checkedFiles []PkgsrcPath

	// whether the line is a multiple-inclusion guard
	guard bool
}

func NewIndentation() *Indentation { return &Indentation{} }

func (ind *Indentation) String() string {
	var s strings.Builder
	for _, level := range ind.levels {
		_, _ = fmt.Fprintf(&s, " %d", level.depth)
		if len(level.conditionalVars) > 0 {
			_, _ = fmt.Fprintf(&s, " (%s)", strings.Join(level.conditionalVars, " "))
		}
	}
	return "[" + trimHspace(s.String()) + "]"
}

func (ind *Indentation) RememberUsedVariables(cond *MkCond) {
	cond.Walk(&MkCondCallback{
		VarUse: func(varuse *MkVarUse) { ind.AddVar(varuse.varname) }})
}

func (ind *Indentation) IsEmpty() bool {
	return len(ind.levels) == 0
}

func (ind *Indentation) top() *indentationLevel {
	return &ind.levels[len(ind.levels)-1]
}

// Depth returns the number of space characters by which the directive
// should be indented.
//
// This is typically two more than the surrounding level, except for
// multiple-inclusion guards.
func (ind *Indentation) Depth(directive string) int {
	i := len(ind.levels) - 1
	switch directive {
	case "elif", "else", "endfor", "endif":
		i--
	}
	if i < 0 {
		return 0
	}
	return ind.levels[i].depth
}

func (ind *Indentation) Pop() {
	ind.levels = ind.levels[:len(ind.levels)-1]
}

func (ind *Indentation) Push(mkline *MkLine, indent int, args string, guard bool) {
	assert(mkline.IsDirective())
	ind.levels = append(ind.levels,
		indentationLevel{mkline, indent, args, mkline, nil, nil, guard})
}

// AddVar remembers that the current indentation depends on the given variable,
// most probably because that variable is used in a .if directive.
//
// Variables named *_MK are ignored since they are usually not interesting.
func (ind *Indentation) AddVar(varname string) {
	if hasSuffix(varname, "_MK") {
		return
	}

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
// any .if or .elif expression, or is inside a .for loop.
//
// Variables named *_MK are excluded since they are usually not interesting.
func (ind *Indentation) IsConditional() bool {
	for _, level := range ind.levels {
		if !level.guard {
			return true
		}
	}
	return false
}

// Varnames returns the list of all variables that are mentioned in any
// condition or loop surrounding the current line.
//
// Variables named *_MK are excluded since they are usually not interesting.
func (ind *Indentation) Varnames() []string {
	varnames := NewStringSet()
	for _, level := range ind.levels {
		for _, levelVarname := range level.conditionalVars {
			varnames.Add(levelVarname)
		}
	}
	return varnames.Elements
}

// Args returns the arguments of the innermost .if, .elif or .for.
func (ind *Indentation) Args() (string, *MkLine) {
	return ind.top().args, ind.top().argsLine
}

func (ind *Indentation) AddCheckedFile(filename PkgsrcPath) {
	top := ind.top()
	top.checkedFiles = append(top.checkedFiles, filename)
}

// HasExists returns whether the given filename has been tested in an
// exists(filename) condition and thus may or may not exist.
//
func (ind *Indentation) HasExists(filename PkgsrcPath) bool {
	for _, level := range ind.levels {
		for _, levelFilename := range level.checkedFiles {
			if filename == levelFilename {
				return true
			}
		}
	}
	return false
}

func (ind *Indentation) TrackBefore(mkline *MkLine) {
	if !mkline.IsDirective() {
		return
	}

	directive := mkline.Directive()
	switch directive {
	case "for", "if", "ifdef", "ifndef":
		guard := false
		if directive == "if" {
			cond := mkline.Cond()
			guard = cond != nil && cond.Not != nil && hasSuffix(cond.Not.Defined, "_MK")
		}
		ind.Push(mkline, ind.Depth(directive), mkline.Args(), guard)
	}
}

func (ind *Indentation) TrackAfter(mkline *MkLine) {
	if !mkline.IsDirective() {
		return
	}

	directive := mkline.Directive()
	args := mkline.Args()

	switch directive {
	case "if":
		// For multiple-inclusion guards, the indentation stays at the same level.
		if !ind.top().guard {
			ind.top().depth += 2
		}

	case "for", "ifdef", "ifndef":
		ind.top().depth += 2

	case "elif":
		// Handled here instead of TrackBefore to allow the action to access the previous condition.
		if !ind.IsEmpty() {
			ind.top().args = args
			ind.top().argsLine = mkline
		}

	case "else":
		if !ind.IsEmpty() {
			ind.top().mkline.SetHasElseBranch(mkline)
		}

	case "endfor", "endif":
		if !ind.IsEmpty() { // Can only be false in unbalanced files.
			ind.Pop()
		}
	}

	switch directive {
	case "if", "elif":
		cond := mkline.Cond()
		if cond == nil {
			break
		}

		ind.RememberUsedVariables(cond)

		cond.Walk(&MkCondCallback{
			Call: func(name string, arg string) {
				if name == "exists" && !NewPath(arg).IsAbs() {
					rel := G.Pkgsrc.Rel(mkline.File(NewRelPathString(arg)))
					ind.AddCheckedFile(rel)
				}
			}})
	}
}

func (ind *Indentation) CheckFinish(filename CurrPath) {
	if ind.IsEmpty() {
		return
	}
	eofLine := NewLineEOF(filename)
	for !ind.IsEmpty() {
		openingMkline := ind.top().mkline
		eofLine.Errorf(".%s from %s must be closed.", openingMkline.Directive(), eofLine.RelLine(openingMkline.Line))
		ind.Pop()
	}
}

// VarbaseBytes contains characters that may be used in the main part of variable names.
// VarparamBytes contains characters that may be used in the parameter part of variable names.
//
// For example, TOOLS_PATH.[ is a valid variable name but [ alone isn't since
// the opening bracket is only allowed in the parameter part of variable names.
//
// This approach differs from the one in devel/bmake/files/parse.c:/^Parse_IsVar,
// but in practice it works equally well. Luckily there aren't many situations
// where a complicated variable name contains unbalanced parentheses or braces,
// which would confuse the devel/bmake parser.
//
// TODO: The allowed characters differ between the basename and the parameter
//  of the variable. The square bracket is only allowed in the parameter part.
var (
	// TODO: remove the ','
	VarbaseBytes = textproc.NewByteSet("A-Za-z_0-9-+,")
	// TODO: Check whether the ',' really needs to be here.
	VarparamBytes = textproc.NewByteSet("A-Za-z_0-9-#*+,./[")
)

func MatchMkInclude(text string) (m bool, indentation, directive string, filename RelPath) {
	tokens, rest := NewMkLexer(text, nil).MkTokens()
	if rest != "" {
		return false, "", "", ""
	}

	lexer := NewMkTokensLexer(tokens)
	if !lexer.SkipByte('.') {
		return false, "", "", ""
	}

	indentation = lexer.NextHspace()

	directive = lexer.NextString("include")
	if directive == "" {
		directive = lexer.NextString("sinclude")
	}
	if directive == "" {
		return false, "", "", ""
	}

	lexer.SkipHspace()
	if !lexer.SkipByte('"') {
		return false, "", "", ""
	}

	mark := lexer.Mark()
	for lexer.SkipBytesFunc(func(c byte) bool { return c != '"' && c != '$' }) ||
		lexer.NextVarUse() != nil {
	}
	enclosed := NewPath(lexer.Since(mark))

	if enclosed.IsEmpty() || enclosed.IsAbs() || !lexer.SkipByte('"') {
		return false, "", "", ""
	}
	lexer.SkipHspace()
	if !lexer.EOF() {
		return false, "", "", ""
	}

	filename = NewRelPath(enclosed)
	m = true
	return
}
