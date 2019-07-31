# $NetBSD: Makefile,v 1.3 2019/07/31 19:56:41 brook Exp $

CATEGORIES=	math R

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
