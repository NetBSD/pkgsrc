package pkglint

import (
	"netbsd.org/pkglint/textproc"
	"sort"
	"strings"
)

func CheckLinesPlist(pkg *Package, lines *Lines) {
	if trace.Tracing {
		defer trace.Call(lines.Filename)()
	}

	idOk := lines.CheckCvsID(0, `@comment `, "@comment ")

	if idOk && lines.Len() == 1 {
		line := lines.Lines[0]
		line.Errorf("PLIST files must not be empty.")
		line.Explain(
			"One reason for empty PLISTs is that this is a newly created package",
			sprintf("and that the author didn't run %q after installing the files.", bmake("print-PLIST")),
			"",
			"For most Perl packages, the final PLIST is generated automatically.",
			"Since the source PLIST is not used at all, it can be removed for these packages.",
			"",
			"Meta packages also don't need a PLIST file",
			"since their only purpose is to declare dependencies.")
		return
	}

	ck := NewPlistChecker(pkg)
	ck.Check(lines)
}

type PlistChecker struct {
	pkg             *Package
	allFiles        map[RelPath]*PlistLine
	allDirs         map[RelPath]*PlistLine
	lastFname       RelPath
	once            Once
	nonAsciiAllowed bool
}

func NewPlistChecker(pkg *Package) *PlistChecker {
	return &PlistChecker{
		pkg,
		make(map[RelPath]*PlistLine),
		make(map[RelPath]*PlistLine),
		"",
		Once{},
		false}
}

func (ck *PlistChecker) Load(lines *Lines) []*PlistLine {
	plines := ck.newLines(lines)
	ck.collectFilesAndDirs(plines)

	if lines.BaseName == "PLIST.common_end" {
		commonLines := Load(lines.Filename.TrimSuffix("_end"), NotEmpty)
		if commonLines != nil {
			ck.collectFilesAndDirs(ck.newLines(commonLines))
		}
	}

	return plines
}

func (ck *PlistChecker) Check(plainLines *Lines) {
	plines := ck.Load(plainLines)

	for _, pline := range plines {
		ck.checkLine(pline)
		pline.CheckTrailingWhitespace()
	}
	ck.checkOmf(plines)
	CheckLinesTrailingEmptyLines(plainLines)

	sorter := NewPlistLineSorter(plines)
	sorter.Sort()
	if !sorter.autofixed {
		SaveAutofixChanges(plainLines)
	}
}

func (*PlistChecker) newLines(lines *Lines) []*PlistLine {
	plines := make([]*PlistLine, lines.Len())
	for i, line := range lines.Lines {
		var conditions []string
		text := line.Text

		for hasPrefix(text, "${PLIST.") /* just for performance */ {
			if m, cond, rest := match2(text, `^(?:\$\{(PLIST\.[\w-.]+)\})(.*)`); m {
				conditions = append(conditions, cond)
				text = rest
			} else {
				break
			}
		}

		plines[i] = &PlistLine{line, conditions, text}
	}
	return plines
}

var plistLineStart = textproc.NewByteSet("$0-9A-Za-z")

func (ck *PlistChecker) collectFilesAndDirs(plines []*PlistLine) {

	for _, pline := range plines {
		text := pline.text
		switch {
		case text == "":
			break
		case plistLineStart.Contains(text[0]):
			ck.collectPath(NewRelPathString(text), pline)
		case text[0] == '@':
			ck.collectDirective(pline)
		}
	}
}

func (ck *PlistChecker) collectPath(rel RelPath, pline *PlistLine) {

	// TODO: What about paths containing variables?
	//  Are they intended to be collected as well?

	if prev := ck.allFiles[rel]; prev == nil || stringSliceLess(pline.conditions, prev.conditions) {
		ck.allFiles[rel] = pline
	}
	for dir := rel.Dir(); dir != "."; dir = dir.Dir() {
		ck.allDirs[dir] = pline
	}
}

func (ck *PlistChecker) collectDirective(pline *PlistLine) {
	m, dirname := match1(pline.text, `^@exec \$\{MKDIR\} %D/(.*)$`)
	if !m || NewPath(dirname).IsAbs() {
		return
	}
	for dir := NewRelPathString(dirname); dir != "."; dir = dir.Dir() {
		ck.allDirs[dir] = pline
	}
}

