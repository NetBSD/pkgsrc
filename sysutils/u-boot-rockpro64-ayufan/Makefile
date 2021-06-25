# $NetBSD: Makefile,v 1.4 2021/06/25 08:28:57 mrg Exp $

UBOOT_TARGET=		rockpro64
UBOOT_CONFIG=		rockpro64-rk3399_defconfig
UBOOT_BIN=		idbloader.img rksd_loader.img rkspi_loader.img u-boot.itb

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

UBOOT_IMAGE_TYPE=	rk3399

UBOOT_VERSION=  2020.01.2014
MASTER_SITES=   ${MASTER_SITE_GITHUB:=ayufan-rock64/}
GITHUB_PROJECT=	linux-mainline-u-boot
GITHUB_TAG=	2020.01-ayufan-2014-gff2cdd38
DISTNAME=	u-boot-rockpro64-ayufan-${GITHUB_TAG}
EXTRACT_SUFX=	.tar.gz	# keep this
PKGNAME=	u-boot-rockpro64-ayufan-${UBOOT_VERSION}

.include "../../sysutils/u-boot/u-boot-rockchip.mk"
