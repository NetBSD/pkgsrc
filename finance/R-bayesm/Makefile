# $NetBSD: Makefile,v 1.2 2020/02/15 23:53:07 mef Exp $

R_PKGNAME=	bayesm
R_PKGVER=	3.1-4
CATEGORIES=	finance

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Bayesian inference for marketing/micro-econometrics
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_LANGUAGES=	c c++ fortran

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../math/R-RcppArmadillo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
