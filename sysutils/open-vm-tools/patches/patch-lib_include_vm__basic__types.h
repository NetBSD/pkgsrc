$NetBSD: patch-lib_include_vm__basic__types.h,v 1.2 2018/01/01 06:56:01 ryoon Exp $

Fix build on NetBSD 6.

--- lib/include/vm_basic_types.h.orig	2017-12-15 19:09:51.000000000 +0000
+++ lib/include/vm_basic_types.h
@@ -80,7 +80,7 @@
 /* STRICT ANSI means the Xserver build and X defines Bool differently. */
 #if !defined(_XTYPEDEF_BOOL) && \
     (!defined(__STRICT_ANSI__) || defined(__FreeBSD__) || \
-      defined(__MINGW32__) || defined(__APPLE__))
+      defined(__MINGW32__) || defined(__APPLE__) || defined(__NetBSD__))
 #define _XTYPEDEF_BOOL
 typedef char           Bool;
 #endif
