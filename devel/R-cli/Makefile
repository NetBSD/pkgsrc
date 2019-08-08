# $NetBSD: Makefile,v 1.6 2019/08/08 19:53:38 brook Exp $

R_PKGNAME=	cli
R_PKGVER=	1.1.0
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Helpers for developing command line interfaces
LICENSE=	mit

DEPENDS+=	R-assertthat>=0.2.1:../../devel/R-assertthat
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
