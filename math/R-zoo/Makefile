# $NetBSD: Makefile,v 1.16 2021/06/06 15:08:56 mef Exp $

R_PKGNAME=	zoo
R_PKGVER=	1.8-9
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	S3 infrastructure for regular and irregular time series
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

#Packages suggested but not available:
#  'AER', 'coda', 'chron', 'fts', 'ggplot2', 'mondate', 'scales',
#  'stinepack', 'strucchange', 'timeDate', 'timeSeries', 'tis',
#  'tseries', 'xts'
TEST_DEPENDS+=	R-xts-[0-9]*:../../math/R-xts
TEST_DEPENDS+=	R-scales-[0-9]*:../../graphics/R-scales
TEST_DEPENDS+=	R-timeDate-[0-9]*:../../time/R-timeDate
TEST_DEPENDS+=	R-timeSeries-[0-9]*:../../finance/R-timeSeries

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
