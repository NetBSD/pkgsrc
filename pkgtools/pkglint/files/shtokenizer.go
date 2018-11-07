package main

type ShTokenizer struct {
	parser *Parser
	mkp    *MkParser
}

func NewShTokenizer(line Line, text string, emitWarnings bool) *ShTokenizer {
	p := NewParser(line, text, emitWarnings)
	mkp := &MkParser{p}
	return &ShTokenizer{p, mkp}
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

	repl := p.parser.repl
	mark := repl.Mark()

	if varuse := p.mkp.VarUse(); varuse != nil {
		return &ShAtom{shtVaruse, repl.Since(mark), quoting, varuse}
	}

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
	case shqDquotBacktDquot:
		atom = p.shAtomDquotBacktDquot()
	case shqDquotBacktSquot:
		atom = p.shAtomDquotBacktSquot()
	}

	if atom == nil {
		repl.Reset(mark)
		if hasPrefix(repl.Rest(), "${") {
			p.parser.Line.Warnf("Unclosed Make variable starting at %q.", shorten(repl.Rest(), 20))
		} else {
			p.parser.Line.Warnf("Pkglint parse error in ShTokenizer.ShAtom at %q (quoting=%s).", repl.Rest(), quoting)
		}
	}
	return atom
}

func (p *ShTokenizer) shAtomPlain() *ShAtom {
	const q = shqPlain
	if op := p.shOperator(q); op != nil {
		return op
	}
	repl := p.parser.repl
	switch {
	case repl.AdvanceHspace():
		return &ShAtom{shtSpace, repl.Str(), q, nil}
	case repl.AdvanceStr("\""):
		return &ShAtom{shtWord, repl.Str(), shqDquot, nil}
	case repl.AdvanceStr("'"):
		return &ShAtom{shtWord, repl.Str(), shqSquot, nil}
	case repl.AdvanceStr("`"):
		return &ShAtom{shtWord, repl.Str(), shqBackt, nil}
	case repl.PeekByte() == '#':
		return &ShAtom{shtComment, repl.AdvanceRest(), q, nil}
	case repl.AdvanceStr("$$("):
		return &ShAtom{shtSubshell, repl.Str(), shqSubsh, nil}
	}

	return p.shAtomInternal(q, false, false)
}

func (p *ShTokenizer) shAtomDquot() *ShAtom {
	repl := p.parser.repl
	switch {
	case repl.AdvanceStr("\""):
		return &ShAtom{shtWord, repl.Str(), shqPlain, nil}
	case repl.AdvanceStr("`"):
		return &ShAtom{shtWord, repl.Str(), shqDquotBackt, nil}
	}
	return p.shAtomInternal(shqDquot, true, false)
}

func (p *ShTokenizer) shAtomSquot() *ShAtom {
	repl := p.parser.repl
	switch {
	case repl.AdvanceStr("'"):
		return &ShAtom{shtWord, repl.Str(), shqPlain, nil}
	}
	return p.shAtomInternal(shqSquot, false, true)
}

func (p *ShTokenizer) shAtomBackt() *ShAtom {
	const q = shqBackt
	if op := p.shOperator(q); op != nil {
		return op
	}
	repl := p.parser.repl
	switch {
	case repl.AdvanceStr("\""):
		return &ShAtom{shtWord, repl.Str(), shqBacktDquot, nil}
	case repl.AdvanceStr("`"):
		return &ShAtom{shtWord, repl.Str(), shqPlain, nil}
	case repl.AdvanceStr("'"):
		return &ShAtom{shtWord, repl.Str(), shqBacktSquot, nil}
	case repl.AdvanceHspace():
		return &ShAtom{shtSpace, repl.Str(), q, nil}
	case repl.AdvanceRegexp("^#[^`]*"):
		return &ShAtom{shtComment, repl.Str(), q, nil}
	}
	return p.shAtomInternal(q, false, false)
}

