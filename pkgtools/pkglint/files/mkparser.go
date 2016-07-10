package main

import (
	"strings"
)

type MkParser struct {
	*Parser
}

func NewMkParser(line *Line, text string, emitWarnings bool) *MkParser {
	return &MkParser{NewParser(line, text, emitWarnings)}
}

func (p *MkParser) MkTokens() []*MkToken {
	repl := p.repl

	var tokens []*MkToken
	for !p.EOF() {
		if repl.AdvanceStr("#") {
			repl.AdvanceRest()
		}

		mark := repl.Mark()
		if varuse := p.VarUse(); varuse != nil {
			tokens = append(tokens, &MkToken{Text: repl.Since(mark), Varuse: varuse})
			continue
		}

	again:
		dollar := strings.IndexByte(repl.rest, '$')
		if dollar == -1 {
			dollar = len(repl.rest)
		}
		repl.Skip(dollar)
		if repl.AdvanceStr("$$") {
			goto again
		}
		text := repl.Since(mark)
		if text != "" {
			tokens = append(tokens, &MkToken{Text: text})
			continue
		}

		break
	}
	return tokens
}

func (p *MkParser) VarUse() *MkVarUse {
	repl := p.repl

	mark := repl.Mark()
	if repl.AdvanceStr("${") || repl.AdvanceStr("$(") {
		usingRoundParen := repl.Since(mark) == "$("
		closing := ifelseStr(usingRoundParen, ")", "}")

		varnameMark := repl.Mark()
		varname := p.Varname()
		if varname != "" {
			if usingRoundParen && p.EmitWarnings {
				p.Line.Warn1("Please use curly braces {} instead of round parentheses () for %s.", varname)
			}
			modifiers := p.VarUseModifiers(varname, closing)
			if repl.AdvanceStr(closing) {
				return &MkVarUse{varname, modifiers}
			}
		}

		for p.VarUse() != nil || repl.AdvanceRegexp(RegexPattern(`^([^$:`+closing+`]|\$\$)+`)) {
		}
		rest := p.Rest()
		if hasPrefix(rest, ":L") || hasPrefix(rest, ":?") {
			varexpr := repl.Since(varnameMark)
			modifiers := p.VarUseModifiers(varexpr, closing)
			if repl.AdvanceStr(closing) {
				return &MkVarUse{varexpr, modifiers}
			}
		}
		repl.Reset(mark)
	}

	if repl.AdvanceStr("$@") {
		return &MkVarUse{"@", nil}
	}
	if repl.AdvanceStr("$<") {
		return &MkVarUse{"<", nil}
	}
	if repl.PeekByte() == '$' && repl.AdvanceRegexp(`^\$(\w)`) {
		varname := repl.m[1]
		if p.EmitWarnings {
			p.Line.Warn1("$%[1]s is ambiguous. Use ${%[1]s} if you mean a Makefile variable or $$%[1]s if you mean a shell variable.", varname)
		}
		return &MkVarUse{varname, nil}
	}
	return nil
}

func (p *MkParser) VarUseModifiers(varname, closing string) []string {
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
				for p.VarUse() != nil || repl.AdvanceRegexp(RegexPattern(`^([^$:`+closing+`]|\$\$)+`)) {
				}
				modifiers = append(modifiers, repl.Since(modifierMark))
				continue
			}

		case 'C', 'S':
			if repl.AdvanceRegexp(`^[CS]([%,/:;@^|])`) {
				separator := repl.m[1]
				repl.AdvanceStr("^")
				re := RegexPattern(`^([^\` + separator + `$` + closing + `\\]|\$\$|\\.)+`)
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
				for p.VarUse() != nil || repl.AdvanceRegexp(RegexPattern(`^([^$:@`+closing+`\\]|\$\$|\\.)+`)) {
				}
				if !repl.AdvanceStr("@") && p.EmitWarnings {
					p.Line.Warn2("Modifier ${%s:@%s@...@} is missing the final \"@\".", varname, loopvar)
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
			re := RegexPattern(`^([^$:` + closing + `]|\$\$)+`)
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
		for p.VarUse() != nil || repl.AdvanceRegexp(RegexPattern(`^([^:$`+closing+`]|\$\$)+`)) {
		}
		if suffixSubst := repl.Since(modifierMark); contains(suffixSubst, "=") {
			modifiers = append(modifiers, suffixSubst)
			continue
		}
	}
	return modifiers
}

func (p *MkParser) MkCond() *Tree {
	return p.mkCondOr()
}

func (p *MkParser) mkCondOr() *Tree {
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

func (p *MkParser) mkCondAnd() *Tree {
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

func (p *MkParser) mkCondAtom() *Tree {
	if G.opts.Debug {
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
			if quotedLHS := p.VarUse(); quotedLHS != nil && repl.AdvanceStr("\"") {
				lhs = quotedLHS
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
				} else if repl.PeekByte() == '"' {
					mark := repl.Mark()
					if repl.AdvanceStr("\"") {
						if quotedRHS := p.VarUse(); quotedRHS != nil {
							if repl.AdvanceStr("\"") {
								return NewTree("compareVarVar", *lhs, op, *quotedRHS)
							}
						}
					}
					repl.Reset(mark)
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

func (p *MkParser) Varname() string {
	repl := p.repl

	mark := repl.Mark()
	repl.AdvanceStr(".")
	isVarnameChar := func(c byte) bool {
		return 'A' <= c && c <= 'Z' || c == '_' || 'a' <= c && c <= 'z' || '0' <= c && c <= '9' || c == '+' || c == '-' || c == '.' || c == '*'
	}
	for p.VarUse() != nil || repl.AdvanceBytesFunc(isVarnameChar) {
	}
	return repl.Since(mark)
}
