# $NetBSD: Makefile,v 1.24 2026/02/06 10:05:01 wiz Exp $

DISTNAME=	kimageannotator-0.7.1
PKGREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ksnip/}
GITHUB_PROJECT=	kImageAnnotator
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ksnip/kImageAnnotator/
COMMENT=	Tool for annotating images
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_WITH_QT6=ON

.include "../../graphics/kcolorpicker/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
