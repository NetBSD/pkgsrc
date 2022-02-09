# $NetBSD: Makefile,v 1.1 2022/02/09 01:57:57 mrg Exp $

PLATFORM=	rk3399
COMMENT=	ARM Trusted Firmware for Rockchip RK3399 SoCs

BL31_SUFFIX=	elf

# This package builds for Cortex-M0 *and* Cortex-A53/A72.
ATF_CORTEX_M0=	yes

.include "../../sysutils/trusted-firmware-a/trusted-firmware-a.mk"
