# $NetBSD: Makefile,v 1.2 2019/08/11 13:21:04 wiz Exp $

PKGREVISION= 1
.include "../../games/stone-soup/Makefile.common"

PKGNAME=	${DISTNAME:S/_/-/:S/-soup/-soup-sdl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Dungeon Crawl Stone Soup - roguelike adventure (tileset version)

MAKE_FLAGS+=	TILES=YesPlease
MAKE_FLAGS+=	SOUND=YesPlease

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
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
