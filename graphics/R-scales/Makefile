# $NetBSD: Makefile,v 1.8 2024/06/05 11:56:12 mef Exp $

R_PKGNAME=	scales
R_PKGVER=	1.3.0
CATEGORIES=	graphics

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Scale functions for visualization
LICENSE=	mit

DEPENDS+=	R-R6>=2.4.1:../../devel/R-R6
DEPENDS+=	R-lifecycle>=0.2.0:../../devel/R-lifecycle
DEPENDS+=	R-dichromat-[0-9]*:../../graphics/R-dichromat
DEPENDS+=	R-farver>=2.0.3:../../graphics/R-farver
DEPENDS+=	R-labeling>=0.3:../../graphics/R-labeling
DEPENDS+=	R-munsell>=0.5:../../graphics/R-munsell
DEPENDS+=	R-viridisLite>=0.3.0:../../graphics/R-viridisLite
DEPENDS+=	R-RColorBrewer>=1.1.2:../../math/R-RColorBrewer
DEPENDS+=	R-plyr-[0-9]*:../../math/R-plyr

USE_LANGUAGES=	c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
