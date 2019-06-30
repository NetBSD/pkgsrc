package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_Lines_CheckCvsID(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("filename",
		"$"+"NetBSD: dummy $",
		"$"+"NetBSD$",
		"$"+"Id: dummy $",
		"$"+"Id$",
		"$"+"FreeBSD$")

	for i := range lines.Lines {
		lines.CheckCvsID(i, ``, "")
	}

	t.CheckOutputLines(
		"ERROR: filename:3: Expected \"$"+"NetBSD$\".",
		"ERROR: filename:4: Expected \"$"+"NetBSD$\".",
		"ERROR: filename:5: Expected \"$"+"NetBSD$\".")
}

// Since pkgsrc-wip uses Git as version control system, the CVS-specific
// IDs don't make sense there. More often than not, the expanded form
// "$NetBSD:" is a copy-and-paste mistake rather than an intentional
// documentation of the file's history. Therefore, pkgsrc-wip files should
// only use the unexpanded form.
func (s *Suite) Test_Lines_CheckCvsID__wip(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.SetUpPackage("wip/package")
	t.CreateFileLines("wip/package/file1.mk",
		"# $"+"NetBSD: dummy $")
	t.CreateFileLines("wip/package/file2.mk",
		"# $"+"NetBSD$")
	t.CreateFileLines("wip/package/file3.mk",
		"# $"+"Id: dummy $")
	t.CreateFileLines("wip/package/file4.mk",
		"# $"+"Id$")
	t.CreateFileLines("wip/package/file5.mk",
		"# $"+"FreeBSD$")
	t.FinishSetUp()

	G.Check(t.File("wip/package"))

	t.CheckOutputLines(
		"NOTE: ~/wip/package/file1.mk:1: Expected exactly \"# $"+"NetBSD$\".",
		"ERROR: ~/wip/package/file3.mk:1: Expected \"# $"+"NetBSD$\".",
		"ERROR: ~/wip/package/file4.mk:1: Expected \"# $"+"NetBSD$\".",
		"ERROR: ~/wip/package/file5.mk:1: Expected \"# $"+"NetBSD$\".")

	G.Logger.Opts.Autofix = true

	G.Check(t.File("wip/package"))

	t.CheckOutputLines(
		"AUTOFIX: ~/wip/package/file1.mk:1: Replacing \"# $"+"NetBSD: dummy $\" with \"# $"+"NetBSD$\".",
		"AUTOFIX: ~/wip/package/file3.mk:1: Inserting a line \"# $"+"NetBSD$\" before this line.",
		"AUTOFIX: ~/wip/package/file4.mk:1: Inserting a line \"# $"+"NetBSD$\" before this line.",
		"AUTOFIX: ~/wip/package/file5.mk:1: Inserting a line \"# $"+"NetBSD$\" before this line.")

	// In production mode, this error is disabled since it doesn't provide
	// enough benefit compared to the work it would produce.
	//
	// To make it useful, the majority of pkgsrc-wip packages would first
	// have to follow this style.
	G.Testing = false

	G.Check(t.File("wip/package"))

	t.CheckOutputEmpty()
}
