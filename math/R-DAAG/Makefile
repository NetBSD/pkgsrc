# $NetBSD: Makefile,v 1.17 2022/12/18 06:22:34 mef Exp $

R_PKGNAME=	DAAG
R_PKGVER=	1.25.4

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Data analysis and graphics data and functions
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-latticeExtra>=0.6.26:../../graphics/R-latticeExtra
DEPENDS+=	R-Rdpack-[0-9]*:../../textproc/R-Rdpack

# Packages suggested but not available: 'leaps', 'oz', 'bookdown'

TEST_DEPENDS+=	R-lme4-[0-9]*:../../math/R-lme4
TEST_DEPENDS+=	R-quantreg-[0-9]*:../../math/R-quantreg
TEST_DEPENDS+=	R-randomForest-[0-9]*:../../math/R-randomForest

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
