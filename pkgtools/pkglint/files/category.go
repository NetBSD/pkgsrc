package main

import (
	"sort"
)

type subdir struct {
	name   string
	line   *Line
	active bool
}

func checkdirCategory() {
	defer tracecall("checkdirCategory", G.currentDir)()

	fname := G.currentDir + "/Makefile"
	lines := LoadNonemptyLines(fname, true)
	if lines == nil {
		return
	}
	ParselinesMk(lines)

	exp := NewExpecter(lines)
	if checklineRcsid(exp.currentLine(), `#\s+`, "# ") {
		exp.advance()
	}

	for !exp.eof() && exp.advanceIfMatches(`^#`) != nil {
	}
	exp.expectEmptyLine()

	if exp.advanceIfMatches(`^COMMENT=\t*(.*)`) != nil {
		checklineValidCharactersInValue(exp.previousLine(), `[- '(),/0-9A-Za-z]`)
	} else {
		exp.currentLine().errorf("COMMENT= line expected.")
	}
	exp.expectEmptyLine()

	// And now to the most complicated part of the category Makefiles,
	// the (hopefully) sorted list of SUBDIRs. The first step is to
	// collect the SUBDIRs in the Makefile and in the file system.

	fSubdirs := getSubdirs(G.currentDir)
	sort.Sort(sort.StringSlice(fSubdirs))
	var mSubdirs []subdir

	prevSubdir := ""
	for !exp.eof() {
		line := exp.currentLine()
		text := line.text

		if m, commentFlag, indentation, name, comment := match4(text, `^(#?)SUBDIR\+=(\s*)(\S+)\s*(?:#\s*(.*?)\s*|)$`); m {
			commentedOut := commentFlag == "#"
			if commentedOut && comment == "" {
				line.warnf("%q commented out without giving a reason.", name)
			}

			if indentation != "\t" {
				line.warnf("Indentation should be a single tab character.")
			}

			if name == prevSubdir {
				line.errorf("%q must only appear once.", name)
			} else if name < prevSubdir {
				line.warnf("%q should come before %q.", name, prevSubdir)
			} else {
				// correctly ordered
			}

			mSubdirs = append(mSubdirs, subdir{name, line, !commentedOut})
			prevSubdir = name
			exp.advance()

		} else {
			if line.text != "" {
				line.errorf("SUBDIR+= line or empty line expected.")
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

	var line *Line
	mActive := false

	for !(mAtend && fAtend) {
		if !mAtend && mNeednext {
			mNeednext = false
			if mIndex >= len(mSubdirs) {
				mAtend = true
				line = exp.currentLine()
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
				line.errorf("%q exists in the file system, but not in the Makefile.", fCurrent)
				line.insertBefore("SUBDIR+=\t" + fCurrent)
			}
			fNeednext = true

		} else if !mAtend && (fAtend || mCurrent < fCurrent) {
			if !fCheck[mCurrent] {
				line.errorf("%q exists in the Makefile, but not in the file system.", mCurrent)
				line.delete()
			}
			mNeednext = true

		} else { // f_current == m_current
			fNeednext = true
			mNeednext = true
			if mActive {
				subdirs = append(subdirs, G.currentDir+"/"+mCurrent)
			}
		}
	}

	// the pkgsrc-wip category Makefile defines its own targets for
	// generating indexes and READMEs. Just skip them.
	if G.isWip {
		exp.index = len(exp.lines) - 2
	}

	exp.expectEmptyLine()

	if exp.currentLine().text == ".include \"../mk/bsd.pkg.subdir.mk\"" {
		exp.advance()
	} else {
		exp.expectText(".include \"../mk/misc/category.mk\"")
	}

	if !exp.eof() {
		exp.currentLine().errorf("The file should end here.")
	}

	ChecklinesMk(lines)

	saveAutofixChanges(lines)

	if G.opts.Recursive {
		G.todo = append(append([]string(nil), subdirs...), G.todo...)
	}
}
