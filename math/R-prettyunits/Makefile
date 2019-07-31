# $NetBSD: Makefile,v 1.2 2019/07/31 20:17:48 brook Exp $

CATEGORIES=	math R

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/gaborcsardi/prettyunits
COMMENT=	Pretty, human readable formatting of quantities
LICENSE=	mit

R_PKGNAME=	prettyunits
R_PKGVER=	1.0.2

DEPENDS+=	R-assertthat>=0.2.1:../../devel/R-assertthat
DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
