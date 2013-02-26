$NetBSD: patch-jhd.c,v 1.1 2013/02/26 11:06:52 joerg Exp $

--- jhd.c.orig	2013-02-25 15:34:57.000000000 +0000
+++ jhd.c
@@ -25,6 +25,8 @@ static char rcsid[] =
 
 #include  <stdio.h>
 #include  <ctype.h>
+#include  <unistd.h>
+#include  <string.h>
 
 #define  BSIZE      16384       /*  input buffer size */
 
@@ -534,7 +536,7 @@ register int     adv;
 	}
 }
 
-dmpall (buf, size)
+void dmpall (buf, size)
 register unsigned char   *buf;
 register int     size;
 {
@@ -728,8 +730,7 @@ char   *name;
 	exit (EXSTAT);
 }
 
-skipread (fp)
-FILE   *fp;
+void skipread(FILE *fp)
 {
 	register long   offset;
 
