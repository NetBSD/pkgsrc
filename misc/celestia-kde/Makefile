# $NetBSD: Makefile,v 1.15 2005/06/17 03:50:21 jlam Exp $

PKGNAME=	${DISTNAME:S/-/-kde-/}

COMMENT=	KDE frontend for free real-time 3D space simulator

DEPENDS=	celestia-${CELESTIA_VERS}*:../../misc/celestia

CONFIGURE_ARGS+=	--with-kde

BUILD_DIRS=	${WRKSRC}/src
KDEWRKSRC=	${WRKSRC}/src/celestia/kde/data

INSTALLATION_DIRS=	bin share/kde/mimelnk/application share/kde/services

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/celestia/celestia \
		${PREFIX}/bin/kcelestia
	${INSTALL_DATA_DIR} ${PREFIX}/share/kde/applnk/Edutainment/Science
	${INSTALL_DATA} ${KDEWRKSRC}/celestia.desktop \
		${PREFIX}/share/kde/applnk/Edutainment/Science/
	${INSTALL_DATA_DIR} ${PREFIX}/share/kde/apps/celestia
	${INSTALL_DATA} ${KDEWRKSRC}/bookmarks.xml \
		${PREFIX}/share/kde/apps/celestia/
	${INSTALL_DATA} ${KDEWRKSRC}/celestia-splash.jpg \
		${PREFIX}/share/kde/apps/celestia/
	${INSTALL_DATA} ${KDEWRKSRC}/celestiaui.rc \
		${PREFIX}/share/kde/apps/celestia/
	${INSTALL_DATA_DIR} ${PREFIX}/share/kde/apps/celestia/favicons
.for nn in 20830192652097 20830192655186 21210223316001 21212191412299 \
		21215164511359 21215164726547 21215170159036 30106235954721
	${INSTALL_DATA} ${KDEWRKSRC}/celestia_200${nn}.png \
		${PREFIX}/share/kde/apps/celestia/favicons/
.endfor
	${INSTALL_DATA} ${KDEWRKSRC}/celestiarc ${PREFIX}/share/kde/config/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/kde/HTML/en/celestia
.for nn in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 \
		25 26 27 28 29 30 221 
	${INSTALL_DATA} ${KDEWRKSRC}/../doc/celestia/fig${nn}.jpg \
		${PREFIX}/share/doc/kde/HTML/en/celestia/
.endfor
	${INSTALL_DATA} ${KDEWRKSRC}/../doc/celestia/index.cache.bz2 \
		${PREFIX}/share/doc/kde/HTML/en/celestia/
	${INSTALL_DATA} ${KDEWRKSRC}/../doc/celestia/index.docbook \
		${PREFIX}/share/doc/kde/HTML/en/celestia/
.for nn in 16 22 32 48
	${INSTALL_DATA_DIR} ${PREFIX}/share/kde/icons/hicolor/${nn}x${nn}/apps
	${INSTALL_DATA} ${KDEWRKSRC}/hi${nn}-app-celestia.png \
		${PREFIX}/share/kde/icons/hicolor/${nn}x${nn}/apps/celestia.png
.endfor
	${INSTALL_DATA} ${KDEWRKSRC}/x-celestia-script.desktop \
		${PREFIX}/share/kde/mimelnk/application/
	${INSTALL_DATA} ${KDEWRKSRC}/celestia.protocol \
		${PREFIX}/share/kde/services/

.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"

.include "../../misc/celestia/Makefile.common"

.include "../../mk/bsd.pkg.mk"
