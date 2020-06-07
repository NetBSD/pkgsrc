package pkglint

import "gopkg.in/check.v1"

// In a single file, five variables get a default value and are later overridden
// with the same value using the five different assignments operators.
func (s *Suite) Test_RedundantScope__single_file_default(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		"VAR.def?=       value",
		"VAR.asg?=       value",
		"VAR.app?=       value",
		"VAR.evl?=       value",
		"VAR.shl?=       value",
		"",
		"VAR.def?=       value",
		"VAR.asg=        value",
		"VAR.app+=       value",
		"VAR.evl:=       value",
		"VAR.shl!=       value")

	NewRedundantScope().Check(mklines)

	t.CheckOutputLines(
		"NOTE: file.mk:7: Default assignment of VAR.def has no effect because of line 1.",
		"NOTE: file.mk:8: Definition of VAR.asg is redundant because of line 2.",
		"NOTE: file.mk:10: Definition of VAR.evl is redundant because of line 4.")
	// TODO: "VAR.shl: is overwritten later"
}

// In a single file, five variables get assigned are value and are later overridden
// with the same value using the five different assignments operators.
func (s *Suite) Test_RedundantScope__single_file_assign(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		"VAR.def=        value",
		"VAR.asg=        value",
		"VAR.app=        value",
		"VAR.evl=        value",
		"VAR.shl=        value",
		"",
		"VAR.def?=       value",
		"VAR.asg=        value",
		"VAR.app+=       value",
		"VAR.evl:=       value",
		"VAR.shl!=       value")

	NewRedundantScope().Check(mklines)

	t.CheckOutputLines(
		"NOTE: file.mk:7: Default assignment of VAR.def has no effect because of line 1.",
		"NOTE: file.mk:8: Definition of VAR.asg is redundant because of line 2.",
		"NOTE: file.mk:10: Definition of VAR.evl is redundant because of line 4.")
	// TODO: "VAR.shl: is overwritten later"
}

// In a single file, five variables get appended a value and are later overridden
// with the same value using the five different assignments operators.
func (s *Suite) Test_RedundantScope__single_file_append(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		"VAR.def+=       value",
		"VAR.asg+=       value",
		"VAR.app+=       value",
		"VAR.evl+=       value",
		"VAR.shl+=       value",
		"",
		"VAR.def?=       value",
		"VAR.asg=        value",
		"VAR.app+=       value",
		"VAR.evl:=       value",
		"VAR.shl!=       value")

	NewRedundantScope().Check(mklines)

	t.CheckOutputLines(
		"NOTE: file.mk:7: Default assignment of VAR.def has no effect because of line 1.",
		"WARN: file.mk:2: Variable VAR.asg is overwritten in line 8.",
		"WARN: file.mk:4: Variable VAR.evl is overwritten in line 10.")
	// TODO: "VAR.shl: is overwritten later"
}

// In a single file, five variables get assigned a value using the := operator,
// which in this simple case is equivalent to the = operator. The variables are
// later overridden with the same value using the five different assignments operators.
func (s *Suite) Test_RedundantScope__single_file_eval(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		"VAR.def:=       value",
		"VAR.asg:=       value",
		"VAR.app:=       value",
		"VAR.evl:=       value",
		"VAR.shl:=       value",
		"",
		"VAR.def?=       value",
		"VAR.asg=        value",
		"VAR.app+=       value",
		"VAR.evl:=       value",
		"VAR.shl!=       value")

	NewRedundantScope().Check(mklines)

	t.CheckOutputLines(
		"NOTE: file.mk:7: Default assignment of VAR.def has no effect because of line 1.",
		"NOTE: file.mk:8: Definition of VAR.asg is redundant because of line 2.",
		"NOTE: file.mk:10: Definition of VAR.evl is redundant because of line 4.")
	// TODO: "VAR.shl: is overwritten later"
}

// In a single file, five variables get assigned a value using the != operator,
// which runs a shell command. As of March 2019 pkglint doesn't try to evaluate
// the shell commands, therefore the variable values are unknown. The variables
// are later overridden using the five different assignments operators.
func (s *Suite) Test_RedundantScope__single_file_shell(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		"VAR.def!=       value",
		"VAR.asg!=       value",
		"VAR.app!=       value",
		"VAR.evl!=       value",
		"VAR.shl!=       value",
		"",
		"VAR.def?=       value",
		"VAR.asg=        value",
		"VAR.app+=       value",
		"VAR.evl:=       value",
		"VAR.shl!=       value")

	NewRedundantScope().Check(mklines)

	t.CheckOutputLines(
		"NOTE: file.mk:7: Default assignment of VAR.def has no effect because of line 1.",
		"WARN: file.mk:2: Variable VAR.asg is overwritten in line 8.",
		"WARN: file.mk:4: Variable VAR.evl is overwritten in line 10.")
	// TODO: "VAR.shl: is overwritten later"
}

// In a single file, five variables get a default value and are later overridden
// with the same value using the five different assignments operators.
func (s *Suite) Test_RedundantScope__single_file_default_ref(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		"VAR.def?=       ${OTHER}",
		"VAR.asg?=       ${OTHER}",
		"VAR.app?=       ${OTHER}",
		"VAR.evl?=       ${OTHER}",
		"VAR.shl?=       ${OTHER}",
		"",
		"VAR.def?=       ${OTHER}",
		"VAR.asg=        ${OTHER}",
		"VAR.app+=       ${OTHER}",
		"VAR.evl:=       ${OTHER}",
		"VAR.shl!=       ${OTHER}")

	NewRedundantScope().Check(mklines)

	t.CheckOutputLines(
		"NOTE: file.mk:7: Default assignment of VAR.def has no effect because of line 1.",
		"NOTE: file.mk:8: Definition of VAR.asg is redundant because of line 2.")
	// TODO: "VAR.evl: is overwritten later",
	// TODO: "VAR.shl: is overwritten later"
}

// In a single file, five variables get assigned are value and are later overridden
// with the same value using the five different assignments operators.
func (s *Suite) Test_RedundantScope__single_file_assign_ref(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		"VAR.def=        ${OTHER}",
		"VAR.asg=        ${OTHER}",
		"VAR.app=        ${OTHER}",
		"VAR.evl=        ${OTHER}",
		"VAR.shl=        ${OTHER}",
		"",
		"VAR.def?=       ${OTHER}",
		"VAR.asg=        ${OTHER}",
		"VAR.app+=       ${OTHER}",
		"VAR.evl:=       ${OTHER}",
		"VAR.shl!=       ${OTHER}")

	NewRedundantScope().Check(mklines)

	t.CheckOutputLines(
		"NOTE: file.mk:7: Default assignment of VAR.def has no effect because of line 1.",
		"NOTE: file.mk:8: Definition of VAR.asg is redundant because of line 2.")
	// TODO: "VAR.evl: is overwritten later",
	// TODO: "VAR.shl: is overwritten later"
}

// In a single file, five variables get appended a value and are later overridden
// with the same value using the five different assignments operators.
func (s *Suite) Test_RedundantScope__single_file_append_ref(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		"VAR.def+=       ${OTHER}",
		"VAR.asg+=       ${OTHER}",
		"VAR.app+=       ${OTHER}",
		"VAR.evl+=       ${OTHER}",
		"VAR.shl+=       ${OTHER}",
		"",
		"VAR.def?=       ${OTHER}",
		"VAR.asg=        ${OTHER}",
		"VAR.app+=       ${OTHER}",
		"VAR.evl:=       ${OTHER}",
		"VAR.shl!=       ${OTHER}")

	NewRedundantScope().Check(mklines)

	t.CheckOutputLines(
		"NOTE: file.mk:7: Default assignment of VAR.def has no effect because of line 1.",
		"WARN: file.mk:2: Variable VAR.asg is overwritten in line 8.")
	// TODO: "VAR.evl: is overwritten later",
	// TODO: "VAR.shl: is overwritten later"
}

