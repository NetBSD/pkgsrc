# $NetBSD: Makefile,v 1.5 2019/08/08 19:53:46 brook Exp $

R_PKGNAME=	RcppArmadillo
R_PKGVER=	0.9.600.4.0
CATEGORIES=	math

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Rcpp integration for the Armadillo templated linear algebra library
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_LANGUAGES=	c++11 fortran

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
