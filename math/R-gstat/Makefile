# $NetBSD: Makefile,v 1.4 2008/10/14 08:24:23 markd Exp $
#

CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		${R_HOMEPAGE_BASE}/gstat/
COMMENT=		Uni/multivariable geostatistical modelling, prediction and simulation

R_PKGNAME=		gstat
R_PKGVER=		0.9-51

DEPENDS+=		R-sp>=0.9.26:../../math/R-sp

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
