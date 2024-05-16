# $NetBSD: Makefile,v 1.69 2024/05/16 06:15:25 wiz Exp $

PKGNAME=	transmission-gtk-${VERSION}
PKGREVISION=	3
COMMENT=	Free, lightweight BitTorrent client (GTK version)

DEPENDS+=	transmission-common>=${VERSION}:../../net/transmission-common

CONFLICTS+=		Transmission-gui-[0-9]*

.include "../../net/transmission/Makefile.common"

CMAKE_ARGS+=	-DENABLE_DAEMON=OFF
CMAKE_ARGS+=	-DENABLE_GTK=ON
CMAKE_ARGS+=	-DENABLE_QT=OFF
CMAKE_ARGS+=	-DENABLE_MAC=OFF
CMAKE_ARGS+=	-DENABLE_WEB=OFF
CMAKE_ARGS+=	-DENABLE_UTILS=OFF
CMAKE_ARGS+=	-DENABLE_CLI=OFF
CMAKE_ARGS+=	-DINSTALL_DOC=OFF
CMAKE_ARGS+=	-DENABLE_TESTS=OFF

# https://github.com/transmission/transmission/issues/4864
post-install:
	${RM} -R ${DESTDIR}${PREFIX}/share/transmission/public_html

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
# XXX: this doesn't work - builtin 0.16.1 is accepted
BUILDLINK_API_DEPENDS.gettext+=	gettext-lib>=0.19.7
.include "../../devel/gettext-lib/buildlink3.mk"
# XXX: so force new gettext-tools, giving us new gettext-lib
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
BUILDLINK_API_DEPENDS.gtkmm4+= gtkmm4>=4.11.1
.include "../../x11/gtkmm4/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
