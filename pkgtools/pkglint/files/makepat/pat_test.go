package makepat

import (
	"testing"
)

func Test_Automaton_Match(t *testing.T) {
	tests := []struct {
		pattern string
		str     string
		want    bool
	}{
		{"a-[0-9]*", "", false},
		{"a-[0-9]*", "a", false},
		{"a-[0-9]*", "b", false},
		{"a-[0-9]*", "a-", false},
		{"a-[0-9]*", "a-0", true},
		{"a-[0-9]*", "a-13", true},
		{"a-[0-9]*", "a-3* matches arbitrary text", true},
		{"a-[0-9]*", "a+", false},
		{"a-[0-9]*", "a-x", false},
		{"\\a", "a", true},
		{"\\a", "\\a", false},
		{"\\a", "\u0007", false},
		{"?", "", false},
		{"?", "x", true},
		{"?", "?", true},
		{"?", "xy", false},
		{"a?", "ax", true},
		{"a?", "xa", false},
		{"[0-9]", "", false},
		{"[0-9]", "55", false},
		{"[0-9]", "/", false},
		{"[0-9]", "0", true},
		{"[0-9]", "5", true},
		{"[0-9]", "9", true},
		{"[0-9]", ":", false},
		{"[^0-9]", "", false},
		{"[^0-9]", "55", false},
		{"[^0-9]", "/", true},
		{"[^0-9]", "0", false},
		{"[^0-9]", "5", false},
		{"[^0-9]", "9", false},
		{"[^0-9]", ":", true},
		{"[^0-9][^a-z]", "a0", true},
		{"[^0-9][^a-z]", "aa", false},
		{"[0-9A-Za-z]", "/", false},
		{"[0-9A-Za-z]", "0", true},
		{"[0-9A-Za-z]", "9", true},
		{"[0-9A-Za-z]", ":", false},
		{"[0-9A-Za-z]", "@", false},
		{"[0-9A-Za-z]", "A", true},
		{"[0-9A-Za-z]", "Z", true},
		{"[0-9A-Za-z]", "[", false},
		{"[0-9A-Za-z]", "`", false},
		{"[0-9A-Za-z]", "a", true},
		{"[0-9A-Za-z]", "z", true},
		{"[0-9A-Za-z]", "{", false},
		{"[\\-]]", "{", false},
		{"[\\-]]", "\\", true},
		{"[\\-]]", "]", true},
		{"[\\-]]", "^", false},
		{"[9-0]", "", false},
		{"[9-0]", "55", false},
		{"[9-0]", "/", false},
		{"[9-0]", "0", true},
		{"[9-0]", "5", true},
		{"[9-0]", "9", true},
		{"[9-0]", ":", false},
	}
	for _, tt := range tests {
		t.Run(tt.pattern+" "+tt.str, func(t *testing.T) {
			a, err := Compile(tt.pattern)
			if err != nil {
				t.Fatal(err)
			}
			if got := a.Match(tt.str); got != tt.want {
				t.Errorf("Match() = %v, want %v", got, tt.want)
			}
		})
	}
}

func Test_Automaton_Compile__errors(t *testing.T) {
	tests := []struct {
		pattern string
		msg     string
	}{
		{"\\", "unfinished escape sequence"},
		{"[", "unfinished character class"},
		{"[a-", "unfinished character range"},
		{"[\\", "unfinished character class"},
	}
	for _, tt := range tests {
		t.Run(tt.pattern, func(t *testing.T) {
			_, err := Compile(tt.pattern)
			if err == nil {
				t.Fail()
			} else if err.Error() != tt.msg {
				t.Errorf("err = %v, want %v", err, tt.msg)
			}
		})
	}
}

func Test_Intersect(t *testing.T) {
	tests := []struct {
		pattern1 string
		pattern2 string
		str      string
		matches  bool
		canMatch bool
	}{
		{"N-*", "N-*", "N-*", true, true},
		{"N-9.99.*", "N-[1-9].*", "", false, true},
		{"N-9.99.*", "N-[1-9][0-9].*", "", false, false},
	}
	for _, tt := range tests {
		t.Run(tt.str, func(t *testing.T) {
			a1, err1 := Compile(tt.pattern1)
			a2, err2 := Compile(tt.pattern2)
			if err1 != nil {
				t.Fatal(err1)
			}
			if err2 != nil {
				t.Fatal(err2)
			}
			a := Intersect(a1, a2)
			matches := a.Match(tt.str)
			if matches != tt.matches {
				t.Errorf("Match() = %v, want %v", matches, tt.matches)
			}
			canMatch := a.CanMatch()
			if canMatch != tt.canMatch {
				t.Errorf("CanMatch() = %v, want %v", canMatch, tt.canMatch)
			}
		})
	}
}
