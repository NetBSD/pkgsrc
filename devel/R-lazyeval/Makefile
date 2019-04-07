# $NetBSD: Makefile,v 1.3 2019/04/07 13:11:27 wen Exp $

CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/lazyeval/
COMMENT=	Lazy (non-standard) evaluation
LICENSE=	gnu-gpl-v3

R_PKGNAME=	lazyeval
R_PKGVER=	0.2.2

USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.R+=	R>=3.1.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
