$NetBSD: patch-misc.h,v 1.1 2012/01/11 20:58:09 hans Exp $

--- misc.h.orig	2003-03-31 01:40:56.000000000 +0200
+++ misc.h	2012-01-02 18:16:15.405713912 +0100
@@ -30,6 +30,17 @@
 
 #include <sys/types.h>
 
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
