# $NetBSD: Makefile,v 1.4 2019/08/08 19:53:41 brook Exp $

R_PKGNAME=	fAsianOptions
R_PKGVER=	3042.82
CATEGORIES=	finance

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Functions for pricing and valuating Asian options
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-fBasics>=3042.89:../../finance/R-fBasics
DEPENDS+=	R-fOptions>=3042.86:../../finance/R-fOptions
DEPENDS+=	R-timeSeries>=3042.102:../../finance/R-timeSeries
DEPENDS+=	R-timeDate>=3042.101:../../time/R-timeDate

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
