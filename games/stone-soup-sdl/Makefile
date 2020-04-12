# $NetBSD: Makefile,v 1.9 2020/04/12 08:28:45 adam Exp $

PKGREVISION= 2
.include "../../games/stone-soup/Makefile.common"

PKGNAME=	${DISTNAME:S/_/-/:S/-soup/-soup-sdl/}

MAINTAINER=	nia@NetBSD.org
COMMENT=	Dungeon Crawl Stone Soup - roguelike adventure (tileset version)

CONFLICTS+=	stone-soup-[0-9]*

MAKE_FLAGS+=	TILES=YesPlease
MAKE_FLAGS+=	SOUND=YesPlease
MAKE_FLAGS+=	COPY_FONTS=YesPlease

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/48x48/apps

post-install:
	${INSTALL_DATA} ${FILESDIR}/crawl.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/source/debian/crawl.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/48x48/apps

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
