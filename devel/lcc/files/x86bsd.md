%{
enum { EAX=0, ECX=1, EDX=2, EBX=3, ESI=6, EDI=7 };
#include "c.h"
#define NODEPTR_TYPE Node
#define OP_LABEL(p) ((p)->op)
#define LEFT_CHILD(p) ((p)->kids[0])
#define RIGHT_CHILD(p) ((p)->kids[1])
#define STATE_LABEL(p) ((p)->x.state)
static void address(Symbol, Symbol, long);
static void blkfetch(int, int, int, int);
static void blkloop(int, int, int, int, int, int[]);
static void blkstore(int, int, int, int);
static void defaddress(Symbol);
static void defconst(int, int, Value);
static void defstring(int, char *);
static void defsymbol(Symbol);
static void defsymbolelf(Symbol);
static void doarg(Node);
static void emit2(Node);
static void export(Symbol);
static void clobber(Node);
static void function(Symbol, Symbol [], Symbol [], int);
static void global(Symbol);
static void import(Symbol);
static void local(Symbol);
static void progbeg(int, char **);
static void progend(void);
static void segment(int);
static void space(int);
static void target(Node);
static int ckstack(Node, int);
static int memop(Node);
static int hasargs (Node);
static int sametree(Node, Node);
static void globalend(void);
static Symbol charreg[32], shortreg[32], intreg[32];
static Symbol charregw, shortregw, intregw, fltregw;
static Symbol fltreg[32];
static Symbol quo, rem;
static int cseg, profile = 0;

%}
%start stmt

%term CNSTF4=4113 CNSTF8=8209 CNSTF16=16401
%term CNSTI1=1045 CNSTI2=2069 CNSTI4=4117
%term CNSTP4=4119
%term CNSTU1=1046 CNSTU2=2070 CNSTU4=4118

%term ARGB=41
%term ARGF4=4129 ARGF8=8225 ARGF16=16417
%term ARGI4=4133
%term ARGP4=4135
%term ARGU4=4134

%term ASGNB=57
%term ASGNF4=4145 ASGNF8=8241 ASGNF16=16433
%term ASGNI1=1077 ASGNI2=2101 ASGNI4=4149
%term ASGNP4=4151
%term ASGNU1=1078 ASGNU2=2102 ASGNU4=4150

%term INDIRB=73
%term INDIRF4=4161 INDIRF8=8257 INDIRF16=16449
%term INDIRI1=1093 INDIRI2=2117 INDIRI4=4165
%term INDIRP4=4167
%term INDIRU1=1094 INDIRU2=2118 INDIRU4=4166

%term CVFF4=4209 CVFF8=8305 CVFF16=16497
%term CVFI4=4213

%term CVIF4=4225 CVIF8=8321 CVIF16=16513
%term CVII1=1157 CVII2=2181 CVII4=4229
%term CVIU1=1158 CVIU2=2182 CVIU4=4230

%term CVPU4=4246

%term CVUI1=1205 CVUI2=2229 CVUI4=4277
%term CVUP4=4279
%term CVUU1=1206 CVUU2=2230 CVUU4=4278

%term NEGF4=4289 NEGF8=8385 NEGF16=16577
%term NEGI4=4293

%term CALLB=217
%term CALLF4=4305 CALLF8=8401 CALLF16=16593
%term CALLI4=4309
%term CALLP4=4311
%term CALLU4=4310
%term CALLV=216

%term RETF4=4337 RETF8=8433 RETF16=16625
%term RETI4=4341
%term RETP4=4343
%term RETU4=4342
%term RETV=248

%term ADDRGP4=4359

%term ADDRFP4=4375

%term ADDRLP4=4391

%term ADDF4=4401 ADDF8=8497 ADDF16=16689
%term ADDI4=4405
%term ADDP4=4407
%term ADDU4=4406

%term SUBF4=4417 SUBF8=8513 SUBF16=16705
%term SUBI4=4421
%term SUBP4=4423
%term SUBU4=4422

%term LSHI4=4437
%term LSHU4=4438

%term MODI4=4453
%term MODU4=4454

%term RSHI4=4469
%term RSHU4=4470

%term BANDI4=4485
%term BANDU4=4486

%term BCOMI4=4501
%term BCOMU4=4502

%term BORI4=4517
%term BORU4=4518

%term BXORI4=4533
%term BXORU4=4534

%term DIVF4=4545 DIVF8=8641 DIVF16=16833
%term DIVI4=4549
%term DIVU4=4550

%term MULF4=4561 MULF8=8657 MULF16=16849
%term MULI4=4565
%term MULU4=4566

%term EQF4=4577 EQF8=8673 EQF16=16865
%term EQI4=4581
%term EQU4=4582

%term GEF4=4593 GEF8=8689 GEF16=16881
%term GEI4=4597
%term GEU4=4598

%term GTF4=4609 GTF8=8705 GTF16=16897
%term GTI4=4613
%term GTU4=4614

%term LEF4=4625 LEF8=8721 LEF16=16913
%term LEI4=4629
%term LEU4=4630

%term LTF4=4641 LTF8=8737 LTF16=16929
%term LTI4=4645
%term LTU4=4646

%term NEF4=4657 NEF8=8753 NEF16=16945
%term NEI4=4661
%term NEU4=4662

%term JUMPV=584

%term LABELV=600

%term LOADB=233
%term LOADF4=4321 LOADF8=8417 LOADF16=16609
%term LOADI1=1253 LOADI2=2277 LOADI4=4325
%term LOADP4=4327
%term LOADU1=1254 LOADU2=2278 LOADU4=4326

%term VREGP=711
%%
reg: INDIRI1(VREGP)      "# read register\n"
reg: INDIRU1(VREGP)      "# read register\n"

reg: INDIRI2(VREGP)      "# read register\n"
reg: INDIRU2(VREGP)      "# read register\n"

reg: INDIRI4(VREGP)      "# read register\n"
reg: INDIRP4(VREGP)      "# read register\n"
reg: INDIRU4(VREGP)      "# read register\n"

freg: INDIRF4(VREGP)     "# read register\n"
freg: INDIRF8(VREGP)     "# read register\n"

stmt: ASGNI1(VREGP,reg)  "# write register\n"
stmt: ASGNU1(VREGP,reg)  "# write register\n"

stmt: ASGNI2(VREGP,reg)  "# write register\n"
stmt: ASGNU2(VREGP,reg)  "# write register\n"

stmt: ASGNF4(VREGP,reg)  "# write register\n"
stmt: ASGNI4(VREGP,reg)  "# write register\n"
stmt: ASGNP4(VREGP,reg)  "# write register\n"
stmt: ASGNU4(VREGP,reg)  "# write register\n"

stmt: ASGNF8(VREGP,reg)  "# write register\n"

cnst: CNSTI1  	"%a"
cnst: CNSTU1  	"%a"

cnst: CNSTI2  	"%a"
cnst: CNSTU2  	"%a"

cnst: CNSTI4  	"%a"
cnst: CNSTU4  	"%a"
cnst: CNSTP4  	"%a"

con: cnst   	"$%0"

stmt: reg  	""
stmt: freg	""

acon: ADDRGP4  "%a"
acon: cnst     "%0"

