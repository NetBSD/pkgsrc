# $NetBSD: Makefile,v 1.5 2019/07/31 19:49:55 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/lme4/
COMMENT=	Linear mixed-effects models using Eigen and S4
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	lme4
R_PKGVER=	1.1-21

DEPENDS+=	R-minqa>=1.1.15:../../math/R-minqa
DEPENDS+=	R-nloptr>=1.0.4:../../math/R-nloptr

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../math/R-RcppEigen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
