$NetBSD: patch-deps_hiredis_fmacros.h,v 1.3 2015/04/13 11:33:35 fhajny Exp $

Add MirBSD support.
--- deps/hiredis/fmacros.h.orig	2015-04-01 14:01:44.000000000 +0000
+++ deps/hiredis/fmacros.h
@@ -11,6 +11,7 @@
 
 #if defined(__sun__)
 #define _POSIX_C_SOURCE 200112L
+#elif defined(__MirBSD__)
 #elif defined(__linux__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #define _XOPEN_SOURCE 600
 #else
