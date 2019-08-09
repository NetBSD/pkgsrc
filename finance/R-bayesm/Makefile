# $NetBSD: Makefile,v 1.1 2019/08/09 15:39:04 brook Exp $

R_PKGNAME=	bayesm
R_PKGVER=	3.1-3
CATEGORIES=	finance

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Bayesian inference for marketing/micro-econometrics
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_LANGUAGES=	c c++ fortran

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../math/R-RcppArmadillo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
