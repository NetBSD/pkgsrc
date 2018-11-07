package trace

import (
	"bytes"
	"gopkg.in/check.v1"
	"netbsd.org/pkglint/intqa"
	"testing"
)

type Suite struct {
	Tracer Tracer
}

var _ = check.Suite(new(Suite))

func Test(t *testing.T) { check.TestingT(t) }

func (t *Tracer) onlyArguments(args ...interface{}) {
	defer t.Call(args...)()
	t.Stepf("Running %q", "code")
}

func (t *Tracer) argumentsAndResult(arg0 string, arg1 int) (result string) {
	defer t.Call(arg0, arg1, t.Result(&result))()
	t.Stepf("Running %q", "code")
	return "the result"
}

func (t *Tracer) argumentsAndResultWrong(arg0 string, arg1 int) (result string) {
	defer t.Call(arg0, arg1, result)() // "result" is evaluated too early and only once.
	t.Stepf("Running %q", "code")
	return "the result"
}

func (s *Suite) Test_Tracer_Call__only_arguments(c *check.C) {
	tracer := &s.Tracer

	output := s.captureTracingOutput(func() {
		tracer.onlyArguments("arg0", 1234)
	})

	c.Check(output, check.Equals, ""+
		"TRACE: + netbsd.org/pkglint/trace.(*Tracer).onlyArguments(\"arg0\", 1234)\n"+
		"TRACE: 1   Running \"code\"\n"+
		"TRACE: - netbsd.org/pkglint/trace.(*Tracer).onlyArguments(\"arg0\", 1234)\n")
}

func (s *Suite) Test_Tracer_Call__arguments_and_result(c *check.C) {
	tracer := &s.Tracer

	output := s.captureTracingOutput(func() {
		tracer.argumentsAndResult("arg0", 1234)
	})

	c.Check(output, check.Equals, ""+
		"TRACE: + netbsd.org/pkglint/trace.(*Tracer).argumentsAndResult(\"arg0\", 1234)\n"+
		"TRACE: 1   Running \"code\"\n"+
		"TRACE: - netbsd.org/pkglint/trace.(*Tracer).argumentsAndResult(\"arg0\", 1234, \"=>\", \"the result\")\n")
}

func (s *Suite) Test_Tracer_Call__arguments_and_result_wrong(c *check.C) {
	tracer := &s.Tracer

	output := s.captureTracingOutput(func() {
		tracer.argumentsAndResultWrong("arg0", 1234)
	})

	c.Check(output, check.Equals, ""+
		"TRACE: + netbsd.org/pkglint/trace.(*Tracer).argumentsAndResultWrong(\"arg0\", 1234, \"\")\n"+
		"TRACE: 1   Running \"code\"\n"+
		"TRACE: - netbsd.org/pkglint/trace.(*Tracer).argumentsAndResultWrong(\"arg0\", 1234, \"\")\n")
}

func (s *Suite) Test__fixed_argument_variants(c *check.C) {
	tracer := &s.Tracer

	output := s.captureTracingOutput(func() {
		defer tracer.Call0()()
		defer tracer.Call1("x")()
		defer tracer.Call2("x", "y")()
		tracer.Step1("step %s", "a")
		tracer.Step2("step %s, %s", "a", "b")
	})

	c.Check(output, check.Equals, ""+
		"TRACE: + netbsd.org/pkglint/trace.(*Suite).Test__fixed_argument_variants.func1()\n"+
		"TRACE: 1 + netbsd.org/pkglint/trace.(*Suite).Test__fixed_argument_variants.func1(\"x\")\n"+
		"TRACE: 1 2 + netbsd.org/pkglint/trace.(*Suite).Test__fixed_argument_variants.func1(\"x\", \"y\")\n"+
		"TRACE: 1 2 3   step a\n"+
		"TRACE: 1 2 3   step a, b\n"+
		"TRACE: 1 2 - netbsd.org/pkglint/trace.(*Suite).Test__fixed_argument_variants.func1(\"x\", \"y\")\n"+
		"TRACE: 1 - netbsd.org/pkglint/trace.(*Suite).Test__fixed_argument_variants.func1(\"x\")\n"+
		"TRACE: - netbsd.org/pkglint/trace.(*Suite).Test__fixed_argument_variants.func1()\n")
}

func (s *Suite) Test__stringer_arg(c *check.C) {
	tracer := &s.Tracer

	output := s.captureTracingOutput(func() {
		defer tracer.Call(str{}, &str{})()
	})

	c.Check(output, check.Equals, ""+
		"TRACE: + netbsd.org/pkglint/trace.(*Suite).Test__stringer_arg.func1(It's a string, It's a string)\n"+
		"TRACE: - netbsd.org/pkglint/trace.(*Suite).Test__stringer_arg.func1(It's a string, It's a string)\n")
}

func (s *Suite) Test_Tracer_traceCall__panic(c *check.C) {
	tracer := &s.Tracer

	c.Check(
		func() { tracer.traceCall() },
		check.Panics,
		"Internal pkglint error: calls to trace.Call must only occur in tracing mode")
}

func (s *Suite) Test_Tracer_Result__panic(c *check.C) {
	tracer := &s.Tracer

	c.Check(
		func() { tracer.Result("invalid argument") },
		check.Panics,
		"Result must be called with a pointer to the result, not \"invalid argument\".")
}

func (s *Suite) captureTracingOutput(action func()) string {
	tracer := &s.Tracer

	out := bytes.Buffer{}
	tracer.Out = &out
	tracer.Tracing = true

	action()

	tracer.Tracing = false
	tracer.Out = nil
	return out.String()
}

type str struct{}

func (str) String() string {
	return "It's a string"
}

func (s *Suite) Test__test_names(c *check.C) {
	ck := intqa.NewTestNameChecker(c)
	ck.AllowCamelCaseDescriptions()
	ck.ShowWarnings(false)
	ck.Check()
}
