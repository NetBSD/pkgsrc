# $NetBSD: Makefile,v 1.1 2017/09/01 21:02:39 jmcneill Exp $

VERSION=	20170831
GITHUB_PROJECT=	arm-trusted-firmware
GITHUB_TAG=	aa75c8da415158a94b82a430b2b40000778e851f

PKGNAME=	${GITHUB_PROJECT}-sun50iw1p1-${VERSION}
DISTNAME=	${PKGNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=apritzel/}
EXTRACT_SUFX=	.zip

MAINTAINER=	port-arm@NetBSD.org
HOMEPAGE=	https://github.com/apritzel/arm-trusted-firmware/
COMMENT=	ARM Trusted Firmware for Allwinner sun50iw1p1 SoCs
LICENSE=	modified-bsd

USE_TOOLS+=	gmake

MAKE_FLAGS+=	CROSS_COMPILE=${PREFIX}/cross-aarch64-none-elf/bin/aarch64-none-elf-
MAKE_FLAGS+=	PLAT=sun50iw1p1
MAKE_FLAGS+=	DEBUG=1
MAKE_FLAGS+=	BUILD_STRING=${GITHUB_TAG}
BUILD_TARGET=	bl31

BUILD_DEPENDS+=	cross-aarch64-none-elf-gcc-[0-9]*:../../cross/aarch64-none-elf-gcc

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/arm-trusted-firmware/sun50iw1p1
	${INSTALL_DATA} ${WRKSRC}/build/sun50iw1p1/debug/bl31.bin \
	    ${DESTDIR}${PREFIX}/share/arm-trusted-firmware/sun50iw1p1

.include "../../mk/bsd.pkg.mk"
