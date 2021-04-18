$NetBSD: patch-include-configs-pinebook_pro_rk3399.h,v 1.1 2021/04/18 08:54:55 mrg Exp $

Pinebook Pro support from https://patchwork.ozlabs.org/patch/1194525/

diff --git include/configs/pinebook_pro_rk3399.h include/configs/pinebook_pro_rk3399.h
new file mode 100644
index 0000000000..f383becbf8
--- /dev/null
+++ include/configs/pinebook_pro_rk3399.h
@@ -0,0 +1,29 @@
+/*
+ * Copyright (C) 2016 Rockchip Electronics Co., Ltd
+ * Copyright (C) 2019 Peter Robinson <pbrobinson at gmail.com>
+ *
+ * SPDX-License-Identifier:     GPL-2.0+
+ */
+
+#ifndef __PINEBOOKPRO_RK3399_H
+#define __PINEBOOKPRO_RK3399_H
+
+#define ROCKCHIP_DEVICE_SETTINGS \
+		"stdin=serial,usbkbd\0" \
+		"stdout=serial,vidconsole\0" \
+		"stderr=serial,vidconsole\0"
+
+#include <configs/rk3399_common.h>
+
+#if defined(CONFIG_ENV_IS_IN_MMC)
+#define CONFIG_SYS_MMC_ENV_DEV 0
+#elif defined(CONFIG_ENV_IS_IN_SPI_FLASH)
+#define CONFIG_ENV_SECT_SIZE		(8 * 1024)
+#endif
+
+#undef CONFIG_SYS_SPI_U_BOOT_OFFS
+#define CONFIG_SYS_SPI_U_BOOT_OFFS	1024 * 512
+
+#define SDRAM_BANK_SIZE			(2UL << 30)
+
+#endif
