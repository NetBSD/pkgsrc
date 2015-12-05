package main

import (
	"os"
	"path"
)

func CheckDirent(fname string) {
	defer tracecall("CheckDirent", fname)()

	st, err := os.Lstat(fname)
	if err != nil || !st.Mode().IsDir() && !st.Mode().IsRegular() {
		errorf(fname, noLines, "No such file or directory.")
		return
	}
	isDir := st.Mode().IsDir()
	isReg := st.Mode().IsRegular()

	G.currentDir = ifelseStr(isReg, path.Dir(fname), fname)
	absCurrentDir := abspath(G.currentDir)
	G.isWip = !G.opts.Import && matches(absCurrentDir, `/wip/|/wip$`)
	G.isInfrastructure = matches(absCurrentDir, `/mk/|/mk$`)
	G.curPkgsrcdir = findPkgsrcTopdir(G.currentDir)
	if G.curPkgsrcdir == "" {
		errorf(fname, noLines, "Cannot determine the pkgsrc root directory for %q.", G.currentDir)
		return
	}

	switch {
	case isDir && isEmptyDir(fname):
		return
	case isReg:
		checkfile(fname)
		return
	}

	switch G.curPkgsrcdir {
	case "../..":
		checkdirPackage(relpath(G.globalData.pkgsrcdir, G.currentDir))
	case "..":
		checkdirCategory()
	case ".":
		checkdirToplevel()
	default:
		errorf(fname, noLines, "Cannot check directories outside a pkgsrc tree.")
	}
}
