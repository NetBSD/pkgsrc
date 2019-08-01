package pkglint

import (
	"netbsd.org/pkglint/textproc"
	"strings"
)

// VaralignBlock checks that all variable assignments from a paragraph
// use the same indentation depth for their values.
// It also checks that the indentation uses tabs instead of spaces.
//
// In general, all values should be aligned using tabs.
// As an exception, a single very long line (called an outlier) may be
// aligned with a single space.
// A typical example is a SITES.very-long-file-name.tar.gz variable
// between HOMEPAGE and DISTFILES.
//
// Continuation lines are also aligned to the single-line assignments.
// There are two types of continuation lines. The first type is an
// empty multiline:
//
//  MULTI_EMPTY_LINE= \
//          The value starts in the second line.
//
// The backslash in the first line is usually aligned to the other variables
// in the same paragraph. If the variable name is so long that it is an
// outlier, it may be indented with a single space, just like a single-line
// variable. In multi-line shell commands or AWK programs, the backslash is
// often indented to column 73, as are the backslashes from the follow-up
// lines, to act as a visual guideline.
//
// Since this type is often used for URLs or other long values, the first
// follow-up line may be indented with a single tab, even if the other
// variables in the paragraph are aligned further to the right. If the
// indentation is not a single tab, it must match the indentation of the
// other lines in the paragraph.
//
//  INITIAL_LINE=   The value starts in the first line \
//                  and continues in the second line.
//
// In lists or plain text, like in the INITIAL_LINE above, all values are
// aligned in the same column. Some variables also contain code, and in
// these variables, the line containing the first word defines how deep
// the follow-up lines must be indented at least.
//
//  SHELL_CMD=                                                              \
//          if ${PKG_ADMIN} pmatch ${PKGNAME} ${dependency}; then           \
//                  ${ECHO} yes;                                            \
//          else                                                            \
//                  ${ECHO} no;                                             \
//          fi
//
// In the continuation lines, each follow-up line is indented with at least
// one tab, to avoid confusing them with regular single-lines. This is
// especially true for CONFIGURE_ENV, since the environment variables are
// typically uppercase as well.
//
// TODO: An initial line has this form:
//  comment? varname+op space? value? space? comment? space? backslash?
//
// TODO: A follow-up line has the form:
//  comment? space? value? space? comment? space? backslash?
//
// TODO: The alignment checks are performed on the raw lines instead of
//  the logical lines, since this check is about the visual appearance
//  as opposed to the meaning of the variable assignment.
//
// FIXME: Implement each requirement from the above documentation.
type VaralignBlock struct {
	infos []*varalignLine
	skip  bool

	// When the indentation of the initial line of a multiline is
	// changed, all its follow-up lines are shifted by the same
	// amount and in the same direction. Typical examples are
	// SUBST_SED, shell programs and AWK programs like in
	// GENERATE_PLIST.
	indentDiffSet bool
	// The amount by which the follow-up lines are shifted.
	// Positive values mean shifting to the right, negative values
	// mean shifting to the left.
	indentDiff int
}

type varalignLine struct {
	mkline   *MkLine
	rawIndex int

	// Is true for multilines that don't have a value in their first
	// physical line.
	//
	// The follow-up lines of these lines may be indented with as few
	// as a single tab. Example:
	//  VAR= \
	//          value1 \
	//          value2
	// In all other lines, the indentation must be at least the indentation
	// of the first value found.
	multiEmpty bool

	parts varalignSplitResult
}

type varalignSplitResult struct {
	leadingComment    string // either the # or some rarely used U+0020 spaces
	varnameOp         string // empty iff it is a follow-up line
	spaceBeforeValue  string // for follow-up lines, this is the indentation
	value             string
	spaceAfterValue   string
	trailingComment   string
	spaceAfterComment string
	continuation      string
}

func (va *VaralignBlock) Process(mkline *MkLine) {
	switch {
	case !G.Opts.WarnSpace:

	case mkline.IsEmpty():
		va.Finish()

	case mkline.IsVarassignMaybeCommented():
		va.processVarassign(mkline)

	case mkline.IsComment(), mkline.IsDirective():

	default:
		trace.Stepf("Skipping varalign block because of line %s", &mkline.Location)
		va.skip = true
	}
}