baseaddr: ADDRGP4	"%a"
base: reg		"(%0)"
base: ADDI4(reg,acon)	"%1(%0)"
base: ADDP4(reg,acon)	"%1(%0)"
base: ADDU4(reg,acon)	"%1(%0)"
base: ADDRFP4		"%a(%%ebp)"
base: ADDRLP4		"%a(%%ebp)"

index: reg 		"%0"
index: LSHI4(reg,con1)  "%0,2"
index: LSHI4(reg,con2)  "%0,4"
index: LSHI4(reg,con3)  "%0,8"
index: LSHU4(reg,con1)  "%0,2"
index: LSHU4(reg,con2)  "%0,4"
index: LSHU4(reg,con3)  "%0,8"

con0:  CNSTI4  "1"  range(a, 0, 0)
con0:  CNSTU4  "1"  range(a, 0, 0)
con1:  CNSTI4  "1"  range(a, 1, 1)
con1:  CNSTU4  "1"  range(a, 1, 1)
con2:  CNSTI4  "2"  range(a, 2, 2)
con2:  CNSTU4  "2"  range(a, 2, 2)
con3:  CNSTI4  "3"  range(a, 3, 3)
con3:  CNSTU4  "3"  range(a, 3, 3)

addr: base                	"%0"
addr: baseaddr            	"%0"
addr: ADDI4(index,baseaddr)  	"%1(,%0)"
addr: ADDP4(index,baseaddr)  	"%1(,%0)"
addr: ADDU4(index,baseaddr)  	"%1(,%0)"

addr: ADDI4(reg,baseaddr)  	"%1(%0)"
addr: ADDP4(reg,baseaddr)  	"%1(%0)"
addr: ADDU4(reg,baseaddr)  	"%1(%0)"

addr: ADDI4(index,reg)  	"(%1,%0)"
addr: ADDP4(index,reg)  	"(%1,%0)"
addr: ADDU4(index,reg)  	"(%1,%0)"

addr: index  "(,%0)"

mem1: INDIRI1(addr)  "%0"
mem1: INDIRU1(addr)  "%0"
mem2: INDIRI2(addr)  "%0"
mem2: INDIRU2(addr)  "%0"
mem4: INDIRI4(addr)  "%0"
mem4: INDIRU4(addr)  "%0"
mem4: INDIRP4(addr)  "%0"

rc: reg  	"%0"
rc: con  	"%0"

mr: reg  	"%0"
mr: mem4  	"%0"

mr1: reg 	"%0"
mr1: mem1  	"%0"

mr2: reg 	"%0"
mr2: mem2  	"%0"

mrc: mem4  	"%0"  1
mrc: mem1  	"%0"  1
mrc: mem2  	"%0"  1
mrc: rc   	"%0"

reg: addr         "\tleal %0,%c\n"  1
reg: mr	          "\tmovl %0,%c\n"  1
reg: mr1          "\tmovb %0,%c\n"  1
reg: mr2	  "\tmovw %0,%c\n"  1
reg: con          "\tmovl %0,%c\n"  1

reg: LOADI1(reg)  "# move\n"  1
reg: LOADI2(reg)  "# move\n"  1
reg: LOADI4(reg)  "# move\n"  move(a)
reg: LOADU1(reg)  "# move\n"  1
reg: LOADU2(reg)  "# move\n"  1
reg: LOADU4(reg)  "# move\n"  move(a)
reg: LOADP4(reg)  "# move\n"  move(a)
reg: ADDI4(reg,mrc)  "?\tmovl %0,%c\n\taddl %1,%c\n"  1
reg: ADDP4(reg,mrc)  "?\tmovl %0,%c\n\taddl %1,%c\n"  1
reg: ADDU4(reg,mrc)  "?\tmovl %0,%c\n\taddl %1,%c\n"  1
reg: SUBI4(reg,mrc)  "?\tmovl %0,%c\n\tsubl %1,%c\n"  1
reg: SUBP4(reg,mrc)  "?\tmovl %0,%c\n\tsubl %1,%c\n"  1
reg: SUBU4(reg,mrc)  "?\tmovl %0,%c\n\tsubl %1,%c\n"  1
reg: BANDI4(reg,mrc) "?\tmovl %0,%c\n\tandl %1,%c\n"  1
reg: BORI4(reg,mrc)  "?\tmovl %0,%c\n\torl %1,%c\n"   1
reg: BXORI4(reg,mrc) "?\tmovl %0,%c\n\txorl %1,%c\n"  1
reg: BANDU4(reg,mrc) "?\tmovl %0,%c\n\tandl %1,%c\n"  1
reg: BORU4(reg,mrc)  "?\tmovl %0,%c\n\torl %1,%c\n"   1
reg: BXORU4(reg,mrc) "?\tmovl %0,%c\n\txorl %1,%c\n"  1

stmt: ASGNI4(addr,ADDI4(mem4,con1)) "\tincl %1\n"     memop(a)
stmt: ASGNI4(addr,ADDU4(mem4,con1)) "\tincl %1\n"     memop(a)
stmt: ASGNP4(addr,ADDP4(mem4,con1)) "\tincl %1\n"     memop(a)
stmt: ASGNI4(addr,SUBI4(mem4,con1)) "\tdecl %1\n"     memop(a)
stmt: ASGNI4(addr,SUBU4(mem4,con1)) "\tdecl %1\n"     memop(a)
stmt: ASGNP4(addr,SUBP4(mem4,con1)) "\tdecl %1\n"     memop(a)
stmt: ASGNI4(addr,ADDI4(mem4,rc))   "\taddl %2,%1\n"  memop(a)
stmt: ASGNI4(addr,SUBI4(mem4,rc))   "\tsubl %2,%1\n"   memop(a)
stmt: ASGNU4(addr,ADDU4(mem4,rc))   "\taddl %2,%1\n"   memop(a)
stmt: ASGNU4(addr,SUBU4(mem4,rc))   "\tsubl %2,%1\n"   memop(a)

stmt: ASGNI4(addr,BANDI4(mem4,rc))  "\tandl %2,%1\n"  memop(a)
stmt: ASGNI4(addr,BORI4(mem4,rc))   "\torl %2,%1\n"   memop(a)
stmt: ASGNI4(addr,BXORI4(mem4,rc))  "\txorl %2,%1\n"  memop(a)
stmt: ASGNU4(addr,BANDU4(mem4,rc))  "\tandl %2,%1\n"  memop(a)
stmt: ASGNU4(addr,BORU4(mem4,rc))   "\torl %2,%1\n"   memop(a)
stmt: ASGNU4(addr,BXORU4(mem4,rc))  "\txorl %2,%1\n"  memop(a)

reg: BCOMI4(reg)  "?\tmovl %0,%c\n\tnotl %c\n"  2
reg: BCOMU4(reg)  "?\tmovl %0,%c\n\tnotl %c\n"  2
reg: NEGI4(reg)   "?\tmovl %0,%c\n\tnegl %c\n"  2

stmt: ASGNI4(addr,BCOMI4(mem4))  "\tnotl %1\n"  memop(a)
stmt: ASGNU4(addr,BCOMU4(mem4))  "\tnotl %1\n"  memop(a)
stmt: ASGNI4(addr,NEGI4(mem4))   "\tnegl %1\n"  memop(a)
reg: LSHI4(reg,rc5)  "?\tmovl %0,%c\n\tsall %1,%c\n"  2
reg: LSHU4(reg,rc5)  "?\tmovl %0,%c\n\tshll %1,%c\n"  2
reg: RSHI4(reg,rc5)  "?\tmovl %0,%c\n\tsarl %1,%c\n"  2
reg: RSHU4(reg,rc5)  "?\tmovl %0,%c\n\tshrl %1,%c\n"  2

