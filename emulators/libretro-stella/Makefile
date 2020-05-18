# $NetBSD: Makefile,v 1.4 2020/05/18 12:27:37 nia Exp $

.include "../../emulators/stella/Makefile.common"

PKGNAME=	libretro-${DISTNAME:S/-src//1}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/stella/
COMMENT=	Libretro core based on the Stella Atari 2600 (VCS) emulator

BUILD_DIRS=	src/libretro

USE_TOOLS+=	gmake

MAKE_FLAGS+=	GIT_VERSION="-${PKGVERSION_NOREV}-pkgsrc"
MAKE_FLAGS+=	LTO=

# Should not be combined with -fPIC
BUILDLINK_TRANSFORM+=	rm:-static-libgcc
BUILDLINK_TRANSFORM+=	rm:-static-libstdc++

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--no-undefined
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=link.T

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/src/libretro/stella_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/stella_libretro.so

.include "../../mk/bsd.pkg.mk"
