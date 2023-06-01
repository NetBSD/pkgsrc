# $NetBSD: Makefile,v 1.15 2023/06/01 12:52:39 mef Exp $

R_PKGNAME=	xts
R_PKGVER=	0.13.1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	eXtensible Time Series
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-zoo>=1.7.12:../../math/R-zoo

# Packages suggested but not available:
#  'tseries', 'tis'
TEST_DEPENDS+=	R-chron-[0-9]*:../../math/R-chron
TEST_DEPENDS+=	R-RUnit-[0-9]*:../../devel/R-RUnit
TEST_DEPENDS+=	R-timeDate-[0-9]*:../../time/R-timeDate
TEST_DEPENDS+=	R-timeSeries-[0-9]*:../../finance/R-timeSeries


USE_LANGUAGES+=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
