package intqa

import (
	"bytes"
	"fmt"
	"gopkg.in/check.v1"
	"io/ioutil"
	"testing"
)

type Suite struct {
	c       *check.C
	ck      *TestNameChecker
	summary string
}

func Test(t *testing.T) {
	check.Suite(&Suite{})
	check.TestingT(t)
}

func (s *Suite) Init(c *check.C) *TestNameChecker {
	errorf := func(format string, args ...interface{}) {
		s.summary = fmt.Sprintf(format, args...)
	}

	s.c = c
	s.ck = NewTestNameChecker(errorf)
	s.ck.Enable(EAll)
	s.ck.out = ioutil.Discard
	return s.ck
}

func (s *Suite) TearDownTest(c *check.C) {
	s.c = c
	s.CheckErrors(nil...)
	s.CheckSummary("")
}

func (s *Suite) CheckErrors(errors ...string) {
	s.c.Check(s.ck.errors, check.DeepEquals, errors)
	s.ck.errors = nil
}

func (s *Suite) CheckSummary(summary string) {
	s.c.Check(s.summary, check.Equals, summary)
	s.summary = ""
}

func (s *Suite) Test_TestNameChecker_Check(c *check.C) {
	ck := s.Init(c)

	ck.Check()

	s.CheckErrors(
		"Missing unit test \"Test_NewTestNameChecker\" for \"NewTestNameChecker\".",
		"Missing unit test \"Test_TestNameChecker_IgnoreFiles\" for \"TestNameChecker.IgnoreFiles\".",
		"Missing unit test \"Test_TestNameChecker_Enable\" for \"TestNameChecker.Enable\".",
		"Missing unit test \"Test_TestNameChecker_load\" for \"TestNameChecker.load\".",
		"Missing unit test \"Test_TestNameChecker_loadDecl\" for \"TestNameChecker.loadDecl\".",
		"Missing unit test \"Test_TestNameChecker_addCode\" for \"TestNameChecker.addCode\".",
		"Missing unit test \"Test_TestNameChecker_addTestee\" for \"TestNameChecker.addTestee\".",
		"Missing unit test \"Test_TestNameChecker_nextOrder\" for \"TestNameChecker.nextOrder\".",
		"Missing unit test \"Test_TestNameChecker_relate\" for \"TestNameChecker.relate\".",
		"Missing unit test \"Test_TestNameChecker_checkTests\" for \"TestNameChecker.checkTests\".",
		"Missing unit test \"Test_TestNameChecker_checkTestees\" for \"TestNameChecker.checkTestees\".",
		"Missing unit test \"Test_TestNameChecker_isIgnored\" for \"TestNameChecker.isIgnored\".",
		"Missing unit test \"Test_TestNameChecker_addError\" for \"TestNameChecker.addError\".",
		"Missing unit test \"Test_Test\" for \"Test\".",
		"Missing unit test \"Test_Suite_Init\" for \"Suite.Init\".",
		"Missing unit test \"Test_Suite_TearDownTest\" for \"Suite.TearDownTest\".",
		"Missing unit test \"Test_Suite_CheckErrors\" for \"Suite.CheckErrors\".",
		"Missing unit test \"Test_Suite_CheckSummary\" for \"Suite.CheckSummary\".",
		"Missing unit test \"Test_Value_Method\" for \"Value.Method\".")
	s.CheckSummary("19 errors.")
}

func (s *Suite) Test_TestNameChecker_addTest(c *check.C) {
	ck := s.Init(c)

	ck.addTest(code{"filename.go", "Type", "Method", 0})

	s.CheckErrors(
		"Test \"Type.Method\" must start with \"Test_\".")
}

func (s *Suite) Test_TestNameChecker_addTest__empty_description(c *check.C) {
	ck := s.Init(c)

	ck.addTest(code{"filename.go", "Suite", "Test_Method__", 0})

	s.CheckErrors(
		"Test \"Suite.Test_Method__\" must not have a nonempty description.")
}

func (s *Suite) Test_TestNameChecker_checkTestFile__global(c *check.C) {
	ck := s.Init(c)

	ck.checkTestFile(&test{
		code{"demo_test.go", "Suite", "Test__Global", 0},
		"",
		"",
		&testee{code{"other.go", "", "Global", 0}}})

	s.CheckErrors(
		"Test \"Suite.Test__Global\" for \"Global\" " +
			"must be in other_test.go instead of demo_test.go.")
}

func (s *Suite) Test_TestNameChecker_checkTestTestee__global(c *check.C) {
	ck := s.Init(c)

	ck.checkTestTestee(&test{
		code{"demo_test.go", "Suite", "Test__Global", 0},
		"",
		"",
		nil})

	s.CheckErrors(
		nil...)
}

func (s *Suite) Test_TestNameChecker_checkTestTestee__no_testee(c *check.C) {
	ck := s.Init(c)

	ck.checkTestTestee(&test{
		code{"demo_test.go", "Suite", "Test_Missing", 0},
		"Missing",
		"",
		nil})

	s.CheckErrors(
		"Missing testee \"Missing\" for test \"Suite.Test_Missing\".")
}

