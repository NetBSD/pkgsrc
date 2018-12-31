$NetBSD: patch-include_image.h,v 1.1 2018/12/31 15:06:44 jmcneill Exp $

IH_TYPE_* image type value compatibility was broken in 2018.11. Restore
compatibility with previous and future releases. This has since been fixed
upstream with commit 24431adc366c67c7755c0c6a956978f3b66ad550

--- include/image.h.orig	2018-11-14 16:10:06.000000000 +0000
+++ include/image.h
@@ -251,7 +251,6 @@ enum {
 	IH_TYPE_FLATDT,			/* Binary Flat Device Tree Blob	*/
 	IH_TYPE_KWBIMAGE,		/* Kirkwood Boot Image		*/
 	IH_TYPE_IMXIMAGE,		/* Freescale IMXBoot Image	*/
-	IH_TYPE_IMX8IMAGE,		/* Freescale IMX8Boot Image	*/
 	IH_TYPE_UBLIMAGE,		/* Davinci UBL Image		*/
 	IH_TYPE_OMAPIMAGE,		/* TI OMAP Config Header Image	*/
 	IH_TYPE_AISIMAGE,		/* TI Davinci AIS Image		*/
@@ -278,6 +277,9 @@ enum {
 	IH_TYPE_PMMC,            /* TI Power Management Micro-Controller Firmware */
 	IH_TYPE_STM32IMAGE,		/* STMicroelectronics STM32 Image */
 	IH_TYPE_SOCFPGAIMAGE_V1,	/* Altera SOCFPGA A10 Preloader	*/
+	IH_TYPE_MTKIMAGE,		/* MediaTek BootRO loadable Image */
+	IH_TYPE_IMX8MIMAGE,		/* Freescale IMX8MBoot Image	*/
+	IH_TYPE_IMX8IMAGE,		/* Freescale IMX8Boot Image	*/
 
 	IH_TYPE_COUNT,			/* Number of image types */
 };
