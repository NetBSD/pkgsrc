package main

import "gopkg.in/check.v1"

// Since the --source option generates multi-line diagnostics,
// they are separated by an empty line.
//
// The quoted source code is written below the diagnostics.
// In the --show-autofix and --autofix modes, this order
// is the most useful since it first states the general rule,
// then states how to fix this instance and then shows a concrete
// example. Understanding the general rule is considered most
// important of these three.
//
// To keep the output layout consistent between all these
// modes, the source code is written below the diagnostic
// also in the default (check-only) mode.
func (s *Suite) Test__show_source_separator(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--source")
	lines := t.SetupFileLines("DESCR",
		"The first line",
		"The second line",
		"The third line")

	fix := lines[1].Autofix()
	fix.Warnf("Using \"second\" is deprecated.")
	fix.Replace("second", "silver medal")
	fix.Apply()

	lines[2].Warnf("Dummy warning.")

	fix = lines[2].Autofix()
	fix.Warnf("Using \"third\" is deprecated.")
	fix.Replace("third", "bronze medal")
	fix.Apply()

	t.CheckOutputLines(
		"WARN: ~/DESCR:2: Using \"second\" is deprecated.",
		">\tThe second line",
		"",
		"WARN: ~/DESCR:3: Dummy warning.",
		">\tThe third line",
		"",
		"WARN: ~/DESCR:3: Using \"third\" is deprecated.",
		">\tThe third line")
}

func (s *Suite) Test__show_source_separator_show_autofix(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--source", "--show-autofix")
	lines := t.SetupFileLines("DESCR",
		"The first line",
		"The second line",
		"The third line")

	fix := lines[1].Autofix()
	fix.Warnf("Using \"second\" is deprecated.")
	fix.Replace("second", "silver medal")
	fix.Apply()

	lines[2].Warnf("Dummy warning.")

	fix = lines[2].Autofix()
	fix.Warnf("Using \"third\" is deprecated.")
	fix.Replace("third", "bronze medal")
	fix.Apply()

	t.CheckOutputLines(
		"WARN: ~/DESCR:2: Using \"second\" is deprecated.",
		"AUTOFIX: ~/DESCR:2: Replacing \"second\" with \"silver medal\".",
		"-\tThe second line",
		"+\tThe silver medal line",
		"",
		"WARN: ~/DESCR:3: Using \"third\" is deprecated.",
		"AUTOFIX: ~/DESCR:3: Replacing \"third\" with \"bronze medal\".",
		"-\tThe third line",
		"+\tThe bronze medal line")
}

func (s *Suite) Test__show_source_separator_autofix(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--source", "--autofix")
	lines := t.SetupFileLines("DESCR",
		"The first line",
		"The second line",
		"The third line")

	fix := lines[1].Autofix()
	fix.Warnf("Using \"second\" is deprecated.")
	fix.Replace("second", "silver medal")
	fix.Apply()

	lines[2].Warnf("Dummy warning.")

	fix = lines[2].Autofix()
	fix.Warnf("Using \"third\" is deprecated.")
	fix.Replace("third", "bronze medal")
	fix.Apply()

	t.CheckOutputLines(
		"AUTOFIX: ~/DESCR:2: Replacing \"second\" with \"silver medal\".",
		"-\tThe second line",
		"+\tThe silver medal line",
		"",
		"AUTOFIX: ~/DESCR:3: Replacing \"third\" with \"bronze medal\".",
		"-\tThe third line",
		"+\tThe bronze medal line")
}

// Demonstrates how to filter log messages.
// This is useful in combination with the --autofix option,
// to restrict the fixes to exactly one group or topic.
func (s *Suite) Test_Line_log__only(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--autofix", "--source", "--only", "interesting")
	line := t.NewLine("Makefile", 27, "The old song")

	// Is completely ignored, including any autofixes.
	fix := line.Autofix()
	fix.Warnf("Using \"old\" is deprecated.")
	fix.Replace("old", "new1")
	fix.Apply()

	fix.Warnf("Using \"old\" is interesting.")
	fix.Replace("old", "new2")
	fix.Apply()

	t.CheckOutputLines(
		"AUTOFIX: Makefile:27: Replacing \"old\" with \"new2\".",
		"-\tThe old song",
		"+\tThe new2 song")
}

