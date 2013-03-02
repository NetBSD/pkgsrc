$NetBSD: patch-libraries.c,v 1.1 2013/03/02 18:21:39 joerg Exp $

--- libraries.c.orig	2013-03-01 15:01:58.000000000 +0000
+++ libraries.c
@@ -189,7 +189,7 @@ short *pagetotals(int page, short mode)
    int i;
    short *counts, *icount, *result;
 
-   if (xobjs.pagelist[page]->pageinst == NULL) return;
+   if (xobjs.pagelist[page]->pageinst == NULL) return NULL;
 
    counts = (short *)malloc(xobjs.pages * sizeof(short));
    icount = (short *)malloc(xobjs.pages * sizeof(short));
