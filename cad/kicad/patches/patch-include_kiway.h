$NetBSD: patch-include_kiway.h,v 1.1 2016/02/03 19:34:34 bouyer Exp $

--- include/kiway.h.orig	2015-12-14 21:13:18.000000000 +0100
+++ include/kiway.h	2015-12-14 21:13:39.000000000 +0100
@@ -114,7 +114,7 @@
 // be mangled.
 #define KIFACE_INSTANCE_NAME_AND_VERSION   "KIFACE_1"
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
  #define LIB_ENV_VAR    wxT( "LD_LIBRARY_PATH" )
 #elif defined(__WXMAC__)
  #define LIB_ENV_VAR    wxT( "DYLD_LIBRARY_PATH" )
