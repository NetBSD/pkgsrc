package intqa

import (
	"bytes"
	"fmt"
	"go/ast"
	"gopkg.in/check.v1"
	"io/ioutil"
	"path"
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
	s.ck.out = ioutil.Discard
	return s.ck
}

func (s *Suite) TearDownTest(c *check.C) {
	s.c = c
	s.CheckErrors(nil...)
	s.CheckSummary("")
}

func (s *Suite) CheckTestees(testees ...*testee) {
	s.c.Check(s.ck.testees, check.DeepEquals, testees)
	s.ck.testees = nil
}

func (*Suite) newTestee(filename, typeName, funcName string, order int) *testee {
	return &testee{code{filename, typeName, funcName, order}}
}

func (s *Suite) CheckTests(tests ...*test) {
	s.c.Check(s.ck.tests, check.DeepEquals, tests)
	s.ck.tests = nil
}

func (*Suite) newTest(filename, typeName, funcName string, order int, testeeName, descr string, testee *testee) *test {
	c := code{filename, typeName, funcName, order}
	return &test{c, testeeName, descr, testee}
}

func (s *Suite) CheckErrors(errors ...string) {
	s.c.Check(s.ck.errors, check.DeepEquals, errors)
	s.ck.errors = nil
}

func (s *Suite) CheckSummary(summary string) {
	s.c.Check(s.summary, check.Equals, summary)
	s.summary = ""
}

func (s *Suite) Test_NewTestNameChecker(c *check.C) {
	ck := s.Init(c)

	c.Check(ck.isRelevant("*_test.go", "Suite", "SetUpTest", EAll), check.Equals, true)
	c.Check(ck.isRelevant("*_test.go", "Suite", "SetUpTest", EMissingTest), check.Equals, false)

	c.Check(ck.isRelevant("*_test.go", "Suite", "TearDownTest", EAll), check.Equals, true)
	c.Check(ck.isRelevant("*_test.go", "Suite", "TearDownTest", EMissingTest), check.Equals, false)
}

func (s *Suite) Test_TestNameChecker_Configure(c *check.C) {
	ck := s.Init(c)

	ck.Configure("*", "*", "*", ENone) // overwrite initialization from Suite.Init

	c.Check(ck.isRelevant("", "", "", EAll), check.Equals, false)
	c.Check(ck.isRelevant("", "", "", EMissingTestee), check.Equals, false)
	c.Check(ck.isRelevant("", "", "", EMissingTest), check.Equals, false)

	ck.Configure("*", "*", "*", EAll)

	c.Check(ck.isRelevant("", "", "", EAll), check.Equals, true)
	c.Check(ck.isRelevant("", "", "", EMissingTestee), check.Equals, true)
	c.Check(ck.isRelevant("", "", "", EMissingTest), check.Equals, true)

	ck.Configure("*", "*", "*", -EMissingTestee)

	c.Check(ck.isRelevant("", "", "", EAll), check.Equals, true)
	c.Check(ck.isRelevant("", "", "", EMissingTestee), check.Equals, false)
	c.Check(ck.isRelevant("", "", "", EMissingTest), check.Equals, true)

	ck.Configure("*", "*", "*", ENone, EMissingTest)

	c.Check(ck.isRelevant("", "", "", EAll), check.Equals, true)
	c.Check(ck.isRelevant("", "", "", EMissingTestee), check.Equals, false)
	c.Check(ck.isRelevant("", "", "", EMissingTest), check.Equals, true)

	ck.Configure("*", "*", "*", EAll, -EMissingTest)

	c.Check(ck.isRelevant("", "", "", EAll), check.Equals, true)
	c.Check(ck.isRelevant("", "", "", EMissingTestee), check.Equals, true)
	c.Check(ck.isRelevant("", "", "", EMissingTest), check.Equals, false)
}

func (s *Suite) Test_TestNameChecker_Configure__ignore_single_function(c *check.C) {
	ck := s.Init(c)

	ck.Configure("*", "*", "*", EAll)

	// The intention of this rule is that this particular function is ignored.
	// Everything else from that file is still processed.
	ck.Configure("*_test.go", "", "TestMain", ENone)

	c.Check(ck.isRelevant("file_test.go", "", "", EAll), check.Equals, true)
	c.Check(ck.isRelevant("file_test.go", "*", "*", EAll), check.Equals, true)
	c.Check(ck.isRelevant("file_test.go", "*", "Other", EAll), check.Equals, true)
	c.Check(ck.isRelevant("file_test.go", "", "TestMain", EAll), check.Equals, false)
	c.Check(ck.isRelevant("file_test.go", "*", "TestMain", EAll), check.Equals, true)
}

