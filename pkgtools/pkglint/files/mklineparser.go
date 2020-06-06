package pkglint

import (
	"netbsd.org/pkglint/textproc"
	"strings"
)

// MkLineParser parses a line of text into the syntactical parts of a
// line in Makefiles.
type MkLineParser struct{}

func NewMkLineParser() MkLineParser { return MkLineParser{} }

// Parse parses the text of a Makefile line to see what kind of line
// it is: variable assignment, include, comment, etc.
//
// See devel/bmake/parse.c:/^Parse_File/
func (p MkLineParser) Parse(line *Line) *MkLine {
	text := line.Text

	if hasPrefix(text, " ") && line.Basename != "bsd.buildlink3.mk" {
		line.Warnf("Makefile lines should not start with space characters.")
		line.Explain(
			"If this line should be a shell command connected to a target, use a tab character for indentation.",
			"Otherwise remove the leading whitespace.")
	}

	// Check for shell commands first because these cannot have comments
	// at the end of the line.
	if hasPrefix(text, "\t") {
		lex := textproc.NewLexer(text)
		lex.SkipHspace()

		splitResult := p.split(line, lex.Rest(), false)
		if lex.PeekByte() == '#' {
			return p.parseCommentOrEmpty(line, p.split(line, lex.Rest(), true))
		}
		return p.parseShellcmd(line, splitResult)
	}

	splitResult := p.split(line, text, true)

	if mkline := p.parseVarassign(line, text, splitResult); mkline != nil {
		return mkline
	}
	if mkline := p.parseCommentOrEmpty(line, splitResult); mkline != nil {
		return mkline
	}
	if mkline := p.parseDirective(line, splitResult); mkline != nil {
		return mkline
	}
	if mkline := p.parseInclude(line, splitResult); mkline != nil {
		return mkline
	}
	if mkline := p.parseSysinclude(line, splitResult); mkline != nil {
		return mkline
	}
	if mkline := p.parseDependency(line, splitResult); mkline != nil {
		return mkline
	}
	if mkline := p.parseMergeConflict(line, splitResult); mkline != nil {
		return mkline
	}

	// The %q is deliberate here since it shows possible strange characters.
	line.Errorf("Unknown Makefile line format: %q.", text)
	return &MkLine{line, splitResult, nil}
}

func (p MkLineParser) parseVarassign(line *Line, text string, splitResult mkLineSplitResult) *MkLine {
	m, a := p.MatchVarassign(line, text, &splitResult)
	if !m {
		return nil
	}

	p.fixSpaceAfterVarname(line, a)
	p.checkUnintendedComment(&splitResult, a, line)

	return &MkLine{line, splitResult, a}
}

func (p MkLineParser) MatchVarassign(line *Line, text string, splitResult *mkLineSplitResult) (bool, *mkLineAssign) {

	// A commented variable assignment does not have leading whitespace.
	// Otherwise line 1 of almost every Makefile fragment would need to
	// be scanned for a variable assignment even though it only contains
	// the $NetBSD CVS Id.
	commented := splitResult.main == "" && splitResult.hasComment
	if commented {
		clex := textproc.NewLexer(splitResult.comment)
		if clex.SkipHspace() || clex.EOF() {
			return false, nil
		}
		*splitResult = p.split(nil, text[1:], true)
	}

	lexer := NewMkTokensLexer(splitResult.tokens)
	mainStart := lexer.Mark()

	for !commented && lexer.SkipByte(' ') {
	}

	mkLexer := NewMkLexer(lexer.Rest(), nil)
	varname := mkLexer.Varname()
	lexer.SkipMixed(len(lexer.Rest()) - len(mkLexer.Rest()))

	if varname == "" {
		return false, nil
	}

	spaceAfterVarname := lexer.NextHspace()

	opStart := lexer.Mark()
	switch lexer.PeekByte() {
	case '!', '+', ':', '?':
		lexer.Skip(1)
	}
	if !lexer.SkipByte('=') {
		return false, nil
	}
	op := NewMkOperator(lexer.Since(opStart))

	if hasSuffix(varname, "+") && op == opAssign && spaceAfterVarname == "" {
		varname = varname[:len(varname)-1]
		op = opAssignAppend
	}

	lexer.SkipHspace()

	value := trimHspace(lexer.Rest())
	parsedValueAlign := condStr(commented, "#", "") + lexer.Since(mainStart)
	valueAlign := p.getRawValueAlign(line.raw[0].Orig(), parsedValueAlign)
	if value == "" {
		valueAlign += splitResult.spaceBeforeComment
		splitResult.spaceBeforeComment = ""
	}

	return true, &mkLineAssign{
		commented:         commented,
		varname:           varname,
		varcanon:          varnameCanon(varname),
		varparam:          varnameParam(varname),
		spaceAfterVarname: spaceAfterVarname,
		op:                op,
		value:             value,
		valueMk:           nil, // filled in lazily
		valueMkRest:       "",  // filled in lazily
		fields:            nil, // filled in lazily
	}
}

