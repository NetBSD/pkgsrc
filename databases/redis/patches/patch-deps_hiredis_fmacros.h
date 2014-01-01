$NetBSD: patch-deps_hiredis_fmacros.h,v 1.1 2014/01/01 16:08:24 bsiegert Exp $

--- deps/hiredis/fmacros.h.orig	Wed Aug 28 09:36:00 2013
+++ deps/hiredis/fmacros.h
@@ -7,6 +7,7 @@
 
 #if defined(__sun__)
 #define _POSIX_C_SOURCE 200112L
+#elif defined(__MirBSD__)
 #elif defined(__linux__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #define _XOPEN_SOURCE 600
 #else
