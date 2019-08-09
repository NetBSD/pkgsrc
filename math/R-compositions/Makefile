# $NetBSD: Makefile,v 1.1 2019/08/09 15:50:05 brook Exp $

R_PKGNAME=	compositions
R_PKGVER=	1.40-2
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Compositional data analysis
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-bayesm>=3.1.3:../../finance/R-bayesm
DEPENDS+=	R-energy>=1.7.6:../../math/R-energy
DEPENDS+=	R-robustbase>=0.93.5:../../math/R-robustbase
DEPENDS+=	R-tensorA>=0.36.1:../../math/R-tensorA

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
