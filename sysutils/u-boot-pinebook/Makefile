# $NetBSD: Makefile,v 1.15 2021/08/12 07:30:22 wiz Exp $

UBOOT_VERSION=		2018.11rc3
UBOOT_TARGET=		pinebook
UBOOT_CONFIG=		pinebook_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

# Use anarsoul's fork of mainline U-Boot with Pinebook support patched in
MASTER_SITES=		${MASTER_SITE_GITHUB:=anarsoul/}
GITHUB_PROJECT=		u-boot-pine64
GITHUB_TAG=		88eea875b3b82a0e50cbb112e0aea2259dc2e011
DISTNAME=		u-boot-${UBOOT_TARGET}-${UBOOT_VERSION}
EXTRACT_SUFX=		.tar.gz
PKGREVISION=		3

DISTINFO_FILE=		${.CURDIR}/../../sysutils/u-boot-pinebook/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/u-boot-pinebook/patches

CHECK_PORTABILITY_SKIP+=	tools/imx_cntr_image.sh

post-extract:
	${CP} ${PREFIX}/share/arm-trusted-firmware/sun50i_a64/bl31.bin ${WRKSRC}

post-build:
	${CAT} ${WRKSRC}/spl/sunxi-spl.bin ${WRKSRC}/u-boot.itb > ${WRKSRC}/u-boot-sunxi-with-spl.bin

.include "../../sysutils/arm-trusted-firmware-sun50i_a64/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-arm64.mk"
.include "../../mk/bsd.pkg.mk"
