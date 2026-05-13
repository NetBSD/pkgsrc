# $NetBSD: Makefile,v 1.48 2026/05/13 06:50:50 adam Exp $

DISTNAME=	qt-creator-opensource-src-19.0.1
PKGNAME=	${DISTNAME:S/qt-/qt/:S/-opensource-src//}
CATEGORIES=	editors
MASTER_SITES=	http://download.qt.io/official_releases/${PKGBASE}/${PKGVERSION_NOREV:R}/${PKGVERSION_NOREV}/
MASTER_SITES+=	http://download.qt.io/archive/${PKGBASE}/${PKGVERSION_NOREV:R}/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.qt.io/
COMMENT=	Cross-platform IDE for Qt and C++
LICENSE=	gnu-lgpl-v3

USE_CXX_FEATURES=	c++20
USE_LANGUAGES=		c c++
USE_TOOLS+=		bash gmake perl pkg-config
# Requires Go compiler.
CMAKE_CONFIGURE_ARGS+=	-DBUILD_EXECUTABLE_CMDBRIDGE=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_WITH_PCH=OFF

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/qtcreator/plugins
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/qtcreator

REPLACE_BASH+=		scripts/deployqtHelper_mac.sh
REPLACE_BASH+=		src/app/winicons/createicons.sh
REPLACE_BASH+=		src/libs/qmljs/parser/gen-parser.sh
REPLACE_BASH+=		src/shared/qbs/tests/auto/blackbox/testdata/badInterpreter/script-ok
REPLACE_BASH+=		tests/manual/distribution/elflint

REPLACE_PYTHON+=	src/libs/qmljs/parser/changeLicense.py
REPLACE_PYTHON+=	src/tools/icons/export.py
REPLACE_PYTHON+=	tests/system/tools/findUnusedObjects.py
REPLACE_PYTHON+=	tests/system/tools/objectsToTable.py
REPLACE_PYTHON+=	scripts/checkInstalledFiles.py
REPLACE_PYTHON+=	scripts/dependencyinfo.py
REPLACE_PYTHON+=	scripts/uichanges.py

REPLACE_PERL+=		doc/fixnavi.pl
REPLACE_PERL+=		share/qtcreator/translations/check-ts.pl
REPLACE_PERL+=		src/shared/qbs/doc/fixnavi.pl
REPLACE_PERL+=		scripts/gcc2tasks.pl
REPLACE_PERL+=		scripts/krazy2tasks.pl
REPLACE_PERL+=		scripts/msvc2tasks.pl
REPLACE_PERL+=		scripts/mytasks.pl
REPLACE_PERL+=		scripts/purify2tasks.pl
REPLACE_PERL+=		scripts/qdoc2tasks.pl
REPLACE_PERL+=		scripts/test2tasks.pl
REPLACE_PERL+=		scripts/updateCopyright.pl

PLIST_VARS+=	nodarwin

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
PLIST.nodarwin=	yes
.endif

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/qt6-qt5compat/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qt6-qtcharts/buildlink3.mk"
.include "../../graphics/qt6-qtquick3d/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/yaml-cpp/buildlink3.mk"
.include "../../www/litehtml/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/qt6-qtserialport/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
