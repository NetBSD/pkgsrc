$NetBSD: patch-src_compat_compat-basename.c,v 1.1 2013/07/30 18:57:30 jperkin Exp $

Sun ld needs at least one symbol.  This is as good a place to put
one as any..

--- src/compat/compat-basename.c.orig	2012-09-10 15:01:08.000000000 +0000
+++ src/compat/compat-basename.c
@@ -28,6 +28,10 @@
 #include "config-msvc.h"
 #endif
 
+#ifdef __sun
+int need_at_least_one_symbol = 0;
+#endif
+
 #ifndef HAVE_BASENAME
 
 #include "compat.h"
