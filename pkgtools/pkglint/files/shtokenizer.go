package pkglint

import "netbsd.org/pkglint/textproc"

type ShTokenizer struct {
	parser *MkParser
}

func NewShTokenizer(line *Line, text string, emitWarnings bool) *ShTokenizer {
	// TODO: Switching to NewMkParser is nontrivial since emitWarnings must equal (line != nil).
	p := MkParser{line, textproc.NewLexer(text), emitWarnings}
	return &ShTokenizer{&p}
}

// ShAtom parses a basic building block of a shell program.
// Examples for such atoms are: variable reference (both make and shell),
// operator, text, quote, space.
//
// See ShQuote.Feed
func (p *ShTokenizer) ShAtom(quoting ShQuoting) *ShAtom {
	if p.parser.EOF() {
		return nil
	}

	lexer := p.parser.lexer
	mark := lexer.Mark()

	if varuse := p.parser.VarUse(); varuse != nil {
		return &ShAtom{shtVaruse, lexer.Since(mark), quoting, varuse}
	}

	// TODO: Most probably there is a more elegant way than the large switch block below.

	var atom *ShAtom
	switch quoting {
	case shqPlain:
		atom = p.shAtomPlain()
	case shqDquot:
		atom = p.shAtomDquot()
	case shqSquot:
		atom = p.shAtomSquot()
	case shqBackt:
		atom = p.shAtomBackt()
	case shqSubsh:
		atom = p.shAtomSubsh()
	case shqDquotBackt:
		atom = p.shAtomDquotBackt()
	case shqBacktDquot:
		atom = p.shAtomBacktDquot()
	case shqBacktSquot:
		atom = p.shAtomBacktSquot()
	case shqSubshDquot:
		atom = p.shAtomSubshDquot()
	case shqSubshSquot:
		atom = p.shAtomSubshSquot()
	case shqSubshBackt:
		atom = p.shAtomSubshBackt()
	case shqDquotBacktDquot:
		atom = p.shAtomDquotBacktDquot()
	case shqDquotBacktSquot:
		atom = p.shAtomDquotBacktSquot()
	}

	if atom == nil {
		lexer.Reset(mark)
		if hasPrefix(lexer.Rest(), "$${") {
			p.parser.Line.Warnf("Unclosed shell variable starting at %q.", shorten(lexer.Rest(), 20))
		} else {
			p.parser.Line.Warnf("Internal pkglint error in ShTokenizer.ShAtom at %q (quoting=%s).", lexer.Rest(), quoting)
		}
	}
	return atom
}

func (p *ShTokenizer) shAtomPlain() *ShAtom {
	const q = shqPlain
	if op := p.shOperator(q); op != nil {
		return op
	}
	lexer := p.parser.lexer
	mark := lexer.Mark()
	switch {
	case lexer.NextHspace() != "":
		return &ShAtom{shtSpace, lexer.Since(mark), q, nil}
	case lexer.SkipByte('"'):
		return &ShAtom{shtText, lexer.Since(mark), shqDquot, nil}
	case lexer.SkipByte('\''):
		return &ShAtom{shtText, lexer.Since(mark), shqSquot, nil}
	case lexer.SkipByte('`'):
		return &ShAtom{shtText, lexer.Since(mark), shqBackt, nil}
	case lexer.PeekByte() == '#':
		rest := lexer.Rest()
		lexer.Skip(len(rest))
		return &ShAtom{shtComment, rest, q, nil}
	case lexer.SkipString("$$("):
		return &ShAtom{shtSubshell, lexer.Since(mark), shqSubsh, nil}
	}

	return p.shAtomInternal(q, false, false)
}

func (p *ShTokenizer) shAtomDquot() *ShAtom {
	lexer := p.parser.lexer
	mark := lexer.Mark()
	switch {
	case lexer.SkipByte('"'):
		return &ShAtom{shtText, lexer.Since(mark), shqPlain, nil}
	case lexer.SkipByte('`'):
		return &ShAtom{shtText, lexer.Since(mark), shqDquotBackt, nil}
	}
	return p.shAtomInternal(shqDquot, true, false)
}

