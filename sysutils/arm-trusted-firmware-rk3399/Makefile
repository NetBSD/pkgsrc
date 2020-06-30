# $NetBSD: Makefile,v 1.4 2020/06/30 14:33:15 thorpej Exp $

PLATFORM=	rk3399
COMMENT=	ARM Trusted Firmware for Rockchip RK3399 SoCs

BL31_SUFFIX=	elf

# This package builds for Cortex-M0 *and* Cortex-A53/A72.
ATF_CORTEX_M0=	yes

.include "../../sysutils/arm-trusted-firmware/arm-trusted-firmware.mk"
