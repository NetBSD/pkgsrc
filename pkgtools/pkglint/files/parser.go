package main

import (
	"netbsd.org/pkglint/textproc"
	"strings"
)

type Parser struct {
	Line         Line
	repl         *textproc.PrefixReplacer
	EmitWarnings bool
}

func NewParser(line Line, s string, emitWarnings bool) *Parser {
	return &Parser{line, G.NewPrefixReplacer(s), emitWarnings}
}

func (p *Parser) EOF() bool {
	return p.repl.Rest() == ""
}

func (p *Parser) Rest() string {
	return p.repl.Rest()
}

func (p *Parser) PkgbasePattern() (pkgbase string) {
	repl := p.repl

	for {
		if repl.AdvanceRegexp(`^\$\{\w+\}`) ||
			repl.AdvanceRegexp(`^[\w.*+,{}]+`) ||
			repl.AdvanceRegexp(`^\[[\d-]+\]`) {
			pkgbase += repl.Str()
			continue
		}

		mark := repl.Mark()
		if repl.AdvanceStr("-") {
			if repl.AdvanceRegexp(`^\d`) ||
				repl.AdvanceRegexp(`^\$\{\w*VER\w*\}`) ||
				repl.AdvanceStr("[") {
				repl.Reset(mark)
				return
			}
			pkgbase += "-"
		} else {
			return
		}
	}
}

type DependencyPattern struct {
	Pkgbase  string // "freeciv-client", "{gcc48,gcc48-libs}", "${EMACS_REQD}"
	LowerOp  string // ">=", ">"
	Lower    string // "2.5.0", "${PYVER}"
	UpperOp  string // "<", "<="
	Upper    string // "3.0", "${PYVER}"
	Wildcard string // "[0-9]*", "1.5.*", "${PYVER}"
}

func (p *Parser) Dependency() *DependencyPattern {
	repl := p.repl

	var dp DependencyPattern
	mark := repl.Mark()
	dp.Pkgbase = p.PkgbasePattern()
	if dp.Pkgbase == "" {
		return nil
	}

	mark2 := repl.Mark()
	if repl.AdvanceStr(">=") || repl.AdvanceStr(">") {
		op := repl.Str()
		if repl.AdvanceRegexp(`^(?:(?:\$\{\w+\})+|\d[\w.]*)`) {
			dp.LowerOp = op
			dp.Lower = repl.Str()
		} else {
			repl.Reset(mark2)
		}
	}
	if repl.AdvanceStr("<=") || repl.AdvanceStr("<") {
		op := repl.Str()
		if repl.AdvanceRegexp(`^(?:(?:\$\{\w+\})+|\d[\w.]*)`) {
			dp.UpperOp = op
			dp.Upper = repl.Str()
		} else {
			repl.Reset(mark2)
		}
	}
	if dp.LowerOp != "" || dp.UpperOp != "" {
		return &dp
	}
	if repl.AdvanceStr("-") && repl.Rest() != "" {
		dp.Wildcard = repl.AdvanceRest()
		return &dp
	}
	if hasPrefix(dp.Pkgbase, "${") && hasSuffix(dp.Pkgbase, "}") {
		return &dp
	}
	if hasSuffix(dp.Pkgbase, "-*") {
		dp.Pkgbase = strings.TrimSuffix(dp.Pkgbase, "-*")
		dp.Wildcard = "*"
		return &dp
	}

	repl.Reset(mark)
	return nil
}
