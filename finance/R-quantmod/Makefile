# $NetBSD: Makefile,v 1.7 2025/01/04 22:38:15 mef Exp $

R_PKGNAME=	quantmod
R_PKGVER=	0.4.26
CATEGORIES=	finance

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Quantitative financial modelling framework
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-curl>=4.0:../../www/R-curl
DEPENDS+=	R-jsonlite-[0-9]*:../../textproc/R-jsonlite
DEPENDS+=	R-TTR>=0.2:../../finance/R-TTR
DEPENDS+=	R-xts>=0.9.0:../../math/R-xts
DEPENDS+=	R-zoo>=1.8.6:../../math/R-zoo

# Packages suggested but not available: 'RMySQL', 'downloader'
TEST_DEPENDS+=	R-DBI-[0-9]*:../../math/R-DBI
TEST_DEPENDS+=	R-RSQLite-[0-9]*:../../databases/R-RSQLite
TEST_DEPENDS+=	R-timeSeries-[0-9]*:../../finance/R-timeSeries
TEST_DEPENDS+=	R-xml2-[0-9]*:../../textproc/R-xml2


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../math/R-xts/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
