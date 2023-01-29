package pkglint

import (
	"netbsd.org/pkglint/pkgver"
	"netbsd.org/pkglint/textproc"
	"sort"
	"strings"
)

// Changes collects the doc/CHANGES-* files, which mainly contain package
// updates, as well as other package modifications and changes to the pkgsrc
// infrastructure.
type Changes struct {
	LastChange      map[PkgsrcPath]*Change
	LastFreezeStart string // e.g. "2018-01-01", or ""
	LastFreezeEnd   string // e.g. "2018-01-01", or ""
}

func (ch *Changes) load(src *Pkgsrc) {
	docDir := src.File("doc")
	files := src.ReadDir("doc")
	if len(files) == 0 {
		G.Logger.TechFatalf(docDir, "Cannot be read for loading the package changes.")
	}

	var filenames []RelPath
	for _, file := range files {
		filename := file.Name()
		// Files before 2011 are too far in the past to be still relevant today.
		if matches(filename, `^CHANGES-20\d\d$`) && filename >= "CHANGES-2011" {
			filenames = append(filenames, NewRelPathString(filename))
		}
	}

	ch.LastChange = make(map[PkgsrcPath]*Change)
	for _, filename := range filenames {
		changes := ch.parseFile(docDir.JoinNoClean(filename), false)
		for _, change := range changes {
			ch.LastChange[change.Pkgpath] = change
			if change.Action == Renamed || change.Action == Moved {
				ch.LastChange[change.Target()] = change
			}
		}
	}

	ch.checkRemovedAfterLastFreeze(src)
}

func (ch *Changes) parseFile(filename CurrPath, direct bool) []*Change {

	warn := direct || G.CheckGlobal && !G.Wip

	// Each date in the file should be from the same year as the filename says.
	// This check has been added in 2018.
	// For years earlier than 2018 pkglint doesn't care because it's not a big issue anyway.
	year := ""
	if _, yyyy := match1(filename.Base().String(), `-(\d\d\d\d)$`); yyyy >= "2018" {
		year = yyyy
	}
	thorough := direct || G.CheckGlobal || year >= "2020" // For performance reasons

	latest := make(map[PkgsrcPath]*Change)

	infra := false
	lines := Load(filename, MustSucceed|NotEmpty)
	var changes []*Change
	for _, line := range lines.Lines {

		if hasPrefix(line.Text, "\tmk/") {
			infra = true
			if hasPrefix(line.Text, "\tmk/bsd.pkg.mk: started freeze for") {
				if m, date := match1(line.Text, `(\d\d\d\d-\d\d-\d\d)\]$`); m {
					ch.LastFreezeStart = date
					ch.LastFreezeEnd = ""
				}
			} else if hasPrefix(line.Text, "\tmk/bsd.pkg.mk: freeze ended for") {
				if m, date := match1(line.Text, `(\d\d\d\d-\d\d-\d\d)\]$`); m {
					ch.LastFreezeEnd = date
				}
			}
		}
		if infra {
			if hasSuffix(line.Text, "]") {
				infra = false
			}
			continue
		}

		change := ch.parseLine(line, warn)
		if change == nil {
			continue
		}

		changes = append(changes, change)

		if !warn {
			continue
		}

		if thorough {
			ch.checkChangeVersion(change, latest, line)
			ch.checkChangeDate(filename, year, change, line, changes)
		}
	}

	return changes
}

