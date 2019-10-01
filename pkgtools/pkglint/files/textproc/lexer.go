package textproc

import (
	"fmt"
	"regexp"
	"strings"
)

// Lexer provides a flexible way of splitting a string into several parts
// by repeatedly chopping off a prefix that matches a string, a function
// or a set of byte values.
//
// The Next* methods chop off and return the matched portion.
//
// The Skip* methods chop off the matched portion and return whether something matched.
//
// PeekByte and TestByteSet look at the next byte without chopping it off.
// They are typically used in switch statements, which don't allow variable declarations.
type Lexer struct {
	rest string
}

// LexerMark remembers a position in the string being parsed, to be able
// to revert to that position, should a complex expression not match in
// its entirety.
type LexerMark string

// ByteSet is a subset of all 256 possible byte values.
// It is used for matching byte strings efficiently.
//
// It cannot match Unicode code points individually and is therefore
// usually used with ASCII characters.
type ByteSet struct {
	bits [256]bool
}

func NewLexer(text string) *Lexer {
	return &Lexer{text}
}

// Rest returns the part of the string that has not yet been chopped off.
func (l *Lexer) Rest() string { return l.rest }

// EOF returns whether the whole input has been consumed.
func (l *Lexer) EOF() bool { return l.rest == "" }

// PeekByte returns the next byte without chopping it off, or -1 at the end.
func (l *Lexer) PeekByte() int {
	if l.rest != "" {
		return int(l.rest[0])
	}
	return -1
}

// TestByteSet returns whether the remaining string starts with a byte
// from the given set.
func (l *Lexer) TestByteSet(set *ByteSet) bool {
	rest := l.rest
	return 0 < len(rest) && set.Contains(rest[0])
}

// Skip skips the next n bytes.
func (l *Lexer) Skip(n int) bool {
	l.rest = l.rest[n:]
	return n > 0
}

// NextString tests whether the remaining string has the given prefix,
// and if so, chops and returns it. Otherwise, returns the empty string.
func (l *Lexer) NextString(prefix string) string {
	if strings.HasPrefix(l.rest, prefix) {
		l.rest = l.rest[len(prefix):]
		return prefix
	}
	return ""
}

// SkipString skips over the given string, if the remaining string starts
// with it. It returns whether it actually skipped.
func (l *Lexer) SkipString(prefix string) bool {
	skipped := strings.HasPrefix(l.rest, prefix)
	if skipped {
		l.rest = l.rest[len(prefix):]
	}
	return skipped
}

// SkipHspace chops off the longest prefix (possibly empty) consisting
// solely of horizontal whitespace, which is the ASCII space (U+0020)
// and tab (U+0009).
func (l *Lexer) SkipHspace() bool {
	// Very similar code as in NextHspace, inlined here for performance reasons.
	// As of Go 1.11, the compiler does not inline a call to NextHspace here.
	i := 0
	rest := l.rest
	for i < len(rest) && (rest[i] == ' ' || rest[i] == '\t') {
		i++
	}
	if i > 0 {
		l.rest = rest[i:]
		return true
	}
	return false
}

// NextHspace chops off the longest prefix (possibly empty) consisting
// solely of horizontal whitespace, which is the ASCII space (U+0020)
// and tab (U+0009).
func (l *Lexer) NextHspace() string {
	// The same code as in NextBytesFunc, inlined here for performance reasons.
	// As of Go 1.11, the compiler does not inline constant function arguments.
	i := 0
	rest := l.rest
	for i < len(rest) && (rest[i] == ' ' || rest[i] == '\t') {
		i++
	}
	if i != 0 {
		l.rest = rest[i:]
	}
	return rest[:i]
}

// SkipByte returns true if the remaining string starts with the given byte,
// and in that case, chops it off.
func (l *Lexer) SkipByte(b byte) bool {
	if len(l.rest) > 0 && l.rest[0] == b {
		l.rest = l.rest[1:]
		return true
	}
	return false
}

// NextByte returns the next byte.
func (l *Lexer) NextByte() byte {
	b := l.rest[0]
	l.rest = l.rest[1:]
	return b
}

// NextBytesFunc chops off the longest prefix (possibly empty) consisting
// solely of bytes for which fn returns true.
func (l *Lexer) NextBytesFunc(fn func(b byte) bool) string {
	i := 0
	rest := l.rest
	for i < len(rest) && fn(rest[i]) {
		i++
	}
	if i != 0 {
		l.rest = rest[i:]
	}
	return rest[:i]
}

