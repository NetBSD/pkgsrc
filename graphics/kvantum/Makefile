# $NetBSD: Makefile,v 1.37 2024/03/20 13:10:10 pin Exp $

DISTNAME=	Kvantum-1.1.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=tsujan/}
GITHUB_TAG=	V${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/tsujan/Kvantum/
COMMENT=	SVG-based theme engine for Qt and KDE
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}/Kvantum
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}
CMAKE_ARGS+=	-DENABLE_QT5=ON

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/kwindowsystem/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
