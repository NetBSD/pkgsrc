package pkglint

import "netbsd.org/pkglint/textproc"

func CheckdirCategory(dir CurrPath) {
	if trace.Tracing {
		defer trace.Call(dir)()
	}

	mklines := LoadMk(dir.JoinNoClean("Makefile").CleanDot(), nil, NotEmpty|LogErrors)
	if mklines == nil {
		return
	}

	mklines.Check()

	mlex := NewMkLinesLexer(mklines)
	for mlex.SkipPrefix("#") {
	}
	mlex.SkipEmptyOrNote()

	if mlex.SkipIf(func(mkline *MkLine) bool { return mkline.IsVarassign() && mkline.Varname() == "COMMENT" }) {
		mkline := mlex.PreviousMkLine()

		valid := textproc.NewByteSet("--- '(),/0-9A-Za-z")
		invalid := invalidCharacters(mkline.Value(), valid)
		if invalid != "" {
			mkline.Warnf("%s contains invalid characters (%s).",
				mkline.Varname(), invalid)
		}

	} else {
		mlex.CurrentLine().Errorf("COMMENT= line expected.")
	}
	mlex.SkipEmptyOrNote()

	type subdir struct {
		name RelPath
		line *MkLine
	}

	// And now to the most complicated part of the category Makefiles,
	// the (hopefully) sorted list of SUBDIRs. The first step is to
	// collect the SUBDIRs in the Makefile and in the file system.

	var fSubdirs []RelPath
	var mSubdirs []subdir

	for _, subdir := range getSubdirs(dir) {
		if dir.JoinNoClean(subdir).JoinNoClean("Makefile").IsFile() {
			fSubdirs = append(fSubdirs, subdir)
		}
	}

	seen := make(map[RelPath]*MkLine)
	for !mlex.EOF() {
		mkline := mlex.CurrentMkLine()

		if mkline.IsVarassignMaybeCommented() && mkline.Varname() == "SUBDIR" {
			mlex.Skip()

			value := NewPath(mkline.Value())
			if value.IsAbs() {
				mkline.Errorf("%q must be a relative path.", value.String())
				continue
			}
			sub := NewRelPath(value)

			if mkline.IsCommentedVarassign() && !mkline.HasComment() {
				mkline.Warnf("%q commented out without giving a reason.", sub)
			}

			if prev := seen[sub]; prev != nil {
				mkline.Errorf("%q must only appear once, already seen in %s.",
					sub, mkline.RelMkLine(prev))
			}
			seen[sub] = mkline

			if len(mSubdirs) > 0 {
				if prev := mSubdirs[len(mSubdirs)-1].name; sub < prev {
					mkline.Warnf("%q should come before %q.", sub, prev)
				}
			}

			mSubdirs = append(mSubdirs, subdir{sub, mkline})

		} else {
			if !mkline.IsEmpty() {
				mkline.Errorf("SUBDIR+= line or empty line expected.")
			}
			break
		}
	}

	// To prevent unnecessary warnings about subdirectories that are
	// in one list but not in the other, generate the sets of
	// subdirs of each list.
	fCheck := make(map[RelPath]bool)
	mCheck := make(map[RelPath]bool)
	for _, fsub := range fSubdirs {
		fCheck[fsub] = true
	}
	for _, msub := range mSubdirs {
		mCheck[msub.name] = true
	}

	fRest := fSubdirs[:]
	mRest := mSubdirs[:]

	for len(mRest) > 0 || len(fRest) > 0 {

		if len(fRest) > 0 && (len(mRest) == 0 || fRest[0] < mRest[0].name) {
			fCurrent := fRest[0]
			if !mCheck[fCurrent] {
				var line *Line
				if len(mRest) > 0 {
					line = mRest[0].line.Line
				} else {
					line = mlex.CurrentLine()
				}

				fix := line.Autofix()
				fix.Errorf("Package %q must be listed here.", fCurrent)
				fix.InsertAbove("SUBDIR+=\t" + fCurrent.String())
				fix.Apply()
			}
			fRest = fRest[1:]

		} else if len(fRest) == 0 || mRest[0].name < fRest[0] {
			if !fCheck[mRest[0].name] {
				fix := mRest[0].line.Autofix()
				fix.Errorf("%q does not contain a package.", mRest[0].name)
				fix.Delete()
				fix.Apply()
			}
			mRest = mRest[1:]

		} else {
			fRest = fRest[1:]
			mRest = mRest[1:]
		}
	}

	// the pkgsrc-wip category Makefile defines its own targets for
	// generating indexes and READMEs. Just skip them.
	if !G.Wip {
		mlex.SkipEmptyOrNote()
		mlex.SkipTextOrWarn(".include \"../mk/misc/category.mk\"")
		if !mlex.EOF() {
			mlex.CurrentLine().Errorf("The file must end here.")
		}
	}

	mklines.SaveAutofixChanges()

	if G.Recursive {
		var recurseInto []CurrPath
		for _, msub := range mSubdirs {
			if !msub.line.IsCommentedVarassign() {
				recurseInto = append(recurseInto, dir.JoinNoClean(msub.name))
			}
		}
		G.Todo.PushFront(recurseInto...)
	}
}
