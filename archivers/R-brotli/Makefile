# $NetBSD: Makefile,v 1.2 2025/01/01 22:19:36 mef Exp $

R_PKGNAME=	brotli
R_PKGVER=	1.3.1
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Compression Format Optimized for the Web
LICENSE=	mit	# + file LICENSE

# Package suggested but not available: 'R.rsp'

TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-microbenchmark-[0-9]*:../../benchmarks/R-microbenchmark
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
