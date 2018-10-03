package main

import (
	"gopkg.in/check.v1"
	"math/rand"
)

type Fuzzer struct {
	seed  int64
	rnd   *rand.Rand
	stock []struct {
		r      rune
		weight int
	}
	total int
	last  string
	ok    bool
}

func NewFuzzer(seed ...int64) *Fuzzer {
	var actualSeed int64
	if len(seed) != 0 {
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
	s := ""
	for i := 0; i < length; i++ {
		s += string(f.randomChar())
	}
	f.last = s
	return s
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

func (f *Fuzzer) CheckOk() {
	if !f.ok {
		dummyLine.Errorf("Fuzzing failed with seed %d, last generated value: %s", f.seed, f.last)
	}
}

func (f *Fuzzer) Ok() { f.ok = true }

func (s *Suite) Test_Fuzzer__out_of_stock(c *check.C) {
	fuzzer := NewFuzzer(0)
	fuzzer.total = 1 // Trick the fuzzer to achieve full code coverage.

	c.Check(
		func() { fuzzer.Generate(1) },
		check.Panics,
		"Out of stock")
}
