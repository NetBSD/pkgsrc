# $NetBSD: Makefile,v 1.23 2026/03/30 16:06:23 adam Exp $

.include "../../emulators/ppsspp/Makefile.common"

PKGNAME=	libretro-${DISTNAME}

HOMEPAGE=	https://docs.libretro.com/library/ppsspp/
COMMENT=	Libretro core based on the PPSSPP PlayStation Portable emulator

CONFLICTS+=	ppsspp-[0-9]*
CONFLICTS+=	ppsspp-qt-[0-9]*

CMAKE_CONFIGURE_ARGS+=	-DLIBRETRO=ON

INSTALLATION_DIRS+=	lib/libretro

OPSYSVARS+=	SOEXT
SOEXT.Darwin=	dylib
SOEXT.*=	so

post-install:
	# clean up rubbish
	${RM} -rf ${DESTDIR}${PREFIX}/share/applications
	${RM} -rf ${DESTDIR}${PREFIX}/share/assets
	${RM} -rf ${DESTDIR}${PREFIX}/share/icons
	${INSTALL_LIB} ${WRKSRC}/${CMAKE_BUILD_DIR}/lib/ppsspp_libretro.${SOEXT} \
		${DESTDIR}${PREFIX}/lib/libretro/ppsspp_libretro.${SOEXT}

.include "../../mk/bsd.pkg.mk"
