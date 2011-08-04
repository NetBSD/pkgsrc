$NetBSD: patch-awk-run.c,v 1.1 2011/08/04 11:37:59 joerg Exp $

--- awk/run.c.orig	2011-08-03 11:53:06.000000000 +0000
+++ awk/run.c
@@ -377,7 +377,7 @@ Cell *jump(Node **a, int n)	/* break, co
 	return 0;	/* not reached */
 }
 
-Cell *getline(Node **a, int n)	/* get next line from specific input */
+Cell *my_getline(Node **a, int n)	/* get next line from specific input */
 {		/* a[0] is variable, a[1] is operator, a[2] is filename */
 	Cell *r, *x;
 	extern Cell **fldtab;
