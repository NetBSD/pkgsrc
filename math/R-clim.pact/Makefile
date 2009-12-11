# $NetBSD: Makefile,v 1.5 2009/12/11 19:26:24 adam Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mchittur@cs.nmsu.edu
HOMEPAGE=	${R_HOMEPAGE_BASE}/clim.pact/
COMMENT=	Climate analysis and downscaling package for monthly and daily data

R_PKGNAME=	clim.pact
R_PKGVER=	2.2-39

DEPENDS+=	R-akima>=0.5.1:../../math/R-akima
DEPENDS+=	R-ncdf>=1.5:../../math/R-ncdf

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
