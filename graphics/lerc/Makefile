# $NetBSD: Makefile,v 1.4 2026/07/27 14:42:21 wiz Exp $

DISTNAME=	lerc-4.2.0
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
