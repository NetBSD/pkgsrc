# $NetBSD: Makefile,v 1.7 2023/07/08 00:16:39 mef Exp $

R_PKGNAME=	emdbook
R_PKGVER=	1.3.13

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Support functions and data for "Ecological Models and Data"
LICENSE=	gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-bbmle>=1.0.20:../../math/R-bbmle
DEPENDS+=	R-coda>=0.19.3:../../math/R-coda
DEPENDS+=	R-plyr>=1.8.4:../../math/R-plyr

# Packages suggested but not available: 'R2jags', 'ellipse', 'SuppDists'
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
