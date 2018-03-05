# $NetBSD: Makefile,v 1.1 2018/03/05 16:52:13 minskim Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

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
