$NetBSD: patch-src_runtime_bsd-os.h,v 1.1 2016/10/12 11:35:48 asau Exp $

--- src/runtime/bsd-os.h.orig	2016-09-30 16:41:12.000000000 +0000
+++ src/runtime/bsd-os.h
@@ -13,6 +13,10 @@
 #include <osreldate.h>
 #endif
 
+#if defined(__NetBSD__)
+#define _KERNTYPES
+#endif
+
 #include <sys/types.h>
 #include <sys/mman.h>
 #include <sys/signal.h>
