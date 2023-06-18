# $NetBSD: Makefile,v 1.5 2023/06/18 14:04:46 mef Exp $

R_PKGNAME=	checkmate
R_PKGVER=	2.2.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fast and versatile argument checks
LICENSE=	modified-bsd

DEPENDS+=	R-backports>=1.1.0:../../math/R-backports

# Package suggested but not available: 'fastmatch'

TEST_DEPENDS+=	R-data.table-[0-9]*:../../textproc/R-data.table
TEST_DEPENDS+=	R-devtools-[0-9]*:../../devel/R-devtools
TEST_DEPENDS+=	R-tinytest-[0-9]*:../../devel/R-tinytest
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-microbenchmark-[0-9]*:../../benchmarks/R-microbenchmark
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown


USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
