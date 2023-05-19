$NetBSD: patch-gnulib-tests_vma-iter.c,v 1.1 2023/05/19 14:12:18 jperkin Exp $

Remove broken workaround on SunOS.

--- gnulib-tests/vma-iter.c.orig	2022-10-09 14:42:28.000000000 +0000
+++ gnulib-tests/vma-iter.c
@@ -28,7 +28,7 @@
       switch to Clang."
    The files that we access in this compilation unit are less than 2 GB
    large.  */
-#if defined __sun || defined __ANDROID__
+#if defined __ANDROID__
 # undef _FILE_OFFSET_BITS
 #endif
 
