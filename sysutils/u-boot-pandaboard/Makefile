# $NetBSD: Makefile,v 1.1 2020/06/21 03:27:58 thorpej Exp $

UBOOT_TARGET=		pandaboard
UBOOT_CONFIG=		omap4_panda_defconfig
UBOOT_BIN=		u-boot.img
UBOOT_BIN+=		MLO

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

.include "../../sysutils/u-boot/u-boot-arm.mk"
