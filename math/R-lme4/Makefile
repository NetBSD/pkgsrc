# $NetBSD: Makefile,v 1.6 2019/08/08 19:53:50 brook Exp $

R_PKGNAME=	lme4
R_PKGVER=	1.1-21
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linear mixed-effects models using Eigen and S4
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-minqa>=1.1.15:../../math/R-minqa
DEPENDS+=	R-nloptr>=1.0.4:../../math/R-nloptr

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../math/R-RcppEigen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
