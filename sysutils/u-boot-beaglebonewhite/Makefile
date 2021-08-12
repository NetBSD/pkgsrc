# $NetBSD: Makefile,v 1.7 2021/08/12 07:25:56 wiz Exp $

UBOOT_TARGET=		beaglebonewhite
UBOOT_CONFIG=		am335x_evm_defconfig
UBOOT_BIN=		u-boot.img
UBOOT_BIN+=		MLO

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

PKGREVISION=		4

.include "../../sysutils/u-boot/u-boot-arm.mk"
.include "../../mk/bsd.pkg.mk"
