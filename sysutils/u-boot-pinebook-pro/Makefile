# $NetBSD: Makefile,v 1.1 2020/01/06 08:41:44 mrg Exp $

UBOOT_TARGET=		pinebook-pro
UBOOT_CONFIG=		pinebook_pro-rk3399_defconfig
UBOOT_BIN=		idbloader.img u-boot.itb

UBOOT_VERSION=		2020.01-rc5

DISTINFO_FILE=		${.CURDIR}/../../sysutils/u-boot-pinebook-pro/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/u-boot-pinebook-pro/patches

USE_TOOLS+=	gawk

MAKE_ENV+=	BL31=${PREFIX}/share/arm-trusted-firmware/rk3399/bl31.elf

.include "../../sysutils/arm-trusted-firmware-rk3399/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-arm64.mk"
