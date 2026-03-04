# $NetBSD: Makefile,v 1.7 2026/03/04 00:25:46 tnn Exp $

GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
DISTNAME=	flameshot-13.3.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=flameshot-org/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flameshot.org/
COMMENT=	Powerful yet simple to use screenshot software
LICENSE=	gnu-gpl-v3

ICON_THEMES=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
CMAKE_CONFIGURE_ARGS+=	-DUSE_KDSINGLEAPPLICATION=OFF	# not in pkgsrc
CMAKE_CONFIGURE_ARGS+=	-DDISABLE_UPDATE_CHECKER=ON
CONFIGURE_ENV+=		GIT_HASH=88c951e

SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-configure
SUBST_FILES.mandir=	src/CMakeLists.txt
SUBST_VARS.mandir=	PKGMANDIR

BROKEN_ON_PLATFORM+=		Darwin-*-*

.include "../../devel/cmake/build.mk"
BUILDLINK_DEPMETHOD.qt6-qttools=	build
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qt6-qt-color-widgets/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
