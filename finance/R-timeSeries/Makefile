# $NetBSD: Makefile,v 1.5 2022/04/02 03:10:26 wen Exp $

R_PKGNAME=	timeSeries
R_PKGVER=	3062.100
CATEGORIES=	finance

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Financial time series objects
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-timeDate>=2150.95:../../time/R-timeDate

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