func (s *Suite) Test_Pkglint_PrintSummary__explanations_with_only(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--only", "interesting")
	line := t.NewLine("Makefile", 27, "The old song")

	line.Warnf("Filtered warning.")               // Is not logged.
	Explain("Explanation for the above warning.") // Neither would this explanation be logged.
	G.PrintSummary()

	c.Check(G.explanationsAvailable, equals, false)
	t.CheckOutputLines(
		"Looks fine.") // "pkglint -e" is not advertised since the above explanation is not relevant.

	line.Warnf("What an interesting line.")
	Explain("This explanation is available.")
	G.PrintSummary()

	c.Check(G.explanationsAvailable, equals, true)
	t.CheckOutputLines(
		"WARN: Makefile:27: What an interesting line.",
		"0 errors and 1 warning found.",
		"(Run \"pkglint -e\" to show explanations.)")
}

func (s *Suite) Test_Explain__only(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--only", "interesting", "--explain")
	line := t.NewLine("Makefile", 27, "The old song")

	line.Warnf("Filtered warning.")               // Is not logged.
	Explain("Explanation for the above warning.") // Neither is this explanation logged.

	line.Warnf("What an interesting line.")
	Explain("This explanation is logged.")

	t.CheckOutputLines(
		"WARN: Makefile:27: What an interesting line.",
		"",
		"\tThis explanation is logged.",
		"")
}

func (s *Suite) Test_logs__duplicate_messages(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--explain")
	G.opts.LogVerbose = false
	line := t.NewLine("README.txt", 123, "text")

	// In rare cases, the explanations for the same warning may differ
	// when they appear in different contexts. In such a case, if the
	// warning is suppressed, the explanation must not appear on its own.
	line.Warnf("The warning.") // Is logged
	Explain("Explanation 1")
	line.Warnf("The warning.") // Is suppressed
	Explain("Explanation 2")

	t.CheckOutputLines(
		"WARN: README.txt:123: The warning.",
		"",
		"\tExplanation 1",
		"")
}

func (s *Suite) Test_logs__duplicate_explanations(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--explain")
	line := t.NewLine("README.txt", 123, "text")

	// In rare cases, different diagnostics may have the same explanation.
	line.Warnf("Warning 1.")
	Explain("Explanation")
	line.Warnf("Warning 2.")
	Explain("Explanation") // Is suppressed.

	t.CheckOutputLines(
		"WARN: README.txt:123: Warning 1.",
		"",
		"\tExplanation",
		"",
		"WARN: README.txt:123: Warning 2.")
}

func (s *Suite) Test_logs__panic(c *check.C) {
	c.Check(func() {
		logs(llError, "filename", "13", "No period", "No period")
	}, check.Panics, "Diagnostic format \"No period\" must end in a period.")
}

func (s *Suite) Test_Explain__long_lines(c *check.C) {
	t := s.Init(c)

	Explain(
		"123456789 12345678. abcdefghi. 123456789 123456789 123456789 123456789 123456789")

	t.CheckOutputLines(
		"Long explanation line: 123456789 12345678. abcdefghi. 123456789 123456789 123456789 123456789 123456789",
		"Break after: 123456789 12345678. abcdefghi. 123456789 123456789 123456789",
		"Short space after period: 123456789 12345678. abcdefghi. 123456789 123456789 123456789 123456789 123456789")
}

func (s *Suite) Test_Explain__trailing_whitespace(c *check.C) {
	t := s.Init(c)

	Explain(
		"This is a space: ")

	t.CheckOutputLines(
		"Trailing whitespace: \"This is a space: \"")
}