// NextByteSet chops off and returns the first byte if the set contains it,
// otherwise -1.
func (l *Lexer) NextByteSet(set *ByteSet) int {
	rest := l.rest
	if 0 < len(rest) && set.Contains(rest[0]) {
		l.rest = rest[1:]
		return int(rest[0])
	}
	return -1
}

// NextBytesSet chops off the longest prefix (possibly empty) consisting
// solely of bytes from the given set.
func (l *Lexer) NextBytesSet(bytes *ByteSet) string {
	// The same code as in NextBytesFunc, inlined here for performance reasons.
	// As of Go 1.11, the compiler does not inline variable function arguments.
	i := 0
	rest := l.rest
	for i < len(rest) && bytes.Contains(rest[i]) {
		i++
	}
	if i != 0 {
		l.rest = rest[i:]
	}
	return rest[:i]
}

// SkipRegexp returns true if the remaining string matches the given regular
// expression, and in that case, chops it off.
func (l *Lexer) SkipRegexp(re *regexp.Regexp) bool {
	if !strings.HasPrefix(re.String(), "^") {
		panic(fmt.Sprintf("Lexer.SkipRegexp: regular expression %q must have prefix %q.", re, "^"))
	}
	str := re.FindString(l.rest)
	if str != "" {
		l.Skip(len(str))
	}
	return str != ""
}

// NextRegexp tests whether the remaining string matches the given regular
// expression, and in that case, skips over it and returns the matched substrings,
// as in regexp.FindStringSubmatch.
// If the regular expression does not match, returns nil.
func (l *Lexer) NextRegexp(re *regexp.Regexp) []string {
	if !strings.HasPrefix(re.String(), "^") {
		panic(fmt.Sprintf("Lexer.NextRegexp: regular expression %q must have prefix %q.", re, "^"))
	}
	m := re.FindStringSubmatch(l.rest)
	if m != nil {
		l.Skip(len(m[0]))
	}
	return m
}

// Mark returns the current position of the lexer,
// which can later be restored by calling Reset.
func (l *Lexer) Mark() LexerMark {
	return LexerMark(l.rest)
}

// Reset sets the lexer back to the position where
// the corresponding Mark was called.
func (l *Lexer) Reset(mark LexerMark) {
	l.rest = string(mark)
}

// Since returns the text between the given mark and the current position.
func (l *Lexer) Since(mark LexerMark) string {
	return string(mark)[0 : len(mark)-len(l.rest)]
}

// Copy returns a copy of this lexer.
// It can be used to try one path of parsing and then either discard the
// result or commit it back by calling Commit.
func (l *Lexer) Copy() *Lexer { return &Lexer{l.rest} }

// Commit copies the state of the other lexer into this lexer.
// It always returns true so that it can be used in conditions.
func (l *Lexer) Commit(other *Lexer) bool { l.rest = other.rest; return true }

// NewByteSet creates a bit mask out of a string like "0-9A-Za-z_".
// To add an actual hyphen to the bit mask, write it as "---"
// (a range from hyphen to hyphen).
//
// The bit mask can be used with Lexer.NextBytesSet.
func NewByteSet(chars string) *ByteSet {
	var set ByteSet
	i := 0

	for i < len(chars) {
		switch {
		case i+2 < len(chars) && chars[i+1] == '-':
			min := uint(chars[i])
			max := uint(chars[i+2]) // inclusive
			for c := min; c <= max; c++ {
				set.bits[c] = true
			}
			i += 3
		default:
			set.bits[chars[i]] = true
			i++
		}
	}
	return &set
}

// Inverse returns a byte set that matches the inverted set of bytes.
func (bs *ByteSet) Inverse() *ByteSet {
	var inv ByteSet
	for i := 0; i < 256; i++ {
		inv.bits[i] = !bs.Contains(byte(i))
	}
	return &inv
}

// Contains tests whether the byte set contains the given byte.
func (bs *ByteSet) Contains(b byte) bool { return bs.bits[b] }

// Predefined byte sets for parsing ASCII text.
var (
	Alnum  = NewByteSet("A-Za-z0-9")  // Alphanumerical, without underscore
	AlnumU = NewByteSet("A-Za-z0-9_") // Alphanumerical, including underscore
	Alpha  = NewByteSet("A-Za-z")     // Alphabetical, without underscore
	Digit  = NewByteSet("0-9")        // The digits zero to nine
	Upper  = NewByteSet("A-Z")        // The uppercase letters from A to Z
	Lower  = NewByteSet("a-z")        // The lowercase letters from a to z
	Space  = NewByteSet("\t\n ")      // Tab, newline, space
	Hspace = NewByteSet("\t ")        // Tab, space
	XPrint = NewByteSet("\n\t -~")    // Printable ASCII, plus tab and newline
)
