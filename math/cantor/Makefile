# $NetBSD: Makefile,v 1.53 2019/11/20 22:30:05 markd Exp $

DISTNAME=	cantor-${KAPPSVER}
CATEGORIES=	math

HOMEPAGE=	https://kde.org/applications/education/cantor/
COMMENT=	KDE frontend to mathematical software
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=${KF5VER}:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_R=TRUE
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_LuaJIT=TRUE

#  only try to build python3 support
PYTHON_VERSIONS_INCOMPATIBLE=	27
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_PythonLibs=TRUE
SUBST_CLASSES+=		py3
SUBST_STAGE.py3=	pre-configure
SUBST_FILES.py3=	cmake/FindPythonLibs3.cmake
SUBST_SED.py3=		-e 's:python3):python-${PYVERSSUFFIX}):'

REPLACE_SH+=	src/backends/sage/cantor-execsage

.include "../../devel/kpty/buildlink3.mk"
.include "../../devel/ktexteditor/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../math/analitza/buildlink3.mk"
.include "../../math/qalculate/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
