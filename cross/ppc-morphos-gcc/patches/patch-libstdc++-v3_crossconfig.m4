$NetBSD: patch-libstdc++-v3_crossconfig.m4,v 1.3 2026/06/28 02:09:51 js Exp $

--- libstdc++-v3/crossconfig.m4.orig	2026-06-28 01:16:15.931547411 +0000
+++ libstdc++-v3/crossconfig.m4
@@ -200,11 +200,6 @@ case "${host}" in
     ;;
   *-morphos*)
     GLIBCXX_CHECK_COMPILER_FEATURES
-    GLIBCXX_CHECK_LINKER_FEATURES
-    GLIBCXX_CHECK_MATH_SUPPORT
-    GLIBCXX_CHECK_STDLIB_SUPPORT
-    AC_CHECK_FUNCS(__cxa_thread_atexit_impl)
-    AC_CHECK_FUNCS(aligned_alloc posix_memalign memalign _aligned_malloc)
     ;;
   *-netbsd* | *-openbsd*)
     SECTION_FLAGS='-ffunction-sections -fdata-sections'
