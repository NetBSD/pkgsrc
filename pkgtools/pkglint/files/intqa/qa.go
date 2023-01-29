// Package intqa provides quality assurance for the pkglint code.
package intqa

import (
	"fmt"
	"go/ast"
	"go/parser"
	"go/token"
	"io"
	"os"
	"path"
	"reflect"
	"sort"
	"strings"
	"unicode"
)

type Error int

const (
	ENone Error = iota + 1
	EAll

	// EMissingTest complains if a function or method does not have a
	// corresponding test.
	EMissingTest

	// EMissingTestee complains if the name of a test function does not
	// correspond to a program element to be tested.
	EMissingTestee

	// EOrder complains if the tests are not in the same order as their
	// corresponding testees in the main code.
	EOrder

	// EName complains if the test method does not have a valid name.
	EName

	// EFile complains if the file of the test method does not correspond
	// to the file of the testee.
	EFile

	// EMethodsSameFile complains if a method of a type is in a different
	// file than its corresponding type definition.
	EMethodsSameFile
)

// QAChecker analyzes Go source code for consistency.
//
// Among others, it enforces a strict naming scheme for test methods:
//
//	Test_${Type}_${Method}__${description_using_underscores}
//
// Each of the variable parts may be omitted.
type QAChecker struct {
	errorf func(format string, args ...interface{})

	filters []filter
	order   int

	testees []*testee
	tests   []*test

	errors []string
	out    io.Writer
}

// NewQAChecker creates a new checker.
// By default, all errors are enabled;
// call Configure to disable them selectively.
func NewQAChecker(errorf func(format string, args ...interface{})) *QAChecker {
	ck := QAChecker{errorf: errorf, out: os.Stderr}

	// For test fixtures from https://gopkg.in/check/v1.
	ck.Configure("*_test.go", "*", "SetUpTest", -EMissingTest)
	ck.Configure("*_test.go", "*", "TearDownTest", -EMissingTest)

	// See https://github.com/rillig/gobco.
	ck.Configure("gobco_*.go", "gobco*", "*", -EMissingTest)
	ck.Configure("gobco_*.go", "", "gobco*", -EMissingTest)

	return &ck
}

// Configure sets the errors that are activated for the given code,
// specified by shell patterns like in path.Match.
//
// All rules are applied in order. Later rules overwrite earlier rules.
//
// Individual errors can be enabled by giving their constant and disabled
// by negating them, such as -EMissingTestee. To reset everything, use
// either EAll or ENone.
func (ck *QAChecker) Configure(filenames, typeNames, funcNames string, errors ...Error) {
	ck.filters = append(ck.filters, filter{filenames, typeNames, funcNames, errors})
}

func (ck *QAChecker) Check() {
	ck.load(".")
	ck.checkTesteesTest()
	ck.checkTests()
	ck.checkMethodsSameFile()
	ck.checkOrder()
	ck.print()
}

// load loads all type, function and method names from the current package.
func (ck *QAChecker) load(dir string) {

	fileSet := token.NewFileSet()
	pkgs, err := parser.ParseDir(fileSet, dir, nil, 0)
	if err != nil {
		panic(err)
	}

	for _, pkgname := range sortedKeys(pkgs) {
		files := pkgs[pkgname].Files

		for _, filename := range sortedKeys(files) {
			file := files[filename]
			for _, decl := range file.Decls {
				ck.loadDecl(decl, filename)
			}
		}
	}

	ck.relate()
}

// loadDecl adds a single type or function declaration to the known elements.
func (ck *QAChecker) loadDecl(decl ast.Decl, filename string) {
	switch decl := decl.(type) {

	case *ast.GenDecl:
		for _, spec := range decl.Specs {
			switch spec := spec.(type) {
			case *ast.TypeSpec:
				typeName := spec.Name.Name
				ck.addCode(code{filename, typeName, "", 0}, nil)
			}
		}

	case *ast.FuncDecl:
		code := ck.parseFuncDecl(filename, decl)
		ck.addCode(code, decl)
	}
}

func (*QAChecker) parseFuncDecl(filename string, decl *ast.FuncDecl) code {
	typeName := ""
	if decl.Recv != nil {
		typeExpr := decl.Recv.List[0].Type.(ast.Expr)
		if star, ok := typeExpr.(*ast.StarExpr); ok {
			typeExpr = star.X
		}
		typeName = typeExpr.(*ast.Ident).Name
	}

	funcName := decl.Name.Name
	return code{filename, typeName, funcName, 0}
}

func (ck *QAChecker) addCode(code code, decl *ast.FuncDecl) {
	if code.isTestScope() && code.isFunc() && code.Func == "TestMain" {
		// This is not a test for Main, but a wrapper function of the test.
		// Therefore it is completely ignored.
		// See https://golang.org/pkg/testing/#hdr-Main.
		//
		// Among others, this function is created by
		// https://github.com/rillig/gobco when measuring the branch
		// coverage of a package.
		return
	}

	if !ck.isRelevant(code.file, code.Type, code.Func, EAll) {
		return
	}

	if ck.isTest(code, decl) {
		ck.addTest(code)
	} else {
		ck.addTestee(code)
	}
}

