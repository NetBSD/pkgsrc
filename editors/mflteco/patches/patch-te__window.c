$NetBSD: patch-te__window.c,v 1.1 2012/12/27 06:13:20 dholland Exp $

- remove unused variables
- fix signed/unsigned issues
- use static for local functions
- declare own functions
- declare void functions void
- use c89
- don't index arrays with (signed) char
- patch up two uninitialized variables
- silence warnings about assignments in conditionals
- #if out unused function putchar_d()
- silence unnecessary pointer width warning

--- te_window.c.orig	1995-04-25 15:02:41.000000000 +0000
+++ te_window.c
@@ -78,16 +78,37 @@ char win_dlyc[] =   { 0, 2, 1, 0, 0, 0, 
 int rate[]  = { 0, 0, 9600, 4800, 2400, 1800, 1200, 600, 300, 200, 150, 134, 110 };
 #define NSPEEDS (sizeof(win_speeds) / sizeof(char))
 #endif
-int real_win_speed = 0;
+static unsigned real_win_speed = 0;
 #define win_speed  ((ez_val & EZ_NOFILL) ? 0: real_win_speed)
-static int brate = 0;
+
+static VOID window0(int num);
+static VOID window1_both(void);
+static VOID window1(void);
+static VOID window1_abs(void);
+static VOID window1_inc(int wd);
+static VOID window1_after(void);
+static VOID w_rmcurs(void);
+static VOID window2(int arg);
+static VOID vtm(int arg);
+static VOID w_makecurs(char wc, short crflag);
+static int w_overflow(int wd);
+static VOID w_type(char c, int m);
+static VOID w_init(void);
+static VOID w_separators(void);
+static VOID w_move(short y, short x);
+static VOID w_scroll(int count);
+static VOID w_ebol(void);
+static int w_setptr(struct bh *pbuff, register int loc,
+		    register struct qp *pp);
+static int w_lines(int n, register struct qp *ps, register struct qp *pd);
+
 /* routine to perform simple scope operations */
 /* (an attempt to concentrate VT-100 specific things in one place) */
 
-vt(func)
+VOID vt(func)
 	int func;
 {
-	short t;
+	unsigned t;
 	switch (func)
 	{
 		case VT_CLEAR:			/* clear screen */
@@ -141,7 +162,7 @@ int win_min[]  = { 4,  20,		4,		 0, 0,	 
 int win_max[]  = { 4,  W_MAX_H,	W_MAX_V, 3, MAX, 12, -1,  20,	20,	-1,	-1 } ;	/* max values */
 int win_data[] = { 4,  132,		24,		 0, 0,	  0,  0,   0,	 0,	 0,	 0 } ;	/* window parameters	*/
 
-do_window(ref_flag)
+VOID do_window(ref_flag)
 	int ref_flag;					/* nonzero forces "refresh" operation */
 {
 	int i;
@@ -149,7 +170,7 @@ do_window(ref_flag)
 	if (colonflag && !ref_flag)
 	{
 		i = get_value(0);	/* get sub-function */
-		if ((i < 0) || (i > (sizeof(win_data)/sizeof(int)))) ERROR(E_IWA);
+		if ((i < 0) || (i > (int)(sizeof(win_data)/sizeof(int)))) ERROR(E_IWA);
 		if (!esp->flag2)	/* it's a "get" */
 		{
 			esp->val1 = win_data[i];
@@ -205,7 +226,7 @@ do_window(ref_flag)
 /* routine to update screen size with numbers obtained from environment	*/
 /* (called by main program's initialization)							*/
 
-set_term_par(lines, cols)
+VOID set_term_par(lines, cols)
 	int lines, cols;
 {
 	if ((lines >= win_min[2]) && (lines <= win_max[2])) win_1.size = win_data[2] = lines, win_1.end = lines - 1;
@@ -223,7 +244,7 @@ set_term_par(lines, cols)
 /* WIN_LINE:	does WIN_REFR unless that wouldn't do anything, in which case		*/
 /*				it does effective 1EV output										*/
 
-window(arg)
+VOID window(arg)
 	int arg;
 {
 	int i;
@@ -308,8 +329,7 @@ window(arg)
 /* used for ev, es, and <BS> or <LF> as immediate commands					*/
 /* starting char position is in w_p1; argument is number of lines			*/
 
-window0(num)
-int num; 
+static VOID window0(int num)
 {
 	int wi;
 	char wc;			/* temp char */
@@ -319,7 +339,7 @@ int num; 
 	{
 		wc = w_p1.p->ch[w_p1.c];		/* get character */
 
-		if ((char_count >= WN_width) && (wc != CR) && !(spec_chars[wc] & A_L))	/* if about to exceed width */
+		if ((char_count >= WN_width) && (wc != CR) && !(spec_chars[(unsigned char)wc] & A_L))	/* if about to exceed width */
 		{
 			if (et_val & ET_TRUNC) goto w0_noprint;			/* truncate: don't print this */
 			else
@@ -383,7 +403,7 @@ int num; 
 
 struct bh *old_pbuff;
 
-window1_both()
+static VOID window1_both(void)
 {
 	pw0 = &win_1;
 	pb0 = &buffs[0];
@@ -414,12 +434,14 @@ window1_both()
 /* if scroll mode is enabled, the VT100 screen is split and only the upper part */
 /* is used by this routine; else the whole screen is used.						*/
 
-window1()
+static VOID window1(void)
 {
 	int i, j, m, lflag;
 	register struct bh *pb = pb0;
 	register struct w_data *pw = pw0;
 
+	lflag = 0; /* XXX is this right? */
+
 	/* return if nothing has changed */
 	if (!redraw_sw && (pbuff == old_pbuff) && (pb->dot == pw->last_dot) && (pb->buff_mod == MAX)) return;
 
@@ -514,7 +536,7 @@ window1()
 }
 /* routine to redraw screen absolutely */
 
-window1_abs()
+static VOID window1_abs(void)
 {
 	int i, j;
 	struct bh *save_pbuff;								/* save old pbuff during set_pointer call */
@@ -545,8 +567,8 @@ window1_abs()
 
 /* redraw screen incrementally */
 
-window1_inc(wd)
-	int wd;						/* argument is earliest change */
+static VOID window1_inc(int wd)
+			/* argument is earliest change */
 {
 	short temp_y;
 	register struct bh *pb = pb0;
@@ -572,12 +594,14 @@ window1_inc(wd)
 }
 /* routine to move window downwards: scroll up or redraw as appropriate */
 
-window1_after()
+static VOID window1_after(void)
 {
 	int i, lflag;
 	register struct bh *pb = pb0;
 	register struct w_data *pw = pw0;
 
+	lflag = 0; /* XXX: is this right? */
+
 	w_rmcurs();						/* remove old cursor */
 	w_setptr(pb, wlp[pw->end]->start, &w_p1);		/* set pointer to start of last line on screen */
 
@@ -604,7 +628,7 @@ window1_after()
 
 /* routine to remove the existing cursor */
 
-w_rmcurs()
+static VOID w_rmcurs(void)
 {
 	register struct w_data *pw = pw0;
 
@@ -621,8 +645,7 @@ w_rmcurs()
 /* called with w_p1 at starting char, curr_y, curr_x at starting coordinate			*/
 /* rewrites to end of screen if arg = 0, or only until line with cursor if arg = 1	*/
 
-window2(arg)
-	int arg;
+static VOID window2(int arg)
 {
 	register struct bh *pb = pb0;
 	register struct w_data *pw = pw0;
@@ -635,7 +658,7 @@ window2(arg)
 	for (wdot = w_p1.dot; (curr_y <= pw->end) && (wdot < pb->z); wdot++)		/* for each character */
 	{
 		wc = w_p1.p->ch[w_p1.c] & 0177;		/* get character */
-		if (dflag = (wdot == pb->dot)) if (arg) arg = -1;		/* save "this is char at dot", "on line with dot" */
+		if ((dflag = (wdot == pb->dot)) != 0) if (arg) arg = -1;		/* save "this is char at dot", "on line with dot" */
 
 		if (wc < ' ') switch (wc)				/* dispatch control characters */
 		{
@@ -821,7 +844,7 @@ window2(arg)
 			wc = 'c';     /* get character */
 		else
 			wc = '`';     /* get character */
-		if (dflag = (wdot == pb->dot)) if (arg) arg = -1;		/* save "this is char at dot", "on line with dot" */
+		if ((dflag = (wdot == pb->dot)) != 0) if (arg) arg = -1;		/* save "this is char at dot", "on line with dot" */
 		if (curr_x >= WN_width)
 		{
 			if (et_val & ET_TRUNC) goto noprint;
@@ -856,8 +879,7 @@ window2(arg)
 }
 /* routine to move cursor to current location and then call vt */
 
-vtm(arg)
-	int arg;
+static VOID vtm(int arg)
 {
 	w_move(curr_y, curr_x);
 	vt(arg);
@@ -869,9 +891,7 @@ vtm(arg)
 /* routine to set reverse video and save cursor location */
 /* first argument is char at cursor, 2nd is value for curs_crflag */
 
-w_makecurs(wc, crflag)
-	char wc;
-	short crflag;
+static VOID w_makecurs(char wc, short crflag)
 {
 	register struct w_data *pw = pw0;
 
@@ -888,7 +908,7 @@ w_makecurs(wc, crflag)
 /* returns nonzero if at end of screen, zero otherwise */
 /* arg is current character position */
 
-int w_overflow(wd)
+static int w_overflow(int wd)
 {
 	register struct w_data *pw = pw0;
 
@@ -912,12 +932,11 @@ int w_overflow(wd)
 /* routine to type one character:  arguments are char and a */
 /* "mark" bit.  If mark is set, the char is always retyped  */
 
-w_type(c, m)
+static VOID w_type(c, m)
 	char c;
 	int m;
 {
 	register char *p;
-	register struct w_data *pw = pw0;
 
 	p = &wlp[curr_y]->ch[curr_x];		/* pointer to char image */
 	if ((c != *p) || (m) || (redraw_sw) || (curr_x >= wlp[curr_y]->n))
@@ -936,7 +955,7 @@ w_type(c, m)
 
 /* initialize display image */
 
-w_init()
+static VOID w_init(void)
 {
 	short i, j;
 
@@ -968,7 +987,7 @@ w_init()
 
 /* write separator lines between windows on screen */
 
-w_separators()
+static VOID w_separators(void)
 {
 	int i;
 
@@ -990,29 +1009,30 @@ w_separators()
 /* put character followed by appropriate number of nulls for "other control function" */
 /* if argument is 0, output filler chars only */
 
-putchar_d(c)
-	char c;
+#if 0 /* not used */
+static VOID putchar_d(char c)
 {
-	int i;
+	unsigned i;
 
 	if (c) putchar(c);												/* output character */
 	for (i = 0; i < win_dlyc[win_speed]; i++) putchar('\0');		/* output filler */
 }
+#endif
 
 
 
 /* put out appropriate number of filler chars for display function that scrolls (LF, etc.) */
 
-scroll_dly()
+VOID scroll_dly(void)
 {
-	int i;
+	unsigned i;
 
 	for (i = 0; i < win_dlys[win_speed]; i++) putchar('\0');		/* output filler */
 }
 /* move terminal cursor to stated y, x position */
 /* uses incremental moves or absolute cursor position, whichever is shorter */
 
-w_move(y, x)
+static VOID w_move(y, x)
 	short y, x;
 {
 	register short i;
@@ -1052,10 +1072,9 @@ w_move(y, x)
 }
 /* scroll screen: argument is count: + up, - down */
 
-w_scroll(count)
-	int count;
+static VOID w_scroll(int count)
 {
-	register int i, ic;
+	register int i;
 	struct w_line *p[W_MAX_V];					/* temp copy of pointer array */
 	register struct w_data *pw = pw0;
 
@@ -1084,10 +1103,9 @@ w_scroll(count)
 /* clear line to left of curr_x */
 /* if some chars nonblank, does erase from start of line */
 
-w_ebol()
+static VOID w_ebol(void)
 {
 	short i, j;
-	register struct w_data *pw = pw0;
 
 	for (j = i = 0; i < curr_x; i++) if (wlp[curr_y]->ch[i] != ' ') wlp[curr_y]->ch[i] = ' ', j++;
 	if (j || redraw_sw) w_move(curr_y, curr_x-1), vt(VT_EBOL);
@@ -1098,7 +1116,7 @@ w_ebol()
 /* routine to set a pointer to a given location (like set_pointer) */
 /* returns nonzero if a text buffer exists, otherwise 0 */
 
-int w_setptr(pbuff, loc, pp)
+static int w_setptr(pbuff, loc, pp)
 	struct bh *pbuff;				/* current buffer header */
 	register int loc;				/* location */
 	register struct qp *pp;			/* address of pointer */
@@ -1111,7 +1129,7 @@ int w_setptr(pbuff, loc, pp)
 		pp->c = loc % CELLSIZE;
 		pp->dot = loc;
 	}
-	return( (int) pbuff->f);
+	return( pbuff->f != NULL );
 }
 /* routine to move N lines (back, forward, or 0)				*/
 /* w_lines(n, &source, &dest) where n is the line count, source	*/
@@ -1121,7 +1139,7 @@ int w_setptr(pbuff, loc, pp)
 
 struct qp w_lines_p;				/* to compute # of display lines in -N lines */
 
-int w_lines(n, ps, pd)
+static int w_lines(n, ps, pd)
 	int n;							/* number of lines */
 	register struct qp *ps, *pd;	/* source, destination qp's */
 {
@@ -1138,7 +1156,7 @@ int w_lines(n, ps, pd)
 	{
 		for (tcnt = tl = tn = 0; (tn < n) && (tdot < pb0->z); tdot++)	/* forward over N line separators */
 		{
-			if (spec_chars[ tch = tp->ch[tc] ] & A_L) ++tl, ++tn;		/* count separators */
+			if (spec_chars[ (unsigned char)(tch = tp->ch[tc]) ] & A_L) ++tl, ++tn;		/* count separators */
 			else if (!(et_val & ET_TRUNC))		/* if text lines can overflow screen lines */
 			{
 				if (!(tch & 0140))				/* if character is a control char */
@@ -1166,7 +1184,7 @@ int w_lines(n, ps, pd)
 		{
 			--tdot;
 			if (--tc < 0) tp = tp->b, tc = CELLSIZE -1;
-			if (spec_chars[tp->ch[tc]] & A_L) --tn;
+			if (spec_chars[(unsigned char)tp->ch[tc]] & A_L) --tn;
 		}
 		if (tn < n)			/* if stopped on a line sep, fwd over it */
 		{
@@ -1187,8 +1205,7 @@ int w_lines(n, ps, pd)
 }
 /* routine to move n chars on line */
 /* call with # of columns, return new dot value */
-int x_to_dot(x)
-	int x;
+static int x_to_dot(int x)
 {
 	struct qp m_dot;
 	int m_count;
@@ -1227,7 +1244,7 @@ int last_dis_buff;
 int last_dis_x;
 int last_dis_wrap;
 
-VOID display_lines()
+VOID display_lines(void)
 {
 	int dis_buff = (pbuff == &buffs[0]) ? 0 : 1 ;		/* current buffer */
 	struct w_data *pw = dis_buff ? &win_2 : &win_1 ;
