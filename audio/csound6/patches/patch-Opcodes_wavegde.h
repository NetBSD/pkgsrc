$NetBSD: patch-Opcodes_wavegde.h,v 1.2 2019/11/02 22:25:46 mrg Exp $

Use native len_t on SunOS.

--- Opcodes/wavegde.h.orig	2019-07-12 14:54:19.000000000 -0700
+++ Opcodes/wavegde.h	2019-10-29 13:45:37.120974231 -0700
@@ -43,7 +43,9 @@
 #endif
 
 /* TYPEDEFS */
+#ifndef __sun
 typedef int64_t    len_t;    /* length type */
+#endif
 
 /* CLASS DEFINITIONS */
 
