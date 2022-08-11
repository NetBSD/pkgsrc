# $NetBSD: Makefile,v 1.12 2022/08/11 05:08:24 gutteridge Exp $

PKGREVISION= 4
.include "../../games/cataclysm-dda/Makefile.common"

PKGNAME=	${DISTNAME:S/-dda/-dda-sdl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Post-apocalyptic turn-based survival game (tileset version)

CONFLICTS+=	cataclysm-dda-[0-9]*

BUILD_TARGET=	cataclysm-tiles localization

MAKE_FLAGS+=	TILES=1
MAKE_FLAGS+=	SOUND=1

ICON_SIZES=	16 32 64 128 256 512 1024

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/appdata
INSTALLATION_DIRS+=	share/icons/hicolor/scalable/apps
.for s in ${ICON_SIZES}
INSTALLATION_DIRS+=	share/icons/hicolor/${s}x${s}/apps
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cataclysm-tiles ${DESTDIR}${PREFIX}/bin
.for target in core font json mods names raw motd credits title sound
	cd ${WRKSRC}/data && ${PAX} -rw -pp ${target} \
	    ${DESTDIR}${PREFIX}/share/cataclysm-dda
.endfor
	cd ${WRKSRC}/gfx && ${PAX} -rw -pp . \
	    ${DESTDIR}${PREFIX}/share/cataclysm-dda/gfx
	${INSTALL_DATA} ${WRKSRC}/data/changelog.txt \
	    ${DESTDIR}${PREFIX}/share/cataclysm-dda
	${INSTALL_DATA} ${WRKSRC}/data/cataicon.ico \
	    ${DESTDIR}${PREFIX}/share/cataclysm-dda
	${INSTALL_DATA} ${WRKSRC}/data/fontdata.json \
	    ${DESTDIR}${PREFIX}/share/cataclysm-dda
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt \
	    ${DESTDIR}${PREFIX}/share/cataclysm-dda
	cd ${WRKSRC} && LOCALE_DIR=${DESTDIR}${PREFIX}/share/locale ${SH} lang/compile_mo.sh
	${INSTALL_DATA} ${WRKSRC}/data/xdg/org.cataclysmdda.CataclysmDDA.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/data/xdg/org.cataclysmdda.CataclysmDDA.appdata.xml \
	    ${DESTDIR}${PREFIX}/share/appdata
	${INSTALL_DATA} ${WRKSRC}/data/xdg/org.cataclysmdda.CataclysmDDA.svg \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps
.for s in ${ICON_SIZES}
	${INSTALL_DATA} ${WRKSRC}/build-data/osx/AppIcon.iconset/icon_${s}x${s}.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/cataclysm-dda.png
.endfor

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
