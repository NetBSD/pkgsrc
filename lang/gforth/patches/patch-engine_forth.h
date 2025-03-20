$NetBSD: patch-engine_forth.h,v 1.1 2025/03/20 09:18:51 wiz Exp $

Provide evct prototype.

--- engine/forth.h.orig	2025-03-20 09:14:27.952948108 +0000
+++ engine/forth.h
@@ -490,7 +490,7 @@ extern double asinh(double r1);
 extern double acosh(double r1);
 #endif
 #ifndef HAVE_ECVT
-/* extern char* ecvt(double x, int len, int* exp, int* sign);*/
+extern char* ecvt(double x, int len, int* exp, int* sign);
 #endif
 #ifndef HAVE_MEMMOVE
 /* extern char *memmove(char *dest, const char *src, long n); */
