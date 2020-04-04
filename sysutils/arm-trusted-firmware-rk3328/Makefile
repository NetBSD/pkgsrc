# $NetBSD: Makefile,v 1.1 2020/04/04 06:21:54 mrg Exp $

VERSION=	2.2
GITHUB_PROJECT=	arm-trusted-firmware
GITHUB_TAG=	v2.2
#GITHUB_TAG=	ab3d22473df279c61ed4d4873d26b072dcf887e8

DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PLATFORM=	rk3328
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
MAKE_FLAGS+=	M0_CROSS_COMPILE=${PREFIX}/cross-arm-none-eabi/bin/arm-none-eabi-
MAKE_FLAGS+=	PLAT=${PLATFORM}
MAKE_FLAGS+=	CFLAGS='-gdwarf-2'
#MAKE_FLAGS+=	DEBUG=1
#MAKE_FLAGS+=	LOG_LEVEL=50
#MAKE_FLAGS+=	V=1
MAKE_FLAGS+=	BUILD_STRING=${GITHUB_TAG}
BUILD_TARGET=	bl31

# This package builds for Cortex-M0 *and* Cortex-A53/A72.
BUILD_DEPENDS+=	cross-aarch64-none-elf-gcc-[0-9]*:../../cross/aarch64-none-elf-gcc
BUILD_DEPENDS+=	cross-arm-none-eabi-gcc-[0-9]*:../../cross/arm-none-eabi-gcc

.if empty(MAKE_FLAGS:MDEBUG=1)
BL31_DIR=release
.else
BL31_DIR=debug
.endif

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/arm-trusted-firmware/${PLATFORM}
	${INSTALL_DATA} ${WRKSRC}/build/${PLATFORM}/${BL31_DIR}/bl31/bl31.elf \
	    ${DESTDIR}${PREFIX}/share/arm-trusted-firmware/${PLATFORM}/

# XXX kludge. pkgsrc passes down run path flags in LDFLAGS assuming
# gcc is used for linking, but here we call the linker directly.
COMPILER_RPATH_FLAG=	-R

.include "../../mk/bsd.pkg.mk"
