package main

import (
	"netbsd.org/pkglint/trace"
	"sort"
)

func CheckdirCategory(dir string) {
	if trace.Tracing {
		defer trace.Call1(dir)()
	}

	mklines := LoadMk(dir+"/Makefile", NotEmpty|LogErrors)
	if mklines == nil {
		return
	}

	mklines.Check()

	exp := NewMkExpecter(mklines)
	for exp.AdvanceIfPrefix("#") {
	}
	exp.ExpectEmptyLine(G.opts.WarnSpace)

	if exp.AdvanceIfMatches(`^COMMENT=\t*(.*)`) {
		MkLineChecker{mklines.mklines[exp.Index()-1]}.CheckValidCharactersInValue(`[- '(),/0-9A-Za-z]`)
	} else {
		exp.CurrentLine().Errorf("COMMENT= line expected.")
	}
	exp.ExpectEmptyLine(G.opts.WarnSpace)

	type subdir struct {
		name   string
		line   Line
		active bool
	}

	// And now to the most complicated part of the category Makefiles,
	// the (hopefully) sorted list of SUBDIRs. The first step is to
	// collect the SUBDIRs in the Makefile and in the file system.

	fSubdirs := getSubdirs(dir)
	sort.Strings(fSubdirs)
	var mSubdirs []subdir

	prevSubdir := ""
	for !exp.EOF() {
		line := exp.CurrentLine()
		text := line.Text

		if m, commentFlag, indentation, name, comment := match4(text, `^(#?)SUBDIR\+=(\s*)(\S+)\s*(?:#\s*(.*?)\s*|)$`); m {
			commentedOut := commentFlag == "#"
			if commentedOut && comment == "" {
				line.Warnf("%q commented out without giving a reason.", name)
			}

			if indentation != "\t" {
				line.Warnf("Indentation should be a single tab character.")
			}

			if name == prevSubdir {
				line.Errorf("%q must only appear once.", name)
			} else if name < prevSubdir {
				line.Warnf("%q should come before %q.", name, prevSubdir)
			} else {
				// correctly ordered
			}

			mSubdirs = append(mSubdirs, subdir{name, line, !commentedOut})
			prevSubdir = name
			exp.Advance()

		} else {
			if line.Text != "" {
				line.Errorf("SUBDIR+= line or empty line expected.")
			}
			break
		}
	}

	// To prevent unnecessary warnings about subdirectories that are
	// in one list, but not in the other, we generate the sets of
	// subdirs of each list.
	fCheck := make(map[string]bool)
	mCheck := make(map[string]bool)
	for _, fsub := range fSubdirs {
		fCheck[fsub] = true
	}
	for _, msub := range mSubdirs {
		mCheck[msub.name] = true
	}

	fIndex, fAtend, fNeednext, fCurrent := 0, false, true, ""
	mIndex, mAtend, mNeednext, mCurrent := 0, false, true, ""

	var subdirs []string

	var line Line
	mActive := false

	for !(mAtend && fAtend) {
		if !mAtend && mNeednext {
			mNeednext = false
			if mIndex >= len(mSubdirs) {
				mAtend = true
				line = exp.CurrentLine()
				continue
			} else {
				mCurrent = mSubdirs[mIndex].name
				line = mSubdirs[mIndex].line
				mActive = mSubdirs[mIndex].active
				mIndex++
			}
		}

		if !fAtend && fNeednext {
			fNeednext = false
			if fIndex >= len(fSubdirs) {
				fAtend = true
				continue
			} else {
				fCurrent = fSubdirs[fIndex]
				fIndex++
			}
		}

		if !fAtend && (mAtend || fCurrent < mCurrent) {
			if !mCheck[fCurrent] {
				fix := line.Autofix()
				fix.Errorf("%q exists in the file system, but not in the Makefile.", fCurrent)
				fix.InsertBefore("SUBDIR+=\t" + fCurrent)
				fix.Apply()
			}
			fNeednext = true

		} else if !mAtend && (fAtend || mCurrent < fCurrent) {
			if !fCheck[mCurrent] {
				fix := line.Autofix()
				fix.Errorf("%q exists in the Makefile, but not in the file system.", mCurrent)
				fix.Delete()
				fix.Apply()
			}
			mNeednext = true

		} else { // f_current == m_current
			fNeednext = true
			mNeednext = true
			if mActive {
				subdirs = append(subdirs, dir+"/"+mCurrent)
			}
		}
	}

	// the pkgsrc-wip category Makefile defines its own targets for
	// generating indexes and READMEs. Just skip them.
	if G.Wip {
		exp.SkipToFooter()
	}

	exp.ExpectEmptyLine(G.opts.WarnSpace)
	exp.ExpectText(".include \"../mk/misc/category.mk\"")
	if !exp.EOF() {
		exp.CurrentLine().Errorf("The file should end here.")
	}

	mklines.SaveAutofixChanges()

	if G.opts.Recursive {
		G.Todo = append(append([]string(nil), subdirs...), G.Todo...)
	}
}
