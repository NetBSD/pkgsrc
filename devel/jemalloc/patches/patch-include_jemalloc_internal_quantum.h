$NetBSD: patch-include_jemalloc_internal_quantum.h,v 1.2 2026/04/14 12:49:12 adam Exp $

Add 32-bit SPARC support.

--- include/jemalloc/internal/quantum.h.orig	2026-04-14 00:12:37.000000000 +0000
+++ include/jemalloc/internal/quantum.h
@@ -16,7 +16,7 @@
 #		define LG_QUANTUM 4
 #	endif
 #	if (defined(__sparc64__) || defined(__sparcv9)                        \
-	    || defined(__sparc_v9__))
+	    || defined(__sparc_v9__) || defined(__sparc__))
 #		define LG_QUANTUM 4
 #	endif
 #	if (defined(__amd64__) || defined(__x86_64__) || defined(_M_X64))
