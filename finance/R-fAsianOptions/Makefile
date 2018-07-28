# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:43 brook Exp $

CATEGORIES=	finance

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.rmetrics.org/
COMMENT=	Functions for pricing and valuating Asian options
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-fBasics-[0-9]*:../../finance/R-fBasics
DEPENDS+=	R-fOptions-[0-9]*:../../finance/R-fOptions
DEPENDS+=	R-timeDate-[0-9]*:../../time/R-timeDate
DEPENDS+=	R-timeSeries-[0-9]*:../../finance/R-timeSeries

R_PKGNAME=	fAsianOptions
R_PKGVER=	3042.82

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