func (*Changes) parseLine(line *Line, warn bool) *Change {
	lex := textproc.NewLexer(line.Text)

	space := lex.NextHspace()
	if space == "" {
		return nil
	}

	if space != "\t" {
		if warn {
			line.Warnf("Package changes should be indented using a single tab, not %q.", space)
			line.Explain(
				"To avoid this formatting mistake in the future, just run",
				sprintf("%q", bmake("cce")),
				"after committing the update to the package.")
		}

		return nil
	}

	invalid := func() *Change {
		if warn {
			line.Warnf("Invalid doc/CHANGES line: %s", line.Text)
			line.Explain(
				"See mk/misc/developer.mk for the rules.",
				"",
				"To generate these entries automatically, run",
				sprintf("%q.", bmakeHelp("cce")))
		}
		return nil
	}

	f := strings.Fields(lex.Rest())
	n := len(f)
	if n > 1 && hasSuffix(f[0], ":") {
		return nil
	}
	if n == 0 {
		return invalid()
	}

	action := ParseChangeAction(f[0])
	var pkgpath, author, date string
	if n > 1 {
		pkgpath = f[1]
		date = f[n-1]
	}
	if n > 2 {
		author = f[n-2]
	}

	author, date = (*Changes).parseAuthorAndDate(nil, author, date)
	if author == "" {
		return invalid()
	}

	switch {
	case
		action == Added && f[2] == "version" && n == 6,
		action == Updated && f[2] == "to" && n == 6,
		action == Downgraded && f[2] == "to" && n == 6,
		action == Removed && ((f[2] == "successor" || f[2] == "version") && n == 6 || n == 4),
		(action == Renamed || action == Moved) && f[2] == "to" && n == 6:
		return &Change{
			Location: line.Location,
			Action:   action,
			Pkgpath:  NewPkgsrcPath(NewPath(intern(pkgpath))),
			target:   intern(condStr(n == 6, f[3], "")),
			Author:   intern(author),
			Date:     intern(date),
		}
	}

	return invalid()
}

// parseAuthorAndDate parses the author and date from a line in doc/CHANGES.
func (*Changes) parseAuthorAndDate(author, date string) (string, string) {
	alex := textproc.NewLexer(author)
	if !alex.SkipByte('[') {
		return "", ""
	}
	author = alex.NextBytesSet(textproc.AlnumU)
	if !alex.EOF() {
		return "", ""
	}

	isDigit := func(b byte) bool { return '0' <= b && b <= '9' }

	if len(date) == 11 &&
		isDigit(date[0]) &&
		isDigit(date[1]) &&
		isDigit(date[2]) &&
		isDigit(date[3]) &&
		date[4] == '-' &&
		isDigit(date[5]) &&
		isDigit(date[6]) &&
		10*(date[5]-'0')+(date[6]-'0') >= 1 &&
		10*(date[5]-'0')+(date[6]-'0') <= 12 &&
		date[7] == '-' &&
		isDigit(date[8]) &&
		isDigit(date[9]) &&
		10*(date[8]-'0')+(date[9]-'0') >= 1 &&
		10*(date[8]-'0')+(date[9]-'0') <= 31 &&
		date[10] == ']' {
		date = date[:10]
		return author, date
	}

	return "", ""
}

func (ch *Changes) checkChangeVersion(change *Change, latest map[PkgsrcPath]*Change, line *Line) {
	switch change.Action {

	case Added:
		ch.checkChangeVersionNumber(change, line)
		existing := latest[change.Pkgpath]
		if existing != nil && existing.Version() == change.Version() {
			line.Warnf("Package %q was already added in %s.",
				change.Pkgpath.String(), line.RelLocation(existing.Location))
		}
		latest[change.Pkgpath] = change

	case Updated:
		ch.checkChangeVersionNumber(change, line)
		existing := latest[change.Pkgpath]
		if existing != nil && pkgver.Compare(change.Version(), existing.Version()) <= 0 {
			line.Warnf("Updating %q from %s in %s to %s should increase the version number.",
				change.Pkgpath.String(), existing.Version(), line.RelLocation(existing.Location), change.Version())
		}
		latest[change.Pkgpath] = change

	case Downgraded:
		ch.checkChangeVersionNumber(change, line)
		existing := latest[change.Pkgpath]
		if existing != nil && pkgver.Compare(change.Version(), existing.Version()) >= 0 {
			line.Warnf("Downgrading %q from %s in %s to %s should decrease the version number.",
				change.Pkgpath.String(), existing.Version(), line.RelLocation(existing.Location), change.Version())
		}
		latest[change.Pkgpath] = change

	default:
		latest[change.Pkgpath] = nil
	}
}

func (*Changes) checkChangeVersionNumber(change *Change, line *Line) {
	version := change.Version()

	switch {
	case !textproc.NewLexer(version).TestByteSet(textproc.Digit):
		line.Warnf("Version number %q should start with a digit.", version)

	// See rePkgname for the regular expression.
	case !matches(version, `^([0-9][.\-0-9A-Z_a-z]*)$`):
		line.Warnf("Malformed version number %q.", version)
	}
}

