# $NetBSD: Makefile,v 1.5 2019/05/08 05:14:20 thorpej Exp $

UBOOT_TARGET=		beaglebonewhite
UBOOT_CONFIG=		am335x_evm_defconfig
UBOOT_BIN=		u-boot.img
UBOOT_BIN+= 		MLO

UBOOT_INSTALLBOOT_PLIST=installboot.plist

PKGREVISION=		4

.include "../../sysutils/u-boot/u-boot-arm.mk"
