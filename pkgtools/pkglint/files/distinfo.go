package pkglint

import (
	"bytes"
	"crypto/sha1"
	"crypto/sha512"
	"encoding/hex"
	"golang.org/x/crypto/ripemd160"
	hashpkg "hash"
	"io"
	"strings"
)

func CheckLinesDistinfo(pkg *Package, lines *Lines) {
	if trace.Tracing {
		defer trace.Call(lines.Filename)()
	}

	filename := lines.Filename
	patchdir := NewPackagePath("patches")
	if pkg != nil && pkg.File(pkg.Patchdir).IsDir() {
		patchdir = pkg.Patchdir
	}
	if trace.Tracing {
		trace.Stepf("patchdir=%q", patchdir)
	}

	distinfoIsCommitted := isCommitted(filename)
	ck := distinfoLinesChecker{
		pkg, lines, patchdir, distinfoIsCommitted,
		nil, make(map[RelPath]distinfoFileInfo)}
	ck.parse()
	ck.check()
	CheckLinesTrailingEmptyLines(lines)
	ck.checkUnrecordedPatches()

	if pkg != nil {
		pkg.distinfoDistfiles = make(map[RelPath]bool)
		for path := range ck.infos {
			pkg.distinfoDistfiles[path.Base()] = true
		}
	}

	SaveAutofixChanges(lines)
}

type distinfoLinesChecker struct {
	pkg                 *Package
	lines               *Lines
	patchdir            PackagePath
	distinfoIsCommitted bool

	filenames []RelPath // For keeping the order from top to bottom
	infos     map[RelPath]distinfoFileInfo
}

func (ck *distinfoLinesChecker) parse() {
	lines := ck.lines

	llex := NewLinesLexer(lines)
	if !llex.EOF() && lines.CheckCvsID(0, ``, "") {
		llex.Skip()
	}
	llex.SkipEmptyOrNote()

	prevFilename := NewRelPath("")
	var hashes []distinfoHash

	isPatch := func() YesNoUnknown {
		switch {
		case !prevFilename.HasPrefixText("patch-"):
			return no
		case ck.pkg == nil:
			return unknown
		case ck.pkg.File(ck.patchdir.JoinNoClean(prevFilename)).IsFile():
			return yes
		default:
			return no
		}
	}

	finishGroup := func() {
		ck.filenames = append(ck.filenames, prevFilename)
		ck.infos[prevFilename] = distinfoFileInfo{isPatch(), hashes}
		hashes = nil
	}

	for !llex.EOF() {
		line := llex.CurrentLine()
		llex.Skip()

		m, alg, file, hash := match3(line.Text, `^(\w+) \((\w[^)]*)\) = (\S+(?: bytes)?)$`)
		filename := NewRelPathString(file)
		if !m {
			line.Errorf("Invalid line: %s", line.Text)
			continue
		}

		if !prevFilename.IsEmpty() && filename != prevFilename {
			finishGroup()
		}
		prevFilename = filename

		hashes = append(hashes, distinfoHash{line, filename, alg, hash})
	}

	if !prevFilename.IsEmpty() {
		finishGroup()
	}
}

func (ck *distinfoLinesChecker) check() {
	for _, filename := range ck.filenames {
		info := ck.infos[filename]

		ck.checkFilename(filename, info)
		ck.checkAlgorithms(info)
		for _, hash := range info.hashes {
			ck.checkGlobalDistfileMismatch(hash)
			if info.isPatch == yes {
				ck.checkUncommittedPatch(hash)
			}
		}
	}
}

func (ck *distinfoLinesChecker) checkFilename(filename RelPath, info distinfoFileInfo) {
	if info.isPatch != no || !info.hasDistfileAlgorithms() || matches(filename.String(), `\d`) {
		return
	}

	line := info.line()
	line.Warnf(
		"Distfiles without version number should be placed in a versioned DIST_SUBDIR.")
	line.Explain(
		seeGuide("How to handle modified distfiles with the 'old' name", "modified-distfiles-same-name"))
}

func (ck *distinfoLinesChecker) checkAlgorithms(info distinfoFileInfo) {
	filename := info.filename()
	algorithms := info.algorithms()
	line := info.line()

	isPatch := info.isPatch

	switch {
	case algorithms == "SHA1" && isPatch != no:
		return

	case algorithms == "SHA1, RMD160, SHA512, Size" && isPatch != yes:
		return
	}

	switch {
	case isPatch == yes:
		line.Errorf("Expected SHA1 hash for %s, got %s.", filename, algorithms)

	case isPatch == unknown:
		line.Errorf("Wrong checksum algorithms %s for %s.", algorithms, filename)
		line.Explain(
			"Distfiles that are downloaded from external sources must have the",
			"checksum algorithms SHA1, RMD160, SHA512, Size.",
			"",
			"Patch files from pkgsrc must have only the SHA1 hash.")

	// At this point, the file is either a missing patch file or a distfile.

	case filename.HasPrefixText("patch-") && algorithms == "SHA1":
		if ck.pkg.IgnoreMissingPatches {
			break
		}

		line.Warnf("Patch file %q does not exist in directory %q.",
			filename, line.Rel(ck.pkg.File(ck.patchdir)))
		line.Explain(
			"If the patches directory looks correct, the patch may have been",
			"removed without updating the distinfo file.",
			"In such a case please update the distinfo file.",
			"",
			"In rare cases, pkglint cannot determine the correct location of the patches directory.",
			"In that case, see the pkglint man page for contact information.")

	default:
		ck.checkAlgorithmsDistfile(info)
	}
}

