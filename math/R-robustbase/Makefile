# $NetBSD: Makefile,v 1.5 2023/08/11 05:23:11 mef Exp $

R_PKGNAME=	robustbase
R_PKGVER=	0.99-0

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Basic robust statistics
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-DEoptimR>=1.0.8:../../math/R-DEoptimR

# Packages suggested but not available:
#   'robust', 'fit.models', 'MPV', 'GGally', 'sfsmisc', 'catdata',
#   'doParallel', 'skewt'

TEST_DEPENDS+=	R-foreach -[0-9]*:../../devel/R-foreach 
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-xtable-[0-9]*:../../math/R-xtable

# Packages which this enhances but not available for checking:
#   'robustX', 'rrcov', 'matrixStats', 'quantreg', 'Hmisc'

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
