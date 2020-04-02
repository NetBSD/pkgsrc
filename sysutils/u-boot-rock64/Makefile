# $NetBSD: Makefile,v 1.6 2020/04/02 09:09:05 tnn Exp $

PKGREVISION=		6
UBOOT_TARGET=		rock64
UBOOT_CONFIG=		rock64-rk3328_defconfig
UBOOT_BIN=		idbloader.img rksd_loader.img rkspi_loader.img u-boot.itb

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

DISTINFO_FILE=	${.CURDIR}/../../sysutils/u-boot-rock64/distinfo

U_BOOT_IMAGE_TYPE=	rk3328
.include "../../sysutils/u-boot-rock64/u-boot-rockchip.mk"

# Boot Loader stage 3-1 (BL31) EL3 Runtime Firmware
# XXX LICENSE?
BL31=		rk322xh_bl31_v1.41.elf
DISTFILES+=	${BL31}
SITES.${BL31}=	${MASTER_SITE_GITHUB:=rockchip-linux/rkbin/raw/fc322b129b4438307ac18cbdc73c38400c7b33d9/bin/rk33/}

# DDR init binary
DDR_BIN=		rk3328_ddr_333MHz_v1.16.bin
SITES.${DDR_BIN}=	${MASTER_SITE_GITHUB:=rockchip-linux/rkbin/raw/6ee03f14441f4f2812c713e1027b88e3a24c546b/bin/rk33/}
DISTFILES+=		${DDR_BIN}

.include "../../sysutils/u-boot/u-boot-arm64.mk"
