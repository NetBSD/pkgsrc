# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:44 brook Exp $

CATEGORIES=	finance

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.rmetrics.org/
COMMENT=	Financial time series objects
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-timeDate-[0-9]*:../../time/R-timeDate

R_PKGNAME=	timeSeries
R_PKGVER=	3042.102

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
