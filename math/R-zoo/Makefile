# $NetBSD: Makefile,v 1.17 2022/05/23 11:48:04 mef Exp $

R_PKGNAME=	zoo
R_PKGVER=	1.8-10

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	S3 infrastructure for regular and irregular time series
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

# Packages suggested but not available:
#   'AER', 'fts', 'mondate', 'stinepack', 'strucchange', 'tis'

TEST_DEPENDS+=	R-chron-[0-9]*:../../math/R-chron
TEST_DEPENDS+=	R-coda-[0-9]*:../../math/R-coda
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-scales-[0-9]*:../../graphics/R-scales
TEST_DEPENDS+=	R-timeDate-[0-9]*:../../time/R-timeDate
TEST_DEPENDS+=	R-timeSeries-[0-9]*:../../finance/R-timeSeries
TEST_DEPENDS+=	R-tseries-[0-9]*:../../finance/R-tseries
TEST_DEPENDS+=	R-xts-[0-9]*:../../math/R-xts

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
