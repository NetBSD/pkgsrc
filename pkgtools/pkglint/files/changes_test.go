package pkglint

import (
	"gopkg.in/check.v1"
	"strings"
)

func (s *Suite) Test_Changes_load(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("doc/CHANGES-2018",
		CvsID,
		"",
		"\tUpdated pkgpath to 1.0 [author 2018-01-01]",
		"\tRenamed pkgpath to new-pkg [author 2018-02-01]",
		"\tMoved pkgpath to category/new-pkg [author 2018-03-01]")
	t.FinishSetUp()

	t.CheckEquals(G.Pkgsrc.changes.LastChange["pkgpath"].Action, Moved)
}

func (s *Suite) Test_Changes_load__not_found(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.Remove("doc/CHANGES-2018")
	t.Remove("doc/TODO")
	t.Remove("doc")

	t.ExpectFatal(
		t.FinishSetUp,
		"FATAL: ~/doc: Cannot be read for loading the package changes.")
}

func (s *Suite) Test_Changes_parseFile(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("doc/CHANGES-2018",
		"\tAdded category/package version 1.0 [author1 2015-01-01]", // Wrong year
		"\tUpdated category/package to 1.5 [author2 2018-01-02]",
		"\tRenamed category/package to category/pkg [author3 2018-01-03]",
		"\tMoved category/package to other/package [author4 2018-01-04]",
		"\tRemoved category/package [author5 2018-01-09]", // Too far in the future
		"\tRemoved category/package successor category/package2 [author6 2018-01-06]",
		"\tDowngraded category/package to 1.2 [author7 2018-01-07]",
		"\tReworked category/package to 1.2 [author8 2018-01-08]",
		"",
		"\ttoo few fields",
		"\ttoo many many many many many fields",
		"\tmissing brackets around author",
		"\tAdded another [new package]",
		"",
		"\tmk/bsd.pkg.mk: freeze ended for branch pkgsrc-2019Q2", // missing date
		"\tmk/bsd.pkg.mk: freeze ended for branch pkgsrc-2019Q2 [thawer 2019-07-01]",
		"",
		"Normal paragraph.")

	changes := G.Pkgsrc.changes.parseFile(t.File("doc/CHANGES-2018"), true)

	t.CheckDeepEquals(
		changes, []*Change{
			{changes[0].Location,
				Added, "category/package", "1.0",
				"author1", "2015-01-01"},
			{changes[1].Location,
				Updated, "category/package", "1.5",
				"author2", "2018-01-02"},
			{changes[2].Location,
				Renamed, "category/package", "category/pkg",
				"author3", "2018-01-03"},
			{changes[3].Location,
				Moved, "category/package", "other/package",
				"author4", "2018-01-04"},
			{changes[4].Location,
				Removed, "category/package", "",
				"author5", "2018-01-09"},
			{changes[5].Location,
				Removed, "category/package", "category/package2",
				"author6", "2018-01-06"},
			{changes[6].Location,
				Downgraded, "category/package", "1.2",
				"author7", "2018-01-07"}})

	t.CheckOutputLines(
		"WARN: ~/doc/CHANGES-2018:1: Year \"2015\" for category/package does not match the filename CHANGES-2018.",
		"WARN: ~/doc/CHANGES-2018:6: Date \"2018-01-06\" for category/package is earlier than \"2018-01-09\" in line 5.",
		"WARN: ~/doc/CHANGES-2018:8: Invalid doc/CHANGES line: \tReworked category/package to 1.2 [author8 2018-01-08]",
		"WARN: ~/doc/CHANGES-2018:10: Invalid doc/CHANGES line: \ttoo few fields",
		"WARN: ~/doc/CHANGES-2018:11: Invalid doc/CHANGES line: \ttoo many many many many many fields",
		"WARN: ~/doc/CHANGES-2018:12: Invalid doc/CHANGES line: \tmissing brackets around author",
		"WARN: ~/doc/CHANGES-2018:13: Invalid doc/CHANGES line: \tAdded another [new package]")
}

func (s *Suite) Test_Changes_parseFile__not_found(c *check.C) {
	t := s.Init(c)

	t.ExpectFatal(
		func() { G.Pkgsrc.changes.parseFile(t.File("doc/CHANGES-2018"), false) },
		"FATAL: ~/doc/CHANGES-2018: Cannot be read.")
}

