# $NetBSD: Makefile,v 1.7 2021/08/12 07:25:59 wiz Exp $

UBOOT_TARGET=		orangepi-zero
UBOOT_CONFIG=		orangepi_zero_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

PKGREVISION=		4

.include "../../sysutils/u-boot/u-boot-arm.mk"
.include "../../mk/bsd.pkg.mk"
