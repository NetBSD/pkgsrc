$NetBSD: patch-Opcodes_wavegde.h,v 1.1 2014/01/09 16:55:16 jperkin Exp $

Use native len_t on SunOS.

--- Opcodes/wavegde.h.orig	2005-09-05 17:27:44.000000000 +0000
+++ Opcodes/wavegde.h
@@ -43,7 +43,9 @@
 #endif
 
 /* TYPEDEFS */
+#ifndef __sun
 typedef long    len_t;    /* length type */
+#endif
 
 /* CLASS DEFINITIONS */
 
