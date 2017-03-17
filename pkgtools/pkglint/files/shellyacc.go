//line shell.y:2
package main

import __yyfmt__ "fmt"

//line shell.y:2
//line shell.y:18
type shyySymType struct {
	yys             int
	IONum           int
	List            *MkShList
	AndOr           *MkShAndOr
	Pipeline        *MkShPipeline
	Command         *MkShCommand
	CompoundCommand *MkShCompoundCommand
	Separator       MkShSeparator
	Simple          *MkShSimpleCommand
	FuncDef         *MkShFunctionDefinition
	For             *MkShForClause
	If              *MkShIfClause
	Case            *MkShCaseClause
	CaseItem        *MkShCaseItem
	Loop            *MkShLoopClause
	Words           []*ShToken
	Word            *ShToken
	Redirections    []*MkShRedirection
	Redirection     *MkShRedirection
}

const tkWORD = 57346
const tkASSIGNMENT_WORD = 57347
const tkNEWLINE = 57348
const tkIO_NUMBER = 57349
const tkBACKGROUND = 57350
const tkPIPE = 57351
const tkSEMI = 57352
const tkAND = 57353
const tkOR = 57354
const tkSEMISEMI = 57355
const tkLT = 57356
const tkGT = 57357
const tkLTLT = 57358
const tkGTGT = 57359
const tkLTAND = 57360
const tkGTAND = 57361
const tkLTGT = 57362
const tkLTLTDASH = 57363
const tkGTPIPE = 57364
const tkIF = 57365
const tkTHEN = 57366
const tkELSE = 57367
const tkELIF = 57368
const tkFI = 57369
const tkDO = 57370
const tkDONE = 57371
const tkCASE = 57372
const tkESAC = 57373
const tkWHILE = 57374
const tkUNTIL = 57375
const tkFOR = 57376
const tkLPAREN = 57377
const tkRPAREN = 57378
const tkLBRACE = 57379
const tkRBRACE = 57380
const tkEXCLAM = 57381
const tkIN = 57382

var shyyToknames = [...]string{
	"$end",
	"error",
	"$unk",
	"tkWORD",
	"tkASSIGNMENT_WORD",
	"tkNEWLINE",
	"tkIO_NUMBER",
	"tkBACKGROUND",
	"tkPIPE",
	"tkSEMI",
	"tkAND",
	"tkOR",
	"tkSEMISEMI",
	"tkLT",
	"tkGT",
	"tkLTLT",
	"tkGTGT",
	"tkLTAND",
	"tkGTAND",
	"tkLTGT",
	"tkLTLTDASH",
	"tkGTPIPE",
	"tkIF",
	"tkTHEN",
	"tkELSE",
	"tkELIF",
	"tkFI",
	"tkDO",
	"tkDONE",
	"tkCASE",
	"tkESAC",
	"tkWHILE",
	"tkUNTIL",
	"tkFOR",
	"tkLPAREN",
	"tkRPAREN",
	"tkLBRACE",
	"tkRBRACE",
	"tkEXCLAM",
	"tkIN",
}
var shyyStatenames = [...]string{}

const shyyEofCode = 1
const shyyErrCode = 2
const shyyInitialStackSize = 16

//line yacctab:1
var shyyExca = [...]int{
	-1, 0,
	1, 3,
	-2, 93,
	-1, 1,
	1, -1,
	-2, 0,
	-1, 154,
	31, 93,
	-2, 24,
	-1, 162,
	31, 92,
	-2, 97,
	-1, 166,
	31, 44,
	-2, 96,
}

const shyyNprod = 100
const shyyPrivate = 57344

var shyyTokenNames []string
var shyyStates []string

const shyyLast = 342