func (s *Suite) Test_TestNameChecker_checkTestTestee__testee_exists(c *check.C) {
	ck := s.Init(c)

	ck.checkTestTestee(&test{
		code{"demo_test.go", "Suite", "Test_Missing", 0},
		"Missing",
		"",
		&testee{}})

	s.CheckErrors(
		nil...)
}

func (s *Suite) Test_TestNameChecker_checkTestName__camel_case(c *check.C) {
	ck := s.Init(c)

	ck.checkTestName(&test{
		code{"demo_test.go", "Suite", "Test_Missing__CamelCase", 0},
		"Missing",
		"CamelCase",
		&testee{}})

	s.CheckErrors(
		"Suite.Test_Missing__CamelCase: Test description \"CamelCase\" " +
			"must not use CamelCase in the first word.")
}

func (s *Suite) Test_TestNameChecker_checkOrder(c *check.C) {
	ck := s.Init(c)

	ck.addTestee(code{"f.go", "T", "", 10})
	ck.addTestee(code{"f.go", "T", "M1", 11})
	ck.addTestee(code{"f.go", "T", "M2", 12})
	ck.addTestee(code{"f.go", "T", "M3", 13})
	ck.addTest(code{"f_test.go", "S", "Test_T_M1", 100})    // maxTestee = 11
	ck.addTest(code{"f_test.go", "S", "Test_T_M2", 101})    // maxTestee = 12
	ck.addTest(code{"f_test.go", "S", "Test_T", 102})       // testee 10 < maxTestee 12: insert before first [.testee > testee 10] == T_M1
	ck.addTest(code{"f_test.go", "S", "Test_T_M3", 103})    // maxTestee = 13
	ck.addTest(code{"f_test.go", "S", "Test_T__1", 104})    // testee < maxTestee: insert before first [testee > 10]
	ck.addTest(code{"f_test.go", "S", "Test_T__2", 105})    // testee < maxTestee: insert before first [testee > 10]
	ck.addTest(code{"f_test.go", "S", "Test_T_M2__1", 106}) // testee < maxTestee: insert before first [testee > 12] == T_M3
	ck.relate()

	ck.checkOrder()

	s.CheckErrors(
		"Test \"S.Test_T\" should be ordered before \"S.Test_T_M1\".",
		"Test \"S.Test_T__1\" should be ordered before \"S.Test_T_M1\".",
		"Test \"S.Test_T__2\" should be ordered before \"S.Test_T_M1\".",
		"Test \"S.Test_T_M2__1\" should be ordered before \"S.Test_T_M3\".")
}

func (s *Suite) Test_TestNameChecker_print__empty(c *check.C) {
	var out bytes.Buffer
	ck := s.Init(c)
	ck.out = &out

	ck.print()

	c.Check(out.String(), check.Equals, "")
}

func (s *Suite) Test_TestNameChecker_print__errors(c *check.C) {
	var out bytes.Buffer
	ck := s.Init(c)
	ck.out = &out

	ck.addError(EName, "1")
	ck.print()

	c.Check(out.String(), check.Equals, "1\n")
	s.CheckErrors("1")
	s.CheckSummary("1 error.")
}

func (s *Suite) Test_code_fullName(c *check.C) {
	_ = s.Init(c)

	test := func(typeName, funcName, fullName string) {
		code := code{"filename", typeName, funcName, 0}
		c.Check(code.fullName(), check.Equals, fullName)
	}

	test("Type", "", "Type")
	test("", "Func", "Func")
	test("Type", "Method", "Type.Method")
}

func (s *Suite) Test_plural(c *check.C) {
	_ = s.Init(c)

	c.Check(plural(0, "singular", "plural"), check.Equals, "")
	c.Check(plural(1, "singular", "plural"), check.Equals, "1 singular")
	c.Check(plural(2, "singular", "plural"), check.Equals, "2 plural")
	c.Check(plural(1000, "singular", "plural"), check.Equals, "1000 plural")
}

func (s *Suite) Test_isCamelCase(c *check.C) {
	_ = s.Init(c)

	c.Check(isCamelCase(""), check.Equals, false)
	c.Check(isCamelCase("Word"), check.Equals, false)
	c.Check(isCamelCase("Ada_Case"), check.Equals, false)
	c.Check(isCamelCase("snake_case"), check.Equals, false)
	c.Check(isCamelCase("CamelCase"), check.Equals, true)

	// After the first underscore of the description, any CamelCase
	// is ignored because there is no danger of confusing the method
	// name with the description.
	c.Check(isCamelCase("Word_CamelCase"), check.Equals, false)
}

func (s *Suite) Test_join(c *check.C) {
	_ = s.Init(c)

	c.Check(join("", " and ", ""), check.Equals, "")
	c.Check(join("one", " and ", ""), check.Equals, "one")
	c.Check(join("", " and ", "two"), check.Equals, "two")
	c.Check(join("one", " and ", "two"), check.Equals, "one and two")
}

type Value struct{}

// Method has no star on the receiver,
// for code coverage of TestNameChecker.loadDecl.
func (Value) Method() {}
