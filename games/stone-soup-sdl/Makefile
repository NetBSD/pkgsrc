# $NetBSD: Makefile,v 1.26 2022/08/11 05:08:35 gutteridge Exp $

PKGREVISION= 3
.include "../../games/stone-soup/Makefile.common"

PKGNAME=	${DISTNAME:S/_/-/:S/-soup/-soup-sdl/:S/-nodeps//1}

MAINTAINER=	nia@NetBSD.org
COMMENT=	Dungeon Crawl Stone Soup - roguelike adventure (tileset version)

CONFLICTS+=	stone-soup-[0-9]*

TOOL_DEPENDS+=	pngcrush-[0-9]*:../../graphics/pngcrush
DEPENDS+=	dejavu-ttf-[0-9]*:../../fonts/dejavu-ttf

MAKE_FLAGS+=	TILES=YesPlease
MAKE_FLAGS+=	SOUND=YesPlease
MAKE_FLAGS+=	COPY_FONTS=YesPlease

MAKE_FLAGS+=	PROPORTIONAL_FONT=${PREFIX}/share/fonts/X11/TTF/DejaVuSans.ttf
MAKE_FLAGS+=	MONOSPACED_FONT=${PREFIX}/share/fonts/X11/TTF/DejaVuSansMono.ttf

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
