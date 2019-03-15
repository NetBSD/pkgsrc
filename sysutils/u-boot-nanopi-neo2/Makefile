# $NetBSD: Makefile,v 1.6 2019/03/15 13:59:38 martin Exp $

UBOOT_TARGET=		nanopi-neo2
UBOOT_CONFIG=		nanopi_neo2_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

PKGREVISION=		2

# Switch to EL1 before booting kernel (required for 32-bit support)
PKG_DEFAULT_OPTIONS+=	el1

post-extract:
	${CP} ${PREFIX}/share/arm-trusted-firmware/sun50i_a64/bl31.bin ${WRKSRC}

post-build:
	${CAT} ${WRKSRC}/spl/sunxi-spl.bin ${WRKSRC}/u-boot.itb > ${WRKSRC}/u-boot-sunxi-with-spl.bin

.include "../../sysutils/arm-trusted-firmware-sun50i_a64/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-arm64.mk"
