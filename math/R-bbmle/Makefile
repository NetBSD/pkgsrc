# $NetBSD: Makefile,v 1.4 2019/08/08 19:53:47 brook Exp $

R_PKGNAME=	bbmle
R_PKGVER=	1.0.20
CATEGORIES=	math

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Tools for general maximum likelihood estimation
LICENSE=	gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-numDeriv>=2016.8.1:../../math/R-numDeriv

USE_LANGUAGES+=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
