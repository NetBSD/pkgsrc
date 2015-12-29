$NetBSD: patch-intern.c,v 1.2 2015/12/29 23:34:56 dholland Exp $

Fix a number of cases of plainly invalid C and portability issues.

--- intern.c.orig	2015-11-06 16:15:17.000000000 +0000
+++ intern.c
@@ -39,11 +39,11 @@ FIXNUM hash(char *s, int len) {
     /* and Ullman's book, Compilers: Principles, Techniques, and */
     /* Tools; figure 7.35. */
 
-    unsigned FIXNUM h = 0, g;
+    unsigned long FIXNUM h = 0, g;
 
     while (--len >= 0) {
 	h = (h << 4) + (FIXNUM)(*s++);
-	g = h & (0xf << (WORDSIZE-4));
+	g = h & (0xfUL << (WORDSIZE-4));
 	if (g != 0) {
 	    h ^= g ^ (g >> (WORDSIZE-8));
 	}
