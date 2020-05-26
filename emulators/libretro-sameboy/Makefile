# $NetBSD: Makefile,v 1.6 2020/05/26 09:45:16 nia Exp $

.include "../../emulators/sameboy/Makefile.common"

PKGNAME=	libretro-${DISTNAME}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/sameboy/
COMMENT=	Libretro core based on the SameBoy Game Boy/Game Boy Color emulator

BUILD_DIRS=	libretro

MAKE_FLAGS+=	GIT_VERSION="${PKGVERSION}-pkgsrc"

OPSYSVARS+=	SOEXT
SOEXT.Darwin=	dylib
SOEXT.*=	so
PLIST_SUBST+=	SOEXT=${SOEXT}

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/bin/sameboy_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro

.include "../../mk/bsd.pkg.mk"
