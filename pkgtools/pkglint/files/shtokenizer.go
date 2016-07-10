package main

type ShTokenizer struct {
	parser *Parser
	mkp    *MkParser
}

func NewShTokenizer(line *Line, text string, emitWarnings bool) *ShTokenizer {
	p := NewParser(line, text, emitWarnings)
	mkp := &MkParser{p}
	return &ShTokenizer{p, mkp}
}

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
		atom = p.shAtomSub()
	case shqDquotBackt:
		atom = p.shAtomDquotBackt()
	case shqBacktDquot:
		atom = p.shAtomBacktDquot()
	case shqBacktSquot:
		atom = p.shAtomBacktSquot()
	case shqSubshSquot:
		atom = p.shAtomSubshSquot()
	case shqDquotBacktDquot:
		atom = p.shAtomDquotBacktDquot()
	case shqDquotBacktSquot:
		atom = p.shAtomDquotBacktSquot()
	}

	if atom == nil {
		repl.Reset(mark)
		p.parser.Line.Warnf("Pkglint parse error in ShTokenizer.ShAtom at %q (quoting=%s)", repl.rest, quoting)
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
		return &ShAtom{shtSpace, repl.s, q, nil}
	case repl.AdvanceStr("\""):
		return &ShAtom{shtWord, repl.s, shqDquot, nil}
	case repl.AdvanceStr("'"):
		return &ShAtom{shtWord, repl.s, shqSquot, nil}
	case repl.AdvanceStr("`"):
		return &ShAtom{shtWord, repl.s, shqBackt, nil}
	case repl.AdvanceRegexp(`^#.*`):
		return &ShAtom{shtComment, repl.m[0], q, nil}
	case repl.AdvanceStr("$$("):
		return &ShAtom{shtSubshell, repl.s, q, nil}
	case repl.AdvanceRegexp(`^(?:[!#%*+,\-./0-9:=?@A-Z\[\]^_a-z{}~]+|\\[^$]|` + reShDollar + `)+`):
		return &ShAtom{shtWord, repl.m[0], q, nil}
	}
	return nil
}

func (p *ShTokenizer) shAtomDquot() *ShAtom {
	repl := p.parser.repl
	switch {
	case repl.AdvanceStr("\""):
		return &ShAtom{shtWord, repl.s, shqPlain, nil}
	case repl.AdvanceStr("`"):
		return &ShAtom{shtWord, repl.s, shqDquotBackt, nil}
	case repl.AdvanceRegexp(`^(?:[\t !#%&'()*+,\-./0-9:;<=>?@A-Z\[\]^_a-z{|}~]+|\\[^$]|` + reShDollar + `)+`):
		return &ShAtom{shtWord, repl.m[0], shqDquot, nil} // XXX: unescape?
	}
	return nil
}

func (p *ShTokenizer) shAtomSquot() *ShAtom {
	repl := p.parser.repl
	switch {
	case repl.AdvanceStr("'"):
		return &ShAtom{shtWord, repl.s, shqPlain, nil}
	case repl.AdvanceRegexp(`^([\t !"#%&()*+,\-./0-9:;<=>?@A-Z\[\\\]^_` + "`" + `a-z{|}~]+|\$\$)+`):
		return &ShAtom{shtWord, repl.m[0], shqSquot, nil}
	}
	return nil
}

func (p *ShTokenizer) shAtomBackt() *ShAtom {
	const q = shqBackt
	if op := p.shOperator(q); op != nil {
		return op
	}
	repl := p.parser.repl
	switch {
	case repl.AdvanceStr("\""):
		return &ShAtom{shtWord, repl.s, shqBacktDquot, nil}
	case repl.AdvanceStr("`"):
		return &ShAtom{shtWord, repl.s, shqPlain, nil}
	case repl.AdvanceStr("'"):
		return &ShAtom{shtWord, repl.s, shqBacktSquot, nil}
	case repl.AdvanceHspace():
		return &ShAtom{shtSpace, repl.s, q, nil}
	case repl.AdvanceRegexp("^#[^`]*"):
		return &ShAtom{shtComment, repl.s, q, nil}
	case repl.AdvanceRegexp(`^(?:[!#%*+,\-./0-9:=?@A-Z\[\]_a-z~]+|\\[^$]|` + reShDollar + `)+`):
		return &ShAtom{shtWord, repl.s, q, nil}
	}
	return nil
}

func (p *ShTokenizer) shAtomSub() *ShAtom {
	const q = shqSubsh
	if op := p.shOperator(q); op != nil {
		return op
	}
	repl := p.parser.repl
	mark := repl.Mark()
	atom := func(typ ShAtomType) *ShAtom {
		return &ShAtom{typ, repl.Since(mark), shqSubsh, nil}
	}
	switch {
	case repl.AdvanceHspace():
		return atom(shtSpace)
	case repl.AdvanceStr("\""):
		//return &ShAtom{shtWord, repl.s, shqDquot, nil}
	case repl.AdvanceStr("'"):
		return &ShAtom{shtWord, repl.s, shqSubshSquot, nil}
	case repl.AdvanceStr("`"):
		//return &ShAtom{shtWord, repl.s, shqBackt, nil}
	case repl.AdvanceRegexp(`^#.*`):
		return &ShAtom{shtComment, repl.m[0], q, nil}
	case repl.AdvanceStr(")"):
		return &ShAtom{shtWord, repl.s, shqPlain, nil}
	case repl.AdvanceRegexp(`^(?:[!#%*+,\-./0-9:=?@A-Z\[\]^_a-z{}~]+|\\[^$]|` + reShDollar + `)+`):
		return &ShAtom{shtWord, repl.m[0], q, nil}
	}
	return nil
}

