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
	var a Pattern
	s := a.AddState(false)

	var deadEnd StateID

	lex := textproc.NewLexer(pattern)
	for !lex.EOF() {

		if lex.SkipByte('*') {
			a.AddTransition(s, 0, 255, s)
			continue
		}

		if lex.SkipByte('?') {
			next := a.AddState(false)
			a.AddTransition(s, 0, 255, next)
			s = next
			continue
		}

		if lex.SkipByte('\\') {
			if lex.EOF() {
				return nil, errors.New("unfinished escape sequence")
			}
			ch := lex.NextByte()
			next := a.AddState(false)
			a.AddTransition(s, ch, ch, next)
			s = next
			continue
		}

		ch := lex.NextByte()
		if ch != '[' {
			next := a.AddState(false)
			a.AddTransition(s, ch, ch, next)
			s = next
			continue
		}

		negate := lex.SkipByte('^')
		if negate && deadEnd == 0 {
			deadEnd = a.AddState(false)
		}
		next := a.AddState(false)
		for {
			if lex.EOF() {
				return nil, errors.New("unfinished character class")
			}
			ch = lex.NextByte()
			if ch == ']' {
				break
			}
			max := ch
			if lex.SkipByte('-') {
				if lex.EOF() {
					return nil, errors.New("unfinished character range")
				}
				max = lex.NextByte()
			}

			to := next
			if negate {
				to = deadEnd
			}
			a.AddTransition(s, bmin(ch, max), bmax(ch, max), to)
		}
		if negate {
			a.AddTransition(s, 0, 255, next)
		}
		s = next
	}

	a.states[s].end = true
	return &a, nil
}

func (a *Pattern) AddState(end bool) StateID {
	a.states = append(a.states, state{nil, end})
	return StateID(len(a.states) - 1)
}

func (a *Pattern) AddTransition(from StateID, min, max byte, to StateID) {
	state := &a.states[from]
	state.transitions = append(state.transitions, transition{min, max, to})
}

// Match tests whether a pattern matches the given string.
func (a *Pattern) Match(s string) bool {
	state := StateID(0)
	for _, ch := range []byte(s) {
		for _, tr := range a.states[state].transitions {
			if tr.min <= ch && ch <= tr.max {
				state = tr.to
				goto nextByte
			}
		}
		return false
	nextByte:
	}
	return a.states[state].end
}

// Intersect computes a pattern that only matches if both given patterns
// match at the same time.
func Intersect(a, b *Pattern) *Pattern {
	var is Pattern
	for i := 0; i < len(a.states); i++ {
		for j := 0; j < len(b.states); j++ {
			is.AddState(a.states[i].end && b.states[j].end)
		}
	}

	for i := 0; i < len(a.states); i++ {
		for j := 0; j < len(b.states); j++ {
			for _, at := range a.states[i].transitions {
				for _, bt := range b.states[j].transitions {
					min := bmax(at.min, bt.min)
					max := bmin(at.max, bt.max)
					if min <= max {
						from := StateID(i*len(b.states) + j)
						to := at.to*StateID(len(b.states)) + bt.to
						is.AddTransition(from, min, max, to)
					}
				}
			}
		}
	}

	// TODO: optimize: remove transitions that point to a dead end

	return &is
}

// CanMatch tests whether the pattern can match some string.
// Most patterns can do that.
// Typical counterexamples are:
//  [^]
//  Intersect("*.c", "*.h")
func (a *Pattern) CanMatch() bool {
	reachable := make([]bool, len(a.states))
	reachable[0] = true

again:
	changed := false
	for i, s := range a.states {
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

	for i, s := range a.states {
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
