package makepat

import (
	"netbsd.org/pkglint/intqa"
	"netbsd.org/pkglint/textproc"
	"reflect"
	"testing"
)

func Test_Compile__errors(t *testing.T) {
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

func Test_compileCharClass(t *testing.T) {
	tests := []struct {
		pattern string
		str     string
		want    bool
	}{
		{"[0-9]", "/", false},
		{"[0-9]", "0", true},
		{"[0-9]", "9", true},
		{"[0-9]", ":", false},
	}
	for _, tt := range tests {
		t.Run(tt.pattern, func(t *testing.T) {
			p, err := Compile(tt.pattern)
			if err != nil {
				t.Fail()
			} else {
				got := p.Match(tt.str)
				if got != tt.want {
					t.Errorf("got %v, want %v", got, tt.want)
				}
			}
		})
	}
}

func Test_Pattern_addTransitions(t *testing.T) {
	none := textproc.NewByteSet("")
	numeric := textproc.NewByteSet("-+0-9.Ee")
	all := none.Inverse()

	tests := []struct {
		name    string
		bs      *textproc.ByteSet
		example byte
		want    bool
	}{
		{"none min", none, 0, false},
		{"none max", none, 255, false},
		{"all min", all, 0, true},
		{"all max", all, 255, true},
		{"numeric", numeric, '*', false},
		{"numeric", numeric, '+', true},
		{"numeric", numeric, ',', false},
		{"numeric", numeric, '-', true},
		{"numeric", numeric, '.', true},
		{"numeric", numeric, '/', false},
		{"numeric", numeric, '0', true},
		{"numeric", numeric, '9', true},
		{"numeric", numeric, ':', false},
		{"numeric", numeric, 'D', false},
		{"numeric", numeric, 'E', true},
		{"numeric", numeric, 'F', false},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			var p Pattern
			s0 := p.addState(false)
			s1 := p.addState(true)
			var chars [256]bool
			for i := 0; i < 256; i++ {
				chars[i] = tt.bs.Contains(byte(i))
			}
			p.addTransitions(s0, &chars, s1)
			got := p.Match(string([]byte{tt.example}))
			if got != tt.want {
				t.Errorf("got %v, want %v", got, tt.want)
			}
		})
	}
}

func Test_Pattern_addState(t *testing.T) {
	var p Pattern

	p.addState(false)
	p.addState(true)

	expected := Pattern{states: []state{{nil, false}, {nil, true}}}
	if !reflect.DeepEqual(p, expected) {
		t.Errorf("%#v", p)
	}
}

func Test_Pattern_addTransition(t *testing.T) {
	var p Pattern

	p.addState(false)
	p.addState(true)
	p.addTransition(0, '0', '9', 1)
	p.addTransition(1, '0', '9', 0)

	expected := Pattern{states: []state{
		{[]transition{{'0', '9', 1}}, false},
		{[]transition{{'0', '9', 0}}, true}}}
	if !reflect.DeepEqual(p, expected) {
		t.Errorf("%#v", p)
	}
}

