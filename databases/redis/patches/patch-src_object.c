$NetBSD: patch-src_object.c,v 1.3 2015/04/13 11:33:35 fhajny Exp $

Add MirBSD support.

--- src/object.c.orig	2015-04-01 14:01:44.000000000 +0000
+++ src/object.c
@@ -32,7 +32,7 @@
 #include <math.h>
 #include <ctype.h>
 
-#ifdef __CYGWIN__
+#if defined(__CYGWIN__) || defined(__MirBSD__)
 #define strtold(a,b) ((long double)strtod((a),(b)))
 #endif
 
