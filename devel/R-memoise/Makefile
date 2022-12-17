# $NetBSD: Makefile,v 1.6 2022/12/17 15:26:16 mef Exp $

R_PKGNAME=	memoise
R_PKGVER=	2.0.1
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Memoisation of functions
LICENSE=	mit

DEPENDS+=	R-digest>=0.6.3:../../security/R-digest
DEPENDS+=	R-cachem-[0-9]*:../../devel/R-cachem

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
