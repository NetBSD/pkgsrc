# $NetBSD: Makefile,v 1.5 2019/07/31 18:41:30 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/RcppEigen/
COMMENT=	Rcpp integration for the Eigen templated linear algebra library
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3	# OR file LICENSE

R_PKGNAME=	RcppEigen
R_PKGVER=	0.3.3.5.0

USE_LANGUAGES=	c c++11 fortran

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