var shyyAct = [...]int{

	4, 121, 7, 135, 3, 5, 138, 134, 48, 25,
	102, 14, 12, 49, 115, 64, 8, 76, 103, 84,
	111, 97, 98, 9, 57, 57, 60, 65, 94, 147,
	110, 125, 67, 68, 31, 152, 71, 72, 73, 140,
	152, 30, 103, 32, 33, 29, 28, 36, 27, 88,
	139, 139, 153, 89, 90, 91, 78, 79, 80, 81,
	82, 83, 157, 34, 87, 86, 92, 151, 92, 65,
	99, 100, 101, 156, 95, 93, 66, 144, 133, 35,
	46, 137, 137, 75, 104, 54, 37, 39, 44, 41,
	38, 40, 42, 45, 43, 108, 124, 123, 122, 74,
	124, 123, 6, 95, 107, 56, 112, 63, 113, 158,
	109, 139, 120, 105, 106, 52, 53, 85, 129, 130,
	114, 58, 10, 6, 77, 50, 126, 51, 141, 142,
	128, 127, 118, 70, 55, 145, 117, 148, 143, 146,
	119, 149, 118, 69, 150, 59, 117, 136, 116, 24,
	23, 154, 132, 131, 21, 160, 163, 164, 159, 22,
	162, 165, 166, 161, 17, 26, 20, 35, 15, 16,
	13, 47, 19, 155, 37, 39, 44, 41, 38, 40,
	42, 45, 43, 31, 18, 2, 1, 0, 0, 0,
	30, 0, 32, 33, 29, 28, 0, 27, 0, 11,
	17, 26, 0, 35, 0, 0, 0, 0, 0, 0,
	37, 39, 44, 41, 38, 40, 42, 45, 43, 31,
	0, 0, 0, 0, 0, 0, 30, 0, 32, 33,
	29, 28, 0, 27, 0, 11, 17, 26, 0, 35,
	0, 0, 0, 0, 0, 0, 37, 39, 44, 41,
	38, 40, 42, 45, 43, 31, 0, 0, 0, 0,
	62, 61, 30, 35, 32, 33, 29, 28, 0, 27,
	37, 39, 44, 41, 38, 40, 42, 45, 43, 96,
	0, 0, 35, 0, 0, 0, 0, 0, 0, 37,
	39, 44, 41, 38, 40, 42, 45, 43, 66, 0,
	0, 35, 0, 0, 0, 0, 0, 0, 37, 39,
	44, 41, 38, 40, 42, 45, 43, 35, 0, 0,
	0, 0, 0, 0, 37, 39, 44, 41, 38, 40,
	42, 45, 43, 37, 39, 44, 41, 38, 40, 42,
	45, 43,
}
var shyyPact = [...]int{

	96, -1000, -1000, -1000, 196, 74, -1000, 117, 104, -1000,
	76, 232, -1000, -1000, 310, 310, 256, 72, -1000, -1000,
	-1000, -1000, -1000, -1000, -1000, -1000, -1000, 96, 96, 139,
	129, 96, 96, 96, -1000, 319, -1000, 120, 120, 120,
	120, 120, 120, 120, 113, 113, -1000, 196, 96, 74,
	-1000, -1000, 96, 96, 96, 76, 310, -1000, 310, 294,
	-1000, -1000, -1000, -8, 275, -1000, -1000, -17, -14, 96,
	96, 48, 14, 14, -1000, -1000, -1000, -1000, -1000, -1000,
	-1000, -1000, -1000, -1000, -1000, -1000, -1000, 104, -1000, 196,
	196, 232, -1000, 275, 96, -1000, -1000, -1000, -1000, -10,
	-20, 96, -1000, 96, -1000, -1000, -1000, -1000, 11, -1000,
	136, 96, 71, 2, -1000, 14, 126, 96, 96, -1000,
	47, 12, -1000, 96, 96, -1000, -1000, 14, -1000, -1000,
	-1000, 46, -2, -1000, -1000, -1000, 96, 107, 31, -1000,
	-1000, 28, -1000, -1000, -1000, -1000, -1000, -1000, 160, 60,
	26, -1000, 105, 96, 117, 96, 96, -1000, -1000, 75,
	-1000, 96, 74, -1000, -1000, -1000, -1000,
}
var shyyPgo = [...]int{

	0, 186, 185, 4, 184, 172, 2, 10, 16, 23,
	122, 12, 11, 171, 8, 14, 170, 169, 15, 168,
	166, 159, 1, 154, 153, 152, 7, 3, 150, 149,
	148, 147, 6, 17, 145, 19, 105, 9, 63, 47,
	0, 5,
}
var shyyR1 = [...]int{

	0, 1, 2, 2, 8, 8, 8, 9, 9, 10,
	10, 11, 11, 11, 11, 11, 12, 12, 12, 12,
	12, 12, 12, 5, 3, 3, 6, 6, 20, 20,
	20, 30, 30, 23, 23, 23, 25, 25, 24, 24,
	31, 31, 27, 27, 27, 26, 26, 32, 32, 21,
	21, 22, 22, 22, 28, 29, 19, 4, 7, 16,
	16, 16, 16, 16, 34, 17, 17, 17, 17, 18,
	18, 18, 18, 36, 36, 37, 37, 37, 37, 38,
	38, 38, 38, 38, 38, 38, 33, 39, 39, 35,
	41, 41, 40, 40, 14, 14, 13, 13, 15, 15,
}
var shyyR2 = [...]int{

	0, 1, 1, 0, 1, 4, 4, 1, 2, 1,
	4, 1, 1, 2, 1, 2, 1, 1, 1, 1,
	1, 1, 1, 3, 2, 3, 1, 3, 4, 6,
	7, 1, 2, 7, 7, 6, 1, 2, 1, 2,
	3, 2, 2, 4, 5, 4, 4, 1, 3, 6,
	5, 4, 5, 2, 3, 3, 5, 3, 3, 3,
	2, 1, 2, 1, 1, 1, 1, 2, 2, 1,
	1, 2, 2, 1, 2, 1, 2, 1, 2, 2,
	2, 2, 2, 2, 2, 2, 1, 2, 2, 1,
	1, 2, 1, 0, 1, 1, 2, 1, 2, 2,
}
var shyyChk = [...]int{

	-1000, -1, -2, -3, -40, -41, 6, -6, -8, -9,
	-10, 39, -11, -16, -12, -19, -17, 4, -4, -5,
	-20, -23, -21, -28, -29, -37, 5, 37, 35, 34,
	30, 23, 32, 33, -38, 7, -39, 14, 18, 15,
	19, 17, 20, 22, 16, 21, 6, -13, -14, -41,
	8, 10, 11, 12, 9, -10, -36, -37, -36, -34,
	-37, 5, 4, 35, -18, -37, 4, -3, -3, 4,
	4, -3, -3, -3, -38, -39, -33, 4, -33, -33,
	-33, -33, -33, -33, -35, 4, -35, -8, -40, -40,
	-40, -40, -37, -18, 36, -37, 4, 38, 36, -40,
	-40, 24, -7, 28, -7, -9, -9, -11, -40, -7,
	40, 40, -3, -3, -12, -15, -30, 10, 6, 4,
	-40, -22, 27, 26, 25, 29, -7, -15, 4, -40,
	-40, -24, -25, 31, -26, -27, -31, 35, -32, 4,
	27, -3, -3, -7, 31, -27, -26, 31, -40, -3,
	-32, 36, 9, 24, -6, 13, 13, 36, 4, -3,
	-40, -14, -41, -40, -40, -22, -40,
}
var shyyDef = [...]int{

	-2, -2, 1, 2, 0, 92, 90, 24, 26, 4,
	7, 0, 9, 11, 12, 14, 61, 63, 16, 17,
	18, 19, 20, 21, 22, 65, 66, 93, 93, 0,
	0, 93, 93, 93, 75, 0, 77, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 91, 25, 93, 97,
	94, 95, 93, 93, 93, 8, 13, 73, 15, 60,
	67, 68, 64, 0, 62, 69, 70, 0, 0, 93,
	93, 0, 0, 0, 76, 78, 79, 86, 80, 81,
	82, 83, 84, 85, 87, 89, 88, 27, 96, 0,
	0, 0, 74, 59, 93, 71, 72, 57, 23, 0,
	0, 93, 54, 93, 55, 5, 6, 10, 0, 28,
	0, 93, 0, 0, 56, 0, 0, 93, 93, 31,
	0, 0, 50, 93, 93, 58, 29, 0, 32, 98,
	99, 0, 0, 35, 38, 36, 93, 0, 0, 47,
	49, 0, 53, 30, 33, 37, 39, 34, 42, 0,
	0, 41, 0, 93, -2, 93, 93, 40, 48, 51,
	43, 93, -2, 45, 46, 52, -2,
}
var shyyTok1 = [...]int{

	1,
}
var shyyTok2 = [...]int{

	2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
	12, 13, 14, 15, 16, 17, 18, 19, 20, 21,
	22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
	32, 33, 34, 35, 36, 37, 38, 39, 40,
}
var shyyTok3 = [...]int{
	0,
}

