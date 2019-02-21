package pkglint

// Checks concerning single lines in Makefiles.

import (
	"fmt"
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/textproc"
	"path"
	"strings"
)

// MkLine is a line from a Makefile fragment.
// There are several types of lines.
// The most common types in pkgsrc are variable assignments,
// shell commands and directives like .if and .for.
type MkLine = *MkLineImpl

type MkLineImpl struct {
	Line
	data interface{} // One of the following mkLine* types
}
type mkLineAssign = *mkLineAssignImpl // See https://github.com/golang/go/issues/28045
type mkLineAssignImpl struct {
	commented   bool       // Whether the whole variable assignment is commented out
	varname     string     // e.g. "HOMEPAGE", "SUBST_SED.perl"
	varcanon    string     // e.g. "HOMEPAGE", "SUBST_SED.*"
	varparam    string     // e.g. "", "perl"
	op          MkOperator //
	valueAlign  string     // The text up to and including the assignment operator, e.g. VARNAME+=\t
	value       string     // The trimmed value
	valueMk     []*MkToken // The value, sent through splitIntoMkWords
	valueMkRest string     // nonempty in case of parse errors
	fields      []string   // The value, space-separated according to shell quoting rules
	comment     string
}
type mkLineShell struct {
	command string
}
type mkLineComment struct{} // See mkLineAssignImpl.commented for another type of comment line
type mkLineEmpty struct{}
type mkLineDirective = *mkLineDirectiveImpl // See https://github.com/golang/go/issues/28045
type mkLineDirectiveImpl struct {
	indent    string // the space between the leading "." and the directive
	directive string // "if", "else", "for", etc.
	args      string
	comment   string   // mainly interesting for .endif and .endfor
	elseLine  MkLine   // for .if (filled in later)
	cond      MkCond   // for .if and .elif (filled in on first access)
	fields    []string // the arguments for the .for loop (filled in on first access)
}
type mkLineInclude = *mkLineIncludeImpl // See https://github.com/golang/go/issues/28045
type mkLineIncludeImpl struct {
	mustExist       bool     // for .sinclude, nonexistent files are ignored
	sys             bool     // whether the include uses <file.mk> (very rare) instead of "file.mk"
	indent          string   // the space between the leading "." and the directive
	includedFile    string   // the text between the <brackets> or "quotes"
	conditionalVars []string // variables on which this inclusion depends (filled in later, as needed)
}
type mkLineDependency struct {
	targets string
	sources string
}

