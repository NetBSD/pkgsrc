# $NetBSD: Makefile,v 1.1 2020/06/20 17:46:28 thorpej Exp $

UBOOT_TARGET=		ci20
UBOOT_CONFIG=		ci20_mmc_defconfig
UBOOT_BIN=		u-boot-spl.bin u-boot-dtb.img

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

#PKGREVISION=		4

UBOOT_VERSION=		2020.04

DISTINFO_FILE=		${.CURDIR}/../../sysutils/u-boot-ci20/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/u-boot-ci20/patches
DISTFILES=		${DEFAULT_DISTFILES}

post-build:
	cp ${WRKSRC}/spl/u-boot-spl.bin ${WRKSRC}/u-boot-spl.bin

.include "../../sysutils/u-boot/u-boot-mipsel.mk"
