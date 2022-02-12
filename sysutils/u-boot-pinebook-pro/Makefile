# $NetBSD: Makefile,v 1.16 2022/02/12 07:44:55 mrg Exp $

UBOOT_TARGET=		pinebook-pro
UBOOT_CONFIG=		pinebook-pro-rk3399_defconfig
UBOOT_BIN=		idbloader.img rksd_loader.img rkspi_loader.img u-boot.itb
UBOOT_IMAGE_TYPE=	rk3399
UBOOT_MKIMAGE_RKSPI=	1
UBOOT_RK_SPI_OFF=	768

PKGREVISION=		1

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

.include "../../sysutils/u-boot/u-boot-rockchip.mk"
.include "../../mk/bsd.pkg.mk"
