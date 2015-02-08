$NetBSD: patch-dbench.h,v 1.1 2015/02/08 20:40:51 fhajny Exp $

Fix build on SunOS. Taken from bundled snprintf.c.

--- dbench.h.orig	2008-02-18 00:49:35.000000000 +0000
+++ dbench.h
@@ -92,6 +92,10 @@
 #define False 0
 #define uint32 unsigned
 
+#ifdef __sun
+#define MAX(p,q) (((p) >= (q)) ? (p) : (q))
+#endif
+
 struct op {
 	unsigned count;
 	double total_time;
