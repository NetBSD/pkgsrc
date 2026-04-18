# $NetBSD: Makefile,v 1.9 2026/04/18 19:55:24 jmcneill Exp $

UBOOT_TARGET=		sopine-baseboard
UBOOT_CONFIG=		sopine_baseboard_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin
UBOOT_ENV+=		BL31=${PREFIX}/share/arm-trusted-firmware/sun50i_a64/bl31.bin
UBOOT_VERSION=		2024.10
UBOOT_OPTIONS+=		CONFIG_TOOLS_MKEFICAPSULE=n

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

.include "../../sysutils/arm-trusted-firmware-sun50i_a64/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-arm64.mk"
.include "../../mk/bsd.pkg.mk"
