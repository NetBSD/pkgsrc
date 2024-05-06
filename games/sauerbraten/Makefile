# $NetBSD: Makefile,v 1.14 2024/05/06 08:07:30 nia Exp $

BUILD_TARGET=	client master server

.include "Makefile.common"

PKGREVISION=	8

COMMENT=	First-person shooter game based on Cube 2

CONFLICTS+=	sauerbraten-server-[0-9]*

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

post-install:
	${INSTALL_DATA} ${FILESDIR}/sauerbraten.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/data/cube.png \
	    ${DESTDIR}${PREFIX}/share/pixmaps/sauerbraten.png

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
