# $NetBSD: Makefile,v 1.19 2025/04/17 21:51:05 wiz Exp $

DISTNAME=	kimageannotator-0.7.1
PKGREVISION=	5
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

.include "../../graphics/kcolorpicker/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
