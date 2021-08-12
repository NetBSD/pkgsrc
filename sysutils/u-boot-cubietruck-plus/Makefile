# $NetBSD: Makefile,v 1.5 2021/08/12 07:25:56 wiz Exp $

UBOOT_TARGET=		cubietruck-plus
UBOOT_CONFIG=		Cubietruck_plus_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

PKGREVISION=		2

.include "../../sysutils/u-boot/u-boot-arm.mk"
.include "../../mk/bsd.pkg.mk"
