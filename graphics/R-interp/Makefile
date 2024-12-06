# $NetBSD: Makefile,v 1.2 2024/12/06 23:57:34 mef Exp $

R_PKGNAME=	interp
R_PKGVER=	1.1-6
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Interpolation Methods
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-deldir>=1.0.6:../../geography/R-deldir

# Packages suggested but not available: 'Ryacas', 'scatterplot3d'

TEST_DEPENDS+=	R-Deriv-[0-9]*:../../math/R-Deriv
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-gridExtra-[0-9]*:../../graphics/R-gridExtra
TEST_DEPENDS+=	R-sp-[0-9]*:../../math/R-sp
TEST_DEPENDS+=	R-stringi-[0-9]*:../../textproc/R-stringi
TEST_DEPENDS+=	R-stringr-[0-9]*:../../textproc/R-stringr

USE_LANGUAGES=	c c++ fortran

.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../math/R-RcppEigen/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
