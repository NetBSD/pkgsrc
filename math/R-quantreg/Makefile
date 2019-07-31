# $NetBSD: Makefile,v 1.6 2019/07/31 20:22:08 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/quantreg/
COMMENT=	Quantile regression
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	quantreg
R_PKGVER=	5.42.1

DEPENDS+=	R-MatrixModels>=0:../../math/R-MatrixModels
DEPENDS+=	R-SparseM>=1.77:../../math/R-SparseM

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
