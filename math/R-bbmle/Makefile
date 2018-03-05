# $NetBSD: Makefile,v 1.1 2018/03/05 16:56:27 minskim Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/bbmle/
COMMENT=	Tools for general maximum likelihood estimation
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-numDeriv-[0-9]*:../../math/R-numDeriv

R_PKGNAME=	bbmle
R_PKGVER=	1.0.20

USE_LANGUAGES+=	# none

BUILDLINK_API_DEPENDS.R+=	R>=3.0.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
