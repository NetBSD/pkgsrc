# $NetBSD: Makefile,v 1.6 2021/06/06 12:35:52 mef Exp $

R_PKGNAME=	glue
R_PKGVER=	1.4.2
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Interpreted string literals
LICENSE=	mit

# Packages suggested but not available:
#   'RSQLite', 'R.utils', 'forcats',  'rprintf'
TEST_DEPENDS+=	R-microbenchmark-[0-9]*:../../benchmarks/R-microbenchmark
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
