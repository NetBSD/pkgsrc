$NetBSD: patch-misc.h,v 1.2 2018/03/16 23:02:09 maya Exp $

--- misc.h.orig	2018-03-16 05:15:51.000000000 +0000
+++ misc.h
@@ -41,6 +41,17 @@
 #include <sys/types.h>
 #endif
 
+#ifdef __sun
+#include <sys/byteorder.h>
+#define LITTLE_ENDIAN 1234
+#define BIG_ENDIAN 4321
+#ifdef _LITTLE_ENDIAN
+#define BYTE_ORDER LITTLE_ENDIAN
+#else
+#define BYTE_ORDER BIG_ENDIAN
+#endif
+#endif
+
 #if BYTE_ORDER==LITTLE_ENDIAN
 union magic {
   struct {
