package main

import "gopkg.in/check.v1"

// Since the --source option generates multi-line diagnostics,
// they are separated by an empty line.
//
// Whether the quoted source code is written above or below the
// diagnostics depends on the --show-autofix and --autofix options.
// When any of them is given, the general rule is given first, followed
// by a description of the fix ("replacing A with B"), finally followed
// by the actual changes to the code.
//
// In default mode, without any autofix options, the usual order is
// to first show the code and then show the diagnostic. This allows
// the diagnostics to underline the relevant part of the source code
// and reminds of the squiggly line used for spellchecking.
func (s *Suite) Test__show_source_separator(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--source")
	lines := t.SetupFileLines("DESCR",
		"The first line",
		"The second line",
		"The third line")

	fix := lines.Lines[1].Autofix()
	fix.Warnf("Using \"second\" is deprecated.")
	fix.Replace("second", "silver medal")
	fix.Apply()

	lines.Lines[2].Warnf("Dummy warning.")

	fix = lines.Lines[2].Autofix()
	fix.Warnf("Using \"third\" is deprecated.")
	fix.Replace("third", "bronze medal")
	fix.Apply()

	t.CheckOutputLines(
		">\tThe second line",
		"WARN: ~/DESCR:2: Using \"second\" is deprecated.",
		"",
		">\tThe third line",
		"WARN: ~/DESCR:3: Dummy warning.",
		"",
		">\tThe third line",
		"WARN: ~/DESCR:3: Using \"third\" is deprecated.")
}

func (s *Suite) Test__show_source_separator_show_autofix(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--source", "--show-autofix")
	lines := t.SetupFileLines("DESCR",
		"The first line",
		"The second line",
		"The third line")

	fix := lines.Lines[1].Autofix()
	fix.Warnf("Using \"second\" is deprecated.")
	fix.Replace("second", "silver medal")
	fix.Apply()

	lines.Lines[2].Warnf("Dummy warning.")

	fix = lines.Lines[2].Autofix()
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

	fix := lines.Lines[1].Autofix()
	fix.Warnf("Using \"second\" is deprecated.")
	fix.Replace("second", "silver medal")
	fix.Apply()

	lines.Lines[2].Warnf("Dummy warning.")

	fix = lines.Lines[2].Autofix()
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

func (s *Suite) Test_logf__duplicate_messages(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--explain")
	G.Opts.LogVerbose = false
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

func (s *Suite) Test_logf__duplicate_explanations(c *check.C) {
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

// Even if verbose logging is disabled, the "Replacing" diagnostics
// must not be filtered for duplicates since each of them modifies the line.
func (s *Suite) Test_logf__duplicate_autofix(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--explain", "--autofix")
	G.Opts.LogVerbose = false // See SetUpTest
	line := t.NewLine("README.txt", 123, "text")

	fix := line.Autofix()
	fix.Warnf("T should always be uppercase.")
	fix.ReplaceRegex(`t`, "T", -1)
	fix.Apply()

	t.CheckOutputLines(
		"AUTOFIX: README.txt:123: Replacing \"t\" with \"T\".",
		"AUTOFIX: README.txt:123: Replacing \"t\" with \"T\".")
}

func (s *Suite) Test_logf__panic(c *check.C) {
	t := s.Init(c)

	t.ExpectPanic(
		func() { logf(Error, "fileName", "13", "No period", "No period") },
		"Pkglint internal error: Diagnostic format \"No period\" must end in a period.")
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
