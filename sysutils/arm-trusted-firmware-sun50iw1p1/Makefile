# $NetBSD: Makefile,v 1.4 2019/02/20 17:04:13 martin Exp $

VERSION=	20180210
GITHUB_PROJECT=	arm-trusted-firmware
GITHUB_TAG=	c9f55c023164a6c8c49f70f7ac6c68c626839d6f
PKGREVISION=	1

PKGNAME=	${GITHUB_PROJECT}-sun50iw1p1-${VERSION}
DISTNAME=	${PKGNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=apritzel/}
EXTRACT_SUFX=	.zip

MAINTAINER=	port-arm@NetBSD.org
HOMEPAGE=	https://github.com/apritzel/arm-trusted-firmware/
COMMENT=	ARM Trusted Firmware for Allwinner A64/H5 SoCs
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
