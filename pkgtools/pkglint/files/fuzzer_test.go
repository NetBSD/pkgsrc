package pkglint

import (
	"gopkg.in/check.v1"
	"math/rand"
)

// Fuzzer generates random strings.
// The structure of the strings is configurable.
type Fuzzer struct {
	seed  int64
	rnd   *rand.Rand
	stock []struct {
		r      rune
		weight int
	}
	total int    // The sum of all stock weights
	last  string //
	ok    bool   // Whether the last string was processed correctly
}

// NewFuzzer returns a fuzzer.
// If no seed is passed, a random seed is chosen.
// To reproduce a previous run, pass the seed from that run as the parameter.
func NewFuzzer(seed ...int64) *Fuzzer {
	var actualSeed int64
	if len(seed) > 0 {
		actualSeed = seed[0]
	} else {
		actualSeed = rand.Int63()
	}
	return &Fuzzer{seed: actualSeed, rnd: rand.New(rand.NewSource(actualSeed))}
}

// Char randomly generates a character from the given set.
// Each character has the given weight.
func (f *Fuzzer) Char(set string, weight int) {
	for _, r := range set {
		f.addChar(r, weight)
	}
}

// Range randomly generates a character from the given range.
// Each character has the given weight.
func (f *Fuzzer) Range(minIncl, maxIncl rune, weight int) {
	for r := minIncl; r <= maxIncl; r++ {
		f.addChar(r, weight)
	}
}

func (f *Fuzzer) addChar(r rune, weight int) {
	f.stock = append(f.stock, struct {
		r      rune
		weight int
	}{r, weight})
	f.total += weight
}

func (f *Fuzzer) Generate(length int) string {
	rs := make([]rune, length)
	for i := 0; i < length; i++ {
		rs[i] = f.randomChar()
	}
	f.last = string(rs)
	return f.last
}

func (f *Fuzzer) randomChar() rune {
	i := int(f.rnd.Int31n(int32(f.total)))
	for _, entry := range f.stock {
		i -= entry.weight
		if i < 0 {
			return entry.r
		}
	}
	panic("Out of stock")
}

// CheckOk is typically used in a defer statement and is run after all
// the tests to check whether they have been marked as ok.
func (f *Fuzzer) CheckOk() {
	if !f.ok {
		panic(sprintf("Fuzzing failed with seed %d, last generated value: %s", f.seed, f.last))
	}
}

// Ok marks the current string as processed correctly.
func (f *Fuzzer) Ok() { f.ok = true }

func (s *Suite) Test_Fuzzer__out_of_stock(c *check.C) {
	fuzzer := NewFuzzer(0)
	fuzzer.total = 1 // Intentionally damage the fuzzer to achieve full code coverage.

	c.Check(
		func() { fuzzer.Generate(1) },
		check.Panics,
		"Out of stock")
}
