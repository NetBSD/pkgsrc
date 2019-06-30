package pkglint

import (
	"gopkg.in/check.v1"
	"netbsd.org/pkglint/histogram"
	"strings"
)

// Calling Logf without further preparation just logs the message.
// Suppressing duplicate messages or filtering messages happens
// in other methods of the Logger, namely Relevant, FirstTime, Diag.
func (s *Suite) Test_Logger_Logf(c *check.C) {
	var sw strings.Builder
	logger := Logger{out: NewSeparatorWriter(&sw)}

	logger.Logf(Error, "filename", "3", "Blue should be %s.", "Blue should be orange.")

	c.Check(sw.String(), equals, ""+
		"ERROR: filename:3: Blue should be orange.\n")
}

// Logf doesn't filter duplicates, but Diag does.
func (s *Suite) Test_Logger_Logf__duplicates(c *check.C) {
	var sw strings.Builder
	logger := Logger{out: NewSeparatorWriter(&sw)}

	logger.Logf(Error, "filename", "3", "Blue should be %s.", "Blue should be orange.")
	logger.Logf(Error, "filename", "3", "Blue should be %s.", "Blue should be orange.")

	c.Check(sw.String(), equals, ""+
		"ERROR: filename:3: Blue should be orange.\n"+
		"ERROR: filename:3: Blue should be orange.\n")
}

// Ensure that suppressing a diagnostic doesn't influence later calls to Logf.
func (s *Suite) Test_Logger_Logf__mixed_with_Diag(c *check.C) {
	t := s.Init(c)

	var sw strings.Builder
	logger := Logger{out: NewSeparatorWriter(&sw)}
	line := t.NewLine("filename", 3, "Text")

	logger.Logf(Error, "filename", "3", "Logf output 1.", "Logf output 1.")
	logger.Diag(line, Error, "Diag %s.", "1")
	logger.Logf(Error, "filename", "3", "Logf output 2.", "Logf output 2.")
	logger.Diag(line, Error, "Diag %s.", "1") // Duplicate, therefore suppressed
	logger.Logf(Error, "filename", "3", "Logf output 3.", "Logf output 3.")

	c.Check(sw.String(), equals, ""+
		"ERROR: filename:3: Logf output 1.\n"+
		"ERROR: filename:3: Diag 1.\n"+
		"ERROR: filename:3: Logf output 2.\n"+
		"ERROR: filename:3: Logf output 3.\n")
}

func (s *Suite) Test_Logger_Logf__production(c *check.C) {
	var sw strings.Builder
	logger := Logger{out: NewSeparatorWriter(&sw)}

	// In production mode, the checks for the diagnostic messages are
	// turned off, for performance reasons. The unit tests provide
	// enough coverage.
	G.Testing = false
	logger.Logf(Error, "filename", "3", "diagnostic", "message")

	c.Check(sw.String(), equals, ""+
		"ERROR: filename:3: message\n")
}

func (s *Suite) Test_Logger_Logf__profiling(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename", 123, "text")

	G.Opts.Profiling = true
	G.Logger.histo = histogram.New()
	line.Warnf("Warning.")

	G.Logger.histo.PrintStats(G.Logger.out.out, "loghisto", -1)

	t.CheckOutputLines(
		"WARN: filename:123: Warning.",
		"loghisto      1 Warning.")
}

func (s *Suite) Test_Logger_Logf__profiling_autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--show-autofix", "--source", "--explain")
	line := t.NewLine("filename", 123, "text")

	G.Opts.Profiling = true
	G.Logger.histo = histogram.New()

	fix := line.Autofix()
	fix.Notef("Autofix note.")
	fix.Explain(
		"Autofix explanation.")
	fix.Replace("text", "replacement")
	fix.Apply()

	// The AUTOFIX line is not counted in the histogram although
	// it uses the same code path as the other messages.
	G.Logger.histo.PrintStats(G.Logger.out.out, "loghisto", -1)

	t.CheckOutputLines(
		"NOTE: filename:123: Autofix note.",
		"AUTOFIX: filename:123: Replacing \"text\" with \"replacement\".",
		"-\ttext",
		"+\treplacement",
		"",
		"\tAutofix explanation.",
		"",
		"loghisto      1 Autofix note.")
}

