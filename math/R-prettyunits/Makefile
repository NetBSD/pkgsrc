# $NetBSD: Makefile,v 1.3 2019/08/08 19:53:52 brook Exp $

R_PKGNAME=	prettyunits
R_PKGVER=	1.0.2
CATEGORIES=	math

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Pretty, human readable formatting of quantities
LICENSE=	mit

DEPENDS+=	R-assertthat>=0.2.1:../../devel/R-assertthat
DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