stmt: ASGNI4(addr,LSHI4(mem4,rc5))  "\tsall %2,%1\n"  memop(a)
stmt: ASGNI4(addr,LSHU4(mem4,rc5))  "\tshll %2,%1\n"  memop(a)
stmt: ASGNI4(addr,RSHI4(mem4,rc5))  "\tsarl %2,%1\n"  memop(a)
stmt: ASGNI4(addr,RSHU4(mem4,rc5))  "\tshrl %2,%1\n"  memop(a)

rc5: CNSTI4          "$%a"  range(a, 0, 31)
rc5: reg             "%%cl"
reg: MULI4(reg,mrc)  "?\tmovl %0,%c\n\timull %1,%c\n"  14
reg: MULI4(con,mr)   "\timul %0,%1,%c\n"  13
reg: MULU4(reg,mr)   "\tmull %1\n"  13
reg: DIVU4(reg,reg)  "\txorl %%edx,%%edx\n\tdivl %1\n"
reg: MODU4(reg,reg)  "\txorl %%edx,%%edx\n\tdivl %1\n"
reg: DIVI4(reg,reg)  "\tcdq\n\tidivl %1\n"
reg: MODI4(reg,reg)  "\tcdq\n\tidivl %1\n"
reg: CVPU4(reg)      "\tmovl %0,%c\n"  move(a)
reg: CVUP4(reg)      "\tmovl %0,%c\n"  move(a)
reg: CVII4(INDIRI1(addr))  "\tmovsbl %0,%c\n"  3
reg: CVII4(INDIRI2(addr))  "\tmovswl %0,%c\n"  3
reg: CVUU4(INDIRU1(addr))  "movzbl %0,%c\n"  3
reg: CVUU4(INDIRU2(addr))  "movzwl %0,%c\n"  3
reg: CVII4(reg)  "# extend\n"  3
reg: CVIU4(reg)  "# extend\n"  3
reg: CVUI4(reg)  "# extend\n"  3
reg: CVUU4(reg)  "# extend\n"  3

reg: CVII1(reg)  "# truncate\n"  1
reg: CVII2(reg)  "# truncate\n"  1
reg: CVUU1(reg)  "# truncate\n"  1
reg: CVUU2(reg)  "# truncate\n"  1

mrca: mem4    "%0"
mrca: rc      "%0"
mrca: ADDRGP4 "$%a"

stmt: ASGNI1(addr,rc)	"\tmovb %1,%0\n"   1
stmt: ASGNI2(addr,rc)	"\tmovw %1,%0\n"   1
stmt: ASGNI4(addr,rc)	"\tmovl %1,%0\n"   1
stmt: ASGNU1(addr,rc)	"\tmovb %1,%0\n"   1
stmt: ASGNU2(addr,rc)  	"\tmovw %1,%0\n"   1
stmt: ASGNU4(addr,rc)  	"\tmovl %1,%0\n"   1
stmt: ASGNP4(addr,rc)	"\tmovl %1,%0\n"   1
stmt: ARGI4(mrca)	"\tpushl %0\n"  1
stmt: ARGU4(mrca)	"\tpushl %0\n"  1
stmt: ARGP4(mrca)	"\tpushl %0\n"  1
stmt: ASGNB(reg,INDIRB(reg))	"\tmovl $%a,%%ecx\n\trep\n\tmovsb\n"
stmt: ARGB(INDIRB(reg))		"\tsubl $%a,%%esp\n\tmovl %%esp,%%edi\n\tmovl $%a,%%ecx\n\trep\n\tmovsb\n"

memf: INDIRF8(addr)         "l %0"
memf: INDIRF4(addr)         "s %0"
memf: CVFF8(INDIRF4(addr))  "s %0"
memf: CVFF4(INDIRF8(addr))  "l %0"

freg: memf  "\tfld%0\n"  3

stmt: ASGNF8(addr,freg)         "\tfstpl %0\n"  7
stmt: ASGNF4(addr,freg)         "\tfstps %0\n"  7
stmt: ASGNF4(addr,CVFF4(freg))  "\tfstps %0\n"  7

stmt: ARGF8(freg)  "\tsubl $8,%%esp\n\tfstpl (%%esp)\n"
stmt: ARGF4(freg)  "\tsubl $4,%%esp\n\tfstps (%%esp)\n"
freg: NEGF8(freg)  "\tfchs\n"
freg: NEGF4(freg)  "\tfchs\n"

flt: memf	"%0"
flt: freg	"p %%st(1),%%st"

freg: ADDF8(freg,flt)  "\tfadd%1\n"
freg: ADDF4(freg,flt)  "\tfadd%1\n"

freg: DIVF8(freg,flt)  "\tfdiv%1\n" 
freg: DIVF4(freg,flt)  "\tfdiv%1\n"

freg: MULF8(freg,flt)  "\tfmul%1\n"
freg: MULF4(freg,flt)  "\tfmul%1\n"

freg: SUBF8(freg,flt)  "\tfsub%1\n"
freg: SUBF4(freg,flt)  "\tfsub%1\n"

freg: CVFF8(freg)  "# CVFF8\n"
freg: CVFF4(freg)  "\tsub $4,%%esp\n\tfstps (%%esp)\n\tflds (%%esp)\n\taddl $4,%%esp\n"  12

stmt: ASGNI4(addr,CVFI4(freg))  "\tfistpl %0\n" 29
reg: CVFI4(freg)  "\tsubl $4,%%esp\n\tfistpl 0(%%esp)\n\tpopl %c\n" 31

freg: CVIF8(INDIRI4(addr))  "\tfildl %0\n"  10
freg: CVIF8(reg)  "\tpushl %0\n\tfildl (%%esp)\n\taddl $4,%%esp\n"  12

freg: CVIF4(INDIRI4(addr))  "\tfildl %0\n"  10
freg: CVIF4(reg)  "\tpushl %0\n\tfildl (%%esp)\n\taddl $4,%%esp\n"  12

addrj: ADDRGP4  "%a"
addrj: reg      "*%0"  2
addrj: mem4     "*%0"  2

stmt: LABELV        "%a:\n"
stmt: JUMPV(addrj)  "\tjmp %0\n"  3

stmt: EQI4(mem4,rc)  "\tcmpl %1,%0\n\tje %a\n"   5
stmt: GEI4(mem4,rc)  "\tcmpl %1,%0\n\tjge %a\n"  5
stmt: GTI4(mem4,rc)  "\tcmpl %1,%0\n\tjg %a\n"   5
stmt: LEI4(mem4,rc)  "\tcmpl %1,%0\n\tjle %a\n"  5
stmt: LTI4(mem4,rc)  "\tcmpl %1,%0\n\tjl %a\n"   5
stmt: NEI4(mem4,rc)  "\tcmpl %1,%0\n\tjne %a\n"  5
stmt: GEU4(mem4,rc)  "\tcmpl %1,%0\n\tjae %a\n"  5
stmt: GTU4(mem4,rc)  "\tcmpl %1,%0\n\tja  %a\n"  5
stmt: LEU4(mem4,rc)  "\tcmpl %1,%0\n\tjbe %a\n"  5
stmt: LTU4(mem4,rc)  "\tcmpl %1,%0\n\tjb  %a\n"  5
stmt: EQI4(reg,mrc)  "\tcmpl %1,%0\n\tje %a\n"   4
stmt: GEI4(reg,mrc)  "\tcmpl %1,%0\n\tjge %a\n"  4
stmt: GTI4(reg,mrc)  "\tcmpl %1,%0\n\tjg %a\n"   4
stmt: LEI4(reg,mrc)  "\tcmpl %1,%0\n\tjle %a\n"  4
stmt: LTI4(reg,mrc)  "\tcmpl %1,%0\n\tjl %a\n"   4
stmt: NEI4(reg,mrc)  "\tcmpl %1,%0\n\tjne %a\n"  4

