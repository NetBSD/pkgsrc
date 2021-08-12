# $NetBSD: Makefile,v 1.4 2021/08/12 07:25:58 wiz Exp $

UBOOT_TARGET=		nanopi-r1
UBOOT_CONFIG=		nanopi_r1_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

PKGREVISION=	1

.include "../../sysutils/u-boot/u-boot-arm.mk"
.include "../../mk/bsd.pkg.mk"