var shyyErrorMessages = [...]struct {
	state int
	token int
	msg   string
}{}

//line yaccpar:1

/*	parser for yacc output	*/

var (
	shyyDebug        = 0
	shyyErrorVerbose = false
)

type shyyLexer interface {
	Lex(lval *shyySymType) int
	Error(s string)
}

type shyyParser interface {
	Parse(shyyLexer) int
	Lookahead() int
}

type shyyParserImpl struct {
	lval  shyySymType
	stack [shyyInitialStackSize]shyySymType
	char  int
}

func (p *shyyParserImpl) Lookahead() int {
	return p.char
}

func shyyNewParser() shyyParser {
	return &shyyParserImpl{}
}

const shyyFlag = -1000

func shyyTokname(c int) string {
	if c >= 1 && c-1 < len(shyyToknames) {
		if shyyToknames[c-1] != "" {
			return shyyToknames[c-1]
		}
	}
	return __yyfmt__.Sprintf("tok-%v", c)
}

func shyyStatname(s int) string {
	if s >= 0 && s < len(shyyStatenames) {
		if shyyStatenames[s] != "" {
			return shyyStatenames[s]
		}
	}
	return __yyfmt__.Sprintf("state-%v", s)
}

func shyyErrorMessage(state, lookAhead int) string {
	const TOKSTART = 4

	if !shyyErrorVerbose {
		return "syntax error"
	}

	for _, e := range shyyErrorMessages {
		if e.state == state && e.token == lookAhead {
			return "syntax error: " + e.msg
		}
	}

	res := "syntax error: unexpected " + shyyTokname(lookAhead)

	// To match Bison, suggest at most four expected tokens.
	expected := make([]int, 0, 4)

	// Look for shiftable tokens.
	base := shyyPact[state]
	for tok := TOKSTART; tok-1 < len(shyyToknames); tok++ {
		if n := base + tok; n >= 0 && n < shyyLast && shyyChk[shyyAct[n]] == tok {
			if len(expected) == cap(expected) {
				return res
			}
			expected = append(expected, tok)
		}
	}

	if shyyDef[state] == -2 {
		i := 0
		for shyyExca[i] != -1 || shyyExca[i+1] != state {
			i += 2
		}

		// Look for tokens that we accept or reduce.
		for i += 2; shyyExca[i] >= 0; i += 2 {
			tok := shyyExca[i]
			if tok < TOKSTART || shyyExca[i+1] == 0 {
				continue
			}
			if len(expected) == cap(expected) {
				return res
			}
			expected = append(expected, tok)
		}

		// If the default action is to accept or reduce, give up.
		if shyyExca[i+1] != 0 {
			return res
		}
	}

	for i, tok := range expected {
		if i == 0 {
			res += ", expecting "
		} else {
			res += " or "
		}
		res += shyyTokname(tok)
	}
	return res
}

