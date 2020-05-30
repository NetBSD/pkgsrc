$NetBSD: patch-src_openrct2_util_Util.cpp,v 1.1 2020/05/30 20:47:08 joerg Exp $

--- src/openrct2/util/Util.cpp.orig	2020-05-27 23:27:33.350998119 +0000
+++ src/openrct2/util/Util.cpp
@@ -184,7 +184,7 @@ int32_t bitscanforward(int32_t source)
 #endif
 }
 
-#if defined(__GNUC__) && (defined(__x86_64__) || defined(__i386__))
+#if defined(__GNUC__) && (defined(__x86_64__) || defined(__i386__)) && !defined(__clang__)
 #    include <cpuid.h>
 #    define OpenRCT2_CPUID_GNUC_X86
 #elif defined(_MSC_VER) && (_MSC_VER >= 1500) && (defined(_M_X64) || defined(_M_IX86)) // VS2008
@@ -223,7 +223,7 @@ bool sse41_available()
 
 bool avx2_available()
 {
-#ifdef OPENRCT2_X86
+#if defined(OPENRCT2_X86) && !defined(__clang__)
     // For GCC and similar use the builtin function, as cpuid changed its semantics in
     // https://github.com/gcc-mirror/gcc/commit/132fa33ce998df69a9f793d63785785f4b93e6f1
     // which causes it to ignore subleafs, but the new function is unavailable on
