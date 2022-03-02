$NetBSD: patch-src_include_a68g-includes.h,v 1.1 2022/03/02 01:41:34 ryoon Exp $

* Fix compiler build for *BSD.

--- src/include/a68g-includes.h.orig	2022-02-01 20:45:41.000000000 +0000
+++ src/include/a68g-includes.h
@@ -66,7 +66,7 @@
 #include <dirent.h>
 #endif
 
-#if defined (HAVE_DL)
+#if defined (HAVE_DL) || defined(BUILD_BSD)
 #include <dlfcn.h>
 #endif
 
