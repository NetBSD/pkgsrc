# $NetBSD: Makefile,v 1.7 2019/11/04 21:28:54 rillig Exp $

UBOOT_TARGET=		beagleboneblack
UBOOT_CONFIG=		am335x_boneblack_defconfig
UBOOT_BIN=		u-boot.img
UBOOT_BIN+=		MLO

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

PKGREVISION=		4

.include "../../sysutils/u-boot/u-boot-arm.mk"
