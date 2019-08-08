# $NetBSD: Makefile,v 1.4 2019/08/08 19:53:41 brook Exp $

R_PKGNAME=	timeSeries
R_PKGVER=	3042.102
CATEGORIES=	finance

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Financial time series objects
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-timeDate>=2150.95:../../time/R-timeDate

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
