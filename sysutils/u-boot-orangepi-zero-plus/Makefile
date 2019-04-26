# $NetBSD: Makefile,v 1.5 2019/04/26 08:32:30 skrll Exp $

UBOOT_TARGET=		orangepi-zero-plus
UBOOT_CONFIG=		orangepi_zero_plus_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

PKGREVISION=		4

# Switch to EL1 before booting kernel (required for 32-bit support)
PKG_DEFAULT_OPTIONS+=   el1

post-extract:
	${CP} ${PREFIX}/share/arm-trusted-firmware/sun50i_a64/bl31.bin ${WRKSRC}

post-build:
	${CAT} ${WRKSRC}/spl/sunxi-spl.bin ${WRKSRC}/u-boot.itb > ${WRKSRC}/u-boot-sunxi-with-spl.bin

.include "../../sysutils/arm-trusted-firmware-sun50i_a64/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-arm64.mk"
