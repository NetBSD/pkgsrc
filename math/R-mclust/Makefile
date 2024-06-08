# $NetBSD: Makefile,v 1.1 2024/06/08 14:12:49 mef Exp $

R_PKGNAME=	mclust
R_PKGVER=	6.1.1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Gaussian Mixture Modelling for Model-Based Clustering, Classification, and Density Estimation
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_LANGUAGES=	c fortran

# Packages suggested but not available: 'mix', 'geometry'
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