func (ck *PlistChecker) checkLine(pline *PlistLine) {
	text := pline.text

	if text == "" {
		fix := pline.Autofix()
		fix.Warnf("PLISTs should not contain empty lines.")
		fix.Delete()
		fix.Apply()

	} else if plistLineStart.Contains(text[0]) {
		ck.checkPath(pline, pline.Path())

	} else if m, cmd, arg := match2(text, `^@([a-z-]+)[\t ]*(.*)`); m {
		pline.CheckDirective(cmd, arg)
		if cmd == "comment" && pline.Line.Location.lineno > 1 {
			ck.nonAsciiAllowed = true
		}

	} else {
		pline.Errorf("Invalid line type: %s", pline.Line.Text)
	}
}

func (ck *PlistChecker) checkPath(pline *PlistLine, rel RelPath) {
	ck.checkPathNonAscii(pline)
	ck.checkSorted(pline)
	ck.checkDuplicate(pline)

	if rel.Base().ContainsText("${IMAKE_MANNEWSUFFIX}") {
		pline.warnImakeMannewsuffix()
	}

	if rel.HasPrefixPath("${PKGMANDIR}") {
		fix := pline.Autofix()
		fix.Notef("PLIST files should use \"man/\" instead of \"${PKGMANDIR}\".")
		fix.Explain(
			"The pkgsrc infrastructure takes care of replacing the correct value",
			"when generating the actual PLIST for the package.")
		fix.Replace("${PKGMANDIR}/", "man/")
		fix.Apply()

		// Since the autofix only applies to the Line, the PlistLine needs to be updated manually.
		pline.text = strings.Replace(pline.text, "${PKGMANDIR}/", "man/", 1)
	}

	topdir := rel.Parts()[0]

	switch topdir {
	case "bin":
		ck.checkPathBin(pline, rel)
	case "doc":
		pline.Errorf("Documentation must be installed under share/doc, not doc.")
	case "etc":
		ck.checkPathEtc(pline)
	case "info":
		ck.checkPathInfo(pline)
	case "lib":
		ck.checkPathLib(pline, rel)
	case "man":
		ck.checkPathMan(pline)
	case "share":
		ck.checkPathShare(pline)
	}

	ck.checkPathMisc(rel, pline)
	ck.checkPathCond(pline)
}

func (ck *PlistChecker) checkPathMisc(rel RelPath, pline *PlistLine) {
	if rel.ContainsText("${PKGLOCALEDIR}") && ck.pkg != nil && !ck.pkg.vars.IsDefined("USE_PKGLOCALEDIR") {
		pline.Warnf("PLIST contains ${PKGLOCALEDIR}, but USE_PKGLOCALEDIR is not set in the package Makefile.")
	}

	if rel.ContainsPath("CVS") {
		pline.Warnf("CVS files should not be in the PLIST.")
	}
	if rel.HasSuffixText(".orig") {
		pline.Warnf(".orig files should not be in the PLIST.")
	}
	if rel.HasBase("perllocal.pod") {
		pline.Warnf("The perllocal.pod file should not be in the PLIST.")
		pline.Explain(
			"This file is handled automatically by the INSTALL/DEINSTALL scripts",
			"since its contents depends on more than one package.")
	}
	if rel.ContainsText(".egg-info/") {
		canFix := ck.pkg != nil && ck.pkg.CanFixAddInclude()
		fix := pline.Autofix()
		fix.Warnf("Include \"../../lang/python/egg.mk\" " +
			"instead of listing .egg-info files directly.")
		if canFix {
			fix.Replace(pline.Path().Dir().String(), "${PYSITELIB}/${EGG_INFODIR}")
		}
		fix.Apply()
		if canFix {
			ck.pkg.FixAddInclude("../../lang/python/egg.mk")
		}
	}
	if rel.ContainsPath("..") {
		pline.Errorf("Paths in PLIST files must not contain \"..\".")
	} else if canonical := rel.Clean(); canonical != rel {
		pline.Errorf("Paths in PLIST files must be canonical (%s).", canonical)
	}
}

