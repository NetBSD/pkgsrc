# $NetBSD: Makefile,v 1.1 2018/02/26 17:17:00 minskim Exp $

CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

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
