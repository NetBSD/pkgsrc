$NetBSD: manual-ltdl.m4,v 1.1 2004/04/20 18:29:34 tv Exp $

--- ltdl.m4.orig	Sun Sep 21 08:51:38 2003
+++ ltdl.m4
@@ -149,6 +149,9 @@ AC_CACHE_CHECK([whether deplibs are load
   hpux10*|hpux11*)
     libltdl_cv_sys_dlopen_deplibs=yes
     ;;
+  interix*)
+    libltdl_cv_sys_dlopen_deplibs=yes
+    ;;
   irix[[12345]]*|irix6.[[01]]*)
     # Catch all versions of IRIX before 6.2, and indicate that we don't
     # know how it worked for any of those versions.
