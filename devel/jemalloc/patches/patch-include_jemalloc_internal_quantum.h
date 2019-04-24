$NetBSD: patch-include_jemalloc_internal_quantum.h,v 1.1 2019/04/24 17:11:00 adam Exp $

Add 32-bit SPARC support.

--- include/jemalloc/internal/quantum.h.orig	2019-04-24 16:37:33.000000000 +0000
+++ include/jemalloc/internal/quantum.h
@@ -15,7 +15,7 @@
 #  ifdef __alpha__
 #    define LG_QUANTUM		4
 #  endif
-#  if (defined(__sparc64__) || defined(__sparcv9) || defined(__sparc_v9__))
+#  if (defined(__sparc64__) || defined(__sparcv9) || defined(__sparc_v9__) || defined(__sparc__))
 #    define LG_QUANTUM		4
 #  endif
 #  if (defined(__amd64__) || defined(__x86_64__) || defined(_M_X64))
