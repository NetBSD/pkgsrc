package main

func checklinesDescr(lines []*Line) {
	defer tracecall("checklinesDescr", lines[0].fname)()

	for _, line := range lines {
		checklineLength(line, 80)
		checklineTrailingWhitespace(line)
		checklineValidCharacters(line, `[\t -~]`)
		if contains(line.text, "${") {
			line.notef("Variables are not expanded in the DESCR file.")
		}
	}
	checklinesTrailingEmptyLines(lines)

	if maxlines := 24; len(lines) > maxlines {
		line := lines[maxlines]

		line.warnf("File too long (should be no more than %d lines).", maxlines)
		line.explain(
			"A common terminal size is 80x25 characters. The DESCR file should",
			"fit on one screen. It is also intended to give a _brief_ summary",
			"about the package's contents.")
	}

	saveAutofixChanges(lines)
}
