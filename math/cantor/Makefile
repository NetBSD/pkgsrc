# $NetBSD: Makefile,v 1.63 2020/04/03 10:30:32 wiz Exp $

DISTNAME=	cantor-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	math

HOMEPAGE=	https://kde.org/applications/education/cantor/
COMMENT=	KDE frontend to mathematical software
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

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
SUBST_SED.py3+=		-e 's:python3.6m python3.7m:python3.6m python3.6 python3.7m python3.7:'

REPLACE_SH+=	src/backends/sage/cantor-execsage

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	src/CMakeLists.txt
SUBST_FILES.xdg+=	src/backends/*/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/cantor.knsrc \
		${PKG_SYSCONFDIR}/xdg/cantor.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/cantor_kalgebra.knsrc \
		${PKG_SYSCONFDIR}/xdg/cantor_kalgebra.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/cantor_maxima.knsrc \
		${PKG_SYSCONFDIR}/xdg/cantor_maxima.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/cantor_octave.knsrc \
		${PKG_SYSCONFDIR}/xdg/cantor_octave.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/cantor_python3.knsrc \
		${PKG_SYSCONFDIR}/xdg/cantor_python3.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/cantor_qalculate.knsrc \
		${PKG_SYSCONFDIR}/xdg/cantor_qalculate.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/cantor_sage.knsrc \
		${PKG_SYSCONFDIR}/xdg/cantor_sage.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/cantor_scilab.knsrc \
		${PKG_SYSCONFDIR}/xdg/cantor_scilab.knsrc

SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/src/backends/*/CMakeFiles/cantor_*backend_autogen.dir/AutogenInfo.json
SUBST_FILES.fix-moc+=	_KDE_build/src/panelplugins/variablemgr/CMakeFiles/cantor_variablemanagerplugin_autogen.dir/AutogenInfo.json
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
.include "../../textproc/discount/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
