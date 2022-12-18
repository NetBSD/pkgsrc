# $NetBSD: Makefile,v 1.3 2022/12/18 11:43:26 mef Exp $

R_PKGNAME=	energy
R_PKGVER=	1.7-10

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	E-statistics: multivariate inference via the energy of data
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-gsl-[0-9]*:../../math/R-gsl

# Package suggested but not available: 'CompQuadForm'
#TEST_DEPENDS+=	R-CompQuadForm-[0-9]*:../../

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
