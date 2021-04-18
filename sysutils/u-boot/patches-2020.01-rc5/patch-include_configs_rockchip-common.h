$NetBSD: patch-include_configs_rockchip-common.h,v 1.1 2021/04/18 08:54:55 mrg Exp $

Author: dhivael <dhivael.git@eno.space>
Date:   Sat Jan 11 15:04:04 2020 +0100

    rockchip: move usb0 after mmc1 in default boot order
	
    now that we support booting from USB we should prefer USB boot over eMMC
    boot. we still try to boot from SD cards first.

commit 908d441fefc2203affe1bb0d79f75f611888fc1f
Author: dhivael <dhivael.git@eno.space>
Date:   Sat Jan 11 15:04:04 2020 +0100

    rockchip: move usb0 after mmc1 in default boot order
    
    now that we support booting from USB we should prefer USB boot over eMMC
    boot. we still try to boot from SD cards first.


--- include/configs/rockchip-common.h.orig	2019-12-16 04:39:56.000000000 -0800
+++ include/configs/rockchip-common.h	2020-01-13 23:17:05.743249968 -0800
@@ -13,11 +13,10 @@
 
 /* First try to boot from SD (index 0), then eMMC (index 1) */
 #if CONFIG_IS_ENABLED(CMD_MMC)
-	#define BOOT_TARGET_MMC(func) \
-		func(MMC, mmc, 0) \
-		func(MMC, mmc, 1)
+	#define BOOT_TARGET_MMC(func, idx) \
+		func(MMC, mmc, idx)
 #else
-	#define BOOT_TARGET_MMC(func)
+	#define BOOT_TARGET_MMC(func, idx)
 #endif
 
 #if CONFIG_IS_ENABLED(CMD_USB)
@@ -39,8 +38,9 @@
 #endif
 
 #define BOOT_TARGET_DEVICES(func) \
-	BOOT_TARGET_MMC(func) \
+	BOOT_TARGET_MMC(func, 1) \
 	BOOT_TARGET_USB(func) \
+	BOOT_TARGET_MMC(func, 0) \
 	BOOT_TARGET_PXE(func) \
 	BOOT_TARGET_DHCP(func)
 
