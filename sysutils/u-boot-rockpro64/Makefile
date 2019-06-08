# $NetBSD: Makefile,v 1.3 2019/06/08 12:25:05 mrg Exp $

UBOOT_TARGET=		rockpro64
UBOOT_CONFIG=		rockpro64-rk3399_defconfig
UBOOT_BIN=		idbloader.img rksd_loader.img u-boot.itb

DISTINFO_FILE=	${.CURDIR}/../../sysutils/u-boot-rockpro64/distinfo

U_BOOT_IMAGE_TYPE=	rk3399
.include "../../sysutils/u-boot/u-boot-rockchip.mk"

# Boot Loader stage 3-1 (BL31) EL3 Runtime Firmware
# XXX LICENSE?
BL31=		rk3399_bl31_v1.18.elf
DISTFILES+=	${BL31}
SITES.${BL31}=	${MASTER_SITE_GITHUB:=rockchip-linux/rkbin/raw/9e6625e7551ffa591f0ac4c271f12a7ab5cedcf4/bin/rk33/}

# DDR init binary
DDR_BIN=		rk3399_ddr_800MHz_v1.14.bin
SITES.${DDR_BIN}=	${MASTER_SITE_GITHUB:=rockchip-linux/rkbin/raw/dbc8710a93406669fb2df2d57dc086228bf1979f/bin/rk33/}
DISTFILES+=		${DDR_BIN}

.include "../../sysutils/u-boot/u-boot-arm64.mk"
