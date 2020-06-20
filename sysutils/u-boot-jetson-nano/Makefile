# $NetBSD: Makefile,v 1.1 2020/06/20 22:29:12 thorpej Exp $

UBOOT_TARGET=		jetson-nano
UBOOT_CONFIG=		p3450-0000_defconfig
UBOOT_BIN=		u-boot u-boot-dtb.bin

UBOOT_VERSION=		2020.04

DISTINFO_FILE=		${.CURDIR}/../../sysutils/u-boot-jetson-nano/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/u-boot-jetson-nano/patches
DISTFILES=		${DEFAULT_DISTFILES}

# This could be moved to u-boot.mk as long as we don't have support for
# any imx8 boards.
CHECK_PORTABILITY_SKIP+=	tools/imx8m_image.sh

# Switch to EL1 before booting kernel (required for 32-bit support)
PKG_DEFAULT_OPTIONS+=	el1

.include "../../sysutils/u-boot/u-boot-arm64.mk"