func (s *Suite) Test_TestNameChecker_Check(c *check.C) {
	ck := s.Init(c)

	ck.Configure("*", "Suite", "*", -EMissingTest)

	ck.Check()

	s.CheckErrors(
		"Missing unit test \"Test_TestNameChecker_addCode\" for \"TestNameChecker.addCode\".",
		"Missing unit test \"Test_TestNameChecker_relate\" for \"TestNameChecker.relate\".",
		"Missing unit test \"Test_TestNameChecker_isRelevant\" for \"TestNameChecker.isRelevant\".")
	s.CheckSummary("3 errors.")
}

func (s *Suite) Test_TestNameChecker_load__filtered_nothing(c *check.C) {
	ck := s.Init(c)

	ck.Configure("*", "*", "*", ENone)

	ck.load(".")

	c.Check(ck.testees, check.IsNil)
	c.Check(ck.tests, check.IsNil)
}

func (s *Suite) Test_TestNameChecker_load__filtered_only_Value(c *check.C) {
	ck := s.Init(c)

	ck.Configure("*", "*", "*", ENone)
	ck.Configure("*", "Value", "*", EAll)

	ck.load(".")

	c.Check(ck.testees, check.DeepEquals, []*testee{
		{code{"testnames_test.go", "Value", "", 0}},
		{code{"testnames_test.go", "Value", "Method", 1}}})
	c.Check(ck.tests, check.IsNil)
}

func (s *Suite) Test_TestNameChecker_load__panic(c *check.C) {
	ck := s.Init(c)

	c.Check(
		func() { ck.load("does-not-exist") },
		check.PanicMatches,
		`^open does-not-exist\b.*`)
}

func (s *Suite) Test_TestNameChecker_loadDecl(c *check.C) {
	ck := s.Init(c)

	typeDecl := func(name string) *ast.GenDecl {
		return &ast.GenDecl{Specs: []ast.Spec{&ast.TypeSpec{Name: &ast.Ident{Name: name}}}}
	}
	funcDecl := func(name string) *ast.FuncDecl {
		return &ast.FuncDecl{Name: &ast.Ident{Name: name}}
	}
	methodDecl := func(typeName, methodName string) *ast.FuncDecl {
		return &ast.FuncDecl{
			Name: &ast.Ident{Name: methodName},
			Recv: &ast.FieldList{List: []*ast.Field{{Type: &ast.Ident{Name: typeName}}}}}
	}

	ck.loadDecl(typeDecl("TypeName"), "file_test.go")

	s.CheckTestees(
		s.newTestee("file_test.go", "TypeName", "", 0))

	// The freestanding TestMain function is ignored by a hardcoded rule,
	// independently of the configuration.
	ck.loadDecl(funcDecl("TestMain"), "file_test.go")

	// The TestMain method on a type is relevant, but violates the naming rule.
	// Therefore it is ignored.
	ck.loadDecl(methodDecl("Suite", "TestMain"), "file_test.go")

	s.CheckTests(
		nil...)
	s.CheckErrors(
		"Test \"Suite.TestMain\" must start with \"Test_\".")

	// The above error can be disabled, and then the method is handled
	// like any other test method.
	ck.Configure("*", "Suite", "*", -EName)
	ck.loadDecl(methodDecl("Suite", "TestMain"), "file_test.go")

	s.CheckTests(
		s.newTest("file_test.go", "Suite", "TestMain", 1, "Main", "", nil))

	// There is no special handling for TestMain method with a description.
	ck.loadDecl(methodDecl("Suite", "TestMain__descr"), "file_test.go")

	s.CheckTests(
		s.newTest("file_test.go", "Suite", "TestMain__descr", 2, "Main", "descr", nil))
}

func (s *Suite) Test_TestNameChecker_addTestee(c *check.C) {
	ck := s.Init(c)

	code := code{"filename.go", "Type", "Method", 0}
	ck.addTestee(code)

	c.Check(ck.testees, check.DeepEquals, []*testee{{code}})
}

func (s *Suite) Test_TestNameChecker_addTest(c *check.C) {
	ck := s.Init(c)

	ck.addTest(code{"filename.go", "Type", "Method", 0})

	c.Check(ck.tests, check.IsNil)
	s.CheckErrors(
		"Test \"Type.Method\" must start with \"Test_\".")
}

func (s *Suite) Test_TestNameChecker_addTest__empty_description(c *check.C) {
	ck := s.Init(c)

	ck.addTest(code{"f_test.go", "Suite", "Test_Method__", 0})

	s.CheckErrors(
		"Test \"Suite.Test_Method__\" must have a nonempty description.")

	// The test is not registered and thus cannot complain about its missing
	// testee.
	ck.checkTests()

	s.CheckErrors(
		nil...)
}