func (va *VaralignBlock) processVarassign(mkline *MkLine) {
	switch {
	case mkline.Op() == opAssignEval && matches(mkline.Varname(), `^[a-z]`):
		// Arguments to procedures do not take part in block alignment.
		//
		// Example:
		// pkgpath := ${PKGPATH}
		// .include "../../mk/pkg-build-options.mk"
		return

	case mkline.Value() == "" && mkline.VarassignComment() == "":
		// Multiple-inclusion guards usually appear in a block of
		// their own and therefore do not need alignment.
		//
		// Example:
		// .if !defined(INCLUSION_GUARD_MK)
		// INCLUSION_GUARD_MK:=
		// # ...
		// .endif
		return
	}

	follow := false
	for i, raw := range mkline.raw {
		info := varalignLine{mkline, i, follow, va.split(raw.textnl, i == 0)}

		if i == 0 && info.parts.value == "" && info.continuation() {
			follow = true
			info.multiEmpty = true
		}

		va.infos = append(va.infos, &info)
	}
}

func (*VaralignBlock) split(textnl string, initial bool) varalignSplitResult {

	// See MkLineParser.unescapeComment for very similar code.

	p := NewMkParser(nil, textnl)
	lexer := p.lexer

	parseLeadingComment := func() string {
		mark := lexer.Mark()

		if !lexer.SkipByte('#') && initial && lexer.SkipByte(' ') {
			lexer.SkipHspace()
		}

		return lexer.Since(mark)
	}

	parseVarnameOp := func() string {
		if !initial {
			return ""
		}

		mark := lexer.Mark()
		_ = p.Varname()
		lexer.SkipHspace()
		ok, _ := p.Op()
		assert(ok)
		return lexer.Since(mark)
	}

	parseValue := func() (string, string) {
		mark := lexer.Mark()

		for !lexer.EOF() &&
			lexer.PeekByte() != '#' &&
			lexer.PeekByte() != '\n' &&
			!hasPrefix(lexer.Rest(), "\\\n") {

			if lexer.NextBytesSet(unescapeMkCommentSafeChars) != "" ||
				lexer.SkipString("[#") ||
				lexer.SkipByte('[') {
				continue
			}

			if len(lexer.Rest()) < 2 {
				break
			}

			assert(lexer.SkipByte('\\'))
			lexer.Skip(1)
		}

		valueSpace := lexer.Since(mark)
		value := rtrimHspace(valueSpace)
		space := valueSpace[len(value):]
		return value, space
	}

	parseComment := func() (string, string, string) {
		rest := lexer.Rest()

		newline := len(rest)
		for newline > 0 && rest[newline-1] == '\n' {
			newline--
		}

		backslash := newline
		for backslash > 0 && rest[backslash-1] == '\\' {
			backslash--
		}

		if (newline-backslash)%2 == 1 {
			continuation := rest[backslash:]
			commentSpace := rest[:backslash]
			comment := rtrimHspace(commentSpace)
			space := commentSpace[len(comment):]
			return comment, space, continuation
		}

		return rest[:newline], "", rest[newline:]
	}

	leadingComment := parseLeadingComment()
	varnameOp := parseVarnameOp()
	spaceBeforeValue := lexer.NextHspace()
	value, spaceAfterValue := parseValue()
	trailingComment, spaceAfterComment, continuation := parseComment()

	return varalignSplitResult{
		leadingComment,
		varnameOp,
		spaceBeforeValue,
		value,
		spaceAfterValue,
		trailingComment,
		spaceAfterComment,
		continuation,
	}
}

