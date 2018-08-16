package main

import (
	"bytes"
	"crypto/sha1"
	"fmt"
	"io/ioutil"
	"netbsd.org/pkglint/trace"
	"path"
	"strings"
)

func ChecklinesDistinfo(lines []Line) {
	if trace.Tracing {
		defer trace.Call1(lines[0].Filename)()
	}

	fname := lines[0].Filename
	patchdir := "patches"
	if G.Pkg != nil && dirExists(G.Pkg.File(G.Pkg.Patchdir)) {
		patchdir = G.Pkg.Patchdir
	}
	if trace.Tracing {
		trace.Step1("patchdir=%q", patchdir)
	}

	distinfoIsCommitted := isCommitted(fname)
	ck := &distinfoLinesChecker{
		fname, patchdir, distinfoIsCommitted,
		make(map[string]bool), nil, "", unknown, nil}
	ck.checkLines(lines)
	ChecklinesTrailingEmptyLines(lines)
	ck.checkUnrecordedPatches()
	SaveAutofixChanges(lines)
}

type distinfoLinesChecker struct {
	distinfoFilename    string
	patchdir            string // Relative to G.Pkg
	distinfoIsCommitted bool

	patches          map[string]bool // "patch-aa" => true
	currentFirstLine Line
	currentFilename  string
	isPatch          YesNoUnknown
	algorithms       []string
}

func (ck *distinfoLinesChecker) checkLines(lines []Line) {
	CheckLineRcsid(lines[0], ``, "")
	if 1 < len(lines) && lines[1].Text != "" {
		lines[1].Notef("Empty line expected.")
	}

	for i, line := range lines {
		if i < 2 {
			continue
		}
		m, alg, filename, hash := match3(line.Text, `^(\w+) \((\w[^)]*)\) = (.*)(?: bytes)?$`)
		if !m {
			line.Errorf("Invalid line.")
			continue
		}

		if filename != ck.currentFilename {
			ck.onFilenameChange(line, filename)
		}
		ck.algorithms = append(ck.algorithms, alg)

		ck.checkGlobalMismatch(line, filename, alg, hash)
		ck.checkUncommittedPatch(line, filename, alg, hash)
	}
	ck.onFilenameChange(NewLineEOF(ck.distinfoFilename), "")
}

func (ck *distinfoLinesChecker) onFilenameChange(line Line, nextFname string) {
	currentFname := ck.currentFilename
	if currentFname != "" {
		algorithms := strings.Join(ck.algorithms, ", ")
		if ck.isPatch == yes {
			if algorithms != "SHA1" {
				line.Errorf("Expected SHA1 hash for %s, got %s.", currentFname, algorithms)
			}
		} else if ck.isPatch == unknown {
		} else if G.Pkg != nil && G.Pkg.IgnoreMissingPatches {
		} else if hasPrefix(currentFname, "patch-") && algorithms == "SHA1" {
			pathToPatchdir := relpath(path.Dir(ck.currentFirstLine.Filename), G.Pkg.File(ck.patchdir))
			ck.currentFirstLine.Warnf("Patch file %q does not exist in directory %q.", currentFname, pathToPatchdir)
			Explain(
				"If the patches directory looks correct, the patch may have been",
				"removed without updating the distinfo file.  In such a case please",
				"update the distinfo file.",
				"",
				"If the patches directory looks wrong, pkglint needs to be improved.")
		} else if algorithms != "SHA1, RMD160, Size" && algorithms != "SHA1, RMD160, SHA512, Size" {
			line.Errorf("Expected SHA1, RMD160, SHA512, Size checksums for %q, got %s.", currentFname, algorithms)
		}
	}

	if !hasPrefix(nextFname, "patch-") {
		ck.isPatch = no
	} else if G.Pkg == nil {
		ck.isPatch = unknown
	} else if fileExists(G.Pkg.File(ck.patchdir + "/" + nextFname)) {
		ck.isPatch = yes
	} else {
		ck.isPatch = no
	}

	ck.currentFilename = nextFname
	ck.currentFirstLine = line
	ck.algorithms = nil
}

