# $NetBSD: Makefile,v 1.4 2019/07/31 18:39:23 brook Exp $

CATEGORIES=	math R

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://dirk.eddelbuettel.com/code/rcpp.armadillo.html
COMMENT=	Rcpp integration for the Armadillo templated linear algebra library
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	RcppArmadillo
R_PKGVER=	0.9.600.4.0

USE_LANGUAGES=	c++11 fortran

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
