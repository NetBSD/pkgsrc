# $NetBSD: Makefile,v 1.5 2019/07/18 10:44:57 nia Exp $

.include "../../emulators/sameboy/Makefile.common"

PKGNAME=	libretro-${DISTNAME}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/sameboy/
COMMENT=	Libretro core based on the SameBoy Game Boy/Game Boy Color emulator

BUILD_DIRS=	libretro

MAKE_FLAGS+=	GIT_VERSION="${PKGVERSION}-pkgsrc"

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/bin/sameboy_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro

.include "../../mk/bsd.pkg.mk"
