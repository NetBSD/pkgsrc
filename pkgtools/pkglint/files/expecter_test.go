package main

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_Expecter_ExpectEmptyLine__beginning_of_file(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("file.txt",
		"line 1",
		"line 2")
	exp := NewExpecter(lines)

	exp.ExpectEmptyLine()

	t.CheckOutputLines(
		"NOTE: file.txt:1: Empty line expected before this line.")
}

func (s *Suite) Test_Expecter_ExpectEmptyLine__end_of_file(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("file.txt",
		"line 1",
		"line 2")
	exp := NewExpecter(lines)

	for exp.Advance() {
	}

	exp.ExpectEmptyLine()

	t.CheckOutputLines(
		"NOTE: file.txt:2: Empty line expected after this line.")
}
