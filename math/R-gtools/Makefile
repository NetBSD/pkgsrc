# $NetBSD: Makefile,v 1.12 2024/01/26 14:07:11 mef Exp $

R_PKGNAME=	gtools
R_PKGVER=	3.9.5

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Various R programming tools
LICENSE=	gnu-gpl-v2


# Packages suggested but not available: 'gplots', 'SGP', 'taxize'

TEST_DEPENDS+=	R-car-[0-9]*:../../math/R-car
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rstudioapi-[0-9]*:../../math/R-rstudioapi

CHECK_WRKREF_SKIP+=	lib/R/library/gtools/libs/gtools.so

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
