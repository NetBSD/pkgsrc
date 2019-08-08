# $NetBSD: Makefile,v 1.6 2019/08/08 19:53:46 brook Exp $

R_PKGNAME=	RcppEigen
R_PKGVER=	0.3.3.5.0
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Rcpp integration for the Eigen templated linear algebra library
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3	# OR file LICENSE

USE_LANGUAGES=	c c++11 fortran

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
