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
//
// Next try for the spec, from November 2019.
// Completely built from the existing examples, striving to be short and clear.
// Needs some more time to mature.
// After implementing it, it will be translated into English.
//
//  Ebenen: Datei > Absatz > MkZeile > Zeile
//
//  ### Datei
//
//  #.  Ein einzelner Absatz, der einen Tab weniger eingerückt ist als die übrigen,
//      darf auf die Einrückung der anderen Absätze angeglichen werden,
//      sofern der Absatz dadurch nicht zu breit wird.
//
//  ### Einzelner Absatz
//
//  #.  Jede Zeile besteht aus #, VarOp, Leerraum, Wert, Leerraum und Fortsetzung.
//
//  #.  Die Werte aller Zeilen sind mit Tabs an einer gemeinsamen vertikalen Linie
//      (Ausrichtung) ausgerichtet.
//
//  #.  Das Ausrichten mit mehr als 1 Tab ist erlaubt, wenn die Ausrichtung einheitlich ist.
//
//  #.  Wenn VarOp über die Ausrichtung hinausragt (Ausreißer),
//      darf zwischen VarOp und Wert statt der Ausrichtung 1 Leerzeichen sein.
//
//  #.  Die minimale Ausrichtung ergibt sich aus der maximalen Breite von # und VarOp
//      aller Zeilen, gerundet zum nächsten Tabstopp.
//      Dabei zählen auch Zeilen mit, die rechts von VarOp komplett leer sind.
//
//  #.  Die maximale Ausrichtung ergibt sich aus der maximalen Breite von Wert
//      und Kommentar, abgezogen vom maximalen rechten Rand (in Spalte 73).
//
//  #.  Beim Umformatieren darf die Zeilenbreite die 73 Zeichen nicht überschreiten,
//      damit am rechten Rand eindeutig ist, wo jede Zeile aufhört.
//      Zeilen, die bereits vorher breiter waren, dürfen ruhig noch breiter werden.
//
//  #.  Das Verhältnis zwischen Tab-Zeilen und hinausragenden Zeilen muss ausgewogen sein.
//      Nicht zu viele hinausragende Zeilen. (Noch zu definieren.)
//      Möglicher Ansatz: Anteil der Leerfläche?
//
//  ### Mehrzeilig
//
//  #.  Jede MkZeile hat für alle ihre Zeilen einen gemeinsamen rechten Rand.
//
//  #.  Die Fortsetzungen jeder MkZeile sind entweder alle durch je 1 Leerzeichen abgetrennt,
//      oder alle Fortsetzungen sind am rechten Rand.
//
//  #.  Um den gemeinsamen rechten Rand zu bestimmen, werden alle Zeilen ignoriert,
//      in denen die Fortsetzung durch 1 Leerzeichen abgetrennt ist.
//
//  #.  Einzelne Fortsetzungen dürfen über den rechten Rand hinausragen.
//      Die Fortsetzung wird dann durch 1 Leerzeichen abgetrennt.
//
//  ### Mehrzeilig, Erstzeile
//
//  #.  Die Fortsetzung der Erstzeile ist durch 1 Leerzeichen abgetrennt,
//      wenn sie rechts von der Ausrichtung steht,
//      andernfalls durch Tabs an der Ausrichtung.
//
//  #.  Eine leere Erstzeile mit 1 fortgesetzer Zeile ist nur zulässig,
//      wenn die kombinierte Zeile breiter als 73 Zeichen wäre.
//      Sonst werden die beiden Zeilen kombiniert.
//
//  ### Mehrzeilig, fortgesetzte Zeilen
//
//  #.  Nach einer leeren Erstzeile ist die erste fortgesetzte Zeile an der
//      Ausrichtung aller Zeilen eingerückt, wenn die Erstzeile über die
//      Ausrichtung ragt und der Platz aller Zeilen es zulässt, andernfalls
//      mit 1 Tab.
//
//  #.  Bei mehrzeiligen einrückbaren Werten (AWK, Shell, Listen aus Tupeln)
//      dürfen die weiteren Fortsetzungszeilen weiter eingerückt sein als die erste.
//      Ihre Einrückung besteht aus Tabs, gefolgt von 0 bis 7 Leerzeichen.
type VaralignBlock struct {
	mkinfos []*varalignMkLine
	skip    bool
}