func (p MkLineParser) fixSpaceAfterVarname(line *Line, a *mkLineAssign) {
	if !(a.spaceAfterVarname != "") {
		return
	}

	varname := a.varname
	op := a.op
	switch {
	case hasSuffix(varname, "+") && (op == opAssign || op == opAssignAppend):
		break
	case matches(varname, `^[a-z]`) && op == opAssignEval:
		break

	default:
		parts := NewVaralignSplitter().split(line.RawText(0), true)
		before := parts.leadingComment + parts.varnameOp + parts.spaceBeforeValue
		after := alignWith(varname+op.String(), before)

		fix := line.Autofix()
		fix.Notef("Unnecessary space after variable name %q.", varname)
		fix.Replace(before, after)
		fix.Apply()
	}
}

func (p MkLineParser) checkUnintendedComment(splitResult *mkLineSplitResult, a *mkLineAssign, line *Line) {
	if !(splitResult.hasComment && a.value != "" && splitResult.spaceBeforeComment == "") {
		return
	}

	line.Warnf("The # character starts a Makefile comment.")
	line.Explain(
		"In a variable assignment, an unescaped # starts a comment that",
		"continues until the end of the line.",
		"To escape the #, write \\#.",
		"",
		"If this # character intentionally starts a comment,",
		"it should be preceded by a space in order to make it more visible.")
}

func (p MkLineParser) parseShellcmd(line *Line, splitResult mkLineSplitResult) *MkLine {
	return &MkLine{line, splitResult, mkLineShell{line.Text[1:]}}
}

func (p MkLineParser) parseCommentOrEmpty(line *Line, splitResult mkLineSplitResult) *MkLine {
	trimmedText := trimHspace(line.Text)

	if strings.HasPrefix(trimmedText, "#") {
		return &MkLine{line, splitResult, mkLineComment{}}
	}

	if trimmedText == "" {
		return &MkLine{line, splitResult, mkLineEmpty{}}
	}

	return nil
}

func (p MkLineParser) parseDirective(line *Line, splitResult mkLineSplitResult) *MkLine {
	lexer := textproc.NewLexer(splitResult.main)
	if !lexer.SkipByte('.') {
		return nil
	}

	indent := lexer.NextHspace()
	directive := lexer.NextBytesSet(LowerDash)
	switch directive {
	case "if", "else", "elif", "endif",
		"ifdef", "ifndef",
		"for", "endfor", "undef",
		"error", "warning", "info",
		"export", "export-env", "unexport", "unexport-env":
		break
	default:
		// Intentionally not supported are: ifmake ifnmake elifdef elifndef elifmake elifnmake.
		return nil
	}

	lexer.SkipHspace()

	args := lexer.Rest()

	// In .if and .endif lines the space surrounding the comment is irrelevant.
	// Especially for checking that the .endif comment matches the .if condition,
	// it must be trimmed.
	trimmedComment := trimHspace(splitResult.comment)

	return &MkLine{line, splitResult, &mkLineDirective{indent, directive, args, trimmedComment, nil, nil, nil}}
}

func (p MkLineParser) parseInclude(line *Line, splitResult mkLineSplitResult) *MkLine {
	m, indent, directive, includedFile := MatchMkInclude(splitResult.main)
	if !m {
		return nil
	}

	return &MkLine{line, splitResult, &mkLineInclude{directive == "include", false, indent, includedFile, nil}}
}

func (p MkLineParser) parseSysinclude(line *Line, splitResult mkLineSplitResult) *MkLine {
	m, indent, directive, includedFile := match3(splitResult.main, `^\.([\t ]*)(s?include)[\t ]+<([^>]+)>$`)
	if !m {
		return nil
	}

	return &MkLine{line, splitResult, &mkLineInclude{directive == "include", true, indent, NewRelPathString(includedFile), nil}}
}

func (p MkLineParser) parseDependency(line *Line, splitResult mkLineSplitResult) *MkLine {
	// XXX: Replace this regular expression with proper parsing.
	// There might be a ${VAR:M*.c} in these variables, which the below regular expression cannot handle.
	m, targets, whitespace, sources := match3(line.Text, `^([^\t :]+(?:[\t ]*[^\t :]+)*)([\t ]*):[\t ]*([^#]*?)(?:[\t ]*#.*)?$`)
	if !m {
		return nil
	}

	if whitespace != "" {
		line.Notef("Space before colon in dependency line.")
	}
	return &MkLine{line, splitResult, mkLineDependency{targets, sources}}
}

func (p MkLineParser) parseMergeConflict(line *Line, splitResult mkLineSplitResult) *MkLine {
	if !matches(line.Text, `^(<<<<<<<|=======|>>>>>>>)`) {
		return nil
	}

	return &MkLine{line, splitResult, nil}
}

