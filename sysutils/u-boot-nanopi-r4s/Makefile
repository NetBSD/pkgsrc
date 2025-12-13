# $NetBSD: Makefile,v 1.1 2025/12/13 01:10:23 gutteridge Exp $

UBOOT_TARGET=		nanopi-r4s
UBOOT_CONFIG=		nanopi-r4s-rk3399_defconfig
UBOOT_BIN=		idbloader.img rksd_loader.img rkspi_loader.img u-boot.itb
UBOOT_IMAGE_TYPE=	rk3399
UBOOT_MKIMAGE_RKSPI=	1
UBOOT_RK_SPI_OFF=	768

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

.include "../../sysutils/u-boot/u-boot-rockchip.mk"
.include "../../mk/bsd.pkg.mk"
