# $NetBSD: Makefile,v 1.17 2022/02/11 23:03:50 mrg Exp $

UBOOT_TARGET=		rockpro64
UBOOT_CONFIG=		rockpro64-rk3399_defconfig
UBOOT_BIN=		idbloader.img rksd_loader.img rkspi_loader.img u-boot.itb
UBOOT_IMAGE_TYPE=	rk3399
UBOOT_MKIMAGE_RKSPI=	1
UBOOT_RK_SPI_OFF=	768

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

.include "../../sysutils/u-boot/u-boot-rockchip.mk"
.include "../../mk/bsd.pkg.mk"
