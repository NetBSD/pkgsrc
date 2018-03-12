# $NetBSD: Makefile,v 1.1 2018/03/12 15:47:48 minskim Exp $

CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/hadley/scales
COMMENT=	Scale functions for visualization
LICENSE=	mit

R_PKGNAME=	scales
R_PKGVER=	0.5.0

DEPENDS+=	R-R6-[0-9]*:../../devel/R-R6
DEPENDS+=	R-RColorBrewer-[0-9]*:../../math/R-RColorBrewer
DEPENDS+=	R-dichromat-[0-9]*:../../graphics/R-dichromat
DEPENDS+=	R-labeling-[0-9]*:../../graphics/R-labeling
DEPENDS+=	R-munsell>=0.2:../../graphics/R-munsell
DEPENDS+=	R-plyr-[0-9]*:../../math/R-plyr
DEPENDS+=	R-viridisLite-[0-9]*:../../graphics/R-viridisLite

USE_LANGUAGES=	c++

.include "../../devel/R-Rcpp/buildlink3.mk"
BUILDLINK_API_DEPENDS.R+=	R>=2.13
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
