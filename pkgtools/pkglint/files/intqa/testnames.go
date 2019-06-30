// Package intqa provides quality assurance for the pkglint code.
package intqa

import (
	"fmt"
	"go/ast"
	"go/parser"
	"go/token"
	"gopkg.in/check.v1"
	"os"
	"path/filepath"
	"sort"
	"strings"
	"unicode"
)

// TestNameChecker ensures that all test names follow a common naming scheme:
//
// Test_${Type}_${Method}__${description_using_underscores}
type TestNameChecker struct {
	camelCase map[string]bool
	ignore    []string
	warn      bool
	prefixes  []testeePrefix
	c         *check.C
	errors    []string
	warnings  []string
}

type testeePrefix struct {
	prefix   string
	filename string
}

// testeeElement is an element of the source code that can be tested.
// It is either a type, a function or a method.
// The test methods are also testeeElements.
type testeeElement struct {
	File string // The file containing the testeeElement
	Type string // The type, e.g. MkLine
	Func string // The function or method name, e.g. Warnf

	FullName string // Type + "." + Func

	// Whether the testeeElement is a test or a testee
	Test bool

	// For a test, its name without the description,
	// otherwise the prefix (Type + "_" + Func) for the corresponding tests
	Prefix string
}

func NewTestNameChecker(c *check.C) *TestNameChecker {
	return &TestNameChecker{c: c, camelCase: make(map[string]bool)}
}

func (ck *TestNameChecker) IgnoreFiles(fileGlob string) {
	ck.ignore = append(ck.ignore, fileGlob)
}

// AllowPrefix allows tests with the given prefix to appear in the test
// file corresponding to the given source file (which doesn't even have
// to exist).
//
// In all other cases, the tests may only be named after things from the
// main code that can actually be tested.
func (ck *TestNameChecker) AllowPrefix(prefix, sourceFileName string) {
	ck.prefixes = append(ck.prefixes, testeePrefix{prefix, sourceFileName})
}

// AllowCamelCaseDescriptions allows the given strings to appear
// in the description part of a test name (Test_$Type_$Method__$description).
// In most cases the description should use snake case to allow for
// easier reading.
//
// When writing tests for combinations of several functions, it is most
// natural to mention one of these functions in the test name and the
// other in the test description. This is a typical use case.
func (ck *TestNameChecker) AllowCamelCaseDescriptions(descriptions ...string) {
	for _, description := range descriptions {
		ck.camelCase[description] = true
	}
}

func (ck *TestNameChecker) ShowWarnings(warn bool) { ck.warn = warn }

func (ck *TestNameChecker) addError(format string, args ...interface{}) {
	ck.errors = append(ck.errors, "E: "+fmt.Sprintf(format, args...))
}

func (ck *TestNameChecker) addWarning(format string, args ...interface{}) {
	ck.warnings = append(ck.warnings, "W: "+fmt.Sprintf(format, args...))
}

