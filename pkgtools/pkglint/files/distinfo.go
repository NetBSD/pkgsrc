package main

import (
	"bytes"
	"crypto/sha1"
	"io/ioutil"
	"strings"
)

func checklinesDistinfo(lines []*Line) {
	defer tracecall("checklinesDistinfo", lines[0].fname)()

	fname := lines[0].fname
	var patchesDir = "patches"
	if G.pkgContext != nil && dirExists(G.currentDir+"/"+G.pkgContext.patchdir) {
		patchesDir = G.pkgContext.patchdir
	}
	if G.pkgContext != nil && hasSuffix(fname, "/lang/php54/distinfo") {
		patchesDir = G.curPkgsrcdir + "/lang/php54/patches"
	}
	_ = G.opts.DebugMisc && debugf(fname, NO_LINES, "patchesDir=%q", patchesDir)

	ck := &distinfoLinesChecker{
		fname, patchesDir, isCommitted(fname),
		make(map[string]bool), "", false, nil}
	ck.checkLines(lines)
	checklinesTrailingEmptyLines(lines)
	ck.checkUnrecordedPatches()
}

type distinfoLinesChecker struct {
	fname       string
	patchdir    string // Relative to G.currentDir
	isCommitted bool

	patches          map[string]bool
	previousFilename string
	isPatch          bool
	algorithms       []string
}

func (ck *distinfoLinesChecker) checkLines(lines []*Line) {
	checklineRcsid(lines[0], ``, "")
	if 1 < len(lines) && lines[1].text != "" {
		lines[1].notef("Empty line expected.")
	}

	for i, line := range lines {
		if i < 2 {
			continue
		}
		m, alg, fname, hash := match3(line.text, `^(\w+) \((\w[^)]*)\) = (.*)(?: bytes)?$`)
		if !m {
			line.errorf("Invalid line.")
			continue
		}

		if fname != ck.previousFilename {
			ck.onFilenameChange(line, fname)
		}
		ck.algorithms = append(ck.algorithms, alg)

		ck.checkGlobalMismatch(line, fname, alg, hash)
		ck.checkUncommittedPatch(line, fname, hash)
	}
	ck.onFilenameChange(NewLine(ck.fname, "EOF", "", nil), "")
}

func (ctx *distinfoLinesChecker) onFilenameChange(line *Line, nextFname string) {
	prevFname := ctx.previousFilename
	if prevFname != "" {
		algorithms := strings.Join(ctx.algorithms, ", ")
		if ctx.isPatch {
			if algorithms != "SHA1" {
				line.errorf("Expected SHA1 hash for %s, got %s.", prevFname, algorithms)
			}
		} else {
			if algorithms != "SHA1, RMD160, Size" && algorithms != "SHA1, RMD160, SHA512, Size" {
				line.errorf("Expected SHA1, RMD160, SHA512, Size checksums for %q, got %s.", prevFname, algorithms)
			}
		}
	}

	ctx.isPatch = matches(nextFname, `^patch-.+$`) && fileExists(G.currentDir+"/"+ctx.patchdir+"/"+nextFname)
	ctx.previousFilename = nextFname
	ctx.algorithms = nil
}

func (ctx *distinfoLinesChecker) checkPatchSha1(line *Line, fname, distinfoSha1Hex string) {
	patchBytes, err := ioutil.ReadFile(fname)
	if err != nil {
		line.errorf("%s does not exist.", fname)
		return
	}

	h := sha1.New()
	netbsd := []byte("$NetBSD")
	for _, patchLine := range bytes.SplitAfter(patchBytes, []byte("\n")) {
		if !bytes.Contains(patchLine, netbsd) {
			h.Write(patchLine)
		}
	}
	fileSha1Hex := sprintf("%x", h.Sum(nil))
	if distinfoSha1Hex != fileSha1Hex {
		line.errorf("%s hash of %s differs (distinfo has %s, patch file has %s). Run \"%s makepatchsum\".", "SHA1", fname, distinfoSha1Hex, fileSha1Hex, confMake)
	}
}

func (ck *distinfoLinesChecker) checkUnrecordedPatches() {
	files, err := ioutil.ReadDir(G.currentDir + "/" + ck.patchdir)
	if err != nil {
		for _, file := range files {
			patch := file.Name()
			if !ck.patches[patch] {
				errorf(ck.fname, NO_LINES, "patch is not recorded. Run \"%s makepatchsum\".", confMake)
			}
		}
	}
}

// Inter-package check for differing distfile checksums.
func (ck *distinfoLinesChecker) checkGlobalMismatch(line *Line, fname, alg, hash string) {
	if G.ipcDistinfo != nil && !ck.isPatch {
		key := alg + ":" + fname
		otherHash := G.ipcDistinfo[key]
		if otherHash != nil {
			if otherHash.hash != hash {
				line.errorf("The hash %s for %s is %s, ...", alg, fname, hash)
				otherHash.line.errorf("... which differs from %s.", otherHash.hash)
			}
		} else {
			G.ipcDistinfo[key] = &Hash{hash, line}
		}
	}
}

func (ck *distinfoLinesChecker) checkUncommittedPatch(line *Line, fname, sha1Hash string) {
	if ck.isPatch {
		fname := G.currentDir + "/" + ck.patchdir + "/" + fname
		if ck.isCommitted && !isCommitted(fname) {
			line.warnf("%s/%s is registered in distinfo but not added to CVS.", ck.patchdir, fname)
		}
		ck.checkPatchSha1(line, fname, sha1Hash)
		ck.patches[fname] = true
	}
}
