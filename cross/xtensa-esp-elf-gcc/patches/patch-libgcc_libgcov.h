$NetBSD: patch-libgcc_libgcov.h,v 1.1 2024/07/22 20:01:50 tnn Exp $

For some reason uses configure result from host, not target.

--- libgcc/libgcov.h.orig	2024-07-22 15:25:59.142776507 +0000
+++ libgcc/libgcov.h
@@ -46,8 +46,10 @@
 #include "gcov.h"
 
 #if HAVE_SYS_MMAN_H
+#if 0
 #include <sys/mman.h>
 #endif
+#endif
 
 #if __CHAR_BIT__ == 8
 typedef unsigned gcov_unsigned_t __attribute__ ((mode (SI)));
