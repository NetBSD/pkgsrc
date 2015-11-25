package main

// High-level iterating through lines and checking them.
type Expecter struct {
	lines []*Line
	index int
}

func NewExpecter(lines []*Line) *Expecter {
	return &Expecter{lines, 0}
}

func (ctx *Expecter) currentLine() *Line {
	if ctx.index < len(ctx.lines) {
		return ctx.lines[ctx.index]
	}

	return NewLine(ctx.lines[0].fname, "EOF", "", nil) // dummy
}

func (ctx *Expecter) previousLine() *Line {
	return ctx.lines[ctx.index-1]
}

func (ctx *Expecter) eof() bool {
	return !(ctx.index < len(ctx.lines))
}
func (ctx *Expecter) advance() {
	ctx.index++
}

func (ctx *Expecter) advanceIfMatches(re string) []string {
	defer tracecall("Expecter.advanceIfMatches", ctx.currentLine().text, re)()

	if ctx.index < len(ctx.lines) {
		if m := match(ctx.lines[ctx.index].text, re); m != nil {
			ctx.index++
			return m
		}
	}
	return nil
}

func (ctx *Expecter) expectEmptyLine() bool {
	if ctx.advanceIfMatches(`^$`) != nil {
		return true
	}

	_ = G.opts.WarnSpace && ctx.currentLine().notef("Empty line expected.")
	return false
}

func (ctx *Expecter) expectText(text string) bool {
	if ctx.index < len(ctx.lines) && ctx.lines[ctx.index].text == text {
		ctx.index++
		return true
	}

	ctx.currentLine().warnf("This line should contain the following text: %s", text)
	return false
}
