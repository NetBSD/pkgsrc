# $NetBSD: Makefile,v 1.2 2021/08/12 07:25:58 wiz Exp $

UBOOT_TARGET=		orangepi-lite
UBOOT_CONFIG=		orangepi_lite_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

PKGREVISION=		4

.include "../../sysutils/u-boot/u-boot-arm.mk"
.include "../../mk/bsd.pkg.mk"
