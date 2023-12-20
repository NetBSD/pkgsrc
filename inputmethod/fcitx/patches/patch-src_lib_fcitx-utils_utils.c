$NetBSD: patch-src_lib_fcitx-utils_utils.c,v 1.2 2023/12/20 12:03:25 nros Exp $

Illumos has endian.h just like Linux

--- src/lib/fcitx-utils/utils.c.orig	2017-12-22 18:02:24.000000000 +0000
+++ src/lib/fcitx-utils/utils.c
@@ -56,14 +56,16 @@
 #include <fcntl.h>
 #include <sys/param.h>
 #include <sys/sysctl.h>
+#  if !defined(__NetBSD__)
 #include <sys/user.h>
+#  endif
 #endif
 
 #if defined(__linux__)
 #include <sys/prctl.h>
 #endif
 
-#if defined(__linux__) || defined(__GLIBC__)
+#if defined(__linux__) || defined(__GLIBC__) || defined(__illumos__)
 #include <endian.h>
 #else
 #include <sys/endian.h>
