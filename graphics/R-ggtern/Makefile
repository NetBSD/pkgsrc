# $NetBSD: Makefile,v 1.6 2024/06/08 20:15:29 mef Exp $

R_PKGNAME=	ggtern
R_PKGVER=	3.5.0
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extension to 'ggplot2', for the creation of ternary diagrams
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-proto>=1.0.0:../../devel/R-proto
DEPENDS+=	R-ggplot2>=3.5.0:../../graphics/R-ggplot2
DEPENDS+=	R-gridExtra>=2.3:../../graphics/R-gridExtra
DEPENDS+=	R-latex2exp>=0.5:../../graphics/R-latex2exp
DEPENDS+=	R-scales>=1.3.0:../../graphics/R-scales
DEPENDS+=	R-compositions>=2.0.2:../../math/R-compositions
DEPENDS+=	R-gtable>=0.1.2:../../math/R-gtable
DEPENDS+=	R-plyr>=1.8.3:../../math/R-plyr
DEPENDS+=	R-stat.extend-[0-9]*:../../math/R-stat.extend
DEPENDS+=	R-R.utils-[0-9]*:../../devel/R-R.utils
#EPENDS+=	R-lattice-[0-9]*:../../math/R-lattice
DEPENDS+=	R-hexbin-[0-9]*:../../math/R-hexbin

USE_LANGUAGES=	# none

TEST_DEPENDS+=	R-chemometrics-[0-9]*:../../math/R-chemometrics
TEST_DEPENDS+=	R-mclust-[0-9]*:../../math/R-mclust
TEST_DEPENDS+=	R-sp-[0-9]*:../../math/R-sp

TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
