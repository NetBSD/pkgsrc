# $NetBSD: Makefile,v 1.9 2021/08/12 07:25:55 wiz Exp $

UBOOT_TARGET=		bananapi-m3
UBOOT_CONFIG=		Sinovoip_BPI_M3_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

PKGREVISION=		4

.include "../../sysutils/u-boot/u-boot-arm.mk"
.include "../../mk/bsd.pkg.mk"
