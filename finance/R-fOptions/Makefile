# $NetBSD: Makefile,v 1.1 2018/03/02 18:38:19 minskim Exp $

CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

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
