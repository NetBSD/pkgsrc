$NetBSD: patch-src_lib_sfio_Stdio__b_vsscanf.c,v 1.1 2013/09/10 14:18:11 joerg Exp $

--- src/lib/sfio/Stdio_b/vsscanf.c.orig	2013-09-10 12:06:32.000000000 +0000
+++ src/lib/sfio/Stdio_b/vsscanf.c
@@ -5,7 +5,7 @@
 */
 
 #if __STD_C
-int vsscanf(char* s, const char* form, va_list args)
+int vsscanf(const char* s, const char* form, va_list args)
 #else
 int vsscanf(s,form,args)
 reg char*	s;
