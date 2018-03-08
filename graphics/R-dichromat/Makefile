# $NetBSD: Makefile,v 1.1 2018/03/08 19:33:37 minskim Exp $

CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/dichromat/
COMMENT=	Color schemes for dichromats
LICENSE=	gnu-gpl-v2

R_PKGNAME=	dichromat
R_PKGVER=	2.0-0

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.R+=	R>=2.10
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
