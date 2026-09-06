# $NetBSD: Makefile,v 1.119 2026/09/06 11:03:03 markd Exp $

DISTNAME=	kdenlive-${KAPPSVER}
CATEGORIES=	multimedia

HOMEPAGE=	https://www.kdenlive.org/
COMMENT=	KDE video editor
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools
DEPENDS+=	dvdauthor>=0.6.18:../../multimedia/dvdauthor
DEPENDS+=	ffplay8-[0-9]*:../../multimedia/ffplay8

USE_TOOLS+=	msgmerge pkg-config

CXXFLAGS.NetBSD+=	-DHAVE_LOCALE_H
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_LibV4L2=TRUE
CMAKE_CONFIGURE_ARGS+=	-DFETCH_OTIO=OFF
CMAKE_CONFIGURE_ARGS+=	-DFFMPEG_SUFFIX=8

.include "../../devel/kf6-kdeclarative/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-knotifyconfig/buildlink3.mk"
.include "../../devel/kf6-purpose/buildlink3.mk"
.include "../../devel/rttr/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kddockwidgets/buildlink3.mk"
.include "../../multimedia/ffmpeg8/buildlink3.mk"
.include "../../multimedia/frei0r/buildlink3.mk"
.include "../../multimedia/mlt/buildlink3.mk"
.include "../../multimedia/opentimelineio/buildlink3.mk"
.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../security/qt6-qtnetworkauth/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/kf6-kfilemetadata/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt6WebEngineWidgets:BOOL=TRUE
#.include "../../x11/qt6-qtwebengine/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
