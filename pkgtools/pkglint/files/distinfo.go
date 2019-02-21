package pkglint

import (
	"bytes"
	"crypto/sha1"
	"encoding/hex"
	"io/ioutil"
	"path"
	"strings"
)

func CheckLinesDistinfo(lines Lines) {
	if trace.Tracing {
		defer trace.Call1(lines.FileName)()
	}

	filename := lines.FileName
	patchdir := "patches"
	if G.Pkg != nil && dirExists(G.Pkg.File(G.Pkg.Patchdir)) {
		patchdir = G.Pkg.Patchdir
	}
	if trace.Tracing {
		trace.Step1("patchdir=%q", patchdir)
	}

	distinfoIsCommitted := isCommitted(filename)
	ck := distinfoLinesChecker{
		lines, patchdir, distinfoIsCommitted,
		make(map[string]bool), "", nil, unknown, nil}
	ck.checkLines(lines)
	CheckLinesTrailingEmptyLines(lines)
	ck.checkUnrecordedPatches()
	SaveAutofixChanges(lines)
}

// XXX: Maybe an approach that first groups the lines by filename
// is easier to understand.

type distinfoLinesChecker struct {
	distinfoLines       Lines
	patchdir            string // Relative to G.Pkg
	distinfoIsCommitted bool

	// All patches that are mentioned in the distinfo file.
	patches map[string]bool // "patch-aa" => true

	currentFileName  string
	currentFirstLine Line         // The first line of the currentFileName group
	isPatch          YesNoUnknown // Whether currentFileName is a patch, as opposed to a distfile
	algorithms       []string     // The algorithms seen for currentFileName
}

func (ck *distinfoLinesChecker) checkLines(lines Lines) {
	lines.CheckRcsID(0, ``, "")
	if 1 < len(lines.Lines) && lines.Lines[1].Text != "" {
		lines.Lines[1].Notef("Empty line expected.")
	}

	for i, line := range lines.Lines {
		if i < 2 {
			continue
		}
		m, alg, filename, hash := match3(line.Text, `^(\w+) \((\w[^)]*)\) = (.*)(?: bytes)?$`)
		if !m {
			line.Errorf("Invalid line: %s", line.Text)
			continue
		}

		if filename != ck.currentFileName {
			ck.onFilenameChange(line, filename)
		}
		ck.algorithms = append(ck.algorithms, alg)

		ck.checkGlobalDistfileMismatch(line, filename, alg, hash)
		ck.checkUncommittedPatch(line, filename, alg, hash)
	}
	ck.onFilenameChange(ck.distinfoLines.EOFLine(), "")
}

