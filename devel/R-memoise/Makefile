# $NetBSD: Makefile,v 1.5 2021/05/31 22:43:04 mef Exp $

R_PKGNAME=	memoise
R_PKGVER=	2.0.0
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Memoisation of functions
LICENSE=	mit

DEPENDS+=	R-digest>=0.6.3:../../security/R-digest
DEPENDS+=	R-cachem-[0-9]*:../../devel/R-cachem

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
