# $NetBSD: Makefile,v 1.1 2023/06/15 11:45:30 mef Exp $

R_PKGNAME=	interp
R_PKGVER=	1.1-4
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Interpolation Methods
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-deldir>=1.0.6:../../geography/R-deldir

USE_LANGUAGES=	c c++ fortran

.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../math/R-RcppEigen/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
