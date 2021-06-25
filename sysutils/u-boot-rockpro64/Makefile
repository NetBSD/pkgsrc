# $NetBSD: Makefile,v 1.12 2021/06/25 08:28:57 mrg Exp $

UBOOT_TARGET=		rockpro64
UBOOT_CONFIG=		rockpro64-rk3399_defconfig
UBOOT_BIN=		idbloader.img rksd_loader.img rkspi_loader.img u-boot.itb

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

UBOOT_IMAGE_TYPE=	rk3399

.include "../../sysutils/u-boot/u-boot-rockchip.mk"