// In a single file, five variables get assigned a value using the := operator,
// which in this simple case is equivalent to the = operator. The variables are
// later overridden with the same value using the five different assignments operators.
func (s *Suite) Test_RedundantScope__single_file_eval_ref(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		"VAR.def:=       ${OTHER}",
		"VAR.asg:=       ${OTHER}",
		"VAR.app:=       ${OTHER}",
		"VAR.evl:=       ${OTHER}",
		"VAR.shl:=       ${OTHER}",
		"",
		"VAR.def?=       ${OTHER}",
		"VAR.asg=        ${OTHER}",
		"VAR.app+=       ${OTHER}",
		"VAR.evl:=       ${OTHER}",
		"VAR.shl!=       ${OTHER}")

	NewRedundantScope().Check(mklines)

	t.CheckOutputLines(
		"NOTE: file.mk:7: Default assignment of VAR.def has no effect because of line 1.",
		"NOTE: file.mk:8: Definition of VAR.asg is redundant because of line 2.")
	// TODO: "VAR.evl: is overwritten later",
	// TODO: "VAR.shl: is overwritten later"
}

// In a single file, five variables get assigned a value using the != operator,
// which runs a shell command. As of March 2019 pkglint doesn't try to evaluate
// the shell commands, therefore the variable values are unknown. The variables
// are later overridden using the five different assignments operators.
func (s *Suite) Test_RedundantScope__single_file_shell_ref(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		"VAR.def!=       ${OTHER}",
		"VAR.asg!=       ${OTHER}",
		"VAR.app!=       ${OTHER}",
		"VAR.evl!=       ${OTHER}",
		"VAR.shl!=       ${OTHER}",
		"",
		"VAR.def?=       ${OTHER}",
		"VAR.asg=        ${OTHER}",
		"VAR.app+=       ${OTHER}",
		"VAR.evl:=       ${OTHER}",
		"VAR.shl!=       ${OTHER}")

	NewRedundantScope().Check(mklines)

	t.CheckOutputLines(
		"NOTE: file.mk:7: Default assignment of VAR.def has no effect because of line 1.",
		"WARN: file.mk:2: Variable VAR.asg is overwritten in line 8.")
	// TODO: "VAR.evl: is overwritten later",
	// TODO: "VAR.shl: is overwritten later"
}

func (s *Suite) Test_RedundantScope__after_including_same_value(c *check.C) {
	t := s.Init(c)

	// including.mk:1:  include "included.mk"
	//   included.mk:1:   VAR.x.y op1 ${OTHER}
	// including.mk:2:  VAR.x.y op2 ${OTHER}
	//
	test := func(includedOp, includingOp string, diagnostics ...string) {
		opName := [...]string{"asg", "shl", "evl", "app", "def"}
		varname := sprintf("VAR.%s.%s",
			opName[NewMkOperator(includedOp)],
			opName[NewMkOperator(includingOp)])

		include, get := t.SetUpHierarchy()
		include("including.mk",
			include("included.mk",
				sprintf("%s%s ${OTHER}", varname, includedOp)),
			sprintf("%s%s ${OTHER}", varname, includingOp))

		NewRedundantScope().Check(get("including.mk"))

		t.CheckOutput(diagnostics)
	}

	// As of March 2019, the != operator is ignored for the redundancy check.
	// TODO: Add the != operator.

	test("?=", "?=",
		"NOTE: including.mk:2: Default assignment of VAR.def.def has no effect because of included.mk:1.")

	test("?=", "=",
		"NOTE: including.mk:2: Definition of VAR.def.asg is redundant because of included.mk:1.")

	// VAR.def.app defines a default value and then appends to it. This is a common pattern.
	// Appending the same value feels redundant but probably doesn't happen in practice.
	// If it does, there should be a note for it.
	test("?=", "+=")

	// VAR.def.evl introduces a subtle difference since := evaluates the variable immediately.
	// Therefore the assignment is not redundant.
	test("?=", ":=")

	test("=", "?=",
		"NOTE: including.mk:2: Default assignment of VAR.asg.def has no effect because of included.mk:1.")

	test("=", "=",
		"NOTE: including.mk:2: Definition of VAR.asg.asg is redundant because of included.mk:1.")

	// VAR.asg.app defines a variable and later appends to it. This is a common pattern.
	// Appending the same value feels redundant but probably doesn't happen in practice.
	// If it does, there should be a note for it.
	test("=", "+=")

	// VAR.asg.evl evaluates the variable immediately and is thus not redundant.
	test("=", ":=")

	test("+=", "?=",
		"NOTE: including.mk:2: Default assignment of VAR.app.def has no effect because of included.mk:1.")

	// VAR.app.asg first appends and then overwrites. This might be a mistake.
	// TODO: Find out whether this case happens in actual pkgsrc and if it's accidental.
	// VAR.app.app first appends and then appends one more. This is a common pattern.
	test("+=", "=")

	test("+=", "+=")

	test("+=", ":=")

	test(":=", "?=",
		"NOTE: including.mk:2: Default assignment of VAR.evl.def has no effect because of included.mk:1.")

	test(":=", "=",
		"NOTE: including.mk:2: Definition of VAR.evl.asg is redundant because of included.mk:1.")

	test(":=", "+=")

	test(":=", ":=")
}

func (s *Suite) Test_RedundantScope__after_including_different_value(c *check.C) {
	t := s.Init(c)

	// Only test the ?=, = and += operators since the others are ignored,
	// as of March 2019.
	include, get := t.SetUpHierarchy()
	include("including.mk",
		include("included.mk",
			"VAR.def.def?=   ${VALUE}",
			"VAR.def.asg?=   ${VALUE}",
			"VAR.def.app?=   ${VALUE}",
			"VAR.asg.def=    ${VALUE}",
			"VAR.asg.asg=    ${VALUE}",
			"VAR.asg.app=    ${VALUE}",
			"VAR.app.def+=   ${VALUE}",
			"VAR.app.asg+=   ${VALUE}",
			"VAR.app.app+=   ${VALUE}"),
		"VAR.def.def?=   ${OTHER}",
		"VAR.def.asg=    ${OTHER}",
		"VAR.def.app+=   ${OTHER}",
		"VAR.asg.def?=   ${OTHER}",
		"VAR.asg.asg=    ${OTHER}",
		"VAR.asg.app+=   ${OTHER}",
		"VAR.app.def?=   ${OTHER}",
		"VAR.app.asg=    ${OTHER}",
		"VAR.app.app+=   ${OTHER}")
	mklines := get("including.mk")

	NewRedundantScope().Check(mklines)

	t.CheckOutputLines(
		"NOTE: including.mk:2: Default assignment of VAR.def.def has no effect because of included.mk:1.",
		"NOTE: including.mk:5: Default assignment of VAR.asg.def has no effect because of included.mk:4.",
		"NOTE: including.mk:8: Default assignment of VAR.app.def has no effect because of included.mk:7.")
}