stmt: EQU4(reg,mrc)  "\tcmpl %1,%0\n\tje %a\n"   4
stmt: GEU4(reg,mrc)  "\tcmpl %1,%0\n\tjae %a\n"  4
stmt: GTU4(reg,mrc)  "\tcmpl %1,%0\n\tja %a\n"   4
stmt: LEU4(reg,mrc)  "\tcmpl %1,%0\n\tjbe %a\n"  4
stmt: LTU4(reg,mrc)  "\tcmpl %1,%0\n\tjb %a\n"   4
stmt: NEU4(reg,mrc)  "\tcmpl %1,%0\n\tjne %a\n"  4


stmt: EQI4(BANDU4(mr,con),con0) "\ttestl\t%1,%0\n\tje\t%a\n" 3
stmt: NEI4(BANDU4(mr,con),con0) "\ttestl\t%1,%0\n\tjne\t%a\n"

stmt: EQI4(BANDU4(CVII2(INDIRI2(addr)),con),con0) "\ttestw\t%1,%0\n\tje\t%a\n"
stmt: NEI4(BANDU4(CVII2(INDIRI2(addr)),con),con0) "\ttestw\t%1,%0\n\tjne\t%a\n"
stmt: EQI4(BANDU4(CVIU2(INDIRI2(addr)),con),con0) "\ttestw\t%1,%0\n\tje\t%a\n"
stmt: NEI4(BANDU4(CVIU2(INDIRI2(addr)),con),con0) "\ttestw\t%1,%0\n\tjne\t%a\n"
stmt: EQI4(BANDU4(CVII1(INDIRI1(addr)),con),con0) "\ttestb\t%1,%0\n\tje\t%a\n"

cmpf: INDIRF8(addr)		"l %0"
cmpf: INDIRF4(addr)		"s %0"
cmpf: CVFF8(INDIRF4(addr))	"s %0"
cmpf: freg   "p"

stmt: EQF8(cmpf,freg)  "\tfcomp%0\n\tfstsw %%ax\n\tsahf\n\tje %a\n"
stmt: GEF8(cmpf,freg)  "\tfcomp%0\n\tfstsw %%ax\n\tsahf\n\tjbe %a\n"
stmt: GTF8(cmpf,freg)  "\tfcomp%0\n\tfstsw %%ax\n\tsahf\n\tjb %a\n"
stmt: LEF8(cmpf,freg)  "\tfcomp%0\n\tfstsw %%ax\n\tsahf\n\tjae %a\n"
stmt: LTF8(cmpf,freg)  "\tfcomp%0\n\tfstsw %%ax\n\tsahf\n\tja %a\n"
stmt: NEF8(cmpf,freg)  "\tfcomp%0\n\tfstsw %%ax\n\tsahf\n\tjne %a\n"

stmt: EQF4(cmpf,freg)  "\tfcomp%0\n\tfstsw %%ax\n\tsahf\n\tje %a\n"
stmt: GEF4(cmpf,freg)  "\tfcomp%0\n\tfstsw %%ax\n\tsahf\n\tjbe %a\n"
stmt: GTF4(cmpf,freg)  "\tfcomp%0\n\tfstsw %%ax\n\tsahf\n\tjb %a\n"
stmt: LEF4(cmpf,freg)  "\tfcomp%0\n\tfstsw %%ax\n\tsahf\n\tjae %a\n"
stmt: LTF4(cmpf,freg)  "\tfcomp%0\n\tfstsw %%ax\n\tsahf\n\tja %a\n"
stmt: NEF4(cmpf,freg)  "\tfcomp%0\n\tfstsw %%ax\n\tsahf\n\tjne %a\n"


freg: DIVF8(freg,CVIF8(INDIRI4(addr))) 		"\tfidivl\t%1\n"
freg: DIVF8(CVIF8(INDIRI4(addr)),freg) 		"\tfidivrl\t%0\n"
freg: DIVF8(freg,CVIF8(CVII2(INDIRI2(addr)))) 	"\tfidivs\t%1\n"
freg: DIVF8(CVIF8(CVII2(INDIRI2(addr))),freg) 	"\tfidivrs\t%0\n"
freg: MULF8(freg,CVIF8(INDIRI4(addr))) 		"\tfimull\t%1\n"
freg: MULF8(freg,CVIF8(CVII2(INDIRI2(addr)))) 	"\tfimuls\t%1\n"
freg: SUBF8(freg,CVIF8(INDIRI4(addr))) 		"\tfisubl\t%1\n"
freg: SUBF8(CVIF8(INDIRI4(addr)),freg) 		"\tfisubrl\t%0\n"
freg: SUBF8(freg,CVIF8(CVII2(INDIRI2(addr)))) 	"\tfisubs\t%1\n"
freg: SUBF8(CVIF8(CVII2(INDIRI2(addr))),freg) 	"\tfisubrs\t%0\n"
freg: ADDF8(freg,CVIF8(INDIRI4(addr))) 		"\tfiaddl\t%1\n"
freg: ADDF8(freg,CVIF8(CVII2(INDIRI2(addr)))) 	"\tfiadds\t%1\n"
freg: ADDF8(freg,CVFF8(INDIRF4(addr))) 		"\tfdivs\t%1\n"
freg: SUBF8(freg,CVFF8(INDIRF4(addr))) 		"\tfsubs\t%1\n"
freg: MULF8(freg,CVFF8(INDIRF4(addr))) 		"\tfmuls\t%1\n"
freg: DIVF8(freg,CVFF8(INDIRF4(addr))) 		"\tfdivs\t%1\n"
freg: LOADF8(memf) "\tfld%0\n"

stmt: CALLV(addrj)   "\tcall %0\n\taddl $%a,%%esp\n"	hasargs(a)
reg:  CALLI4(addrj)  "\tcall %0\n\taddl $%a,%%esp\n"	hasargs(a)
reg:  CALLU4(addrj)  "\tcall %0\n\taddl $%a,%%esp\n"	hasargs(a)
reg:  CALLP4(addrj)  "\tcall %0\n\taddl $%a,%%esp\n"	hasargs(a)
freg: CALLF4(addrj)  "\tcall %0\n\taddl $%a,%%esp\n"	hasargs(a)
stmt: CALLF4(addrj)  "\tcall %0\n\taddl $%a,%%esp\n\tfstp %%st(0)\n" hasargs(a)
freg: CALLF8(addrj)  "\tcall %0\n\taddl $%a,%%esp\n"	hasargs(a)
stmt: CALLF8(addrj)  "\tcall %0\n\taddl $%a,%%esp\n\tfstp %%st(0)\n" hasargs(a)

