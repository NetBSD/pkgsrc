# $NetBSD: Makefile,v 1.112 2026/01/07 08:48:08 wiz Exp $

DISTNAME=	kdenlive-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	multimedia

HOMEPAGE=	https://www.kdenlive.org/
COMMENT=	KDE video editor
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools
DEPENDS+=	dvdauthor>=0.6.18:../../multimedia/dvdauthor
DEPENDS+=	ffplay7-[0-9]*:../../multimedia/ffplay7
DEPENDS+=	mlt-qt6-[0-9]*:../../multimedia/mlt-qt6

USE_TOOLS+=	msgmerge pkg-config

CXXFLAGS.NetBSD+=	-DHAVE_LOCALE_H
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_LibV4L2=TRUE
CMAKE_CONFIGURE_ARGS+=	-DFETCH_OTIO=OFF
CMAKE_CONFIGURE_ARGS+=	-DFFMPEG_SUFFIX=7

.include "../../devel/kf6-kdeclarative/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-knotifyconfig/buildlink3.mk"
.include "../../devel/kf6-purpose/buildlink3.mk"
.include "../../devel/rttr/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/ffmpeg7/buildlink3.mk"
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
