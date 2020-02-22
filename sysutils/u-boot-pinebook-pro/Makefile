# $NetBSD: Makefile,v 1.6 2020/02/22 11:55:36 mrg Exp $

PKGREVISION=		4

UBOOT_TARGET=		pinebook-pro
UBOOT_CONFIG=		pinebook_pro-rk3399_defconfig
UBOOT_BIN=		idbloader.img rksd_loader.img rkspi_loader.img u-boot.itb

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

U_BOOT_IMAGE_TYPE=	rk3399

.include "../../sysutils/u-boot-pinebook-pro/u-boot-rockchip.mk"
