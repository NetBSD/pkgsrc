$NetBSD: patch-hw_core_uboot__image.h,v 1.1 2021/02/20 22:55:19 ryoon Exp $

--- hw/core/uboot_image.h.orig	2019-04-23 18:14:45.000000000 +0000
+++ hw/core/uboot_image.h
@@ -75,6 +75,7 @@
 #define IH_CPU_NIOS2		15	/* Nios-II	*/
 #define IH_CPU_BLACKFIN		16	/* Blackfin	*/
 #define IH_CPU_AVR32		17	/* AVR32	*/
+#define IH_CPU_ARM64		22	/* ARM64        */
 
 /*
  * Image Types
