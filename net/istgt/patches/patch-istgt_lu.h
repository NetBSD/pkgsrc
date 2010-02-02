$NetBSD: patch-istgt_lu.h,v 1.1.1.1 2010/02/02 16:09:51 sborrill Exp $

--- src/istgt_lu.h.orig	2010-02-02 13:22:21.000000000 +0000
+++ src/istgt_lu.h	2010-02-02 13:24:47.000000000 +0000
@@ -50,7 +50,13 @@
 #define DEFAULT_LU_QUEUE_DEPTH 16
 
 //#define DEFAULT_LU_VENDOR "PEACHNW"
+#if defined(__NetBSD__)
+#define DEFAULT_LU_VENDOR "NetBSD"
+#elif defined(__OpenBSD__)
+#define DEFAULT_LU_VENDOR "OpenBSD"
+#else
 #define DEFAULT_LU_VENDOR "FreeBSD"
+#endif
 #define DEFAULT_LU_VENDOR_DISK DEFAULT_LU_VENDOR
 #define DEFAULT_LU_VENDOR_DVD  DEFAULT_LU_VENDOR
 #ifndef USE_LU_TAPE_DLT8000
