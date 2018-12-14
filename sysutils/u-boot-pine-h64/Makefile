# $NetBSD: Makefile,v 1.3 2018/12/14 00:52:27 jmcneill Exp $

UBOOT_TARGET=		pine-h64
UBOOT_CONFIG=		pine_h64_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

post-extract:
	${CP} ${PREFIX}/share/arm-trusted-firmware/sun50i-h6/bl31.bin ${WRKSRC}

post-build:
	${CAT} ${WRKSRC}/spl/sunxi-spl.bin ${WRKSRC}/u-boot.itb > ${WRKSRC}/u-boot-sunxi-with-spl.bin

.include "../../sysutils/arm-trusted-firmware-sun50i-h6/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-arm64.mk"
