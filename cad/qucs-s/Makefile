# $NetBSD: Makefile,v 1.1 2026/05/09 15:57:36 wiz Exp $

DISTNAME=	qucs-s-25.2.0
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=ra3xdh/}
GITHUB_PROJECT=	qucs_s
GITHUB_RELEASE=	25.2.0
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	ea1abz@gmail.com
HOMEPAGE=	https://github.com/ra3xdh/qucs_s/
COMMENT=	Circuit simulation program based on Qucs circuit simulator
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	dos2unix-[0-9]*:../../converters/dos2unix
TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

USE_LANGUAGES=	c c++
# Upstream CMakeLists.txt select C++17 or C++20 depending on Qt version.
# In pkgsrc-current, Qt >= 6.7 is used, which requires C++20
FORCE_CXX_STD=	gnu++20

USE_TOOLS+=	bison

CMAKE_CONFIGURE_ARGS+=	-DBISON_DIR=${TOOLS_DIR}/bin

.include "../../mk/bsd.fast.prefs.mk"

.if ${PKGMANDIR} != "share/man"
SUBST_CLASSES+=		man
SUBST_FILES.man+=	contrib/CMakeLists.txt
SUBST_FILES.man+=	qucs-transcalc/CMakeLists.txt
SUBST_FILES.man+=	qucs/CMakeLists.txt
SUBST_FILES.man+=	qucsator_rf/doc/CMakeLists.txt
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},"
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fix man page installation path.
.endif

.include "../../devel/cmake/build.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qt6-qtcharts/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
