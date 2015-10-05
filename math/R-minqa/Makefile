# $NetBSD: Makefile,v 1.1 2015/10/05 01:12:46 wen Exp $
#

CATEGORIES=		math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

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
