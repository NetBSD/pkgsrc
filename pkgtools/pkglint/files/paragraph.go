package pkglint

import "strings"

// Paragraph is a slice of Makefile lines that is surrounded by empty lines.
//
// All variable assignments in a paragraph should be aligned in the same column.
//
// If the paragraph adds an identifier to SUBST_CLASSES, the rest of the SUBST
// block should be defined in the same paragraph.
type Paragraph struct {
	mklines *MkLines
	from    int
	to      int
}

func NewParagraph(mklines *MkLines, from, to int) *Paragraph {
	for i := from; i < to; i++ {
		assert(!mklines.mklines[i].IsEmpty())
	}
	return &Paragraph{mklines, from, to}
}

func (p *Paragraph) FirstLine() *MkLine { return p.mklines.mklines[p.from] }
func (p *Paragraph) LastLine() *MkLine  { return p.mklines.mklines[p.to-1] }

func (p *Paragraph) MkLines() []*MkLine { return p.mklines.mklines[p.from:p.to] }

func (p *Paragraph) ForEach(action func(mkline *MkLine)) {
	for _, mkline := range p.MkLines() {
		action(mkline)
	}
}

func (p *Paragraph) Align() {
	var align VaralignBlock
	p.ForEach(align.Process)
	align.Finish()
}

// AlignTo realigns all variable assignments in the paragraph so that their
// values start in the same column. Variable assignments that are commented
// out are also realigned.
//
// No warning or note is logged. Therefore this method must only be used to
// realign the whole paragraph after one of its lines has been modified.
func (p *Paragraph) AlignTo(column int) {
	p.ForEach(func(mkline *MkLine) {
		if !mkline.IsVarassign() {
			return
		}

		align := mkline.ValueAlign()
		oldWidth := tabWidth(align)
		if tabWidth(rtrimHspace(align)) > column {
			return
		}
		if oldWidth == column && !hasSuffix(strings.TrimRight(align, "\t"), " ") {
			return
		}
		if mkline.IsMultiline() && !mkline.FirstLineContainsValue() {
			return
		}

		trimmed := strings.TrimRightFunc(align, isHspaceRune)
		newSpace := strings.Repeat("\t", (7+column-tabWidth(trimmed))/8)

		fix := mkline.Autofix()
		fix.Notef(SilentAutofixFormat)
		fix.ReplaceAfter(trimmed, align[len(trimmed):], newSpace)
		fix.Apply()
	})
}
