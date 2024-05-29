# $NetBSD: Makefile,v 1.85 2024/05/29 16:34:04 adam Exp $

PKGNAME=	transmission-qt-${VERSION}
PKGREVISION=	3
COMMENT=	Free, lightweight BitTorrent client (QT version)

DEPENDS+=	transmission-common>=${VERSION}:../../net/transmission-common

CMAKE_ARGS+=	-DENABLE_DAEMON=OFF
CMAKE_ARGS+=	-DENABLE_GTK=OFF
CMAKE_ARGS+=	-DENABLE_QT=ON
CMAKE_ARGS+=	-DENABLE_MAC=OFF
CMAKE_ARGS+=	-DENABLE_WEB=OFF
CMAKE_ARGS+=	-DENABLE_UTILS=OFF
CMAKE_ARGS+=	-DENABLE_CLI=OFF
CMAKE_ARGS+=	-DINSTALL_DOC=OFF
CMAKE_ARGS+=	-DENABLE_TESTS=OFF

USE_CXX_FEATURES+=	filesystem

CONFLICTS+=		Transmission-gui-[0-9]*

INSTALLATION_DIRS=	share/applications

# https://github.com/transmission/transmission/issues/4864
post-install:
	${INSTALL_DATA} ${FILESDIR}/transmission-qt.desktop		\
	${DESTDIR}${PREFIX}/share/applications/transmission-qt.desktop
	${RM} -R ${DESTDIR}${PREFIX}/share/transmission/public_html

.include "options.mk"
.include "../../net/transmission/Makefile.common"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