// Since package authors for pkgsrc-wip cannot necessarily commit to
// main pkgsrc, don't warn about unsorted doc/CHANGES lines.
// Only pkgsrc main committers can fix these.
func (s *Suite) Test_Changes_parseFile__wip_suppresses_warnings(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("wip/package")
	t.CreateFileLines("doc/CHANGES-2018",
		CvsID,
		"",
		"Changes to the packages collection and infrastructure in 2018:",
		"",
		"\tUpdated sysutils/checkperms to 1.10 [rillig 2018-01-05]",
		"\tUpdated sysutils/checkperms to 1.11 [rillig 2018-01-01]",
		"\t\tWrong indentation",
		"\tInvalid pkgpath to 1.16 [rillig 2019-06-16]")

	t.Main("-Cglobal", "-Wall", "wip/package")

	t.CheckOutputLines(
		"Looks fine.")
}

// When a single package is checked, only the lines from doc/CHANGES
// that are related to that package are shown. The others are too
// unrelated.
func (s *Suite) Test_Changes_parseFile__default(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("doc/CHANGES-2018",
		CvsID,
		"",
		"Changes to the packages collection and infrastructure in 2018:",
		"",
		"\tUpdated sysutils/checkperms to 1.10 [rillig 2018-01-05]",
		"\tUpdated sysutils/checkperms to 1.11 [rillig 2018-01-01]",
		"\t\tWrong indentation",
		"\tInvalid pkgpath to 1.16 [rillig 2019-06-16]",
		"\tUpdated category/package to 2.0 [rillig 2019-07-24]")
	t.CreateFileLines("Makefile",
		MkCvsID)

	t.Main("category/package")

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:3: The package is being downgraded from 2.0 (see ../../doc/CHANGES-2018:9) to 1.0.",
		"1 warning found.",
		t.Shquote("(Run \"pkglint -e %s\" to show explanations.)", "category/package"))

	// Only when the global checks are enabled, the errors from doc/CHANGES are shown.
	t.Main("-Cglobal", "-Wall", ".")

	t.CheckOutputLines(
		"WARN: ~/doc/CHANGES-2018:6: Date \"2018-01-01\" for sysutils/checkperms is earlier than \"2018-01-05\" in line 5.",
		"WARN: ~/doc/CHANGES-2018:7: Package changes should be indented using a single tab, not \"\\t\\t\".",
		"WARN: ~/doc/CHANGES-2018:8: Invalid doc/CHANGES line: \tInvalid pkgpath to 1.16 [rillig 2019-06-16]",
		"WARN: ~/doc/CHANGES-2018:9: Year \"2019\" for category/package does not match the filename CHANGES-2018.",
		"4 warnings found.",
		t.Shquote("(Run \"pkglint -e -Cglobal -Wall %s\" to show explanations.)", "."))
}

func (s *Suite) Test_Changes_parseFile__wrong_indentation(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("doc/CHANGES-2018",
		CvsID,
		"",
		"Changes to the packages collection and infrastructure in 2018:",
		"",
		"        Updated sysutils/checkperms to 1.10 [rillig 2018-01-05]",
		"    \tUpdated sysutils/checkperms to 1.11 [rillig 2018-01-01]")

	t.Main("-Cglobal", "-Wall", "category/package")

	t.CheckOutputLines(
		"WARN: ~/doc/CHANGES-2018:5: Package changes should be indented using a single tab, not \"        \".",
		"WARN: ~/doc/CHANGES-2018:6: Package changes should be indented using a single tab, not \"    \\t\".",
		"2 warnings found.",
		t.Shquote("(Run \"pkglint -e -Cglobal -Wall %s\" to show explanations.)", "category/package"))
}

