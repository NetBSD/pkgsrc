# $NetBSD: Makefile,v 1.1 2020/08/09 15:14:14 brook Exp $

R_PKGNAME=	ggspatial
R_PKGVER=	1.0.3
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spatial Data Framework for ggplot2
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-rlang>=0.4.5:../../devel/R-rlang
DEPENDS+=	R-raster>=3.0.12:../../geography/R-raster
DEPENDS+=	R-rosm>=0.2.5:../../geography/R-rosm
DEPENDS+=	R-sf>=0.8.1:../../geography/R-sf
DEPENDS+=	R-ggplot2>=2.2.1.9000:../../graphics/R-ggplot2
DEPENDS+=	R-scales>=1.1.0:../../graphics/R-scales
DEPENDS+=	R-abind>=1.4.5:../../math/R-abind
DEPENDS+=	R-plyr>=1.8.6:../../math/R-plyr
DEPENDS+=	R-reshape2>=1.4.3:../../math/R-reshape2
DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble
DEPENDS+=	R-tidyr>=1.0.2:../../math/R-tidyr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