// NewMkLine parses the text of a Makefile line to see what kind of line
// it is: variable assignment, include, comment, etc.
//
// See devel/bmake/parse.c:/^Parse_File/
func NewMkLine(line Line) *MkLineImpl {
	text := line.Text

	// XXX: This check should be moved somewhere else. NewMkLine should only be concerned with parsing.
	if hasPrefix(text, " ") && line.Basename != "bsd.buildlink3.mk" {
		line.Warnf("Makefile lines should not start with space characters.")
		G.Explain(
			"If this line should be a shell command connected to a target, use a tab character for indentation.",
			"Otherwise remove the leading whitespace.")
	}

	if m, commented, varname, spaceAfterVarname, op, valueAlign, value, spaceAfterValue, comment := MatchVarassign(text); m {
		if spaceAfterVarname != "" {
			switch {
			case hasSuffix(varname, "+") && op == "=":
				break
			case matches(varname, `^[a-z]`) && op == ":=":
				break
			default:
				// XXX: This check should be moved somewhere else. NewMkLine should only be concerned with parsing.
				fix := line.Autofix()
				fix.Notef("Unnecessary space after variable name %q.", varname)
				fix.Replace(varname+spaceAfterVarname+op, varname+op)
				fix.Apply()
			}
		}

		// XXX: This check should be moved somewhere else. NewMkLine should only be concerned with parsing.
		if comment != "" && value != "" && spaceAfterValue == "" {
			line.Warnf("The # character starts a Makefile comment.")
			G.Explain(
				"In a variable assignment, an unescaped # starts a comment that",
				"continues until the end of the line.",
				"To escape the #, write \\#.")
		}

		return &MkLineImpl{line, &mkLineAssignImpl{
			commented,
			varname,
			varnameCanon(varname),
			varnameParam(varname),
			NewMkOperator(op),
			valueAlign,
			strings.Replace(value, "\\#", "#", -1),
			nil,
			"",
			nil,
			comment}}
	}

	if hasPrefix(text, "\t") {
		shellcmd := text[1:]
		return &MkLineImpl{line, mkLineShell{shellcmd}}
	}

	trimmedText := trimHspace(text)
	if strings.HasPrefix(trimmedText, "#") {
		return &MkLineImpl{line, mkLineComment{}}
	}

	if trimmedText == "" {
		return &MkLineImpl{line, mkLineEmpty{}}
	}

	if m, indent, directive, args, comment := matchMkDirective(text); m {
		return &MkLineImpl{line, &mkLineDirectiveImpl{indent, directive, args, comment, nil, nil, nil}}
	}

	if m, indent, directive, includedFile := MatchMkInclude(text); m {
		return &MkLineImpl{line, &mkLineIncludeImpl{directive == "include", false, indent, includedFile, nil}}
	}

	if m, indent, directive, includedFile := match3(text, `^\.([\t ]*)(s?include)[\t ]+<([^>]+)>[\t ]*(?:#.*)?$`); m {
		return &MkLineImpl{line, &mkLineIncludeImpl{directive == "include", true, indent, includedFile, nil}}
	}

	// XXX: Replace this regular expression with proper parsing.
	// There might be a ${VAR:M*.c} in these variables, which the below regular expression cannot handle.
	if m, targets, whitespace, sources := match3(text, `^([^\t :]+(?:[\t ]*[^\t :]+)*)([\t ]*):[\t ]*([^#]*?)(?:[\t ]*#.*)?$`); m {
		// XXX: This check should be moved somewhere else. NewMkLine should only be concerned with parsing.
		if whitespace != "" {
			line.Notef("Space before colon in dependency line.")
		}
		return &MkLineImpl{line, mkLineDependency{targets, sources}}
	}

	if matches(text, `^(<<<<<<<|=======|>>>>>>>)`) {
		return &MkLineImpl{line, nil}
	}

	// The %q is deliberate here since it shows possible strange characters.
	line.Errorf("Unknown Makefile line format: %q.", text)
	return &MkLineImpl{line, nil}
}

func (mkline *MkLineImpl) String() string {
	return sprintf("%s:%s", mkline.Filename, mkline.Linenos())
}

// IsVarassign returns true for variable assignments of the form VAR=value.
//
// See IsCommentedVarassign.
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

// IsComment returns true for lines that consist entirely of a comment.
func (mkline *MkLineImpl) IsComment() bool {
	_, ok := mkline.data.(mkLineComment)
	return ok || mkline.IsCommentedVarassign()
}

func (mkline *MkLineImpl) IsEmpty() bool {
	_, ok := mkline.data.(mkLineEmpty)
	return ok
}

// IsDirective returns true for conditionals (.if/.elif/.else/.if) or loops (.for/.endfor).
//
// See IsInclude.
func (mkline *MkLineImpl) IsDirective() bool {
	_, ok := mkline.data.(mkLineDirective)
	return ok
}

// IsInclude returns true for lines like: .include "other.mk"
//
// See IsSysinclude for lines like: .include <sys.mk>
func (mkline *MkLineImpl) IsInclude() bool {
	incl, ok := mkline.data.(mkLineInclude)
	return ok && !incl.sys
}

// IsSysinclude returns true for lines like: .include <sys.mk>
//
// See IsInclude for lines like: .include "other.mk"
func (mkline *MkLineImpl) IsSysinclude() bool {
	incl, ok := mkline.data.(mkLineInclude)
	return ok && incl.sys
}

// IsDependency returns true for dependency lines like "target: source".
func (mkline *MkLineImpl) IsDependency() bool {
	_, ok := mkline.data.(mkLineDependency)
	return ok
}

