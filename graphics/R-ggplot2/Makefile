# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:44 brook Exp $

CATEGORIES=	graphics

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ggplot2.tidyverse.org/
COMMENT=	Elegant data visualization using the Grammar of Graphcis
LICENSE=	gnu-gpl-v2

R_PKGNAME=	ggplot2
R_PKGVER=	2.2.1

DEPENDS+=	R-digest-[0-9]*:../../security/R-digest
DEPENDS+=	R-gtable>=0.1.1:../../math/R-gtable
DEPENDS+=	R-plyr>=1.7.1:../../math/R-plyr
DEPENDS+=	R-reshape2-[0-9]*:../../math/R-reshape2
DEPENDS+=	R-scales>=0.4.1:../../graphics/R-scales
DEPENDS+=	R-tibble-[0-9]*:../../math/R-tibble
DEPENDS+=	R-lazyeval-[0-9]*:../../devel/R-lazyeval

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.R+=	R>=3.1
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
