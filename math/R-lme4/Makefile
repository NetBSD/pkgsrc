# $NetBSD: Makefile,v 1.4 2018/12/21 12:53:49 wen Exp $
#

CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/lme4/
COMMENT=	Linear mixed-effects models using Eigen and S4
LICENSE=	gnu-gpl-v2

R_PKGNAME=	lme4
R_PKGVER=	1.1-19

USE_LANGUAGES=	c c++

DEPENDS+=	R-minqa>=1.1.15:../../math/R-minqa
DEPENDS+=	R-nloptr>=1.0.4:../../math/R-nloptr

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../math/R-RcppEigen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
