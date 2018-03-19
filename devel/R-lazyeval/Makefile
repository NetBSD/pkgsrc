# $NetBSD: Makefile,v 1.1 2018/03/19 02:31:20 minskim Exp $

CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/lazyeval/
COMMENT=	Lazy (non-standard) evaluation
LICENSE=	gnu-gpl-v3

R_PKGNAME=	lazyeval
R_PKGVER=	0.2.1

USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.R+=	R>=3.1.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
