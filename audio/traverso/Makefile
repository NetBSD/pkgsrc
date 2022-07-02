# $NetBSD: Makefile,v 1.15 2022/07/02 16:53:08 ryoon Exp $

DISTNAME=	traverso-0.49.6
PKGREVISION=	13
CATEGORIES=	audio
MASTER_SITES=	https://traverso-daw.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://traverso-daw.org/
COMMENT=	Multitrack audio recording and audio editing suite
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

# note: C++11 'constexpr' only available with -std=c++11 or -std=gnu++11
USE_LANGUAGES=	c c++11

CMAKE_ARGS+=	-DWANT_MP3_ENCODE=ON

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CMAKE_ARGS+=	-DWANT_COREAUDIO=ON
.endif

INSTALLATION_DIRS+=	share/applications

post-install:
	${INSTALL_DATA} ${WRKSRC}/resources/traverso.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
.for s in 16x16 24x24 48x48 64x64 128x128 scalable
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKSRC}/resources/freedesktop/icons/${s}/apps/*.* \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons/hicolor/${s}/mimetypes
	${INSTALL_DATA} ${WRKSRC}/resources/freedesktop/icons/${s}/mimetypes/*.* \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/${s}/mimetypes
.endfor

.include "options.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/lilv/buildlink3.mk"
.include "../../audio/wavpack/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
