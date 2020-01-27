# $NetBSD: Makefile,v 1.5 2020/01/27 08:02:29 thorpej Exp $

PKGREVISION=		3

UBOOT_TARGET=		pinebook-pro
UBOOT_CONFIG=		pinebook_pro-rk3399_defconfig
UBOOT_BIN=		idbloader.img rksd_loader.img rkspi_loader.img u-boot.itb

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

U_BOOT_IMAGE_TYPE=	rk3399

.include "../../sysutils/u-boot-pinebook-pro/u-boot-rockchip.mk"
