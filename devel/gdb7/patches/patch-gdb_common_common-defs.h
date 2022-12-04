$NetBSD: patch-gdb_common_common-defs.h,v 1.1 2022/12/04 19:04:21 he Exp $

Insert a hack for NetBSD/powerpc to bring register_t in scope.

--- gdb/common/common-defs.h.orig	2016-02-10 03:19:39.000000000 +0000
+++ gdb/common/common-defs.h
@@ -20,6 +20,12 @@
 #ifndef COMMON_DEFS_H
 #define COMMON_DEFS_H
 
+#ifdef __NetBSD__
+#  ifdef __powerpc__
+#    define _KMEMUSER 1 /* needed for register_t */
+#  endif
+#endif
+
 #include "config.h"
 #ifdef GDBSERVER
 #include "build-gnulib-gdbserver/config.h"
