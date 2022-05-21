# $NetBSD: Makefile,v 1.6 2022/05/21 13:29:45 mef Exp $

R_PKGNAME=	bbmle
R_PKGVER=	1.0.20

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Tools for general maximum likelihood estimation
LICENSE=	gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-numDeriv>=2016.8.1:../../math/R-numDeriv
# Packages required but not available: 'bdsmatrix', 'mvtnorm'
#
# Packages suggested but not available:
#  'emdbook', 'rms', 'ggplot2', 'RUnit', 'MuMIn', 'AICcmodavg', 'Hmisc',
#  'optimx', 'knitr', 'testthat'


USE_LANGUAGES+=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
