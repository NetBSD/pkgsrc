# $NetBSD: Makefile,v 1.4 2021/08/28 07:12:05 mef Exp $

R_PKGNAME=	ggtern
R_PKGVER=	3.3.5
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extension to 'ggplot2', for the creation of ternary diagrams
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-proto>=1.0.0:../../devel/R-proto
DEPENDS+=	R-ggplot2>=3.3.5:../../graphics/R-ggplot2
DEPENDS+=	R-gridExtra>=2.3:../../graphics/R-gridExtra
DEPENDS+=	R-latex2exp>=0.5:../../graphics/R-latex2exp
DEPENDS+=	R-scales>=0.3.0:../../graphics/R-scales
DEPENDS+=	R-compositions>=2.0.2:../../math/R-compositions
DEPENDS+=	R-gtable>=0.1.2:../../math/R-gtable
DEPENDS+=	R-plyr>=1.8.3:../../math/R-plyr
DEPENDS+=	R-stat.extend-[0-9]*:../../math/R-stat.extend
DEPENDS+=	R-R.utils-[0-9]*:../../devel/R-R.utils
#EPENDS+=	R-lattice-[0-9]*:../../math/R-lattice
DEPENDS+=	R-hexbin-[0-9]*:../../math/R-hexbin

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