func (va *VaralignBlock) Process(mkline *MkLine) {
	switch {
	case mkline.IsEmpty():
		va.Finish()

	case mkline.IsVarassignMaybeCommented():
		va.processVarassign(mkline)

	case mkline.IsComment(), mkline.IsDirective():

	default:
		trace.Stepf("Skipping varalign block because of line %s", mkline.String())
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

	var infos []*varalignLine
	for rawIndex := range mkline.raw {
		parts := NewVaralignSplitter().split(mkline.RawText(rawIndex), rawIndex == 0)
		info := varalignLine{mkline, rawIndex, false, parts}
		infos = append(infos, &info)
	}
	va.mkinfos = append(va.mkinfos, &varalignMkLine{infos})
}

func (va *VaralignBlock) Finish() {
	if len(va.mkinfos) == 0 || va.skip {
		*va = VaralignBlock{}
		return
	}

	if trace.Tracing {
		defer trace.Call()()
	}

	newWidth := va.optimalWidth()
	for _, mkinfo := range va.mkinfos {
		mkinfo.realign(newWidth)
	}

	*va = VaralignBlock{}
}

func (l *varalignMkLine) realign(newWidth int) {
	// When the indentation of the initial line of a multiline is
	// changed, all its follow-up lines are shifted by the same
	// amount and in the same direction. Typical examples are
	// SUBST_SED, shell programs and AWK programs like in
	// GENERATE_PLIST.
	//
	// The amount by which the follow-up lines are shifted.
	// Positive values mean shifting to the right, negative values
	// mean shifting to the left.
	var indentDiff optInt

	_, rightMargin := l.rightMargin()
	isMultiEmpty := l.isMultiEmpty()

	if info := l.infos[0]; !isMultiEmpty && info.isContinuation() {
		indentDiff.set(newWidth - info.valueColumn())
	}

	for _, info := range l.infos {

		if newWidth > 0 || info.rawIndex > 0 {
			info.realignDetails(newWidth, &indentDiff, isMultiEmpty)
		}

		if !info.fixedSpaceBeforeContinuation {
			info.alignContinuation(newWidth, rightMargin)
		}
	}
}

// optimalWidth computes the desired screen width for the variable assignment
// lines. If the paragraph is already indented consistently, it is kept as-is.
//
// There may be a single line sticking out from the others (called outlier).
// This is to prevent a single SITES.* variable from forcing the rest of the
// paragraph to be indented too far to the right.
func (va *VaralignBlock) optimalWidth() int {

	minVarnameOpWidth, outlier := va.varnameOpWidths()
	minTotalWidth, maxTotalWidth := va.spaceWidths(outlier)
	va.traceWidths(minTotalWidth, maxTotalWidth, minVarnameOpWidth, outlier)

	if minTotalWidth > minVarnameOpWidth && minTotalWidth == maxTotalWidth && minTotalWidth%8 == 0 {
		// The whole paragraph is already indented to the same width.
		return minTotalWidth
	}

	if minVarnameOpWidth == 0 {
		// Only continuation lines in this paragraph.
		return 0
	}

	return minVarnameOpWidth&-8 + 8
}

// varnameOpWidths calculates the required width of varnameOp,
// without the trailing whitespace, as well as the outlier.
func (va *VaralignBlock) varnameOpWidths() (int, int) {
	var widths bag
	for i, mkinfo := range va.mkinfos {
		if !mkinfo.isMultiEmpty() {
			info := mkinfo.infos[0]
			widths.add(i, info.spaceBeforeValueColumn())
		}
	}
	if widths.len() == 0 {
		return 0, 0
	}

	widths.sortDesc()

	longest := widths.opt(0)
	secondLongest := widths.opt(1)

	haveOutlier := secondLongest != 0 &&
		secondLongest/8+1 < longest/8 &&
		!va.mkinfos[widths.key(0).(int)].infos[0].isContinuation()

	if haveOutlier {
		return secondLongest, longest
	}
	return longest, 0
}

func (va *VaralignBlock) spaceWidths(outlier int) (min, max int) {
	// Widths of the current indentation (including whitespace)
	spaceWidths := newInterval()
	for _, mkinfo := range va.mkinfos {
		info := mkinfo.infos[0]
		if mkinfo.isMultiEmpty() || outlier > 0 && info.spaceBeforeValueColumn() == outlier {
			continue
		}
		spaceWidths.add(info.valueColumn())
	}

	return spaceWidths.min, spaceWidths.max
}

func (va *VaralignBlock) traceWidths(minTotalWidth int, maxTotalWidth int, minVarnameOpWidth int, outlier int) {
	if trace.Tracing {
		trace.Stepf("Indentation including whitespace is between %d and %d.",
			minTotalWidth, maxTotalWidth)
		trace.Stepf("Minimum required indentation is %d + 1.", minVarnameOpWidth)
		if outlier != 0 {
			trace.Stepf("The outlier is at indentation %d.", outlier)
		}
	}
}

func (info *varalignLine) realignDetails(newWidth int, indentDiff *optInt, isMultiEmpty bool) {
	switch {

	case info.rawIndex == 0 && info.isContinuation():
		info.alignValueInitial(newWidth)

	case isMultiEmpty:
		oldWidth := tabWidth(info.spaceBeforeValue)
		if !indentDiff.isSet {
			diff := 0
			if newWidth != 0 {
				diff = newWidth - oldWidth
				if diff > 0 && !info.isCommentedOut() {
					diff = 0
				}
			}
			indentDiff.set(diff)
		}

		width := imax(oldWidth+indentDiff.get(), 8)
		info.alignValueMultiFollow(width)

	case info.rawIndex > 0:
		width := imax(newWidth, info.valueColumn()+indentDiff.get())
		info.alignValueMultiFollow(width)

	default:
		info.alignValueSingle(newWidth)
	}
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
	value, spaceAfterValue, continuation := s.parseValue(lexer)

	return varalignParts{
		leadingComment,
		varnameOp,
		spaceBeforeValue,
		value,
		spaceAfterValue,
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
	_ = parser.mklex.Varname()
	lexer.SkipHspace()
	ok, _ := parser.Op()
	assert(ok)
	return lexer.Since(mark), lexer.NextHspace()
}

func (VaralignSplitter) parseValue(lexer *textproc.Lexer) (string, string, string) {
	rest := lexer.Rest()

	for !lexer.EOF() && lexer.PeekByte() != '#' && lexer.Rest() != "\\" {

		if lexer.NextBytesSet(unescapeMkCommentSafeChars) != "" ||
			lexer.SkipString("[#") ||
			lexer.SkipByte('[') {
			continue
		}

		assert(lexer.SkipByte('\\'))
		lexer.Skip(1)
	}

	end := len(rest)

	backslash := end
	for backslash > 0 && rest[backslash-1] == '\\' {
		backslash--
	}

	if (end-backslash)%2 == 0 {
		return rest[:end], "", ""
	}

	continuation := rest[backslash:]
	valueAndSpace := rest[:backslash]
	value := rtrimHspace(valueAndSpace)
	space := valueAndSpace[len(value):]
	return value, space, continuation
}

type varalignMkLine struct {
	infos []*varalignLine
}

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
func (l *varalignMkLine) isMultiEmpty() bool {
	return l.infos[0].isEmptyContinuation()
}

// rightMargin calculates the column in which the continuation backslashes
// should be placed.
// In addition it returns whether the right margin is already in its
// canonical form.
func (l *varalignMkLine) rightMargin() (ok bool, margin int) {
	restIndex := condInt(l.infos[0].value == "", 1, 0)
	infos := l.infos[restIndex:]

	var columns []int
	for _, info := range infos {
		if info.isContinuation() {
			space := info.spaceBeforeContinuation()
			if space != "" && space != " " {
				columns = append(columns, info.continuationColumn())
			}
		}
	}

	if len(columns) <= 1 {
		return false, 0
	}

	sort.Ints(columns)

	for i := len(columns) - 2; i >= 0; i-- {
		col := columns[i]
		if col == columns[i+1] {
			ok := columns[0] == columns[len(columns)-1] && col <= 72
			return ok, imin(col, 72)
		}
	}

	var min int
	for _, info := range infos {
		if info.isContinuation() {
			mainWidth := info.uptoValueWidth()
			if mainWidth > min {
				min = mainWidth
			}
		}
	}
	return false, min&-8 + 8
}

type varalignLine struct {
	fixer    Autofixer
	rawIndex int

	fixedSpaceBeforeContinuation bool

	varalignParts
}

func (info *varalignLine) alignValueSingle(newWidth int) {
	leadingComment := info.leadingComment
	varnameOp := info.varnameOp

	oldSpace := info.spaceBeforeValue
	newSpace := alignmentToWidths(tabWidthSlice(leadingComment, varnameOp), newWidth)

	// Indent the outlier with a space instead of a tab to keep the line short.
	if newSpace == "" && info.isCanonicalInitial(newWidth) {
		return
	}
	if newSpace == "" {
		newSpace = " "
	}

	if newSpace == oldSpace {
		return
	}

	hasSpace := strings.IndexByte(oldSpace, ' ') != -1
	oldColumn := tabWidthSlice(leadingComment, varnameOp, oldSpace)
	column := tabWidthSlice(leadingComment, varnameOp, newSpace)

	fix := info.fixer.Autofix()
	if newSpace == " " {
		fix.Notef(
			"This outlier variable value should be aligned " +
				"with a single space.")
		info.explainWrongColumn(fix)
	} else if hasSpace && column != oldColumn {
		fix.Notef(
			"This variable value should be aligned "+
				"with tabs, not spaces, to column %d instead of %d.",
			column+1, oldColumn+1)
		info.explainWrongColumn(fix)
	} else if column != oldColumn {
		fix.Notef(
			"This variable value should be aligned to column %d instead of %d.",
			column+1, oldColumn+1)
		info.explainWrongColumn(fix)
	} else {
		fix.Notef("Variable values should be aligned with tabs, not spaces.")
	}
	fix.ReplaceAt(info.rawIndex, info.spaceBeforeValueIndex(), oldSpace, newSpace)
	fix.Apply()
	info.spaceBeforeValue = newSpace
}

func (info *varalignLine) alignValueInitial(newWidth int) {
	if info.isEmptyContinuation() && info.valueColumn() > newWidth {
		return
	}
	newSpace := alignmentToWidths(info.spaceBeforeValueColumn(), newWidth)
	if newSpace == info.spaceBeforeValue {
		return
	}
	info.alignValue(newWidth)
}

func (info *varalignLine) alignValueMultiFollow(newWidth int) {
	newSpace := indent(newWidth)
	if newSpace == info.spaceBeforeValue {
		return
	}

	info.alignFollow(newSpace)
}

func (info *varalignLine) alignValue(width int) {
	oldSpace := info.spaceBeforeValue
	oldWidth := info.valueColumn()
	newSpace := alignmentToWidths(info.spaceBeforeValueColumn(), width)

	fix := info.fixer.Autofix()
	if width != oldWidth && contains(oldSpace, " ") {
		fix.Notef(
			"This variable value should be aligned "+
				"with tabs, not spaces, to column %d instead of %d.",
			width+1, oldWidth+1)
	} else if width != oldWidth {
		fix.Notef(
			"This variable value should be aligned "+
				"to column %d instead of %d.",
			width+1, oldWidth+1)
	} else {
		fix.Notef("Variable values should be aligned with tabs, not spaces.")
	}
	fix.ReplaceAt(info.rawIndex, info.spaceBeforeValueIndex(), oldSpace, newSpace)
	fix.Apply()
	info.spaceBeforeValue = newSpace
}

func (info *varalignLine) alignFollow(newSpace string) {
	// Below a continuation marker, there may be a completely empty line.
	// This is confusing to the human readers, but technically allowed.
	if info.varalignParts.isEmpty() {
		return
	}

	continuationColumn := 0
	if info.spaceBeforeContinuation() != " " {
		continuationColumn = imin(72, info.continuationColumn())
	}

	fix := info.fixer.Autofix()
	fix.Notef("This continuation line should be indented with %q.", newSpace)
	info.replaceSpaceBeforeValue(fix, newSpace)
	if info.isContinuation() {
		info.replaceSpaceBeforeContinuationSilently(fix, continuationColumn)
	}
	fix.Apply()
}

func (info *varalignLine) alignContinuation(valueColumn, rightMarginColumn int) {
	if !info.isContinuation() {
		return
	}

	oldSpace := info.spaceBeforeContinuation()
	if oldSpace == " " {
		return
	}

	column := info.continuationColumn()
	if column <= 72 && oldSpace == "\t" {
		return
	}
	if column == 72 || column == rightMarginColumn || column <= valueColumn {
		return
	}

	newSpace := " "
	fix := info.fixer.Autofix()
	if oldSpace == "" || rightMarginColumn == 0 {
		fix.Notef("The continuation backslash should be preceded by a single space or tab.")
	} else if info.isTooLongFor(valueColumn) {
		fix.Notef("The continuation backslash should be preceded by a single space.")
	} else {
		newSpace = alignmentToWidths(info.uptoValueWidth(), rightMarginColumn)
		fix.Notef(
			"The continuation backslash should be in column %d, not %d.",
			rightMarginColumn+1, column+1)
	}
	index := info.continuationIndex() - len(oldSpace)
	fix.ReplaceAt(info.rawIndex, index, oldSpace, newSpace)
	info.setSpaceBeforeContinuation(newSpace)
	fix.Apply()
}

func (info *varalignLine) replaceSpaceBeforeValue(fix *Autofix, newSpace string) {
	index := info.spaceBeforeValueIndex()
	fix.ReplaceAt(info.rawIndex, index, info.spaceBeforeValue, newSpace)
	info.spaceBeforeValue = newSpace
}

func (info *varalignLine) replaceSpaceBeforeContinuationSilently(fix *Autofix, column int) {
	if info.value == "" {
		return
	}

	oldSpace := info.spaceBeforeContinuation()
	if oldSpace == " " {
		return
	}
	newSpaceColumn := info.uptoValueWidth()
	newSpace := alignmentToWidths(newSpaceColumn, column)
	if newSpace == "" {
		newSpace = " "
	}
	if oldSpace == newSpace {
		return
	}

	index := info.spaceBeforeContinuationIndex()
	fix.ReplaceAt(info.rawIndex, index, oldSpace+"\\", newSpace+"\\")
	info.varalignParts.setSpaceBeforeContinuation(newSpace)
	info.fixedSpaceBeforeContinuation = true
}

func (*varalignLine) explainWrongColumn(fix *Autofix) {
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

type varalignParts struct {
	leadingComment   string // either the # or some rarely used U+0020 spaces
	varnameOp        string // empty iff it is a follow-up line
	spaceBeforeValue string // for follow-up lines, this is the indentation
	value            string // including any trailing comment
	spaceAfterValue  string
	continuation     string // either a single backslash or empty
}

func (p *varalignParts) String() string {
	return p.leadingComment +
		p.varnameOp + p.spaceBeforeValue +
		p.value + p.spaceAfterValue +
		p.continuation
}

func (p *varalignParts) leadingCommentIndex() int {
	return 0
}

func (p *varalignParts) varnameOpIndex() int {
	return p.leadingCommentIndex() + len(p.leadingComment)
}

// spaceBeforeValueIndex returns the string index at which the space before the value starts.
// It's the same as the end of the assignment operator. Example:
//  #VAR=   value
// The index is 5.
func (p *varalignParts) spaceBeforeValueIndex() int {
	return p.varnameOpIndex() + len(p.varnameOp)
}

func (p *varalignParts) valueIndex() int {
	return p.spaceBeforeValueIndex() + len(p.spaceBeforeValue)
}

func (p *varalignParts) spaceAfterValueIndex() int {
	return p.valueIndex() + len(p.value)
}

func (p *varalignParts) continuationIndex() int {
	return p.spaceAfterValueIndex() + len(p.spaceAfterValue)
}

func (p *varalignParts) leadingCommentColumn() int {
	return 0
}

func (p *varalignParts) varnameOpColumn() int {
	return tabWidthAppend(p.leadingCommentColumn(), p.leadingComment)
}

func (p *varalignParts) spaceBeforeValueColumn() int {
	return tabWidthAppend(p.varnameOpColumn(), p.varnameOp)
}

func (p *varalignParts) valueColumn() int {
	return tabWidthAppend(p.spaceBeforeValueColumn(), p.spaceBeforeValue)
}

func (p *varalignParts) spaceAfterValueColumn() int {
	return tabWidthAppend(p.valueColumn(), p.value)
}

func (p *varalignParts) continuationColumn() int {
	return tabWidthAppend(p.spaceAfterValueColumn(), p.spaceAfterValue)
}

// continuation returns whether this line ends with a backslash.
func (p *varalignParts) isContinuation() bool {
	return p.continuation != ""
}

func (p *varalignParts) isEmptyContinuation() bool {
	return p.value == "" && p.isContinuation()
}

func (p *varalignParts) isEmpty() bool {
	return p.value == "" && !p.isContinuation()
}

func (p *varalignParts) spaceBeforeContinuation() string {
	if p.value == "" {
		return p.spaceBeforeValue
	}
	return p.spaceAfterValue
}

func (p *varalignParts) setSpaceBeforeContinuation(space string) {
	if p.value == "" {
		p.spaceBeforeValue = space
	} else {
		p.spaceAfterValue = space
	}
}

func (p *varalignParts) spaceBeforeContinuationIndex() int {
	assert(p.isContinuation())
	assert(p.value != "")

	return p.spaceAfterValueIndex()
}

func (p *varalignParts) uptoValueWidth() int {
	if p.value != "" {
		return p.spaceAfterValueColumn()
	} else {
		return p.spaceBeforeValueColumn()
	}
}

func (p *varalignParts) isCommentedOut() bool {
	return hasPrefix(p.leadingComment, "#")
}

// isCanonicalInitial returns whether the space between the assignment
// operator and the value has its canonical form, which is either
// at least one tab, or a single space, but only for lines that stick out.
func (p *varalignParts) isCanonicalInitial(column int) bool {
	space := p.spaceBeforeValue
	if space == "" {
		return false
	}

	if space == " " && p.valueColumn() > column {
		return true
	}

	return strings.TrimLeft(space, "\t") == ""
}

// isCanonicalFollow returns whether the space before the value has its
// canonical form, which is at least one tab, followed by up to 7 spaces.
func (p *varalignParts) isCanonicalFollow() bool {
	column := p.valueColumn()
	return column >= 8 && p.spaceBeforeValue == indent(column)
}

func (p *varalignParts) isTooLongFor(valueColumn int) bool {
	column := tabWidthAppend(imax(valueColumn, 8), p.value)
	if p.isContinuation() {
		column += 2
	}
	return column > 73
}