// checkAlgorithmsDistfile checks whether some of the standard algorithms are
// missing. If so and the downloaded distfile exists, they are calculated and
// added to the distinfo file via an autofix.
func (ck *distinfoLinesChecker) checkAlgorithmsDistfile(info distinfoFileInfo) {
	line := info.line()
	line.Errorf("Expected SHA1, RMD160, SHA512, Size checksums for %q, got %s.", info.filename(), info.algorithms())

	algorithms := [...]string{"SHA1", "RMD160", "SHA512", "Size"}

	missing := map[string]bool{}
	for _, alg := range algorithms {
		missing[alg] = true
	}
	seen := map[string]bool{}

	for _, hash := range info.hashes {
		alg := hash.algorithm
		if missing[alg] {
			seen[alg] = true
			delete(missing, alg)
		}
	}

	if len(missing) == 0 || len(seen) == 0 {
		return
	}

	distdir := G.Pkgsrc.File("distfiles")

	distfile := distdir.JoinNoClean(info.filename()).CleanPath()
	if !distfile.IsFile() {

		// It's a rare situation that the explanation is generated
		// this far from the corresponding diagnostic.
		// This explanation only makes sense when there are some
		// hashes missing that can be automatically added by pkglint.
		line.Explain(
			"To add the missing lines to the distinfo file, run",
			sprintf("\t%s", bmake("distinfo")),
			"for each variant of the package until all distfiles are downloaded to",
			"${PKGSRCDIR}/distfiles.",
			"",
			"The variants are typically selected by setting EMUL_PLATFORM",
			"or similar variables in the command line.",
			"",
			"After that, run",
			sprintf("%q", "cvs update -C distinfo"),
			"to revert the distinfo file to the previous state, since the above",
			"commands have removed some of the entries.",
			"",
			"After downloading all possible distfiles, run",
			sprintf("%q,", "pkglint --autofix"),
			"which will find the downloaded distfiles and add the missing",
			"hashes to the distinfo file.")

		return
	}

	computeHash := func(hasher hashpkg.Hash) string {
		f, err := distfile.Open()
		assertNil(err, "Opening distfile")

		// Don't load the distfile into memory since some of them
		// are hundreds of MB in size.
		_, err = io.Copy(hasher, f)
		assertNil(err, "Computing hash of distfile")

		hexHash := hex.EncodeToString(hasher.Sum(nil))

		err = f.Close()
		assertNil(err, "Closing distfile")

		return hexHash
	}

	compute := func(alg string) string {
		switch alg {
		case "SHA1":
			return computeHash(sha1.New())
		case "RMD160":
			return computeHash(ripemd160.New())
		case "SHA512":
			return computeHash(sha512.New())
		default:
			fileInfo, err := distfile.Lstat()
			assertNil(err, "Inaccessible distfile info")
			return sprintf("%d bytes", fileInfo.Size())
		}
	}

	for _, hash := range info.hashes {
		alg := hash.algorithm
		if !seen[alg] {
			continue
		}
		computed := compute(alg)

		if computed != hash.hash {
			// Do not try to autofix anything in this situation.
			// Wrong hashes are a serious issue.
			line.Errorf("The %s checksum for %q is %s in distinfo, %s in %s.",
				alg, hash.filename, hash.hash, computed, line.Rel(distfile))
			return
		}
	}

	// At this point, all the existing hash algorithms are correct,
	// and there is at least one hash algorithm. This is evidence enough
	// that the distfile is the expected one. Now generate the missing hashes
	// and insert them, in the correct order.

	var insertion *Line
	var remainingHashes = info.hashes
	for _, alg := range algorithms {
		if missing[alg] {
			computed := compute(alg)

			if insertion == nil {
				fix := line.Autofix()
				fix.Errorf("Missing %s hash for %s.", alg, info.filename())
				fix.InsertAbove(sprintf("%s (%s) = %s", alg, info.filename(), computed))
				fix.Apply()
			} else {
				fix := insertion.Autofix()
				fix.Errorf("Missing %s hash for %s.", alg, info.filename())
				fix.InsertBelow(sprintf("%s (%s) = %s", alg, info.filename(), computed))
				fix.Apply()
			}

		} else if remainingHashes[0].algorithm == alg {
			insertion = remainingHashes[0].line
			remainingHashes = remainingHashes[1:]
		}
	}
}