func (va *VaralignBlock) Finish() {
	infos := va.infos
	skip := va.skip
	*va = VaralignBlock{} // overwrites infos and skip

	if len(infos) == 0 || skip {
		return
	}

	if trace.Tracing {
		defer trace.Call(infos[0].mkline.Line)()
	}

	newWidth := va.optimalWidth(infos)

	for _, info := range infos {
		if info.rawIndex == 0 {
			va.indentDiffSet = false
			va.indentDiff = 0
		}

		if newWidth > 0 || info.rawIndex > 0 {
			va.realign(info, newWidth)
		}
	}
}

// optimalWidth computes the desired screen width for the variable assignment
// lines. If the paragraph is already indented consistently, it is kept as-is.
//
// There may be a single line sticking out from the others (called outlier).
// This is to prevent a single SITES.* variable from forcing the rest of the
// paragraph to be indented too far to the right.
func (*VaralignBlock) optimalWidth(infos []*varalignLine) int {
	longest := 0 // The longest seen varnameOpWidth
	var longestLine *MkLine
	secondLongest := 0 // The second-longest seen varnameOpWidth

	for _, info := range infos {
		if info.multiEmpty || info.rawIndex > 0 {
			continue
		}

		width := info.varnameOpWidth()
		if width >= longest {
			secondLongest = longest
			longest = width
			longestLine = info.mkline
		} else if width > secondLongest {
			secondLongest = width
		}
	}

	haveOutlier := secondLongest != 0 &&
		longest/8 >= secondLongest/8+2 &&
		!longestLine.IsMultiline()

	// Minimum required width of varnameOp, without the trailing whitespace.
	minVarnameOpWidth := condInt(haveOutlier, secondLongest, longest)
	outlier := condInt(haveOutlier, longest, 0)

	// Widths of the current indentation (including whitespace)
	minTotalWidth := 0
	maxTotalWidth := 0
	for _, info := range infos {
		if info.multiEmpty || info.rawIndex > 0 || (outlier > 0 && info.varnameOpWidth() == outlier) {
			continue
		}

		width := info.varnameOpSpaceWidth()
		if minTotalWidth == 0 || width < minTotalWidth {
			minTotalWidth = width
		}
		maxTotalWidth = imax(maxTotalWidth, width)
	}

	if trace.Tracing {
		trace.Stepf("Indentation including whitespace is between %d and %d.",
			minTotalWidth, maxTotalWidth)
		trace.Stepf("Minimum required indentation is %d + 1.", minVarnameOpWidth)
		if outlier != 0 {
			trace.Stepf("The outlier is at indentation %d.", outlier)
		}
	}

	if minTotalWidth > minVarnameOpWidth && minTotalWidth == maxTotalWidth && minTotalWidth%8 == 0 {
		// The whole paragraph is already indented to the same width.
		return minTotalWidth
	}

	if minVarnameOpWidth == 0 {
		// Only continuation lines in this paragraph.
		return 0
	}

	return (minVarnameOpWidth & -8) + 8
}

func (va *VaralignBlock) realign(info *varalignLine, newWidth int) {
	if info.multiEmpty {
		if info.rawIndex == 0 {
			va.realignMultiEmptyInitial(info, newWidth)
		} else {
			va.realignMultiEmptyFollow(info, newWidth)
		}
	} else if info.rawIndex == 0 && info.continuation() {
		va.realignMultiInitial(info, newWidth)
	} else if info.rawIndex > 0 {
		va.realignMultiFollow(info, newWidth)
	} else {
		va.realignSingle(info, newWidth)
	}
}

