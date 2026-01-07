# $NetBSD: Makefile,v 1.44 2026/01/07 08:45:47 wiz Exp $

.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	lxqt-archiver-1.3.0
PKGREVISION=	2
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-archiver/
COMMENT=	Simple and lightweight Qt file archiver
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config perl bsdtar:run gzip:run 7za:run gtar:run bzip2:run unzip:run zip:run xz:run

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

TOOL_DEPENDS+=	lxqt-build-tools>=2.3.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

BUILDLINK_API_DEPENDS.qt6-qtbase+=      qt6-qtbase>=6.6.0
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/libfm-qt/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
