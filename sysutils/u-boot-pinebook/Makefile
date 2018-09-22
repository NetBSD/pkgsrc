# $NetBSD: Makefile,v 1.7 2018/09/22 14:44:24 jmcneill Exp $

UBOOT_VERSION=		2018.07rc1
UBOOT_TARGET=		pinebook
UBOOT_CONFIG=		pinebook_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

# Use AOSC-Dev's fork of mainline U-Boot with Pinebook support patched in
MASTER_SITES=		${MASTER_SITE_GITHUB:=AOSC-Dev/}
GITHUB_PROJECT=		u-boot
GITHUB_TAG=		9533bb9d6b2052c3c4e88ce43b633f6ec67f324e
DISTNAME=		u-boot-${UBOOT_TARGET}-${UBOOT_VERSION}
EXTRACT_SUFX=		.tar.gz

DISTINFO_FILE=		${.CURDIR}/../../sysutils/u-boot-pinebook/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/u-boot-pinebook/patches

# Switch to EL1 before booting kernel (required for 32-bit support)
PKG_DEFAULT_OPTIONS+=	el1

post-extract:
	${CP} ${PREFIX}/share/arm-trusted-firmware/sun50iw1p1/bl31.bin ${WRKSRC}

post-build:
	${CAT} ${WRKSRC}/spl/sunxi-spl.bin ${WRKSRC}/u-boot.itb > ${WRKSRC}/u-boot-sunxi-with-spl.bin

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/tool.mk"

.include "../../sysutils/arm-trusted-firmware-sun50iw1p1/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-arm64.mk"