func (s *Suite) Test_TestNameChecker_addTest__suppressed_empty_description(c *check.C) {
	ck := s.Init(c)

	ck.Configure("*", "*", "*", -EName)
	ck.addTest(code{"f_test.go", "Suite", "Test_Method__", 0})

	s.CheckErrors(
		nil...)

	// Since there was no error above, the test is added normally
	// and can complain about its missing testee.
	ck.checkTests()

	s.CheckErrors(
		"Missing testee \"Method\" for test \"Suite.Test_Method__\".")
}

func (s *Suite) Test_TestNameChecker_nextOrder(c *check.C) {
	ck := s.Init(c)

	c.Check(ck.nextOrder(), check.Equals, 0)
	c.Check(ck.nextOrder(), check.Equals, 1)
	c.Check(ck.nextOrder(), check.Equals, 2)
}

func (s *Suite) Test_TestNameChecker_checkTests(c *check.C) {
	ck := s.Init(c)

	ck.tests = append(ck.tests,
		s.newTest("wrong_test.go", "", "Test_Func", 0, "Func", "",
			s.newTestee("source.go", "", "Func", 1)))

	ck.checkTests()

	s.CheckErrors(
		"Test \"Test_Func\" for \"Func\" " +
			"must be in source_test.go instead of wrong_test.go.")
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

func (s *Suite) Test_TestNameChecker_checkTestDescr__camel_case(c *check.C) {
	ck := s.Init(c)

	ck.checkTestDescr(&test{
		code{"demo_test.go", "Suite", "Test_Missing__CamelCase", 0},
		"Missing",
		"CamelCase",
		&testee{}})

	s.CheckErrors(
		"Suite.Test_Missing__CamelCase: Test description \"CamelCase\" " +
			"must not use CamelCase in the first word.")
}

func (s *Suite) Test_TestNameChecker_checkTestees(c *check.C) {
	ck := s.Init(c)

	ck.testees = []*testee{s.newTestee("s.go", "", "Func", 0)}
	ck.tests = nil // force an error

	ck.checkTestees()

	s.CheckErrors(
		"Missing unit test \"Test_Func\" for \"Func\".")
}

func (s *Suite) Test_TestNameChecker_checkTesteeTest(c *check.C) {
	ck := s.Init(c)

	ck.checkTesteeTest(
		&testee{code{"demo.go", "Type", "", 0}},
		nil)
	ck.checkTesteeTest(
		&testee{code{"demo.go", "", "Func", 0}},
		nil)
	ck.checkTesteeTest(
		&testee{code{"demo.go", "Type", "Method", 0}},
		nil)

	s.CheckErrors(
		"Missing unit test \"Test_Func\" for \"Func\".",
		"Missing unit test \"Test_Type_Method\" for \"Type.Method\".")
}

func (s *Suite) Test_TestNameChecker_errorsMask(c *check.C) {
	ck := s.Init(c)

	c.Check(ck.errorsMask(0, EAll), check.Equals, ^uint64(0))
	c.Check(ck.errorsMask(12345, ENone), check.Equals, uint64(0))
	c.Check(ck.errorsMask(12345, ENone, EMissingTest), check.Equals, uint64(8))
	c.Check(ck.errorsMask(2, EMissingTest), check.Equals, uint64(10))
}

func (s *Suite) Test_TestNameChecker_checkOrder(c *check.C) {
	ck := s.Init(c)

	ck.addTestee(code{"f.go", "T", "", 10})
	ck.addTestee(code{"f.go", "T", "M1", 11})
	ck.addTestee(code{"f.go", "T", "M2", 12})
	ck.addTestee(code{"f.go", "T", "M3", 13})
	ck.addTest(code{"a_test.go", "S", "Test_A", 98})        // different file, is skipped
	ck.addTest(code{"f_test.go", "S", "Test_Missing", 99})  // missing testee, is skipped
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
		"Test \"S.Test_T\" must be ordered before \"S.Test_T_M1\".",
		"Test \"S.Test_T__1\" must be ordered before \"S.Test_T_M1\".",
		"Test \"S.Test_T__2\" must be ordered before \"S.Test_T_M1\".",
		"Test \"S.Test_T_M2__1\" must be ordered before \"S.Test_T_M3\".")
}

