# $NetBSD: Makefile,v 1.1 2019/06/08 12:25:05 mrg Exp $

UBOOT_TARGET=		rock64
UBOOT_CONFIG=		rock64-rk3328_defconfig
UBOOT_BIN=		idbloader.img rksd_loader.img u-boot.itb

DISTINFO_FILE=	${.CURDIR}/../../sysutils/u-boot-rock64/distinfo

U_BOOT_IMAGE_TYPE=	rk3328
.include "../../sysutils/u-boot/u-boot-rockchip.mk"

# Boot Loader stage 3-1 (BL31) EL3 Runtime Firmware
# XXX LICENSE?
BL31=		rk322xh_bl31_v1.40.elf
DISTFILES+=	${BL31}
SITES.${BL31}=	${MASTER_SITE_GITHUB:=rockchip-linux/rkbin/raw/master/bin/rk33/}

# DDR init binary
DDR_BIN=		rk3328_ddr_333MHz_v1.16.bin
SITES.${DDR_BIN}=	${MASTER_SITE_GITHUB:=rockchip-linux/rkbin/raw/master/bin/rk33/}
DISTFILES+=		${DDR_BIN}

.include "../../sysutils/u-boot/u-boot-arm64.mk"
