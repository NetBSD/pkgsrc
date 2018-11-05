$NetBSD: patch-hw_core_uboot__image.h,v 1.1 2018/11/05 07:27:59 skrll Exp $

--- hw/core/uboot_image.h.orig	2018-08-14 19:10:34.000000000 +0000
+++ hw/core/uboot_image.h
@@ -75,6 +75,7 @@
 #define IH_CPU_NIOS2		15	/* Nios-II	*/
 #define IH_CPU_BLACKFIN		16	/* Blackfin	*/
 #define IH_CPU_AVR32		17	/* AVR32	*/
+#define IH_CPU_ARM64		22	/* ARM64        */
 
 /*
  * Image Types
@@ -124,6 +125,7 @@
 #define IH_TYPE_SCRIPT		6	/* Script file			*/
 #define IH_TYPE_FILESYSTEM	7	/* Filesystem Image (any type)	*/
 #define IH_TYPE_FLATDT		8	/* Binary Flat Device Tree Blob	*/
+#define IH_TYPE_KERNEL_NOLOAD  14	/* OS Kernel Image (noload)	*/
 
 /*
  * Compression Types
