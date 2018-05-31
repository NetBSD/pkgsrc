# $NetBSD: Makefile,v 1.2 2018/05/31 20:25:15 wiz Exp $

UBOOT_VERSION=		2018.03rc1
UBOOT_TARGET=		pine-h64
UBOOT_CONFIG=		pine_h64_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

# Use Icenowy's fork of mainline U-Boot with Pine H64 support patched in
MASTER_SITES=		${MASTER_SITE_GITHUB:=Icenowy/}
GITHUB_PROJECT=		u-boot
GITHUB_TAG=		f4077661c6c0f3b92f26cb7c35432ad64615fe32
DISTNAME=		u-boot-${UBOOT_TARGET}-${UBOOT_VERSION}
EXTRACT_SUFX=		.tar.gz

post-extract:
	${CP} ${PREFIX}/share/arm-trusted-firmware/sun50i-h6/bl31.bin ${WRKSRC}

post-build:
	${CAT} ${WRKSRC}/spl/sunxi-spl.bin ${WRKSRC}/u-boot.itb > ${WRKSRC}/u-boot-sunxi-with-spl.bin

DISTINFO_FILE=		${.CURDIR}/../../sysutils/u-boot-pine-h64/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/u-boot-pine-h64/patches

.include "../../sysutils/arm-trusted-firmware-sun50i-h6/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-arm64.mk"
