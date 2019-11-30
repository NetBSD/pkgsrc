package pkglint

type Toplevel struct {
	dir            Path
	previousSubdir Path
	subdirs        []Path
}

func CheckdirToplevel(dir Path) {
	if trace.Tracing {
		defer trace.Call(dir)()
	}

	ctx := Toplevel{dir, "", nil}
	filename := dir + "/Makefile"

	mklines := LoadMk(filename, NotEmpty|LogErrors)
	if mklines == nil {
		return
	}

	for _, mkline := range mklines.mklines {
		if mkline.IsVarassignMaybeCommented() && mkline.Varname() == "SUBDIR" {
			ctx.checkSubdir(mkline)
		}
	}

	mklines.Check()

	if G.Opts.Recursive {
		if G.Opts.CheckGlobal {
			G.InterPackage.Enable()
		}
		G.Todo.PushFront(ctx.subdirs...)
	}
}

func (ctx *Toplevel) checkSubdir(mkline *MkLine) {
	subdir := NewPath(mkline.Value())

	if mkline.IsCommentedVarassign() {
		if !mkline.HasComment() || mkline.Comment() == "" {
			mkline.Warnf("%q commented out without giving a reason.", subdir)
		}
	}

	if containsVarRef(subdir.String()) || !ctx.dir.JoinNoClean(subdir).JoinNoClean("Makefile").IsFile() {
		return
	}

	prev := ctx.previousSubdir
	switch {
	case subdir > prev:
		// Correctly ordered
	case subdir == prev:
		mkline.Errorf("Each subdir must only appear once.")
	case subdir == "archivers" && prev == "x11":
		// This exception is documented in the top-level Makefile.
	default:
		mkline.Warnf("%s should come before %s.", subdir, prev)
	}
	ctx.previousSubdir = subdir

	if !mkline.IsCommentedVarassign() {
		ctx.subdirs = append(ctx.subdirs, ctx.dir.JoinNoClean(subdir))
	}
}
