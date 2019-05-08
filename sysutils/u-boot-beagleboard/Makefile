# $NetBSD: Makefile,v 1.5 2019/05/08 05:14:19 thorpej Exp $

UBOOT_TARGET=		beagleboard
UBOOT_CONFIG=		omap3_beagle_defconfig
UBOOT_BIN=		u-boot.img
UBOOT_BIN+= 		MLO

UBOOT_INSTALLBOOT_PLIST=installboot.plist

PKGREVISION=		4

.include "../../sysutils/u-boot/u-boot-arm.mk"
