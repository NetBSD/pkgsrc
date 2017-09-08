# $NetBSD: Makefile,v 1.1 2017/09/08 10:25:17 jmcneill Exp $

UBOOT_TARGET=		jetson-tx1
UBOOT_CONFIG=		p2371-2180_defconfig
UBOOT_BIN=		u-boot.bin

# Switch to EL1 before booting kernel (required for 32-bit support)
PKG_DEFAULT_OPTIONS+=	el1

.include "../../sysutils/u-boot/u-boot-arm64.mk"