func (s *Suite) Test_RedundantScope__before_including_same_value(c *check.C) {
	t := s.Init(c)

	// Only test the ?=, = and += operators since the others are ignored,
	// as of March 2019.
	include, get := t.SetUpHierarchy()
	include("including.mk",
		"VAR.def.def?=   ${OTHER}",
		"VAR.def.asg?=   ${OTHER}",
		"VAR.def.app?=   ${OTHER}",
		"VAR.asg.def=    ${OTHER}",
		"VAR.asg.asg=    ${OTHER}",
		"VAR.asg.app=    ${OTHER}",
		"VAR.app.def+=   ${OTHER}",
		"VAR.app.asg+=   ${OTHER}",
		"VAR.app.app+=   ${OTHER}",
		include("included.mk",
			"VAR.def.def?=   ${OTHER}",
			"VAR.def.asg=    ${OTHER}",
			"VAR.def.app+=   ${OTHER}",
			"VAR.asg.def?=   ${OTHER}",
			"VAR.asg.asg=    ${OTHER}",
			"VAR.asg.app+=   ${OTHER}",
			"VAR.app.def?=   ${OTHER}",
			"VAR.app.asg=    ${OTHER}",
			"VAR.app.app+=   ${OTHER}"))
	mklines := get("including.mk")

	NewRedundantScope().Check(mklines)

	t.CheckOutputLines(
		"NOTE: including.mk:1: Default assignment of VAR.def.def has no effect because of included.mk:1.",
		"NOTE: including.mk:2: Default assignment of VAR.def.asg has no effect because of included.mk:2.",
		"NOTE: including.mk:4: Definition of VAR.asg.def is redundant because of included.mk:4.",
		"NOTE: including.mk:5: Definition of VAR.asg.asg is redundant because of included.mk:5.",
		"WARN: including.mk:8: Variable VAR.app.asg is overwritten in included.mk:8.")
}

func (s *Suite) Test_RedundantScope__before_including_different_value(c *check.C) {
	t := s.Init(c)

	// Only test the ?=, = and += operators since the others are ignored,
	// as of March 2019.
	include, get := t.SetUpHierarchy()
	include("including.mk",
		"VAR.def.def?=   ${VALUE}",
		"VAR.def.asg?=   ${VALUE}",
		"VAR.def.app?=   ${VALUE}",
		"VAR.asg.def=    ${VALUE}",
		"VAR.asg.asg=    ${VALUE}",
		"VAR.asg.app=    ${VALUE}",
		"VAR.app.def+=   ${VALUE}",
		"VAR.app.asg+=   ${VALUE}",
		"VAR.app.app+=   ${VALUE}",
		include("included.mk",
			"VAR.def.def?=   ${OTHER}",
			"VAR.def.asg=    ${OTHER}",
			"VAR.def.app+=   ${OTHER}",
			"VAR.asg.def?=   ${OTHER}",
			"VAR.asg.asg=    ${OTHER}",
			"VAR.asg.app+=   ${OTHER}",
			"VAR.app.def?=   ${OTHER}",
			"VAR.app.asg=    ${OTHER}",
			"VAR.app.app+=   ${OTHER}"))
	mklines := get("including.mk")

	NewRedundantScope().Check(mklines)

	t.CheckOutputLines(
		"WARN: including.mk:2: Variable VAR.def.asg is overwritten in included.mk:2.",
		"WARN: including.mk:5: Variable VAR.asg.asg is overwritten in included.mk:5.",
		"WARN: including.mk:8: Variable VAR.app.asg is overwritten in included.mk:8.")
}

func (s *Suite) Test_RedundantScope__independent_same_value(c *check.C) {
	t := s.Init(c)

	// Only test the ?=, = and += operators since the others are ignored,
	// as of March 2019.
	include, get := t.SetUpHierarchy()
	include("including.mk",
		include("included1.mk",
			"VAR.def.def?=   ${OTHER}",
			"VAR.def.asg?=   ${OTHER}",
			"VAR.def.app?=   ${OTHER}",
			"VAR.asg.def=    ${OTHER}",
			"VAR.asg.asg=    ${OTHER}",
			"VAR.asg.app=    ${OTHER}",
			"VAR.app.def+=   ${OTHER}",
			"VAR.app.asg+=   ${OTHER}",
			"VAR.app.app+=   ${OTHER}"),
		include("included2.mk",
			"VAR.def.def?=   ${OTHER}",
			"VAR.def.asg=    ${OTHER}",
			"VAR.def.app+=   ${OTHER}",
			"VAR.asg.def?=   ${OTHER}",
			"VAR.asg.asg=    ${OTHER}",
			"VAR.asg.app+=   ${OTHER}",
			"VAR.app.def?=   ${OTHER}",
			"VAR.app.asg=    ${OTHER}",
			"VAR.app.app+=   ${OTHER}"))
	mklines := get("including.mk")

	NewRedundantScope().Check(mklines)

	// Since the two included files are independent, there cannot be any
	// redundancies between them. These redundancies can only be discovered
	// when one of them includes the other.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_RedundantScope__independent_different_value(c *check.C) {
	t := s.Init(c)

	// Only test the ?=, = and += operators since the others are ignored,
	// as of March 2019.
	include, get := t.SetUpHierarchy()
	include("including.mk",
		include("included1.mk",
			"VAR.def.def?=   ${VALUE}",
			"VAR.def.asg?=   ${VALUE}",
			"VAR.def.app?=   ${VALUE}",
			"VAR.asg.def=    ${VALUE}",
			"VAR.asg.asg=    ${VALUE}",
			"VAR.asg.app=    ${VALUE}",
			"VAR.app.def+=   ${VALUE}",
			"VAR.app.asg+=   ${VALUE}",
			"VAR.app.app+=   ${VALUE}"),
		include("included2.mk",
			"VAR.def.def?=   ${OTHER}",
			"VAR.def.asg=    ${OTHER}",
			"VAR.def.app+=   ${OTHER}",
			"VAR.asg.def?=   ${OTHER}",
			"VAR.asg.asg=    ${OTHER}",
			"VAR.asg.app+=   ${OTHER}",
			"VAR.app.def?=   ${OTHER}",
			"VAR.app.asg=    ${OTHER}",
			"VAR.app.app+=   ${OTHER}"))
	mklines := get("including.mk")

	NewRedundantScope().Check(mklines)

	// Since the two included files are independent, there cannot be any
	// redundancies between them. Redundancies can only be discovered
	// when one of them includes the other.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_RedundantScope__file_hierarchy(c *check.C) {
	t := s.Init(c)

	include, get := t.SetUpHierarchy()

	include("including.mk",
		include("other.mk",
			"VAR=    other"),
		include("module.mk",
			"VAR=    module",
			include("version.mk",
				"VAR=    version"),
			include("env.mk",
				"VAR=     env")))

	NewRedundantScope().Check(get("including.mk"))

	// No output since the included files are independent.
	t.CheckOutputEmpty()

	NewRedundantScope().Check(get("other.mk"))

	// No output since the file by itself in neither redundant nor
	// does it include any other file.
	t.CheckOutputEmpty()

	NewRedundantScope().Check(get("module.mk"))

	// No warning about env.mk because it is independent from version.mk.
	// Pkglint only produces warnings when it is very sure that the variable
	// definition is really redundant in all cases.
	//
	// One reason to not warn is that at the point where env.mk is evaluated,
	// version.mk had last written to the variable. Since version.mk is
	// independent from env.mk, there is nothing redundant here.
	// Pkglint doesn't do this, but it could.
	//
	// Another reason not to warn is that all locations where the variable has
	// ever been accessed are saved. And if the current location neither includes
	// all of the others nor is included by all of the others, there is at least
	// one access that is in an unrelated file. This is what pkglint does.
	t.CheckOutputLines(
		"WARN: module.mk:1: Variable VAR is overwritten in version.mk:1.")
}

