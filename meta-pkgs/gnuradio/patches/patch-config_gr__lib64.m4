$NetBSD: patch-config_gr__lib64.m4,v 1.1 2012/01/26 22:58:46 sbd Exp $

Don't use a libdir suffix (eg. lib64) 

--- config/gr_lib64.m4.orig	2010-06-01 05:04:08.000000000 +0000
+++ config/gr_lib64.m4
@@ -58,6 +58,7 @@ AC_DEFUN([GR_LIB64],[
   else
     _GR_LIB64_ASK_COMPILER  
   fi
+  gr_libdir_suffix=""
   AC_MSG_RESULT([$gr_libdir_suffix])
 
 
