# $NetBSD: Makefile,v 1.4 2018/07/28 14:40:46 brook Exp $

CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/RcppEigen/
COMMENT=	Rcpp integration for the Eigen templated linear algebra library
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	RcppEigen
R_PKGVER=	0.3.3.4.0

USE_LANGUAGES=	c c++11 fortran

.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
