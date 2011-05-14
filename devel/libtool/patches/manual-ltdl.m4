$NetBSD: manual-ltdl.m4,v 1.4 2011/05/14 16:49:45 bsiegert Exp $

--- libltdl/m4/ltdl.m4.orig	2009-11-16 14:11:59.000000000 +0100
+++ libltdl/m4/ltdl.m4	2010-12-30 17:04:01.000000000 +0100
@@ -487,6 +487,9 @@
     # at 6.2 and later dlopen does load deplibs.
     lt_cv_sys_dlopen_deplibs=yes
     ;;
+  mirbsd*)
+    lt_cv_sys_dlopen_deplibs=yes
+    ;;
   netbsd*)
     lt_cv_sys_dlopen_deplibs=yes
     ;;
