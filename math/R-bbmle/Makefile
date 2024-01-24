# $NetBSD: Makefile,v 1.8 2024/01/24 14:11:56 mef Exp $

R_PKGNAME=	bbmle
R_PKGVER=	1.0.25.1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Tools for general maximum likelihood estimation
LICENSE=	gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-numDeriv>=2016.8.1:../../math/R-numDeriv
DEPENDS+=	R-bdsmatrix-[0-9]*:../../math/R-bdsmatrix
DEPENDS+=	R-mvtnorm-[0-9]*:../../math/R-mvtnorm
#
# Packages suggested but not available:
#   'rms', 'MuMIn', 'AICcmodavg', 'optimx'


TEST_DEPENDS+=	R-emdbook-[0-9]*:../../math/R-emdbook
#EST_DEPENDS+=	R-rms-[0-9]*:
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-RUnit-[0-9]*:../../devel/R-RUnit
#EST_DEPENDS+=	R-MuMIn-[0-9]*:
#EST_DEPENDS+=	R-AICcmodavg-[0-9]*:
TEST_DEPENDS+=	R-Hmisc-[0-9]*:../../misc/R-Hmisc
#EST_DEPENDS+=	R-optimx-[0-9]*:
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES+=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
