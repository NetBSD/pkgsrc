package pkglint

import (
	"netbsd.org/pkglint/textproc"
	"strings"
)

type Parser struct {
	Line         Line
	lexer        *textproc.Lexer
	EmitWarnings bool
}

func NewParser(line Line, s string, emitWarnings bool) *Parser {
	return &Parser{line, textproc.NewLexer(s), emitWarnings}
}

func (p *Parser) EOF() bool {
	return p.lexer.EOF()
}

func (p *Parser) Rest() string {
	return p.lexer.Rest()
}

func (p *Parser) PkgbasePattern() (pkgbase string) {
	lexer := p.lexer

	for {
		mark := lexer.Mark()

		if lexer.SkipRegexp(G.res.Compile(`^\$\{\w+\}`)) ||
			lexer.SkipRegexp(G.res.Compile(`^[\w.*+,{}]+`)) ||
			lexer.SkipRegexp(G.res.Compile(`^\[[\d-]+\]`)) {
			pkgbase += lexer.Since(mark)
			continue
		}

		if lexer.SkipByte('-') {
			if lexer.SkipRegexp(G.res.Compile(`^\d`)) ||
				lexer.SkipRegexp(G.res.Compile(`^\$\{\w*VER\w*\}`)) ||
				lexer.SkipByte('[') {
				lexer.Reset(mark)
				return
			}
			pkgbase += "-"
			continue
		}

		lexer.Reset(mark)
		return
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
	lexer := p.lexer

	var dp DependencyPattern
	mark := lexer.Mark()
	dp.Pkgbase = p.PkgbasePattern()
	if dp.Pkgbase == "" {
		return nil
	}

	mark2 := lexer.Mark()
	op := lexer.NextString(">=")
	if op == "" {
		op = lexer.NextString(">")
	}
	if op != "" {
		if m := lexer.NextRegexp(G.res.Compile(`^(?:(?:\$\{\w+\})+|\d[\w.]*)`)); m != nil {
			dp.LowerOp = op
			dp.Lower = m[0]
		} else {
			lexer.Reset(mark2)
		}
	}

	op = lexer.NextString("<=")
	if op == "" {
		op = lexer.NextString("<")
	}
	if op != "" {
		if m := lexer.NextRegexp(G.res.Compile(`^(?:(?:\$\{\w+\})+|\d[\w.]*)`)); m != nil {
			dp.UpperOp = op
			dp.Upper = m[0]
		} else {
			lexer.Reset(mark2)
		}
	}

	if dp.LowerOp != "" || dp.UpperOp != "" {
		return &dp
	}

	if lexer.SkipByte('-') && lexer.Rest() != "" {
		dp.Wildcard = lexer.Rest()
		lexer.Skip(len(lexer.Rest()))
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

	lexer.Reset(mark)
	return nil
}
