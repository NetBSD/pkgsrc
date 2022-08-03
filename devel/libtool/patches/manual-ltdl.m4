$NetBSD: manual-ltdl.m4,v 1.9 2022/08/03 13:06:32 jperkin Exp $

Support Minix.

--- m4/ltdl.m4.orig	2022-03-17 02:43:39.000000000 +0000
+++ m4/ltdl.m4
@@ -497,7 +497,7 @@ AC_CACHE_CHECK([whether deplibs are load
     # at 6.2 and later dlopen does load deplibs.
     lt_cv_sys_dlopen_deplibs=yes
     ;;
-  netbsd*)
+  netbsd* | minix*)
     lt_cv_sys_dlopen_deplibs=yes
     ;;
   openbsd*)
