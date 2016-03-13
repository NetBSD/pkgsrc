package main

import (
	"strings"
)

type Parser struct {
	line *Line
	repl *PrefixReplacer
}

func NewParser(line *Line, s string) *Parser {
	return &Parser{line, NewPrefixReplacer(s)}
}

func (p *Parser) EOF() bool {
	return p.repl.rest == ""
}

func (p *Parser) Rest() string {
	return p.repl.rest
}

func (p *Parser) PkgbasePattern() (pkgbase string) {
	repl := p.repl

	for {
		if repl.AdvanceRegexp(`^\$\{\w+\}`) ||
			repl.AdvanceRegexp(`^[\w.*+,{}]+`) ||
			repl.AdvanceRegexp(`^\[[\d-]+\]`) {
			pkgbase += repl.m[0]
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

func (p *Parser) Dependency() *DependencyPattern {
	repl := p.repl

	var dp DependencyPattern
	mark := repl.Mark()
	dp.pkgbase = p.PkgbasePattern()
	if dp.pkgbase == "" {
		return nil
	}

	mark2 := repl.Mark()
	if repl.AdvanceStr(">=") || repl.AdvanceStr(">") {
		op := repl.s
		if repl.AdvanceRegexp(`^(?:(?:\$\{\w+\})+|\d[\w.]*)`) {
			dp.lowerOp = op
			dp.lower = repl.m[0]
		} else {
			repl.Reset(mark2)
		}
	}
	if repl.AdvanceStr("<=") || repl.AdvanceStr("<") {
		op := repl.s
		if repl.AdvanceRegexp(`^(?:(?:\$\{\w+\})+|\d[\w.]*)`) {
			dp.upperOp = op
			dp.upper = repl.m[0]
		} else {
			repl.Reset(mark2)
		}
	}
	if dp.lowerOp != "" || dp.upperOp != "" {
		return &dp
	}
	if repl.AdvanceStr("-") && repl.rest != "" {
		dp.wildcard = repl.AdvanceRest()
		return &dp
	}
	if hasPrefix(dp.pkgbase, "${") && hasSuffix(dp.pkgbase, "}") {
		return &dp
	}
	if hasSuffix(dp.pkgbase, "-*") {
		dp.pkgbase = strings.TrimSuffix(dp.pkgbase, "-*")
		dp.wildcard = "*"
		return &dp
	}

	repl.Reset(mark)
	return nil
}

type MkToken struct {
	literal string
	varuse  MkVarUse
}
type MkVarUse struct {
	varname   string
	modifiers []string
}

func (p *Parser) MkTokens() []*MkToken {
	repl := p.repl

	var tokens []*MkToken
	for !p.EOF() {
		if varuse := p.VarUse(); varuse != nil {
			tokens = append(tokens, &MkToken{varuse: *varuse})
			continue
		}

		mark := repl.Mark()
		needsReplace := false
	again:
		dollar := strings.IndexByte(repl.rest, '$')
		if dollar == -1 {
			dollar = len(repl.rest)
		}
		repl.Skip(dollar)
		if repl.AdvanceStr("$$") {
			needsReplace = true
			goto again
		}
		literal := repl.Since(mark)
		if needsReplace {
			literal = strings.Replace(literal, "$$", "$", -1)
		}
		if literal != "" {
			tokens = append(tokens, &MkToken{literal: literal})
			continue
		}

		break
	}
	return tokens
}

func (p *Parser) Varname() string {
	repl := p.repl

	mark := repl.Mark()
	repl.AdvanceStr(".")
	for p.VarUse() != nil || repl.AdvanceBytes(0x00000000, 0x03ff6800, 0x87fffffe, 0x07fffffe, `[\w+\-.]`) {
	}
	return repl.Since(mark)
}

func (p *Parser) VarUse() *MkVarUse {
	repl := p.repl

	mark := repl.Mark()
	if repl.AdvanceStr("${") || repl.AdvanceStr("$(") {
		usingRoundParen := repl.Since(mark) == "$("
		closing := ifelseStr(usingRoundParen, ")", "}")

		varnameMark := repl.Mark()
		varname := p.Varname()
		if varname != "" {
			if usingRoundParen {
				p.line.Warn1("Please use curly braces {} instead of round parentheses () for %s.", varname)
			}
			modifiers := p.VarUseModifiers(varname, closing)
			if repl.AdvanceStr(closing) {
				return &MkVarUse{varname, modifiers}
			}
		}

		for p.VarUse() != nil || repl.AdvanceRegexp(`^([^$:`+closing+`]|\$\$)+`) {
		}
		rest := p.Rest()
		if hasPrefix(rest, ":L") || hasPrefix(rest, ":sh") || hasPrefix(rest, ":?") {
			varexpr := repl.Since(varnameMark)
			modifiers := p.VarUseModifiers(varexpr, closing)
			if repl.AdvanceStr(closing) {
				return &MkVarUse{varexpr, modifiers}
			}
		}
		repl.Reset(mark)
	}

	return nil
}

func (p *Parser) VarUseModifiers(varname, closing string) []string {
	repl := p.repl

	var modifiers []string
	mayOmitColon := false
	for repl.AdvanceStr(":") || mayOmitColon {
		mayOmitColon = false
		modifierMark := repl.Mark()

		switch repl.PeekByte() {
		case 'E', 'H', 'L', 'O', 'Q', 'R', 'T', 's', 't', 'u':
			if repl.AdvanceRegexp(`^(E|H|L|Ox?|Q|R|T|sh|tA|tW|tl|tu|tw|u)`) {
				modifiers = append(modifiers, repl.Since(modifierMark))
				continue
			}
			if repl.AdvanceStr("ts") {
				rest := repl.rest
				if len(rest) >= 2 && (rest[1] == closing[0] || rest[1] == ':') {
					repl.Skip(1)
				} else if len(rest) >= 1 && (rest[0] == closing[0] || rest[0] == ':') {
				} else if repl.AdvanceRegexp(`^\\\d+`) {
				} else {
					break
				}
				modifiers = append(modifiers, repl.Since(modifierMark))
				continue
			}

		case '=', 'D', 'M', 'N', 'U':
			if repl.AdvanceRegexp(`^[=DMNU]`) {
				for p.VarUse() != nil || repl.AdvanceRegexp(`^([^$:`+closing+`]|\$\$)+`) {
				}
				modifiers = append(modifiers, repl.Since(modifierMark))
				continue
			}

		case 'C', 'S':
			if repl.AdvanceRegexp(`^[CS]([%,/:;@^|])`) {
				separator := repl.m[1]
				repl.AdvanceStr("^")
				re := `^([^\` + separator + `$` + closing + `\\]|\$\$|\\.)+`
				for p.VarUse() != nil || repl.AdvanceRegexp(re) {
				}
				repl.AdvanceStr("$")
				if repl.AdvanceStr(separator) {
					for p.VarUse() != nil || repl.AdvanceRegexp(re) {
					}
					if repl.AdvanceStr(separator) {
						repl.AdvanceRegexp(`^[1gW]`)
						modifiers = append(modifiers, repl.Since(modifierMark))
						mayOmitColon = true
						continue
					}
				}
			}

		case '@':
			if repl.AdvanceRegexp(`^@([\w.]+)@`) {
				loopvar := repl.m[1]
				for p.VarUse() != nil || repl.AdvanceRegexp(`^([^$:@`+closing+`\\]|\$\$|\\.)+`) {
				}
				if !repl.AdvanceStr("@") {
					p.line.Warn2("Modifier ${%s:@%s@...@} is missing the final \"@\".", varname, loopvar)
				}
				modifiers = append(modifiers, repl.Since(modifierMark))
				continue
			}

		case '[':
			if repl.AdvanceRegexp(`^\[[-.\d]+\]`) {
				modifiers = append(modifiers, repl.Since(modifierMark))
				continue
			}

		case '?':
			repl.AdvanceStr("?")
			re := `^([^$:` + closing + `]|\$\$)+`
			for p.VarUse() != nil || repl.AdvanceRegexp(re) {
			}
			if repl.AdvanceStr(":") {
				for p.VarUse() != nil || repl.AdvanceRegexp(re) {
				}
				modifiers = append(modifiers, repl.Since(modifierMark))
				continue
			}
		}

		repl.Reset(modifierMark)
		for p.VarUse() != nil || repl.AdvanceRegexp(`^([^:$`+closing+`]|\$\$)+`) {
		}
		if suffixSubst := repl.Since(modifierMark); contains(suffixSubst, "=") {
			modifiers = append(modifiers, suffixSubst)
			continue
		}
	}
	return modifiers
}

func (p *Parser) MkCond() *Tree {
	return p.mkCondOr()
}

func (p *Parser) mkCondOr() *Tree {
	and := p.mkCondAnd()
	if and == nil {
		return nil
	}

	ands := append([]interface{}(nil), and)
	for {
		mark := p.repl.Mark()
		if !p.repl.AdvanceRegexp(`^\s*\|\|\s*`) {
			break
		}
		next := p.mkCondAnd()
		if next == nil {
			p.repl.Reset(mark)
			break
		}
		ands = append(ands, next)
	}
	if len(ands) == 1 {
		return and
	}
	return NewTree("or", ands...)
}

func (p *Parser) mkCondAnd() *Tree {
	atom := p.mkCondAtom()
	if atom == nil {
		return nil
	}

	atoms := append([]interface{}(nil), atom)
	for {
		mark := p.repl.Mark()
		if !p.repl.AdvanceRegexp(`^\s*&&\s*`) {
			break
		}
		next := p.mkCondAtom()
		if next == nil {
			p.repl.Reset(mark)
			break
		}
		atoms = append(atoms, next)
	}
	if len(atoms) == 1 {
		return atom
	}
	return NewTree("and", atoms...)
}

func (p *Parser) mkCondAtom() *Tree {
	if G.opts.DebugTrace {
		defer tracecall1(p.Rest())()
	}

	repl := p.repl
	mark := repl.Mark()
	repl.SkipSpace()
	switch {
	case repl.AdvanceStr("!"):
		cond := p.mkCondAtom()
		if cond != nil {
			return NewTree("not", cond)
		}
	case repl.AdvanceStr("("):
		cond := p.MkCond()
		if cond != nil {
			repl.SkipSpace()
			if repl.AdvanceStr(")") {
				return cond
			}
		}
	case repl.AdvanceRegexp(`^defined\s*\(`):
		if varname := p.Varname(); varname != "" {
			if repl.AdvanceStr(")") {
				return NewTree("defined", varname)
			}
		}
	case repl.AdvanceRegexp(`^empty\s*\(`):
		if varname := p.Varname(); varname != "" {
			modifiers := p.VarUseModifiers(varname, ")")
			if repl.AdvanceStr(")") {
				return NewTree("empty", MkVarUse{varname, modifiers})
			}
		}
	case repl.AdvanceRegexp(`^(commands|exists|make|target)\s*\(`):
		funcname := repl.m[1]
		argMark := repl.Mark()
		for p.VarUse() != nil || repl.AdvanceRegexp(`^[^$)]+`) {
		}
		arg := repl.Since(argMark)
		if repl.AdvanceStr(")") {
			return NewTree(funcname, arg)
		}
	default:
		lhs := p.VarUse()
		mark := repl.Mark()
		if lhs == nil && repl.AdvanceStr("\"") {
			if quotedLhs := p.VarUse(); quotedLhs != nil && repl.AdvanceStr("\"") {
				lhs = quotedLhs
			} else {
				repl.Reset(mark)
			}
		}
		if lhs != nil {
			if repl.AdvanceRegexp(`^\s*(<|<=|==|!=|>=|>)\s*(\d+(?:\.\d+)?)`) {
				return NewTree("compareVarNum", *lhs, repl.m[1], repl.m[2])
			}
			if repl.AdvanceRegexp(`^\s*(<|<=|==|!=|>=|>)\s*`) {
				op := repl.m[1]
				if (op == "!=" || op == "==") && repl.AdvanceRegexp(`^"([^"\$\\]*)"`) {
					return NewTree("compareVarStr", *lhs, op, repl.m[1])
				} else if repl.AdvanceRegexp(`^\w+`) {
					return NewTree("compareVarStr", *lhs, op, repl.m[0])
				} else if rhs := p.VarUse(); rhs != nil {
					return NewTree("compareVarVar", *lhs, op, *rhs)
				}
			} else {
				return NewTree("not", NewTree("empty", *lhs)) // See devel/bmake/files/cond.c:/\* For \.if \$/
			}
		}
		if repl.AdvanceRegexp(`^\d+(?:\.\d+)?`) {
			return NewTree("literalNum", repl.m[0])
		}
	}
	repl.Reset(mark)
	return nil
}
