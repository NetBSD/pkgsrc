# $NetBSD: Makefile,v 1.1 2020/06/21 19:43:48 thorpej Exp $

UBOOT_TARGET=		libretech-all-h3-cc-h5
UBOOT_CONFIG=		libretech_all_h3_cc_h5_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

# Switch to EL1 before booting kernel (required for 32-bit support)
PKG_DEFAULT_OPTIONS+=	el1

post-extract:
	${CP} ${PREFIX}/share/arm-trusted-firmware/sun50i_a64/bl31.bin ${WRKSRC}

post-build:
	${CAT} ${WRKSRC}/spl/sunxi-spl.bin ${WRKSRC}/u-boot.itb > ${WRKSRC}/u-boot-sunxi-with-spl.bin

.include "../../sysutils/arm-trusted-firmware-sun50i_a64/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-arm64.mk"