func (ck *distinfoLinesChecker) checkUnrecordedPatches() {
	if G.Pkg == nil {
		return
	}
	files, err := ioutil.ReadDir(G.Pkg.File(ck.patchdir))
	if err != nil {
		if trace.Tracing {
			trace.Stepf("Cannot read patchesDir %q: %s", ck.patchdir, err)
		}
		return
	}

	for _, file := range files {
		patch := file.Name()
		if file.Mode().IsRegular() && !ck.patches[patch] && hasPrefix(patch, "patch-") {
			NewLineWhole(ck.distinfoFilename).Errorf("patch %q is not recorded. Run \"%s makepatchsum\".", ck.patchdir+"/"+patch, confMake)
		}
	}
}

// Inter-package check for differing distfile checksums.
func (ck *distinfoLinesChecker) checkGlobalMismatch(line Line, fname, alg, hash string) {
	hashes := G.Pkgsrc.Hashes
	if hashes != nil && !hasPrefix(fname, "patch-") { // Intentionally checking the filename instead of ck.isPatch
		key := alg + ":" + fname
		otherHash := hashes[key]
		if otherHash != nil {
			if otherHash.hash != hash {
				line.Errorf("The hash %s for %s is %s, which differs from %s in %s.",
					alg, fname, hash, otherHash.hash, otherHash.line.ReferenceFrom(line))
			}
		} else {
			hashes[key] = &Hash{hash, line}
		}
	}
}

func (ck *distinfoLinesChecker) checkUncommittedPatch(line Line, patchName, alg, hash string) {
	if ck.isPatch == yes {
		patchFname := ck.patchdir + "/" + patchName
		if ck.distinfoIsCommitted && !isCommitted(G.Pkg.File(patchFname)) {
			line.Warnf("%s is registered in distinfo but not added to CVS.", patchFname)
		}
		if alg == "SHA1" {
			ck.checkPatchSha1(line, patchFname, hash)
		}
		ck.patches[patchName] = true
	}
}

func (ck *distinfoLinesChecker) checkPatchSha1(line Line, patchFname, distinfoSha1Hex string) {
	fileSha1Hex, err := computePatchSha1Hex(G.Pkg.File(patchFname))
	if err != nil {
		line.Errorf("%s does not exist.", patchFname)
		return
	}
	if distinfoSha1Hex != fileSha1Hex {
		fix := line.Autofix()
		fix.Errorf("%s hash of %s differs (distinfo has %s, patch file has %s). Run \"%s makepatchsum\".",
			"SHA1", patchFname, distinfoSha1Hex, fileSha1Hex, confMake)
		fix.Replace(distinfoSha1Hex, fileSha1Hex)
		fix.Apply()
	}
}

// Same as in mk/checksum/distinfo.awk:/function patchsum/
func computePatchSha1Hex(patchFilename string) (string, error) {
	patchBytes, err := ioutil.ReadFile(patchFilename)
	if err != nil {
		return "", err
	}

	hash := sha1.New()
	netbsd := []byte("$" + "NetBSD")
	for _, patchLine := range bytes.SplitAfter(patchBytes, []byte("\n")) {
		if !bytes.Contains(patchLine, netbsd) {
			hash.Write(patchLine)
		}
	}
	return fmt.Sprintf("%x", hash.Sum(nil)), nil
}

func AutofixDistinfo(oldSha1, newSha1 string) {
	distinfoFilename := G.Pkg.File(G.Pkg.DistinfoFile)
	if lines := Load(distinfoFilename, NotEmpty|LogErrors); lines != nil {
		for _, line := range lines {
			fix := line.Autofix()
			fix.Warnf("Silent-Magic-Diagnostic")
			fix.Replace(oldSha1, newSha1)
			fix.Apply()
		}
		SaveAutofixChanges(lines)
	}
}
