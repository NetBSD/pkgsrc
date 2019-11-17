// Package intqa provides quality assurance for the pkglint code.
package intqa

import (
	"fmt"
	"go/ast"
	"go/parser"
	"go/token"
	"io"
	"os"
	"path/filepath"
	"sort"
	"strings"
	"unicode"
)

type Error int

const (
	ENone Error = iota
	EAll

	// A function or method does not have a corresponding test.
	EMissingTest

	// The name of a test function does not correspond to a program
	// element to be tested.
	EMissingTestee

	// The tests are not in the same order as their corresponding
	// testees in the main code.
	EOrder

	// The test method does not have a valid name.
	EName

	// The file of the test method does not correspond to the
	// file of the testee.
	EFile
)

// TestNameChecker ensures that all test names follow a common naming scheme:
//  Test_${Type}_${Method}__${description_using_underscores}
// Each of the variable parts may be omitted.
type TestNameChecker struct {
	errorf func(format string, args ...interface{})

	ignoredFiles []string
	order        int

	testees []*testee
	tests   []*test

	errorsMask uint64
	errors     []string
	out        io.Writer
}

// NewTestNameChecker creates a new checker.
// By default, all errors are disabled; call Enable to enable them.
func NewTestNameChecker(errorf func(format string, args ...interface{})) *TestNameChecker {
	return &TestNameChecker{errorf: errorf, out: os.Stderr}
}

func (ck *TestNameChecker) IgnoreFiles(fileGlob string) {
	ck.ignoredFiles = append(ck.ignoredFiles, fileGlob)
}

func (ck *TestNameChecker) Enable(errors ...Error) {
	for _, err := range errors {
		if err == ENone {
			ck.errorsMask = 0
		} else if err == EAll {
			ck.errorsMask = ^uint64(0)
		} else if err < 0 {
			ck.errorsMask &= ^(uint64(1) << -uint(err))
		} else {
			ck.errorsMask |= uint64(1) << uint(err)
		}
	}
}

func (ck *TestNameChecker) Check() {
	ck.load()
	ck.checkTestees()
	ck.checkTests()
	ck.checkOrder()
	ck.print()
}

// load loads all type, function and method names from the current package.
func (ck *TestNameChecker) load() {
	fileSet := token.NewFileSet()
	pkgs, err := parser.ParseDir(fileSet, ".", nil, 0)
	if err != nil {
		panic(err)
	}

	var pkgnames []string
	for pkgname := range pkgs {
		pkgnames = append(pkgnames, pkgname)
	}
	sort.Strings(pkgnames)

	for _, pkgname := range pkgnames {
		files := pkgs[pkgname].Files

		var filenames []string
		for filename := range files {
			filenames = append(filenames, filename)
		}
		sort.Strings(filenames)

		for _, filename := range filenames {
			file := files[filename]
			for _, decl := range file.Decls {
				ck.loadDecl(decl, filename)
			}
		}
	}

	ck.relate()
}

// loadDecl adds a single type or function declaration to the known elements.
func (ck *TestNameChecker) loadDecl(decl ast.Decl, filename string) {
	switch decl := decl.(type) {

	case *ast.GenDecl:
		for _, spec := range decl.Specs {
			switch spec := spec.(type) {
			case *ast.TypeSpec:
				typeName := spec.Name.Name
				ck.addCode(code{filename, typeName, "", ck.nextOrder()})
			}
		}

	case *ast.FuncDecl:
		typeName := ""
		if decl.Recv != nil {
			typeExpr := decl.Recv.List[0].Type.(ast.Expr)
			if star, ok := typeExpr.(*ast.StarExpr); ok {
				typeName = star.X.(*ast.Ident).Name
			} else {
				typeName = typeExpr.(*ast.Ident).Name
			}
		}
		ck.addCode(code{filename, typeName, decl.Name.Name, ck.nextOrder()})
	}
}

func (ck *TestNameChecker) addCode(code code) {
	isTest := strings.HasSuffix(code.file, "_test.go") &&
		code.Type != "" &&
		strings.HasPrefix(code.Func, "Test")

	if isTest {
		ck.addTest(code)
	} else {
		ck.addTestee(code)
	}
}

func (ck *TestNameChecker) addTestee(code code) {
	ck.testees = append(ck.testees, &testee{code})
}

