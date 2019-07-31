# $NetBSD: Makefile,v 1.3 2019/07/31 18:54:43 brook Exp $

CATEGORIES=	math R

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/bbmle/
COMMENT=	Tools for general maximum likelihood estimation
LICENSE=	gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	bbmle
R_PKGVER=	1.0.20

DEPENDS+=	R-numDeriv>=2016.8.1:../../math/R-numDeriv

USE_LANGUAGES+=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
