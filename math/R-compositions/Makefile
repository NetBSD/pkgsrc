# $NetBSD: Makefile,v 1.2 2021/08/28 05:30:45 mef Exp $

R_PKGNAME=	compositions
R_PKGVER=	2.0-2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Compositional data analysis
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-bayesm>=3.1.3:../../finance/R-bayesm
DEPENDS+=	R-energy>=1.7.6:../../math/R-energy
DEPENDS+=	R-robustbase>=0.93.5:../../math/R-robustbase
DEPENDS+=	R-tensorA>=0.36.1:../../math/R-tensorA

# Packages suggested but not available: 'rgl', 'combinat'
#TEST_DEPENDS+=	R-rgl-[0-9]*:../..
#TEST_DEPENDS+=	R-combinat-[0-9]*:../..

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
