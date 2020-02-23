$NetBSD: patch-plat_rockchip_common_params_setup.c,v 1.1 2020/02/23 01:01:11 mrg Exp $

https://github.com/ARM-software/arm-trusted-firmware/commit/d52331d01e0efae36e837af90887a8aed33ff604#diff-94a9f1c135591eedd6addbcc729f46fb

 plat/rockchip: initialize reset and poweroff GPIOs with known invalid value

 And return NULL if we didn't get them in bl aux params otherwise reset and poweroff
 will be broken on platforms that do not have reset and poweroff GPIOs.

 Fixes: c1185ff ("plat/rockchip: Switch to use new common BL aux parameter library")
 Signed-off-by: Vasily Khoruzhick <anarsoul@gmail.com>
 Change-Id: Ic6cf6383d8f05d745e2c5d5e1b1df38514ea8429

--- plat/rockchip/common/params_setup.c.orig	2019-10-22 06:36:23.000000000 -0700
+++ plat/rockchip/common/params_setup.c	2020-02-22 16:35:59.372670386 -0800
@@ -6,6 +6,7 @@
 
 #include <assert.h>
 #include <errno.h>
+#include <limits.h>
 #include <string.h>
 
 #include <lib/bl_aux_params/bl_aux_params.h>
@@ -21,8 +22,8 @@
 #include <plat_params.h>
 #include <plat_private.h>
 
-static struct bl_aux_gpio_info rst_gpio;
-static struct bl_aux_gpio_info poweroff_gpio;
+static struct bl_aux_gpio_info rst_gpio = { .index = UINT_MAX };
+static struct bl_aux_gpio_info poweroff_gpio = { .index = UINT_MAX };
 static struct bl_aux_gpio_info suspend_gpio[10];
 uint32_t suspend_gpio_cnt;
 static struct bl_aux_rk_apio_info suspend_apio;
@@ -174,11 +175,17 @@
 
 struct bl_aux_gpio_info *plat_get_rockchip_gpio_reset(void)
 {
+	if (rst_gpio.index == UINT_MAX)
+		return NULL;
+
 	return &rst_gpio;
 }
 
 struct bl_aux_gpio_info *plat_get_rockchip_gpio_poweroff(void)
 {
+	if (poweroff_gpio.index == UINT_MAX)
+		return NULL;
+
 	return &poweroff_gpio;
 }
 
