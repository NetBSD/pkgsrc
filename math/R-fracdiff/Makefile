# $NetBSD: Makefile,v 1.1 2018/02/07 01:11:18 minskim Exp $

CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/fracdiff/
COMMENT=	Fractionally differenced ARIMA aka ARFIMA(p,d,q) models
LICENSE=	gnu-gpl-v2

R_PKGNAME=	fracdiff
R_PKGVER=	1.4-2

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
