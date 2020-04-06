# $NetBSD: Makefile,v 1.1 2020/04/06 15:08:34 tnn Exp $

UBOOT_TARGET=		rockpro64
UBOOT_CONFIG=		rockpro64-rk3399_defconfig
UBOOT_BIN=		idbloader.img rksd_loader.img rkspi_loader.img u-boot.itb

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

U_BOOT_IMAGE_TYPE=	rk3399

DISTINFO_FILE?=         ${.CURDIR}/../../sysutils/u-boot-rockpro64-ayufan/distinfo
PATCHDIR?=              ${.CURDIR}/../../sysutils/u-boot-rockpro64-ayufan/patches

UBOOT_VERSION=  2020.01.2007
MASTER_SITES=   ${MASTER_SITE_GITHUB:=ayufan-rock64/}
GITHUB_PROJECT=	linux-mainline-u-boot
GITHUB_TAG=	2020.01-ayufan-2007-g928e3ac6
DISTNAME=	u-boot-rockpro64-ayufan-${GITHUB_TAG}
EXTRACT_SUFX=	.tar.gz	# keep this
PKGNAME=	u-boot-rockpro64-ayufan-${UBOOT_VERSION}

.include "../../sysutils/u-boot/u-boot-rockchip.mk"