// Once or twice in a decade, changes to the pkgsrc infrastructure are also
// documented in doc/CHANGES. These entries typically span multiple lines.
func (s *Suite) Test_Changes_parseFile__infrastructure(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("doc/CHANGES-2018",
		CvsID,
		"",
		"Changes to the packages collection and infrastructure in 2018:",
		"",
		"\tmk/bsd.pkg.mk: Added new framework for handling packages",
		"\t\twith multiple MASTER_SITES while fetching the main",
		"\t\tdistfile directly from GitHub [rillig 2018-01-01]",
		"\tmk/bsd.pkg.mk: Another infrastructure change [rillig 2018-01-02]")

	t.Main("category/package")

	// For pkglint's purpose, the infrastructure entries are simply ignored
	// since they do not belong to a single package.
	t.CheckOutputLines(
		"Looks fine.")
}

func (s *Suite) Test_Changes_parseFile__old(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Cglobal", "-Wall")
	t.SetUpPkgsrc()
	t.CreateFileLines("doc/CHANGES-2010",
		CvsID,
		"",
		"Changes to the packages collection and infrastructure in 2015:",
		"",
		"\tInvalid line [3 4]")
	t.CreateFileLines("doc/CHANGES-2015",
		CvsID,
		"",
		"Changes to the packages collection and infrastructure in 2015:",
		"",
		"\tUpdated pkgpath to 1.0 [author 2015-07-01]",
		"\tInvalid line [3 4]",
		// The date of the below entry is earlier than that of the above entry;
		// this error is ignored because the 2015 file is too old.
		"\tUpdated pkgpath to 1.2 [author 2015-02-01]")
	t.CreateFileLines("doc/CHANGES-2018",
		CvsID,
		"",
		"Changes to the packages collection and infrastructure in 2018:",
		"",
		"\tUpdated pkgpath to 1.0 [author date]",
		"\tUpdated pkgpath to 1.0 [author d]")
	t.FinishSetUp()

	// The 2010 file is so old that it is skipped completely.
	// The 2015 file is so old that the date is not checked.
	// Since 2018, each date in the file must match the filename.
	t.CheckOutputLines(
		"WARN: ~/doc/CHANGES-2015:6: Invalid doc/CHANGES line: \tInvalid line [3 4]",
		"WARN: ~/doc/CHANGES-2018:5: Invalid doc/CHANGES line: \tUpdated pkgpath to 1.0 [author date]",
		"WARN: ~/doc/CHANGES-2018:6: Invalid doc/CHANGES line: \tUpdated pkgpath to 1.0 [author d]")
}

