# $NetBSD: Makefile,v 1.5 2020/05/26 09:45:16 nia Exp $

.include "../../emulators/stella/Makefile.common"

PKGNAME=	libretro-${DISTNAME:S/-src//1}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/stella/
COMMENT=	Libretro core based on the Stella Atari 2600 (VCS) emulator

BUILD_DIRS=	src/libretro

USE_TOOLS+=	gmake

OPSYSVARS+=	SOEXT
SOEXT.Darwin=	dylib
SOEXT.*=	so
PLIST_SUBST+=	SOEXT=${SOEXT}

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