// The RedundantScope keeps track of the variable values. As a consequence,
// it reports the variable assignment in the last line as being redundant,
// instead of warning that it destroys the previous value.
func (s *Suite) Test_RedundantScope__assign_and_append_followed_by_assign(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("redundant.mk",
		"VAR=    first",
		"VAR+=   second",
		"VAR=    first second")

	NewRedundantScope().Check(mklines)

	t.CheckOutputLines(
		"NOTE: redundant.mk:3: Definition of VAR is redundant because of line 2.")
}

// The redundancy analysis for a variable VAR is influenced by changes to
// each variable that is referenced by VAR. The exact details also depend
// on the assignment operators being used for VAR and OTHER.
func (s *Suite) Test_RedundantScope__referenced_variable_is_modified(c *check.C) {
	t := s.Init(c)

	test := func(line1, line2, line3, line4 string, diagnostics ...string) {
		mklines := t.NewMkLines("filename.mk",
			line1, line2, line3, line4)

		NewRedundantScope().Check(mklines)

		t.CheckOutput(diagnostics)
	}

	test(
		"OTHER=  other-before",
		"VAR=    ${OTHER}",
		"OTHER?= other-after",
		"VAR=    ${OTHER}",

		// TODO: "3: has no effect"
		"NOTE: filename.mk:4: Definition of VAR is redundant because of line 2.")

	test(
		"OTHER=  other-before",
		"VAR=    ${OTHER}",
		"OTHER=  other-after",
		"VAR=    ${OTHER}",

		// TODO: "3: overwrites",
		"NOTE: filename.mk:4: Definition of VAR is redundant because of line 2.")

	test(
		"OTHER=  other-before",
		"VAR=    ${OTHER}",
		"OTHER+= other-after",
		"VAR=    ${OTHER}",

		"NOTE: filename.mk:4: Definition of VAR is redundant because of line 2.")

	test(
		"OTHER=  other-before",
		"VAR=    ${OTHER}",
		"OTHER:= other-after",
		"VAR=    ${OTHER}",

		// TODO: "3: overwrites line 1"
		"NOTE: filename.mk:4: Definition of VAR is redundant because of line 2.")

	test(
		"OTHER=  other-before",
		"VAR=    ${OTHER}",
		"OTHER!= other-after",
		"VAR=    ${OTHER}",

		// TODO: "3: overwrites line 1",
		"NOTE: filename.mk:4: Definition of VAR is redundant because of line 2.")
}

// The redundancy analysis for a variable VAR is influenced by changes to
// each variable that is referenced by VAR. The exact details also depend
// on the assignment operators being used for VAR and OTHER.
func (s *Suite) Test_RedundantScope__variable_referencing_another_is_modified(c *check.C) {
	t := s.Init(c)

	test := func(line1, line2, line3, line4 string, diagnostics ...string) {
		mklines := t.NewMkLines("filename.mk",
			line1, line2, line3, line4)

		NewRedundantScope().Check(mklines)

		t.CheckOutput(diagnostics)
	}

	// In this test, the second line is tested for each operator.

	test(
		"OTHER=  other-before",
		"VAR?=   ${OTHER}",
		"OTHER=  other-after",
		"VAR=    ${OTHER}",

		// TODO: "3: overwrites line 1"
		"NOTE: filename.mk:4: Definition of VAR is redundant because of line 2.")

	test(
		"OTHER=  other-before",
		"VAR=    ${OTHER}",
		"OTHER=  other-after",
		"VAR=    ${OTHER}",

		// TODO: "3: overwrites",
		"NOTE: filename.mk:4: Definition of VAR is redundant because of line 2.")

	test(
		"OTHER=  other-before",
		"VAR+=   ${OTHER}",
		"OTHER=  other-after",
		"VAR=    ${OTHER}",

		// TODO: "3: overwrites",
		// The value from line 2 is prefixed by a space, therefore pkglint
		// issues a warning here instead of an "is redundant" note.
		"WARN: filename.mk:2: Variable VAR is overwritten in line 4.")

	test(
		"OTHER=  other-before",
		"VAR:=   ${OTHER}",
		"OTHER=  other-after",
		"VAR=    ${OTHER}",

		// As of March 2019, pkglint only looks at each variable in isolation.
		// In this case, to detect that the assignment in line 1 has no effect,
		// it's necessary to trace the assignment in line 2 and then see that
		// the VAR from line 2 is immediately overwritten in line 4.
		"NOTE: filename.mk:4: Definition of VAR is redundant because of line 2.")

	test(
		"OTHER=  other-before",
		"VAR=    ${OTHER}",
		"OTHER!= other-after",
		"VAR=    ${OTHER}",

		"NOTE: filename.mk:4: Definition of VAR is redundant because of line 2.")
}

