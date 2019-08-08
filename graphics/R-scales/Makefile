# $NetBSD: Makefile,v 1.4 2019/08/08 19:53:43 brook Exp $

R_PKGNAME=	scales
R_PKGVER=	1.0.0
CATEGORIES=	graphics

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Scale functions for visualization
LICENSE=	mit

DEPENDS+=	R-R6-[0-9]*:../../devel/R-R6
DEPENDS+=	R-dichromat-[0-9]*:../../graphics/R-dichromat
DEPENDS+=	R-labeling>=0.3:../../graphics/R-labeling
DEPENDS+=	R-munsell>=0.5:../../graphics/R-munsell
DEPENDS+=	R-viridisLite>=0.3.0:../../graphics/R-viridisLite
DEPENDS+=	R-RColorBrewer-[0-9]*:../../math/R-RColorBrewer
DEPENDS+=	R-plyr-[0-9]*:../../math/R-plyr

USE_LANGUAGES=	c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
