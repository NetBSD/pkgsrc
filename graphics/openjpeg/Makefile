# $NetBSD: Makefile,v 1.28 2024/02/26 18:15:43 adam Exp $

DISTNAME=	openjpeg-2.5.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=uclouvain/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.openjpeg.org/
COMMENT=	JPEG 2000 library
LICENSE=	2-clause-bsd

USE_CC_FEATURES=	c99
USE_LANGUAGES=		c c++

.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
