# $NetBSD: Makefile,v 1.14 2021/07/27 19:23:43 tnn Exp $

UBOOT_TARGET=		rockpro64
UBOOT_CONFIG=		rockpro64-rk3399_defconfig
UBOOT_BIN=		idbloader.img rksd_loader.img rkspi_loader.img u-boot.itb
UBOOT_IMAGE_TYPE=	rk3399
UBOOT_VERSION?=		2021.07
PKGREVISION=		1

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

.include "../../sysutils/u-boot/u-boot-rockchip.mk"
