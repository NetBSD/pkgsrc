package pkglint

func (list *MkShList) AddSemicolon() *MkShList  { return list.AddSeparator(sepSemicolon) }
func (list *MkShList) AddBackground() *MkShList { return list.AddSeparator(sepBackground) }
func (list *MkShList) AddNewline() *MkShList    { return list.AddSeparator(sepNewline) }

// AddCommand adds a command directly to a list of commands,
// creating all the intermediate nodes for the syntactic representation.
//
// As soon as that representation is replaced with a semantic representation,
// this method should no longer be necessary.
func (list *MkShList) AddCommand(command *MkShCommand) *MkShList {
	pipeline := NewMkShPipeline(false, []*MkShCommand{command})
	andOr := NewMkShAndOr(pipeline)
	return list.AddAndOr(andOr)
}
