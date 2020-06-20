package makepat

import (
	"errors"
	"netbsd.org/pkglint/textproc"
)

// Pattern is a compiled pattern like "*.c" or "NetBSD-??.[^0-9]".
// It behaves exactly like in bmake,
// see devel/bmake/files/str.c, function Str_Match.
type Pattern struct {
	states []state
}

type state struct {
	transitions []transition
	end         bool
}

type transition struct {
	min, max byte
	to       StateID
}

type StateID uint16

// Compile parses a pattern, including the error checking that is missing
// from bmake.
func Compile(pattern string) (*Pattern, error) {
	var p Pattern
	s := p.AddState(false)

	lex := textproc.NewLexer(pattern)
	for !lex.EOF() {

		if lex.SkipByte('*') {
			p.AddTransition(s, 0, 255, s)
			continue
		}

		if lex.SkipByte('?') {
			next := p.AddState(false)
			p.AddTransition(s, 0, 255, next)
			s = next
			continue
		}

		if lex.SkipByte('\\') {
			if lex.EOF() {
				return nil, errors.New("unfinished escape sequence")
			}
			ch := lex.NextByte()
			next := p.AddState(false)
			p.AddTransition(s, ch, ch, next)
			s = next
			continue
		}

		ch := lex.NextByte()
		if ch != '[' {
			next := p.AddState(false)
			p.AddTransition(s, ch, ch, next)
			s = next
			continue
		}

		next, err := compileCharClass(&p, lex, ch, s)
		if err != nil {
			return nil, err
		}

		s = next
	}

	p.states[s].end = true
	return &p, nil
}

func compileCharClass(p *Pattern, lex *textproc.Lexer, ch byte, s StateID) (StateID, error) {
	negate := lex.SkipByte('^')
	chars := make([]bool, 256)
	next := p.AddState(false)
	for {
		if lex.EOF() {
			return 0, errors.New("unfinished character class")
		}
		ch = lex.NextByte()
		if ch == ']' {
			break
		}
		if lex.SkipByte('-') {
			if lex.EOF() {
				return 0, errors.New("unfinished character range")
			}
			max := lex.NextByte()
			if ch > max {
				ch, max = max, ch
			}
			for i := int(ch); i <= int(max); i++ {
				chars[i] = true
			}
		} else {
			chars[ch] = true
		}
	}
	if negate {
		for i, b := range chars {
			chars[i] = !b
		}
	}

	start := 0
	for start < len(chars) && !chars[start] {
		start++
	}

	for start < len(chars) {
		end := start
		for end < len(chars) && chars[end] {
			end++
		}

		if start < end {
			p.AddTransition(s, byte(start), byte(end-1), next)
		}

		start = end
		for start < len(chars) && !chars[start] {
			start++
		}
	}
	return next, nil
}

func (p *Pattern) AddState(end bool) StateID {
	p.states = append(p.states, state{nil, end})
	return StateID(len(p.states) - 1)
}

func (p *Pattern) AddTransition(from StateID, min, max byte, to StateID) {
	state := &p.states[from]
	state.transitions = append(state.transitions, transition{min, max, to})
}

// Match tests whether a pattern matches the given string.
func (p *Pattern) Match(s string) bool {
	curr := make([]bool, len(p.states))
	next := make([]bool, len(p.states))

	curr[0] = true
	for _, ch := range []byte(s) {
		ok := false
		for i, _ := range next {
			next[i] = false
		}

		for si := range curr {
			if !curr[si] {
				continue
			}
			for _, tr := range p.states[si].transitions {
				if tr.min <= ch && ch <= tr.max {
					next[tr.to] = true
					ok = true
				}
			}
		}
		if !ok {
			return false
		}
		curr, next = next, curr
	}

	for i, curr := range curr {
		if curr && p.states[i].end {
			return true
		}
	}
	return false
}

// Intersect computes a pattern that only matches if both given patterns
// match at the same time.
func Intersect(p1, p2 *Pattern) *Pattern {
	var res Pattern
	for i1 := 0; i1 < len(p1.states); i1++ {
		for i2 := 0; i2 < len(p2.states); i2++ {
			res.AddState(p1.states[i1].end && p2.states[i2].end)
		}
	}

	for i1 := 0; i1 < len(p1.states); i1++ {
		for i2 := 0; i2 < len(p2.states); i2++ {
			for _, t1 := range p1.states[i1].transitions {
				for _, t2 := range p2.states[i2].transitions {
					min := bmax(t1.min, t2.min)
					max := bmin(t1.max, t2.max)
					if min <= max {
						from := StateID(i1*len(p2.states) + i2)
						to := t1.to*StateID(len(p2.states)) + t2.to
						res.AddTransition(from, min, max, to)
					}
				}
			}
		}
	}

	return res.optimized()
}

func (p *Pattern) optimized() *Pattern {
	var opt Pattern

	var todo []StateID
	hasNewID := make([]bool, len(p.states))
	newIDs := make([]StateID, len(p.states))

	todo = append(todo, 0)
	newIDs[0] = opt.AddState(p.states[0].end)
	hasNewID[0] = true

	for len(todo) > 0 {
		oldStateID := todo[len(todo)-1]
		todo = todo[:len(todo)-1]

		oldState := p.states[oldStateID]

		for _, t := range oldState.transitions {
			if !hasNewID[t.to] {
				hasNewID[t.to] = true
				newIDs[t.to] = opt.AddState(p.states[t.to].end)
				todo = append(todo, t.to)
			}
			opt.AddTransition(newIDs[oldStateID], t.min, t.max, newIDs[t.to])
		}
	}

	// TODO: remove transitions that point to a dead end

	return &opt
}

// CanMatch tests whether the pattern can match some string.
// Most patterns can do that.
// Typical counterexamples are:
//  [^]
//  Intersect("*.c", "*.h")
func (p *Pattern) CanMatch() bool {
	reachable := make([]bool, len(p.states))
	reachable[0] = true

again:
	changed := false
	for i, s := range p.states {
		if reachable[i] {
			for _, t := range s.transitions {
				if !reachable[t.to] {
					reachable[t.to] = true
					changed = true
				}
			}
		}
	}
	if changed {
		goto again
	}

	for i, s := range p.states {
		if reachable[i] && s.end {
			return true
		}
	}
	return false
}

func bmin(a, b byte) byte {
	if a < b {
		return a
	}
	return b
}

func bmax(a, b byte) byte {
	if a > b {
		return a
	}
	return b
}
