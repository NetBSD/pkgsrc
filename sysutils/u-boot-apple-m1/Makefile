# $NetBSD: Makefile,v 1.5 2021/08/19 07:47:48 wiz Exp $

UBOOT_TARGET=		apple-m1
UBOOT_CONFIG=		apple_m1_defconfig
UBOOT_BIN=		u-boot-nodtb.bin u-boot.macho

DISTINFO_FILE?=		${.CURDIR}/../../sysutils/u-boot-apple-m1/distinfo
PATCHDIR?=		${.CURDIR}/../../sysutils/u-boot-apple-m1/patches

UBOOT_VERSION=	2021.01
GITHUB_PROJECT=	u-boot
GITHUB_TAG=	efe1ec684e2fdaeca38422e5373bdde046ec1f20
MASTER_SITES=	${MASTER_SITE_GITHUB:=kettenis/}
DIST_SUBDIR=	${GITHUB_PROJECT}
DISTNAME=	u-boot-apple-m1-${GITHUB_TAG}
EXTRACT_SUFX=	.tar.gz	# keep this
PKGNAME=	u-boot-apple-m1-${UBOOT_VERSION}
BUILD_TARGET=	u-boot-nodtb.bin

BUILD_DEPENDS+=	preloader-m1>=0:../../sysutils/preloader-m1
BUILD_DEPENDS+=	dtb-arm64-apple-m1>=0:../../sysutils/dtb-arm64-apple-m1

post-build:
	${PREFIX}/bin/machopack ${WRKSRC}/u-boot.macho \
	    ${PREFIX}/share/preloader-m1/preboot.bin@0x803040000 \
	    ${WRKSRC}/u-boot-nodtb.bin@0x803080000 \
	    ${PREFIX}/share/dtb/arm64/apple/apple-m1-j274.dtb@0x803060000

.include "../../sysutils/u-boot/u-boot-arm64.mk"
.include "../../mk/bsd.pkg.mk"