func (p *ShTokenizer) shAtomDquotBackt() *ShAtom {
	const q = shqDquotBackt
	if op := p.shOperator(q); op != nil {
		return op
	}
	repl := p.parser.repl
	switch {
	case repl.AdvanceStr("`"):
		return &ShAtom{shtWord, repl.s, shqDquot, nil}
	case repl.AdvanceStr("\""):
		return &ShAtom{shtWord, repl.s, shqDquotBacktDquot, nil}
	case repl.AdvanceStr("'"):
		return &ShAtom{shtWord, repl.s, shqDquotBacktSquot, nil}
	case repl.AdvanceRegexp("^#[^`]*"):
		return &ShAtom{shtComment, repl.s, q, nil}
	case repl.AdvanceRegexp(`^(?:[!#%*+,\-./0-9:=?@A-Z\[\]_a-z~]+|\\[^$]|` + reShDollar + `)+`):
		return &ShAtom{shtWord, repl.s, q, nil}
	case repl.AdvanceHspace():
		return &ShAtom{shtSpace, repl.s, q, nil}
	}
	return nil
}

func (p *ShTokenizer) shAtomBacktDquot() *ShAtom {
	repl := p.parser.repl
	switch {
	case repl.AdvanceStr("\""):
		return &ShAtom{shtWord, repl.s, shqBackt, nil}
	case repl.AdvanceRegexp(`^(?:[\t !%&()*+,\-./0-9:;<=>?@A-Z\[\]^_a-z{|}~]+|\\[^$]|` + reShDollar + `)+`):
		return &ShAtom{shtWord, repl.m[0], shqBacktDquot, nil}
	}
	return nil
}

func (p *ShTokenizer) shAtomBacktSquot() *ShAtom {
	const q = shqBacktSquot
	repl := p.parser.repl
	switch {
	case repl.AdvanceStr("'"):
		return &ShAtom{shtWord, repl.s, shqBackt, nil}
	case repl.AdvanceRegexp(`^([\t !"#%&()*+,\-./0-9:;<=>?@A-Z\[\\\]^_` + "`" + `a-z{|}~]+|\$\$)+`):
		return &ShAtom{shtWord, repl.m[0], q, nil}
	}
	return nil
}

func (p *ShTokenizer) shAtomSubshSquot() *ShAtom {
	const q = shqSubshSquot
	repl := p.parser.repl
	switch {
	case repl.AdvanceStr("'"):
		return &ShAtom{shtWord, repl.s, shqSubsh, nil}
	case repl.AdvanceRegexp(`^([\t !"#%&()*+,\-./0-9:;<=>?@A-Z\[\\\]^_` + "`" + `a-z{|}~]+|\$\$)+`):
		return &ShAtom{shtWord, repl.m[0], q, nil}
	}
	return nil
}

func (p *ShTokenizer) shAtomDquotBacktDquot() *ShAtom {
	const q = shqDquotBacktDquot
	repl := p.parser.repl
	switch {
	case repl.AdvanceStr("\""):
		return &ShAtom{shtWord, repl.s, shqDquotBackt, nil}
	case repl.AdvanceRegexp(`^(?:[\t !%&()*+,\-./0-9:;<=>?@A-Z\[\]^_a-z{|}~]+|\\[^$]|` + reShDollar + `)+`):
		return &ShAtom{shtWord, repl.m[0], q, nil}
	}
	return nil
}

func (p *ShTokenizer) shAtomDquotBacktSquot() *ShAtom {
	repl := p.parser.repl
	switch {
	case repl.AdvanceStr("'"):
		return &ShAtom{shtWord, repl.s, shqDquotBackt, nil}
	case repl.AdvanceRegexp(`^(?:[\t !"#%()*+,\-./0-9:;<=>?@A-Z\[\]^_a-z{|}~]+|\\[^$]|\\\$\$|\$\$)+`):
		return &ShAtom{shtWord, repl.m[0], shqDquotBacktSquot, nil}
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
		return &ShAtom{shtOperator, repl.s, q, nil}
	case repl.AdvanceRegexp(`^\d*(?:<<-|<<|<&|<>|>>|>&|>\||<|>)`):
		return &ShAtom{shtOperator, repl.m[0], q, nil}
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
	inimark := repl.Mark()
	var atoms []*ShAtom

	for peek() != nil && peek().Type == shtSpace {
		skip()
		inimark = repl.Mark()
	}

	if peek() == nil {
		return nil
	}
	if atom := peek(); !atom.Type.IsWord() {
		return NewShToken(atom.MkText, atom)
	}

nextatom:
	mark := repl.Mark()
	atom := peek()
	if atom != nil && (atom.Type.IsWord() || atom.Quoting != shqPlain) {
		skip()
		atoms = append(atoms, atom)
		goto nextatom
	}
	repl.Reset(mark)

	if len(atoms) == 0 {
		return nil
	}
	return NewShToken(repl.Since(inimark), atoms...)
}

func (p *ShTokenizer) Mark() PrefixReplacerMark {
	return p.parser.repl.Mark()
}

func (p *ShTokenizer) Reset(mark PrefixReplacerMark) {
	p.parser.repl.Reset(mark)
}

func (p *ShTokenizer) Rest() string {
	return p.parser.Rest()
}