func (ck *PlistChecker) checkPathNonAscii(pline *PlistLine) {
	text := pline.text

	lex := textproc.NewLexer(text)
	lex.SkipBytesFunc(func(b byte) bool { return b >= ' ' && b <= '~' })
	ascii := lex.EOF()

	switch {
	case !ck.nonAsciiAllowed && !ascii:
		ck.nonAsciiAllowed = true

		pline.Warnf("Non-ASCII filename %q.", escapePrintable(text))
		pline.Explain(
			"The great majority of filenames installed by pkgsrc packages",
			"are ASCII-only. Filenames containing non-ASCII characters",
			"can cause various problems since their name may already be",
			"different when another character encoding is set in the locale.",
			"",
			"To mark a filename as intentionally non-ASCII, insert a PLIST",
			"@comment with a convincing reason directly above this line.",
			"That comment will allow this line and the lines directly",
			"below it to contain non-ASCII filenames.")

	case ck.nonAsciiAllowed && ascii:
		ck.nonAsciiAllowed = false
	}
}

func (ck *PlistChecker) checkSorted(pline *PlistLine) {
	if !pline.HasPlainPath() {
		return
	}

	rel := pline.Path()
	if ck.lastFname != "" && ck.lastFname > rel && !G.Logger.Opts.Autofix {
		pline.Warnf("%q should be sorted before %q.", rel.String(), ck.lastFname.String())
		pline.Explain(
			"The files in the PLIST should be sorted alphabetically.",
			"This allows human readers to quickly see whether a file is included or not.")
	}
	ck.lastFname = rel
}

func (ck *PlistChecker) checkDuplicate(pline *PlistLine) {
	if !pline.HasPlainPath() {
		return
	}

	prev := ck.allFiles[pline.Path()]
	if prev == pline || len(prev.conditions) > 0 {
		return
	}

	fix := pline.Autofix()
	fix.Errorf("Duplicate filename %q, already appeared in %s.", pline.text, pline.RelLine(prev.Line))
	fix.Delete()
	fix.Apply()
}

func (ck *PlistChecker) checkPathBin(pline *PlistLine, rel RelPath) {
	if rel.Count() > 2 {
		pline.Warnf("The bin/ directory should not have subdirectories.")
		pline.Explain(
			"The programs in bin/ are collected there to be executable by the",
			"user without having to type an absolute path.",
			"This advantage does not apply to programs in subdirectories of bin/.",
			"These programs should rather be placed in libexec/PKGBASE.")
		return
	}
}

func (ck *PlistChecker) checkPathEtc(pline *PlistLine) {
	if hasPrefix(pline.text, "etc/rc.d/") {
		pline.Errorf("RCD_SCRIPTS must not be registered in the PLIST.")
		pline.Explain(
			"Please use the RCD_SCRIPTS framework, which is described in mk/pkginstall/bsd.pkginstall.mk.")
		return
	}

	pline.Errorf("Configuration files must not be registered in the PLIST.")
	pline.Explain(
		"Please use the CONF_FILES framework, which is described in mk/pkginstall/bsd.pkginstall.mk.")
}

func (ck *PlistChecker) checkPathInfo(pline *PlistLine) {
	if pline.text == "info/dir" {
		pline.Errorf("\"info/dir\" must not be listed. Use install-info to add/remove an entry.")
		return
	}

	if ck.pkg != nil && !ck.pkg.vars.IsDefined("INFO_FILES") {
		pline.Warnf("Packages that install info files should set INFO_FILES in the Makefile.")
	}
}

