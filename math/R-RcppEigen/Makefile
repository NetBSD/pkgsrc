# $NetBSD: Makefile,v 1.1 2016/07/27 03:53:50 wen Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/RcppEigen/
COMMENT=	Rcpp integration for the Eigen templated linear algebra library
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	RcppEigen
R_PKGVER=	0.3.2.8.1

USE_LANGUAGES=	c c++ fortran

.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