func (p *ShTokenizer) shAtomSquot() *ShAtom {
	lexer := p.parser.lexer
	mark := lexer.Mark()
	switch {
	case lexer.SkipByte('\''):
		return &ShAtom{shtText, lexer.Since(mark), shqPlain, nil}
	}
	return p.shAtomInternal(shqSquot, false, true)
}

func (p *ShTokenizer) shAtomBackt() *ShAtom {
	const q = shqBackt
	if op := p.shOperator(q); op != nil {
		return op
	}
	lexer := p.parser.lexer
	mark := lexer.Mark()
	switch {
	case lexer.SkipByte('"'):
		return &ShAtom{shtText, lexer.Since(mark), shqBacktDquot, nil}
	case lexer.SkipByte('`'):
		return &ShAtom{shtText, lexer.Since(mark), shqPlain, nil}
	case lexer.SkipByte('\''):
		return &ShAtom{shtText, lexer.Since(mark), shqBacktSquot, nil}
	case lexer.NextHspace() != "":
		return &ShAtom{shtSpace, lexer.Since(mark), q, nil}
	case lexer.SkipRegexp(G.res.Compile("^#[^`]*")):
		return &ShAtom{shtComment, lexer.Since(mark), q, nil}
	}
	return p.shAtomInternal(q, false, false)
}

// In pkgsrc, the $(...) subshell syntax is not used, in order to preserve
// compatibility with /bin/sh from Solaris 7.
func (p *ShTokenizer) shAtomSubsh() *ShAtom {
	const q = shqSubsh
	lexer := p.parser.lexer
	mark := lexer.Mark()
	switch {
	case lexer.NextHspace() != "":
		return &ShAtom{shtSpace, lexer.Since(mark), q, nil}
	case lexer.SkipByte('"'):
		return &ShAtom{shtText, lexer.Since(mark), shqSubshDquot, nil}
	case lexer.SkipByte('\''):
		return &ShAtom{shtText, lexer.Since(mark), shqSubshSquot, nil}
	case lexer.SkipByte('`'):
		return &ShAtom{shtText, lexer.Since(mark), shqSubshBackt, nil}
	case lexer.SkipRegexp(G.res.Compile(`^#[^)]*`)):
		return &ShAtom{shtComment, lexer.Since(mark), q, nil}
	case lexer.SkipByte(')'):
		// The closing parenthesis can have multiple meanings:
		// - end of a subshell, such as (echo "in a subshell")
		// - end of a subshell variable expression, such as var=$$(echo "from a subshell")
		// - end of a case pattern
		// In the "subshell variable expression" case, the atom type
		// could be shtText since it is part of a text node. On the
		// other hand, pkglint doesn't tokenize shell programs correctly
		// anyway. This needs to be fixed someday.
		return &ShAtom{shtOperator, lexer.Since(mark), shqPlain, nil}
	}
	if op := p.shOperator(q); op != nil {
		return op
	}
	return p.shAtomInternal(q, false, false)
}

func (p *ShTokenizer) shAtomDquotBackt() *ShAtom {
	const q = shqDquotBackt
	if op := p.shOperator(q); op != nil {
		return op
	}
	lexer := p.parser.lexer
	mark := lexer.Mark()
	switch {
	case lexer.SkipByte('`'):
		return &ShAtom{shtText, lexer.Since(mark), shqDquot, nil}
	case lexer.SkipByte('"'):
		return &ShAtom{shtText, lexer.Since(mark), shqDquotBacktDquot, nil}
	case lexer.SkipByte('\''):
		return &ShAtom{shtText, lexer.Since(mark), shqDquotBacktSquot, nil}
	case lexer.SkipRegexp(G.res.Compile("^#[^`]*")):
		return &ShAtom{shtComment, lexer.Since(mark), q, nil}
	case lexer.NextHspace() != "":
		return &ShAtom{shtSpace, lexer.Since(mark), q, nil}
	}
	return p.shAtomInternal(q, false, false)
}

