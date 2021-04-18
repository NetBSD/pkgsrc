$NetBSD: patch-board_pine64_pinebook_pro_rk3399_pinebook-pro-rk3399.c,v 1.1 2021/04/18 08:54:55 mrg Exp $

Pinebook Pro support from https://patchwork.ozlabs.org/patch/1194525/

diff --git board/pine64/pinebook_pro_rk3399/pinebook-pro-rk3399.c board/pine64/pinebook_pro_rk3399/pinebook-pro-rk3399.c
new file mode 100644
index 0000000000..b1a2ed3b77
--- /dev/null
+++ board/pine64/pinebook_pro_rk3399/pinebook-pro-rk3399.c
@@ -0,0 +1,192 @@
+/*
+ * (C) Copyright 2016 Rockchip Electronics Co., Ltd
+ *
+ * SPDX-License-Identifier:     GPL-2.0+
+ */
+#include <common.h>
+#include <dm.h>
+#include <misc.h>
+#include <syscon.h>
+#include <dm/pinctrl.h>
+#include <dm/uclass-internal.h>
+#include <asm/io.h>
+#include <asm/setup.h>
+#include <asm/arch-rockchip/clock.h>
+#include <asm/arch-rockchip/grf_rk3399.h>
+#include <asm/arch-rockchip/hardware.h>
+#include <asm/arch-rockchip/misc.h>
+#include <asm/arch-rockchip/periph.h>
+#include <power/regulator.h>
+#include <usb.h>
+#include <dwc3-uboot.h>
+
+#define RK3399_CPUID_OFF  0x7
+#define RK3399_CPUID_LEN  0x10
+
+static int fix_lcd_backling_pull_mode(void)
+{
+#include <asm/arch-rockchip/grf_rk3399.h>
+
+#define PMU_GRF_BASE	0xff320000
+
+	// set pull of GPIO1_A0
+	struct rk3399_pmugrf_regs * const pmugrf = (void *)PMU_GRF_BASE;
+	rk_clrsetreg(&pmugrf->gpio1_p[0], 3 << (2 * 0), 0 << (2 * 0));
+	return 0;
+}
+
+#ifndef CONFIG_SPL_BUILD
+int board_early_init_f(void)
+{
+	struct udevice *regulator;
+	int ret;
+
+	ret = regulator_get_by_platname("vcc5v0_host", &regulator);
+	if (ret) {
+		debug("%s vcc5v0_host init fail! ret %d\n", __func__, ret);
+		goto out;
+	}
+
+	ret = regulator_set_enable(regulator, true);
+	if (ret)
+		debug("%s vcc5v0-host-en set fail! ret %d\n", __func__, ret);
+
+	fix_lcd_backling_pull_mode();
+
+out:
+	return 0;
+}
+#endif
+
+static void setup_serial(void)
+{
+#if CONFIG_IS_ENABLED(ROCKCHIP_EFUSE)
+	struct udevice *dev;
+	int ret, i;
+	u8 cpuid[RK3399_CPUID_LEN];
+	u8 low[RK3399_CPUID_LEN/2], high[RK3399_CPUID_LEN/2];
+	char cpuid_str[RK3399_CPUID_LEN * 2 + 1];
+	u64 serialno;
+	char serialno_str[16];
+
+	/* retrieve the device */
+	ret = uclass_get_device_by_driver(UCLASS_MISC,
+					  DM_GET_DRIVER(rockchip_efuse), &dev);
+	if (ret) {
+		debug("%s: could not find efuse device\n", __func__);
+		return;
+	}
+
+	/* read the cpu_id range from the efuses */
+	ret = misc_read(dev, RK3399_CPUID_OFF, &cpuid, sizeof(cpuid));
+	if (ret) {
+		debug("%s: reading cpuid from the efuses failed\n",
+		      __func__);
+		return;
+	}
+
+	memset(cpuid_str, 0, sizeof(cpuid_str));
+	for (i = 0; i < 16; i++)
+		sprintf(&cpuid_str[i * 2], "%02x", cpuid[i]);
+
+	debug("cpuid: %s\n", cpuid_str);
+
+	/*
+	 * Mix the cpuid bytes using the same rules as in
+	 *   ${linux}/drivers/soc/rockchip/rockchip-cpuinfo.c
+	 */
+	for (i = 0; i < 8; i++) {
+		low[i] = cpuid[1 + (i << 1)];
+		high[i] = cpuid[i << 1];
+	}
+
+	serialno = crc32_no_comp(0, low, 8);
+	serialno |= (u64)crc32_no_comp(serialno, high, 8) << 32;
+	snprintf(serialno_str, sizeof(serialno_str), "%llx", serialno);
+
+	env_set("cpuid#", cpuid_str);
+	env_set("serial#", serialno_str);
+#endif
+
+	return;
+}
+
+#define GRF_IO_VSEL_BT565_SHIFT 0
+#define PMUGRF_CON0_VSEL_SHIFT 8
+
+#ifdef CONFIG_MISC_INIT_R
+static void setup_iodomain(void)
+{
+	struct rk3399_grf_regs *grf =
+	   syscon_get_first_range(ROCKCHIP_SYSCON_GRF);
+	struct rk3399_pmugrf_regs *pmugrf =
+	   syscon_get_first_range(ROCKCHIP_SYSCON_PMUGRF);
+
+	/* BT565 is in 1.8v domain */
+	rk_setreg(&grf->io_vsel, 1 << GRF_IO_VSEL_BT565_SHIFT);
+
+	/* Set GPIO1 1.8v/3.0v source select to PMU1830_VOL */
+	rk_setreg(&pmugrf->soc_con0, 1 << PMUGRF_CON0_VSEL_SHIFT);
+}
+
+int misc_init_r(void)
+{
+	const u32 cpuid_offset = 0x7;
+	const u32 cpuid_length = 0x10;
+	u8 cpuid[cpuid_length];
+	int ret;
+
+	setup_iodomain();
+
+	ret = rockchip_cpuid_from_efuse(cpuid_offset, cpuid_length, cpuid);
+	if (ret)
+		return ret;
+
+	ret = rockchip_cpuid_set(cpuid, cpuid_length);
+	if (ret)
+		return ret;
+
+	ret = rockchip_setup_macaddr();
+
+	setup_serial();
+
+	return ret;
+}
+#endif
+
+#ifdef CONFIG_SERIAL_TAG
+void get_board_serial(struct tag_serialnr *serialnr)
+{
+	char *serial_string;
+	u64 serial = 0;
+
+	serial_string = env_get("serial#");
+
+	if (serial_string)
+		serial = simple_strtoull(serial_string, NULL, 16);
+
+	serialnr->high = (u32)(serial >> 32);
+	serialnr->low = (u32)(serial & 0xffffffff);
+}
+#endif
+
+#ifdef CONFIG_USB_DWC3
+static struct dwc3_device dwc3_device_data = {
+	.maximum_speed = USB_SPEED_HIGH,
+	.base = 0xfe800000,
+	.dr_mode = USB_DR_MODE_PERIPHERAL,
+	.index = 0,
+	.dis_u2_susphy_quirk = 1,
+};
+
+int usb_gadget_handle_interrupts(void)
+{
+	dwc3_uboot_handle_interrupt(0);
+	return 0;
+}
+
+int board_usb_init(int index, enum usb_init_type init)
+{
+	return dwc3_uboot_init(&dwc3_device_data);
+}
+#endif
