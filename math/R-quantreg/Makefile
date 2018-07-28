# $NetBSD: Makefile,v 1.5 2018/07/28 14:40:50 brook Exp $
#

CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/quantreg/
COMMENT=	Quantile Regression
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	quantreg
R_PKGVER=	5.34

USE_LANGUAGES=	c fortran

DEPENDS+=	R-SparseM>=0:../../math/R-SparseM \
		R-MatrixModels>=0:../../math/R-MatrixModels

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
