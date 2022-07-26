$NetBSD: manual-ltdl.m4,v 1.8 2022/07/26 16:15:26 wiz Exp $

Support mirbsd & minix

--- m4/ltdl.m4.orig	2022-03-17 02:43:39.000000000 +0000
+++ m4/ltdl.m4
@@ -497,7 +497,10 @@ AC_CACHE_CHECK([whether deplibs are load
     # at 6.2 and later dlopen does load deplibs.
     lt_cv_sys_dlopen_deplibs=yes
     ;;
-  netbsd*)
+  mirbsd*)
+    lt_cv_sys_dlopen_deplibs=yes
+    ;;
+  netbsd* | minix*)
     lt_cv_sys_dlopen_deplibs=yes
     ;;
   openbsd*)