func (ck *distinfoLinesChecker) onFilenameChange(line Line, nextFname string) {
	if ck.currentFileName != "" {
		ck.checkAlgorithms(line)
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

	ck.currentFileName = nextFname
	ck.currentFirstLine = line
	ck.algorithms = nil
}

func (ck *distinfoLinesChecker) checkAlgorithms(line Line) {
	filename := ck.currentFileName
	algorithms := strings.Join(ck.algorithms, ", ")

	switch {

	case ck.isPatch == yes:
		if algorithms != "SHA1" {
			line.Errorf("Expected SHA1 hash for %s, got %s.", filename, algorithms)
		}

	case ck.isPatch == unknown:
		break

	case G.Pkg != nil && G.Pkg.IgnoreMissingPatches:
		break

	case hasPrefix(filename, "patch-") && algorithms == "SHA1":
		pathToPatchdir := relpath(path.Dir(ck.currentFirstLine.Filename), G.Pkg.File(ck.patchdir))
		ck.currentFirstLine.Warnf("Patch file %q does not exist in directory %q.", filename, pathToPatchdir)
		G.Explain(
			"If the patches directory looks correct, the patch may have been",
			"removed without updating the distinfo file.",
			"In such a case please update the distinfo file.",
			"",
			"If the patches directory looks wrong, pkglint needs to be improved.")

	case algorithms != "SHA1, RMD160, SHA512, Size":
		line.Errorf("Expected SHA1, RMD160, SHA512, Size checksums for %q, got %s.", filename, algorithms)
	}
}

func (ck *distinfoLinesChecker) checkUnrecordedPatches() {
	if G.Pkg == nil {
		return
	}
	patchFiles, err := ioutil.ReadDir(G.Pkg.File(ck.patchdir))
	if err != nil {
		if trace.Tracing {
			trace.Stepf("Cannot read patchdir %q: %s", ck.patchdir, err)
		}
		return
	}

	for _, file := range patchFiles {
		patchName := file.Name()
		if file.Mode().IsRegular() && !ck.patches[patchName] && hasPrefix(patchName, "patch-") {
			ck.distinfoLines.Errorf("Patch %q is not recorded. Run %q.",
				cleanpath(relpath(path.Dir(ck.distinfoLines.FileName), G.Pkg.File(ck.patchdir+"/"+patchName))),
				bmake("makepatchsum"))
		}
	}
}

// Inter-package check for differing distfile checksums.
func (ck *distinfoLinesChecker) checkGlobalDistfileMismatch(line Line, filename, alg, hash string) {

	// Intentionally checking the filename instead of ck.isPatch.
	// Missing the few distfiles that actually start with patch-*
	// is more convenient than having lots of false positive mismatches.
	if hasPrefix(filename, "patch-") {
		return
	}

	hashes := G.Hashes
	if hashes == nil {
		return
	}

	// The Size hash is not encoded in hex, therefore it would trigger wrong error messages below.
	// Since the Size hash is targeted towards humans and not really useful for detecting duplicates,
	// omitting the check here is ok. Any mismatches will be reliably detected because the other
	// hashes will be different, too.
	if alg == "Size" {
		return
	}

	key := alg + ":" + filename
	otherHash := hashes[key]

	// See https://github.com/golang/go/issues/29802
	hashBytes := make([]byte, hex.DecodedLen(len(hash)))
	_, err := hex.Decode(hashBytes, []byte(hash))
	if err != nil {
		line.Errorf("The %s hash for %s contains a non-hex character.", alg, filename)
	}

	if otherHash != nil {
		if !bytes.Equal(otherHash.hash, hashBytes) {
			line.Errorf("The %s hash for %s is %s, which conflicts with %s in %s.",
				alg, filename, hash, hex.EncodeToString(otherHash.hash), line.RefToLocation(otherHash.location))
		}
	} else {
		hashes[key] = &Hash{hashBytes, line.Location}
	}
}

func (ck *distinfoLinesChecker) checkUncommittedPatch(line Line, patchName, alg, hash string) {
	if ck.isPatch == yes {
		patchFileName := ck.patchdir + "/" + patchName
		resolvedPatchFileName := G.Pkg.File(patchFileName)
		if ck.distinfoIsCommitted && !isCommitted(resolvedPatchFileName) {
			line.Warnf("%s is registered in distinfo but not added to CVS.", line.PathToFile(resolvedPatchFileName))
		}
		if alg == "SHA1" {
			ck.checkPatchSha1(line, patchFileName, hash)
		}
		ck.patches[patchName] = true
	}
}

func (ck *distinfoLinesChecker) checkPatchSha1(line Line, patchFileName, distinfoSha1Hex string) {
	fileSha1Hex, err := computePatchSha1Hex(G.Pkg.File(patchFileName))
	if err != nil {
		line.Errorf("Patch %s does not exist.", patchFileName)
		return
	}
	if distinfoSha1Hex != fileSha1Hex {
		fix := line.Autofix()
		fix.Errorf("SHA1 hash of %s differs (distinfo has %s, patch file has %s).",
			line.PathToFile(G.Pkg.File(patchFileName)), distinfoSha1Hex, fileSha1Hex)
		fix.Explain(
			"To fix the hashes, either let pkglint --autofix do the work",
			sprintf("or run %q.", bmake("makepatchsum")))
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

	hasher := sha1.New()
	skipText := []byte("$" + "NetBSD")
	for _, patchLine := range bytes.SplitAfter(patchBytes, []byte("\n")) {
		if !bytes.Contains(patchLine, skipText) {
			hasher.Write(patchLine)
		}
	}
	return sprintf("%x", hasher.Sum(nil)), nil
}
