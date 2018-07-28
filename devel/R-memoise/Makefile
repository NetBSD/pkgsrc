# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:43 brook Exp $

CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/hadley/memoise
COMMENT=	Memoisation of Functions
LICENSE=	mit

R_PKGNAME=	memoise
R_PKGVER=	1.1.0

DEPENDS+=	R-digest>=0.6.3:../../security/R-digest

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