// Varname applies to variable assignments and returns the name
// of the variable that is assigned or appended to.
//
// Example:
//  VARNAME.${param}?=      value   # Varname is "VARNAME.${param}"
func (mkline *MkLineImpl) Varname() string { return mkline.data.(mkLineAssign).varname }

// Varcanon applies to variable assignments and returns the canonicalized variable name for parameterized variables.
// Examples:
//  HOMEPAGE           => "HOMEPAGE"
//  SUBST_SED.anything => "SUBST_SED.*"
//  SUBST_SED.${param} => "SUBST_SED.*"
func (mkline *MkLineImpl) Varcanon() string { return mkline.data.(mkLineAssign).varcanon }

// Varparam applies to variable assignments and returns the parameter for parameterized variables.
// Examples:
//  HOMEPAGE           => ""
//  SUBST_SED.anything => "anything"
//  SUBST_SED.${param} => "${param}"
func (mkline *MkLineImpl) Varparam() string { return mkline.data.(mkLineAssign).varparam }

// Op applies to variable assignments and returns the assignment operator.
func (mkline *MkLineImpl) Op() MkOperator { return mkline.data.(mkLineAssign).op }

// ValueAlign applies to variable assignments and returns all the text
// before the variable value, e.g. "VARNAME+=\t".
func (mkline *MkLineImpl) ValueAlign() string { return mkline.data.(mkLineAssign).valueAlign }

func (mkline *MkLineImpl) Value() string { return mkline.data.(mkLineAssign).value }

// VarassignComment applies to variable assignments and returns the comment.
//
// Example:
//  VAR=value # comment
//
// In the above line, the comment is "# comment".
//
// The leading "#" is included so that pkglint can distinguish between no comment at all and an empty comment.
func (mkline *MkLineImpl) VarassignComment() string { return mkline.data.(mkLineAssign).comment }

func (mkline *MkLineImpl) ShellCommand() string { return mkline.data.(mkLineShell).command }

func (mkline *MkLineImpl) Indent() string {
	if mkline.IsDirective() {
		return mkline.data.(mkLineDirective).indent
	} else {
		return mkline.data.(mkLineInclude).indent
	}
}

// Directive returns the preprocessing directive, like "if", "for", "endfor", etc.
//
// See matchMkDirective.
func (mkline *MkLineImpl) Directive() string { return mkline.data.(mkLineDirective).directive }

// Args returns the arguments from an .if, .ifdef, .ifndef, .elif, .for, .undef.
func (mkline *MkLineImpl) Args() string { return mkline.data.(mkLineDirective).args }

// Cond applies to an .if or .elif line and returns the parsed condition.
//
// If a parse error occurs, it is silently swallowed, returning a
// best-effort part of the condition, or even nil.
func (mkline *MkLineImpl) Cond() MkCond {
	cond := mkline.data.(mkLineDirective).cond
	if cond == nil {
		cond = NewMkParser(nil, mkline.Args(), false).MkCond()
		mkline.data.(mkLineDirective).cond = cond
	}
	return cond
}

// DirectiveComment is the trailing end-of-line comment, typically at a deeply nested .endif or .endfor.
func (mkline *MkLineImpl) DirectiveComment() string { return mkline.data.(mkLineDirective).comment }

func (mkline *MkLineImpl) HasElseBranch() bool { return mkline.data.(mkLineDirective).elseLine != nil }

func (mkline *MkLineImpl) SetHasElseBranch(elseLine MkLine) {
	data := mkline.data.(mkLineDirective)
	data.elseLine = elseLine
	mkline.data = data
}

func (mkline *MkLineImpl) MustExist() bool { return mkline.data.(mkLineInclude).mustExist }

func (mkline *MkLineImpl) IncludedFile() string { return mkline.data.(mkLineInclude).includedFile }

func (mkline *MkLineImpl) Targets() string { return mkline.data.(mkLineDependency).targets }

func (mkline *MkLineImpl) Sources() string { return mkline.data.(mkLineDependency).sources }

