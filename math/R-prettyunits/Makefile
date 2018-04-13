# $NetBSD: Makefile,v 1.1 2018/04/13 15:26:31 minskim Exp $

DISTNAME=	prettyunits_1.0.2
CATEGORIES=	math

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/gaborcsardi/prettyunits
COMMENT=	Pretty, Human Readable Formatting of Quantities
LICENSE=	mit

DEPENDS+=	R-assertthat-[0-9]*:../../devel/R-assertthat
DEPENDS+=	R-magrittr-[0-9]*:../../devel/R-magrittr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
