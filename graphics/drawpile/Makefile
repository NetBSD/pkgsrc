# $NetBSD: Makefile,v 1.39 2026/06/20 01:19:28 nia Exp $

DISTNAME=	Drawpile-2.1.17
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	33
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=drawpile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://drawpile.net/
COMMENT=	Collaborative drawing program
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

LDFLAGS.SunOS+=	-lsocket

CMAKE_CONFIGURE_ARGS+=	-DINITSYS=""
CMAKE_CONFIGURE_ARGS+=  -DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../archivers/karchive/buildlink3.mk"
.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../net/miniupnpc/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
