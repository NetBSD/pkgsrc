# $NetBSD: Makefile,v 1.1 2017/09/01 21:04:09 jmcneill Exp $

UBOOT_TARGET=		pine64-plus
UBOOT_CONFIG=		pine64_plus_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

post-extract:
	${CP} ${PREFIX}/share/arm-trusted-firmware/sun50iw1p1/bl31.bin ${WRKSRC}

BUILD_DEPENDS+=		arm-trusted-firmware-sun50iw1p1-[0-9]*:../../sysutils/arm-trusted-firmware-sun50iw1p1

post-build:
	${CAT} ${WRKSRC}/spl/sunxi-spl.bin ${WRKSRC}/u-boot.itb > ${WRKSRC}/u-boot-sunxi-with-spl.bin

.include "../../sysutils/u-boot/u-boot-arm64.mk"
