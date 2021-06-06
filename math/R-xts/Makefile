# $NetBSD: Makefile,v 1.13 2021/06/06 15:12:59 mef Exp $

R_PKGNAME=	xts
R_PKGVER=	0.12.1
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	eXtensible Time Series
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-zoo>=1.7.12:../../math/R-zoo

# Packages suggested but not available:
#  'timeSeries', 'timeDate', 'tseries', 'chron', 'fts', 'tis', 'RUnit'


USE_LANGUAGES+=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
