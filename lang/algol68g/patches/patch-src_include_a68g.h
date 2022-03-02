$NetBSD: patch-src_include_a68g.h,v 1.1 2022/03/02 01:41:34 ryoon Exp $

* Enable compiler for *BSD.

--- src/include/a68g.h.orig	2022-02-01 20:45:41.000000000 +0000
+++ src/include/a68g.h
@@ -32,7 +32,7 @@
 
 // Build switches depending on platform.
 
-#if (defined (BUILD_LINUX) && defined (HAVE_GCC) && defined (HAVE_DL))
+#if (defined (BUILD_LINUX) && defined (HAVE_GCC) && defined (HAVE_DL)) || defined(BUILD_BSD)
 #  define BUILD_A68_COMPILER
 #else
 // Untested, so disabled.
