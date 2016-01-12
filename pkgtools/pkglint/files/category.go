package main

import (
	"sort"
)

func CheckdirCategory() {
	if G.opts.DebugTrace {
		defer tracecall1(G.CurrentDir)()
	}

	lines := LoadNonemptyLines(G.CurrentDir+"/Makefile", true)
	if lines == nil {
		return
	}

	mklines := NewMkLines(lines)
	mklines.Check()

	exp := NewExpecter(lines)
	for exp.AdvanceIfPrefix("#") {
	}
	exp.ExpectEmptyLine()

	if exp.AdvanceIfMatches(`^COMMENT=\t*(.*)`) {
		mklines.mklines[exp.index-1].CheckValidCharactersInValue(`[- '(),/0-9A-Za-z]`)
	} else {
		exp.CurrentLine().Error0("COMMENT= line expected.")
	}
	exp.ExpectEmptyLine()

	type subdir struct {
		name   string
		line   *Line
		active bool
	}

	// And now to the most complicated part of the category Makefiles,
	// the (hopefully) sorted list of SUBDIRs. The first step is to
	// collect the SUBDIRs in the Makefile and in the file system.

	fSubdirs := getSubdirs(G.CurrentDir)
	sort.Sort(sort.StringSlice(fSubdirs))
	var mSubdirs []subdir

	prevSubdir := ""
	for !exp.EOF() {
		line := exp.CurrentLine()
		text := line.Text

		if m, commentFlag, indentation, name, comment := match4(text, `^(#?)SUBDIR\+=(\s*)(\S+)\s*(?:#\s*(.*?)\s*|)$`); m {
			commentedOut := commentFlag == "#"
			if commentedOut && comment == "" {
				line.Warn1("%q commented out without giving a reason.", name)
			}

			if indentation != "\t" {
				line.Warn0("Indentation should be a single tab character.")
			}

			if name == prevSubdir {
				line.Error1("%q must only appear once.", name)
			} else if name < prevSubdir {
				line.Warn2("%q should come before %q.", name, prevSubdir)
			} else {
				// correctly ordered
			}

			mSubdirs = append(mSubdirs, subdir{name, line, !commentedOut})
			prevSubdir = name
			exp.Advance()

		} else {
			if line.Text != "" {
				line.Error0("SUBDIR+= line or empty line expected.")
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
				if !line.AutofixInsertBefore("SUBDIR+=\t" + fCurrent) {
					line.Error1("%q exists in the file system, but not in the Makefile.", fCurrent)
				}
			}
			fNeednext = true

		} else if !mAtend && (fAtend || mCurrent < fCurrent) {
			if !fCheck[mCurrent] {
				if !line.AutofixDelete() {
					line.Error1("%q exists in the Makefile, but not in the file system.", mCurrent)
				}
			}
			mNeednext = true

		} else { // f_current == m_current
			fNeednext = true
			mNeednext = true
			if mActive {
				subdirs = append(subdirs, G.CurrentDir+"/"+mCurrent)
			}
		}
	}

	// the pkgsrc-wip category Makefile defines its own targets for
	// generating indexes and READMEs. Just skip them.
	if G.Wip {
		exp.index = len(exp.lines) - 2
	}

	exp.ExpectEmptyLine()
	exp.ExpectText(".include \"../mk/misc/category.mk\"")
	if !exp.EOF() {
		exp.CurrentLine().Error0("The file should end here.")
	}

	SaveAutofixChanges(lines)

	if G.opts.Recursive {
		G.Todo = append(append([]string(nil), subdirs...), G.Todo...)
	}
}
