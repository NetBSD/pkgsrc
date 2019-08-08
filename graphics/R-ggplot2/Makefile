# $NetBSD: Makefile,v 1.4 2019/08/08 19:53:42 brook Exp $

R_PKGNAME=	ggplot2
R_PKGVER=	3.2.0
CATEGORIES=	graphics

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Create elegant data visualisations using the grammar of graphics
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-lazyeval>=0.2.2:../../devel/R-lazyeval
DEPENDS+=	R-rlang>=0.3.0:../../devel/R-rlang
DEPENDS+=	R-withr>=2.0.0:../../devel/R-withr
DEPENDS+=	R-scales>=0.5.0:../../graphics/R-scales
DEPENDS+=	R-viridisLite>=0.3.0:../../graphics/R-viridisLite
DEPENDS+=	R-gtable>=0.1.1:../../math/R-gtable
DEPENDS+=	R-plyr>=1.7.1:../../math/R-plyr
DEPENDS+=	R-reshape2>=1.4.3:../../math/R-reshape2
DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble
DEPENDS+=	R-digest>=0.6.20:../../security/R-digest

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
