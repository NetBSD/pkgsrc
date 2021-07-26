# $NetBSD: Makefile,v 1.13 2021/07/26 06:36:41 mrg Exp $

UBOOT_TARGET=		rockpro64
UBOOT_CONFIG=		rockpro64-rk3399_defconfig
UBOOT_BIN=		idbloader.img rksd_loader.img rkspi_loader.img u-boot.itb
UBOOT_IMAGE_TYPE=	rk3399
UBOOT_VERSION?=		2021.07

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

.include "../../sysutils/u-boot/u-boot-rockchip.mk"
