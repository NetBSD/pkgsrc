package pkglint

import (
	"netbsd.org/pkglint/textproc"
	"sort"
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
// There are two types of continuation lines. The first type has just
// the continuation backslash in the first line:
//
//  MULTI_LINE= \
//          The value starts in the second line.
//
// The backslash in the first line is usually aligned to the other variables
// in the same paragraph. If the variable name is longer than the indentation
// of the paragraph, it may be indented with a single space.
// In multi-line shell commands or AWK programs, the backslash is
// often indented to column 73, as are the backslashes from the follow-up
// lines, to act as a visual guideline.
//
// The indentation of the first value of the variable determines the minimum
// indentation for the remaining continuation lines. To allow long variable
// values to be indented as little as possible, the follow-up lines only need
// to be indented by a single tab, even if the other
// variables in the paragraph are aligned further to the right. If the
// indentation is not a single tab, it must match the indentation of the
// other lines in the paragraph.
//
//  MULTI_LINE=     The value starts in the first line \
//                  and continues in the second line.
//
// In lists or plain text, like in the example above, all values are
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
// For the purpose of aligning the variable assignments, each raw line is
// split into several parts, as described by the varalignParts type.
//
// The alignment checks are performed on the raw lines instead of
// the logical lines, since this check is about the visual appearance
// as opposed to the meaning of the variable assignment.
//
// FIXME: Implement each requirement from the above documentation.
type VaralignBlock struct {
	infos []*varalignLine
	skip  bool
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

	// Whether the line is so long that it may use a single tab as indentation.
	long bool

	varalignParts
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

	case mkline.Value() == "" && !mkline.HasComment():
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
		parts := NewVaralignSplitter().split(strings.TrimSuffix(raw.textnl, "\n"), i == 0)
		info := varalignLine{mkline, i, follow, false, parts}

		if i == 0 && info.isEmptyContinuation() {
			follow = true
			info.multiEmpty = true
		}

		va.infos = append(va.infos, &info)
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
	va.adjustLong(newWidth, infos)
	rightMargin := 0

	// When the indentation of the initial line of a multiline is
	// changed, all its follow-up lines are shifted by the same
	// amount and in the same direction. Typical examples are
	// SUBST_SED, shell programs and AWK programs like in
	// GENERATE_PLIST.
	indentDiffSet := false
	// The amount by which the follow-up lines are shifted.
	// Positive values mean shifting to the right, negative values
	// mean shifting to the left.
	indentDiff := 0

	for i, info := range infos {
		if info.rawIndex == 0 {
			indentDiffSet = false
			indentDiff = 0
			restIndex := i + condInt(info.value != "", 0, 1)
			rightMargin = va.rightMargin(infos[restIndex:])
		}

		va.checkRightMargin(info, newWidth, rightMargin)

		if newWidth > 0 || info.rawIndex > 0 {
			va.realign(info, newWidth, &indentDiffSet, &indentDiff)
		}
	}
}

// rightMargin calculates the column in which the continuation backslashes
// should be placed.
func (*VaralignBlock) rightMargin(infos []*varalignLine) int {
	var columns []int
	for _, info := range infos {
		if info.isContinuation() {
			space := info.spaceBeforeContinuation()
			if space != "" && space != " " {
				columns = append(columns, info.continuationColumn())
			}
		}
	}

	sort.Ints(columns)

	for i := len(columns) - 2; i >= 0; i-- {
		if columns[i] == columns[i+1] {
			return columns[i]
		}
	}

	if len(columns) <= 1 {
		return 0
	}

	var min int
	for _, info := range infos {
		if info.isContinuation() {
			mainWidth := tabWidth(info.beforeContinuation())
			if mainWidth > min {
				min = mainWidth
			}
		}
	}
	return (min & -8) + 8
}

// optimalWidth computes the desired screen width for the variable assignment
// lines. If the paragraph is already indented consistently, it is kept as-is.
//
// There may be a single line sticking out from the others (called outlier).
// This is to prevent a single SITES.* variable from forcing the rest of the
// paragraph to be indented too far to the right.
func (*VaralignBlock) optimalWidth(infos []*varalignLine) int {

	var widths mklineInts
	for _, info := range infos {
		if !info.multiEmpty && info.rawIndex == 0 {
			widths.append(info.mkline, info.varnameOpWidth())
		}
	}
	widths.sortDesc()

	longest := widths.opt(0)
	longestLine := widths.optLine(0)
	secondLongest := widths.opt(1)

	haveOutlier := secondLongest != 0 &&
		secondLongest/8+1 < longest/8 &&
		!longestLine.IsMultiline() // TODO: may be too imprecise

	// Minimum required width of varnameOp, without the trailing whitespace.
	minVarnameOpWidth := condInt(haveOutlier, secondLongest, longest)
	outlier := condInt(haveOutlier, longest, 0)

	// Widths of the current indentation (including whitespace)
	var spaceWidths mklineInts
	for _, info := range infos {
		if info.multiEmpty || info.rawIndex > 0 || (outlier > 0 && info.varnameOpWidth() == outlier) {
			continue
		}
		spaceWidths.append(info.mkline, info.varnameOpSpaceWidth())
	}
	spaceWidths.sortDesc()

	minTotalWidth := spaceWidths.min()
	maxTotalWidth := spaceWidths.max()

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

func (va *VaralignBlock) adjustLong(newWidth int, infos []*varalignLine) {
	long := false
	for _, info := range infos {
		if info.rawIndex == 0 {
			long = false
		}
		if !info.multiEmpty && info.spaceBeforeValue == "\t" && info.varnameOpSpaceWidth() != newWidth && info.widthAlignedAt(newWidth) > 72 {
			long = true
		}
		info.long = long
	}
}

func (va *VaralignBlock) checkRightMargin(info *varalignLine, newWidth int, rightMargin int) {
	if !info.isContinuation() {
		return
	}

	oldSpace := info.spaceBeforeContinuation()
	if oldSpace == " " || oldSpace == "\t" {
		return
	}

	column := info.continuationColumn()
	if column == 72 || column == rightMargin || column <= newWidth {
		return
	}

	newSpace := " "
	fix := info.mkline.Autofix()
	if oldSpace == "" || rightMargin == 0 || tabWidth(info.beforeContinuation()) >= rightMargin {
		fix.Notef("The continuation backslash should be preceded by a single space or tab.")
	} else {
		newSpace = alignmentAfter(info.beforeContinuation(), rightMargin)
		fix.Notef(
			"The continuation backslash should be preceded by a single space or tab, "+
				"or be in column %d, not %d.",
			rightMargin+1, column+1)
	}
	fix.ReplaceAt(info.rawIndex, info.continuationIndex()-len(oldSpace), oldSpace, newSpace)
	fix.Apply()
}

func (va *VaralignBlock) realign(info *varalignLine, newWidth int, indentDiffSet *bool, indentDiff *int) {
	if info.multiEmpty {
		if info.rawIndex == 0 {
			va.realignMultiEmptyInitial(info, newWidth)
		} else {
			va.realignMultiEmptyFollow(info, newWidth, indentDiffSet, indentDiff)
		}
	} else if info.rawIndex == 0 && info.isContinuation() {
		va.realignMultiInitial(info, newWidth, indentDiffSet, indentDiff)
	} else if info.rawIndex > 0 {
		assert(*indentDiffSet)
		va.realignMultiFollow(info, newWidth, *indentDiff)
	} else {
		assert(!*indentDiffSet)
		va.realignSingle(info, newWidth)
	}
}

func (*VaralignBlock) realignMultiEmptyInitial(info *varalignLine, newWidth int) {
	leadingComment := info.leadingComment
	varnameOp := info.varnameOp
	oldSpace := info.spaceBeforeValue

	// Indent the outlier and any other lines that stick out
	// with a space instead of a tab to keep the line short.
	newSpace := " "
	if info.varnameOpSpaceWidth() <= newWidth {
		newSpace = alignmentAfter(leadingComment+varnameOp, newWidth)
	}

	if newSpace == oldSpace {
		return
	}

	if newSpace == " " {
		return // This case is handled by checkRightMargin.
	}

	hasSpace := strings.IndexByte(oldSpace, ' ') != -1
	oldColumn := info.varnameOpSpaceWidth()
	column := tabWidth(leadingComment + varnameOp + newSpace)

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

func (va *VaralignBlock) realignMultiEmptyFollow(info *varalignLine, newWidth int, indentDiffSet *bool, indentDiff *int) {
	oldSpace := info.spaceBeforeValue
	oldWidth := tabWidth(oldSpace)

	if !*indentDiffSet {
		*indentDiffSet = true
		*indentDiff = condInt(newWidth != 0, newWidth-oldWidth, 0)
		if *indentDiff > 0 && !info.commentedOut() {
			*indentDiff = 0
		}
	}

	newSpace := indent(imax(oldWidth+*indentDiff, 8))
	if newSpace == oldSpace {
		return
	}

	// Below a continuation marker, there may be a completely empty line.
	// This is confusing to the human readers, but technically allowed.
	if info.varalignParts.isEmpty() {
		return
	}

	fix := info.mkline.Autofix()
	fix.Notef("This continuation line should be indented with %q.", newSpace)
	fix.ReplaceAt(info.rawIndex, info.spaceBeforeValueIndex(), oldSpace, newSpace)
	fix.Apply()
}

func (va *VaralignBlock) realignMultiInitial(info *varalignLine, newWidth int, indentDiffSet *bool, indentDiff *int) {
	leadingComment := info.leadingComment
	varnameOp := info.varnameOp
	oldSpace := info.spaceBeforeValue

	*indentDiffSet = true
	oldWidth := info.varnameOpSpaceWidth()
	*indentDiff = newWidth - oldWidth

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

func (va *VaralignBlock) realignMultiFollow(info *varalignLine, newWidth int, indentDiff int) {
	oldSpace := info.spaceBeforeValue
	newSpace := indent(tabWidth(oldSpace) + indentDiff)
	if tabWidth(newSpace) < newWidth {
		newSpace = indent(newWidth)
	}
	if newSpace == oldSpace || info.long {
		return
	}

	fix := info.mkline.Autofix()
	fix.Notef("This continuation line should be indented with %q.", indent(newWidth))
	fix.ReplaceAt(info.rawIndex, info.spaceBeforeValueIndex(), oldSpace, newSpace)
	fix.Apply()
}

func (va *VaralignBlock) realignSingle(info *varalignLine, newWidth int) {
	leadingComment := info.leadingComment
	varnameOp := info.varnameOp
	oldSpace := info.spaceBeforeValue

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

	fix := info.mkline.Autofix()
	if newSpace == " " {
		fix.Notef("This outlier variable value should be aligned with a single space.")
		va.explainWrongColumn(fix)
	} else if hasSpace && column != oldColumn {
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

// VaralignSplitter parses the text of a raw line into those parts that
// are relevant for aligning the variable values, and the backslash
// continuation markers.
//
// See MkLineParser.unescapeComment for very similar code.
type VaralignSplitter struct {
}

func NewVaralignSplitter() VaralignSplitter {
	return VaralignSplitter{}
}

func (s VaralignSplitter) split(rawText string, initial bool) varalignParts {
	assert(!hasSuffix(rawText, "\n"))
	parser := NewMkParser(nil, rawText)
	lexer := parser.lexer

	leadingComment := s.parseLeadingComment(lexer, initial)
	varnameOp, spaceBeforeValue := s.parseVarnameOp(parser, initial)
	value, spaceAfterValue := s.parseValue(lexer)
	trailingComment, spaceAfterComment, continuation := s.parseComment(lexer.Rest())

	return varalignParts{
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

func (VaralignSplitter) parseLeadingComment(lexer *textproc.Lexer, initial bool) string {
	if hasPrefix(lexer.Rest(), "# ") {
		return ""
	}

	comment := lexer.NextString("#")
	if comment != "" {
		return comment
	}

	mark := lexer.Mark()
	if initial && lexer.SkipByte(' ') {
		lexer.SkipHspace()
	}
	return lexer.Since(mark)
}

func (VaralignSplitter) parseVarnameOp(parser *MkParser, initial bool) (string, string) {
	lexer := parser.lexer
	if !initial {
		return "", lexer.NextHspace()
	}

	mark := lexer.Mark()
	_ = parser.Varname()
	lexer.SkipHspace()
	ok, _ := parser.Op()
	assert(ok)
	return lexer.Since(mark), lexer.NextHspace()
}

func (VaralignSplitter) parseValue(lexer *textproc.Lexer) (string, string) {
	mark := lexer.Mark()

	for !lexer.EOF() && lexer.PeekByte() != '#' && lexer.Rest() != "\\" {

		if lexer.NextBytesSet(unescapeMkCommentSafeChars) != "" ||
			lexer.SkipString("[#") ||
			lexer.SkipByte('[') {
			continue
		}

		assert(lexer.SkipByte('\\'))
		lexer.Skip(1)
	}

	valueSpace := lexer.Since(mark)
	value := rtrimHspace(valueSpace)
	space := valueSpace[len(value):]
	return value, space
}

func (VaralignSplitter) parseComment(rest string) (string, string, string) {
	end := len(rest)

	backslash := end
	for backslash > 0 && rest[backslash-1] == '\\' {
		backslash--
	}

	if (end-backslash)&1 == 0 { // see https://github.com/golang/go/issues/34166
		return rest[:end], "", ""
	}

	continuation := rest[backslash:]
	commentSpace := rest[:backslash]
	comment := rtrimHspace(commentSpace)
	space := commentSpace[len(comment):]
	return comment, space, continuation
}

type varalignParts struct {
	leadingComment    string // either the # or some rarely used U+0020 spaces
	varnameOp         string // empty iff it is a follow-up line
	spaceBeforeValue  string // for follow-up lines, this is the indentation
	value             string
	spaceAfterValue   string // only set if there is a value
	trailingComment   string
	spaceAfterComment string // only set if there is a trailing comment
	continuation      string // either a single backslash or empty
}

// continuation returns whether this line ends with a backslash.
func (p *varalignParts) isContinuation() bool {
	return p.continuation != ""
}

func (p *varalignParts) isEmptyContinuation() bool {
	return p.value == "" && p.trailingComment == "" && p.isContinuation()
}

func (p *varalignParts) isEmpty() bool {
	return p.value == "" && p.trailingComment == "" && !p.isContinuation()
}

func (p *varalignParts) varnameOpWidth() int {
	return tabWidth(p.leadingComment + p.varnameOp)
}

func (p *varalignParts) varnameOpSpaceWidth() int {
	return tabWidth(p.leadingComment + p.varnameOp + p.spaceBeforeValue)
}

// spaceBeforeValueIndex returns the string index at which the space before the value starts.
// It's the same as the end of the assignment operator. Example:
//  #VAR=   value
// The index is 5.
func (p *varalignParts) spaceBeforeValueIndex() int {
	return len(p.leadingComment) + len(p.varnameOp)
}

func (p *varalignParts) spaceBeforeContinuation() string {
	if p.trailingComment == "" {
		if p.value == "" {
			return p.spaceBeforeValue
		}
		return p.spaceAfterValue
	}
	return p.spaceAfterComment
}

func (p *varalignParts) beforeContinuation() string {
	return rtrimHspace(p.leadingComment +
		p.varnameOp + p.spaceBeforeValue +
		p.value + p.spaceAfterValue +
		p.trailingComment + p.spaceAfterComment)
}

func (p *varalignParts) continuationColumn() int {
	return tabWidth(p.leadingComment +
		p.varnameOp + p.spaceBeforeValue +
		p.value + p.spaceAfterValue +
		p.trailingComment + p.spaceAfterComment)
}

func (p *varalignParts) continuationIndex() int {
	return len(p.leadingComment) +
		len(p.varnameOp) + len(p.spaceBeforeValue) +
		len(p.value) + len(p.spaceAfterValue) +
		len(p.trailingComment) + len(p.spaceAfterComment)
}

func (p *varalignParts) commentedOut() bool {
	return hasPrefix(p.leadingComment, "#")
}

// canonicalInitial returns whether the space between the assignment
// operator and the value has its canonical form, which is either
// at least one tab, or a single space, but only for lines that stick out.
func (p *varalignParts) canonicalInitial(width int) bool {
	space := p.spaceBeforeValue
	if space == "" {
		return false
	}

	if space == " " && p.varnameOpSpaceWidth() > width {
		return true
	}

	return strings.TrimLeft(space, "\t") == ""
}

// canonicalFollow returns whether the space before the value has its
// canonical form, which is at least one tab, followed by up to 7 spaces.
func (p *varalignParts) canonicalFollow() bool {
	lexer := textproc.NewLexer(p.spaceBeforeValue)

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

func (p *varalignParts) widthAlignedAt(valueAlign int) int {
	return tabWidthAppend(
		valueAlign,
		p.value+p.spaceAfterValue+p.trailingComment+p.spaceAfterComment+p.continuation)
}

type mklineInts struct {
	slice []struct {
		mkline *MkLine
		value  int
	}
}

func (mi mklineInts) sortDesc() {
	less := func(i, j int) bool { return mi.slice[j].value < mi.slice[i].value }
	sort.SliceStable(mi.slice, less)
}

func (mi mklineInts) opt(index int) int {
	if uint(index) < uint(len(mi.slice)) {
		return mi.slice[index].value
	}
	return 0
}

func (mi mklineInts) optLine(index int) *MkLine {
	if uint(index) < uint(len(mi.slice)) {
		return mi.slice[index].mkline
	}
	return nil
}

func (mi *mklineInts) append(mkline *MkLine, value int) {
	mi.slice = append(mi.slice, struct {
		mkline *MkLine
		value  int
	}{mkline, value})
}

func (mi mklineInts) min() int { return mi.opt(0) }

func (mi mklineInts) max() int { return mi.opt(len(mi.slice) - 1) }
