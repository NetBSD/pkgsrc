$NetBSD: patch-Common_CPUDetect.cpp,v 1.1 2026/03/19 17:37:13 adam Exp $

Fix build on NetBSD.

--- Common/CPUDetect.cpp.orig	2026-03-19 17:29:50.553306189 +0000
+++ Common/CPUDetect.cpp
@@ -67,6 +67,10 @@ void do_cpuid(u32 regs[4], u32 cpuid_leaf) {
 
 #else  // !_WIN32
 
+#ifdef __NetBSD__
+#define do_xgetbv _xgetbv
+#endif
+
 #ifdef _M_SSE
 
 #include <emmintrin.h>