func (ck *PlistChecker) checkPathLib(pline *PlistLine, rel RelPath) {

	switch {

	case rel.HasPrefixPath("lib/locale"):
		pline.Errorf("\"lib/locale\" must not be listed. Use ${PKGLOCALEDIR}/locale and set USE_PKGLOCALEDIR instead.")
		return
	}

	basename := rel.Base()
	if basename.ContainsText(".a") || basename.ContainsText(".so") {
		la := replaceAll(pline.text, `(\.a|\.so[0-9.]*)$`, ".la")
		if la != pline.text {
			laLine := ck.allFiles[NewRelPathString(la)]
			if laLine != nil {
				pline.Warnf("Redundant library found. The libtool library is in %s.",
					pline.RelLine(laLine.Line))
			}
		}
	}

	pkg := ck.pkg
	if pkg == nil {
		return
	}

	if pline.text == "lib/charset.alias" && pkg.Pkgpath != "converters/libiconv" {
		pline.Errorf("Only the libiconv package may install lib/charset.alias.")
	}

	if basename.HasSuffixText(".la") && !pkg.vars.IsDefined("USE_LIBTOOL") {
		if ck.once.FirstTime("USE_LIBTOOL") {
			pline.Warnf("Packages that install libtool libraries should define USE_LIBTOOL.")
		}
	}
}

func (ck *PlistChecker) checkPathMan(pline *PlistLine) {
	m, catOrMan, section, base := match3(pline.text, `^man/(cat|man)(\w+)/(.*)$`)
	if !m {
		// maybe: line.Warnf("Invalid filename %q for manual page.", text)
		return
	}
	m, manpage, ext, gz := match3(base, `^(.*?)\.(\w+)(\.gz)?$`)
	if !m {
		// maybe: line.Warnf("Invalid filename %q for manual page.", text)
		return
	}

	if !matches(section, `^[0-9ln]$`) {
		pline.Warnf("Unknown section %q for manual page.", section)
	}

	if catOrMan == "cat" && ck.allFiles[NewRelPathString("man/man"+section+"/"+manpage+"."+section)] == nil {
		pline.Warnf("Preformatted manual page without unformatted one.")
	}

	if catOrMan == "man" && !hasPrefix(ext, section) {
		pline.Warnf("Mismatch between the section (%s) "+
			"and extension (%s) of the manual page.",
			section, ext)
	}

	if gz != "" {
		fix := pline.Autofix()
		fix.Notef("The .gz extension is unnecessary for manual pages.")
		fix.Explain(
			"Whether the manual pages are installed in compressed form or not is",
			"configured by the pkgsrc user.",
			"Compression and decompression takes place automatically,",
			"no matter if the .gz extension is mentioned in the PLIST or not.")
		fix.ReplaceAt(0, len(pline.Line.Text)-len(".gz"), ".gz", "")
		fix.Apply()
	}
}

func (ck *PlistChecker) checkPathShare(pline *PlistLine) {
	text := pline.text

	switch {
	case ck.pkg != nil && hasPrefix(text, "share/icons/"):
		ck.checkPathShareIcons(pline)

	case hasPrefix(text, "share/doc/html/"):
		pline.Warnf("Use of \"share/doc/html\" is deprecated. Use \"share/doc/${PKGBASE}\" instead.")

	case hasPrefix(text, "share/info/"):
		pline.Warnf("Info pages should be installed into info/, not share/info/.")
		pline.Explain(
			"To fix this, add INFO_FILES=yes to the package Makefile.")

	case hasPrefix(text, "share/man/"):
		pline.Warnf("Man pages should be installed into man/, not share/man/.")
	}
}

func (ck *PlistChecker) checkPathShareIcons(pline *PlistLine) {
	pkg := ck.pkg
	text := pline.text

	if hasPrefix(text, "share/icons/hicolor/") && pkg.Pkgpath != "graphics/hicolor-icon-theme" {
		f := "../../graphics/hicolor-icon-theme/buildlink3.mk"
		if !pkg.included.Seen(NewPackagePathString(f)) && ck.once.FirstTime("hicolor-icon-theme") {
			pline.Errorf("Packages that install hicolor icons must include %q in the Makefile.", f)
		}
	}

	if text == "share/icons/hicolor/icon-theme.cache" && pkg.Pkgpath != "graphics/hicolor-icon-theme" {
		pline.Errorf("The file icon-theme.cache must not appear in any PLIST file.")
		pline.Explain(
			"Remove this line and add the following line to the package Makefile.",
			"",
			".include \"../../graphics/hicolor-icon-theme/buildlink3.mk\"")
	}

	if hasPrefix(text, "share/icons/gnome") && pkg.Pkgpath != "graphics/gnome-icon-theme" {
		f := "../../graphics/gnome-icon-theme/buildlink3.mk"
		if !pkg.included.Seen(NewPackagePathString(f)) {
			pline.Errorf("The package Makefile must include %q.", f)
			pline.Explain(
				"Packages that install GNOME icons must maintain the icon theme",
				"cache.")
		}
	}

	if contains(text[12:], "/") && !pkg.vars.IsDefined("ICON_THEMES") && ck.once.FirstTime("ICON_THEMES") {
		pline.Warnf("Packages that install icon theme files should set ICON_THEMES.")
	}
}