func (va *VaralignBlock) realignMultiEmptyInitial(info *varalignLine, newWidth int) {
	leadingComment := info.parts.leadingComment
	varnameOp := info.parts.varnameOp
	oldSpace := info.parts.spaceBeforeValue

	// Indent the outlier and any other lines that stick out
	// with a space instead of a tab to keep the line short.
	newSpace := " "
	if info.varnameOpSpaceWidth() <= newWidth {
		newSpace = alignmentAfter(leadingComment+varnameOp, newWidth)
	}

	if newSpace == oldSpace {
		return
	}

	if newSpace == " " && oldSpace != "" && oldSpace == strings.Repeat("\t", len(oldSpace)) {
		return
	}

	hasSpace := strings.IndexByte(oldSpace, ' ') != -1
	oldColumn := tabWidth(leadingComment + varnameOp + oldSpace)
	column := tabWidth(leadingComment + varnameOp + newSpace)

	assert(column >= oldColumn || column > info.varnameOpWidth())

	// TODO: explicitly mention "single space", "tabs to the newWidth", "tabs to column 72"

	fix := info.mkline.Autofix()
	if hasSpace && column != oldColumn {
		fix.Notef("This variable value should be aligned with tabs, not spaces, to column %d.", column+1)
	} else if column != oldColumn {
		fix.Notef("This variable value should be aligned to column %d.", column+1)
	} else {
		fix.Notef("Variable values should be aligned with tabs, not spaces.")
	}
	fix.ReplaceAt(info.rawIndex, info.spaceBeforeValueIndex(), oldSpace, newSpace)
	fix.Apply()
}

func (va *VaralignBlock) realignMultiEmptyFollow(info *varalignLine, newWidth int) {
	oldSpace := info.parts.spaceBeforeValue
	oldWidth := tabWidth(oldSpace)

	if !va.indentDiffSet {
		va.indentDiffSet = true
		va.indentDiff = condInt(newWidth != 0, newWidth-oldWidth, 0)
		if va.indentDiff > 0 && !info.commentedOut() {
			va.indentDiff = 0
		}
	}

	newWidth = oldWidth + va.indentDiff
	if newWidth < 8 {
		newWidth = oldWidth & -8
		if newWidth < 8 {
			newWidth = 8
		}
	}

	newSpace := indent(newWidth)
	if newSpace == oldSpace {
		return
	}

	// Below a continuation marker, there may be a completely empty line.
	// This is confusing to the human readers, but technically allowed.
	if info.parts.value == "" && info.parts.trailingComment == "" && !info.continuation() {
		return
	}

	fix := info.mkline.Autofix()
	fix.Notef("This continuation line should be indented with %q.", newSpace)
	fix.ReplaceAt(info.rawIndex, info.spaceBeforeValueIndex(), oldSpace, newSpace)
	fix.Apply()
}

func (va *VaralignBlock) realignMultiInitial(info *varalignLine, newWidth int) {
	leadingComment := info.parts.leadingComment
	varnameOp := info.parts.varnameOp
	oldSpace := info.parts.spaceBeforeValue

	va.indentDiffSet = true
	oldWidth := info.varnameOpSpaceWidth()
	va.indentDiff = newWidth - oldWidth

	newSpace := alignmentAfter(leadingComment+varnameOp, newWidth)
	if newSpace == oldSpace {
		return
	}

	hasSpace := strings.IndexByte(oldSpace, ' ') != -1
	width := tabWidth(leadingComment + varnameOp + newSpace)

	fix := info.mkline.Autofix()
	if hasSpace && width != oldWidth {
		fix.Notef("This variable value should be aligned with tabs, not spaces, to column %d.", width+1)
	} else if width != oldWidth {
		fix.Notef("This variable value should be aligned to column %d.", width+1)
	} else {
		fix.Notef("Variable values should be aligned with tabs, not spaces.")
	}
	fix.ReplaceAt(info.rawIndex, info.spaceBeforeValueIndex(), oldSpace, newSpace)
	fix.Apply()
}

func (va *VaralignBlock) realignMultiFollow(info *varalignLine, newWidth int) {
	assert(va.indentDiffSet)

	oldSpace := info.parts.spaceBeforeValue
	newSpace := indent(tabWidth(oldSpace) + va.indentDiff)
	if tabWidth(newSpace) < newWidth {
		newSpace = indent(newWidth)
	}
	if newSpace == oldSpace || oldSpace == "\t" {
		return
	}

	fix := info.mkline.Autofix()
	fix.Notef("This continuation line should be indented with %q.", indent(newWidth))
	fix.ReplaceAt(info.rawIndex, info.spaceBeforeValueIndex(), oldSpace, newSpace)
	fix.Apply()
}

