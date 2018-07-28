# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:44 brook Exp $

CATEGORIES=	finance

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.rmetrics.org/
COMMENT=	Markets and basic statistics
LICENSE=	gnu-gpl-v2

R_PKGNAME=	fBasics
R_PKGVER=	3042.89

DEPENDS+=	R-gss-[0-9]*:../../math/R-gss
DEPENDS+=	R-stabledist-[0-9]*:../../math/R-stabledist
DEPENDS+=	R-timeDate-[0-9]*:../../time/R-timeDate
DEPENDS+=	R-timeSeries-[0-9]*:../../finance/R-timeSeries

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
