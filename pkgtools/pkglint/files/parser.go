package main

import (
	"strings"
)

type Parser struct {
	repl *PrefixReplacer
}

func NewParser(s string) *Parser {
	return &Parser{NewPrefixReplacer(s)}
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
		closing := "}"
		if repl.Since(mark) == "$(" {
			closing = ")"
		}

		varnameMark := repl.Mark()
		varname := p.Varname()
		if varname != "" {
			modifiers := p.VarUseModifiers(closing)
			if repl.AdvanceStr(closing) {
				return &MkVarUse{varname, modifiers}
			}
		}

		for p.VarUse() != nil || repl.AdvanceRegexp(`^([^$:`+closing+`]|\$\$)+`) {
		}
		rest := p.Rest()
		if hasPrefix(rest, ":L") || hasPrefix(rest, ":sh") || hasPrefix(rest, ":?") {
			varexpr := repl.Since(varnameMark)
			modifiers := p.VarUseModifiers(closing)
			if repl.AdvanceStr(closing) {
				return &MkVarUse{varexpr, modifiers}
			}
		}
		repl.Reset(mark)
	}

	return nil
}

func (p *Parser) VarUseModifiers(closing string) []string {
	repl := p.repl

	var modifiers []string
	for repl.AdvanceStr(":") {
		modifierMark := repl.Mark()

		switch repl.PeekByte() {
		case 'E', 'H', 'L', 'O', 'Q', 'R', 'T', 's', 't', 'u':
			if repl.AdvanceRegexp(`^(E|H|L|Ox?|Q|R|T|sh|tA|tW|tl|ts.|tu|tw|u)`) {
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
						continue
					}
				}
			}

		case '@':
			if repl.AdvanceRegexp(`^@([\w.]+)@`) {
				for p.VarUse() != nil || repl.AdvanceRegexp(`^([^$:@`+closing+`\\]|\$\$|\\.)+`) {
				}
				if repl.AdvanceStr("@") {
					modifiers = append(modifiers, repl.Since(modifierMark))
					continue
				}
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
