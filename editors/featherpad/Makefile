# $NetBSD: Makefile,v 1.2 2020/02/13 04:37:41 gutteridge Exp $

DISTNAME=		FeatherPad-V0.12.0
PKGNAME=		featherpad-0.12.0
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_GITHUB:=tsujan/}
GITHUB_TAG=		V${PKGVERSION_NOREV}

MAINTAINER=	voidpin@protonmail.com
HOMEPAGE=	https://github.com/tsujan/FeatherPad/
COMMENT=	Lightweight Qt5 plain-text editor
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/FeatherPad-0.12.0
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
