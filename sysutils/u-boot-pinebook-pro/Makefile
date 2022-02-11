# $NetBSD: Makefile,v 1.14 2022/02/11 22:06:22 mrg Exp $

UBOOT_TARGET=		pinebook-pro
UBOOT_CONFIG=		pinebook-pro-rk3399_defconfig
UBOOT_BIN=		idbloader.img rksd_loader.img rkspi_loader.img u-boot.itb
UBOOT_IMAGE_TYPE=	rk3399
UBOOT_VERSION?=		2022.01
UBOOT_MKIMAGE_RKSPI=	1
UBOOT_RK_SPI_OFF=	768

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

.include "../../sysutils/u-boot/u-boot-rockchip.mk"
.include "../../mk/bsd.pkg.mk"
