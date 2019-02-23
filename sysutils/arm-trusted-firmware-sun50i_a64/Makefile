# $NetBSD: Makefile,v 1.2 2019/02/23 06:24:37 martin Exp $

VERSION=	2.0
GITHUB_PROJECT=	arm-trusted-firmware
GITHUB_TAG=	v${VERSION}

DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PLATFORM=	sun50i_a64
PKGNAME=	${GITHUB_PROJECT}-${PLATFORM}-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=ARM-software/}
EXTRACT_SUFX=	.zip

MAINTAINER=	port-arm@NetBSD.org
HOMEPAGE=	https://github.com/ARM-software/arm-trusted-firmware/
COMMENT=	ARM Trusted Firmware
LICENSE=	modified-bsd

USE_TOOLS+=	gmake

MAKE_FLAGS+=	CROSS_COMPILE=${PREFIX}/cross-aarch64-none-elf/bin/aarch64-none-elf-
MAKE_FLAGS+=	PLAT=${PLATFORM}
MAKE_FLAGS+=	DEBUG=1
MAKE_FLAGS+=	BUILD_STRING=${GITHUB_TAG}
BUILD_TARGET=	bl31

BUILD_DEPENDS+=	cross-aarch64-none-elf-gcc-[0-9]*:../../cross/aarch64-none-elf-gcc

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/arm-trusted-firmware/${PLATFORM}
	${INSTALL_DATA} ${WRKSRC}/build/${PLATFORM}/debug/bl31.bin \
	    ${DESTDIR}${PREFIX}/share/arm-trusted-firmware/${PLATFORM}/


# XXX kludge. pkgsrc passes down run path flags in LDFLAGS but the
# cross ld(1) doesn't understand -R. If we pass down -L instead it
# will be safely ignored.
COMPILER_RPATH_FLAG=-L


.include "../../mk/bsd.pkg.mk"
