# $NetBSD: Makefile,v 1.10 2020/04/02 09:12:54 tnn Exp $

UBOOT_TARGET=		rockpro64
UBOOT_CONFIG=		rockpro64-rk3399_defconfig
UBOOT_BIN=		idbloader.img rksd_loader.img rkspi_loader.img u-boot.itb

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

U_BOOT_IMAGE_TYPE=	rk3399

.include "../../sysutils/u-boot/u-boot-rockchip.mk"
