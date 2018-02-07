# $NetBSD: Makefile,v 1.1 2018/02/07 20:51:53 minskim Exp $

CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/repr/
COMMENT=	Serializable representations
LICENSE=	gnu-gpl-v3

R_PKGNAME=	repr
R_PKGVER=	0.12.0

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.R+=	R>=3.0.1
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