// In pkgsrc, the $(...) subshell syntax is not used, in order to preserve
// compatibility with /bin/sh from Solaris 7.
func (p *ShTokenizer) shAtomSubsh() *ShAtom {
	const q = shqSubsh
	repl := p.parser.repl
	switch {
	case repl.AdvanceHspace():
		return &ShAtom{shtSpace, repl.Str(), q, nil}
	case repl.AdvanceStr("\""):
		return &ShAtom{shtWord, repl.Str(), shqSubshDquot, nil}
	case repl.AdvanceStr("'"):
		return &ShAtom{shtWord, repl.Str(), shqSubshSquot, nil}
	case repl.AdvanceStr("`"):
		// FIXME: return &ShAtom{shtWord, repl.Str(), shqBackt, nil}
	case repl.AdvanceRegexp(`^#[^)]*`):
		return &ShAtom{shtComment, repl.Str(), q, nil}
	case repl.AdvanceStr(")"):
		return &ShAtom{shtWord, repl.Str(), shqPlain, nil}
	case repl.AdvanceRegexp(`^(?:[!#%*+,\-./0-9:=?@A-Z\[\]^_a-z{}~]+|\\[^$]|` + reShDollar + `)+`):
		return &ShAtom{shtWord, repl.Str(), q, nil}
	}
	return p.shOperator(q)
}

func (p *ShTokenizer) shAtomDquotBackt() *ShAtom {
	const q = shqDquotBackt
	if op := p.shOperator(q); op != nil {
		return op
	}
	repl := p.parser.repl
	switch {
	case repl.AdvanceStr("`"):
		return &ShAtom{shtWord, repl.Str(), shqDquot, nil}
	case repl.AdvanceStr("\""):
		return &ShAtom{shtWord, repl.Str(), shqDquotBacktDquot, nil}
	case repl.AdvanceStr("'"):
		return &ShAtom{shtWord, repl.Str(), shqDquotBacktSquot, nil}
	case repl.AdvanceRegexp("^#[^`]*"):
		return &ShAtom{shtComment, repl.Str(), q, nil}
	case repl.AdvanceRegexp(`^(?:[!#%*+,\-./0-9:=?@A-Z\[\]_a-z~]+|\\[^$]|` + reShDollar + `)+`):
		return &ShAtom{shtWord, repl.Str(), q, nil}
	case repl.AdvanceHspace():
		return &ShAtom{shtSpace, repl.Str(), q, nil}
	}
	return nil
}

func (p *ShTokenizer) shAtomBacktDquot() *ShAtom {
	repl := p.parser.repl
	switch {
	case repl.AdvanceStr("\""):
		return &ShAtom{shtWord, repl.Str(), shqBackt, nil}
	case repl.AdvanceRegexp(`^(?:[\t !%&()*+,\-./0-9:;<=>?@A-Z\[\]^_a-z{|}~]+|\\[^$]|` + reShDollar + `)+`):
		return &ShAtom{shtWord, repl.Str(), shqBacktDquot, nil}
	}
	return nil
}

func (p *ShTokenizer) shAtomBacktSquot() *ShAtom {
	const q = shqBacktSquot
	repl := p.parser.repl
	switch {
	case repl.AdvanceStr("'"):
		return &ShAtom{shtWord, repl.Str(), shqBackt, nil}
	case repl.AdvanceRegexp(`^([\t !"#%&()*+,\-./0-9:;<=>?@A-Z\[\\\]^_` + "`" + `a-z{|}~]+|\$\$)+`):
		return &ShAtom{shtWord, repl.Str(), q, nil}
	}
	return nil
}

func (p *ShTokenizer) shAtomSubshDquot() *ShAtom {
	repl := p.parser.repl
	switch {
	case repl.AdvanceStr("\""):
		return &ShAtom{shtWord, repl.Str(), shqSubsh, nil}
	case repl.AdvanceRegexp(`^(?:[\t !%&()*+,\-./0-9:;<=>?@A-Z\[\]^_a-z{|}~]+|\\[^$]|` + reShDollar + `)+`):
		return &ShAtom{shtWord, repl.Str(), shqSubshDquot, nil}
	}
	return nil
}

func (p *ShTokenizer) shAtomSubshSquot() *ShAtom {
	const q = shqSubshSquot
	repl := p.parser.repl
	switch {
	case repl.AdvanceStr("'"):
		return &ShAtom{shtWord, repl.Str(), shqSubsh, nil}
	case repl.AdvanceRegexp(`^([\t !"#%&()*+,\-./0-9:;<=>?@A-Z\[\\\]^_` + "`" + `a-z{|}~]+|\$\$)+`):
		return &ShAtom{shtWord, repl.Str(), q, nil}
	}
	return nil
}

