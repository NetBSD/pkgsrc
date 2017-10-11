# $NetBSD: Makefile,v 1.1 2017/10/11 20:34:18 jmcneill Exp $

UBOOT_TARGET=		nanopi-neo2
UBOOT_CONFIG=		nanopi_neo2_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

# Switch to EL1 before booting kernel (required for 32-bit support)
PKG_DEFAULT_OPTIONS+=	el1

post-extract:
	${CP} ${PREFIX}/share/arm-trusted-firmware/sun50iw1p1/bl31.bin ${WRKSRC}

BUILD_DEPENDS+=		arm-trusted-firmware-sun50iw1p1-[0-9]*:../../sysutils/arm-trusted-firmware-sun50iw1p1

post-build:
	${CAT} ${WRKSRC}/spl/sunxi-spl.bin ${WRKSRC}/u-boot.itb > ${WRKSRC}/u-boot-sunxi-with-spl.bin

.include "../../sysutils/u-boot/u-boot-arm64.mk"
