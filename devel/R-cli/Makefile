# $NetBSD: Makefile,v 1.5 2019/07/31 15:17:54 brook Exp $

CATEGORIES=	devel R

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/r-lib/cli
COMMENT=	Helpers for developing command line interfaces
LICENSE=	mit

R_PKGNAME=	cli
R_PKGVER=	1.1.0

DEPENDS+=	R-assertthat>=0.2.1:../../devel/R-assertthat
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