func (p *ShTokenizer) shAtomBacktDquot() *ShAtom {
	const q = shqBacktDquot
	lexer := p.parser.lexer
	mark := lexer.Mark()
	switch {
	case lexer.SkipByte('"'):
		return &ShAtom{shtText, lexer.Since(mark), shqBackt, nil}
	}
	return p.shAtomInternal(q, true, false)
}

func (p *ShTokenizer) shAtomBacktSquot() *ShAtom {
	const q = shqBacktSquot
	lexer := p.parser.lexer
	mark := lexer.Mark()
	switch {
	case lexer.SkipByte('\''):
		return &ShAtom{shtText, lexer.Since(mark), shqBackt, nil}
	}
	return p.shAtomInternal(q, false, true)
}

func (p *ShTokenizer) shAtomSubshDquot() *ShAtom {
	const q = shqSubshDquot
	lexer := p.parser.lexer
	mark := lexer.Mark()
	switch {
	case lexer.SkipByte('"'):
		return &ShAtom{shtText, lexer.Since(mark), shqSubsh, nil}
	}
	return p.shAtomInternal(q, true, false)
}

func (p *ShTokenizer) shAtomSubshSquot() *ShAtom {
	const q = shqSubshSquot
	lexer := p.parser.lexer
	mark := lexer.Mark()
	switch {
	case lexer.SkipByte('\''):
		return &ShAtom{shtText, lexer.Since(mark), shqSubsh, nil}
	}
	return p.shAtomInternal(q, false, true)
}

func (p *ShTokenizer) shAtomSubshBackt() *ShAtom {
	const q = shqSubshBackt
	lexer := p.parser.lexer
	mark := lexer.Mark()
	switch {
	case lexer.SkipByte('`'):
		return &ShAtom{shtOperator, lexer.Since(mark), shqSubsh, nil}
	case lexer.SkipHspace():
		return &ShAtom{shtSpace, lexer.Since(mark), q, nil}
	}
	return p.shAtomInternal(q, false, false)
}

func (p *ShTokenizer) shAtomDquotBacktDquot() *ShAtom {
	const q = shqDquotBacktDquot
	lexer := p.parser.lexer
	mark := lexer.Mark()
	switch {
	case lexer.SkipByte('"'):
		return &ShAtom{shtText, lexer.Since(mark), shqDquotBackt, nil}
	}
	return p.shAtomInternal(q, true, false)
}

func (p *ShTokenizer) shAtomDquotBacktSquot() *ShAtom {
	const q = shqDquotBacktSquot
	lexer := p.parser.lexer
	mark := lexer.Mark()
	switch {
	case lexer.SkipByte('\''):
		return &ShAtom{shtText, lexer.Since(mark), shqDquotBackt, nil}
	}
	return p.shAtomInternal(q, false, true)
}

// shAtomInternal reads the next shtText or shtShVarUse.
//
// Examples:
//  while
//  text$$,text
//  $$!
//  $$$$
//  text
//  ${var:=default}
func (p *ShTokenizer) shAtomInternal(q ShQuoting, dquot, squot bool) *ShAtom {
	if shVarUse := p.shVarUse(q); shVarUse != nil {
		return shVarUse
	}

	lexer := p.parser.lexer
	mark := lexer.Mark()

loop:
	for {
		_ = `^[\t "$&'();<>\\|]+` // These are not allowed in shqPlain.

		switch {
		case lexer.SkipRegexp(G.res.Compile(`^[!#%*+,\-./0-9:=?@A-Z\[\]^_a-z{}~]+`)):
			break
		case dquot && lexer.SkipRegexp(G.res.Compile(`^[\t &'();<>|]+`)):
			break
		case squot && lexer.SkipByte('`'):
			break
		case squot && lexer.SkipRegexp(G.res.Compile(`^[\t "&();<>\\|]+`)):
			break
		case squot && lexer.SkipString("$$"):
			break
		case squot:
			break loop
		case lexer.SkipString("\\$$"):
			break
		case lexer.SkipRegexp(G.res.Compile(`^\\[^$]`)):
			break
		case matches(lexer.Rest(), `^\$\$[^!#(*\-0-9?@A-Z_a-z{]`):
			lexer.NextString("$$")
		case lexer.Rest() == "$$":
			lexer.Skip(2)
		case lexer.Rest() == "$":
			lexer.Skip(1)
		default:
			break loop
		}
	}

	if token := lexer.Since(mark); token != "" {
		return &ShAtom{shtText, token, q, nil}
	}
	return nil
}

