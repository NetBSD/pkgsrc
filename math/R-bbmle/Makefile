# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:47 brook Exp $

CATEGORIES=	math

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
