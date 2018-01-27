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
func (s *Suite) Test_show_source_separator(c *check.C) {
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

func (s *Suite) Test_show_source_separator_show_autofix(c *check.C) {
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

func (s *Suite) Test_show_source_separator_autofix(c *check.C) {
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
func (s *Suite) Test_Line_log_only(c *check.C) {
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
