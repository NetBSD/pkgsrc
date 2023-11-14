$NetBSD: patch-src_core_cpu__recompiler__types.h,v 1.1 2023/11/14 17:57:41 nia Exp $

NetBSD (and more POSIX platforms) support.

--- src/core/cpu_recompiler_types.h.orig	2023-08-12 04:46:09.000000000 +0000
+++ src/core/cpu_recompiler_types.h
@@ -86,10 +86,8 @@ constexpr u32 CODE_STORAGE_ALIGNMENT = 4
 // ABI selection
 #if defined(_WIN32)
 #define ABI_WIN64 1
-#elif defined(__linux__) || defined(__ANDROID__) || defined(__APPLE__) || defined(__HAIKU__) || defined(__FreeBSD__)
-#define ABI_SYSV 1
 #else
-#error Unknown ABI.
+#define ABI_SYSV 1
 #endif
 
 #elif defined(CPU_AARCH32)
