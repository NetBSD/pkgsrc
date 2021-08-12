# $NetBSD: Makefile,v 1.2 2021/08/12 07:25:59 wiz Exp $

UBOOT_TARGET=		pandaboard
UBOOT_CONFIG=		omap4_panda_defconfig
UBOOT_BIN=		u-boot.img
UBOOT_BIN+=		MLO

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

.include "../../sysutils/u-boot/u-boot-arm.mk"
.include "../../mk/bsd.pkg.mk"
