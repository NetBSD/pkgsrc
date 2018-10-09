package trace

import (
	"bytes"
	"gopkg.in/check.v1"
	"testing"
)

type Suite struct{}

var _ = check.Suite(new(Suite))

func Test(t *testing.T) { check.TestingT(t) }

func onlyArguments(args ...interface{}) {
	defer Call(args...)()
	Stepf("Running %q", "code")
}

func argumentsAndResult(arg0 string, arg1 int) (result string) {
	defer Call(arg0, arg1, Result(&result))()
	Stepf("Running %q", "code")
	return "the result"
}

func argumentsAndResultWrong(arg0 string, arg1 int) (result string) {
	defer Call(arg0, arg1, result)() // "result" is evaluated too early and only once.
	Stepf("Running %q", "code")
	return "the result"
}

func (s *Suite) Test_Call__onlyArguments(c *check.C) {

	output := s.captureTracingOutput(func() {
		onlyArguments("arg0", 1234)
	})

	c.Check(output, check.Equals, ""+
		"TRACE: + netbsd.org/pkglint/trace.onlyArguments(\"arg0\", 1234)\n"+
		"TRACE: 1   Running \"code\"\n"+
		"TRACE: - netbsd.org/pkglint/trace.onlyArguments(\"arg0\", 1234)\n")
}

func (s *Suite) Test_Call__argumentsAndResult(c *check.C) {

	output := s.captureTracingOutput(func() {
		argumentsAndResult("arg0", 1234)
	})

	c.Check(output, check.Equals, ""+
		"TRACE: + netbsd.org/pkglint/trace.argumentsAndResult(\"arg0\", 1234)\n"+
		"TRACE: 1   Running \"code\"\n"+
		"TRACE: - netbsd.org/pkglint/trace.argumentsAndResult(\"arg0\", 1234, \"=>\", \"the result\")\n")
}

func (s *Suite) Test_Call__argumentsAndResultWrong(c *check.C) {

	output := s.captureTracingOutput(func() {
		argumentsAndResultWrong("arg0", 1234)
	})

	c.Check(output, check.Equals, ""+
		"TRACE: + netbsd.org/pkglint/trace.argumentsAndResultWrong(\"arg0\", 1234, \"\")\n"+
		"TRACE: 1   Running \"code\"\n"+
		"TRACE: - netbsd.org/pkglint/trace.argumentsAndResultWrong(\"arg0\", 1234, \"\")\n")
}

func (s *Suite) Test__fixed_argument_variants(c *check.C) {

	output := s.captureTracingOutput(func() {
		defer Call0()()
		defer Call1("x")()
		defer Call2("x", "y")()
		Step1("step %s", "a")
		Step2("step %s, %s", "a", "b")
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

	output := s.captureTracingOutput(func() {
		defer Call(str{}, &str{})()
	})

	c.Check(output, check.Equals, ""+
		"TRACE: + netbsd.org/pkglint/trace.(*Suite).Test__stringer_arg.func1(It's a string, It's a string)\n"+
		"TRACE: - netbsd.org/pkglint/trace.(*Suite).Test__stringer_arg.func1(It's a string, It's a string)\n")
}

func (s *Suite) Test_traceCall__panic(c *check.C) {
	c.Check(
		func() { traceCall() },
		check.Panics,
		"Internal pkglint error: calls to trace.Call must only occur in tracing mode")
}

func (s *Suite) Test_Result__panic(c *check.C) {
	c.Check(
		func() { Result("invalid argument") },
		check.Panics,
		"Result must be called with a pointer to the result, not \"invalid argument\".")
}

func (s *Suite) captureTracingOutput(action func()) string {
	out := bytes.Buffer{}
	Out = &out
	Tracing = true

	action()

	Tracing = false
	Out = nil
	return out.String()
}

type str struct{}

func (str) String() string {
	return "It's a string"
}
