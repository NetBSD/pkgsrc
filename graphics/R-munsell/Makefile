# $NetBSD: Makefile,v 1.3 2019/07/31 16:10:15 brook Exp $

CATEGORIES=	graphics R

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/munsell/
COMMENT=	Utilities for using Munsell colours
LICENSE=	mit

R_PKGNAME=	munsell
R_PKGVER=	0.5.0

DEPENDS+=	R-colorspace>=1.4.1:../../graphics/R-colorspace

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
