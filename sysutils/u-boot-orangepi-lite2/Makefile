# $NetBSD: Makefile,v 1.1 2020/04/04 15:20:35 thorpej Exp $

UBOOT_TARGET=		orangepi-lite2
UBOOT_CONFIG=		orangepi_lite2_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

post-extract:
	${CP} ${PREFIX}/share/arm-trusted-firmware/sun50i-h6/bl31.bin ${WRKSRC}

post-build:
	${CAT} ${WRKSRC}/spl/sunxi-spl.bin ${WRKSRC}/u-boot.itb > ${WRKSRC}/u-boot-sunxi-with-spl.bin

.include "../../sysutils/arm-trusted-firmware-sun50i-h6/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-arm64.mk"