func (s *Suite) Test_RedundantScope__incomplete_then_default(c *check.C) {
	t := s.Init(c)

	include, get := t.SetUpHierarchy()

	include("including.mk",
		".if ${OPSYS} == NetBSD",
		"VAR=\tNetBSD",
		".elif ${OPSYS} == FreeBSD",
		"VAR=\tFreeBSD",
		".endif",
		"",
		"VAR?=\tdefault")

	mklines := get("including.mk")

	NewRedundantScope().Check(mklines)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_RedundantScope__complete_then_default(c *check.C) {
	t := s.Init(c)

	include, get := t.SetUpHierarchy()

	include("including.mk",
		".if ${OPSYS} == NetBSD",
		"VAR=\tNetBSD",
		".else",
		"VAR=\tFreeBSD",
		".endif",
		"",
		"VAR?=\tdefault")

	mklines := get("including.mk")

	NewRedundantScope().Check(mklines)

	// TODO: Pkglint could know that the ?= is redundant because VAR is
	//  definitely assigned.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_RedundantScope__conditional_then_override(c *check.C) {
	t := s.Init(c)

	include, get := t.SetUpHierarchy()

	include("including.mk",
		".if ${OPSYS} == NetBSD",
		"VAR=\tNetBSD",
		".else",
		"VAR=\tFreeBSD",
		".endif",
		"",
		"VAR=\tdefault")

	mklines := get("including.mk")

	NewRedundantScope().Check(mklines)

	// TODO: Pkglint could know that no matter which branch is taken,
	//  the variable will be overwritten in the last line.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_RedundantScope__set_then_conditional(c *check.C) {
	t := s.Init(c)

	include, get := t.SetUpHierarchy()

	include("including.mk",
		"VAR=\tdefault",
		"",
		".if ${OPSYS} == NetBSD",
		"VAR=\tNetBSD",
		".else",
		"VAR=\tFreeBSD",
		".endif")

	mklines := get("including.mk")

	NewRedundantScope().Check(mklines)

	// TODO: Pkglint could know that no matter which branch is taken,
	//  one of the branches will overwrite the assignment from line 1.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_RedundantScope__branch_with_set_then_set(c *check.C) {
	t := s.Init(c)

	include, get := t.SetUpHierarchy()

	include("including.mk",
		".if ${OPSYS} == NetBSD",
		"VAR=\tfirst",
		"VAR=\tsecond",
		".endif")

	mklines := get("including.mk")

	NewRedundantScope().Check(mklines)

	// TODO: Pkglint could know that the second assignment overwrites the
	//  first assignment since they are in the same basic block.
	t.CheckOutputEmpty()
}

// TODO: Continue the systematic redundancy tests.
//
// Tests where the variables are defined in a .for loop that might not be
// evaluated at all.
//
// Tests where files are included conditionally and additionally have conditional
// sections, arbitrarily nested.
//
// Tests that show how to suppress the notes about redundant assignments
// and overwritten variables. The explanation must be helpful.
//
// Tests for dynamic variable assignments. For example BUILD_DIRS.NetBSD may
// be modified by any assignment of the form BUILD_DIRS.${var} or even ${var}.
// Without further analysis, pkglint cannot report redundancy warnings for any
// package that uses such variable assignments.
//
// Tests for variables with modifiers, such as ${VAR:Uundef}, ${VAR:Mpattern},
// ${command:sh}, ${command::=value}.
//
// A test that compares a package with the default values from mk/defaults/mk.conf.
// A package doesn't need to override these defaults, and the redundancy check
// should notify the package author of this redundancy.

func (s *Suite) Test_RedundantScope__override_after_including(c *check.C) {
	t := s.Init(c)

	include, get := t.SetUpHierarchy()
	include("including.mk",
		include("included.mk",
			"OVERRIDE=       previous value",
			"REDUNDANT=      redundant"),
		"OVERRIDE=       overridden value",
		"REDUNDANT=      redundant")

	NewRedundantScope().Check(get("including.mk"))

	t.CheckOutputLines(
		"NOTE: including.mk:3: Definition of REDUNDANT is redundant because of included.mk:2.")
}

func (s *Suite) Test_RedundantScope__redundant_assign_after_including(c *check.C) {
	t := s.Init(c)

	include, get := t.SetUpHierarchy()
	include("including.mk",
		include("included.mk",
			"REDUNDANT=      redundant"),
		"REDUNDANT=      redundant")

	NewRedundantScope().Check(get("including.mk"))

	t.CheckOutputLines(
		"NOTE: including.mk:2: Definition of REDUNDANT is redundant because of included.mk:1.")
}

func (s *Suite) Test_RedundantScope__override_in_Makefile_after_including(c *check.C) {
	t := s.Init(c)

	include, get := t.SetUpHierarchy()
	include("Makefile",
		include("module.mk",
			"VAR=    value ${OTHER}",
			"VAR?=   value ${OTHER}",
			"VAR=    new value"),
		"VAR=    the package may overwrite variables from other files")

	// XXX: The warnings from here are not in the same order as the other warnings.
	// XXX: There may be some warnings for the same file separated by warnings for other files.
	NewRedundantScope().Check(get("Makefile"))

	// No warning for VAR=... in Makefile since it makes sense to have common files
	// with default values for variables, overriding some of them in each package.
	t.CheckOutputLines(
		"NOTE: module.mk:2: Default assignment of VAR has no effect because of line 1.",
		"WARN: module.mk:2: Variable VAR is overwritten in line 3.")
}

func (s *Suite) Test_RedundantScope__default_value_definitely_unused(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("module.mk",
		"VAR=    value ${OTHER}",
		"VAR?=   different value")

	NewRedundantScope().Check(mklines)

	// A default assignment after an unconditional assignment is redundant.
	// Even more so when the variable is not used between the two assignments.
	t.CheckOutputLines(
		"NOTE: module.mk:2: Default assignment of VAR has no effect because of line 1.")
}

func (s *Suite) Test_RedundantScope__default_value_overridden(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("module.mk",
		"VAR?=   default value",
		"VAR=    overridden value")

	NewRedundantScope().Check(mklines)

	t.CheckOutputLines(
		"WARN: module.mk:1: Variable VAR is overwritten in line 2.")
}

func (s *Suite) Test_RedundantScope__overwrite_same_value(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("module.mk",
		"VAR=    value ${OTHER}",
		"VAR=    value ${OTHER}")

	NewRedundantScope().Check(mklines)

	t.CheckOutputLines(
		"NOTE: module.mk:2: Definition of VAR is redundant because of line 1.")
}

func (s *Suite) Test_RedundantScope__conditional_overwrite(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("module.mk",
		"VAR=    default",
		".if ${OPSYS} == NetBSD",
		"VAR=    opsys",
		".endif")

	NewRedundantScope().Check(mklines)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_RedundantScope__overwrite_inside_conditional(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("module.mk",
		"VAR=    generic",
		".if ${OPSYS} == NetBSD",
		"VAR=    ignored",
		"VAR=    overwritten",
		".endif")

	NewRedundantScope().Check(mklines)

	// TODO: expected a warning "WARN: module.mk:4: line 3 is ignored"
	// Since line 3 and line 4 are in the same basic block, line 3 is definitely ignored.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_RedundantScope__conditionally_include(c *check.C) {
	t := s.Init(c)

	include, get := t.SetUpHierarchy()
	include("module.mk",
		"VAR=    generic",
		".if ${OPSYS} == NetBSD",
		include("included.mk",
			"VAR=    ignored",
			"VAR=    overwritten"),
		".endif")

	NewRedundantScope().Check(get("module.mk"))

	// TODO: expected a warning "WARN: module.mk:4: line 3 is ignored"
	//  Since line 3 and line 4 are in the same basic block, line 3 is definitely ignored.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_RedundantScope__conditional_default(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("module.mk",
		"VAR=    default",
		".if ${OPSYS} == NetBSD",
		"VAR?=   opsys",
		".endif")

	NewRedundantScope().Check(mklines)

	// TODO: WARN: module.mk:3: The value \"opsys\" will never be assigned
	//  to VAR because it is defined unconditionally in line 1.
	t.CheckOutputEmpty()
}

// These warnings are precise and accurate since the value of VAR is not used between line 2 and 4.
func (s *Suite) Test_RedundantScope__overwrite_same_variable_different_value(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("module.mk",
		"OTHER=  value before",
		"VAR=    value ${OTHER}",
		"OTHER=  value after",
		"VAR=    value ${OTHER}")

	NewRedundantScope().Check(mklines)

	// Strictly speaking, line 1 is redundant because OTHER is not evaluated
	// at load time and then immediately overwritten in line 3. If the operator
	// in line 2 were a := instead of a =, the situation would be clear.
	// Pkglint doesn't warn about the redundancy in line 1 because it prefers
	// to omit warnings instead of giving wrong advice.
	t.CheckOutputLines(
		"NOTE: module.mk:4: Definition of VAR is redundant because of line 2.")
}

func (s *Suite) Test_RedundantScope__overwrite_different_value_used_between(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("module.mk",
		"OTHER=          value before",
		"VAR=            value ${OTHER}",

		// VAR is used here at load time, therefore it must be defined at this point.
		// At this point, VAR uses the \"before\" value of OTHER.
		"RESULT1:=       ${VAR}",

		"OTHER=          value after",

		// VAR is used here again at load time, this time using the \"after\" value of OTHER.
		"RESULT2:=       ${VAR}",

		// Still this definition is redundant.
		"VAR=            value ${OTHER}")

	NewRedundantScope().Check(mklines)

	// There is nothing redundant here. Each write is followed by a
	// corresponding read, except for the last one. That is ok though
	// because in pkgsrc the last action of a package is to include
	// bsd.pkg.mk, which reads almost all variables.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_RedundantScope__procedure_call_to_noop(c *check.C) {
	t := s.Init(c)

	include, get := t.SetUpHierarchy()
	include("mk/pthread.buildlink3.mk",
		"CHECK_BUILTIN.pthread:= yes",
		include("pthread.builtin.mk",
			"# Nothing happens here."),
		"CHECK_BUILTIN.pthread:= no")

	NewRedundantScope().Check(get("mk/pthread.buildlink3.mk"))

	t.CheckOutputLines(
		"WARN: mk/pthread.buildlink3.mk:1: Variable CHECK_BUILTIN.pthread is overwritten in line 3.")
}

func (s *Suite) Test_RedundantScope__procedure_call_implemented(c *check.C) {
	t := s.Init(c)

	include, get := t.SetUpHierarchy()
	include("mk/pthread.buildlink3.mk",
		"CHECK_BUILTIN.pthread:= yes",
		include("pthread.builtin.mk",
			"CHECK_BUILTIN.pthread?= no",
			".if !empty(CHECK_BUILTIN.pthread:M[Nn][Oo])",
			".endif"),
		"CHECK_BUILTIN.pthread:= no")

	NewRedundantScope().Check(get("mk/pthread.buildlink3.mk"))

	// This test is a bit unrealistic. It wrongly assumes that all files from
	// an .include directive are actually included by pkglint.
	//
	// See Package.readMakefile/handleIncludeLine/skip.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_RedundantScope__procedure_call_implemented_package(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.SetUpPackage("devel/gettext-lib")
	t.SetUpPackage("x11/Xaos",
		".include \"../../devel/gettext-lib/buildlink3.mk\"")
	t.CreateFileLines("devel/gettext-lib/builtin.mk",
		MkCvsID,
		"",
		".include \"../../mk/bsd.fast.prefs.mk\"",
		"",
		"CHECK_BUILTIN.gettext?= no",
		".if !empty(CHECK_BUILTIN.gettext:M[nN][oO])",
		".endif")
	t.CreateFileLines("devel/gettext-lib/buildlink3.mk",
		MkCvsID,
		"CHECK_BUILTIN.gettext:= yes",
		".include \"builtin.mk\"",
		"CHECK_BUILTIN.gettext:= no")
	t.FinishSetUp()

	// Checking x11/Xaos instead of devel/gettext-lib avoids warnings
	// about the minimal buildlink3.mk file.
	G.Check(t.File("x11/Xaos"))

	// There is nothing redundant here.
	// Up to March 2019, pkglint didn't pass the correct pathnames to Package.included,
	// which triggered a wrong note here.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_RedundantScope__procedure_call_infrastructure(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("x11/alacarte",
		".include \"../../mk/pthread.buildlink3.mk\"")
	t.CreateFileLines("mk/pthread.buildlink3.mk",
		MkCvsID,
		"CHECK_BUILTIN.gettext:= yes",
		".include \"pthread.builtin.mk\"",
		"CHECK_BUILTIN.gettext:= no")
	t.CreateFileLines("mk/pthread.builtin.mk",
		MkCvsID,
		"CHECK_BUILTIN.gettext?= no",
		".if !empty(CHECK_BUILTIN.gettext:M[nN][oO])",
		".endif")
	t.FinishSetUp()

	G.Check(t.File("x11/alacarte"))

	// There is nothing redundant here.
	//
	// 1. pthread.buildlink3.mk sets the variable
	// 2. pthread.builtin.mk assigns it a default value
	//    (which is common practice)
	// 3. pthread.builtin.mk then reads it
	//    (which marks the next write as non-redundant)
	// 4. pthread.buildlink3.mk sets the variable again
	//    (this is considered neither overwriting nor redundant)
	//
	// Up to March 2019, pkglint complained:
	//
	// WARN: ~/mk/pthread.buildlink3.mk:2:
	//     Variable CHECK_BUILTIN.gettext is overwritten in line 4.
	//
	// The cause for the warning is that when including files from the
	// infrastructure, pkglint only includes the outermost level of files.
	// If an infrastructure file includes another infrastructure file,
	// pkglint skips that, for performance reasons.
	//
	// This optimization effectively made the .include for pthread.builtin.mk
	// a no-op, therefore it was correct to issue a warning here.
	//
	// Since this warning is wrong, in March 2019 another special rule has
	// been added to Package.readMakefile.handleIncludeLine.skip saying that
	// including a buildlink3.mk file also includes the corresponding
	// builtin.mk file.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_RedundantScope__shell_and_eval(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("module.mk",
		"VAR:=    value ${OTHER}",
		"VAR!=    value ${OTHER}")

	NewRedundantScope().Check(mklines)

	// As of November 2018, pkglint doesn't check redundancies that involve the := or != operators.
	//
	// What happens here is:
	//
	// Line 1 evaluates OTHER at load time.
	// Line 1 assigns its value to VAR.
	// Line 2 evaluates OTHER at load time.
	// Line 2 passes its value through the shell and assigns the result to VAR.
	//
	// Since VAR is defined in line 1, not used afterwards and overwritten in line 2, it is redundant.
	// Well, not quite, because evaluating ${OTHER} might have side-effects from :sh or ::= modifiers,
	// but these are so rare that they are frowned upon and are not considered by pkglint.
	//
	// Expected result:
	// WARN: module.mk:2: Previous definition of VAR in line 1 is unused.

	t.CheckOutputEmpty()
}

