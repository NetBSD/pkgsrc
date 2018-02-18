# $NetBSD: Makefile,v 1.3 2018/02/18 16:25:45 jmcneill Exp $

PKGREVISION=		3

UBOOT_TARGET=		pine64
UBOOT_CONFIG=		pine64_plus_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

# Switch to EL1 before booting kernel (required for 32-bit support)
PKG_DEFAULT_OPTIONS+=	el1

post-extract:
	${CP} ${PREFIX}/share/arm-trusted-firmware/sun50iw1p1/bl31.bin ${WRKSRC}

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} u-boot-sunxi-with-spl.bin

.include "../../sysutils/arm-trusted-firmware-sun50iw1p1/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-arm64.mk"
