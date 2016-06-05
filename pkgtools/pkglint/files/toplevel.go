package main

type Toplevel struct {
	previousSubdir string
	subdirs        []string
}

func CheckdirToplevel() {
	if G.opts.Debug {
		defer tracecall1(G.CurrentDir)()
	}

	ctx := new(Toplevel)
	fname := G.CurrentDir + "/Makefile"

	lines := LoadNonemptyLines(fname, true)
	if lines == nil {
		return
	}

	for _, line := range lines {
		if m, commentedOut, indentation, subdir, comment := match4(line.Text, `^(#?)SUBDIR\s*\+=(\s*)(\S+)\s*(?:#\s*(.*?)\s*|)$`); m {
			ctx.checkSubdir(line, commentedOut == "#", indentation, subdir, comment)
		}
	}

	NewMkLines(lines).Check()

	if G.opts.Recursive {
		if G.opts.CheckGlobal {
			G.UsedLicenses = make(map[string]bool)
			G.Hash = make(map[string]*Hash)
		}
		G.Todo = append(G.Todo, ctx.subdirs...)
	}
}

func (ctx *Toplevel) checkSubdir(line *Line, commentedOut bool, indentation, subdir, comment string) {
	if commentedOut && comment == "" {
		line.Warn1("%q commented out without giving a reason.", subdir)
	}

	if indentation != "\t" {
		line.Warn0("Indentation should be a single tab character.")
	}

	if contains(subdir, "$") || !fileExists(G.CurrentDir+"/"+subdir+"/Makefile") {
		return
	}

	prev := ctx.previousSubdir
	switch {
	case subdir > prev:
		// Correctly ordered
	case subdir == prev:
		line.Error0("Each subdir must only appear once.")
	case subdir == "archivers" && prev == "x11":
		// This exception is documented in the top-level Makefile.
	default:
		line.Warn2("%s should come before %s", subdir, prev)
	}
	ctx.previousSubdir = subdir

	if !commentedOut {
		ctx.subdirs = append(ctx.subdirs, G.CurrentDir+"/"+subdir)
	}
}
