# $NetBSD: Makefile,v 1.7 2021/09/16 23:47:51 mef Exp $

R_PKGNAME=	lme4
R_PKGVER=	1.1-27.1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linear mixed-effects models using Eigen and S4
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-minqa>=1.1.15:../../math/R-minqa
DEPENDS+=	R-nloptr>=1.0.4:../../math/R-nloptr

# Packages suggested but not available:
#  'PKPDmodels', 'MEMSS', 'mlmRev', 'optimx', 'gamm4', 'HSAUR3',
#  'dfoptim', 'rr2', 'semEff'
TEST_DEPENDS+=	R-markdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-numDeriv-[0-9]*:../../math/R-numDeriv
TEST_DEPENDS+=	R-statmod-[0-9]*:../../math/R-statmod
TEST_DEPENDS+=	R-car-[0-9]*:../../math/R-car
TEST_DEPENDS+=	R-pbkrtest-[0-9]*:../../math/R-pbkrtest

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../math/R-RcppEigen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
