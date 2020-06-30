$NetBSD: patch-plat_allwinner_sun50i_h6_include_sunxi_mmap.h,v 1.1 2020/06/30 14:33:15 thorpej Exp $

Work around broken H6 WDOG reset.

--- plat/allwinner/sun50i_h6/include/sunxi_mmap.h.orig	2020-04-20 15:56:43.000000000 +0000
+++ plat/allwinner/sun50i_h6/include/sunxi_mmap.h	2020-06-22 02:24:08.336010712 +0000
@@ -58,4 +58,8 @@
 #define SUNXI_R_UART_BASE		0x07080000
 #define SUNXI_R_PIO_BASE		0x07022000
 
+/* Work around broken H6 WDOG reset. */
+#undef SUNXI_WDOG_BASE
+#define SUNXI_WDOG_BASE			SUNXI_R_WDOG_BASE
+
 #endif /* SUNXI_MMAP_H */