func (s *Suite) Test_Changes_parseLine(c *check.C) {
	t := s.Init(c)

	test := func(text string, diagnostics ...string) {
		line := t.NewLine("doc/CHANGES-2019", 123, text)
		_ = (*Changes)(nil).parseLine(line, true)
		t.CheckOutput(diagnostics)
	}

	test(CvsID,
		nil...)
	test("",
		nil...)
	test("Changes to the packages collection and infrastructure in 2019:",
		nil...)

	test("\tAdded something [author date]",
		"WARN: doc/CHANGES-2019:123: Invalid doc/CHANGES line: "+
			"\tAdded something [author date]")

	test("\tAdded category/package 1.0 [author 2019-11-17]",
		"WARN: doc/CHANGES-2019:123: Invalid doc/CHANGES line: "+
			"\tAdded category/package 1.0 [author 2019-11-17]")

	test("\t\tToo large indentation",
		"WARN: doc/CHANGES-2019:123: Package changes should be indented using a single tab, not \"\\t\\t\".")
	test("\t Too large indentation",
		"WARN: doc/CHANGES-2019:123: Package changes should be indented using a single tab, not \"\\t \".")

	test("\t",
		"WARN: doc/CHANGES-2019:123: Invalid doc/CHANGES line: \t")
	test("\t1",
		"WARN: doc/CHANGES-2019:123: Invalid doc/CHANGES line: \t1")
	test("\t1 2 3 4",
		"WARN: doc/CHANGES-2019:123: Invalid doc/CHANGES line: \t1 2 3 4")
	test("\t1 2 3 4 5",
		"WARN: doc/CHANGES-2019:123: Invalid doc/CHANGES line: \t1 2 3 4 5")
	test("\t1 2 3 4 5 6",
		"WARN: doc/CHANGES-2019:123: Invalid doc/CHANGES line: \t1 2 3 4 5 6")
	test("\t1 2 3 4 5 6 7",
		"WARN: doc/CHANGES-2019:123: Invalid doc/CHANGES line: \t1 2 3 4 5 6 7")
	test("\t1 2 [3 4",
		"WARN: doc/CHANGES-2019:123: Invalid doc/CHANGES line: \t1 2 [3 4")
	test("\t1 2 [3 4]",
		"WARN: doc/CHANGES-2019:123: Invalid doc/CHANGES line: \t1 2 [3 4]")
	test("\tAdded 2 [3 4]",
		"WARN: doc/CHANGES-2019:123: Invalid doc/CHANGES line: \tAdded 2 [3 4]")

	test("\tAdded pkgpath version 1.0 [author 2019-01-01]",
		nil...)

	// "to" is wrong
	test("\tAdded pkgpath to 1.0 [author 2019-01-01]",
		"WARN: doc/CHANGES-2019:123: Invalid doc/CHANGES line: "+
			"\tAdded pkgpath to 1.0 [author 2019-01-01]")

	test("\tUpdated pkgpath to 1.0 [author 2019-01-01]",
		nil...)

	// "from" is wrong
	test("\tUpdated pkgpath from 1.0 [author 2019-01-01]",
		"WARN: doc/CHANGES-2019:123: Invalid doc/CHANGES line: "+
			"\tUpdated pkgpath from 1.0 [author 2019-01-01]")

	test("\tDowngraded pkgpath to 1.0 [author 2019-01-01]",
		nil...)

	// "from" is wrong
	test("\tDowngraded pkgpath from 1.0 [author 2019-01-01]",
		"WARN: doc/CHANGES-2019:123: Invalid doc/CHANGES line: "+
			"\tDowngraded pkgpath from 1.0 [author 2019-01-01]")

	test("\tRemoved pkgpath [author 2019-01-01]",
		nil...)

	test("\tRemoved pkgpath successor pkgpath [author 2019-01-01]",
		nil...)

	// Since 2020-10-06
	test("\tRemoved pkgpath version 1.3.4 [author 2019-01-01]",
		nil...)

	// "and" is wrong
	test("\tRemoved pkgpath and pkgpath [author 2019-01-01]",
		"WARN: doc/CHANGES-2019:123: Invalid doc/CHANGES line: "+
			"\tRemoved pkgpath and pkgpath [author 2019-01-01]")

	test("\tRenamed pkgpath to other [author 2019-01-01]",
		nil...)

	// "from" is wrong
	test("\tRenamed pkgpath from previous [author 2019-01-01]",
		"WARN: doc/CHANGES-2019:123: Invalid doc/CHANGES line: "+
			"\tRenamed pkgpath from previous [author 2019-01-01]")

	test("\tMoved pkgpath to other [author 2019-01-01]",
		nil...)

	// "from" is wrong
	test("\tMoved pkgpath from previous [author 2019-01-01]",
		"WARN: doc/CHANGES-2019:123: Invalid doc/CHANGES line: "+
			"\tMoved pkgpath from previous [author 2019-01-01]")

	// "Split" is wrong
	test("\tSplit pkgpath into a and b [author 2019-01-01]",
		"WARN: doc/CHANGES-2019:123: Invalid doc/CHANGES line: "+
			"\tSplit pkgpath into a and b [author 2019-01-01]")

	// Entries ending in a colon are used for infrastructure changes.
	test("\tmk: remove support for USE_CROSSBASE [author 2016-06-19]",
		nil...)

	test("\tAdded category/pkgpath version 1.0 [author-dash 2019-01-01]",
		"WARN: doc/CHANGES-2019:123: Invalid doc/CHANGES line: "+
			"\tAdded category/pkgpath version 1.0 [author-dash 2019-01-01]")

	// The word 'version' must only appear with 'Added', not with 'Updated'.
	test("\tUpdated category/pkgpath to version 1.0 [author 2019-01-01]",
		"WARN: doc/CHANGES-2019:123: Invalid doc/CHANGES line: "+
			"\tUpdated category/pkgpath to version 1.0 [author 2019-01-01]")
}

