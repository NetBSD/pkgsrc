package main

type Toplevel struct {
	previousSubdir string
	subdirs        []string
}

func checkdirToplevel() {
	defer tracecall("checkdirToplevel", G.currentDir)()

	ctx := new(Toplevel)

	fname := G.currentDir + "/Makefile"

	lines := LoadNonemptyLines(fname, true)
	if lines == nil {
		return
	}

	ParselinesMk(lines)

	for _, line := range lines {
		if m, commentedOut, indentation, subdir, comment := match4(line.text, `^(#?)SUBDIR\s*\+=(\s*)(\S+)\s*(?:#\s*(.*?)\s*|)$`); m {
			ctx.checkSubdir(line, commentedOut == "#", indentation, subdir, comment)
		}
	}

	ChecklinesMk(lines)

	if G.opts.Recursive {
		if G.opts.CheckGlobal {
			G.ipcUsedLicenses = make(map[string]bool)
		}
		G.todo = append(G.todo, ctx.subdirs...)
	}
}

func (ctx *Toplevel) checkSubdir(line *Line, commentedOut bool, indentation, subdir, comment string) {
	if commentedOut && comment == "" {
		line.warnf("%q commented out without giving a reason.", subdir)
	}

	if indentation != "\t" {
		line.warnf("Indentation should be a single tab character.")
	}

	if contains(subdir, "$") || !fileExists(G.currentDir+"/"+subdir+"/Makefile") {
		return
	}

	prev := ctx.previousSubdir
	switch {
	case subdir > prev:
		// Correctly ordered
	case subdir == prev:
		line.errorf("Each subdir must only appear once.")
	case subdir == "archivers" && prev == "x11":
		// This exception is documented in the top-level Makefile.
	default:
		line.warnf("%s should come before %s", subdir, prev)
	}
	ctx.previousSubdir = subdir

	if !commentedOut {
		ctx.subdirs = append(ctx.subdirs, G.currentDir+"/"+subdir)
	}
}
