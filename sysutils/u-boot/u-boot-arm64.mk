# $NetBSD: u-boot-arm64.mk,v 1.4 2021/08/12 07:30:21 wiz Exp $

MAINTAINER=	port-arm@NetBSD.org
BUILD_DEPENDS+=	cross-aarch64-none-elf-gcc-[0-9]*:../../cross/aarch64-none-elf-gcc

UBOOT_ENV+=	CROSS_COMPILE=${PREFIX}/cross-aarch64-none-elf/bin/aarch64-none-elf-

.include "u-boot.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.u-boot-${UBOOT_TARGET}
PKG_SUPPORTED_OPTIONS=	el1

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mel1)
UBOOT_OPTIONS+=	CONFIG_ARMV8_SWITCH_TO_EL1=y
.endif