stmt: CALLV(addrj)   "\tcall %0\n"			1
reg:  CALLI4(addrj)  "\tcall %0\n"			1
reg:  CALLU4(addrj)  "\tcall %0\n"			1
reg:  CALLP4(addrj)  "\tcall %0\n"			1
freg: CALLF4(addrj)  "\tcall %0\n"			1
stmt: CALLF4(addrj)  "\tcall %0\n\tfstp %%st(0)\n"	1
freg: CALLF8(addrj)  "\tcall %0\n"			1
stmt: CALLF8(addrj)  "\tcall %0\n\tfstp %%st(0)\n"	1

stmt: RETI4(reg)  "# ret\n"
stmt: RETU4(reg)  "# ret\n"
stmt: RETP4(reg)  "# ret\n"
stmt: RETF4(freg) "# ret\n"
stmt: RETF8(freg) "# ret\n"

%%
static void progbeg(int argc, char *argv[]) {
        int i;

        {
                union {
                        char c;
                        int i;
                } u;
                u.i = 0;
                u.c = 1;
                swap = ((int)(u.i == 1)) != IR->little_endian;
        }

        parseflags(argc, argv);
        for (i = 0; i < argc; i++) 
                if (!strcmp(argv[i], "-p") || !strcmp(argv[i], "-pg"))
                        profile = 1;

        intreg[EAX] = mkreg("%%eax", EAX, 1, IREG);
        intreg[EDX] = mkreg("%%edx", EDX, 1, IREG);
        intreg[ECX] = mkreg("%%ecx", ECX, 1, IREG);
        intreg[EBX] = mkreg("%%ebx", EBX, 1, IREG);
        intreg[ESI] = mkreg("%%esi", ESI, 1, IREG);
        intreg[EDI] = mkreg("%%edi", EDI, 1, IREG);
        shortreg[EAX] = mkreg("%%ax", EAX, 1, IREG);
        shortreg[ECX] = mkreg("%%cx", ECX, 1, IREG);
        shortreg[EDX] = mkreg("%%dx", EDX, 1, IREG);
        shortreg[EBX] = mkreg("%%bx", EBX, 1, IREG);
        shortreg[ESI] = mkreg("%%si", ESI, 1, IREG);
        shortreg[EDI] = mkreg("%%di", EDI, 1, IREG);

        charreg[EAX]  = mkreg("%%al", EAX, 1, IREG);
        charreg[ECX]  = mkreg("%%cl", ECX, 1, IREG);
        charreg[EDX]  = mkreg("%%dl", EDX, 1, IREG);
        charreg[EBX]  = mkreg("%%bl", EBX, 1, IREG);
        for (i = 0; i < 8; i++)
                fltreg[i] = mkreg("%d", i, 0, FREG);
        charregw = mkwildcard(charreg);
        shortregw = mkwildcard(shortreg);
        intregw = mkwildcard(intreg);
        fltregw = mkwildcard(fltreg);

        tmask[IREG] = (1<<EDI) | (1<<ESI) | (1<<EBX)
                    | (1<<EDX) | (1<<ECX) | (1<<EAX);
        vmask[IREG] = 0;
        tmask[FREG] = 0xff;
        vmask[FREG] = 0;
        cseg = 0;
	print("\t.text\n");
        quo = mkreg("%%eax", EAX, 1, IREG);
        quo->x.regnode->mask |= 1<<EDX;
        rem = mkreg("%%edx", EDX, 1, IREG);
        rem->x.regnode->mask |= 1<<EAX;
}
static Symbol rmap(int opk) {
        switch (optype(opk)) {
        case B: case P:
                return intregw;
        case I: case U:
                if (opsize(opk) == 1)
                        return charregw;
                else if (opsize(opk) == 2)
                        return shortregw;
                else
                        return intregw;
        case F:
                return fltregw;
        default:
                return 0;
        }
}
static void segment(int n) {
        if (n == cseg)
                return;
        cseg = n;
        if (cseg == CODE)
                print("\t.text\n");
        else if (cseg == BSS)
                print("\t.bss\n");
        else if (cseg == DATA || cseg == LIT)
                print("\t.data\n");
}
static void progend(void) {
        segment(0);
}
static void target(Node p) {
        assert(p);
        switch (specific(p->op)) {
        case RSH+I: case RSH+U: case LSH+I: case LSH+U:
                if (generic(p->kids[1]->op) != CNST
                && !(   generic(p->kids[1]->op) == INDIR
                     && specific(p->kids[1]->kids[0]->op) == VREG+P
                     && p->kids[1]->syms[RX]->u.t.cse
                     && generic(p->kids[1]->syms[RX]->u.t.cse->op) == CNST
)) {
                        rtarget(p, 1, intreg[ECX]);
                        setreg(p, intreg[EAX]);
                }
                break;
        case MUL+U:
                setreg(p, quo);
                rtarget(p, 0, intreg[EAX]);
                break;
        case DIV+I: case DIV+U:
                setreg(p, quo);
                rtarget(p, 0, intreg[EAX]);
                rtarget(p, 1, intreg[ECX]);
                break;
        case MOD+I: case MOD+U:
                setreg(p, rem);
                rtarget(p, 0, intreg[EAX]);
                rtarget(p, 1, intreg[ECX]);
                break;
        case ASGN+B:
                rtarget(p, 0, intreg[EDI]);
                rtarget(p->kids[1], 0, intreg[ESI]);
                break;
        case ARG+B:
                rtarget(p->kids[0], 0, intreg[ESI]);
                break;
        case CVF+I:
                setreg(p, intreg[EAX]);
                break;
        case CALL+I: case CALL+U: case CALL+P: case CALL+V:
                setreg(p, intreg[EAX]);
                break;
        case RET+I: case RET+U: case RET+P:
                rtarget(p, 0, intreg[EAX]);
                break;
        }
}

static void clobber(Node p) {
        static int nstack = 0;

        assert(p);
        nstack = ckstack(p, nstack);
        switch (specific(p->op)) {
        case ASGN+B: case ARG+B:
                spill(1<<ECX | 1<<ESI | 1<<EDI, IREG, p);
                break;
        case EQ+F: case LE+F: case GE+F: case LT+F: case GT+F: case NE+F:
                spill(1<<EAX, IREG, p);
                break;
        case CALL+F:
                spill(1<<EDX | 1<<EAX, IREG, p);
                break;
        }
}
#define isfp(p) (optype((p)->op)==F)

