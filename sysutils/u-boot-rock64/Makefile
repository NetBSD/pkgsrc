# $NetBSD: Makefile,v 1.12 2022/02/11 23:03:50 mrg Exp $

UBOOT_TARGET=		rock64
UBOOT_CONFIG=		rock64-rk3328_defconfig
UBOOT_BIN=		idbloader.img rksd_loader.img rkspi_loader.img u-boot.itb
UBOOT_IMAGE_TYPE=	rk3328
UBOOT_RK_SPI_OFF=	768

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

.include "../../sysutils/u-boot/u-boot-rockchip.mk"
.include "../../mk/bsd.pkg.mk"
