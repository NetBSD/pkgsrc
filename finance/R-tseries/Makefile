# $NetBSD: Makefile,v 1.1 2018/03/07 19:23:21 minskim Exp $

CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/tseries/
COMMENT=	Time series analysis and computational finance
LICENSE=	gnu-gpl-v2

R_PKGNAME=	tseries
R_PKGVER=	0.10-43

DEPENDS+=	R-quadprog-[0-9]*:../../math/R-quadprog
DEPENDS+=	R-quantmod>=0.4.9:../../finance/R-quantmod
DEPENDS+=	R-zoo-[0-9]*:../../math/R-zoo

USE_LANGUAGES=	c fortran

BUILDLINK_API_DEPENDS.R+=	R>=2.10.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