func (p *ShTokenizer) shAtomDquotBacktDquot() *ShAtom {
	const q = shqDquotBacktDquot
	repl := p.parser.repl
	switch {
	case repl.AdvanceStr("\""):
		return &ShAtom{shtWord, repl.Str(), shqDquotBackt, nil}
	case repl.AdvanceRegexp(`^(?:[\t !%&()*+,\-./0-9:;<=>?@A-Z\[\]^_a-z{|}~]+|\\[^$]|` + reShDollar + `)+`):
		return &ShAtom{shtWord, repl.Str(), q, nil}
	}
	return nil
}

func (p *ShTokenizer) shAtomDquotBacktSquot() *ShAtom {
	repl := p.parser.repl
	switch {
	case repl.AdvanceStr("'"):
		return &ShAtom{shtWord, repl.Str(), shqDquotBackt, nil}
	case repl.AdvanceRegexp(`^(?:[\t !"#%()*+,\-./0-9:;<=>?@A-Z\[\]^_a-z{|}~]+|\\[^$]|\\\$\$|\$\$)+`):
		return &ShAtom{shtWord, repl.Str(), shqDquotBacktSquot, nil}
	}
	return nil
}

// shAtomInternal advances the parser over the next "word",
// which is everything that does not change the quoting and is not a Make(1) variable.
// Shell variables may appear as part of a word.
//
// Examples:
//  while$var
//  $$,
//  $$!$$$$
//  echo
//  text${var:=default}text
func (p *ShTokenizer) shAtomInternal(q ShQuoting, dquot, squot bool) *ShAtom {
	repl := p.parser.repl

	mark := repl.Mark()
loop:
	for {
		_ = `^[\t "$&'();<>\\|]+` // These are not allowed in shqPlain.

		switch {
		case repl.AdvanceRegexp(`^[!#%*+,\-./0-9:=?@A-Z\[\]^_a-z{}~]+`):
		case dquot && repl.AdvanceRegexp(`^[\t &'();<>|]+`):
		case squot && repl.AdvanceStr("`"):
		case squot && repl.AdvanceRegexp(`^[\t "&();<>\\|]+`):
		case squot && repl.AdvanceStr("$$"):
		case squot:
			break loop
		case repl.AdvanceRegexp(`^\\[^$]`):
		case repl.HasPrefixRegexp(`^\$\$[^!#(*\-0-9?@A-Z_a-z{]`):
			repl.AdvanceStr("$$")
		case repl.AdvanceRegexp(`^(?:` + reShDollar + `)`):
		default:
			break loop
		}
	}

	if token := repl.Since(mark); token != "" {
		return &ShAtom{shtWord, token, q, nil}
	}
	return nil
}

func (p *ShTokenizer) shOperator(q ShQuoting) *ShAtom {
	repl := p.parser.repl
	switch {
	case repl.AdvanceStr("||"),
		repl.AdvanceStr("&&"),
		repl.AdvanceStr(";;"),
		repl.AdvanceStr("\n"),
		repl.AdvanceStr(";"),
		repl.AdvanceStr("("),
		repl.AdvanceStr(")"),
		repl.AdvanceStr("|"),
		repl.AdvanceStr("&"):
		return &ShAtom{shtOperator, repl.Str(), q, nil}
	case repl.AdvanceRegexp(`^\d*(?:<<-|<<|<&|<>|>>|>&|>\||<|>)`):
		return &ShAtom{shtOperator, repl.Str(), q, nil}
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

	peek := func() *ShAtom {
		if curr == nil {
			curr = p.ShAtom(q)
			if curr != nil {
				q = curr.Quoting
			}
		}
		return curr
	}
	skip := func() {
		curr = nil
	}

	repl := p.parser.repl
	initialMark := repl.Mark()
	var atoms []*ShAtom

	for peek() != nil && peek().Type == shtSpace {
		skip()
		initialMark = repl.Mark()
	}

	if peek() == nil {
		return nil
	}
	if atom := peek(); !atom.Type.IsWord() {
		return NewShToken(atom.MkText, atom)
	}

nextAtom:
	mark := repl.Mark()
	atom := peek()
	if atom != nil && (atom.Type.IsWord() || atom.Quoting != shqPlain) {
		skip()
		atoms = append(atoms, atom)
		goto nextAtom
	}
	repl.Reset(mark)

	G.Assertf(len(atoms) > 0, "ShTokenizer.ShToken")
	return NewShToken(repl.Since(initialMark), atoms...)
}

func (p *ShTokenizer) Rest() string {
	return p.parser.Rest()
}
