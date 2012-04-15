# $NetBSD: Makefile,v 1.7 2012/04/15 16:03:42 brook Exp $
#

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/wle/
COMMENT=	Weighted Likelihood Estimation
LICENSE=	gnu-gpl-v2

R_PKGNAME=	wle
R_PKGVER=	0.9-4

USE_LANGUAGES+=	c fortran

DEPENDS+=	R-circular>=0.4.3:../../math/R-circular

.include "../../math/R/Makefile.extension"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
