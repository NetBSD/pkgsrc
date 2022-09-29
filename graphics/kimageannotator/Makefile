# $NetBSD: Makefile,v 1.1 2022/09/29 00:09:28 markd Exp $

DISTNAME=	kimageannotator-0.6.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ksnip/}
GITHUB_PROJECT=	kImageAnnotator
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ksnip/kImageAnnotator/
COMMENT=	Tool for annotating images
LICENSE=	gnu-lgpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../graphics/kcolorpicker/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
