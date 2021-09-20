# $NetBSD: Makefile,v 1.2 2021/09/20 00:10:53 mef Exp $

R_PKGNAME=	robustbase
R_PKGVER=	0.93-8

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Basic robust statistics
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-DEoptimR>=1.0.8:../../math/R-DEoptimR

# Packages suggested but not available:
#   'robust', 'fit.models', 'MPV', 'GGally',
#   'RColorBrewer', 'reshape2', 'sfsmisc', 'catdata', 'doParallel',
#   'foreach', 'skewt'
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-xtable-[0-9]*:../../math/R-xtable

# Packages which this enhances but not available for checking:
#   'robustX', 'rrcov', 'matrixStats', 'quantreg', 'Hmisc'

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
