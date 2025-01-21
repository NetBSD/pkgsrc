$NetBSD: patch-torch_csrc_utils_byte__order.h,v 1.1 2025/01/21 13:36:49 ryoon Exp $

* Support NetBSD.

--- torch/csrc/utils/byte_order.h.orig	2025-01-17 11:52:24.707676599 +0000
+++ torch/csrc/utils/byte_order.h
@@ -16,6 +16,12 @@
 #define thp_bswap16(x) bswap16(x)
 #define thp_bswap32(x) bswap32(x)
 #define thp_bswap64(x) bswap64(x)
+#elif defined(__NetBSD__)
+#include <sys/types.h>
+#include <machine/bswap.h>
+#define thp_bswap16(x) bswap16(x)
+#define thp_bswap32(x) bswap32(x)
+#define thp_bswap64(x) bswap64(x)
 #elif defined(__APPLE__)
 #include <libkern/OSByteOrder.h>
 #define thp_bswap16(x) OSSwapInt16(x)
