//line licenses.y:2
package licenses

import __yyfmt__ "fmt"

//line licenses.y:2
//line licenses.y:8
type liyySymType struct {
	yys  int
	Node *Condition
}

const ltNAME = 57346
const ltAND = 57347
const ltOR = 57348
const ltOPEN = 57349
const ltCLOSE = 57350

var liyyToknames = [...]string{
	"$end",
	"error",
	"$unk",
	"ltNAME",
	"ltAND",
	"ltOR",
	"ltOPEN",
	"ltCLOSE",
}
var liyyStatenames = [...]string{}

const liyyEofCode = 1
const liyyErrCode = 2
const liyyInitialStackSize = 16

//line yacctab:1
var liyyExca = [...]int{
	-1, 1,
	1, -1,
	-2, 0,
}

const liyyNprod = 7
const liyyPrivate = 57344

var liyyTokenNames []string
var liyyStates []string

const liyyLast = 15

var liyyAct = [...]int{

	6, 7, 3, 11, 4, 1, 0, 5, 2, 9,
	10, 6, 7, 0, 8,
}
var liyyPact = [...]int{

	0, -1000, 6, -1000, -1000, 0, 0, 0, -5, -1000,
	-1000, -1000,
}
var liyyPgo = [...]int{

	0, 5, 8, 2,
}
var liyyR1 = [...]int{

	0, 1, 2, 2, 2, 3, 3,
}
var liyyR2 = [...]int{

	0, 1, 1, 3, 3, 1, 3,
}
var liyyChk = [...]int{

	-1000, -1, -2, -3, 4, 7, 5, 6, -2, -3,
	-3, 8,
}
var liyyDef = [...]int{

	0, -2, 1, 2, 5, 0, 0, 0, 0, 3,
	4, 6,
}
var liyyTok1 = [...]int{

	1,
}
var liyyTok2 = [...]int{

	2, 3, 4, 5, 6, 7, 8,
}
var liyyTok3 = [...]int{
	0,
}

var liyyErrorMessages = [...]struct {
	state int
	token int
	msg   string
}{}

//line yaccpar:1

/*	parser for yacc output	*/

var (
	liyyDebug        = 0
	liyyErrorVerbose = false
)

type liyyLexer interface {
	Lex(lval *liyySymType) int
	Error(s string)
}

type liyyParser interface {
	Parse(liyyLexer) int
	Lookahead() int
}

type liyyParserImpl struct {
	lval  liyySymType
	stack [liyyInitialStackSize]liyySymType
	char  int
}

func (p *liyyParserImpl) Lookahead() int {
	return p.char
}

func liyyNewParser() liyyParser {
	return &liyyParserImpl{}
}

const liyyFlag = -1000

func liyyTokname(c int) string {
	if c >= 1 && c-1 < len(liyyToknames) {
		if liyyToknames[c-1] != "" {
			return liyyToknames[c-1]
		}
	}
	return __yyfmt__.Sprintf("tok-%v", c)
}

func liyyStatname(s int) string {
	if s >= 0 && s < len(liyyStatenames) {
		if liyyStatenames[s] != "" {
			return liyyStatenames[s]
		}
	}
	return __yyfmt__.Sprintf("state-%v", s)
}

func liyyErrorMessage(state, lookAhead int) string {
	const TOKSTART = 4

	if !liyyErrorVerbose {
		return "syntax error"
	}

	for _, e := range liyyErrorMessages {
		if e.state == state && e.token == lookAhead {
			return "syntax error: " + e.msg
		}
	}

	res := "syntax error: unexpected " + liyyTokname(lookAhead)

	// To match Bison, suggest at most four expected tokens.
	expected := make([]int, 0, 4)

	// Look for shiftable tokens.
	base := liyyPact[state]
	for tok := TOKSTART; tok-1 < len(liyyToknames); tok++ {
		if n := base + tok; n >= 0 && n < liyyLast && liyyChk[liyyAct[n]] == tok {
			if len(expected) == cap(expected) {
				return res
			}
			expected = append(expected, tok)
		}
	}

	if liyyDef[state] == -2 {
		i := 0
		for liyyExca[i] != -1 || liyyExca[i+1] != state {
			i += 2
		}

		// Look for tokens that we accept or reduce.
		for i += 2; liyyExca[i] >= 0; i += 2 {
			tok := liyyExca[i]
			if tok < TOKSTART || liyyExca[i+1] == 0 {
				continue
			}
			if len(expected) == cap(expected) {
				return res
			}
			expected = append(expected, tok)
		}

		// If the default action is to accept or reduce, give up.
		if liyyExca[i+1] != 0 {
			return res
		}
	}

	for i, tok := range expected {
		if i == 0 {
			res += ", expecting "
		} else {
			res += " or "
		}
		res += liyyTokname(tok)
	}
	return res
}

