# $NetBSD: Makefile,v 1.2 2020/01/06 09:43:16 mrg Exp $

PKGREVISION=            1
UBOOT_TARGET=		pinebook-pro
UBOOT_CONFIG=		pinebook_pro-rk3399_defconfig
UBOOT_BIN=		idbloader.img u-boot.itb rksd_loader.img

UBOOT_VERSION=		2020.01-rc5

DISTINFO_FILE=		${.CURDIR}/../../sysutils/u-boot-pinebook-pro/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/u-boot-pinebook-pro/patches

USE_TOOLS+=	gawk

MAKE_ENV+=	BL31=${PREFIX}/share/arm-trusted-firmware/rk3399/bl31.elf

post-build:
# wrap everything up into a single file that can be written to an SD card
	cp ${WRKSRC}/idbloader.img ${WRKSRC}/rksd_loader.img
	dd if=${WRKSRC}/u-boot.itb seek=448 conv=notrunc of=${WRKSRC}/rksd_loader.img

.include "../../sysutils/arm-trusted-firmware-rk3399/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-arm64.mk"
