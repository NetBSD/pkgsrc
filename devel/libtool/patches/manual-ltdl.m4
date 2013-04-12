$NetBSD: manual-ltdl.m4,v 1.5 2013/04/12 13:44:08 joerg Exp $

--- libltdl/m4/ltdl.m4.orig	2011-10-17 10:17:05.000000000 +0000
+++ libltdl/m4/ltdl.m4
@@ -493,6 +493,9 @@ AC_CACHE_CHECK([whether deplibs are load
     # at 6.2 and later dlopen does load deplibs.
     lt_cv_sys_dlopen_deplibs=yes
     ;;
+  mirbsd*)
+    lt_cv_sys_dlopen_deplibs=yes
+    ;;
   netbsd*)
     lt_cv_sys_dlopen_deplibs=yes
     ;;