func (*QAChecker) isTest(code code, decl *ast.FuncDecl) bool {
	if !code.isTestScope() || !strings.HasPrefix(code.Func, "Test") {
		return false
	}
	if decl.Type.Params.NumFields() != 1 {
		return false
	}

	paramType := decl.Type.Params.List[0].Type
	if star, ok := paramType.(*ast.StarExpr); ok {
		paramType = star.X
	}
	if sel, ok := paramType.(*ast.SelectorExpr); ok {
		paramType = sel.Sel
	}

	paramTypeName := paramType.(*ast.Ident).Name
	return paramTypeName == "C" || paramTypeName == "T"
}

func (ck *QAChecker) addTestee(code code) {
	code.order = ck.nextOrder()
	ck.testees = append(ck.testees, &testee{code})
}

func (ck *QAChecker) addTest(code code) {
	if !strings.HasPrefix(code.Func, "Test_") &&
		code.Func != "Test" &&
		ck.addError(
			EName,
			code,
			"Test %q must start with %q.",
			code.fullName(), "Test_") {

		return
	}

	parts := strings.SplitN(code.Func, "__", 2)
	testeeName := strings.TrimPrefix(strings.TrimPrefix(parts[0], "Test"), "_")
	descr := ""
	if len(parts) > 1 {
		if parts[1] == "" &&
			ck.addError(
				EName,
				code,
				"Test %q must have a nonempty description.",
				code.fullName()) {
			return
		}
		descr = parts[1]
	}

	code.order = ck.nextOrder()
	ck.tests = append(ck.tests, &test{code, testeeName, descr, nil})
}

func (ck *QAChecker) nextOrder() int {
	id := ck.order
	ck.order++
	return id
}

// relate connects the tests to their testees.
func (ck *QAChecker) relate() {
	testeesByPrefix := make(map[string]*testee)
	for _, testee := range ck.testees {
		prefix := join(testee.Type, "_", testee.Func)
		testeesByPrefix[prefix] = testee
	}

	for _, test := range ck.tests {
		test.testee = testeesByPrefix[test.testeeName]
	}
}

func (ck *QAChecker) checkTests() {
	for _, test := range ck.tests {
		ck.checkTestFile(test)
		ck.checkTestTestee(test)
		ck.checkTestDescr(test)
	}
}

func (ck *QAChecker) checkTestFile(test *test) {
	testee := test.testee
	if testee == nil || testee.file == test.file {
		return
	}

	correctTestFile := testee.testFile()
	if correctTestFile == test.file {
		return
	}

	ck.addError(
		EFile,
		test.code,
		"Test %q for %q must be in %s instead of %s.",
		test.fullName(), testee.fullName(), correctTestFile, test.file)
}

func (ck *QAChecker) checkTestTestee(test *test) {
	testee := test.testee
	if testee != nil || test.testeeName == "" {
		return
	}

	testeeName := strings.Replace(test.testeeName, "_", ".", -1)
	ck.addError(
		EMissingTestee,
		test.code,
		"Missing testee %q for test %q.",
		testeeName, test.fullName())
}

// checkTestDescr ensures that the type or function name of the testee
// does not accidentally end up in the description of the test. This could
// happen if there is a double underscore instead of a single underscore.
func (ck *QAChecker) checkTestDescr(test *test) {
	testee := test.testee
	if testee == nil || testee.isMethod() || !isCamelCase(test.descr) {
		return
	}

	ck.addError(
		EName,
		testee.code,
		"%s: Test description %q must not use CamelCase in the first word.",
		test.fullName(), test.descr)
}

// checkTesteesTest ensures that each testee has a corresponding unit test.
func (ck *QAChecker) checkTesteesTest() {
	tested := make(map[*testee]bool)
	for _, test := range ck.tests {
		tested[test.testee] = true
	}

	for _, testee := range ck.testees {
		if tested[testee] {
			continue
		}

		testName := "Test_" + join(testee.Type, "_", testee.Func)

		testCode := code{testee.testFile(), "", testName, 0}
		test := test{testCode, testee.fullName(), "", testee}
		insertion := ck.insertionSuggestion(&test)

		ck.addError(
			EMissingTest,
			testee.code,
			"Missing unit test %q for %q. %s",
			testName, testee.fullName(), insertion)
	}
}

// checkTesteesMethodsSameFile ensures that all methods of a type are
// defined in the same file or in the corresponding test file.
func (ck *QAChecker) checkMethodsSameFile() {
	types := map[string]*code{}
	var methods []*code

	for _, testee := range ck.testees {
		if testee.isType() {
			types[testee.Type] = &testee.code
		} else if testee.isMethod() {
			methods = append(methods, &testee.code)
		}
	}
	for _, test := range ck.tests {
		if test.isMethod() {
			methods = append(methods, &test.code)
		}
	}

	for _, method := range methods {
		typ := types[method.Type]
		if typ == nil || method.file == typ.file {
			continue
		}

		if method.isTestScope() == typ.isTestScope() {
			ck.addError(
				EMethodsSameFile,
				*method,
				"Method %s must be in %s, like its type.",
				method.fullName(), typ.file)
			continue
		}

		correctFile := typ.testFile()
		if method.file == correctFile {
			continue
		}

		ck.addError(
			EMethodsSameFile,
			*method,
			"Method %s must be in %s, corresponding to its type.",
			method.fullName(), correctFile)
	}
}

