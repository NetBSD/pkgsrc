# $NetBSD: Makefile,v 1.5 2009/12/11 19:35:02 adam Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mchittur@cs.nmsu.edu
HOMEPAGE=	${R_HOMEPAGE_BASE}/mapproj/
COMMENT=	Converts latitude/longitude into projected coordinates

R_PKGNAME=	mapproj
R_PKGVER=	1.1-8.2

DEPENDS+=	R-maps>=2.0.40:../../math/R-maps

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