func (ck *PlistChecker) checkPathCond(pline *PlistLine) {
	if ck.pkg == nil {
		return
	}

	for _, cond := range pline.conditions {
		ck.checkCond(pline, cond[6:])
	}
}

func (ck *PlistChecker) checkCond(pline *PlistLine, cond string) {
	vars := ck.pkg.vars
	mkline := vars.LastDefinition("PLIST_VARS")
	if mkline == nil || ck.once.SeenSlice("cond", cond) {
		return
	}

	plistVars := vars.LastValue("PLIST_VARS")
	resolvedPlistVars := resolveVariableRefs(plistVars, nil, ck.pkg)
	for _, varparam := range mkline.ValueFields(resolvedPlistVars) {
		if varparam == cond {
			return
		}
		if containsVarUse(varparam) {
			trace.Stepf(
				"Skipping check for condition %q because PLIST_VARS "+
					"contains the unresolved %q as part of %q.",
				cond, varparam, resolvedPlistVars)
			return
		}
	}

	assert(ck.once.FirstTimeSlice("cond", cond))
	pline.Warnf(
		"Condition %q should be added to PLIST_VARS in the package Makefile.",
		cond)
}

func (ck *PlistChecker) checkOmf(plines []*PlistLine) {
	if ck.pkg == nil {
		return
	}
	mkline := ck.pkg.Includes("../../mk/omf-scrollkeeper.mk")
	if mkline == nil {
		return
	}

	for _, pline := range plines {
		if hasSuffix(pline.text, ".omf") {
			return
		}
	}

	fix := mkline.Autofix()
	fix.Errorf("Only packages that have .omf files in their PLIST may include omf-scrollkeeper.mk.")
	if !mkline.HasRationale() {
		fix.Delete()
	}
	fix.Apply()
}

type PlistLine struct {
	Line *Line
	// XXX: Why "PLIST.docs" and not simply "docs"?
	conditions []string // e.g. PLIST.docs
	text       string   // Line.Text without any conditions of the form ${PLIST.cond}
}

// Autofix returns the autofix instance belonging to the line.
//
// See Line.Autofix for usage details.
func (pline *PlistLine) Autofix() *Autofix { return pline.Line.Autofix() }

func (pline *PlistLine) Errorf(format string, args ...interface{}) {
	pline.Line.Errorf(format, args...)
}
func (pline *PlistLine) Warnf(format string, args ...interface{}) {
	pline.Line.Warnf(format, args...)
}
func (pline *PlistLine) Explain(explanation ...string) {
	pline.Line.Explain(explanation...)
}
func (pline *PlistLine) RelLine(other *Line) string {
	return pline.Line.RelLine(other)
}

func (pline *PlistLine) HasPath() bool {
	return pline.text != "" && plistLineStart.Contains(pline.text[0])
}

func (pline *PlistLine) HasPlainPath() bool {
	text := pline.text
	return text != "" &&
		plistLineStart.Contains(text[0]) &&
		!containsVarUse(text)
}

func (pline *PlistLine) Path() RelPath {
	assert(pline.HasPath())
	return NewRelPathString(pline.text)
}

func (pline *PlistLine) CheckTrailingWhitespace() {
	if hasSuffix(pline.text, " ") || hasSuffix(pline.text, "\t") {
		pline.Errorf("Pkgsrc does not support filenames ending in whitespace.")
		pline.Explain(
			"Each character in the PLIST is relevant, even trailing whitespace.")
	}
}

