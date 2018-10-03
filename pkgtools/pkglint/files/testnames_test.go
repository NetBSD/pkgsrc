package main

import (
	"go/ast"
	"go/parser"
	"go/token"
	"gopkg.in/check.v1"
	"os"
	"sort"
	"strings"
)

// Ensures that all test names follow a common naming scheme:
//
//  Test_${Type}_${Method}__${description_using_underscores}
func (s *Suite) Test__test_names(c *check.C) {

	// addTestee adds a single type or function declaration
	// to the testees.
	addTestee := func(testees *[]string, decl ast.Decl) {
		switch decl := decl.(type) {

		case *ast.GenDecl:
			for _, spec := range decl.Specs {
				switch spec := spec.(type) {
				case *ast.TypeSpec:
					*testees = append(*testees, spec.Name.Name)
				}
			}

		case *ast.FuncDecl:
			typePrefix := ""
			if decl.Recv != nil {
				typeExpr := decl.Recv.List[0].Type.(ast.Expr)
				var typeName string
				if star, ok := typeExpr.(*ast.StarExpr); ok {
					typeName = star.X.(*ast.Ident).Name
				} else {
					typeName = typeExpr.(*ast.Ident).Name
				}
				typePrefix = strings.TrimSuffix(typeName, "Impl") + "."
			}
			*testees = append(*testees, typePrefix+decl.Name.Name)
		}
	}

	// loadAllTestees returns all type, function and method names
	// from the current package, in the form FunctionName or
	// TypeName.MethodName (omitting the * from the type name).
	loadAllTestees := func() []string {
		fset := token.NewFileSet()
		pkgs, err := parser.ParseDir(fset, ".", func(fi os.FileInfo) bool { return true }, 0)
		if err != nil {
			panic(err)
		}

		var typesAndFunctions []string
		for _, file := range pkgs["main"].Files {
			for _, decl := range file.Decls {
				addTestee(&typesAndFunctions, decl)
			}
		}

		sort.Strings(typesAndFunctions)
		return typesAndFunctions
	}

	generateAllowedPrefixes := func(typesAndFunctions []string) map[string]bool {
		prefixes := make(map[string]bool)
		for _, funcName := range typesAndFunctions {
			prefix := strings.Replace(funcName, ".", "_", 1)
			prefixes[prefix] = true
		}

		// Allow some special test name prefixes.
		prefixes["Varalign"] = true
		prefixes["ShellParser"] = true
		return prefixes
	}

	checkTestName := func(fullTestMethod string, testee string, descr string, prefixes map[string]bool) {
		if !prefixes[testee] {
			c.Errorf("%s: Testee %q not found.\n", fullTestMethod, testee)
		}
		if matches(descr, `\p{Ll}\p{Lu}`) {
			switch descr {
			case "comparing_YesNo_variable_to_string",
				"GitHub",
				"enumFrom",
				"dquotBacktDquot",
				"and_getSubdirs":
				// These exceptions are ok.

			default:
				c.Errorf("%s: Test description must not use CamelCase.\n", fullTestMethod)
			}
		}
	}

	checkAll := func(typesAndFunctions []string, prefixes map[string]bool) {
		for _, funcName := range typesAndFunctions {
			typeAndMethod := strings.SplitN(funcName, ".", 2)
			if len(typeAndMethod) == 2 {
				method := typeAndMethod[1]
				switch {
				case !hasPrefix(method, "Test"):
					// Ignore

				case hasPrefix(method, "Test__"):
					// OK

				case hasPrefix(method, "Test_"):
					refAndDescr := strings.SplitN(method[5:], "__", 2)
					descr := ""
					if len(refAndDescr) > 1 {
						descr = refAndDescr[1]
					}
					checkTestName(funcName, refAndDescr[0], descr, prefixes)

				default:
					c.Errorf("%s: Missing underscore.\n", funcName)
				}
			}
		}
	}

	testees := loadAllTestees()
	prefixes := generateAllowedPrefixes(testees)
	checkAll(testees, prefixes)
}
