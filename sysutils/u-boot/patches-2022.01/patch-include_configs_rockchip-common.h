$NetBSD: patch-include_configs_rockchip-common.h,v 1.1 2022/02/11 21:46:14 mrg Exp $

Add SCSI/AHCI support.
Default to booting from SD, USB, EMMC, NVME, SCSI, PXE, DHCP and then SF.

--- include/configs/rockchip-common.h.orig	2022-01-10 10:46:34.000000000 -0800
+++ include/configs/rockchip-common.h	2022-02-07 02:27:47.781052660 -0800
@@ -16,11 +16,10 @@
 
 /* First try to boot from SD (index 1), then eMMC (index 0) */
 #if CONFIG_IS_ENABLED(CMD_MMC)
-	#define BOOT_TARGET_MMC(func) \
-		func(MMC, mmc, 1) \
-		func(MMC, mmc, 0)
+	#define BOOT_TARGET_MMC(func, idx) \
+		func(MMC, mmc, idx)
 #else
-	#define BOOT_TARGET_MMC(func)
+	#define BOOT_TARGET_MMC(func, idx)
 #endif
 
 #if CONFIG_IS_ENABLED(CMD_NVME)
@@ -53,18 +52,27 @@
 	#define BOOT_TARGET_SF(func)
 #endif
 
+#if CONFIG_IS_ENABLED(CMD_SCSI)
+	#define BOOT_TARGET_SCSI(func)	func(SCSI, scsi, 0)
+#else
+	#define BOOT_TARGET_SCSI(func)
+#endif
+
 #ifdef CONFIG_ROCKCHIP_RK3399
 #define BOOT_TARGET_DEVICES(func) \
-	BOOT_TARGET_MMC(func) \
-	BOOT_TARGET_NVME(func) \
+	BOOT_TARGET_MMC(func, 1) \
 	BOOT_TARGET_USB(func) \
+	BOOT_TARGET_MMC(func, 0) \
+	BOOT_TARGET_NVME(func) \
+	BOOT_TARGET_SCSI(func) \
 	BOOT_TARGET_PXE(func) \
 	BOOT_TARGET_DHCP(func) \
 	BOOT_TARGET_SF(func)
 #else
 #define BOOT_TARGET_DEVICES(func) \
-	BOOT_TARGET_MMC(func) \
+	BOOT_TARGET_MMC(func, 1) \
 	BOOT_TARGET_USB(func) \
+	BOOT_TARGET_MMC(func, 0) \
 	BOOT_TARGET_PXE(func) \
 	BOOT_TARGET_DHCP(func)
 #endif
