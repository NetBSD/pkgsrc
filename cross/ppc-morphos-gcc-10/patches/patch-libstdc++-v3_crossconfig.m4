$NetBSD: patch-libstdc++-v3_crossconfig.m4,v 1.1 2021/07/25 15:06:25 js Exp $

Don't use anything that needs a link test, as link tests are forbidden after
GCC_NO_EXECUTABLES and will error out.

--- libstdc++-v3/crossconfig.m4.orig	2021-07-25 14:28:05.622501010 +0000
+++ libstdc++-v3/crossconfig.m4
@@ -201,9 +201,6 @@ case "${host}" in
     ;;
   *-morphos*)
     GLIBCXX_CHECK_COMPILER_FEATURES
-    GLIBCXX_CHECK_LINKER_FEATURES
-    GLIBCXX_CHECK_MATH_SUPPORT
-    GLIBCXX_CHECK_STDLIB_SUPPORT
     ;;
   *-netbsd* | *-openbsd*)
     SECTION_FLAGS='-ffunction-sections -fdata-sections'