// isRelevant checks whether the given error is enabled.
func (ck *QAChecker) isRelevant(filename, typeName, funcName string, e Error) bool {
	mask := ^uint64(0)
	for _, filter := range ck.filters {
		if matches(filename, filter.filenames) &&
			matches(typeName, filter.typeNames) &&
			matches(funcName, filter.funcNames) {
			mask = ck.errorsMask(mask, filter.errors...)
		}
	}
	return mask&ck.errorsMask(0, e) != 0
}

func (ck *QAChecker) errorsMask(mask uint64, errors ...Error) uint64 {
	for _, err := range errors {
		if err == ENone {
			mask = 0
		} else if err == EAll {
			mask = ^uint64(0)
		} else if err < 0 {
			mask &= ^(uint64(1) << -uint(err))
		} else {
			mask |= uint64(1) << uint(err)
		}
	}
	return mask
}

// checkOrder ensures that the tests appear in the same order as their
// counterparts in the main code.
func (ck *QAChecker) checkOrder() {
	maxOrderByFile := make(map[string]*test)

	for _, test := range ck.tests {
		testee := test.testee
		if testee == nil {
			continue
		}

		maxOrder := maxOrderByFile[testee.file]
		if maxOrder == nil || testee.order > maxOrder.testee.order {
			maxOrderByFile[testee.file] = test
		}

		if maxOrder != nil && testee.order < maxOrder.testee.order {
			insertBefore := maxOrder
			for _, before := range ck.tests {
				if before.file == test.file && before.testee != nil && before.testee.order > testee.order {
					insertBefore = before
					break
				}
			}

			ck.addError(
				EOrder,
				test.code,
				"Test %q must be ordered before %q.",
				test.fullName(), insertBefore.fullName())
		}
	}
}

func (ck *QAChecker) addError(e Error, c code, format string, args ...interface{}) bool {
	relevant := ck.isRelevant(c.file, c.Type, c.Func, e)
	if relevant {
		ck.errors = append(ck.errors, fmt.Sprintf(format, args...))
	}
	return relevant
}

func (ck *QAChecker) print() {
	for _, msg := range ck.errors {
		_, _ = fmt.Fprintln(ck.out, msg)
	}

	n := len(ck.errors)
	if n > 1 {
		ck.errorf("%d errors.", n)
	} else if n == 1 {
		ck.errorf("%d error.", n)
	}
}

func (ck *QAChecker) insertionSuggestion(newTest *test) string {
	testFile := newTest.testee.testFile()

	for _, test := range ck.tests {
		if test.testee != nil &&
			test.testee.order >= newTest.testee.order &&
			test.file == testFile {

			return fmt.Sprintf("Insert it in %q, above %q.",
				newTest.file, test.fullName())
		}
	}

	return fmt.Sprintf("Insert it at the bottom of %q.", newTest.file)
}

type filter struct {
	filenames string
	typeNames string
	funcNames string
	errors    []Error
}

// testee is an element of the source code that can be tested.
type testee struct {
	code
}

type test struct {
	code

	testeeName string // The method name without the "Test_" prefix and description
	descr      string // The part after the "__" in the method name
	testee     *testee
}

// code is either a type, a function or a method.
type code struct {
	file  string // the file containing the code
	Type  string // the type, e.g. MkLine
	Func  string // the function or method name, e.g. Warnf
	order int    // the relative order in the file
}

func (c *code) fullName() string { return join(c.Type, ".", c.Func) }
func (c *code) isFunc() bool     { return c.Type == "" }
func (c *code) isType() bool     { return c.Func == "" }
func (c *code) isMethod() bool   { return c.Type != "" && c.Func != "" }

func (c *code) isTestScope() bool {
	return strings.HasSuffix(c.file, "_test.go")
}

func (c *code) testFile() string {
	if strings.HasSuffix(c.file, "_test.go") {
		return c.file
	}
	return strings.TrimSuffix(c.file, ".go") + "_test.go"
}

func isCamelCase(str string) bool {
	for i := 0; i+1 < len(str); i++ {
		if str[i] == '_' {
			return false
		}
		if unicode.IsLower(rune(str[i])) && unicode.IsUpper(rune(str[i+1])) {
			return true
		}
	}
	return false
}

func join(a, sep, b string) string {
	if a == "" || b == "" {
		sep = ""
	}
	return a + sep + b
}

func matches(subj string, pattern string) bool {
	ok, err := path.Match(pattern, subj)
	if err != nil {
		panic(err)
	}
	return ok
}

// sortedKeys returns the sorted keys from an arbitrary map.
func sortedKeys(m interface{}) []string {
	var keys []string
	for _, key := range reflect.ValueOf(m).MapKeys() {
		keys = append(keys, key.Interface().(string))
	}
	sort.Strings(keys)
	return keys
}
