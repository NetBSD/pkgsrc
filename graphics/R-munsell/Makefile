# $NetBSD: Makefile,v 1.1 2018/03/08 19:36:13 minskim Exp $

CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/munsell/
COMMENT=	Utilities for using Munsell colors
LICENSE=	mit

R_PKGNAME=	munsell
R_PKGVER=	0.4.3

DEPENDS+=	R-colorspace-[0-9]*:../../graphics/R-colorspace

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
