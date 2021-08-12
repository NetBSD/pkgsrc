# $NetBSD: Makefile,v 1.2 2021/08/12 07:25:55 wiz Exp $

UBOOT_TARGET=		a20-olinuxino-micro-emmc
UBOOT_CONFIG=		A20-OLinuXino_MICRO-eMMC_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

.include "../../sysutils/u-boot/u-boot-arm.mk"
.include "../../mk/bsd.pkg.mk"