func (s *Suite) Test_Changes_parseAuthorAndDate(c *check.C) {
	t := s.Init(c)

	test := func(dateAndAuthor string, expectedAuthor, expectedDate string) {
		fields := strings.Split(dateAndAuthor, " ")
		authorIn, dateIn := fields[0], fields[1]
		author, date := (*Changes).parseAuthorAndDate(nil, authorIn, dateIn)
		t.CheckEquals(author, expectedAuthor)
		t.CheckEquals(date, expectedDate)
	}

	test("[author 20!9-01-01]", "", "") // bad digit '!' in year
	test("[author x019-01-01]", "", "") // bad digit 'x' in year
	test("[author 2x19-01-01]", "", "") // bad digit 'x' in year
	test("[author 20x9-01-01]", "", "") // bad digit 'x' in year
	test("[author 201x-01-01]", "", "") // bad digit 'x' in year

	test("[author 2019/01-01]", "", "") // bad separator '/'

	test("[author 2019-x0-01]", "", "") // bad digit 'x' in month
	test("[author 2019-0x-01]", "", "") // bad digit 'x' in month
	test("[author 2019-00-01]", "", "") // bad month '00'
	test("[author 2019-13-01]", "", "") // bad month '13'

	test("[author 2019-01/01]", "", "") // bad separator '/'

	test("[author 2019-01-x0]", "", "") // bad digit 'x' in day
	test("[author 2019-01-0x]", "", "") // bad digit 'x' in day
	test("[author 2019-01-00]", "", "") // bad day '00'
	test("[author 2019-01-32]", "", "") // bad day '32'
	// No leap year detection, to keep the code fast.
	test("[author 2019-02-29]", "author", "2019-02-29") // 2019 is not a leap year.

	test("[author 2019-01-01", "", "")  // missing trailing ']'
	test("[author 2019-01-01+", "", "") // trailing '+' instead of ']'

	test("[author 2019-01-01]", "author", "2019-01-01")
}

func (s *Suite) Test_Changes_checkChangeVersion(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("doc/CHANGES-2020",
		"\tAdded category/package version 1.0 [author1 2020-01-01]",
		"\tAdded category/package version 1.0 [author1 2020-01-01]",
		"\tAdded category/package version 2.3 [author1 2020-01-01]",
		"\tUpdated category/package to 0.9 [author1 2020-01-01]",
		"\tDowngraded category/package to 1.0 [author1 2020-01-01]",
		"\tDowngraded category/package to 0.8 [author 2020-01-01]",
		"\tRenamed category/package to category/renamed [author1 2020-01-01]",
		"\tMoved category/package to other/renamed [author1 2020-01-01]")
	t.Chdir("doc")

	G.Pkgsrc.changes.parseFile("CHANGES-2020", true)

	// In line 3 there is no warning about the repeated addition since
	// the multi-packages (Lua, PHP, Python) may add a package in
	// several versions to the same PKGPATH.
	t.CheckOutputLines(
		"WARN: CHANGES-2020:2: Package \"category/package\" was already added in line 1.",
		"WARN: CHANGES-2020:4: Updating \"category/package\" from 2.3 in line 3 to 0.9 should increase the version number.",
		"WARN: CHANGES-2020:5: Downgrading \"category/package\" from 0.9 in line 4 to 1.0 should decrease the version number.")
}

func (s *Suite) Test_Changes_checkChangeVersionNumber(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("doc/CHANGES-2020",
		"\tAdded category/package version v1 [author1 2020-01-01]",
		"\tUpdated category/package to v2 [author1 2020-01-01]",
		"\tDowngraded category/package to v2 [author1 2020-01-01]",
		"\tUpdated category/package to 2020/03 [author1 2020-01-01]")
	t.Chdir("doc")

	G.Pkgsrc.changes.parseFile("CHANGES-2020", true)

	t.CheckOutputLines(
		"WARN: CHANGES-2020:1: Version number \"v1\" should start with a digit.",
		"WARN: CHANGES-2020:2: Version number \"v2\" should start with a digit.",
		"WARN: CHANGES-2020:3: Version number \"v2\" should start with a digit.",
		"WARN: CHANGES-2020:3: Downgrading \"category/package\" from v2 in line 2 "+
			"to v2 should decrease the version number.",
		"WARN: CHANGES-2020:4: Malformed version number \"2020/03\".")
}

