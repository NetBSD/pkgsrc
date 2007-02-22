# $NetBSD: Makefile,v 1.4 2007/02/22 19:30:05 wiz Exp $
#

CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		${R_HOMEPAGE_BASE}/wle.html
COMMENT=		Provides approach to robustness via Weighted Likelihood Estimation

R_PKGNAME=		wle
R_PKGVER=		0.9-2
USE_LANGUAGES=		c fortran

.include "../../math/R/Makefile.extension"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
