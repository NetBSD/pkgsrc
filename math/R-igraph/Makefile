# $NetBSD: Makefile,v 1.2 2018/09/04 00:23:12 minskim Exp $

DISTNAME=	igraph_1.2.1
CATEGORIES=	graphics

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://igraph.org/
COMMENT=	Network Analysis and Visualization
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-magrittr-[0-9]*:../../devel/R-magrittr
DEPENDS+=	R-pkgconfig>=2.0.0:../../devel/R-pkgconfig

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
