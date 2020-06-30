# $NetBSD: Makefile,v 1.1 2020/06/30 14:40:05 thorpej Exp $

UBOOT_TARGET=		roc-rk3328-cc
UBOOT_CONFIG=		roc-cc-rk3328_defconfig
UBOOT_BIN=		u-boot-rockchip.bin

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

UBOOT_VERSION=		2020.07-rc4

DISTINFO_FILE=		${.CURDIR}/../../sysutils/u-boot-roc-rk3328-cc/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/u-boot-roc-rk3328-cc/patches
DISTFILES=		${DEFAULT_DISTFILES}

# This could be moved to u-boot.mk as long as we don't have support for
# any imx8 boards.
CHECK_PORTABILITY_SKIP+=	tools/imx8m_image.sh

# Switch to EL1 before booting kernel (required for 32-bit support)
PKG_DEFAULT_OPTIONS+=	el1

post-extract:
	${CP} ${PREFIX}/share/arm-trusted-firmware/rk3328/bl31.elf ${WRKSRC}

.include "../../sysutils/arm-trusted-firmware-rk3328/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-arm64.mk"
