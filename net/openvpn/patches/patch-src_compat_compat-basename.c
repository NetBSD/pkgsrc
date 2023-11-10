$NetBSD: patch-src_compat_compat-basename.c,v 1.2 2023/11/10 00:17:47 gdt Exp $

Sun ld needs at least one symbol.  This is as good a place to put
one as any..

\todo File this upstream.

--- src/compat/compat-basename.c.orig	2023-11-08 15:49:40.000000000 +0000
+++ src/compat/compat-basename.c
@@ -25,6 +25,10 @@
 #include "config.h"
 #endif
 
+#ifdef __sun
+int need_at_least_one_symbol = 0;
+#endif
+
 #ifndef HAVE_BASENAME
 
 #include "compat.h"