func (ck *distinfoLinesChecker) checkUnrecordedPatches() {
	if ck.pkg == nil {
		return
	}
	patchFiles, err := ck.pkg.File(ck.patchdir).ReadDir()
	if err != nil {
		if trace.Tracing {
			trace.Stepf("Cannot read patchdir %q: %s", ck.patchdir, err)
		}
		return
	}

	for _, file := range patchFiles {
		patchName := NewRelPathString(file.Name())
		if file.Mode().IsRegular() && ck.infos[patchName].isPatch != yes && patchName.HasPrefixText("patch-") {
			line := NewLineWhole(ck.lines.Filename)
			line.Errorf("Patch %q is not recorded. Run %q.",
				line.Rel(ck.pkg.File(ck.patchdir.JoinNoClean(patchName))),
				bmake("makepatchsum"))
		}
	}
}

// Inter-package check for differing distfile checksums.
func (ck *distinfoLinesChecker) checkGlobalDistfileMismatch(info distinfoHash) {

	if !G.InterPackage.Enabled() {
		return
	}

	filename := info.filename
	alg := info.algorithm
	hash := info.hash
	line := info.line

	// Intentionally checking the filename instead of ck.isPatch.
	// Missing the few distfiles that actually start with patch-*
	// is more convenient than having lots of false positive mismatches.
	if filename.HasPrefixText("patch-") {
		return
	}

	// The Size hash is not encoded in hex, therefore it would trigger wrong error messages below.
	// Since the Size hash is targeted towards humans and not really useful for detecting duplicates,
	// omitting the check here is ok. Any mismatches will be reliably detected because the other
	// hashes will be different, too.
	if alg == "Size" {
		return
	}

	// See https://github.com/golang/go/issues/29802
	hashBytes := make([]byte, hex.DecodedLen(len(hash)))
	_, err := hex.Decode(hashBytes, []byte(hash))
	if err != nil {
		line.Errorf("The %s hash for %s contains a non-hex character.", alg, filename)
		return
	}

	otherHash := G.InterPackage.Hash(alg, filename, hashBytes, &line.Location)
	if otherHash != nil {
		if !bytes.Equal(otherHash.hash, hashBytes) {
			line.Errorf("The %s hash for %s is %s, which conflicts with %s in %s.",
				alg, filename, hash, hex.EncodeToString(otherHash.hash), line.RelLocation(otherHash.location))
		}
	}
}

func (ck *distinfoLinesChecker) checkUncommittedPatch(info distinfoHash) {
	patchName := info.filename
	alg := info.algorithm
	hash := info.hash
	line := info.line

	patchFileName := ck.patchdir.JoinNoClean(patchName)
	resolvedPatchFileName := ck.pkg.File(patchFileName)
	if ck.distinfoIsCommitted && !isCommitted(resolvedPatchFileName) {
		line.Warnf("%s is registered in distinfo but not added to CVS.", line.Rel(resolvedPatchFileName))
	}
	if alg == "SHA1" {
		ck.checkPatchSha1(line, patchFileName, hash)
	}
}

func (ck *distinfoLinesChecker) checkPatchSha1(line *Line, patchFileName PackagePath, distinfoSha1Hex string) {
	lines := Load(ck.pkg.File(patchFileName), 0)
	if lines == nil {
		line.Errorf("Patch %s does not exist.", patchFileName.AsRelPath())
		return
	}

	fileSha1Hex := computePatchSha1Hex(lines)
	if distinfoSha1Hex != fileSha1Hex {
		fix := line.Autofix()
		fix.Errorf("SHA1 hash of %s differs (distinfo has %s, patch file has %s).",
			line.Rel(ck.pkg.File(patchFileName)), distinfoSha1Hex, fileSha1Hex)
		fix.Explain(
			"To fix the hashes, either let pkglint --autofix do the work",
			sprintf("or run %q.", bmake("makepatchsum")))
		fix.Replace(distinfoSha1Hex, fileSha1Hex)
		fix.Apply()
	}
}

type distinfoFileInfo struct {
	//  yes     = the patch file exists
	//  unknown = distinfo file is checked without a pkgsrc package
	//  no      = distfile or nonexistent patch file
	isPatch YesNoUnknown
	hashes  []distinfoHash
}

func (info *distinfoFileInfo) filename() RelPath { return info.hashes[0].filename }
func (info *distinfoFileInfo) line() *Line       { return info.hashes[0].line }

func (info *distinfoFileInfo) algorithms() string {
	var algs []string
	for _, hash := range info.hashes {
		algs = append(algs, hash.algorithm)
	}
	return strings.Join(algs, ", ")
}

func (info *distinfoFileInfo) hasDistfileAlgorithms() bool {
	h := info.hashes
	return len(h) == 4 &&
		h[0].algorithm == "SHA1" &&
		h[1].algorithm == "RMD160" &&
		h[2].algorithm == "SHA512" &&
		h[3].algorithm == "Size"
}

type distinfoHash struct {
	line      *Line
	filename  RelPath
	algorithm string
	hash      string
}

// Same as in mk/checksum/distinfo.awk:/function patchsum/
func computePatchSha1Hex(lines *Lines) string {

	hasher := sha1.New()
	skipText := "$" + "NetBSD"
	for _, line := range lines.Lines {
		for _, raw := range line.raw {
			textnl := raw.orignl
			if !contains(textnl, skipText) {
				_, _ = hasher.Write([]byte(textnl))
			}
		}
	}
	return sprintf("%x", hasher.Sum(nil))
}
