package pkglint

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_RawLine_String(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename", 123, "text")

	t.CheckEquals(line.raw[0].String(), "123:text\n")
}

func (s *Suite) Test_NewLine__assertion(c *check.C) {
	t := s.Init(c)

	t.ExpectAssert(func() { NewLine("filename", 123, "text", nil) })
}

func (s *Suite) Test_Line_IsMultiline(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(t.NewLine("filename", 123, "text").IsMultiline(), false)
	t.CheckEquals(NewLineEOF("filename").IsMultiline(), false)

	t.CheckEquals(NewLineMulti("filename", 123, 125, "text", nil).IsMultiline(), true)
}

// In case of a fatal error, pkglint quits in a controlled manner,
// and the trace log shows where the fatal error happened.
func (s *Suite) Test_Line_Fatalf__trace(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename", 123, "")
	t.EnableTracingToLog()

	inner := func() {
		defer trace.Call0()()
		line.Fatalf("Cannot continue because of %q and %q.", "reason 1", "reason 2")
	}
	outer := func() {
		defer trace.Call0()()
		inner()
	}

	t.ExpectFatal(
		outer,
		"TRACE: + (*Suite).Test_Line_Fatalf__trace.func2()",
		"TRACE: 1 + (*Suite).Test_Line_Fatalf__trace.func1()",
		"TRACE: 1 2   Fatalf: \"Cannot continue because of %q and %q.\", [reason 1 reason 2]",
		"TRACE: 1 - (*Suite).Test_Line_Fatalf__trace.func1()",
		"TRACE: - (*Suite).Test_Line_Fatalf__trace.func2()",
		"FATAL: filename:123: Cannot continue because of \"reason 1\" and \"reason 2\".")
}