func (va *VaralignBlock) realignSingle(info *varalignLine, newWidth int) {
	assert(!va.indentDiffSet)

	leadingComment := info.parts.leadingComment
	varnameOp := info.parts.varnameOp
	oldSpace := info.parts.spaceBeforeValue

	newSpace := ""
	for tabWidth(leadingComment+varnameOp+newSpace) < newWidth {
		newSpace += "\t"
	}

	// Indent the outlier with a space instead of a tab to keep the line short.
	if newSpace == "" && info.canonicalInitial(newWidth) {
		return
	}
	if newSpace == "" {
		newSpace = " "
	}

	if newSpace == oldSpace {
		return
	}

	hasSpace := strings.IndexByte(oldSpace, ' ') != -1
	oldColumn := tabWidth(leadingComment + varnameOp + oldSpace)
	column := tabWidth(leadingComment + varnameOp + newSpace)

	if info.parts.value == "" && info.parts.trailingComment == "" && !info.continuation() {
		return
	}

	fix := info.mkline.Autofix()
	if hasSpace && column != oldColumn {
		fix.Notef("This variable value should be aligned with tabs, not spaces, to column %d.", column+1)
		va.explainWrongColumn(fix)
	} else if column != oldColumn {
		fix.Notef("This variable value should be aligned to column %d.", column+1)
		va.explainWrongColumn(fix)
	} else {
		fix.Notef("Variable values should be aligned with tabs, not spaces.")
	}
	fix.ReplaceAt(info.rawIndex, info.spaceBeforeValueIndex(), oldSpace, newSpace)
	fix.Apply()
}

func (va *VaralignBlock) explainWrongColumn(fix *Autofix) {
	fix.Explain(
		"Normally, all variable values in a block should start at the same column.",
		"This provides orientation, especially for sequences",
		"of variables that often appear in the same order.",
		"For these it suffices to look at the variable values only.",
		"",
		"There are some exceptions to this rule:",
		"",
		"Definitions for long variable names may be indented with a single space instead of tabs,",
		"but only if they appear in a block that is otherwise indented with tabs.",
		"",
		"Variable definitions that span multiple lines are not checked for alignment at all.",
		"",
		"When the block contains something else than variable definitions",
		"and directives like .if or .for, it is not checked at all.")
}

func (l *varalignLine) varnameOpWidth() int {
	return tabWidth(l.parts.leadingComment + l.parts.varnameOp)
}

func (l *varalignLine) varnameOpSpaceWidth() int {
	return tabWidth(l.parts.leadingComment + l.parts.varnameOp + l.parts.spaceBeforeValue)
}

// spaceBeforeValueIndex returns the string index at which the space before the value starts.
// It's the same as the end of the assignment operator. Example:
//  #VAR=   value
// The index is 5.
func (l *varalignLine) spaceBeforeValueIndex() int {
	return len(l.parts.leadingComment) + len(l.parts.varnameOp)
}

// continuation returns whether this line ends with a backslash.
func (l *varalignLine) continuation() bool {
	return hasPrefix(l.parts.continuation, "\\")
}

func (l *varalignLine) commentedOut() bool {
	return hasPrefix(l.parts.leadingComment, "#")
}

// canonicalInitial returns whether the space between the assignment
// operator and the value has its canonical form, which is either
// at least one tab, or a single space, but only for lines that stick out.
func (l *varalignLine) canonicalInitial(width int) bool {
	space := l.parts.spaceBeforeValue
	if space == "" {
		return false
	}

	if space == " " && l.varnameOpSpaceWidth() > width {
		return true
	}

	return strings.TrimLeft(space, "\t") == ""
}

// canonicalFollow returns whether the space before the value has its
// canonical form, which is at least one tab, followed by up to 7 spaces.
func (l *varalignLine) canonicalFollow() bool {
	lexer := textproc.NewLexer(l.parts.spaceBeforeValue)

	tabs := 0
	for lexer.SkipByte('\t') {
		tabs++
	}

	spaces := 0
	for lexer.SkipByte(' ') {
		spaces++
	}

	return tabs >= 1 && spaces <= 7
}
