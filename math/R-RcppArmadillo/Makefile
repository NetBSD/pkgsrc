# $NetBSD: Makefile,v 1.2 2018/03/25 00:32:45 minskim Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://dirk.eddelbuettel.com/code/rcpp.armadillo.html
COMMENT=	Testing linear regression models
LICENSE=	gnu-gpl-v2

R_PKGNAME=	RcppArmadillo
R_PKGVER=	0.8.400.0.0

USE_LANGUAGES=	c++11 fortran

.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