func (*Changes) checkChangeDate(filename CurrPath, year string, change *Change, line *Line, changes []*Change) {
	if year != "" && change.Date[0:4] != year {
		line.Warnf("Year %q for %s does not match the filename %s.",
			change.Date[0:4], change.Pkgpath.String(), line.Rel(filename))
	}

	if len(changes) >= 2 && year != "" {
		if prev := changes[len(changes)-2]; change.Date < prev.Date {
			line.Warnf("Date %q for %s is earlier than %q in %s.",
				change.Date, change.Pkgpath.String(), prev.Date, line.RelLocation(prev.Location))
			line.Explain(
				"The entries in doc/CHANGES should be in chronological order, and",
				"all dates are assumed to be in the UTC timezone, to prevent time",
				"warps.",
				"",
				"To fix this, determine which of the involved dates are correct",
				"and which aren't.",
				"",
				"To prevent this kind of mistakes in the future,",
				"make sure that your system time is correct and run",
				sprintf("%q", bmake("cce")),
				"to commit the changes entry.")
		}
	}
}

func (ch *Changes) checkRemovedAfterLastFreeze(src *Pkgsrc) {
	if ch.LastFreezeStart == "" || G.Wip || !G.CheckGlobal {
		return
	}

	var wrong []*Change
	for pkgsrcPath, change := range ch.LastChange {
		switch change.Action {
		case Added, Updated, Downgraded:
			if !src.File(pkgsrcPath).IsDir() {
				wrong = append(wrong, change)
			}
		}
	}

	sort.Slice(wrong, func(i, j int) bool { return wrong[i].IsAbove(wrong[j]) })

	for _, change := range wrong {
		// The original line of the change is not available anymore.
		// Therefore, it is necessary to load the whole file again.
		lines := Load(change.Location.Filename, MustSucceed)
		line := lines.Lines[change.Location.lineno-1]
		line.Errorf("Package %s must either exist or be marked as removed.", change.Pkgpath.String())
	}
}

// Change describes a modification to a single package, from the doc/CHANGES-* files.
type Change struct {
	Location Location
	Action   ChangeAction // Added, Updated, Downgraded, Renamed, Moved, Removed
	Pkgpath  PkgsrcPath   // For renamed or moved packages, the previous PKGPATH
	target   string       // The path or version number, depending on the action
	Author   string
	Date     string
}

// Version returns the version number for an Added, Updated or Downgraded package.
func (ch *Change) Version() string {
	assert(ch.Action == Added || ch.Action == Updated || ch.Action == Downgraded)
	return ch.target
}

// Target returns the target PKGPATH for a Renamed or Moved package.
func (ch *Change) Target() PkgsrcPath {
	assert(ch.Action == Renamed || ch.Action == Moved)
	return NewPkgsrcPath(NewPath(ch.target))
}

// SuccessorOrVersion returns the successor for a Removed package,
// or the version number of its last appearance.
// As of 2020-10-06, no cross-validation is done on this field though.
func (ch *Change) SuccessorOrVersion() string {
	assert(ch.Action == Removed)
	return ch.target
}

func (ch *Change) IsAbove(other *Change) bool {
	if ch.Date != other.Date {
		return ch.Date < other.Date
	}
	return ch.Location.lineno < other.Location.lineno
}

type ChangeAction uint8

const (
	Added ChangeAction = 1 + iota
	Updated
	Downgraded
	Renamed
	Moved
	Removed
)

func ParseChangeAction(s string) ChangeAction {
	switch s {
	case "Added":
		return Added
	case "Updated":
		return Updated
	case "Downgraded":
		return Downgraded
	case "Renamed":
		return Renamed
	case "Moved":
		return Moved
	case "Removed":
		return Removed
	}
	return 0
}

func (ca ChangeAction) String() string {
	return [...]string{"", "Added", "Updated", "Downgraded", "Renamed", "Moved", "Removed"}[ca]
}

// SuggestedUpdate describes a desired package update, from the doc/TODO file.
type SuggestedUpdate struct {
	Line    Location
	Pkgname string
	Version string
	Comment string
}
