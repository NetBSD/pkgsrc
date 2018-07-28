# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:50 brook Exp $

CATEGORIES=	math

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/numDeriv/
COMMENT=	Accurate numerical derivatives
LICENSE=	gnu-gpl-v2

R_PKGNAME=	numDeriv
R_PKGVER=	2016.8-1

USE_LANGUAGES+=	# none

BUILDLINK_API_DEPENDS.R+=	R>=2.11.1
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
