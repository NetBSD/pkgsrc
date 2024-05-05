# $NetBSD: Makefile,v 1.20 2024/05/05 09:31:36 nia Exp $

.include "Makefile.common"

CONFLICTS+=	xonotic-dedicated-[0-9]*

COMMENT=	Fast arena-style FPS

BUILD_TARGET=	both

ICON_SIZES=	16 24 32 64 128 256 512

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
.for s in ${ICON_SIZES}
INSTALLATION_DIRS+=	share/icons/hicolor/${s}x${s}/apps
.endfor
INSTALLATION_DIRS+=	share/xonotic/data
INSTALLATION_DIRS+=	share/xonotic

CHECK_WRKREF_SKIP+=	share/*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/darkplaces/darkplaces-sdl \
	    ${DESTDIR}${PREFIX}/bin/xonotic-sdl
	${INSTALL_PROGRAM} ${WRKSRC}/source/darkplaces/darkplaces-dedicated \
	    ${DESTDIR}${PREFIX}/bin/xonotic-dedicated
	${INSTALL_DATA} ${WRKSRC}/key_0.d0pk \
	    ${DESTDIR}${PREFIX}/share/xonotic
	${INSTALL_DATA} ${WRKSRC}/data/*.pk3 \
	    ${DESTDIR}${PREFIX}/share/xonotic/data
	${INSTALL_DATA} ${WRKSRC}/misc/logos/xonotic.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
.for s in ${ICON_SIZES}
	${INSTALL_DATA}	${WRKSRC}/misc/logos/icons_png/xonotic_${s}.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/xonotic.png
.endfor

.if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
