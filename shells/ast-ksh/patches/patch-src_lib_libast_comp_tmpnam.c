$NetBSD: patch-src_lib_libast_comp_tmpnam.c,v 1.1 2017/02/19 20:18:16 maya Exp $

Workaround "storage size of 'buf' isn't known",
likely from #define P_tmpdir in ast_stdio.h.

just define it to be a sensible size.

--- src/lib/libast/comp/tmpnam.c.orig	2006-09-22 15:28:13.000000000 +0000
+++ src/lib/libast/comp/tmpnam.c
@@ -38,9 +38,8 @@
 #define extern	__EXPORT__
 #endif
 
-#ifndef L_tmpnam
+#undef L_tmpnam /* Defined as sizeof(P_tmpdir) but P_tmpdir is defined as empty */
 #define L_tmpnam	25
-#endif
 
 extern char*
 tmpnam(char* s)
