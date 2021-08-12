# $NetBSD: Makefile,v 1.3 2021/08/12 07:25:57 wiz Exp $

UBOOT_TARGET=		nanopi-duo2
UBOOT_CONFIG=		nanopi_duo2_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

.include "../../sysutils/u-boot/u-boot-arm.mk"
.include "../../mk/bsd.pkg.mk"