func Test_Pattern_Match(t *testing.T) {
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
		{"*.c", ".c", true},
		{"*.c", "a.c", true},
		{"*.c", "c.c", true},
		{"*.c", "..c", true},
		{"*.c", ".c.c", true},
		{"*.c", "a.c.c", true},
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

func Test_Intersect(t *testing.T) {
	// The state machine of the compiled patterns is more powerful than
	// the string representation of the patterns, therefore the
	// intersected pattern is not visualized. Instead, it is tested using
	// a single example string.
	tests := []struct {
		pattern1 string
		pattern2 string
		canMatch bool
		example  string
		matches  bool
	}{
		{"N-*", "N-*", true, "N-*", true},
		{"N-9.99.*", "N-[1-9].*", true, "", false},
		{"N-9.99.*", "N-[1-9][0-9].*", false, "", false},
		{"*.c", "*.h", false, "", false},
		{"a*", "*b", true, "ab", true},
		{"a*bc", "ab*c", true, "abc", true},
		{"*1*", "*2*", true, "asdf", false},
		{"*1*", "*2*", true, "a1a", false},
		{"*1*", "*2*", true, "a2a", false},
		{"*1*", "*2*", true, "a12a", true},
		{"*1*", "*2*", true, "a21a", true},
		{"*[^0-9-+eE.]*", "*.c", true, ".c", true},
		{"*[^0-9-+eE.]*", "*.c", true, "0.c", true},
		{"*[^0-9-+eE.]*", "*.e", true, "0.e", false},
		{"*[^0-9-+eE.]*", "*.e", true, "a.e", true},
		{"*[^0-9-+eE.]*", "*.0", true, "000a0.0", true},
		{"*[^0-9-+eE.]*", "*.0", true, "0000.0", false},
		{"[0-9]", "[a-f]", false, "0", false},
		{"[0-9]", "[0a-f]", true, "0", true},
		{"[0-9]", "[0a-f]", true, "1", false},
		{"[0-9]", "[0a-f]", true, "00", false},
	}
	for _, tt := range tests {
		t.Run(tt.example, func(t *testing.T) {
			p1, err1 := Compile(tt.pattern1)
			p2, err2 := Compile(tt.pattern2)
			if err1 != nil {
				t.Fatal(err1)
			}
			if err2 != nil {
				t.Fatal(err2)
			}
			both := Intersect(p1, p2)
			canMatch := both.CanMatch()
			if canMatch != tt.canMatch {
				t.Errorf("CanMatch() = %v, want %v", canMatch, tt.canMatch)
			}
			matches := both.Match(tt.example)
			if matches != tt.matches {
				t.Errorf("Match() = %v, want %v", matches, tt.matches)
			}
			if matches && !p1.Match(tt.example) {
				t.Errorf("example %q doesn't match pattern1 %q", tt.example, tt.pattern1)
			}
			if matches && !p2.Match(tt.example) {
				t.Errorf("example %q doesn't match pattern2 %q", tt.example, tt.pattern2)
			}
		})
	}
}

func Test_Pattern_optimized(t *testing.T) {
	var p Pattern
	p.addState(false)
	p.addState(false)
	p.addState(false)
	p.addState(true)
	p.addTransition(0, '1', '1', 1)
	p.addTransition(1, '2', '2', 3)

	opt := p.optimized()

	expected := Pattern{[]state{
		{[]transition{{'1', '1', 1}}, false},
		{[]transition{{'2', '2', 2}}, false},
		{nil, true}}}
	if !reflect.DeepEqual(opt, &expected) {
		t.Errorf("%#v", p)
	}
}

func Test_Pattern_reachable(t *testing.T) {
	p, err := Compile("N-*")
	if err != nil {
		t.Fatal(err)
	}

	reachable := p.reachable()

	if !reflect.DeepEqual(reachable, []bool{true, true, true}) {
		t.Errorf("%#v", reachable)
	}
}

func Test_Pattern_relevant(t *testing.T) {
	p, err := Compile("N-*")
	if err != nil {
		t.Fatal(err)
	}

	reachable := p.reachable()
	relevant := p.relevant(reachable)

	if !reflect.DeepEqual(relevant, []bool{true, true, true}) {
		t.Errorf("%#v", relevant)
	}
}

func Test_Pattern_compressed(t *testing.T) {
	p, err := Compile("N-*")
	if err != nil {
		t.Fatal(err)
	}

	reachable := p.reachable()
	relevant := p.relevant(reachable)
	compressed := p.compressed(relevant)

	if !reflect.DeepEqual(compressed, p) {
		t.Errorf("%#v", compressed)
	}
}

func Test_Pattern_CanMatch(t *testing.T) {
	tests := []struct {
		p1   string
		p2   string
		want bool
	}{
		{"*.c", "*.h", false},
		{"*.c", "????.?", true},
		{"[1-9]", "5", true},
		{"[1-9]", ":", false},
		{"[1-9A-Za-z]", "[ -/]", false},
	}
	for _, tt := range tests {
		t.Run(tt.p1+" "+tt.p2, func(t *testing.T) {
			p1, err1 := Compile(tt.p1)
			p2, err2 := Compile(tt.p2)
			if err1 != nil {
				t.Fatal(err1)
			}
			if err2 != nil {
				t.Fatal(err2)
			}
			both := Intersect(p1, p2)
			got := both.CanMatch()
			if got != tt.want {
				t.Errorf("CanMatch() = %v, want %v", got, tt.want)
			}
		})
	}

}

func Test_Number(t *testing.T) {
	tests := []struct {
		example string
		want    bool
	}{
		{"", false},
		{".", false},
		{"0x", false},
		{"0xa", true},
		{"+0xa", true},
		{"-0xa", true},
		{"0xa.", false},
		{"0xa.a", false},
		{"0xa.aa", false},
		{"0xa.p", false},
		{"0xa.p-1", true},
		{"0xa.p1", true},
		{"0xa.p11", true},
		{"0xaa.", false},
		{"1", true},
		{"+1", true},
		{"-1", true},
		{"1.", true},
		{"1.1", true},
		{"1.11", true},
		{"1.1e", false},
		{"1.1e+", false},
		{"1.1e+1", true},
		{"1.1e+11", true},
		{"1.1e-1", true},
		{"1.e+1", true},
		{"11", true},
	}

	for _, tt := range tests {
		t.Run(tt.example, func(t *testing.T) {
			if got := Number().Match(tt.example); got != tt.want {
				t.Errorf("got %v, want %v", got, tt.want)
			}
		})
	}
}

func Test_bmin(t *testing.T) {
	if bmin(0, 255) != 0 {
		t.Error()
	}
	if bmin(128, 127) != 127 {
		t.Error()
	}
}

func Test_bmax(t *testing.T) {
	if bmax(0, 255) != 255 {
		t.Error()
	}
	if bmax(128, 127) != 128 {
		t.Error()
	}
}

func Test(t *testing.T) {
	ck := intqa.NewQAChecker(t.Errorf)
	ck.Configure("*", "*", "", -intqa.EMissingTest)
	ck.Check()
}
