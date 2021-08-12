# $NetBSD: Makefile,v 1.7 2021/08/12 07:25:55 wiz Exp $

UBOOT_TARGET=		beagleboard
UBOOT_CONFIG=		omap3_beagle_defconfig
UBOOT_BIN=		u-boot.img
UBOOT_BIN+=		MLO

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

PKGREVISION=		4

.include "../../sysutils/u-boot/u-boot-arm.mk"
.include "../../mk/bsd.pkg.mk"