// ConditionalVars applies to .include lines and is a space-separated
// list of those variable names on which the inclusion depends.
// It is initialized later, step by step, when parsing other lines.
func (mkline *MkLineImpl) ConditionalVars() []string {
	return mkline.data.(mkLineInclude).conditionalVars
}
func (mkline *MkLineImpl) SetConditionalVars(varnames []string) {
	include := mkline.data.(mkLineInclude)
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
func (mkline *MkLineImpl) Tokenize(text string, warn bool) []*MkToken {
	if trace.Tracing {
		defer trace.Call(mkline, text)()
	}

	var tokens []*MkToken
	var rest string
	if (mkline.IsVarassign() || mkline.IsCommentedVarassign()) && text == mkline.Value() {
		tokens, rest = mkline.ValueTokens()
	} else {
		p := NewMkParser(mkline.Line, text, true)
		tokens = p.MkTokens()
		rest = p.Rest()
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
func (mkline *MkLineImpl) ValueSplit(value string, separator string) []string {
	G.Assertf(separator != "", "Separator must not be empty; use ValueFields to split on whitespace")

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

// ValueFields splits the given value, taking care of variable references.
// Example:
//
//  ValueFields("${VAR:Udefault value} ${VAR2}two words")
//  => "${VAR:Udefault value}"
//     "${VAR2}two"
//     "words"
//
// Note that even though the first word contains a space, it is not split
// at that point since the space is inside a variable use.
func (mkline *MkLineImpl) ValueFields(value string) []string {
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
				for lexer.NextBytesSet(textproc.Space) != "" {
					cont = false
				}
				if word := lexer.NextBytesSet(textproc.Space.Inverse()); word != "" {
					out(word)
					cont = true
				}
			}
		}
	}
	return split
}

func (mkline *MkLineImpl) ValueTokens() ([]*MkToken, string) {
	value := mkline.Value()
	if value == "" {
		return nil, ""
	}

	assign := mkline.data.(mkLineAssign)
	if assign.valueMk != nil || assign.valueMkRest != "" {
		return assign.valueMk, assign.valueMkRest
	}

	p := NewMkParser(mkline.Line, value, true)
	assign.valueMk = p.MkTokens()
	assign.valueMkRest = p.Rest()
	return assign.valueMk, assign.valueMkRest
}

// Fields applies to variable assignments and .for loops.
// For variable assignments, it returns the right-hand side, properly split into words.
// For .for loops, it returns all arguments (including variable names), properly split into words.
func (mkline *MkLineImpl) Fields() []string {
	if mkline.IsVarassign() {
		value := mkline.Value()
		if value == "" {
			return nil
		}

		assign := mkline.data.(mkLineAssign)
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

	directive := mkline.data.(mkLineDirective)
	if directive.fields != nil {
		return directive.fields
	}

	directive.fields = mkline.ValueFields(args)
	return directive.fields

}

func (mkline *MkLineImpl) WithoutMakeVariables(value string) string {
	valueNovar := ""
	for _, token := range NewMkParser(nil, value, false).MkTokens() {
		if token.Varuse == nil {
			valueNovar += token.Text
		}
	}
	return valueNovar
}

func (mkline *MkLineImpl) ResolveVarsInRelativePath(relativePath string) string {

	var basedir string
	if G.Pkg != nil {
		basedir = G.Pkg.File(".")
	} else {
		basedir = path.Dir(mkline.Filename)
	}

	tmp := relativePath
	if contains(tmp, "PKGSRCDIR") {
		pkgsrcdir := relpath(basedir, G.Pkgsrc.File("."))

		if G.Testing {
			// Relative pkgsrc paths usually only contain two or three levels.
			// A possible reason for reaching this assertion is a pkglint unit test
			// that uses t.NewMkLines instead of the correct t.SetUpFileMkLines.
			G.Assertf(!contains(pkgsrcdir, "../../../../.."),
				"Relative path %q for %q is too deep below the pkgsrc root %q.",
				pkgsrcdir, basedir, G.Pkgsrc.File("."))
		}
		tmp = strings.Replace(tmp, "${PKGSRCDIR}", pkgsrcdir, -1)
	}
	tmp = strings.Replace(tmp, "${.CURDIR}", ".", -1)   // TODO: Replace with the "typical" os.Getwd().
	tmp = strings.Replace(tmp, "${.PARSEDIR}", ".", -1) // FIXME

	replaceLatest := func(varuse, category string, pattern regex.Pattern, replacement string) {
		if contains(tmp, varuse) {
			latest := G.Pkgsrc.Latest(category, pattern, replacement)
			tmp = strings.Replace(tmp, varuse, latest, -1)
		}
	}

	// These variables are only used in pkgsrc packages, therefore they
	// are replaced with the fixed "../.." regardless of where the text appears.
	replaceLatest("${LUA_PKGSRCDIR}", "lang", `^lua[0-9]+$`, "../../lang/$0")
	replaceLatest("${PHPPKGSRCDIR}", "lang", `^php[0-9]+$`, "../../lang/$0")
	replaceLatest("${PYPKGSRCDIR}", "lang", `^python[0-9]+$`, "../../lang/$0")

	replaceLatest("${PYPACKAGE}", "lang", `^python[0-9]+$`, "$0")
	replaceLatest("${SUSE_DIR_PREFIX}", "emulators", `^(suse[0-9]+)_base$`, "$1")

	if G.Pkg != nil {
		// XXX: Even if these variables are defined indirectly,
		// pkglint should be able to resolve them properly.
		// There is already G.Pkg.Value, maybe that can be used here.
		tmp = strings.Replace(tmp, "${FILESDIR}", G.Pkg.Filesdir, -1)
		tmp = strings.Replace(tmp, "${PKGDIR}", G.Pkg.Pkgdir, -1)
	}

	tmp = cleanpath(tmp)

	if trace.Tracing && relativePath != tmp {
		trace.Step2("resolveVarsInRelativePath: %q => %q", relativePath, tmp)
	}
	return tmp
}

func (mkline *MkLineImpl) ExplainRelativeDirs() {
	G.Explain(
		"Directories in the form \"../../category/package\" make it easier to",
		"move a package around in pkgsrc, for example from pkgsrc-wip to the",
		"main pkgsrc repository.")
}

// RefTo returns a reference to another line,
// which can be in the same file or in a different file.
//
// If there is a type mismatch when calling this function, try to add ".line" to
// either the method receiver or the other line.
func (mkline *MkLineImpl) RefTo(other MkLine) string {
	return mkline.Line.RefTo(other.Line)
}

var (
	LowerDash = textproc.NewByteSet("a-z---")
	AlnumDot  = textproc.NewByteSet("A-Za-z0-9_.")
)

func matchMkDirective(text string) (m bool, indent, directive, args, comment string) {
	lexer := textproc.NewLexer(text)
	if !lexer.SkipByte('.') {
		return
	}

	indent = lexer.NextHspace()
	directive = lexer.NextBytesSet(LowerDash)
	switch directive {
	case "if", "else", "elif", "endif",
		"ifdef", "ifndef",
		"for", "endfor", "undef",
		"error", "warning", "info",
		"export", "export-env", "unexport", "unexport-env":
		break
	default:
		// Intentionally not supported are: ifmake ifnmake elifdef elifndef elifmake elifnmake.
		return
	}

	lexer.SkipHspace()

	argsStart := lexer.Mark()
	for !lexer.EOF() && lexer.PeekByte() != '#' {
		switch {
		case lexer.SkipString("[#"):
			// See devel/bmake/files/parse.c:/as in modifier/

		case lexer.PeekByte() == '\\' && len(lexer.Rest()) > 1:
			lexer.Skip(2)

		default:
			lexer.Skip(1)
		}
	}
	args = lexer.Since(argsStart)
	args = strings.TrimFunc(args, func(r rune) bool { return isHspace(byte(r)) })
	args = strings.Replace(args, "\\#", "#", -1)

	if !lexer.EOF() {
		lexer.Skip(1)
		lexer.SkipHspace()
		comment = lexer.Rest()
	}

	m = true
	return
}

// VariableNeedsQuoting determines whether the given variable needs the :Q operator
// in the given context.
//
// This decision depends on many factors, such as whether the type of the context is
// a list of things, whether the variable is a list, whether it can contain only
// safe characters, and so on.
func (mkline *MkLineImpl) VariableNeedsQuoting(varname string, vartype *Vartype, vuc *VarUseContext) (needsQuoting YesNoUnknown) {
	if trace.Tracing {
		defer trace.Call(varname, vartype, vuc, trace.Result(&needsQuoting))()
	}

	// TODO: Systematically test this function, each and every case, from top to bottom.
	// TODO: Re-check the order of all these if clauses whether it really makes sense.

	vucVartype := vuc.vartype
	if vartype == nil || vucVartype == nil || vartype.basicType == BtUnknown {
		return unknown
	}

	if !vartype.basicType.NeedsQ() {
		if vartype.kindOfList == lkNone {
			if vartype.guessed {
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
		if vartype.kindOfList == lkNone && vartype.basicType == BtShellWord {
			return no
		}
	}

	// Determine whether the context expects a list of shell words or not.
	wantList := vucVartype.IsConsideredList()
	haveList := vartype.IsConsideredList()
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
	if tool := G.ToolByVarname(varname); tool != nil {
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
	if vucVartype.IsPlainString() {
		return no
	}

	if wantList != haveList {
		if vucVartype.basicType == BtFetchURL && vartype.basicType == BtHomepage {
			return no
		}
		if vucVartype.basicType == BtHomepage && vartype.basicType == BtFetchURL {
			return no // Just for HOMEPAGE=${MASTER_SITE_*:=subdir/}.
		}
		return yes
	}

	// Bad: LDADD+= -l${LIBS}
	// Good: LDADD+= ${LIBS:S,^,-l,}
	if wantList {
		return yes
	}

	if trace.Tracing {
		trace.Step1("Don't know whether :Q is needed for %q", varname)
	}
	return unknown
}

func (mkline *MkLineImpl) DetermineUsedVariables() []string {
	// TODO: It would be good to have these variables as MkVarUse objects
	//  including the context in which they are used.

	var varnames []string

	add := func(varname string) {
		varnames = append(varnames, varname)
	}

	var searchIn func(text string) // mutually recursive with searchInVarUse

	searchInVarUse := func(varuse *MkVarUse) {
		varname := varuse.varname
		if !varuse.IsExpression() {
			add(varname)
		}
		searchIn(varname)
		for _, mod := range varuse.modifiers {
			searchIn(mod.Text)
		}
	}

	searchIn = func(text string) {
		if !contains(text, "$") {
			return
		}

		for _, token := range NewMkParser(nil, text, false).MkTokens() {
			if token.Varuse != nil {
				searchInVarUse(token.Varuse)
			}
		}
	}

	switch {

	case mkline.IsVarassign():
		searchIn(mkline.Varname())
		searchIn(mkline.Value())

	case mkline.IsDirective() && mkline.Directive() == "for":
		searchIn(mkline.Args())

	case mkline.IsDirective() && mkline.Cond() != nil:
		mkline.Cond().Walk(&MkCondCallback{VarUse: searchInVarUse})

	case mkline.IsShellCommand():
		searchIn(mkline.ShellCommand())

	case mkline.IsDependency():
		searchIn(mkline.Targets())
		searchIn(mkline.Sources())

	case mkline.IsInclude():
		searchIn(mkline.IncludedFile())
	}

	return varnames
}

func (mkline *MkLineImpl) UnquoteShell(str string) string {
	var sb strings.Builder
	n := len(str)

outer:
	for i := 0; i < n; i++ {
		switch str[i] {
		case '"':
			for i++; i < n; i++ {
				switch str[i] {
				case '"':
					continue outer
				case '\\':
					i++
					if i < n {
						sb.WriteByte(str[i])
					}
				default:
					sb.WriteByte(str[i])
				}
			}

		case '\'':
			for i++; i < n && str[i] != '\''; i++ {
				sb.WriteByte(str[i])
			}

		case '\\':
			i++
			if i < n {
				sb.WriteByte(str[i])
			}

		default:
			sb.WriteByte(str[i])
		}
	}

	return sb.String()
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
	quoting    VucQuoting
	IsWordPart bool // Example: LOCALBASE=${LOCALBASE}
}

// vucTime is the time at which a variable is used.
//
// See ToolTime, which is the same except that there is no unknown.
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
	//
	// Well, except for the ::= modifier.
	// But that modifier is usually not used in pkgsrc.
	vucTimeRun
)

func (t vucTime) String() string { return [...]string{"unknown", "parse", "run"}[t] }

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
type Indentation struct {
	levels []indentationLevel
}

func NewIndentation() *Indentation {
	ind := Indentation{}
	ind.Push(nil, 0, "") // Dummy
	return &ind
}

func (ind *Indentation) String() string {
	var s strings.Builder
	for _, level := range ind.levels[1:] {
		_, _ = fmt.Fprintf(&s, " %d", level.depth)
		if len(level.conditionalVars) > 0 {
			_, _ = fmt.Fprintf(&s, " (%s)", strings.Join(level.conditionalVars, " "))
		}
	}
	return "[" + trimHspace(s.String()) + "]"
}

func (ind *Indentation) RememberUsedVariables(cond MkCond) {
	cond.Walk(&MkCondCallback{
		VarUse: func(varuse *MkVarUse) { ind.AddVar(varuse.varname) }})
}

type indentationLevel struct {
	mkline          MkLine   // The line in which the indentation started; the .if/.for
	depth           int      // Number of space characters; always a multiple of 2
	args            string   // The arguments from the .if or .for, or the latest .elif
	conditionalVars []string // Variables on which the current path depends

	// Files whose existence has been checked in an if branch that is
	// related to the current indentation. After a .if exists(fname),
	// pkglint will happily accept .include "fname" in both the then and
	// the else branch. This is ok since the primary job of this file list
	// is to prevent wrong pkglint warnings about missing files.
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
//
// This is typically two more than the surrounding level, except for
// multiple-inclusion guards.
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
// any variable in an .if or .elif expression or from a .for loop.
//
// Variables named *_MK are excluded since they are usually not interesting.
func (ind *Indentation) IsConditional() bool {
	for _, level := range ind.levels {
		if len(level.conditionalVars) > 0 {
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
	var varnames []string
	for _, level := range ind.levels {
		for _, levelVarname := range level.conditionalVars {
			G.Assertf(
				!hasSuffix(levelVarname, "_MK"),
				"multiple-inclusion guard must be filtered out earlier.")
			varnames = append(varnames, levelVarname)
		}
	}
	return varnames
}

// Args returns the arguments of the innermost .if, .elif or .for.
func (ind *Indentation) Args() string {
	return ind.top().args
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

	switch mkline.Directive() {
	case "for", "if", "ifdef", "ifndef":
		ind.Push(mkline, ind.top().depth, mkline.Args())
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
		cond := mkline.Cond()

		// For multiple-inclusion guards, the indentation stays at the same level.
		guard := cond != nil && cond.Not != nil && hasSuffix(cond.Not.Defined, "_MK")
		if !guard {
			ind.top().depth += 2
		}

	case "for", "ifdef", "ifndef":
		ind.top().depth += 2

	case "elif":
		// Handled here instead of TrackBefore to allow the action to access the previous condition.
		ind.top().args = args

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

	switch directive {
	case "if", "elif":
		cond := mkline.Cond()
		if cond == nil {
			break
		}

		ind.RememberUsedVariables(cond)

		cond.Walk(&MkCondCallback{
			Call: func(name string, arg string) {
				if name == "exists" {
					ind.AddCheckedFile(arg)
				}
			}})
	}

	if trace.Tracing {
		trace.Stepf("Indentation after line %s: %s", mkline.Linenos(), ind)
	}
}

func (ind *Indentation) CheckFinish(filename string) {
	if ind.Len() <= 1 {
		return
	}
	eofLine := NewLineEOF(filename)
	for ind.Len() > 1 {
		openingMkline := ind.levels[ind.Len()-1].mkline
		eofLine.Errorf(".%s from %s must be closed.", openingMkline.Directive(), eofLine.RefTo(openingMkline.Line))
		ind.Pop()
	}
}

// VarnameBytes contains characters that may be used in variable names.
// The bracket is included only for the tool of the same name, e.g. "TOOLS_PATH.[".
//
// This approach differs from the one in devel/bmake/files/parse.c:/^Parse_IsVar,
// but in practice it works equally well. Luckily there aren't many situations
// where a complicated variable name contains unbalanced parentheses or braces,
// which would confuse the devel/bmake parser.
var VarnameBytes = textproc.NewByteSet("A-Za-z_0-9*+---.[")

func MatchVarassign(text string) (m, commented bool, varname, spaceAfterVarname, op, valueAlign, value, spaceAfterValue, comment string) {
	lexer := textproc.NewLexer(text)

	commented = lexer.SkipByte('#')
	for !commented && lexer.SkipByte(' ') {
	}

	varnameStart := lexer.Mark()
	for !lexer.EOF() {
		switch {

		case lexer.NextBytesSet(VarnameBytes) != "":
			continue

		case lexer.PeekByte() == '$':
			parser := NewMkParser(nil, lexer.Rest(), false)
			varuse := parser.VarUse()
			if varuse == nil {
				return
			}
			varuseLen := len(lexer.Rest()) - len(parser.Rest())
			lexer.Skip(varuseLen)
			continue
		}
		break
	}
	varname = lexer.Since(varnameStart)

	if varname == "" {
		return
	}

	spaceAfterVarname = lexer.NextHspace()

	opStart := lexer.Mark()
	switch lexer.PeekByte() {
	case '!', '+', ':', '?':
		lexer.Skip(1)
	}
	if !lexer.SkipByte('=') {
		return
	}
	op = lexer.Since(opStart)

	if hasSuffix(varname, "+") && op == "=" && spaceAfterVarname == "" {
		varname = varname[:len(varname)-1]
		op = "+="
	}

	lexer.SkipHspace()

	valueAlign = text[:len(text)-len(lexer.Rest())]
	valueStart := lexer.Mark()
	// FIXME: This is the same code as in matchMkDirective.
	for !lexer.EOF() && lexer.PeekByte() != '#' {
		switch {
		case lexer.SkipString("[#"):
			break

		case lexer.PeekByte() == '\\' && len(lexer.Rest()) > 1:
			lexer.Skip(2)

		default:
			lexer.Skip(1)
		}
	}
	rawValueWithSpace := lexer.Since(valueStart)
	spaceAfterValue = rawValueWithSpace[len(strings.TrimRight(rawValueWithSpace, " \t")):]
	value = trimHspace(strings.Replace(lexer.Since(valueStart), "\\#", "#", -1))
	comment = lexer.Rest()

	m = true
	return
}

func MatchMkInclude(text string) (m bool, indentation, directive, filename string) {
	lexer := textproc.NewLexer(text)
	if lexer.SkipByte('.') {
		indentation = lexer.NextHspace()
		directive = lexer.NextString("include")
		if directive == "" {
			directive = lexer.NextString("sinclude")
		}
		if directive != "" {
			lexer.NextHspace()
			if lexer.SkipByte('"') {
				// Note: strictly speaking, the full MkVarUse would have to be parsed
				// here. But since these usually don't contain double quotes, it has
				// worked fine up to now.
				filename = lexer.NextBytesFunc(func(c byte) bool { return c != '"' })
				if filename != "" && lexer.SkipByte('"') {
					lexer.NextHspace()
					if lexer.EOF() || lexer.SkipByte('#') {
						m = true
						return
					}
				}
			}
		}
	}
	return false, "", "", ""
}
