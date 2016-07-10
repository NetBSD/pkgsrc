package main

func (list *MkShList) AddSemicolon() *MkShList  { return list.AddSeparator(sepSemicolon) }
func (list *MkShList) AddBackground() *MkShList { return list.AddSeparator(sepBackground) }
func (list *MkShList) AddNewline() *MkShList    { return list.AddSeparator(sepNewline) }
