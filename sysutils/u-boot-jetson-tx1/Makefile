# $NetBSD: Makefile,v 1.5 2018/12/14 00:52:26 jmcneill Exp $

UBOOT_TARGET=		jetson-tx1
UBOOT_CONFIG=		p2371-2180_defconfig
UBOOT_BIN=		u-boot u-boot-dtb.bin

# Switch to EL1 before booting kernel (required for 32-bit support)
PKG_DEFAULT_OPTIONS+=	el1

.include "../../sysutils/u-boot/u-boot-arm64.mk"
