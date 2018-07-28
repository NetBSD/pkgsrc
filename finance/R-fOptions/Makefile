# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:44 brook Exp $

CATEGORIES=	finance

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.rmetrics.org/
COMMENT=	Markets and basic statistics
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-fBasics-[0-9]*:../../finance/R-fBasics
DEPENDS+=	R-timeDate-[0-9]*:../../time/R-timeDate
DEPENDS+=	R-timeSeries-[0-9]*:../../finance/R-timeSeries

R_PKGNAME=	fOptions
R_PKGVER=	3042.86

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
