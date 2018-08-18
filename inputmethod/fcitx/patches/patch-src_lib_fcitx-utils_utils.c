$NetBSD: patch-src_lib_fcitx-utils_utils.c,v 1.1 2018/08/18 01:11:16 ryoon Exp $

--- src/lib/fcitx-utils/utils.c.orig	2017-12-22 18:02:24.000000000 +0000
+++ src/lib/fcitx-utils/utils.c
@@ -56,7 +56,9 @@
 #include <fcntl.h>
 #include <sys/param.h>
 #include <sys/sysctl.h>
+#  if !defined(__NetBSD__)
 #include <sys/user.h>
+#  endif
 #endif
 
 #if defined(__linux__)
