# $NetBSD: Makefile,v 1.10 2025/02/14 13:45:47 mef Exp $

R_PKGNAME=	RcppArmadillo
R_PKGVER=	14.2.3-1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Rcpp integration for the Armadillo templated linear algebra library
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

# Packages suggested but not available: 'reticulate'
TEST_DEPENDS+=	R-tinytest-[0-9]*:../../devel/R-tinytest
TEST_DEPENDS+=	R-pkgKitten-[0-9]*:../../devel/R-pkgKitten
TEST_DEPENDS+=	R-slam-[0-9]*:../../math/R-slam

USE_LANGUAGES=		c++ fortran
USE_CXX_FEATURES+=	c++11

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
