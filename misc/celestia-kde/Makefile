# $NetBSD: Makefile,v 1.12 2004/04/24 18:53:40 snj Exp $
#

.include "../../misc/celestia/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-kde-/}
PKGREVISION=	7

COMMENT=	KDE frontend for free real-time 3D space simulator

DEPENDS=	celestia-${CELESTIA_VERS}*:../../misc/celestia

CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--with-kde

BUILD_DIRS=	${WRKSRC}/src
KDEWRKSRC=	${WRKSRC}/src/celestia/kde/data

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/celestia/celestia ${PREFIX}/bin/kcelestia
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/kde/HTML/en/celestia
	${INSTALL_DATA} ${KDEWRKSRC}/index.docbook ${PREFIX}/share/doc/kde/HTML/en/celestia/index.docbook
	${INSTALL_DATA_DIR} ${PREFIX}/share/kde/applnk/Edutainment/Science
	${INSTALL_DATA} ${KDEWRKSRC}/celestia.desktop ${PREFIX}/share/kde/applnk/Edutainment/Science/celestia.desktop
	${INSTALL_DATA_DIR} ${PREFIX}/share/kde/apps/celestia/favicons
	${INSTALL_DATA} ${KDEWRKSRC}/bookmarks.xml ${PREFIX}/share/kde/apps/celestia/bookmarks.xml
	${INSTALL_DATA} ${KDEWRKSRC}/celestiaui.rc ${PREFIX}/share/kde/apps/celestia/celestiaui.rc
	${INSTALL_DATA} ${KDEWRKSRC}/celestia_200*.png ${PREFIX}/share/kde/apps/celestia/favicons
	${INSTALL_DATA} ${KDEWRKSRC}/celestiarc ${PREFIX}/share/kde/config/celestiarc
	${INSTALL_DATA} ${KDEWRKSRC}/hi16-app-celestia.png ${PREFIX}/share/kde/icons/hicolor/16x16/apps/celestia.png
	${INSTALL_DATA} ${KDEWRKSRC}/hi22-app-celestia.png ${PREFIX}/share/kde/icons/hicolor/22x22/apps/celestia.png
	${INSTALL_DATA} ${KDEWRKSRC}/hi32-app-celestia.png ${PREFIX}/share/kde/icons/hicolor/32x32/apps/celestia.png
	${INSTALL_DATA} ${KDEWRKSRC}/hi48-app-celestia.png ${PREFIX}/share/kde/icons/hicolor/48x48/apps/celestia.png
	${INSTALL_DATA} ${KDEWRKSRC}/x-celestia-script.desktop ${PREFIX}/share/kde/mimelnk/application/x-celestia-script.desktop
	${INSTALL_DATA} ${KDEWRKSRC}/celestia.protocol ${PREFIX}/share/kde/services/celestia.protocol

.include "../../x11/kdelibs3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
