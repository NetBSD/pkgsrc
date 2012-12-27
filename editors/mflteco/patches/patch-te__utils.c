$NetBSD: patch-te__utils.c,v 1.1 2012/12/27 06:13:20 dholland Exp $

- use standard headers
- don't declare own malloc
- fix signed/unsigned mismatches
- remove useless/dangerous cast
- declare void functions void
- avoid implicit int
- don't index arrays with signed char

--- te_utils.c.orig	1993-08-05 22:29:35.000000000 +0000
+++ te_utils.c
@@ -7,6 +7,7 @@
 /* improved dly_freebuf 03/30/92  11.23										*/
 
 #include "te_defs.h"
+#include <stdlib.h>
 
 /* routines to handle storage */
 /* get a buffcell */
@@ -14,13 +15,12 @@
 
 struct buffcell *get_bcell()
 {
-	char *malloc();
 	struct buffcell *p;
-	int i;
+	unsigned i;
 
 	if (freebuff == NULL)
 	{
-		p = (struct buffcell *) malloc(BLOCKSIZE);
+		p = malloc(BLOCKSIZE);
 		if (!p) ERROR(E_MEM);
 		else
 		{
@@ -40,7 +40,7 @@ struct buffcell *get_bcell()
 
 
 /* free a list of buffcells */
-free_blist(p)
+VOID free_blist(p)
 	struct buffcell *p;
 {
 	struct buffcell *t;
@@ -53,7 +53,7 @@ free_blist(p)
 	}
 }
 /* free a list of buffcells to the "delayed free" list */
-dly_free_blist(p)
+VOID dly_free_blist(p)
 	struct buffcell *p;
 {
 	struct buffcell *t;
@@ -110,7 +110,7 @@ VOID reset_q_usecounts()
 struct is *get_dcell()
 {
 	struct is *t;
-	int i;
+	unsigned i;
 
 	if (freedcell == NULL)
 	{
@@ -129,7 +129,7 @@ struct is *get_dcell()
 }
 /* build a buffer:  called with address of a qh */
 /* if no buffer there, get a cell and link it in */
-make_buffer(p)
+VOID make_buffer(p)
 	struct qh *p;
 {
 	if (!(p->f))
@@ -163,7 +163,7 @@ int fwdc(arg)
 	return(1);
 }
 
-fwdcx(arg)
+int fwdcx(arg)
 	struct qp *arg;
 {
 	if ((*arg).c >= CELLSIZE-1)		/* test char count for max */
@@ -200,7 +200,7 @@ fwdcx(arg)
 
 /* set up a pointer to a particular text buffer position */
 
-set_pointer(pos, ptr)	/* first arg is position, 2nd is addr of pointer */
+VOID set_pointer(pos, ptr)	/* first arg is position, 2nd is addr of pointer */
 	int pos;
 	struct qp *ptr;
 {
@@ -225,7 +225,7 @@ set_pointer(pos, ptr)	/* first arg is po
 /* if pushcmdc() has returned any chars, read them first	*/
 /* routines type characters as read, if argument != 0		*/
 
-char getcmdc0(trace)
+char getcmdc0(int trace)
 {
 	while (cptr.dot >= cptr.z)		/* if at end of this level, pop macro stack */
 	{
@@ -252,7 +252,7 @@ char getcmdc0(trace)
 }
 
 
-char getcmdc(trace)
+char getcmdc(int trace)
 {
 	if (cptr.dot++ >= cptr.z) ERROR((msp <= &mstack[0]) ? E_UTC : E_UTM);
 	else
@@ -273,5 +273,5 @@ char getcmdc(trace)
 int peekcmdc(arg)
 	char arg;
 {
-	return(((cptr.dot < cptr.z) && (mapch_l[cptr.p->ch[cptr.c]] == mapch_l[arg])) ? 1 : 0);
+	return(((cptr.dot < cptr.z) && (mapch_l[(unsigned char)cptr.p->ch[cptr.c]] == mapch_l[(unsigned char)arg])) ? 1 : 0);
 }