static int ckstack(Node p, int n) {
        int i;

        for (i = 0; i < NELEMS(p->x.kids) && p->x.kids[i]; i++)
                if (isfp(p->x.kids[i]))
                        n--;
        if (isfp(p) && p->count > 0)
                n++;
        if (n > 8)
                error("expression too complicated\n");
        debug(fprint(stderr, "(ckstack(%x)=%d)\n", p, n));
        assert(n >= 0);
        return n;
}
static int hasargs(Node p) {
        assert(p);
        assert(generic(p->op) == CALL);
        assert(p->syms[0]);
        if (p->syms[0]->u.c.v.i > 0) 
                return 0;
        return LBURG_MAX;
}
static int memop(Node p) {
        assert(p);
        assert(generic(p->op) == ASGN);
        assert(p->kids[0]);
        assert(p->kids[1]);
        if (generic(p->kids[1]->kids[0]->op) == INDIR
        && sametree(p->kids[0], p->kids[1]->kids[0]->kids[0]))
                return 3;
        else
                return LBURG_MAX;
}
static int sametree(Node p, Node q) {
        return p == NULL && q == NULL
        || p && q && p->op == q->op && p->syms[0] == q->syms[0]
                && sametree(p->kids[0], q->kids[0])
                && sametree(p->kids[1], q->kids[1]);
}
static void emit2(Node p) {
        int op = specific(p->op);
#define preg(f) ((f)[getregnum(p->x.kids[0])]->x.name)

        if (op == CVI+I && opsize(p->op) == 4 && opsize(p->x.kids[0]->op) == 1)
                print("\tmovsbl\t%s,%s\n",  preg(charreg), p->syms[RX]->x.name);
        else if (op == CVI+U && opsize(p->op) == 4 && opsize(p->x.kids[0]->op) == 1)
                print("\tmovsbl\t%s,%s\n", preg(charreg), p->syms[RX]->x.name);
        else if (op == CVI+I && opsize(p->op) == 4 && opsize(p->x.kids[0]->op) == 2)
                print("\tmovswl\t%s,%s\n", preg(shortreg), p->syms[RX]->x.name);
        else if (op == CVI+U && opsize(p->op) == 4 && opsize(p->x.kids[0]->op) == 2)
                print("\tmovswl\t%s,%s\n", preg(shortreg), p->syms[RX]->x.name);
        else if (op == CVU+I && opsize(p->op) == 4 && opsize(p->x.kids[0]->op) == 1)
                print("\tmovzbl\t%s,%s\n", preg(charreg), p->syms[RX]->x.name);
        else if (op == CVU+U && opsize(p->op) == 4 && opsize(p->x.kids[0]->op) == 1)
                print("\tmovzbl\t%s,%s\n", preg(charreg), p->syms[RX]->x.name);
        else if (op == CVU+I && opsize(p->op) == 4 && opsize(p->x.kids[0]->op) == 2)
                print("\tmovzwl\t%s,%s\n",  preg(shortreg), p->syms[RX]->x.name);
        else if (op == CVU+U && opsize(p->op) == 4 && opsize(p->x.kids[0]->op) == 2)
                print("\tmovzwl\t%s,%s\n",  preg(shortreg), p->syms[RX]->x.name);
        else if (generic(op) == CVI || generic(op) == CVU || generic(op) == LOAD) {
                char *dst = intreg[getregnum(p)]->x.name;
                char *src = preg(intreg);
                assert(opsize(p->op) <= opsize(p->x.kids[0]->op));
                if (dst != src)
                        print("\tmovl\t%s,%s\n", src, dst);
        }
}

static void doarg(Node p) {
        assert(p && p->syms[0]);
        mkactual(4, p->syms[0]->u.c.v.i);
}
static void blkfetch(int k, int off, int reg, int tmp) {}
static void blkstore(int k, int off, int reg, int tmp) {}
static void blkloop(int dreg, int doff, int sreg, int soff,
        int size, int tmps[]) {}
static void local(Symbol p) {
        if (isfloat(p->type))
                p->sclass = AUTO;
        if (askregvar(p, rmap(ttob(p->type))) == 0)
                mkauto(p);
}
static void function(Symbol f, Symbol caller[], Symbol callee[], int n) {
        int i;

        print("\t.type\t%s,@function\n", f->x.name);
        print("%s:\n", f->x.name);
        print("\tpushl\t%%ebp\n");
	if (profile) {
                static int profile_label;
                print("\tmovl\t%%esp,%%ebp\n");
                segment(DATA);
                print("\t.align 4\nLP%d:\n\t.long\t0\n", profile_label);
                segment(CODE);
                print("\tmovl\t$LP%d,%%edx\n\tcall\tmcount\n", profile_label);
                profile_label++; 
	}
        print("\tpushl\t%%ebx\n");
        print("\tpushl\t%%esi\n");
        print("\tpushl\t%%edi\n");
        print("\tmovl\t%%esp,%%ebp\n");
        usedmask[0] = usedmask[1] = 0;
        freemask[0] = freemask[1] = ~(unsigned)0;
        offset = 16 + 4;
        for (i = 0; callee[i]; i++) {
                Symbol p = callee[i];
                Symbol q = caller[i];
                assert(q);
                p->x.offset = q->x.offset = offset;
                p->x.name = q->x.name = stringf("%d", p->x.offset);
                p->sclass = q->sclass = AUTO;
                offset += roundup(q->type->size, 4);
        }
        assert(caller[i] == 0);
        offset = maxoffset = 0;
        gencode(caller, callee);
        framesize = roundup(maxoffset, 4);
        if (framesize > 0)
                print("\tsubl\t$%d,%%esp\n", framesize);
        emitcode();
        print("\tmovl\t%%ebp,%%esp\n");
        print("\tpopl\t%%edi\n");
        print("\tpopl\t%%esi\n");
        print("\tpopl\t%%ebx\n");
        print("\tpopl\t%%ebp\n");
        print("\tret\n");
	i = genlabel(1);
	print("L%d:\n", i);
	print("\t.size\t%s,L%d-%s\n", f->x.name, i, f->x.name);
}
static void defsymbol(Symbol p) {
        if (p->scope >= LOCAL && p->sclass == STATIC)
                p->x.name = stringf("L%d", genlabel(1));
        else if (p->generated)
                p->x.name = stringf("L%s", p->name);
        else if (p->scope == GLOBAL || p->sclass == EXTERN)
                p->x.name = stringf("_%s", p->name);
/*
        else if (p->scope == CONSTANTS
        && (isint(p->type) || isptr(p->type))
        && p->name[0] == '0' && p->name[1] == 'x')
                p->x.name = stringf("0%sH", &p->name[2]);
*/
        else
                p->x.name = p->name;
}
static void defsymbolelf(Symbol p) {
        if (p->scope >= LOCAL && p->sclass == STATIC)
                p->x.name = stringf("L%d", genlabel(1));
        else if (p->generated)
                p->x.name = stringf("L%s", p->name);
        else if (p->scope == GLOBAL || p->sclass == EXTERN)
                p->x.name = stringf("%s", p->name);
/*
        else if (p->scope == CONSTANTS
        && (isint(p->type) || isptr(p->type))
        && p->name[0] == '0' && p->name[1] == 'x')
                p->x.name = stringf("0%sH", &p->name[2]);
*/
        else
                p->x.name = p->name;
}
static void address(Symbol q, Symbol p, long n) {
        if (p->scope == GLOBAL
        || p->sclass == STATIC || p->sclass == EXTERN)
                q->x.name = stringf("%s%s%d",
                        p->x.name, n >= 0 ? "+" : "", n);
        else {
                q->x.offset = p->x.offset + n;
                q->x.name = stringd(q->x.offset);
        }
}
static void defconst(int suffix, int size, Value v) {
        if (suffix == I && size == 1)
                print("\t.byte\t%d\n",   v.u);
        else if (suffix == I && size == 2)
                print("\t.word\t%d\n",   v.i);
        else if (suffix == I && size == 4)
                print("\t.long\t%d\n",   v.i);
        else if (suffix == U && size == 1)
                print("\t.byte\t0x%x\n", v.u);
        else if (suffix == U && size == 2)
                print("\t.word\t0x%x\n", v.u);
        else if (suffix == U && size == 4)
                print("\t.long\t0x%x\n", v.u);
        else if (suffix == P && size == 4)
                print("\t.long\t0x%x\n", v.p);
        else if (suffix == F && size == 4) {
                float f = v.d;
                print("\t.long\t0x%x\n", *(unsigned *)&f);
        }
        else if (suffix == F && size == 8) {
                double d = v.d;
                unsigned *p = (unsigned *)&d;
                print("\t.long\t0x%x\n\t.long\t0x%x\n", p[swap], p[!swap]);
        }
        else assert(0);
}
static void defaddress(Symbol p) {
        print("\t.long\t%s\n", p->x.name);
}
static void defstring(int n, char *str) {
        char *s;

        for (s = str; s < str + n; s++)
                print("\t.byte\t%d\n", (*s)&0377);
}
static void export(Symbol p) {
        print("\t.globl\t%s\n", p->x.name);
}
static void import(Symbol p) {
        int oldseg = cseg;

        if (p->ref > 0) {
                segment(0);
                print("\t.extern\t%s\n", p->x.name);
                segment(oldseg);
        }
}
static void global(Symbol p) {
	print("\t.align\t%d\n", p->type->align > 4 ? 4 : p->type->align);
	if (!p->generated)
		print("\t.type\t%s,@%s\n", p->x.name,
			isfunc(p->type) ? "function" : "object");
	if (p->u.seg == BSS) {
		if (p->sclass == STATIC)
			print("\t.lcomm\t%s,%d\n", p->x.name, p->type->size);
		else 
			print("\t.comm\t%s,%d\n", p->x.name, p->type->size);
	} else {
		if (!p->generated) 
			print("\t.size\t%s,%d\n", p->x.name, p->type->size);
		print("%s:\n", p->x.name);
	}
}
static void space(int n) {
        if (cseg != BSS)
		print("\t.space\t%d\n", n);
}

