# $NetBSD: Makefile,v 1.6 2019/11/04 21:28:54 rillig Exp $

UBOOT_TARGET=		beagleboard
UBOOT_CONFIG=		omap3_beagle_defconfig
UBOOT_BIN=		u-boot.img
UBOOT_BIN+=		MLO

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

PKGREVISION=		4

.include "../../sysutils/u-boot/u-boot-arm.mk"
