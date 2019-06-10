package pkglint

import "strings"

// Paragraph is a slice of Makefile lines that is surrounded by empty lines.
//
// All variable assignments in a paragraph should be aligned in the same column.
//
// If the paragraph adds an identifier to SUBST_CLASSES, the rest of the SUBST
// block should be defined in the same paragraph.
type Paragraph struct {
	mklines []MkLine
}

func NewParagraph(mklines []MkLine) *Paragraph {
	return &Paragraph{mklines}
}

func (p *Paragraph) Clear() {
	p.mklines = nil
}

func (p *Paragraph) Add(mkline MkLine) {
	assertf(!mkline.IsEmpty(), "A paragraph must not contain empty lines.")
	p.mklines = append(p.mklines, mkline)
}

func (p *Paragraph) ForEach(action func(mkline MkLine)) {
	for _, mkline := range p.mklines {
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
	for _, mkline := range p.mklines {
		if !mkline.IsVarassign() {
			continue
		}

		align := mkline.ValueAlign()
		oldWidth := tabWidth(align)
		if tabWidth(rtrimHspace(align)) > column {
			continue
		}
		if oldWidth == column && !hasSuffix(strings.TrimRight(align, "\t"), " ") {
			continue
		}
		if mkline.IsMultiline() && !mkline.FirstLineContainsValue() {
			continue
		}

		trimmed := strings.TrimRightFunc(align, isHspaceRune)
		newSpace := strings.Repeat("\t", (7+column-tabWidth(trimmed))/8)

		fix := mkline.Autofix()
		fix.Notef(SilentAutofixFormat)
		fix.ReplaceAfter(trimmed, align[len(trimmed):], newSpace)
		fix.Apply()
	}
}
