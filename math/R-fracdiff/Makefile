# $NetBSD: Makefile,v 1.6 2024/11/02 22:12:36 mef Exp $

R_PKGNAME=	fracdiff
R_PKGVER=	1.5-3

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Fractionally differenced ARIMA aka ARFIMA(p,d,q) models
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

# Package suggested but not available: 'longmemo'
TEST_DEPENDS+=	R-forecast-[0-9]*:../../math/R-forecast

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
