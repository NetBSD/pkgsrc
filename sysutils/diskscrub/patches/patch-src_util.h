$NetBSD: patch-src_util.h,v 1.1 2015/03/05 21:29:20 sevan Exp $

--- src/util.h.orig	2015-03-05 19:13:14.116234563 +0000
+++ src/util.h
@@ -30,6 +30,10 @@
 typedef enum { false, true } bool;
 #endif
 
+#ifdef HAVE_SYS_MMAN_H
+#include <sys/mman.h>
+#endif
+
 typedef enum {
     FILE_NOEXIST,
     FILE_REGULAR,
