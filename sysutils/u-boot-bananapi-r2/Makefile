# $NetBSD: Makefile,v 1.1 2019/01/03 05:12:49 thorpej Exp $

UBOOT_TARGET=		bananapi-r2
UBOOT_CONFIG=		mt7623n_bpir2_defconfig
UBOOT_BIN=		u-boot-mtk.bin

UBOOT_VERSION=		2019.01-rc2

DISTINFO_FILE=		${.CURDIR}/../../sysutils/u-boot-bananapi-r2/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/u-boot-bananapi-r2/patches
DISTFILES=		${DEFAULT_DISTFILES}

.include "../../sysutils/u-boot/u-boot-arm.mk"