#include <stab.h>
static char *currentfile;       /* current file name */
static int ntypes;

/*
 * emittype - emit ty's type number, emitting its definition if necessary.
 * Returns the output column number after emission; col is the approximate
 * output column before emission and is used to emit continuation lines for long
 * struct, union, and enum types. Continuations are not emitted for other types,
 * even if the definition is long. lev is the depth of calls to emittype.
 */
static int emittype(ty, lev, col) Type ty; {
	int tc = ty->x.typeno;

	if (isconst(ty) || isvolatile(ty)) {
		col = emittype(ty->type, lev, col);
		ty->x.typeno = ty->type->x.typeno;
		ty->x.printed = 1;
		return col;
	}
	if (tc == 0) {
		ty->x.typeno = tc = ++ntypes;
/*              fprint(2,"`%t'=%d\n", ty, tc); */
	}
	print("%d", tc), col += 3;
	if (ty->x.printed)
		return col;
	ty->x.printed = 1;
	switch (ty->op) {
	case VOID:	/* void is defined as itself */
		print("=%d", tc), col += 1+3;
		break;
	case CHAR:	/* unsigned char is a subrange of int */
		if (ty == unsignedchar)
			print("=r1;0;255;"), col += 10;
		else	/* following pcc, char is a subrange of itself */
			print("=r%d;-128;127;", tc), col += 2+3+10;
		break;
	case SHORT:	/* short is a subrange of int */
		if (ty == unsignedshort)
			print("=r1;0;65535;"), col += 12;
		else	/* signed */
			print("=r1;-32768;32767;"), col += 17;
		break;
	case INT:	/* int is a subrange of itself */
		print("=r1;%d;%d;", INT_MIN, INT_MAX), col += 4+11+1+10+1;
		break;
	case UNSIGNED:	/* unsigned is a subrange of int */
		print("=r1;0;-1;"), col += 9;
		break;
	case FLOAT:
	case DOUBLE:	/* float, double get sizes instead of ranges */
		print("=r1;%d;0;", ty->size), col += 4+1+3;
		break;
	case POINTER:
		print("=*"), col += 2;
		col = emittype(ty->type, lev + 1, col);
		break;
	case FUNCTION:
		print("=f"), col += 2;
		col = emittype(ty->type, lev + 1, col);
		break;
	case ARRAY:	/* array includes subscript as an int range */
		if (ty->size && ty->type->size)
			print("=ar1;0;%d;", ty->size/ty->type->size - 1), col += 7+3+1;
		else
			print("=ar1;0;-1;"), col += 10;
		col = emittype(ty->type, lev + 1, col);
		break;
	case STRUCT: case UNION: {
		Field p;
		if (!ty->u.sym->defined) {
			print("=x%c%s:", ty->op == STRUCT ? 's' : 'u', ty->u.sym->name);
			col += 2+1+strlen(ty->u.sym->name)+1;
			break;
		}
		if (lev > 0 && (*ty->u.sym->name < '0' || *ty->u.sym->name > '9')) {
			ty->x.printed = 0;
			break;
		}
		print("=%c%d", ty->op == STRUCT ? 's' : 'u', ty->size), col += 1+1+3;
		for (p = fieldlist(ty); p; p = p->link) {
			if (p->name)
				print("%s:", p->name), col += strlen(p->name)+1;
			else
				print(":"), col += 1;
			col = emittype(p->type, lev + 1, col);
			if (p->lsb)
				print(",%d,%d;", 8*p->offset +
					(IR->little_endian ? fieldright(p) : fieldleft(p)),
					fieldsize(p));
			else
				print(",%d,%d;", 8*p->offset, 8*p->type->size);
			col += 1+3+1+3+1;	/* accounts for ,%d,%d; */
			if (col >= 80 && p->link) {
				print("\\\\\",%d,0,0,0\n.stabs \"", N_LSYM);
				col = 8;
			}
		}
		print(";"), col += 1;
		break;
		}
	case ENUM: {
		Symbol *p;
		if (lev > 0 && (*ty->u.sym->name < '0' || *ty->u.sym->name > '9')) {
			ty->x.printed = 0;
			break;
		}
		print("=e"), col += 2;
		for (p = ty->u.sym->u.idlist; *p; p++) {
			print("%s:%d,", (*p)->name, (*p)->u.value), col += strlen((*p)->name)+3;
			if (col >= 80 && p[1]) {
				print("\\\\\",%d,0,0,0\n.stabs \"", N_LSYM);
				col = 8;
			}
		}
		print(";"), col += 1;
		break;
		}
	default:
		assert(0);
	}
	return col;
}

/* dbxout - output .stabs entry for type ty */
static void dbxout(ty) Type ty; {
	ty = unqual(ty);
	if (!ty->x.printed) {
		int col = 0;
		print(".stabs \""), col += 8;
		if (ty->u.sym && !(isfunc(ty) || isarray(ty) || isptr(ty)))
			print("%s", ty->u.sym->name), col += strlen(ty->u.sym->name);
		print(":%c", isstruct(ty) || isenum(ty) ? 'T' : 't'), col += 2;
		emittype(ty, 0, col);
		print("\",%d,0,0,0\n", N_LSYM);
	}
}

