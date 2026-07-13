# $NetBSD: Makefile,v 1.2.4.1 2026/07/13 23:48:25 maya Exp $

DISTNAME=	lerc-4.1.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=Esri/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/Esri/lerc/
COMMENT=	Limited Error Raster Compression library
LICENSE=	apache-2.0

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	Lerc.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
