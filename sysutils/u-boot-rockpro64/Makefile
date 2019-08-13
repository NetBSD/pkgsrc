# $NetBSD: Makefile,v 1.5 2019/08/13 21:28:47 tnn Exp $

UBOOT_TARGET=		rockpro64
UBOOT_CONFIG=		rockpro64-rk3399_defconfig
UBOOT_BIN=		idbloader.img rksd_loader.img rkspi_loader.img u-boot.itb

DISTINFO_FILE=	${.CURDIR}/../../sysutils/u-boot-rockpro64/distinfo

U_BOOT_IMAGE_TYPE=	rk3399
.include "../../sysutils/u-boot/u-boot-rockchip.mk"

# Boot Loader stage 3-1 (BL31) EL3 Runtime Firmware
# XXX LICENSE?
BL31=		rk3399_bl31_v1.29.elf
DISTFILES+=	${BL31}
SITES.${BL31}=	${MASTER_SITE_GITHUB:=rockchip-linux/rkbin/raw/0b8a4e66958b5d3d87fc61fc4bd8e069c79e931a/bin/rk33/}

# DDR init binary
DDR_BIN=		rk3399_ddr_800MHz_v1.23.bin
SITES.${DDR_BIN}=	${MASTER_SITE_GITHUB:=rockchip-linux/rkbin/raw/016471bcfb1a0b1e1269895cb7b6f534813edfdc/bin/rk33/}
DISTFILES+=		${DDR_BIN}

.include "../../sysutils/u-boot/u-boot-arm64.mk"
