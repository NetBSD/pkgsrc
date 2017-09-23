# $NetBSD: Makefile,v 1.2 2017/09/23 17:33:12 jmcneill Exp $

PKGREVISION=		1

UBOOT_TARGET=		jetson-tx1
UBOOT_CONFIG=		p2371-2180_defconfig
UBOOT_BIN=		u-boot u-boot-dtb.bin

# Switch to EL1 before booting kernel (required for 32-bit support)
PKG_DEFAULT_OPTIONS+=	el1

.include "../../sysutils/u-boot/u-boot-arm64.mk"