func (s *Suite) Test_RedundantScope__shell_and_eval_literal(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("module.mk",
		"VAR:=    value",
		"VAR!=    value")

	NewRedundantScope().Check(mklines)

	// Even when := is used with a literal value (which is usually
	// only done for procedure calls), the shell evaluation can have
	// so many different side effects that pkglint cannot reliably
	// help in this situation.
	//
	// TODO: Why not? The evaluation in line 1 is trivial to analyze.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_RedundantScope__included_OPSYS_variable(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"../../category/dependency/buildlink3.mk\"",
		"CONFIGURE_ARGS+=        one",
		"CONFIGURE_ARGS=         two",
		"CONFIGURE_ARGS+=        three")
	t.SetUpPackage("category/dependency")
	t.CreateFileBuildlink3("category/dependency/buildlink3.mk")
	t.CreateFileLines("category/dependency/builtin.mk",
		MkCvsID,
		"CONFIGURE_ARGS.Darwin+= darwin")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:21: Variable CONFIGURE_ARGS is overwritten in line 22.")
}

func (s *Suite) Test_RedundantScope__if_then_else(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("if-then-else.mk",
		".if exists(${FILE})",
		"OS=     NetBSD",
		".else",
		"OS=     OTHER",
		".endif")

	NewRedundantScope().Check(mklines)

	// These two definitions are of course not redundant since they happen in
	// different branches of the same .if statement.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_RedundantScope__if_then_else_without_variable(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("if-then-else.mk",
		".if exists(/nonexistent)",
		"IT=     exists",
		".else",
		"IT=     doesn't exist",
		".endif")

	NewRedundantScope().Check(mklines)

	// These two definitions are of course not redundant since they happen in
	// different branches of the same .if statement.
	// Even though the .if condition does not refer to any variables,
	// this still means that the variable assignments are conditional.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_RedundantScope__append_then_default(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("append-then-default.mk",
		"VAR+=   value",
		"VAR?=   value")

	NewRedundantScope().Check(mklines)

	t.CheckOutputLines(
		"NOTE: append-then-default.mk:2: Default assignment of VAR has no effect because of line 1.")
}

