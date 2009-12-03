# $NetBSD: Makefile,v 1.6 2009/12/03 13:06:53 asau Exp $
#

PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		${R_HOMEPAGE_BASE}/wle/
COMMENT=		Provides approach to robustness via Weighted Likelihood Estimation

R_PKGNAME=		wle
R_PKGVER=               0.9-3
USE_LANGUAGES+=		c fortran

DEPENDS+=		R-circular>=0.3.8:../../math/R-circular

.include "../../math/R/Makefile.extension"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
