# $NetBSD: Makefile,v 1.10 2021/09/16 22:41:01 mef Exp $

R_PKGNAME=	gtools
R_PKGVER=	3.9.2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Various R programming tools
LICENSE=	gnu-gpl-v2

# Packages suggested but not available:
#  'gplots', 'rstudioapi', 'SGP', 'taxize'

TEST_DEPENDS+=	R-car-[0-9]*:../../math/R-car
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr

CHECK_WRKREF_SKIP+=	lib/R/library/gtools/libs/gtools.so

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
