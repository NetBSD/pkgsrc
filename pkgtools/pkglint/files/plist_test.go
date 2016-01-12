package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestChecklinesPlist(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.Pkg = NewPackage("category/pkgbase")
	lines := s.NewLines("PLIST",
		"bin/i386/6c",
		"bin/program",
		"etc/my.cnf",
		"etc/rc.d/service",
		"@exec ${MKDIR} include/pkgbase",
		"info/dir",
		"lib/c.so",
		"lib/libc.so.6",
		"lib/libc.la",
		"${PLIST.man}man/cat3/strcpy.4",
		"man/man1/imake.${IMAKE_MANNEWSUFFIX}",
		"${PLIST.obsolete}@unexec rmdir /tmp",
		"sbin/clockctl",
		"share/icons/gnome/delete-icon",
		"share/tzinfo",
		"share/tzinfo")

	ChecklinesPlist(lines)

	c.Check(s.Output(), equals, ""+
		"ERROR: PLIST:1: Expected \"@comment $"+"NetBSD$\".\n"+
		"WARN: PLIST:1: The bin/ directory should not have subdirectories.\n"+
		"WARN: PLIST:2: Manual page missing for bin/program.\n"+
		"ERROR: PLIST:3: Configuration files must not be registered in the PLIST. Please use the CONF_FILES framework, which is described in mk/pkginstall/bsd.pkginstall.mk.\n"+
		"ERROR: PLIST:4: RCD_SCRIPTS must not be registered in the PLIST. Please use the RCD_SCRIPTS framework.\n"+
		"ERROR: PLIST:6: \"info/dir\" must not be listed. Use install-info to add/remove an entry.\n"+
		"WARN: PLIST:7: Library filename \"c.so\" should start with \"lib\".\n"+
		"WARN: PLIST:8: Redundant library found. The libtool library is in line 9.\n"+
		"WARN: PLIST:9: \"lib/libc.la\" should be sorted before \"lib/libc.so.6\".\n"+
		"WARN: PLIST:10: Preformatted manual page without unformatted one.\n"+
		"WARN: PLIST:10: Preformatted manual pages should end in \".0\".\n"+
		"WARN: PLIST:11: IMAKE_MANNEWSUFFIX is not meant to appear in PLISTs.\n"+
		"WARN: PLIST:12: Please remove this line. It is no longer necessary.\n"+
		"WARN: PLIST:13: Manual page missing for sbin/clockctl.\n"+
		"ERROR: PLIST:14: The package Makefile must include \"../../graphics/gnome-icon-theme/buildlink3.mk\".\n"+
		"ERROR: PLIST:16: Duplicate filename \"share/tzinfo\", already appeared in line 15.\n")
}

func (s *Suite) TestChecklinesPlist_empty(c *check.C) {
	lines := s.NewLines("PLIST",
		"@comment $"+"NetBSD$")

	ChecklinesPlist(lines)

	c.Check(s.Output(), equals, "WARN: PLIST:1: PLIST files shouldn't be empty.\n")
}

func (s *Suite) TestChecklinesPlist_commonEnd(c *check.C) {
	s.CreateTmpFile(c, "PLIST.common", ""+
		"@comment $"+"NetBSD$\n"+
		"bin/common\n")
	fname := s.CreateTmpFile(c, "PLIST.common_end", ""+
		"@comment $"+"NetBSD$\n"+
		"sbin/common_end\n")

	ChecklinesPlist(LoadExistingLines(fname, false))

	c.Check(s.OutputCleanTmpdir(), equals, "")
}

func (s *Suite) TestChecklinesPlist_conditional(c *check.C) {
	G.Pkg = NewPackage("category/pkgbase")
	G.Pkg.plistSubstCond["PLIST.bincmds"] = true
	lines := s.NewLines("PLIST",
		"@comment $"+"NetBSD$",
		"${PLIST.bincmds}bin/subdir/command")

	ChecklinesPlist(lines)

	c.Check(s.Output(), equals, "WARN: PLIST:2: The bin/ directory should not have subdirectories.\n")
}

func (s *Suite) TestChecklinesPlist_sorting(c *check.C) {
	s.UseCommandLine(c, "-Wplist-sort")
	lines := s.NewLines("PLIST",
		"@comment $"+"NetBSD$",
		"@comment Do not remove",
		"sbin/i386/6c",
		"sbin/program",
		"bin/otherprogram",
		"${PLIST.conditional}bin/cat")

	ChecklinesPlist(lines)

	c.Check(s.Output(), equals, ""+
		"WARN: PLIST:5: \"bin/otherprogram\" should be sorted before \"sbin/program\".\n"+
		"WARN: PLIST:6: \"bin/cat\" should be sorted before \"bin/otherprogram\".\n")
}

func (s *Suite) TestPlistChecker_sort(c *check.C) {
	s.UseCommandLine(c, "--autofix")
	tmpfile := s.CreateTmpFile(c, "PLIST", "dummy\n")
	ck := &PlistChecker{nil, nil, ""}
	lines := s.NewLines(tmpfile,
		"@comment $"+"NetBSD$",
		"@comment Do not remove",
		"A",
		"b",
		"CCC",
		"lib/${UNKNOWN}.la",
		"C",
		"ddd",
		"@exec echo \"after ddd\"",
		"sbin/program",
		"${PLIST.one}bin/program",
		"${PKGMANDIR}/man1/program.1",
		"${PLIST.two}bin/program2",
		"lib/before.la",
		"lib/after.la",
		"@exec echo \"after lib/after.la\"")
	plines := ck.NewLines(lines)

	NewPlistLineSorter(plines).Sort()

	c.Check(s.OutputCleanTmpdir(), equals, ""+
		"AUTOFIX: ~/PLIST:1: Sorting the whole file.\n"+
		"AUTOFIX: ~/PLIST: Has been auto-fixed. Please re-run pkglint.\n")
	c.Check(s.LoadTmpFile(c, "PLIST"), equals, ""+
		"@comment $"+"NetBSD$\n"+
		"@comment Do not remove\n"+
		"A\n"+
		"C\n"+
		"CCC\n"+
		"lib/${UNKNOWN}.la\n"+ // Stays below the previous line
		"b\n"+
		"${PLIST.one}bin/program\n"+ // Conditionals are ignored while sorting
		"${PKGMANDIR}/man1/program.1\n"+ // Stays below the previous line
		"${PLIST.two}bin/program2\n"+
		"ddd\n"+
		"@exec echo \"after ddd\"\n"+ // Stays below the previous line
		"lib/after.la\n"+
		"@exec echo \"after lib/after.la\"\n"+
		"lib/before.la\n"+
		"sbin/program\n")
}

func (s *Suite) TestPlistChecker_checkpathShare_Desktop(c *check.C) {
	s.UseCommandLine(c, "-Wextra")
	G.Pkg = NewPackage("category/pkgpath")

	ChecklinesPlist(s.NewLines("PLIST",
		"@comment $"+"NetBSD$",
		"share/applications/pkgbase.desktop"))

	c.Check(s.Output(), equals, "WARN: PLIST:2: Packages that install a .desktop entry should .include \"../../sysutils/desktop-file-utils/desktopdb.mk\".\n")
}

func (s *Suite) TestPlistChecker_checkpathMan_gz(c *check.C) {
	G.Pkg = NewPackage("category/pkgbase")

	ChecklinesPlist(s.NewLines("PLIST",
		"@comment $"+"NetBSD$",
		"man/man3/strerror.3.gz"))

	c.Check(s.Output(), equals, "NOTE: PLIST:2: The .gz extension is unnecessary for manual pages.\n")
}
