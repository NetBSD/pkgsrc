# $NetBSD: Makefile,v 1.10 2023/08/11 06:23:48 mef Exp $

R_PKGNAME=	quantreg
R_PKGVER=	5.96

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Quantile regression
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-MatrixModels>=0:../../math/R-MatrixModels
DEPENDS+=	R-SparseM>=1.77:../../math/R-SparseM

# Packages suggested but not available:
#  'logspline', 'nor1mix', 'R.rsp', 'conquer'

TEST_DEPENDS+=	R-Formula-[0-9]*:../../math/R-Formula
TEST_DEPENDS+=	R-interp-[0-9]*:../../graphics/R-interp
TEST_DEPENDS+=	R-rgl-[0-9]*:../../graphics/R-rgl
TEST_DEPENDS+=	R-zoo-[0-9]*:../../math/R-zoo

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