func (pline *PlistLine) CheckDirective(cmd, arg string) {
	if cmd == "unexec" {
		if m, dir := match1(arg, `^(?:rmdir|\$\{RMDIR\} %D/)(.*)`); m {
			if !contains(dir, "true") && !contains(dir, "${TRUE}") {
				fix := pline.Autofix()
				fix.Warnf("Please remove this line. It is no longer necessary.")
				fix.Delete()
				fix.Apply()
			}
		}
	}

	switch cmd {
	case "exec", "unexec":
		switch {
		case contains(arg, "ldconfig") && !contains(arg, "/usr/bin/true"):
			pline.Errorf("The ldconfig command must be used with \"||/usr/bin/true\".")
		}

	case "comment":
		// Nothing to check.

	case "dirrm":
		pline.Warnf("@dirrm is obsolete. Please remove this line.")
		pline.Explain(
			"Directories are removed automatically when they are empty.",
			"When a package needs an empty directory, it can use the @pkgdir",
			"command in the PLIST.")

	case "imake-man":
		args := strings.Fields(arg)
		switch {
		case len(args) != 3:
			pline.Warnf("Invalid number of arguments for imake-man, should be 3.")
		case args[2] == "${IMAKE_MANNEWSUFFIX}":
			pline.warnImakeMannewsuffix()
		}

	case "pkgdir":
		// Nothing to check.

	default:
		pline.Warnf("Unknown PLIST directive \"@%s\".", cmd)
	}
}

func (pline *PlistLine) warnImakeMannewsuffix() {
	pline.Warnf("IMAKE_MANNEWSUFFIX is not meant to appear in PLISTs.")
	pline.Explain(
		"This is the result of a print-PLIST call that has not been edited",
		"manually by the package maintainer.",
		"Please replace the IMAKE_MANNEWSUFFIX with:",
		"",
		"\tIMAKE_MAN_SUFFIX for programs,",
		"\tIMAKE_LIBMAN_SUFFIX for library functions,",
		"\tIMAKE_FILEMAN_SUFFIX for file formats,",
		"\tIMAKE_GAMEMAN_SUFFIX for games,",
		"\tIMAKE_MISCMAN_SUFFIX for other man pages.")
}

type plistLineSorter struct {
	header     []*PlistLine // Does not take part in sorting
	middle     []*PlistLine // Only this part is sorted
	footer     []*PlistLine // Does not take part in sorting, typically contains @exec or @pkgdir
	unsortable *Line        // Some lines are so difficult to sort that only humans can do that
	changed    bool         // Whether the sorting actually changed something
	autofixed  bool         // Whether the newly sorted file has been written to disk
}

func NewPlistLineSorter(plines []*PlistLine) *plistLineSorter {
	headerEnd := 0
	for headerEnd < len(plines) && hasPrefix(plines[headerEnd].text, "@comment") {
		headerEnd++
	}

	footerStart := len(plines)
	for footerStart > headerEnd && hasPrefix(plines[footerStart-1].text, "@") {
		footerStart--
	}

	header := plines[0:headerEnd]
	middle := plines[headerEnd:footerStart]
	footer := plines[footerStart:]
	var unsortable *Line

	for _, pline := range middle {
		if unsortable == nil && (hasPrefix(pline.text, "@") || contains(pline.text, "$")) {
			unsortable = pline.Line
		}
	}
	return &plistLineSorter{header, middle, footer, unsortable, false, false}
}

