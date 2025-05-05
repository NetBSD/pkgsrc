# $NetBSD: Makefile,v 1.2 2025/05/05 09:45:19 tnn Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	flameshot-12.1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=flameshot-org/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flameshot.org/
COMMENT=	Powerful yet simple to use screenshot software
LICENSE=	gnu-gpl-v3

ICON_THEMES=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++

PKGCONFIG_OVERRIDE+=	external/Qt-Color-Widgets/QtColorWidgets.pc.in

SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-configure
SUBST_FILES.mandir=	src/CMakeLists.txt
SUBST_VARS.mandir=	PKGMANDIR

BROKEN_ON_PLATFORM+=		Darwin-*-*

.include "../../devel/cmake/build.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools=	build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
