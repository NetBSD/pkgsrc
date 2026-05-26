# $NetBSD: Makefile,v 1.11 2026/05/26 13:10:41 mef Exp $

R_PKGNAME=	RcppArmadillo
R_PKGVER=	15.2.6-1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Rcpp integration for the Armadillo templated linear algebra library
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

# Packages suggested but not available: 'reticulate'
TEST_DEPENDS+=	R-tinytest-[0-9]*:../../devel/R-tinytest
TEST_DEPENDS+=	R-pkgKitten-[0-9]*:../../devel/R-pkgKitten
TEST_DEPENDS+=	R-slam-[0-9]*:../../math/R-slam

USE_LANGUAGES=		c++ fortran
USE_CXX_FEATURES+=	c++11
# for patch portablility (ifne)
USE_TOOLS+=		gmake
# configure claims 7.5 is too old
GCC_REQD+=		8

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