// shVarUse parses a use of a shell variable, like $$var or $${var:=value}.
//
// See http://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html#tag_02_06_02
func (p *ShTokenizer) shVarUse(q ShQuoting) *ShAtom {
	lexer := p.parser.lexer
	beforeDollar := lexer.Mark()

	if !lexer.SkipString("$$") {
		return nil
	}

	if lexer.TestByteSet(textproc.Digit) {
		lexer.Skip(1)
		text := lexer.Since(beforeDollar)
		return &ShAtom{shtShVarUse, text, q, text[2:]}
	}

	brace := lexer.SkipByte('{')

	varnameStart := lexer.Mark()
	if !lexer.SkipRegexp(G.res.Compile(`^(?:[!#*\-?@]|\$\$|[A-Za-z_]\w*|\d+)`)) {
		lexer.Reset(beforeDollar)
		return nil
	}

	shVarname := lexer.Since(varnameStart)
	if shVarname == "$$" {
		shVarname = "$"
	}

	if brace {
		lexer.SkipRegexp(G.res.Compile(`^(?:##?|%%?|:?[+\-=?])[^$\\{}]*`))
		if !lexer.SkipByte('}') {
			lexer.Reset(beforeDollar)
			return nil
		}
	}

	return &ShAtom{shtShVarUse, lexer.Since(beforeDollar), q, shVarname}
}

func (p *ShTokenizer) shOperator(q ShQuoting) *ShAtom {
	lexer := p.parser.lexer
	mark := lexer.Mark()
	switch {
	case lexer.SkipString("||"),
		lexer.SkipString("&&"),
		lexer.SkipString(";;"),
		lexer.NextBytesFunc(func(b byte) bool { return b == '\n' }) != "",
		lexer.SkipByte(';'),
		lexer.SkipByte('('),
		lexer.SkipByte(')'),
		lexer.SkipByte('|'),
		lexer.SkipByte('&'):
		return &ShAtom{shtOperator, lexer.Since(mark), q, nil}
	case lexer.SkipRegexp(G.res.Compile(`^\d*(?:<<-|<<|<&|<>|>>|>&|>\||<|>)`)):
		return &ShAtom{shtOperator, lexer.Since(mark), q, nil}
	}
	return nil
}

func (p *ShTokenizer) ShAtoms() []*ShAtom {
	var atoms []*ShAtom
	q := shqPlain
	for {
		atom := p.ShAtom(q)
		if atom == nil {
			return atoms
		}
		atoms = append(atoms, atom)
		q = atom.Quoting
	}
}

func (p *ShTokenizer) ShToken() *ShToken {
	var curr *ShAtom
	q := shqPlain
	prevQ := q

	peek := func() *ShAtom {
		if curr == nil {
			curr = p.ShAtom(q)
			if curr != nil {
				prevQ = q
				q = curr.Quoting
			}
		}
		return curr
	}
	skip := func() {
		curr = nil
	}

	lexer := p.parser.lexer
	initialMark := lexer.Mark()

	for peek() != nil && peek().Type == shtSpace {
		skip()
		initialMark = lexer.Mark()
	}

	if curr == nil {
		return nil
	}

	if !curr.Type.IsWord() && q != shqSubsh {
		return NewShToken(curr.MkText, curr)
	}

	var atoms []*ShAtom
	for {
		mark := lexer.Mark()
		peek()
		if curr == nil || !curr.Type.IsWord() && q == shqPlain && prevQ != shqSubsh {
			lexer.Reset(mark)
			break
		}
		atoms = append(atoms, curr)
		skip()
	}

	if q != shqPlain {
		lexer.Reset(initialMark)
		return nil
	}

	return NewShToken(lexer.Since(initialMark), atoms...)
}

func (p *ShTokenizer) Rest() string {
	return p.parser.Rest()
}
