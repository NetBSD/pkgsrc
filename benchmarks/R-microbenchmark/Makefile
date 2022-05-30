# $NetBSD: Makefile,v 1.2 2022/05/30 15:18:25 mef Exp $

R_PKGNAME=	microbenchmark
R_PKGVER=	1.4.9
CATEGORIES=	benchmarks

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Accurate Timing Functions
LICENSE=	2-clause-bsd	# + file LICENSE

# Packages suggested but not available: 'multcomp'
TEST_DEPENDS+=	R-RUnit-[0-9]*:../../devel/R-RUnit
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
