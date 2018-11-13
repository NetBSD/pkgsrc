$NetBSD: manual-ltdl.m4,v 1.7 2018/11/13 21:44:42 sevan Exp $

Support mirbsd & minix

--- m4/ltdl.m4.orig	Fri Jan 16 18:52:04 2015
+++ m4/ltdl.m4
@@ -496,7 +496,10 @@ AC_CACHE_CHECK([whether deplibs are loaded by dlopen],
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
