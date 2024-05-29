# $NetBSD: Makefile,v 1.98 2024/05/29 16:33:44 adam Exp $

DISTNAME=	kdenlive-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	multimedia

HOMEPAGE=	https://www.kdenlive.org/
COMMENT=	KDE video editor
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	dvdauthor>=0.6.18:../../multimedia/dvdauthor
DEPENDS+=	ffplay5-[0-9]*:../../multimedia/ffplay5

USE_TOOLS+=	msgmerge

CXXFLAGS.NetBSD+=	-DHAVE_LOCALE_H
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_LibV4L2=TRUE
CMAKE_ARGS+=		-DFFMPEG_SUFFIX=5

.include "../../devel/kdeclarative/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../devel/purpose/buildlink3.mk"
.include "../../devel/rttr/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/ffmpeg5/buildlink3.mk"
.include "../../multimedia/frei0r/buildlink3.mk"
.include "../../multimedia/mlt/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/kfilemetadata5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtnetworkauth/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt5WebEngineWidgets:BOOL=TRUE
#.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
