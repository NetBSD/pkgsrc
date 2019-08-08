# $NetBSD: Makefile,v 1.7 2019/08/08 19:53:53 brook Exp $

R_PKGNAME=	quantreg
R_PKGVER=	5.42.1
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Quantile regression
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-MatrixModels>=0:../../math/R-MatrixModels
DEPENDS+=	R-SparseM>=1.77:../../math/R-SparseM

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