func (s *plistLineSorter) Sort() {
	if line := s.unsortable; line != nil {
		if trace.Tracing {
			trace.Stepf("%s: This line prevents pkglint from sorting the PLIST automatically.", line)
		}
		return
	}

	if !G.Logger.shallBeLogged("%q should be sorted before %q.") {
		return
	}
	if len(s.middle) == 0 {
		return
	}
	firstLine := s.middle[0].Line

	sort.SliceStable(s.middle, func(i, j int) bool {
		mi := s.middle[i]
		mj := s.middle[j]
		less := mi.text < mj.text ||
			mi.text == mj.text && stringSliceLess(mi.conditions, mj.conditions)
		if i < j != less {
			s.changed = true
		}
		return less
	})

	if !s.changed {
		return
	}

	fix := firstLine.Autofix()
	fix.Notef(SilentAutofixFormat)
	fix.Describef(0, "Sorting the whole file.")
	fix.Apply()

	var lines []*Line
	for _, pline := range s.header {
		lines = append(lines, pline.Line)
	}
	for _, pline := range s.middle {
		lines = append(lines, pline.Line)
	}
	for _, pline := range s.footer {
		lines = append(lines, pline.Line)
	}

	s.autofixed = SaveAutofixChanges(NewLines(lines[0].Filename(), lines))
}

type PlistRank struct {
	Rank  int
	Opsys string
	Arch  string
	Rest  string
}

var defaultPlistRank = &PlistRank{0, "", "", ""}

func NewPlistRank(basename RelPath) *PlistRank {
	isOpsys := func(s string) bool {
		return G.Pkgsrc.VariableType(nil, "OPSYS").basicType.HasEnum(s)
	}
	isArch := func(s string) bool {
		return G.Pkgsrc.VariableType(nil, "MACHINE_ARCH").basicType.HasEnum(s)
	}
	isEmulOpsys := func(s string) bool {
		return G.Pkgsrc.VariableType(nil, "EMUL_OPSYS").basicType.HasEnum(s)
	}
	isEmulArch := func(s string) bool {
		return G.Pkgsrc.VariableType(nil, "EMUL_ARCH").basicType.HasEnum(s)
	}

	switch basename {
	case "PLIST":
		return defaultPlistRank
	case "PLIST.common":
		return &PlistRank{1, "", "", ""}
	case "PLIST.common_end":
		return &PlistRank{2, "", "", ""}
	}

	parts := strings.Split(basename.String()[6:], "-")
	rank := PlistRank{3, "", "", ""}
	if isOpsys(parts[0]) {
		rank.Opsys = parts[0]
		parts = parts[1:]
	}
	if len(parts) > 0 && isArch(parts[0]) {
		rank.Arch = parts[0]
		parts = parts[1:]
	}
	if len(parts) >= 2 && isEmulOpsys(parts[0]) && isEmulArch(parts[1]) {
		rank.Opsys = parts[0]
		rank.Arch = parts[1]
		parts = parts[2:]
	}
	rank.Rest = strings.Join(parts, "-")
	return &rank
}

// The ranks among the files are:
//  PLIST
//  -> PLIST.common
//  -> PLIST.common_end
//  -> { PLIST.OPSYS, PLIST.ARCH }
//  -> { PLIST.OPSYS.ARCH, PLIST.EMUL_PLATFORM }
// Files are a later level must not mention files that are already
// mentioned at an earlier level.
func (r *PlistRank) MoreGeneric(other *PlistRank) bool {
	if r.Rank != 3 && other.Rank != 3 {
		return r.Rank < other.Rank
	}
	if r.Opsys != "" && r.Opsys != other.Opsys {
		return false
	}
	if r.Arch != "" && r.Arch != other.Arch {
		return false
	}
	if r.Rest != "" && r.Rest != other.Rest {
		return false
	}
	return *r != *other
}

type PlistLines struct {
	all map[RelPath][]*plistLineData
}

func NewPlistLines() *PlistLines {
	return &PlistLines{make(map[RelPath][]*plistLineData)}
}

type plistLineData struct {
	line *PlistLine
	rank *PlistRank
}

func (pl *PlistLines) Add(line *PlistLine, rank *PlistRank) {
	path := line.Path()
	for _, existing := range pl.all[path] {
		switch {
		case existing.rank == rank:
			break
		case existing.rank.MoreGeneric(rank):
			line.Errorf("Path %s is already listed in %s.",
				path, line.RelLine(existing.line.Line))
		case rank.MoreGeneric(existing.rank):
			existing.line.Errorf("Path %s is already listed in %s.",
				path, existing.line.RelLine(line.Line))
		}
	}
	pl.all[path] = append(pl.all[path], &plistLineData{line, rank})
}
