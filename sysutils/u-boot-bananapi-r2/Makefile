# $NetBSD: Makefile,v 1.8 2020/06/20 17:42:34 thorpej Exp $

UBOOT_TARGET=		bananapi-r2
UBOOT_CONFIG=		mt7623n_bpir2_defconfig
UBOOT_BIN=		bpi-r2-sdmmc.img u-boot.bin

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

UBOOT_VERSION=		2020.04

DISTINFO_FILE=		${.CURDIR}/../../sysutils/u-boot-bananapi-r2/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/u-boot-bananapi-r2/patches
DISTFILES=		${DEFAULT_DISTFILES}

# This could be moved to u-boot.mk as long as we don't have support for
# any imx8 boards.
CHECK_PORTABILITY_SKIP+=	tools/imx8m_image.sh

# SDMMC_BOOT-signature
SDMMC_BOOT_IMG=		BPI-R2-HEAD440-0k.img
DISTFILES+=		${SDMMC_BOOT_IMG}
UBOOT_BIN+=		${SDMMC_BOOT_IMG}
SITES.${SDMMC_BOOT_IMG}= ${MASTER_SITE_GITHUB:=BPI-SINOVOIP/BPI-R2-bsp/raw/v1.2.1/mt-pack/mtk/bpi-r2/bin/}

# BRLYT-signature
BRLYT_IMG=		BPI-R2-HEAD1-512b.img
DISTFILES+=		${BRLYT_IMG}
UBOOT_BIN+=		${BRLYT_IMG}
SITES.${BRLYT_IMG}=	${MASTER_SITE_GITHUB:=BPI-SINOVOIP/BPI-R2-bsp/raw/v1.2.1/mt-pack/mtk/bpi-r2/bin/}

# Preloader
PRELOADER_BIN=		preloader_iotg7623Np1_sd_1600M.bin
DISTFILES+=		${PRELOADER_BIN}
UBOOT_BIN+=		${PRELOADER_BIN}
SITES.${PRELOADER_BIN}=	${MASTER_SITE_GITHUB:=BPI-SINOVOIP/BPI-R2-bsp/raw/v1.2.1/mt-pack/mtk/bpi-r2/bin/}

# pkgsrc tries to run distfiles that end in .bin; handle manually
EXTRACT_ONLY=		${DISTFILES:N*.bin}

post-extract:
	cp ${DISTDIR}/${SDMMC_BOOT_IMG} ${DISTDIR}/${BRLYT_IMG} \
	    ${DISTDIR}/${PRELOADER_BIN} ${WRKSRC}

post-build:
# Prepare an image that can be written to an SD card.  First is the
# SDMMC_BOOT signature + address of second header (offset 0x200).
	dd if=${WRKSRC}/${SDMMC_BOOT_IMG} of=${WRKSRC}/bpi-r2-sdmmc.img \
	    bs=512 seek=0
# Append the second header (BRLTY signature) + address of preloader
# (offset 0x800).
	dd if=${WRKSRC}/${BRLYT_IMG} of=${WRKSRC}/bpi-r2-sdmmc.img \
	    bs=512 seek=1
# Append preloader.
	dd if=${WRKSRC}/${PRELOADER_BIN} of=${WRKSRC}/bpi-r2-sdmmc.img \
	    bs=1024 seek=2
# Append U-boot image (offset 320KiB)
	dd if=${WRKSRC}/u-boot.bin of=${WRKSRC}/bpi-r2-sdmmc.img \
	    bs=1024 seek=320 conv=sync

.include "../../sysutils/u-boot/u-boot-arm.mk"
