# $NetBSD: Makefile,v 1.7 2022/12/18 01:03:47 mef Exp $

R_PKGNAME=	bit
R_PKGVER=	4.0.5
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Class for vectors of 1-bit booleans
LICENSE=	gnu-gpl-v2

TEST_DEPENDS+=	R-bit64-[0-9]*:../../devel/R-bit64
TEST_DEPENDS+=	R-microbenchmarks-[0-9]*:../../benchmarks/R-microbenchmark
TEST_DEPENDS+=	R-roxygen2-[0-9]*:../../devel/R-roxygen2
TEST_DEPENDS+=	R-microbenchmark-[0-9]*:../../benchmarks/R-microbenchmark
TEST_DEPENDS+=	R-bit64-[0-9]*:../../devel/R-bit64
TEST_DEPENDS+=	R-ff-[0-9]*:../../sysutils/R-ff

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
