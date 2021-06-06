# $NetBSD: Makefile,v 1.6 2021/06/06 23:44:37 mef Exp $

R_PKGNAME=	bit
R_PKGVER=	4.0.4
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Class for vectors of 1-bit booleans
LICENSE=	gnu-gpl-v2

# Packages suggested but not available:
#  'roxygen2', 'microbenchmark', 'bit64', 'ff'
TEST_DEPENDS+=	R-bit64-[0-9]*:../../devel/R-bit64
TEST_DEPENDS+=	R-microbenchmarks-[0-9]*:../../benchmarks/R-microbenchmark
TEST_DEPENDS+=	R-roxygen2-[0-9]*:../../devel/R-roxygen2

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
