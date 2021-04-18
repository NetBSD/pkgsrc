# $NetBSD: Makefile,v 1.9 2021/04/18 07:30:28 mrg Exp $

PKGREVISION=		5

UBOOT_TARGET=		pinebook-pro
UBOOT_CONFIG=		pinebook_pro-rk3399_defconfig
UBOOT_BIN=		idbloader.img rksd_loader.img rkspi_loader.img u-boot.itb

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

U_BOOT_IMAGE_TYPE=	rk3399

# Patches kept in pinebook-pro; first worked there.
DISTINFO_FILE=		${.CURDIR}/../../sysutils/u-boot-pinebook-pro/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/u-boot-pinebook-pro/patches

.include "../../sysutils/u-boot/u-boot-rockchip.mk"
