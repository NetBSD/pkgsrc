# $NetBSD: Makefile,v 1.125 2024/05/16 06:15:09 wiz Exp $

DISTNAME=	cantor-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	math

HOMEPAGE=	https://kde.org/applications/education/cantor/
COMMENT=	KDE frontend to mathematical software
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_R=TRUE
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_LuaJIT=TRUE
CMAKE_ARGS+=	-DBUILD_TESTING=OFF

#  only try to build python3 support
PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_SH+=	src/backends/sage/cantor-execsage

SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/src/*/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

.include "../../devel/kpty/buildlink3.mk"
.include "../../devel/ktexteditor/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../math/analitza/buildlink3.mk"
.include "../../math/qalculate/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../print/poppler-qt5/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
# Requires bundled copy with custom mkd_latextext()
#.include "../../textproc/discount/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
