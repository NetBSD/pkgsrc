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

func (s *Suite) captureTracingOutput(action func()) string {
	out := bytes.Buffer{}
	Out = &out
	Tracing = true

	action()

	Tracing = false
	Out = nil
	return out.String()
}