func liyylex1(lex liyyLexer, lval *liyySymType) (char, token int) {
	token = 0
	char = lex.Lex(lval)
	if char <= 0 {
		token = liyyTok1[0]
		goto out
	}
	if char < len(liyyTok1) {
		token = liyyTok1[char]
		goto out
	}
	if char >= liyyPrivate {
		if char < liyyPrivate+len(liyyTok2) {
			token = liyyTok2[char-liyyPrivate]
			goto out
		}
	}
	for i := 0; i < len(liyyTok3); i += 2 {
		token = liyyTok3[i+0]
		if token == char {
			token = liyyTok3[i+1]
			goto out
		}
	}

out:
	if token == 0 {
		token = liyyTok2[1] /* unknown char */
	}
	if liyyDebug >= 3 {
		__yyfmt__.Printf("lex %s(%d)\n", liyyTokname(token), uint(char))
	}
	return char, token
}

func liyyParse(liyylex liyyLexer) int {
	return liyyNewParser().Parse(liyylex)
}

func (liyyrcvr *liyyParserImpl) Parse(liyylex liyyLexer) int {
	var liyyn int
	var liyyVAL liyySymType
	var liyyDollar []liyySymType
	_ = liyyDollar // silence set and not used
	liyyS := liyyrcvr.stack[:]

	Nerrs := 0   /* number of errors */
	Errflag := 0 /* error recovery flag */
	liyystate := 0
	liyyrcvr.char = -1
	liyytoken := -1 // liyyrcvr.char translated into internal numbering
	defer func() {
		// Make sure we report no lookahead when not parsing.
		liyystate = -1
		liyyrcvr.char = -1
		liyytoken = -1
	}()
	liyyp := -1
	goto liyystack

ret0:
	return 0

ret1:
	return 1

liyystack:
	/* put a state and value onto the stack */
	if liyyDebug >= 4 {
		__yyfmt__.Printf("char %v in %v\n", liyyTokname(liyytoken), liyyStatname(liyystate))
	}

	liyyp++
	if liyyp >= len(liyyS) {
		nyys := make([]liyySymType, len(liyyS)*2)
		copy(nyys, liyyS)
		liyyS = nyys
	}
	liyyS[liyyp] = liyyVAL
	liyyS[liyyp].yys = liyystate

liyynewstate:
	liyyn = liyyPact[liyystate]
	if liyyn <= liyyFlag {
		goto liyydefault /* simple state */
	}
	if liyyrcvr.char < 0 {
		liyyrcvr.char, liyytoken = liyylex1(liyylex, &liyyrcvr.lval)
	}
	liyyn += liyytoken
	if liyyn < 0 || liyyn >= liyyLast {
		goto liyydefault
	}
	liyyn = liyyAct[liyyn]
	if liyyChk[liyyn] == liyytoken { /* valid shift */
		liyyrcvr.char = -1
		liyytoken = -1
		liyyVAL = liyyrcvr.lval
		liyystate = liyyn
		if Errflag > 0 {
			Errflag--
		}
		goto liyystack
	}

liyydefault:
	/* default state action */
	liyyn = liyyDef[liyystate]
	if liyyn == -2 {
		if liyyrcvr.char < 0 {
			liyyrcvr.char, liyytoken = liyylex1(liyylex, &liyyrcvr.lval)
		}

		/* look through exception table */
		xi := 0
		for {
			if liyyExca[xi+0] == -1 && liyyExca[xi+1] == liyystate {
				break
			}
			xi += 2
		}
		for xi += 2; ; xi += 2 {
			liyyn = liyyExca[xi+0]
			if liyyn < 0 || liyyn == liyytoken {
				break
			}
		}
		liyyn = liyyExca[xi+1]
		if liyyn < 0 {
			goto ret0
		}
	}
	if liyyn == 0 {
		/* error ... attempt to resume parsing */
		switch Errflag {
		case 0: /* brand new error */
			liyylex.Error(liyyErrorMessage(liyystate, liyytoken))
			Nerrs++
			if liyyDebug >= 1 {
				__yyfmt__.Printf("%s", liyyStatname(liyystate))
				__yyfmt__.Printf(" saw %s\n", liyyTokname(liyytoken))
			}
			fallthrough

		case 1, 2: /* incompletely recovered error ... try again */
			Errflag = 3

			/* find a state where "error" is a legal shift action */
			for liyyp >= 0 {
				liyyn = liyyPact[liyyS[liyyp].yys] + liyyErrCode
				if liyyn >= 0 && liyyn < liyyLast {
					liyystate = liyyAct[liyyn] /* simulate a shift of "error" */
					if liyyChk[liyystate] == liyyErrCode {
						goto liyystack
					}
				}

				/* the current p has no shift on "error", pop stack */
				if liyyDebug >= 2 {
					__yyfmt__.Printf("error recovery pops state %d\n", liyyS[liyyp].yys)
				}
				liyyp--
			}
			/* there is no state on the stack with an error shift ... abort */
			goto ret1

		case 3: /* no shift yet; clobber input char */
			if liyyDebug >= 2 {
				__yyfmt__.Printf("error recovery discards %s\n", liyyTokname(liyytoken))
			}
			if liyytoken == liyyEofCode {
				goto ret1
			}
			liyyrcvr.char = -1
			liyytoken = -1
			goto liyynewstate /* try again in the same state */
		}
	}

	/* reduction by production liyyn */
	if liyyDebug >= 2 {
		__yyfmt__.Printf("reduce %v in:\n\t%v\n", liyyn, liyyStatname(liyystate))
	}

	liyynt := liyyn
	liyypt := liyyp
	_ = liyypt // guard against "declared and not used"

	liyyp -= liyyR2[liyyn]
	// liyyp is now the index of $0. Perform the default action. Iff the
	// reduced production is ε, $1 is possibly out of range.
	if liyyp+1 >= len(liyyS) {
		nyys := make([]liyySymType, len(liyyS)*2)
		copy(nyys, liyyS)
		liyyS = nyys
	}
	liyyVAL = liyyS[liyyp+1]

	/* consult goto table to find next state */
	liyyn = liyyR1[liyyn]
	liyyg := liyyPgo[liyyn]
	liyyj := liyyg + liyyS[liyyp].yys + 1

	if liyyj >= liyyLast {
		liyystate = liyyAct[liyyg]
	} else {
		liyystate = liyyAct[liyyj]
		if liyyChk[liyystate] != -liyyn {
			liyystate = liyyAct[liyyg]
		}
	}
	// dummy call; replaced with literal code
	switch liyynt {

	case 1:
		liyyDollar = liyyS[liyypt-1 : liyypt+1]
		//line licenses.y:16
		{
			liyylex.(*licenseLexer).result = liyyVAL.Node
		}
	case 2:
		liyyDollar = liyyS[liyypt-1 : liyypt+1]
		//line licenses.y:20
		{
			liyyVAL.Node = &Condition{Children: []*Condition{liyyDollar[1].Node}}
		}
	case 3:
		liyyDollar = liyyS[liyypt-3 : liyypt+1]
		//line licenses.y:23
		{
			liyyVAL.Node.Children = append(liyyVAL.Node.Children, liyyDollar[3].Node)
			liyyVAL.Node.And = true
		}
	case 4:
		liyyDollar = liyyS[liyypt-3 : liyypt+1]
		//line licenses.y:27
		{
			liyyVAL.Node.Children = append(liyyVAL.Node.Children, liyyDollar[3].Node)
			liyyVAL.Node.Or = true
		}
	case 5:
		liyyDollar = liyyS[liyypt-1 : liyypt+1]
		//line licenses.y:32
		{
			liyyVAL.Node = liyyDollar[1].Node
		}
	case 6:
		liyyDollar = liyyS[liyypt-3 : liyypt+1]
		//line licenses.y:35
		{
			liyyVAL.Node = &Condition{Paren: liyyDollar[2].Node}
		}
	}
	goto liyystack /* stack new state and value */
}
