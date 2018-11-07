package main

import "path"

type Lines = *LinesImpl

type LinesImpl struct {
	FileName string
	BaseName string
	Lines    []Line
}

func NewLines(fileName string, lines []Line) Lines {
	return &LinesImpl{fileName, path.Base(fileName), lines}
}

func (ls *LinesImpl) Len() int { return len(ls.Lines) }

func (ls *LinesImpl) LastLine() Line { return ls.Lines[ls.Len()-1] }

func (ls *LinesImpl) EOFLine() Line { return NewLine(ls.FileName, -1, "", nil) }

func (ls *LinesImpl) Errorf(format string, args ...interface{}) {
	NewLineWhole(ls.FileName).Errorf(format, args...)
}

func (ls *LinesImpl) Warnf(format string, args ...interface{}) {
	NewLineWhole(ls.FileName).Warnf(format, args...)
}

func (ls *LinesImpl) SaveAutofixChanges() {
	SaveAutofixChanges(ls)
}