func shyylex1(lex shyyLexer, lval *shyySymType) (char, token int) {
	token = 0
	char = lex.Lex(lval)
	if char <= 0 {
		token = shyyTok1[0]
		goto out
	}
	if char < len(shyyTok1) {
		token = shyyTok1[char]
		goto out
	}
	if char >= shyyPrivate {
		if char < shyyPrivate+len(shyyTok2) {
			token = shyyTok2[char-shyyPrivate]
			goto out
		}
	}
	for i := 0; i < len(shyyTok3); i += 2 {
		token = shyyTok3[i+0]
		if token == char {
			token = shyyTok3[i+1]
			goto out
		}
	}

out:
	if token == 0 {
		token = shyyTok2[1] /* unknown char */
	}
	if shyyDebug >= 3 {
		__yyfmt__.Printf("lex %s(%d)\n", shyyTokname(token), uint(char))
	}
	return char, token
}

func shyyParse(shyylex shyyLexer) int {
	return shyyNewParser().Parse(shyylex)
}

func (shyyrcvr *shyyParserImpl) Parse(shyylex shyyLexer) int {
	var shyyn int
	var shyyVAL shyySymType
	var shyyDollar []shyySymType
	_ = shyyDollar // silence set and not used
	shyyS := shyyrcvr.stack[:]

	Nerrs := 0   /* number of errors */
	Errflag := 0 /* error recovery flag */
	shyystate := 0
	shyyrcvr.char = -1
	shyytoken := -1 // shyyrcvr.char translated into internal numbering
	defer func() {
		// Make sure we report no lookahead when not parsing.
		shyystate = -1
		shyyrcvr.char = -1
		shyytoken = -1
	}()
	shyyp := -1
	goto shyystack

ret0:
	return 0

ret1:
	return 1

shyystack:
	/* put a state and value onto the stack */
	if shyyDebug >= 4 {
		__yyfmt__.Printf("char %v in %v\n", shyyTokname(shyytoken), shyyStatname(shyystate))
	}

	shyyp++
	if shyyp >= len(shyyS) {
		nyys := make([]shyySymType, len(shyyS)*2)
		copy(nyys, shyyS)
		shyyS = nyys
	}
	shyyS[shyyp] = shyyVAL
	shyyS[shyyp].yys = shyystate

shyynewstate:
	shyyn = shyyPact[shyystate]
	if shyyn <= shyyFlag {
		goto shyydefault /* simple state */
	}
	if shyyrcvr.char < 0 {
		shyyrcvr.char, shyytoken = shyylex1(shyylex, &shyyrcvr.lval)
	}
	shyyn += shyytoken
	if shyyn < 0 || shyyn >= shyyLast {
		goto shyydefault
	}
	shyyn = shyyAct[shyyn]
	if shyyChk[shyyn] == shyytoken { /* valid shift */
		shyyrcvr.char = -1
		shyytoken = -1
		shyyVAL = shyyrcvr.lval
		shyystate = shyyn
		if Errflag > 0 {
			Errflag--
		}
		goto shyystack
	}

shyydefault:
	/* default state action */
	shyyn = shyyDef[shyystate]
	if shyyn == -2 {
		if shyyrcvr.char < 0 {
			shyyrcvr.char, shyytoken = shyylex1(shyylex, &shyyrcvr.lval)
		}

		/* look through exception table */
		xi := 0
		for {
			if shyyExca[xi+0] == -1 && shyyExca[xi+1] == shyystate {
				break
			}
			xi += 2
		}
		for xi += 2; ; xi += 2 {
			shyyn = shyyExca[xi+0]
			if shyyn < 0 || shyyn == shyytoken {
				break
			}
		}
		shyyn = shyyExca[xi+1]
		if shyyn < 0 {
			goto ret0
		}
	}
	if shyyn == 0 {
		/* error ... attempt to resume parsing */
		switch Errflag {
		case 0: /* brand new error */
			shyylex.Error(shyyErrorMessage(shyystate, shyytoken))
			Nerrs++
			if shyyDebug >= 1 {
				__yyfmt__.Printf("%s", shyyStatname(shyystate))
				__yyfmt__.Printf(" saw %s\n", shyyTokname(shyytoken))
			}
			fallthrough

		case 1, 2: /* incompletely recovered error ... try again */
			Errflag = 3

			/* find a state where "error" is a legal shift action */
			for shyyp >= 0 {
				shyyn = shyyPact[shyyS[shyyp].yys] + shyyErrCode
				if shyyn >= 0 && shyyn < shyyLast {
					shyystate = shyyAct[shyyn] /* simulate a shift of "error" */
					if shyyChk[shyystate] == shyyErrCode {
						goto shyystack
					}
				}

				/* the current p has no shift on "error", pop stack */
				if shyyDebug >= 2 {
					__yyfmt__.Printf("error recovery pops state %d\n", shyyS[shyyp].yys)
				}
				shyyp--
			}
			/* there is no state on the stack with an error shift ... abort */
			goto ret1

		case 3: /* no shift yet; clobber input char */
			if shyyDebug >= 2 {
				__yyfmt__.Printf("error recovery discards %s\n", shyyTokname(shyytoken))
			}
			if shyytoken == shyyEofCode {
				goto ret1
			}
			shyyrcvr.char = -1
			shyytoken = -1
			goto shyynewstate /* try again in the same state */
		}
	}

	/* reduction by production shyyn */
	if shyyDebug >= 2 {
		__yyfmt__.Printf("reduce %v in:\n\t%v\n", shyyn, shyyStatname(shyystate))
	}

	shyynt := shyyn
	shyypt := shyyp
	_ = shyypt // guard against "declared and not used"

	shyyp -= shyyR2[shyyn]
	// shyyp is now the index of $0. Perform the default action. Iff the
	// reduced production is ε, $1 is possibly out of range.
	if shyyp+1 >= len(shyyS) {
		nyys := make([]shyySymType, len(shyyS)*2)
		copy(nyys, shyyS)
		shyyS = nyys
	}
	shyyVAL = shyyS[shyyp+1]

	/* consult goto table to find next state */
	shyyn = shyyR1[shyyn]
	shyyg := shyyPgo[shyyn]
	shyyj := shyyg + shyyS[shyyp].yys + 1

	if shyyj >= shyyLast {
		shyystate = shyyAct[shyyg]
	} else {
		shyystate = shyyAct[shyyj]
		if shyyChk[shyystate] != -shyyn {
			shyystate = shyyAct[shyyg]
		}
	}
	// dummy call; replaced with literal code
	switch shyynt {

	case 1:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:59
		{
			shyylex.(*ShellLexer).result = shyyVAL.List
		}
	case 2:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:63
		{
			shyyVAL.List = shyyDollar[1].List
		}
	case 3:
		shyyDollar = shyyS[shyypt-0 : shyypt+1]
		//line shell.y:66
		{
			shyyVAL.List = &MkShList{}
		}
	case 4:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:70
		{
			shyyVAL.AndOr = NewMkShAndOr(shyyDollar[1].Pipeline)
		}
	case 5:
		shyyDollar = shyyS[shyypt-4 : shyypt+1]
		//line shell.y:73
		{
			shyyVAL.AndOr.Add("&&", shyyDollar[4].Pipeline)
		}
	case 6:
		shyyDollar = shyyS[shyypt-4 : shyypt+1]
		//line shell.y:76
		{
			shyyVAL.AndOr.Add("||", shyyDollar[4].Pipeline)
		}
	case 7:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:80
		{
			/* empty */
		}
	case 8:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:82
		{
			shyyVAL.Pipeline = shyyDollar[2].Pipeline
			shyyVAL.Pipeline.Negated = true
		}
	case 9:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:87
		{
			shyyVAL.Pipeline = NewMkShPipeline(false, shyyDollar[1].Command)
		}
	case 10:
		shyyDollar = shyyS[shyypt-4 : shyypt+1]
		//line shell.y:90
		{
			shyyVAL.Pipeline.Add(shyyDollar[4].Command)
		}
	case 11:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:94
		{
			shyyVAL.Command = &MkShCommand{Simple: shyyDollar[1].Simple}
		}
	case 12:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:97
		{
			shyyVAL.Command = &MkShCommand{Compound: shyyDollar[1].CompoundCommand}
		}
	case 13:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:100
		{
			shyyVAL.Command = &MkShCommand{Compound: shyyDollar[1].CompoundCommand, Redirects: shyyDollar[2].Redirections}
		}
	case 14:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:103
		{
			shyyVAL.Command = &MkShCommand{FuncDef: shyyDollar[1].FuncDef}
		}
	case 15:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:106
		{
			shyyVAL.Command = &MkShCommand{FuncDef: shyyDollar[1].FuncDef, Redirects: shyyDollar[2].Redirections}
		}
	case 16:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:110
		{
			shyyVAL.CompoundCommand = &MkShCompoundCommand{Brace: shyyDollar[1].List}
		}
	case 17:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:113
		{
			shyyVAL.CompoundCommand = &MkShCompoundCommand{Subshell: shyyDollar[1].List}
		}
	case 18:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:116
		{
			shyyVAL.CompoundCommand = &MkShCompoundCommand{For: shyyDollar[1].For}
		}
	case 19:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:119
		{
			shyyVAL.CompoundCommand = &MkShCompoundCommand{Case: shyyDollar[1].Case}
		}
	case 20:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:122
		{
			shyyVAL.CompoundCommand = &MkShCompoundCommand{If: shyyDollar[1].If}
		}
	case 21:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:125
		{
			shyyVAL.CompoundCommand = &MkShCompoundCommand{Loop: shyyDollar[1].Loop}
		}
	case 22:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:128
		{
			shyyVAL.CompoundCommand = &MkShCompoundCommand{Loop: shyyDollar[1].Loop}
		}
	case 23:
		shyyDollar = shyyS[shyypt-3 : shyypt+1]
		//line shell.y:132
		{
			shyyVAL.List = shyyDollar[2].List
		}
	case 24:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:136
		{
			shyyVAL.List = shyyDollar[2].List
		}
	case 25:
		shyyDollar = shyyS[shyypt-3 : shyypt+1]
		//line shell.y:139
		{
			shyyVAL.List = shyyDollar[2].List
			shyyVAL.List.AddSeparator(shyyDollar[3].Separator)
		}
	case 26:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:144
		{
			shyyVAL.List = NewMkShList()
			shyyVAL.List.AddAndOr(shyyDollar[1].AndOr)
		}
	case 27:
		shyyDollar = shyyS[shyypt-3 : shyypt+1]
		//line shell.y:148
		{
			shyyVAL.List.AddSeparator(shyyDollar[2].Separator)
			shyyVAL.List.AddAndOr(shyyDollar[3].AndOr)
		}
	case 28:
		shyyDollar = shyyS[shyypt-4 : shyypt+1]
		//line shell.y:153
		{
			args := NewShToken("\"$$@\"",
				&ShAtom{shtWord, "\"", shqDquot, nil},
				&ShAtom{shtWord, "$$@", shqDquot, nil},
				&ShAtom{shtWord, "\"", shqPlain, nil})
			shyyVAL.For = &MkShForClause{shyyDollar[2].Word.MkText, []*ShToken{args}, shyyDollar[4].List}
		}
	case 29:
		shyyDollar = shyyS[shyypt-6 : shyypt+1]
		//line shell.y:160
		{
			shyyVAL.For = &MkShForClause{shyyDollar[2].Word.MkText, nil, shyyDollar[6].List}
		}
	case 30:
		shyyDollar = shyyS[shyypt-7 : shyypt+1]
		//line shell.y:163
		{
			shyyVAL.For = &MkShForClause{shyyDollar[2].Word.MkText, shyyDollar[5].Words, shyyDollar[7].List}
		}
	case 31:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:167
		{
			shyyVAL.Words = append(shyyVAL.Words, shyyDollar[1].Word)
		}
	case 32:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:170
		{
			shyyVAL.Words = append(shyyVAL.Words, shyyDollar[2].Word)
		}
	case 33:
		shyyDollar = shyyS[shyypt-7 : shyypt+1]
		//line shell.y:174
		{
			shyyVAL.Case = shyyDollar[6].Case
			shyyVAL.Case.Word = shyyDollar[2].Word
		}
	case 34:
		shyyDollar = shyyS[shyypt-7 : shyypt+1]
		//line shell.y:178
		{
			shyyVAL.Case = shyyDollar[6].Case
			shyyVAL.Case.Word = shyyDollar[2].Word
		}
	case 35:
		shyyDollar = shyyS[shyypt-6 : shyypt+1]
		//line shell.y:182
		{
			shyyVAL.Case = &MkShCaseClause{shyyDollar[2].Word, nil}
		}
	case 36:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:186
		{
			shyyVAL.Case = &MkShCaseClause{nil, nil}
			shyyVAL.Case.Cases = append(shyyVAL.Case.Cases, shyyDollar[1].CaseItem)
		}
	case 37:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:190
		{
			shyyVAL.Case.Cases = append(shyyVAL.Case.Cases, shyyDollar[2].CaseItem)
		}
	case 38:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:194
		{
			shyyVAL.Case = &MkShCaseClause{nil, nil}
			shyyVAL.Case.Cases = append(shyyVAL.Case.Cases, shyyDollar[1].CaseItem)
		}
	case 39:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:198
		{
			shyyVAL.Case.Cases = append(shyyVAL.Case.Cases, shyyDollar[2].CaseItem)
		}
	case 40:
		shyyDollar = shyyS[shyypt-3 : shyypt+1]
		//line shell.y:202
		{
			shyyVAL.Words = shyyDollar[2].Words
		}
	case 41:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:205
		{
			/* empty */
		}
	case 42:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:208
		{
			shyyVAL.CaseItem = &MkShCaseItem{shyyDollar[1].Words, &MkShList{}, sepNone}
		}
	case 43:
		shyyDollar = shyyS[shyypt-4 : shyypt+1]
		//line shell.y:211
		{
			shyyVAL.CaseItem = &MkShCaseItem{shyyDollar[1].Words, shyyDollar[3].List, sepNone}
		}
	case 44:
		shyyDollar = shyyS[shyypt-5 : shyypt+1]
		//line shell.y:214
		{
			shyyVAL.CaseItem = &MkShCaseItem{shyyDollar[1].Words, shyyDollar[3].List, shyyDollar[4].Separator}
		}
	case 45:
		shyyDollar = shyyS[shyypt-4 : shyypt+1]
		//line shell.y:218
		{
			shyyVAL.CaseItem = &MkShCaseItem{shyyDollar[1].Words, &MkShList{}, sepNone}
		}
	case 46:
		shyyDollar = shyyS[shyypt-4 : shyypt+1]
		//line shell.y:221
		{
			shyyVAL.CaseItem = &MkShCaseItem{shyyDollar[1].Words, shyyDollar[2].List, sepNone}
		}
	case 47:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:225
		{
			shyyVAL.Words = nil
			shyyVAL.Words = append(shyyVAL.Words, shyyDollar[1].Word)
		}
	case 48:
		shyyDollar = shyyS[shyypt-3 : shyypt+1]
		//line shell.y:229
		{
			shyyVAL.Words = append(shyyVAL.Words, shyyDollar[3].Word)
		}
	case 49:
		shyyDollar = shyyS[shyypt-6 : shyypt+1]
		//line shell.y:233
		{
			shyyVAL.If = shyyDollar[5].If
			shyyVAL.If.Prepend(shyyDollar[2].List, shyyDollar[4].List)
		}
	case 50:
		shyyDollar = shyyS[shyypt-5 : shyypt+1]
		//line shell.y:237
		{
			shyyVAL.If = &MkShIfClause{}
			shyyVAL.If.Prepend(shyyDollar[2].List, shyyDollar[4].List)
		}
	case 51:
		shyyDollar = shyyS[shyypt-4 : shyypt+1]
		//line shell.y:242
		{
			shyyVAL.If = &MkShIfClause{}
			shyyVAL.If.Prepend(shyyDollar[2].List, shyyDollar[4].List)
		}
	case 52:
		shyyDollar = shyyS[shyypt-5 : shyypt+1]
		//line shell.y:246
		{
			shyyVAL.If = shyyDollar[5].If
			shyyVAL.If.Prepend(shyyDollar[2].List, shyyDollar[4].List)
		}
	case 53:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:250
		{
			shyyVAL.If = &MkShIfClause{nil, nil, shyyDollar[2].List}
		}
	case 54:
		shyyDollar = shyyS[shyypt-3 : shyypt+1]
		//line shell.y:254
		{
			shyyVAL.Loop = &MkShLoopClause{shyyDollar[2].List, shyyDollar[3].List, false}
		}
	case 55:
		shyyDollar = shyyS[shyypt-3 : shyypt+1]
		//line shell.y:257
		{
			shyyVAL.Loop = &MkShLoopClause{shyyDollar[2].List, shyyDollar[3].List, true}
		}
	case 56:
		shyyDollar = shyyS[shyypt-5 : shyypt+1]
		//line shell.y:261
		{ /* Apply rule 9 */
			shyyVAL.FuncDef = &MkShFunctionDefinition{shyyDollar[1].Word.MkText, shyyDollar[5].CompoundCommand}
		}
	case 57:
		shyyDollar = shyyS[shyypt-3 : shyypt+1]
		//line shell.y:264
		{
			shyyVAL.List = shyyDollar[2].List
		}
	case 58:
		shyyDollar = shyyS[shyypt-3 : shyypt+1]
		//line shell.y:268
		{
			shyyVAL.List = shyyDollar[2].List
		}
	case 59:
		shyyDollar = shyyS[shyypt-3 : shyypt+1]
		//line shell.y:272
		{
			shyyVAL.Simple.Name = shyyDollar[2].Word
			shyyVAL.Simple.Args = append(shyyVAL.Simple.Args, shyyDollar[3].Simple.Args...)
			shyyVAL.Simple.Redirections = append(shyyVAL.Simple.Redirections, shyyDollar[3].Simple.Redirections...)
		}
	case 60:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:277
		{
			shyyVAL.Simple.Name = shyyDollar[2].Word
		}
	case 61:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:280
		{
			/* empty */
		}
	case 62:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:282
		{
			shyyVAL.Simple = shyyDollar[2].Simple
			shyyVAL.Simple.Name = shyyDollar[1].Word
		}
	case 63:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:286
		{
			shyyVAL.Simple = &MkShSimpleCommand{Name: shyyDollar[1].Word}
		}
	case 64:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:290
		{ /* Apply rule 7b */
			/* empty */
		}
	case 65:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:292
		{
			shyyVAL.Simple = &MkShSimpleCommand{}
			shyyVAL.Simple.Redirections = append(shyyVAL.Simple.Redirections, shyyDollar[1].Redirection)
		}
	case 66:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:296
		{
			shyyVAL.Simple = &MkShSimpleCommand{}
			shyyVAL.Simple.Assignments = append(shyyVAL.Simple.Assignments, shyyDollar[1].Word)
		}
	case 67:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:300
		{
			shyyVAL.Simple.Redirections = append(shyyVAL.Simple.Redirections, shyyDollar[2].Redirection)
		}
	case 68:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:303
		{
			shyyVAL.Simple.Assignments = append(shyyVAL.Simple.Assignments, shyyDollar[2].Word)
		}
	case 69:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:307
		{
			shyyVAL.Simple = &MkShSimpleCommand{}
			shyyVAL.Simple.Redirections = append(shyyVAL.Simple.Redirections, shyyDollar[1].Redirection)
		}
	case 70:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:311
		{
			shyyVAL.Simple = &MkShSimpleCommand{}
			shyyVAL.Simple.Args = append(shyyVAL.Simple.Args, shyyDollar[1].Word)
		}
	case 71:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:315
		{
			shyyVAL.Simple.Redirections = append(shyyVAL.Simple.Redirections, shyyDollar[2].Redirection)
		}
	case 72:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:318
		{
			shyyVAL.Simple.Args = append(shyyVAL.Simple.Args, shyyDollar[2].Word)
		}
	case 73:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:322
		{
			shyyVAL.Redirections = nil
			shyyVAL.Redirections = append(shyyVAL.Redirections, shyyDollar[1].Redirection)
		}
	case 74:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:326
		{
			shyyVAL.Redirections = append(shyyVAL.Redirections, shyyDollar[2].Redirection)
		}
	case 75:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:330
		{
			/* empty */
		}
	case 76:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:332
		{
			shyyVAL.Redirection = shyyDollar[2].Redirection
			shyyVAL.Redirection.Fd = shyyDollar[1].IONum
		}
	case 77:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:337
		{
			/* empty */
		}
	case 78:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:339
		{
			shyyVAL.Redirection = shyyDollar[2].Redirection
			shyyVAL.Redirection.Fd = shyyDollar[1].IONum
		}
	case 79:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:344
		{
			shyyVAL.Redirection = &MkShRedirection{-1, "<", shyyDollar[2].Word}
		}
	case 80:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:347
		{
			shyyVAL.Redirection = &MkShRedirection{-1, "<&", shyyDollar[2].Word}
		}
	case 81:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:350
		{
			shyyVAL.Redirection = &MkShRedirection{-1, ">", shyyDollar[2].Word}
		}
	case 82:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:353
		{
			shyyVAL.Redirection = &MkShRedirection{-1, ">&", shyyDollar[2].Word}
		}
	case 83:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:356
		{
			shyyVAL.Redirection = &MkShRedirection{-1, ">>", shyyDollar[2].Word}
		}
	case 84:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:359
		{
			shyyVAL.Redirection = &MkShRedirection{-1, "<>", shyyDollar[2].Word}
		}
	case 85:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:362
		{
			shyyVAL.Redirection = &MkShRedirection{-1, ">|", shyyDollar[2].Word}
		}
	case 86:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:366
		{ /* Apply rule 2 */
			/* empty */
		}
	case 87:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:368
		{
			shyyVAL.Redirection = &MkShRedirection{-1, "<<", shyyDollar[2].Word}
		}
	case 88:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:371
		{
			shyyVAL.Redirection = &MkShRedirection{-1, "<<-", shyyDollar[2].Word}
		}
	case 89:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:375
		{ /* Apply rule 3 */
			/* empty */
		}
	case 90:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:377
		{
			/* empty */
		}
	case 91:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:379
		{
			/* empty */
		}
	case 92:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:382
		{
			/* empty */
		}
	case 93:
		shyyDollar = shyyS[shyypt-0 : shyypt+1]
		//line shell.y:384
		{
			/* empty */
		}
	case 94:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:387
		{
			shyyVAL.Separator = sepBackground
		}
	case 95:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:390
		{
			shyyVAL.Separator = sepSemicolon
		}
	case 96:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:394
		{
			/* empty */
		}
	case 97:
		shyyDollar = shyyS[shyypt-1 : shyypt+1]
		//line shell.y:396
		{
			shyyVAL.Separator = sepNewline
		}
	case 98:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:400
		{
			shyyVAL.Separator = sepSemicolon
		}
	case 99:
		shyyDollar = shyyS[shyypt-2 : shyypt+1]
		//line shell.y:403
		{
			shyyVAL.Separator = sepNewline
		}
	}
	goto shyystack /* stack new state and value */
}
