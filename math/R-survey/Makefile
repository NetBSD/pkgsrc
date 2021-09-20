# $NetBSD: Makefile,v 1.3 2021/09/20 00:49:49 mef Exp $

R_PKGNAME=	survey
R_PKGVER=	4.1-1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Analysis of complex survey samples
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-minqa>=1.2.4:../../math/R-minqa
DEPENDS+=	R-mitools>=2.4:../../math/R-mitools
DEPENDS+=	R-numDeriv>=2016.8.1.1:../../math/R-numDeriv

# Packages suggested but not available: 'CompQuadForm', 'AER'
TEST_DEPENDS+=	R-hexbin-[0-9]*:../../math/R-hexbin
TEST_DEPENDS+=	R-RSQLite-[0-9]*:../../databases/R-RSQLite
TEST_DEPENDS+=	R-quantreg-[0-9]*:../../math/R-quantreg

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
