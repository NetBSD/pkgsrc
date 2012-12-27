$NetBSD: patch-te__subs.c,v 1.1 2012/12/27 06:13:20 dholland Exp $

- declare void functions void
- don't index arrays with (signed) char
- use <ctype.h> functions correctly

--- te_subs.c.orig	1995-04-25 15:02:59.000000000 +0000
+++ te_subs.c
@@ -21,7 +21,7 @@
 /*    n is the returned number of chars moved	*/
 /* max is the maximum number of chars to move	*/
 
-movenchars(from, to, n)
+VOID movenchars(from, to, n)
 	struct qp *from, *to;		/* address of buffer pointers */
 	register int n;				/* number of characters */
 {
@@ -80,7 +80,8 @@ movenchars(from, to, n)
 		to->c = tc;
 	}
 }
-moveuntil(from, to, c, n, max, trace)
+
+VOID moveuntil(from, to, c, n, max, trace)
 	struct qp *from, *to;		/* address of buffer pointers	*/
 	register char c;			/* match char that ends move	*/
 	int *n;						/* pointer to returned value	*/
@@ -166,7 +167,7 @@ int lines(arg)
 				if (!(p = p->b)) break;
 				c = CELLSIZE - 1;
 			}
-			if ( (ez_val & EZ_NOVTFF) ? (p->ch[c] == LF) : (spec_chars[p->ch[c]] & A_L) ) ++arg;	/* if line sep found */
+			if ( (ez_val & EZ_NOVTFF) ? (p->ch[c] == LF) : (spec_chars[(unsigned char)p->ch[c]] & A_L) ) ++arg;	/* if line sep found */
 		}
 		if (arg > 0) ++i;				/* if terminated on a line separator, advance over the separator */
 	}
@@ -175,7 +176,7 @@ int lines(arg)
 	{
 		for (i = pbuff->dot; (arg > 0) && (i < pbuff->z); i++)
 		{
-			if ( (ez_val & EZ_NOVTFF) ? (p->ch[c] == LF) : (spec_chars[p->ch[c]] & A_L) ) --arg;
+			if ( (ez_val & EZ_NOVTFF) ? (p->ch[c] == LF) : (spec_chars[(unsigned char)p->ch[c]] & A_L) ) --arg;
 			if (++c > CELLSIZE-1)
 			{
 				if (!(p = p->f)) break;
@@ -241,19 +242,19 @@ int getqspec(fors, c)	/* fors ("file or 
 	int fors;
 	char c;
 {
-	if (isdigit(c)) 
+	if (isdigit((unsigned char)c))
 		return(c - '0' + 1);
-	else if (isalpha(c)) return(mapch_l[c] - 'a' + 11);
+	else if (isalpha((unsigned char)c)) return(mapch_l[(unsigned char)c] - 'a' + 11);
 	else if (c == '`')
 	{
-		if (isdigit(c = getcmdc(trace_sw))) return (EXTQREGS + c - '0');
-		else if (isalpha(c)) return (EXTQREGS + 10 + mapch_l[c] - 'a');
+		if (isdigit((unsigned char)(c = getcmdc(trace_sw)))) return (EXTQREGS + c - '0');
+		else if (isalpha((unsigned char)c)) return (EXTQREGS + 10 + mapch_l[(unsigned char)c] - 'a');
 		else ERROR(E_IQN);
 	}
 	else if (c == '~')
 	{
-		if (isdigit(c = getcmdc(trace_sw))) return (EXTQREGS + NEXTQREGS/2 + c - '0');
-		else if (isalpha(c)) return (EXTQREGS + NEXTQREGS/2 + 10 + mapch_l[c] - 'a');
+		if (isdigit((unsigned char)(c = getcmdc(trace_sw)))) return (EXTQREGS + NEXTQREGS/2 + c - '0');
+		else if (isalpha((unsigned char)c)) return (EXTQREGS + NEXTQREGS/2 + 10 + mapch_l[(unsigned char)c] - 'a');
 		else ERROR(E_IQN);
 	}
 	else if (fors)
@@ -276,7 +277,7 @@ int getqspec(fors, c)	/* fors ("file or 
 
 struct buffcell *insert_p;
 
-insert1()
+VOID insert1(void)
 {
 	int nchars;				/* number of chars in cell */
 
@@ -293,7 +294,8 @@ insert1()
 
 	movenchars(&aa, &bb, nchars);	/* copy cell up to dot */
 }
-insert2(count)				/* count is the number of chars added */
+
+VOID insert2(count)				/* count is the number of chars added */
 	int count;
 {
 	aa.p->b->f = insert_p;		/* put the new cell where the old one was */
@@ -314,7 +316,7 @@ insert1()
 /* subroutine to delete n characters starting at dot	*/
 /* argument is number of characters						*/
 
-delete1(nchars)
+VOID delete1(nchars)
 	int nchars;
 {
 	if (!nchars) return;		/* 0 chars is a nop */
@@ -339,7 +341,7 @@ delete1(nchars)
 
 struct qh obuff;		/* tag string buffer */
 
-do_o()
+VOID do_o(void)
 {
 	int i, j;			/* i used as start of tag, j as end */
 	int p, level;		/* p is pointer to tag string, level is iteration lvl */
@@ -400,7 +402,7 @@ do_o()
 					for (p = i; p < j; p++)
 					{
 						if (getcmdc(0) == '!') epfound = 1;		/* mark "trailing ! found */
-						if (mapch_l[cmdc] != mapch_l[obuff.f->ch[p]]) break;	/* compare */
+						if (mapch_l[(unsigned char)cmdc] != mapch_l[(unsigned char)obuff.f->ch[p]]) break;	/* compare */
 					}
 					if (p >= j)			/* if all comparison chars matched */
 					{
@@ -426,7 +428,7 @@ char skipto(arg)
 
 	for (atsw = 0; ;)		/* forever		*/
 	{
-		while (!(ta = spec_chars[skipc = getcmdc(0)] & (A_X | A_S | A_T | A_Q)));	/* read until something interesting found */
+		while (!(ta = spec_chars[(unsigned char)(skipc = getcmdc(0))] & (A_X | A_S | A_T | A_Q)));	/* read until something interesting found */
 
 	again:
 		if (ta & A_Q) if((tb = getcmdc(0)) == '`' || tb == '~') getcmdc(0);		/* if command takes a Q spec, skip the spec */
@@ -440,7 +442,7 @@ char skipto(arg)
 			switch (skipc)
 			{
 				case '^':							/* treat next char as CTL */
-					if (ta = spec_chars[skipc = getcmdc(0) & 0x1f]) goto again;
+					if ((ta = spec_chars[(unsigned char)(skipc = getcmdc(0) & 0x1f)]) != 0) goto again;
 					break;
 
 				case '@':							/* use alternative text terminator */
@@ -464,7 +466,7 @@ char skipto(arg)
 
 				case 'e':							/* first char of two-letter E or F command */
 				case 'f':
-					if (spec_chars[getcmdc(0)] & ((skipc == 'e') ? A_E : A_F)) 		/* if one with a text arg */
+					if (spec_chars[(unsigned char)getcmdc(0)] & ((skipc == 'e') ? A_E : A_F)) 		/* if one with a text arg */
 					{
 						term = (atsw) ? getcmdc(0) : ESC;
 						atsw = 0;
@@ -485,7 +487,7 @@ char skipto(arg)
 
 /* find number of characters to next matching (, [, or {  (like '%' in vi) */
 
-do_ctlp()
+VOID do_ctlp(void)
 {
 	int i, l;
 	char c, c1;
