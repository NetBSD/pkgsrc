package pkglint

import (
	"fmt"
	"netbsd.org/pkglint/textproc"
	"strings"
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

	mlex := NewMkLinesLexer(mklines)
	for mlex.SkipPrefix("#") {
	}
	mlex.SkipEmptyOrNote()

	if mlex.SkipIf(func(mkline *MkLine) bool { return mkline.IsVarassign() && mkline.Varname() == "COMMENT" }) {
		mkline := mlex.PreviousMkLine()

		lex := textproc.NewLexer(mkline.Value())
		valid := textproc.NewByteSet("--- '(),/0-9A-Za-z")
		invalid := valid.Inverse()
		var uni strings.Builder

		for !lex.EOF() {
			_ = lex.NextBytesSet(valid)
			ch := lex.NextByteSet(invalid)
			if ch != -1 {
				_, _ = fmt.Fprintf(&uni, " %U", ch)
			}
		}

		if uni.Len() > 0 {
			mkline.Warnf("%s contains invalid characters (%s).", mkline.Varname(), uni.String()[1:])
		}

	} else {
		mlex.CurrentLine().Errorf("COMMENT= line expected.")
	}
	mlex.SkipEmptyOrNote()

	type subdir struct {
		name string
		line *MkLine
	}

	// And now to the most complicated part of the category Makefiles,
	// the (hopefully) sorted list of SUBDIRs. The first step is to
	// collect the SUBDIRs in the Makefile and in the file system.

	fSubdirs := getSubdirs(dir)
	var mSubdirs []subdir

	seen := make(map[string]*MkLine)
	for !mlex.EOF() {
		mkline := mlex.CurrentMkLine()

		if (mkline.IsVarassign() || mkline.IsCommentedVarassign()) && mkline.Varname() == "SUBDIR" {
			mlex.Skip()

			name := mkline.Value()
			if mkline.IsCommentedVarassign() && mkline.VarassignComment() == "" {
				mkline.Warnf("%q commented out without giving a reason.", name)
			}

			if prev := seen[name]; prev != nil {
				mkline.Errorf("%q must only appear once, already seen in %s.", name, mkline.RefTo(prev))
			}
			seen[name] = mkline

			if len(mSubdirs) > 0 {
				if prev := mSubdirs[len(mSubdirs)-1].name; name < prev {
					mkline.Warnf("%q should come before %q.", name, prev)
				}
			}

			mSubdirs = append(mSubdirs, subdir{name, mkline})

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
	fCheck := make(map[string]bool)
	mCheck := make(map[string]bool)
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
				fix.Errorf("%q exists in the file system but not in the Makefile.", fCurrent)
				fix.InsertBefore("SUBDIR+=\t" + fCurrent)
				fix.Apply()
			}
			fRest = fRest[1:]

		} else if len(fRest) == 0 || mRest[0].name < fRest[0] {
			if !fCheck[mRest[0].name] {
				fix := mRest[0].line.Autofix()
				fix.Errorf("%q exists in the Makefile but not in the file system.", mRest[0].name)
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
		mlex.SkipContainsOrWarn(".include \"../mk/misc/category.mk\"")
		if !mlex.EOF() {
			mlex.CurrentLine().Errorf("The file should end here.")
		}
	}

	mklines.SaveAutofixChanges()

	if G.Opts.Recursive {
		var recurseInto []string
		for _, msub := range mSubdirs {
			if !msub.line.IsCommentedVarassign() {
				recurseInto = append(recurseInto, dir+"/"+msub.name)
			}
		}
		G.Todo = append(recurseInto, G.Todo...)
	}
}
