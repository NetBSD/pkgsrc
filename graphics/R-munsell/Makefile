# $NetBSD: Makefile,v 1.5 2021/06/06 15:05:36 mef Exp $

R_PKGNAME=	munsell
R_PKGVER=	0.5.0
CATEGORIES=	graphics

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Utilities for using Munsell colours
LICENSE=	mit

DEPENDS+=	R-colorspace>=1.4.1:../../graphics/R-colorspace

TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