func (s *Suite) Test_Changes_checkChangeDate(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("doc/CHANGES-2020",
		"\tAdded category/package version 1 [author 2018-01-01]")
	t.Chdir("doc")

	G.Pkgsrc.changes.parseFile("CHANGES-2020", true)

	t.CheckOutputLines(
		"WARN: CHANGES-2020:1: " +
			"Year \"2018\" for category/package " +
			"does not match the filename CHANGES-2020.")
}

func (s *Suite) Test_Changes_checkRemovedAfterLastFreeze(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--source")
	t.CreateFileLines("doc/CHANGES-2019",
		CvsID,
		"",
		"\tUpdated category/updated-before to 1.0 [updater 2019-04-01]",
		"\tmk/bsd.pkg.mk: started freeze for pkgsrc-2019Q1 branch [freezer 2019-06-21]",
		"\tmk/bsd.pkg.mk: freeze ended for pkgsrc-2019Q1 branch [freezer 2019-06-25]",
		"\tUpdated category/updated-after to 1.0 [updater 2019-07-01]",
		"\tAdded category/added-after version 1.0 [updater 2019-07-01]",
		"\tMoved category/moved-from to category/moved-to [author 2019-07-02]",
		"\tDowngraded category/downgraded to 1.0 [author 2019-07-03]",
		"\tUpdated category/still-there to 1.0 [updater 2019-07-04]")
	t.SetUpPackage("category/still-there")
	t.FinishSetUp()

	// No error message since -Cglobal is not given.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Changes_checkRemovedAfterLastFreeze__check_global(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "-Cglobal", "--source")
	t.CreateFileLines("doc/CHANGES-2019",
		CvsID,
		"",
		"\tUpdated category/updated-before to 1.0 [updater 2019-04-01]",
		"\tmk/bsd.pkg.mk: started freeze for pkgsrc-2019Q1 branch [freezer 2019-06-21]",
		"\tmk/bsd.pkg.mk: freeze ended for pkgsrc-2019Q1 branch [freezer 2019-06-25]",
		"\tUpdated category/updated-after to 1.0 [updater 2019-07-01]",
		"\tAdded category/added-after version 1.0 [updater 2019-07-01]",
		"\tMoved category/moved-from to category/moved-to [author 2019-07-02]",
		"\tDowngraded category/downgraded to 1.0 [author 2019-07-03]",
		"\tUpdated category/still-there to 1.0 [updater 2019-07-04]")
	t.SetUpPackage("category/still-there")
	t.FinishSetUp()

	// It doesn't matter whether the last visible package change was before
	// or after the latest freeze. The crucial point is that the most
	// interesting change is the invisible one, which is the removal.
	// And for finding the removal reliably, it doesn't matter how long ago
	// the last package change was.

	t.CheckOutputLines(
		">\t\tUpdated category/updated-before to 1.0 [updater 2019-04-01]",
		"ERROR: ~/doc/CHANGES-2019:3: Package category/updated-before "+
			"must either exist or be marked as removed.",
		"",
		">\t\tUpdated category/updated-after to 1.0 [updater 2019-07-01]",
		"ERROR: ~/doc/CHANGES-2019:6: Package category/updated-after "+
			"must either exist or be marked as removed.",
		"",
		">\t\tAdded category/added-after version 1.0 [updater 2019-07-01]",
		"ERROR: ~/doc/CHANGES-2019:7: Package category/added-after "+
			"must either exist or be marked as removed.",
		"",
		">\t\tDowngraded category/downgraded to 1.0 [author 2019-07-03]",
		"ERROR: ~/doc/CHANGES-2019:9: Package category/downgraded "+
			"must either exist or be marked as removed.")
}