func (s *Suite) Test_RedundantScope__assign_then_default_in_same_file(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("assign-then-default.mk",
		"VAR=    value",
		"VAR?=   value")

	NewRedundantScope().Check(mklines)

	t.CheckOutputLines(
		"NOTE: assign-then-default.mk:2: " +
			"Default assignment of VAR has no effect because of line 1.")
}

func (s *Suite) Test_RedundantScope__eval_then_eval(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		"VAR:=   value",
		"VAR:=   value",
		"VAR:=   other")

	NewRedundantScope().Check(mklines)

	t.CheckOutputLines(
		"NOTE: filename.mk:2: Definition of VAR is redundant because of line 1.",
		"WARN: filename.mk:2: Variable VAR is overwritten in line 3.")
}

func (s *Suite) Test_RedundantScope__shell_then_assign(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		"VAR!=   echo echo",
		"VAR=    echo echo")

	NewRedundantScope().Check(mklines)

	// Although the two variable assignments look very similar, they do
	// something entirely different. The first executes the echo command,
	// and the second just assigns a string. Therefore the actual variable
	// values are different, and the second assignment is not redundant.
	// It assigns a different value. Nevertheless, the shell command is
	// redundant and can be removed since its result is never used.
	t.CheckOutputLines(
		"WARN: filename.mk:1: Variable VAR is overwritten in line 2.")
}

func (s *Suite) Test_RedundantScope__shell_then_read_then_assign(c *check.C) {
	t := s.Init(c)

	mklines := t.SetUpFileMkLines("filename.mk",
		"VAR!=           echo echo",
		"OUTPUT:=        ${VAR}",
		"VAR=            echo echo")

	NewRedundantScope().Check(mklines)

	// No warning since the value is used in-between.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_RedundantScope__assign_then_default_in_included_file(c *check.C) {
	t := s.Init(c)

	include, get := t.SetUpHierarchy()
	include("assign-then-default.mk",
		"VAR=    value",
		include("included.mk",
			"VAR?=    value"))

	NewRedundantScope().Check(get("assign-then-default.mk"))

	// If assign-then-default.mk:1 were deleted, VAR would still have the same value.
	t.CheckOutputLines(
		"NOTE: assign-then-default.mk:1: Definition of VAR is redundant because of included.mk:1.")
}

func (s *Suite) Test_RedundantScope__conditionally_included_file(c *check.C) {
	t := s.Init(c)

	include, get := t.SetUpHierarchy()
	include("including.mk",
		"VAR=    value",
		".if ${COND}",
		include("included.mk",
			"VAR?=   value"),
		".endif")

	NewRedundantScope().Check(get("including.mk"))

	// The assignment in including.mk:2 is only redundant if included.mk is actually included.
	// Therefore both included.mk:2 nor including.mk:2 are relevant.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_RedundantScope__procedure_parameters(c *check.C) {
	t := s.Init(c)

	// TODO: make Tester.SetUpHierarchy accept a file multiple times.
	t.CreateFileLines("mk/pkg-build-options.mk",
		"USED:=  ${pkgbase}")
	t.CreateFileLines("including.mk",
		"pkgbase= package1",
		".include \"mk/pkg-build-options.mk\"",
		"",
		"pkgbase= package2",
		".include \"mk/pkg-build-options.mk\"",
		"",
		"pkgbase= package3",
		".include \"mk/pkg-build-options.mk\"")
	mklines := t.LoadMkInclude("including.mk")

	NewRedundantScope().Check(mklines)

	// This variable is not overwritten since it is used in-between
	// by the included file.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_RedundantScope__is_relevant_for_infrastructure(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/bsd.options.mk",
		"PKG_OPTIONS:=\t# empty",
		"PKG_OPTIONS=\t# empty",
		"PKG_OPTIONS=\toverwritten")
	t.CreateFileLines("options.mk",
		"OUTSIDE:=\t# empty",
		"OUTSIDE=\t# empty",
		"OUTSIDE=\toverwritten",
		".include \"mk/bsd.options.mk\"")

	test := func(diagnostics ...string) {
		mklines := t.LoadMkInclude("options.mk")
		scope := NewRedundantScope()
		scope.IsRelevant = func(mkline *MkLine) bool {
			// See checkfilePackageMakefile.
			return G.CheckGlobal || !G.Pkgsrc.IsInfra(mkline.Filename())
		}

		scope.Check(mklines)

		// No note about the redundant variable assignment in bsd.options.mk
		// because it is part of the infrastructure, which is filtered out.
		t.CheckOutput(diagnostics)
	}

	test(
		"NOTE: ~/options.mk:2: "+
			"Definition of OUTSIDE is redundant because of line 1.",
		"WARN: ~/options.mk:2: "+
			"Variable OUTSIDE is overwritten in line 3.")

	t.SetUpCommandLine("-Cglobal")

	test(
		"NOTE: ~/options.mk:2: "+
			"Definition of OUTSIDE is redundant because of line 1.",
		"WARN: ~/options.mk:2: "+
			"Variable OUTSIDE is overwritten in line 3.",
		"NOTE: ~/mk/bsd.options.mk:2: "+
			"Definition of PKG_OPTIONS is redundant because of line 1.",
		"WARN: ~/mk/bsd.options.mk:2: "+
			"Variable PKG_OPTIONS is overwritten in line 3.")
}

// Branch coverage for info.vari.IsConstant(). The other tests typically
// make a variable non-constant by adding conditional assignments between
// .if/.endif. But there are other ways. The output of shell commands is
// unpredictable for pkglint (as of March 2019), therefore it treats these
// variables as non-constant.
func (s *Suite) Test_RedundantScope_handleVarassign__shell_followed_by_default(c *check.C) {
	t := s.Init(c)

	include, get := t.SetUpHierarchy()
	include("including.mk",
		"VAR!=   echo 'hello, world'",
		include("included.mk",
			"VAR?=   hello world"))

	NewRedundantScope().Check(get("including.mk"))

	// If pkglint should ever learn to interpret simple shell commands, there
	// should be a warning for including.mk:2 that the shell command generates
	// the default value.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_RedundantScope_handleVarassign__overwrite_definition_from_included_file(c *check.C) {
	t := s.Init(c)

	include, get := t.SetUpHierarchy()
	include("including.mk",
		"SUBDIR= ${WRKSRC}",
		include("included.mk",
			"WRKSRC= ${WRKDIR}/${PKGBASE}"),
		"WRKSRC= ${WRKDIR}/overwritten")

	NewRedundantScope().Check(get("including.mk"))

	// Before pkglint 5.7.2 (2019-03-10), the above setup generated a warning:
	//
	// WARN: ~/included.mk:2: Variable WRKSRC is overwritten in including.mk:4.
	//
	// This warning is obviously wrong since the included file must never
	// receive a warning. Of course this default definition may be overridden
	// by the including file.
	//
	// The warning was generated because in including.mk:2 the variable WRKSRC
	// was used for the first time. Back then, each variable had only a single
	// include path. That include path marks where the variable is used and
	// defined.
	//
	// The variable definition at included.mk didn't modify this include path.
	// Therefore pkglint wrongly assumed that this variable was only ever
	// accessed in including.mk and issued a warning.
	//
	// To fix this, the RedundantScope now remembers every access to the
	// variable, and the redundancy warnings are only issued in cases where
	// either all variable accesses are in files including the current file,
	// or all variable accesses are in files included by the current file.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_RedundantScope_handleVarassign__conditional(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		"VAR=    value",
		".if 1",
		"VAR=    conditional",
		".endif")

	scope := NewRedundantScope()
	scope.Check(mklines)
	writeLocations := scope.get("VAR").vari.WriteLocations()

	t.CheckDeepEquals(
		writeLocations,
		[]*MkLine{mklines.mklines[0], mklines.mklines[2]})
}

