# $NetBSD: Makefile,v 1.9 2020/11/05 09:08:24 ryoon Exp $

DISTNAME=	Kvantum-0.17.0
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=tsujan/}
GITHUB_TAG=	V${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/tsujan/Kvantum/
COMMENT=	SVG-based theme engine for Qt and KDE
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}/Kvantum
USE_CMAKE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/kwindowsystem/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