func (s *Suite) Test_TestNameChecker_addError(c *check.C) {
	ck := s.Init(c)

	ck.Configure("ignored*", "*", "*", -EName)
	ok1 := ck.addError(EName, code{"ignored.go", "", "Func", 0}, "E1")
	ok2 := ck.addError(EName, code{"reported.go", "", "Func", 0}, "E2")

	c.Check(ok1, check.Equals, false)
	c.Check(ok2, check.Equals, true)
	s.CheckErrors(
		"E2")
}

func (s *Suite) Test_TestNameChecker_print__empty(c *check.C) {
	var out bytes.Buffer
	ck := s.Init(c)
	ck.out = &out

	ck.print()

	c.Check(out.String(), check.Equals, "")
}

func (s *Suite) Test_TestNameChecker_print__1_error(c *check.C) {
	var out bytes.Buffer
	ck := s.Init(c)
	ck.out = &out
	ck.addError(EName, code{}, "1")

	ck.print()

	c.Check(out.String(), check.Equals, "1\n")
	s.CheckErrors("1")
	s.CheckSummary("1 error.")
}

func (s *Suite) Test_TestNameChecker_print__2_errors(c *check.C) {
	var out bytes.Buffer
	ck := s.Init(c)
	ck.out = &out
	ck.addError(EName, code{}, "1")
	ck.addError(EName, code{}, "2")

	ck.print()

	c.Check(out.String(), check.Equals, "1\n2\n")
	s.CheckErrors("1", "2")
	s.CheckSummary("2 errors.")
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

func (s *Suite) Test_code_isFunc(c *check.C) {
	_ = s.Init(c)

	test := func(typeName, funcName string, isFunc bool) {
		code := code{"filename", typeName, funcName, 0}
		c.Check(code.isFunc(), check.Equals, isFunc)
	}

	test("Type", "", false)
	test("", "Func", true)
	test("Type", "Method", false)
}

func (s *Suite) Test_code_isType(c *check.C) {
	_ = s.Init(c)

	test := func(typeName, funcName string, isType bool) {
		code := code{"filename", typeName, funcName, 0}
		c.Check(code.isType(), check.Equals, isType)
	}

	test("Type", "", true)
	test("", "Func", false)
	test("Type", "Method", false)
}

func (s *Suite) Test_code_isMethod(c *check.C) {
	_ = s.Init(c)

	test := func(typeName, funcName string, isMethod bool) {
		code := code{"filename", typeName, funcName, 0}
		c.Check(code.isMethod(), check.Equals, isMethod)
	}

	test("Type", "", false)
	test("", "Func", false)
	test("Type", "Method", true)
}

func (s *Suite) Test_code_isTest(c *check.C) {
	_ = s.Init(c)

	test := func(filename, typeName, funcName string, isTest bool) {
		code := code{filename, typeName, funcName, 0}
		c.Check(code.isTest(), check.Equals, isTest)
	}

	test("f.go", "Type", "", false)
	test("f.go", "", "Func", false)
	test("f.go", "Type", "Method", false)
	test("f.go", "Type", "Test", false)
	test("f.go", "Type", "Test_Type_Method", false)
	test("f.go", "", "Test_Type_Method", false)
	test("f_test.go", "Type", "Test", true)
	test("f_test.go", "Type", "Test_Type_Method", true)
	test("f_test.go", "", "Test_Type_Method", true)
}

func (s *Suite) Test_code_isTestScope(c *check.C) {
	_ = s.Init(c)

	test := func(filename string, isTestScope bool) {
		code := code{filename, "", "", 0}
		c.Check(code.isTestScope(), check.Equals, isTestScope)
	}

	test("f.go", false)
	test("test.go", false)
	test("_test.go", true)
	test("file_test.go", true)
	test("file_linux_test.go", true)
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

func (s *Suite) Test_matches(c *check.C) {
	_ = s.Init(c)

	c.Check(matches("*", "*"), check.Equals, true)
	c.Check(matches("anything", "*"), check.Equals, true)
	c.Check(matches("*", "anything"), check.Equals, false)
	c.Check(func() { matches("any", "[") }, check.Panics, path.ErrBadPattern)
}

func (s *Suite) Test_sortedKeys(c *check.C) {
	_ = s.Init(c)

	m := make(map[string]uint8)
	m["first"] = 1
	m["second"] = 2
	m["third"] = 3
	m["fourth"] = 4

	c.Check(
		sortedKeys(m),
		check.DeepEquals,
		[]string{"first", "fourth", "second", "third"})
}

func (s *Suite) Test_Value_Method(c *check.C) {
	_ = s.Init(c)

	// Just for code coverage of checkTestFile, to have a piece of code
	// that lives in the same file as its test.
}

type Value struct{}

// Method has no star on the receiver,
// for code coverage of TestNameChecker.loadDecl.
func (Value) Method() {}