// addElement adds a single type or function declaration
// to the known elements.
func (ck *TestNameChecker) addElement(elements *[]*testeeElement, decl ast.Decl, filename string) {
	switch decl := decl.(type) {

	case *ast.GenDecl:
		for _, spec := range decl.Specs {
			switch spec := spec.(type) {
			case *ast.TypeSpec:
				typeName := spec.Name.Name
				*elements = append(*elements, newElement(typeName, "", filename))
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
		*elements = append(*elements, newElement(typeName, decl.Name.Name, filename))
	}
}

// loadAllElements returns all type, function and method names
// from the current package, in the form FunctionName or
// TypeName.MethodName (omitting the * from the type name).
func (ck *TestNameChecker) loadAllElements() []*testeeElement {
	fileSet := token.NewFileSet()
	pkgs, err := parser.ParseDir(fileSet, ".", func(fi os.FileInfo) bool { return true }, 0)
	if err != nil {
		panic(err)
	}

	var elements []*testeeElement
	for _, pkg := range pkgs {
		for filename, file := range pkg.Files {
			for _, decl := range file.Decls {
				ck.addElement(&elements, decl, filename)
			}
		}
	}

	sort.Slice(elements, func(i, j int) bool { return elements[i].Less(elements[j]) })

	return elements
}

// collectTesteeByName generates a map containing the names of all
// testable elements, as used in the test names. Examples:
//
//  Autofix
//  Line_Warnf
//  match5
func (ck *TestNameChecker) collectTesteeByName(elements []*testeeElement) map[string]*testeeElement {
	prefixes := make(map[string]*testeeElement)
	for _, element := range elements {
		if element.Prefix != "" {
			prefixes[element.Prefix] = element
		}
	}

	for _, p := range ck.prefixes {
		prefixes[p.prefix] = newElement(p.prefix, "", p.filename)
	}

	return prefixes
}

func (ck *TestNameChecker) checkTestName(test *testeeElement, prefix string, descr string, testeeByName map[string]*testeeElement) {
	testee := testeeByName[prefix]
	if testee == nil {
		ck.addError("Test %q for missing testee %q.", test.FullName, prefix)

	} else if !strings.HasSuffix(testee.File, "_test.go") {
		correctTestFile := strings.TrimSuffix(testee.File, ".go") + "_test.go"
		if correctTestFile != test.File {
			ck.addError("Test %q for %q must be in %s instead of %s.",
				test.FullName, testee.FullName, correctTestFile, test.File)
		}
	}

	if isCamelCase(descr) && !ck.camelCase[descr] {
		ck.addError("%s: Test description %q must not use CamelCase.", test.FullName, descr)
	}
}

func (ck *TestNameChecker) checkAll(elements []*testeeElement, testeeByName map[string]*testeeElement) {
	testNames := make(map[string]bool)

	for _, element := range elements {
		if element.Test {
			method := element.Func
			switch {
			case strings.HasPrefix(method, "Test__"):
				// OK

			case strings.HasPrefix(method, "Test_"):
				refAndDescr := strings.SplitN(method[5:], "__", 2)
				descr := ""
				if len(refAndDescr) > 1 {
					descr = refAndDescr[1]
				}
				testNames[refAndDescr[0]] = true
				ck.checkTestName(element, refAndDescr[0], descr, testeeByName)

			default:
				ck.addError("Test name %q must contain an underscore.", element.FullName)
			}
		}
	}

	for _, element := range elements {
		if !strings.HasSuffix(element.File, "_test.go") && !ck.isIgnored(element.File) {
			if !testNames[element.Prefix] {
				ck.addWarning("Missing unit test %q for %q.",
					"Test_"+element.Prefix, element.FullName)
			}
		}
	}
}

func (ck *TestNameChecker) Check() {
	elements := ck.loadAllElements()
	testeeByName := ck.collectTesteeByName(elements)
	ck.checkAll(elements, testeeByName)

	for _, err := range ck.errors {
		fmt.Println(err)
	}
	for _, warning := range ck.warnings {
		if ck.warn {
			fmt.Println(warning)
		}
	}
	if len(ck.errors) > 0 || (ck.warn && len(ck.warnings) > 0) {
		ck.c.Errorf("%d %s and %d %s.",
			len(ck.errors),
			ifelseStr(len(ck.errors) == 1, "error", "errors"),
			len(ck.warnings),
			ifelseStr(len(ck.warnings) == 1, "warning", "warnings"))
	}
}

func (ck *TestNameChecker) isIgnored(filename string) bool {
	for _, mask := range ck.ignore {
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

func newElement(typeName, funcName, filename string) *testeeElement {
	typeName = strings.TrimSuffix(typeName, "Impl")

	e := testeeElement{File: filename, Type: typeName, Func: funcName}

	e.FullName = e.Type + ifelseStr(e.Type != "" && e.Func != "", ".", "") + e.Func

	e.Test = strings.HasSuffix(e.File, "_test.go") && e.Type != "" && strings.HasPrefix(e.Func, "Test")

	if e.Test {
		e.Prefix = strings.Split(strings.TrimPrefix(e.Func, "Test"), "__")[0]
	} else {
		e.Prefix = e.Type + ifelseStr(e.Type != "" && e.Func != "", "_", "") + e.Func
	}

	return &e
}

func (el *testeeElement) Less(other *testeeElement) bool {
	switch {
	case el.Type != other.Type:
		return el.Type < other.Type
	case el.Func != other.Func:
		return el.Func < other.Func
	default:
		return el.File < other.File
	}
}

func ifelseStr(cond bool, a, b string) string {
	if cond {
		return a
	}
	return b
}

func isCamelCase(str string) bool {
	for i := 0; i+1 < len(str); i++ {
		if unicode.IsLower(rune(str[i])) && unicode.IsUpper(rune(str[i+1])) {
			return true
		}
	}
	return false
}