func (ck *TestNameChecker) addTest(code code) {
	if !strings.HasPrefix(code.Func, "Test_") {
		ck.addError(
			EName,
			"Test %q must start with %q.",
			code.fullName(), "Test_")
		return
	}

	parts := strings.SplitN(code.Func, "__", 2)
	testeeName := strings.TrimPrefix(strings.TrimPrefix(parts[0], "Test"), "_")
	descr := ""
	if len(parts) > 1 {
		if parts[1] == "" {
			ck.addError(
				EName,
				"Test %q must not have a nonempty description.",
				code.fullName())
			return
		}
		descr = parts[1]
	}

	ck.tests = append(ck.tests, &test{code, testeeName, descr, nil})
}

func (ck *TestNameChecker) nextOrder() int {
	id := ck.order
	ck.order++
	return id
}

// relate connects the tests to their testees.
func (ck *TestNameChecker) relate() {
	testeesByPrefix := make(map[string]*testee)
	for _, testee := range ck.testees {
		prefix := join(testee.Type, "_", testee.Func)
		testeesByPrefix[prefix] = testee
	}

	for _, test := range ck.tests {
		test.testee = testeesByPrefix[test.testeeName]
	}
}

func (ck *TestNameChecker) checkTests() {
	for _, test := range ck.tests {
		ck.checkTestFile(test)
		ck.checkTestName(test)
		ck.checkTestTestee(test)
	}
}

func (ck *TestNameChecker) checkTestFile(test *test) {
	testee := test.testee
	if testee == nil || testee.file == test.file {
		return
	}

	correctTestFile := strings.TrimSuffix(testee.file, ".go") + "_test.go"
	if correctTestFile != test.file {
		ck.addError(
			EFile,
			"Test %q for %q must be in %s instead of %s.",
			test.fullName(), testee.fullName(), correctTestFile, test.file)
	}
}

func (ck *TestNameChecker) checkTestTestee(test *test) {
	testee := test.testee
	if testee != nil || test.testeeName == "" {
		return
	}

	testeeName := strings.Replace(test.testeeName, "_", ".", -1)
	ck.addError(
		EMissingTestee,
		"Missing testee %q for test %q.",
		testeeName, test.fullName())
}

// checkTestName ensures that the method name does not accidentally
// end up in the description of the test. This could happen if there is a
// double underscore instead of a single underscore.
func (ck *TestNameChecker) checkTestName(test *test) {
	testee := test.testee
	if testee == nil {
		return
	}
	if testee.Type != "" && testee.Func != "" {
		return
	}
	if !isCamelCase(test.descr) {
		return
	}

	ck.addError(
		EName,
		"%s: Test description %q must not use CamelCase in the first word.",
		test.fullName(), test.descr)
}

func (ck *TestNameChecker) checkTestees() {
	tested := make(map[*testee]bool)
	for _, test := range ck.tests {
		tested[test.testee] = true
	}

	for _, testee := range ck.testees {
		if tested[testee] || testee.Func == "" {
			continue
		}

		testName := "Test_" + join(testee.Type, "_", testee.Func)
		ck.addError(
			EMissingTest,
			"Missing unit test %q for %q.",
			testName, testee.fullName())
	}
}

func (ck *TestNameChecker) isIgnored(filename string) bool {
	for _, mask := range ck.ignoredFiles {
		ok, err := filepath.Match(mask, filename)
		if err != nil {
			panic(err)
		}
		if ok {
			return true
		}
	}
	return false
}

// checkOrder ensures that the tests appear in the same order as their
// counterparts in the main code.
func (ck *TestNameChecker) checkOrder() {
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
				"Test %q should be ordered before %q.",
				test.fullName(), insertBefore.fullName())
		}
	}
}

func (ck *TestNameChecker) addError(e Error, format string, args ...interface{}) {
	if ck.errorsMask&(uint64(1)<<uint(e)) != 0 {
		ck.errors = append(ck.errors, fmt.Sprintf(format, args...))
	}
}

func (ck *TestNameChecker) print() {
	for _, msg := range ck.errors {
		_, _ = fmt.Fprintln(ck.out, msg)
	}

	errors := plural(len(ck.errors), "error", "errors")
	if len(ck.errors) > 0 {
		ck.errorf("%s.", errors)
	}
}

type code struct {
	file  string // The file containing the code
	Type  string // The type, e.g. MkLine
	Func  string // The function or method name, e.g. Warnf
	order int    // The relative order in the file
}

func (c *code) fullName() string { return join(c.Type, ".", c.Func) }

// testee is an element of the source code that can be tested.
// It is either a type, a function or a method.
type testee struct {
	code
}

type test struct {
	code

	testeeName string // The method name without the "Test_" prefix and description
	descr      string // The part after the "__" in the method name
	testee     *testee
}

func plural(n int, sg, pl string) string {
	if n == 0 {
		return ""
	}
	form := pl
	if n == 1 {
		form = sg
	}
	return fmt.Sprintf("%d %s", n, form)
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
