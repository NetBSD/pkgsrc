# $NetBSD: Makefile,v 1.8 2024/01/24 03:51:30 mef Exp $

R_PKGNAME=	RcppArmadillo
R_PKGVER=	0.12.6.6.0

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Rcpp integration for the Armadillo templated linear algebra library
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

# Packages suggested but not available: 'reticulate', 'slam'
TEST_DEPENDS+=	R-tinytest-[0-9]*:../../devel/R-tinytest
TEST_DEPENDS+=	R-pkgKitten-[0-9]*:../../devel/R-pkgKitten

USE_LANGUAGES=		c++ fortran
USE_CXX_FEATURES+=	c++11

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
