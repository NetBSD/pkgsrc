# $NetBSD: Makefile,v 1.13 2021/08/12 07:30:23 wiz Exp $

UBOOT_TARGET=		pinebook-pro
UBOOT_CONFIG=		pinebook-pro-rk3399_defconfig
UBOOT_BIN=		idbloader.img rksd_loader.img rkspi_loader.img u-boot.itb
UBOOT_IMAGE_TYPE=	rk3399
UBOOT_VERSION?=		2021.07

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

.include "../../sysutils/u-boot/u-boot-rockchip.mk"
.include "../../mk/bsd.pkg.mk"
