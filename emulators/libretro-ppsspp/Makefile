# $NetBSD: Makefile,v 1.17 2025/04/17 21:50:38 wiz Exp $

PKGREVISION= 1
.include "../../emulators/ppsspp/Makefile.common"

PKGNAME=	libretro-${DISTNAME}

HOMEPAGE=	https://docs.libretro.com/library/ppsspp/
COMMENT=	Libretro core based on the PPSSPP PlayStation Portable emulator

CONFLICTS+=	ppsspp-[0-9]*
CONFLICTS+=	ppsspp-qt-[0-9]*

OPSYSVARS+=	SOEXT
SOEXT.Darwin=	dylib
SOEXT.*=	so
PLIST_SUBST+=	SOEXT=${SOEXT}

CMAKE_CONFIGURE_ARGS+=	-DLIBRETRO=ON

INSTALLATION_DIRS+=	lib/libretro

post-install:
	# clean up rubbish
	${RM} -rf ${DESTDIR}${PREFIX}/share/applications
	${RM} -rf ${DESTDIR}${PREFIX}/share/icons
	${INSTALL_LIB} ${WRKSRC}/${CMAKE_BUILD_DIR}/lib/ppsspp_libretro.so \
		${DESTDIR}${PREFIX}/lib/libretro/ppsspp_libretro.so

.include "../../mk/bsd.pkg.mk"
