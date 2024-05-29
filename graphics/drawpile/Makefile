# $NetBSD: Makefile,v 1.25 2024/05/29 16:32:51 adam Exp $

DISTNAME=	Drawpile-2.1.17
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	23
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=drawpile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://drawpile.net/
COMMENT=	Collaborative drawing program
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DINITSYS=""

.include "../../archivers/karchive/buildlink3.mk"
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
