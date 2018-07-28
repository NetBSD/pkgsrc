# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:49 brook Exp $
#

CATEGORIES=		math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/minqa/
COMMENT=	Derivative-free optimization algorithms by quadratic approximation
LICENSE=	gnu-gpl-v2

R_PKGNAME=	minqa
R_PKGVER=	1.2.4

USE_LANGUAGES=	c++ fortran

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