/* asgncode - assign type code to ty */
static void asgncode(ty, lev) Type ty; {
	if (ty->x.marked || ty->x.typeno)
		return;
	ty->x.marked = 1;
	switch (ty->op) {
	case VOLATILE: case CONST: case VOLATILE+CONST:
		asgncode(ty->type, lev);
		ty->x.typeno = ty->type->x.typeno;
		break;
	case POINTER: case FUNCTION: case ARRAY:
		asgncode(ty->type, lev + 1);
		/* fall thru */
	case VOID: case CHAR: case SHORT: case INT: case UNSIGNED:
	case FLOAT: case DOUBLE:
		break;
	case STRUCT: case UNION: {
		Field p;
		for (p = fieldlist(ty); p; p = p->link)
			asgncode(p->type, lev + 1);
		/* fall thru */
	case ENUM:
		if (ty->x.typeno == 0)
			ty->x.typeno = ++ntypes;
		if (lev > 0 && (*ty->u.sym->name < '0' || *ty->u.sym->name > '9'))
			dbxout(ty);
		break;
		}
	default:
		assert(0);
	}
}

/* dbxtype - emit a stabs entry for type ty, return type code */
static int dbxtype(ty) Type ty; {
        asgncode(ty, 0);
        dbxout(ty);
        return ty->x.typeno;
}

/* stabsym - output a stab entry for symbol p */
static void stabsym(p) Symbol p; {
	int code, tc, sz = p->type->size;

	if (p->generated || p->computed)
		return;
	if (isfunc(p->type)) {
		print(".stabs \"%s:%c%d\",%d,0,0,%s\n", p->name,
			p->sclass == STATIC ? 'f' : 'F', dbxtype(freturn(p->type)),
			N_FUN, p->x.name);
		return;
	}
	if (!IR->wants_argb && p->scope == PARAM && p->structarg) {
		assert(isptr(p->type) && isstruct(p->type->type));
		tc = dbxtype(p->type->type);
		sz = p->type->type->size;
	} else
		tc = dbxtype(p->type);
	if (p->sclass == AUTO && p->scope == GLOBAL || p->sclass == EXTERN) {
		print(".stabs \"%s:G", p->name);
		code = N_GSYM;
	} else if (p->sclass == STATIC) {
		print(".stabs \"%s:%c%d\",%d,0,0,%s\n", p->name, p->scope == GLOBAL ? 'S' : 'V',
			tc, p->u.seg == BSS ? N_LCSYM : N_STSYM, p->x.name);
		return;
	} else if (p->sclass == REGISTER) {
		if (p->scope > PARAM) {
			int r = p->x.regnode->number;
			if (p->x.regnode->set == FREG)
				r += 32;	/* floating point */
			print(".stabs \"%s:r%d\",%d,0,", p->name, tc, N_RSYM);
			print("%d,%d\n", sz, r);
		}
		return;
	} else if (p->scope == PARAM) {
		print(".stabs \"%s:p", p->name);
		code = N_PSYM;
	} else if (p->scope >= LOCAL) {
		print(".stabs \"%s:", p->name);
		code = N_LSYM;
	} else
		assert(0);
	print("%d\",%d,0,0,%s\n", tc, code,
		p->scope >= PARAM && p->sclass != EXTERN ? p->x.name : "0");
}

/* stabtype - output a stab entry for type *p */
static void stabtype(p) Symbol p; {
	if (p->type) {
		if (p->sclass == 0)
			dbxtype(p->type);
		else if (p->sclass == TYPEDEF)
			print(".stabs \"%s:t%d\",%d,0,0,0\n", p->name, dbxtype(p->type), N_LSYM);
	}
}

/* stabblock - output a stab entry for '{' or '}' at level lev */
static void stabblock(brace, lev, p) Symbol *p; {
	if (brace == '{')
		while (*p)
			stabsym(*p++);
	print(".stabd 0x%x,0,%d\n", brace == '{' ? N_LBRAC : N_RBRAC, lev);
}

/* stabinit - initialize stab output */
static void stabinit(file, argc, argv) char *file; int argc; char *argv[]; {
	typedef void (*Closure) (Symbol, void *);

	if (file && *file) {
		(*IR->segment)(CODE);
		print("Ltext:.stabs \"%s\",0x%x,0,0,Ltext\n", file, N_SO);
		currentfile = file;
	}
	dbxtype(inttype);
	dbxtype(chartype);
	dbxtype(doubletype);
	dbxtype(floattype);
	dbxtype(longdouble);
	dbxtype(longtype);
	dbxtype(shorttype);
	dbxtype(signedchar);
	dbxtype(unsignedchar);
	dbxtype(unsignedlong);
	dbxtype(unsignedshort);
	dbxtype(unsignedtype);
	dbxtype(voidtype);
	foreach(types, GLOBAL, (Closure)stabtype, NULL);
}

/* stabline - emit stab entry for source coordinate *cp */
static void stabline(cp) Coordinate *cp; {
	if (cp->file && cp->file != currentfile) {
		int lab = genlabel(1);
		print("L%d: .stabs \"%s\",0x%x,0,0,L%d\n", lab,
				cp->file, N_SOL, lab);
		currentfile = cp->file;
	}
	print(".stabd 0x%x,0,%d\n", N_SLINE, cp->y);
}

Interface x86bsdIR = {
        1, 1, 0,  /* char */
        2, 2, 0,  /* short */
        4, 4, 0,  /* int */
        4, 4, 0,  /* long */
	4, 4, 0,  /* long long */
        4, 4, 1,  /* float */
        8, 4, 1,  /* double */
        8, 4, 1,  /* long double */
        4, 4, 0,  /* T * */
        0, 4, 0,  /* struct; so that ARGB keeps stack aligned */
        1,        /* little_endian */
        0,        /* mulops_calls */
        0,        /* wants_callb */
        1,        /* wants_argb */
        0,        /* left_to_right */
        0,        /* wants_dag */
	0,	  /* unsigned char */
        address,
        blockbeg,
        blockend,
        defaddress,
        defconst,
        defstring,
        defsymbol,
        emit,
        export,
        function,
        gen,
        global,
        import,
        local,
        progbeg,
        progend,
        segment,
        space,
        stabblock, 0, 0, stabinit, stabline, stabsym, stabtype,
        {1, rmap,
            blkfetch, blkstore, blkloop,
            _label,
            _rule,
            _nts,
            _kids,
            _string,
            _templates,
            _isinstruction,
            _ntname,
            emit2,
            doarg,
            target,
            clobber,
	}
};
Interface x86bsdelfIR = {
        1, 1, 0,  /* char */
        2, 2, 0,  /* short */
        4, 4, 0,  /* int */
        4, 4, 0,  /* long */
	4, 4, 0,  /* long long */
        4, 4, 1,  /* float */
        8, 4, 1,  /* double */
        8, 4, 1,  /* long double */
        4, 4, 0,  /* T * */
        0, 4, 0,  /* struct; so that ARGB keeps stack aligned */
        1,        /* little_endian */
        0,        /* mulops_calls */
        0,        /* wants_callb */
        1,        /* wants_argb */
        0,        /* left_to_right */
        0,        /* wants_dag */
	0,	  /* unsigned char */
        address,
        blockbeg,
        blockend,
        defaddress,
        defconst,
        defstring,
        defsymbolelf,
        emit,
        export,
        function,
        gen,
        global,
        import,
        local,
        progbeg,
        progend,
        segment,
        space,
        stabblock, 0, 0, stabinit, stabline, stabsym, stabtype,
        {1, rmap,
            blkfetch, blkstore, blkloop,
            _label,
            _rule,
            _nts,
            _kids,
            _string,
            _templates,
            _isinstruction,
            _ntname,
            emit2,
            doarg,
            target,
            clobber,
	}
};
