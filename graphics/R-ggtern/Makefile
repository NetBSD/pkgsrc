# $NetBSD: Makefile,v 1.3 2019/08/14 22:03:15 brook Exp $

R_PKGNAME=	ggtern
R_PKGVER=	3.1.0
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extension to 'ggplot2', for the creation of ternary diagrams
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-proto>=1.0.0:../../devel/R-proto
DEPENDS+=	R-ggplot2>=3.1.0:../../graphics/R-ggplot2
DEPENDS+=	R-gridExtra>=2.3:../../graphics/R-gridExtra
DEPENDS+=	R-latex2exp>=0.4:../../graphics/R-latex2exp
DEPENDS+=	R-scales>=0.3.0:../../graphics/R-scales
DEPENDS+=	R-compositions>=1.40.2:../../math/R-compositions
DEPENDS+=	R-gtable>=0.1.2:../../math/R-gtable
DEPENDS+=	R-plyr>=1.8.3:../../math/R-plyr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
