package main

type Toplevel struct {
	dir            string
	previousSubdir string
	subdirs        []string
}

func CheckdirToplevel(dir string) {
	if trace.Tracing {
		defer trace.Call1(dir)()
	}

	ctx := &Toplevel{dir, "", nil}
	fileName := dir + "/Makefile"

	mklines := LoadMk(fileName, NotEmpty|LogErrors)
	if mklines == nil {
		return
	}

	for _, mkline := range mklines.mklines {
		if (mkline.IsVarassign() || mkline.IsCommentedVarassign()) && mkline.Varname() == "SUBDIR" {
			ctx.checkSubdir(mkline)
		}
	}

	mklines.Check()

	if G.Opts.Recursive {
		if G.Opts.CheckGlobal {
			G.Pkgsrc.UsedLicenses = make(map[string]bool)
			G.Pkgsrc.Hashes = make(map[string]*Hash)
		}
		G.Todo = append(append([]string(nil), ctx.subdirs...), G.Todo...)
	}
}

func (ctx *Toplevel) checkSubdir(mkline MkLine) {
	subdir := mkline.Value()

	if mkline.IsCommentedVarassign() && (mkline.VarassignComment() == "#" || mkline.VarassignComment() == "") {
		mkline.Warnf("%q commented out without giving a reason.", subdir)
	}

	if !hasSuffix(mkline.ValueAlign(), "=\t") {
		mkline.Warnf("Indentation should be a single tab character.")
	}

	if contains(subdir, "$") || !fileExists(ctx.dir+"/"+subdir+"/Makefile") {
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
		ctx.subdirs = append(ctx.subdirs, ctx.dir+"/"+subdir)
	}
}
