$NetBSD: manual-ltdl.m4,v 1.2 2005/03/22 15:12:08 tv Exp $

--- ltdl.m4.orig	2005-02-12 07:18:34.000000000 -0500
+++ ltdl.m4
@@ -134,6 +134,9 @@ AC_CACHE_CHECK([whether deplibs are load
   hpux10*|hpux11*)
     libltdl_cv_sys_dlopen_deplibs=yes
     ;;
+  interix*)
+    libltdl_cv_sys_dlopen_deplibs=yes
+    ;;
   irix[[12345]]*|irix6.[[01]]*)
     # Catch all versions of IRIX before 6.2, and indicate that we don't
     # know how it worked for any of those versions.
