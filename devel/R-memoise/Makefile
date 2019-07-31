# $NetBSD: Makefile,v 1.3 2019/07/31 15:29:46 brook Exp $

CATEGORIES=	devel R

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/hadley/memoise
COMMENT=	Memoisation of functions
LICENSE=	mit

R_PKGNAME=	memoise
R_PKGVER=	1.1.0

DEPENDS+=	R-digest>=0.6.3:../../security/R-digest

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
