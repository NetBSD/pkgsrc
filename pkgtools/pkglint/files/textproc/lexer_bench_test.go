package textproc

import (
	"fmt"
	"testing"
)

func validate(n int, sum int) {
	var expected int
	switch n {
	case 1:
		expected = 0
	case 100:
		expected = 40
	case 10000:
		expected = 2457
	case 1000000:
		expected = 246088
	case 100000000:
		expected = 24609375
	case 10000000000:
		expected = 246093750
	default:
		return
	}
	if sum != expected {
		panic(fmt.Sprintf("expected %d for n = %d, got %d", expected, n, sum))
	}
}

type ByteSetBool struct {
	bits [256]bool
}

func NewByteSetBool(other *ByteSet) *ByteSetBool {
	var s ByteSetBool
	for i := 0; i < 256; i++ {
		s.bits[i] = other.Contains(byte(i))
	}
	return &s
}

func (s *ByteSetBool) Contains(b byte) bool { return s.bits[b] }

func Benchmark_ByteSetBool_Contains(b *testing.B) {
	set := NewByteSetBool(AlnumU)
	var sum int
	for i := 0; i < b.N; i++ {
		if set.Contains(byte(i)) {
			sum++
		}
	}
	validate(b.N, sum)
}

type ByteSetUint8 struct {
	bits [32]uint8
}

func NewByteSetUint8(other *ByteSet) *ByteSetUint8 {
	var s8 ByteSetUint8
	for i := uint(0); i < 256; i++ {
		if other.Contains(byte(i)) {
			s8.bits[i/8] |= 1 << (i % 8)
		}
	}
	return &s8
}

func (s *ByteSetUint8) Contains(b byte) bool { return s.bits[b/8]&(1<<(b%8)) != 0 }

func Benchmark_ByteSetUint8_Contains(b *testing.B) {
	set := NewByteSetUint8(AlnumU)
	var sum int
	for i := 0; i < b.N; i++ {
		if set.Contains(byte(i)) {
			sum++
		}
	}
	validate(b.N, sum)
}

type ByteSetUint16 struct {
	bits [16]uint16
}

func NewByteSetUint16(other *ByteSet) *ByteSetUint16 {
	var s ByteSetUint16
	for i := uint(0); i < 256; i++ {
		if other.Contains(byte(i)) {
			s.bits[i/16] |= 1 << (i % 16)
		}
	}
	return &s
}

func (s *ByteSetUint16) Contains(b byte) bool { return s.bits[b/16]&(1<<(b%16)) != 0 }

func Benchmark_ByteSet16_Contains(b *testing.B) {
	set := NewByteSetUint16(AlnumU)
	var sum int
	for i := 0; i < b.N; i++ {
		if set.Contains(byte(i)) {
			sum++
		}
	}
	validate(b.N, sum)
}

type ByteSetUint64 struct {
	bits [64]uint64
}

func NewByteSetUint64(other *ByteSet) *ByteSetUint64 {
	var s ByteSetUint64
	for i := uint(0); i < 256; i++ {
		if other.Contains(byte(i)) {
			s.bits[i/64] |= 1 << (i % 64)
		}
	}
	return &s
}

func (s *ByteSetUint64) Contains(b byte) bool { return s.bits[b/64]&(1<<(b%64)) != 0 }

func Benchmark_ByteSet64_Contains(b *testing.B) {
	set := NewByteSetUint64(AlnumU)
	var sum int
	for i := 0; i < b.N; i++ {
		if set.Contains(byte(i)) {
			sum++
		}
	}
	validate(b.N, sum)
}

func Benchmark_Direct_Compare(b *testing.B) {
	var sum int
	for i := 0; i < b.N; i++ {
		i := byte(i)
		if 'A' <= i && i <= 'Z' || 'a' <= i && i <= 'z' || '0' <= i && i <= '9' || i == '_' {
			sum++
		}
	}
	validate(b.N, sum)
}

func Benchmark_Direct_Compare_binary_search(b *testing.B) {
	var sum int
	for i := 0; i < b.N; i++ {
		i := byte(i)
		if i >= 'A' {
			if i >= 'a' {
				if i <= 'z' {
					sum++
				}
			} else if i <= 'Z' {
				sum++
			} else if i == '_' {
				sum++
			}
		} else if i >= '0' && i <= '9' {
			sum++
		}
	}
	validate(b.N, sum)
}

func Benchmark_Direct_Compare_reverse(b *testing.B) {
	var sum int
	for i := 0; i < b.N; i++ {
		i := byte(i)
		if i == '_' || '0' <= i && i <= '9' || 'a' <= i && i <= 'z' || 'A' <= i && i <= 'Z' {
			sum++
		}
	}
	validate(b.N, sum)
}

func Benchmark_Direct_Compare_fold_case(b *testing.B) {
	var sum int
	for i := 0; i < b.N; i++ {
		i := byte(i)
		if 'A' <= (i&^0x20) && (i&^0x20) <= 'Z' || '0' <= i && i <= '9' || i == '_' {
			sum++
		}
	}
	validate(b.N, sum)
}
