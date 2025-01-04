# $NetBSD: Makefile,v 1.6 2025/01/04 15:06:50 mef Exp $

R_PKGNAME=	timeSeries
R_PKGVER=	4041.111
CATEGORIES=	finance

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Financial time series objects
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-timeDate>=4041.110:../../time/R-timeDate

# Packages suggested but not available:
#   'xts', 'zoo', 'PerformanceAnalytics', 'fTrading'

TEST_DEPENDS+=	R-RUnit-[0-9]*:../../devel/R-RUnit
TEST_DEPENDS+=	R-robustbase-[0-9]*:../../math/R-robustbase

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
