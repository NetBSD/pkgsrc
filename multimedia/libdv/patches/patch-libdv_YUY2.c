$NetBSD: patch-libdv_YUY2.c,v 1.1 2013/12/03 21:46:46 bsiegert Exp $

This is needed on MirBSD and probably also OpenBSD.

--- libdv/YUY2.c.orig	Tue Dec  3 20:03:17 2013
+++ libdv/YUY2.c
@@ -31,6 +31,9 @@
 # include <config.h>
 #endif
 
+#if HAVE_SYS_TYPES_H
+#include <sys/types.h>
+#endif
 #if HAVE_ENDIAN_H
 #include <endian.h>
 #elif HAVE_MACHINE_ENDIAN_H
