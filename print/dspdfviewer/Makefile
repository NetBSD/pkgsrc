# $NetBSD: Makefile,v 1.71 2025/01/22 08:29:04 wiz Exp $

DISTNAME=	dspdfviewer-1.15.1
PKGREVISION=	67
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=dannyedel/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://dspdfviewer.danny-edel.de/
COMMENT=	Dual-Screen PDF Viewer for latex-beamer
LICENSE=	gnu-gpl-v2

DEPENDS+=	qt5-qttools>=5.5.1:../../x11/qt5-qttools

USE_LANGUAGES=		c c++
# required by boost-libs
USE_CXX_FEATURES+=	c++14
FORCE_CXX_STD=		c++14
USE_TOOLS+=		pkg-config
CMAKE_CONFIGURE_ARGS+=	-DBuildTests=OFF
BUILD_MAKE_FLAGS+=	VERBOSE=1

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/cmake/build.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler-qt5+=	poppler-qt5>=0.50.0
.include "../../print/poppler-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
