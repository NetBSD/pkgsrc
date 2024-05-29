# $NetBSD: Makefile,v 1.26 2024/05/29 16:32:32 adam Exp $

PKGREVISION=	3

COMMENT=	Cube-based FPS with realistic environments

BUILD_TARGET=	client server

.include "Makefile.common"

.include "../../mk/bsd.fast.prefs.mk"

LDFLAGS+=	${BUILDLINK_LDADD.iconv}

.if ${OPSYS} == "Darwin"
LDFLAGS+=	-framework OpenAL
LDFLAGS+=	-framework OpenGL
# server part needs SDL2 thread/semaphore functions,
# but does not link against it
LDFLAGS+=	-lSDL2
.else
.  include "../../audio/openal-soft/buildlink3.mk"
.  include "../../graphics/MesaLib/buildlink3.mk"
.  include "../../x11/libX11/buildlink3.mk"
LDFLAGS+=	-lGL -lX11 -lopenal
.endif

CONFLICTS+=	assaultcube-server-[0-9]*

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/256x256/apps

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/images/icon.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/256x256/apps/assaultcube.png
	${INSTALL_DATA} ${FILESDIR}/assaultcube.desktop \
	    ${DESTDIR}${PREFIX}/share/applications

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
