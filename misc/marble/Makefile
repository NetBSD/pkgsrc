# $NetBSD: Makefile,v 1.78 2022/06/28 11:34:48 wiz Exp $

DISTNAME=	marble-${KAPPSVER}
PKGREVISION=	12
CATEGORIES=	misc

HOMEPAGE=	https://marble.kde.org/
COMMENT=	KDE desktop globe
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v3 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge perl

CMAKE_ARGS+=	-DQT_PLUGINS_DIR=${QTDIR}/plugins
CMAKE_ARGS+=	-DMARBLE_PRI_INSTALL_USE_QT_SYS_PATHS=TRUE

SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/src/apps/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

.include "../../devel/kparts/buildlink3.mk"
.include "../../devel/krunner/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../geography/gpsd/buildlink3.mk"
.include "../../geography/shapelib/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../multimedia/phonon-qt5/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtserialport/buildlink3.mk"
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt5WebEngineWidgets:BOOL=TRUE
#.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
