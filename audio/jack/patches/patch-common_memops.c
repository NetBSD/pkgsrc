$NetBSD: patch-common_memops.c,v 1.1 2021/09/08 19:19:20 nia Exp $

Add NetBSD support.

--- common/memops.c.orig	2021-07-15 06:18:26.000000000 +0000
+++ common/memops.c
@@ -35,6 +35,13 @@
 #endif
 #include "memops.h"
 
+#ifdef __NetBSD__
+#include <sys/endian.h>
+#define __BYTE_ORDER BYTE_ORDER
+#define __LITTLE_ENDIAN LITTLE_ENDIAN
+#define __BIG_ENDIAN BIG_ENDIAN
+#endif
+
 #if defined (__SSE2__) && !defined (__sun__)
 #include <emmintrin.h>
 #ifdef __SSE4_1__
