$NetBSD: patch-src-ed-fileio.c,v 1.1 2011/09/25 19:53:07 joerg Exp $

--- src/ed/fileio.c.orig	2011-09-25 09:18:25.000000000 +0000
+++ src/ed/fileio.c
@@ -20,11 +20,11 @@ typedef struct {
 } fiocontext;
 
 /*
- * NAME:	getline()
+ * NAME:	my_getline()
  * DESCRIPTION:	read a line from the input, return as '\0'-terminated string
  *		without '\n'
  */
-static char *getline(ptr)
+static char *my_getline(ptr)
 char *ptr;
 {
     register fiocontext *x;
@@ -126,7 +126,7 @@ io *iobuf;
 	P_close(x.fd);
 	error((char *) NULL);	/* pass on error */
     }
-    eb_add(eb, l, getline, (char *) &x);
+    eb_add(eb, l, my_getline, (char *) &x);
     ec_pop();
     P_close(x.fd);
 