// Ensures that commented variables do not influence the redundancy check.
func (s *Suite) Test_RedundantScope_handleVarassign__commented_variable_assignment(c *check.C) {
	t := s.Init(c)

	include, get := t.SetUpHierarchy()
	include("main.mk",
		include("redundant.mk",
			"VAR=    value"),
		include("doc.mk",
			"#OTHER= ${VAR}"),
		"VAR=     value",
		"OTHER=   value")

	NewRedundantScope().Check(get("main.mk"))

	t.CheckOutputLines(
		"NOTE: main.mk:3: Definition of VAR is redundant because of redundant.mk:1.")
}

func (s *Suite) Test_RedundantScope_handleVarassign__assign_then_eval(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("mk/bsd.options.mk",
		"PKG_OPTIONS=\t# empty",
		"PKG_OPTIONS:=\t# empty")

	scope := NewRedundantScope()
	scope.Check(mklines)

	t.CheckOutputLines(
		"NOTE: mk/bsd.options.mk:2: " +
			"Definition of PKG_OPTIONS is redundant because of line 1.")
}

func (s *Suite) Test_RedundantScope_checkAppendUnique__redundant_before_including(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"CATEGORIES=\tcategory perl5",
		".include \"included.mk\"")
	t.CreateFileLines("category/package/included.mk",
		MkCvsID,
		"CATEGORIES+=\tperl5 python",
		"CATEGORIES+=\tpython",
		"CATEGORIES?=\tcategory japanese")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	// The second line sounds a bit strange since it references a line
	// further down in the file. It's correct though.
	t.CheckOutputLines(
		"NOTE: Makefile:5: Adding \"perl5\" to CATEGORIES is redundant "+
			"because it will later be appended in included.mk:2.",
		"NOTE: included.mk:2: Adding \"python\" to CATEGORIES is redundant "+
			"because it will later be appended in line 3.")
}

func (s *Suite) Test_RedundantScope_checkAppendUnique__redundant_after_including(c *check.C) {
	t := s.Init(c)

	// The assignment to CATEGORIES must be commented out in this test.
	// The redundancy check only works if either _all_ previous variable
	// assignments happen in included files or if _all_ previous variable
	// assignments happen in including files.
	//
	// See Tester.SetUpPackage for the magic that is involved in defining
	// a package during testing. That magic is also the reason for having
	// both included1.mk and included2.mk.
	t.SetUpPackage("category/package",
		"#CATEGORIES=\tcategory",
		".include \"included1.mk\"")
	t.CreateFileLines("category/package/included1.mk",
		MkCvsID,
		".include \"included2.mk\"",
		"CATEGORIES+=\tcategory perl5 python japanese")
	t.CreateFileLines("category/package/included2.mk",
		MkCvsID,
		"CATEGORIES+=\tcategory perl5 japanese chinese")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"NOTE: included1.mk:3: Appending \"category\" to CATEGORIES is redundant "+
			"because it is already added in included2.mk:2.",
		"NOTE: included1.mk:3: Appending \"perl5\" to CATEGORIES is redundant "+
			"because it is already added in included2.mk:2.",
		"NOTE: included1.mk:3: Appending \"japanese\" to CATEGORIES is redundant "+
			"because it is already added in included2.mk:2.")
}

func (s *Suite) Test_RedundantScope_checkAppendUnique__redundant_and_later_conditional(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"CATEGORIES=\tcategory",
		".include \"included.mk\"")
	t.CreateFileLines("category/package/included.mk",
		MkCvsID,
		"CATEGORIES+=\tperl5 python",
		"CATEGORIES+=\tpython",
		"CATEGORIES?=\tcategory japanese",
		"",
		".if 1",
		"CATEGORIES+=\tchinese",
		".endif")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	// Even though the "chinese" category is conditional, pkglint can
	// diagnose that everything that happens before that conditional
	// assignment adds to the constant value of the variable.
	// Therefore it flags the duplicate category "python".
	t.CheckOutputLines(
		"NOTE: included.mk:2: Adding \"python\" to CATEGORIES is redundant " +
			"because it will later be appended in line 3.")
}

// The := assignment operator is equivalent to the simple = operator
// if its right-hand side does not contain references to any variables.
func (s *Suite) Test_RedundantScope_checkAppendUnique__eval_assignment(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"CATEGORIES:=\tcategory",
		".include \"included.mk\"")
	t.CreateFileLines("category/package/included.mk",
		MkCvsID,
		"CATEGORIES+=\tcategory")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"NOTE: Makefile:5: Adding \"category\" to CATEGORIES is redundant " +
			"because it will later be appended in included.mk:2.")
}

func (s *Suite) Test_RedundantScope_checkAppendUnique__not_redundant(c *check.C) {
	t := s.Init(c)

	t.SetUpCategory("perl")
	t.SetUpPackage("category/package",
		"CATEGORIES:=\tcategory",
		".include \"included1.mk\"",
		".include \"included2.mk\"")
	t.Chdir("category/package")
	t.CreateFileLines("included1.mk",
		MkCvsID,
		"CATEGORIES+=\tperl")
	t.CreateFileLines("included2.mk",
		MkCvsID,
		"CATEGORIES+=\tperl")
	t.FinishSetUp()

	G.Check(".")

	// The additions in included1.mk and included2.mk are not redundant
	// since neither of them includes the other.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_includePath_includes(c *check.C) {
	t := s.Init(c)

	path := func(locations ...CurrPath) includePath {
		return includePath{locations}
	}

	var (
		m   = path("Makefile")
		mc  = path("Makefile", "Makefile.common")
		mco = path("Makefile", "Makefile.common", "other.mk")
		mo  = path("Makefile", "other.mk")
	)

	t.CheckEquals(m.includes(m), false)

	t.CheckEquals(m.includes(mc), true)
	t.CheckEquals(m.includes(mco), true)
	t.CheckEquals(mc.includes(mco), true)

	t.CheckEquals(mc.includes(m), false)
	t.CheckEquals(mc.includes(mo), false)
	t.CheckEquals(mo.includes(mc), false)
}

func (s *Suite) Test_includePath_equals(c *check.C) {
	t := s.Init(c)

	path := func(locations ...CurrPath) includePath {
		return includePath{locations}
	}

	var (
		m   = path("Makefile")
		mc  = path("Makefile", "Makefile.common")
		mco = path("Makefile", "Makefile.common", "other.mk")
		mo  = path("Makefile", "other.mk")
	)

	t.CheckEquals(m.equals(m), true)

	t.CheckEquals(m.equals(mc), false)
	t.CheckEquals(m.equals(mco), false)
	t.CheckEquals(mc.equals(mco), false)

	t.CheckEquals(mc.equals(m), false)
	t.CheckEquals(mc.equals(mo), false)
	t.CheckEquals(mo.equals(mc), false)
}
