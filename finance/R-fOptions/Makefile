# $NetBSD: Makefile,v 1.3 2019/07/31 15:51:14 brook Exp $

CATEGORIES=	finance R

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.rmetrics.org/
COMMENT=	Markets and basic statistics
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	fOptions
R_PKGVER=	3042.86

DEPENDS+=	R-fBasics>=3042.89:../../finance/R-fBasics
DEPENDS+=	R-timeSeries>=3042.102:../../finance/R-timeSeries
DEPENDS+=	R-timeDate>=3042.101:../../time/R-timeDate

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
