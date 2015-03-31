$NetBSD: patch-src_system_types.h,v 1.1 2015/03/31 15:25:22 joerg Exp $

--- src/system/types.h.orig	2015-03-26 10:25:25.000000000 +0000
+++ src/system/types.h
@@ -42,7 +42,7 @@
 #ifdef __GNUC__
 
 	// FIXME: configure
-#	ifndef __ppc__
+#	ifdef __i386__
 #		define FASTCALL __attribute__((regparm (3)))
 #	else
 #		define FASTCALL
