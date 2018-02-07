# $NetBSD: Makefile,v 1.1 2018/02/07 20:48:49 minskim Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/gtable/
COMMENT=	Arrage 'grobs' in tables
LICENSE=	gnu-gpl-v2

R_PKGNAME=	gtable
R_PKGVER=	0.2.0

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.R+=	R>=2.14
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