// Diag filters duplicate messages, unlike Logf.
func (s *Suite) Test_Logger_Diag__duplicates(c *check.C) {
	t := s.Init(c)

	var sw strings.Builder
	logger := Logger{out: NewSeparatorWriter(&sw)}
	line := t.NewLine("filename", 3, "Text")

	logger.Diag(line, Error, "Blue should be %s.", "orange")
	logger.Diag(line, Error, "Blue should be %s.", "orange")

	c.Check(sw.String(), equals, ""+
		"ERROR: filename:3: Blue should be orange.\n")
}

// Explanations are associated with their diagnostics. Therefore, when one
// of them is suppressed, the other is suppressed, too.
func (s *Suite) Test_Logger_Diag__explanation(c *check.C) {
	t := s.Init(c)

	var sw strings.Builder
	logger := Logger{out: NewSeparatorWriter(&sw)}
	logger.Opts.Explain = true
	line := t.NewLine("filename", 3, "Text")

	logger.Diag(line, Error, "Blue should be %s.", "orange")
	logger.Explain(
		"The colors have changed.")

	logger.Diag(line, Error, "Blue should be %s.", "orange")
	logger.Explain(
		"The colors have changed.")

	// Even when the text of the explanation is not the same, it is still
	// suppressed since it belongs to the diagnostic.
	logger.Diag(line, Error, "Blue should be %s.", "orange")
	logger.Explain(
		"The colors have further changed.")

	c.Check(sw.String(), equals, ""+
		"ERROR: filename:3: Blue should be orange.\n"+
		"\n"+
		"\tThe colors have changed.\n"+
		"\n")
}

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
func (s *Suite) Test_Logger__show_source_separator(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--source")
	lines := t.SetUpFileLines("DESCR",
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

// When the --show-autofix option is given, the warning is shown first,
// without the affected source, even if the --source option is also given.
// This is because the original and the modified source are shown after
// the "Replacing" message. Since these are shown in diff style, they
// must be kept together. And since the "+" line must be below the "Replacing"
// line, this order of lines seems to be the most intuitive.
func (s *Suite) Test__show_source_separator_show_autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--source", "--show-autofix")
	lines := t.SetUpFileLines("DESCR",
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

// See Test__show_source_separator_show_autofix for the ordering of the
// output lines.
//
// TODO: Giving the diagnostics again would be useful, but the warning and
//  error counters should not be affected, as well as the exitcode.
func (s *Suite) Test__show_source_separator_autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--source", "--autofix")
	lines := t.SetUpFileLines("DESCR",
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

func (s *Suite) Test_Logger_Explain__only(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--only", "interesting", "--explain")
	line := t.NewLine("Makefile", 27, "The old song")

	// Neither the warning nor the corresponding explanation are logged.
	line.Warnf("Filtered warning.")
	line.Explain("Explanation for the above warning.")

	line.Notef("What an interesting line.")
	line.Explain("This explanation is logged.")

	t.CheckOutputLines(
		"NOTE: Makefile:27: What an interesting line.",
		"",
		"\tThis explanation is logged.",
		"")
}

func (s *Suite) Test_Logger_Explain__show_autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--explain", "--show-autofix")
	line := t.NewLine("Makefile", 27, "The old song")

	line.Warnf("Warning without fix.")
	line.Explain(
		"Explanation for warning without fix.")

	fix := line.Autofix()
	fix.Warnf("Warning with fix.")
	fix.Explain(
		"Explanation for warning with fix.")
	fix.Replace("old", "new")
	fix.Apply()

	// Since the warning without fix doesn't fix anything, it is filtered out.
	// So is the corresponding explanation.
	t.CheckOutputLines(
		"WARN: Makefile:27: Warning with fix.",
		"AUTOFIX: Makefile:27: Replacing \"old\" with \"new\".",
		"",
		"\tExplanation for warning with fix.",
		"")
}

func (s *Suite) Test_Logger_Explain__show_autofix_and_source(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--explain", "--show-autofix", "--source")
	line := t.NewLine("Makefile", 27, "The old song")

	line.Warnf("Warning without fix.")
	line.Explain(
		"Explanation for warning without fix.")

	fix := line.Autofix()
	fix.Warnf("Warning with fix.")
	fix.Explain(
		"Explanation for warning with fix.")
	fix.Replace("old", "new")
	fix.Apply()

	// Since the warning without fix doesn't fix anything, it is filtered out.
	// So is the corresponding explanation.
	t.CheckOutputLines(
		"WARN: Makefile:27: Warning with fix.",
		"AUTOFIX: Makefile:27: Replacing \"old\" with \"new\".",
		"-\tThe old song",
		"+\tThe new song",
		"",
		"\tExplanation for warning with fix.",
		"")
}

// When the --autofix option is given, the warnings are not shown, therefore it doesn't
// make sense to show the explanation for the warning.
func (s *Suite) Test_Logger_Explain__autofix_and_source(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--explain", "--autofix", "--source")
	line := t.NewLine("Makefile", 27, "The old song")

	line.Warnf("Warning without fix.")
	line.Explain(
		"Explanation for warning without fix.")

	fix := line.Autofix()
	fix.Warnf("Warning with fix.")
	fix.Explain(
		"Explanation for warning with fix.")
	fix.Replace("old", "new")
	fix.Apply()

	// Since the warning without fix doesn't fix anything, it is filtered out.
	// So is the corresponding explanation.
	t.CheckOutputLines(
		"AUTOFIX: Makefile:27: Replacing \"old\" with \"new\".",
		"-\tThe old song",
		"+\tThe new song")
}

// When an explanation consists of multiple paragraphs, it contains some empty lines.
// When printing these lines, there is no need to write the tab that is used for indenting
// the normal lines.
//
// Since pkglint likes to complain about trailing whitespace, it should not generate it itself.
func (s *Suite) Test_Logger_Explain__empty_lines(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--explain")
	line := t.NewLine("Makefile", 27, "The old song")

	line.Warnf("A normal warning.")
	line.Explain(
		"Paragraph 1 of the explanation.",
		"",
		"Paragraph 2 of the explanation.")

	t.CheckOutputLines(
		"WARN: Makefile:27: A normal warning.",
		"",
		"\tParagraph 1 of the explanation.",
		"",
		"\tParagraph 2 of the explanation.",
		"")
}

// In an explanation, it can happen that the pkgsrc directory is mentioned.
// While pkgsrc does not support either PKGSRCDIR or PREFIX or really any
// other directory name to contain spaces, during pkglint development this
// may happen because the pkgsrc root is in the temporary directory.
//
// In this situation, the ~ placeholder must still be properly substituted.
func (s *Suite) Test_Logger_Explain__line_wrapped_temporary_directory(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--explain")
	filename := t.File("filename.mk")
	mkline := t.NewMkLine(filename, 123, "")

	mkline.Notef("Just a note to get the below explanation.")
	G.Logger.Explain(
		sprintf("%[1]s %[1]s %[1]s %[1]s %[1]s %[1]q", filename))

	t.CheckOutputLinesIgnoreSpace(
		"NOTE: ~/filename.mk:123: Just a note to get the below explanation.",
		"",
		"\t~/filename.mk",
		"\t~/filename.mk",
		"\t~/filename.mk",
		"\t~/filename.mk",
		"\t~/filename.mk",
		"\t\"~/filename.mk\"",
		"")
}

func (s *Suite) Test_Logger_ShowSummary__explanations_with_only(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--only", "interesting")
	line := t.NewLine("Makefile", 27, "The old song")

	// Neither the warning nor the corresponding explanation are logged.
	line.Warnf("Filtered warning.")
	line.Explain("Explanation for the above warning.")
	G.Logger.ShowSummary()

	// Since the above warning is filtered out by the --only option,
	// adding --explain to the options would not show any explanation.
	// Therefore, "Run \"pkglint -e\"" is not advertised in this case,
	// but see below.
	c.Check(G.Logger.explanationsAvailable, equals, false)
	t.CheckOutputLines(
		"Looks fine.")

	line.Warnf("This warning is interesting.")
	line.Explain("This explanation is available.")
	G.Logger.ShowSummary()

	c.Check(G.Logger.explanationsAvailable, equals, true)
	t.CheckOutputLines(
		"WARN: Makefile:27: This warning is interesting.",
		"0 errors and 1 warning found.",
		"(Run \"pkglint -e\" to show explanations.)")
}

func (s *Suite) Test_Logger_ShowSummary__looks_fine(c *check.C) {
	t := s.Init(c)

	logger := Logger{out: NewSeparatorWriter(&t.stdout)}

	logger.ShowSummary()

	t.CheckOutputLines(
		"Looks fine.")
}

func (s *Suite) Test_Logger_ShowSummary__1_error_1_warning(c *check.C) {
	t := s.Init(c)

	logger := Logger{out: NewSeparatorWriter(&t.stdout)}
	logger.Logf(Error, "", "", ".", ".")
	logger.Logf(Warn, "", "", ".", ".")

	logger.ShowSummary()

	t.CheckOutputLines(
		"ERROR: .",
		"WARN: .",
		"1 error and 1 warning found.")
}

func (s *Suite) Test_Logger_ShowSummary__2_errors_3_warnings(c *check.C) {
	t := s.Init(c)

	logger := Logger{out: NewSeparatorWriter(&t.stdout)}
	logger.Logf(Error, "", "", "1.", "1.")
	logger.Logf(Error, "", "", "2.", "2.")
	logger.Logf(Warn, "", "", "3.", "3.")
	logger.Logf(Warn, "", "", "4.", "4.")
	logger.Logf(Warn, "", "", "5.", "5.")

	logger.ShowSummary()

	t.CheckOutputLines(
		"ERROR: 1.",
		"ERROR: 2.",
		"WARN: 3.",
		"WARN: 4.",
		"WARN: 5.",
		"2 errors and 3 warnings found.")
}

func (s *Suite) Test_Logger_ShowSummary__looks_fine_quiet(c *check.C) {
	t := s.Init(c)

	logger := Logger{out: NewSeparatorWriter(&t.stdout)}
	logger.Opts.Quiet = true

	logger.ShowSummary()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Logger_ShowSummary__1_error_1_warning_quiet(c *check.C) {
	t := s.Init(c)

	logger := Logger{out: NewSeparatorWriter(&t.stdout)}
	logger.Opts.Quiet = true
	logger.Logf(Error, "", "", ".", ".")
	logger.Logf(Warn, "", "", ".", ".")

	logger.ShowSummary()

	t.CheckOutputLines(
		"ERROR: .",
		"WARN: .")
}

func (s *Suite) Test_Logger_ShowSummary__explanations_available(c *check.C) {
	t := s.Init(c)

	logger := Logger{out: NewSeparatorWriter(&t.stdout)}
	logger.Logf(Error, "", "", ".", ".")
	logger.Explain(
		"Explanation.")

	logger.ShowSummary()

	t.CheckOutputLines(
		"ERROR: .",
		"1 error and 0 warnings found.",
		"(Run \"pkglint -e\" to show explanations.)")
}

func (s *Suite) Test_Logger_ShowSummary__explanations_available_in_explain_mode(c *check.C) {
	t := s.Init(c)

	logger := Logger{out: NewSeparatorWriter(&t.stdout)}
	logger.Logf(Error, "", "", ".", ".")
	logger.Explain(
		"Explanation.")

	// Since the --explain option is already given, it need not be advertised.
	logger.Opts.Explain = true

	logger.ShowSummary()

	t.CheckOutputLines(
		"ERROR: .",
		"1 error and 0 warnings found.")
}

func (s *Suite) Test_Logger_ShowSummary__autofix_available(c *check.C) {
	t := s.Init(c)

	logger := Logger{out: NewSeparatorWriter(&t.stdout)}
	logger.autofixAvailable = true // See SaveAutofixChanges

	logger.ShowSummary()

	t.CheckOutputLines(
		"Looks fine.",
		"(Run \"pkglint -fs\" to show what can be fixed automatically.)",
		"(Run \"pkglint -F\" to automatically fix some issues.)")
}

func (s *Suite) Test_Logger_ShowSummary__autofix_available_with_show_autofix_option(c *check.C) {
	t := s.Init(c)

	logger := Logger{out: NewSeparatorWriter(&t.stdout)}
	logger.autofixAvailable = true // See SaveAutofixChanges
	logger.Opts.ShowAutofix = true

	logger.ShowSummary()

	// Since the --show-autofix option is already given, it need not be advertised.
	// But the --autofix option is not given, therefore mention it.
	t.CheckOutputLines(
		"Looks fine.",
		"(Run \"pkglint -F\" to automatically fix some issues.)")
}

func (s *Suite) Test_Logger_ShowSummary__autofix_available_with_autofix_option(c *check.C) {
	t := s.Init(c)

	logger := Logger{out: NewSeparatorWriter(&t.stdout)}
	logger.autofixAvailable = true // See SaveAutofixChanges
	logger.Opts.Autofix = true

	logger.ShowSummary()

	// Since the --autofix option is already given, it need not be advertised.
	// Mentioning the --show-autofix option would be pointless here since the
	// usual path goes from default mode via --show-autofix to --autofix.
	// The usual "x warnings" would also be misleading since the warnings have just
	// been fixed by the autofix feature. Therefore the output is completely empty.
	t.CheckOutputEmpty()
}

// In rare cases, the explanations for the same warning may differ
// when they appear in different contexts. In such a case, if the
// warning is suppressed, the explanation must not appear on its own.
//
// An example of this was (until November 2018) DESTDIR in the check
// for absolute pathnames.
func (s *Suite) Test_Logger_Logf__duplicate_messages(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--explain")
	G.Logger.Opts.LogVerbose = false
	line := t.NewLine("README.txt", 123, "text")

	// Is logged because it is the first appearance of this warning.
	line.Warnf("The warning.")
	line.Explain("Explanation 1")

	// Is suppressed because the warning is the same as above and LogVerbose
	// has been set to false for this test.
	line.Warnf("The warning.")
	line.Explain("Explanation 2")

	t.CheckOutputLines(
		"WARN: README.txt:123: The warning.",
		"",
		"\tExplanation 1",
		"")
}

func (s *Suite) Test_Logger_Logf__duplicate_explanations(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--explain")
	line := t.NewLine("README.txt", 123, "text")

	// In rare cases, different diagnostics may have the same explanation.
	line.Warnf("Warning 1.")
	line.Explain("Explanation")
	line.Warnf("Warning 2.")
	line.Explain("Explanation") // Is suppressed.

	t.CheckOutputLines(
		"WARN: README.txt:123: Warning 1.",
		"",
		"\tExplanation",
		"",
		"WARN: README.txt:123: Warning 2.")
}

func (s *Suite) Test_Logger_Logf__gcc_format(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--gcc-output-format")

	logger := &G.Logger
	logger.Logf(Note, "filename", "123", "Both filename and line number.", "Both filename and line number.")
	logger.Logf(Note, "", "123", "No filename, only line number.", "No filename, only line number.")
	logger.Logf(Note, "filename", "", "Filename without line number.", "Filename without line number.")
	logger.Logf(Note, "", "", "Neither filename nor line number.", "Neither filename nor line number.")

	t.CheckOutputLines(
		"filename:123: note: Both filename and line number.",
		"note: No filename, only line number.",
		"filename: note: Filename without line number.",
		"note: Neither filename nor line number.")
}

func (s *Suite) Test_Logger_Logf__traditional_format(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--gcc-output-format=no")

	logger := &G.Logger
	logger.Logf(Note, "filename", "123", "Both filename and line number.", "Both filename and line number.")
	logger.Logf(Note, "", "123", "No filename, only line number.", "No filename, only line number.")
	logger.Logf(Note, "filename", "", "Filename without line number.", "Filename without line number.")
	logger.Logf(Note, "", "", "Neither filename nor line number.", "Neither filename nor line number.")

	t.CheckOutputLines(
		"NOTE: filename:123: Both filename and line number.",
		"NOTE: No filename, only line number.",
		"NOTE: filename: Filename without line number.",
		"NOTE: Neither filename nor line number.")
}

func (s *Suite) Test_Logger_Errorf__gcc_format(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--gcc-output-format")

	G.Logger.Errorf("filename", "Cannot be opened for %s.", "reading")

	t.CheckOutputLines(
		"filename: error: Cannot be opened for reading.")
}

// Ensures that pkglint never destroys the terminal emulator by sending unintended escape sequences.
func (s *Suite) Test_Logger_Logf__strange_characters(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--gcc-output-format", "--source", "--explain")

	G.Logger.Logf(Note, "filename", "123", "Format.", "Unicode \U0001F645 and ANSI \x1B are never logged.")
	G.Logger.Explain(
		"Even a \u0007 in the explanation is silent.")

	t.CheckOutputLines(
		"filename:123: note: Unicode <U+1F645> and ANSI <U+001B> are never logged.",
		"",
		"\tEven a <U+0007> in the explanation is silent.",
		"")
}

func (s *Suite) Test_Logger_Diag__show_source(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--show-autofix", "--source")
	line := t.NewLine("filename", 123, "text")

	fix := line.Autofix()
	fix.Notef("Diagnostics can show the differences in autofix mode.")
	fix.InsertBefore("new line before")
	fix.InsertAfter("new line after")
	fix.Apply()

	t.CheckOutputLines(
		"NOTE: filename:123: Diagnostics can show the differences in autofix mode.",
		"AUTOFIX: filename:123: Inserting a line \"new line before\" before this line.",
		"AUTOFIX: filename:123: Inserting a line \"new line after\" after this line.",
		"+\tnew line before",
		">\ttext",
		"+\tnew line after")
}

func (s *Suite) Test_Logger_Diag__show_source_with_whole_file(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--source")
	line := NewLineWhole("filename")

	line.Warnf("This line does not have any RawLine attached.")

	t.CheckOutputLines(
		"WARN: filename: This line does not have any RawLine attached.")
}

// Ensures that when two packages produce a warning in the same file, both the
// warning and the corresponding source code are logged only once.
func (s *Suite) Test_Logger_Diag__source_duplicates(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("category/dependency/patches/patch-aa",
		CvsID,
		"",
		"--- old file",
		"+++ new file",
		"@@ -1,1 +1,1 @@",
		"-old line",
		"+new line")
	t.SetUpPackage("category/package1",
		"PATCHDIR=\t../../category/dependency/patches")
	t.SetUpPackage("category/package2",
		"PATCHDIR=\t../../category/dependency/patches")

	t.Main("--source", "-Wall", t.File("category/package1"), t.File("category/package2"))

	t.CheckOutputLines(
		"ERROR: ~/category/package1/distinfo: "+
			"Patch \"../../category/dependency/patches/patch-aa\" is not recorded. "+
			"Run \""+confMake+" makepatchsum\".",
		"",
		">\t--- old file",
		"ERROR: ~/category/dependency/patches/patch-aa:3: "+
			"Each patch must be documented.",
		"",
		"ERROR: ~/category/package2/distinfo: "+
			"Patch \"../../category/dependency/patches/patch-aa\" is not recorded. "+
			"Run \""+confMake+" makepatchsum\".",
		"",
		"3 errors and 0 warnings found.",
		"(Run \"pkglint -e\" to show explanations.)")
}

func (s *Suite) Test_Logger_shallBeLogged(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine( /* none */ )

	c.Check(G.Logger.shallBeLogged("Options should not contain whitespace."), equals, true)

	t.SetUpCommandLine("--only", "whitespace")

	c.Check(G.Logger.shallBeLogged("Options should not contain whitespace."), equals, true)
	c.Check(G.Logger.shallBeLogged("Options should not contain space."), equals, false)

	t.SetUpCommandLine( /* none again */ )

	c.Check(G.Logger.shallBeLogged("Options should not contain whitespace."), equals, true)
	c.Check(G.Logger.shallBeLogged("Options should not contain space."), equals, true)
}

// Even if verbose logging is disabled, the "Replacing" diagnostics
// must not be filtered for duplicates since each of them modifies the line.
func (s *Suite) Test_Logger_Logf__duplicate_autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--explain", "--autofix")
	G.Logger.Opts.LogVerbose = false // See SetUpTest
	line := t.NewLine("README.txt", 123, "text")

	fix := line.Autofix()
	fix.Warnf("T should always be uppercase.")
	fix.ReplaceRegex(`t`, "T", -1)
	fix.Apply()

	t.CheckOutputLines(
		"AUTOFIX: README.txt:123: Replacing \"t\" with \"T\".",
		"AUTOFIX: README.txt:123: Replacing \"t\" with \"T\".")
}

func (s *Suite) Test_Logger_Logf__panic(c *check.C) {
	t := s.Init(c)

	t.ExpectPanic(
		func() { G.Logger.Logf(Error, "filename", "13", "No period", "No period") },
		"Pkglint internal error: Diagnostic format \"No period\" must end in a period.")
}

func (s *Suite) Test_SeparatorWriter(c *check.C) {
	var sb strings.Builder
	wr := NewSeparatorWriter(&sb)

	wr.WriteLine("a")
	wr.WriteLine("b")

	c.Check(sb.String(), equals, "a\nb\n")

	wr.Separate()

	c.Check(sb.String(), equals, "a\nb\n")

	wr.WriteLine("c")

	c.Check(sb.String(), equals, "a\nb\n\nc\n")
}

func (s *Suite) Test_SeparatorWriter_Flush(c *check.C) {
	var sb strings.Builder
	wr := NewSeparatorWriter(&sb)

	wr.Write("a")
	wr.Write("b")

	c.Check(sb.String(), equals, "")

	wr.Flush()

	c.Check(sb.String(), equals, "ab")

	wr.Separate()

	// The current line is terminated immediately by the above Separate(),
	// but the empty line for separating two paragraphs is kept in mind.
	// It will be added later, before the next non-newline character.
	c.Check(sb.String(), equals, "ab\n")

	wr.Write("c")
	wr.Flush()

	c.Check(sb.String(), equals, "ab\n\nc")
}

func (s *Suite) Test_SeparatorWriter_Separate(c *check.C) {
	var sb strings.Builder
	wr := NewSeparatorWriter(&sb)

	wr.WriteLine("a")
	wr.Separate()

	c.Check(sb.String(), equals, "a\n")

	// The call to Separate had requested an empty line. That empty line
	// can either be given explicitly (like here), or it will be written
	// implicitly before the next non-newline character.
	wr.WriteLine("")
	wr.Separate()

	c.Check(sb.String(), equals, "a\n\n")

	wr.WriteLine("c")
	wr.Separate()

	c.Check(sb.String(), equals, "a\n\nc\n")
}