// split parses a logical line from a Makefile (that is, after joining
// the lines that end in a backslash) into two parts: the main part and the
// comment.
//
// This applies to all line types except those starting with a tab, which
// contain the shell commands to be associated with make targets. These cannot
// have comments.
//
// If diag is given, it is used for logging parse errors and warnings
// about round parentheses instead of curly braces, as well as ambiguous
// variables of the form $v instead of ${v}.
//
// If trimComment is true, the main task of this method is to split the
// text into tokens. The remaining space is placed into spaceBeforeComment,
// but hasComment will always be false, and comment will always be empty.
// This behavior is useful for shell commands (which are indented with a
// single tab).
func (MkLineParser) split(diag Autofixer, text string, trimComment bool) mkLineSplitResult {
	assert(!hasPrefix(text, "\t"))

	var mainWithSpaces, comment string
	if trimComment {
		mainWithSpaces, comment = NewMkLineParser().unescapeComment(text)
	} else {
		mainWithSpaces = text
	}

	parser := NewMkLexer(mainWithSpaces, diag)
	lexer := parser.lexer

	parseOther := func() string {
		sb := NewLazyStringBuilder(lexer.Rest())

		for !lexer.EOF() {
			if lexer.SkipString("$$") {
				sb.WriteString("$$")
				continue
			}

			other := lexer.NextBytesFunc(func(b byte) bool { return b != '$' })
			if other == "" {
				break
			}

			sb.WriteString(other)
		}

		return sb.String()
	}

	var tokens []*MkToken
	for !lexer.EOF() {
		mark := lexer.Mark()

		if varUse := parser.VarUse(); varUse != nil {
			tokens = append(tokens, &MkToken{lexer.Since(mark), varUse})

		} else if other := parseOther(); other != "" {
			tokens = append(tokens, &MkToken{other, nil})

		} else {
			assert(lexer.SkipByte('$'))
			tokens = append(tokens, &MkToken{"$", nil})
		}
	}

	hasComment := comment != ""
	if hasComment {
		comment = comment[1:]
	}

	mainTrimmed := rtrimHspace(mainWithSpaces)
	spaceBeforeComment := mainWithSpaces[len(mainTrimmed):]
	if spaceBeforeComment != "" {
		tokenText := &tokens[len(tokens)-1].Text
		*tokenText = rtrimHspace(*tokenText)
		if *tokenText == "" {
			if len(tokens) == 1 {
				tokens = nil
			} else {
				tokens = tokens[:len(tokens)-1]
			}
		}
	}

	return mkLineSplitResult{mainTrimmed, tokens, spaceBeforeComment, hasComment, "", comment}
}

// unescapeComment takes a Makefile line, as written in a file, and splits
// it into the main part and the comment.
//
// The comment starts at the first #. Except if it is preceded by an odd number
// of backslashes. Or by an opening bracket.
//
// The main text is returned including leading and trailing whitespace.
// Any escaped # is unescaped, that is, \# becomes #.
//
// The comment is returned including the leading "#", if any.
// If the line has no comment, it is an empty string.
func (MkLineParser) unescapeComment(text string) (main, comment string) {
	var sb strings.Builder

	lexer := textproc.NewLexer(text)

again:
	if plain := lexer.NextBytesSet(unescapeMkCommentSafeChars); plain != "" {
		sb.WriteString(plain)
		goto again
	}

	switch {
	case lexer.SkipString("\\#"):
		sb.WriteByte('#')

	case lexer.PeekByte() == '\\' && len(lexer.Rest()) >= 2:
		sb.WriteString(lexer.Rest()[:2])
		lexer.Skip(2)

	case lexer.SkipByte('\\'):
		sb.WriteByte('\\')

	case lexer.SkipString("[#"):
		// See devel/bmake/files/parse.c:/as in modifier/
		sb.WriteString("[#")

	case lexer.SkipByte('['):
		sb.WriteByte('[')

	default:
		main = sb.String()
		if lexer.PeekByte() == '#' {
			return main, lexer.Rest()
		}

		assert(lexer.EOF())
		return main, ""
	}

	goto again
}

func (MkLineParser) getRawValueAlign(raw, parsed string) string {
	r := textproc.NewLexer(raw)
	p := textproc.NewLexer(parsed)
	mark := r.Mark()

	for !p.EOF() {
		pch := p.PeekByte()
		rch := r.PeekByte()

		switch {
		case pch == rch:
			p.Skip(1)
			r.Skip(1)

		case pch == ' ', pch == '\t':
			p.SkipHspace()
			r.SkipHspace()

		default:
			assert(pch == '#')
			assert(r.SkipString("\\#"))
			p.Skip(1)
		}
	}

	return r.Since(mark)
}

type mkLineSplitResult struct {
	// The text of the line, without the comment at the end of the line,
	// and with # signs unescaped.
	main               string
	tokens             []*MkToken
	spaceBeforeComment string
	hasComment         bool
	rationale          string // filled in later, by MkLines.collectRationale
	comment            string
}
