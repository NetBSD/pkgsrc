# $NetBSD: u-boot-rockchip.mk,v 1.18 2023/08/27 23:12:52 gutteridge Exp $
#
# used by sysutils/u-boot-nanopi-r2s/Makefile
# used by sysutils/u-boot-rock64/Makefile
# used by sysutils/u-boot-rockpro64/Makefile
# used by sysutils/u-boot-pinebook-pro/Makefile

# Common makefile fragment for rockchip based u-boot targets.
#
# Set these variables:
#
#	UBOOT_IMAGE_TYPE	("rk3399", "rk3328")
#

UBOOT_VERSION?=		2022.01

TFA=			trusted-firmware-a

# Earlier SPIs were at sector 1024, but newer u-boot has a DT that
# loads them from 768.  Until all are converted, leave the default
# at 1024.
UBOOT_RK_SPI_OFF?=	1024

MAKE_ENV+=		BL31=${PREFIX}/share/${TFA}/${UBOOT_IMAGE_TYPE}/bl31.elf

post-build:
# Wrap everything up into a single file that can be written to an SD card.
# Note that the SD image starts at sector 64, and 64 + 448 = 512, so the
# u-boot.itb is loaded at 256KiB on the card itself.
	cp ${WRKSRC}/idbloader.img ${WRKSRC}/rksd_loader.img
	dd if=${WRKSRC}/u-boot.itb seek=448 conv=notrunc of=${WRKSRC}/rksd_loader.img
.if defined(UBOOT_MKIMAGE_RKSPI)
	 ${WRKSRC}/tools/mkimage \
		-n ${UBOOT_IMAGE_TYPE} \
		-T rkspi \
		-d ${WRKSRC}/tpl/u-boot-tpl.bin:${WRKSRC}/spl/u-boot-spl.bin \
		${WRKSRC}/rkspi_loader.img
.else
# Build SPI NOR flash image. See u-boot-rock64.
	set -e; b=0; while [ "$$b" != 128 ]; do \
		dd bs=2k count=1; \
		dd if=/dev/zero bs=2k count=1; \
		b=$$(expr $$b + 1); \
	done < ${WRKSRC}/idbloader.img > ${WRKSRC}/rkspi_loader.img 2> /dev/null
.endif
	dd if=${WRKSRC}/u-boot.itb seek=${UBOOT_RK_SPI_OFF} conv=notrunc of=${WRKSRC}/rkspi_loader.img

BUILD_TARGET+= V=1

.include "../../sysutils/${TFA}-${UBOOT_IMAGE_TYPE}/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-arm64.mk"
