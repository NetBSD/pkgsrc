package pkglint

import (
	"bytes"
	"crypto/sha1"
	"crypto/sha512"
	"encoding/hex"
	"golang.org/x/crypto/ripemd160"
	"hash"
	"io"
	"io/ioutil"
	"os"
	"strings"
)

func CheckLinesDistinfo(pkg *Package, lines *Lines) {
	if trace.Tracing {
		defer trace.Call1(lines.Filename)()
	}

	filename := lines.Filename
	patchdir := "patches"
	if pkg != nil && dirExists(pkg.File(pkg.Patchdir)) {
		patchdir = pkg.Patchdir
	}
	if trace.Tracing {
		trace.Step1("patchdir=%q", patchdir)
	}

	distinfoIsCommitted := isCommitted(filename)
	ck := distinfoLinesChecker{
		pkg, lines, patchdir, distinfoIsCommitted,
		nil, make(map[string]distinfoFileInfo)}
	ck.parse()
	ck.check()
	CheckLinesTrailingEmptyLines(lines)
	ck.checkUnrecordedPatches()

	SaveAutofixChanges(lines)
}

type distinfoLinesChecker struct {
	pkg                 *Package
	lines               *Lines
	patchdir            string // Relative to pkg
	distinfoIsCommitted bool

	filenames []string // For keeping the order from top to bottom
	infos     map[string]distinfoFileInfo
}

func (ck *distinfoLinesChecker) parse() {
	lines := ck.lines

	llex := NewLinesLexer(lines)
	if lines.CheckCvsID(0, ``, "") {
		llex.Skip()
	}
	llex.SkipEmptyOrNote()

	prevFilename := ""
	var hashes []distinfoHash

	isPatch := func() YesNoUnknown {
		switch {
		case !hasPrefix(prevFilename, "patch-"):
			return no
		case ck.pkg == nil:
			return unknown
		case fileExists(ck.pkg.File(ck.patchdir + "/" + prevFilename)):
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

		m, alg, filename, hash := match3(line.Text, `^(\w+) \((\w[^)]*)\) = (\S+(?: bytes)?)$`)
		if !m {
			line.Errorf("Invalid line: %s", line.Text)
			continue
		}

		if prevFilename != "" && filename != prevFilename {
			finishGroup()
		}
		prevFilename = filename

		hashes = append(hashes, distinfoHash{line, filename, alg, hash})
	}

	if prevFilename != "" {
		finishGroup()
	}
}

func (ck *distinfoLinesChecker) check() {
	for _, filename := range ck.filenames {
		info := ck.infos[filename]

		ck.checkAlgorithms(info)
		for _, hash := range info.hashes {
			ck.checkGlobalDistfileMismatch(hash)
			if info.isPatch == yes {
				ck.checkUncommittedPatch(hash)
			}
		}
	}
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

	case hasPrefix(filename, "patch-") && algorithms == "SHA1":
		if ck.pkg.IgnoreMissingPatches {
			break
		}

		line.Warnf("Patch file %q does not exist in directory %q.",
			filename, line.PathToFile(ck.pkg.File(ck.patchdir)))
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
	seen := map[string]distinfoHash{}

	for _, hash := range info.hashes {
		alg := hash.algorithm
		if missing[alg] {
			seen[alg] = hash
			delete(missing, alg)
		}
	}

	if len(missing) == 0 || len(seen) == 0 {
		return
	}

	distdir := G.Pkgsrc.File("distfiles")

	distfile := cleanpath(distdir + "/" + info.filename())
	if !fileExists(distfile) {

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

	computeHash := func(hasher hash.Hash) string {
		f, err := os.Open(distfile)
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
			fileInfo, err := os.Lstat(distfile)
			assertNil(err, "Inaccessible distfile info")
			return sprintf("%d bytes", fileInfo.Size())
		}
	}

	for alg, hash := range seen {
		computed := compute(alg)

		if computed != hash.hash {
			// Do not try to autofix anything in this situation.
			// Wrong hashes are a serious issue.
			line.Errorf("The %s checksum for %q is %s in distinfo, %s in %s.",
				alg, hash.filename, hash.hash, computed, line.PathToFile(distfile))
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
				fix.InsertBefore(sprintf("%s (%s) = %s", alg, info.filename(), computed))
				fix.Apply()
			} else {
				fix := insertion.Autofix()
				fix.Errorf("Missing %s hash for %s.", alg, info.filename())
				fix.InsertAfter(sprintf("%s (%s) = %s", alg, info.filename(), computed))
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
	patchFiles, err := ioutil.ReadDir(ck.pkg.File(ck.patchdir))
	if err != nil {
		if trace.Tracing {
			trace.Stepf("Cannot read patchdir %q: %s", ck.patchdir, err)
		}
		return
	}

	for _, file := range patchFiles {
		patchName := file.Name()
		if file.Mode().IsRegular() && ck.infos[patchName].isPatch != yes && hasPrefix(patchName, "patch-") {
			line := NewLineWhole(ck.lines.Filename)
			line.Errorf("Patch %q is not recorded. Run %q.",
				line.PathToFile(ck.pkg.File(ck.patchdir+"/"+patchName)),
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
	if hasPrefix(filename, "patch-") {
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
				alg, filename, hash, hex.EncodeToString(otherHash.hash), line.RefToLocation(otherHash.location))
		}
	}
}

func (ck *distinfoLinesChecker) checkUncommittedPatch(info distinfoHash) {
	patchName := info.filename
	alg := info.algorithm
	hash := info.hash
	line := info.line

	patchFileName := ck.patchdir + "/" + patchName
	resolvedPatchFileName := ck.pkg.File(patchFileName)
	if ck.distinfoIsCommitted && !isCommitted(resolvedPatchFileName) {
		line.Warnf("%s is registered in distinfo but not added to CVS.", line.PathToFile(resolvedPatchFileName))
	}
	if alg == "SHA1" {
		ck.checkPatchSha1(line, patchFileName, hash)
	}
}

func (ck *distinfoLinesChecker) checkPatchSha1(line *Line, patchFileName, distinfoSha1Hex string) {
	lines := Load(ck.pkg.File(patchFileName), 0)
	if lines == nil {
		line.Errorf("Patch %s does not exist.", patchFileName)
		return
	}

	fileSha1Hex := computePatchSha1Hex(lines)
	if distinfoSha1Hex != fileSha1Hex {
		fix := line.Autofix()
		fix.Errorf("SHA1 hash of %s differs (distinfo has %s, patch file has %s).",
			line.PathToFile(ck.pkg.File(patchFileName)), distinfoSha1Hex, fileSha1Hex)
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

func (info *distinfoFileInfo) filename() string { return info.hashes[0].filename }
func (info *distinfoFileInfo) line() *Line      { return info.hashes[0].line }

func (info *distinfoFileInfo) algorithms() string {
	var algs []string
	for _, hash := range info.hashes {
		algs = append(algs, hash.algorithm)
	}
	return strings.Join(algs, ", ")
}

type distinfoHash struct {
	line      *Line
	filename  string
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
