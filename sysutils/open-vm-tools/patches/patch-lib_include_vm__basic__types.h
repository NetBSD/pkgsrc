$NetBSD: patch-lib_include_vm__basic__types.h,v 1.1 2017/07/02 09:17:56 taca Exp $

Fix build on NetBSD 6.

--- lib/include/vm_basic_types.h.orig	2017-02-11 10:06:44.000000000 +0000
+++ lib/include/vm_basic_types.h
@@ -79,7 +79,7 @@
 
 /* STRICT ANSI means the Xserver build and X defines Bool differently. */
 #if !defined(_XTYPEDEF_BOOL) && \
-    (!defined(__STRICT_ANSI__) || defined(__FreeBSD__) || defined(__MINGW32__))
+    (!defined(__STRICT_ANSI__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__MINGW32__))
 #define _XTYPEDEF_BOOL
 typedef char           Bool;
 #endif
