$NetBSD: patch-src_openrct2_util_Util.cpp,v 1.6 2023/09/03 07:05:36 triaxx Exp $

Support NetBSD.

--- src/openrct2/util/Util.cpp.orig	2023-03-28 15:48:53.000000000 +0000
+++ src/openrct2/util/Util.cpp
@@ -95,7 +95,7 @@ int32_t UtilBitScanForward(int64_t sourc
 #endif
 }
 
-#if defined(__GNUC__) && (defined(__x86_64__) || defined(__i386__))
+#if defined(__GNUC__) && (defined(__x86_64__) || defined(__i386__)) && !defined(__clang__)
 #    include <cpuid.h>
 #    define OpenRCT2_CPUID_GNUC_X86
 #elif defined(_MSC_VER) && (_MSC_VER >= 1500) && (defined(_M_X64) || defined(_M_IX86)) // VS2008
@@ -134,7 +134,7 @@ bool SSE41Available()
 
 bool AVX2Available()
 {
-#ifdef OPENRCT2_X86
+#if defined(OPENRCT2_X86) && !defined(__clang__)
     // For GCC and similar use the builtin function, as cpuid changed its semantics in
     // https://github.com/gcc-mirror/gcc/commit/132fa33ce998df69a9f793d63785785f4b93e6f1
     // which causes it to ignore subleafs, but the new function is unavailable on
