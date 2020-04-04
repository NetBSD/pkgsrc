# $NetBSD: Makefile,v 1.3 2020/04/04 15:12:17 thorpej Exp $

VERSION=	20180207
GITHUB_PROJECT=	arm-trusted-firmware
GITHUB_TAG=	406a637162bee1f1b0c26525c3aae204aac241fa

PKGNAME=	${GITHUB_PROJECT}-sun50i-h6-${VERSION}
DISTNAME=	${PKGNAME}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Icenowy/}
EXTRACT_SUFX=	.zip

MAINTAINER=	port-arm@NetBSD.org
HOMEPAGE=	https://github.com/Icenowy/arm-trusted-firmware/
COMMENT=	ARM Trusted Firmware for Allwinner H6 SoCs
LICENSE=	modified-bsd

USE_TOOLS+=	gmake

MAKE_FLAGS+=	CROSS_COMPILE=${PREFIX}/cross-aarch64-none-elf/bin/aarch64-none-elf-
MAKE_FLAGS+=	PLAT=sun50i_h6
MAKE_FLAGS+=	DEBUG=1
MAKE_FLAGS+=	BUILD_STRING=${GITHUB_TAG}
BUILD_TARGET=	bl31

BUILD_DEPENDS+=	cross-aarch64-none-elf-gcc-[0-9]*:../../cross/aarch64-none-elf-gcc

.include "../../mk/bsd.prefs.mk"
# XXX kludge. pkgsrc passes down run path flags in LDFLAGS but the
# cross ld(1) doesn't understand -R. If we pass down -L instead it
# will be safely ignored.
COMPILER_RPATH_FLAG=-L
	
do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/arm-trusted-firmware/sun50i-h6
	${INSTALL_DATA} ${WRKSRC}/build/sun50i_h6/debug/bl31.bin \
	    ${DESTDIR}${PREFIX}/share/arm-trusted-firmware/sun50i-h6

.include "../../mk/bsd.pkg.mk"
