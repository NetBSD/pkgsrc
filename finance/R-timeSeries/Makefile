# $NetBSD: Makefile,v 1.3 2019/07/31 15:54:13 brook Exp $

CATEGORIES=	finance R

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.rmetrics.org/
COMMENT=	Financial time series objects
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	timeSeries
R_PKGVER=	3042.102

DEPENDS+=	R-timeDate>=2150.95:../../time/R-timeDate

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
