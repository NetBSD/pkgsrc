# $NetBSD: Makefile,v 1.1 2023/08/27 23:12:52 gutteridge Exp $

UBOOT_TARGET=		nanopi-r2s
UBOOT_CONFIG=		nanopi-r2s-rk3328_defconfig
UBOOT_BIN=		idbloader.img rksd_loader.img rkspi_loader.img u-boot.itb
UBOOT_IMAGE_TYPE=	rk3328
UBOOT_MKIMAGE_RKSPI=	1
UBOOT_RK_SPI_OFF=	768

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

.include "../../sysutils/u-boot/u-boot-rockchip.mk"
.include "../../mk/bsd.pkg.mk"