func (s *Suite) Test_Changes_checkRemovedAfterLastFreeze__wip(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("wip/package")
	t.CreateFileLines("doc/CHANGES-2019",
		CvsID,
		"",
		"\tUpdated category/updated-before to 1.0 [updater 2019-04-01]",
		"\tmk/bsd.pkg.mk: started freeze for pkgsrc-2019Q1 branch [freezer 2019-06-21]",
		"\tmk/bsd.pkg.mk: freeze ended for pkgsrc-2019Q1 branch [freezer 2019-06-25]",
		"\tUpdated category/updated-after to 1.0 [updater 2019-07-01]",
		"\tAdded category/added-after version 1.0 [updater 2019-07-01]",
		"\tMoved category/moved-from to category/moved-to [author 2019-07-02]",
		"\tDowngraded category/downgraded to 1.0 [author 2019-07-03]")

	t.Main("-Wall", "--source", "wip/package")

	// Since the first argument is in pkgsrc-wip, the check for doc/CHANGES
	// is skipped. It may well be that a pkgsrc-wip developer doesn't have
	// write access to main pkgsrc, and therefore cannot fix doc/CHANGES.

	t.CheckOutputLines(
		"Looks fine.")
}

func (s *Suite) Test_Change_Version(c *check.C) {
	t := s.Init(c)

	loc := Location{"doc/CHANGES-2019", 5}
	added := Change{loc, Added, "category/path", "1.0", "author", "2019-01-01"}
	updated := Change{loc, Updated, "category/path", "1.0", "author", "2019-01-01"}
	downgraded := Change{loc, Downgraded, "category/path", "1.0", "author", "2019-01-01"}
	removed := Change{loc, Removed, "category/path", "1.0", "author", "2019-01-01"}

	t.CheckEquals(added.Version(), "1.0")
	t.CheckEquals(updated.Version(), "1.0")
	t.CheckEquals(downgraded.Version(), "1.0")
	t.ExpectAssert(func() { removed.Version() })
}

func (s *Suite) Test_Change_Target(c *check.C) {
	t := s.Init(c)

	loc := Location{"doc/CHANGES-2019", 5}
	renamed := Change{loc, Renamed, "category/path", "category/other", "author", "2019-01-01"}
	moved := Change{loc, Moved, "category/path", "category/other", "author", "2019-01-01"}
	downgraded := Change{loc, Downgraded, "category/path", "1.0", "author", "2019-01-01"}

	t.CheckEquals(renamed.Target(), NewPkgsrcPath("category/other"))
	t.CheckEquals(moved.Target(), NewPkgsrcPath("category/other"))
	t.ExpectAssert(func() { downgraded.Target() })
}

func (s *Suite) Test_Change_SuccessorOrVersion(c *check.C) {
	t := s.Init(c)

	loc := Location{"doc/CHANGES-2019", 5}
	removed := Change{loc, Removed, "category/path", "", "author", "2019-01-01"}
	removedSucc := Change{loc, Removed, "category/path", "category/successor", "author", "2019-01-01"}
	removedVersion := Change{loc, Removed, "category/path", "1.3.4", "author", "2019-01-01"}
	downgraded := Change{loc, Downgraded, "category/path", "1.0", "author", "2019-01-01"}

	t.CheckEquals(removed.SuccessorOrVersion(), "")
	t.CheckEquals(removedSucc.SuccessorOrVersion(), "category/successor")
	t.CheckEquals(removedVersion.SuccessorOrVersion(), "1.3.4")
	t.ExpectAssert(func() { downgraded.SuccessorOrVersion() })
}

func (s *Suite) Test_Change_IsAbove(c *check.C) {
	t := s.Init(c)

	var changes = []*Change{
		{Location{"", 1}, 0, "", "", "", "2011-07-01"},
		{Location{"", 2}, 0, "", "", "", "2011-07-01"},
		{Location{"", 1}, 0, "", "", "", "2011-07-02"}}

	test := func(i int, chi *Change, j int, chj *Change) {
		actual := chi.IsAbove(chj)
		expected := i < j
		if actual != expected {
			t.CheckDeepEquals(
				[]interface{}{i, *chi, j, *chj, actual},
				[]interface{}{i, *chi, j, *chj, expected})
		}
	}

	for i, chi := range changes {
		for j, chj := range changes {
			test(i, chi, j, chj)
		}
	}
}

func (s *Suite) Test_ParseChangeAction(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(ParseChangeAction("Added"), Added)
	t.CheckEquals(ParseChangeAction("Unknown"), ChangeAction(0))
}

func (s *Suite) Test_ChangeAction_String(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(Added.String(), "Added")
	t.CheckEquals(Removed.String(), "Removed")
}
