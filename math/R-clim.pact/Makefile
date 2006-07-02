# $NetBSD: Makefile,v 1.3 2006/07/02 13:22:52 markd Exp $
#

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mchittur@cs.nmsu.edu
HOMEPAGE=	${R_HOMEPAGE_BASE}/clim.pact.html
COMMENT=	Climate analysis and downscaling package for monthly and daily data

R_PKGNAME=	clim.pact
R_PKGVER=	2.2-1

DEPENDS+=	R-akima>=0.5.1:../../math/R-akima
DEPENDS+=	R-ncdf>=1.5:../../math/R-ncdf

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
