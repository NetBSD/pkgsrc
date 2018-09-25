# $NetBSD: Makefile,v 1.2 2018/09/25 21:49:20 jmcneill Exp $

UBOOT_TARGET=		jetson-tx2
UBOOT_CONFIG=		p2771-0000-500_defconfig
UBOOT_BIN=		u-boot u-boot-dtb.bin

PKGREVISION=		1

# Switch to EL1 before booting kernel (required for 32-bit support)
PKG_DEFAULT_OPTIONS+=	el1

.include "../../sysutils/u-boot/u-boot-arm64.mk"
